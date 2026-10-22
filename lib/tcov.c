#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <fcntl.h>
#ifndef _WIN32
#અન્તર્ભાવ <unistd.h>
#અન્તર્ભાવ <errno.h>
#નહીંતર
#અન્તર્ભાવ <windows.h>
#અન્તર્ભાવ <io.h>
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

પ્રકારવ્યાખ્યા સંરચના tcov_લીટી {
    unsigned પૂર્ણાંક fline;
    unsigned પૂર્ણાંક lline;
    unsigned long long ગણતરી_2;
} tcov_લીટી;

પ્રકારવ્યાખ્યા સંરચના tcov_function {
    અક્ષર *function;
    unsigned પૂર્ણાંક first_લીટી;
    unsigned પૂર્ણાંક n_લીટી;
    unsigned પૂર્ણાંક m_લીટી;
    tcov_લીટી *લીટી;
} tcov_function;

પ્રકારવ્યાખ્યા સંરચના tcov_file {
    અક્ષર *filename;
    unsigned પૂર્ણાંક n_func;
    unsigned પૂર્ણાંક m_func;
    tcov_function *func;
    સંરચના tcov_file *next;
} tcov_file;

સ્થિર FILE *open_tcov_file (અક્ષર *cov_filename)
{
    પૂર્ણાંક fd;
#ifndef _WIN32
    સંરચના flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; /* Until EOF.  */
    lock.l_pid = getpid ();
#endif
    fd = open (cov_filename, O_RDWR | O_CREAT, 0666);
    જો (fd < 0)
	પાછા ખાલી;
  
#ifndef _WIN32
    જ્યારે (fcntl (fd, F_SETLKW, &lock) && errno == EINTR)
        ચાલુ;
#નહીંતર
    {
        OVERLAPPED overlapped = { 0 };
        LockFileEx((HANDLE)_get_osfhandle(fd), LOCKFILE_EXCLUSIVE_LOCK,
		   0, 1, 0, &overlapped);
    }
#endif

    પાછા fdopen (fd, "r+");
}

સ્થિર unsigned long long get_કિંમત(unsigned અક્ષર *p, પૂર્ણાંક size)
{
    unsigned long long કિંમત = 0;

    p += size;
    જ્યારે (size--)
 	કિંમત = (કિંમત << 8) | *--p;
    પાછા કિંમત;
}

સ્થિર પૂર્ણાંક sort_func (અચલ શૂન્ય *p, અચલ શૂન્ય *q)
{
    અચલ tcov_function *pp = (અચલ tcov_function *) p;
    અચલ tcov_function *pq = (અચલ tcov_function *) q;

    પાછા pp->first_લીટી > pq->first_લીટી ? 1 :
	   pp->first_લીટી < pq->first_લીટી ? -1 : 0;
}

સ્થિર પૂર્ણાંક sort_લીટી (અચલ શૂન્ય *p, અચલ શૂન્ય *q)
{
    અચલ tcov_લીટી *pp = (અચલ tcov_લીટી *) p;
    અચલ tcov_લીટી *pq = (અચલ tcov_લીટી *) q;

    પાછા pp->fline > pq->fline ? 1 :
	   pp->fline < pq->fline ? -1 :
           pp->ગણતરી_2 < pq->ગણતરી_2 ? 1 :
	   pp->ગણતરી_2 > pq->ગણતરી_2 ? -1 : 0;
}

/* sort to let inline functions work */
સ્થિર tcov_file *sort_test_coverage (unsigned અક્ષર *p)
{
    પૂર્ણાંક i, j, k;
    unsigned અક્ષર *start = p;
    tcov_file *file = ખાલી;
    tcov_file *nfile;

    p += 4;
    જ્યારે (*p) {
        અક્ષર *filename = (અક્ષર *)p;
	size_t len = strlen (filename);

	nfile = file;
	જ્યારે (nfile) {
	    જો (strcmp (nfile->filename, filename) == 0)
		તોડો;
	    nfile = nfile->next;
	}
	જો (nfile == ખાલી) {
	    nfile = malloc (કદ(tcov_file));
	    જો (nfile == ખાલી) {
	        fprintf (stderr, "Malloc error test_coverage\n");
	        પાછા file;
    	    }
	    nfile->filename = filename;
	    nfile->n_func = 0;
	    nfile->m_func = 0;
	    nfile->func = ખાલી;
	    nfile->next = ખાલી;
	    જો (file == ખાલી)
	        file = nfile;
	    નહીંતર {
		tcov_file *lfile = file;

	        જ્યારે (lfile->next)
		    lfile = lfile->next;
		lfile->next = nfile;
	    }
	}
	p += len + 1;
	જ્યારે (*p) {
	    પૂર્ણાંક i;
	    અક્ષર *function = (અક્ષર *)p;
	    tcov_function *func;

	    p += strlen (function) + 1;
	    p += -(p - start) & 7;
	    માટે (i = 0; i < nfile->n_func; i++) {
		func = &nfile->func[i];
		જો (strcmp (func->function, function) == 0)
		    તોડો;
	    }
	    જો (i == nfile->n_func) {
	        જો (nfile->n_func >= nfile->m_func) {
		    nfile->m_func = nfile->m_func == 0 ? 4 : nfile->m_func * 2;
		    nfile->func = realloc (nfile->func,
					   nfile->m_func *
					   કદ (tcov_function));
		    જો (nfile->func == ખાલી) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        પાછા file;
		    }
	        }
	        func = &nfile->func[nfile->n_func++];
	        func->function = function;
	        func->first_લીટી = get_કિંમત (p, 8);
	        func->n_લીટી = 0;
	        func->m_લીટી = 0;
	        func->લીટી = ખાલી;
	    }
	    p += 8;
	    જ્યારે (*p) {
		tcov_લીટી *લીટી;
		unsigned long long val;

		જો (func->n_લીટી >= func->m_લીટી) {
		    func->m_લીટી = func->m_લીટી == 0 ? 4 : func->m_લીટી * 2;
		    func->લીટી = realloc (func->લીટી,
					  func->m_લીટી * કદ (tcov_લીટી));
		    જો (func->લીટી == ખાલી) {
		        fprintf (stderr, "Realloc error test_coverage\n");
		        પાછા file;
		    }
		}
		લીટી = &func->લીટી[func->n_લીટી++];
		val = get_કિંમત (p, 8);
	        લીટી->fline = (val >> 8) & 0xfffffffULL;
	        લીટી->lline = val >> 36;
	        લીટી->ગણતરી_2 = get_કિંમત (p + 8, 8);
	 	p += 16;
	    }
	    p++;
	}
	p++;
    }
    nfile = file;
    જ્યારે (nfile) {
	qsort (nfile->func, nfile->n_func, કદ (tcov_function), sort_func);
	માટે (i = 0; i < nfile->n_func; i++) {
	    tcov_function *func = &nfile->func[i];
	    qsort (func->લીટી, func->n_લીટી, કદ (tcov_લીટી), sort_લીટી);
        }
	nfile = nfile->next;
    }
    પાછા file;
}

/* merge with previous tcov file */
સ્થિર શૂન્ય merge_test_coverage (tcov_file *file, FILE *fp,
				 unsigned પૂર્ણાંક *pruns)
{
    unsigned પૂર્ણાંક runs;
    અક્ષર *p;
    અક્ષર str[10000];
    
    *pruns = 1;
    જો (fp == ખાલી)
        પાછા;
    જો (fgets(str, કદ(str), fp) &&
        (p = strrchr (str, ':')) &&
        (sscanf (p + 1, "%u", &runs) == 1)) 
        *pruns = runs + 1;
    જ્યારે (file) {
	પૂર્ણાંક i;
	size_t len = strlen (file->filename);

	જ્યારે (fgets(str, કદ(str), fp) &&
	       (p = strstr(str, "0:File:")) == ખાલી) {}
        જો ((p = strstr(str, "0:File:")) == ખાલી ||
	    strncmp (p + strlen("0:File:"), file->filename, len) != 0 ||
	    p[strlen("0:File:") + len] != ' ')
	    તોડો;
	માટે (i = 0; i < file->n_func; i++) {
	    પૂર્ણાંક j;
	    tcov_function *func = &file->func[i];
	    unsigned પૂર્ણાંક next_zero = 0;
	    unsigned પૂર્ણાંક curline = 0;

	    માટે (j = 0; j < func->n_લીટી; j++) {
		tcov_લીટી *લીટી = &func->લીટી[j];
	        unsigned પૂર્ણાંક fline = લીટી->fline;
	        unsigned long long ગણતરી_2;
		unsigned પૂર્ણાંક tmp;
		અક્ષર c;

		જ્યારે (curline < fline &&
		       fgets(str, કદ(str), fp))
		    જો ((p = strchr(str, ':')) &&
			sscanf (p + 1, "%u", &tmp) == 1)
			curline = tmp;
		જો (sscanf (str, "%llu%c\n", &ગણતરી_2, &c) == 2) {
		    જો (next_zero == 0)
		        લીટી->ગણતરી_2 += ગણતરી_2;
		    next_zero = c == '*';
		}
	    }
	}
	file = file->next;
    }
}

/* store tcov data in file */
શૂન્ય __store_test_coverage (unsigned અક્ષર * p)
{
    પૂર્ણાંક i, j;
    unsigned પૂર્ણાંક files;
    unsigned પૂર્ણાંક funcs;
    unsigned પૂર્ણાંક blocks;
    unsigned પૂર્ણાંક blocks_run;
    unsigned પૂર્ણાંક runs;
    અક્ષર *cov_filename = (અક્ષર *)p + get_કિંમત (p, 4);
    FILE *fp;
    અક્ષર *q;
    tcov_file *file;
    tcov_file *nfile;
    tcov_function *func;

    fp = open_tcov_file (cov_filename);
    જો (fp == ખાલી) {
	fprintf (stderr, "Cannot create coverage file: %s\n", cov_filename);
	પાછા;
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
    જ્યારે (nfile) {
	files++;
	માટે (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    માટે (j = 0; j < func->n_લીટી; j++) {
		blocks++;
		blocks_run += func->લીટી[j].ગણતરી_2 != 0;
	    }
	}
	nfile = nfile->next;
    }
    જો (blocks == 0)
	blocks = 1;
    fprintf (fp, "        -:    0:All:%s Files:%u Functions:%u %.02f%%\n",
	     cov_filename, files, funcs, 100.0 * (દ્વિગુણ) blocks_run / blocks);
    nfile = file;
    જ્યારે (nfile) {
	FILE *src = fopen (nfile->filename, "r");
	unsigned પૂર્ણાંક curline = 1;
	અક્ષર str[10000];

        જો (src == ખાલી)
	     જાઓ next;
	funcs = 0;
	blocks = 0;
	blocks_run = 0;
	માટે (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	    funcs++;
	    માટે (j = 0; j < func->n_લીટી; j++) {
		blocks++;
		blocks_run += func->લીટી[j].ગણતરી_2 != 0;
	    }
	}
	જો (blocks == 0)
	    blocks = 1;
        fprintf (fp, "        -:    0:File:%s Functions:%u %.02f%%\n",
		 nfile->filename, funcs, 100.0 * (દ્વિગુણ) blocks_run / blocks);
        માટે (i = 0; i < nfile->n_func; i++) {
	    func = &nfile->func[i];
	
	    જ્યારે (curline < func->first_લીટી &&
		   fgets(str, કદ(str), src))
		fprintf (fp, "        -:%5u:%s", curline++, str);
	    blocks = 0;
	    blocks_run = 0;
	    માટે (j = 0; j < func->n_લીટી; j++) {
		blocks++;
		blocks_run += func->લીટી[j].ગણતરી_2 != 0;
	    }
	    જો (blocks == 0)
		blocks = 1;
            fprintf (fp, "        -:    0:Function:%s %.02f%%\n",
		     func->function, 100.0 * (દ્વિગુણ) blocks_run / blocks);
#જો 0
	    માટે (j = 0; j < func->n_લીટી; j++) {
	        unsigned પૂર્ણાંક fline = func->લીટી[j].fline;
	        unsigned પૂર્ણાંક lline = func->લીટી[j].lline;
		unsigned long long ગણતરી_2 = func->લીટી[j].ગણતરી_2;

		fprintf (fp, "%u %u %llu\n", fline, lline, ગણતરી_2);
	    }
#endif
	    માટે (j = 0; j < func->n_લીટી;) {
	        unsigned પૂર્ણાંક fline = func->લીટી[j].fline;
	        unsigned પૂર્ણાંક lline = func->લીટી[j].lline;
	        unsigned long long ગણતરી_2 = func->લીટી[j].ગણતરી_2;
		unsigned પૂર્ણાંક has_zero = 0;
		unsigned પૂર્ણાંક same_લીટી = fline == lline;

		j++;
		જ્યારે (j < func->n_લીટી) {
	            unsigned પૂર્ણાંક nfline = func->લીટી[j].fline;
	            unsigned પૂર્ણાંક nlline = func->લીટી[j].lline;
	            unsigned long long ncount = func->લીટી[j].ગણતરી_2;

		    જો (fline == nfline) {
			જો (ncount == 0)
			    has_zero = 1;
			નહીંતર જો (ncount > ગણતરી_2)
			    ગણતરી_2 =  ncount;
			same_લીટી = nfline == nlline;
			lline = nlline;
			j++;
		    }
		    નહીંતર
			તોડો;
		}
		જો (same_લીટી)
		     lline++;

	        જ્યારે (curline < fline &&
		       fgets(str, કદ(str), src))
		     fprintf (fp, "        -:%5u:%s", curline++, str);
		જ્યારે (curline < lline &&
		       fgets(str, કદ(str), src)) {
		    જો (ગણતરી_2 == 0)
		        fprintf (fp, "    #####:%5u:%s",
				 curline, str);
		    નહીંતર જો (has_zero)
		        fprintf (fp, "%8llu*:%5u:%s", 
				 ગણતરી_2, curline, str);
		    નહીંતર
		        fprintf (fp, "%9llu:%5u:%s",
				 ગણતરી_2, curline, str);
		    curline++;
		}
	    }
	}
	જ્યારે (fgets(str, કદ(str), src))
	    fprintf (fp, "        -:%5u:%s", curline++, str);
	fclose (src);
next:
	nfile = nfile->next;
    }
    જ્યારે (file) {
        માટે (i = 0; i < file->n_func; i++) {
	    func = &file->func[i];
	    મુક્ત (func->લીટી);
        }
	મુક્ત (file->func);
	nfile = file;
	file = file->next;
	મુક્ત (nfile);
    }
    fclose (fp);
}
