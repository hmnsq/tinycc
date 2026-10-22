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

تعريفنوع بنية tcov_هێڵ {
    unsigned صحيح fline;
    unsigned صحيح lline;
    unsigned long long ژماردن_2;
} tcov_هێڵ;

تعريفنوع بنية tcov_function {
    حرف *function;
    unsigned صحيح first_هێڵ;
    unsigned صحيح n_هێڵ;
    unsigned صحيح m_هێڵ;
    tcov_هێڵ *هێڵ;
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
    إذا (fd < 0)
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

ساكن unsigned long long get_بەها(unsigned حرف *p, صحيح size)
{
    unsigned long long بەها = 0;

    p += size;
    طالما (size--)
 	بەها = (بەها << 8) | *--p;
    أرجع بەها;
}

ساكن صحيح sort_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    أرجع pp->first_هێڵ > pq->first_هێڵ ? 1 :
	   pp->first_هێڵ < pq->first_هێڵ ? -1 : 0;
}

ساكن صحيح sort_هێڵ (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_هێڵ *pp = (ثابت tcov_هێڵ *) p;
    ثابت tcov_هێڵ *pq = (ثابت tcov_هێڵ *) q;

    أرجع pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ژماردن_2 < pq->ژماردن_2 ? 1 :
	   pp->ژماردن_2 > pq->ژماردن_2 ? -1 : 0;
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
	    إذا (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->next;
	}
	إذا (nfile == عدم) {
	    nfile = malloc (حجم(tcov_file));
	    إذا (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        أرجع file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->next = عدم;
	    إذا (file == عدم)
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
		إذا (strcmp (func->function, function) == 0)
		    اكسر;
	    }
	    إذا (i == nfile->n_func) {
	        إذا (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   حجم (tcov_function));
		    إذا (nfile->func == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_هێڵ = get_بەها (p, 8);
	        func->n_هێڵ = 0;
	        func->m_هێڵ = 0;
	        func->هێڵ = عدم;
	    }
	    p += 8;
	    طالما (*p) {
		tcov_هێڵ *هێڵ;
		unsigned long long val;

		إذا (func->n_هێڵ >= func->m_هێڵ) {
		    func->m_هێڵ = func->m_هێڵ == 0 ? 4 : func->m_هێڵ * 2;
		    func->هێڵ = realloc (func->هێڵ,
					  func->m_هێڵ * حجم (tcov_هێڵ));
		    إذا (func->هێڵ == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
		    }
		}
		هێڵ = &func->هێڵ[func->n_هێڵ++];
		val = get_بەها (p, 8);
	        هێڵ->fline = (val >> 8) & 0xfffffffULL;
	        هێڵ->lline = val >> 36;
	        هێڵ->ژماردن_2 = get_بەها (p + 8, 8);
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
	    qsort (func->هێڵ, func->n_هێڵ, حجم (tcov_هێڵ), sort_هێڵ);
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
    إذا (fp == عدم)
        أرجع;
    إذا (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    طالما (file) {
	صحيح i;
	size_t len = strlen (file->filename);

	طالما (fgets(str, حجم(str), fp) &&
	       (p = strstr(str, "0:File:")) == عدم) {}
        إذا ((p = strstr(str, "0:File:")) == عدم ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    اكسر;
	لكل (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    unsigned صحيح next_zero = 0;
	    unsigned صحيح curline = 0;

	    لكل (j = 0; j < func->n_هێڵ; j++) {
		tcov_هێڵ *هێڵ = &func->هێڵ[j];
	        unsigned صحيح fline = هێڵ->fline;
	        unsigned long long ژماردن_2;
		unsigned صحيح tmp;
		حرف c;

		طالما (curline < fline &&
		       fgets(str, حجم(str), fp))
		    إذا ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		إذا (sscanf (str, "%llu%c\n", &ژماردن_2, &c) == 2) {
		    إذا (next_zero == 0)
		        هێڵ->ژماردن_2 += ژماردن_2;
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
    حرف *cov_filename = (حرف *)p + get_بەها (p, 4);
    FILE *fp;
    حرف *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    إذا (fp == عدم) {
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
	    لكل (j = 0; j < func->n_هێڵ; j++) {
		blocks++;
		blocks_run += func->هێڵ[j].ژماردن_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    إذا (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) blocks_run / blocks);
    nfile = file;
    طالما (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned صحيح curline = 1;
	حرف str[10000];

        إذا (src == عدم)
	     اذهب next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_هێڵ; j++) {
		blocks++;
		blocks_run += func->هێڵ[j].ژماردن_2 != 0;
	    }
	}
	إذا (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) blocks_run / blocks);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    طالما (curline < func->first_هێڵ &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    لكل (j = 0; j < func->n_هێڵ; j++) {
		blocks++;
		blocks_run += func->هێڵ[j].ژماردن_2 != 0;
	    }
	    إذا (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) blocks_run / blocks);
#إذا 0
	    لكل (j = 0; j < func->n_هێڵ; j++) {
	        unsigned صحيح fline = func->هێڵ[j].fline;
	        unsigned صحيح lline = func->هێڵ[j].lline;
		unsigned long long ژماردن_2 = func->هێڵ[j].ژماردن_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, ژماردن_2);
	    }
#endif
	    لكل (j = 0; j < func->n_هێڵ;) {
	        unsigned صحيح fline = func->هێڵ[j].fline;
	        unsigned صحيح lline = func->هێڵ[j].lline;
	        unsigned long long ژماردن_2 = func->هێڵ[j].ژماردن_2;
		unsigned صحيح has_zero = 0;
		unsigned صحيح same_هێڵ = fline == lline;

		j++;
		طالما (j < func->n_هێڵ) {
	            unsigned صحيح nfline = func->هێڵ[j].fline;
	            unsigned صحيح nlline = func->هێڵ[j].lline;
	            unsigned long long ncount = func->هێڵ[j].ژماردن_2;

		    إذا (fline == nfline) {
			إذا (ncount == 0)
			    has_zero = 1;
			وإلا إذا (ncount > ژماردن_2)
			    ژماردن_2 =  ncount;
			same_هێڵ = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وإلا
			اكسر;
		}
		إذا (same_هێڵ)
		     lline++;

	        طالما (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		طالما (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    إذا (ژماردن_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وإلا إذا (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ژماردن_2, curline, str);
		    وإلا
		        fprintf (fp, "%9llu:%5u:%s",
				 ژماردن_2, curline, str);
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
	    حرر (func->هێڵ);
        }
	حرر (file->func);
	nfile = file;
	file = file->next;
	حرر (nfile);
    }
    fclose (fp);
}
