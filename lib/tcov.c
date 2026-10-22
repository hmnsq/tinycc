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

प्रकारव्याख्या संरचना tcov_ओळ {
    अचिन्हित पूर्णांक fline;
    अचिन्हित पूर्णांक lline;
    अचिन्हित दीर्घ दीर्घ मोजणी_2;
} tcov_ओळ;

प्रकारव्याख्या संरचना tcov_function {
    अक्षर *function;
    अचिन्हित पूर्णांक first_ओळ;
    अचिन्हित पूर्णांक n_ओळ;
    अचिन्हित पूर्णांक m_ओळ;
    tcov_ओळ *ओळ;
} tcov_function;

प्रकारव्याख्या संरचना tcov_file {
    अक्षर *filename;
    अचिन्हित पूर्णांक n_func;
    अचिन्हित पूर्णांक m_func;
    tcov_function *func;
    संरचना tcov_file *next;
} tcov_file;

स्थिर खाता *open_tcov_file (अक्षर *cov_filename)
{
    पूर्णांक fd;
#ifndef _WIN32
    संरचना flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = शुरू_से;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = खोलो (cov_filename, O_RDWR | O_CREAT, 0666);
    जर (fd < 0)
	परत रिक्त;
  
#ifndef _WIN32
    पर्यंत (fcntl (fd, F_SETLKW, &lock) && त्रुटि_सं == EINTR)
        सुरूठेवा;
#अन्यथा
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    परत fdopen (fd, "r+");
}

स्थिर अचिन्हित दीर्घ दीर्घ get_मूल्य(अचिन्हित अक्षर *p, पूर्णांक size)
{
    अचिन्हित दीर्घ दीर्घ मूल्य = 0;

    p += size;
    पर्यंत (size--)
 	मूल्य = (मूल्य << 8) | *--p;
    परत मूल्य;
}

स्थिर पूर्णांक sort_func (स्थिरांक शून्य *p, स्थिरांक शून्य *q)
{
    स्थिरांक tcov_function *pp = (स्थिरांक tcov_function *) p;
    स्थिरांक tcov_function *pq = (स्थिरांक tcov_function *) q;

    परत pp->first_ओळ > pq->first_ओळ ? 1 :
	   pp->first_ओळ < pq->first_ओळ ? -1 : 0;
}

स्थिर पूर्णांक sort_ओळ (स्थिरांक शून्य *p, स्थिरांक शून्य *q)
{
    स्थिरांक tcov_ओळ *pp = (स्थिरांक tcov_ओळ *) p;
    स्थिरांक tcov_ओळ *pq = (स्थिरांक tcov_ओळ *) q;

    परत pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->मोजणी_2 < pq->मोजणी_2 ? 1 :
	   pp->मोजणी_2 > pq->मोजणी_2 ? -1 : 0;
}

/* sort to let inline functions work */
स्थिर tcov_file *sort_test_coverage (अचिन्हित अक्षर *p)
{
    पूर्णांक i, j, k;
    अचिन्हित अक्षर *start = p;
    tcov_file *file = रिक्त;
    tcov_file *nfile;

    p += 4;
    पर्यंत (*p) {
        अक्षर *filename = (अक्षर *)p;
	माप_प्रकार len = म_माप (filename);

	nfile = file;
	पर्यंत (nfile) {
	    जर (म_भेद (nfile->filename, filename) == 0)
		थांबा;
	    nfile = nfile->next;
	}
	जर (nfile == रिक्त) {
	    nfile = दो_स्मृति (आकार(tcov_file));
	    जर (nfile == रिक्त) {
	        ख_लिखो (मानक_त्रुटि, "Malloc error test_coverage\n");
	        परत file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = रिक्त;
	    nfile->next = रिक्त;
	    जर (file == रिक्त)
	        file = nfile;
	    अन्यथा {
		tcov_file *lfile = file;

	        पर्यंत (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	पर्यंत (*p) {
	    पूर्णांक i;
	    अक्षर *function = (अक्षर *)p;
	    tcov_function *func;

	    p += म_माप (function) + 1;
	    p += -(p - start) & 7;
	    साठी (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		जर (म_भेद (func->function, function) == 0)
		    थांबा;
	    }
	    जर (i == nfile->n_func) {
	        जर (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = पुनः_स्मृति (nfile->func,
					   nfile->m_func *
					   आकार (tcov_function));
		    जर (nfile->func == रिक्त) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        परत file;
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
	    पर्यंत (*p) {
		tcov_ओळ *ओळ;
		अचिन्हित दीर्घ दीर्घ val;

		जर (func->n_ओळ >= func->m_ओळ) {
		    func->m_ओळ = func->m_ओळ == 0 ? 4 : func->m_ओळ * 2;
		    func->ओळ = पुनः_स्मृति (func->ओळ,
					  func->m_ओळ * आकार (tcov_ओळ));
		    जर (func->ओळ == रिक्त) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        परत file;
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
    पर्यंत (nfile) {
	क्विक (nfile->func, nfile->n_func, आकार (tcov_function), sort_func);
	साठी (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    क्विक (func->ओळ, func->n_ओळ, आकार (tcov_ओळ), sort_ओळ);
        }
	nfile = nfile->next;
    }
    परत file;
}

/* merge with previous tcov file */
स्थिर शून्य merge_test_coverage (tcov_file *file, खाता *fp,
				 अचिन्हित पूर्णांक *pruns)
{
    अचिन्हित पूर्णांक runs;
    अक्षर *p;
    अक्षर str[10000];
    
    *pruns = 1;
    जर (fp == रिक्त)
        परत;
    जर (ख_माला_लो(str, आकार(str), fp) &&
        (p = म_खोजप (str, ':')) &&
        (माला_पूछो (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    पर्यंत (file) {
	पूर्णांक i;
	माप_प्रकार len = म_माप (file->filename);

	पर्यंत (ख_माला_लो(str, आकार(str), fp) &&
	       (p = म_माला(str, "0:File:")) == रिक्त) {}
        जर ((p = म_माला(str, "0:File:")) == रिक्त ||
	    म_भेदन (p + म_माप("0:File:"), file->filename, len) != 0 ||
	    p[म_माप("0:File:") + len] != ' ')
	    थांबा;
	साठी (i = 0; i < file->n_func; i++) {
	    पूर्णांक j;
	    tcov_function *func = &file->func[i];
	    अचिन्हित पूर्णांक next_zero = 0;
	    अचिन्हित पूर्णांक curline = 0;

	    साठी (j = 0; j < func->n_ओळ; j++) {
		tcov_ओळ *ओळ = &func->ओळ[j];
	        अचिन्हित पूर्णांक fline = ओळ->fline;
	        अचिन्हित दीर्घ दीर्घ मोजणी_2;
		अचिन्हित पूर्णांक tmp;
		अक्षर c;

		पर्यंत (curline < fline &&
		       ख_माला_लो(str, आकार(str), fp))
		    जर ((p = म_अक्षर(str, ':')) &&
			माला_पूछो (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		जर (माला_पूछो (str, "%llu%c\n", &मोजणी_2, &c) == 2) {
		    जर (next_zero == 0)
		        ओळ->मोजणी_2 += मोजणी_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
शून्य __store_test_coverage (अचिन्हित अक्षर * p)
{
    पूर्णांक i, j;
    अचिन्हित पूर्णांक files;
    अचिन्हित पूर्णांक funcs;
    अचिन्हित पूर्णांक blocks;
    अचिन्हित पूर्णांक blocks_run;
    अचिन्हित पूर्णांक runs;
    अक्षर *cov_filename = (अक्षर *)p + get_मूल्य (p, 4);
    खाता *fp;
    अक्षर *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    जर (fp == रिक्त) {
	ख_लिखो (मानक_त्रुटि, "Cannot create coverage file: %s\n", cov_filename);
	परत;
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
    पर्यंत (nfile) {
	files++;
	साठी (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    साठी (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    जर (blocks == 0)
	blocks = 1;
    ख_लिखो (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
    nfile = file;
    पर्यंत (nfile) {
	खाता *src = ख_खोलो (nfile->filename, "r");
	अचिन्हित पूर्णांक curline = 1;
	अक्षर str[10000];

        जर (src == रिक्त)
	     जा next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	साठी (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    साठी (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	}
	जर (blocks == 0)
	    blocks = 1;
        ख_लिखो (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुण) blocks_run / blocks);
        साठी (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    पर्यंत (curline < func->first_ओळ &&
		   ख_माला_लो(str, आकार(str), src))
		ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    साठी (j = 0; j < func->n_ओळ; j++) {
		blocks++;
		blocks_run += func->ओळ[j].मोजणी_2 != 0;
	    }
	    जर (blocks == 0)
		blocks = 1;
            ख_लिखो (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुण) blocks_run / blocks);
#जर 0
	    साठी (j = 0; j < func->n_ओळ; j++) {
	        अचिन्हित पूर्णांक fline = func->ओळ[j].fline;
	        अचिन्हित पूर्णांक lline = func->ओळ[j].lline;
		अचिन्हित दीर्घ दीर्घ मोजणी_2 = func->ओळ[j].मोजणी_2;

		ख_लिखो (fp, "%u %u %llu\n", fline, lline, मोजणी_2);
	    }
#endif
	    साठी (j = 0; j < func->n_ओळ;) {
	        अचिन्हित पूर्णांक fline = func->ओळ[j].fline;
	        अचिन्हित पूर्णांक lline = func->ओळ[j].lline;
	        अचिन्हित दीर्घ दीर्घ मोजणी_2 = func->ओळ[j].मोजणी_2;
		अचिन्हित पूर्णांक has_zero = 0;
		अचिन्हित पूर्णांक same_ओळ = fline == lline;

		j++;
		पर्यंत (j < func->n_ओळ) {
	            अचिन्हित पूर्णांक nfline = func->ओळ[j].fline;
	            अचिन्हित पूर्णांक nlline = func->ओळ[j].lline;
	            अचिन्हित दीर्घ दीर्घ ncount = func->ओळ[j].मोजणी_2;

		    जर (fline == nfline) {
			जर (ncount == 0)
			    has_zero = 1;
			अन्यथा जर (ncount > मोजणी_2)
			    मोजणी_2 =  ncount;
			same_ओळ = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अन्यथा
			थांबा;
		}
		जर (same_ओळ)
		     lline++;

	        पर्यंत (curline < fline &&
		       ख_माला_लो(str, आकार(str), src))
		     ख_लिखो (fp, "        -:%5u:%s", curline++, str);
		पर्यंत (curline < lline &&
		       ख_माला_लो(str, आकार(str), src)) {
		    जर (मोजणी_2 == 0)
		        ख_लिखो (fp, "    #####:%5u:%s",
				 curline, str);
		    अन्यथा जर (has_zero)
		        ख_लिखो (fp, "%8llu*:%5u:%s", 
				 मोजणी_2, curline, str);
		    अन्यथा
		        ख_लिखो (fp, "%9llu:%5u:%s",
				 मोजणी_2, curline, str);
		    curline++;
		}
	    }
	}
	पर्यंत (ख_माला_लो(str, आकार(str), src))
	    ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	ख_बंद (src);
next:
	nfile = nfile->next;
    }
    पर्यंत (file) {
        साठी (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->ओळ);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->next;
	मुक्त (nfile);
    }
    ख_बंद (fp);
}
