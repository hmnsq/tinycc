#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <fcntl.h>
#ifndef _WIN32
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <errno.h>
#अन्यथा
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

प्रकारनिर्देश संरचना tcov_ओळ {
    unsigned पूर्णाङ्क fline;
    unsigned पूर्णाङ्क lline;
    unsigned long long मोजणी_2;
} tcov_ओळ;

प्रकारनिर्देश संरचना tcov_function {
    वर्ण *function;
    unsigned पूर्णाङ्क first_ओळ;
    unsigned पूर्णाङ्क n_ओळ;
    unsigned पूर्णाङ्क m_ओळ;
    tcov_ओळ *ओळ;
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
    यदि (fd < 0)
	प्रत्यागम रिक्त;
  
#ifndef _WIN32
    यावत् (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        अनुवर्त;
#अन्यथा
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    प्रत्यागम fdopen (fd, "r+");
}

स्थिर unsigned long long get_मूल्य(unsigned वर्ण *p, पूर्णाङ्क size)
{
    unsigned long long मूल्य = 0;

    p += size;
    यावत् (size--)
 	मूल्य = (मूल्य << 8) | *--p;
    प्रत्यागम मूल्य;
}

स्थिर पूर्णाङ्क sort_func (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_function *pp = (ध्रुव tcov_function *) p;
    ध्रुव tcov_function *pq = (ध्रुव tcov_function *) q;

    प्रत्यागम pp->first_ओळ > pq->first_ओळ ? 1 :
	   pp->first_ओळ < pq->first_ओळ ? -1 : 0;
}

स्थिर पूर्णाङ्क sort_ओळ (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_ओळ *pp = (ध्रुव tcov_ओळ *) p;
    ध्रुव tcov_ओळ *pq = (ध्रुव tcov_ओळ *) q;

    प्रत्यागम pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->मोजणी_2 < pq->मोजणी_2 ? 1 :
	   pp->मोजणी_2 > pq->मोजणी_2 ? -1 : 0;
}

/* sort to let inline functions work */
स्थिर tcov_file *sort_test_coverage (unsigned वर्ण *p)
{
    पूर्णाङ्क i, j, k;
    unsigned वर्ण *start = p;
    tcov_file *file = रिक्त;
    tcov_file *nfile;

    p += 4;
    यावत् (*p) {
        वर्ण *filename = (वर्ण *)p;
	size_t len = strlen (filename);

	nfile = file;
	यावत् (nfile) {
	    यदि (strcmp (nfile->filename, filename) == 0)
		भङ्ग;
	    nfile = nfile->next;
	}
	यदि (nfile == रिक्त) {
	    nfile = malloc (परिमाण(tcov_file));
	    यदि (nfile == रिक्त) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        प्रत्यागम file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = रिक्त;
	    nfile->next = रिक्त;
	    यदि (file == रिक्त)
	        file = nfile;
	    अन्यथा {
		tcov_file *lfile = file;

	        यावत् (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	यावत् (*p) {
	    पूर्णाङ्क i;
	    वर्ण *function = (वर्ण *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    प्रति (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		यदि (strcmp (func->function, function) == 0)
		    भङ्ग;
	    }
	    यदि (i == nfile->n_func) {
	        यदि (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   परिमाण (tcov_function));
		    यदि (nfile->func == रिक्त) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        प्रत्यागम file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_ओळ = get_मूल्य (p, 8);
	        func->n_ओळ = 0;
	        func->m_ओळ = 0;
	        func->ओळ = रिक्त;
	    }
	    p += 8;
	    यावत् (*p) {
		tcov_ओळ *ओळ;
		unsigned long long val;

		यदि (func->n_ओळ >= func->m_ओळ) {
		    func->m_ओळ = func->m_ओळ == 0 ? 4 : func->m_ओळ * 2;
		    func->ओळ = realloc (func->ओळ,
					  func->m_ओळ * परिमाण (tcov_ओळ));
		    यदि (func->ओळ == रिक्त) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        प्रत्यागम file;
		    }
		}
		ओळ = &func->ओळ[func->n_ओळ++];
		val = get_मूल्य (p, 8);
	        ओळ->fline = (val >> 8) & 0xfffffffULL;
	        ओळ->lline = val >> 36;
	        ओळ->मोजणी_2 = get_मूल्य (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    यावत् (nfile) {
	qsort (nfile->func, nfile->n_func, परिमाण (tcov_function), sort_func);
	प्रति (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->ओळ, func->n_ओळ, परिमाण (tcov_ओळ), sort_ओळ);
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
    यदि (fp == रिक्त)
        प्रत्यागम;
    यदि (fgets(str, परिमाण(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    यावत् (file) {
	पूर्णाङ्क i;
	size_t len = strlen (file->filename);

	यावत् (fgets(str, परिमाण(str), fp) &&
	       (p = strstr(str, "0:File:")) == रिक्त) {}
        यदि ((p = strstr(str, "0:File:")) == रिक्त ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    भङ्ग;
	प्रति (i = 0; i < file->n_func; i++) {
	    पूर्णाङ्क j;
	    tcov_function *func = &file->func[i];
	    unsigned पूर्णाङ्क next_zero = 0;
	    unsigned पूर्णाङ्क curline = 0;

	    प्रति (j = 0; j < func->n_ओळ; j++) {
		tcov_ओळ *ओळ = &func->ओळ[j];
	        unsigned पूर्णाङ्क fline = ओळ->fline;
	        unsigned long long मोजणी_2;
		unsigned पूर्णाङ्क tmp;
		वर्ण c;

		यावत् (curline < fline &&
		       fgets(str, परिमाण(str), fp))
		    यदि ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		यदि (sscanf (str, "%llu%c\n", &मोजणी_2, &c) == 2) {
		    यदि (next_zero == 0)
		        ओळ->मोजणी_2 += मोजणी_2;
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
    वर्ण *cov_filename = (वर्ण *)p + get_मूल्य (p, 4);
    FILE *fp;
    वर्ण *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    यदि (fp == रिक्त) {
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
    यावत् (nfile) {
	files++;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    यदि (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
    nfile = file;
    यावत् (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned पूर्णाङ्क curline = 1;
	वर्ण str[10000];

        यदि (src == रिक्त)
	     गच्छ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	}
	यदि (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
        प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    यावत् (curline < func->first_ओळ &&
		   fgets(str, परिमाण(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    प्रति (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	    यदि (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुण) blocks_run / blocks);
#यदि 0
	    प्रति (j = 0; j < func->n_ओळ; j++) {
	        unsigned पूर्णाङ्क fline = func->ओळ[j].fline;
	        unsigned पूर्णाङ्क lline = func->ओळ[j].lline;
		unsigned long long मोजणी_2 = func->ओळ[j].मोजणी_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, मोजणी_2);
	    }
#endif
	    प्रति (j = 0; j < func->n_ओळ;) {
	        unsigned पूर्णाङ्क fline = func->ओळ[j].fline;
	        unsigned पूर्णाङ्क lline = func->ओळ[j].lline;
	        unsigned long long मोजणी_2 = func->ओळ[j].मोजणी_2;
		unsigned पूर्णाङ्क has_zero = 0;
		unsigned पूर्णाङ्क same_ओळ = fline == lline;

		j++;
		यावत् (j < func->n_ओळ) {
	            unsigned पूर्णाङ्क nfline = func->ओळ[j].fline;
	            unsigned पूर्णाङ्क nlline = func->ओळ[j].lline;
	            unsigned long long ncount = func->ओळ[j].मोजणी_2;

		    यदि (fline == nfline) {
			यदि (ncount == 0)
			    has_zero = 1;
			अन्यथा यदि (ncount > मोजणी_2)
			    मोजणी_2 =  ncount;
			same_ओळ = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अन्यथा
			भङ्ग;
		}
		यदि (same_ओळ)
		     lline++;

	        यावत् (curline < fline &&
		       fgets(str, परिमाण(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		यावत् (curline < lline &&
		       fgets(str, परिमाण(str), src)) {
		    यदि (मोजणी_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    अन्यथा यदि (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 मोजणी_2, curline, str);
		    अन्यथा
		        fprintf (fp, "%9llu:%5u:%s",
				 मोजणी_2, curline, str);
		    curline++;
		}
	    }
	}
	यावत् (fgets(str, परिमाण(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    यावत् (file) {
        प्रति (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->ओळ);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->next;
	मुक्त (nfile);
    }
    fclose (fp);
}
