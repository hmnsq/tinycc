#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#інакше
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
    unsigned ціле fline;
    unsigned ціле lline;
    unsigned long long count;
} tcov_line;

typedef struct tcov_function {
    char *function;
    unsigned ціле first_line;
    unsigned ціле n_line;
    unsigned ціле m_line;
    tcov_line *line;
} tcov_function;

typedef struct tcov_file {
    char *filename;
    unsigned ціле n_func;
    unsigned ціле m_func;
    tcov_function *func;
    struct tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (char *cov_filename)
{
    ціле fd;
#ifndef _WIN32
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    якщо (fd < 0)
	повернути NULL;
  
#ifndef _WIN32
    поки (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#інакше
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    повернути fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned char *p, ціле size)
{
    unsigned long long value = 0;

    p += size;
    поки (size--)
 	value = (value << 8) | *--p;
    повернути value;
}

static ціле sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    повернути pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static ціле sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    повернути pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned char *p)
{
    ціле i, j, k;
    unsigned char *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    поки (*p) {
        char *filename = (char *)p;
	size_t len = strlen (filename);

	nfile = file;
	поки (nfile) {
	    якщо (strcmp (nfile->filename, filename) == 0)
		break;
	    nfile = nfile->next;
	}
	якщо (nfile == NULL) {
	    nfile = malloc (sizeof(tcov_file));
	    якщо (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        повернути file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    якщо (file == NULL)
	        file = nfile;
	    інакше {
		tcov_file *lfile = file;

	        поки (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	поки (*p) {
	    ціле i;
	    char *function = (char *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    для (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		якщо (strcmp (func->function, function) == 0)
		    break;
	    }
	    якщо (i == nfile->n_func) {
	        якщо (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   sizeof (tcov_function));
		    якщо (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        повернути file;
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
	    поки (*p) {
		tcov_line *line;
		unsigned long long val;

		якщо (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * sizeof (tcov_line));
		    якщо (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        повернути file;
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
    поки (nfile) {
	qsort (nfile->func, nfile->n_func, sizeof (tcov_function), sort_func);
	для (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, sizeof (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    повернути file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned ціле *pruns)
{
    unsigned ціле runs;
    char *p;
    char str[10000];
    
    *pruns = 1;
    якщо (fp == NULL)
        повернути;
    якщо (fgets(str, sizeof(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    поки (file) {
	ціле i;
	size_t len = strlen (file->filename);

	поки (fgets(str, sizeof(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        якщо ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    break;
	для (i = 0; i < file->n_func; i++) {
	    ціле j;
	    tcov_function *func = &file->func[i];
	    unsigned ціле next_zero = 0;
	    unsigned ціле curline = 0;

	    для (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned ціле fline = line->fline;
	        unsigned long long count;
		unsigned ціле tmp;
		char c;

		поки (curline < fline &&
		       fgets(str, sizeof(str), fp))
		    якщо ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		якщо (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    якщо (next_zero == 0)
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
    ціле i, j;
    unsigned ціле files;
    unsigned ціле funcs;
    unsigned ціле blocks;
    unsigned ціле blocks_run;
    unsigned ціле runs;
    char *cov_filename = (char *)p + get_value (p, 4);
    FILE *fp;
    char *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    якщо (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	повернути;
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
    поки (nfile) {
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
    якщо (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (double) blocks_run / blocks);
    nfile = file;
    поки (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned ціле curline = 1;
	char str[10000];

        якщо (src == NULL)
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
	якщо (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (double) blocks_run / blocks);
        для (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    поки (curline < func->first_line &&
		   fgets(str, sizeof(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    для (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    якщо (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (double) blocks_run / blocks);
#якщо 0
	    для (j = 0; j < func->n_line; j++) {
	        unsigned ціле fline = func->line[j].fline;
	        unsigned ціле lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    для (j = 0; j < func->n_line;) {
	        unsigned ціле fline = func->line[j].fline;
	        unsigned ціле lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned ціле has_zero = 0;
		unsigned ціле same_line = fline == lline;

		j++;
		поки (j < func->n_line) {
	            unsigned ціле nfline = func->line[j].fline;
	            unsigned ціле nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    якщо (fline == nfline) {
			якщо (ncount == 0)
			    has_zero = 1;
			інакше якщо (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    інакше
			break;
		}
		якщо (same_line)
		     lline++;

	        поки (curline < fline &&
		       fgets(str, sizeof(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		поки (curline < lline &&
		       fgets(str, sizeof(str), src)) {
		    якщо (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    інакше якщо (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    інакше
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	поки (fgets(str, sizeof(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    поки (file) {
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
