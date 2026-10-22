#شامل <stdio.h>
#شامل <string.h>
#شامل <stdlib.h>
#شامل <fcntl.h>
#اگر_غیر_تعریف_شدہ _WIN32
#شامل <unistd.h>
#شامل <errno.h>
#ورنہ
#شامل <windows.h>
#شامل <io.h>
#اگر_ختم

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

قسمتعریف ساخت tcov_سطر {
    غیرعلامتی صحیح fline;
    غیرعلامتی صحیح lline;
    غیرعلامتی طویل طویل گنتی_2;
} tcov_سطر;

قسمتعریف ساخت tcov_function {
    حرف *function;
    غیرعلامتی صحیح پہلا_سطر;
    غیرعلامتی صحیح n_سطر;
    غیرعلامتی صحیح m_سطر;
    tcov_سطر *سطر;
} tcov_function;

قسمتعریف ساخت tcov_file {
    حرف *filename;
    غیرعلامتی صحیح n_func;
    غیرعلامتی صحیح m_func;
    tcov_function *func;
    ساخت tcov_file *اگلا;
} tcov_file;

ساکن FILE *open_tcov_file (حرف *cov_filename)
{
    صحیح fd;
#اگر_غیر_تعریف_شدہ _WIN32
    ساخت flock تالا;

    تالا.l_type = F_WRLCK;
    تالا.l_whence = SEEK_SET;
    تالا.l_start = 0;
    تالا.l_len = 0; /* Until EOF.  */
    تالا.l_pid = getpid ();
#اگر_ختم
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    اگر (fd < 0)
	واپس تہی;
  
#اگر_غیر_تعریف_شدہ _WIN32
    جب (fcntl (fd, F_SETLKW, &تالا) && errno == EINTR)
        جاری;
#ورنہ
    {
        OVERLAPPED overlapped = { 0 };
        تالا_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_تالا,
		   0, 1, 0, &overlapped);
    }
#اگر_ختم

    واپس fdopen (fd, "r+");
}

ساکن غیرعلامتی طویل طویل get_قدر(غیرعلامتی حرف *p, صحیح سائز)
{
    غیرعلامتی طویل طویل قدر = 0;

    p += سائز;
    جب (سائز--)
 	قدر = (قدر << 8) | *--p;
    واپس قدر;
}

ساکن صحیح ترتیب_دو_func (ثابت خالی *p, ثابت خالی *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    واپس pp->پہلا_سطر > pq->پہلا_سطر ? 1 :
	   pp->پہلا_سطر < pq->پہلا_سطر ? -1 : 0;
}

ساکن صحیح ترتیب_دو_سطر (ثابت خالی *p, ثابت خالی *q)
{
    ثابت tcov_سطر *pp = (ثابت tcov_سطر *) p;
    ثابت tcov_سطر *pq = (ثابت tcov_سطر *) q;

    واپس pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->گنتی_2 < pq->گنتی_2 ? 1 :
	   pp->گنتی_2 > pq->گنتی_2 ? -1 : 0;
}

/* sort to let inline functions work */
ساکن tcov_file *ترتیب_دو_test_coverage (غیرعلامتی حرف *p)
{
    صحیح i, j, k;
    غیرعلامتی حرف *آغاز = p;
    tcov_file *file = تہی;
    tcov_file *nfile;

    p += 4;
    جب (*p) {
        حرف *filename = (حرف *)p;
	سائز_t len = لڑی_لمبائی (filename);

	nfile = file;
	جب (nfile) {
	    اگر (strcmp (nfile->filename, filename) == 0)
		توڑو;
	    nfile = nfile->اگلا;
	}
	اگر (nfile == تہی) {
	    nfile = حافظہ_دو (حجم(tcov_file));
	    اگر (nfile == تہی) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        واپس file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = تہی;
	    nfile->اگلا = تہی;
	    اگر (file == تہی)
	        file = nfile;
	    ورنہ {
		tcov_file *lfile = file;

	        جب (lfile->اگلا)
		    lfile = lfile->اگلا;
		lfile->اگلا = nfile;
	    }
	}
	p += len + 1;
	جب (*p) {
	    صحیح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += لڑی_لمبائی (function) + 1;
	    p += -(p - آغاز) & 7;
	    برائے (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		اگر (strcmp (func->function, function) == 0)
		    توڑو;
	    }
	    اگر (i == nfile->n_func) {
	        اگر (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   حجم (tcov_function));
		    اگر (nfile->func == تہی) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        واپس file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->پہلا_سطر = get_قدر (p, 8);
	        func->n_سطر = 0;
	        func->m_سطر = 0;
	        func->سطر = تہی;
	    }
	    p += 8;
	    جب (*p) {
		tcov_سطر *سطر;
		غیرعلامتی طویل طویل val;

		اگر (func->n_سطر >= func->m_سطر) {
		    func->m_سطر = func->m_سطر == 0 ? 4 : func->m_سطر * 2;
		    func->سطر = realloc (func->سطر,
					  func->m_سطر * حجم (tcov_سطر));
		    اگر (func->سطر == تہی) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        واپس file;
		    }
		}
		سطر = &func->سطر[func->n_سطر++];
		val = get_قدر (p, 8);
	        سطر->fline = (val >> 8) & 0xfffffffULL;
	        سطر->lline = val >> 36;
	        سطر->گنتی_2 = get_قدر (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    جب (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), ترتیب_دو_func);
	برائے (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->سطر, func->n_سطر, حجم (tcov_سطر), ترتیب_دو_سطر);
        }
	nfile = nfile->اگلا;
    }
    واپس file;
}

/* merge with previous tcov file */
ساکن خالی ملاؤ_test_coverage (tcov_file *file, FILE *fp,
				 غیرعلامتی صحیح *pruns)
{
    غیرعلامتی صحیح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    اگر (fp == تہی)
        واپس;
    اگر (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (لڑی_سے_پڑھو (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    جب (file) {
	صحیح i;
	سائز_t len = لڑی_لمبائی (file->filename);

	جب (fgets(str, حجم(str), fp) &&
	       (p = لڑی_تلاش(str, "0:File:")) == تہی) {}
        اگر ((p = لڑی_تلاش(str, "0:File:")) == تہی ||
	    لڑی_موازنہ (p + لڑی_لمبائی("0:File:"), file->filename, len) != 0 ||
	    p[لڑی_لمبائی("0:File:") + len] != ' ')
	    توڑو;
	برائے (i = 0; i < file->n_func; i++) {
	    صحیح j;
	    tcov_function *func = &file->func[i];
	    غیرعلامتی صحیح اگلا_zero = 0;
	    غیرعلامتی صحیح curline = 0;

	    برائے (j = 0; j < func->n_سطر; j++) {
		tcov_سطر *سطر = &func->سطر[j];
	        غیرعلامتی صحیح fline = سطر->fline;
	        غیرعلامتی طویل طویل گنتی_2;
		غیرعلامتی صحیح tmp;
		حرف c;

		جب (curline < fline &&
		       fgets(str, حجم(str), fp))
		    اگر ((p = strchr(str, ':')) &&
			لڑی_سے_پڑھو (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		اگر (لڑی_سے_پڑھو (str, "%llu%c\n", &گنتی_2, &c) == 2) {
		    اگر (اگلا_zero == 0)
		        سطر->گنتی_2 += گنتی_2;
		    اگلا_zero = c == '*';
		}
	    }
	}
	file = file->اگلا;
    }
}

/* store tcov data in file */
خالی __store_test_coverage (غیرعلامتی حرف * p)
{
    صحیح i, j;
    غیرعلامتی صحیح files;
    غیرعلامتی صحیح funcs;
    غیرعلامتی صحیح بلاکیں;
    غیرعلامتی صحیح بلاکیں_تسلسل;
    غیرعلامتی صحیح runs;
    حرف *cov_filename = (حرف *)p + get_قدر (p, 4);
    FILE *fp;
    حرف *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    اگر (fp == تہی) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	واپس;
    }
    file = ترتیب_دو_test_coverage (p);
    ملاؤ_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    بلاکیں = 0;
    بلاکیں_تسلسل = 0;
    nfile = file;
    جب (nfile) {
	files++;
	برائے (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    برائے (j = 0; j < func->n_سطر; j++) {
		بلاکیں++;
		بلاکیں_تسلسل += func->سطر[j].گنتی_2 != 0;
	    }
	}
	nfile = nfile->اگلا;
    }
    اگر (بلاکیں == 0)
	بلاکیں = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (دوہرا) بلاکیں_تسلسل / بلاکیں);
    nfile = file;
    جب (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	غیرعلامتی صحیح curline = 1;
	حرف str[10000];

        اگر (src == تہی)
	     جاؤ اگلا;
	funcs = 0;
	بلاکیں = 0;
	بلاکیں_تسلسل = 0;
	برائے (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    برائے (j = 0; j < func->n_سطر; j++) {
		بلاکیں++;
		بلاکیں_تسلسل += func->سطر[j].گنتی_2 != 0;
	    }
	}
	اگر (بلاکیں == 0)
	    بلاکیں = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (دوہرا) بلاکیں_تسلسل / بلاکیں);
        برائے (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    جب (curline < func->پہلا_سطر &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    بلاکیں = 0;
	    بلاکیں_تسلسل = 0;
	    برائے (j = 0; j < func->n_سطر; j++) {
		بلاکیں++;
		بلاکیں_تسلسل += func->سطر[j].گنتی_2 != 0;
	    }
	    اگر (بلاکیں == 0)
		بلاکیں = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (دوہرا) بلاکیں_تسلسل / بلاکیں);
#اگر 0
	    برائے (j = 0; j < func->n_سطر; j++) {
	        غیرعلامتی صحیح fline = func->سطر[j].fline;
	        غیرعلامتی صحیح lline = func->سطر[j].lline;
		غیرعلامتی طویل طویل گنتی_2 = func->سطر[j].گنتی_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, گنتی_2);
	    }
#اگر_ختم
	    برائے (j = 0; j < func->n_سطر;) {
	        غیرعلامتی صحیح fline = func->سطر[j].fline;
	        غیرعلامتی صحیح lline = func->سطر[j].lline;
	        غیرعلامتی طویل طویل گنتی_2 = func->سطر[j].گنتی_2;
		غیرعلامتی صحیح has_zero = 0;
		غیرعلامتی صحیح same_سطر = fline == lline;

		j++;
		جب (j < func->n_سطر) {
	            غیرعلامتی صحیح nfline = func->سطر[j].fline;
	            غیرعلامتی صحیح nlline = func->سطر[j].lline;
	            غیرعلامتی طویل طویل ncount = func->سطر[j].گنتی_2;

		    اگر (fline == nfline) {
			اگر (ncount == 0)
			    has_zero = 1;
			ورنہ اگر (ncount > گنتی_2)
			    گنتی_2 =  ncount;
			same_سطر = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ورنہ
			توڑو;
		}
		اگر (same_سطر)
		     lline++;

	        جب (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		جب (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    اگر (گنتی_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ورنہ اگر (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 گنتی_2, curline, str);
		    ورنہ
		        fprintf (fp, "%9llu:%5u:%s",
				 گنتی_2, curline, str);
		    curline++;
		}
	    }
	}
	جب (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
اگلا:
	nfile = nfile->اگلا;
    }
    جب (file) {
        برائے (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    آزاد (func->سطر);
        }
	آزاد (file->func);
	nfile = file;
	file = file->اگلا;
	آزاد (nfile);
    }
    fclose (fp);
}
