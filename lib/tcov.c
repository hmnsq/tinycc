#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <fcntl.h>
#ifndef _WIN32
#ଅନ୍ତର୍ଭାଵ <unistd.h>
#ଅନ୍ତର୍ଭାଵ <errno.h>
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <windows.h>
#ଅନ୍ତର୍ଭାଵ <io.h>
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tcov_ଧାଡ଼ି {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା fline;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା lline;
    unsigned long long ଗଣନା_3;
} tcov_ଧାଡ଼ି;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tcov_function {
    ଅକ୍ଷର *function;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା first_ଧାଡ଼ି;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_ଧାଡ଼ି;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା m_ଧାଡ଼ି;
    tcov_ଧାଡ଼ି *ଧାଡ଼ି;
} tcov_function;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tcov_file {
    ଅକ୍ଷର *filename;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_func;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା m_func;
    tcov_function *func;
    ସଂରଚନା tcov_file *next;
} tcov_file;

ସ୍ଥିର FILE *open_tcov_file (ଅକ୍ଷର *cov_filename)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd;
#ifndef _WIN32
    ସଂରଚନା flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ଯଦି (fd < 0)
	ଫେରନ୍ତୁ ଖାଲି;
  
#ifndef _WIN32
    ଯେତେବେଳେ (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        ଜାରି;
#ଅନ୍ୟଥା
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    ଫେରନ୍ତୁ fdopen (fd, "r+");
}

ସ୍ଥିର unsigned long long get_ମୂଲ୍ୟ(unsigned ଅକ୍ଷର *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    unsigned long long ମୂଲ୍ୟ = 0;

    p += size;
    ଯେତେବେଳେ (size--)
 	ମୂଲ୍ୟ = (ମୂଲ୍ୟ << 8) | *--p;
    ଫେରନ୍ତୁ ମୂଲ୍ୟ;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା sort_func (ଅଚଳ ଶୂନ୍ୟ *p, ଅଚଳ ଶୂନ୍ୟ *q)
{
    ଅଚଳ tcov_function *pp = (ଅଚଳ tcov_function *) p;
    ଅଚଳ tcov_function *pq = (ଅଚଳ tcov_function *) q;

    ଫେରନ୍ତୁ pp->first_ଧାଡ଼ି > pq->first_ଧାଡ଼ି ? 1 :
	   pp->first_ଧାଡ଼ି < pq->first_ଧାଡ଼ି ? -1 : 0;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା sort_ଧାଡ଼ି (ଅଚଳ ଶୂନ୍ୟ *p, ଅଚଳ ଶୂନ୍ୟ *q)
{
    ଅଚଳ tcov_ଧାଡ଼ି *pp = (ଅଚଳ tcov_ଧାଡ଼ି *) p;
    ଅଚଳ tcov_ଧାଡ଼ି *pq = (ଅଚଳ tcov_ଧାଡ଼ି *) q;

    ଫେରନ୍ତୁ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ଗଣନା_3 < pq->ଗଣନା_3 ? 1 :
	   pp->ଗଣନା_3 > pq->ଗଣନା_3 ? -1 : 0;
}

/* sort to let inline functions work */
ସ୍ଥିର tcov_file *sort_test_coverage (unsigned ଅକ୍ଷର *p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, k;
    unsigned ଅକ୍ଷର *start = p;
    tcov_file *file = ଖାଲି;
    tcov_file *nfile;

    p += 4;
    ଯେତେବେଳେ (*p) {
        ଅକ୍ଷର *filename = (ଅକ୍ଷର *)p;
	size_t len = strlen (filename);

	nfile = file;
	ଯେତେବେଳେ (nfile) {
	    ଯଦି (strcmp (nfile->filename, filename) == 0)
		ଭାଙ୍ଗ;
	    nfile = nfile->next;
	}
	ଯଦି (nfile == ଖାଲି) {
	    nfile = malloc (ଆକାର(tcov_file));
	    ଯଦି (nfile == ଖାଲି) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ଫେରନ୍ତୁ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ଖାଲି;
	    nfile->next = ଖାଲି;
	    ଯଦି (file == ଖାଲି)
	        file = nfile;
	    ଅନ୍ୟଥା {
		tcov_file *lfile = file;

	        ଯେତେବେଳେ (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	ଯେତେବେଳେ (*p) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
	    ଅକ୍ଷର *function = (ଅକ୍ଷର *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    ପାଇଁ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ଯଦି (strcmp (func->function, function) == 0)
		    ଭାଙ୍ଗ;
	    }
	    ଯଦି (i == nfile->n_func) {
	        ଯଦି (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   ଆକାର (tcov_function));
		    ଯଦି (nfile->func == ଖାଲି) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ଫେରନ୍ତୁ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_ଧାଡ଼ି = get_ମୂଲ୍ୟ (p, 8);
	        func->n_ଧାଡ଼ି = 0;
	        func->m_ଧାଡ଼ି = 0;
	        func->ଧାଡ଼ି = ଖାଲି;
	    }
	    p += 8;
	    ଯେତେବେଳେ (*p) {
		tcov_ଧାଡ଼ି *ଧାଡ଼ି;
		unsigned long long val;

		ଯଦି (func->n_ଧାଡ଼ି >= func->m_ଧାଡ଼ି) {
		    func->m_ଧାଡ଼ି = func->m_ଧାଡ଼ି == 0 ? 4 : func->m_ଧାଡ଼ି * 2;
		    func->ଧାଡ଼ି = realloc (func->ଧାଡ଼ି,
					  func->m_ଧାଡ଼ି * ଆକାର (tcov_ଧାଡ଼ି));
		    ଯଦି (func->ଧାଡ଼ି == ଖାଲି) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ଫେରନ୍ତୁ file;
		    }
		}
		ଧାଡ଼ି = &func->ଧାଡ଼ି[func->n_ଧାଡ଼ି++];
		val = get_ମୂଲ୍ୟ (p, 8);
	        ଧାଡ଼ି->fline = (val >> 8) & 0xfffffffULL;
	        ଧାଡ଼ି->lline = val >> 36;
	        ଧାଡ଼ି->ଗଣନା_3 = get_ମୂଲ୍ୟ (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    ଯେତେବେଳେ (nfile) {
	qsort (nfile->func, nfile->n_func, ଆକାର (tcov_function), sort_func);
	ପାଇଁ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->ଧାଡ଼ି, func->n_ଧାଡ଼ି, ଆକାର (tcov_ଧାଡ଼ି), sort_ଧାଡ଼ି);
        }
	nfile = nfile->next;
    }
    ଫେରନ୍ତୁ file;
}

/* merge with previous tcov file */
ସ୍ଥିର ଶୂନ୍ୟ merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pruns)
{
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା runs;
    ଅକ୍ଷର *p;
    ଅକ୍ଷର str[10000];
    
    *pruns = 1;
    ଯଦି (fp == ଖାଲି)
        ଫେରନ୍ତୁ;
    ଯଦି (fgets(str, ଆକାର(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ଯେତେବେଳେ (file) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
	size_t len = strlen (file->filename);

	ଯେତେବେଳେ (fgets(str, ଆକାର(str), fp) &&
	       (p = strstr(str, "0:File:")) == ଖାଲି) {}
        ଯଦି ((p = strstr(str, "0:File:")) == ଖାଲି ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    ଭାଙ୍ଗ;
	ପାଇଁ (i = 0; i < file->n_func; i++) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;
	    tcov_function *func = &file->func[i];
	    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା next_zero = 0;
	    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା curline = 0;

	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି; j++) {
		tcov_ଧାଡ଼ି *ଧାଡ଼ି = &func->ଧାଡ଼ି[j];
	        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା fline = ଧାଡ଼ି->fline;
	        unsigned long long ଗଣନା_3;
		unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା tmp;
		ଅକ୍ଷର c;

		ଯେତେବେଳେ (curline < fline &&
		       fgets(str, ଆକାର(str), fp))
		    ଯଦି ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ଯଦି (sscanf (str, "%llu%c\n", &ଗଣନା_3, &c) == 2) {
		    ଯଦି (next_zero == 0)
		        ଧାଡ଼ି->ଗଣନା_3 += ଗଣନା_3;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
ଶୂନ୍ୟ __store_test_coverage (unsigned ଅକ୍ଷର * p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା files;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା funcs;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା blocks;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା blocks_run;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା runs;
    ଅକ୍ଷର *cov_filename = (ଅକ୍ଷର *)p + get_ମୂଲ୍ୟ (p, 4);
    FILE *fp;
    ଅକ୍ଷର *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ଯଦି (fp == ଖାଲି) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ଫେରନ୍ତୁ;
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
    ଯେତେବେଳେ (nfile) {
	files++;
	ପାଇଁ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି; j++) {
		blocks++;
		blocks_run += func->ଧାଡ଼ି[j].ଗଣନା_3 != 0;
	    }
	}
	nfile = nfile->next;
    }
    ଯଦି (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ଦ୍ୱିଗୁଣ) blocks_run / blocks);
    nfile = file;
    ଯେତେବେଳେ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା curline = 1;
	ଅକ୍ଷର str[10000];

        ଯଦି (src == ଖାଲି)
	     ଯାଅ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	ପାଇଁ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି; j++) {
		blocks++;
		blocks_run += func->ଧାଡ଼ି[j].ଗଣନା_3 != 0;
	    }
	}
	ଯଦି (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ଦ୍ୱିଗୁଣ) blocks_run / blocks);
        ପାଇଁ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ଯେତେବେଳେ (curline < func->first_ଧାଡ଼ି &&
		   fgets(str, ଆକାର(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି; j++) {
		blocks++;
		blocks_run += func->ଧାଡ଼ି[j].ଗଣନା_3 != 0;
	    }
	    ଯଦି (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ଦ୍ୱିଗୁଣ) blocks_run / blocks);
#ଯଦି 0
	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି; j++) {
	        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା fline = func->ଧାଡ଼ି[j].fline;
	        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା lline = func->ଧାଡ଼ି[j].lline;
		unsigned long long ଗଣନା_3 = func->ଧାଡ଼ି[j].ଗଣନା_3;

		fprintf (fp, "%u %u %llu\n", fline, lline, ଗଣନା_3);
	    }
#endif
	    ପାଇଁ (j = 0; j < func->n_ଧାଡ଼ି;) {
	        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା fline = func->ଧାଡ଼ି[j].fline;
	        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା lline = func->ଧାଡ଼ି[j].lline;
	        unsigned long long ଗଣନା_3 = func->ଧାଡ଼ି[j].ଗଣନା_3;
		unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା has_zero = 0;
		unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା same_ଧାଡ଼ି = fline == lline;

		j++;
		ଯେତେବେଳେ (j < func->n_ଧାଡ଼ି) {
	            unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା nfline = func->ଧାଡ଼ି[j].fline;
	            unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା nlline = func->ଧାଡ଼ି[j].lline;
	            unsigned long long ncount = func->ଧାଡ଼ି[j].ଗଣନା_3;

		    ଯଦି (fline == nfline) {
			ଯଦି (ncount == 0)
			    has_zero = 1;
			ଅନ୍ୟଥା ଯଦି (ncount > ଗଣନା_3)
			    ଗଣନା_3 =  ncount;
			same_ଧାଡ଼ି = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ଅନ୍ୟଥା
			ଭାଙ୍ଗ;
		}
		ଯଦି (same_ଧାଡ଼ି)
		     lline++;

	        ଯେତେବେଳେ (curline < fline &&
		       fgets(str, ଆକାର(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ଯେତେବେଳେ (curline < lline &&
		       fgets(str, ଆକାର(str), src)) {
		    ଯଦି (ଗଣନା_3 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ଅନ୍ୟଥା ଯଦି (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ଗଣନା_3, curline, str);
		    ଅନ୍ୟଥା
		        fprintf (fp, "%9llu:%5u:%s",
				 ଗଣନା_3, curline, str);
		    curline++;
		}
	    }
	}
	ଯେତେବେଳେ (fgets(str, ଆକାର(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    ଯେତେବେଳେ (file) {
        ପାଇଁ (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    ମୁକ୍ତ (func->ଧାଡ଼ି);
        }
	ମୁକ୍ତ (file->func);
	nfile = file;
	file = file->next;
	ମୁକ୍ତ (nfile);
    }
    fclose (fp);
}
