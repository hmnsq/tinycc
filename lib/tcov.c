#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#ifndef _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#ܐܚܪܢܐ
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
    ܐܢ (fd < 0)
	ܦܢܐ عدم;
  
#ifndef _WIN32
    ܟܡܐ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        استمر;
#ܐܚܪܢܐ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ܦܢܐ fdopen (fd, "r+");
}

ساكن unsigned long long get_value(unsigned حرف *p, صحيح size)
{
    unsigned long long value = 0;

    p += size;
    ܟܡܐ (size--)
 	value = (value << 8) | *--p;
    ܦܢܐ value;
}

ساكن صحيح sort_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    ܦܢܐ pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

ساكن صحيح sort_line (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_line *pp = (ثابت tcov_line *) p;
    ثابت tcov_line *pq = (ثابت tcov_line *) q;

    ܦܢܐ pp->fline > pq->fline ? 1 :
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
    ܟܡܐ (*p) {
        حرف *filename = (حرف *)p;
	size_t len = strlen (filename);

	nfile = file;
	ܟܡܐ (nfile) {
	    ܐܢ (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->next;
	}
	ܐܢ (nfile == عدم) {
	    nfile = malloc (حجم(tcov_file));
	    ܐܢ (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ܦܢܐ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->next = عدم;
	    ܐܢ (file == عدم)
	        file = nfile;
	    ܐܚܪܢܐ {
		tcov_file *lfile = file;

	        ܟܡܐ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ܟܡܐ (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    لكل (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ܐܢ (strcmp (func->function, function) == 0)
		    اكسر;
	    }
	    ܐܢ (i == nfile->n_func) {
	        ܐܢ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   حجم (tcov_function));
		    ܐܢ (nfile->func == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ܦܢܐ file;
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
	    ܟܡܐ (*p) {
		tcov_line *line;
		unsigned long long val;

		ܐܢ (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * حجم (tcov_line));
		    ܐܢ (func->line == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ܦܢܐ file;
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
    ܟܡܐ (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), sort_func);
	لكل (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, حجم (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    ܦܢܐ file;
}

/* merge with previous tcov file */
ساكن فراغ merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned صحيح *pruns)
{
    unsigned صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    ܐܢ (fp == عدم)
        ܦܢܐ;
    ܐܢ (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ܟܡܐ (file) {
	صحيح i;
	size_t len = strlen (file->filename);

	ܟܡܐ (fgets(str, حجم(str), fp) &&
	       (p = strstr(str, "0:File:")) == عدم) {}
        ܐܢ ((p = strstr(str, "0:File:")) == عدم ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    اكسر;
	لكل (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    unsigned صحيح next_zero = 0;
	    unsigned صحيح curline = 0;

	    لكل (j = 0; j < func->n_line; j++) {
		tcov_line *line = &func->line[j];
	        unsigned صحيح fline = line->fline;
	        unsigned long long count;
		unsigned صحيح tmp;
		حرف c;

		ܟܡܐ (curline < fline &&
		       fgets(str, حجم(str), fp))
		    ܐܢ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ܐܢ (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    ܐܢ (next_zero == 0)
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
    ܐܢ (fp == عدم) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ܦܢܐ;
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
    ܟܡܐ (nfile) {
	files++;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	nfile = nfile->next;
    }
    ܐܢ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) blocks_run / blocks);
    nfile = file;
    ܟܡܐ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned صحيح curline = 1;
	حرف str[10000];

        ܐܢ (src == عدم)
	     اذهب next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	}
	ܐܢ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) blocks_run / blocks);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ܟܡܐ (curline < func->first_line &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    لكل (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    ܐܢ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) blocks_run / blocks);
#ܐܢ 0
	    لكل (j = 0; j < func->n_line; j++) {
	        unsigned صحيح fline = func->line[j].fline;
	        unsigned صحيح lline = func->line[j].lline;
		unsigned long long count = func->line[j].count;

		fprintf (fp, "%u %u %llu\n", fline, lline, count);
	    }
#endif
	    لكل (j = 0; j < func->n_line;) {
	        unsigned صحيح fline = func->line[j].fline;
	        unsigned صحيح lline = func->line[j].lline;
	        unsigned long long count = func->line[j].count;
		unsigned صحيح has_zero = 0;
		unsigned صحيح same_line = fline == lline;

		j++;
		ܟܡܐ (j < func->n_line) {
	            unsigned صحيح nfline = func->line[j].fline;
	            unsigned صحيح nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    ܐܢ (fline == nfline) {
			ܐܢ (ncount == 0)
			    has_zero = 1;
			ܐܚܪܢܐ ܐܢ (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ܐܚܪܢܐ
			اكسر;
		}
		ܐܢ (same_line)
		     lline++;

	        ܟܡܐ (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ܟܡܐ (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    ܐܢ (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ܐܚܪܢܐ ܐܢ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    ܐܚܪܢܐ
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	ܟܡܐ (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ܟܡܐ (file) {
        لكل (i = 0; i < file->n_func; i++) {
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
