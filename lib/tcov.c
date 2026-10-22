#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#아니면
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
    unsigned 정수 fline;
    unsigned 정수 lline;
    unsigned long long count;
} tcov_line;

typedef struct tcov_function {
    char *function;
    unsigned 정수 first_line;
    unsigned 정수 n_line;
    unsigned 정수 m_line;
    tcov_line *line;
} tcov_function;

typedef struct tcov_file {
    char *filename;
    unsigned 정수 n_func;
    unsigned 정수 m_func;
    tcov_function *func;
    struct tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (char *cov_filename)
{
    정수 fd;
#ifndef _WIN32
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    만약 (fd < 0)
	반환 NULL;
  
#ifndef _WIN32
    동안 (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#아니면
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    반환 fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned char *p, 정수 size)
{
    unsigned long long value = 0;

    p += size;
    동안 (size--)
 	value = (value << 8) | *--p;
    반환 value;
}

static 정수 sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    반환 pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static 정수 sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    반환 pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned char *p)
{
    정수 i, j, k;
    unsigned char *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    동안 (*p) {
        char *filename = (char *)p;
	size_t len = strlen (filename);

	nfile = file;
	동안 (nfile) {
	    만약 (strcmp (nfile->filename, filename) == 0)
		break;
	    nfile = nfile->next;
	}
	만약 (nfile == NULL) {
	    nfile = malloc (sizeof(tcov_file));
	    만약 (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        반환 file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    만약 (file == NULL)
	        file = nfile;
	    아니면 {
		tcov_file *lfile = file;

	        동안 (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	동안 (*p) {
	    정수 i;
	    char *function = (char *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    위해 (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		만약 (strcmp (func->function, function) == 0)
		    break;
	    }
	    만약 (i == nfile->n_func) {
	        만약 (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   sizeof (tcov_function));
		    만약 (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        반환 file;
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
	    동안 (*p) {
		tcov_line *line;
		unsigned long long val;

		만약 (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * sizeof (tcov_line));
		    만약 (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        반환 file;
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
    동안 (nfile) {
	qsort (nfile->func, nfile->n_func, sizeof (tcov_function), sort_func);
	위해 (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, sizeof (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    반환 file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned 정수 *pruns)
{
    unsigned 정수 runs;
    char *p;
    char str[10000];
    
    *pruns = 1;
    만약 (fp == NULL)
        반환;
    만약 (fgets(str, sizeof(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    동안 (file) {
	정수 i;
	size_t len = strlen (file->filename);

	동안 (fgets(str, sizeof(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        만약 ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    break;
	위해 (i = 0; i < file->n_func; i++) {
	    정수 j;
	    tcov_function *func = &file->func[i];
	    unsigned 정수 next_zero = 0;
	    unsigned 정수 curline = 0;

	    위해 (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned 정수 fline = line->fline;
	        unsigned long long count;
		unsigned 정수 tmp;
		char c;

		동안 (curline < fline &&
		       fgets(str, sizeof(str), fp))
		    만약 ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		만약 (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    만약 (next_zero == 0)
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
    정수 i, j;
    unsigned 정수 files;
    unsigned 정수 funcs;
    unsigned 정수 blocks;
    unsigned 정수 blocks_run;
    unsigned 정수 runs;
    char *cov_filename = (char *)p + get_value (p, 4);
    FILE *fp;
    char *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    만약 (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	반환;
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
    동안 (nfile) {
	files++;
	위해 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    위해 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    만약 (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (double) blocks_run / blocks);
    nfile = file;
    동안 (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned 정수 curline = 1;
	char str[10000];

        만약 (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	위해 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    위해 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	만약 (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (double) blocks_run / blocks);
        위해 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    동안 (curline < func->first_line &&
		   fgets(str, sizeof(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    위해 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    만약 (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (double) blocks_run / blocks);
#만약 0
	    위해 (j = 0; j < func->n_line; j++) {
	        unsigned 정수 fline = func->line[j].fline;
	        unsigned 정수 lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    위해 (j = 0; j < func->n_line;) {
	        unsigned 정수 fline = func->line[j].fline;
	        unsigned 정수 lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned 정수 has_zero = 0;
		unsigned 정수 same_line = fline == lline;

		j++;
		동안 (j < func->n_line) {
	            unsigned 정수 nfline = func->line[j].fline;
	            unsigned 정수 nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    만약 (fline == nfline) {
			만약 (ncount == 0)
			    has_zero = 1;
			아니면 만약 (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    아니면
			break;
		}
		만약 (same_line)
		     lline++;

	        동안 (curline < fline &&
		       fgets(str, sizeof(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		동안 (curline < lline &&
		       fgets(str, sizeof(str), src)) {
		    만약 (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    아니면 만약 (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    아니면
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	동안 (fgets(str, sizeof(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    동안 (file) {
        위해 (i = 0; i < file->n_func; i++) {
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
