#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#มิฉะนั้น
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

typedef sa_nracanaa tcov_line {
    unsigned จำนวนเต็ม fline;
    unsigned จำนวนเต็ม lline;
    unsigned long long count;
} tcov_line;

typedef sa_nracanaa tcov_function {
    var_na *function;
    unsigned จำนวนเต็ม first_line;
    unsigned จำนวนเต็ม n_line;
    unsigned จำนวนเต็ม m_line;
    tcov_line *line;
} tcov_function;

typedef sa_nracanaa tcov_file {
    var_na *filename;
    unsigned จำนวนเต็ม n_func;
    unsigned จำนวนเต็ม m_func;
    tcov_function *func;
    sa_nracanaa tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (var_na *cov_filename)
{
    จำนวนเต็ม fd;
#ifndef _WIN32
    sa_nracanaa flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ถ้า (fd < 0)
	คืน NULL;
  
#ifndef _WIN32
    ขณะ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#มิฉะนั้น
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    คืน fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned var_na *p, จำนวนเต็ม size)
{
    unsigned long long value = 0;

    p += size;
    ขณะ (size--)
 	value = (value << 8) | *--p;
    คืน value;
}

static จำนวนเต็ม sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    คืน pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static จำนวนเต็ม sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    คืน pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned var_na *p)
{
    จำนวนเต็ม i, j, k;
    unsigned var_na *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    ขณะ (*p) {
        var_na *filename = (var_na *)p;
	size_t len = strlen (filename);

	nfile = file;
	ขณะ (nfile) {
	    ถ้า (strcmp (nfile->filename, filename) == 0)
		bha_nga;
	    nfile = nfile->next;
	}
	ถ้า (nfile == NULL) {
	    nfile = malloc (parimaa_na(tcov_file));
	    ถ้า (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        คืน file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    ถ้า (file == NULL)
	        file = nfile;
	    มิฉะนั้น {
		tcov_file *lfile = file;

	        ขณะ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ขณะ (*p) {
	    จำนวนเต็ม i;
	    var_na *function = (var_na *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    สำหรับ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ถ้า (strcmp (func->function, function) == 0)
		    bha_nga;
	    }
	    ถ้า (i == nfile->n_func) {
	        ถ้า (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   parimaa_na (tcov_function));
		    ถ้า (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        คืน file;
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
	    ขณะ (*p) {
		tcov_line *line;
		unsigned long long val;

		ถ้า (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * parimaa_na (tcov_line));
		    ถ้า (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        คืน file;
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
    ขณะ (nfile) {
	qsort (nfile->func, nfile->n_func, parimaa_na (tcov_function), sort_func);
	สำหรับ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, parimaa_na (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    คืน file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned จำนวนเต็ม *pruns)
{
    unsigned จำนวนเต็ม runs;
    var_na *p;
    var_na str[10000];
    
    *pruns = 1;
    ถ้า (fp == NULL)
        คืน;
    ถ้า (fgets(str, parimaa_na(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ขณะ (file) {
	จำนวนเต็ม i;
	size_t len = strlen (file->filename);

	ขณะ (fgets(str, parimaa_na(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        ถ้า ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    bha_nga;
	สำหรับ (i = 0; i < file->n_func; i++) {
	    จำนวนเต็ม j;
	    tcov_function *func = &file->func[i];
	    unsigned จำนวนเต็ม next_zero = 0;
	    unsigned จำนวนเต็ม curline = 0;

	    สำหรับ (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned จำนวนเต็ม fline = line->fline;
	        unsigned long long count;
		unsigned จำนวนเต็ม tmp;
		var_na c;

		ขณะ (curline < fline &&
		       fgets(str, parimaa_na(str), fp))
		    ถ้า ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ถ้า (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ถ้า (next_zero == 0)
		        line->count += count;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
void __store_test_coverage (unsigned var_na * p)
{
    จำนวนเต็ม i, j;
    unsigned จำนวนเต็ม files;
    unsigned จำนวนเต็ม funcs;
    unsigned จำนวนเต็ม blocks;
    unsigned จำนวนเต็ม blocks_run;
    unsigned จำนวนเต็ม runs;
    var_na *cov_filename = (var_na *)p + get_value (p, 4);
    FILE *fp;
    var_na *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ถ้า (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	คืน;
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
    ขณะ (nfile) {
	files++;
	สำหรับ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    สำหรับ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ถ้า (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
    nfile = file;
    ขณะ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned จำนวนเต็ม curline = 1;
	var_na str[10000];

        ถ้า (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	สำหรับ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    สำหรับ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ถ้า (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
        สำหรับ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ขณะ (curline < func->first_line &&
		   fgets(str, parimaa_na(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    สำหรับ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ถ้า (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (dviguu_na) blocks_run / blocks);
#ถ้า 0
	    สำหรับ (j = 0; j < func->n_line; j++) {
	        unsigned จำนวนเต็ม fline = func->line[j].fline;
	        unsigned จำนวนเต็ม lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    สำหรับ (j = 0; j < func->n_line;) {
	        unsigned จำนวนเต็ม fline = func->line[j].fline;
	        unsigned จำนวนเต็ม lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned จำนวนเต็ม has_zero = 0;
		unsigned จำนวนเต็ม same_line = fline == lline;

		j++;
		ขณะ (j < func->n_line) {
	            unsigned จำนวนเต็ม nfline = func->line[j].fline;
	            unsigned จำนวนเต็ม nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ถ้า (fline == nfline) {
			ถ้า (ncount == 0)
			    has_zero = 1;
			มิฉะนั้น ถ้า (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    มิฉะนั้น
			bha_nga;
		}
		ถ้า (same_line)
		     lline++;

	        ขณะ (curline < fline &&
		       fgets(str, parimaa_na(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ขณะ (curline < lline &&
		       fgets(str, parimaa_na(str), src)) {
		    ถ้า (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    มิฉะนั้น ถ้า (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    มิฉะนั้น
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	ขณะ (fgets(str, parimaa_na(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ขณะ (file) {
        สำหรับ (i = 0; i < file->n_func; i++) {
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
