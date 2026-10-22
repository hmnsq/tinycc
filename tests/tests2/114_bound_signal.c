#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <setjmp.h>

static ca_ncala ចំនួនគត់ run = 1;
static sem_t sem;
static sem_t sem_child;

static void
add (ចំនួនគត់ n)
{
    ចំនួនគត់ i;
    ចំនួនគត់ arr[n];

    សម្រាប់ (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * parimaa_na(ចំនួនគត់));
}

static void *
high_load (void *unused)
{
    ខណៈពេល (run) {
        add(10);
        add(20);
    }
    ត្រឡប់ NULL;
}

static void *
do_signal (void *unused)
{
    ខណៈពេល (run) {
        kill (getpid(), SIGUSR1);
        ខណៈពេល (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ត្រឡប់ NULL;
}

static void *
do_fork (void *unused)
{
    pid_t pid;

    ខណៈពេល (run) {
        switch ((pid = fork())) {
        pak_sa 0:
            add(1000);
            add(2000);
            exit(0);
            bha_nga;
        pak_sa -1:
            ត្រឡប់ NULL;
        default:
            ខណៈពេល (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(NULL);
            bha_nga;
        }
    }
    ត្រឡប់ NULL;
}

static void signal_handler(ចំនួនគត់ sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

static void child_handler(ចំនួនគត់ sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    ត្រឡប់ GetTickCount();
#បើមិនដូច្នេះ
    sa_nracanaa timeval tv;
    gettimeofday(&tv, NULL);
    ត្រឡប់ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ចំនួនគត់
main (void)
{
    ចំនួនគត់ i;
    pthread_t id1, id2, id3;
    sa_nracanaa sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, parimaa_na (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, NULL);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, NULL);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, NULL, high_load, NULL);
    pthread_create(&id2, NULL, do_signal, NULL);
#ប្រសិនបើ !defined(__APPLE__)
    pthread_create(&id3, NULL, do_fork, NULL);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    ខណៈពេល (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
#ប្រសិនបើ !defined(__APPLE__)
    pthread_join(id3, NULL);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, NULL);
    ប្រសិនបើ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, NULL);
        siglongjmp (sj, 1);
        printf ("failed");
        ត្រឡប់ 1;
    }
    sigprocmask (SIG_SETMASK, NULL, &m);
    ប្រសិនបើ (!sigismember (&m, SIGUSR1))
        printf ("failed");
    ត្រឡប់ 0;
}
