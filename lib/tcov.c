#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <fcntl.h>
#ifndef _WIN32
#അന്തര്ഭാവ <unistd.h>
#അന്തര്ഭാവ <errno.h>
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <windows.h>
#അന്തര്ഭാവ <io.h>
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

തരനിർവചനം ഘടന tcov_വരി {
    unsigned പൂർണ്ണസംഖ്യ fline;
    unsigned പൂർണ്ണസംഖ്യ lline;
    unsigned long long എണ്ണം_2;
} tcov_വരി;

തരനിർവചനം ഘടന tcov_function {
    അക്ഷരം *function;
    unsigned പൂർണ്ണസംഖ്യ first_വരി;
    unsigned പൂർണ്ണസംഖ്യ n_വരി;
    unsigned പൂർണ്ണസംഖ്യ m_വരി;
    tcov_വരി *വരി;
} tcov_function;

തരനിർവചനം ഘടന tcov_file {
    അക്ഷരം *filename;
    unsigned പൂർണ്ണസംഖ്യ n_func;
    unsigned പൂർണ്ണസംഖ്യ m_func;
    tcov_function *func;
    ഘടന tcov_file *next;
} tcov_file;

സ്ഥിതം FILE *open_tcov_file (അക്ഷരം *cov_filename)
{
    പൂർണ്ണസംഖ്യ fd;
#ifndef _WIN32
    ഘടന flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    എങ്കിൽ (fd < 0)
	തിരികെ ശൂന്യ;
  
#ifndef _WIN32
    ആകുമ്പോൾ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        തുടരുക;
#അല്ലെങ്കിൽ
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    തിരികെ fdopen (fd, "r+");
}

സ്ഥിതം unsigned long long get_മൂല്യം(unsigned അക്ഷരം *p, പൂർണ്ണസംഖ്യ size)
{
    unsigned long long മൂല്യം = 0;

    p += size;
    ആകുമ്പോൾ (size--)
 	മൂല്യം = (മൂല്യം << 8) | *--p;
    തിരികെ മൂല്യം;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ sort_func (സ്ഥിരം ശൂന്യം *p, സ്ഥിരം ശൂന്യം *q)
{
    സ്ഥിരം tcov_function *pp = (സ്ഥിരം tcov_function *) p;
    സ്ഥിരം tcov_function *pq = (സ്ഥിരം tcov_function *) q;

    തിരികെ pp->first_വരി > pq->first_വരി ? 1 :
	   pp->first_വരി < pq->first_വരി ? -1 : 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ sort_വരി (സ്ഥിരം ശൂന്യം *p, സ്ഥിരം ശൂന്യം *q)
{
    സ്ഥിരം tcov_വരി *pp = (സ്ഥിരം tcov_വരി *) p;
    സ്ഥിരം tcov_വരി *pq = (സ്ഥിരം tcov_വരി *) q;

    തിരികെ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->എണ്ണം_2 < pq->എണ്ണം_2 ? 1 :
	   pp->എണ്ണം_2 > pq->എണ്ണം_2 ? -1 : 0;
}

/* sort to let inline functions work */
സ്ഥിതം tcov_file *sort_test_coverage (unsigned അക്ഷരം *p)
{
    പൂർണ്ണസംഖ്യ i, j, k;
    unsigned അക്ഷരം *start = p;
    tcov_file *file = ശൂന്യ;
    tcov_file *nfile;

    p += 4;
    ആകുമ്പോൾ (*p) {
        അക്ഷരം *filename = (അക്ഷരം *)p;
	size_t len = strlen (filename);

	nfile = file;
	ആകുമ്പോൾ (nfile) {
	    എങ്കിൽ (strcmp (nfile->filename, filename) == 0)
		നിർത്തുക;
	    nfile = nfile->next;
	}
	എങ്കിൽ (nfile == ശൂന്യ) {
	    nfile = malloc (വലുപ്പം(tcov_file));
	    എങ്കിൽ (nfile == ശൂന്യ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        തിരികെ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ശൂന്യ;
	    nfile->next = ശൂന്യ;
	    എങ്കിൽ (file == ശൂന്യ)
	        file = nfile;
	    അല്ലെങ്കിൽ {
		tcov_file *lfile = file;

	        ആകുമ്പോൾ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ആകുമ്പോൾ (*p) {
	    പൂർണ്ണസംഖ്യ i;
	    അക്ഷരം *function = (അക്ഷരം *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    വേണ്ടി (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		എങ്കിൽ (strcmp (func->function, function) == 0)
		    നിർത്തുക;
	    }
	    എങ്കിൽ (i == nfile->n_func) {
	        എങ്കിൽ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   വലുപ്പം (tcov_function));
		    എങ്കിൽ (nfile->func == ശൂന്യ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        തിരികെ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_വരി = get_മൂല്യം (p, 8);
	        func->n_വരി = 0;
	        func->m_വരി = 0;
	        func->വരി = ശൂന്യ;
	    }
	    p += 8;
	    ആകുമ്പോൾ (*p) {
		tcov_വരി *വരി;
		unsigned long long val;

		എങ്കിൽ (func->n_വരി >= func->m_വരി) {
		    func->m_വരി = func->m_വരി == 0 ? 4 : func->m_വരി * 2;
		    func->വരി = realloc (func->വരി,
					  func->m_വരി * വലുപ്പം (tcov_വരി));
		    എങ്കിൽ (func->വരി == ശൂന്യ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        തിരികെ file;
		    }
		}
		വരി = &func->വരി[func->n_വരി++];
		val = get_മൂല്യം (p, 8);
	        വരി->fline = (val >> 8) & 0xfffffffULL;
	        വരി->lline = val >> 36;
	        വരി->എണ്ണം_2 = get_മൂല്യം (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    ആകുമ്പോൾ (nfile) {
	qsort (nfile->func, nfile->n_func, വലുപ്പം (tcov_function), sort_func);
	വേണ്ടി (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->വരി, func->n_വരി, വലുപ്പം (tcov_വരി), sort_വരി);
        }
	nfile = nfile->next;
    }
    തിരികെ file;
}

/* merge with previous tcov file */
സ്ഥിതം ശൂന്യം merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned പൂർണ്ണസംഖ്യ *pruns)
{
    unsigned പൂർണ്ണസംഖ്യ runs;
    അക്ഷരം *p;
    അക്ഷരം str[10000];
    
    *pruns = 1;
    എങ്കിൽ (fp == ശൂന്യ)
        തിരികെ;
    എങ്കിൽ (fgets(str, വലുപ്പം(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ആകുമ്പോൾ (file) {
	പൂർണ്ണസംഖ്യ i;
	size_t len = strlen (file->filename);

	ആകുമ്പോൾ (fgets(str, വലുപ്പം(str), fp) &&
	       (p = strstr(str, "0:File:")) == ശൂന്യ) {}
        എങ്കിൽ ((p = strstr(str, "0:File:")) == ശൂന്യ ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    നിർത്തുക;
	വേണ്ടി (i = 0; i < file->n_func; i++) {
	    പൂർണ്ണസംഖ്യ j;
	    tcov_function *func = &file->func[i];
	    unsigned പൂർണ്ണസംഖ്യ next_zero = 0;
	    unsigned പൂർണ്ണസംഖ്യ curline = 0;

	    വേണ്ടി (j = 0; j < func->n_വരി; j++) {
		tcov_വരി *വരി = &func->വരി[j];
	        unsigned പൂർണ്ണസംഖ്യ fline = വരി->fline;
	        unsigned long long എണ്ണം_2;
		unsigned പൂർണ്ണസംഖ്യ tmp;
		അക്ഷരം c;

		ആകുമ്പോൾ (curline < fline &&
		       fgets(str, വലുപ്പം(str), fp))
		    എങ്കിൽ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		എങ്കിൽ (sscanf (str, "%llu%c\n", &എണ്ണം_2, &c) == 2) {
		    എങ്കിൽ (next_zero == 0)
		        വരി->എണ്ണം_2 += എണ്ണം_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
ശൂന്യം __store_test_coverage (unsigned അക്ഷരം * p)
{
    പൂർണ്ണസംഖ്യ i, j;
    unsigned പൂർണ്ണസംഖ്യ files;
    unsigned പൂർണ്ണസംഖ്യ funcs;
    unsigned പൂർണ്ണസംഖ്യ blocks;
    unsigned പൂർണ്ണസംഖ്യ blocks_run;
    unsigned പൂർണ്ണസംഖ്യ runs;
    അക്ഷരം *cov_filename = (അക്ഷരം *)p + get_മൂല്യം (p, 4);
    FILE *fp;
    അക്ഷരം *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    എങ്കിൽ (fp == ശൂന്യ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	തിരികെ;
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
    ആകുമ്പോൾ (nfile) {
	files++;
	വേണ്ടി (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    വേണ്ടി (j = 0; j < func->n_വരി; j++) {
		blocks++;
		blocks_run += func->വരി[j].എണ്ണം_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    എങ്കിൽ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ഇരട്ട) blocks_run / blocks);
    nfile = file;
    ആകുമ്പോൾ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned പൂർണ്ണസംഖ്യ curline = 1;
	അക്ഷരം str[10000];

        എങ്കിൽ (src == ശൂന്യ)
	     പോകുക next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	വേണ്ടി (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    വേണ്ടി (j = 0; j < func->n_വരി; j++) {
		blocks++;
		blocks_run += func->വരി[j].എണ്ണം_2 != 0;
	    }
	}
	എങ്കിൽ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ഇരട്ട) blocks_run / blocks);
        വേണ്ടി (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ആകുമ്പോൾ (curline < func->first_വരി &&
		   fgets(str, വലുപ്പം(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    വേണ്ടി (j = 0; j < func->n_വരി; j++) {
		blocks++;
		blocks_run += func->വരി[j].എണ്ണം_2 != 0;
	    }
	    എങ്കിൽ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ഇരട്ട) blocks_run / blocks);
#എങ്കിൽ 0
	    വേണ്ടി (j = 0; j < func->n_വരി; j++) {
	        unsigned പൂർണ്ണസംഖ്യ fline = func->വരി[j].fline;
	        unsigned പൂർണ്ണസംഖ്യ lline = func->വരി[j].lline;
		unsigned long long എണ്ണം_2 = func->വരി[j].എണ്ണം_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, എണ്ണം_2);
	    }
#endif
	    വേണ്ടി (j = 0; j < func->n_വരി;) {
	        unsigned പൂർണ്ണസംഖ്യ fline = func->വരി[j].fline;
	        unsigned പൂർണ്ണസംഖ്യ lline = func->വരി[j].lline;
	        unsigned long long എണ്ണം_2 = func->വരി[j].എണ്ണം_2;
		unsigned പൂർണ്ണസംഖ്യ has_zero = 0;
		unsigned പൂർണ്ണസംഖ്യ same_വരി = fline == lline;

		j++;
		ആകുമ്പോൾ (j < func->n_വരി) {
	            unsigned പൂർണ്ണസംഖ്യ nfline = func->വരി[j].fline;
	            unsigned പൂർണ്ണസംഖ്യ nlline = func->വരി[j].lline;
	            unsigned long long ncount = func->വരി[j].എണ്ണം_2;

		    എങ്കിൽ (fline == nfline) {
			എങ്കിൽ (ncount == 0)
			    has_zero = 1;
			അല്ലെങ്കിൽ എങ്കിൽ (ncount > എണ്ണം_2)
			    എണ്ണം_2 =  ncount;
			same_വരി = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    അല്ലെങ്കിൽ
			നിർത്തുക;
		}
		എങ്കിൽ (same_വരി)
		     lline++;

	        ആകുമ്പോൾ (curline < fline &&
		       fgets(str, വലുപ്പം(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ആകുമ്പോൾ (curline < lline &&
		       fgets(str, വലുപ്പം(str), src)) {
		    എങ്കിൽ (എണ്ണം_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    അല്ലെങ്കിൽ എങ്കിൽ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 എണ്ണം_2, curline, str);
		    അല്ലെങ്കിൽ
		        fprintf (fp, "%9llu:%5u:%s",
				 എണ്ണം_2, curline, str);
		    curline++;
		}
	    }
	}
	ആകുമ്പോൾ (fgets(str, വലുപ്പം(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ആകുമ്പോൾ (file) {
        വേണ്ടി (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    സ്വതന്ത്രം (func->വരി);
        }
	സ്വതന്ത്രം (file->func);
	nfile = file;
	file = file->next;
	സ്വതന്ത്രം (nfile);
    }
    fclose (fp);
}
