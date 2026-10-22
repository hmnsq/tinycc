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

static volatile ціле run = 1;
static sem_t sem;
static sem_t sem_child;

static void
add (ціле n)
{
    ціле i;
    ціле arr[n];

    для (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * sizeof(ціле));
}

static void *
high_load (void *unused)
{
    поки (run) {
        add(10);
        add(20);
    }
    повернути NULL;
}

static void *
do_signal (void *unused)
{
    поки (run) {
        kill (getpid(), SIGUSR1);
        поки (sem_wait(&sem) < 0 && errno == EINTR);
    }
    повернути NULL;
}

static void *
do_fork (void *unused)
{
    pid_t pid;

    поки (run) {
        switch ((pid = fork())) {
        case 0:
            add(1000);
            add(2000);
            exit(0);
            break;
        case -1:
            повернути NULL;
        default:
            поки (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(NULL);
            break;
        }
    }
    повернути NULL;
}

static void signal_handler(ціле sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

static void child_handler(ціле sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    повернути GetTickCount();
#інакше
    struct timeval tv;
    gettimeofday(&tv, NULL);
    повернути tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ціле
main (void)
{
    ціле i;
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
#якщо !defined(__APPLE__)
    pthread_create(&id3, NULL, do_fork, NULL);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    поки (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
#якщо !defined(__APPLE__)
    pthread_join(id3, NULL);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, NULL);
    якщо (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, NULL);
        siglongjmp (sj, 1);
        printf ("failed");
        повернути 1;
    }
    sigprocmask (SIG_SETMASK, NULL, &m);
    якщо (!sigismember (&m, SIGUSR1))
        printf ("failed");
    повернути 0;
}
