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

static volatile 정수 run = 1;
static sem_t sem;
static sem_t sem_child;

static void
add (정수 n)
{
    정수 i;
    정수 arr[n];

    위해 (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * sizeof(정수));
}

static void *
high_load (void *unused)
{
    동안 (run) {
        add(10);
        add(20);
    }
    반환 NULL;
}

static void *
do_signal (void *unused)
{
    동안 (run) {
        kill (getpid(), SIGUSR1);
        동안 (sem_wait(&sem) < 0 && errno == EINTR);
    }
    반환 NULL;
}

static void *
do_fork (void *unused)
{
    pid_t pid;

    동안 (run) {
        switch ((pid = fork())) {
        case 0:
            add(1000);
            add(2000);
            exit(0);
            break;
        case -1:
            반환 NULL;
        default:
            동안 (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(NULL);
            break;
        }
    }
    반환 NULL;
}

static void signal_handler(정수 sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

static void child_handler(정수 sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    반환 GetTickCount();
#아니면
    struct timeval tv;
    gettimeofday(&tv, NULL);
    반환 tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

정수
main (void)
{
    정수 i;
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
#만약 !defined(__APPLE__)
    pthread_create(&id3, NULL, do_fork, NULL);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    동안 (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
#만약 !defined(__APPLE__)
    pthread_join(id3, NULL);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, NULL);
    만약 (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, NULL);
        siglongjmp (sj, 1);
        printf ("failed");
        반환 1;
    }
    sigprocmask (SIG_SETMASK, NULL, &m);
    만약 (!sigismember (&m, SIGUSR1))
        printf ("failed");
    반환 0;
}
