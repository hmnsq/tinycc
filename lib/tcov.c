#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#ifndef _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#אחרת
#ضمن <windows.h>
#ضمن <io.h>
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

تعريفنوع بنية tcov_line {
    unsigned صحيح fline;
    unsigned صحيح lline;
    unsigned long long count;
} tcov_line;

تعريفنوع بنية tcov_function {
    حرف *function;
    unsigned صحيح first_line;
    unsigned صحيح n_line;
    unsigned صحيح m_line;
    tcov_line *line;
} tcov_function;

تعريفنوع بنية tcov_file {
    حرف *filename;
    unsigned صحيح n_func;
    unsigned صحيح m_func;
    tcov_function *func;
    بنية tcov_file *next;
} tcov_file;

ساكن FILE *open_tcov_file (حرف *cov_filename)
{
    صحيح fd;
#ifndef _WIN32
    بنية flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    אם (fd < 0)
	החזר عدم;
  
#ifndef _WIN32
    כלעוד (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        استمر;
#אחרת
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    החזר fdopen (fd, "r+");
}

ساكن unsigned long long get_value(unsigned حرف *p, صحيح size)
{
    unsigned long long value = 0;

    p += size;
    כלעוד (size--)
 	value = (value << 8) | *--p;
    החזר value;
}

ساكن صحيح sort_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    החזר pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

ساكن صحيح sort_line (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_line *pp = (ثابت tcov_line *) p;
    ثابت tcov_line *pq = (ثابت tcov_line *) q;

    החזר pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->count < pq->count ? 1 :
	   pp->count > pq->count ? -1 : 0;
}

/* sort to let inline functions work */
ساكن tcov_file *sort_test_coverage (unsigned حرف *p)
{
    صحيح i, j, k;
    unsigned حرف *start = p;
    tcov_file *file = عدم;
    tcov_file *nfile;

    p += 4;
    כלעוד (*p) {
        حرف *filename = (حرف *)p;
	size_t len = strlen (filename);

	nfile = file;
	כלעוד (nfile) {
	    אם (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->next;
	}
	אם (nfile == عدم) {
	    nfile = malloc (حجم(tcov_file));
	    אם (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        החזר file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->next = عدم;
	    אם (file == عدم)
	        file = nfile;
	    אחרת {
		tcov_file *lfile = file;

	        כלעוד (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	כלעוד (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    עבור (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		אם (strcmp (func->function, function) == 0)
		    اكسر;
	    }
	    אם (i == nfile->n_func) {
	        אם (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   حجم (tcov_function));
		    אם (nfile->func == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        החזר file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_line = get_value (p, 8);
	        func->n_line = 0;
	        func->m_line = 0;
	        func->line = عدم;
	    }
	    p += 8;
	    כלעוד (*p) {
		tcov_line *line;
		unsigned long long val;

		אם (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * حجم (tcov_line));
		    אם (func->line == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        החזר file;
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
    כלעוד (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), sort_func);
	עבור (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, حجم (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    החזר file;
}

/* merge with previous tcov file */
ساكن فراغ merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned صحيح *pruns)
{
    unsigned صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    אם (fp == عدم)
        החזר;
    אם (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    כלעוד (file) {
	صحيح i;
	size_t len = strlen (file->filename);

	כלעוד (fgets(str, حجم(str), fp) &&
	       (p = strstr(str, "0:File:")) == عدم) {}
        אם ((p = strstr(str, "0:File:")) == عدم ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    اكسر;
	עבור (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    unsigned صحيح next_zero = 0;
	    unsigned صحيح curline = 0;

	    עבור (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned صحيح fline = line->fline;
	        unsigned long long count;
		unsigned صحيح tmp;
		حرف c;

		כלעוד (curline < fline &&
		       fgets(str, حجم(str), fp))
		    אם ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		אם (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    אם (next_zero == 0)
		        line->count += count;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
فراغ __store_test_coverage (unsigned حرف * p)
{
    صحيح i, j;
    unsigned صحيح files;
    unsigned صحيح funcs;
    unsigned صحيح blocks;
    unsigned صحيح blocks_run;
    unsigned صحيح runs;
    حرف *cov_filename = (حرف *)p + get_value (p, 4);
    FILE *fp;
    حرف *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    אם (fp == عدم) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	החזר;
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
    כלעוד (nfile) {
	files++;
	עבור (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    עבור (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    אם (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) blocks_run / blocks);
    nfile = file;
    כלעוד (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned صحيح curline = 1;
	حرف str[10000];

        אם (src == عدم)
	     اذهب next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	עבור (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    עבור (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	אם (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) blocks_run / blocks);
        עבור (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    כלעוד (curline < func->first_line &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    עבור (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    אם (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) blocks_run / blocks);
#אם 0
	    עבור (j = 0; j < func->n_line; j++) {
	        unsigned صحيح fline = func->line[j].fline;
	        unsigned صحيح lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    עבור (j = 0; j < func->n_line;) {
	        unsigned صحيح fline = func->line[j].fline;
	        unsigned صحيح lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned صحيح has_zero = 0;
		unsigned صحيح same_line = fline == lline;

		j++;
		כלעוד (j < func->n_line) {
	            unsigned صحيح nfline = func->line[j].fline;
	            unsigned صحيح nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    אם (fline == nfline) {
			אם (ncount == 0)
			    has_zero = 1;
			אחרת אם (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    אחרת
			اكسر;
		}
		אם (same_line)
		     lline++;

	        כלעוד (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		כלעוד (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    אם (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    אחרת אם (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    אחרת
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	כלעוד (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    כלעוד (file) {
        עבור (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    حرر (func->line);
        }
	حرر (file->func);
	nfile = file;
	file = file->next;
	حرر (nfile);
    }
    fclose (fp);
}
