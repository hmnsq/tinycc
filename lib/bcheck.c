/*
 *  Tiny C Memory and bounds checker
 * 
 *  Copyright (c) 2002 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <setjmp.h>
#include <stdatomic.h>

#if !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#include <malloc.h>
#endif

#if !defined(_WIN32)
#include <unistd.h>
#include <sys/syscall.h>
#endif

#include "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#if BOUND_DEBUG
 #define dprintf(a...)         if (इलिम्बाग_calls) { bounds_loc(a); }
#else
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#else
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#else
# define DLL_EXPORT
#endif

#if defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#include <sys/mman.h>
#define INIT_SEM()
#define EXIT_SEM()
#define WAIT_SEM()
#define POST_SEM()
#define TRY_SEM()
#define HAVE_MEMALIGN          (0)
#define MALLOC_REDIR           (0)
#define HAVE_PTHREAD_CREATE    (0)
#define HAVE_CTYPE             (0)
#define HAVE_ERRNO             (0)
#define HAVE_SIGNAL            (0)
#define HAVE_SIGACTION         (0)
#define HAVE_FORK              (0)
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (0)

#elif defined(_WIN32)

#include <windows.h>
#include <signal.h>
static CRITICAL_SECTION bounds_sem;
#define INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#define EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#define WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#define POST_SEM()             LeaveCriticalSection(&bounds_sem)
#define TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#define HAVE_MEMALIGN          (0)
#define MALLOC_REDIR           (0)
#define HAVE_PTHREAD_CREATE    (0)
#define HAVE_CTYPE             (0)
#define HAVE_ERRNO             (0)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (0)
#define HAVE_FORK              (0)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)

#else

#define __USE_GNU              /* get RTLD_NEXT */
#include <sys/mman.h>
#include <ctype.h>
#include <pthread.h>
#include <dlfcn.h>
#include <errno.h>
#include <signal.h>
#ifdef __APPLE__
#include <dispatch/dispatch.h>
static dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             if (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             if (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              if (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#elif 0
#include <semaphore.h>
static sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             if (use_sem) while (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             if (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              if (use_sem) while (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#elif 0
static pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, NULL)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             if (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             if (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              if (use_sem) pthread_mutex_trylock (&bounds_mtx)
#else
static pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             if (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             if (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              if (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#if defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#else
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#if defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#if MALLOC_REDIR
static void *(*malloc_redir) (size_t);
static void *(*calloc_redir) (size_t, size_t);
static void (*free_redir) (void *);
static void *(*realloc_redir) (void *, size_t);
static unsigned int pool_index;
static unsigned char __attribute__((aligned(16))) initial_pool[256];
#endif
#if HAVE_MEMALIGN
static void *(*memalign_redir) (size_t, size_t);
#endif
#if HAVE_PTHREAD_CREATE
static int (*pthread_create_redir) (pthread_t *thread,
                                    const pthread_attr_t *attr,
                                    void *(*start_routine)(void *), void *arg);
#endif
#if HAVE_SIGNAL
typedef void (*bound_sig)(int);
static bound_sig (*signal_redir) (int signum, bound_sig handler);
#endif
#if HAVE_SIGACTION
static int (*sigaction_redir) (int signum, const struct sigaction *act,
                               struct sigaction *oldact);
#endif
#if HAVE_FORK
static int (*fork_redir) (void);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((void *)(-2))

typedef struct पुनो_बुहोल पुनो;
struct पुनो_बुहोल {
    पुनो * कालिवा, * कानान;
    size_t start;
    size_t size;
    unsigned char type;
    unsigned char is_invalid; /* true if pointers outside region are invalid */
};

typedef struct alloca_list_struct {
    size_t fp;
    void *p;
    size_t size;
    struct alloca_list_struct *next;
} alloca_list_type;

#if defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#elif defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#elif defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#elif  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#elif defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#else
#define BOUND_TID_TYPE		int
#define BOUND_GET_TID(id)	id = 0
#endif

typedef struct jmp_list_struct {
    void *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    struct jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
static पुनो * splay (size_t addr, पुनो *t);
static पुनो * splay_end (size_t addr, पुनो *t);
static पुनो * splay_इसिंगित(size_t addr, size_t size, पुनो * t);
static पुनो * splay_delete(size_t addr, पुनो *t);
void splay_printtree(पुनो * t, int d);

/* external interface */
void __bounds_checking (int no_check);
void __bound_checking_lock (void);
void __bound_checking_unlock (void);
void __bound_never_fatal (int no_check);
DLL_EXPORT void * __bound_ptr_add(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir1(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir2(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir4(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir8(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir12(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir16(void *p, size_t offset);
DLL_EXPORT void FASTCALL __bound_local_new(void *p1);
DLL_EXPORT void FASTCALL __bound_local_delete(void *p1);
void __bound_init(size_t *, int);
void __bound_main_arg(int argc, char **argv, char **envp);
void __bound_exit(void);
void __bound_exit_dll(size_t *);
#if !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, int prot, int flags, int fd,
                    off_t offset);
int __bound_munmap (void *start, size_t size);
DLL_EXPORT void __bound_siglongjmp(jmp_buf env, int val);
#endif
DLL_EXPORT void __bound_new_region(void *p, size_t size);
DLL_EXPORT void __bound_setjmp(jmp_buf env);
DLL_EXPORT void __bound_longjmp(jmp_buf env, int val);
DLL_EXPORT void *__bound_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT int __bound_memcmp(const void *s1, const void *s2, size_t size);
DLL_EXPORT void *__bound_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound_memset(void *dst, int c, size_t size);
DLL_EXPORT int __bound_strlen(const char *s);
DLL_EXPORT char *__bound_strcpy(char *dst, const char *src);
DLL_EXPORT char *__bound_strncpy(char *dst, const char *src, size_t n);
DLL_EXPORT int __bound_strcmp(const char *s1, const char *s2);
DLL_EXPORT int __bound_strncmp(const char *s1, const char *s2, size_t n);
DLL_EXPORT char *__bound_strcat(char *dest, const char *src);
DLL_EXPORT char *__bound_strncat(char *dest, const char *src, size_t n);
DLL_EXPORT char *__bound_strchr(const char *string, int ch);
DLL_EXPORT char *__bound_strrchr(const char *string, int ch);
DLL_EXPORT char *__bound_strdup(const char *s);

#if defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT void *__bound___aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memset(void *dst, int c, size_t size);
DLL_EXPORT void *__aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memset(void *dst, int c, size_t size);
#endif

#if MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#else
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            free(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT void *__bound_malloc(size_t size, const void *caller);
DLL_EXPORT void *__bound_memalign(size_t align, size_t size, const void *caller);
DLL_EXPORT void __bound_free(void *ptr, const void *caller);
DLL_EXPORT void *__bound_realloc(void *ptr, size_t size, const void *caller);
DLL_EXPORT void *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
static unsigned int free_reuse_index;
static void *free_reuse_list[FREE_REUSE_SIZE];

static पुनो *पुनो_2 = NULL;
#define पुनो_REUSE      (1)
#if पुनो_REUSE
static पुनो *पुनो_free_list;
#endif
static alloca_list_type *alloca_list;
static jmp_list_type *jmp_list;

static unsigned char inited;
static unsigned char इलिम्बाग_warn_ptr_add;
static unsigned char इलिम्बाग_calls;
static unsigned char इलिम्बाग_heap;
static unsigned char इलिम्बाग_statistic;
static unsigned char no_strdup;
static unsigned char use_sem;
static _Atomic int never_fatal;
#if HAVE_TLS_FUNC
#if defined(_WIN32)
static int no_checking = 0;
static DWORD no_checking_सुसि;
#define NO_CHECKING_CHECK() if (!p) {                                         \
                                  p = (int *) LocalAlloc(LPTR, sizeof(int));  \
                                  if (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_हालागा(no_checking_सुसि, p);            \
                            }
#define NO_CHECKING_GET()   ({ int *p = Tls_Get_हालागा(no_checking_सुसि);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { int *p = Tls_Get_हालागा(no_checking_सुसि);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#else
static int no_checking = 0;
static pthread_key_t no_checking_सुसि;
#define NO_CHECKING_CHECK() if (!p) {                                         \
                                  p = (int *) BOUND_MALLOC(sizeof(int));      \
                                  if (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_सुसि, p);    \
                            }
#define NO_CHECKING_GET()   ({ int *p = pthread_getspecific(no_checking_सुसि); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { int *p = pthread_getspecific(no_checking_सुसि);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#elif HAVE_TLS_VAR
static __thread int no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#else
static _Atomic int no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
static char exec[100];

#if BOUND_STATISTIC
static unsigned long long bound_ptr_add_बिलांग;
static unsigned long long bound_ptr_indir1_बिलांग;
static unsigned long long bound_ptr_indir2_बिलांग;
static unsigned long long bound_ptr_indir4_बिलांग;
static unsigned long long bound_ptr_indir8_बिलांग;
static unsigned long long bound_ptr_indir12_बिलांग;
static unsigned long long bound_ptr_indir16_बिलांग;
static unsigned long long bound_local_new_बिलांग;
static unsigned long long bound_local_delete_बिलांग;
static unsigned long long bound_malloc_बिलांग;
static unsigned long long bound_calloc_बिलांग;
static unsigned long long bound_realloc_बिलांग;
static unsigned long long bound_free_बिलांग;
static unsigned long long bound_memalign_बिलांग;
static unsigned long long bound_mmap_बिलांग;
static unsigned long long bound_munmap_बिलांग;
static unsigned long long bound_alloca_बिलांग;
static unsigned long long bound_setjmp_बिलांग;
static unsigned long long bound_longjmp_बिलांग;
static unsigned long long bound_mempcy_बिलांग;
static unsigned long long bound_memcmp_बिलांग;
static unsigned long long bound_memmove_बिलांग;
static unsigned long long bound_memset_बिलांग;
static unsigned long long bound_strlen_बिलांग;
static unsigned long long bound_strcpy_बिलांग;
static unsigned long long bound_strncpy_बिलांग;
static unsigned long long bound_strcmp_बिलांग;
static unsigned long long bound_strncmp_बिलांग;
static unsigned long long bound_strcat_बिलांग;
static unsigned long long bound_strncat_बिलांग;
static unsigned long long bound_strchr_बिलांग;
static unsigned long long bound_strrchr_बिलांग;
static unsigned long long bound_strdup_बिलांग;
static unsigned long long bound_not_found;
#define INCR_बिलांग(x)          ++x
#else
#define INCR_बिलांग(x)
#endif
#if BOUND_STATISTIC_SPLAY
static unsigned long long bound_splay;
static unsigned long long bound_splay_end;
static unsigned long long bound_splay_इसिंगित;
static unsigned long long bound_splay_delete;
#define INCR_बिलांग_SPLAY(x)    ++x
#else
#define INCR_बिलांग_SPLAY(x)
#endif

int tcc_backtrace(const char *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    do {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } while (0)

#define bound_error(...)            \
    do {                            \
        bound_warning(__VA_ARGS__); \
        if (never_fatal == 0)       \
            exit(255);              \
    } while (0)

#define bounds_loc(fp, ...) \
    do {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } while (0)

static void bound_alloc_error(const char *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

static void bound_not_found_warning(const char *file, const char *function,
                                    void *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
void __bounds_checking (int no_check)
{
#if HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#else
    atomic_fetch_add (&no_checking, no_check);
#endif
}

void __bound_checking_lock(void)
{
    WAIT_SEM ();
}

void __bound_checking_unlock(void)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
void __bound_never_fatal (int neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
void * __bound_ptr_add(void *p, size_t offset)
{
    size_t addr = (size_t)p;

    if (NO_CHECKING_GET())
        return p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_बिलांग(bound_ptr_add_बिलांग);
    if (पुनो_2) {
        addr -= पुनो_2->start;
        if (addr >= पुनो_2->size) {
            addr = (size_t)p;
            पुनो_2 = splay (addr, पुनो_2);
            addr -= पुनो_2->start;
        }
        if (addr >= पुनो_2->size) {
            addr = (size_t)p;
            पुनो_2 = splay_end (addr, पुनो_2);
            addr -= पुनो_2->start;
        }
        if (addr <= पुनो_2->size) {
            if (पुनो_2->is_invalid || addr + offset > पुनो_2->size) {
                POST_SEM ();
                if (इलिम्बाग_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)पुनो_2->start,
                                  (long)(पुनो_2->start + पुनो_2->size - 1));
                if (never_fatal <= 0)
                    return INVALID_POINTER; /* return an invalid pointer */
                return p + offset;
            }
        }
        else if (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_बिलांग(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            return p + offset;
        }
    }
    POST_SEM ();
    return p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
void * __bound_ptr_indir ## dsize (void *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    if (NO_CHECKING_GET())                                                     \
        return p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_बिलांग(bound_ptr_indir ## dsize ## बिलांग);                            \
    if (पुनो_2) {                                                                \
        addr -= पुनो_2->start;                                                   \
        if (addr >= पुनो_2->size) {                                              \
            addr = (size_t)p;                                                  \
            पुनो_2 = splay (addr, पुनो_2);                                         \
            addr -= पुनो_2->start;                                               \
        }                                                                      \
        if (addr >= पुनो_2->size) {                                              \
            addr = (size_t)p;                                                  \
            पुनो_2 = splay_end (addr, पुनो_2);                                     \
            addr -= पुनो_2->start;                                               \
        }                                                                      \
        if (addr <= पुनो_2->size) {                                              \
            if (पुनो_2->is_invalid || addr + offset + dsize > पुनो_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)पुनो_2->start,            \
                              (long)(पुनो_2->start + पुनो_2->size - 1));           \
                if (never_fatal <= 0)                                          \
                    return INVALID_POINTER; /* return an invalid pointer */    \
                return p + offset;                                             \
            }                                                                  \
        }                                                                      \
        else {                                                                 \
            INCR_बिलांग(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            return p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    return p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#if (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic इतुलाक
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
void FASTCALL __bound_local_new(void *p1) 
{
    size_t addr, fp, *p = p1;

    if (NO_CHECKING_GET())
         return;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    while ((addr = p[0])) {
        INCR_बिलांग(bound_local_new_बिलांग);
        पुनो_2 = splay_इसिंगित(addr + fp, p[1], पुनो_2);
        p += 2;
    }
    POST_SEM ();
#if BOUND_DEBUG
    if (इलिम्बाग_calls) {
        p = p1;
        while ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (void *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
void FASTCALL __bound_local_delete(void *p1) 
{
    size_t addr, fp, *p = p1;

    if (NO_CHECKING_GET())
         return;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    while ((addr = p[0])) {
        INCR_बिलांग(bound_local_delete_बिलांग);
        पुनो_2 = splay_delete(addr + fp, पुनो_2);
        p += 2;
    }
    if (alloca_list) {
        alloca_list_type *last = NULL;
        alloca_list_type *cur = alloca_list;

        do {
            if (cur->fp == fp) {
                if (last)
                    last->next = cur->next;
                else
                    alloca_list = cur->next;
                पुनो_2 = splay_delete ((size_t) cur->p, पुनो_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             else {
                 last = cur;
                 cur = cur->next;
             }
        } while (cur);
    }
    if (jmp_list) {
        jmp_list_type *last = NULL;
        jmp_list_type *cur = jmp_list;

        do {
            if (cur->fp == fp) {
                if (last)
                    last->next = cur->next;
                else
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            else {
                last = cur;
                cur = cur->next;
            }
        } while (cur);
    }

    POST_SEM ();
#if BOUND_DEBUG
    if (इलिम्बाग_calls) {
        p = p1;
        while ((addr = p[0])) {
            if (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (void *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
void __bound_new_region(void *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    if (NO_CHECKING_GET())
        return;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (sizeof (alloca_list_type));
    WAIT_SEM ();
    INCR_बिलांग(bound_alloca_बिलांग);
    last = NULL;
    cur = alloca_list;
    while (cur) {
#if defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        int align = 4;
#elif defined(__arm__)
        int align = 8;
#else
        int align = 16;
#endif
        void *cure = (void *)((char *)cur->p + ((cur->size + align) & -align));
        void *pe = (void *)((char *)p + ((size + align) & -align));
        if (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            if (last)
                last->next = cur->next;
            else
                alloca_list = cur->next;
            पुनो_2 = splay_delete((size_t)cur->p, पुनो_2);
            break;
        }
        last = cur;
        cur = cur->next;
    }
    पुनो_2 = splay_इसिंगित((size_t)p, size, पुनो_2);
    if (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    if (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

void __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    void *e = (void *) env;

    if (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_बिलांग(bound_setjmp_बिलांग);
        jl = jmp_list;
        while (jl) {
            if (jl->penv == e)
                break;
            jl = jl->next;
        }
        if (jl == NULL) {
            jl = BOUND_MALLOC (sizeof (jmp_list_type));
            if (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        if (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

static void __bound_long_jump(jmp_buf env, int val, int sig, const char *func)
{
    jmp_list_type *jl;
    void *e;
    BOUND_TID_TYPE tid;

    if (NO_CHECKING_GET() == 0) {
        e = (void *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_बिलांग(bound_longjmp_बिलांग);
        jl = jmp_list;
        while (jl) {
            if (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = NULL;

                while (cur->penv != e || cur->tid != tid) {
                    if (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        if (last)
                            last->next = cur->next;
                        else
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    else {
                        last = cur;
                        cur = cur->next;
                    }
                }
                for (;;) {
                    पुनो *t = पुनो_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    while (t && (t->start < start_fp || t->start > end_fp))
                        if (t->start < start_fp)
                            t = t->कानान;
                        else
                            t = t->कालिवा;
                    if (t == NULL)
                        break;
                    last = NULL;
                    cur = alloca_list;
                    while (cur) {
                         if ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             if (last)
                                 last->next = cur->next;
                             else
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             break;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (void *) t->start);
                    पुनो_2 = splay_delete(t->start, पुनो_2);
                }
                break;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#if !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

void __bound_longjmp(jmp_buf env, int val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#if !defined(_WIN32)
void __bound_siglongjmp(jmp_buf env, int val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#if (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic आलिसिन
#endif

void __bound_init(size_t *p, int mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    if (inited) {
        WAIT_SEM();
        goto add_bounds;
    }
    inited = 1;

#if HAVE_TLS_FUNC
#if defined(_WIN32)
    no_checking_सुसि = TlsAlloc();
    Tls_Set_हालागा(no_checking_सुसि, &no_checking);
#else
    pthread_key_create(&no_checking_सुसि, NULL);
    pthread_setspecific(no_checking_सुसि, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    इलिम्बाग_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != NULL;
    इलिम्बाग_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != NULL;
    इलिम्बाग_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != NULL;
    इलिम्बाग_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != NULL;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != NULL;

    INIT_SEM ();

#if MALLOC_REDIR
    {
        void *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(void **) (&malloc_redir) = dlsym (addr, "malloc");
        if (malloc_redir == NULL) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(void **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(void **) (&calloc_redir) = dlsym (addr, "calloc");
        *(void **) (&free_redir) = dlsym (addr, "free");
        *(void **) (&realloc_redir) = dlsym (addr, "realloc");
        *(void **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        if (malloc_redir == NULL || free_redir == NULL)
            bound_alloc_error ("Cannot redirect malloc/free");
#if HAVE_PTHREAD_CREATE
        *(void **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        if (pthread_create_redir == NULL)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#if HAVE_SIGNAL
        *(void **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        if (signal_redir == NULL)
            bound_alloc_error ("Cannot redirect signal");
#endif
#if HAVE_SIGACTION
        *(void **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        if (sigaction_redir == NULL)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#if HAVE_FORK
        *(void **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        if (fork_redir == NULL)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned char found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        char लिन्या[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        if (fp) {
            memset (exec, 0, sizeof(exec));
            fread (exec, 1, sizeof(exec) - 2, fp);
            if (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        if (fp) {
            while (fgets (लिन्या, sizeof(लिन्या), fp)) {
                if (sscanf (लिन्या, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    break;
                }
                if (strstr (लिन्या,"[heap]"))
                    break;
            }
            fclose (fp);
        }
        if (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#if HAVE_CTYPE
#ifdef __APPLE__
    पुनो_2 = splay_इसिंगित((size_t) &_DefaultRuneLocale,
                        sizeof (_DefaultRuneLocale), पुनो_2);
#else
    /* XXX: Does not work if locale is changed */
    पुनो_2 = splay_इसिंगित((size_t) __ctype_b_loc(),
                        sizeof (unsigned short *), पुनो_2);
    पुनो_2 = splay_इसिंगित((size_t) (*__ctype_b_loc() - 128),
                        384 * sizeof (unsigned short), पुनो_2);
    पुनो_2 = splay_इसिंगित((size_t) __ctype_tolower_loc(),
                        sizeof (__int32_t *), पुनो_2);
    पुनो_2 = splay_इसिंगित((size_t) (*__ctype_tolower_loc() - 128),
                        384 * sizeof (__int32_t), पुनो_2);
    पुनो_2 = splay_इसिंगित((size_t) __ctype_toupper_loc(),
                        sizeof (__int32_t *), पुनो_2);
    पुनो_2 = splay_इसिंगित((size_t) (*__ctype_toupper_loc() - 128),
                        384 * sizeof (__int32_t), पुनो_2);
#endif
#endif
#if HAVE_ERRNO
    पुनो_2 = splay_इसिंगित((size_t) (&errno), sizeof (int), पुनो_2);
#endif

add_bounds:
    if (!p)
        goto no_bounds;

    /* add all static bound check values */
    while (p[0] != 0) {
        पुनो_2 = splay_इसिंगित(p[0], p[1], पुनो_2);
#if BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (void *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

void
#if (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(int argc, char **argv, char **envp)
{
    __bound_init (0, -1);
    if (argc && argv) {
        int i;

        WAIT_SEM ();
        for (i = 0; i < argc; i++)
            पुनो_2 = splay_इसिंगित((size_t) argv[i], strlen (argv[i]) + 1, पुनो_2);
        पुनो_2 = splay_इसिंगित((size_t) argv, (argc + 1) * sizeof(char *), पुनो_2);
        POST_SEM ();
#if BOUND_DEBUG
        if (इलिम्बाग_calls) {
            for (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (int)((argc + 1) * sizeof(char *)));
        }
#endif
    }

    if (envp && *envp) {
        char **p = envp;

        WAIT_SEM ();
        while (*p) {
            पुनो_2 = splay_इसिंगित((size_t) *p, strlen (*p) + 1, पुनो_2);
            ++p;
        }
        पुनो_2 = splay_इसिंगित((size_t) envp, (++p - envp) * sizeof(char *), पुनो_2);
        POST_SEM ();
#if BOUND_DEBUG
        if (इलिम्बाग_calls) {
            p = envp;
            while (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (int)((++p - envp) * sizeof(char *)));
        }
#endif
    }
}

void __attribute__((destructor)) __bound_exit(void)
{
    int i;
    static const char * const alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    if (inited) {
#if !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        if (इलिम्बाग_heap) {
            extern void __libc_freeres (void);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        while (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            पुनो_2 = splay_delete ((size_t) alloca_list->p, पुनो_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        while (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        for (i = 0; i < FREE_REUSE_SIZE; i++) {
            if (free_reuse_list[i]) {
                पुनो_2 = splay_delete ((size_t) free_reuse_list[i], पुनो_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        while (पुनो_2) {
            if (इलिम्बाग_heap && पुनो_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[पुनो_2->type],
                         (unsigned long) पुनो_2->size);
            पुनो_2 = splay_delete (पुनो_2->start, पुनो_2);
        }
#if पुनो_REUSE
        while (पुनो_free_list) {
            पुनो *next = पुनो_free_list->कालिवा;
            BOUND_FREE (पुनो_free_list);
            पुनो_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#if HAVE_TLS_FUNC
#if defined(_WIN32)
        TlsFree(no_checking_सुसि);
#else
        pthread_key_delete(no_checking_सुसि);
#endif
#endif
        inited = 0;
        if (इलिम्बाग_statistic) {
#if BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_बिलांग);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_बिलांग);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_बिलांग);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_बिलांग);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_बिलांग);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_बिलांग);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_बिलांग);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_बिलांग);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_बिलांग);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_बिलांग);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_बिलांग);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_बिलांग);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_बिलांग);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_बिलांग);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_बिलांग);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_बिलांग);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_बिलांग);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_बिलांग);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_बिलांग);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_बिलांग);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_बिलांग);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_बिलांग);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_बिलांग);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_बिलांग);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_बिलांग);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_बिलांग);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_बिलांग);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_बिलांग);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_बिलांग);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_बिलांग);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_बिलांग);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_बिलांग);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_बिलांग);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#if BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_इसिंगित);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

void __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    if (p) {
        WAIT_SEM ();
	while (p[0] != 0) {
	    पुनो_2 = splay_delete(p[0], पुनो_2);
#if BOUND_DEBUG
            if (इलिम्बाग_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (void *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#if HAVE_PTHREAD_CREATE
typedef struct {
    void *(*start_routine) (void *);
    void *arg;
    sigset_t old_mask;
} bound_thread_create_type;

static void *bound_thread_create(void *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    void *retval;
#if HAVE_TLS_FUNC
    int *p = (int *) BOUND_MALLOC(sizeof(int));
  
    if (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_सुसि, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, NULL);
    retval = data->start_routine(data->arg);
#if HAVE_TLS_FUNC
    pthread_setspecific(no_checking_सुसि, NULL);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    return retval;
}

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg)
{
    int retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(sizeof(bound_thread_create_type));
    if (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, NULL);
    return retval;
}
#endif

#if HAVE_SIGNAL || HAVE_SIGACTION
typedef union {
#if HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#if HAVE_SIGACTION
    void (*sig_handler)(int);
    void (*sig_sigaction)(int, siginfo_t *, void *);
#endif
} bound_sig_type;

static unsigned char bound_sig_used[NSIG];
static bound_sig_type bound_sig_data[NSIG];
#endif

#if HAVE_SIGNAL
static void signal_handler(int sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig signal(int signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    if (retval != SIG_ERR) {
        if (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        if (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    return retval;
}
#endif

#if HAVE_SIGACTION
static void sig_handler(int sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

static void sig_sigaction(int sig, siginfo_t *info, void *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{
    int retval;
    struct sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    if (sigaction_redir == NULL)
        __bound_init(0,-1);

    if (act) {
        nact = *act;
        if (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        else
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    else
        retval = sigaction_redir(signum, act, &oact);
    if (retval >= 0) {
        if (bound_sig_used[signum]) {
            if (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            else
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        if (oldact) {
            *oldact = oact;
        }
        if (act) {
            bound_sig_used[signum] = 1;
            if (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            else
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    return retval;
}
#endif

#if HAVE_FORK
pid_t fork(void)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    if (retval == 0)
        INIT_SEM();
    else
        POST_SEM();
    return retval;
}
#endif

#if MALLOC_REDIR
void *malloc(size_t size)
#else
void *__bound_malloc(size_t size, const void *caller)
#endif
{
    void *ptr;
    
#if MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    if (malloc_redir == NULL) {
        __bound_init (0, -1);
        if (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            if (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            return ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    if (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_malloc_बिलांग);

        if (ptr) {
            पुनो_2 = splay_इसिंगित ((size_t) ptr, size ? size : size + 1, पुनो_2);
            if (पुनो_2 && पुनो_2->start == (size_t) ptr)
                पुनो_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    return ptr;
}

#if MALLOC_REDIR
void *memalign(size_t align, size_t size)
#else
void *__bound_memalign(size_t align, size_t size, const void *caller)
#endif
{
    void *ptr;

#if HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#else
    if (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } else {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    if (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_memalign_बिलांग);

        if (ptr) {
            पुनो_2 = splay_इसिंगित((size_t) ptr, size ? size : size + 1, पुनो_2);
            if (पुनो_2 && पुनो_2->start == (size_t) ptr)
                पुनो_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    return ptr;
}

#if MALLOC_REDIR
void free(void *ptr)
#else
void __bound_free(void *ptr, const void *caller)
#endif
{
    size_t addr = (size_t) ptr;
    void *p;

    if (ptr == NULL || पुनो_2 == NULL
#if MALLOC_REDIR
        || ((unsigned char *) ptr >= &initial_pool[0] &&
            (unsigned char *) ptr < &initial_pool[sizeof(initial_pool)])
#endif
        )
        return;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    if (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_free_बिलांग);
        पुनो_2 = splay (addr, पुनो_2);
        if (पुनो_2->start == addr) {
            if (पुनो_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                return;
            }
            पुनो_2->is_invalid = 1;
            memset (ptr, 0x5a, पुनो_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            if (p)
                पुनो_2 = splay_delete((size_t)p, पुनो_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#if MALLOC_REDIR
void *realloc(void *ptr, size_t size)
#else
void *__bound_realloc(void *ptr, size_t size, const void *caller)
#endif
{
    void *new_ptr;

    if (size == 0) {
#if MALLOC_REDIR
        free(ptr);
#else
        __bound_free(ptr, caller);
#endif
        return NULL;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    if (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_realloc_बिलांग);

        if (ptr)
            पुनो_2 = splay_delete ((size_t) ptr, पुनो_2);
        if (new_ptr) {
            पुनो_2 = splay_इसिंगित ((size_t) new_ptr, size ? size : size + 1, पुनो_2);
            if (पुनो_2 && पुनो_2->start == (size_t) new_ptr)
                पुनो_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    return new_ptr;
}

#if MALLOC_REDIR
void *calloc(size_t nmemb, size_t size)
#else
void *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    void *ptr;

    size *= nmemb;
#if MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    if (malloc_redir == NULL) {
        __bound_init (0, -1);
        if (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            if (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            return ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    if (ptr) {
        memset (ptr, 0, size);
        if (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_बिलांग(bound_calloc_बिलांग);
            पुनो_2 = splay_इसिंगित ((size_t) ptr, size ? size : size + 1, पुनो_2);
            if (पुनो_2 && पुनो_2->start == (size_t) ptr)
                पुनो_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    return ptr;
}

#if !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, int prot,
                    int flags, int fd, off_t offset)
{
    void *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    if (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_mmap_बिलांग);
        पुनो_2 = splay_इसिंगित((size_t)result, size, पुनो_2);
        POST_SEM ();
    }
    return result;
}

int __bound_munmap (void *start, size_t size)
{
    int result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    if (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_बिलांग(bound_munmap_बिलांग);
        पुनो_2 = splay_delete ((size_t) start, पुनो_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    return result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
static void __bound_check(const void *p, size_t size, const char *function)
{
    if (size != 0 && __bound_ptr_add((void *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

static int check_overlap (const void *p1, size_t n1,
                          const void *p2, size_t n2,
                          const char *function)
{
    const void *p1e = (const void *) ((const char *) p1 + n1);
    const void *p2e = (const void *) ((const char *) p2 + n2);

    if (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        return never_fatal < 0;
    }
    return 0;
}

void *__bound_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_mempcy_बिलांग);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    if (check_overlap(dest, n, src, n, "memcpy"))
        return dest;
    return memcpy(dest, src, n);
}

int __bound_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    int retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_बिलांग(bound_memcmp_बिलांग);
    for (;;) {
        if ((ssize_t) --n == -1)
            break;
        else if (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (const void *)u1 - s1, "memcmp s1");
    __bound_check(s2, (const void *)u2 - s2, "memcmp s2");
    return retval;
}

void *__bound_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_memmove_बिलांग);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    return memmove(dest, src, n);
}

void *__bound_memset(void *s, int c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_बिलांग(bound_memset_बिलांग);
    __bound_check(s, n, "memset");
    return memset(s, c, n);
}

#if defined(__arm__) && defined(__ARM_EABI__)
void *__bound___aeabi_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_mempcy_बिलांग);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    if (check_overlap(dest, n, src, n, "memcpy"))
        return dest;
    return __aeabi_memcpy(dest, src, n);
}

void *__bound___aeabi_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_memmove_बिलांग);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    return __aeabi_memmove(dest, src, n);
}

void *__bound___aeabi_memmove4(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_memmove_बिलांग);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    return __aeabi_memmove4(dest, src, n);
}

void *__bound___aeabi_memmove8(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_memmove_बिलांग);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    return __aeabi_memmove8(dest, src, n);
}

void *__bound___aeabi_memset(void *s, int c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_बिलांग(bound_memset_बिलांग);
    __bound_check(s, n, "memset");
    return __aeabi_memset(s, c, n);
}
#endif

int __bound_strlen(const char *s)
{
    const char *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_बिलांग(bound_strlen_बिलांग);
    while (*p++);
    __bound_check(s, p - s, "strlen");
    return (p - s) - 1;
}

char *__bound_strcpy(char *dest, const char *src)
{
    size_t len;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_बिलांग(bound_strcpy_बिलांग);
    while (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    if (check_overlap(dest, len, src, len, "strcpy"))
        return dest;
    return strcpy (dest, src);
}

char *__bound_strncpy(char *dest, const char *src, size_t n)
{
    size_t len = n;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_strncpy_बिलांग);
    while (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    if (check_overlap(dest, len, src, len, "strncpy"))
        return dest;
    return strncpy(dest, src, n);
}

int __bound_strcmp(const char *s1, const char *s2)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_बिलांग(bound_strcmp_बिलांग);
    while (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((const char *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((const char *)u2 - s2) + 1, "strcmp s2");
    return *u1 - *u2;
}

int __bound_strncmp(const char *s1, const char *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    int retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_बिलांग(bound_strncmp_बिलांग);
    do {
        if ((ssize_t) --n == -1)
            break;
        else if (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u2;
    } while (*u1++);
    __bound_check(s1, (const char *)u1 - s1, "strncmp s1");
    __bound_check(s2, (const char *)u2 - s2, "strncmp s2");
    return retval;
}

char *__bound_strcat(char *dest, const char *src)
{
    char *r = dest;
    const char *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_बिलांग(bound_strcat_बिलांग);
    while (*dest++);
    while (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    if (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        return dest;
    return strcat(r, s);
}

char *__bound_strncat(char *dest, const char *src, size_t n)
{
    char *r = dest;
    const char *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_बिलांग(bound_strncat_बिलांग);
    while (*dest++);
    while (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    if (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        return dest;
    return strncat(r, s, n);
}

char *__bound_strchr(const char *s, int c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_बिलांग(bound_strchr_बिलांग);
    while (*str) {
        if (*str == ch)
            break;
        ++str;
    }
    __bound_check(s, ((const char *)str - s) + 1, "strchr");
    return *str == ch ? (char *) str : NULL;
}

char *__bound_strrchr(const char *s, int c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_बिलांग(bound_strrchr_बिलांग);
    while (*str++);
    __bound_check(s, (const char *)str - s, "strrchr");
    while (str != (const unsigned char *)s) {
        if (*--str == ch)
            break;
    }
    __bound_check(s, (const char *)str - s, "strrchr");
    return *str == ch ? (char *) str : NULL;
}

char *__bound_strdup(const char *s)
{
    const char *p = s;
    char *new;

    INCR_बिलांग(bound_strdup_बिलांग);
    while (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    if (new) {
        if (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            पुनो_2 = splay_इसिंगित((size_t)new, p - s, पुनो_2);
            if (पुनो_2 && पुनो_2->start == (size_t) new)
                पुनो_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    return new;
}

/*
           An implementation of top-down splaying with sizes
             D. Sleator <sleator@cs.cmu.edu>, January 1994.

  This extends top-down-splay.c to maintain a size field in each node.
  This is the number of nodes in the subtree rooted there.  This makes
  it possible to efficiently compute the rank of a key.  (The rank is
  the number of nodes to the left of the given key.)  It it also
  possible to quickly find the node of a given rank.  Both of these
  operations are illustrated in the code below.  The remainder of this
  introduction is taken from top-down-splay.c.

  "Splay trees", or "self-adjusting search trees" are a simple and
  efficient data structure for storing an ordered set.  The data
  structure consists of a binary tree, with no additional fields.  It
  allows searching, insertion, deletion, deletemin, deletemax,
  splitting, joining, and many other operations, all with amortized
  logarithmic performance.  Since the trees adapt to the sequence of
  requests, their performance on real access patterns is typically even
  better.  Splay trees are described in a number of texts and papers
  [1,2,3,4].

  The code here is adapted from simple top-down splay, at the bottom of
  page 669 of [2].  It can be obtained via anonymous ftp from
  spade.pc.cs.cmu.edu in directory /usr/sleator/public.

  The chief modification here is that the splay operation works even if the
  item being splayed is not in the tree, and even if the tree root of the
  tree is NULL.  So the line:

                              t = splay(i, t);

  causes it to search for item with key i in the tree rooted at t.  If it's
  there, it is splayed to the root.  If it isn't there, then the node put
  at the root is the last one before NULL that would have been reached in a
  normal binary search for i.  (It's a neighbor of i in the tree.)  This
  allows many other operations to be easily implemented, as shown below.

  [1] "Data Structures and Their Algorithms", Lewis and Denenberg,
       Harper Collins, 1991, pp 243-251.
  [2] "Self-adjusting Binary Search Trees" Sleator and Tarjan,
       JACM Volume 32, No 3, July 1985, pp 652-686.
  [3] "Data Structure and Algorithm Analysis", Mark Weiss,
       Benjamin Cummins, 1992, pp 119-130.
  [4] "Data Structures, Algorithms, and Performance", Derick Wood,
       Addison-Wesley, 1993, pp 367-375
*/

/* Code adapted for tcc */

#define compare(start,tstart,tsize) (start < tstart ? -1 : \
                                     start >= tstart+tsize  ? 1 : 0)

static पुनो * splay (size_t addr, पुनो *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    पुनो N, *l, *r, *y;
    int comp;
    
    INCR_बिलांग_SPLAY(bound_splay);
    if (t == NULL) return t;
    N.कालिवा = N.कानान = NULL;
    l = r = &N;
 
    for (;;) {
        comp = compare(addr, t->start, t->size);
        if (comp < 0) {
            y = t->कालिवा;
            if (y == NULL) break;
            if (compare(addr, y->start, y->size) < 0) {
                t->कालिवा = y->कानान;                    /* rotate right */
                y->कानान = t;
                t = y;
                if (t->कालिवा == NULL) break;
            }
            r->कालिवा = t;                               /* link right */
            r = t;
            t = t->कालिवा;
        } else if (comp > 0) {
            y = t->कानान;
            if (y == NULL) break;
            if (compare(addr, y->start, y->size) > 0) {
                t->कानान = y->कालिवा;                    /* rotate left */
                y->कालिवा = t;
                t = y;
                if (t->कानान == NULL) break;
            }
            l->कानान = t;                              /* link left */
            l = t;
            t = t->कानान;
        } else {
            break;
        }
    }
    l->कानान = t->कालिवा;                                /* assemble */
    r->कालिवा = t->कानान;
    t->कालिवा = N.कानान;
    t->कानान = N.कालिवा;

    return t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

static पुनो * splay_end (size_t addr, पुनो *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    पुनो N, *l, *r, *y;
    int comp;
    
    INCR_बिलांग_SPLAY(bound_splay_end);
    if (t == NULL) return t;
    N.कालिवा = N.कानान = NULL;
    l = r = &N;
 
    for (;;) {
        comp = compare_end(addr, t->start + t->size);
        if (comp < 0) {
            y = t->कालिवा;
            if (y == NULL) break;
            if (compare_end(addr, y->start + y->size) < 0) {
                t->कालिवा = y->कानान;                    /* rotate right */
                y->कानान = t;
                t = y;
                if (t->कालिवा == NULL) break;
            }
            r->कालिवा = t;                               /* link right */
            r = t;
            t = t->कालिवा;
        } else if (comp > 0) {
            y = t->कानान;
            if (y == NULL) break;
            if (compare_end(addr, y->start + y->size) > 0) {
                t->कानान = y->कालिवा;                    /* rotate left */
                y->कालिवा = t;
                t = y;
                if (t->कानान == NULL) break;
            }
            l->कानान = t;                              /* link left */
            l = t;
            t = t->कानान;
        } else {
            break;
        }
    }
    l->कानान = t->कालिवा;                                /* assemble */
    r->कालिवा = t->कानान;
    t->कालिवा = N.कानान;
    t->कानान = N.कालिवा;

    return t;
}

static पुनो * splay_इसिंगित(size_t addr, size_t size, पुनो * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    पुनो * new;

    INCR_बिलांग_SPLAY(bound_splay_इसिंगित);
    if (t != NULL) {
        t = splay(addr,t);
        if (compare(addr, t->start, t->size)==0) {
            return t;  /* it's already there */
        }
    }
#if पुनो_REUSE
    if (पुनो_free_list) {
          new = पुनो_free_list;
          पुनो_free_list = new->कालिवा;
    }
    else
#endif
    {
        new = (पुनो *) BOUND_MALLOC (sizeof (पुनो));
    }
    if (new == NULL) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    else {
        if (t == NULL) {
            new->कालिवा = new->कानान = NULL;
        } else if (compare(addr, t->start, t->size) < 0) {
            new->कालिवा = t->कालिवा;
            new->कानान = t;
            t->कालिवा = NULL;
        } else {
            new->कानान = t->कानान;
            new->कालिवा = t;
            t->कानान = NULL;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    return new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

static पुनो * splay_delete(size_t addr, पुनो *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    पुनो * x;

    INCR_बिलांग_SPLAY(bound_splay_delete);
    if (t==NULL) return NULL;
    t = splay(addr,t);
    if (compare_destroy(addr, t->start) == 0) {        /* found it */
        if (t->कालिवा == NULL) {
            x = t->कानान;
        } else {
            x = splay(addr, t->कालिवा);
            x->कानान = t->कानान;
        }
#if पुनो_REUSE
        t->कालिवा = पुनो_free_list;
        पुनो_free_list = t;
#else
        BOUND_FREE(t);
#endif
        return x;
    } else {
        return t;                                      /* It wasn't there */
    }
}

void splay_printtree(पुनो * t, int d)
{
    int i;
    if (t == NULL) return;
    splay_printtree(t->कानान, d+1);
    for (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (void *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->कालिवा, d+1);
}
