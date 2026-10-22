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

#ถ้า !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#include <malloc.h>
#endif

#ถ้า !defined(_WIN32)
#include <unistd.h>
#include <sys/syscall.h>
#endif

#include "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#ถ้า BOUND_DEBUG
 #define dprintf(a...)         ถ้า (print_calls) { bounds_loc(a); }
#มิฉะนั้น
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#มิฉะนั้น
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#มิฉะนั้น
# define DLL_EXPORT
#endif

#ถ้า defined(__FreeBSD__) \
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

#มิฉะนั้น

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
#define WAIT_SEM()             ถ้า (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             ถ้า (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              ถ้า (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#elif 0
#include <semaphore.h>
static sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             ถ้า (use_sem) ขณะ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             ถ้า (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              ถ้า (use_sem) ขณะ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#elif 0
static pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, NULL)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             ถ้า (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             ถ้า (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              ถ้า (use_sem) pthread_mutex_trylock (&bounds_mtx)
#มิฉะนั้น
static pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             ถ้า (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             ถ้า (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              ถ้า (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#ถ้า defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#มิฉะนั้น
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#ถ้า defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#ถ้า MALLOC_REDIR
static void *(*malloc_redir) (size_t);
static void *(*calloc_redir) (size_t, size_t);
static void (*free_redir) (void *);
static void *(*realloc_redir) (void *, size_t);
static unsigned จำนวนเต็ม pool_index;
static unsigned var_na __attribute__((aligned(16))) initial_pool[256];
#endif
#ถ้า HAVE_MEMALIGN
static void *(*memalign_redir) (size_t, size_t);
#endif
#ถ้า HAVE_PTHREAD_CREATE
static จำนวนเต็ม (*pthread_create_redir) (pthread_t *thread,
                                    const pthread_attr_t *attr,
                                    void *(*start_routine)(void *), void *arg);
#endif
#ถ้า HAVE_SIGNAL
typedef void (*bound_sig)(จำนวนเต็ม);
static bound_sig (*signal_redir) (จำนวนเต็ม signum, bound_sig handler);
#endif
#ถ้า HAVE_SIGACTION
static จำนวนเต็ม (*sigaction_redir) (จำนวนเต็ม signum, const sa_nracanaa sigaction *act,
                               sa_nracanaa sigaction *oldact);
#endif
#ถ้า HAVE_FORK
static จำนวนเต็ม (*fork_redir) (void);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((void *)(-2))

typedef sa_nracanaa tree_node Tree;
sa_nracanaa tree_node {
    Tree * left, * right;
    size_t start;
    size_t size;
    unsigned var_na type;
    unsigned var_na is_invalid; /* true if pointers outside region are invalid */
};

typedef sa_nracanaa alloca_list_struct {
    size_t fp;
    void *p;
    size_t size;
    sa_nracanaa alloca_list_struct *next;
} alloca_list_type;

#ถ้า defined(_WIN32)
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
#มิฉะนั้น
#define BOUND_TID_TYPE		จำนวนเต็ม
#define BOUND_GET_TID(id)	id = 0
#endif

typedef sa_nracanaa jmp_list_struct {
    void *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    sa_nracanaa jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
static Tree * splay (size_t addr, Tree *t);
static Tree * splay_end (size_t addr, Tree *t);
static Tree * splay_insert(size_t addr, size_t size, Tree * t);
static Tree * splay_delete(size_t addr, Tree *t);
void splay_printtree(Tree * t, จำนวนเต็ม d);

/* external interface */
void __bounds_checking (จำนวนเต็ม no_check);
void __bound_checking_lock (void);
void __bound_checking_unlock (void);
void __bound_never_fatal (จำนวนเต็ม no_check);
DLL_EXPORT void * __bound_ptr_add(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir1(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir2(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir4(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir8(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir12(void *p, size_t offset);
DLL_EXPORT void * __bound_ptr_indir16(void *p, size_t offset);
DLL_EXPORT void FASTCALL __bound_local_new(void *p1);
DLL_EXPORT void FASTCALL __bound_local_delete(void *p1);
void __bound_init(size_t *, จำนวนเต็ม);
void __bound_main_arg(จำนวนเต็ม argc, var_na **argv, var_na **envp);
void __bound_exit(void);
void __bound_exit_dll(size_t *);
#ถ้า !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, จำนวนเต็ม prot, จำนวนเต็ม flags, จำนวนเต็ม fd,
                    off_t offset);
จำนวนเต็ม __bound_munmap (void *start, size_t size);
DLL_EXPORT void __bound_siglongjmp(jmp_buf env, จำนวนเต็ม val);
#endif
DLL_EXPORT void __bound_new_region(void *p, size_t size);
DLL_EXPORT void __bound_setjmp(jmp_buf env);
DLL_EXPORT void __bound_longjmp(jmp_buf env, จำนวนเต็ม val);
DLL_EXPORT void *__bound_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT จำนวนเต็ม __bound_memcmp(const void *s1, const void *s2, size_t size);
DLL_EXPORT void *__bound_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound_memset(void *dst, จำนวนเต็ม c, size_t size);
DLL_EXPORT จำนวนเต็ม __bound_strlen(const var_na *s);
DLL_EXPORT var_na *__bound_strcpy(var_na *dst, const var_na *src);
DLL_EXPORT var_na *__bound_strncpy(var_na *dst, const var_na *src, size_t n);
DLL_EXPORT จำนวนเต็ม __bound_strcmp(const var_na *s1, const var_na *s2);
DLL_EXPORT จำนวนเต็ม __bound_strncmp(const var_na *s1, const var_na *s2, size_t n);
DLL_EXPORT var_na *__bound_strcat(var_na *dest, const var_na *src);
DLL_EXPORT var_na *__bound_strncat(var_na *dest, const var_na *src, size_t n);
DLL_EXPORT var_na *__bound_strchr(const var_na *string, จำนวนเต็ม ch);
DLL_EXPORT var_na *__bound_strrchr(const var_na *string, จำนวนเต็ม ch);
DLL_EXPORT var_na *__bound_strdup(const var_na *s);

#ถ้า defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT void *__bound___aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__bound___aeabi_memset(void *dst, จำนวนเต็ม c, size_t size);
DLL_EXPORT void *__aeabi_memcpy(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove4(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memmove8(void *dst, const void *src, size_t size);
DLL_EXPORT void *__aeabi_memset(void *dst, จำนวนเต็ม c, size_t size);
#endif

#ถ้า MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#มิฉะนั้น
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
static unsigned จำนวนเต็ม free_reuse_index;
static void *free_reuse_list[FREE_REUSE_SIZE];

static Tree *tree = NULL;
#define TREE_REUSE      (1)
#ถ้า TREE_REUSE
static Tree *tree_free_list;
#endif
static alloca_list_type *alloca_list;
static jmp_list_type *jmp_list;

static unsigned var_na inited;
static unsigned var_na print_warn_ptr_add;
static unsigned var_na print_calls;
static unsigned var_na print_heap;
static unsigned var_na print_statistic;
static unsigned var_na no_strdup;
static unsigned var_na use_sem;
static _Atomic จำนวนเต็ม never_fatal;
#ถ้า HAVE_TLS_FUNC
#ถ้า defined(_WIN32)
static จำนวนเต็ม no_checking = 0;
static DWORD no_checking_key;
#define NO_CHECKING_CHECK() ถ้า (!p) {                                         \
                                  p = (จำนวนเต็ม *) LocalAlloc(LPTR, parimaa_na(จำนวนเต็ม));  \
                                  ถ้า (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  TlsSetValue(no_checking_key, p);            \
                            }
#define NO_CHECKING_GET()   ({ จำนวนเต็ม *p = TlsGetValue(no_checking_key);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { จำนวนเต็ม *p = TlsGetValue(no_checking_key);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#มิฉะนั้น
static จำนวนเต็ม no_checking = 0;
static pthread_key_t no_checking_key;
#define NO_CHECKING_CHECK() ถ้า (!p) {                                         \
                                  p = (จำนวนเต็ม *) BOUND_MALLOC(parimaa_na(จำนวนเต็ม));      \
                                  ถ้า (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_key, p);    \
                            }
#define NO_CHECKING_GET()   ({ จำนวนเต็ม *p = pthread_getspecific(no_checking_key); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { จำนวนเต็ม *p = pthread_getspecific(no_checking_key);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#elif HAVE_TLS_VAR
static __thread จำนวนเต็ม no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#มิฉะนั้น
static _Atomic จำนวนเต็ม no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
static var_na exec[100];

#ถ้า BOUND_STATISTIC
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
#มิฉะนั้น
#define INCR_COUNT(x)
#endif
#ถ้า BOUND_STATISTIC_SPLAY
static unsigned long long bound_splay;
static unsigned long long bound_splay_end;
static unsigned long long bound_splay_insert;
static unsigned long long bound_splay_delete;
#define INCR_COUNT_SPLAY(x)    ++x
#มิฉะนั้น
#define INCR_COUNT_SPLAY(x)
#endif

จำนวนเต็ม tcc_backtrace(const var_na *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    do {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ขณะ (0)

#define bound_error(...)            \
    do {                            \
        bound_warning(__VA_ARGS__); \
        ถ้า (never_fatal == 0)       \
            exit(255);              \
    } ขณะ (0)

#define bounds_loc(fp, ...) \
    do {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ขณะ (0)

static void bound_alloc_error(const var_na *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

static void bound_not_found_warning(const var_na *file, const var_na *function,
                                    void *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
void __bounds_checking (จำนวนเต็ม no_check)
{
#ถ้า HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#มิฉะนั้น
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
void __bound_never_fatal (จำนวนเต็ม neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
void * __bound_ptr_add(void *p, size_t offset)
{
    size_t addr = (size_t)p;

    ถ้า (NO_CHECKING_GET())
        คืน p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_COUNT(bound_ptr_add_count);
    ถ้า (tree) {
        addr -= tree->start;
        ถ้า (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay (addr, tree);
            addr -= tree->start;
        }
        ถ้า (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay_end (addr, tree);
            addr -= tree->start;
        }
        ถ้า (addr <= tree->size) {
            ถ้า (tree->is_invalid || addr + offset > tree->size) {
                POST_SEM ();
                ถ้า (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)tree->start,
                                  (long)(tree->start + tree->size - 1));
                ถ้า (never_fatal <= 0)
                    คืน INVALID_POINTER; /* return an invalid pointer */
                คืน p + offset;
            }
        }
        มิฉะนั้น ถ้า (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_COUNT(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            คืน p + offset;
        }
    }
    POST_SEM ();
    คืน p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
void * __bound_ptr_indir ## dsize (void *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    ถ้า (NO_CHECKING_GET())                                                     \
        คืน p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_COUNT(bound_ptr_indir ## dsize ## _count);                            \
    ถ้า (tree) {                                                                \
        addr -= tree->start;                                                   \
        ถ้า (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay (addr, tree);                                         \
            addr -= tree->start;                                               \
        }                                                                      \
        ถ้า (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay_end (addr, tree);                                     \
            addr -= tree->start;                                               \
        }                                                                      \
        ถ้า (addr <= tree->size) {                                              \
            ถ้า (tree->is_invalid || addr + offset + dsize > tree->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)tree->start,            \
                              (long)(tree->start + tree->size - 1));           \
                ถ้า (never_fatal <= 0)                                          \
                    คืน INVALID_POINTER; /* return an invalid pointer */    \
                คืน p + offset;                                             \
            }                                                                  \
        }                                                                      \
        มิฉะนั้น {                                                                 \
            INCR_COUNT(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            คืน p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    คืน p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ถ้า (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
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

    ถ้า (NO_CHECKING_GET())
         คืน;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    ขณะ ((addr = p[0])) {
        INCR_COUNT(bound_local_new_count);
        tree = splay_insert(addr + fp, p[1], tree);
        p += 2;
    }
    POST_SEM ();
#ถ้า BOUND_DEBUG
    ถ้า (print_calls) {
        p = p1;
        ขณะ ((addr = p[0])) {
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

    ถ้า (NO_CHECKING_GET())
         คืน;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (void *)fp);
    WAIT_SEM ();
    ขณะ ((addr = p[0])) {
        INCR_COUNT(bound_local_delete_count);
        tree = splay_delete(addr + fp, tree);
        p += 2;
    }
    ถ้า (alloca_list) {
        alloca_list_type *last = NULL;
        alloca_list_type *cur = alloca_list;

        do {
            ถ้า (cur->fp == fp) {
                ถ้า (last)
                    last->next = cur->next;
                มิฉะนั้น
                    alloca_list = cur->next;
                tree = splay_delete ((size_t) cur->p, tree);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             มิฉะนั้น {
                 last = cur;
                 cur = cur->next;
             }
        } ขณะ (cur);
    }
    ถ้า (jmp_list) {
        jmp_list_type *last = NULL;
        jmp_list_type *cur = jmp_list;

        do {
            ถ้า (cur->fp == fp) {
                ถ้า (last)
                    last->next = cur->next;
                มิฉะนั้น
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            มิฉะนั้น {
                last = cur;
                cur = cur->next;
            }
        } ขณะ (cur);
    }

    POST_SEM ();
#ถ้า BOUND_DEBUG
    ถ้า (print_calls) {
        p = p1;
        ขณะ ((addr = p[0])) {
            ถ้า (addr != 1) {
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

    ถ้า (NO_CHECKING_GET())
        คืน;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (parimaa_na (alloca_list_type));
    WAIT_SEM ();
    INCR_COUNT(bound_alloca_count);
    last = NULL;
    cur = alloca_list;
    ขณะ (cur) {
#ถ้า defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        จำนวนเต็ม align = 4;
#elif defined(__arm__)
        จำนวนเต็ม align = 8;
#มิฉะนั้น
        จำนวนเต็ม align = 16;
#endif
        void *cure = (void *)((var_na *)cur->p + ((cur->size + align) & -align));
        void *pe = (void *)((var_na *)p + ((size + align) & -align));
        ถ้า (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ถ้า (last)
                last->next = cur->next;
            มิฉะนั้น
                alloca_list = cur->next;
            tree = splay_delete((size_t)cur->p, tree);
            bha_nga;
        }
        last = cur;
        cur = cur->next;
    }
    tree = splay_insert((size_t)p, size, tree);
    ถ้า (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ถ้า (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

void __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    void *e = (void *) env;

    ถ้า (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_COUNT(bound_setjmp_count);
        jl = jmp_list;
        ขณะ (jl) {
            ถ้า (jl->penv == e)
                bha_nga;
            jl = jl->next;
        }
        ถ้า (jl == NULL) {
            jl = BOUND_MALLOC (parimaa_na (jmp_list_type));
            ถ้า (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        ถ้า (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

static void __bound_long_jump(jmp_buf env, จำนวนเต็ม val, จำนวนเต็ม sig, const var_na *func)
{
    jmp_list_type *jl;
    void *e;
    BOUND_TID_TYPE tid;

    ถ้า (NO_CHECKING_GET() == 0) {
        e = (void *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_COUNT(bound_longjmp_count);
        jl = jmp_list;
        ขณะ (jl) {
            ถ้า (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = NULL;

                ขณะ (cur->penv != e || cur->tid != tid) {
                    ถ้า (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ถ้า (last)
                            last->next = cur->next;
                        มิฉะนั้น
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    มิฉะนั้น {
                        last = cur;
                        cur = cur->next;
                    }
                }
                สำหรับ (;;) {
                    Tree *t = tree;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    ขณะ (t && (t->start < start_fp || t->start > end_fp))
                        ถ้า (t->start < start_fp)
                            t = t->right;
                        มิฉะนั้น
                            t = t->left;
                    ถ้า (t == NULL)
                        bha_nga;
                    last = NULL;
                    cur = alloca_list;
                    ขณะ (cur) {
                         ถ้า ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ถ้า (last)
                                 last->next = cur->next;
                             มิฉะนั้น
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             bha_nga;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (void *) t->start);
                    tree = splay_delete(t->start, tree);
                }
                bha_nga;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#ถ้า !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

void __bound_longjmp(jmp_buf env, จำนวนเต็ม val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ถ้า !defined(_WIN32)
void __bound_siglongjmp(jmp_buf env, จำนวนเต็ม val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#ถ้า (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

void __bound_init(size_t *p, จำนวนเต็ม mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    ถ้า (inited) {
        WAIT_SEM();
        goto add_bounds;
    }
    inited = 1;

#ถ้า HAVE_TLS_FUNC
#ถ้า defined(_WIN32)
    no_checking_key = TlsAlloc();
    TlsSetValue(no_checking_key, &no_checking);
#มิฉะนั้น
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

#ถ้า MALLOC_REDIR
    {
        void *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(void **) (&malloc_redir) = dlsym (addr, "malloc");
        ถ้า (malloc_redir == NULL) {
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
        ถ้า (malloc_redir == NULL || free_redir == NULL)
            bound_alloc_error ("Cannot redirect malloc/free");
#ถ้า HAVE_PTHREAD_CREATE
        *(void **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ถ้า (pthread_create_redir == NULL)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#ถ้า HAVE_SIGNAL
        *(void **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ถ้า (signal_redir == NULL)
            bound_alloc_error ("Cannot redirect signal");
#endif
#ถ้า HAVE_SIGACTION
        *(void **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ถ้า (sigaction_redir == NULL)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#ถ้า HAVE_FORK
        *(void **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ถ้า (fork_redir == NULL)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned var_na found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        var_na line[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ถ้า (fp) {
            memset (exec, 0, parimaa_na(exec));
            fread (exec, 1, parimaa_na(exec) - 2, fp);
            ถ้า (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        ถ้า (fp) {
            ขณะ (fgets (line, parimaa_na(line), fp)) {
                ถ้า (sscanf (line, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    bha_nga;
                }
                ถ้า (strstr (line,"[heap]"))
                    bha_nga;
            }
            fclose (fp);
        }
        ถ้า (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#ถ้า HAVE_CTYPE
#ifdef __APPLE__
    tree = splay_insert((size_t) &_DefaultRuneLocale,
                        parimaa_na (_DefaultRuneLocale), tree);
#มิฉะนั้น
    /* XXX: Does not work if locale is changed */
    tree = splay_insert((size_t) __ctype_b_loc(),
                        parimaa_na (unsigned short *), tree);
    tree = splay_insert((size_t) (*__ctype_b_loc() - 128),
                        384 * parimaa_na (unsigned short), tree);
    tree = splay_insert((size_t) __ctype_tolower_loc(),
                        parimaa_na (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_tolower_loc() - 128),
                        384 * parimaa_na (__int32_t), tree);
    tree = splay_insert((size_t) __ctype_toupper_loc(),
                        parimaa_na (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_toupper_loc() - 128),
                        384 * parimaa_na (__int32_t), tree);
#endif
#endif
#ถ้า HAVE_ERRNO
    tree = splay_insert((size_t) (&errno), parimaa_na (จำนวนเต็ม), tree);
#endif

add_bounds:
    ถ้า (!p)
        goto no_bounds;

    /* add all static bound check values */
    ขณะ (p[0] != 0) {
        tree = splay_insert(p[0], p[1], tree);
#ถ้า BOUND_DEBUG
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
#ถ้า (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(จำนวนเต็ม argc, var_na **argv, var_na **envp)
{
    __bound_init (0, -1);
    ถ้า (argc && argv) {
        จำนวนเต็ม i;

        WAIT_SEM ();
        สำหรับ (i = 0; i < argc; i++)
            tree = splay_insert((size_t) argv[i], strlen (argv[i]) + 1, tree);
        tree = splay_insert((size_t) argv, (argc + 1) * parimaa_na(var_na *), tree);
        POST_SEM ();
#ถ้า BOUND_DEBUG
        ถ้า (print_calls) {
            สำหรับ (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (จำนวนเต็ม)((argc + 1) * parimaa_na(var_na *)));
        }
#endif
    }

    ถ้า (envp && *envp) {
        var_na **p = envp;

        WAIT_SEM ();
        ขณะ (*p) {
            tree = splay_insert((size_t) *p, strlen (*p) + 1, tree);
            ++p;
        }
        tree = splay_insert((size_t) envp, (++p - envp) * parimaa_na(var_na *), tree);
        POST_SEM ();
#ถ้า BOUND_DEBUG
        ถ้า (print_calls) {
            p = envp;
            ขณะ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (จำนวนเต็ม)((++p - envp) * parimaa_na(var_na *)));
        }
#endif
    }
}

void __attribute__((destructor)) __bound_exit(void)
{
    จำนวนเต็ม i;
    static const var_na * const alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ถ้า (inited) {
#ถ้า !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ถ้า (print_heap) {
            extern void __libc_freeres (void);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        ขณะ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            tree = splay_delete ((size_t) alloca_list->p, tree);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        ขณะ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        สำหรับ (i = 0; i < FREE_REUSE_SIZE; i++) {
            ถ้า (free_reuse_list[i]) {
                tree = splay_delete ((size_t) free_reuse_list[i], tree);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ขณะ (tree) {
            ถ้า (print_heap && tree->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[tree->type],
                         (unsigned long) tree->size);
            tree = splay_delete (tree->start, tree);
        }
#ถ้า TREE_REUSE
        ขณะ (tree_free_list) {
            Tree *next = tree_free_list->left;
            BOUND_FREE (tree_free_list);
            tree_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#ถ้า HAVE_TLS_FUNC
#ถ้า defined(_WIN32)
        TlsFree(no_checking_key);
#มิฉะนั้น
        pthread_key_delete(no_checking_key);
#endif
#endif
        inited = 0;
        ถ้า (print_statistic) {
#ถ้า BOUND_STATISTIC
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
#ถ้า BOUND_STATISTIC_SPLAY
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

    ถ้า (p) {
        WAIT_SEM ();
	ขณะ (p[0] != 0) {
	    tree = splay_delete(p[0], tree);
#ถ้า BOUND_DEBUG
            ถ้า (print_calls) {
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

#ถ้า HAVE_PTHREAD_CREATE
typedef sa_nracanaa {
    void *(*start_routine) (void *);
    void *arg;
    sigset_t old_mask;
} bound_thread_create_type;

static void *bound_thread_create(void *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    void *retval;
#ถ้า HAVE_TLS_FUNC
    จำนวนเต็ม *p = (จำนวนเต็ม *) BOUND_MALLOC(parimaa_na(จำนวนเต็ม));
  
    ถ้า (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_key, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, NULL);
    retval = data->start_routine(data->arg);
#ถ้า HAVE_TLS_FUNC
    pthread_setspecific(no_checking_key, NULL);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    คืน retval;
}

จำนวนเต็ม pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg)
{
    จำนวนเต็ม retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(parimaa_na(bound_thread_create_type));
    ถ้า (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, NULL);
    คืน retval;
}
#endif

#ถ้า HAVE_SIGNAL || HAVE_SIGACTION
typedef sa_ngha {
#ถ้า HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#ถ้า HAVE_SIGACTION
    void (*sig_handler)(จำนวนเต็ม);
    void (*sig_sigaction)(จำนวนเต็ม, siginfo_t *, void *);
#endif
} bound_sig_type;

static unsigned var_na bound_sig_used[NSIG];
static bound_sig_type bound_sig_data[NSIG];
#endif

#ถ้า HAVE_SIGNAL
static void signal_handler(จำนวนเต็ม sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig sa_nkeeta(จำนวนเต็ม signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ถ้า (retval != SIG_ERR) {
        ถ้า (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        ถ้า (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    คืน retval;
}
#endif

#ถ้า HAVE_SIGACTION
static void sig_handler(จำนวนเต็ม sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

static void sig_sigaction(จำนวนเต็ม sig, siginfo_t *info, void *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

จำนวนเต็ม sigaction(จำนวนเต็ม signum, const sa_nracanaa sigaction *act, sa_nracanaa sigaction *oldact)
{
    จำนวนเต็ม retval;
    sa_nracanaa sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ถ้า (sigaction_redir == NULL)
        __bound_init(0,-1);

    ถ้า (act) {
        nact = *act;
        ถ้า (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        มิฉะนั้น
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    มิฉะนั้น
        retval = sigaction_redir(signum, act, &oact);
    ถ้า (retval >= 0) {
        ถ้า (bound_sig_used[signum]) {
            ถ้า (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            มิฉะนั้น
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        ถ้า (oldact) {
            *oldact = oact;
        }
        ถ้า (act) {
            bound_sig_used[signum] = 1;
            ถ้า (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            มิฉะนั้น
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    คืน retval;
}
#endif

#ถ้า HAVE_FORK
pid_t fork(void)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ถ้า (retval == 0)
        INIT_SEM();
    มิฉะนั้น
        POST_SEM();
    คืน retval;
}
#endif

#ถ้า MALLOC_REDIR
void *malloc(size_t size)
#มิฉะนั้น
void *__bound_malloc(size_t size, const void *caller)
#endif
{
    void *ptr;
    
#ถ้า MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ถ้า (malloc_redir == NULL) {
        __bound_init (0, -1);
        ถ้า (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ถ้า (pool_index >= parimaa_na (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            คืน ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    ถ้า (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_malloc_count);

        ถ้า (ptr) {
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            ถ้า (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    คืน ptr;
}

#ถ้า MALLOC_REDIR
void *memalign(size_t align, size_t size)
#มิฉะนั้น
void *__bound_memalign(size_t align, size_t size, const void *caller)
#endif
{
    void *ptr;

#ถ้า HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#มิฉะนั้น
    ถ้า (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } มิฉะนั้น {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ถ้า (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_memalign_count);

        ถ้า (ptr) {
            tree = splay_insert((size_t) ptr, size ? size : size + 1, tree);
            ถ้า (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    คืน ptr;
}

#ถ้า MALLOC_REDIR
void free(void *ptr)
#มิฉะนั้น
void __bound_free(void *ptr, const void *caller)
#endif
{
    size_t addr = (size_t) ptr;
    void *p;

    ถ้า (ptr == NULL || tree == NULL
#ถ้า MALLOC_REDIR
        || ((unsigned var_na *) ptr >= &initial_pool[0] &&
            (unsigned var_na *) ptr < &initial_pool[parimaa_na(initial_pool)])
#endif
        )
        คืน;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ถ้า (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_free_count);
        tree = splay (addr, tree);
        ถ้า (tree->start == addr) {
            ถ้า (tree->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                คืน;
            }
            tree->is_invalid = 1;
            memset (ptr, 0x5a, tree->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            ถ้า (p)
                tree = splay_delete((size_t)p, tree);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ถ้า MALLOC_REDIR
void *realloc(void *ptr, size_t size)
#มิฉะนั้น
void *__bound_realloc(void *ptr, size_t size, const void *caller)
#endif
{
    void *new_ptr;

    ถ้า (size == 0) {
#ถ้า MALLOC_REDIR
        free(ptr);
#มิฉะนั้น
        __bound_free(ptr, caller);
#endif
        คืน NULL;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    ถ้า (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_realloc_count);

        ถ้า (ptr)
            tree = splay_delete ((size_t) ptr, tree);
        ถ้า (new_ptr) {
            tree = splay_insert ((size_t) new_ptr, size ? size : size + 1, tree);
            ถ้า (tree && tree->start == (size_t) new_ptr)
                tree->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    คืน new_ptr;
}

#ถ้า MALLOC_REDIR
void *calloc(size_t nmemb, size_t size)
#มิฉะนั้น
void *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    void *ptr;

    size *= nmemb;
#ถ้า MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ถ้า (malloc_redir == NULL) {
        __bound_init (0, -1);
        ถ้า (malloc_redir == NULL) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ถ้า (pool_index >= parimaa_na (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            คืน ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ถ้า (ptr) {
        memset (ptr, 0, size);
        ถ้า (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_COUNT(bound_calloc_count);
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            ถ้า (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    คืน ptr;
}

#ถ้า !defined(_WIN32)
void *__bound_mmap (void *start, size_t size, จำนวนเต็ม prot,
                    จำนวนเต็ม flags, จำนวนเต็ม fd, off_t offset)
{
    void *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    ถ้า (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_mmap_count);
        tree = splay_insert((size_t)result, size, tree);
        POST_SEM ();
    }
    คืน result;
}

จำนวนเต็ม __bound_munmap (void *start, size_t size)
{
    จำนวนเต็ม result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    ถ้า (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_munmap_count);
        tree = splay_delete ((size_t) start, tree);
        POST_SEM ();
    }
    result = munmap (start, size);
    คืน result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
static void __bound_check(const void *p, size_t size, const var_na *function)
{
    ถ้า (size != 0 && __bound_ptr_add((void *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

static จำนวนเต็ม check_overlap (const void *p1, size_t n1,
                          const void *p2, size_t n2,
                          const var_na *function)
{
    const void *p1e = (const void *) ((const var_na *) p1 + n1);
    const void *p2e = (const void *) ((const var_na *) p2 + n2);

    ถ้า (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        คืน never_fatal < 0;
    }
    คืน 0;
}

void *__bound_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ถ้า (check_overlap(dest, n, src, n, "memcpy"))
        คืน dest;
    คืน memcpy(dest, src, n);
}

จำนวนเต็ม __bound_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned var_na *u1 = (const unsigned var_na *) s1;
    const unsigned var_na *u2 = (const unsigned var_na *) s2;
    จำนวนเต็ม retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_memcmp_count);
    สำหรับ (;;) {
        ถ้า ((ssize_t) --n == -1)
            bha_nga;
        มิฉะนั้น ถ้า (*u1 != *u2) {
            retval = *u1++ - *u2++;
            bha_nga;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (const void *)u1 - s1, "memcmp s1");
    __bound_check(s2, (const void *)u2 - s2, "memcmp s2");
    คืน retval;
}

void *__bound_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    คืน memmove(dest, src, n);
}

void *__bound_memset(void *s, จำนวนเต็ม c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    คืน memset(s, c, n);
}

#ถ้า defined(__arm__) && defined(__ARM_EABI__)
void *__bound___aeabi_memcpy(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ถ้า (check_overlap(dest, n, src, n, "memcpy"))
        คืน dest;
    คืน __aeabi_memcpy(dest, src, n);
}

void *__bound___aeabi_memmove(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    คืน __aeabi_memmove(dest, src, n);
}

void *__bound___aeabi_memmove4(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    คืน __aeabi_memmove4(dest, src, n);
}

void *__bound___aeabi_memmove8(void *dest, const void *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    คืน __aeabi_memmove8(dest, src, n);
}

void *__bound___aeabi_memset(void *s, จำนวนเต็ม c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    คืน __aeabi_memset(s, c, n);
}
#endif

จำนวนเต็ม __bound_strlen(const var_na *s)
{
    const var_na *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_COUNT(bound_strlen_count);
    ขณะ (*p++);
    __bound_check(s, p - s, "strlen");
    คืน (p - s) - 1;
}

var_na *__bound_strcpy(var_na *dest, const var_na *src)
{
    size_t len;
    const var_na *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcpy_count);
    ขณะ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ถ้า (check_overlap(dest, len, src, len, "strcpy"))
        คืน dest;
    คืน strcpy (dest, src);
}

var_na *__bound_strncpy(var_na *dest, const var_na *src, size_t n)
{
    size_t len = n;
    const var_na *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncpy_count);
    ขณะ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ถ้า (check_overlap(dest, len, src, len, "strncpy"))
        คืน dest;
    คืน strncpy(dest, src, n);
}

จำนวนเต็ม __bound_strcmp(const var_na *s1, const var_na *s2)
{
    const unsigned var_na *u1 = (const unsigned var_na *) s1;
    const unsigned var_na *u2 = (const unsigned var_na *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_COUNT(bound_strcmp_count);
    ขณะ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((const var_na *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((const var_na *)u2 - s2) + 1, "strcmp s2");
    คืน *u1 - *u2;
}

จำนวนเต็ม __bound_strncmp(const var_na *s1, const var_na *s2, size_t n)
{
    const unsigned var_na *u1 = (const unsigned var_na *) s1;
    const unsigned var_na *u2 = (const unsigned var_na *) s2;
    จำนวนเต็ม retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_strncmp_count);
    do {
        ถ้า ((ssize_t) --n == -1)
            bha_nga;
        มิฉะนั้น ถ้า (*u1 != *u2) {
            retval = *u1++ - *u2++;
            bha_nga;
        }
        ++u2;
    } ขณะ (*u1++);
    __bound_check(s1, (const var_na *)u1 - s1, "strncmp s1");
    __bound_check(s2, (const var_na *)u2 - s2, "strncmp s2");
    คืน retval;
}

var_na *__bound_strcat(var_na *dest, const var_na *src)
{
    var_na *r = dest;
    const var_na *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcat_count);
    ขณะ (*dest++);
    ขณะ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ถ้า (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        คืน dest;
    คืน strcat(r, s);
}

var_na *__bound_strncat(var_na *dest, const var_na *src, size_t n)
{
    var_na *r = dest;
    const var_na *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncat_count);
    ขณะ (*dest++);
    ขณะ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ถ้า (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        คืน dest;
    คืน strncat(r, s, n);
}

var_na *__bound_strchr(const var_na *s, จำนวนเต็ม c)
{
    const unsigned var_na *str = (const unsigned var_na *) s;
    unsigned var_na ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strchr_count);
    ขณะ (*str) {
        ถ้า (*str == ch)
            bha_nga;
        ++str;
    }
    __bound_check(s, ((const var_na *)str - s) + 1, "strchr");
    คืน *str == ch ? (var_na *) str : NULL;
}

var_na *__bound_strrchr(const var_na *s, จำนวนเต็ม c)
{
    const unsigned var_na *str = (const unsigned var_na *) s;
    unsigned var_na ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strrchr_count);
    ขณะ (*str++);
    __bound_check(s, (const var_na *)str - s, "strrchr");
    ขณะ (str != (const unsigned var_na *)s) {
        ถ้า (*--str == ch)
            bha_nga;
    }
    __bound_check(s, (const var_na *)str - s, "strrchr");
    คืน *str == ch ? (var_na *) str : NULL;
}

var_na *__bound_strdup(const var_na *s)
{
    const var_na *p = s;
    var_na *new;

    INCR_COUNT(bound_strdup_count);
    ขณะ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    ถ้า (new) {
        ถ้า (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            tree = splay_insert((size_t)new, p - s, tree);
            ถ้า (tree && tree->start == (size_t) new)
                tree->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    คืน new;
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
    จำนวนเต็ม comp;
    
    INCR_COUNT_SPLAY(bound_splay);
    ถ้า (t == NULL) คืน t;
    N.left = N.right = NULL;
    l = r = &N;
 
    สำหรับ (;;) {
        comp = compare(addr, t->start, t->size);
        ถ้า (comp < 0) {
            y = t->left;
            ถ้า (y == NULL) bha_nga;
            ถ้า (compare(addr, y->start, y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                ถ้า (t->left == NULL) bha_nga;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } มิฉะนั้น ถ้า (comp > 0) {
            y = t->right;
            ถ้า (y == NULL) bha_nga;
            ถ้า (compare(addr, y->start, y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                ถ้า (t->right == NULL) bha_nga;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } มิฉะนั้น {
            bha_nga;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    คืน t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

static Tree * splay_end (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    Tree N, *l, *r, *y;
    จำนวนเต็ม comp;
    
    INCR_COUNT_SPLAY(bound_splay_end);
    ถ้า (t == NULL) คืน t;
    N.left = N.right = NULL;
    l = r = &N;
 
    สำหรับ (;;) {
        comp = compare_end(addr, t->start + t->size);
        ถ้า (comp < 0) {
            y = t->left;
            ถ้า (y == NULL) bha_nga;
            ถ้า (compare_end(addr, y->start + y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                ถ้า (t->left == NULL) bha_nga;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } มิฉะนั้น ถ้า (comp > 0) {
            y = t->right;
            ถ้า (y == NULL) bha_nga;
            ถ้า (compare_end(addr, y->start + y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                ถ้า (t->right == NULL) bha_nga;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } มิฉะนั้น {
            bha_nga;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    คืน t;
}

static Tree * splay_insert(size_t addr, size_t size, Tree * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    Tree * new;

    INCR_COUNT_SPLAY(bound_splay_insert);
    ถ้า (t != NULL) {
        t = splay(addr,t);
        ถ้า (compare(addr, t->start, t->size)==0) {
            คืน t;  /* it's already there */
        }
    }
#ถ้า TREE_REUSE
    ถ้า (tree_free_list) {
          new = tree_free_list;
          tree_free_list = new->left;
    }
    มิฉะนั้น
#endif
    {
        new = (Tree *) BOUND_MALLOC (parimaa_na (Tree));
    }
    ถ้า (new == NULL) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    มิฉะนั้น {
        ถ้า (t == NULL) {
            new->left = new->right = NULL;
        } มิฉะนั้น ถ้า (compare(addr, t->start, t->size) < 0) {
            new->left = t->left;
            new->right = t;
            t->left = NULL;
        } มิฉะนั้น {
            new->right = t->right;
            new->left = t;
            t->right = NULL;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    คืน new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

static Tree * splay_delete(size_t addr, Tree *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    Tree * x;

    INCR_COUNT_SPLAY(bound_splay_delete);
    ถ้า (t==NULL) คืน NULL;
    t = splay(addr,t);
    ถ้า (compare_destroy(addr, t->start) == 0) {        /* found it */
        ถ้า (t->left == NULL) {
            x = t->right;
        } มิฉะนั้น {
            x = splay(addr, t->left);
            x->right = t->right;
        }
#ถ้า TREE_REUSE
        t->left = tree_free_list;
        tree_free_list = t;
#มิฉะนั้น
        BOUND_FREE(t);
#endif
        คืน x;
    } มิฉะนั้น {
        คืน t;                                      /* It wasn't there */
    }
}

void splay_printtree(Tree * t, จำนวนเต็ม d)
{
    จำนวนเต็ม i;
    ถ้า (t == NULL) คืน;
    splay_printtree(t->right, d+1);
    สำหรับ (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (void *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->left, d+1);
}
