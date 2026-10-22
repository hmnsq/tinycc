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

static volatile số_nguyên run = 1;
static sem_t sem;
static sem_t sem_child;

static void
add (số_nguyên n)
{
    số_nguyên i;
    số_nguyên arr[n];

    cho (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * sizeof(số_nguyên));
}

static void *
high_load (void *unused)
{
    trong_khi (run) {
        add(10);
        add(20);
    }
    trả_về NULL;
}

static void *
do_signal (void *unused)
{
    trong_khi (run) {
        kill (getpid(), SIGUSR1);
        trong_khi (sem_wait(&sem) < 0 && errno == EINTR);
    }
    trả_về NULL;
}

static void *
do_fork (void *unused)
{
    pid_t pid;

    trong_khi (run) {
        switch ((pid = fork())) {
        case 0:
            add(1000);
            add(2000);
            exit(0);
            break;
        case -1:
            trả_về NULL;
        default:
            trong_khi (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(NULL);
            break;
        }
    }
    trả_về NULL;
}

static void signal_handler(số_nguyên sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

static void child_handler(số_nguyên sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    trả_về GetTickCount();
#không_thì
    struct timeval tv;
    gettimeofday(&tv, NULL);
    trả_về tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

số_nguyên
main (void)
{
    số_nguyên i;
    pthread_t id1, id2, id3;
    struct sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, sizeof (act));
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
#nếu !defined(__APPLE__)
    pthread_create(&id3, NULL, do_fork, NULL);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    trong_khi (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
#nếu !defined(__APPLE__)
    pthread_join(id3, NULL);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, NULL);
    nếu (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, NULL);
        siglongjmp (sj, 1);
        printf ("failed");
        trả_về 1;
    }
    sigprocmask (SIG_SETMASK, NULL, &m);
    nếu (!sigismember (&m, SIGUSR1))
        printf ("failed");
    trả_về 0;
}
