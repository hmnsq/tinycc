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

प्रकारनिर्देश संरचना tcov_पङ्क्ति {
    अचिन्हित पूर्णाङ्क fline;
    अचिन्हित पूर्णाङ्क lline;
    अचिन्हित दीर्घ दीर्घ गन्ती_2;
} tcov_पङ्क्ति;

प्रकारनिर्देश संरचना tcov_function {
    वर्ण *function;
    अचिन्हित पूर्णाङ्क first_पङ्क्ति;
    अचिन्हित पूर्णाङ्क n_पङ्क्ति;
    अचिन्हित पूर्णाङ्क m_पङ्क्ति;
    tcov_पङ्क्ति *पङ्क्ति;
} tcov_function;

प्रकारनिर्देश संरचना tcov_file {
    वर्ण *filename;
    अचिन्हित पूर्णाङ्क n_func;
    अचिन्हित पूर्णाङ्क m_func;
    tcov_function *func;
    संरचना tcov_file *next;
} tcov_file;

स्थिर खाता *open_tcov_file (वर्ण *cov_filename)
{
    पूर्णाङ्क fd;
#ifndef _WIN32
    संरचना flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = शुरू_से;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = खोलो (cov_filename, O_RDWR | O_CREAT, 0666);
    यदि (fd < 0)
	फर्काऊ रिक्त;
  
#ifndef _WIN32
    जबसम्म (fcntl (fd, F_SETLKW, &lock) && त्रुटि_सं == EINTR)
        जारी;
#अन्यथा
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    फर्काऊ fdopen (fd, "r+");
}

स्थिर अचिन्हित दीर्घ दीर्घ get_मान(अचिन्हित वर्ण *p, पूर्णाङ्क size)
{
    अचिन्हित दीर्घ दीर्घ मान = 0;

    p += size;
    जबसम्म (size--)
 	मान = (मान << 8) | *--p;
    फर्काऊ मान;
}

स्थिर पूर्णाङ्क sort_func (अचर शून्य *p, अचर शून्य *q)
{
    अचर tcov_function *pp = (अचर tcov_function *) p;
    अचर tcov_function *pq = (अचर tcov_function *) q;

    फर्काऊ pp->first_पङ्क्ति > pq->first_पङ्क्ति ? 1 :
	   pp->first_पङ्क्ति < pq->first_पङ्क्ति ? -1 : 0;
}

स्थिर पूर्णाङ्क sort_पङ्क्ति (अचर शून्य *p, अचर शून्य *q)
{
    अचर tcov_पङ्क्ति *pp = (अचर tcov_पङ्क्ति *) p;
    अचर tcov_पङ्क्ति *pq = (अचर tcov_पङ्क्ति *) q;

    फर्काऊ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->गन्ती_2 < pq->गन्ती_2 ? 1 :
	   pp->गन्ती_2 > pq->गन्ती_2 ? -1 : 0;
}

/* sort to let inline functions work */
स्थिर tcov_file *sort_test_coverage (अचिन्हित वर्ण *p)
{
    पूर्णाङ्क i, j, k;
    अचिन्हित वर्ण *start = p;
    tcov_file *file = रिक्त;
    tcov_file *nfile;

    p += 4;
    जबसम्म (*p) {
        वर्ण *filename = (वर्ण *)p;
	माप_प्रकार len = म_माप (filename);

	nfile = file;
	जबसम्म (nfile) {
	    यदि (म_भेद (nfile->filename, filename) == 0)
		रोक;
	    nfile = nfile->next;
	}
	यदि (nfile == रिक्त) {
	    nfile = दो_स्मृति (परिमाण(tcov_file));
	    यदि (nfile == रिक्त) {
	        ख_लिखो (मानक_त्रुटि, "Malloc error test_coverage\n");
	        फर्काऊ file;
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

	        जबसम्म (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	जबसम्म (*p) {
	    पूर्णाङ्क i;
	    वर्ण *function = (वर्ण *)p;
	    tcov_function *func;

	    p += म_माप (function) + 1;
	    p += -(p - start) & 7;
	    लागि (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		यदि (म_भेद (func->function, function) == 0)
		    रोक;
	    }
	    यदि (i == nfile->n_func) {
	        यदि (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = पुनः_स्मृति (nfile->func,
					   nfile->m_func *
					   परिमाण (tcov_function));
		    यदि (nfile->func == रिक्त) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        फर्काऊ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_पङ्क्ति = get_मान (p, 8);
	        func->n_पङ्क्ति = 0;
	        func->m_पङ्क्ति = 0;
	        func->पङ्क्ति = रिक्त;
	    }
	    p += 8;
	    जबसम्म (*p) {
		tcov_पङ्क्ति *पङ्क्ति;
		अचिन्हित दीर्घ दीर्घ val;

		यदि (func->n_पङ्क्ति >= func->m_पङ्क्ति) {
		    func->m_पङ्क्ति = func->m_पङ्क्ति == 0 ? 4 : func->m_पङ्क्ति * 2;
		    func->पङ्क्ति = पुनः_स्मृति (func->पङ्क्ति,
					  func->m_पङ्क्ति * परिमाण (tcov_पङ्क्ति));
		    यदि (func->पङ्क्ति == रिक्त) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        फर्काऊ file;
		    }
		}
		पङ्क्ति = &func->पङ्क्ति[func->n_पङ्क्ति++];
		val = get_मान (p, 8);
	        पङ्क्ति->fline = (val >> 8) & 0xfffffffULL;
	        पङ्क्ति->lline = val >> 36;
	        पङ्क्ति->गन्ती_2 = get_मान (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    जबसम्म (nfile) {
	क्विक (nfile->func, nfile->n_func, परिमाण (tcov_function), sort_func);
	लागि (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    क्विक (func->पङ्क्ति, func->n_पङ्क्ति, परिमाण (tcov_पङ्क्ति), sort_पङ्क्ति);
        }
	nfile = nfile->next;
    }
    फर्काऊ file;
}

/* merge with previous tcov file */
स्थिर शून्य merge_test_coverage (tcov_file *file, खाता *fp,
				 अचिन्हित पूर्णाङ्क *pruns)
{
    अचिन्हित पूर्णाङ्क runs;
    वर्ण *p;
    वर्ण str[10000];
    
    *pruns = 1;
    यदि (fp == रिक्त)
        फर्काऊ;
    यदि (ख_माला_लो(str, परिमाण(str), fp) &&
        (p = म_खोजप (str, ':')) &&
        (माला_पूछो (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    जबसम्म (file) {
	पूर्णाङ्क i;
	माप_प्रकार len = म_माप (file->filename);

	जबसम्म (ख_माला_लो(str, परिमाण(str), fp) &&
	       (p = म_माला(str, "0:File:")) == रिक्त) {}
        यदि ((p = म_माला(str, "0:File:")) == रिक्त ||
	    म_भेदन (p + म_माप("0:File:"), file->filename, len) != 0 ||
	    p[म_माप("0:File:") + len] != ' ')
	    रोक;
	लागि (i = 0; i < file->n_func; i++) {
	    पूर्णाङ्क j;
	    tcov_function *func = &file->func[i];
	    अचिन्हित पूर्णाङ्क next_zero = 0;
	    अचिन्हित पूर्णाङ्क curline = 0;

	    लागि (j = 0; j < func->n_पङ्क्ति; j++) {
		tcov_पङ्क्ति *पङ्क्ति = &func->पङ्क्ति[j];
	        अचिन्हित पूर्णाङ्क fline = पङ्क्ति->fline;
	        अचिन्हित दीर्घ दीर्घ गन्ती_2;
		अचिन्हित पूर्णाङ्क tmp;
		वर्ण c;

		जबसम्म (curline < fline &&
		       ख_माला_लो(str, परिमाण(str), fp))
		    यदि ((p = म_अक्षर(str, ':')) &&
			माला_पूछो (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		यदि (माला_पूछो (str, "%llu%c\n", &गन्ती_2, &c) == 2) {
		    यदि (next_zero == 0)
		        पङ्क्ति->गन्ती_2 += गन्ती_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
शून्य __store_test_coverage (अचिन्हित वर्ण * p)
{
    पूर्णाङ्क i, j;
    अचिन्हित पूर्णाङ्क files;
    अचिन्हित पूर्णाङ्क funcs;
    अचिन्हित पूर्णाङ्क blocks;
    अचिन्हित पूर्णाङ्क blocks_run;
    अचिन्हित पूर्णाङ्क runs;
    वर्ण *cov_filename = (वर्ण *)p + get_मान (p, 4);
    खाता *fp;
    वर्ण *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    यदि (fp == रिक्त) {
	ख_लिखो (मानक_त्रुटि, "Cannot create coverage file: %s\n", cov_filename);
	फर्काऊ;
    }
    file = sort_test_coverage (p);
    merge_test_coverage (file, fp, &runs);
    ख_जाओ (fp, 0, शुरू_से);
    ख_लिखो (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    blocks = 0;
    blocks_run = 0;
    nfile = file;
    जबसम्म (nfile) {
	files++;
	लागि (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    लागि (j = 0; j < func->n_पङ्क्ति; j++) {
		blocks++;
		blocks_run += func->पङ्क्ति[j].गन्ती_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    यदि (blocks == 0)
	blocks = 1;
    ख_लिखो (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
    nfile = file;
    जबसम्म (nfile) {
	खाता *src = ख_खोलो (nfile->filename, "r");
	अचिन्हित पूर्णाङ्क curline = 1;
	वर्ण str[10000];

        यदि (src == रिक्त)
	     गच्छ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	लागि (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    लागि (j = 0; j < func->n_पङ्क्ति; j++) {
		blocks++;
		blocks_run += func->पङ्क्ति[j].गन्ती_2 != 0;
	    }
	}
	यदि (blocks == 0)
	    blocks = 1;
        ख_लिखो (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
        लागि (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    जबसम्म (curline < func->first_पङ्क्ति &&
		   ख_माला_लो(str, परिमाण(str), src))
		ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    लागि (j = 0; j < func->n_पङ्क्ति; j++) {
		blocks++;
		blocks_run += func->पङ्क्ति[j].गन्ती_2 != 0;
	    }
	    यदि (blocks == 0)
		blocks = 1;
            ख_लिखो (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुण) blocks_run / blocks);
#यदि 0
	    लागि (j = 0; j < func->n_पङ्क्ति; j++) {
	        अचिन्हित पूर्णाङ्क fline = func->पङ्क्ति[j].fline;
	        अचिन्हित पूर्णाङ्क lline = func->पङ्क्ति[j].lline;
		अचिन्हित दीर्घ दीर्घ गन्ती_2 = func->पङ्क्ति[j].गन्ती_2;

		ख_लिखो (fp, "%u %u %llu\n", fline, lline, गन्ती_2);
	    }
#endif
	    लागि (j = 0; j < func->n_पङ्क्ति;) {
	        अचिन्हित पूर्णाङ्क fline = func->पङ्क्ति[j].fline;
	        अचिन्हित पूर्णाङ्क lline = func->पङ्क्ति[j].lline;
	        अचिन्हित दीर्घ दीर्घ गन्ती_2 = func->पङ्क्ति[j].गन्ती_2;
		अचिन्हित पूर्णाङ्क has_zero = 0;
		अचिन्हित पूर्णाङ्क same_पङ्क्ति = fline == lline;

		j++;
		जबसम्म (j < func->n_पङ्क्ति) {
	            अचिन्हित पूर्णाङ्क nfline = func->पङ्क्ति[j].fline;
	            अचिन्हित पूर्णाङ्क nlline = func->पङ्क्ति[j].lline;
	            अचिन्हित दीर्घ दीर्घ ncount = func->पङ्क्ति[j].गन्ती_2;

		    यदि (fline == nfline) {
			यदि (ncount == 0)
			    has_zero = 1;
			अन्यथा यदि (ncount > गन्ती_2)
			    गन्ती_2 =  ncount;
			same_पङ्क्ति = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अन्यथा
			रोक;
		}
		यदि (same_पङ्क्ति)
		     lline++;

	        जबसम्म (curline < fline &&
		       ख_माला_लो(str, परिमाण(str), src))
		     ख_लिखो (fp, "        -:%5u:%s", curline++, str);
		जबसम्म (curline < lline &&
		       ख_माला_लो(str, परिमाण(str), src)) {
		    यदि (गन्ती_2 == 0)
		        ख_लिखो (fp, "    #####:%5u:%s",
				 curline, str);
		    अन्यथा यदि (has_zero)
		        ख_लिखो (fp, "%8llu*:%5u:%s", 
				 गन्ती_2, curline, str);
		    अन्यथा
		        ख_लिखो (fp, "%9llu:%5u:%s",
				 गन्ती_2, curline, str);
		    curline++;
		}
	    }
	}
	जबसम्म (ख_माला_लो(str, परिमाण(str), src))
	    ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	ख_बंद (src);
next:
	nfile = nfile->next;
    }
    जबसम्म (file) {
        लागि (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->पङ्क्ति);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->next;
	मुक्त (nfile);
    }
    ख_बंद (fp);
}
