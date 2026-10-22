#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdlib.h>
#ضمن <fcntl.h>
#که_نه_تعریف_شوی _WIN32
#ضمن <unistd.h>
#ضمن <errno.h>
#وإلا
#ضمن <windows.h>
#ضمن <io.h>
#د_که_پای

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

تعريفنوع بنية tcov_کرښه {
    بینښه صحيح fline;
    بینښه صحيح lline;
    بینښه اوږد اوږد شمېر_2;
} tcov_کرښه;

تعريفنوع بنية tcov_function {
    حرف *function;
    بینښه صحيح لومړی_کرښه;
    بینښه صحيح n_کرښه;
    بینښه صحيح m_کرښه;
    tcov_کرښه *کرښه;
} tcov_function;

تعريفنوع بنية tcov_file {
    حرف *filename;
    بینښه صحيح n_func;
    بینښه صحيح m_func;
    tcov_function *func;
    بنية tcov_file *بل;
} tcov_file;

ساكن FILE *open_tcov_file (حرف *cov_filename)
{
    صحيح fd;
#که_نه_تعریف_شوی _WIN32
    بنية flock قلف;

    قلف.l_type = F_WRLCK;
    قلف.l_whence = SEEK_SET;
    قلف.l_start = 0;
    قلف.l_len = 0; /* Until EOF.  */
    قلف.l_pid = getpid ();
#د_که_پای
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    إذا (fd < 0)
	أرجع عدم;
  
#که_نه_تعریف_شوی _WIN32
    طالما (fcntl (fd, F_SETLKW, &قلف) && errno == EINTR)
        استمر;
#وإلا
    {
        OVERLAPPED overlapped = { 0 };
        قلف_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_قلف,
		   0, 1, 0, &overlapped);
    }
#د_که_پای

    أرجع fdopen (fd, "r+");
}

ساكن بینښه اوږد اوږد get_ارزښت(بینښه حرف *p, صحيح اندازه)
{
    بینښه اوږد اوږد ارزښت = 0;

    p += اندازه;
    طالما (اندازه--)
 	ارزښت = (ارزښت << 8) | *--p;
    أرجع ارزښت;
}

ساكن صحيح ترتیبول_func (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    أرجع pp->لومړی_کرښه > pq->لومړی_کرښه ? 1 :
	   pp->لومړی_کرښه < pq->لومړی_کرښه ? -1 : 0;
}

ساكن صحيح ترتیبول_کرښه (ثابت فراغ *p, ثابت فراغ *q)
{
    ثابت tcov_کرښه *pp = (ثابت tcov_کرښه *) p;
    ثابت tcov_کرښه *pq = (ثابت tcov_کرښه *) q;

    أرجع pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->شمېر_2 < pq->شمېر_2 ? 1 :
	   pp->شمېر_2 > pq->شمېر_2 ? -1 : 0;
}

/* sort to let inline functions work */
ساكن tcov_file *ترتیبول_test_coverage (بینښه حرف *p)
{
    صحيح i, j, k;
    بینښه حرف *پیل = p;
    tcov_file *file = عدم;
    tcov_file *nfile;

    p += 4;
    طالما (*p) {
        حرف *filename = (حرف *)p;
	اندازه_t len = مزي_اوږدوالی (filename);

	nfile = file;
	طالما (nfile) {
	    إذا (strcmp (nfile->filename, filename) == 0)
		اكسر;
	    nfile = nfile->بل;
	}
	إذا (nfile == عدم) {
	    nfile = حافظه_ورکړه (حجم(tcov_file));
	    إذا (nfile == عدم) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        أرجع file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = عدم;
	    nfile->بل = عدم;
	    إذا (file == عدم)
	        file = nfile;
	    وإلا {
		tcov_file *lfile = file;

	        طالما (lfile->بل)
		    lfile = lfile->بل;
		lfile->بل = nfile;
	    }
	}
	p += len + 1;
	طالما (*p) {
	    صحيح i;
	    حرف *function = (حرف *)p;
	    tcov_function *func;

	    p += مزي_اوږدوالی (function) + 1;
	    p += -(p - پیل) & 7;
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
	        func->لومړی_کرښه = get_ارزښت (p, 8);
	        func->n_کرښه = 0;
	        func->m_کرښه = 0;
	        func->کرښه = عدم;
	    }
	    p += 8;
	    طالما (*p) {
		tcov_کرښه *کرښه;
		بینښه اوږد اوږد val;

		إذا (func->n_کرښه >= func->m_کرښه) {
		    func->m_کرښه = func->m_کرښه == 0 ? 4 : func->m_کرښه * 2;
		    func->کرښه = realloc (func->کرښه,
					  func->m_کرښه * حجم (tcov_کرښه));
		    إذا (func->کرښه == عدم) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        أرجع file;
		    }
		}
		کرښه = &func->کرښه[func->n_کرښه++];
		val = get_ارزښت (p, 8);
	        کرښه->fline = (val >> 8) & 0xfffffffULL;
	        کرښه->lline = val >> 36;
	        کرښه->شمېر_2 = get_ارزښت (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    طالما (nfile) {
	qsort (nfile->func, nfile->n_func, حجم (tcov_function), ترتیبول_func);
	لكل (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->کرښه, func->n_کرښه, حجم (tcov_کرښه), ترتیبول_کرښه);
        }
	nfile = nfile->بل;
    }
    أرجع file;
}

/* merge with previous tcov file */
ساكن فراغ یوځای_test_coverage (tcov_file *file, FILE *fp,
				 بینښه صحيح *pruns)
{
    بینښه صحيح runs;
    حرف *p;
    حرف str[10000];
    
    *pruns = 1;
    إذا (fp == عدم)
        أرجع;
    إذا (fgets(str, حجم(str), fp) &&
        (p = strrchr (str, ':')) &&
        (له_مزي_ولوله (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    طالما (file) {
	صحيح i;
	اندازه_t len = مزي_اوږدوالی (file->filename);

	طالما (fgets(str, حجم(str), fp) &&
	       (p = مزي_پلټنه(str, "0:File:")) == عدم) {}
        إذا ((p = مزي_پلټنه(str, "0:File:")) == عدم ||
	    مزي_پرتله (p + مزي_اوږدوالی("0:File:"), file->filename, len) != 0 ||
	    p[مزي_اوږدوالی("0:File:") + len] != ' ')
	    اكسر;
	لكل (i = 0; i < file->n_func; i++) {
	    صحيح j;
	    tcov_function *func = &file->func[i];
	    بینښه صحيح بل_zero = 0;
	    بینښه صحيح curline = 0;

	    لكل (j = 0; j < func->n_کرښه; j++) {
		tcov_کرښه *کرښه = &func->کرښه[j];
	        بینښه صحيح fline = کرښه->fline;
	        بینښه اوږد اوږد شمېر_2;
		بینښه صحيح tmp;
		حرف c;

		طالما (curline < fline &&
		       fgets(str, حجم(str), fp))
		    إذا ((p = strchr(str, ':')) &&
			له_مزي_ولوله (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		إذا (له_مزي_ولوله (str, "%llu%c\n", &شمېر_2, &c) == 2) {
		    إذا (بل_zero == 0)
		        کرښه->شمېر_2 += شمېر_2;
		    بل_zero = c == '*';
		}
	    }
	}
	file = file->بل;
    }
}

/* store tcov data in file */
فراغ __store_test_coverage (بینښه حرف * p)
{
    صحيح i, j;
    بینښه صحيح files;
    بینښه صحيح funcs;
    بینښه صحيح بلاکونه;
    بینښه صحيح بلاکونه_پرلپسې;
    بینښه صحيح runs;
    حرف *cov_filename = (حرف *)p + get_ارزښت (p, 4);
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
    file = ترتیبول_test_coverage (p);
    یوځای_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    بلاکونه = 0;
    بلاکونه_پرلپسې = 0;
    nfile = file;
    طالما (nfile) {
	files++;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_کرښه; j++) {
		بلاکونه++;
		بلاکونه_پرلپسې += func->کرښه[j].شمېر_2 != 0;
	    }
	}
	nfile = nfile->بل;
    }
    إذا (بلاکونه == 0)
	بلاکونه = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (مزدوج) بلاکونه_پرلپسې / بلاکونه);
    nfile = file;
    طالما (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	بینښه صحيح curline = 1;
	حرف str[10000];

        إذا (src == عدم)
	     اذهب بل;
	funcs = 0;
	بلاکونه = 0;
	بلاکونه_پرلپسې = 0;
	لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    لكل (j = 0; j < func->n_کرښه; j++) {
		بلاکونه++;
		بلاکونه_پرلپسې += func->کرښه[j].شمېر_2 != 0;
	    }
	}
	إذا (بلاکونه == 0)
	    بلاکونه = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (مزدوج) بلاکونه_پرلپسې / بلاکونه);
        لكل (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    طالما (curline < func->لومړی_کرښه &&
		   fgets(str, حجم(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    بلاکونه = 0;
	    بلاکونه_پرلپسې = 0;
	    لكل (j = 0; j < func->n_کرښه; j++) {
		بلاکونه++;
		بلاکونه_پرلپسې += func->کرښه[j].شمېر_2 != 0;
	    }
	    إذا (بلاکونه == 0)
		بلاکونه = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (مزدوج) بلاکونه_پرلپسې / بلاکونه);
#إذا 0
	    لكل (j = 0; j < func->n_کرښه; j++) {
	        بینښه صحيح fline = func->کرښه[j].fline;
	        بینښه صحيح lline = func->کرښه[j].lline;
		بینښه اوږد اوږد شمېر_2 = func->کرښه[j].شمېر_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, شمېر_2);
	    }
#د_که_پای
	    لكل (j = 0; j < func->n_کرښه;) {
	        بینښه صحيح fline = func->کرښه[j].fline;
	        بینښه صحيح lline = func->کرښه[j].lline;
	        بینښه اوږد اوږد شمېر_2 = func->کرښه[j].شمېر_2;
		بینښه صحيح has_zero = 0;
		بینښه صحيح same_کرښه = fline == lline;

		j++;
		طالما (j < func->n_کرښه) {
	            بینښه صحيح nfline = func->کرښه[j].fline;
	            بینښه صحيح nlline = func->کرښه[j].lline;
	            بینښه اوږد اوږد ncount = func->کرښه[j].شمېر_2;

		    إذا (fline == nfline) {
			إذا (ncount == 0)
			    has_zero = 1;
			وإلا إذا (ncount > شمېر_2)
			    شمېر_2 =  ncount;
			same_کرښه = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وإلا
			اكسر;
		}
		إذا (same_کرښه)
		     lline++;

	        طالما (curline < fline &&
		       fgets(str, حجم(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		طالما (curline < lline &&
		       fgets(str, حجم(str), src)) {
		    إذا (شمېر_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وإلا إذا (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 شمېر_2, curline, str);
		    وإلا
		        fprintf (fp, "%9llu:%5u:%s",
				 شمېر_2, curline, str);
		    curline++;
		}
	    }
	}
	طالما (fgets(str, حجم(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
بل:
	nfile = nfile->بل;
    }
    طالما (file) {
        لكل (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    حرر (func->کرښه);
        }
	حرر (file->func);
	nfile = file;
	file = file->بل;
	حرر (nfile);
    }
    fclose (fp);
}
