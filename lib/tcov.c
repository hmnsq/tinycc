#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef _WIN32
#include <unistd.h>
#include <errno.h>
#ບໍ່ດັ່ງນັ້ນ
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
    unsigned ຈຳນວນເຕັມ fline;
    unsigned ຈຳນວນເຕັມ lline;
    unsigned long long count;
} tcov_line;

typedef sa_nracanaa tcov_function {
    var_na *function;
    unsigned ຈຳນວນເຕັມ first_line;
    unsigned ຈຳນວນເຕັມ n_line;
    unsigned ຈຳນວນເຕັມ m_line;
    tcov_line *line;
} tcov_function;

typedef sa_nracanaa tcov_file {
    var_na *filename;
    unsigned ຈຳນວນເຕັມ n_func;
    unsigned ຈຳນວນເຕັມ m_func;
    tcov_function *func;
    sa_nracanaa tcov_file *next;
} tcov_file;

static FILE *open_tcov_file (var_na *cov_filename)
{
    ຈຳນວນເຕັມ fd;
#ifndef _WIN32
    sa_nracanaa flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ຖ້າ (fd < 0)
	ສົ່ງຄືນ NULL;
  
#ifndef _WIN32
    ໃນຂະນະທີ່ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        continue;
#ບໍ່ດັ່ງນັ້ນ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ສົ່ງຄືນ fdopen (fd, "r+");
}

static unsigned long long get_value(unsigned var_na *p, ຈຳນວນເຕັມ size)
{
    unsigned long long value = 0;

    p += size;
    ໃນຂະນະທີ່ (size--)
 	value = (value << 8) | *--p;
    ສົ່ງຄືນ value;
}

static ຈຳນວນເຕັມ sort_func (const void *p, const void *q)
{
    const tcov_function *pp = (const tcov_function *) p;
    const tcov_function *pq = (const tcov_function *) q;

    ສົ່ງຄືນ pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

static ຈຳນວນເຕັມ sort_line (const void *p, const void *q)
{
    const tcov_line *pp = (const tcov_line *) p;
    const tcov_line *pq = (const tcov_line *) q;

    ສົ່ງຄືນ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
static tcov_file *sort_test_coverage (unsigned var_na *p)
{
    ຈຳນວນເຕັມ i, j, k;
    unsigned var_na *start = p;
    tcov_file *file = NULL;
    tcov_file *nfile;

    p += 4;
    ໃນຂະນະທີ່ (*p) {
        var_na *filename = (var_na *)p;
	size_t len = strlen (filename);

	nfile = file;
	ໃນຂະນະທີ່ (nfile) {
	    ຖ້າ (strcmp (nfile->filename, filename) == 0)
		bha_nga;
	    nfile = nfile->next;
	}
	ຖ້າ (nfile == NULL) {
	    nfile = malloc (parimaa_na(tcov_file));
	    ຖ້າ (nfile == NULL) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ສົ່ງຄືນ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = NULL;
	    nfile->next = NULL;
	    ຖ້າ (file == NULL)
	        file = nfile;
	    ບໍ່ດັ່ງນັ້ນ {
		tcov_file *lfile = file;

	        ໃນຂະນະທີ່ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ໃນຂະນະທີ່ (*p) {
	    ຈຳນວນເຕັມ i;
	    var_na *function = (var_na *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    ສຳລັບ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ຖ້າ (strcmp (func->function, function) == 0)
		    bha_nga;
	    }
	    ຖ້າ (i == nfile->n_func) {
	        ຖ້າ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   parimaa_na (tcov_function));
		    ຖ້າ (nfile->func == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ສົ່ງຄືນ file;
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
	    ໃນຂະນະທີ່ (*p) {
		tcov_line *line;
		unsigned long long val;

		ຖ້າ (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * parimaa_na (tcov_line));
		    ຖ້າ (func->line == NULL) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ສົ່ງຄືນ file;
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
    ໃນຂະນະທີ່ (nfile) {
	qsort (nfile->func, nfile->n_func, parimaa_na (tcov_function), sort_func);
	ສຳລັບ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, parimaa_na (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    ສົ່ງຄືນ file;
}

/* merge with previous tcov file */
static void merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned ຈຳນວນເຕັມ *pruns)
{
    unsigned ຈຳນວນເຕັມ runs;
    var_na *p;
    var_na str[10000];
    
    *pruns = 1;
    ຖ້າ (fp == NULL)
        ສົ່ງຄືນ;
    ຖ້າ (fgets(str, parimaa_na(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ໃນຂະນະທີ່ (file) {
	ຈຳນວນເຕັມ i;
	size_t len = strlen (file->filename);

	ໃນຂະນະທີ່ (fgets(str, parimaa_na(str), fp) &&
	       (p = strstr(str, "0:File:")) == NULL) {}
        ຖ້າ ((p = strstr(str, "0:File:")) == NULL ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    bha_nga;
	ສຳລັບ (i = 0; i < file->n_func; i++) {
	    ຈຳນວນເຕັມ j;
	    tcov_function *func = &file->func[i];
	    unsigned ຈຳນວນເຕັມ next_zero = 0;
	    unsigned ຈຳນວນເຕັມ curline = 0;

	    ສຳລັບ (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned ຈຳນວນເຕັມ fline = line->fline;
	        unsigned long long count;
		unsigned ຈຳນວນເຕັມ tmp;
		var_na c;

		ໃນຂະນະທີ່ (curline < fline &&
		       fgets(str, parimaa_na(str), fp))
		    ຖ້າ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ຖ້າ (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ຖ້າ (next_zero == 0)
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
    ຈຳນວນເຕັມ i, j;
    unsigned ຈຳນວນເຕັມ files;
    unsigned ຈຳນວນເຕັມ funcs;
    unsigned ຈຳນວນເຕັມ blocks;
    unsigned ຈຳນວນເຕັມ blocks_run;
    unsigned ຈຳນວນເຕັມ runs;
    var_na *cov_filename = (var_na *)p + get_value (p, 4);
    FILE *fp;
    var_na *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ຖ້າ (fp == NULL) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ສົ່ງຄືນ;
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
    ໃນຂະນະທີ່ (nfile) {
	files++;
	ສຳລັບ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ສຳລັບ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ຖ້າ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
    nfile = file;
    ໃນຂະນະທີ່ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned ຈຳນວນເຕັມ curline = 1;
	var_na str[10000];

        ຖ້າ (src == NULL)
	     goto next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	ສຳລັບ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ສຳລັບ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ຖ້າ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (dviguu_na) blocks_run / blocks);
        ສຳລັບ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ໃນຂະນະທີ່ (curline < func->first_line &&
		   fgets(str, parimaa_na(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    ສຳລັບ (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ຖ້າ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (dviguu_na) blocks_run / blocks);
#ຖ້າ 0
	    ສຳລັບ (j = 0; j < func->n_line; j++) {
	        unsigned ຈຳນວນເຕັມ fline = func->line[j].fline;
	        unsigned ຈຳນວນເຕັມ lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    ສຳລັບ (j = 0; j < func->n_line;) {
	        unsigned ຈຳນວນເຕັມ fline = func->line[j].fline;
	        unsigned ຈຳນວນເຕັມ lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned ຈຳນວນເຕັມ has_zero = 0;
		unsigned ຈຳນວນເຕັມ same_line = fline == lline;

		j++;
		ໃນຂະນະທີ່ (j < func->n_line) {
	            unsigned ຈຳນວນເຕັມ nfline = func->line[j].fline;
	            unsigned ຈຳນວນເຕັມ nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ຖ້າ (fline == nfline) {
			ຖ້າ (ncount == 0)
			    has_zero = 1;
			ບໍ່ດັ່ງນັ້ນ ຖ້າ (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ບໍ່ດັ່ງນັ້ນ
			bha_nga;
		}
		ຖ້າ (same_line)
		     lline++;

	        ໃນຂະນະທີ່ (curline < fline &&
		       fgets(str, parimaa_na(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ໃນຂະນະທີ່ (curline < lline &&
		       fgets(str, parimaa_na(str), src)) {
		    ຖ້າ (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ບໍ່ດັ່ງນັ້ນ ຖ້າ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    ບໍ່ດັ່ງນັ້ນ
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	ໃນຂະນະທີ່ (fgets(str, parimaa_na(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ໃນຂະນະທີ່ (file) {
        ສຳລັບ (i = 0; i < file->n_func; i++) {
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
