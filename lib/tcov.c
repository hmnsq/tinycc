#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#បើមិនដូច្នេះ
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
    unsigned ចំនួនគត់ fline;
    unsigned ចំនួនគត់ lline;
    unsigned long long count;
} tcov_line;

typedef sa_nracanaa tcov_function {
    var_na *function;
    unsigned ចំនួនគត់ first_line;
    unsigned ចំនួនគត់ n_line;
    unsigned ចំនួនគត់ m_line;
    tcov_line *line;
} tcov_function;

typedef sa_nracanaa tcov_file {
    var_na *filename;
    unsigned ចំនួនគត់ n_func;
    unsigned ចំនួនគត់ m_func;
    tcov_function *func;
    sa_nracanaa tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (var_na *cov_filename)
{
    ចំនួនគត់ fd;
#ifndef _WIN32
    sa_nracanaa flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ប្រសិនបើ (fd < 0)
	ត្រឡប់ NULL;
  
#ifndef _WIN32
    ខណៈពេល (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#បើមិនដូច្នេះ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ត្រឡប់ fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned var_na *p, ចំនួនគត់ size)
{
    unsigned long long value = 0;

    p += size;
    ខណៈពេល (size--)
 	value = (value << 8) | *--p;
    ត្រឡប់ value;
}

static ចំនួនគត់ sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    ត្រឡប់ pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static ចំនួនគត់ sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    ត្រឡប់ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned var_na *p)
{
    ចំនួនគត់ i, j, k;
    unsigned var_na *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    ខណៈពេល (*p) {
        var_na *filename = (var_na *)p;
	size_t len = strlen (filename);

	nfile = file;
	ខណៈពេល (nfile) {
	    ប្រសិនបើ (strcmp (nfile->filename, filename) == 0)
		bha_nga;
	    nfile = nfile->next;
	}
	ប្រសិនបើ (nfile == NULL) {
	    nfile = malloc (parimaa_na(tcov_file));
	    ប្រសិនបើ (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ត្រឡប់ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    ប្រសិនបើ (file == NULL)
	        file = nfile;
	    បើមិនដូច្នេះ {
		tcov_file *lfile = file;

	        ខណៈពេល (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ខណៈពេល (*p) {
	    ចំនួនគត់ i;
	    var_na *function = (var_na *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    សម្រាប់ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ប្រសិនបើ (strcmp (func->function, function) == 0)
		    bha_nga;
	    }
	    ប្រសិនបើ (i == nfile->n_func) {
	        ប្រសិនបើ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   parimaa_na (tcov_function));
		    ប្រសិនបើ (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ត្រឡប់ file;
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
	    ខណៈពេល (*p) {
		tcov_line *line;
		unsigned long long val;

		ប្រសិនបើ (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * parimaa_na (tcov_line));
		    ប្រសិនបើ (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ត្រឡប់ file;
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
    ខណៈពេល (nfile) {
	qsort (nfile->func, nfile->n_func, parimaa_na (tcov_function), sort_func);
	សម្រាប់ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, parimaa_na (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    ត្រឡប់ file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned ចំនួនគត់ *pruns)
{
    unsigned ចំនួនគត់ runs;
    var_na *p;
    var_na str[10000];
    
    *pruns = 1;
    ប្រសិនបើ (fp == NULL)
        ត្រឡប់;
    ប្រសិនបើ (fgets(str, parimaa_na(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ខណៈពេល (file) {
	ចំនួនគត់ i;
	size_t len = strlen (file->filename);

	ខណៈពេល (fgets(str, parimaa_na(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        ប្រសិនបើ ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    bha_nga;
	សម្រាប់ (i = 0; i < file->n_func; i++) {
	    ចំនួនគត់ j;
	    tcov_function *func = &file->func[i];
	    unsigned ចំនួនគត់ next_zero = 0;
	    unsigned ចំនួនគត់ curline = 0;

	    សម្រាប់ (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned ចំនួនគត់ fline = line->fline;
	        unsigned long long count;
		unsigned ចំនួនគត់ tmp;
		var_na c;

		ខណៈពេល (curline < fline &&
		       fgets(str, parimaa_na(str), fp))
		    ប្រសិនបើ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ប្រសិនបើ (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ប្រសិនបើ (next_zero == 0)
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
    ចំនួនគត់ i, j;
    unsigned ចំនួនគត់ files;
    unsigned ចំនួនគត់ funcs;
    unsigned ចំនួនគត់ blocks;
    unsigned ចំនួនគត់ blocks_run;
    unsigned ចំនួនគត់ runs;
    var_na *cov_filename = (var_na *)p + get_value (p, 4);
    FILE *fp;
    var_na *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ប្រសិនបើ (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ត្រឡប់;
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
    ខណៈពេល (nfile) {
	files++;
	សម្រាប់ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    សម្រាប់ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ប្រសិនបើ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
    nfile = file;
    ខណៈពេល (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned ចំនួនគត់ curline = 1;
	var_na str[10000];

        ប្រសិនបើ (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	សម្រាប់ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    សម្រាប់ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ប្រសិនបើ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
        សម្រាប់ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ខណៈពេល (curline < func->first_line &&
		   fgets(str, parimaa_na(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    សម្រាប់ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ប្រសិនបើ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (dviguu_na) blocks_run / blocks);
#ប្រសិនបើ 0
	    សម្រាប់ (j = 0; j < func->n_line; j++) {
	        unsigned ចំនួនគត់ fline = func->line[j].fline;
	        unsigned ចំនួនគត់ lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    សម្រាប់ (j = 0; j < func->n_line;) {
	        unsigned ចំនួនគត់ fline = func->line[j].fline;
	        unsigned ចំនួនគត់ lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned ចំនួនគត់ has_zero = 0;
		unsigned ចំនួនគត់ same_line = fline == lline;

		j++;
		ខណៈពេល (j < func->n_line) {
	            unsigned ចំនួនគត់ nfline = func->line[j].fline;
	            unsigned ចំនួនគត់ nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ប្រសិនបើ (fline == nfline) {
			ប្រសិនបើ (ncount == 0)
			    has_zero = 1;
			បើមិនដូច្នេះ ប្រសិនបើ (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    បើមិនដូច្នេះ
			bha_nga;
		}
		ប្រសិនបើ (same_line)
		     lline++;

	        ខណៈពេល (curline < fline &&
		       fgets(str, parimaa_na(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ខណៈពេល (curline < lline &&
		       fgets(str, parimaa_na(str), src)) {
		    ប្រសិនបើ (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    បើមិនដូច្នេះ ប្រសិនបើ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    បើមិនដូច្នេះ
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	ខណៈពេល (fgets(str, parimaa_na(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ខណៈពេល (file) {
        សម្រាប់ (i = 0; i < file->n_func; i++) {
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
