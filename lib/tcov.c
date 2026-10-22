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
    unsigned целое fline;
    unsigned целое lline;
    unsigned long long count;
} tcov_line;

typedef struct tcov_function {
    char *function;
    unsigned целое first_line;
    unsigned целое n_line;
    unsigned целое m_line;
    tcov_line *line;
} tcov_function;

typedef struct tcov_file {
    char *filename;
    unsigned целое n_func;
    unsigned целое m_func;
    tcov_function *func;
    struct tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (char *cov_filename)
{
    целое fd;
#ifndef _WIN32
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    если (fd < 0)
	вернуть NULL;
  
#ifndef _WIN32
    пока (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#иначе
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    вернуть fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned char *p, целое size)
{
    unsigned long long value = 0;

    p += size;
    пока (size--)
 	value = (value << 8) | *--p;
    вернуть value;
}

static целое sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    вернуть pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static целое sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    вернуть pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned char *p)
{
    целое i, j, k;
    unsigned char *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    пока (*p) {
        char *filename = (char *)p;
	size_t len = strlen (filename);

	nfile = file;
	пока (nfile) {
	    если (strcmp (nfile->filename, filename) == 0)
		break;
	    nfile = nfile->next;
	}
	если (nfile == NULL) {
	    nfile = malloc (sizeof(tcov_file));
	    если (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        вернуть file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    если (file == NULL)
	        file = nfile;
	    иначе {
		tcov_file *lfile = file;

	        пока (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	пока (*p) {
	    целое i;
	    char *function = (char *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    для (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		если (strcmp (func->function, function) == 0)
		    break;
	    }
	    если (i == nfile->n_func) {
	        если (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   sizeof (tcov_function));
		    если (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        вернуть file;
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
	    пока (*p) {
		tcov_line *line;
		unsigned long long val;

		если (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * sizeof (tcov_line));
		    если (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        вернуть file;
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
    пока (nfile) {
	qsort (nfile->func, nfile->n_func, sizeof (tcov_function), sort_func);
	для (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, sizeof (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    вернуть file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned целое *pruns)
{
    unsigned целое runs;
    char *p;
    char str[10000];
    
    *pruns = 1;
    если (fp == NULL)
        вернуть;
    если (fgets(str, sizeof(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    пока (file) {
	целое i;
	size_t len = strlen (file->filename);

	пока (fgets(str, sizeof(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        если ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    break;
	для (i = 0; i < file->n_func; i++) {
	    целое j;
	    tcov_function *func = &file->func[i];
	    unsigned целое next_zero = 0;
	    unsigned целое curline = 0;

	    для (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned целое fline = line->fline;
	        unsigned long long count;
		unsigned целое tmp;
		char c;

		пока (curline < fline &&
		       fgets(str, sizeof(str), fp))
		    если ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		если (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    если (next_zero == 0)
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
    целое i, j;
    unsigned целое files;
    unsigned целое funcs;
    unsigned целое blocks;
    unsigned целое blocks_run;
    unsigned целое runs;
    char *cov_filename = (char *)p + get_value (p, 4);
    FILE *fp;
    char *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    если (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	вернуть;
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
    пока (nfile) {
	files++;
	для (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    для (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    если (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (double) blocks_run / blocks);
    nfile = file;
    пока (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned целое curline = 1;
	char str[10000];

        если (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	для (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    для (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	если (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (double) blocks_run / blocks);
        для (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    пока (curline < func->first_line &&
		   fgets(str, sizeof(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    для (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    если (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (double) blocks_run / blocks);
#если 0
	    для (j = 0; j < func->n_line; j++) {
	        unsigned целое fline = func->line[j].fline;
	        unsigned целое lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    для (j = 0; j < func->n_line;) {
	        unsigned целое fline = func->line[j].fline;
	        unsigned целое lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned целое has_zero = 0;
		unsigned целое same_line = fline == lline;

		j++;
		пока (j < func->n_line) {
	            unsigned целое nfline = func->line[j].fline;
	            unsigned целое nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    если (fline == nfline) {
			если (ncount == 0)
			    has_zero = 1;
			иначе если (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    иначе
			break;
		}
		если (same_line)
		     lline++;

	        пока (curline < fline &&
		       fgets(str, sizeof(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		пока (curline < lline &&
		       fgets(str, sizeof(str), src)) {
		    если (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    иначе если (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    иначе
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	пока (fgets(str, sizeof(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    пока (file) {
        для (i = 0; i < file->n_func; i++) {
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
