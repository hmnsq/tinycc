#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <fcntl.h>
#నిర్వచితం_కాకపోతే _WIN32
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <errno.h>
#లేకపోతే
#అన్తర్భావ <windows.h>
#అన్తర్భావ <io.h>
#అయితే_ముగింపు

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

రకనిర్వచనం నిర్మాణం tcov_పంక్తి {
    గుర్తులేని పూర్ణాంకం fline;
    గుర్తులేని పూర్ణాంకం lline;
    గుర్తులేని దీర్ఘ దీర్ఘ లెక్క_2;
} tcov_పంక్తి;

రకనిర్వచనం నిర్మాణం tcov_function {
    అక్షరం *function;
    గుర్తులేని పూర్ణాంకం మొదటి_పంక్తి;
    గుర్తులేని పూర్ణాంకం n_పంక్తి;
    గుర్తులేని పూర్ణాంకం m_పంక్తి;
    tcov_పంక్తి *పంక్తి;
} tcov_function;

రకనిర్వచనం నిర్మాణం tcov_file {
    అక్షరం *filename;
    గుర్తులేని పూర్ణాంకం n_func;
    గుర్తులేని పూర్ణాంకం m_func;
    tcov_function *func;
    నిర్మాణం tcov_file *తదుపరి;
} tcov_file;

స్థిర FILE *open_tcov_file (అక్షరం *cov_filename)
{
    పూర్ణాంకం fd;
#నిర్వచితం_కాకపోతే _WIN32
    నిర్మాణం flock తాళం;

    తాళం.l_type = F_WRLCK;
    తాళం.l_whence = SEEK_SET;
    తాళం.l_start = 0;
    తాళం.l_len = 0; /* Until EOF.  */
    తాళం.l_pid = getpid ();
#అయితే_ముగింపు
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ఒకవేళ (fd < 0)
	తిరిగి ఖాళీ;
  
#నిర్వచితం_కాకపోతే _WIN32
    అయితే (fcntl (fd, F_SETLKW, &తాళం) && errno == EINTR)
        కొనసాగు;
#లేకపోతే
    {
        OVERLAPPED overlapped = { 0 };
        తాళం_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_తాళం,
		   0, 1, 0, &overlapped);
    }
#అయితే_ముగింపు

    తిరిగి fdopen (fd, "r+");
}

స్థిర గుర్తులేని దీర్ఘ దీర్ఘ get_విలువ(గుర్తులేని అక్షరం *p, పూర్ణాంకం కొలత)
{
    గుర్తులేని దీర్ఘ దీర్ఘ విలువ = 0;

    p += కొలత;
    అయితే (కొలత--)
 	విలువ = (విలువ << 8) | *--p;
    తిరిగి విలువ;
}

స్థిర పూర్ణాంకం క్రమీకరించు_func (స్థిరరాశి శూన్య *p, స్థిరరాశి శూన్య *q)
{
    స్థిరరాశి tcov_function *pp = (స్థిరరాశి tcov_function *) p;
    స్థిరరాశి tcov_function *pq = (స్థిరరాశి tcov_function *) q;

    తిరిగి pp->మొదటి_పంక్తి > pq->మొదటి_పంక్తి ? 1 :
	   pp->మొదటి_పంక్తి < pq->మొదటి_పంక్తి ? -1 : 0;
}

స్థిర పూర్ణాంకం క్రమీకరించు_పంక్తి (స్థిరరాశి శూన్య *p, స్థిరరాశి శూన్య *q)
{
    స్థిరరాశి tcov_పంక్తి *pp = (స్థిరరాశి tcov_పంక్తి *) p;
    స్థిరరాశి tcov_పంక్తి *pq = (స్థిరరాశి tcov_పంక్తి *) q;

    తిరిగి pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->లెక్క_2 < pq->లెక్క_2 ? 1 :
	   pp->లెక్క_2 > pq->లెక్క_2 ? -1 : 0;
}

/* sort to let inline functions work */
స్థిర tcov_file *క్రమీకరించు_test_coverage (గుర్తులేని అక్షరం *p)
{
    పూర్ణాంకం i, j, k;
    గుర్తులేని అక్షరం *ప్రారంభం = p;
    tcov_file *file = ఖాళీ;
    tcov_file *nfile;

    p += 4;
    అయితే (*p) {
        అక్షరం *filename = (అక్షరం *)p;
	కొలత_t len = అక్షరశ్రేణి_పొడవు (filename);

	nfile = file;
	అయితే (nfile) {
	    ఒకవేళ (strcmp (nfile->filename, filename) == 0)
		ఆపు;
	    nfile = nfile->తదుపరి;
	}
	ఒకవేళ (nfile == ఖాళీ) {
	    nfile = జ్ఞాపకం_ఇవ్వు (పరిమాణం(tcov_file));
	    ఒకవేళ (nfile == ఖాళీ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        తిరిగి file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ఖాళీ;
	    nfile->తదుపరి = ఖాళీ;
	    ఒకవేళ (file == ఖాళీ)
	        file = nfile;
	    లేకపోతే {
		tcov_file *lfile = file;

	        అయితే (lfile->తదుపరి)
		    lfile = lfile->తదుపరి;
		lfile->తదుపరి = nfile;
	    }
	}
	p += len + 1;
	అయితే (*p) {
	    పూర్ణాంకం i;
	    అక్షరం *function = (అక్షరం *)p;
	    tcov_function *func;

	    p += అక్షరశ్రేణి_పొడవు (function) + 1;
	    p += -(p - ప్రారంభం) & 7;
	    కొరకు (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ఒకవేళ (strcmp (func->function, function) == 0)
		    ఆపు;
	    }
	    ఒకవేళ (i == nfile->n_func) {
	        ఒకవేళ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   పరిమాణం (tcov_function));
		    ఒకవేళ (nfile->func == ఖాళీ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        తిరిగి file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->మొదటి_పంక్తి = get_విలువ (p, 8);
	        func->n_పంక్తి = 0;
	        func->m_పంక్తి = 0;
	        func->పంక్తి = ఖాళీ;
	    }
	    p += 8;
	    అయితే (*p) {
		tcov_పంక్తి *పంక్తి;
		గుర్తులేని దీర్ఘ దీర్ఘ val;

		ఒకవేళ (func->n_పంక్తి >= func->m_పంక్తి) {
		    func->m_పంక్తి = func->m_పంక్తి == 0 ? 4 : func->m_పంక్తి * 2;
		    func->పంక్తి = realloc (func->పంక్తి,
					  func->m_పంక్తి * పరిమాణం (tcov_పంక్తి));
		    ఒకవేళ (func->పంక్తి == ఖాళీ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        తిరిగి file;
		    }
		}
		పంక్తి = &func->పంక్తి[func->n_పంక్తి++];
		val = get_విలువ (p, 8);
	        పంక్తి->fline = (val >> 8) & 0xfffffffULL;
	        పంక్తి->lline = val >> 36;
	        పంక్తి->లెక్క_2 = get_విలువ (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    అయితే (nfile) {
	qsort (nfile->func, nfile->n_func, పరిమాణం (tcov_function), క్రమీకరించు_func);
	కొరకు (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->పంక్తి, func->n_పంక్తి, పరిమాణం (tcov_పంక్తి), క్రమీకరించు_పంక్తి);
        }
	nfile = nfile->తదుపరి;
    }
    తిరిగి file;
}

/* merge with previous tcov file */
స్థిర శూన్య విలీనం_test_coverage (tcov_file *file, FILE *fp,
				 గుర్తులేని పూర్ణాంకం *pruns)
{
    గుర్తులేని పూర్ణాంకం runs;
    అక్షరం *p;
    అక్షరం str[10000];
    
    *pruns = 1;
    ఒకవేళ (fp == ఖాళీ)
        తిరిగి;
    ఒకవేళ (fgets(str, పరిమాణం(str), fp) &&
        (p = strrchr (str, ':')) &&
        (అక్షరశ్రేణి_చదువు (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    అయితే (file) {
	పూర్ణాంకం i;
	కొలత_t len = అక్షరశ్రేణి_పొడవు (file->filename);

	అయితే (fgets(str, పరిమాణం(str), fp) &&
	       (p = అక్షరశ్రేణి_శోధన(str, "0:File:")) == ఖాళీ) {}
        ఒకవేళ ((p = అక్షరశ్రేణి_శోధన(str, "0:File:")) == ఖాళీ ||
	    అక్షరశ్రేణి_పోలిక (p + అక్షరశ్రేణి_పొడవు("0:File:"), file->filename, len) != 0 ||
	    p[అక్షరశ్రేణి_పొడవు("0:File:") + len] != ' ')
	    ఆపు;
	కొరకు (i = 0; i < file->n_func; i++) {
	    పూర్ణాంకం j;
	    tcov_function *func = &file->func[i];
	    గుర్తులేని పూర్ణాంకం తదుపరి_zero = 0;
	    గుర్తులేని పూర్ణాంకం curline = 0;

	    కొరకు (j = 0; j < func->n_పంక్తి; j++) {
		tcov_పంక్తి *పంక్తి = &func->పంక్తి[j];
	        గుర్తులేని పూర్ణాంకం fline = పంక్తి->fline;
	        గుర్తులేని దీర్ఘ దీర్ఘ లెక్క_2;
		గుర్తులేని పూర్ణాంకం tmp;
		అక్షరం c;

		అయితే (curline < fline &&
		       fgets(str, పరిమాణం(str), fp))
		    ఒకవేళ ((p = strchr(str, ':')) &&
			అక్షరశ్రేణి_చదువు (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ఒకవేళ (అక్షరశ్రేణి_చదువు (str, "%llu%c\n", &లెక్క_2, &c) == 2) {
		    ఒకవేళ (తదుపరి_zero == 0)
		        పంక్తి->లెక్క_2 += లెక్క_2;
		    తదుపరి_zero = c == '*';
		}
	    }
	}
	file = file->తదుపరి;
    }
}

/* store tcov data in file */
శూన్య __store_test_coverage (గుర్తులేని అక్షరం * p)
{
    పూర్ణాంకం i, j;
    గుర్తులేని పూర్ణాంకం files;
    గుర్తులేని పూర్ణాంకం funcs;
    గుర్తులేని పూర్ణాంకం ఖండాలు;
    గుర్తులేని పూర్ణాంకం ఖండాలు_నిరంతరం;
    గుర్తులేని పూర్ణాంకం runs;
    అక్షరం *cov_filename = (అక్షరం *)p + get_విలువ (p, 4);
    FILE *fp;
    అక్షరం *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ఒకవేళ (fp == ఖాళీ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	తిరిగి;
    }
    file = క్రమీకరించు_test_coverage (p);
    విలీనం_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    ఖండాలు = 0;
    ఖండాలు_నిరంతరం = 0;
    nfile = file;
    అయితే (nfile) {
	files++;
	కొరకు (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    కొరకు (j = 0; j < func->n_పంక్తి; j++) {
		ఖండాలు++;
		ఖండాలు_నిరంతరం += func->పంక్తి[j].లెక్క_2 != 0;
	    }
	}
	nfile = nfile->తదుపరి;
    }
    ఒకవేళ (ఖండాలు == 0)
	ఖండాలు = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ద్విగుణ) ఖండాలు_నిరంతరం / ఖండాలు);
    nfile = file;
    అయితే (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	గుర్తులేని పూర్ణాంకం curline = 1;
	అక్షరం str[10000];

        ఒకవేళ (src == ఖాళీ)
	     వెళ్ళు తదుపరి;
	funcs = 0;
	ఖండాలు = 0;
	ఖండాలు_నిరంతరం = 0;
	కొరకు (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    కొరకు (j = 0; j < func->n_పంక్తి; j++) {
		ఖండాలు++;
		ఖండాలు_నిరంతరం += func->పంక్తి[j].లెక్క_2 != 0;
	    }
	}
	ఒకవేళ (ఖండాలు == 0)
	    ఖండాలు = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ద్విగుణ) ఖండాలు_నిరంతరం / ఖండాలు);
        కొరకు (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    అయితే (curline < func->మొదటి_పంక్తి &&
		   fgets(str, పరిమాణం(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    ఖండాలు = 0;
	    ఖండాలు_నిరంతరం = 0;
	    కొరకు (j = 0; j < func->n_పంక్తి; j++) {
		ఖండాలు++;
		ఖండాలు_నిరంతరం += func->పంక్తి[j].లెక్క_2 != 0;
	    }
	    ఒకవేళ (ఖండాలు == 0)
		ఖండాలు = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ద్విగుణ) ఖండాలు_నిరంతరం / ఖండాలు);
#ఒకవేళ 0
	    కొరకు (j = 0; j < func->n_పంక్తి; j++) {
	        గుర్తులేని పూర్ణాంకం fline = func->పంక్తి[j].fline;
	        గుర్తులేని పూర్ణాంకం lline = func->పంక్తి[j].lline;
		గుర్తులేని దీర్ఘ దీర్ఘ లెక్క_2 = func->పంక్తి[j].లెక్క_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, లెక్క_2);
	    }
#అయితే_ముగింపు
	    కొరకు (j = 0; j < func->n_పంక్తి;) {
	        గుర్తులేని పూర్ణాంకం fline = func->పంక్తి[j].fline;
	        గుర్తులేని పూర్ణాంకం lline = func->పంక్తి[j].lline;
	        గుర్తులేని దీర్ఘ దీర్ఘ లెక్క_2 = func->పంక్తి[j].లెక్క_2;
		గుర్తులేని పూర్ణాంకం has_zero = 0;
		గుర్తులేని పూర్ణాంకం same_పంక్తి = fline == lline;

		j++;
		అయితే (j < func->n_పంక్తి) {
	            గుర్తులేని పూర్ణాంకం nfline = func->పంక్తి[j].fline;
	            గుర్తులేని పూర్ణాంకం nlline = func->పంక్తి[j].lline;
	            గుర్తులేని దీర్ఘ దీర్ఘ ncount = func->పంక్తి[j].లెక్క_2;

		    ఒకవేళ (fline == nfline) {
			ఒకవేళ (ncount == 0)
			    has_zero = 1;
			లేకపోతే ఒకవేళ (ncount > లెక్క_2)
			    లెక్క_2 =  ncount;
			same_పంక్తి = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    లేకపోతే
			ఆపు;
		}
		ఒకవేళ (same_పంక్తి)
		     lline++;

	        అయితే (curline < fline &&
		       fgets(str, పరిమాణం(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		అయితే (curline < lline &&
		       fgets(str, పరిమాణం(str), src)) {
		    ఒకవేళ (లెక్క_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    లేకపోతే ఒకవేళ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 లెక్క_2, curline, str);
		    లేకపోతే
		        fprintf (fp, "%9llu:%5u:%s",
				 లెక్క_2, curline, str);
		    curline++;
		}
	    }
	}
	అయితే (fgets(str, పరిమాణం(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
తదుపరి:
	nfile = nfile->తదుపరి;
    }
    అయితే (file) {
        కొరకు (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    విడుదల (func->పంక్తి);
        }
	విడుదల (file->func);
	nfile = file;
	file = file->తదుపరి;
	విడుదల (nfile);
    }
    fclose (fp);
}
