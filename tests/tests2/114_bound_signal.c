#समावेश <stdio.h>
#समावेश <pthread.h>
#समावेश <semaphore.h>
#समावेश <signal.h>
#समावेश <string.h>
#समावेश <sys/types.h>
#समावेश <sys/wait.h>
#समावेश <sys/time.h>
#समावेश <unistd.h>
#समावेश <stdlib.h>
#समावेश <errno.h>
#समावेश <setjmp.h>

अटल अस्थिर पूर्णांक run = 1;
अटल sem_t sem;
अटल sem_t sem_child;

अटल व्योम
add (पूर्णांक n)
{
    पूर्णांक i;
    पूर्णांक arr[n];

    क्रम (i = 0; i < n; i++) {
        arr[i]++;
    }
    स_रखो (&arr[0], 0, n * माप(पूर्णांक));
}

अटल व्योम *
ऊपरी_load (व्योम *unused)
{
    जबतक (run) {
        add(10);
        add(20);
    }
    वापस शून्य;
}

अटल व्योम *
do_signal (व्योम *unused)
{
    जबतक (run) {
        समाप्त (getpid(), SIGUSR1);
        जबतक (sem_wait(&sem) < 0 && त्रुटि_सं == EINTR);
    }
    वापस शून्य;
}

अटल व्योम *
do_fork (व्योम *unused)
{
    pid_t pid;

    जबतक (run) {
        चयन ((pid = विभाजन())) {
        हाल 0:
            add(1000);
            add(2000);
            निकास(0);
            अवरोध;
        हाल -1:
            वापस शून्य;
        शेष:
            जबतक (sem_wait(&sem_child) < 0 && त्रुटि_सं == EINTR);
            रुको(शून्य);
            अवरोध;
        }
    }
    वापस शून्य;
}

अटल व्योम signal_handler(पूर्णांक sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

अटल व्योम child_handler(पूर्णांक sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

अटल अचिन्हित getclock_ms(व्योम)
{
#अगर_घोषित _WIN32
    वापस Get_Tick_गिनती();
#अन्यथा
    काष्ठा timeval tv;
    gettimeofday(&tv, शून्य);
    वापस tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#पूर्ण_अगर
}

पूर्णांक
मुख्य (व्योम)
{
    पूर्णांक i;
    pthread_t id1, id2, id3;
    काष्ठा sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    समय_प्रकार end;

    स_रखो (&act, 0, माप (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, शून्य);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, शून्य);

    म_लिखो ("start\n"); ख_साफ(मानक_निकास);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, शून्य, ऊपरी_load, शून्य);
    pthread_create(&id2, शून्य, do_signal, शून्य);
#अगर !defined(__APPLE__)
    pthread_create(&id3, शून्य, do_fork, शून्य);
#पूर्ण_अगर

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    जबतक (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, शून्य);
    pthread_join(id2, शून्य);
#अगर !defined(__APPLE__)
    pthread_join(id3, शून्य);
#पूर्ण_अगर
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    म_लिखो ("end\n"); ख_साफ(मानक_निकास);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, शून्य);
    अगर (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, शून्य);
        siglongjmp (sj, 1);
        म_लिखो ("failed");
        वापस 1;
    }
    sigprocmask (SIG_SETMASK, शून्य, &m);
    अगर (!sigismember (&m, SIGUSR1))
        म_लिखो ("failed");
    वापस 0;
}
