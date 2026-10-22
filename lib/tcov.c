#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#නැතහොත්
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
    unsigned පූර්ණ_සංඛ්‍යා fline;
    unsigned පූර්ණ_සංඛ්‍යා lline;
    unsigned long long count;
} tcov_line;

typedef sa_nracanaa tcov_function {
    var_na *function;
    unsigned පූර්ණ_සංඛ්‍යා first_line;
    unsigned පූර්ණ_සංඛ්‍යා n_line;
    unsigned පූර්ණ_සංඛ්‍යා m_line;
    tcov_line *line;
} tcov_function;

typedef sa_nracanaa tcov_file {
    var_na *filename;
    unsigned පූර්ණ_සංඛ්‍යා n_func;
    unsigned පූර්ණ_සංඛ්‍යා m_func;
    tcov_function *func;
    sa_nracanaa tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (var_na *cov_filename)
{
    පූර්ණ_සංඛ්‍යා fd;
#ifndef _WIN32
    sa_nracanaa flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    නම් (fd < 0)
	ආපසු NULL;
  
#ifndef _WIN32
    අතරතුර (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#නැතහොත්
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ආපසු fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned var_na *p, පූර්ණ_සංඛ්‍යා size)
{
    unsigned long long value = 0;

    p += size;
    අතරතුර (size--)
 	value = (value << 8) | *--p;
    ආපසු value;
}

static පූර්ණ_සංඛ්‍යා sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    ආපසු pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static පූර්ණ_සංඛ්‍යා sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    ආපසු pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned var_na *p)
{
    පූර්ණ_සංඛ්‍යා i, j, k;
    unsigned var_na *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    අතරතුර (*p) {
        var_na *filename = (var_na *)p;
	size_t len = strlen (filename);

	nfile = file;
	අතරතුර (nfile) {
	    නම් (strcmp (nfile->filename, filename) == 0)
		bha_nga;
	    nfile = nfile->next;
	}
	නම් (nfile == NULL) {
	    nfile = malloc (parimaa_na(tcov_file));
	    නම් (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ආපසු file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    නම් (file == NULL)
	        file = nfile;
	    නැතහොත් {
		tcov_file *lfile = file;

	        අතරතුර (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	අතරතුර (*p) {
	    පූර්ණ_සංඛ්‍යා i;
	    var_na *function = (var_na *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    සඳහා (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		නම් (strcmp (func->function, function) == 0)
		    bha_nga;
	    }
	    නම් (i == nfile->n_func) {
	        නම් (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   parimaa_na (tcov_function));
		    නම් (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ආපසු file;
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
	    අතරතුර (*p) {
		tcov_line *line;
		unsigned long long val;

		නම් (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * parimaa_na (tcov_line));
		    නම් (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ආපසු file;
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
    අතරතුර (nfile) {
	qsort (nfile->func, nfile->n_func, parimaa_na (tcov_function), sort_func);
	සඳහා (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, parimaa_na (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    ආපසු file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned පූර්ණ_සංඛ්‍යා *pruns)
{
    unsigned පූර්ණ_සංඛ්‍යා runs;
    var_na *p;
    var_na str[10000];
    
    *pruns = 1;
    නම් (fp == NULL)
        ආපසු;
    නම් (fgets(str, parimaa_na(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    අතරතුර (file) {
	පූර්ණ_සංඛ්‍යා i;
	size_t len = strlen (file->filename);

	අතරතුර (fgets(str, parimaa_na(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        නම් ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    bha_nga;
	සඳහා (i = 0; i < file->n_func; i++) {
	    පූර්ණ_සංඛ්‍යා j;
	    tcov_function *func = &file->func[i];
	    unsigned පූර්ණ_සංඛ්‍යා next_zero = 0;
	    unsigned පූර්ණ_සංඛ්‍යා curline = 0;

	    සඳහා (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned පූර්ණ_සංඛ්‍යා fline = line->fline;
	        unsigned long long count;
		unsigned පූර්ණ_සංඛ්‍යා tmp;
		var_na c;

		අතරතුර (curline < fline &&
		       fgets(str, parimaa_na(str), fp))
		    නම් ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		නම් (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    නම් (next_zero == 0)
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
    පූර්ණ_සංඛ්‍යා i, j;
    unsigned පූර්ණ_සංඛ්‍යා files;
    unsigned පූර්ණ_සංඛ්‍යා funcs;
    unsigned පූර්ණ_සංඛ්‍යා blocks;
    unsigned පූර්ණ_සංඛ්‍යා blocks_run;
    unsigned පූර්ණ_සංඛ්‍යා runs;
    var_na *cov_filename = (var_na *)p + get_value (p, 4);
    FILE *fp;
    var_na *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    නම් (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ආපසු;
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
    අතරතුර (nfile) {
	files++;
	සඳහා (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    සඳහා (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    නම් (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
    nfile = file;
    අතරතුර (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned පූර්ණ_සංඛ්‍යා curline = 1;
	var_na str[10000];

        නම් (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	සඳහා (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    සඳහා (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	නම් (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
        සඳහා (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    අතරතුර (curline < func->first_line &&
		   fgets(str, parimaa_na(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    සඳහා (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    නම් (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (dviguu_na) blocks_run / blocks);
#නම් 0
	    සඳහා (j = 0; j < func->n_line; j++) {
	        unsigned පූර්ණ_සංඛ්‍යා fline = func->line[j].fline;
	        unsigned පූර්ණ_සංඛ්‍යා lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    සඳහා (j = 0; j < func->n_line;) {
	        unsigned පූර්ණ_සංඛ්‍යා fline = func->line[j].fline;
	        unsigned පූර්ණ_සංඛ්‍යා lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned පූර්ණ_සංඛ්‍යා has_zero = 0;
		unsigned පූර්ණ_සංඛ්‍යා same_line = fline == lline;

		j++;
		අතරතුර (j < func->n_line) {
	            unsigned පූර්ණ_සංඛ්‍යා nfline = func->line[j].fline;
	            unsigned පූර්ණ_සංඛ්‍යා nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    නම් (fline == nfline) {
			නම් (ncount == 0)
			    has_zero = 1;
			නැතහොත් නම් (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    නැතහොත්
			bha_nga;
		}
		නම් (same_line)
		     lline++;

	        අතරතුර (curline < fline &&
		       fgets(str, parimaa_na(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		අතරතුර (curline < lline &&
		       fgets(str, parimaa_na(str), src)) {
		    නම් (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    නැතහොත් නම් (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    නැතහොත්
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	අතරතුර (fgets(str, parimaa_na(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    අතරතුර (file) {
        සඳහා (i = 0; i < file->n_func; i++) {
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
