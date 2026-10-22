#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <semaphore.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <sys/types.h>
#ಅನ್ತರ್ಭಾವ <sys/wait.h>
#ಅನ್ತರ್ಭಾವ <sys/time.h>
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>

ಸ್ಥಿರ ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಸತತ = 1;
ಸ್ಥಿರ sem_t sem;
ಸ್ಥಿರ sem_t sem_ಮಗು;

ಸ್ಥಿರ ಶೂನ್ಯ
ಕೂಡಿಸು (ಪೂರ್ಣಾಂಕ n)
{
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ arr[n];

    ಗಾಗಿ (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
}

ಸ್ಥಿರ ಶೂನ್ಯ *
ಮೇಲಿನ_ತುಂಬು (ಶೂನ್ಯ *ಬಳಸದ)
{
    ಆಗ (ಸತತ) {
        ಕೂಡಿಸು(10);
        ಕೂಡಿಸು(20);
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ ಶೂನ್ಯ *
do_signal (ಶೂನ್ಯ *ಬಳಸದ)
{
    ಆಗ (ಸತತ) {
        kill (getpid(), SIGUSR1);
        ಆಗ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ ಶೂನ್ಯ *
do_fork (ಶೂನ್ಯ *ಬಳಸದ)
{
    pid_t pid;

    ಆಗ (ಸತತ) {
        ಆಯ್ಕೆ ((pid = fork())) {
        ಸ್ಥಿತಿ 0:
            ಕೂಡಿಸು(1000);
            ಕೂಡಿಸು(2000);
            ನಿರ್ಗಮಿಸು(0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ -1:
            ಹಿಂತಿರುಗಿ ಖಾಲಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಆಗ (sem_wait(&sem_ಮಗು) < 0 && errno == EINTR);
            wait(ಖಾಲಿ);
            ನಿಲ್ಲಿಸು;
        }
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ ಶೂನ್ಯ signal_handler(ಪೂರ್ಣಾಂಕ sig)
{
    ಕೂಡಿಸು(10);
    ಕೂಡಿಸು(20);
    sem_post (&sem);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಮಗು_handler(ಪೂರ್ಣಾಂಕ sig)
{
    ಕೂಡಿಸು(10);
    ಕೂಡಿಸು(20);
    sem_post (&sem_ಮಗು);
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ getclock_ms(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಹಿಂತಿರುಗಿ Get_Tick_ಎಣಿಕೆ();
#ಇಲ್ಲದಿದ್ದರೆ
    ರಚನೆ timeval tv;
    gettimeofday(&tv, ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i;
    pthread_t id1, id2, id3;
    ರಚನೆ sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t ಕೊನೆ;

    memset (&act, 0, ಗಾತ್ರ (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ಖಾಲಿ);
    act.sa_handler = ಮಗು_handler;
    sigaction (SIGCHLD, &act, ಖಾಲಿ);

    ಬರೆ ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_ಮಗು, 0, 0);
    pthread_create(&id1, ಖಾಲಿ, ಮೇಲಿನ_ತುಂಬು, ಖಾಲಿ);
    pthread_create(&id2, ಖಾಲಿ, do_signal, ಖಾಲಿ);
#ಆದರೆ !defined(__APPLE__)
    pthread_create(&id3, ಖಾಲಿ, do_fork, ಖಾಲಿ);
#ಆದರೆ_ಅಂತ್ಯ

    /* sleep does not work !!! */
    ಕೊನೆ = getclock_ms() + 200;
    ಆಗ (getclock_ms() < ಕೊನೆ) ;
    ಸತತ = 0;

    pthread_join(id1, ಖಾಲಿ);
    pthread_join(id2, ಖಾಲಿ);
#ಆದರೆ !defined(__APPLE__)
    pthread_join(id3, ಖಾಲಿ);
#ಆದರೆ_ಅಂತ್ಯ
    sem_destroy (&sem);
    sem_destroy (&sem_ಮಗು);

    ಬರೆ ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ಖಾಲಿ);
    ಆದರೆ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ಖಾಲಿ);
        siglongjmp (sj, 1);
        ಬರೆ ("failed");
        ಹಿಂತಿರುಗಿ 1;
    }
    sigprocmask (SIG_SETMASK, ಖಾಲಿ, &m);
    ಆದರೆ (!sigismember (&m, SIGUSR1))
        ಬರೆ ("failed");
    ಹಿಂತಿರುಗಿ 0;
}
