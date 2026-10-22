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
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <stdarg.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#ضمن <stdatomic.h>

#ܐܢ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ضمن <malloc.h>
#endif

#ܐܢ !defined(_WIN32)
#ضمن <unistd.h>
#ضمن <sys/syscall.h>
#endif

#ضمن "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#ܐܢ BOUND_DEBUG
 #define dprintf(a...)         ܐܢ (print_calls) { bounds_loc(a); }
#ܐܚܪܢܐ
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#ܐܚܪܢܐ
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ܐܚܪܢܐ
# define DLL_EXPORT
#endif

#ܐܢ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ضمن <sys/mman.h>
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

#وإلاإذا defined(_WIN32)

#ضمن <windows.h>
#ضمن <signal.h>
ساكن CRITICAL_SECTION bounds_sem;
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

#ܐܚܪܢܐ

#define __USE_GNU              /* get RTLD_NEXT */
#ضمن <sys/mman.h>
#ضمن <ctype.h>
#ضمن <pthread.h>
#ضمن <dlfcn.h>
#ضمن <errno.h>
#ضمن <signal.h>
#ifdef __APPLE__
#ضمن <dispatch/dispatch.h>
ساكن dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             ܐܢ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             ܐܢ (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              ܐܢ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#وإلاإذا 0
#ضمن <semaphore.h>
ساكن sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             ܐܢ (use_sem) ܟܡܐ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             ܐܢ (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              ܐܢ (use_sem) ܟܡܐ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وإلاإذا 0
ساكن pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, عدم)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             ܐܢ (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             ܐܢ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              ܐܢ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ܐܚܪܢܐ
ساكن pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             ܐܢ (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             ܐܢ (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              ܐܢ (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#ܐܢ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#ܐܚܪܢܐ
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#ܐܢ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#ܐܢ MALLOC_REDIR
ساكن فراغ *(*malloc_redir) (size_t);
ساكن فراغ *(*calloc_redir) (size_t, size_t);
ساكن فراغ (*free_redir) (فراغ *);
ساكن فراغ *(*realloc_redir) (فراغ *, size_t);
ساكن unsigned صحيح pool_index;
ساكن unsigned حرف __attribute__((aligned(16))) initial_pool[256];
#endif
#ܐܢ HAVE_MEMALIGN
ساكن فراغ *(*memalign_redir) (size_t, size_t);
#endif
#ܐܢ HAVE_PTHREAD_CREATE
ساكن صحيح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    فراغ *(*start_routine)(فراغ *), فراغ *arg);
#endif
#ܐܢ HAVE_SIGNAL
تعريفنوع فراغ (*bound_sig)(صحيح);
ساكن bound_sig (*signal_redir) (صحيح signum, bound_sig handler);
#endif
#ܐܢ HAVE_SIGACTION
ساكن صحيح (*sigaction_redir) (صحيح signum, ثابت بنية sigaction *act,
                               بنية sigaction *oldact);
#endif
#ܐܢ HAVE_FORK
ساكن صحيح (*fork_redir) (فراغ);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((فراغ *)(-2))

تعريفنوع بنية tree_node Tree;
بنية tree_node {
    Tree * left, * right;
    size_t start;
    size_t size;
    unsigned حرف type;
    unsigned حرف is_invalid; /* true if pointers outside region are invalid */
};

تعريفنوع بنية alloca_list_struct {
    size_t fp;
    فراغ *p;
    size_t size;
    بنية alloca_list_struct *next;
} alloca_list_type;

#ܐܢ defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#وإلاإذا defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#وإلاإذا defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#وإلاإذا  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#وإلاإذا defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ܐܚܪܢܐ
#define BOUND_TID_TYPE		صحيح
#define BOUND_GET_TID(id)	id = 0
#endif

تعريفنوع بنية jmp_list_struct {
    فراغ *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    بنية jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
ساكن Tree * splay (size_t addr, Tree *t);
ساكن Tree * splay_end (size_t addr, Tree *t);
ساكن Tree * splay_insert(size_t addr, size_t size, Tree * t);
ساكن Tree * splay_delete(size_t addr, Tree *t);
فراغ splay_printtree(Tree * t, صحيح d);

/* external interface */
فراغ __bounds_checking (صحيح no_check);
فراغ __bound_checking_lock (فراغ);
فراغ __bound_checking_unlock (فراغ);
فراغ __bound_never_fatal (صحيح no_check);
DLL_EXPORT فراغ * __bound_ptr_add(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir1(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir2(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir4(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir8(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir12(فراغ *p, size_t offset);
DLL_EXPORT فراغ * __bound_ptr_indir16(فراغ *p, size_t offset);
DLL_EXPORT فراغ FASTCALL __bound_local_new(فراغ *p1);
DLL_EXPORT فراغ FASTCALL __bound_local_delete(فراغ *p1);
فراغ __bound_init(size_t *, صحيح);
فراغ __bound_main_arg(صحيح argc, حرف **argv, حرف **envp);
فراغ __bound_exit(فراغ);
فراغ __bound_exit_dll(size_t *);
#ܐܢ !defined(_WIN32)
فراغ *__bound_mmap (فراغ *start, size_t size, صحيح prot, صحيح flags, صحيح fd,
                    off_t offset);
صحيح __bound_munmap (فراغ *start, size_t size);
DLL_EXPORT فراغ __bound_siglongjmp(jmp_buf env, صحيح val);
#endif
DLL_EXPORT فراغ __bound_new_region(فراغ *p, size_t size);
DLL_EXPORT فراغ __bound_setjmp(jmp_buf env);
DLL_EXPORT فراغ __bound_longjmp(jmp_buf env, صحيح val);
DLL_EXPORT فراغ *__bound_memcpy(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, size_t size);
DLL_EXPORT فراغ *__bound_memmove(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__bound_memset(فراغ *dst, صحيح c, size_t size);
DLL_EXPORT صحيح __bound_strlen(ثابت حرف *s);
DLL_EXPORT حرف *__bound_strcpy(حرف *dst, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncpy(حرف *dst, ثابت حرف *src, size_t n);
DLL_EXPORT صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2);
DLL_EXPORT صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, size_t n);
DLL_EXPORT حرف *__bound_strcat(حرف *dest, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncat(حرف *dest, ثابت حرف *src, size_t n);
DLL_EXPORT حرف *__bound_strchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strrchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strdup(ثابت حرف *s);

#ܐܢ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT فراغ *__bound___aeabi_memcpy(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__bound___aeabi_memmove(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__bound___aeabi_memmove4(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__bound___aeabi_memmove8(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__bound___aeabi_memset(فراغ *dst, صحيح c, size_t size);
DLL_EXPORT فراغ *__aeabi_memcpy(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__aeabi_memmove(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__aeabi_memmove4(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__aeabi_memmove8(فراغ *dst, ثابت فراغ *src, size_t size);
DLL_EXPORT فراغ *__aeabi_memset(فراغ *dst, صحيح c, size_t size);
#endif

#ܐܢ MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ܐܚܪܢܐ
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            حرر(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT فراغ *__bound_malloc(size_t size, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_memalign(size_t align, size_t size, ثابت فراغ *caller);
DLL_EXPORT فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_realloc(فراغ *ptr, size_t size, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
ساكن unsigned صحيح free_reuse_index;
ساكن فراغ *free_reuse_list[FREE_REUSE_SIZE];

ساكن Tree *tree = عدم;
#define TREE_REUSE      (1)
#ܐܢ TREE_REUSE
ساكن Tree *tree_free_list;
#endif
ساكن alloca_list_type *alloca_list;
ساكن jmp_list_type *jmp_list;

ساكن unsigned حرف inited;
ساكن unsigned حرف print_warn_ptr_add;
ساكن unsigned حرف print_calls;
ساكن unsigned حرف print_heap;
ساكن unsigned حرف print_statistic;
ساكن unsigned حرف no_strdup;
ساكن unsigned حرف use_sem;
ساكن _Atomic صحيح never_fatal;
#ܐܢ HAVE_TLS_FUNC
#ܐܢ defined(_WIN32)
ساكن صحيح no_checking = 0;
ساكن DWORD no_checking_key;
#define NO_CHECKING_CHECK() ܐܢ (!p) {                                         \
                                  p = (صحيح *) LocalAlloc(LPTR, حجم(صحيح));  \
                                  ܐܢ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  TlsSetValue(no_checking_key, p);            \
                            }
#define NO_CHECKING_GET()   ({ صحيح *p = TlsGetValue(no_checking_key);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { صحيح *p = TlsGetValue(no_checking_key);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ܐܚܪܢܐ
ساكن صحيح no_checking = 0;
ساكن pthread_key_t no_checking_key;
#define NO_CHECKING_CHECK() ܐܢ (!p) {                                         \
                                  p = (صحيح *) BOUND_MALLOC(حجم(صحيح));      \
                                  ܐܢ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_key, p);    \
                            }
#define NO_CHECKING_GET()   ({ صحيح *p = pthread_getspecific(no_checking_key); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { صحيح *p = pthread_getspecific(no_checking_key);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#وإلاإذا HAVE_TLS_VAR
ساكن __thread صحيح no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#ܐܚܪܢܐ
ساكن _Atomic صحيح no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
ساكن حرف exec[100];

#ܐܢ BOUND_STATISTIC
ساكن unsigned long long bound_ptr_add_count;
ساكن unsigned long long bound_ptr_indir1_count;
ساكن unsigned long long bound_ptr_indir2_count;
ساكن unsigned long long bound_ptr_indir4_count;
ساكن unsigned long long bound_ptr_indir8_count;
ساكن unsigned long long bound_ptr_indir12_count;
ساكن unsigned long long bound_ptr_indir16_count;
ساكن unsigned long long bound_local_new_count;
ساكن unsigned long long bound_local_delete_count;
ساكن unsigned long long bound_malloc_count;
ساكن unsigned long long bound_calloc_count;
ساكن unsigned long long bound_realloc_count;
ساكن unsigned long long bound_free_count;
ساكن unsigned long long bound_memalign_count;
ساكن unsigned long long bound_mmap_count;
ساكن unsigned long long bound_munmap_count;
ساكن unsigned long long bound_alloca_count;
ساكن unsigned long long bound_setjmp_count;
ساكن unsigned long long bound_longjmp_count;
ساكن unsigned long long bound_mempcy_count;
ساكن unsigned long long bound_memcmp_count;
ساكن unsigned long long bound_memmove_count;
ساكن unsigned long long bound_memset_count;
ساكن unsigned long long bound_strlen_count;
ساكن unsigned long long bound_strcpy_count;
ساكن unsigned long long bound_strncpy_count;
ساكن unsigned long long bound_strcmp_count;
ساكن unsigned long long bound_strncmp_count;
ساكن unsigned long long bound_strcat_count;
ساكن unsigned long long bound_strncat_count;
ساكن unsigned long long bound_strchr_count;
ساكن unsigned long long bound_strrchr_count;
ساكن unsigned long long bound_strdup_count;
ساكن unsigned long long bound_not_found;
#define INCR_COUNT(x)          ++x
#ܐܚܪܢܐ
#define INCR_COUNT(x)
#endif
#ܐܢ BOUND_STATISTIC_SPLAY
ساكن unsigned long long bound_splay;
ساكن unsigned long long bound_splay_end;
ساكن unsigned long long bound_splay_insert;
ساكن unsigned long long bound_splay_delete;
#define INCR_COUNT_SPLAY(x)    ++x
#ܐܚܪܢܐ
#define INCR_COUNT_SPLAY(x)
#endif

صحيح tcc_backtrace(ثابت حرف *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    ܥܒܕ {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ܟܡܐ (0)

#define bound_error(...)            \
    ܥܒܕ {                            \
        bound_warning(__VA_ARGS__); \
        ܐܢ (never_fatal == 0)       \
            exit(255);              \
    } ܟܡܐ (0)

#define bounds_loc(fp, ...) \
    ܥܒܕ {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ܟܡܐ (0)

ساكن فراغ bound_alloc_error(ثابت حرف *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

ساكن فراغ bound_not_found_warning(ثابت حرف *file, ثابت حرف *function,
                                    فراغ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
فراغ __bounds_checking (صحيح no_check)
{
#ܐܢ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#ܐܚܪܢܐ
    atomic_fetch_add (&no_checking, no_check);
#endif
}

فراغ __bound_checking_lock(فراغ)
{
    WAIT_SEM ();
}

فراغ __bound_checking_unlock(فراغ)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
فراغ __bound_never_fatal (صحيح neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
فراغ * __bound_ptr_add(فراغ *p, size_t offset)
{
    size_t addr = (size_t)p;

    ܐܢ (NO_CHECKING_GET())
        ܦܢܐ p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_COUNT(bound_ptr_add_count);
    ܐܢ (tree) {
        addr -= tree->start;
        ܐܢ (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay (addr, tree);
            addr -= tree->start;
        }
        ܐܢ (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay_end (addr, tree);
            addr -= tree->start;
        }
        ܐܢ (addr <= tree->size) {
            ܐܢ (tree->is_invalid || addr + offset > tree->size) {
                POST_SEM ();
                ܐܢ (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)tree->start,
                                  (long)(tree->start + tree->size - 1));
                ܐܢ (never_fatal <= 0)
                    ܦܢܐ INVALID_POINTER; /* return an invalid pointer */
                ܦܢܐ p + offset;
            }
        }
        ܐܚܪܢܐ ܐܢ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_COUNT(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            ܦܢܐ p + offset;
        }
    }
    POST_SEM ();
    ܦܢܐ p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
فراغ * __bound_ptr_indir ## dsize (فراغ *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    ܐܢ (NO_CHECKING_GET())                                                     \
        ܦܢܐ p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_COUNT(bound_ptr_indir ## dsize ## _count);                            \
    ܐܢ (tree) {                                                                \
        addr -= tree->start;                                                   \
        ܐܢ (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay (addr, tree);                                         \
            addr -= tree->start;                                               \
        }                                                                      \
        ܐܢ (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay_end (addr, tree);                                     \
            addr -= tree->start;                                               \
        }                                                                      \
        ܐܢ (addr <= tree->size) {                                              \
            ܐܢ (tree->is_invalid || addr + offset + dsize > tree->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)tree->start,            \
                              (long)(tree->start + tree->size - 1));           \
                ܐܢ (never_fatal <= 0)                                          \
                    ܦܢܐ INVALID_POINTER; /* return an invalid pointer */    \
                ܦܢܐ p + offset;                                             \
            }                                                                  \
        }                                                                      \
        ܐܚܪܢܐ {                                                                 \
            INCR_COUNT(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            ܦܢܐ p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ܦܢܐ p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ܐܢ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
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
فراغ FASTCALL __bound_local_new(فراغ *p1) 
{
    size_t addr, fp, *p = p1;

    ܐܢ (NO_CHECKING_GET())
         ܦܢܐ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    ܟܡܐ ((addr = p[0])) {
        INCR_COUNT(bound_local_new_count);
        tree = splay_insert(addr + fp, p[1], tree);
        p += 2;
    }
    POST_SEM ();
#ܐܢ BOUND_DEBUG
    ܐܢ (print_calls) {
        p = p1;
        ܟܡܐ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (فراغ *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
فراغ FASTCALL __bound_local_delete(فراغ *p1) 
{
    size_t addr, fp, *p = p1;

    ܐܢ (NO_CHECKING_GET())
         ܦܢܐ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    ܟܡܐ ((addr = p[0])) {
        INCR_COUNT(bound_local_delete_count);
        tree = splay_delete(addr + fp, tree);
        p += 2;
    }
    ܐܢ (alloca_list) {
        alloca_list_type *last = عدم;
        alloca_list_type *cur = alloca_list;

        ܥܒܕ {
            ܐܢ (cur->fp == fp) {
                ܐܢ (last)
                    last->next = cur->next;
                ܐܚܪܢܐ
                    alloca_list = cur->next;
                tree = splay_delete ((size_t) cur->p, tree);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             ܐܚܪܢܐ {
                 last = cur;
                 cur = cur->next;
             }
        } ܟܡܐ (cur);
    }
    ܐܢ (jmp_list) {
        jmp_list_type *last = عدم;
        jmp_list_type *cur = jmp_list;

        ܥܒܕ {
            ܐܢ (cur->fp == fp) {
                ܐܢ (last)
                    last->next = cur->next;
                ܐܚܪܢܐ
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            ܐܚܪܢܐ {
                last = cur;
                cur = cur->next;
            }
        } ܟܡܐ (cur);
    }

    POST_SEM ();
#ܐܢ BOUND_DEBUG
    ܐܢ (print_calls) {
        p = p1;
        ܟܡܐ ((addr = p[0])) {
            ܐܢ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (فراغ *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
فراغ __bound_new_region(فراغ *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    ܐܢ (NO_CHECKING_GET())
        ܦܢܐ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (حجم (alloca_list_type));
    WAIT_SEM ();
    INCR_COUNT(bound_alloca_count);
    last = عدم;
    cur = alloca_list;
    ܟܡܐ (cur) {
#ܐܢ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحيح align = 4;
#وإلاإذا defined(__arm__)
        صحيح align = 8;
#ܐܚܪܢܐ
        صحيح align = 16;
#endif
        فراغ *cure = (فراغ *)((حرف *)cur->p + ((cur->size + align) & -align));
        فراغ *pe = (فراغ *)((حرف *)p + ((size + align) & -align));
        ܐܢ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ܐܢ (last)
                last->next = cur->next;
            ܐܚܪܢܐ
                alloca_list = cur->next;
            tree = splay_delete((size_t)cur->p, tree);
            اكسر;
        }
        last = cur;
        cur = cur->next;
    }
    tree = splay_insert((size_t)p, size, tree);
    ܐܢ (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ܐܢ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

فراغ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    فراغ *e = (فراغ *) env;

    ܐܢ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_COUNT(bound_setjmp_count);
        jl = jmp_list;
        ܟܡܐ (jl) {
            ܐܢ (jl->penv == e)
                اكسر;
            jl = jl->next;
        }
        ܐܢ (jl == عدم) {
            jl = BOUND_MALLOC (حجم (jmp_list_type));
            ܐܢ (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        ܐܢ (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ساكن فراغ __bound_long_jump(jmp_buf env, صحيح val, صحيح sig, ثابت حرف *func)
{
    jmp_list_type *jl;
    فراغ *e;
    BOUND_TID_TYPE tid;

    ܐܢ (NO_CHECKING_GET() == 0) {
        e = (فراغ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_COUNT(bound_longjmp_count);
        jl = jmp_list;
        ܟܡܐ (jl) {
            ܐܢ (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = عدم;

                ܟܡܐ (cur->penv != e || cur->tid != tid) {
                    ܐܢ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ܐܢ (last)
                            last->next = cur->next;
                        ܐܚܪܢܐ
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    ܐܚܪܢܐ {
                        last = cur;
                        cur = cur->next;
                    }
                }
                لكل (;;) {
                    Tree *t = tree;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    ܟܡܐ (t && (t->start < start_fp || t->start > end_fp))
                        ܐܢ (t->start < start_fp)
                            t = t->right;
                        ܐܚܪܢܐ
                            t = t->left;
                    ܐܢ (t == عدم)
                        اكسر;
                    last = عدم;
                    cur = alloca_list;
                    ܟܡܐ (cur) {
                         ܐܢ ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ܐܢ (last)
                                 last->next = cur->next;
                             ܐܚܪܢܐ
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             اكسر;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (فراغ *) t->start);
                    tree = splay_delete(t->start, tree);
                }
                اكسر;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#ܐܢ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

فراغ __bound_longjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ܐܢ !defined(_WIN32)
فراغ __bound_siglongjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#ܐܢ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

فراغ __bound_init(size_t *p, صحيح mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    ܐܢ (inited) {
        WAIT_SEM();
        اذهب add_bounds;
    }
    inited = 1;

#ܐܢ HAVE_TLS_FUNC
#ܐܢ defined(_WIN32)
    no_checking_key = TlsAlloc();
    TlsSetValue(no_checking_key, &no_checking);
#ܐܚܪܢܐ
    pthread_key_create(&no_checking_key, عدم);
    pthread_setspecific(no_checking_key, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != عدم;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != عدم;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != عدم;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != عدم;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != عدم;

    INIT_SEM ();

#ܐܢ MALLOC_REDIR
    {
        فراغ *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(فراغ **) (&malloc_redir) = dlsym (addr, "malloc");
        ܐܢ (malloc_redir == عدم) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(فراغ **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(فراغ **) (&calloc_redir) = dlsym (addr, "calloc");
        *(فراغ **) (&free_redir) = dlsym (addr, "free");
        *(فراغ **) (&realloc_redir) = dlsym (addr, "realloc");
        *(فراغ **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        ܐܢ (malloc_redir == عدم || free_redir == عدم)
            bound_alloc_error ("Cannot redirect malloc/free");
#ܐܢ HAVE_PTHREAD_CREATE
        *(فراغ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ܐܢ (pthread_create_redir == عدم)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#ܐܢ HAVE_SIGNAL
        *(فراغ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ܐܢ (signal_redir == عدم)
            bound_alloc_error ("Cannot redirect signal");
#endif
#ܐܢ HAVE_SIGACTION
        *(فراغ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ܐܢ (sigaction_redir == عدم)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#ܐܢ HAVE_FORK
        *(فراغ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ܐܢ (fork_redir == عدم)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned حرف found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        حرف line[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ܐܢ (fp) {
            memset (exec, 0, حجم(exec));
            fread (exec, 1, حجم(exec) - 2, fp);
            ܐܢ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        ܐܢ (fp) {
            ܟܡܐ (fgets (line, حجم(line), fp)) {
                ܐܢ (sscanf (line, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    اكسر;
                }
                ܐܢ (strstr (line,"[heap]"))
                    اكسر;
            }
            fclose (fp);
        }
        ܐܢ (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#ܐܢ HAVE_CTYPE
#ifdef __APPLE__
    tree = splay_insert((size_t) &_DefaultRuneLocale,
                        حجم (_DefaultRuneLocale), tree);
#ܐܚܪܢܐ
    /* XXX: Does not work if locale is changed */
    tree = splay_insert((size_t) __ctype_b_loc(),
                        حجم (unsigned short *), tree);
    tree = splay_insert((size_t) (*__ctype_b_loc() - 128),
                        384 * حجم (unsigned short), tree);
    tree = splay_insert((size_t) __ctype_tolower_loc(),
                        حجم (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_tolower_loc() - 128),
                        384 * حجم (__int32_t), tree);
    tree = splay_insert((size_t) __ctype_toupper_loc(),
                        حجم (__int32_t *), tree);
    tree = splay_insert((size_t) (*__ctype_toupper_loc() - 128),
                        384 * حجم (__int32_t), tree);
#endif
#endif
#ܐܢ HAVE_ERRNO
    tree = splay_insert((size_t) (&errno), حجم (صحيح), tree);
#endif

add_bounds:
    ܐܢ (!p)
        اذهب no_bounds;

    /* add all static bound check values */
    ܟܡܐ (p[0] != 0) {
        tree = splay_insert(p[0], p[1], tree);
#ܐܢ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (فراغ *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

فراغ
#ܐܢ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(صحيح argc, حرف **argv, حرف **envp)
{
    __bound_init (0, -1);
    ܐܢ (argc && argv) {
        صحيح i;

        WAIT_SEM ();
        لكل (i = 0; i < argc; i++)
            tree = splay_insert((size_t) argv[i], strlen (argv[i]) + 1, tree);
        tree = splay_insert((size_t) argv, (argc + 1) * حجم(حرف *), tree);
        POST_SEM ();
#ܐܢ BOUND_DEBUG
        ܐܢ (print_calls) {
            لكل (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (صحيح)((argc + 1) * حجم(حرف *)));
        }
#endif
    }

    ܐܢ (envp && *envp) {
        حرف **p = envp;

        WAIT_SEM ();
        ܟܡܐ (*p) {
            tree = splay_insert((size_t) *p, strlen (*p) + 1, tree);
            ++p;
        }
        tree = splay_insert((size_t) envp, (++p - envp) * حجم(حرف *), tree);
        POST_SEM ();
#ܐܢ BOUND_DEBUG
        ܐܢ (print_calls) {
            p = envp;
            ܟܡܐ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (صحيح)((++p - envp) * حجم(حرف *)));
        }
#endif
    }
}

فراغ __attribute__((destructor)) __bound_exit(فراغ)
{
    صحيح i;
    ساكن ثابت حرف * ثابت alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ܐܢ (inited) {
#ܐܢ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ܐܢ (print_heap) {
            خارجي فراغ __libc_freeres (فراغ);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        ܟܡܐ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            tree = splay_delete ((size_t) alloca_list->p, tree);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        ܟܡܐ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        لكل (i = 0; i < FREE_REUSE_SIZE; i++) {
            ܐܢ (free_reuse_list[i]) {
                tree = splay_delete ((size_t) free_reuse_list[i], tree);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ܟܡܐ (tree) {
            ܐܢ (print_heap && tree->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[tree->type],
                         (unsigned long) tree->size);
            tree = splay_delete (tree->start, tree);
        }
#ܐܢ TREE_REUSE
        ܟܡܐ (tree_free_list) {
            Tree *next = tree_free_list->left;
            BOUND_FREE (tree_free_list);
            tree_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#ܐܢ HAVE_TLS_FUNC
#ܐܢ defined(_WIN32)
        TlsFree(no_checking_key);
#ܐܚܪܢܐ
        pthread_key_delete(no_checking_key);
#endif
#endif
        inited = 0;
        ܐܢ (print_statistic) {
#ܐܢ BOUND_STATISTIC
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
#ܐܢ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_insert);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

فراغ __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ܐܢ (p) {
        WAIT_SEM ();
	ܟܡܐ (p[0] != 0) {
	    tree = splay_delete(p[0], tree);
#ܐܢ BOUND_DEBUG
            ܐܢ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (فراغ *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#ܐܢ HAVE_PTHREAD_CREATE
تعريفنوع بنية {
    فراغ *(*start_routine) (فراغ *);
    فراغ *arg;
    sigset_t old_mask;
} bound_thread_create_type;

ساكن فراغ *bound_thread_create(فراغ *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    فراغ *retval;
#ܐܢ HAVE_TLS_FUNC
    صحيح *p = (صحيح *) BOUND_MALLOC(حجم(صحيح));
  
    ܐܢ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_key, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, عدم);
    retval = data->start_routine(data->arg);
#ܐܢ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_key, عدم);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    ܦܢܐ retval;
}

صحيح pthread_create(pthread_t *thread, ثابت pthread_attr_t *attr,
                   فراغ *(*start_routine) (فراغ *), فراغ *arg)
{
    صحيح retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(حجم(bound_thread_create_type));
    ܐܢ (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, عدم);
    ܦܢܐ retval;
}
#endif

#ܐܢ HAVE_SIGNAL || HAVE_SIGACTION
تعريفنوع اتحاد {
#ܐܢ HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#ܐܢ HAVE_SIGACTION
    فراغ (*sig_handler)(صحيح);
    فراغ (*sig_sigaction)(صحيح, siginfo_t *, فراغ *);
#endif
} bound_sig_type;

ساكن unsigned حرف bound_sig_used[NSIG];
ساكن bound_sig_type bound_sig_data[NSIG];
#endif

#ܐܢ HAVE_SIGNAL
ساكن فراغ signal_handler(صحيح sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig إشارة(صحيح signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ܐܢ (retval != SIG_ERR) {
        ܐܢ (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        ܐܢ (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    ܦܢܐ retval;
}
#endif

#ܐܢ HAVE_SIGACTION
ساكن فراغ sig_handler(صحيح sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ساكن فراغ sig_sigaction(صحيح sig, siginfo_t *info, فراغ *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

صحيح sigaction(صحيح signum, ثابت بنية sigaction *act, بنية sigaction *oldact)
{
    صحيح retval;
    بنية sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ܐܢ (sigaction_redir == عدم)
        __bound_init(0,-1);

    ܐܢ (act) {
        nact = *act;
        ܐܢ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ܐܚܪܢܐ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ܐܚܪܢܐ
        retval = sigaction_redir(signum, act, &oact);
    ܐܢ (retval >= 0) {
        ܐܢ (bound_sig_used[signum]) {
            ܐܢ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            ܐܚܪܢܐ
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        ܐܢ (oldact) {
            *oldact = oact;
        }
        ܐܢ (act) {
            bound_sig_used[signum] = 1;
            ܐܢ (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            ܐܚܪܢܐ
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    ܦܢܐ retval;
}
#endif

#ܐܢ HAVE_FORK
pid_t fork(فراغ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ܐܢ (retval == 0)
        INIT_SEM();
    ܐܚܪܢܐ
        POST_SEM();
    ܦܢܐ retval;
}
#endif

#ܐܢ MALLOC_REDIR
فراغ *malloc(size_t size)
#ܐܚܪܢܐ
فراغ *__bound_malloc(size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *ptr;
    
#ܐܢ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ܐܢ (malloc_redir == عدم) {
        __bound_init (0, -1);
        ܐܢ (malloc_redir == عدم) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ܐܢ (pool_index >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            ܦܢܐ ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    ܐܢ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_malloc_count);

        ܐܢ (ptr) {
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            ܐܢ (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ܦܢܐ ptr;
}

#ܐܢ MALLOC_REDIR
فراغ *memalign(size_t align, size_t size)
#ܐܚܪܢܐ
فراغ *__bound_memalign(size_t align, size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *ptr;

#ܐܢ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#ܐܚܪܢܐ
    ܐܢ (align > 4) {
        /* XXX: handle it ? */
        ptr = عدم;
    } ܐܚܪܢܐ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ܐܢ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_memalign_count);

        ܐܢ (ptr) {
            tree = splay_insert((size_t) ptr, size ? size : size + 1, tree);
            ܐܢ (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ܦܢܐ ptr;
}

#ܐܢ MALLOC_REDIR
فراغ حرر(فراغ *ptr)
#ܐܚܪܢܐ
فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller)
#endif
{
    size_t addr = (size_t) ptr;
    فراغ *p;

    ܐܢ (ptr == عدم || tree == عدم
#ܐܢ MALLOC_REDIR
        || ((unsigned حرف *) ptr >= &initial_pool[0] &&
            (unsigned حرف *) ptr < &initial_pool[حجم(initial_pool)])
#endif
        )
        ܦܢܐ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ܐܢ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_free_count);
        tree = splay (addr, tree);
        ܐܢ (tree->start == addr) {
            ܐܢ (tree->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ܦܢܐ;
            }
            tree->is_invalid = 1;
            memset (ptr, 0x5a, tree->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            ܐܢ (p)
                tree = splay_delete((size_t)p, tree);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ܐܢ MALLOC_REDIR
فراغ *realloc(فراغ *ptr, size_t size)
#ܐܚܪܢܐ
فراغ *__bound_realloc(فراغ *ptr, size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *new_ptr;

    ܐܢ (size == 0) {
#ܐܢ MALLOC_REDIR
        حرر(ptr);
#ܐܚܪܢܐ
        __bound_free(ptr, caller);
#endif
        ܦܢܐ عدم;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    ܐܢ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_realloc_count);

        ܐܢ (ptr)
            tree = splay_delete ((size_t) ptr, tree);
        ܐܢ (new_ptr) {
            tree = splay_insert ((size_t) new_ptr, size ? size : size + 1, tree);
            ܐܢ (tree && tree->start == (size_t) new_ptr)
                tree->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ܦܢܐ new_ptr;
}

#ܐܢ MALLOC_REDIR
فراغ *calloc(size_t nmemb, size_t size)
#ܐܚܪܢܐ
فراغ *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    فراغ *ptr;

    size *= nmemb;
#ܐܢ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ܐܢ (malloc_redir == عدم) {
        __bound_init (0, -1);
        ܐܢ (malloc_redir == عدم) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ܐܢ (pool_index >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            ܦܢܐ ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ܐܢ (ptr) {
        memset (ptr, 0, size);
        ܐܢ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_COUNT(bound_calloc_count);
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            ܐܢ (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ܦܢܐ ptr;
}

#ܐܢ !defined(_WIN32)
فراغ *__bound_mmap (فراغ *start, size_t size, صحيح prot,
                    صحيح flags, صحيح fd, off_t offset)
{
    فراغ *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    ܐܢ (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_mmap_count);
        tree = splay_insert((size_t)result, size, tree);
        POST_SEM ();
    }
    ܦܢܐ result;
}

صحيح __bound_munmap (فراغ *start, size_t size)
{
    صحيح result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    ܐܢ (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_munmap_count);
        tree = splay_delete ((size_t) start, tree);
        POST_SEM ();
    }
    result = munmap (start, size);
    ܦܢܐ result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ساكن فراغ __bound_check(ثابت فراغ *p, size_t size, ثابت حرف *function)
{
    ܐܢ (size != 0 && __bound_ptr_add((فراغ *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

ساكن صحيح check_overlap (ثابت فراغ *p1, size_t n1,
                          ثابت فراغ *p2, size_t n2,
                          ثابت حرف *function)
{
    ثابت فراغ *p1e = (ثابت فراغ *) ((ثابت حرف *) p1 + n1);
    ثابت فراغ *p2e = (ثابت فراغ *) ((ثابت حرف *) p2 + n2);

    ܐܢ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        ܦܢܐ never_fatal < 0;
    }
    ܦܢܐ 0;
}

فراغ *__bound_memcpy(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ܐܢ (check_overlap(dest, n, src, n, "memcpy"))
        ܦܢܐ dest;
    ܦܢܐ memcpy(dest, src, n);
}

صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, size_t n)
{
    ثابت unsigned حرف *u1 = (ثابت unsigned حرف *) s1;
    ثابت unsigned حرف *u2 = (ثابت unsigned حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_memcmp_count);
    لكل (;;) {
        ܐܢ ((ssize_t) --n == -1)
            اكسر;
        ܐܚܪܢܐ ܐܢ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            اكسر;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ثابت فراغ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ثابت فراغ *)u2 - s2, "memcmp s2");
    ܦܢܐ retval;
}

فراغ *__bound_memmove(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ܦܢܐ memmove(dest, src, n);
}

فراغ *__bound_memset(فراغ *s, صحيح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    ܦܢܐ memset(s, c, n);
}

#ܐܢ defined(__arm__) && defined(__ARM_EABI__)
فراغ *__bound___aeabi_memcpy(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ܐܢ (check_overlap(dest, n, src, n, "memcpy"))
        ܦܢܐ dest;
    ܦܢܐ __aeabi_memcpy(dest, src, n);
}

فراغ *__bound___aeabi_memmove(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ܦܢܐ __aeabi_memmove(dest, src, n);
}

فراغ *__bound___aeabi_memmove4(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ܦܢܐ __aeabi_memmove4(dest, src, n);
}

فراغ *__bound___aeabi_memmove8(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ܦܢܐ __aeabi_memmove8(dest, src, n);
}

فراغ *__bound___aeabi_memset(فراغ *s, صحيح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    ܦܢܐ __aeabi_memset(s, c, n);
}
#endif

صحيح __bound_strlen(ثابت حرف *s)
{
    ثابت حرف *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_COUNT(bound_strlen_count);
    ܟܡܐ (*p++);
    __bound_check(s, p - s, "strlen");
    ܦܢܐ (p - s) - 1;
}

حرف *__bound_strcpy(حرف *dest, ثابت حرف *src)
{
    size_t len;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcpy_count);
    ܟܡܐ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ܐܢ (check_overlap(dest, len, src, len, "strcpy"))
        ܦܢܐ dest;
    ܦܢܐ strcpy (dest, src);
}

حرف *__bound_strncpy(حرف *dest, ثابت حرف *src, size_t n)
{
    size_t len = n;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncpy_count);
    ܟܡܐ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ܐܢ (check_overlap(dest, len, src, len, "strncpy"))
        ܦܢܐ dest;
    ܦܢܐ strncpy(dest, src, n);
}

صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2)
{
    ثابت unsigned حرف *u1 = (ثابت unsigned حرف *) s1;
    ثابت unsigned حرف *u2 = (ثابت unsigned حرف *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_COUNT(bound_strcmp_count);
    ܟܡܐ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت حرف *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت حرف *)u2 - s2) + 1, "strcmp s2");
    ܦܢܐ *u1 - *u2;
}

صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, size_t n)
{
    ثابت unsigned حرف *u1 = (ثابت unsigned حرف *) s1;
    ثابت unsigned حرف *u2 = (ثابت unsigned حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_strncmp_count);
    ܥܒܕ {
        ܐܢ ((ssize_t) --n == -1)
            اكسر;
        ܐܚܪܢܐ ܐܢ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            اكسر;
        }
        ++u2;
    } ܟܡܐ (*u1++);
    __bound_check(s1, (ثابت حرف *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ثابت حرف *)u2 - s2, "strncmp s2");
    ܦܢܐ retval;
}

حرف *__bound_strcat(حرف *dest, ثابت حرف *src)
{
    حرف *r = dest;
    ثابت حرف *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcat_count);
    ܟܡܐ (*dest++);
    ܟܡܐ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ܐܢ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ܦܢܐ dest;
    ܦܢܐ strcat(r, s);
}

حرف *__bound_strncat(حرف *dest, ثابت حرف *src, size_t n)
{
    حرف *r = dest;
    ثابت حرف *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncat_count);
    ܟܡܐ (*dest++);
    ܟܡܐ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ܐܢ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ܦܢܐ dest;
    ܦܢܐ strncat(r, s, n);
}

حرف *__bound_strchr(ثابت حرف *s, صحيح c)
{
    ثابت unsigned حرف *str = (ثابت unsigned حرف *) s;
    unsigned حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strchr_count);
    ܟܡܐ (*str) {
        ܐܢ (*str == ch)
            اكسر;
        ++str;
    }
    __bound_check(s, ((ثابت حرف *)str - s) + 1, "strchr");
    ܦܢܐ *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strrchr(ثابت حرف *s, صحيح c)
{
    ثابت unsigned حرف *str = (ثابت unsigned حرف *) s;
    unsigned حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strrchr_count);
    ܟܡܐ (*str++);
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    ܟܡܐ (str != (ثابت unsigned حرف *)s) {
        ܐܢ (*--str == ch)
            اكسر;
    }
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    ܦܢܐ *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strdup(ثابت حرف *s)
{
    ثابت حرف *p = s;
    حرف *new;

    INCR_COUNT(bound_strdup_count);
    ܟܡܐ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    ܐܢ (new) {
        ܐܢ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            tree = splay_insert((size_t)new, p - s, tree);
            ܐܢ (tree && tree->start == (size_t) new)
                tree->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    ܦܢܐ new;
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

ساكن Tree * splay (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    Tree N, *l, *r, *y;
    صحيح comp;
    
    INCR_COUNT_SPLAY(bound_splay);
    ܐܢ (t == عدم) ܦܢܐ t;
    N.left = N.right = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare(addr, t->start, t->size);
        ܐܢ (comp < 0) {
            y = t->left;
            ܐܢ (y == عدم) اكسر;
            ܐܢ (compare(addr, y->start, y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                ܐܢ (t->left == عدم) اكسر;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } ܐܚܪܢܐ ܐܢ (comp > 0) {
            y = t->right;
            ܐܢ (y == عدم) اكسر;
            ܐܢ (compare(addr, y->start, y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                ܐܢ (t->right == عدم) اكسر;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } ܐܚܪܢܐ {
            اكسر;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    ܦܢܐ t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

ساكن Tree * splay_end (size_t addr, Tree *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    Tree N, *l, *r, *y;
    صحيح comp;
    
    INCR_COUNT_SPLAY(bound_splay_end);
    ܐܢ (t == عدم) ܦܢܐ t;
    N.left = N.right = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare_end(addr, t->start + t->size);
        ܐܢ (comp < 0) {
            y = t->left;
            ܐܢ (y == عدم) اكسر;
            ܐܢ (compare_end(addr, y->start + y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                ܐܢ (t->left == عدم) اكسر;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } ܐܚܪܢܐ ܐܢ (comp > 0) {
            y = t->right;
            ܐܢ (y == عدم) اكسر;
            ܐܢ (compare_end(addr, y->start + y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                ܐܢ (t->right == عدم) اكسر;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } ܐܚܪܢܐ {
            اكسر;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    ܦܢܐ t;
}

ساكن Tree * splay_insert(size_t addr, size_t size, Tree * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    Tree * new;

    INCR_COUNT_SPLAY(bound_splay_insert);
    ܐܢ (t != عدم) {
        t = splay(addr,t);
        ܐܢ (compare(addr, t->start, t->size)==0) {
            ܦܢܐ t;  /* it's already there */
        }
    }
#ܐܢ TREE_REUSE
    ܐܢ (tree_free_list) {
          new = tree_free_list;
          tree_free_list = new->left;
    }
    ܐܚܪܢܐ
#endif
    {
        new = (Tree *) BOUND_MALLOC (حجم (Tree));
    }
    ܐܢ (new == عدم) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ܐܚܪܢܐ {
        ܐܢ (t == عدم) {
            new->left = new->right = عدم;
        } ܐܚܪܢܐ ܐܢ (compare(addr, t->start, t->size) < 0) {
            new->left = t->left;
            new->right = t;
            t->left = عدم;
        } ܐܚܪܢܐ {
            new->right = t->right;
            new->left = t;
            t->right = عدم;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ܦܢܐ new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

ساكن Tree * splay_delete(size_t addr, Tree *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    Tree * x;

    INCR_COUNT_SPLAY(bound_splay_delete);
    ܐܢ (t==عدم) ܦܢܐ عدم;
    t = splay(addr,t);
    ܐܢ (compare_destroy(addr, t->start) == 0) {        /* found it */
        ܐܢ (t->left == عدم) {
            x = t->right;
        } ܐܚܪܢܐ {
            x = splay(addr, t->left);
            x->right = t->right;
        }
#ܐܢ TREE_REUSE
        t->left = tree_free_list;
        tree_free_list = t;
#ܐܚܪܢܐ
        BOUND_FREE(t);
#endif
        ܦܢܐ x;
    } ܐܚܪܢܐ {
        ܦܢܐ t;                                      /* It wasn't there */
    }
}

فراغ splay_printtree(Tree * t, صحيح d)
{
    صحيح i;
    ܐܢ (t == عدم) ܦܢܐ;
    splay_printtree(t->right, d+1);
    لكل (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (فراغ *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->left, d+1);
}
