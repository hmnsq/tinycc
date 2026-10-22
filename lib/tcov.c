#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#ifndef _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#وإلا
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
    𐤀𐤌 (fd < 0)
	أرجع عدم;
  
#ifndef _WIN32
    طالما (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        استمر;
#وإلا
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    أرجع fdopen (fd, "r+");
}

ساكن unsigned long long get_value(unsigned حرف *p, صحيح size)
{
    unsigned long long value = 0;

    p += size;
    طالما (size--)
 	value = (value << 8) | *--p;
    أرجع value;
}

ساكن صحيح sort_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    أرجع pp->first_line > pq->first_line ? 1 :
	   pp->first_line < pq->first_line ? -1 : 0;
}

ساكن صحيح sort_line (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_line *pp = (ثابت tcov_line *) p;
    ثابت tcov_line *pq = (ثابت tcov_line *) q;

    أرجع pp->fline > pq->fline ? 1 :
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
    طالما (*p) {
        حرف *filename = (حرف *)p;
	size_t len = strlen (filename);

	nfile = file;
	طالما (nfile) {
	    𐤀𐤌 (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->next;
	}
	𐤀𐤌 (nfile == عدم) {
	    nfile = malloc (حجم(tcov_file));
	    𐤀𐤌 (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        أرجع file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->next = عدم;
	    𐤀𐤌 (file == عدم)
	        file = nfile;
	    وإلا {
		tcov_file *lfile = file;

	        طالما (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	طالما (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    لكل (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		𐤀𐤌 (strcmp (func->function, function) == 0)
		    اكسر;
	    }
	    𐤀𐤌 (i == nfile->n_func) {
	        𐤀𐤌 (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   حجم (tcov_function));
		    𐤀𐤌 (nfile->func == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
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
	    طالما (*p) {
		tcov_line *line;
		unsigned long long val;

		𐤀𐤌 (func->n_line >= func->m_line) {
		    func->m_line = func->m_line == 0 ? 4 : func->m_line * 2;
		    func->line = realloc (func->line,
					  func->m_line * حجم (tcov_line));
		    𐤀𐤌 (func->line == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
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
    طالما (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), sort_func);
	لكل (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->line, func->n_line, حجم (tcov_line), sort_line);
        }
	nfile = nfile->next;
    }
    أرجع file;
}

/* merge with previous tcov file */
ساكن فراغ merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned صحيح *pruns)
{
    unsigned صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    𐤀𐤌 (fp == عدم)
        أرجع;
    𐤀𐤌 (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    طالما (file) {
	صحيح i;
	size_t len = strlen (file->filename);

	طالما (fgets(str, حجم(str), fp) &&
	       (p = strstr(str, "0:File:")) == عدم) {}
        𐤀𐤌 ((p = strstr(str, "0:File:")) == عدم ||
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

		طالما (curline < fline &&
		       fgets(str, حجم(str), fp))
		    𐤀𐤌 ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		𐤀𐤌 (sscanf (str, "%llu%c\n", &count, &c) == 2) {
		    𐤀𐤌 (next_zero == 0)
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
    𐤀𐤌 (fp == عدم) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	أرجع;
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
    طالما (nfile) {
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
    𐤀𐤌 (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) blocks_run / blocks);
    nfile = file;
    طالما (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned صحيح curline = 1;
	حرف str[10000];

        𐤀𐤌 (src == عدم)
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
	𐤀𐤌 (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) blocks_run / blocks);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    طالما (curline < func->first_line &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    لكل (j = 0; j < func->n_line; j++) {
		blocks++;
		blocks_run += func->line[j].count != 0;
	    }
	    𐤀𐤌 (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) blocks_run / blocks);
#𐤀𐤌 0
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
		طالما (j < func->n_line) {
	            unsigned صحيح nfline = func->line[j].fline;
	            unsigned صحيح nlline = func->line[j].lline;
	            unsigned long long ncount = func->line[j].count;

		    𐤀𐤌 (fline == nfline) {
			𐤀𐤌 (ncount == 0)
			    has_zero = 1;
			وإلا 𐤀𐤌 (ncount > count)
			    count =  ncount;
			same_line = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وإلا
			اكسر;
		}
		𐤀𐤌 (same_line)
		     lline++;

	        طالما (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		طالما (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    𐤀𐤌 (count == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وإلا 𐤀𐤌 (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 count, curline, str);
		    وإلا
		        fprintf (fp, "%9llu:%5u:%s",
				 count, curline, str);
		    curline++;
		}
	    }
	}
	طالما (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    طالما (file) {
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
