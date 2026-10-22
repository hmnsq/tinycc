#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
#ضمن <signal.h>
#ضمن <string.h>
#ضمن <sys/types.h>
#ضمن <sys/wait.h>
#ضمن <sys/time.h>
#ضمن <unistd.h>
#ضمن <stdlib.h>
#ضمن <errno.h>
#ضمن <setjmp.h>

ساكن متطاير صحيح لاڳيتو = 1;
ساكن sem_t sem;
ساكن sem_t sem_ٻار;

ساكن فراغ
جوڙيو (صحيح n)
{
    صحيح i;
    صحيح arr[n];

    لكل (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحيح));
}

ساكن فراغ *
مٿاهون_ڀريو (فراغ *اڻ_استعمال_ٿيل)
{
    طالما (لاڳيتو) {
        جوڙيو(10);
        جوڙيو(20);
    }
    أرجع عدم;
}

ساكن فراغ *
do_signal (فراغ *اڻ_استعمال_ٿيل)
{
    طالما (لاڳيتو) {
        kill (getpid(), SIGUSR1);
        طالما (sem_wait(&sem) < 0 && errno == EINTR);
    }
    أرجع عدم;
}

ساكن فراغ *
do_fork (فراغ *اڻ_استعمال_ٿيل)
{
    pid_t pid;

    طالما (لاڳيتو) {
        بدل ((pid = fork())) {
        حالة 0:
            جوڙيو(1000);
            جوڙيو(2000);
            ٻاهر_نڪرو(0);
            اكسر;
        حالة -1:
            أرجع عدم;
        افتراضي:
            طالما (sem_wait(&sem_ٻار) < 0 && errno == EINTR);
            wait(عدم);
            اكسر;
        }
    }
    أرجع عدم;
}

ساكن فراغ signal_handler(صحيح sig)
{
    جوڙيو(10);
    جوڙيو(20);
    sem_post (&sem);
}

ساكن فراغ ٻار_handler(صحيح sig)
{
    جوڙيو(10);
    جوڙيو(20);
    sem_post (&sem_ٻار);
}

ساكن بنانشان getclock_ms(فراغ)
{
#جيڪڏهن_وصف_ٿيل _WIN32
    أرجع Get_Tick_ڳڻپ();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#جيڪڏهن_پورو
}

صحيح
مکيه (فراغ)
{
    صحيح i;
    pthread_t id1, id2, id3;
    بنية sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t پڇاڙي;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, عدم);
    act.sa_handler = ٻار_handler;
    sigaction (SIGCHLD, &act, عدم);

    لکو ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_ٻار, 0, 0);
    pthread_create(&id1, عدم, مٿاهون_ڀريو, عدم);
    pthread_create(&id2, عدم, do_signal, عدم);
#إذا !defined(__APPLE__)
    pthread_create(&id3, عدم, do_fork, عدم);
#جيڪڏهن_پورو

    /* sleep does not work !!! */
    پڇاڙي = getclock_ms() + 200;
    طالما (getclock_ms() < پڇاڙي) ;
    لاڳيتو = 0;

    pthread_join(id1, عدم);
    pthread_join(id2, عدم);
#إذا !defined(__APPLE__)
    pthread_join(id3, عدم);
#جيڪڏهن_پورو
    sem_destroy (&sem);
    sem_destroy (&sem_ٻار);

    لکو ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, عدم);
    إذا (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, عدم);
        siglongjmp (sj, 1);
        لکو ("failed");
        أرجع 1;
    }
    sigprocmask (SIG_SETMASK, عدم, &m);
    إذا (!sigismember (&m, SIGUSR1))
        لکو ("failed");
    أرجع 0;
}
