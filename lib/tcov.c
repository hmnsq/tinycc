#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <fcntl.h>
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <io.h>
#ಆದರೆ_ಅಂತ್ಯ

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

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ tcov_ಸಾಲು {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ fline;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ lline;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಎಣಿಕೆ_3;
} tcov_ಸಾಲು;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ tcov_function {
    ಅಕ್ಷರ *function;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮೊದಲ_ಸಾಲು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n_ಸಾಲು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ m_ಸಾಲು;
    tcov_ಸಾಲು *ಸಾಲು;
} tcov_function;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ tcov_file {
    ಅಕ್ಷರ *filename;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n_func;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ m_func;
    tcov_function *func;
    ರಚನೆ tcov_file *ಮುಂದಿನ;
} tcov_file;

ಸ್ಥಿರ FILE *open_tcov_file (ಅಕ್ಷರ *cov_filename)
{
    ಪೂರ್ಣಾಂಕ fd;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
    ರಚನೆ flock ಬೀಗ;

    ಬೀಗ.l_type = F_WRLCK;
    ಬೀಗ.l_whence = SEEK_SET;
    ಬೀಗ.l_start = 0;
    ಬೀಗ.l_len = 0; /* Until EOF.  */
    ಬೀಗ.l_pid = getpid ();
#ಆದರೆ_ಅಂತ್ಯ
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ಆದರೆ (fd < 0)
	ಹಿಂತಿರುಗಿ ಖಾಲಿ;
  
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
    ಆಗ (fcntl (fd, F_SETLKW, &ಬೀಗ) && errno == EINTR)
        ಮುಂದುವರಿ;
#ಇಲ್ಲದಿದ್ದರೆ
    {
        OVERLAPPED overlapped = { 0 };
        ಬೀಗ_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_ಬೀಗ,
		   0, 1, 0, &overlapped);
    }
#ಆದರೆ_ಅಂತ್ಯ

    ಹಿಂತಿರುಗಿ fdopen (fd, "r+");
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ get_ಮೌಲ್ಯ(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ = 0;

    p += ಗಾತ್ರ_2;
    ಆಗ (ಗಾತ್ರ_2--)
 	ಮೌಲ್ಯ = (ಮೌಲ್ಯ << 8) | *--p;
    ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ವಿಂಗಡಿಸು_func (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *q)
{
    ಸ್ಥಿರಾಂಕ tcov_function *pp = (ಸ್ಥಿರಾಂಕ tcov_function *) p;
    ಸ್ಥಿರಾಂಕ tcov_function *pq = (ಸ್ಥಿರಾಂಕ tcov_function *) q;

    ಹಿಂತಿರುಗಿ pp->ಮೊದಲ_ಸಾಲು > pq->ಮೊದಲ_ಸಾಲು ? 1 :
	   pp->ಮೊದಲ_ಸಾಲು < pq->ಮೊದಲ_ಸಾಲು ? -1 : 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ವಿಂಗಡಿಸು_ಸಾಲು (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *q)
{
    ಸ್ಥಿರಾಂಕ tcov_ಸಾಲು *pp = (ಸ್ಥಿರಾಂಕ tcov_ಸಾಲು *) p;
    ಸ್ಥಿರಾಂಕ tcov_ಸಾಲು *pq = (ಸ್ಥಿರಾಂಕ tcov_ಸಾಲು *) q;

    ಹಿಂತಿರುಗಿ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ಎಣಿಕೆ_3 < pq->ಎಣಿಕೆ_3 ? 1 :
	   pp->ಎಣಿಕೆ_3 > pq->ಎಣಿಕೆ_3 ? -1 : 0;
}

/* sort to let inline functions work */
ಸ್ಥಿರ tcov_file *ವಿಂಗಡಿಸು_test_coverage (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p)
{
    ಪೂರ್ಣಾಂಕ i, j, k;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಆರಂಭ = p;
    tcov_file *file = ಖಾಲಿ;
    tcov_file *nfile;

    p += 4;
    ಆಗ (*p) {
        ಅಕ್ಷರ *filename = (ಅಕ್ಷರ *)p;
	ಗಾತ್ರ_t len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (filename);

	nfile = file;
	ಆಗ (nfile) {
	    ಆದರೆ (strcmp (nfile->filename, filename) == 0)
		ನಿಲ್ಲಿಸು;
	    nfile = nfile->ಮುಂದಿನ;
	}
	ಆದರೆ (nfile == ಖಾಲಿ) {
	    nfile = ಸ್ಮರಣೆ_ಕೊಡು (ಗಾತ್ರ(tcov_file));
	    ಆದರೆ (nfile == ಖಾಲಿ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ಹಿಂತಿರುಗಿ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ಖಾಲಿ;
	    nfile->ಮುಂದಿನ = ಖಾಲಿ;
	    ಆದರೆ (file == ಖಾಲಿ)
	        file = nfile;
	    ಇಲ್ಲದಿದ್ದರೆ {
		tcov_file *lfile = file;

	        ಆಗ (lfile->ಮುಂದಿನ)
		    lfile = lfile->ಮುಂದಿನ;
		lfile->ಮುಂದಿನ = nfile;
	    }
	}
	p += len + 1;
	ಆಗ (*p) {
	    ಪೂರ್ಣಾಂಕ i;
	    ಅಕ್ಷರ *function = (ಅಕ್ಷರ *)p;
	    tcov_function *func;

	    p += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (function) + 1;
	    p += -(p - ಆರಂಭ) & 7;
	    ಗಾಗಿ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ಆದರೆ (strcmp (func->function, function) == 0)
		    ನಿಲ್ಲಿಸು;
	    }
	    ಆದರೆ (i == nfile->n_func) {
	        ಆದರೆ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   ಗಾತ್ರ (tcov_function));
		    ಆದರೆ (nfile->func == ಖಾಲಿ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ಹಿಂತಿರುಗಿ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->ಮೊದಲ_ಸಾಲು = get_ಮೌಲ್ಯ (p, 8);
	        func->n_ಸಾಲು = 0;
	        func->m_ಸಾಲು = 0;
	        func->ಸಾಲು = ಖಾಲಿ;
	    }
	    p += 8;
	    ಆಗ (*p) {
		tcov_ಸಾಲು *ಸಾಲು;
		ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ val;

		ಆದರೆ (func->n_ಸಾಲು >= func->m_ಸಾಲು) {
		    func->m_ಸಾಲು = func->m_ಸಾಲು == 0 ? 4 : func->m_ಸಾಲು * 2;
		    func->ಸಾಲು = realloc (func->ಸಾಲು,
					  func->m_ಸಾಲು * ಗಾತ್ರ (tcov_ಸಾಲು));
		    ಆದರೆ (func->ಸಾಲು == ಖಾಲಿ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ಹಿಂತಿರುಗಿ file;
		    }
		}
		ಸಾಲು = &func->ಸಾಲು[func->n_ಸಾಲು++];
		val = get_ಮೌಲ್ಯ (p, 8);
	        ಸಾಲು->fline = (val >> 8) & 0xfffffffULL;
	        ಸಾಲು->lline = val >> 36;
	        ಸಾಲು->ಎಣಿಕೆ_3 = get_ಮೌಲ್ಯ (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    ಆಗ (nfile) {
	qsort (nfile->func, nfile->n_func, ಗಾತ್ರ (tcov_function), ವಿಂಗಡಿಸು_func);
	ಗಾಗಿ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->ಸಾಲು, func->n_ಸಾಲು, ಗಾತ್ರ (tcov_ಸಾಲು), ವಿಂಗಡಿಸು_ಸಾಲು);
        }
	nfile = nfile->ಮುಂದಿನ;
    }
    ಹಿಂತಿರುಗಿ file;
}

/* merge with previous tcov file */
ಸ್ಥಿರ ಶೂನ್ಯ ವಿಲೀನ_test_coverage (tcov_file *file, FILE *fp,
				 ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *pruns)
{
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ runs;
    ಅಕ್ಷರ *p;
    ಅಕ್ಷರ str[10000];
    
    *pruns = 1;
    ಆದರೆ (fp == ಖಾಲಿ)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (fgets(str, ಗಾತ್ರ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (ಅಕ್ಷರಸರಣಿ_ಓದು (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ಆಗ (file) {
	ಪೂರ್ಣಾಂಕ i;
	ಗಾತ್ರ_t len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (file->filename);

	ಆಗ (fgets(str, ಗಾತ್ರ(str), fp) &&
	       (p = ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(str, "0:File:")) == ಖಾಲಿ) {}
        ಆದರೆ ((p = ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(str, "0:File:")) == ಖಾಲಿ ||
	    ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ (p + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ("0:File:"), file->filename, len) != 0 ||
	    p[ಅಕ್ಷರಸರಣಿ_ಉದ್ದ("0:File:") + len] != ' ')
	    ನಿಲ್ಲಿಸು;
	ಗಾಗಿ (i = 0; i < file->n_func; i++) {
	    ಪೂರ್ಣಾಂಕ j;
	    tcov_function *func = &file->func[i];
	    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮುಂದಿನ_zero = 0;
	    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ curline = 0;

	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		tcov_ಸಾಲು *ಸಾಲು = &func->ಸಾಲು[j];
	        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ fline = ಸಾಲು->fline;
	        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಎಣಿಕೆ_3;
		ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ tmp;
		ಅಕ್ಷರ c;

		ಆಗ (curline < fline &&
		       fgets(str, ಗಾತ್ರ(str), fp))
		    ಆದರೆ ((p = strchr(str, ':')) &&
			ಅಕ್ಷರಸರಣಿ_ಓದು (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಓದು (str, "%llu%c\n", &ಎಣಿಕೆ_3, &c) == 2) {
		    ಆದರೆ (ಮುಂದಿನ_zero == 0)
		        ಸಾಲು->ಎಣಿಕೆ_3 += ಎಣಿಕೆ_3;
		    ಮುಂದಿನ_zero = c == '*';
		}
	    }
	}
	file = file->ಮುಂದಿನ;
    }
}

/* store tcov data in file */
ಶೂನ್ಯ __store_test_coverage (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ * p)
{
    ಪೂರ್ಣಾಂಕ i, j;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ files;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ funcs;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಖಂಡಗಳು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಖಂಡಗಳು_ಸತತ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ runs;
    ಅಕ್ಷರ *cov_filename = (ಅಕ್ಷರ *)p + get_ಮೌಲ್ಯ (p, 4);
    FILE *fp;
    ಅಕ್ಷರ *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ಆದರೆ (fp == ಖಾಲಿ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ಹಿಂತಿರುಗಿ;
    }
    file = ವಿಂಗಡಿಸು_test_coverage (p);
    ವಿಲೀನ_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    ಖಂಡಗಳು = 0;
    ಖಂಡಗಳು_ಸತತ = 0;
    nfile = file;
    ಆಗ (nfile) {
	files++;
	ಗಾಗಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		ಖಂಡಗಳು++;
		ಖಂಡಗಳು_ಸತತ += func->ಸಾಲು[j].ಎಣಿಕೆ_3 != 0;
	    }
	}
	nfile = nfile->ಮುಂದಿನ;
    }
    ಆದರೆ (ಖಂಡಗಳು == 0)
	ಖಂಡಗಳು = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ದ್ವಿಗುಣ) ಖಂಡಗಳು_ಸತತ / ಖಂಡಗಳು);
    nfile = file;
    ಆಗ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ curline = 1;
	ಅಕ್ಷರ str[10000];

        ಆದರೆ (src == ಖಾಲಿ)
	     ಹೋಗು ಮುಂದಿನ;
	funcs = 0;
	ಖಂಡಗಳು = 0;
	ಖಂಡಗಳು_ಸತತ = 0;
	ಗಾಗಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		ಖಂಡಗಳು++;
		ಖಂಡಗಳು_ಸತತ += func->ಸಾಲು[j].ಎಣಿಕೆ_3 != 0;
	    }
	}
	ಆದರೆ (ಖಂಡಗಳು == 0)
	    ಖಂಡಗಳು = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ದ್ವಿಗುಣ) ಖಂಡಗಳು_ಸತತ / ಖಂಡಗಳು);
        ಗಾಗಿ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ಆಗ (curline < func->ಮೊದಲ_ಸಾಲು &&
		   fgets(str, ಗಾತ್ರ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    ಖಂಡಗಳು = 0;
	    ಖಂಡಗಳು_ಸತತ = 0;
	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು; j++) {
		ಖಂಡಗಳು++;
		ಖಂಡಗಳು_ಸತತ += func->ಸಾಲು[j].ಎಣಿಕೆ_3 != 0;
	    }
	    ಆದರೆ (ಖಂಡಗಳು == 0)
		ಖಂಡಗಳು = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ದ್ವಿಗುಣ) ಖಂಡಗಳು_ಸತತ / ಖಂಡಗಳು);
#ಆದರೆ 0
	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು; j++) {
	        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ fline = func->ಸಾಲು[j].fline;
	        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ lline = func->ಸಾಲು[j].lline;
		ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಎಣಿಕೆ_3 = func->ಸಾಲು[j].ಎಣಿಕೆ_3;

		fprintf (fp, "%u %u %llu\n", fline, lline, ಎಣಿಕೆ_3);
	    }
#ಆದರೆ_ಅಂತ್ಯ
	    ಗಾಗಿ (j = 0; j < func->n_ಸಾಲು;) {
	        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ fline = func->ಸಾಲು[j].fline;
	        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ lline = func->ಸಾಲು[j].lline;
	        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಎಣಿಕೆ_3 = func->ಸಾಲು[j].ಎಣಿಕೆ_3;
		ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ has_zero = 0;
		ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ same_ಸಾಲು = fline == lline;

		j++;
		ಆಗ (j < func->n_ಸಾಲು) {
	            ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ nfline = func->ಸಾಲು[j].fline;
	            ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ nlline = func->ಸಾಲು[j].lline;
	            ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ncount = func->ಸಾಲು[j].ಎಣಿಕೆ_3;

		    ಆದರೆ (fline == nfline) {
			ಆದರೆ (ncount == 0)
			    has_zero = 1;
			ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ncount > ಎಣಿಕೆ_3)
			    ಎಣಿಕೆ_3 =  ncount;
			same_ಸಾಲು = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ಇಲ್ಲದಿದ್ದರೆ
			ನಿಲ್ಲಿಸು;
		}
		ಆದರೆ (same_ಸಾಲು)
		     lline++;

	        ಆಗ (curline < fline &&
		       fgets(str, ಗಾತ್ರ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ಆಗ (curline < lline &&
		       fgets(str, ಗಾತ್ರ(str), src)) {
		    ಆದರೆ (ಎಣಿಕೆ_3 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ಎಣಿಕೆ_3, curline, str);
		    ಇಲ್ಲದಿದ್ದರೆ
		        fprintf (fp, "%9llu:%5u:%s",
				 ಎಣಿಕೆ_3, curline, str);
		    curline++;
		}
	    }
	}
	ಆಗ (fgets(str, ಗಾತ್ರ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
ಮುಂದಿನ:
	nfile = nfile->ಮುಂದಿನ;
    }
    ಆಗ (file) {
        ಗಾಗಿ (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    ಬಿಡುಗಡೆ (func->ಸಾಲು);
        }
	ಬಿಡುಗಡೆ (file->func);
	nfile = file;
	file = file->ಮುಂದಿನ;
	ಬಿಡುಗಡೆ (nfile);
    }
    fclose (fp);
}
