#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#否则
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
    unsigned 整数 fline;
    unsigned 整数 lline;
    unsigned long long count;
} tcov_line;

typedef struct tcov_function {
    char *function;
    unsigned 整数 first_line;
    unsigned 整数 n_line;
    unsigned 整数 m_line;
    tcov_line *line;
} tcov_function;

typedef struct tcov_file {
    char *filename;
    unsigned 整数 n_func;
    unsigned 整数 m_func;
    tcov_function *func;
    struct tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (char *cov_filename)
{
    整数 fd;
#ifndef _WIN32
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    如果 (fd < 0)
	返回 NULL;
  
#ifndef _WIN32
    当 (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#否则
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    返回 fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned char *p, 整数 size)
{
    unsigned long long value = 0;

    p += size;
    当 (size--)
 	value = (value << 8) | *--p;
    返回 value;
}

static 整数 sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    返回 pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static 整数 sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    返回 pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned char *p)
{
    整数 i, j, k;
    unsigned char *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    当 (*p) {
        char *filename = (char *)p;
	size_t len = strlen (filename);

	nfile = file;
	当 (nfile) {
	    如果 (strcmp (nfile->filename, filename) == 0)
		break;
	    nfile = nfile->next;
	}
	如果 (nfile == NULL) {
	    nfile = malloc (sizeof(tcov_file));
	    如果 (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        返回 file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    如果 (file == NULL)
	        file = nfile;
	    否则 {
		tcov_file *lfile = file;

	        当 (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	当 (*p) {
	    整数 i;
	    char *function = (char *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    为 (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		如果 (strcmp (func->function, function) == 0)
		    break;
	    }
	    如果 (i == nfile->n_func) {
	        如果 (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   sizeof (tcov_function));
		    如果 (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        返回 file;
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
	    当 (*p) {
		tcov_line *line;
		unsigned long long val;

		如果 (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * sizeof (tcov_line));
		    如果 (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        返回 file;
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
    当 (nfile) {
	qsort (nfile->func, nfile->n_func, sizeof (tcov_function), sort_func);
	为 (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, sizeof (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    返回 file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned 整数 *pruns)
{
    unsigned 整数 runs;
    char *p;
    char str[10000];
    
    *pruns = 1;
    如果 (fp == NULL)
        返回;
    如果 (fgets(str, sizeof(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    当 (file) {
	整数 i;
	size_t len = strlen (file->filename);

	当 (fgets(str, sizeof(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        如果 ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    break;
	为 (i = 0; i < file->n_func; i++) {
	    整数 j;
	    tcov_function *func = &file->func[i];
	    unsigned 整数 next_zero = 0;
	    unsigned 整数 curline = 0;

	    为 (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned 整数 fline = line->fline;
	        unsigned long long count;
		unsigned 整数 tmp;
		char c;

		当 (curline < fline &&
		       fgets(str, sizeof(str), fp))
		    如果 ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		如果 (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    如果 (next_zero == 0)
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
    整数 i, j;
    unsigned 整数 files;
    unsigned 整数 funcs;
    unsigned 整数 blocks;
    unsigned 整数 blocks_run;
    unsigned 整数 runs;
    char *cov_filename = (char *)p + get_value (p, 4);
    FILE *fp;
    char *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    如果 (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	返回;
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
    当 (nfile) {
	files++;
	为 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    为 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    如果 (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (double) blocks_run / blocks);
    nfile = file;
    当 (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned 整数 curline = 1;
	char str[10000];

        如果 (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	为 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    为 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	如果 (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (double) blocks_run / blocks);
        为 (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    当 (curline < func->first_line &&
		   fgets(str, sizeof(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    为 (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    如果 (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (double) blocks_run / blocks);
#如果 0
	    为 (j = 0; j < func->n_line; j++) {
	        unsigned 整数 fline = func->line[j].fline;
	        unsigned 整数 lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    为 (j = 0; j < func->n_line;) {
	        unsigned 整数 fline = func->line[j].fline;
	        unsigned 整数 lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned 整数 has_zero = 0;
		unsigned 整数 same_line = fline == lline;

		j++;
		当 (j < func->n_line) {
	            unsigned 整数 nfline = func->line[j].fline;
	            unsigned 整数 nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    如果 (fline == nfline) {
			如果 (ncount == 0)
			    has_zero = 1;
			否则 如果 (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    否则
			break;
		}
		如果 (same_line)
		     lline++;

	        当 (curline < fline &&
		       fgets(str, sizeof(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		当 (curline < lline &&
		       fgets(str, sizeof(str), src)) {
		    如果 (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    否则 如果 (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    否则
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	当 (fgets(str, sizeof(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    当 (file) {
        为 (i = 0; i < file->n_func; i++) {
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
