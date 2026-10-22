#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <fcntl.h>
#ifndef _WIN32
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <io.h>
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

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tcov_ಸಾಲು {
    unsigned ಪೂರ್ಣಾಙ್ಕ fline;
    unsigned ಪೂರ್ಣಾಙ್ಕ lline;
    unsigned long long ಎಣಿಕೆ_2;
} tcov_ಸಾಲು;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tcov_function {
    ವರ್ಣ *function;
    unsigned ಪೂರ್ಣಾಙ್ಕ first_ಸಾಲು;
    unsigned ಪೂರ್ಣಾಙ್ಕ n_ಸಾಲು;
    unsigned ಪೂರ್ಣಾಙ್ಕ m_ಸಾಲು;
    tcov_ಸಾಲು *ಸಾಲು;
} tcov_function;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tcov_file {
    ವರ್ಣ *filename;
    unsigned ಪೂರ್ಣಾಙ್ಕ n_func;
    unsigned ಪೂರ್ಣಾಙ್ಕ m_func;
    tcov_function *func;
    ಸಂರಚನಾ tcov_file *next;
} tcov_file;

ಸ್ಥಿರ FILE *open_tcov_file (ವರ್ಣ *cov_filename)
{
    ಪೂರ್ಣಾಙ್ಕ fd;
#ifndef _WIN32
    ಸಂರಚನಾ flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ಯದಿ (fd < 0)
	ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
  
#ifndef _WIN32
    ಯಾವತ್ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        ಅನುವರ್ತ;
#ಅನ್ಯಥಾ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ಪ್ರತ್ಯಾಗಮ fdopen (fd, "r+");
}

ಸ್ಥಿರ unsigned long long get_ಮೌಲ್ಯ(unsigned ವರ್ಣ *p, ಪೂರ್ಣಾಙ್ಕ size)
{
    unsigned long long ಮೌಲ್ಯ = 0;

    p += size;
    ಯಾವತ್ (size--)
 	ಮೌಲ್ಯ = (ಮೌಲ್ಯ << 8) | *--p;
    ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sort_func (ಧ್ರುವ ಶೂನ್ಯ *p, ಧ್ರುವ ಶೂನ್ಯ *q)
{
    ಧ್ರುವ tcov_function *pp = (ಧ್ರುವ tcov_function *) p;
    ಧ್ರುವ tcov_function *pq = (ಧ್ರುವ tcov_function *) q;

    ಪ್ರತ್ಯಾಗಮ pp->first_ಸಾಲು > pq->first_ಸಾಲು ? 1 :
	   pp->first_ಸಾಲು < pq->first_ಸಾಲು ? -1 : 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sort_ಸಾಲು (ಧ್ರುವ ಶೂನ್ಯ *p, ಧ್ರುವ ಶೂನ್ಯ *q)
{
    ಧ್ರುವ tcov_ಸಾಲು *pp = (ಧ್ರುವ tcov_ಸಾಲು *) p;
    ಧ್ರುವ tcov_ಸಾಲು *pq = (ಧ್ರುವ tcov_ಸಾಲು *) q;

    ಪ್ರತ್ಯಾಗಮ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ಎಣಿಕೆ_2 < pq->ಎಣಿಕೆ_2 ? 1 :
	   pp->ಎಣಿಕೆ_2 > pq->ಎಣಿಕೆ_2 ? -1 : 0;
}

/* sort to let inline functions work */
ಸ್ಥಿರ tcov_file *sort_test_coverage (unsigned ವರ್ಣ *p)
{
    ಪೂರ್ಣಾಙ್ಕ i, j, k;
    unsigned ವರ್ಣ *start = p;
    tcov_file *file = ರಿಕ್ತ;
    tcov_file *nfile;

    p += 4;
    ಯಾವತ್ (*p) {
        ವರ್ಣ *filename = (ವರ್ಣ *)p;
	size_t len = strlen (filename);

	nfile = file;
	ಯಾವತ್ (nfile) {
	    ಯದಿ (strcmp (nfile->filename, filename) == 0)
		ಭಙ್ಗ;
	    nfile = nfile->next;
	}
	ಯದಿ (nfile == ರಿಕ್ತ) {
	    nfile = malloc (ಪರಿಮಾಣ(tcov_file));
	    ಯದಿ (nfile == ರಿಕ್ತ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ಪ್ರತ್ಯಾಗಮ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ರಿಕ್ತ;
	    nfile->next = ರಿಕ್ತ;
	    ಯದಿ (file == ರಿಕ್ತ)
	        file = nfile;
	    ಅನ್ಯಥಾ {
		tcov_file *lfile = file;

	        ಯಾವತ್ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ಯಾವತ್ (*p) {
	    ಪೂರ್ಣಾಙ್ಕ i;
	    ವರ್ಣ *function = (ವರ್ಣ *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    ಪ್ರತಿ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ಯದಿ (strcmp (func->function, function) == 0)
		    ಭಙ್ಗ;
	    }
	    ಯದಿ (i == nfile->n_func) {
	        ಯದಿ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   ಪರಿಮಾಣ (tcov_function));
		    ಯದಿ (nfile->func == ರಿಕ್ತ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ಪ್ರತ್ಯಾಗಮ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_ಸಾಲು = get_ಮೌಲ್ಯ (p, 8);
	        func->n_ಸಾಲು = 0;
	        func->m_ಸಾಲು = 0;
	        func->ಸಾಲು = ರಿಕ್ತ;
	    }
	    p += 8;
	    ಯಾವತ್ (*p) {
		tcov_ಸಾಲು *ಸಾಲು;
		unsigned long long val;

		ಯದಿ (func->n_ಸಾಲು >= func->m_ಸಾಲು) {
		    func->m_ಸಾಲು = func->m_ಸಾಲು == 0 ? 4 : func->m_ಸಾಲು * 2;
		    func->ಸಾಲು = realloc (func->ಸಾಲು,
					  func->m_ಸಾಲು * ಪರಿಮಾಣ (tcov_ಸಾಲು));
		    ಯದಿ (func->ಸಾಲು == ರಿಕ್ತ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ಪ್ರತ್ಯಾಗಮ file;
		    }
		}
		ಸಾಲು = &func->ಸಾಲು[func->n_ಸಾಲು++];
		val = get_ಮೌಲ್ಯ (p, 8);
	        ಸಾಲು->fline = (val >> 8) & 0xfffffffULL;
	        ಸಾಲು->lline = val >> 36;
	        ಸಾಲು->ಎಣಿಕೆ_2 = get_ಮೌಲ್ಯ (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    ಯಾವತ್ (nfile) {
	qsort (nfile->func, nfile->n_func, ಪರಿಮಾಣ (tcov_function), sort_func);
	ಪ್ರತಿ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->ಸಾಲು, func->n_ಸಾಲು, ಪರಿಮಾಣ (tcov_ಸಾಲು), sort_ಸಾಲು);
        }
	nfile = nfile->next;
    }
    ಪ್ರತ್ಯಾಗಮ file;
}

/* merge with previous tcov file */
ಸ್ಥಿರ ಶೂನ್ಯ merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned ಪೂರ್ಣಾಙ್ಕ *pruns)
{
    unsigned ಪೂರ್ಣಾಙ್ಕ runs;
    ವರ್ಣ *p;
    ವರ್ಣ str[10000];
    
    *pruns = 1;
    ಯದಿ (fp == ರಿಕ್ತ)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (fgets(str, ಪರಿಮಾಣ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ಯಾವತ್ (file) {
	ಪೂರ್ಣಾಙ್ಕ i;
	size_t len = strlen (file->filename);

	ಯಾವತ್ (fgets(str, ಪರಿಮಾಣ(str), fp) &&
	       (p = strstr(str, "0:File:")) == ರಿಕ್ತ) {}
        ಯದಿ ((p = strstr(str, "0:File:")) == ರಿಕ್ತ ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    ಭಙ್ಗ;
	ಪ್ರತಿ (i = 0; i < file->n_func; i++) {
	    ಪೂರ್ಣಾಙ್ಕ j;
	    tcov_function *func = &file->func[i];
	    unsigned ಪೂರ್ಣಾಙ್ಕ next_zero = 0;
	    unsigned ಪೂರ್ಣಾಙ್ಕ curline = 0;

	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		tcov_ಸಾಲು *ಸಾಲು = &func->ಸಾಲು[j];
	        unsigned ಪೂರ್ಣಾಙ್ಕ fline = ಸಾಲು->fline;
	        unsigned long long ಎಣಿಕೆ_2;
		unsigned ಪೂರ್ಣಾಙ್ಕ tmp;
		ವರ್ಣ c;

		ಯಾವತ್ (curline < fline &&
		       fgets(str, ಪರಿಮಾಣ(str), fp))
		    ಯದಿ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ಯದಿ (sscanf (str, "%llu%c\n", &ಎಣಿಕೆ_2, &c) == 2) {
		    ಯದಿ (next_zero == 0)
		        ಸಾಲು->ಎಣಿಕೆ_2 += ಎಣಿಕೆ_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
ಶೂನ್ಯ __store_test_coverage (unsigned ವರ್ಣ * p)
{
    ಪೂರ್ಣಾಙ್ಕ i, j;
    unsigned ಪೂರ್ಣಾಙ್ಕ files;
    unsigned ಪೂರ್ಣಾಙ್ಕ funcs;
    unsigned ಪೂರ್ಣಾಙ್ಕ blocks;
    unsigned ಪೂರ್ಣಾಙ್ಕ blocks_run;
    unsigned ಪೂರ್ಣಾಙ್ಕ runs;
    ವರ್ಣ *cov_filename = (ವರ್ಣ *)p + get_ಮೌಲ್ಯ (p, 4);
    FILE *fp;
    ವರ್ಣ *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ಯದಿ (fp == ರಿಕ್ತ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ಪ್ರತ್ಯಾಗಮ;
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
    ಯಾವತ್ (nfile) {
	files++;
	ಪ್ರತಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		blocks++;
		blocks_run += func->ಸಾಲು[j].ಎಣಿಕೆ_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    ಯದಿ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ದ್ವಿಗುಣ) blocks_run / blocks);
    nfile = file;
    ಯಾವತ್ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned ಪೂರ್ಣಾಙ್ಕ curline = 1;
	ವರ್ಣ str[10000];

        ಯದಿ (src == ರಿಕ್ತ)
	     ಗಚ್ಛ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	ಪ್ರತಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		blocks++;
		blocks_run += func->ಸಾಲು[j].ಎಣಿಕೆ_2 != 0;
	    }
	}
	ಯದಿ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ದ್ವಿಗುಣ) blocks_run / blocks);
        ಪ್ರತಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ಯಾವತ್ (curline < func->first_ಸಾಲು &&
		   fgets(str, ಪರಿಮಾಣ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		blocks++;
		blocks_run += func->ಸಾಲು[j].ಎಣಿಕೆ_2 != 0;
	    }
	    ಯದಿ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ದ್ವಿಗುಣ) blocks_run / blocks);
#ಯದಿ 0
	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು; j++) {
	        unsigned ಪೂರ್ಣಾಙ್ಕ fline = func->ಸಾಲು[j].fline;
	        unsigned ಪೂರ್ಣಾಙ್ಕ lline = func->ಸಾಲು[j].lline;
		unsigned long long ಎಣಿಕೆ_2 = func->ಸಾಲು[j].ಎಣಿಕೆ_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, ಎಣಿಕೆ_2);
	    }
#endif
	    ಪ್ರತಿ (j = 0; j < func->n_ಸಾಲು;) {
	        unsigned ಪೂರ್ಣಾಙ್ಕ fline = func->ಸಾಲು[j].fline;
	        unsigned ಪೂರ್ಣಾಙ್ಕ lline = func->ಸಾಲು[j].lline;
	        unsigned long long ಎಣಿಕೆ_2 = func->ಸಾಲು[j].ಎಣಿಕೆ_2;
		unsigned ಪೂರ್ಣಾಙ್ಕ has_zero = 0;
		unsigned ಪೂರ್ಣಾಙ್ಕ same_ಸಾಲು = fline == lline;

		j++;
		ಯಾವತ್ (j < func->n_ಸಾಲು) {
	            unsigned ಪೂರ್ಣಾಙ್ಕ nfline = func->ಸಾಲು[j].fline;
	            unsigned ಪೂರ್ಣಾಙ್ಕ nlline = func->ಸಾಲು[j].lline;
	            unsigned long long ncount = func->ಸಾಲು[j].ಎಣಿಕೆ_2;

		    ಯದಿ (fline == nfline) {
			ಯದಿ (ncount == 0)
			    has_zero = 1;
			ಅನ್ಯಥಾ ಯದಿ (ncount > ಎಣಿಕೆ_2)
			    ಎಣಿಕೆ_2 =  ncount;
			same_ಸಾಲು = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ಅನ್ಯಥಾ
			ಭಙ್ಗ;
		}
		ಯದಿ (same_ಸಾಲು)
		     lline++;

	        ಯಾವತ್ (curline < fline &&
		       fgets(str, ಪರಿಮಾಣ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ಯಾವತ್ (curline < lline &&
		       fgets(str, ಪರಿಮಾಣ(str), src)) {
		    ಯದಿ (ಎಣಿಕೆ_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ಅನ್ಯಥಾ ಯದಿ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ಎಣಿಕೆ_2, curline, str);
		    ಅನ್ಯಥಾ
		        fprintf (fp, "%9llu:%5u:%s",
				 ಎಣಿಕೆ_2, curline, str);
		    curline++;
		}
	    }
	}
	ಯಾವತ್ (fgets(str, ಪರಿಮಾಣ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ಯಾವತ್ (file) {
        ಪ್ರತಿ (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    ಮುಕ್ತ (func->ಸಾಲು);
        }
	ಮುಕ್ತ (file->func);
	nfile = file;
	file = file->next;
	ಮುಕ್ತ (nfile);
    }
    fclose (fp);
}
