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

#nếu !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#include <malloc.h>
#endif

#nếu !defined(_WIN32)
#include <unistd.h>
#include <sys/syscall.h>
#endif

#include "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#nếu BOUND_DEBUG
 #define dprintf(a...)         nếu (print_calls) { bounds_loc(a); }
#không_thì
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#không_thì
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#không_thì
# define DLL_EXPORT
#endif

#nếu defined(__FreeBSD__) \
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

#không_thì

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
#define WAIT_SEM()             nếu (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             nếu (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              nếu (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#elif 0
#include <semaphore.h>
static sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             nếu (use_sem) trong_khi (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             nếu (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              nếu (use_sem) trong_khi (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#elif 0
static pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, NULL)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             nếu (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             nếu (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              nếu (use_sem) pthread_mutex_trylock (&bounds_mtx)
#không_thì
static pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             nếu (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             nếu (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              nếu (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#nếu defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#không_thì
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#nếu defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#nếu MALLOC_REDIR
static void *(*malloc_redir) (size_t);
static void *(*calloc_redir) (size_t, size_t);
static void (*free_redir) (void *);
static void *(*realloc_redir) (void *, size_t);
static unsigned số_nguyên pool_index;
static unsigned char __attribute__((aligned(16))) initial_pool[256];
#endif
#nếu HAVE_MEMALIGN
static void *(*memalign_redir) (size_t, size_t);
#endif
#nếu HAVE_PTHREAD_CREATE
static số_nguyên (*pthread_create_redir) (pthread_t *thread,
                                    const pthread_attr_t *attr,
                                    void *(*start_routine)(void *), void *arg);
#endif
#nếu HAVE_SIGNAL
typedef void (*bound_sig)(số_nguyên);
static bound_sig (*signal_redir) (số_nguyên signum, bound_sig handler);
#endif
#nếu HAVE_SIGACTION
static số_nguyên (*sigaction_redir) (số_nguyên signum, const struct sigaction *act,
                               struct sigaction *oldact);
#endif
#nếu HAVE_FORK
static số_nguyên (*fork_redir) (void);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((void *)(-2))

typedef struct tree_node Tree;
struct tree_node {
    Tree * left, * right;
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

#nếu defined(_WIN32)
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
#không_thì
#define BOUND_TID_TYPE		số_nguyên
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
static Tree * splay (size_t addr, Tree *t);
static Tree * splay_end (size_t addr, Tree *t);
static Tree * splay_insert(size_t addr, size_t size, Tree * t);
static Tree * splay_delete(size_t addr, Tree *t);
void splay_printtree(Tree * t, số_nguyên d);

/* external interface */
void __bounds_checking (số_nguyên no_check);
void __bound_checking_lock (void);
void __bound_checking_unlock (void);
void __bound_never_fatal (số_nguyên no_check);
DLL_EXPORT void * __bound_ptr_add(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir1(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir2(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir4(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir8(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir12(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir16(void *p, size_t offset);
DLL_EXPORT void FASTCALL __bound_local_new(void *p1);
DLL_EXPORT void FASTCALL __bound_local_delete(void *p1);
void __bound_init(size_t *, số_nguyên);
void __bound_main_arg(số_nguyên argc, char **argv, char **envp);
void __bound_exit(void);
void __bound_exit_dll(size_t *);
#nếu !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, số_nguyên prot, số_nguyên flags, số_nguyên fd,
                    off_t offset);
số_nguyên __bound_munmap (void *start, size_t size);
DLL_EXPORT void __bound_siglongjmp(jmp_buf env, số_nguyên val);
#endif
DLL_EXPORT void __bound_new_region(void *p, size_t size);
DLL_EXPORT void __bound_setjmp(jmp_buf env);
DLL_EXPORT void __bound_longjmp(jmp_buf env, số_nguyên val);
DLL_EXPORT void *__bound_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT số_nguyên __bound_memcmp(const void *s1, const void *s2, size_t size);
DLL_EXPORT void *__bound_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound_memset(void *dst, số_nguyên c, size_t size);
DLL_EXPORT số_nguyên __bound_strlen(const char *s);
DLL_EXPORT char *__bound_strcpy(char *dst, const char *src);
DLL_EXPORT char *__bound_strncpy(char *dst, const char *src, size_t n);
DLL_EXPORT số_nguyên __bound_strcmp(const char *s1, const char *s2);
DLL_EXPORT số_nguyên __bound_strncmp(const char *s1, const char *s2, size_t n);
DLL_EXPORT char *__bound_strcat(char *dest, const char *src);
DLL_EXPORT char *__bound_strncat(char *dest, const char *src, size_t n);
DLL_EXPORT char *__bound_strchr(const char *string, số_nguyên ch);
DLL_EXPORT char *__bound_strrchr(const char *string, số_nguyên ch);
DLL_EXPORT char *__bound_strdup(const char *s);

#nếu defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT void *__bound___aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memset(void *dst, số_nguyên c, size_t size);
DLL_EXPORT void *__aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memset(void *dst, số_nguyên c, size_t size);
#endif

#nếu MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#không_thì
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
static unsigned số_nguyên free_reuse_index;
static void *free_reuse_list[FREE_REUSE_SIZE];

static Tree *tree = NULL;
#define TREE_REUSE      (1)
#nếu TREE_REUSE
static Tree *tree_free_list;
#endif
static alloca_list_type *alloca_list;
static jmp_list_type *jmp_list;

static unsigned char inited;
static unsigned char print_warn_ptr_add;
static unsigned char print_calls;
static unsigned char print_heap;
static unsigned char print_statistic;
static unsigned char no_strdup;
static unsigned char use_sem;
static _Atomic số_nguyên never_fatal;
#nếu HAVE_TLS_FUNC
#nếu defined(_WIN32)
static số_nguyên no_checking = 0;
static DWORD no_checking_key;
#define NO_CHECKING_CHECK() nếu (!p) {                                         \
                                  p = (số_nguyên *) LocalAlloc(LPTR, sizeof(số_nguyên));  \
                                  nếu (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  TlsSetValue(no_checking_key, p);            \
                            }
#define NO_CHECKING_GET()   ({ số_nguyên *p = TlsGetValue(no_checking_key);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { số_nguyên *p = TlsGetValue(no_checking_key);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#không_thì
static số_nguyên no_checking = 0;
static pthread_key_t no_checking_key;
#define NO_CHECKING_CHECK() nếu (!p) {                                         \
                                  p = (số_nguyên *) BOUND_MALLOC(sizeof(số_nguyên));      \
                                  nếu (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_key, p);    \
                            }
#define NO_CHECKING_GET()   ({ số_nguyên *p = pthread_getspecific(no_checking_key); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { số_nguyên *p = pthread_getspecific(no_checking_key);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#elif HAVE_TLS_VAR
static __thread số_nguyên no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#không_thì
static _Atomic số_nguyên no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
static char exec[100];

#nếu BOUND_STATISTIC
static unsigned long long bound_ptr_add_count;
static unsigned long long bound_ptr_indir1_count;
static unsigned long long bound_ptr_indir2_count;
static unsigned long long bound_ptr_indir4_count;
static unsigned long long bound_ptr_indir8_count;
static unsigned long long bound_ptr_indir12_count;
static unsigned long long bound_ptr_indir16_count;
static unsigned long long bound_local_new_count;
static unsigned long long bound_local_delete_count;
static unsigned long long bound_malloc_count;
static unsigned long long bound_calloc_count;
static unsigned long long bound_realloc_count;
static unsigned long long bound_free_count;
static unsigned long long bound_memalign_count;
static unsigned long long bound_mmap_count;
static unsigned long long bound_munmap_count;
static unsigned long long bound_alloca_count;
static unsigned long long bound_setjmp_count;
static unsigned long long bound_longjmp_count;
static unsigned long long bound_mempcy_count;
static unsigned long long bound_memcmp_count;
static unsigned long long bound_memmove_count;
static unsigned long long bound_memset_count;
static unsigned long long bound_strlen_count;
static unsigned long long bound_strcpy_count;
static unsigned long long bound_strncpy_count;
static unsigned long long bound_strcmp_count;
static unsigned long long bound_strncmp_count;
static unsigned long long bound_strcat_count;
static unsigned long long bound_strncat_count;
static unsigned long long bound_strchr_count;
static unsigned long long bound_strrchr_count;
static unsigned long long bound_strdup_count;
static unsigned long long bound_not_found;
#define INCR_COUNT(x)          ++x
#không_thì
#define INCR_COUNT(x)
#endif
#nếu BOUND_STATISTIC_SPLAY
static unsigned long long bound_splay;
static unsigned long long bound_splay_end;
static unsigned long long bound_splay_insert;
static unsigned long long bound_splay_delete;
#define INCR_COUNT_SPLAY(x)    ++x
#không_thì
#define INCR_COUNT_SPLAY(x)
#endif

số_nguyên tcc_backtrace(const char *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    do {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } trong_khi (0)

#define bound_error(...)            \
    do {                            \
        bound_warning(__VA_ARGS__); \
        nếu (never_fatal == 0)       \
            exit(255);              \
    } trong_khi (0)

#define bounds_loc(fp, ...) \
    do {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } trong_khi (0)

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
void __bounds_checking (số_nguyên no_check)
{
#nếu HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#không_thì
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
void __bound_never_fatal (số_nguyên neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
void * __bound_ptr_add(void *p, size_t offset)
{
    size_t addr = (size_t)p;

    nếu (NO_CHECKING_GET())
        trả_về p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_COUNT(bound_ptr_add_count);
    nếu (tree) {
        addr -= tree->start;
        nếu (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay (addr, tree);
            addr -= tree->start;
        }
        nếu (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay_end (addr, tree);
            addr -= tree->start;
        }
        nếu (addr <= tree->size) {
            nếu (tree->is_invalid || addr + offset > tree->size) {
                POST_SEM ();
                nếu (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)tree->start,
                                  (long)(tree->start + tree->size - 1));
                nếu (never_fatal <= 0)
                    trả_về INVALID_POINTER; /* return an invalid pointer */
                trả_về p + offset;
            }
        }
        không_thì nếu (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_COUNT(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            trả_về p + offset;
        }
    }
    POST_SEM ();
    trả_về p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
void * __bound_ptr_indir ## dsize (void *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    nếu (NO_CHECKING_GET())                                                     \
        trả_về p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_COUNT(bound_ptr_indir ## dsize ## _count);                            \
    nếu (tree) {                                                                \
        addr -= tree->start;                                                   \
        nếu (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay (addr, tree);                                         \
            addr -= tree->start;                                               \
        }                                                                      \
        nếu (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay_end (addr, tree);                                     \
            addr -= tree->start;                                               \
        }                                                                      \
        nếu (addr <= tree->size) {                                              \
            nếu (tree->is_invalid || addr + offset + dsize > tree->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)tree->start,            \
                              (long)(tree->start + tree->size - 1));           \
                nếu (never_fatal <= 0)                                          \
                    trả_về INVALID_POINTER; /* return an invalid pointer */    \
                trả_về p + offset;                                             \
            }                                                                  \
        }                                                                      \
        không_thì {                                                                 \
            INCR_COUNT(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            trả_về p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    trả_về p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#nếu (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic push
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

    nếu (NO_CHECKING_GET())
         trả_về;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    trong_khi ((addr = p[0])) {
        INCR_COUNT(bound_local_new_count);
        tree = splay_insert(addr + fp, p[1], tree);
        p += 2;
    }
    POST_SEM ();
#nếu BOUND_DEBUG
    nếu (print_calls) {
        p = p1;
        trong_khi ((addr = p[0])) {
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

    nếu (NO_CHECKING_GET())
         trả_về;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    trong_khi ((addr = p[0])) {
        INCR_COUNT(bound_local_delete_count);
        tree = splay_delete(addr + fp, tree);
        p += 2;
    }
    nếu (alloca_list) {
        alloca_list_type *last = NULL;
        alloca_list_type *cur = alloca_list;

        do {
            nếu (cur->fp == fp) {
                nếu (last)
                    last->next = cur->next;
                không_thì
                    alloca_list = cur->next;
                tree = splay_delete ((size_t) cur->p, tree);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             không_thì {
                 last = cur;
                 cur = cur->next;
             }
        } trong_khi (cur);
    }
    nếu (jmp_list) {
        jmp_list_type *last = NULL;
        jmp_list_type *cur = jmp_list;

        do {
            nếu (cur->fp == fp) {
                nếu (last)
                    last->next = cur->next;
                không_thì
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            không_thì {
                last = cur;
                cur = cur->next;
            }
        } trong_khi (cur);
    }

    POST_SEM ();
#nếu BOUND_DEBUG
    nếu (print_calls) {
        p = p1;
        trong_khi ((addr = p[0])) {
            nếu (addr != 1) {
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

    nếu (NO_CHECKING_GET())
        trả_về;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (sizeof (alloca_list_type));
    WAIT_SEM ();
    INCR_COUNT(bound_alloca_count);
    last = NULL;
    cur = alloca_list;
    trong_khi (cur) {
#nếu defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        số_nguyên align = 4;
#elif defined(__arm__)
        số_nguyên align = 8;
#không_thì
        số_nguyên align = 16;
#endif
        void *cure = (void *)((char *)cur->p + ((cur->size + align) & -align));
        void *pe = (void *)((char *)p + ((size + align) & -align));
        nếu (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            nếu (last)
                last->next = cur->next;
            không_thì
                alloca_list = cur->next;
            tree = splay_delete((size_t)cur->p, tree);
            break;
        }
        last = cur;
        cur = cur->next;
    }
    tree = splay_insert((size_t)p, size, tree);
    nếu (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    nếu (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

void __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    void *e = (void *) env;

    nếu (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_COUNT(bound_setjmp_count);
        jl = jmp_list;
        trong_khi (jl) {
            nếu (jl->penv == e)
                break;
            jl = jl->next;
        }
        nếu (jl == NULL) {
            jl = BOUND_MALLOC (sizeof (jmp_list_type));
            nếu (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        nếu (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

static void __bound_long_jump(jmp_buf env, số_nguyên val, số_nguyên sig, const char *func)
{
    jmp_list_type *jl;
    void *e;
    BOUND_TID_TYPE tid;

    nếu (NO_CHECKING_GET() == 0) {
        e = (void *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_COUNT(bound_longjmp_count);
        jl = jmp_list;
        trong_khi (jl) {
            nếu (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = NULL;

                trong_khi (cur->penv != e || cur->tid != tid) {
                    nếu (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        nếu (last)
                            last->next = cur->next;
                        không_thì
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    không_thì {
                        last = cur;
                        cur = cur->next;
                    }
                }
                cho (;;) {
                    Tree *t = tree;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    trong_khi (t && (t->start < start_fp || t->start > end_fp))
                        nếu (t->start < start_fp)
                            t = t->right;
                        không_thì
                            t = t->left;
                    nếu (t == NULL)
                        break;
                    last = NULL;
                    cur = alloca_list;
                    trong_khi (cur) {
                         nếu ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             nếu (last)
                                 last->next = cur->next;
                             không_thì
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             break;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (void *) t->start);
                    tree = splay_delete(t->start, tree);
                }
                break;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#nếu !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

void __bound_longjmp(jmp_buf env, số_nguyên val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#nếu !defined(_WIN32)
void __bound_siglongjmp(jmp_buf env, số_nguyên val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#nếu (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

void __bound_init(size_t *p, số_nguyên mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    nếu (inited) {
        WAIT_SEM();
        goto add_bounds;
    }
    inited = 1;

#nếu HAVE_TLS_FUNC
#nếu defined(_WIN32)
    no_checking_key = TlsAlloc();
    TlsSetValue(no_checking_key, &no_checking);
#không_thì
    pthread_key_create(&no_checking_key, NULL);
    pthread_setspecific(no_checking_key, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != NULL;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != NULL;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != NULL;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != NULL;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != NULL;

    INIT_SEM ();

#nếu MALLOC_REDIR
    {
        void *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(void **) (&malloc_redir) = dlsym (addr, "malloc");
        nếu (malloc_redir == NULL) {
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
        nếu (malloc_redir == NULL || free_redir == NULL)
            bound_alloc_error ("Cannot redirect malloc/free");
#nếu HAVE_PTHREAD_CREATE
        *(void **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        nếu (pthread_create_redir == NULL)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#nếu HAVE_SIGNAL
        *(void **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        nếu (signal_redir == NULL)
            bound_alloc_error ("Cannot redirect signal");
#endif
#nếu HAVE_SIGACTION
        *(void **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        nếu (sigaction_redir == NULL)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#nếu HAVE_FORK
        *(void **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        nếu (fork_redir == NULL)
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
        char line[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        nếu (fp) {
            memset (exec, 0, sizeof(exec));
            fread (exec, 1, sizeof(exec) - 2, fp);
            nếu (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        nếu (fp) {
            trong_khi (fgets (line, sizeof(line), fp)) {
                nếu (sscanf (line, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    break;
                }
                nếu (strstr (line,"[heap]"))
                    break;
            }
            fclose (fp);
        }
        nếu (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#nếu HAVE_CTYPE
#ifdef __APPLE__
    tree = splay_insert((size_t) &_DefaultRuneLocale,
                        sizeof (_DefaultRuneLocale), tree);
#không_thì
    /* XXX: Does not work if locale is changed */
    tree = splay_insert((size_t) __ctype_b_loc(),
                        sizeof (unsigned short *), tree);
    tree = splay_insert((size_t) (*__ctype_b_loc() - 128),
                        384 * sizeof (unsigned short), tree);
    tree = splay_insert((size_t) __ctype_tolower_loc(),
                        sizeof (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_tolower_loc() - 128),
                        384 * sizeof (__int32_t), tree);
    tree = splay_insert((size_t) __ctype_toupper_loc(),
                        sizeof (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_toupper_loc() - 128),
                        384 * sizeof (__int32_t), tree);
#endif
#endif
#nếu HAVE_ERRNO
    tree = splay_insert((size_t) (&errno), sizeof (số_nguyên), tree);
#endif

add_bounds:
    nếu (!p)
        goto no_bounds;

    /* add all static bound check values */
    trong_khi (p[0] != 0) {
        tree = splay_insert(p[0], p[1], tree);
#nếu BOUND_DEBUG
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
#nếu (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(số_nguyên argc, char **argv, char **envp)
{
    __bound_init (0, -1);
    nếu (argc && argv) {
        số_nguyên i;

        WAIT_SEM ();
        cho (i = 0; i < argc; i++)
            tree = splay_insert((size_t) argv[i], strlen (argv[i]) + 1, tree);
        tree = splay_insert((size_t) argv, (argc + 1) * sizeof(char *), tree);
        POST_SEM ();
#nếu BOUND_DEBUG
        nếu (print_calls) {
            cho (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (số_nguyên)((argc + 1) * sizeof(char *)));
        }
#endif
    }

    nếu (envp && *envp) {
        char **p = envp;

        WAIT_SEM ();
        trong_khi (*p) {
            tree = splay_insert((size_t) *p, strlen (*p) + 1, tree);
            ++p;
        }
        tree = splay_insert((size_t) envp, (++p - envp) * sizeof(char *), tree);
        POST_SEM ();
#nếu BOUND_DEBUG
        nếu (print_calls) {
            p = envp;
            trong_khi (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (số_nguyên)((++p - envp) * sizeof(char *)));
        }
#endif
    }
}

void __attribute__((destructor)) __bound_exit(void)
{
    số_nguyên i;
    static const char * const alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    nếu (inited) {
#nếu !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        nếu (print_heap) {
            extern void __libc_freeres (void);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        trong_khi (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            tree = splay_delete ((size_t) alloca_list->p, tree);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        trong_khi (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        cho (i = 0; i < FREE_REUSE_SIZE; i++) {
            nếu (free_reuse_list[i]) {
                tree = splay_delete ((size_t) free_reuse_list[i], tree);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        trong_khi (tree) {
            nếu (print_heap && tree->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[tree->type],
                         (unsigned long) tree->size);
            tree = splay_delete (tree->start, tree);
        }
#nếu TREE_REUSE
        trong_khi (tree_free_list) {
            Tree *next = tree_free_list->left;
            BOUND_FREE (tree_free_list);
            tree_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#nếu HAVE_TLS_FUNC
#nếu defined(_WIN32)
        TlsFree(no_checking_key);
#không_thì
        pthread_key_delete(no_checking_key);
#endif
#endif
        inited = 0;
        nếu (print_statistic) {
#nếu BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_count);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_count);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_count);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_count);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_count);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_count);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_count);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_count);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_count);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_count);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_count);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_count);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_count);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_count);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_count);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_count);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_count);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_count);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_count);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_count);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_count);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_count);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_count);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_count);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_count);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_count);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_count);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_count);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_count);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_count);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_count);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_count);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_count);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#nếu BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_insert);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

void __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    nếu (p) {
        WAIT_SEM ();
	trong_khi (p[0] != 0) {
	    tree = splay_delete(p[0], tree);
#nếu BOUND_DEBUG
            nếu (print_calls) {
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

#nếu HAVE_PTHREAD_CREATE
typedef struct {
    void *(*start_routine) (void *);
    void *arg;
    sigset_t old_mask;
} bound_thread_create_type;

static void *bound_thread_create(void *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    void *retval;
#nếu HAVE_TLS_FUNC
    số_nguyên *p = (số_nguyên *) BOUND_MALLOC(sizeof(số_nguyên));
  
    nếu (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_key, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, NULL);
    retval = data->start_routine(data->arg);
#nếu HAVE_TLS_FUNC
    pthread_setspecific(no_checking_key, NULL);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    trả_về retval;
}

số_nguyên pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg)
{
    số_nguyên retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(sizeof(bound_thread_create_type));
    nếu (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, NULL);
    trả_về retval;
}
#endif

#nếu HAVE_SIGNAL || HAVE_SIGACTION
typedef union {
#nếu HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#nếu HAVE_SIGACTION
    void (*sig_handler)(số_nguyên);
    void (*sig_sigaction)(số_nguyên, siginfo_t *, void *);
#endif
} bound_sig_type;

static unsigned char bound_sig_used[NSIG];
static bound_sig_type bound_sig_data[NSIG];
#endif

#nếu HAVE_SIGNAL
static void signal_handler(số_nguyên sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig signal(số_nguyên signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    nếu (retval != SIG_ERR) {
        nếu (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        nếu (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    trả_về retval;
}
#endif

#nếu HAVE_SIGACTION
static void sig_handler(số_nguyên sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

static void sig_sigaction(số_nguyên sig, siginfo_t *info, void *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

số_nguyên sigaction(số_nguyên signum, const struct sigaction *act, struct sigaction *oldact)
{
    số_nguyên retval;
    struct sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    nếu (sigaction_redir == NULL)
        __bound_init(0,-1);

    nếu (act) {
        nact = *act;
        nếu (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        không_thì
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    không_thì
        retval = sigaction_redir(signum, act, &oact);
    nếu (retval >= 0) {
        nếu (bound_sig_used[signum]) {
            nếu (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            không_thì
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        nếu (oldact) {
            *oldact = oact;
        }
        nếu (act) {
            bound_sig_used[signum] = 1;
            nếu (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            không_thì
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    trả_về retval;
}
#endif

#nếu HAVE_FORK
pid_t fork(void)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    nếu (retval == 0)
        INIT_SEM();
    không_thì
        POST_SEM();
    trả_về retval;
}
#endif

#nếu MALLOC_REDIR
void *malloc(size_t size)
#không_thì
void *__bound_malloc(size_t size, const void *caller)
#endif
{
    void *ptr;
    
#nếu MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    nếu (malloc_redir == NULL) {
        __bound_init (0, -1);
        nếu (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            nếu (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            trả_về ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    nếu (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_malloc_count);

        nếu (ptr) {
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            nếu (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    trả_về ptr;
}

#nếu MALLOC_REDIR
void *memalign(size_t align, size_t size)
#không_thì
void *__bound_memalign(size_t align, size_t size, const void *caller)
#endif
{
    void *ptr;

#nếu HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#không_thì
    nếu (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } không_thì {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    nếu (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_memalign_count);

        nếu (ptr) {
            tree = splay_insert((size_t) ptr, size ? size : size + 1, tree);
            nếu (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    trả_về ptr;
}

#nếu MALLOC_REDIR
void free(void *ptr)
#không_thì
void __bound_free(void *ptr, const void *caller)
#endif
{
    size_t addr = (size_t) ptr;
    void *p;

    nếu (ptr == NULL || tree == NULL
#nếu MALLOC_REDIR
        || ((unsigned char *) ptr >= &initial_pool[0] &&
            (unsigned char *) ptr < &initial_pool[sizeof(initial_pool)])
#endif
        )
        trả_về;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    nếu (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_free_count);
        tree = splay (addr, tree);
        nếu (tree->start == addr) {
            nếu (tree->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                trả_về;
            }
            tree->is_invalid = 1;
            memset (ptr, 0x5a, tree->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            nếu (p)
                tree = splay_delete((size_t)p, tree);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#nếu MALLOC_REDIR
void *realloc(void *ptr, size_t size)
#không_thì
void *__bound_realloc(void *ptr, size_t size, const void *caller)
#endif
{
    void *new_ptr;

    nếu (size == 0) {
#nếu MALLOC_REDIR
        free(ptr);
#không_thì
        __bound_free(ptr, caller);
#endif
        trả_về NULL;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    nếu (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_realloc_count);

        nếu (ptr)
            tree = splay_delete ((size_t) ptr, tree);
        nếu (new_ptr) {
            tree = splay_insert ((size_t) new_ptr, size ? size : size + 1, tree);
            nếu (tree && tree->start == (size_t) new_ptr)
                tree->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    trả_về new_ptr;
}

#nếu MALLOC_REDIR
void *calloc(size_t nmemb, size_t size)
#không_thì
void *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    void *ptr;

    size *= nmemb;
#nếu MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    nếu (malloc_redir == NULL) {
        __bound_init (0, -1);
        nếu (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            nếu (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            trả_về ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    nếu (ptr) {
        memset (ptr, 0, size);
        nếu (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_COUNT(bound_calloc_count);
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            nếu (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    trả_về ptr;
}

#nếu !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, số_nguyên prot,
                    số_nguyên flags, số_nguyên fd, off_t offset)
{
    void *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    nếu (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_mmap_count);
        tree = splay_insert((size_t)result, size, tree);
        POST_SEM ();
    }
    trả_về result;
}

số_nguyên __bound_munmap (void *start, size_t size)
{
    số_nguyên result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    nếu (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_munmap_count);
        tree = splay_delete ((size_t) start, tree);
        POST_SEM ();
    }
    result = munmap (start, size);
    trả_về result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
static void __bound_check(const void *p, size_t size, const char *function)
{
    nếu (size != 0 && __bound_ptr_add((void *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

static số_nguyên check_overlap (const void *p1, size_t n1,
                          const void *p2, size_t n2,
                          const char *function)
{
    const void *p1e = (const void *) ((const char *) p1 + n1);
    const void *p2e = (const void *) ((const char *) p2 + n2);

    nếu (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        trả_về never_fatal < 0;
    }
    trả_về 0;
}

void *__bound_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    nếu (check_overlap(dest, n, src, n, "memcpy"))
        trả_về dest;
    trả_về memcpy(dest, src, n);
}

số_nguyên __bound_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    số_nguyên retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_memcmp_count);
    cho (;;) {
        nếu ((ssize_t) --n == -1)
            break;
        không_thì nếu (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (const void *)u1 - s1, "memcmp s1");
    __bound_check(s2, (const void *)u2 - s2, "memcmp s2");
    trả_về retval;
}

void *__bound_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    trả_về memmove(dest, src, n);
}

void *__bound_memset(void *s, số_nguyên c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    trả_về memset(s, c, n);
}

#nếu defined(__arm__) && defined(__ARM_EABI__)
void *__bound___aeabi_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    nếu (check_overlap(dest, n, src, n, "memcpy"))
        trả_về dest;
    trả_về __aeabi_memcpy(dest, src, n);
}

void *__bound___aeabi_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    trả_về __aeabi_memmove(dest, src, n);
}

void *__bound___aeabi_memmove4(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    trả_về __aeabi_memmove4(dest, src, n);
}

void *__bound___aeabi_memmove8(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    trả_về __aeabi_memmove8(dest, src, n);
}

void *__bound___aeabi_memset(void *s, số_nguyên c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    trả_về __aeabi_memset(s, c, n);
}
#endif

số_nguyên __bound_strlen(const char *s)
{
    const char *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_COUNT(bound_strlen_count);
    trong_khi (*p++);
    __bound_check(s, p - s, "strlen");
    trả_về (p - s) - 1;
}

char *__bound_strcpy(char *dest, const char *src)
{
    size_t len;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcpy_count);
    trong_khi (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    nếu (check_overlap(dest, len, src, len, "strcpy"))
        trả_về dest;
    trả_về strcpy (dest, src);
}

char *__bound_strncpy(char *dest, const char *src, size_t n)
{
    size_t len = n;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncpy_count);
    trong_khi (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    nếu (check_overlap(dest, len, src, len, "strncpy"))
        trả_về dest;
    trả_về strncpy(dest, src, n);
}

số_nguyên __bound_strcmp(const char *s1, const char *s2)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_COUNT(bound_strcmp_count);
    trong_khi (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((const char *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((const char *)u2 - s2) + 1, "strcmp s2");
    trả_về *u1 - *u2;
}

số_nguyên __bound_strncmp(const char *s1, const char *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    số_nguyên retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_strncmp_count);
    do {
        nếu ((ssize_t) --n == -1)
            break;
        không_thì nếu (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u2;
    } trong_khi (*u1++);
    __bound_check(s1, (const char *)u1 - s1, "strncmp s1");
    __bound_check(s2, (const char *)u2 - s2, "strncmp s2");
    trả_về retval;
}

char *__bound_strcat(char *dest, const char *src)
{
    char *r = dest;
    const char *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcat_count);
    trong_khi (*dest++);
    trong_khi (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    nếu (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        trả_về dest;
    trả_về strcat(r, s);
}

char *__bound_strncat(char *dest, const char *src, size_t n)
{
    char *r = dest;
    const char *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncat_count);
    trong_khi (*dest++);
    trong_khi (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    nếu (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        trả_về dest;
    trả_về strncat(r, s, n);
}

char *__bound_strchr(const char *s, số_nguyên c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strchr_count);
    trong_khi (*str) {
        nếu (*str == ch)
            break;
        ++str;
    }
    __bound_check(s, ((const char *)str - s) + 1, "strchr");
    trả_về *str == ch ? (char *) str : NULL;
}

char *__bound_strrchr(const char *s, số_nguyên c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strrchr_count);
    trong_khi (*str++);
    __bound_check(s, (const char *)str - s, "strrchr");
    trong_khi (str != (const unsigned char *)s) {
        nếu (*--str == ch)
            break;
    }
    __bound_check(s, (const char *)str - s, "strrchr");
    trả_về *str == ch ? (char *) str : NULL;
}

char *__bound_strdup(const char *s)
{
    const char *p = s;
    char *new;

    INCR_COUNT(bound_strdup_count);
    trong_khi (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    nếu (new) {
        nếu (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            tree = splay_insert((size_t)new, p - s, tree);
            nếu (tree && tree->start == (size_t) new)
                tree->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    trả_về new;
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

static Tree * splay (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    Tree N, *l, *r, *y;
    số_nguyên comp;
    
    INCR_COUNT_SPLAY(bound_splay);
    nếu (t == NULL) trả_về t;
    N.left = N.right = NULL;
    l = r = &N;
 
    cho (;;) {
        comp = compare(addr, t->start, t->size);
        nếu (comp < 0) {
            y = t->left;
            nếu (y == NULL) break;
            nếu (compare(addr, y->start, y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                nếu (t->left == NULL) break;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } không_thì nếu (comp > 0) {
            y = t->right;
            nếu (y == NULL) break;
            nếu (compare(addr, y->start, y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                nếu (t->right == NULL) break;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } không_thì {
            break;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    trả_về t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

static Tree * splay_end (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    Tree N, *l, *r, *y;
    số_nguyên comp;
    
    INCR_COUNT_SPLAY(bound_splay_end);
    nếu (t == NULL) trả_về t;
    N.left = N.right = NULL;
    l = r = &N;
 
    cho (;;) {
        comp = compare_end(addr, t->start + t->size);
        nếu (comp < 0) {
            y = t->left;
            nếu (y == NULL) break;
            nếu (compare_end(addr, y->start + y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                nếu (t->left == NULL) break;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } không_thì nếu (comp > 0) {
            y = t->right;
            nếu (y == NULL) break;
            nếu (compare_end(addr, y->start + y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                nếu (t->right == NULL) break;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } không_thì {
            break;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    trả_về t;
}

static Tree * splay_insert(size_t addr, size_t size, Tree * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    Tree * new;

    INCR_COUNT_SPLAY(bound_splay_insert);
    nếu (t != NULL) {
        t = splay(addr,t);
        nếu (compare(addr, t->start, t->size)==0) {
            trả_về t;  /* it's already there */
        }
    }
#nếu TREE_REUSE
    nếu (tree_free_list) {
          new = tree_free_list;
          tree_free_list = new->left;
    }
    không_thì
#endif
    {
        new = (Tree *) BOUND_MALLOC (sizeof (Tree));
    }
    nếu (new == NULL) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    không_thì {
        nếu (t == NULL) {
            new->left = new->right = NULL;
        } không_thì nếu (compare(addr, t->start, t->size) < 0) {
            new->left = t->left;
            new->right = t;
            t->left = NULL;
        } không_thì {
            new->right = t->right;
            new->left = t;
            t->right = NULL;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    trả_về new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

static Tree * splay_delete(size_t addr, Tree *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    Tree * x;

    INCR_COUNT_SPLAY(bound_splay_delete);
    nếu (t==NULL) trả_về NULL;
    t = splay(addr,t);
    nếu (compare_destroy(addr, t->start) == 0) {        /* found it */
        nếu (t->left == NULL) {
            x = t->right;
        } không_thì {
            x = splay(addr, t->left);
            x->right = t->right;
        }
#nếu TREE_REUSE
        t->left = tree_free_list;
        tree_free_list = t;
#không_thì
        BOUND_FREE(t);
#endif
        trả_về x;
    } không_thì {
        trả_về t;                                      /* It wasn't there */
    }
}

void splay_printtree(Tree * t, số_nguyên d)
{
    số_nguyên i;
    nếu (t == NULL) trả_về;
    splay_printtree(t->right, d+1);
    cho (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (void *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->left, d+1);
}
