#समावेश <stdio.h>
#समावेश <string.h>
#समावेश <stdlib.h>
#समावेश <fcntl.h>
#अगर_अघोषित _WIN32
#समावेश <unistd.h>
#समावेश <errno.h>
#अन्यथा
#समावेश <windows.h>
#समावेश <io.h>
#पूर्ण_अगर

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

प्रकार काष्ठा tcov_पंक्ति {
    अचिन्हित पूर्णांक fline;
    अचिन्हित पूर्णांक lline;
    अचिन्हित दीर्घ दीर्घ गिनती_2;
} tcov_पंक्ति;

प्रकार काष्ठा tcov_function {
    अक्षर *function;
    अचिन्हित पूर्णांक first_पंक्ति;
    अचिन्हित पूर्णांक n_पंक्ति;
    अचिन्हित पूर्णांक m_पंक्ति;
    tcov_पंक्ति *पंक्ति_2;
} tcov_function;

प्रकार काष्ठा tcov_file {
    अक्षर *filename;
    अचिन्हित पूर्णांक n_func;
    अचिन्हित पूर्णांक m_func;
    tcov_function *func;
    काष्ठा tcov_file *अग्र;
} tcov_file;

अटल खाता *open_tcov_file (अक्षर *cov_filename)
{
    पूर्णांक fd;
#अगर_अघोषित _WIN32
    काष्ठा flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = शुरू_से;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#पूर्ण_अगर
    fd = खोलो (cov_filename, O_RDWR | O_CREAT, 0666);
    अगर (fd < 0)
	वापस शून्य;
  
#अगर_अघोषित _WIN32
    जबतक (fcntl (fd, F_SETLKW, &lock) && त्रुटि_सं == EINTR)
        जारी;
#अन्यथा
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#पूर्ण_अगर

    वापस fdopen (fd, "r+");
}

अटल अचिन्हित दीर्घ दीर्घ get_मूल्य(अचिन्हित अक्षर *p, पूर्णांक आकार)
{
    अचिन्हित दीर्घ दीर्घ मूल्य = 0;

    p += आकार;
    जबतक (आकार--)
 	मूल्य = (मूल्य << 8) | *--p;
    वापस मूल्य;
}

अटल पूर्णांक sort_func (स्थिर व्योम *p, स्थिर व्योम *q)
{
    स्थिर tcov_function *pp = (स्थिर tcov_function *) p;
    स्थिर tcov_function *pq = (स्थिर tcov_function *) q;

    वापस pp->first_पंक्ति > pq->first_पंक्ति ? 1 :
	   pp->first_पंक्ति < pq->first_पंक्ति ? -1 : 0;
}

अटल पूर्णांक sort_पंक्ति (स्थिर व्योम *p, स्थिर व्योम *q)
{
    स्थिर tcov_पंक्ति *pp = (स्थिर tcov_पंक्ति *) p;
    स्थिर tcov_पंक्ति *pq = (स्थिर tcov_पंक्ति *) q;

    वापस pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->गिनती_2 < pq->गिनती_2 ? 1 :
	   pp->गिनती_2 > pq->गिनती_2 ? -1 : 0;
}

/* sort to let inline functions work */
अटल tcov_file *sort_test_coverage (अचिन्हित अक्षर *p)
{
    पूर्णांक i, j, k;
    अचिन्हित अक्षर *start = p;
    tcov_file *file = शून्य;
    tcov_file *nfile;

    p += 4;
    जबतक (*p) {
        अक्षर *filename = (अक्षर *)p;
	माप_प्रकार len = म_माप (filename);

	nfile = file;
	जबतक (nfile) {
	    अगर (म_भेद (nfile->filename, filename) == 0)
		अवरोध;
	    nfile = nfile->अग्र;
	}
	अगर (nfile == शून्य) {
	    nfile = दो_स्मृति (माप(tcov_file));
	    अगर (nfile == शून्य) {
	        ख_लिखो (मानक_त्रुटि, "Malloc error test_coverage\n");
	        वापस file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = शून्य;
	    nfile->अग्र = शून्य;
	    अगर (file == शून्य)
	        file = nfile;
	    अन्यथा {
		tcov_file *lfile = file;

	        जबतक (lfile->अग्र)
		    lfile = lfile->अग्र;
		lfile->अग्र = nfile;
	    }
	}
	p += len + 1;
	जबतक (*p) {
	    पूर्णांक i;
	    अक्षर *function = (अक्षर *)p;
	    tcov_function *func;

	    p += म_माप (function) + 1;
	    p += -(p - start) & 7;
	    क्रम (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		अगर (म_भेद (func->function, function) == 0)
		    अवरोध;
	    }
	    अगर (i == nfile->n_func) {
	        अगर (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = पुनः_स्मृति (nfile->func,
					   nfile->m_func *
					   माप (tcov_function));
		    अगर (nfile->func == शून्य) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        वापस file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_पंक्ति = get_मूल्य (p, 8);
	        func->n_पंक्ति = 0;
	        func->m_पंक्ति = 0;
	        func->पंक्ति_2 = शून्य;
	    }
	    p += 8;
	    जबतक (*p) {
		tcov_पंक्ति *पंक्ति_2;
		अचिन्हित दीर्घ दीर्घ val;

		अगर (func->n_पंक्ति >= func->m_पंक्ति) {
		    func->m_पंक्ति = func->m_पंक्ति == 0 ? 4 : func->m_पंक्ति * 2;
		    func->पंक्ति_2 = पुनः_स्मृति (func->पंक्ति_2,
					  func->m_पंक्ति * माप (tcov_पंक्ति));
		    अगर (func->पंक्ति_2 == शून्य) {
		        ख_लिखो (मानक_त्रुटि, "Realloc error test_coverage\n");
		        वापस file;
		    }
		}
		पंक्ति_2 = &func->पंक्ति_2[func->n_पंक्ति++];
		val = get_मूल्य (p, 8);
	        पंक्ति_2->fline = (val >> 8) & 0xfffffffULL;
	        पंक्ति_2->lline = val >> 36;
	        पंक्ति_2->गिनती_2 = get_मूल्य (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    जबतक (nfile) {
	क्विक (nfile->func, nfile->n_func, माप (tcov_function), sort_func);
	क्रम (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    क्विक (func->पंक्ति_2, func->n_पंक्ति, माप (tcov_पंक्ति), sort_पंक्ति);
        }
	nfile = nfile->अग्र;
    }
    वापस file;
}

/* merge with previous tcov file */
अटल व्योम merge_test_coverage (tcov_file *file, खाता *fp,
				 अचिन्हित पूर्णांक *pruns)
{
    अचिन्हित पूर्णांक runs;
    अक्षर *p;
    अक्षर str[10000];
    
    *pruns = 1;
    अगर (fp == शून्य)
        वापस;
    अगर (ख_माला_लो(str, माप(str), fp) &&
        (p = म_खोजप (str, ':')) &&
        (माला_पूछो (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    जबतक (file) {
	पूर्णांक i;
	माप_प्रकार len = म_माप (file->filename);

	जबतक (ख_माला_लो(str, माप(str), fp) &&
	       (p = म_माला(str, "0:File:")) == शून्य) {}
        अगर ((p = म_माला(str, "0:File:")) == शून्य ||
	    म_भेदन (p + म_माप("0:File:"), file->filename, len) != 0 ||
	    p[म_माप("0:File:") + len] != ' ')
	    अवरोध;
	क्रम (i = 0; i < file->n_func; i++) {
	    पूर्णांक j;
	    tcov_function *func = &file->func[i];
	    अचिन्हित पूर्णांक अग्र_zero = 0;
	    अचिन्हित पूर्णांक curline = 0;

	    क्रम (j = 0; j < func->n_पंक्ति; j++) {
		tcov_पंक्ति *पंक्ति_2 = &func->पंक्ति_2[j];
	        अचिन्हित पूर्णांक fline = पंक्ति_2->fline;
	        अचिन्हित दीर्घ दीर्घ गिनती_2;
		अचिन्हित पूर्णांक tmp;
		अक्षर c;

		जबतक (curline < fline &&
		       ख_माला_लो(str, माप(str), fp))
		    अगर ((p = म_अक्षर(str, ':')) &&
			माला_पूछो (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		अगर (माला_पूछो (str, "%llu%c\n", &गिनती_2, &c) == 2) {
		    अगर (अग्र_zero == 0)
		        पंक्ति_2->गिनती_2 += गिनती_2;
		    अग्र_zero = c == '*';
		}
	    }
	}
	file = file->अग्र;
    }
}

/* store tcov data in file */
व्योम __store_test_coverage (अचिन्हित अक्षर * p)
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
    अगर (fp == शून्य) {
	ख_लिखो (मानक_त्रुटि, "Cannot create coverage file: %s\n", cov_filename);
	वापस;
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
    जबतक (nfile) {
	files++;
	क्रम (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    क्रम (j = 0; j < func->n_पंक्ति; j++) {
		blocks++;
		blocks_run += func->पंक्ति_2[j].गिनती_2 != 0;
	    }
	}
	nfile = nfile->अग्र;
    }
    अगर (blocks == 0)
	blocks = 1;
    ख_लिखो (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुन) blocks_run / blocks);
    nfile = file;
    जबतक (nfile) {
	खाता *src = ख_खोलो (nfile->filename, "r");
	अचिन्हित पूर्णांक curline = 1;
	अक्षर str[10000];

        अगर (src == शून्य)
	     जाओ अग्र;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	क्रम (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    क्रम (j = 0; j < func->n_पंक्ति; j++) {
		blocks++;
		blocks_run += func->पंक्ति_2[j].गिनती_2 != 0;
	    }
	}
	अगर (blocks == 0)
	    blocks = 1;
        ख_लिखो (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुन) blocks_run / blocks);
        क्रम (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    जबतक (curline < func->first_पंक्ति &&
		   ख_माला_लो(str, माप(str), src))
		ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    क्रम (j = 0; j < func->n_पंक्ति; j++) {
		blocks++;
		blocks_run += func->पंक्ति_2[j].गिनती_2 != 0;
	    }
	    अगर (blocks == 0)
		blocks = 1;
            ख_लिखो (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुन) blocks_run / blocks);
#अगर 0
	    क्रम (j = 0; j < func->n_पंक्ति; j++) {
	        अचिन्हित पूर्णांक fline = func->पंक्ति_2[j].fline;
	        अचिन्हित पूर्णांक lline = func->पंक्ति_2[j].lline;
		अचिन्हित दीर्घ दीर्घ गिनती_2 = func->पंक्ति_2[j].गिनती_2;

		ख_लिखो (fp, "%u %u %llu\n", fline, lline, गिनती_2);
	    }
#पूर्ण_अगर
	    क्रम (j = 0; j < func->n_पंक्ति;) {
	        अचिन्हित पूर्णांक fline = func->पंक्ति_2[j].fline;
	        अचिन्हित पूर्णांक lline = func->पंक्ति_2[j].lline;
	        अचिन्हित दीर्घ दीर्घ गिनती_2 = func->पंक्ति_2[j].गिनती_2;
		अचिन्हित पूर्णांक has_zero = 0;
		अचिन्हित पूर्णांक same_पंक्ति = fline == lline;

		j++;
		जबतक (j < func->n_पंक्ति) {
	            अचिन्हित पूर्णांक nfline = func->पंक्ति_2[j].fline;
	            अचिन्हित पूर्णांक nlline = func->पंक्ति_2[j].lline;
	            अचिन्हित दीर्घ दीर्घ ncount = func->पंक्ति_2[j].गिनती_2;

		    अगर (fline == nfline) {
			अगर (ncount == 0)
			    has_zero = 1;
			अन्यथा अगर (ncount > गिनती_2)
			    गिनती_2 =  ncount;
			same_पंक्ति = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अन्यथा
			अवरोध;
		}
		अगर (same_पंक्ति)
		     lline++;

	        जबतक (curline < fline &&
		       ख_माला_लो(str, माप(str), src))
		     ख_लिखो (fp, "        -:%5u:%s", curline++, str);
		जबतक (curline < lline &&
		       ख_माला_लो(str, माप(str), src)) {
		    अगर (गिनती_2 == 0)
		        ख_लिखो (fp, "    #####:%5u:%s",
				 curline, str);
		    अन्यथा अगर (has_zero)
		        ख_लिखो (fp, "%8llu*:%5u:%s", 
				 गिनती_2, curline, str);
		    अन्यथा
		        ख_लिखो (fp, "%9llu:%5u:%s",
				 गिनती_2, curline, str);
		    curline++;
		}
	    }
	}
	जबतक (ख_माला_लो(str, माप(str), src))
	    ख_लिखो (fp, "        -:%5u:%s", curline++, str);
	ख_बंद (src);
अग्र:
	nfile = nfile->अग्र;
    }
    जबतक (file) {
        क्रम (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->पंक्ति_2);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->अग्र;
	मुक्त (nfile);
    }
    ख_बंद (fp);
}
