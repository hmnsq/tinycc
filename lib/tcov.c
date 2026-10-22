#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <fcntl.h>
#ifndef _WIN32
#அந்தர்பாவ <unistd.h>
#அந்தர்பாவ <errno.h>
#இல்லையெனில்
#அந்தர்பாவ <windows.h>
#அந்தர்பாவ <io.h>
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

வகைவரை கட்டமைப்பு tcov_வரி {
    unsigned முழு fline;
    unsigned முழு lline;
    unsigned long long மொத்தம்_2;
} tcov_வரி;

வகைவரை கட்டமைப்பு tcov_function {
    எழுத்து *function;
    unsigned முழு first_வரி;
    unsigned முழு n_வரி;
    unsigned முழு m_வரி;
    tcov_வரி *வரி;
} tcov_function;

வகைவரை கட்டமைப்பு tcov_file {
    எழுத்து *filename;
    unsigned முழு n_func;
    unsigned முழு m_func;
    tcov_function *func;
    கட்டமைப்பு tcov_file *next;
} tcov_file;

நிலையான FILE *open_tcov_file (எழுத்து *cov_filename)
{
    முழு fd;
#ifndef _WIN32
    கட்டமைப்பு flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    எனில் (fd < 0)
	திரும்பு வெற்று;
  
#ifndef _WIN32
    போது (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        தொடர்;
#இல்லையெனில்
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    திரும்பு fdopen (fd, "r+");
}

நிலையான unsigned long long get_மதிப்பு(unsigned எழுத்து *p, முழு size)
{
    unsigned long long மதிப்பு = 0;

    p += size;
    போது (size--)
 	மதிப்பு = (மதிப்பு << 8) | *--p;
    திரும்பு மதிப்பு;
}

நிலையான முழு sort_func (மாறிலி வெறுமை *p, மாறிலி வெறுமை *q)
{
    மாறிலி tcov_function *pp = (மாறிலி tcov_function *) p;
    மாறிலி tcov_function *pq = (மாறிலி tcov_function *) q;

    திரும்பு pp->first_வரி > pq->first_வரி ? 1 :
	   pp->first_வரி < pq->first_வரி ? -1 : 0;
}

நிலையான முழு sort_வரி (மாறிலி வெறுமை *p, மாறிலி வெறுமை *q)
{
    மாறிலி tcov_வரி *pp = (மாறிலி tcov_வரி *) p;
    மாறிலி tcov_வரி *pq = (மாறிலி tcov_வரி *) q;

    திரும்பு pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->மொத்தம்_2 < pq->மொத்தம்_2 ? 1 :
	   pp->மொத்தம்_2 > pq->மொத்தம்_2 ? -1 : 0;
}

/* sort to let inline functions work */
நிலையான tcov_file *sort_test_coverage (unsigned எழுத்து *p)
{
    முழு i, j, k;
    unsigned எழுத்து *start = p;
    tcov_file *file = வெற்று;
    tcov_file *nfile;

    p += 4;
    போது (*p) {
        எழுத்து *filename = (எழுத்து *)p;
	size_t len = strlen (filename);

	nfile = file;
	போது (nfile) {
	    எனில் (strcmp (nfile->filename, filename) == 0)
		நிறுத்து;
	    nfile = nfile->next;
	}
	எனில் (nfile == வெற்று) {
	    nfile = malloc (அளவு(tcov_file));
	    எனில் (nfile == வெற்று) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        திரும்பு file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = வெற்று;
	    nfile->next = வெற்று;
	    எனில் (file == வெற்று)
	        file = nfile;
	    இல்லையெனில் {
		tcov_file *lfile = file;

	        போது (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	போது (*p) {
	    முழு i;
	    எழுத்து *function = (எழுத்து *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    க்கு (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		எனில் (strcmp (func->function, function) == 0)
		    நிறுத்து;
	    }
	    எனில் (i == nfile->n_func) {
	        எனில் (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   அளவு (tcov_function));
		    எனில் (nfile->func == வெற்று) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        திரும்பு file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_வரி = get_மதிப்பு (p, 8);
	        func->n_வரி = 0;
	        func->m_வரி = 0;
	        func->வரி = வெற்று;
	    }
	    p += 8;
	    போது (*p) {
		tcov_வரி *வரி;
		unsigned long long val;

		எனில் (func->n_வரி >= func->m_வரி) {
		    func->m_வரி = func->m_வரி == 0 ? 4 : func->m_வரி * 2;
		    func->வரி = realloc (func->வரி,
					  func->m_வரி * அளவு (tcov_வரி));
		    எனில் (func->வரி == வெற்று) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        திரும்பு file;
		    }
		}
		வரி = &func->வரி[func->n_வரி++];
		val = get_மதிப்பு (p, 8);
	        வரி->fline = (val >> 8) & 0xfffffffULL;
	        வரி->lline = val >> 36;
	        வரி->மொத்தம்_2 = get_மதிப்பு (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    போது (nfile) {
	qsort (nfile->func, nfile->n_func, அளவு (tcov_function), sort_func);
	க்கு (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->வரி, func->n_வரி, அளவு (tcov_வரி), sort_வரி);
        }
	nfile = nfile->next;
    }
    திரும்பு file;
}

/* merge with previous tcov file */
நிலையான வெறுமை merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned முழு *pruns)
{
    unsigned முழு runs;
    எழுத்து *p;
    எழுத்து str[10000];
    
    *pruns = 1;
    எனில் (fp == வெற்று)
        திரும்பு;
    எனில் (fgets(str, அளவு(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    போது (file) {
	முழு i;
	size_t len = strlen (file->filename);

	போது (fgets(str, அளவு(str), fp) &&
	       (p = strstr(str, "0:File:")) == வெற்று) {}
        எனில் ((p = strstr(str, "0:File:")) == வெற்று ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    நிறுத்து;
	க்கு (i = 0; i < file->n_func; i++) {
	    முழு j;
	    tcov_function *func = &file->func[i];
	    unsigned முழு next_zero = 0;
	    unsigned முழு curline = 0;

	    க்கு (j = 0; j < func->n_வரி; j++) {
		tcov_வரி *வரி = &func->வரி[j];
	        unsigned முழு fline = வரி->fline;
	        unsigned long long மொத்தம்_2;
		unsigned முழு tmp;
		எழுத்து c;

		போது (curline < fline &&
		       fgets(str, அளவு(str), fp))
		    எனில் ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		எனில் (sscanf (str, "%llu%c\n", &மொத்தம்_2, &c) == 2) {
		    எனில் (next_zero == 0)
		        வரி->மொத்தம்_2 += மொத்தம்_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
வெறுமை __store_test_coverage (unsigned எழுத்து * p)
{
    முழு i, j;
    unsigned முழு files;
    unsigned முழு funcs;
    unsigned முழு blocks;
    unsigned முழு blocks_run;
    unsigned முழு runs;
    எழுத்து *cov_filename = (எழுத்து *)p + get_மதிப்பு (p, 4);
    FILE *fp;
    எழுத்து *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    எனில் (fp == வெற்று) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	திரும்பு;
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
    போது (nfile) {
	files++;
	க்கு (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    க்கு (j = 0; j < func->n_வரி; j++) {
		blocks++;
		blocks_run += func->வரி[j].மொத்தம்_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    எனில் (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (இரட்டை) blocks_run / blocks);
    nfile = file;
    போது (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned முழு curline = 1;
	எழுத்து str[10000];

        எனில் (src == வெற்று)
	     செல் next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	க்கு (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    க்கு (j = 0; j < func->n_வரி; j++) {
		blocks++;
		blocks_run += func->வரி[j].மொத்தம்_2 != 0;
	    }
	}
	எனில் (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (இரட்டை) blocks_run / blocks);
        க்கு (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    போது (curline < func->first_வரி &&
		   fgets(str, அளவு(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    க்கு (j = 0; j < func->n_வரி; j++) {
		blocks++;
		blocks_run += func->வரி[j].மொத்தம்_2 != 0;
	    }
	    எனில் (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (இரட்டை) blocks_run / blocks);
#எனில் 0
	    க்கு (j = 0; j < func->n_வரி; j++) {
	        unsigned முழு fline = func->வரி[j].fline;
	        unsigned முழு lline = func->வரி[j].lline;
		unsigned long long மொத்தம்_2 = func->வரி[j].மொத்தம்_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, மொத்தம்_2);
	    }
#endif
	    க்கு (j = 0; j < func->n_வரி;) {
	        unsigned முழு fline = func->வரி[j].fline;
	        unsigned முழு lline = func->வரி[j].lline;
	        unsigned long long மொத்தம்_2 = func->வரி[j].மொத்தம்_2;
		unsigned முழு has_zero = 0;
		unsigned முழு same_வரி = fline == lline;

		j++;
		போது (j < func->n_வரி) {
	            unsigned முழு nfline = func->வரி[j].fline;
	            unsigned முழு nlline = func->வரி[j].lline;
	            unsigned long long ncount = func->வரி[j].மொத்தம்_2;

		    எனில் (fline == nfline) {
			எனில் (ncount == 0)
			    has_zero = 1;
			இல்லையெனில் எனில் (ncount > மொத்தம்_2)
			    மொத்தம்_2 =  ncount;
			same_வரி = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    இல்லையெனில்
			நிறுத்து;
		}
		எனில் (same_வரி)
		     lline++;

	        போது (curline < fline &&
		       fgets(str, அளவு(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		போது (curline < lline &&
		       fgets(str, அளவு(str), src)) {
		    எனில் (மொத்தம்_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    இல்லையெனில் எனில் (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 மொத்தம்_2, curline, str);
		    இல்லையெனில்
		        fprintf (fp, "%9llu:%5u:%s",
				 மொத்தம்_2, curline, str);
		    curline++;
		}
	    }
	}
	போது (fgets(str, அளவு(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    போது (file) {
        க்கு (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    விடுவி (func->வரி);
        }
	விடுவி (file->func);
	nfile = file;
	file = file->next;
	விடுவி (nfile);
    }
    fclose (fp);
}
