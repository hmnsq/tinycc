#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#جيڪڏهن_وصف_نه_ٿيل _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#وإلا
#ضمن <windows.h>
#ضمن <io.h>
#جيڪڏهن_پورو

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

تعريفنوع بنية tcov_سٽ {
    بنانشان صحيح fline;
    بنانشان صحيح lline;
    بنانشان ڊگهو ڊگهو ڳڻپ_2;
} tcov_سٽ;

تعريفنوع بنية tcov_function {
    حرف *function;
    بنانشان صحيح پهريون_سٽ;
    بنانشان صحيح n_سٽ;
    بنانشان صحيح m_سٽ;
    tcov_سٽ *سٽ;
} tcov_function;

تعريفنوع بنية tcov_file {
    حرف *filename;
    بنانشان صحيح n_func;
    بنانشان صحيح m_func;
    tcov_function *func;
    بنية tcov_file *ايندڙ;
} tcov_file;

ساكن FILE *open_tcov_file (حرف *cov_filename)
{
    صحيح fd;
#جيڪڏهن_وصف_نه_ٿيل _WIN32
    بنية flock تالو;

    تالو.l_type = F_WRLCK;
    تالو.l_whence = SEEK_SET;
    تالو.l_start = 0;
    تالو.l_len = 0; /* Until EOF.  */
    تالو.l_pid = getpid ();
#جيڪڏهن_پورو
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    إذا (fd < 0)
	أرجع عدم;
  
#جيڪڏهن_وصف_نه_ٿيل _WIN32
    طالما (fcntl (fd, F_SETLKW, &تالو) && errno == EINTR)
        استمر;
#وإلا
    {
        OVERLAPPED overlapped = { 0 };
        تالو_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_تالو,
		   0, 1, 0, &overlapped);
    }
#جيڪڏهن_پورو

    أرجع fdopen (fd, "r+");
}

ساكن بنانشان ڊگهو ڊگهو get_قدر(بنانشان حرف *p, صحيح سائيز)
{
    بنانشان ڊگهو ڊگهو قدر = 0;

    p += سائيز;
    طالما (سائيز--)
 	قدر = (قدر << 8) | *--p;
    أرجع قدر;
}

ساكن صحيح ترتيب_ڏيو_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    أرجع pp->پهريون_سٽ > pq->پهريون_سٽ ? 1 :
	   pp->پهريون_سٽ < pq->پهريون_سٽ ? -1 : 0;
}

ساكن صحيح ترتيب_ڏيو_سٽ (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_سٽ *pp = (ثابت tcov_سٽ *) p;
    ثابت tcov_سٽ *pq = (ثابت tcov_سٽ *) q;

    أرجع pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ڳڻپ_2 < pq->ڳڻپ_2 ? 1 :
	   pp->ڳڻپ_2 > pq->ڳڻپ_2 ? -1 : 0;
}

/* sort to let inline functions work */
ساكن tcov_file *ترتيب_ڏيو_test_coverage (بنانشان حرف *p)
{
    صحيح i, j, k;
    بنانشان حرف *شروعات = p;
    tcov_file *file = عدم;
    tcov_file *nfile;

    p += 4;
    طالما (*p) {
        حرف *filename = (حرف *)p;
	سائيز_t len = لڙي_ڊيگهه (filename);

	nfile = file;
	طالما (nfile) {
	    إذا (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->ايندڙ;
	}
	إذا (nfile == عدم) {
	    nfile = يادگيري_ڏيو (حجم(tcov_file));
	    إذا (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        أرجع file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->ايندڙ = عدم;
	    إذا (file == عدم)
	        file = nfile;
	    وإلا {
		tcov_file *lfile = file;

	        طالما (lfile->ايندڙ)
		    lfile = lfile->ايندڙ;
		lfile->ايندڙ = nfile;
	    }
	}
	p += len + 1;
	طالما (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += لڙي_ڊيگهه (function) + 1;
	    p += -(p - شروعات) & 7;
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
	        func->پهريون_سٽ = get_قدر (p, 8);
	        func->n_سٽ = 0;
	        func->m_سٽ = 0;
	        func->سٽ = عدم;
	    }
	    p += 8;
	    طالما (*p) {
		tcov_سٽ *سٽ;
		بنانشان ڊگهو ڊگهو val;

		إذا (func->n_سٽ >= func->m_سٽ) {
		    func->m_سٽ = func->m_سٽ == 0 ? 4 : func->m_سٽ * 2;
		    func->سٽ = realloc (func->سٽ,
					  func->m_سٽ * حجم (tcov_سٽ));
		    إذا (func->سٽ == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
		    }
		}
		سٽ = &func->سٽ[func->n_سٽ++];
		val = get_قدر (p, 8);
	        سٽ->fline = (val >> 8) & 0xfffffffULL;
	        سٽ->lline = val >> 36;
	        سٽ->ڳڻپ_2 = get_قدر (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    طالما (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), ترتيب_ڏيو_func);
	لكل (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->سٽ, func->n_سٽ, حجم (tcov_سٽ), ترتيب_ڏيو_سٽ);
        }
	nfile = nfile->ايندڙ;
    }
    أرجع file;
}

/* merge with previous tcov file */
ساكن فراغ ملايو_test_coverage (tcov_file *file, FILE *fp,
				 بنانشان صحيح *pruns)
{
    بنانشان صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    إذا (fp == عدم)
        أرجع;
    إذا (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (لڙي_مان_پڙهو (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    طالما (file) {
	صحيح i;
	سائيز_t len = لڙي_ڊيگهه (file->filename);

	طالما (fgets(str, حجم(str), fp) &&
	       (p = لڙي_ڳولا(str, "0:File:")) == عدم) {}
        إذا ((p = لڙي_ڳولا(str, "0:File:")) == عدم ||
	    لڙي_ڀيٽ (p + لڙي_ڊيگهه("0:File:"), file->filename, len) != 0 ||
	    p[لڙي_ڊيگهه("0:File:") + len] != ' ')
	    اكسر;
	لكل (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    بنانشان صحيح ايندڙ_zero = 0;
	    بنانشان صحيح curline = 0;

	    لكل (j = 0; j < func->n_سٽ; j++) {
		tcov_سٽ *سٽ = &func->سٽ[j];
	        بنانشان صحيح fline = سٽ->fline;
	        بنانشان ڊگهو ڊگهو ڳڻپ_2;
		بنانشان صحيح tmp;
		حرف c;

		طالما (curline < fline &&
		       fgets(str, حجم(str), fp))
		    إذا ((p = strchr(str, ':')) &&
			لڙي_مان_پڙهو (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		إذا (لڙي_مان_پڙهو (str, "%llu%c\n", &ڳڻپ_2, &c) == 2) {
		    إذا (ايندڙ_zero == 0)
		        سٽ->ڳڻپ_2 += ڳڻپ_2;
		    ايندڙ_zero = c == '*';
		}
	    }
	}
	file = file->ايندڙ;
    }
}

/* store tcov data in file */
فراغ __store_test_coverage (بنانشان حرف * p)
{
    صحيح i, j;
    بنانشان صحيح files;
    بنانشان صحيح funcs;
    بنانشان صحيح بلاڪون;
    بنانشان صحيح بلاڪون_لاڳيتو;
    بنانشان صحيح runs;
    حرف *cov_filename = (حرف *)p + get_قدر (p, 4);
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
    file = ترتيب_ڏيو_test_coverage (p);
    ملايو_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    بلاڪون = 0;
    بلاڪون_لاڳيتو = 0;
    nfile = file;
    طالما (nfile) {
	files++;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_سٽ; j++) {
		بلاڪون++;
		بلاڪون_لاڳيتو += func->سٽ[j].ڳڻپ_2 != 0;
	    }
	}
	nfile = nfile->ايندڙ;
    }
    إذا (بلاڪون == 0)
	بلاڪون = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) بلاڪون_لاڳيتو / بلاڪون);
    nfile = file;
    طالما (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	بنانشان صحيح curline = 1;
	حرف str[10000];

        إذا (src == عدم)
	     اذهب ايندڙ;
	funcs = 0;
	بلاڪون = 0;
	بلاڪون_لاڳيتو = 0;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_سٽ; j++) {
		بلاڪون++;
		بلاڪون_لاڳيتو += func->سٽ[j].ڳڻپ_2 != 0;
	    }
	}
	إذا (بلاڪون == 0)
	    بلاڪون = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) بلاڪون_لاڳيتو / بلاڪون);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    طالما (curline < func->پهريون_سٽ &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    بلاڪون = 0;
	    بلاڪون_لاڳيتو = 0;
	    لكل (j = 0; j < func->n_سٽ; j++) {
		بلاڪون++;
		بلاڪون_لاڳيتو += func->سٽ[j].ڳڻپ_2 != 0;
	    }
	    إذا (بلاڪون == 0)
		بلاڪون = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) بلاڪون_لاڳيتو / بلاڪون);
#إذا 0
	    لكل (j = 0; j < func->n_سٽ; j++) {
	        بنانشان صحيح fline = func->سٽ[j].fline;
	        بنانشان صحيح lline = func->سٽ[j].lline;
		بنانشان ڊگهو ڊگهو ڳڻپ_2 = func->سٽ[j].ڳڻپ_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, ڳڻپ_2);
	    }
#جيڪڏهن_پورو
	    لكل (j = 0; j < func->n_سٽ;) {
	        بنانشان صحيح fline = func->سٽ[j].fline;
	        بنانشان صحيح lline = func->سٽ[j].lline;
	        بنانشان ڊگهو ڊگهو ڳڻپ_2 = func->سٽ[j].ڳڻپ_2;
		بنانشان صحيح has_zero = 0;
		بنانشان صحيح same_سٽ = fline == lline;

		j++;
		طالما (j < func->n_سٽ) {
	            بنانشان صحيح nfline = func->سٽ[j].fline;
	            بنانشان صحيح nlline = func->سٽ[j].lline;
	            بنانشان ڊگهو ڊگهو ncount = func->سٽ[j].ڳڻپ_2;

		    إذا (fline == nfline) {
			إذا (ncount == 0)
			    has_zero = 1;
			وإلا إذا (ncount > ڳڻپ_2)
			    ڳڻپ_2 =  ncount;
			same_سٽ = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وإلا
			اكسر;
		}
		إذا (same_سٽ)
		     lline++;

	        طالما (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		طالما (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    إذا (ڳڻپ_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وإلا إذا (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ڳڻپ_2, curline, str);
		    وإلا
		        fprintf (fp, "%9llu:%5u:%s",
				 ڳڻپ_2, curline, str);
		    curline++;
		}
	    }
	}
	طالما (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
ايندڙ:
	nfile = nfile->ايندڙ;
    }
    طالما (file) {
        لكل (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    حرر (func->سٽ);
        }
	حرر (file->func);
	nfile = file;
	file = file->ايندڙ;
	حرر (nfile);
    }
    fclose (fp);
}
