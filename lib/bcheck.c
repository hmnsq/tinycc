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

#如果 !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#include <malloc.h>
#endif

#如果 !defined(_WIN32)
#include <unistd.h>
#include <sys/syscall.h>
#endif

#include "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#如果 BOUND_DEBUG
 #define dprintf(a...)         如果 (print_calls) { bounds_loc(a); }
#否则
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#否则
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#否则
# define DLL_EXPORT
#endif

#如果 defined(__FreeBSD__) \
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

#否则

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
#define WAIT_SEM()             如果 (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             如果 (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              如果 (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#elif 0
#include <semaphore.h>
static sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             如果 (use_sem) 当 (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             如果 (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              如果 (use_sem) 当 (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#elif 0
static pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, NULL)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             如果 (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             如果 (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              如果 (use_sem) pthread_mutex_trylock (&bounds_mtx)
#否则
static pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             如果 (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             如果 (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              如果 (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#如果 defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#否则
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#如果 defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#如果 MALLOC_REDIR
static void *(*malloc_redir) (size_t);
static void *(*calloc_redir) (size_t, size_t);
static void (*free_redir) (void *);
static void *(*realloc_redir) (void *, size_t);
static unsigned 整数 pool_index;
static unsigned char __attribute__((aligned(16))) initial_pool[256];
#endif
#如果 HAVE_MEMALIGN
static void *(*memalign_redir) (size_t, size_t);
#endif
#如果 HAVE_PTHREAD_CREATE
static 整数 (*pthread_create_redir) (pthread_t *thread,
                                    const pthread_attr_t *attr,
                                    void *(*start_routine)(void *), void *arg);
#endif
#如果 HAVE_SIGNAL
typedef void (*bound_sig)(整数);
static bound_sig (*signal_redir) (整数 signum, bound_sig handler);
#endif
#如果 HAVE_SIGACTION
static 整数 (*sigaction_redir) (整数 signum, const struct sigaction *act,
                               struct sigaction *oldact);
#endif
#如果 HAVE_FORK
static 整数 (*fork_redir) (void);
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

#如果 defined(_WIN32)
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
#否则
#define BOUND_TID_TYPE		整数
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
void splay_printtree(Tree * t, 整数 d);

/* external interface */
void __bounds_checking (整数 no_check);
void __bound_checking_lock (void);
void __bound_checking_unlock (void);
void __bound_never_fatal (整数 no_check);
DLL_EXPORT void * __bound_ptr_add(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir1(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir2(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir4(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir8(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir12(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir16(void *p, size_t offset);
DLL_EXPORT void FASTCALL __bound_local_new(void *p1);
DLL_EXPORT void FASTCALL __bound_local_delete(void *p1);
void __bound_init(size_t *, 整数);
void __bound_main_arg(整数 argc, char **argv, char **envp);
void __bound_exit(void);
void __bound_exit_dll(size_t *);
#如果 !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, 整数 prot, 整数 flags, 整数 fd,
                    off_t offset);
整数 __bound_munmap (void *start, size_t size);
DLL_EXPORT void __bound_siglongjmp(jmp_buf env, 整数 val);
#endif
DLL_EXPORT void __bound_new_region(void *p, size_t size);
DLL_EXPORT void __bound_setjmp(jmp_buf env);
DLL_EXPORT void __bound_longjmp(jmp_buf env, 整数 val);
DLL_EXPORT void *__bound_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT 整数 __bound_memcmp(const void *s1, const void *s2, size_t size);
DLL_EXPORT void *__bound_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound_memset(void *dst, 整数 c, size_t size);
DLL_EXPORT 整数 __bound_strlen(const char *s);
DLL_EXPORT char *__bound_strcpy(char *dst, const char *src);
DLL_EXPORT char *__bound_strncpy(char *dst, const char *src, size_t n);
DLL_EXPORT 整数 __bound_strcmp(const char *s1, const char *s2);
DLL_EXPORT 整数 __bound_strncmp(const char *s1, const char *s2, size_t n);
DLL_EXPORT char *__bound_strcat(char *dest, const char *src);
DLL_EXPORT char *__bound_strncat(char *dest, const char *src, size_t n);
DLL_EXPORT char *__bound_strchr(const char *string, 整数 ch);
DLL_EXPORT char *__bound_strrchr(const char *string, 整数 ch);
DLL_EXPORT char *__bound_strdup(const char *s);

#如果 defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT void *__bound___aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memset(void *dst, 整数 c, size_t size);
DLL_EXPORT void *__aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memset(void *dst, 整数 c, size_t size);
#endif

#如果 MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#否则
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
static unsigned 整数 free_reuse_index;
static void *free_reuse_list[FREE_REUSE_SIZE];

static Tree *tree = NULL;
#define TREE_REUSE      (1)
#如果 TREE_REUSE
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
static _Atomic 整数 never_fatal;
#如果 HAVE_TLS_FUNC
#如果 defined(_WIN32)
static 整数 no_checking = 0;
static DWORD no_checking_key;
#define NO_CHECKING_CHECK() 如果 (!p) {                                         \
                                  p = (整数 *) LocalAlloc(LPTR, sizeof(整数));  \
                                  如果 (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  TlsSetValue(no_checking_key, p);            \
                            }
#define NO_CHECKING_GET()   ({ 整数 *p = TlsGetValue(no_checking_key);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { 整数 *p = TlsGetValue(no_checking_key);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#否则
static 整数 no_checking = 0;
static pthread_key_t no_checking_key;
#define NO_CHECKING_CHECK() 如果 (!p) {                                         \
                                  p = (整数 *) BOUND_MALLOC(sizeof(整数));      \
                                  如果 (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_key, p);    \
                            }
#define NO_CHECKING_GET()   ({ 整数 *p = pthread_getspecific(no_checking_key); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { 整数 *p = pthread_getspecific(no_checking_key);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#elif HAVE_TLS_VAR
static __thread 整数 no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#否则
static _Atomic 整数 no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
static char exec[100];

#如果 BOUND_STATISTIC
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
#否则
#define INCR_COUNT(x)
#endif
#如果 BOUND_STATISTIC_SPLAY
static unsigned long long bound_splay;
static unsigned long long bound_splay_end;
static unsigned long long bound_splay_insert;
static unsigned long long bound_splay_delete;
#define INCR_COUNT_SPLAY(x)    ++x
#否则
#define INCR_COUNT_SPLAY(x)
#endif

整数 tcc_backtrace(const char *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    do {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } 当 (0)

#define bound_error(...)            \
    do {                            \
        bound_warning(__VA_ARGS__); \
        如果 (never_fatal == 0)       \
            exit(255);              \
    } 当 (0)

#define bounds_loc(fp, ...) \
    do {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } 当 (0)

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
void __bounds_checking (整数 no_check)
{
#如果 HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#否则
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
void __bound_never_fatal (整数 neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
void * __bound_ptr_add(void *p, size_t offset)
{
    size_t addr = (size_t)p;

    如果 (NO_CHECKING_GET())
        返回 p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_COUNT(bound_ptr_add_count);
    如果 (tree) {
        addr -= tree->start;
        如果 (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay (addr, tree);
            addr -= tree->start;
        }
        如果 (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay_end (addr, tree);
            addr -= tree->start;
        }
        如果 (addr <= tree->size) {
            如果 (tree->is_invalid || addr + offset > tree->size) {
                POST_SEM ();
                如果 (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)tree->start,
                                  (long)(tree->start + tree->size - 1));
                如果 (never_fatal <= 0)
                    返回 INVALID_POINTER; /* return an invalid pointer */
                返回 p + offset;
            }
        }
        否则 如果 (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_COUNT(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            返回 p + offset;
        }
    }
    POST_SEM ();
    返回 p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
void * __bound_ptr_indir ## dsize (void *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    如果 (NO_CHECKING_GET())                                                     \
        返回 p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_COUNT(bound_ptr_indir ## dsize ## _count);                            \
    如果 (tree) {                                                                \
        addr -= tree->start;                                                   \
        如果 (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay (addr, tree);                                         \
            addr -= tree->start;                                               \
        }                                                                      \
        如果 (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay_end (addr, tree);                                     \
            addr -= tree->start;                                               \
        }                                                                      \
        如果 (addr <= tree->size) {                                              \
            如果 (tree->is_invalid || addr + offset + dsize > tree->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)tree->start,            \
                              (long)(tree->start + tree->size - 1));           \
                如果 (never_fatal <= 0)                                          \
                    返回 INVALID_POINTER; /* return an invalid pointer */    \
                返回 p + offset;                                             \
            }                                                                  \
        }                                                                      \
        否则 {                                                                 \
            INCR_COUNT(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            返回 p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    返回 p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#如果 (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
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

    如果 (NO_CHECKING_GET())
         返回;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    当 ((addr = p[0])) {
        INCR_COUNT(bound_local_new_count);
        tree = splay_insert(addr + fp, p[1], tree);
        p += 2;
    }
    POST_SEM ();
#如果 BOUND_DEBUG
    如果 (print_calls) {
        p = p1;
        当 ((addr = p[0])) {
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

    如果 (NO_CHECKING_GET())
         返回;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    当 ((addr = p[0])) {
        INCR_COUNT(bound_local_delete_count);
        tree = splay_delete(addr + fp, tree);
        p += 2;
    }
    如果 (alloca_list) {
        alloca_list_type *last = NULL;
        alloca_list_type *cur = alloca_list;

        do {
            如果 (cur->fp == fp) {
                如果 (last)
                    last->next = cur->next;
                否则
                    alloca_list = cur->next;
                tree = splay_delete ((size_t) cur->p, tree);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             否则 {
                 last = cur;
                 cur = cur->next;
             }
        } 当 (cur);
    }
    如果 (jmp_list) {
        jmp_list_type *last = NULL;
        jmp_list_type *cur = jmp_list;

        do {
            如果 (cur->fp == fp) {
                如果 (last)
                    last->next = cur->next;
                否则
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            否则 {
                last = cur;
                cur = cur->next;
            }
        } 当 (cur);
    }

    POST_SEM ();
#如果 BOUND_DEBUG
    如果 (print_calls) {
        p = p1;
        当 ((addr = p[0])) {
            如果 (addr != 1) {
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

    如果 (NO_CHECKING_GET())
        返回;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (sizeof (alloca_list_type));
    WAIT_SEM ();
    INCR_COUNT(bound_alloca_count);
    last = NULL;
    cur = alloca_list;
    当 (cur) {
#如果 defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        整数 align = 4;
#elif defined(__arm__)
        整数 align = 8;
#否则
        整数 align = 16;
#endif
        void *cure = (void *)((char *)cur->p + ((cur->size + align) & -align));
        void *pe = (void *)((char *)p + ((size + align) & -align));
        如果 (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            如果 (last)
                last->next = cur->next;
            否则
                alloca_list = cur->next;
            tree = splay_delete((size_t)cur->p, tree);
            break;
        }
        last = cur;
        cur = cur->next;
    }
    tree = splay_insert((size_t)p, size, tree);
    如果 (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    如果 (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

void __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    void *e = (void *) env;

    如果 (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_COUNT(bound_setjmp_count);
        jl = jmp_list;
        当 (jl) {
            如果 (jl->penv == e)
                break;
            jl = jl->next;
        }
        如果 (jl == NULL) {
            jl = BOUND_MALLOC (sizeof (jmp_list_type));
            如果 (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        如果 (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

static void __bound_long_jump(jmp_buf env, 整数 val, 整数 sig, const char *func)
{
    jmp_list_type *jl;
    void *e;
    BOUND_TID_TYPE tid;

    如果 (NO_CHECKING_GET() == 0) {
        e = (void *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_COUNT(bound_longjmp_count);
        jl = jmp_list;
        当 (jl) {
            如果 (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = NULL;

                当 (cur->penv != e || cur->tid != tid) {
                    如果 (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        如果 (last)
                            last->next = cur->next;
                        否则
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    否则 {
                        last = cur;
                        cur = cur->next;
                    }
                }
                为 (;;) {
                    Tree *t = tree;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    当 (t && (t->start < start_fp || t->start > end_fp))
                        如果 (t->start < start_fp)
                            t = t->right;
                        否则
                            t = t->left;
                    如果 (t == NULL)
                        break;
                    last = NULL;
                    cur = alloca_list;
                    当 (cur) {
                         如果 ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             如果 (last)
                                 last->next = cur->next;
                             否则
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
#如果 !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

void __bound_longjmp(jmp_buf env, 整数 val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#如果 !defined(_WIN32)
void __bound_siglongjmp(jmp_buf env, 整数 val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#如果 (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

void __bound_init(size_t *p, 整数 mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    如果 (inited) {
        WAIT_SEM();
        goto add_bounds;
    }
    inited = 1;

#如果 HAVE_TLS_FUNC
#如果 defined(_WIN32)
    no_checking_key = TlsAlloc();
    TlsSetValue(no_checking_key, &no_checking);
#否则
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

#如果 MALLOC_REDIR
    {
        void *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(void **) (&malloc_redir) = dlsym (addr, "malloc");
        如果 (malloc_redir == NULL) {
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
        如果 (malloc_redir == NULL || free_redir == NULL)
            bound_alloc_error ("Cannot redirect malloc/free");
#如果 HAVE_PTHREAD_CREATE
        *(void **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        如果 (pthread_create_redir == NULL)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#如果 HAVE_SIGNAL
        *(void **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        如果 (signal_redir == NULL)
            bound_alloc_error ("Cannot redirect signal");
#endif
#如果 HAVE_SIGACTION
        *(void **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        如果 (sigaction_redir == NULL)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#如果 HAVE_FORK
        *(void **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        如果 (fork_redir == NULL)
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
        如果 (fp) {
            memset (exec, 0, sizeof(exec));
            fread (exec, 1, sizeof(exec) - 2, fp);
            如果 (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        如果 (fp) {
            当 (fgets (line, sizeof(line), fp)) {
                如果 (sscanf (line, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    break;
                }
                如果 (strstr (line,"[heap]"))
                    break;
            }
            fclose (fp);
        }
        如果 (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#如果 HAVE_CTYPE
#ifdef __APPLE__
    tree = splay_insert((size_t) &_DefaultRuneLocale,
                        sizeof (_DefaultRuneLocale), tree);
#否则
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
#如果 HAVE_ERRNO
    tree = splay_insert((size_t) (&errno), sizeof (整数), tree);
#endif

add_bounds:
    如果 (!p)
        goto no_bounds;

    /* add all static bound check values */
    当 (p[0] != 0) {
        tree = splay_insert(p[0], p[1], tree);
#如果 BOUND_DEBUG
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
#如果 (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(整数 argc, char **argv, char **envp)
{
    __bound_init (0, -1);
    如果 (argc && argv) {
        整数 i;

        WAIT_SEM ();
        为 (i = 0; i < argc; i++)
            tree = splay_insert((size_t) argv[i], strlen (argv[i]) + 1, tree);
        tree = splay_insert((size_t) argv, (argc + 1) * sizeof(char *), tree);
        POST_SEM ();
#如果 BOUND_DEBUG
        如果 (print_calls) {
            为 (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (整数)((argc + 1) * sizeof(char *)));
        }
#endif
    }

    如果 (envp && *envp) {
        char **p = envp;

        WAIT_SEM ();
        当 (*p) {
            tree = splay_insert((size_t) *p, strlen (*p) + 1, tree);
            ++p;
        }
        tree = splay_insert((size_t) envp, (++p - envp) * sizeof(char *), tree);
        POST_SEM ();
#如果 BOUND_DEBUG
        如果 (print_calls) {
            p = envp;
            当 (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (整数)((++p - envp) * sizeof(char *)));
        }
#endif
    }
}

void __attribute__((destructor)) __bound_exit(void)
{
    整数 i;
    static const char * const alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    如果 (inited) {
#如果 !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        如果 (print_heap) {
            extern void __libc_freeres (void);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        当 (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            tree = splay_delete ((size_t) alloca_list->p, tree);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        当 (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        为 (i = 0; i < FREE_REUSE_SIZE; i++) {
            如果 (free_reuse_list[i]) {
                tree = splay_delete ((size_t) free_reuse_list[i], tree);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        当 (tree) {
            如果 (print_heap && tree->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[tree->type],
                         (unsigned long) tree->size);
            tree = splay_delete (tree->start, tree);
        }
#如果 TREE_REUSE
        当 (tree_free_list) {
            Tree *next = tree_free_list->left;
            BOUND_FREE (tree_free_list);
            tree_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#如果 HAVE_TLS_FUNC
#如果 defined(_WIN32)
        TlsFree(no_checking_key);
#否则
        pthread_key_delete(no_checking_key);
#endif
#endif
        inited = 0;
        如果 (print_statistic) {
#如果 BOUND_STATISTIC
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
#如果 BOUND_STATISTIC_SPLAY
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

    如果 (p) {
        WAIT_SEM ();
	当 (p[0] != 0) {
	    tree = splay_delete(p[0], tree);
#如果 BOUND_DEBUG
            如果 (print_calls) {
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

#如果 HAVE_PTHREAD_CREATE
typedef struct {
    void *(*start_routine) (void *);
    void *arg;
    sigset_t old_mask;
} bound_thread_create_type;

static void *bound_thread_create(void *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    void *retval;
#如果 HAVE_TLS_FUNC
    整数 *p = (整数 *) BOUND_MALLOC(sizeof(整数));
  
    如果 (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_key, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, NULL);
    retval = data->start_routine(data->arg);
#如果 HAVE_TLS_FUNC
    pthread_setspecific(no_checking_key, NULL);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    返回 retval;
}

整数 pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg)
{
    整数 retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(sizeof(bound_thread_create_type));
    如果 (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, NULL);
    返回 retval;
}
#endif

#如果 HAVE_SIGNAL || HAVE_SIGACTION
typedef union {
#如果 HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#如果 HAVE_SIGACTION
    void (*sig_handler)(整数);
    void (*sig_sigaction)(整数, siginfo_t *, void *);
#endif
} bound_sig_type;

static unsigned char bound_sig_used[NSIG];
static bound_sig_type bound_sig_data[NSIG];
#endif

#如果 HAVE_SIGNAL
static void signal_handler(整数 sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig signal(整数 signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    如果 (retval != SIG_ERR) {
        如果 (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        如果 (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    返回 retval;
}
#endif

#如果 HAVE_SIGACTION
static void sig_handler(整数 sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

static void sig_sigaction(整数 sig, siginfo_t *info, void *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

整数 sigaction(整数 signum, const struct sigaction *act, struct sigaction *oldact)
{
    整数 retval;
    struct sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    如果 (sigaction_redir == NULL)
        __bound_init(0,-1);

    如果 (act) {
        nact = *act;
        如果 (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        否则
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    否则
        retval = sigaction_redir(signum, act, &oact);
    如果 (retval >= 0) {
        如果 (bound_sig_used[signum]) {
            如果 (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            否则
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        如果 (oldact) {
            *oldact = oact;
        }
        如果 (act) {
            bound_sig_used[signum] = 1;
            如果 (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            否则
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    返回 retval;
}
#endif

#如果 HAVE_FORK
pid_t fork(void)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    如果 (retval == 0)
        INIT_SEM();
    否则
        POST_SEM();
    返回 retval;
}
#endif

#如果 MALLOC_REDIR
void *malloc(size_t size)
#否则
void *__bound_malloc(size_t size, const void *caller)
#endif
{
    void *ptr;
    
#如果 MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    如果 (malloc_redir == NULL) {
        __bound_init (0, -1);
        如果 (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            如果 (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            返回 ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    如果 (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_malloc_count);

        如果 (ptr) {
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            如果 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    返回 ptr;
}

#如果 MALLOC_REDIR
void *memalign(size_t align, size_t size)
#否则
void *__bound_memalign(size_t align, size_t size, const void *caller)
#endif
{
    void *ptr;

#如果 HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#否则
    如果 (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } 否则 {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    如果 (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_memalign_count);

        如果 (ptr) {
            tree = splay_insert((size_t) ptr, size ? size : size + 1, tree);
            如果 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    返回 ptr;
}

#如果 MALLOC_REDIR
void free(void *ptr)
#否则
void __bound_free(void *ptr, const void *caller)
#endif
{
    size_t addr = (size_t) ptr;
    void *p;

    如果 (ptr == NULL || tree == NULL
#如果 MALLOC_REDIR
        || ((unsigned char *) ptr >= &initial_pool[0] &&
            (unsigned char *) ptr < &initial_pool[sizeof(initial_pool)])
#endif
        )
        返回;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    如果 (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_free_count);
        tree = splay (addr, tree);
        如果 (tree->start == addr) {
            如果 (tree->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                返回;
            }
            tree->is_invalid = 1;
            memset (ptr, 0x5a, tree->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            如果 (p)
                tree = splay_delete((size_t)p, tree);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#如果 MALLOC_REDIR
void *realloc(void *ptr, size_t size)
#否则
void *__bound_realloc(void *ptr, size_t size, const void *caller)
#endif
{
    void *new_ptr;

    如果 (size == 0) {
#如果 MALLOC_REDIR
        free(ptr);
#否则
        __bound_free(ptr, caller);
#endif
        返回 NULL;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    如果 (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_realloc_count);

        如果 (ptr)
            tree = splay_delete ((size_t) ptr, tree);
        如果 (new_ptr) {
            tree = splay_insert ((size_t) new_ptr, size ? size : size + 1, tree);
            如果 (tree && tree->start == (size_t) new_ptr)
                tree->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    返回 new_ptr;
}

#如果 MALLOC_REDIR
void *calloc(size_t nmemb, size_t size)
#否则
void *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    void *ptr;

    size *= nmemb;
#如果 MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    如果 (malloc_redir == NULL) {
        __bound_init (0, -1);
        如果 (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            如果 (pool_index >= sizeof (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            返回 ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    如果 (ptr) {
        memset (ptr, 0, size);
        如果 (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_COUNT(bound_calloc_count);
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            如果 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    返回 ptr;
}

#如果 !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, 整数 prot,
                    整数 flags, 整数 fd, off_t offset)
{
    void *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    如果 (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_mmap_count);
        tree = splay_insert((size_t)result, size, tree);
        POST_SEM ();
    }
    返回 result;
}

整数 __bound_munmap (void *start, size_t size)
{
    整数 result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    如果 (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_munmap_count);
        tree = splay_delete ((size_t) start, tree);
        POST_SEM ();
    }
    result = munmap (start, size);
    返回 result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
static void __bound_check(const void *p, size_t size, const char *function)
{
    如果 (size != 0 && __bound_ptr_add((void *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

static 整数 check_overlap (const void *p1, size_t n1,
                          const void *p2, size_t n2,
                          const char *function)
{
    const void *p1e = (const void *) ((const char *) p1 + n1);
    const void *p2e = (const void *) ((const char *) p2 + n2);

    如果 (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        返回 never_fatal < 0;
    }
    返回 0;
}

void *__bound_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    如果 (check_overlap(dest, n, src, n, "memcpy"))
        返回 dest;
    返回 memcpy(dest, src, n);
}

整数 __bound_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    整数 retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_memcmp_count);
    为 (;;) {
        如果 ((ssize_t) --n == -1)
            break;
        否则 如果 (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (const void *)u1 - s1, "memcmp s1");
    __bound_check(s2, (const void *)u2 - s2, "memcmp s2");
    返回 retval;
}

void *__bound_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    返回 memmove(dest, src, n);
}

void *__bound_memset(void *s, 整数 c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    返回 memset(s, c, n);
}

#如果 defined(__arm__) && defined(__ARM_EABI__)
void *__bound___aeabi_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    如果 (check_overlap(dest, n, src, n, "memcpy"))
        返回 dest;
    返回 __aeabi_memcpy(dest, src, n);
}

void *__bound___aeabi_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    返回 __aeabi_memmove(dest, src, n);
}

void *__bound___aeabi_memmove4(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    返回 __aeabi_memmove4(dest, src, n);
}

void *__bound___aeabi_memmove8(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    返回 __aeabi_memmove8(dest, src, n);
}

void *__bound___aeabi_memset(void *s, 整数 c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    返回 __aeabi_memset(s, c, n);
}
#endif

整数 __bound_strlen(const char *s)
{
    const char *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_COUNT(bound_strlen_count);
    当 (*p++);
    __bound_check(s, p - s, "strlen");
    返回 (p - s) - 1;
}

char *__bound_strcpy(char *dest, const char *src)
{
    size_t len;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcpy_count);
    当 (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    如果 (check_overlap(dest, len, src, len, "strcpy"))
        返回 dest;
    返回 strcpy (dest, src);
}

char *__bound_strncpy(char *dest, const char *src, size_t n)
{
    size_t len = n;
    const char *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncpy_count);
    当 (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    如果 (check_overlap(dest, len, src, len, "strncpy"))
        返回 dest;
    返回 strncpy(dest, src, n);
}

整数 __bound_strcmp(const char *s1, const char *s2)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_COUNT(bound_strcmp_count);
    当 (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((const char *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((const char *)u2 - s2) + 1, "strcmp s2");
    返回 *u1 - *u2;
}

整数 __bound_strncmp(const char *s1, const char *s2, size_t n)
{
    const unsigned char *u1 = (const unsigned char *) s1;
    const unsigned char *u2 = (const unsigned char *) s2;
    整数 retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_strncmp_count);
    do {
        如果 ((ssize_t) --n == -1)
            break;
        否则 如果 (*u1 != *u2) {
            retval = *u1++ - *u2++;
            break;
        }
        ++u2;
    } 当 (*u1++);
    __bound_check(s1, (const char *)u1 - s1, "strncmp s1");
    __bound_check(s2, (const char *)u2 - s2, "strncmp s2");
    返回 retval;
}

char *__bound_strcat(char *dest, const char *src)
{
    char *r = dest;
    const char *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcat_count);
    当 (*dest++);
    当 (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    如果 (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        返回 dest;
    返回 strcat(r, s);
}

char *__bound_strncat(char *dest, const char *src, size_t n)
{
    char *r = dest;
    const char *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncat_count);
    当 (*dest++);
    当 (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    如果 (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        返回 dest;
    返回 strncat(r, s, n);
}

char *__bound_strchr(const char *s, 整数 c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strchr_count);
    当 (*str) {
        如果 (*str == ch)
            break;
        ++str;
    }
    __bound_check(s, ((const char *)str - s) + 1, "strchr");
    返回 *str == ch ? (char *) str : NULL;
}

char *__bound_strrchr(const char *s, 整数 c)
{
    const unsigned char *str = (const unsigned char *) s;
    unsigned char ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strrchr_count);
    当 (*str++);
    __bound_check(s, (const char *)str - s, "strrchr");
    当 (str != (const unsigned char *)s) {
        如果 (*--str == ch)
            break;
    }
    __bound_check(s, (const char *)str - s, "strrchr");
    返回 *str == ch ? (char *) str : NULL;
}

char *__bound_strdup(const char *s)
{
    const char *p = s;
    char *new;

    INCR_COUNT(bound_strdup_count);
    当 (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    如果 (new) {
        如果 (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            tree = splay_insert((size_t)new, p - s, tree);
            如果 (tree && tree->start == (size_t) new)
                tree->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    返回 new;
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
    整数 comp;
    
    INCR_COUNT_SPLAY(bound_splay);
    如果 (t == NULL) 返回 t;
    N.left = N.right = NULL;
    l = r = &N;
 
    为 (;;) {
        comp = compare(addr, t->start, t->size);
        如果 (comp < 0) {
            y = t->left;
            如果 (y == NULL) break;
            如果 (compare(addr, y->start, y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                如果 (t->left == NULL) break;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } 否则 如果 (comp > 0) {
            y = t->right;
            如果 (y == NULL) break;
            如果 (compare(addr, y->start, y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                如果 (t->right == NULL) break;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } 否则 {
            break;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    返回 t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

static Tree * splay_end (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    Tree N, *l, *r, *y;
    整数 comp;
    
    INCR_COUNT_SPLAY(bound_splay_end);
    如果 (t == NULL) 返回 t;
    N.left = N.right = NULL;
    l = r = &N;
 
    为 (;;) {
        comp = compare_end(addr, t->start + t->size);
        如果 (comp < 0) {
            y = t->left;
            如果 (y == NULL) break;
            如果 (compare_end(addr, y->start + y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                如果 (t->left == NULL) break;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } 否则 如果 (comp > 0) {
            y = t->right;
            如果 (y == NULL) break;
            如果 (compare_end(addr, y->start + y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                如果 (t->right == NULL) break;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } 否则 {
            break;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    返回 t;
}

static Tree * splay_insert(size_t addr, size_t size, Tree * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    Tree * new;

    INCR_COUNT_SPLAY(bound_splay_insert);
    如果 (t != NULL) {
        t = splay(addr,t);
        如果 (compare(addr, t->start, t->size)==0) {
            返回 t;  /* it's already there */
        }
    }
#如果 TREE_REUSE
    如果 (tree_free_list) {
          new = tree_free_list;
          tree_free_list = new->left;
    }
    否则
#endif
    {
        new = (Tree *) BOUND_MALLOC (sizeof (Tree));
    }
    如果 (new == NULL) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    否则 {
        如果 (t == NULL) {
            new->left = new->right = NULL;
        } 否则 如果 (compare(addr, t->start, t->size) < 0) {
            new->left = t->left;
            new->right = t;
            t->left = NULL;
        } 否则 {
            new->right = t->right;
            new->left = t;
            t->right = NULL;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    返回 new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

static Tree * splay_delete(size_t addr, Tree *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    Tree * x;

    INCR_COUNT_SPLAY(bound_splay_delete);
    如果 (t==NULL) 返回 NULL;
    t = splay(addr,t);
    如果 (compare_destroy(addr, t->start) == 0) {        /* found it */
        如果 (t->left == NULL) {
            x = t->right;
        } 否则 {
            x = splay(addr, t->left);
            x->right = t->right;
        }
#如果 TREE_REUSE
        t->left = tree_free_list;
        tree_free_list = t;
#否则
        BOUND_FREE(t);
#endif
        返回 x;
    } 否则 {
        返回 t;                                      /* It wasn't there */
    }
}

void splay_printtree(Tree * t, 整数 d)
{
    整数 i;
    如果 (t == NULL) 返回;
    splay_printtree(t->right, d+1);
    为 (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (void *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->left, d+1);
}
