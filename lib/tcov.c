#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <fcntl.h>
#ifndef _WIN32
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <errno.h>
#अण्णहा
#अन्तर्भाव <windows.h>
#अन्तर्भाव <io.h>
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

प्रकारनिर्देश संरचना tcov_पङ्क्तिः {
    unsigned पूर्णाङ्क fline;
    unsigned पूर्णाङ्क lline;
    unsigned long long गणनम्_2;
} tcov_पङ्क्तिः;

प्रकारनिर्देश संरचना tcov_function {
    वर्ण *function;
    unsigned पूर्णाङ्क first_पङ्क्तिः;
    unsigned पूर्णाङ्क n_पङ्क्तिः;
    unsigned पूर्णाङ्क m_पङ्क्तिः;
    tcov_पङ्क्तिः *पङ्क्तिः;
} tcov_function;

प्रकारनिर्देश संरचना tcov_file {
    वर्ण *filename;
    unsigned पूर्णाङ्क n_func;
    unsigned पूर्णाङ्क m_func;
    tcov_function *func;
    संरचना tcov_file *next;
} tcov_file;

स्थिर FILE *open_tcov_file (वर्ण *cov_filename)
{
    पूर्णाङ्क fd;
#ifndef _WIN32
    संरचना flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    जइ (fd < 0)
	प्रत्यागम रिक्त;
  
#ifndef _WIN32
    जाव (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        अनुवर्त;
#अण्णहा
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    प्रत्यागम fdopen (fd, "r+");
}

स्थिर unsigned long long get_मानम्(unsigned वर्ण *p, पूर्णाङ्क size)
{
    unsigned long long मानम् = 0;

    p += size;
    जाव (size--)
 	मानम् = (मानम् << 8) | *--p;
    प्रत्यागम मानम्;
}

स्थिर पूर्णाङ्क sort_func (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_function *pp = (ध्रुव tcov_function *) p;
    ध्रुव tcov_function *pq = (ध्रुव tcov_function *) q;

    प्रत्यागम pp->first_पङ्क्तिः > pq->first_पङ्क्तिः ? 1 :
	   pp->first_पङ्क्तिः < pq->first_पङ्क्तिः ? -1 : 0;
}

स्थिर पूर्णाङ्क sort_पङ्क्तिः (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_पङ्क्तिः *pp = (ध्रुव tcov_पङ्क्तिः *) p;
    ध्रुव tcov_पङ्क्तिः *pq = (ध्रुव tcov_पङ्क्तिः *) q;

    प्रत्यागम pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->गणनम्_2 < pq->गणनम्_2 ? 1 :
	   pp->गणनम्_2 > pq->गणनम्_2 ? -1 : 0;
}

/* sort to let inline functions work */
स्थिर tcov_file *sort_test_coverage (unsigned वर्ण *p)
{
    पूर्णाङ्क i, j, k;
    unsigned वर्ण *start = p;
    tcov_file *file = रिक्त;
    tcov_file *nfile;

    p += 4;
    जाव (*p) {
        वर्ण *filename = (वर्ण *)p;
	size_t len = strlen (filename);

	nfile = file;
	जाव (nfile) {
	    जइ (strcmp (nfile->filename, filename) == 0)
		भङ्ग;
	    nfile = nfile->next;
	}
	जइ (nfile == रिक्त) {
	    nfile = malloc (परिमाण(tcov_file));
	    जइ (nfile == रिक्त) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        प्रत्यागम file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = रिक्त;
	    nfile->next = रिक्त;
	    जइ (file == रिक्त)
	        file = nfile;
	    अण्णहा {
		tcov_file *lfile = file;

	        जाव (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	जाव (*p) {
	    पूर्णाङ्क i;
	    वर्ण *function = (वर्ण *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    प्रति (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		जइ (strcmp (func->function, function) == 0)
		    भङ्ग;
	    }
	    जइ (i == nfile->n_func) {
	        जइ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   परिमाण (tcov_function));
		    जइ (nfile->func == रिक्त) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        प्रत्यागम file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_पङ्क्तिः = get_मानम् (p, 8);
	        func->n_पङ्क्तिः = 0;
	        func->m_पङ्क्तिः = 0;
	        func->पङ्क्तिः = रिक्त;
	    }
	    p += 8;
	    जाव (*p) {
		tcov_पङ्क्तिः *पङ्क्तिः;
		unsigned long long val;

		जइ (func->n_पङ्क्तिः >= func->m_पङ्क्तिः) {
		    func->m_पङ्क्तिः = func->m_पङ्क्तिः == 0 ? 4 : func->m_पङ्क्तिः * 2;
		    func->पङ्क्तिः = realloc (func->पङ्क्तिः,
					  func->m_पङ्क्तिः * परिमाण (tcov_पङ्क्तिः));
		    जइ (func->पङ्क्तिः == रिक्त) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        प्रत्यागम file;
		    }
		}
		पङ्क्तिः = &func->पङ्क्तिः[func->n_पङ्क्तिः++];
		val = get_मानम् (p, 8);
	        पङ्क्तिः->fline = (val >> 8) & 0xfffffffULL;
	        पङ्क्तिः->lline = val >> 36;
	        पङ्क्तिः->गणनम्_2 = get_मानम् (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    जाव (nfile) {
	qsort (nfile->func, nfile->n_func, परिमाण (tcov_function), sort_func);
	प्रति (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->पङ्क्तिः, func->n_पङ्क्तिः, परिमाण (tcov_पङ्क्तिः), sort_पङ्क्तिः);
        }
	nfile = nfile->next;
    }
    प्रत्यागम file;
}

/* merge with previous tcov file */
स्थिर शून्य merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned पूर्णाङ्क *pruns)
{
    unsigned पूर्णाङ्क runs;
    वर्ण *p;
    वर्ण str[10000];
    
    *pruns = 1;
    जइ (fp == रिक्त)
        प्रत्यागम;
    जइ (fgets(str, परिमाण(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    जाव (file) {
	पूर्णाङ्क i;
	size_t len = strlen (file->filename);

	जाव (fgets(str, परिमाण(str), fp) &&
	       (p = strstr(str, "0:File:")) == रिक्त) {}
        जइ ((p = strstr(str, "0:File:")) == रिक्त ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    भङ्ग;
	प्रति (i = 0; i < file->n_func; i++) {
	    पूर्णाङ्क j;
	    tcov_function *func = &file->func[i];
	    unsigned पूर्णाङ्क next_zero = 0;
	    unsigned पूर्णाङ्क curline = 0;

	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		tcov_पङ्क्तिः *पङ्क्तिः = &func->पङ्क्तिः[j];
	        unsigned पूर्णाङ्क fline = पङ्क्तिः->fline;
	        unsigned long long गणनम्_2;
		unsigned पूर्णाङ्क tmp;
		वर्ण c;

		जाव (curline < fline &&
		       fgets(str, परिमाण(str), fp))
		    जइ ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		जइ (sscanf (str, "%llu%c\n", &गणनम्_2, &c) == 2) {
		    जइ (next_zero == 0)
		        पङ्क्तिः->गणनम्_2 += गणनम्_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
शून्य __store_test_coverage (unsigned वर्ण * p)
{
    पूर्णाङ्क i, j;
    unsigned पूर्णाङ्क files;
    unsigned पूर्णाङ्क funcs;
    unsigned पूर्णाङ्क blocks;
    unsigned पूर्णाङ्क blocks_run;
    unsigned पूर्णाङ्क runs;
    वर्ण *cov_filename = (वर्ण *)p + get_मानम् (p, 4);
    FILE *fp;
    वर्ण *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    जइ (fp == रिक्त) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	प्रत्यागम;
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
    जाव (nfile) {
	files++;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		blocks++;
		blocks_run += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    जइ (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
    nfile = file;
    जाव (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned पूर्णाङ्क curline = 1;
	वर्ण str[10000];

        जइ (src == रिक्त)
	     गच्छ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		blocks++;
		blocks_run += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	}
	जइ (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
        प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    जाव (curline < func->first_पङ्क्तिः &&
		   fgets(str, परिमाण(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		blocks++;
		blocks_run += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	    जइ (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुण) blocks_run / blocks);
#जइ 0
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
	        unsigned पूर्णाङ्क fline = func->पङ्क्तिः[j].fline;
	        unsigned पूर्णाङ्क lline = func->पङ्क्तिः[j].lline;
		unsigned long long गणनम्_2 = func->पङ्क्तिः[j].गणनम्_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, गणनम्_2);
	    }
#endif
	    प्रति (j = 0; j < func->n_पङ्क्तिः;) {
	        unsigned पूर्णाङ्क fline = func->पङ्क्तिः[j].fline;
	        unsigned पूर्णाङ्क lline = func->पङ्क्तिः[j].lline;
	        unsigned long long गणनम्_2 = func->पङ्क्तिः[j].गणनम्_2;
		unsigned पूर्णाङ्क has_zero = 0;
		unsigned पूर्णाङ्क same_पङ्क्तिः = fline == lline;

		j++;
		जाव (j < func->n_पङ्क्तिः) {
	            unsigned पूर्णाङ्क nfline = func->पङ्क्तिः[j].fline;
	            unsigned पूर्णाङ्क nlline = func->पङ्क्तिः[j].lline;
	            unsigned long long ncount = func->पङ्क्तिः[j].गणनम्_2;

		    जइ (fline == nfline) {
			जइ (ncount == 0)
			    has_zero = 1;
			अण्णहा जइ (ncount > गणनम्_2)
			    गणनम्_2 =  ncount;
			same_पङ्क्तिः = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अण्णहा
			भङ्ग;
		}
		जइ (same_पङ्क्तिः)
		     lline++;

	        जाव (curline < fline &&
		       fgets(str, परिमाण(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		जाव (curline < lline &&
		       fgets(str, परिमाण(str), src)) {
		    जइ (गणनम्_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    अण्णहा जइ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 गणनम्_2, curline, str);
		    अण्णहा
		        fprintf (fp, "%9llu:%5u:%s",
				 गणनम्_2, curline, str);
		    curline++;
		}
	    }
	}
	जाव (fgets(str, परिमाण(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    जाव (file) {
        प्रति (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->पङ्क्तिः);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->next;
	मुक्त (nfile);
    }
    fclose (fp);
}
