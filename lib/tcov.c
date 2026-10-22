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

প্রকারনির্দেশ সংরচনা tcov_সারি {
    unsigned পূর্ণাঙ্ক fline;
    unsigned পূর্ণাঙ্ক lline;
    unsigned long long গুনতি_2;
} tcov_সারি;

প্রকারনির্দেশ সংরচনা tcov_function {
    বর্ণ *function;
    unsigned পূর্ণাঙ্ক first_সারি;
    unsigned পূর্ণাঙ্ক n_সারি;
    unsigned পূর্ণাঙ্ক m_সারি;
    tcov_সারি *সারি;
} tcov_function;

প্রকারনির্দেশ সংরচনা tcov_file {
    বর্ণ *filename;
    unsigned পূর্ণাঙ্ক n_func;
    unsigned পূর্ণাঙ্ক m_func;
    tcov_function *func;
    সংরচনা tcov_file *next;
} tcov_file;

স্থির FILE *open_tcov_file (বর্ণ *cov_filename)
{
    পূর্ণাঙ্ক fd;
#ifndef _WIN32
    সংরচনা flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    যদি (fd < 0)
	প্রত্যাগম রিক্ত;
  
#ifndef _WIN32
    যাবত্ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        অনুবর্ত;
#অন্যথা
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    প্রত্যাগম fdopen (fd, "r+");
}

স্থির unsigned long long get_মান(unsigned বর্ণ *p, পূর্ণাঙ্ক size)
{
    unsigned long long মান = 0;

    p += size;
    যাবত্ (size--)
 	মান = (মান << 8) | *--p;
    প্রত্যাগম মান;
}

স্থির পূর্ণাঙ্ক sort_func (ধ্রুব শূন্য *p, ধ্রুব শূন্য *q)
{
    ধ্রুব tcov_function *pp = (ধ্রুব tcov_function *) p;
    ধ্রুব tcov_function *pq = (ধ্রুব tcov_function *) q;

    প্রত্যাগম pp->first_সারি > pq->first_সারি ? 1 :
	   pp->first_সারি < pq->first_সারি ? -1 : 0;
}

স্থির পূর্ণাঙ্ক sort_সারি (ধ্রুব শূন্য *p, ধ্রুব শূন্য *q)
{
    ধ্রুব tcov_সারি *pp = (ধ্রুব tcov_সারি *) p;
    ধ্রুব tcov_সারি *pq = (ধ্রুব tcov_সারি *) q;

    প্রত্যাগম pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->গুনতি_2 < pq->গুনতি_2 ? 1 :
	   pp->গুনতি_2 > pq->গুনতি_2 ? -1 : 0;
}

/* sort to let inline functions work */
স্থির tcov_file *sort_test_coverage (unsigned বর্ণ *p)
{
    পূর্ণাঙ্ক i, j, k;
    unsigned বর্ণ *start = p;
    tcov_file *file = রিক্ত;
    tcov_file *nfile;

    p += 4;
    যাবত্ (*p) {
        বর্ণ *filename = (বর্ণ *)p;
	size_t len = strlen (filename);

	nfile = file;
	যাবত্ (nfile) {
	    যদি (strcmp (nfile->filename, filename) == 0)
		ভঙ্গ;
	    nfile = nfile->next;
	}
	যদি (nfile == রিক্ত) {
	    nfile = malloc (পরিমাণ(tcov_file));
	    যদি (nfile == রিক্ত) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        প্রত্যাগম file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = রিক্ত;
	    nfile->next = রিক্ত;
	    যদি (file == রিক্ত)
	        file = nfile;
	    অন্যথা {
		tcov_file *lfile = file;

	        যাবত্ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	যাবত্ (*p) {
	    পূর্ণাঙ্ক i;
	    বর্ণ *function = (বর্ণ *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    প্রতি (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		যদি (strcmp (func->function, function) == 0)
		    ভঙ্গ;
	    }
	    যদি (i == nfile->n_func) {
	        যদি (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   পরিমাণ (tcov_function));
		    যদি (nfile->func == রিক্ত) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        প্রত্যাগম file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_সারি = get_মান (p, 8);
	        func->n_সারি = 0;
	        func->m_সারি = 0;
	        func->সারি = রিক্ত;
	    }
	    p += 8;
	    যাবত্ (*p) {
		tcov_সারি *সারি;
		unsigned long long val;

		যদি (func->n_সারি >= func->m_সারি) {
		    func->m_সারি = func->m_সারি == 0 ? 4 : func->m_সারি * 2;
		    func->সারি = realloc (func->সারি,
					  func->m_সারি * পরিমাণ (tcov_সারি));
		    যদি (func->সারি == রিক্ত) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        প্রত্যাগম file;
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
    যাবত্ (nfile) {
	qsort (nfile->func, nfile->n_func, পরিমাণ (tcov_function), sort_func);
	প্রতি (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->সারি, func->n_সারি, পরিমাণ (tcov_সারি), sort_সারি);
        }
	nfile = nfile->next;
    }
    প্রত্যাগম file;
}

/* merge with previous tcov file */
স্থির শূন্য merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned পূর্ণাঙ্ক *pruns)
{
    unsigned পূর্ণাঙ্ক runs;
    বর্ণ *p;
    বর্ণ str[10000];
    
    *pruns = 1;
    যদি (fp == রিক্ত)
        প্রত্যাগম;
    যদি (fgets(str, পরিমাণ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    যাবত্ (file) {
	পূর্ণাঙ্ক i;
	size_t len = strlen (file->filename);

	যাবত্ (fgets(str, পরিমাণ(str), fp) &&
	       (p = strstr(str, "0:File:")) == রিক্ত) {}
        যদি ((p = strstr(str, "0:File:")) == রিক্ত ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    ভঙ্গ;
	প্রতি (i = 0; i < file->n_func; i++) {
	    পূর্ণাঙ্ক j;
	    tcov_function *func = &file->func[i];
	    unsigned পূর্ণাঙ্ক next_zero = 0;
	    unsigned পূর্ণাঙ্ক curline = 0;

	    প্রতি (j = 0; j < func->n_সারি; j++) {
		tcov_সারি *সারি = &func->সারি[j];
	        unsigned পূর্ণাঙ্ক fline = সারি->fline;
	        unsigned long long গুনতি_2;
		unsigned পূর্ণাঙ্ক tmp;
		বর্ণ c;

		যাবত্ (curline < fline &&
		       fgets(str, পরিমাণ(str), fp))
		    যদি ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		যদি (sscanf (str, "%llu%c\n", &গুনতি_2, &c) == 2) {
		    যদি (next_zero == 0)
		        সারি->গুনতি_2 += গুনতি_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
শূন্য __store_test_coverage (unsigned বর্ণ * p)
{
    পূর্ণাঙ্ক i, j;
    unsigned পূর্ণাঙ্ক files;
    unsigned পূর্ণাঙ্ক funcs;
    unsigned পূর্ণাঙ্ক blocks;
    unsigned পূর্ণাঙ্ক blocks_run;
    unsigned পূর্ণাঙ্ক runs;
    বর্ণ *cov_filename = (বর্ণ *)p + get_মান (p, 4);
    FILE *fp;
    বর্ণ *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    যদি (fp == রিক্ত) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	প্রত্যাগম;
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
    যাবত্ (nfile) {
	files++;
	প্রতি (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    প্রতি (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    যদি (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (দ্বিগুণ) blocks_run / blocks);
    nfile = file;
    যাবত্ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned পূর্ণাঙ্ক curline = 1;
	বর্ণ str[10000];

        যদি (src == রিক্ত)
	     গচ্ছ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	প্রতি (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    প্রতি (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	}
	যদি (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (দ্বিগুণ) blocks_run / blocks);
        প্রতি (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    যাবত্ (curline < func->first_সারি &&
		   fgets(str, পরিমাণ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    প্রতি (j = 0; j < func->n_সারি; j++) {
		blocks++;
		blocks_run += func->সারি[j].গুনতি_2 != 0;
	    }
	    যদি (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (দ্বিগুণ) blocks_run / blocks);
#যদি 0
	    প্রতি (j = 0; j < func->n_সারি; j++) {
	        unsigned পূর্ণাঙ্ক fline = func->সারি[j].fline;
	        unsigned পূর্ণাঙ্ক lline = func->সারি[j].lline;
		unsigned long long গুনতি_2 = func->সারি[j].গুনতি_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, গুনতি_2);
	    }
#endif
	    প্রতি (j = 0; j < func->n_সারি;) {
	        unsigned পূর্ণাঙ্ক fline = func->সারি[j].fline;
	        unsigned পূর্ণাঙ্ক lline = func->সারি[j].lline;
	        unsigned long long গুনতি_2 = func->সারি[j].গুনতি_2;
		unsigned পূর্ণাঙ্ক has_zero = 0;
		unsigned পূর্ণাঙ্ক same_সারি = fline == lline;

		j++;
		যাবত্ (j < func->n_সারি) {
	            unsigned পূর্ণাঙ্ক nfline = func->সারি[j].fline;
	            unsigned পূর্ণাঙ্ক nlline = func->সারি[j].lline;
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
			ভঙ্গ;
		}
		যদি (same_সারি)
		     lline++;

	        যাবত্ (curline < fline &&
		       fgets(str, পরিমাণ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		যাবত্ (curline < lline &&
		       fgets(str, পরিমাণ(str), src)) {
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
	যাবত্ (fgets(str, পরিমাণ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    যাবত্ (file) {
        প্রতি (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    মুক্ত (func->সারি);
        }
	মুক্ত (file->func);
	nfile = file;
	file = file->next;
	মুক্ত (nfile);
    }
    fclose (fp);
}
