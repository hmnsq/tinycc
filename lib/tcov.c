#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <fcntl.h>
#यदि_अपरिभाषितम् _WIN32
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <errno.h>
#अन्यथा
#अन्तर्भाव <windows.h>
#अन्तर्भाव <io.h>
#यदि_अन्तः

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
    अचिह्नित पूर्णाङ्क fline;
    अचिह्नित पूर्णाङ्क lline;
    अचिह्नित दीर्घ दीर्घ गणनम्_2;
} tcov_पङ्क्तिः;

प्रकारनिर्देश संरचना tcov_function {
    वर्ण *function;
    अचिह्नित पूर्णाङ्क first_पङ्क्तिः;
    अचिह्नित पूर्णाङ्क n_पङ्क्तिः;
    अचिह्नित पूर्णाङ्क m_पङ्क्तिः;
    tcov_पङ्क्तिः *पङ्क्तिः;
} tcov_function;

प्रकारनिर्देश संरचना tcov_file {
    वर्ण *filename;
    अचिह्नित पूर्णाङ्क n_func;
    अचिह्नित पूर्णाङ्क m_func;
    tcov_function *func;
    संरचना tcov_file *अग्र;
} tcov_file;

स्थिर FILE *open_tcov_file (वर्ण *cov_filename)
{
    पूर्णाङ्क fd;
#यदि_अपरिभाषितम् _WIN32
    संरचना flock तालकम्;

    तालकम्.l_type = F_WRLCK;
    तालकम्.l_whence = SEEK_SET;
    तालकम्.l_start = 0;
    तालकम्.l_len = 0; /* Until EOF.  */
    तालकम्.l_pid = getpid ();
#यदि_अन्तः
    fd = उद्घाटय (cov_filename, O_RDWR | O_CREAT, 0666);
    यदि (fd < 0)
	प्रत्यागम रिक्त;
  
#यदि_अपरिभाषितम् _WIN32
    यावत् (fcntl (fd, F_SETLKW, &तालकम्) && errno == EINTR)
        अनुवर्त;
#अन्यथा
    {
        OVERLAPPED overlapped = { 0 };
        तालकम्_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_तालकम्,
		   0, 1, 0, &overlapped);
    }
#यदि_अन्तः

    प्रत्यागम fdopen (fd, "r+");
}

स्थिर अचिह्नित दीर्घ दीर्घ get_मानम्(अचिह्नित वर्ण *p, पूर्णाङ्क आकार)
{
    अचिह्नित दीर्घ दीर्घ मानम् = 0;

    p += आकार;
    यावत् (आकार--)
 	मानम् = (मानम् << 8) | *--p;
    प्रत्यागम मानम्;
}

स्थिर पूर्णाङ्क क्रमय_func (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_function *pp = (ध्रुव tcov_function *) p;
    ध्रुव tcov_function *pq = (ध्रुव tcov_function *) q;

    प्रत्यागम pp->first_पङ्क्तिः > pq->first_पङ्क्तिः ? 1 :
	   pp->first_पङ्क्तिः < pq->first_पङ्क्तिः ? -1 : 0;
}

स्थिर पूर्णाङ्क क्रमय_पङ्क्तिः (ध्रुव शून्य *p, ध्रुव शून्य *q)
{
    ध्रुव tcov_पङ्क्तिः *pp = (ध्रुव tcov_पङ्क्तिः *) p;
    ध्रुव tcov_पङ्क्तिः *pq = (ध्रुव tcov_पङ्क्तिः *) q;

    प्रत्यागम pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->गणनम्_2 < pq->गणनम्_2 ? 1 :
	   pp->गणनम्_2 > pq->गणनम्_2 ? -1 : 0;
}

/* sort to let inline functions work */
स्थिर tcov_file *क्रमय_test_coverage (अचिह्नित वर्ण *p)
{
    पूर्णाङ्क i, j, k;
    अचिह्नित वर्ण *start = p;
    tcov_file *file = रिक्त;
    tcov_file *nfile;

    p += 4;
    यावत् (*p) {
        वर्ण *filename = (वर्ण *)p;
	आकार_t len = वाक्यदैर्घ्यम् (filename);

	nfile = file;
	यावत् (nfile) {
	    यदि (वाक्यं_तुलय (nfile->filename, filename) == 0)
		भङ्ग;
	    nfile = nfile->अग्र;
	}
	यदि (nfile == रिक्त) {
	    nfile = स्मृतिं_देहि (परिमाण(tcov_file));
	    यदि (nfile == रिक्त) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        प्रत्यागम file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = रिक्त;
	    nfile->अग्र = रिक्त;
	    यदि (file == रिक्त)
	        file = nfile;
	    अन्यथा {
		tcov_file *lfile = file;

	        यावत् (lfile->अग्र)
		    lfile = lfile->अग्र;
		lfile->अग्र = nfile;
	    }
	}
	p += len + 1;
	यावत् (*p) {
	    पूर्णाङ्क i;
	    वर्ण *function = (वर्ण *)p;
	    tcov_function *func;

	    p += वाक्यदैर्घ्यम् (function) + 1;
	    p += -(p - start) & 7;
	    प्रति (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		यदि (वाक्यं_तुलय (func->function, function) == 0)
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
	        func->first_पङ्क्तिः = get_मानम् (p, 8);
	        func->n_पङ्क्तिः = 0;
	        func->m_पङ्क्तिः = 0;
	        func->पङ्क्तिः = रिक्त;
	    }
	    p += 8;
	    यावत् (*p) {
		tcov_पङ्क्तिः *पङ्क्तिः;
		अचिह्नित दीर्घ दीर्घ val;

		यदि (func->n_पङ्क्तिः >= func->m_पङ्क्तिः) {
		    func->m_पङ्क्तिः = func->m_पङ्क्तिः == 0 ? 4 : func->m_पङ्क्तिः * 2;
		    func->पङ्क्तिः = realloc (func->पङ्क्तिः,
					  func->m_पङ्क्तिः * परिमाण (tcov_पङ्क्तिः));
		    यदि (func->पङ्क्तिः == रिक्त) {
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
    यावत् (nfile) {
	शीघ्रं_क्रमय (nfile->func, nfile->n_func, परिमाण (tcov_function), क्रमय_func);
	प्रति (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    शीघ्रं_क्रमय (func->पङ्क्तिः, func->n_पङ्क्तिः, परिमाण (tcov_पङ्क्तिः), क्रमय_पङ्क्तिः);
        }
	nfile = nfile->अग्र;
    }
    प्रत्यागम file;
}

/* merge with previous tcov file */
स्थिर शून्य merge_test_coverage (tcov_file *file, FILE *fp,
				 अचिह्नित पूर्णाङ्क *pruns)
{
    अचिह्नित पूर्णाङ्क runs;
    वर्ण *p;
    वर्ण str[10000];
    
    *pruns = 1;
    यदि (fp == रिक्त)
        प्रत्यागम;
    यदि (fgets(str, परिमाण(str), fp) &&
        (p = strrchr (str, ':')) &&
        (वाक्यात्_पठ (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    यावत् (file) {
	पूर्णाङ्क i;
	आकार_t len = वाक्यदैर्घ्यम् (file->filename);

	यावत् (fgets(str, परिमाण(str), fp) &&
	       (p = वाक्ये_अन्विष(str, "0:File:")) == रिक्त) {}
        यदि ((p = वाक्ये_अन्विष(str, "0:File:")) == रिक्त ||
	    वाक्ये_तुलय (p + वाक्यदैर्घ्यम्("0:File:"), file->filename, len) != 0 ||
	    p[वाक्यदैर्घ्यम्("0:File:") + len] != ' ')
	    भङ्ग;
	प्रति (i = 0; i < file->n_func; i++) {
	    पूर्णाङ्क j;
	    tcov_function *func = &file->func[i];
	    अचिह्नित पूर्णाङ्क अग्र_zero = 0;
	    अचिह्नित पूर्णाङ्क curline = 0;

	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		tcov_पङ्क्तिः *पङ्क्तिः = &func->पङ्क्तिः[j];
	        अचिह्नित पूर्णाङ्क fline = पङ्क्तिः->fline;
	        अचिह्नित दीर्घ दीर्घ गणनम्_2;
		अचिह्नित पूर्णाङ्क tmp;
		वर्ण c;

		यावत् (curline < fline &&
		       fgets(str, परिमाण(str), fp))
		    यदि ((p = strchr(str, ':')) &&
			वाक्यात्_पठ (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		यदि (वाक्यात्_पठ (str, "%llu%c\n", &गणनम्_2, &c) == 2) {
		    यदि (अग्र_zero == 0)
		        पङ्क्तिः->गणनम्_2 += गणनम्_2;
		    अग्र_zero = c == '*';
		}
	    }
	}
	file = file->अग्र;
    }
}

/* store tcov data in file */
शून्य __store_test_coverage (अचिह्नित वर्ण * p)
{
    पूर्णाङ्क i, j;
    अचिह्नित पूर्णाङ्क files;
    अचिह्नित पूर्णाङ्क funcs;
    अचिह्नित पूर्णाङ्क खण्डानि;
    अचिह्नित पूर्णाङ्क खण्डानि_सततम्;
    अचिह्नित पूर्णाङ्क runs;
    वर्ण *cov_filename = (वर्ण *)p + get_मानम् (p, 4);
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
    file = क्रमय_test_coverage (p);
    merge_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    खण्डानि = 0;
    खण्डानि_सततम् = 0;
    nfile = file;
    यावत् (nfile) {
	files++;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		खण्डानि++;
		खण्डानि_सततम् += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	}
	nfile = nfile->अग्र;
    }
    यदि (खण्डानि == 0)
	खण्डानि = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (द्विगुण) खण्डानि_सततम् / खण्डानि);
    nfile = file;
    यावत् (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	अचिह्नित पूर्णाङ्क curline = 1;
	वर्ण str[10000];

        यदि (src == रिक्त)
	     गच्छ अग्र;
	funcs = 0;
	खण्डानि = 0;
	खण्डानि_सततम् = 0;
	प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		खण्डानि++;
		खण्डानि_सततम् += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	}
	यदि (खण्डानि == 0)
	    खण्डानि = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (द्विगुण) खण्डानि_सततम् / खण्डानि);
        प्रति (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    यावत् (curline < func->first_पङ्क्तिः &&
		   fgets(str, परिमाण(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    खण्डानि = 0;
	    खण्डानि_सततम् = 0;
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
		खण्डानि++;
		खण्डानि_सततम् += func->पङ्क्तिः[j].गणनम्_2 != 0;
	    }
	    यदि (खण्डानि == 0)
		खण्डानि = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (द्विगुण) खण्डानि_सततम् / खण्डानि);
#यदि 0
	    प्रति (j = 0; j < func->n_पङ्क्तिः; j++) {
	        अचिह्नित पूर्णाङ्क fline = func->पङ्क्तिः[j].fline;
	        अचिह्नित पूर्णाङ्क lline = func->पङ्क्तिः[j].lline;
		अचिह्नित दीर्घ दीर्घ गणनम्_2 = func->पङ्क्तिः[j].गणनम्_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, गणनम्_2);
	    }
#यदि_अन्तः
	    प्रति (j = 0; j < func->n_पङ्क्तिः;) {
	        अचिह्नित पूर्णाङ्क fline = func->पङ्क्तिः[j].fline;
	        अचिह्नित पूर्णाङ्क lline = func->पङ्क्तिः[j].lline;
	        अचिह्नित दीर्घ दीर्घ गणनम्_2 = func->पङ्क्तिः[j].गणनम्_2;
		अचिह्नित पूर्णाङ्क has_zero = 0;
		अचिह्नित पूर्णाङ्क same_पङ्क्तिः = fline == lline;

		j++;
		यावत् (j < func->n_पङ्क्तिः) {
	            अचिह्नित पूर्णाङ्क nfline = func->पङ्क्तिः[j].fline;
	            अचिह्नित पूर्णाङ्क nlline = func->पङ्क्तिः[j].lline;
	            अचिह्नित दीर्घ दीर्घ ncount = func->पङ्क्तिः[j].गणनम्_2;

		    यदि (fline == nfline) {
			यदि (ncount == 0)
			    has_zero = 1;
			अन्यथा यदि (ncount > गणनम्_2)
			    गणनम्_2 =  ncount;
			same_पङ्क्तिः = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    अन्यथा
			भङ्ग;
		}
		यदि (same_पङ्क्तिः)
		     lline++;

	        यावत् (curline < fline &&
		       fgets(str, परिमाण(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		यावत् (curline < lline &&
		       fgets(str, परिमाण(str), src)) {
		    यदि (गणनम्_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    अन्यथा यदि (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 गणनम्_2, curline, str);
		    अन्यथा
		        fprintf (fp, "%9llu:%5u:%s",
				 गणनम्_2, curline, str);
		    curline++;
		}
	    }
	}
	यावत् (fgets(str, परिमाण(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
अग्र:
	nfile = nfile->अग्र;
    }
    यावत् (file) {
        प्रति (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    मुक्त (func->पङ्क्तिः);
        }
	मुक्त (file->func);
	nfile = file;
	file = file->अग्र;
	मुक्त (nfile);
    }
    fclose (fp);
}
