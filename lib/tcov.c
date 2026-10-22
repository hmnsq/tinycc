#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#اگر_تعریف_نشده _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#وإلا
#ضمن <windows.h>
#ضمن <io.h>
#پایان_اگر

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

تعريفنوع بنية tcov_سطر {
    بیعلامت صحيح fline;
    بیعلامت صحيح lline;
    بیعلامت دراز دراز شمار_2;
} tcov_سطر;

تعريفنوع بنية tcov_function {
    حرف *function;
    بیعلامت صحيح اولی_سطر;
    بیعلامت صحيح n_سطر;
    بیعلامت صحيح m_سطر;
    tcov_سطر *سطر;
} tcov_function;

تعريفنوع بنية tcov_file {
    حرف *filename;
    بیعلامت صحيح n_func;
    بیعلامت صحيح m_func;
    tcov_function *func;
    بنية tcov_file *بعدی;
} tcov_file;

ساكن FILE *open_tcov_file (حرف *cov_filename)
{
    صحيح fd;
#اگر_تعریف_نشده _WIN32
    بنية flock قفل;

    قفل.l_type = F_WRLCK;
    قفل.l_whence = SEEK_SET;
    قفل.l_start = 0;
    قفل.l_len = 0; /* Until EOF.  */
    قفل.l_pid = getpid ();
#پایان_اگر
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    إذا (fd < 0)
	أرجع عدم;
  
#اگر_تعریف_نشده _WIN32
    طالما (fcntl (fd, F_SETLKW, &قفل) && errno == EINTR)
        استمر;
#وإلا
    {
        OVERLAPPED overlapped = { 0 };
        قفل_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_قفل,
		   0, 1, 0, &overlapped);
    }
#پایان_اگر

    أرجع fdopen (fd, "r+");
}

ساكن بیعلامت دراز دراز get_مقدار(بیعلامت حرف *p, صحيح اندازه)
{
    بیعلامت دراز دراز مقدار = 0;

    p += اندازه;
    طالما (اندازه--)
 	مقدار = (مقدار << 8) | *--p;
    أرجع مقدار;
}

ساكن صحيح مرتب_سازی_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    أرجع pp->اولی_سطر > pq->اولی_سطر ? 1 :
	   pp->اولی_سطر < pq->اولی_سطر ? -1 : 0;
}

ساكن صحيح مرتب_سازی_سطر (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_سطر *pp = (ثابت tcov_سطر *) p;
    ثابت tcov_سطر *pq = (ثابت tcov_سطر *) q;

    أرجع pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->شمار_2 < pq->شمار_2 ? 1 :
	   pp->شمار_2 > pq->شمار_2 ? -1 : 0;
}

/* sort to let inline functions work */
ساكن tcov_file *مرتب_سازی_test_coverage (بیعلامت حرف *p)
{
    صحيح i, j, k;
    بیعلامت حرف *شروع = p;
    tcov_file *file = عدم;
    tcov_file *nfile;

    p += 4;
    طالما (*p) {
        حرف *filename = (حرف *)p;
	اندازه_t len = طول_رشته (filename);

	nfile = file;
	طالما (nfile) {
	    إذا (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->بعدی;
	}
	إذا (nfile == عدم) {
	    nfile = حافظه_بده (حجم(tcov_file));
	    إذا (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        أرجع file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->بعدی = عدم;
	    إذا (file == عدم)
	        file = nfile;
	    وإلا {
		tcov_file *lfile = file;

	        طالما (lfile->بعدی)
		    lfile = lfile->بعدی;
		lfile->بعدی = nfile;
	    }
	}
	p += len + 1;
	طالما (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += طول_رشته (function) + 1;
	    p += -(p - شروع) & 7;
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
	        func->اولی_سطر = get_مقدار (p, 8);
	        func->n_سطر = 0;
	        func->m_سطر = 0;
	        func->سطر = عدم;
	    }
	    p += 8;
	    طالما (*p) {
		tcov_سطر *سطر;
		بیعلامت دراز دراز val;

		إذا (func->n_سطر >= func->m_سطر) {
		    func->m_سطر = func->m_سطر == 0 ? 4 : func->m_سطر * 2;
		    func->سطر = realloc (func->سطر,
					  func->m_سطر * حجم (tcov_سطر));
		    إذا (func->سطر == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
		    }
		}
		سطر = &func->سطر[func->n_سطر++];
		val = get_مقدار (p, 8);
	        سطر->fline = (val >> 8) & 0xfffffffULL;
	        سطر->lline = val >> 36;
	        سطر->شمار_2 = get_مقدار (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    طالما (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), مرتب_سازی_func);
	لكل (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->سطر, func->n_سطر, حجم (tcov_سطر), مرتب_سازی_سطر);
        }
	nfile = nfile->بعدی;
    }
    أرجع file;
}

/* merge with previous tcov file */
ساكن فراغ ادغام_test_coverage (tcov_file *file, FILE *fp,
				 بیعلامت صحيح *pruns)
{
    بیعلامت صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    إذا (fp == عدم)
        أرجع;
    إذا (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (از_رشته_بخوان (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    طالما (file) {
	صحيح i;
	اندازه_t len = طول_رشته (file->filename);

	طالما (fgets(str, حجم(str), fp) &&
	       (p = جستجوی_رشته(str, "0:File:")) == عدم) {}
        إذا ((p = جستجوی_رشته(str, "0:File:")) == عدم ||
	    مقایسه_رشته (p + طول_رشته("0:File:"), file->filename, len) != 0 ||
	    p[طول_رشته("0:File:") + len] != ' ')
	    اكسر;
	لكل (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    بیعلامت صحيح بعدی_zero = 0;
	    بیعلامت صحيح curline = 0;

	    لكل (j = 0; j < func->n_سطر; j++) {
		tcov_سطر *سطر = &func->سطر[j];
	        بیعلامت صحيح fline = سطر->fline;
	        بیعلامت دراز دراز شمار_2;
		بیعلامت صحيح tmp;
		حرف c;

		طالما (curline < fline &&
		       fgets(str, حجم(str), fp))
		    إذا ((p = strchr(str, ':')) &&
			از_رشته_بخوان (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		إذا (از_رشته_بخوان (str, "%llu%c\n", &شمار_2, &c) == 2) {
		    إذا (بعدی_zero == 0)
		        سطر->شمار_2 += شمار_2;
		    بعدی_zero = c == '*';
		}
	    }
	}
	file = file->بعدی;
    }
}

/* store tcov data in file */
فراغ __store_test_coverage (بیعلامت حرف * p)
{
    صحيح i, j;
    بیعلامت صحيح files;
    بیعلامت صحيح funcs;
    بیعلامت صحيح بلوکها;
    بیعلامت صحيح بلوکها_پیاپی;
    بیعلامت صحيح runs;
    حرف *cov_filename = (حرف *)p + get_مقدار (p, 4);
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
    file = مرتب_سازی_test_coverage (p);
    ادغام_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    بلوکها = 0;
    بلوکها_پیاپی = 0;
    nfile = file;
    طالما (nfile) {
	files++;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_سطر; j++) {
		بلوکها++;
		بلوکها_پیاپی += func->سطر[j].شمار_2 != 0;
	    }
	}
	nfile = nfile->بعدی;
    }
    إذا (بلوکها == 0)
	بلوکها = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) بلوکها_پیاپی / بلوکها);
    nfile = file;
    طالما (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	بیعلامت صحيح curline = 1;
	حرف str[10000];

        إذا (src == عدم)
	     اذهب بعدی;
	funcs = 0;
	بلوکها = 0;
	بلوکها_پیاپی = 0;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_سطر; j++) {
		بلوکها++;
		بلوکها_پیاپی += func->سطر[j].شمار_2 != 0;
	    }
	}
	إذا (بلوکها == 0)
	    بلوکها = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) بلوکها_پیاپی / بلوکها);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    طالما (curline < func->اولی_سطر &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    بلوکها = 0;
	    بلوکها_پیاپی = 0;
	    لكل (j = 0; j < func->n_سطر; j++) {
		بلوکها++;
		بلوکها_پیاپی += func->سطر[j].شمار_2 != 0;
	    }
	    إذا (بلوکها == 0)
		بلوکها = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) بلوکها_پیاپی / بلوکها);
#إذا 0
	    لكل (j = 0; j < func->n_سطر; j++) {
	        بیعلامت صحيح fline = func->سطر[j].fline;
	        بیعلامت صحيح lline = func->سطر[j].lline;
		بیعلامت دراز دراز شمار_2 = func->سطر[j].شمار_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, شمار_2);
	    }
#پایان_اگر
	    لكل (j = 0; j < func->n_سطر;) {
	        بیعلامت صحيح fline = func->سطر[j].fline;
	        بیعلامت صحيح lline = func->سطر[j].lline;
	        بیعلامت دراز دراز شمار_2 = func->سطر[j].شمار_2;
		بیعلامت صحيح has_zero = 0;
		بیعلامت صحيح same_سطر = fline == lline;

		j++;
		طالما (j < func->n_سطر) {
	            بیعلامت صحيح nfline = func->سطر[j].fline;
	            بیعلامت صحيح nlline = func->سطر[j].lline;
	            بیعلامت دراز دراز ncount = func->سطر[j].شمار_2;

		    إذا (fline == nfline) {
			إذا (ncount == 0)
			    has_zero = 1;
			وإلا إذا (ncount > شمار_2)
			    شمار_2 =  ncount;
			same_سطر = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وإلا
			اكسر;
		}
		إذا (same_سطر)
		     lline++;

	        طالما (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		طالما (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    إذا (شمار_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وإلا إذا (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 شمار_2, curline, str);
		    وإلا
		        fprintf (fp, "%9llu:%5u:%s",
				 شمار_2, curline, str);
		    curline++;
		}
	    }
	}
	طالما (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
بعدی:
	nfile = nfile->بعدی;
    }
    طالما (file) {
        لكل (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    حرر (func->سطر);
        }
	حرر (file->func);
	nfile = file;
	file = file->بعدی;
	حرر (nfile);
    }
    fclose (fp);
}
