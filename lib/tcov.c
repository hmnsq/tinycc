#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <fcntl.h>
#ifndef _WIN32
#অন্তর্ভাব <unistd.h>
#অন্তর্ভাব <errno.h>
#অন্যথা
#অন্তর্ভাব <windows.h>
#অন্তর্ভাব <io.h>
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

প্রকারলেখ কাঠামো tcov_সারি {
    unsigned পূর্ণসংখ্যা fline;
    unsigned পূর্ণসংখ্যা lline;
    unsigned long long গুনতি_2;
} tcov_সারি;

প্রকারলেখ কাঠামো tcov_function {
    অক্ষর *function;
    unsigned পূর্ণসংখ্যা first_সারি;
    unsigned পূর্ণসংখ্যা n_সারি;
    unsigned পূর্ণসংখ্যা m_সারি;
    tcov_সারি *সারি;
} tcov_function;

প্রকারলেখ কাঠামো tcov_file {
    অক্ষর *filename;
    unsigned পূর্ণসংখ্যা n_func;
    unsigned পূর্ণসংখ্যা m_func;
    tcov_function *func;
    কাঠামো tcov_file *পরবর্তী;
} tcov_file;

স্থির FILE *open_tcov_file (অক্ষর *cov_filename)
{
    পূর্ণসংখ্যা fd;
#ifndef _WIN32
    কাঠামো flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    যদি (fd < 0)
	ফেরত ফাঁকা;
  
#ifndef _WIN32
    যখন (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        চালু;
#অন্যথা
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ফেরত fdopen (fd, "r+");
}

স্থির unsigned long long get_মান(unsigned অক্ষর *p, পূর্ণসংখ্যা আকার_2)
{
    unsigned long long মান = 0;

    p += আকার_2;
    যখন (আকার_2--)
 	মান = (মান << 8) | *--p;
    ফেরত মান;
}

স্থির পূর্ণসংখ্যা sort_func (ধ্রুবক শূন্য *p, ধ্রুবক শূন্য *q)
{
    ধ্রুবক tcov_function *pp = (ধ্রুবক tcov_function *) p;
    ধ্রুবক tcov_function *pq = (ধ্রুবক tcov_function *) q;

    ফেরত pp->first_সারি > pq->first_সারি ? 1 :
	   pp->first_সারি < pq->first_সারি ? -1 : 0;
}

স্থির পূর্ণসংখ্যা sort_সারি (ধ্রুবক শূন্য *p, ধ্রুবক শূন্য *q)
{
    ধ্রুবক tcov_সারি *pp = (ধ্রুবক tcov_সারি *) p;
    ধ্রুবক tcov_সারি *pq = (ধ্রুবক tcov_সারি *) q;

    ফেরত pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->গুনতি_2 < pq->গুনতি_2 ? 1 :
	   pp->গুনতি_2 > pq->গুনতি_2 ? -1 : 0;
}

/* sort to let inline functions work */
স্থির tcov_file *sort_test_coverage (unsigned অক্ষর *p)
{
    পূর্ণসংখ্যা i, j, k;
    unsigned অক্ষর *start = p;
    tcov_file *file = ফাঁকা;
    tcov_file *nfile;

    p += 4;
    যখন (*p) {
        অক্ষর *filename = (অক্ষর *)p;
	আকার_t len = strlen (filename);

	nfile = file;
	যখন (nfile) {
	    যদি (strcmp (nfile->filename, filename) == 0)
		বিরতি;
	    nfile = nfile->পরবর্তী;
	}
	যদি (nfile == ফাঁকা) {
	    nfile = malloc (আকার(tcov_file));
	    যদি (nfile == ফাঁকা) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ফেরত file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ফাঁকা;
	    nfile->পরবর্তী = ফাঁকা;
	    যদি (file == ফাঁকা)
	        file = nfile;
	    অন্যথা {
		tcov_file *lfile = file;

	        যখন (lfile->পরবর্তী)
		    lfile = lfile->পরবর্তী;
		lfile->পরবর্তী = nfile;
	    }
	}
	p += len + 1;
	যখন (*p) {
	    পূর্ণসংখ্যা i;
	    অক্ষর *function = (অক্ষর *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    জন্য (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		যদি (strcmp (func->function, function) == 0)
		    বিরতি;
	    }
	    যদি (i == nfile->n_func) {
	        যদি (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   আকার (tcov_function));
		    যদি (nfile->func == ফাঁকা) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ফেরত file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_সারি = get_মান (p, 8);
	        func->n_সারি = 0;
	        func->m_সারি = 0;
	        func->সারি = ফাঁকা;
	    }
	    p += 8;
	    যখন (*p) {
		tcov_সারি *সারি;
		unsigned long long val;

		যদি (func->n_সারি >= func->m_সারি) {
		    func->m_সারি = func->m_সারি == 0 ? 4 : func->m_সারি * 2;
		    func->সারি = realloc (func->সারি,
					  func->m_সারি * আকার (tcov_সারি));
		    যদি (func->সারি == ফাঁকা) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ফেরত file;
		    }
		}
		সারি = &func->সারি[func->n_সারি++];
		val = get_মান (p, 8);
	        সারি->fline = (val >> 8) & 0xfffffffULL;
	        সারি->lline = val >> 36;
	        সারি->গুনতি_2 = get_মান (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    যখন (nfile) {
	qsort (nfile->func, nfile->n_func, আকার (tcov_function), sort_func);
	জন্য (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->সারি, func->n_সারি, আকার (tcov_সারি), sort_সারি);
        }
	nfile = nfile->পরবর্তী;
    }
    ফেরত file;
}

/* merge with previous tcov file */
স্থির শূন্য merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned পূর্ণসংখ্যা *pruns)
{
    unsigned পূর্ণসংখ্যা runs;
    অক্ষর *p;
    অক্ষর str[10000];
    
    *pruns = 1;
    যদি (fp == ফাঁকা)
        ফেরত;
    যদি (fgets(str, আকার(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    যখন (file) {
	পূর্ণসংখ্যা i;
	আকার_t len = strlen (file->filename);

	যখন (fgets(str, আকার(str), fp) &&
	       (p = strstr(str, "0:File:")) == ফাঁকা) {}
        যদি ((p = strstr(str, "0:File:")) == ফাঁকা ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    বিরতি;
	জন্য (i = 0; i < file->n_func; i++) {
	    পূর্ণসংখ্যা j;
	    tcov_function *func = &file->func[i];
	    unsigned পূর্ণসংখ্যা পরবর্তী_zero = 0;
	    unsigned পূর্ণসংখ্যা curline = 0;

	    জন্য (j = 0; j < func->n_সারি; j++) {
		tcov_সারি *সারি = &func->সারি[j];
	        unsigned পূর্ণসংখ্যা fline = সারি->fline;
	        unsigned long long গুনতি_2;
		unsigned পূর্ণসংখ্যা tmp;
		অক্ষর c;

		যখন (curline < fline &&
		       fgets(str, আকার(str), fp))
		    যদি ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		যদি (sscanf (str, "%llu%c\n", &গুনতি_2, &c) == 2) {
		    যদি (পরবর্তী_zero == 0)
		        সারি->গুনতি_2 += গুনতি_2;
		    পরবর্তী_zero = c == '*';
		}
	    }
	}
	file = file->পরবর্তী;
    }
}

/* store tcov data in file */
শূন্য __store_test_coverage (unsigned অক্ষর * p)
{
    পূর্ণসংখ্যা i, j;
    unsigned পূর্ণসংখ্যা files;
    unsigned পূর্ণসংখ্যা funcs;
    unsigned পূর্ণসংখ্যা blocks;
    unsigned পূর্ণসংখ্যা blocks_run;
    unsigned পূর্ণসংখ্যা runs;
    অক্ষর *cov_filename = (অক্ষর *)p + get_মান (p, 4);
    FILE *fp;
    অক্ষর *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    যদি (fp == ফাঁকা) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ফেরত;
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
    যখন (nfile) {
	files++;
	জন্য (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    জন্য (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	}
	nfile = nfile->পরবর্তী;
    }
    যদি (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (দ্বিগুণ) blocks_run / blocks);
    nfile = file;
    যখন (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned পূর্ণসংখ্যা curline = 1;
	অক্ষর str[10000];

        যদি (src == ফাঁকা)
	     যাও পরবর্তী;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	জন্য (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    জন্য (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	}
	যদি (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (দ্বিগুণ) blocks_run / blocks);
        জন্য (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    যখন (curline < func->first_সারি &&
		   fgets(str, আকার(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    জন্য (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	    যদি (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (দ্বিগুণ) blocks_run / blocks);
#যদি 0
	    জন্য (j = 0; j < func->n_সারি; j++) {
	        unsigned পূর্ণসংখ্যা fline = func->সারি[j].fline;
	        unsigned পূর্ণসংখ্যা lline = func->সারি[j].lline;
		unsigned long long গুনতি_2 = func->সারি[j].গুনতি_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, গুনতি_2);
	    }
#endif
	    জন্য (j = 0; j < func->n_সারি;) {
	        unsigned পূর্ণসংখ্যা fline = func->সারি[j].fline;
	        unsigned পূর্ণসংখ্যা lline = func->সারি[j].lline;
	        unsigned long long গুনতি_2 = func->সারি[j].গুনতি_2;
		unsigned পূর্ণসংখ্যা has_zero = 0;
		unsigned পূর্ণসংখ্যা same_সারি = fline == lline;

		j++;
		যখন (j < func->n_সারি) {
	            unsigned পূর্ণসংখ্যা nfline = func->সারি[j].fline;
	            unsigned পূর্ণসংখ্যা nlline = func->সারি[j].lline;
	            unsigned long long ncount = func->সারি[j].গুনতি_2;

		    যদি (fline == nfline) {
			যদি (ncount == 0)
			    has_zero = 1;
			অন্যথা যদি (ncount > গুনতি_2)
			    গুনতি_2 =  ncount;
			same_সারি = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    অন্যথা
			বিরতি;
		}
		যদি (same_সারি)
		     lline++;

	        যখন (curline < fline &&
		       fgets(str, আকার(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		যখন (curline < lline &&
		       fgets(str, আকার(str), src)) {
		    যদি (গুনতি_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    অন্যথা যদি (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 গুনতি_2, curline, str);
		    অন্যথা
		        fprintf (fp, "%9llu:%5u:%s",
				 গুনতি_2, curline, str);
		    curline++;
		}
	    }
	}
	যখন (fgets(str, আকার(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
পরবর্তী:
	nfile = nfile->পরবর্তী;
    }
    যখন (file) {
        জন্য (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    মুক্ত (func->সারি);
        }
	মুক্ত (file->func);
	nfile = file;
	file = file->পরবর্তী;
	মুক্ত (nfile);
    }
    fclose (fp);
}
