#अन्तर्भाव <stdio.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <semaphore.h>
#अन्तर्भाव <signal.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <sys/types.h>
#अन्तर्भाव <sys/wait.h>
#अन्तर्भाव <sys/time.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <errno.h>
#अन्तर्भाव <setjmp.h>

स्थिर चञ्चल पूर्णाङ्क सततम् = 1;
स्थिर sem_t sem;
स्थिर sem_t sem_child;

स्थिर शून्य
सङ्कलय (पूर्णाङ्क n)
{
    पूर्णाङ्क i;
    पूर्णाङ्क arr[n];

    प्रति (i = 0; i < n; i++) {
        arr[i]++;
    }
    स्मृतिं_पूरय (&arr[0], 0, n * परिमाण(पूर्णाङ्क));
}

स्थिर शून्य *
उच्चः_आरोपय (शून्य *अप्रयुक्तम्)
{
    यावत् (सततम्) {
        सङ्कलय(10);
        सङ्कलय(20);
    }
    प्रत्यागम रिक्त;
}

स्थिर शून्य *
do_signal (शून्य *अप्रयुक्तम्)
{
    यावत् (सततम्) {
        kill (getpid(), SIGUSR1);
        यावत् (sem_wait(&sem) < 0 && errno == EINTR);
    }
    प्रत्यागम रिक्त;
}

स्थिर शून्य *
do_fork (शून्य *अप्रयुक्तम्)
{
    pid_t pid;

    यावत् (सततम्) {
        विकल्प ((pid = fork())) {
        पक्ष 0:
            सङ्कलय(1000);
            सङ्कलय(2000);
            निर्गच्छ(0);
            भङ्ग;
        पक्ष -1:
            प्रत्यागम रिक्त;
        स्वभाव:
            यावत् (sem_wait(&sem_child) < 0 && errno == EINTR);
            प्रतीक्षस्व(रिक्त);
            भङ्ग;
        }
    }
    प्रत्यागम रिक्त;
}

स्थिर शून्य signal_handler(पूर्णाङ्क sig)
{
    सङ्कलय(10);
    सङ्कलय(20);
    sem_post (&sem);
}

स्थिर शून्य child_handler(पूर्णाङ्क sig)
{
    सङ्कलय(10);
    सङ्कलय(20);
    sem_post (&sem_child);
}

स्थिर अचिह्नित getclock_ms(शून्य)
{
#यदि_परिभाषितम् _WIN32
    प्रत्यागम Get_Tick_गणनम्();
#अन्यथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    प्रत्यागम tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#यदि_अन्तः
}

पूर्णाङ्क
मुख्यम् (शून्य)
{
    पूर्णाङ्क i;
    pthread_t id1, id2, id3;
    संरचना sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t अन्तः;

    स्मृतिं_पूरय (&act, 0, परिमाण (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, रिक्त);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, रिक्त);

    प्रारूप_लिख ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, रिक्त, उच्चः_आरोपय, रिक्त);
    pthread_create(&id2, रिक्त, do_signal, रिक्त);
#यदि !defined(__APPLE__)
    pthread_create(&id3, रिक्त, do_fork, रिक्त);
#यदि_अन्तः

    /* sleep does not work !!! */
    अन्तः = getclock_ms() + 200;
    यावत् (getclock_ms() < अन्तः) ;
    सततम् = 0;

    pthread_join(id1, रिक्त);
    pthread_join(id2, रिक्त);
#यदि !defined(__APPLE__)
    pthread_join(id3, रिक्त);
#यदि_अन्तः
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    प्रारूप_लिख ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, रिक्त);
    यदि (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, रिक्त);
        siglongjmp (sj, 1);
        प्रारूप_लिख ("failed");
        प्रत्यागम 1;
    }
    sigprocmask (SIG_SETMASK, रिक्त, &m);
    यदि (!sigismember (&m, SIGUSR1))
        प्रारूप_लिख ("failed");
    प्रत्यागम 0;
}
