#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#ꦭꦶꦪ
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
    unsigned puur_naa_nka fline;
    unsigned puur_naa_nka lline;
    unsigned long long count;
} tcov_line;

typedef sa_nracanaa tcov_function {
    var_na *function;
    unsigned puur_naa_nka first_line;
    unsigned puur_naa_nka n_line;
    unsigned puur_naa_nka m_line;
    tcov_line *line;
} tcov_function;

typedef sa_nracanaa tcov_file {
    var_na *filename;
    unsigned puur_naa_nka n_func;
    unsigned puur_naa_nka m_func;
    tcov_function *func;
    sa_nracanaa tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (var_na *cov_filename)
{
    puur_naa_nka fd;
#ifndef _WIN32
    sa_nracanaa flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ꦪꦼꦤ꧀ (fd < 0)
	ꦮꦭꦶ NULL;
  
#ifndef _WIN32
    ꦱꦼꦢꦼꦭ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#ꦭꦶꦪ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ꦮꦭꦶ fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned var_na *p, puur_naa_nka size)
{
    unsigned long long value = 0;

    p += size;
    ꦱꦼꦢꦼꦭ (size--)
 	value = (value << 8) | *--p;
    ꦮꦭꦶ value;
}

static puur_naa_nka sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    ꦮꦭꦶ pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static puur_naa_nka sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    ꦮꦭꦶ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned var_na *p)
{
    puur_naa_nka i, j, k;
    unsigned var_na *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    ꦱꦼꦢꦼꦭ (*p) {
        var_na *filename = (var_na *)p;
	size_t len = strlen (filename);

	nfile = file;
	ꦱꦼꦢꦼꦭ (nfile) {
	    ꦪꦼꦤ꧀ (strcmp (nfile->filename, filename) == 0)
		bha_nga;
	    nfile = nfile->next;
	}
	ꦪꦼꦤ꧀ (nfile == NULL) {
	    nfile = malloc (parimaa_na(tcov_file));
	    ꦪꦼꦤ꧀ (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ꦮꦭꦶ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    ꦪꦼꦤ꧀ (file == NULL)
	        file = nfile;
	    ꦭꦶꦪ {
		tcov_file *lfile = file;

	        ꦱꦼꦢꦼꦭ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ꦱꦼꦢꦼꦭ (*p) {
	    puur_naa_nka i;
	    var_na *function = (var_na *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    ꦏꦁꦒꦺꦴ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ꦪꦼꦤ꧀ (strcmp (func->function, function) == 0)
		    bha_nga;
	    }
	    ꦪꦼꦤ꧀ (i == nfile->n_func) {
	        ꦪꦼꦤ꧀ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   parimaa_na (tcov_function));
		    ꦪꦼꦤ꧀ (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ꦮꦭꦶ file;
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
	    ꦱꦼꦢꦼꦭ (*p) {
		tcov_line *line;
		unsigned long long val;

		ꦪꦼꦤ꧀ (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * parimaa_na (tcov_line));
		    ꦪꦼꦤ꧀ (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ꦮꦭꦶ file;
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
    ꦱꦼꦢꦼꦭ (nfile) {
	qsort (nfile->func, nfile->n_func, parimaa_na (tcov_function), sort_func);
	ꦏꦁꦒꦺꦴ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, parimaa_na (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    ꦮꦭꦶ file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned puur_naa_nka *pruns)
{
    unsigned puur_naa_nka runs;
    var_na *p;
    var_na str[10000];
    
    *pruns = 1;
    ꦪꦼꦤ꧀ (fp == NULL)
        ꦮꦭꦶ;
    ꦪꦼꦤ꧀ (fgets(str, parimaa_na(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ꦱꦼꦢꦼꦭ (file) {
	puur_naa_nka i;
	size_t len = strlen (file->filename);

	ꦱꦼꦢꦼꦭ (fgets(str, parimaa_na(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        ꦪꦼꦤ꧀ ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    bha_nga;
	ꦏꦁꦒꦺꦴ (i = 0; i < file->n_func; i++) {
	    puur_naa_nka j;
	    tcov_function *func = &file->func[i];
	    unsigned puur_naa_nka next_zero = 0;
	    unsigned puur_naa_nka curline = 0;

	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned puur_naa_nka fline = line->fline;
	        unsigned long long count;
		unsigned puur_naa_nka tmp;
		var_na c;

		ꦱꦼꦢꦼꦭ (curline < fline &&
		       fgets(str, parimaa_na(str), fp))
		    ꦪꦼꦤ꧀ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ꦪꦼꦤ꧀ (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ꦪꦼꦤ꧀ (next_zero == 0)
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
    puur_naa_nka i, j;
    unsigned puur_naa_nka files;
    unsigned puur_naa_nka funcs;
    unsigned puur_naa_nka blocks;
    unsigned puur_naa_nka blocks_run;
    unsigned puur_naa_nka runs;
    var_na *cov_filename = (var_na *)p + get_value (p, 4);
    FILE *fp;
    var_na *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ꦪꦼꦤ꧀ (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ꦮꦭꦶ;
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
    ꦱꦼꦢꦼꦭ (nfile) {
	files++;
	ꦏꦁꦒꦺꦴ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ꦪꦼꦤ꧀ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
    nfile = file;
    ꦱꦼꦢꦼꦭ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned puur_naa_nka curline = 1;
	var_na str[10000];

        ꦪꦼꦤ꧀ (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	ꦏꦁꦒꦺꦴ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ꦪꦼꦤ꧀ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
        ꦏꦁꦒꦺꦴ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ꦱꦼꦢꦼꦭ (curline < func->first_line &&
		   fgets(str, parimaa_na(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ꦪꦼꦤ꧀ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (dviguu_na) blocks_run / blocks);
#ꦪꦼꦤ꧀ 0
	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line; j++) {
	        unsigned puur_naa_nka fline = func->line[j].fline;
	        unsigned puur_naa_nka lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    ꦏꦁꦒꦺꦴ (j = 0; j < func->n_line;) {
	        unsigned puur_naa_nka fline = func->line[j].fline;
	        unsigned puur_naa_nka lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned puur_naa_nka has_zero = 0;
		unsigned puur_naa_nka same_line = fline == lline;

		j++;
		ꦱꦼꦢꦼꦭ (j < func->n_line) {
	            unsigned puur_naa_nka nfline = func->line[j].fline;
	            unsigned puur_naa_nka nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ꦪꦼꦤ꧀ (fline == nfline) {
			ꦪꦼꦤ꧀ (ncount == 0)
			    has_zero = 1;
			ꦭꦶꦪ ꦪꦼꦤ꧀ (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ꦭꦶꦪ
			bha_nga;
		}
		ꦪꦼꦤ꧀ (same_line)
		     lline++;

	        ꦱꦼꦢꦼꦭ (curline < fline &&
		       fgets(str, parimaa_na(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ꦱꦼꦢꦼꦭ (curline < lline &&
		       fgets(str, parimaa_na(str), src)) {
		    ꦪꦼꦤ꧀ (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ꦭꦶꦪ ꦪꦼꦤ꧀ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    ꦭꦶꦪ
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	ꦱꦼꦢꦼꦭ (fgets(str, parimaa_na(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ꦱꦼꦢꦼꦭ (file) {
        ꦏꦁꦒꦺꦴ (i = 0; i < file->n_func; i++) {
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
