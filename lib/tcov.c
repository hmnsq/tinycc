#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#иначе
#include <windows.h>
#include <io.h>
#endif

/* section layout (all little endian):
   32bit offset to executable/so file name
     filename \0
       function name \0
       align to 64 bits
       64bit function start line
         64bits end_line(28bits) / start_line(28bits) / flag=0xff(8bits)
	 64bits counter
       \0
     \0
   \0
   executable/so file name \0
 */

typedef struct tcov_line {
    unsigned цяло fline;
    unsigned цяло lline;
    unsigned long long count;
} tcov_line;

typedef struct tcov_function {
    char *function;
    unsigned цяло first_line;
    unsigned цяло n_line;
    unsigned цяло m_line;
    tcov_line *line;
} tcov_function;

typedef struct tcov_file {
    char *filename;
    unsigned цяло n_func;
    unsigned цяло m_func;
    tcov_function *func;
    struct tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (char *cov_filename)
{
    цяло fd;
#ifndef _WIN32
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ако (fd < 0)
	върни NULL;
  
#ifndef _WIN32
    докато (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#иначе
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    върни fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned char *p, цяло size)
{
    unsigned long long value = 0;

    p += size;
    докато (size--)
 	value = (value << 8) | *--p;
    върни value;
}

static цяло sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    върни pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static цяло sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    върни pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned char *p)
{
    цяло i, j, k;
    unsigned char *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    докато (*p) {
        char *filename = (char *)p;
	size_t len = strlen (filename);

	nfile = file;
	докато (nfile) {
	    ако (strcmp (nfile->filename, filename) == 0)
		break;
	    nfile = nfile->next;
	}
	ако (nfile == NULL) {
	    nfile = malloc (sizeof(tcov_file));
	    ако (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        върни file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    ако (file == NULL)
	        file = nfile;
	    иначе {
		tcov_file *lfile = file;

	        докато (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	докато (*p) {
	    цяло i;
	    char *function = (char *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    за (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ако (strcmp (func->function, function) == 0)
		    break;
	    }
	    ако (i == nfile->n_func) {
	        ако (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   sizeof (tcov_function));
		    ако (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        върни file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_line = get_value (p, 8);
	        func->n_line = 0;
	        func->m_line = 0;
	        func->line = NULL;
	    }
	    p += 8;
	    докато (*p) {
		tcov_line *line;
		unsigned long long val;

		ако (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * sizeof (tcov_line));
		    ако (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        върни file;
		    }
		}
		line = &func->line[func->n_line++];
		val = get_value (p, 8);
	        line->fline = (val >> 8) & 0xfffffffULL;
	        line->lline = val >> 36;
	        line->count = get_value (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    докато (nfile) {
	qsort (nfile->func, nfile->n_func, sizeof (tcov_function), sort_func);
	за (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, sizeof (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    върни file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned цяло *pruns)
{
    unsigned цяло runs;
    char *p;
    char str[10000];
    
    *pruns = 1;
    ако (fp == NULL)
        върни;
    ако (fgets(str, sizeof(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    докато (file) {
	цяло i;
	size_t len = strlen (file->filename);

	докато (fgets(str, sizeof(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        ако ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    break;
	за (i = 0; i < file->n_func; i++) {
	    цяло j;
	    tcov_function *func = &file->func[i];
	    unsigned цяло next_zero = 0;
	    unsigned цяло curline = 0;

	    за (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned цяло fline = line->fline;
	        unsigned long long count;
		unsigned цяло tmp;
		char c;

		докато (curline < fline &&
		       fgets(str, sizeof(str), fp))
		    ако ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ако (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ако (next_zero == 0)
		        line->count += count;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
void __store_test_coverage (unsigned char * p)
{
    цяло i, j;
    unsigned цяло files;
    unsigned цяло funcs;
    unsigned цяло blocks;
    unsigned цяло blocks_run;
    unsigned цяло runs;
    char *cov_filename = (char *)p + get_value (p, 4);
    FILE *fp;
    char *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ако (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	върни;
    }
    file = sort_test_coverage (p);
    merge_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    blocks = 0;
    blocks_run = 0;
    nfile = file;
    докато (nfile) {
	files++;
	за (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    за (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ако (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (double) blocks_run / blocks);
    nfile = file;
    докато (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned цяло curline = 1;
	char str[10000];

        ако (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	за (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    за (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ако (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (double) blocks_run / blocks);
        за (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    докато (curline < func->first_line &&
		   fgets(str, sizeof(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    за (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ако (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (double) blocks_run / blocks);
#ако 0
	    за (j = 0; j < func->n_line; j++) {
	        unsigned цяло fline = func->line[j].fline;
	        unsigned цяло lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    за (j = 0; j < func->n_line;) {
	        unsigned цяло fline = func->line[j].fline;
	        unsigned цяло lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned цяло has_zero = 0;
		unsigned цяло same_line = fline == lline;

		j++;
		докато (j < func->n_line) {
	            unsigned цяло nfline = func->line[j].fline;
	            unsigned цяло nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ако (fline == nfline) {
			ако (ncount == 0)
			    has_zero = 1;
			иначе ако (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    иначе
			break;
		}
		ако (same_line)
		     lline++;

	        докато (curline < fline &&
		       fgets(str, sizeof(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		докато (curline < lline &&
		       fgets(str, sizeof(str), src)) {
		    ако (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    иначе ако (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    иначе
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	докато (fgets(str, sizeof(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    докато (file) {
        за (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    free (func->line);
        }
	free (file->func);
	nfile = file;
	file = file->next;
	free (nfile);
    }
    fclose (fp);
}
