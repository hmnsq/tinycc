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

#𐤀𐤌 !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ضمن <malloc.h>
#endif

#𐤀𐤌 !defined(_WIN32)
#ضمن <unistd.h>
#ضمن <sys/syscall.h>
#endif

#ضمن "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#𐤀𐤌 BOUND_DEBUG
 #define dprintf(a...)         𐤀𐤌 (print_calls) { bounds_loc(a); }
#وإلا
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#وإلا
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وإلا
# define DLL_EXPORT
#endif

#𐤀𐤌 defined(__FreeBSD__) \
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

#وإلا

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
#define WAIT_SEM()             𐤀𐤌 (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             𐤀𐤌 (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              𐤀𐤌 (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#وإلاإذا 0
#ضمن <semaphore.h>
ساكن sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             𐤀𐤌 (use_sem) طالما (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             𐤀𐤌 (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              𐤀𐤌 (use_sem) طالما (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وإلاإذا 0
ساكن pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, عدم)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             𐤀𐤌 (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             𐤀𐤌 (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              𐤀𐤌 (use_sem) pthread_mutex_trylock (&bounds_mtx)
#وإلا
ساكن pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             𐤀𐤌 (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             𐤀𐤌 (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              𐤀𐤌 (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#𐤀𐤌 defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#وإلا
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#𐤀𐤌 defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#𐤀𐤌 MALLOC_REDIR
ساكن فراغ *(*malloc_redir) (size_t);
ساكن فراغ *(*calloc_redir) (size_t, size_t);
ساكن فراغ (*free_redir) (فراغ *);
ساكن فراغ *(*realloc_redir) (فراغ *, size_t);
ساكن unsigned صحيح pool_index;
ساكن unsigned حرف __attribute__((aligned(16))) initial_pool[256];
#endif
#𐤀𐤌 HAVE_MEMALIGN
ساكن فراغ *(*memalign_redir) (size_t, size_t);
#endif
#𐤀𐤌 HAVE_PTHREAD_CREATE
ساكن صحيح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    فراغ *(*start_routine)(فراغ *), فراغ *arg);
#endif
#𐤀𐤌 HAVE_SIGNAL
تعريفنوع فراغ (*bound_sig)(صحيح);
ساكن bound_sig (*signal_redir) (صحيح signum, bound_sig handler);
#endif
#𐤀𐤌 HAVE_SIGACTION
ساكن صحيح (*sigaction_redir) (صحيح signum, ثابت بنية sigaction *act,
                               بنية sigaction *oldact);
#endif
#𐤀𐤌 HAVE_FORK
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

#𐤀𐤌 defined(_WIN32)
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
#وإلا
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
#𐤀𐤌 !defined(_WIN32)
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

#𐤀𐤌 defined(__arm__) && defined(__ARM_EABI__)
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

#𐤀𐤌 MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#وإلا
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
#𐤀𐤌 TREE_REUSE
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
#𐤀𐤌 HAVE_TLS_FUNC
#𐤀𐤌 defined(_WIN32)
ساكن صحيح no_checking = 0;
ساكن DWORD no_checking_key;
#define NO_CHECKING_CHECK() 𐤀𐤌 (!p) {                                         \
                                  p = (صحيح *) LocalAlloc(LPTR, حجم(صحيح));  \
                                  𐤀𐤌 (!p) bound_alloc_error("tls malloc");    \
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
#وإلا
ساكن صحيح no_checking = 0;
ساكن pthread_key_t no_checking_key;
#define NO_CHECKING_CHECK() 𐤀𐤌 (!p) {                                         \
                                  p = (صحيح *) BOUND_MALLOC(حجم(صحيح));      \
                                  𐤀𐤌 (!p) bound_alloc_error("tls malloc");    \
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
#وإلا
ساكن _Atomic صحيح no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
ساكن حرف exec[100];

#𐤀𐤌 BOUND_STATISTIC
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
#وإلا
#define INCR_COUNT(x)
#endif
#𐤀𐤌 BOUND_STATISTIC_SPLAY
ساكن unsigned long long bound_splay;
ساكن unsigned long long bound_splay_end;
ساكن unsigned long long bound_splay_insert;
ساكن unsigned long long bound_splay_delete;
#define INCR_COUNT_SPLAY(x)    ++x
#وإلا
#define INCR_COUNT_SPLAY(x)
#endif

صحيح tcc_backtrace(ثابت حرف *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    𐤐𐤏𐤋 {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } طالما (0)

#define bound_error(...)            \
    𐤐𐤏𐤋 {                            \
        bound_warning(__VA_ARGS__); \
        𐤀𐤌 (never_fatal == 0)       \
            exit(255);              \
    } طالما (0)

#define bounds_loc(fp, ...) \
    𐤐𐤏𐤋 {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } طالما (0)

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
#𐤀𐤌 HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#وإلا
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

    𐤀𐤌 (NO_CHECKING_GET())
        أرجع p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_COUNT(bound_ptr_add_count);
    𐤀𐤌 (tree) {
        addr -= tree->start;
        𐤀𐤌 (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay (addr, tree);
            addr -= tree->start;
        }
        𐤀𐤌 (addr >= tree->size) {
            addr = (size_t)p;
            tree = splay_end (addr, tree);
            addr -= tree->start;
        }
        𐤀𐤌 (addr <= tree->size) {
            𐤀𐤌 (tree->is_invalid || addr + offset > tree->size) {
                POST_SEM ();
                𐤀𐤌 (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)tree->start,
                                  (long)(tree->start + tree->size - 1));
                𐤀𐤌 (never_fatal <= 0)
                    أرجع INVALID_POINTER; /* return an invalid pointer */
                أرجع p + offset;
            }
        }
        وإلا 𐤀𐤌 (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_COUNT(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            أرجع p + offset;
        }
    }
    POST_SEM ();
    أرجع p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
فراغ * __bound_ptr_indir ## dsize (فراغ *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    𐤀𐤌 (NO_CHECKING_GET())                                                     \
        أرجع p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_COUNT(bound_ptr_indir ## dsize ## _count);                            \
    𐤀𐤌 (tree) {                                                                \
        addr -= tree->start;                                                   \
        𐤀𐤌 (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay (addr, tree);                                         \
            addr -= tree->start;                                               \
        }                                                                      \
        𐤀𐤌 (addr >= tree->size) {                                              \
            addr = (size_t)p;                                                  \
            tree = splay_end (addr, tree);                                     \
            addr -= tree->start;                                               \
        }                                                                      \
        𐤀𐤌 (addr <= tree->size) {                                              \
            𐤀𐤌 (tree->is_invalid || addr + offset + dsize > tree->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)tree->start,            \
                              (long)(tree->start + tree->size - 1));           \
                𐤀𐤌 (never_fatal <= 0)                                          \
                    أرجع INVALID_POINTER; /* return an invalid pointer */    \
                أرجع p + offset;                                             \
            }                                                                  \
        }                                                                      \
        وإلا {                                                                 \
            INCR_COUNT(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            أرجع p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    أرجع p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#𐤀𐤌 (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
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

    𐤀𐤌 (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_COUNT(bound_local_new_count);
        tree = splay_insert(addr + fp, p[1], tree);
        p += 2;
    }
    POST_SEM ();
#𐤀𐤌 BOUND_DEBUG
    𐤀𐤌 (print_calls) {
        p = p1;
        طالما ((addr = p[0])) {
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

    𐤀𐤌 (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_COUNT(bound_local_delete_count);
        tree = splay_delete(addr + fp, tree);
        p += 2;
    }
    𐤀𐤌 (alloca_list) {
        alloca_list_type *last = عدم;
        alloca_list_type *cur = alloca_list;

        𐤐𐤏𐤋 {
            𐤀𐤌 (cur->fp == fp) {
                𐤀𐤌 (last)
                    last->next = cur->next;
                وإلا
                    alloca_list = cur->next;
                tree = splay_delete ((size_t) cur->p, tree);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             وإلا {
                 last = cur;
                 cur = cur->next;
             }
        } طالما (cur);
    }
    𐤀𐤌 (jmp_list) {
        jmp_list_type *last = عدم;
        jmp_list_type *cur = jmp_list;

        𐤐𐤏𐤋 {
            𐤀𐤌 (cur->fp == fp) {
                𐤀𐤌 (last)
                    last->next = cur->next;
                وإلا
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            وإلا {
                last = cur;
                cur = cur->next;
            }
        } طالما (cur);
    }

    POST_SEM ();
#𐤀𐤌 BOUND_DEBUG
    𐤀𐤌 (print_calls) {
        p = p1;
        طالما ((addr = p[0])) {
            𐤀𐤌 (addr != 1) {
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

    𐤀𐤌 (NO_CHECKING_GET())
        أرجع;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (حجم (alloca_list_type));
    WAIT_SEM ();
    INCR_COUNT(bound_alloca_count);
    last = عدم;
    cur = alloca_list;
    طالما (cur) {
#𐤀𐤌 defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحيح align = 4;
#وإلاإذا defined(__arm__)
        صحيح align = 8;
#وإلا
        صحيح align = 16;
#endif
        فراغ *cure = (فراغ *)((حرف *)cur->p + ((cur->size + align) & -align));
        فراغ *pe = (فراغ *)((حرف *)p + ((size + align) & -align));
        𐤀𐤌 (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            𐤀𐤌 (last)
                last->next = cur->next;
            وإلا
                alloca_list = cur->next;
            tree = splay_delete((size_t)cur->p, tree);
            اكسر;
        }
        last = cur;
        cur = cur->next;
    }
    tree = splay_insert((size_t)p, size, tree);
    𐤀𐤌 (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    𐤀𐤌 (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

فراغ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    فراغ *e = (فراغ *) env;

    𐤀𐤌 (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_COUNT(bound_setjmp_count);
        jl = jmp_list;
        طالما (jl) {
            𐤀𐤌 (jl->penv == e)
                اكسر;
            jl = jl->next;
        }
        𐤀𐤌 (jl == عدم) {
            jl = BOUND_MALLOC (حجم (jmp_list_type));
            𐤀𐤌 (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        𐤀𐤌 (jl) {
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

    𐤀𐤌 (NO_CHECKING_GET() == 0) {
        e = (فراغ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_COUNT(bound_longjmp_count);
        jl = jmp_list;
        طالما (jl) {
            𐤀𐤌 (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = عدم;

                طالما (cur->penv != e || cur->tid != tid) {
                    𐤀𐤌 (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        𐤀𐤌 (last)
                            last->next = cur->next;
                        وإلا
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    وإلا {
                        last = cur;
                        cur = cur->next;
                    }
                }
                لكل (;;) {
                    Tree *t = tree;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    طالما (t && (t->start < start_fp || t->start > end_fp))
                        𐤀𐤌 (t->start < start_fp)
                            t = t->right;
                        وإلا
                            t = t->left;
                    𐤀𐤌 (t == عدم)
                        اكسر;
                    last = عدم;
                    cur = alloca_list;
                    طالما (cur) {
                         𐤀𐤌 ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             𐤀𐤌 (last)
                                 last->next = cur->next;
                             وإلا
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
#𐤀𐤌 !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

فراغ __bound_longjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#𐤀𐤌 !defined(_WIN32)
فراغ __bound_siglongjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#𐤀𐤌 (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

فراغ __bound_init(size_t *p, صحيح mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    𐤀𐤌 (inited) {
        WAIT_SEM();
        اذهب add_bounds;
    }
    inited = 1;

#𐤀𐤌 HAVE_TLS_FUNC
#𐤀𐤌 defined(_WIN32)
    no_checking_key = TlsAlloc();
    TlsSetValue(no_checking_key, &no_checking);
#وإلا
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

#𐤀𐤌 MALLOC_REDIR
    {
        فراغ *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(فراغ **) (&malloc_redir) = dlsym (addr, "malloc");
        𐤀𐤌 (malloc_redir == عدم) {
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
        𐤀𐤌 (malloc_redir == عدم || free_redir == عدم)
            bound_alloc_error ("Cannot redirect malloc/free");
#𐤀𐤌 HAVE_PTHREAD_CREATE
        *(فراغ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        𐤀𐤌 (pthread_create_redir == عدم)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#𐤀𐤌 HAVE_SIGNAL
        *(فراغ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        𐤀𐤌 (signal_redir == عدم)
            bound_alloc_error ("Cannot redirect signal");
#endif
#𐤀𐤌 HAVE_SIGACTION
        *(فراغ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        𐤀𐤌 (sigaction_redir == عدم)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#𐤀𐤌 HAVE_FORK
        *(فراغ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        𐤀𐤌 (fork_redir == عدم)
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
        𐤀𐤌 (fp) {
            memset (exec, 0, حجم(exec));
            fread (exec, 1, حجم(exec) - 2, fp);
            𐤀𐤌 (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        𐤀𐤌 (fp) {
            طالما (fgets (line, حجم(line), fp)) {
                𐤀𐤌 (sscanf (line, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    اكسر;
                }
                𐤀𐤌 (strstr (line,"[heap]"))
                    اكسر;
            }
            fclose (fp);
        }
        𐤀𐤌 (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#𐤀𐤌 HAVE_CTYPE
#ifdef __APPLE__
    tree = splay_insert((size_t) &_DefaultRuneLocale,
                        حجم (_DefaultRuneLocale), tree);
#وإلا
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
#𐤀𐤌 HAVE_ERRNO
    tree = splay_insert((size_t) (&errno), حجم (صحيح), tree);
#endif

add_bounds:
    𐤀𐤌 (!p)
        اذهب no_bounds;

    /* add all static bound check values */
    طالما (p[0] != 0) {
        tree = splay_insert(p[0], p[1], tree);
#𐤀𐤌 BOUND_DEBUG
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
#𐤀𐤌 (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(صحيح argc, حرف **argv, حرف **envp)
{
    __bound_init (0, -1);
    𐤀𐤌 (argc && argv) {
        صحيح i;

        WAIT_SEM ();
        لكل (i = 0; i < argc; i++)
            tree = splay_insert((size_t) argv[i], strlen (argv[i]) + 1, tree);
        tree = splay_insert((size_t) argv, (argc + 1) * حجم(حرف *), tree);
        POST_SEM ();
#𐤀𐤌 BOUND_DEBUG
        𐤀𐤌 (print_calls) {
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

    𐤀𐤌 (envp && *envp) {
        حرف **p = envp;

        WAIT_SEM ();
        طالما (*p) {
            tree = splay_insert((size_t) *p, strlen (*p) + 1, tree);
            ++p;
        }
        tree = splay_insert((size_t) envp, (++p - envp) * حجم(حرف *), tree);
        POST_SEM ();
#𐤀𐤌 BOUND_DEBUG
        𐤀𐤌 (print_calls) {
            p = envp;
            طالما (*p) {
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

    𐤀𐤌 (inited) {
#𐤀𐤌 !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        𐤀𐤌 (print_heap) {
            خارجي فراغ __libc_freeres (فراغ);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        طالما (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            tree = splay_delete ((size_t) alloca_list->p, tree);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        طالما (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        لكل (i = 0; i < FREE_REUSE_SIZE; i++) {
            𐤀𐤌 (free_reuse_list[i]) {
                tree = splay_delete ((size_t) free_reuse_list[i], tree);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        طالما (tree) {
            𐤀𐤌 (print_heap && tree->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[tree->type],
                         (unsigned long) tree->size);
            tree = splay_delete (tree->start, tree);
        }
#𐤀𐤌 TREE_REUSE
        طالما (tree_free_list) {
            Tree *next = tree_free_list->left;
            BOUND_FREE (tree_free_list);
            tree_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#𐤀𐤌 HAVE_TLS_FUNC
#𐤀𐤌 defined(_WIN32)
        TlsFree(no_checking_key);
#وإلا
        pthread_key_delete(no_checking_key);
#endif
#endif
        inited = 0;
        𐤀𐤌 (print_statistic) {
#𐤀𐤌 BOUND_STATISTIC
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
#𐤀𐤌 BOUND_STATISTIC_SPLAY
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

    𐤀𐤌 (p) {
        WAIT_SEM ();
	طالما (p[0] != 0) {
	    tree = splay_delete(p[0], tree);
#𐤀𐤌 BOUND_DEBUG
            𐤀𐤌 (print_calls) {
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

#𐤀𐤌 HAVE_PTHREAD_CREATE
تعريفنوع بنية {
    فراغ *(*start_routine) (فراغ *);
    فراغ *arg;
    sigset_t old_mask;
} bound_thread_create_type;

ساكن فراغ *bound_thread_create(فراغ *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    فراغ *retval;
#𐤀𐤌 HAVE_TLS_FUNC
    صحيح *p = (صحيح *) BOUND_MALLOC(حجم(صحيح));
  
    𐤀𐤌 (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_key, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, عدم);
    retval = data->start_routine(data->arg);
#𐤀𐤌 HAVE_TLS_FUNC
    pthread_setspecific(no_checking_key, عدم);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    أرجع retval;
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
    𐤀𐤌 (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, عدم);
    أرجع retval;
}
#endif

#𐤀𐤌 HAVE_SIGNAL || HAVE_SIGACTION
تعريفنوع اتحاد {
#𐤀𐤌 HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#𐤀𐤌 HAVE_SIGACTION
    فراغ (*sig_handler)(صحيح);
    فراغ (*sig_sigaction)(صحيح, siginfo_t *, فراغ *);
#endif
} bound_sig_type;

ساكن unsigned حرف bound_sig_used[NSIG];
ساكن bound_sig_type bound_sig_data[NSIG];
#endif

#𐤀𐤌 HAVE_SIGNAL
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
    𐤀𐤌 (retval != SIG_ERR) {
        𐤀𐤌 (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        𐤀𐤌 (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    أرجع retval;
}
#endif

#𐤀𐤌 HAVE_SIGACTION
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

    𐤀𐤌 (sigaction_redir == عدم)
        __bound_init(0,-1);

    𐤀𐤌 (act) {
        nact = *act;
        𐤀𐤌 (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        وإلا
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    وإلا
        retval = sigaction_redir(signum, act, &oact);
    𐤀𐤌 (retval >= 0) {
        𐤀𐤌 (bound_sig_used[signum]) {
            𐤀𐤌 (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            وإلا
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        𐤀𐤌 (oldact) {
            *oldact = oact;
        }
        𐤀𐤌 (act) {
            bound_sig_used[signum] = 1;
            𐤀𐤌 (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            وإلا
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    أرجع retval;
}
#endif

#𐤀𐤌 HAVE_FORK
pid_t fork(فراغ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    𐤀𐤌 (retval == 0)
        INIT_SEM();
    وإلا
        POST_SEM();
    أرجع retval;
}
#endif

#𐤀𐤌 MALLOC_REDIR
فراغ *malloc(size_t size)
#وإلا
فراغ *__bound_malloc(size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *ptr;
    
#𐤀𐤌 MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    𐤀𐤌 (malloc_redir == عدم) {
        __bound_init (0, -1);
        𐤀𐤌 (malloc_redir == عدم) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            𐤀𐤌 (pool_index >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            أرجع ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    𐤀𐤌 (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_malloc_count);

        𐤀𐤌 (ptr) {
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            𐤀𐤌 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#𐤀𐤌 MALLOC_REDIR
فراغ *memalign(size_t align, size_t size)
#وإلا
فراغ *__bound_memalign(size_t align, size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *ptr;

#𐤀𐤌 HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#وإلا
    𐤀𐤌 (align > 4) {
        /* XXX: handle it ? */
        ptr = عدم;
    } وإلا {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    𐤀𐤌 (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_memalign_count);

        𐤀𐤌 (ptr) {
            tree = splay_insert((size_t) ptr, size ? size : size + 1, tree);
            𐤀𐤌 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#𐤀𐤌 MALLOC_REDIR
فراغ حرر(فراغ *ptr)
#وإلا
فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller)
#endif
{
    size_t addr = (size_t) ptr;
    فراغ *p;

    𐤀𐤌 (ptr == عدم || tree == عدم
#𐤀𐤌 MALLOC_REDIR
        || ((unsigned حرف *) ptr >= &initial_pool[0] &&
            (unsigned حرف *) ptr < &initial_pool[حجم(initial_pool)])
#endif
        )
        أرجع;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    𐤀𐤌 (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_free_count);
        tree = splay (addr, tree);
        𐤀𐤌 (tree->start == addr) {
            𐤀𐤌 (tree->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                أرجع;
            }
            tree->is_invalid = 1;
            memset (ptr, 0x5a, tree->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            𐤀𐤌 (p)
                tree = splay_delete((size_t)p, tree);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#𐤀𐤌 MALLOC_REDIR
فراغ *realloc(فراغ *ptr, size_t size)
#وإلا
فراغ *__bound_realloc(فراغ *ptr, size_t size, ثابت فراغ *caller)
#endif
{
    فراغ *new_ptr;

    𐤀𐤌 (size == 0) {
#𐤀𐤌 MALLOC_REDIR
        حرر(ptr);
#وإلا
        __bound_free(ptr, caller);
#endif
        أرجع عدم;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    𐤀𐤌 (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_realloc_count);

        𐤀𐤌 (ptr)
            tree = splay_delete ((size_t) ptr, tree);
        𐤀𐤌 (new_ptr) {
            tree = splay_insert ((size_t) new_ptr, size ? size : size + 1, tree);
            𐤀𐤌 (tree && tree->start == (size_t) new_ptr)
                tree->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    أرجع new_ptr;
}

#𐤀𐤌 MALLOC_REDIR
فراغ *calloc(size_t nmemb, size_t size)
#وإلا
فراغ *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    فراغ *ptr;

    size *= nmemb;
#𐤀𐤌 MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    𐤀𐤌 (malloc_redir == عدم) {
        __bound_init (0, -1);
        𐤀𐤌 (malloc_redir == عدم) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            𐤀𐤌 (pool_index >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            أرجع ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    𐤀𐤌 (ptr) {
        memset (ptr, 0, size);
        𐤀𐤌 (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_COUNT(bound_calloc_count);
            tree = splay_insert ((size_t) ptr, size ? size : size + 1, tree);
            𐤀𐤌 (tree && tree->start == (size_t) ptr)
                tree->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    أرجع ptr;
}

#𐤀𐤌 !defined(_WIN32)
فراغ *__bound_mmap (فراغ *start, size_t size, صحيح prot,
                    صحيح flags, صحيح fd, off_t offset)
{
    فراغ *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    𐤀𐤌 (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_mmap_count);
        tree = splay_insert((size_t)result, size, tree);
        POST_SEM ();
    }
    أرجع result;
}

صحيح __bound_munmap (فراغ *start, size_t size)
{
    صحيح result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    𐤀𐤌 (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_COUNT(bound_munmap_count);
        tree = splay_delete ((size_t) start, tree);
        POST_SEM ();
    }
    result = munmap (start, size);
    أرجع result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ساكن فراغ __bound_check(ثابت فراغ *p, size_t size, ثابت حرف *function)
{
    𐤀𐤌 (size != 0 && __bound_ptr_add((فراغ *)p, size) == INVALID_POINTER) {
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

    𐤀𐤌 (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        أرجع never_fatal < 0;
    }
    أرجع 0;
}

فراغ *__bound_memcpy(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    𐤀𐤌 (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع memcpy(dest, src, n);
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
        𐤀𐤌 ((ssize_t) --n == -1)
            اكسر;
        وإلا 𐤀𐤌 (*u1 != *u2) {
            retval = *u1++ - *u2++;
            اكسر;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ثابت فراغ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ثابت فراغ *)u2 - s2, "memcmp s2");
    أرجع retval;
}

فراغ *__bound_memmove(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع memmove(dest, src, n);
}

فراغ *__bound_memset(فراغ *s, صحيح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    أرجع memset(s, c, n);
}

#𐤀𐤌 defined(__arm__) && defined(__ARM_EABI__)
فراغ *__bound___aeabi_memcpy(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_mempcy_count);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    𐤀𐤌 (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع __aeabi_memcpy(dest, src, n);
}

فراغ *__bound___aeabi_memmove(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove(dest, src, n);
}

فراغ *__bound___aeabi_memmove4(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove4(dest, src, n);
}

فراغ *__bound___aeabi_memmove8(فراغ *dest, ثابت فراغ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_memmove_count);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove8(dest, src, n);
}

فراغ *__bound___aeabi_memset(فراغ *s, صحيح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_COUNT(bound_memset_count);
    __bound_check(s, n, "memset");
    أرجع __aeabi_memset(s, c, n);
}
#endif

صحيح __bound_strlen(ثابت حرف *s)
{
    ثابت حرف *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_COUNT(bound_strlen_count);
    طالما (*p++);
    __bound_check(s, p - s, "strlen");
    أرجع (p - s) - 1;
}

حرف *__bound_strcpy(حرف *dest, ثابت حرف *src)
{
    size_t len;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcpy_count);
    طالما (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    𐤀𐤌 (check_overlap(dest, len, src, len, "strcpy"))
        أرجع dest;
    أرجع strcpy (dest, src);
}

حرف *__bound_strncpy(حرف *dest, ثابت حرف *src, size_t n)
{
    size_t len = n;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncpy_count);
    طالما (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    𐤀𐤌 (check_overlap(dest, len, src, len, "strncpy"))
        أرجع dest;
    أرجع strncpy(dest, src, n);
}

صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2)
{
    ثابت unsigned حرف *u1 = (ثابت unsigned حرف *) s1;
    ثابت unsigned حرف *u2 = (ثابت unsigned حرف *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_COUNT(bound_strcmp_count);
    طالما (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت حرف *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت حرف *)u2 - s2) + 1, "strcmp s2");
    أرجع *u1 - *u2;
}

صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, size_t n)
{
    ثابت unsigned حرف *u1 = (ثابت unsigned حرف *) s1;
    ثابت unsigned حرف *u2 = (ثابت unsigned حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_COUNT(bound_strncmp_count);
    𐤐𐤏𐤋 {
        𐤀𐤌 ((ssize_t) --n == -1)
            اكسر;
        وإلا 𐤀𐤌 (*u1 != *u2) {
            retval = *u1++ - *u2++;
            اكسر;
        }
        ++u2;
    } طالما (*u1++);
    __bound_check(s1, (ثابت حرف *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ثابت حرف *)u2 - s2, "strncmp s2");
    أرجع retval;
}

حرف *__bound_strcat(حرف *dest, ثابت حرف *src)
{
    حرف *r = dest;
    ثابت حرف *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_COUNT(bound_strcat_count);
    طالما (*dest++);
    طالما (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    𐤀𐤌 (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        أرجع dest;
    أرجع strcat(r, s);
}

حرف *__bound_strncat(حرف *dest, ثابت حرف *src, size_t n)
{
    حرف *r = dest;
    ثابت حرف *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_COUNT(bound_strncat_count);
    طالما (*dest++);
    طالما (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    𐤀𐤌 (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        أرجع dest;
    أرجع strncat(r, s, n);
}

حرف *__bound_strchr(ثابت حرف *s, صحيح c)
{
    ثابت unsigned حرف *str = (ثابت unsigned حرف *) s;
    unsigned حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strchr_count);
    طالما (*str) {
        𐤀𐤌 (*str == ch)
            اكسر;
        ++str;
    }
    __bound_check(s, ((ثابت حرف *)str - s) + 1, "strchr");
    أرجع *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strrchr(ثابت حرف *s, صحيح c)
{
    ثابت unsigned حرف *str = (ثابت unsigned حرف *) s;
    unsigned حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_COUNT(bound_strrchr_count);
    طالما (*str++);
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    طالما (str != (ثابت unsigned حرف *)s) {
        𐤀𐤌 (*--str == ch)
            اكسر;
    }
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    أرجع *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strdup(ثابت حرف *s)
{
    ثابت حرف *p = s;
    حرف *new;

    INCR_COUNT(bound_strdup_count);
    طالما (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    𐤀𐤌 (new) {
        𐤀𐤌 (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            tree = splay_insert((size_t)new, p - s, tree);
            𐤀𐤌 (tree && tree->start == (size_t) new)
                tree->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    أرجع new;
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
    𐤀𐤌 (t == عدم) أرجع t;
    N.left = N.right = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare(addr, t->start, t->size);
        𐤀𐤌 (comp < 0) {
            y = t->left;
            𐤀𐤌 (y == عدم) اكسر;
            𐤀𐤌 (compare(addr, y->start, y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                𐤀𐤌 (t->left == عدم) اكسر;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } وإلا 𐤀𐤌 (comp > 0) {
            y = t->right;
            𐤀𐤌 (y == عدم) اكسر;
            𐤀𐤌 (compare(addr, y->start, y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                𐤀𐤌 (t->right == عدم) اكسر;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } وإلا {
            اكسر;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    أرجع t;
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
    𐤀𐤌 (t == عدم) أرجع t;
    N.left = N.right = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare_end(addr, t->start + t->size);
        𐤀𐤌 (comp < 0) {
            y = t->left;
            𐤀𐤌 (y == عدم) اكسر;
            𐤀𐤌 (compare_end(addr, y->start + y->size) < 0) {
                t->left = y->right;                    /* rotate right */
                y->right = t;
                t = y;
                𐤀𐤌 (t->left == عدم) اكسر;
            }
            r->left = t;                               /* link right */
            r = t;
            t = t->left;
        } وإلا 𐤀𐤌 (comp > 0) {
            y = t->right;
            𐤀𐤌 (y == عدم) اكسر;
            𐤀𐤌 (compare_end(addr, y->start + y->size) > 0) {
                t->right = y->left;                    /* rotate left */
                y->left = t;
                t = y;
                𐤀𐤌 (t->right == عدم) اكسر;
            }
            l->right = t;                              /* link left */
            l = t;
            t = t->right;
        } وإلا {
            اكسر;
        }
    }
    l->right = t->left;                                /* assemble */
    r->left = t->right;
    t->left = N.right;
    t->right = N.left;

    أرجع t;
}

ساكن Tree * splay_insert(size_t addr, size_t size, Tree * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    Tree * new;

    INCR_COUNT_SPLAY(bound_splay_insert);
    𐤀𐤌 (t != عدم) {
        t = splay(addr,t);
        𐤀𐤌 (compare(addr, t->start, t->size)==0) {
            أرجع t;  /* it's already there */
        }
    }
#𐤀𐤌 TREE_REUSE
    𐤀𐤌 (tree_free_list) {
          new = tree_free_list;
          tree_free_list = new->left;
    }
    وإلا
#endif
    {
        new = (Tree *) BOUND_MALLOC (حجم (Tree));
    }
    𐤀𐤌 (new == عدم) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    وإلا {
        𐤀𐤌 (t == عدم) {
            new->left = new->right = عدم;
        } وإلا 𐤀𐤌 (compare(addr, t->start, t->size) < 0) {
            new->left = t->left;
            new->right = t;
            t->left = عدم;
        } وإلا {
            new->right = t->right;
            new->left = t;
            t->right = عدم;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    أرجع new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

ساكن Tree * splay_delete(size_t addr, Tree *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    Tree * x;

    INCR_COUNT_SPLAY(bound_splay_delete);
    𐤀𐤌 (t==عدم) أرجع عدم;
    t = splay(addr,t);
    𐤀𐤌 (compare_destroy(addr, t->start) == 0) {        /* found it */
        𐤀𐤌 (t->left == عدم) {
            x = t->right;
        } وإلا {
            x = splay(addr, t->left);
            x->right = t->right;
        }
#𐤀𐤌 TREE_REUSE
        t->left = tree_free_list;
        tree_free_list = t;
#وإلا
        BOUND_FREE(t);
#endif
        أرجع x;
    } وإلا {
        أرجع t;                                      /* It wasn't there */
    }
}

فراغ splay_printtree(Tree * t, صحيح d)
{
    صحيح i;
    𐤀𐤌 (t == عدم) أرجع;
    splay_printtree(t->right, d+1);
    لكل (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (فراغ *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->left, d+1);
}
