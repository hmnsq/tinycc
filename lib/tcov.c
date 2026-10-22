#شامل <stdio.h>
#شامل <string.h>
#شامل <stdlib.h>
#شامل <fcntl.h>
#ifndef _WIN32
#شامل <unistd.h>
#شامل <errno.h>
#وگرنه
#شامل <windows.h>
#شامل <io.h>
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

تعریفنوع ساختار tcov_سطر {
    unsigned صحیح fline;
    unsigned صحیح lline;
    unsigned long long شمار_2;
} tcov_سطر;

تعریفنوع ساختار tcov_function {
    نویسه *function;
    unsigned صحیح first_سطر;
    unsigned صحیح n_سطر;
    unsigned صحیح m_سطر;
    tcov_سطر *سطر;
} tcov_function;

تعریفنوع ساختار tcov_file {
    نویسه *filename;
    unsigned صحیح n_func;
    unsigned صحیح m_func;
    tcov_function *func;
    ساختار tcov_file *next;
} tcov_file;

ایستا FILE *open_tcov_file (نویسه *cov_filename)
{
    صحیح fd;
#ifndef _WIN32
    ساختار flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    اگر (fd < 0)
	بازگشت پوچ;
  
#ifndef _WIN32
    وقتی (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        ادامه;
#وگرنه
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    بازگشت fdopen (fd, "r+");
}

ایستا unsigned long long get_مقدار(unsigned نویسه *p, صحیح size)
{
    unsigned long long مقدار = 0;

    p += size;
    وقتی (size--)
 	مقدار = (مقدار << 8) | *--p;
    بازگشت مقدار;
}

ایستا صحیح sort_func (ثابت تهی *p, ثابت تهی *q)
{
    ثابت tcov_function *pp = (ثابت tcov_function *) p;
    ثابت tcov_function *pq = (ثابت tcov_function *) q;

    بازگشت pp->first_سطر > pq->first_سطر ? 1 :
	   pp->first_سطر < pq->first_سطر ? -1 : 0;
}

ایستا صحیح sort_سطر (ثابت تهی *p, ثابت تهی *q)
{
    ثابت tcov_سطر *pp = (ثابت tcov_سطر *) p;
    ثابت tcov_سطر *pq = (ثابت tcov_سطر *) q;

    بازگشت pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->شمار_2 < pq->شمار_2 ? 1 :
	   pp->شمار_2 > pq->شمار_2 ? -1 : 0;
}

/* sort to let inline functions work */
ایستا tcov_file *sort_test_coverage (unsigned نویسه *p)
{
    صحیح i, j, k;
    unsigned نویسه *start = p;
    tcov_file *file = پوچ;
    tcov_file *nfile;

    p += 4;
    وقتی (*p) {
        نویسه *filename = (نویسه *)p;
	size_t len = strlen (filename);

	nfile = file;
	وقتی (nfile) {
	    اگر (strcmp (nfile->filename, filename) == 0)
		بشکن;
	    nfile = nfile->next;
	}
	اگر (nfile == پوچ) {
	    nfile = malloc (اندازه(tcov_file));
	    اگر (nfile == پوچ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        بازگشت file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = پوچ;
	    nfile->next = پوچ;
	    اگر (file == پوچ)
	        file = nfile;
	    وگرنه {
		tcov_file *lfile = file;

	        وقتی (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	وقتی (*p) {
	    صحیح i;
	    نویسه *function = (نویسه *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    برای (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		اگر (strcmp (func->function, function) == 0)
		    بشکن;
	    }
	    اگر (i == nfile->n_func) {
	        اگر (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   اندازه (tcov_function));
		    اگر (nfile->func == پوچ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        بازگشت file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_سطر = get_مقدار (p, 8);
	        func->n_سطر = 0;
	        func->m_سطر = 0;
	        func->سطر = پوچ;
	    }
	    p += 8;
	    وقتی (*p) {
		tcov_سطر *سطر;
		unsigned long long val;

		اگر (func->n_سطر >= func->m_سطر) {
		    func->m_سطر = func->m_سطر == 0 ? 4 : func->m_سطر * 2;
		    func->سطر = realloc (func->سطر,
					  func->m_سطر * اندازه (tcov_سطر));
		    اگر (func->سطر == پوچ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        بازگشت file;
		    }
		}
		سطر = &func->سطر[func->n_سطر++];
		val = get_مقدار (p, 8);
	        سطر->fline = (val >> 8) & 0xfffffffULL;
	        سطر->lline = val >> 36;
	        سطر->شمار_2 = get_مقدار (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    وقتی (nfile) {
	qsort (nfile->func, nfile->n_func, اندازه (tcov_function), sort_func);
	برای (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->سطر, func->n_سطر, اندازه (tcov_سطر), sort_سطر);
        }
	nfile = nfile->next;
    }
    بازگشت file;
}

/* merge with previous tcov file */
ایستا تهی merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned صحیح *pruns)
{
    unsigned صحیح runs;
    نویسه *p;
    نویسه str[10000];
    
    *pruns = 1;
    اگر (fp == پوچ)
        بازگشت;
    اگر (fgets(str, اندازه(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    وقتی (file) {
	صحیح i;
	size_t len = strlen (file->filename);

	وقتی (fgets(str, اندازه(str), fp) &&
	       (p = strstr(str, "0:File:")) == پوچ) {}
        اگر ((p = strstr(str, "0:File:")) == پوچ ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    بشکن;
	برای (i = 0; i < file->n_func; i++) {
	    صحیح j;
	    tcov_function *func = &file->func[i];
	    unsigned صحیح next_zero = 0;
	    unsigned صحیح curline = 0;

	    برای (j = 0; j < func->n_سطر; j++) {
		tcov_سطر *سطر = &func->سطر[j];
	        unsigned صحیح fline = سطر->fline;
	        unsigned long long شمار_2;
		unsigned صحیح tmp;
		نویسه c;

		وقتی (curline < fline &&
		       fgets(str, اندازه(str), fp))
		    اگر ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		اگر (sscanf (str, "%llu%c\n", &شمار_2, &c) == 2) {
		    اگر (next_zero == 0)
		        سطر->شمار_2 += شمار_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
تهی __store_test_coverage (unsigned نویسه * p)
{
    صحیح i, j;
    unsigned صحیح files;
    unsigned صحیح funcs;
    unsigned صحیح blocks;
    unsigned صحیح blocks_run;
    unsigned صحیح runs;
    نویسه *cov_filename = (نویسه *)p + get_مقدار (p, 4);
    FILE *fp;
    نویسه *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    اگر (fp == پوچ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	بازگشت;
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
    وقتی (nfile) {
	files++;
	برای (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    برای (j = 0; j < func->n_سطر; j++) {
		blocks++;
		blocks_run += func->سطر[j].شمار_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    اگر (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (دوگانه) blocks_run / blocks);
    nfile = file;
    وقتی (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned صحیح curline = 1;
	نویسه str[10000];

        اگر (src == پوچ)
	     برو next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	برای (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    برای (j = 0; j < func->n_سطر; j++) {
		blocks++;
		blocks_run += func->سطر[j].شمار_2 != 0;
	    }
	}
	اگر (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (دوگانه) blocks_run / blocks);
        برای (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    وقتی (curline < func->first_سطر &&
		   fgets(str, اندازه(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    برای (j = 0; j < func->n_سطر; j++) {
		blocks++;
		blocks_run += func->سطر[j].شمار_2 != 0;
	    }
	    اگر (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (دوگانه) blocks_run / blocks);
#اگر 0
	    برای (j = 0; j < func->n_سطر; j++) {
	        unsigned صحیح fline = func->سطر[j].fline;
	        unsigned صحیح lline = func->سطر[j].lline;
		unsigned long long شمار_2 = func->سطر[j].شمار_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, شمار_2);
	    }
#endif
	    برای (j = 0; j < func->n_سطر;) {
	        unsigned صحیح fline = func->سطر[j].fline;
	        unsigned صحیح lline = func->سطر[j].lline;
	        unsigned long long شمار_2 = func->سطر[j].شمار_2;
		unsigned صحیح has_zero = 0;
		unsigned صحیح same_سطر = fline == lline;

		j++;
		وقتی (j < func->n_سطر) {
	            unsigned صحیح nfline = func->سطر[j].fline;
	            unsigned صحیح nlline = func->سطر[j].lline;
	            unsigned long long ncount = func->سطر[j].شمار_2;

		    اگر (fline == nfline) {
			اگر (ncount == 0)
			    has_zero = 1;
			وگرنه اگر (ncount > شمار_2)
			    شمار_2 =  ncount;
			same_سطر = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    وگرنه
			بشکن;
		}
		اگر (same_سطر)
		     lline++;

	        وقتی (curline < fline &&
		       fgets(str, اندازه(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		وقتی (curline < lline &&
		       fgets(str, اندازه(str), src)) {
		    اگر (شمار_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    وگرنه اگر (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 شمار_2, curline, str);
		    وگرنه
		        fprintf (fp, "%9llu:%5u:%s",
				 شمار_2, curline, str);
		    curline++;
		}
	    }
	}
	وقتی (fgets(str, اندازه(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    وقتی (file) {
        برای (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    آزاد (func->سطر);
        }
	آزاد (file->func);
	nfile = file;
	file = file->next;
	آزاد (nfile);
    }
    fclose (fp);
}
