#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <fcntl.h>
#ifndef _WIN32
#অন্তর্ভাৱ <unistd.h>
#অন্তর্ভাৱ <errno.h>
#অন্যথা
#অন্তর্ভাৱ <windows.h>
#অন্তর্ভাৱ <io.h>
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

প্রকারনির্দেশ সংরচনা tcov_সাৰি {
    unsigned পূর্ণাঙ্ক fline;
    unsigned পূর্ণাঙ্ক lline;
    unsigned long long গুনতি_2;
} tcov_সাৰি;

প্রকারনির্দেশ সংরচনা tcov_function {
    ৱর্ণ *function;
    unsigned পূর্ণাঙ্ক first_সাৰি;
    unsigned পূর্ণাঙ্ক n_সাৰি;
    unsigned পূর্ণাঙ্ক m_সাৰি;
    tcov_সাৰি *সাৰি;
} tcov_function;

প্রকারনির্দেশ সংরচনা tcov_file {
    ৱর্ণ *filename;
    unsigned পূর্ণাঙ্ক n_func;
    unsigned পূর্ণাঙ্ক m_func;
    tcov_function *func;
    সংরচনা tcov_file *next;
} tcov_file;

স্থির FILE *open_tcov_file (ৱর্ণ *cov_filename)
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
	ঘূৰাই রিক্ত;
  
#ifndef _WIN32
    যেতিয়ালৈ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        অনুৱর্ত;
#অন্যথা
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ঘূৰাই fdopen (fd, "r+");
}

স্থির unsigned long long get_মান(unsigned ৱর্ণ *p, পূর্ণাঙ্ক size)
{
    unsigned long long মান = 0;

    p += size;
    যেতিয়ালৈ (size--)
 	মান = (মান << 8) | *--p;
    ঘূৰাই মান;
}

স্থির পূর্ণাঙ্ক sort_func (ধ্রুৱ শূন্য *p, ধ্রুৱ শূন্য *q)
{
    ধ্রুৱ tcov_function *pp = (ধ্রুৱ tcov_function *) p;
    ধ্রুৱ tcov_function *pq = (ধ্রুৱ tcov_function *) q;

    ঘূৰাই pp->first_সাৰি > pq->first_সাৰি ? 1 :
	   pp->first_সাৰি < pq->first_সাৰি ? -1 : 0;
}

স্থির পূর্ণাঙ্ক sort_সাৰি (ধ্রুৱ শূন্য *p, ধ্রুৱ শূন্য *q)
{
    ধ্রুৱ tcov_সাৰি *pp = (ধ্রুৱ tcov_সাৰি *) p;
    ধ্রুৱ tcov_সাৰি *pq = (ধ্রুৱ tcov_সাৰি *) q;

    ঘূৰাই pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->গুনতি_2 < pq->গুনতি_2 ? 1 :
	   pp->গুনতি_2 > pq->গুনতি_2 ? -1 : 0;
}

/* sort to let inline functions work */
স্থির tcov_file *sort_test_coverage (unsigned ৱর্ণ *p)
{
    পূর্ণাঙ্ক i, j, k;
    unsigned ৱর্ণ *start = p;
    tcov_file *file = রিক্ত;
    tcov_file *nfile;

    p += 4;
    যেতিয়ালৈ (*p) {
        ৱর্ণ *filename = (ৱর্ণ *)p;
	size_t len = strlen (filename);

	nfile = file;
	যেতিয়ালৈ (nfile) {
	    যদি (strcmp (nfile->filename, filename) == 0)
		ভঙ্গ;
	    nfile = nfile->next;
	}
	যদি (nfile == রিক্ত) {
	    nfile = malloc (পরিমাণ(tcov_file));
	    যদি (nfile == রিক্ত) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ঘূৰাই file;
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

	        যেতিয়ালৈ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	যেতিয়ালৈ (*p) {
	    পূর্ণাঙ্ক i;
	    ৱর্ণ *function = (ৱর্ণ *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    বাবে (i = 0; i < nfile->n_func; i++) {
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
		        ঘূৰাই file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_সাৰি = get_মান (p, 8);
	        func->n_সাৰি = 0;
	        func->m_সাৰি = 0;
	        func->সাৰি = রিক্ত;
	    }
	    p += 8;
	    যেতিয়ালৈ (*p) {
		tcov_সাৰি *সাৰি;
		unsigned long long val;

		যদি (func->n_সাৰি >= func->m_সাৰি) {
		    func->m_সাৰি = func->m_সাৰি == 0 ? 4 : func->m_সাৰি * 2;
		    func->সাৰি = realloc (func->সাৰি,
					  func->m_সাৰি * পরিমাণ (tcov_সাৰি));
		    যদি (func->সাৰি == রিক্ত) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ঘূৰাই file;
		    }
		}
		সাৰি = &func->সাৰি[func->n_সাৰি++];
		val = get_মান (p, 8);
	        সাৰি->fline = (val >> 8) & 0xfffffffULL;
	        সাৰি->lline = val >> 36;
	        সাৰি->গুনতি_2 = get_মান (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    যেতিয়ালৈ (nfile) {
	qsort (nfile->func, nfile->n_func, পরিমাণ (tcov_function), sort_func);
	বাবে (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->সাৰি, func->n_সাৰি, পরিমাণ (tcov_সাৰি), sort_সাৰি);
        }
	nfile = nfile->next;
    }
    ঘূৰাই file;
}

/* merge with previous tcov file */
স্থির শূন্য merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned পূর্ণাঙ্ক *pruns)
{
    unsigned পূর্ণাঙ্ক runs;
    ৱর্ণ *p;
    ৱর্ণ str[10000];
    
    *pruns = 1;
    যদি (fp == রিক্ত)
        ঘূৰাই;
    যদি (fgets(str, পরিমাণ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    যেতিয়ালৈ (file) {
	পূর্ণাঙ্ক i;
	size_t len = strlen (file->filename);

	যেতিয়ালৈ (fgets(str, পরিমাণ(str), fp) &&
	       (p = strstr(str, "0:File:")) == রিক্ত) {}
        যদি ((p = strstr(str, "0:File:")) == রিক্ত ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    ভঙ্গ;
	বাবে (i = 0; i < file->n_func; i++) {
	    পূর্ণাঙ্ক j;
	    tcov_function *func = &file->func[i];
	    unsigned পূর্ণাঙ্ক next_zero = 0;
	    unsigned পূর্ণাঙ্ক curline = 0;

	    বাবে (j = 0; j < func->n_সাৰি; j++) {
		tcov_সাৰি *সাৰি = &func->সাৰি[j];
	        unsigned পূর্ণাঙ্ক fline = সাৰি->fline;
	        unsigned long long গুনতি_2;
		unsigned পূর্ণাঙ্ক tmp;
		ৱর্ণ c;

		যেতিয়ালৈ (curline < fline &&
		       fgets(str, পরিমাণ(str), fp))
		    যদি ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		যদি (sscanf (str, "%llu%c\n", &গুনতি_2, &c) == 2) {
		    যদি (next_zero == 0)
		        সাৰি->গুনতি_2 += গুনতি_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
শূন্য __store_test_coverage (unsigned ৱর্ণ * p)
{
    পূর্ণাঙ্ক i, j;
    unsigned পূর্ণাঙ্ক files;
    unsigned পূর্ণাঙ্ক funcs;
    unsigned পূর্ণাঙ্ক blocks;
    unsigned পূর্ণাঙ্ক blocks_run;
    unsigned পূর্ণাঙ্ক runs;
    ৱর্ণ *cov_filename = (ৱর্ণ *)p + get_মান (p, 4);
    FILE *fp;
    ৱর্ণ *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    যদি (fp == রিক্ত) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ঘূৰাই;
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
    যেতিয়ালৈ (nfile) {
	files++;
	বাবে (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    বাবে (j = 0; j < func->n_সাৰি; j++) {
		blocks++;
		blocks_run += func->সাৰি[j].গুনতি_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    যদি (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (দ্ৱিগুণ) blocks_run / blocks);
    nfile = file;
    যেতিয়ালৈ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned পূর্ণাঙ্ক curline = 1;
	ৱর্ণ str[10000];

        যদি (src == রিক্ত)
	     গচ্ছ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	বাবে (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    বাবে (j = 0; j < func->n_সাৰি; j++) {
		blocks++;
		blocks_run += func->সাৰি[j].গুনতি_2 != 0;
	    }
	}
	যদি (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (দ্ৱিগুণ) blocks_run / blocks);
        বাবে (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    যেতিয়ালৈ (curline < func->first_সাৰি &&
		   fgets(str, পরিমাণ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    বাবে (j = 0; j < func->n_সাৰি; j++) {
		blocks++;
		blocks_run += func->সাৰি[j].গুনতি_2 != 0;
	    }
	    যদি (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (দ্ৱিগুণ) blocks_run / blocks);
#যদি 0
	    বাবে (j = 0; j < func->n_সাৰি; j++) {
	        unsigned পূর্ণাঙ্ক fline = func->সাৰি[j].fline;
	        unsigned পূর্ণাঙ্ক lline = func->সাৰি[j].lline;
		unsigned long long গুনতি_2 = func->সাৰি[j].গুনতি_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, গুনতি_2);
	    }
#endif
	    বাবে (j = 0; j < func->n_সাৰি;) {
	        unsigned পূর্ণাঙ্ক fline = func->সাৰি[j].fline;
	        unsigned পূর্ণাঙ্ক lline = func->সাৰি[j].lline;
	        unsigned long long গুনতি_2 = func->সাৰি[j].গুনতি_2;
		unsigned পূর্ণাঙ্ক has_zero = 0;
		unsigned পূর্ণাঙ্ক same_সাৰি = fline == lline;

		j++;
		যেতিয়ালৈ (j < func->n_সাৰি) {
	            unsigned পূর্ণাঙ্ক nfline = func->সাৰি[j].fline;
	            unsigned পূর্ণাঙ্ক nlline = func->সাৰি[j].lline;
	            unsigned long long ncount = func->সাৰি[j].গুনতি_2;

		    যদি (fline == nfline) {
			যদি (ncount == 0)
			    has_zero = 1;
			অন্যথা যদি (ncount > গুনতি_2)
			    গুনতি_2 =  ncount;
			same_সাৰি = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    অন্যথা
			ভঙ্গ;
		}
		যদি (same_সাৰি)
		     lline++;

	        যেতিয়ালৈ (curline < fline &&
		       fgets(str, পরিমাণ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		যেতিয়ালৈ (curline < lline &&
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
	যেতিয়ালৈ (fgets(str, পরিমাণ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    যেতিয়ালৈ (file) {
        বাবে (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    মুক্ত (func->সাৰি);
        }
	মুক্ত (file->func);
	nfile = file;
	file = file->next;
	মুক্ত (nfile);
    }
    fclose (fp);
}
