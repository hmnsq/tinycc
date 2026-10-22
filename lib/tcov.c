#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <fcntl.h>
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <errno.h>
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <io.h>
#ਜੇ_ਅੰਤ

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

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ tcov_ਸਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ fline;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ lline;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਗਿਣਤੀ_3;
} tcov_ਸਤਰ;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ tcov_function {
    ਅੱਖਰ *function;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਪਹਿਲਾ_ਸਤਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n_ਸਤਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ m_ਸਤਰ;
    tcov_ਸਤਰ *ਸਤਰ;
} tcov_function;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ tcov_file {
    ਅੱਖਰ *filename;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n_func;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ m_func;
    tcov_function *func;
    ਬਣਤਰ tcov_file *ਅਗਲਾ;
} tcov_file;

ਸਥਿਰ FILE *open_tcov_file (ਅੱਖਰ *cov_filename)
{
    ਪੂਰਨ fd;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਬਣਤਰ flock ਤਾਲਾ;

    ਤਾਲਾ.l_type = F_WRLCK;
    ਤਾਲਾ.l_whence = SEEK_SET;
    ਤਾਲਾ.l_start = 0;
    ਤਾਲਾ.l_len = 0; /* Until EOF.  */
    ਤਾਲਾ.l_pid = getpid ();
#ਜੇ_ਅੰਤ
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    ਜੇ (fd < 0)
	ਵਾਪਸ ਨਿਰਾ;
  
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਜਦੋਂ (fcntl (fd, F_SETLKW, &ਤਾਲਾ) && errno == EINTR)
        ਜਾਰੀ;
#ਨਹੀਂਤਾਂ
    {
        OVERLAPPED overlapped = { 0 };
        ਤਾਲਾ_File_Ex((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_ਤਾਲਾ,
		   0, 1, 0, &overlapped);
    }
#ਜੇ_ਅੰਤ

    ਵਾਪਸ fdopen (fd, "r+");
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ get_ਮੁੱਲ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, ਪੂਰਨ ਮਾਪ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ = 0;

    p += ਮਾਪ;
    ਜਦੋਂ (ਮਾਪ--)
 	ਮੁੱਲ = (ਮੁੱਲ << 8) | *--p;
    ਵਾਪਸ ਮੁੱਲ;
}

ਸਥਿਰ ਪੂਰਨ ਛਾਂਟੋ_func (ਅਚਲ ਖਾਲੀ *p, ਅਚਲ ਖਾਲੀ *q)
{
    ਅਚਲ tcov_function *pp = (ਅਚਲ tcov_function *) p;
    ਅਚਲ tcov_function *pq = (ਅਚਲ tcov_function *) q;

    ਵਾਪਸ pp->ਪਹਿਲਾ_ਸਤਰ > pq->ਪਹਿਲਾ_ਸਤਰ ? 1 :
	   pp->ਪਹਿਲਾ_ਸਤਰ < pq->ਪਹਿਲਾ_ਸਤਰ ? -1 : 0;
}

ਸਥਿਰ ਪੂਰਨ ਛਾਂਟੋ_ਸਤਰ (ਅਚਲ ਖਾਲੀ *p, ਅਚਲ ਖਾਲੀ *q)
{
    ਅਚਲ tcov_ਸਤਰ *pp = (ਅਚਲ tcov_ਸਤਰ *) p;
    ਅਚਲ tcov_ਸਤਰ *pq = (ਅਚਲ tcov_ਸਤਰ *) q;

    ਵਾਪਸ pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ਗਿਣਤੀ_3 < pq->ਗਿਣਤੀ_3 ? 1 :
	   pp->ਗਿਣਤੀ_3 > pq->ਗਿਣਤੀ_3 ? -1 : 0;
}

/* sort to let inline functions work */
ਸਥਿਰ tcov_file *ਛਾਂਟੋ_test_coverage (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p)
{
    ਪੂਰਨ i, j, k;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਸ਼ੁਰੂ = p;
    tcov_file *file = ਨਿਰਾ;
    tcov_file *nfile;

    p += 4;
    ਜਦੋਂ (*p) {
        ਅੱਖਰ *filename = (ਅੱਖਰ *)p;
	ਮਾਪ_t len = ਲੜੀ_ਲੰਬਾਈ (filename);

	nfile = file;
	ਜਦੋਂ (nfile) {
	    ਜੇ (strcmp (nfile->filename, filename) == 0)
		ਰੋਕੋ;
	    nfile = nfile->ਅਗਲਾ;
	}
	ਜੇ (nfile == ਨਿਰਾ) {
	    nfile = ਸਮ੍ਰਿਤੀ_ਦਿਓ (ਆਕਾਰ(tcov_file));
	    ਜੇ (nfile == ਨਿਰਾ) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        ਵਾਪਸ file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ਨਿਰਾ;
	    nfile->ਅਗਲਾ = ਨਿਰਾ;
	    ਜੇ (file == ਨਿਰਾ)
	        file = nfile;
	    ਨਹੀਂਤਾਂ {
		tcov_file *lfile = file;

	        ਜਦੋਂ (lfile->ਅਗਲਾ)
		    lfile = lfile->ਅਗਲਾ;
		lfile->ਅਗਲਾ = nfile;
	    }
	}
	p += len + 1;
	ਜਦੋਂ (*p) {
	    ਪੂਰਨ i;
	    ਅੱਖਰ *function = (ਅੱਖਰ *)p;
	    tcov_function *func;

	    p += ਲੜੀ_ਲੰਬਾਈ (function) + 1;
	    p += -(p - ਸ਼ੁਰੂ) & 7;
	    ਲਈ (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		ਜੇ (strcmp (func->function, function) == 0)
		    ਰੋਕੋ;
	    }
	    ਜੇ (i == nfile->n_func) {
	        ਜੇ (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   ਆਕਾਰ (tcov_function));
		    ਜੇ (nfile->func == ਨਿਰਾ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ਵਾਪਸ file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->ਪਹਿਲਾ_ਸਤਰ = get_ਮੁੱਲ (p, 8);
	        func->n_ਸਤਰ = 0;
	        func->m_ਸਤਰ = 0;
	        func->ਸਤਰ = ਨਿਰਾ;
	    }
	    p += 8;
	    ਜਦੋਂ (*p) {
		tcov_ਸਤਰ *ਸਤਰ;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ val;

		ਜੇ (func->n_ਸਤਰ >= func->m_ਸਤਰ) {
		    func->m_ਸਤਰ = func->m_ਸਤਰ == 0 ? 4 : func->m_ਸਤਰ * 2;
		    func->ਸਤਰ = realloc (func->ਸਤਰ,
					  func->m_ਸਤਰ * ਆਕਾਰ (tcov_ਸਤਰ));
		    ਜੇ (func->ਸਤਰ == ਨਿਰਾ) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        ਵਾਪਸ file;
		    }
		}
		ਸਤਰ = &func->ਸਤਰ[func->n_ਸਤਰ++];
		val = get_ਮੁੱਲ (p, 8);
	        ਸਤਰ->fline = (val >> 8) & 0xfffffffULL;
	        ਸਤਰ->lline = val >> 36;
	        ਸਤਰ->ਗਿਣਤੀ_3 = get_ਮੁੱਲ (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    ਜਦੋਂ (nfile) {
	qsort (nfile->func, nfile->n_func, ਆਕਾਰ (tcov_function), ਛਾਂਟੋ_func);
	ਲਈ (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->ਸਤਰ, func->n_ਸਤਰ, ਆਕਾਰ (tcov_ਸਤਰ), ਛਾਂਟੋ_ਸਤਰ);
        }
	nfile = nfile->ਅਗਲਾ;
    }
    ਵਾਪਸ file;
}

/* merge with previous tcov file */
ਸਥਿਰ ਖਾਲੀ ਮਿਲਾਓ_test_coverage (tcov_file *file, FILE *fp,
				 ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *pruns)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ runs;
    ਅੱਖਰ *p;
    ਅੱਖਰ str[10000];
    
    *pruns = 1;
    ਜੇ (fp == ਨਿਰਾ)
        ਵਾਪਸ;
    ਜੇ (fgets(str, ਆਕਾਰ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    ਜਦੋਂ (file) {
	ਪੂਰਨ i;
	ਮਾਪ_t len = ਲੜੀ_ਲੰਬਾਈ (file->filename);

	ਜਦੋਂ (fgets(str, ਆਕਾਰ(str), fp) &&
	       (p = ਲੜੀ_ਖੋਜ(str, "0:File:")) == ਨਿਰਾ) {}
        ਜੇ ((p = ਲੜੀ_ਖੋਜ(str, "0:File:")) == ਨਿਰਾ ||
	    ਲੜੀ_ਤੁਲਨਾ (p + ਲੜੀ_ਲੰਬਾਈ("0:File:"), file->filename, len) != 0 ||
	    p[ਲੜੀ_ਲੰਬਾਈ("0:File:") + len] != ' ')
	    ਰੋਕੋ;
	ਲਈ (i = 0; i < file->n_func; i++) {
	    ਪੂਰਨ j;
	    tcov_function *func = &file->func[i];
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਅਗਲਾ_zero = 0;
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ curline = 0;

	    ਲਈ (j = 0; j < func->n_ਸਤਰ; j++) {
		tcov_ਸਤਰ *ਸਤਰ = &func->ਸਤਰ[j];
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ fline = ਸਤਰ->fline;
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਗਿਣਤੀ_3;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ tmp;
		ਅੱਖਰ c;

		ਜਦੋਂ (curline < fline &&
		       fgets(str, ਆਕਾਰ(str), fp))
		    ਜੇ ((p = strchr(str, ':')) &&
			ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		ਜੇ (ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ (str, "%llu%c\n", &ਗਿਣਤੀ_3, &c) == 2) {
		    ਜੇ (ਅਗਲਾ_zero == 0)
		        ਸਤਰ->ਗਿਣਤੀ_3 += ਗਿਣਤੀ_3;
		    ਅਗਲਾ_zero = c == '*';
		}
	    }
	}
	file = file->ਅਗਲਾ;
    }
}

/* store tcov data in file */
ਖਾਲੀ __store_test_coverage (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ * p)
{
    ਪੂਰਨ i, j;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ files;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ funcs;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਖੰਡਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਖੰਡਾਂ_ਲੜੀਵਾਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ runs;
    ਅੱਖਰ *cov_filename = (ਅੱਖਰ *)p + get_ਮੁੱਲ (p, 4);
    FILE *fp;
    ਅੱਖਰ *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    ਜੇ (fp == ਨਿਰਾ) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	ਵਾਪਸ;
    }
    file = ਛਾਂਟੋ_test_coverage (p);
    ਮਿਲਾਓ_test_coverage (file, fp, &runs);
    fseek (fp, 0, SEEK_SET);
    fprintf (fp, "        -:    0:Runs:%u\n", runs);
    files = 0;
    funcs = 0;
    ਖੰਡਾਂ = 0;
    ਖੰਡਾਂ_ਲੜੀਵਾਰ = 0;
    nfile = file;
    ਜਦੋਂ (nfile) {
	files++;
	ਲਈ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ਲਈ (j = 0; j < func->n_ਸਤਰ; j++) {
		ਖੰਡਾਂ++;
		ਖੰਡਾਂ_ਲੜੀਵਾਰ += func->ਸਤਰ[j].ਗਿਣਤੀ_3 != 0;
	    }
	}
	nfile = nfile->ਅਗਲਾ;
    }
    ਜੇ (ਖੰਡਾਂ == 0)
	ਖੰਡਾਂ = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (ਦੁੱਗਣਾ) ਖੰਡਾਂ_ਲੜੀਵਾਰ / ਖੰਡਾਂ);
    nfile = file;
    ਜਦੋਂ (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ curline = 1;
	ਅੱਖਰ str[10000];

        ਜੇ (src == ਨਿਰਾ)
	     ਜਾਓ ਅਗਲਾ;
	funcs = 0;
	ਖੰਡਾਂ = 0;
	ਖੰਡਾਂ_ਲੜੀਵਾਰ = 0;
	ਲਈ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    ਲਈ (j = 0; j < func->n_ਸਤਰ; j++) {
		ਖੰਡਾਂ++;
		ਖੰਡਾਂ_ਲੜੀਵਾਰ += func->ਸਤਰ[j].ਗਿਣਤੀ_3 != 0;
	    }
	}
	ਜੇ (ਖੰਡਾਂ == 0)
	    ਖੰਡਾਂ = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (ਦੁੱਗਣਾ) ਖੰਡਾਂ_ਲੜੀਵਾਰ / ਖੰਡਾਂ);
        ਲਈ (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    ਜਦੋਂ (curline < func->ਪਹਿਲਾ_ਸਤਰ &&
		   fgets(str, ਆਕਾਰ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    ਖੰਡਾਂ = 0;
	    ਖੰਡਾਂ_ਲੜੀਵਾਰ = 0;
	    ਲਈ (j = 0; j < func->n_ਸਤਰ; j++) {
		ਖੰਡਾਂ++;
		ਖੰਡਾਂ_ਲੜੀਵਾਰ += func->ਸਤਰ[j].ਗਿਣਤੀ_3 != 0;
	    }
	    ਜੇ (ਖੰਡਾਂ == 0)
		ਖੰਡਾਂ = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (ਦੁੱਗਣਾ) ਖੰਡਾਂ_ਲੜੀਵਾਰ / ਖੰਡਾਂ);
#ਜੇ 0
	    ਲਈ (j = 0; j < func->n_ਸਤਰ; j++) {
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ fline = func->ਸਤਰ[j].fline;
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ lline = func->ਸਤਰ[j].lline;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਗਿਣਤੀ_3 = func->ਸਤਰ[j].ਗਿਣਤੀ_3;

		fprintf (fp, "%u %u %llu\n", fline, lline, ਗਿਣਤੀ_3);
	    }
#ਜੇ_ਅੰਤ
	    ਲਈ (j = 0; j < func->n_ਸਤਰ;) {
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ fline = func->ਸਤਰ[j].fline;
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ lline = func->ਸਤਰ[j].lline;
	        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਗਿਣਤੀ_3 = func->ਸਤਰ[j].ਗਿਣਤੀ_3;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ has_zero = 0;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ same_ਸਤਰ = fline == lline;

		j++;
		ਜਦੋਂ (j < func->n_ਸਤਰ) {
	            ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ nfline = func->ਸਤਰ[j].fline;
	            ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ nlline = func->ਸਤਰ[j].lline;
	            ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ncount = func->ਸਤਰ[j].ਗਿਣਤੀ_3;

		    ਜੇ (fline == nfline) {
			ਜੇ (ncount == 0)
			    has_zero = 1;
			ਨਹੀਂਤਾਂ ਜੇ (ncount > ਗਿਣਤੀ_3)
			    ਗਿਣਤੀ_3 =  ncount;
			same_ਸਤਰ = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    ਨਹੀਂਤਾਂ
			ਰੋਕੋ;
		}
		ਜੇ (same_ਸਤਰ)
		     lline++;

	        ਜਦੋਂ (curline < fline &&
		       fgets(str, ਆਕਾਰ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		ਜਦੋਂ (curline < lline &&
		       fgets(str, ਆਕਾਰ(str), src)) {
		    ਜੇ (ਗਿਣਤੀ_3 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    ਨਹੀਂਤਾਂ ਜੇ (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ਗਿਣਤੀ_3, curline, str);
		    ਨਹੀਂਤਾਂ
		        fprintf (fp, "%9llu:%5u:%s",
				 ਗਿਣਤੀ_3, curline, str);
		    curline++;
		}
	    }
	}
	ਜਦੋਂ (fgets(str, ਆਕਾਰ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
ਅਗਲਾ:
	nfile = nfile->ਅਗਲਾ;
    }
    ਜਦੋਂ (file) {
        ਲਈ (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    ਮੁਕਤ (func->ਸਤਰ);
        }
	ਮੁਕਤ (file->func);
	nfile = file;
	file = file->ਅਗਲਾ;
	ਮੁਕਤ (nfile);
    }
    fclose (fp);
}
