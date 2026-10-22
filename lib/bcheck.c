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
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <stdarg.h>
#شامل <string.h>
#شامل <setjmp.h>
#شامل <stdatomic.h>

#اگر !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#شامل <malloc.h>
#endif

#اگر !defined(_WIN32)
#شامل <unistd.h>
#شامل <sys/syscall.h>
#endif

#شامل "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#اگر BOUND_DEBUG
 #define dprintf(a...)         اگر (print_calls) { bounds_loc(a); }
#وگرنه
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#وگرنه
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وگرنه
# define DLL_EXPORT
#endif

#اگر defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#شامل <sys/mman.h>
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

#وگرنهاگر defined(_WIN32)

#شامل <windows.h>
#شامل <signal.h>
ایستا CRITICAL_SECTION bounds_sem;
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

#وگرنه

#define __USE_GNU              /* get RTLD_NEXT */
#شامل <sys/mman.h>
#شامل <ctype.h>
#شامل <pthread.h>
#شامل <dlfcn.h>
#شامل <errno.h>
#شامل <signal.h>
#ifdef __APPLE__
#شامل <dispatch/dispatch.h>
ایستا dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             اگر (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             اگر (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              اگر (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#وگرنهاگر 0
#شامل <semaphore.h>
ایستا sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             اگر (use_sem) وقتی (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             اگر (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              اگر (use_sem) وقتی (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وگرنهاگر 0
ایستا pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, پوچ)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             اگر (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             اگر (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              اگر (use_sem) pthread_mutex_trylock (&bounds_mtx)
#وگرنه
ایستا pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             اگر (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             اگر (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              اگر (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#اگر defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#وگرنه
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#اگر defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#اگر MALLOC_REDIR
ایستا تهی *(*malloc_redir) (size_t);
ایستا تهی *(*calloc_redir) (size_t, size_t);
ایستا تهی (*free_redir) (تهی *);
ایستا تهی *(*realloc_redir) (تهی *, size_t);
ایستا unsigned صحیح pool_index;
ایستا unsigned نویسه __attribute__((aligned(16))) initial_pool[256];
#endif
#اگر HAVE_MEMALIGN
ایستا تهی *(*memalign_redir) (size_t, size_t);
#endif
#اگر HAVE_PTHREAD_CREATE
ایستا صحیح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    تهی *(*start_routine)(تهی *), تهی *arg);
#endif
#اگر HAVE_SIGNAL
تعریفنوع تهی (*bound_sig)(صحیح);
ایستا bound_sig (*signal_redir) (صحیح signum, bound_sig handler);
#endif
#اگر HAVE_SIGACTION
ایستا صحیح (*sigaction_redir) (صحیح signum, ثابت ساختار sigaction *act,
                               ساختار sigaction *oldact);
#endif
#اگر HAVE_FORK
ایستا صحیح (*fork_redir) (تهی);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((تهی *)(-2))

تعریفنوع ساختار گره_درخت درخت;
ساختار گره_درخت {
    درخت * چپ, * راست;
    size_t start;
    size_t size;
    unsigned نویسه type;
    unsigned نویسه is_invalid; /* true if pointers outside region are invalid */
};

تعریفنوع ساختار alloca_list_struct {
    size_t fp;
    تهی *p;
    size_t size;
    ساختار alloca_list_struct *next;
} alloca_list_type;

#اگر defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#وگرنهاگر defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#وگرنهاگر defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#وگرنهاگر  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#وگرنهاگر defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#وگرنه
#define BOUND_TID_TYPE		صحیح
#define BOUND_GET_TID(id)	id = 0
#endif

تعریفنوع ساختار jmp_list_struct {
    تهی *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    ساختار jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
ایستا درخت * splay (size_t addr, درخت *t);
ایستا درخت * splay_end (size_t addr, درخت *t);
ایستا درخت * splay_درج(size_t addr, size_t size, درخت * t);
ایستا درخت * splay_delete(size_t addr, درخت *t);
تهی splay_printtree(درخت * t, صحیح d);

/* external interface */
تهی __bounds_checking (صحیح no_check);
تهی __bound_checking_lock (تهی);
تهی __bound_checking_unlock (تهی);
تهی __bound_never_fatal (صحیح no_check);
DLL_EXPORT تهی * __bound_ptr_add(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir1(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir2(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir4(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir8(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir12(تهی *p, size_t offset);
DLL_EXPORT تهی * __bound_ptr_indir16(تهی *p, size_t offset);
DLL_EXPORT تهی FASTCALL __bound_local_new(تهی *p1);
DLL_EXPORT تهی FASTCALL __bound_local_delete(تهی *p1);
تهی __bound_init(size_t *, صحیح);
تهی __bound_main_arg(صحیح argc, نویسه **argv, نویسه **envp);
تهی __bound_exit(تهی);
تهی __bound_exit_dll(size_t *);
#اگر !defined(_WIN32)
تهی *__bound_mmap (تهی *start, size_t size, صحیح prot, صحیح flags, صحیح fd,
                    off_t offset);
صحیح __bound_munmap (تهی *start, size_t size);
DLL_EXPORT تهی __bound_siglongjmp(jmp_buf env, صحیح val);
#endif
DLL_EXPORT تهی __bound_new_region(تهی *p, size_t size);
DLL_EXPORT تهی __bound_setjmp(jmp_buf env);
DLL_EXPORT تهی __bound_longjmp(jmp_buf env, صحیح val);
DLL_EXPORT تهی *__bound_memcpy(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT صحیح __bound_memcmp(ثابت تهی *s1, ثابت تهی *s2, size_t size);
DLL_EXPORT تهی *__bound_memmove(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__bound_memset(تهی *dst, صحیح c, size_t size);
DLL_EXPORT صحیح __bound_strlen(ثابت نویسه *s);
DLL_EXPORT نویسه *__bound_strcpy(نویسه *dst, ثابت نویسه *src);
DLL_EXPORT نویسه *__bound_strncpy(نویسه *dst, ثابت نویسه *src, size_t n);
DLL_EXPORT صحیح __bound_strcmp(ثابت نویسه *s1, ثابت نویسه *s2);
DLL_EXPORT صحیح __bound_strncmp(ثابت نویسه *s1, ثابت نویسه *s2, size_t n);
DLL_EXPORT نویسه *__bound_strcat(نویسه *dest, ثابت نویسه *src);
DLL_EXPORT نویسه *__bound_strncat(نویسه *dest, ثابت نویسه *src, size_t n);
DLL_EXPORT نویسه *__bound_strchr(ثابت نویسه *string, صحیح ch);
DLL_EXPORT نویسه *__bound_strrchr(ثابت نویسه *string, صحیح ch);
DLL_EXPORT نویسه *__bound_strdup(ثابت نویسه *s);

#اگر defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT تهی *__bound___aeabi_memcpy(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__bound___aeabi_memmove(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__bound___aeabi_memmove4(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__bound___aeabi_memmove8(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__bound___aeabi_memset(تهی *dst, صحیح c, size_t size);
DLL_EXPORT تهی *__aeabi_memcpy(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__aeabi_memmove(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__aeabi_memmove4(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__aeabi_memmove8(تهی *dst, ثابت تهی *src, size_t size);
DLL_EXPORT تهی *__aeabi_memset(تهی *dst, صحیح c, size_t size);
#endif

#اگر MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#وگرنه
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            آزاد(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT تهی *__bound_malloc(size_t size, ثابت تهی *caller);
DLL_EXPORT تهی *__bound_memalign(size_t align, size_t size, ثابت تهی *caller);
DLL_EXPORT تهی __bound_free(تهی *ptr, ثابت تهی *caller);
DLL_EXPORT تهی *__bound_realloc(تهی *ptr, size_t size, ثابت تهی *caller);
DLL_EXPORT تهی *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
ایستا unsigned صحیح free_reuse_index;
ایستا تهی *free_reuse_list[FREE_REUSE_SIZE];

ایستا درخت *درخت_2 = پوچ;
#define درخت_REUSE      (1)
#اگر درخت_REUSE
ایستا درخت *درخت_free_list;
#endif
ایستا alloca_list_type *alloca_list;
ایستا jmp_list_type *jmp_list;

ایستا unsigned نویسه inited;
ایستا unsigned نویسه print_warn_ptr_add;
ایستا unsigned نویسه print_calls;
ایستا unsigned نویسه print_heap;
ایستا unsigned نویسه print_statistic;
ایستا unsigned نویسه no_strdup;
ایستا unsigned نویسه use_sem;
ایستا _Atomic صحیح never_fatal;
#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
ایستا صحیح no_checking = 0;
ایستا DWORD no_checking_کلید;
#define NO_CHECKING_CHECK() اگر (!p) {                                         \
                                  p = (صحیح *) LocalAlloc(LPTR, اندازه(صحیح));  \
                                  اگر (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_مقدار(no_checking_کلید, p);            \
                            }
#define NO_CHECKING_GET()   ({ صحیح *p = Tls_Get_مقدار(no_checking_کلید);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { صحیح *p = Tls_Get_مقدار(no_checking_کلید);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#وگرنه
ایستا صحیح no_checking = 0;
ایستا pthread_key_t no_checking_کلید;
#define NO_CHECKING_CHECK() اگر (!p) {                                         \
                                  p = (صحیح *) BOUND_MALLOC(اندازه(صحیح));      \
                                  اگر (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_کلید, p);    \
                            }
#define NO_CHECKING_GET()   ({ صحیح *p = pthread_getspecific(no_checking_کلید); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { صحیح *p = pthread_getspecific(no_checking_کلید);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#وگرنهاگر HAVE_TLS_VAR
ایستا __thread صحیح no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#وگرنه
ایستا _Atomic صحیح no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
ایستا نویسه exec[100];

#اگر BOUND_STATISTIC
ایستا unsigned long long bound_ptr_add_شمار;
ایستا unsigned long long bound_ptr_indir1_شمار;
ایستا unsigned long long bound_ptr_indir2_شمار;
ایستا unsigned long long bound_ptr_indir4_شمار;
ایستا unsigned long long bound_ptr_indir8_شمار;
ایستا unsigned long long bound_ptr_indir12_شمار;
ایستا unsigned long long bound_ptr_indir16_شمار;
ایستا unsigned long long bound_local_new_شمار;
ایستا unsigned long long bound_local_delete_شمار;
ایستا unsigned long long bound_malloc_شمار;
ایستا unsigned long long bound_calloc_شمار;
ایستا unsigned long long bound_realloc_شمار;
ایستا unsigned long long bound_free_شمار;
ایستا unsigned long long bound_memalign_شمار;
ایستا unsigned long long bound_mmap_شمار;
ایستا unsigned long long bound_munmap_شمار;
ایستا unsigned long long bound_alloca_شمار;
ایستا unsigned long long bound_setjmp_شمار;
ایستا unsigned long long bound_longjmp_شمار;
ایستا unsigned long long bound_mempcy_شمار;
ایستا unsigned long long bound_memcmp_شمار;
ایستا unsigned long long bound_memmove_شمار;
ایستا unsigned long long bound_memset_شمار;
ایستا unsigned long long bound_strlen_شمار;
ایستا unsigned long long bound_strcpy_شمار;
ایستا unsigned long long bound_strncpy_شمار;
ایستا unsigned long long bound_strcmp_شمار;
ایستا unsigned long long bound_strncmp_شمار;
ایستا unsigned long long bound_strcat_شمار;
ایستا unsigned long long bound_strncat_شمار;
ایستا unsigned long long bound_strchr_شمار;
ایستا unsigned long long bound_strrchr_شمار;
ایستا unsigned long long bound_strdup_شمار;
ایستا unsigned long long bound_not_found;
#define INCR_شمار(x)          ++x
#وگرنه
#define INCR_شمار(x)
#endif
#اگر BOUND_STATISTIC_SPLAY
ایستا unsigned long long bound_splay;
ایستا unsigned long long bound_splay_end;
ایستا unsigned long long bound_splay_درج;
ایستا unsigned long long bound_splay_delete;
#define INCR_شمار_SPLAY(x)    ++x
#وگرنه
#define INCR_شمار_SPLAY(x)
#endif

صحیح tcc_backtrace(ثابت نویسه *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    انجامبده {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } وقتی (0)

#define bound_error(...)            \
    انجامبده {                            \
        bound_warning(__VA_ARGS__); \
        اگر (never_fatal == 0)       \
            exit(255);              \
    } وقتی (0)

#define bounds_loc(fp, ...) \
    انجامبده {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } وقتی (0)

ایستا تهی bound_alloc_error(ثابت نویسه *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

ایستا تهی bound_not_found_warning(ثابت نویسه *file, ثابت نویسه *function,
                                    تهی *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
تهی __bounds_checking (صحیح no_check)
{
#اگر HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#وگرنه
    atomic_fetch_add (&no_checking, no_check);
#endif
}

تهی __bound_checking_lock(تهی)
{
    WAIT_SEM ();
}

تهی __bound_checking_unlock(تهی)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
تهی __bound_never_fatal (صحیح neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
تهی * __bound_ptr_add(تهی *p, size_t offset)
{
    size_t addr = (size_t)p;

    اگر (NO_CHECKING_GET())
        بازگشت p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_شمار(bound_ptr_add_شمار);
    اگر (درخت_2) {
        addr -= درخت_2->start;
        اگر (addr >= درخت_2->size) {
            addr = (size_t)p;
            درخت_2 = splay (addr, درخت_2);
            addr -= درخت_2->start;
        }
        اگر (addr >= درخت_2->size) {
            addr = (size_t)p;
            درخت_2 = splay_end (addr, درخت_2);
            addr -= درخت_2->start;
        }
        اگر (addr <= درخت_2->size) {
            اگر (درخت_2->is_invalid || addr + offset > درخت_2->size) {
                POST_SEM ();
                اگر (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)درخت_2->start,
                                  (long)(درخت_2->start + درخت_2->size - 1));
                اگر (never_fatal <= 0)
                    بازگشت INVALID_POINTER; /* return an invalid pointer */
                بازگشت p + offset;
            }
        }
        وگرنه اگر (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_شمار(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            بازگشت p + offset;
        }
    }
    POST_SEM ();
    بازگشت p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
تهی * __bound_ptr_indir ## dsize (تهی *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    اگر (NO_CHECKING_GET())                                                     \
        بازگشت p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_شمار(bound_ptr_indir ## dsize ## شمار);                            \
    اگر (درخت_2) {                                                                \
        addr -= درخت_2->start;                                                   \
        اگر (addr >= درخت_2->size) {                                              \
            addr = (size_t)p;                                                  \
            درخت_2 = splay (addr, درخت_2);                                         \
            addr -= درخت_2->start;                                               \
        }                                                                      \
        اگر (addr >= درخت_2->size) {                                              \
            addr = (size_t)p;                                                  \
            درخت_2 = splay_end (addr, درخت_2);                                     \
            addr -= درخت_2->start;                                               \
        }                                                                      \
        اگر (addr <= درخت_2->size) {                                              \
            اگر (درخت_2->is_invalid || addr + offset + dsize > درخت_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)درخت_2->start,            \
                              (long)(درخت_2->start + درخت_2->size - 1));           \
                اگر (never_fatal <= 0)                                          \
                    بازگشت INVALID_POINTER; /* return an invalid pointer */    \
                بازگشت p + offset;                                             \
            }                                                                  \
        }                                                                      \
        وگرنه {                                                                 \
            INCR_شمار(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            بازگشت p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    بازگشت p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic افزودن
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
تهی FASTCALL __bound_local_new(تهی *p1) 
{
    size_t addr, fp, *p = p1;

    اگر (NO_CHECKING_GET())
         بازگشت;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (تهی *)fp);
    WAIT_SEM ();
    وقتی ((addr = p[0])) {
        INCR_شمار(bound_local_new_شمار);
        درخت_2 = splay_درج(addr + fp, p[1], درخت_2);
        p += 2;
    }
    POST_SEM ();
#اگر BOUND_DEBUG
    اگر (print_calls) {
        p = p1;
        وقتی ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (تهی *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
تهی FASTCALL __bound_local_delete(تهی *p1) 
{
    size_t addr, fp, *p = p1;

    اگر (NO_CHECKING_GET())
         بازگشت;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (تهی *)fp);
    WAIT_SEM ();
    وقتی ((addr = p[0])) {
        INCR_شمار(bound_local_delete_شمار);
        درخت_2 = splay_delete(addr + fp, درخت_2);
        p += 2;
    }
    اگر (alloca_list) {
        alloca_list_type *last = پوچ;
        alloca_list_type *cur = alloca_list;

        انجامبده {
            اگر (cur->fp == fp) {
                اگر (last)
                    last->next = cur->next;
                وگرنه
                    alloca_list = cur->next;
                درخت_2 = splay_delete ((size_t) cur->p, درخت_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             وگرنه {
                 last = cur;
                 cur = cur->next;
             }
        } وقتی (cur);
    }
    اگر (jmp_list) {
        jmp_list_type *last = پوچ;
        jmp_list_type *cur = jmp_list;

        انجامبده {
            اگر (cur->fp == fp) {
                اگر (last)
                    last->next = cur->next;
                وگرنه
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            وگرنه {
                last = cur;
                cur = cur->next;
            }
        } وقتی (cur);
    }

    POST_SEM ();
#اگر BOUND_DEBUG
    اگر (print_calls) {
        p = p1;
        وقتی ((addr = p[0])) {
            اگر (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (تهی *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
تهی __bound_new_region(تهی *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    اگر (NO_CHECKING_GET())
        بازگشت;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (اندازه (alloca_list_type));
    WAIT_SEM ();
    INCR_شمار(bound_alloca_شمار);
    last = پوچ;
    cur = alloca_list;
    وقتی (cur) {
#اگر defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحیح align = 4;
#وگرنهاگر defined(__arm__)
        صحیح align = 8;
#وگرنه
        صحیح align = 16;
#endif
        تهی *cure = (تهی *)((نویسه *)cur->p + ((cur->size + align) & -align));
        تهی *pe = (تهی *)((نویسه *)p + ((size + align) & -align));
        اگر (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            اگر (last)
                last->next = cur->next;
            وگرنه
                alloca_list = cur->next;
            درخت_2 = splay_delete((size_t)cur->p, درخت_2);
            بشکن;
        }
        last = cur;
        cur = cur->next;
    }
    درخت_2 = splay_درج((size_t)p, size, درخت_2);
    اگر (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    اگر (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

تهی __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    تهی *e = (تهی *) env;

    اگر (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_شمار(bound_setjmp_شمار);
        jl = jmp_list;
        وقتی (jl) {
            اگر (jl->penv == e)
                بشکن;
            jl = jl->next;
        }
        اگر (jl == پوچ) {
            jl = BOUND_MALLOC (اندازه (jmp_list_type));
            اگر (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        اگر (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ایستا تهی __bound_long_jump(jmp_buf env, صحیح val, صحیح sig, ثابت نویسه *func)
{
    jmp_list_type *jl;
    تهی *e;
    BOUND_TID_TYPE tid;

    اگر (NO_CHECKING_GET() == 0) {
        e = (تهی *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_شمار(bound_longjmp_شمار);
        jl = jmp_list;
        وقتی (jl) {
            اگر (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = پوچ;

                وقتی (cur->penv != e || cur->tid != tid) {
                    اگر (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        اگر (last)
                            last->next = cur->next;
                        وگرنه
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    وگرنه {
                        last = cur;
                        cur = cur->next;
                    }
                }
                برای (;;) {
                    درخت *t = درخت_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    وقتی (t && (t->start < start_fp || t->start > end_fp))
                        اگر (t->start < start_fp)
                            t = t->راست;
                        وگرنه
                            t = t->چپ;
                    اگر (t == پوچ)
                        بشکن;
                    last = پوچ;
                    cur = alloca_list;
                    وقتی (cur) {
                         اگر ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             اگر (last)
                                 last->next = cur->next;
                             وگرنه
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             بشکن;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (تهی *) t->start);
                    درخت_2 = splay_delete(t->start, درخت_2);
                }
                بشکن;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#اگر !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

تهی __bound_longjmp(jmp_buf env, صحیح val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#اگر !defined(_WIN32)
تهی __bound_siglongjmp(jmp_buf env, صحیح val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic برداشت
#endif

تهی __bound_init(size_t *p, صحیح mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    اگر (inited) {
        WAIT_SEM();
        برو add_bounds;
    }
    inited = 1;

#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
    no_checking_کلید = TlsAlloc();
    Tls_Set_مقدار(no_checking_کلید, &no_checking);
#وگرنه
    pthread_key_create(&no_checking_کلید, پوچ);
    pthread_setspecific(no_checking_کلید, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != پوچ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != پوچ;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != پوچ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != پوچ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != پوچ;

    INIT_SEM ();

#اگر MALLOC_REDIR
    {
        تهی *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(تهی **) (&malloc_redir) = dlsym (addr, "malloc");
        اگر (malloc_redir == پوچ) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(تهی **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(تهی **) (&calloc_redir) = dlsym (addr, "calloc");
        *(تهی **) (&free_redir) = dlsym (addr, "free");
        *(تهی **) (&realloc_redir) = dlsym (addr, "realloc");
        *(تهی **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        اگر (malloc_redir == پوچ || free_redir == پوچ)
            bound_alloc_error ("Cannot redirect malloc/free");
#اگر HAVE_PTHREAD_CREATE
        *(تهی **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        اگر (pthread_create_redir == پوچ)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#اگر HAVE_SIGNAL
        *(تهی **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        اگر (signal_redir == پوچ)
            bound_alloc_error ("Cannot redirect signal");
#endif
#اگر HAVE_SIGACTION
        *(تهی **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        اگر (sigaction_redir == پوچ)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#اگر HAVE_FORK
        *(تهی **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        اگر (fork_redir == پوچ)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned نویسه found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        نویسه سطر[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        اگر (fp) {
            memset (exec, 0, اندازه(exec));
            fread (exec, 1, اندازه(exec) - 2, fp);
            اگر (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        اگر (fp) {
            وقتی (fgets (سطر, اندازه(سطر), fp)) {
                اگر (sscanf (سطر, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    بشکن;
                }
                اگر (strstr (سطر,"[heap]"))
                    بشکن;
            }
            fclose (fp);
        }
        اگر (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#اگر HAVE_CTYPE
#ifdef __APPLE__
    درخت_2 = splay_درج((size_t) &_DefaultRuneLocale,
                        اندازه (_DefaultRuneLocale), درخت_2);
#وگرنه
    /* XXX: Does not work if locale is changed */
    درخت_2 = splay_درج((size_t) __ctype_b_loc(),
                        اندازه (unsigned short *), درخت_2);
    درخت_2 = splay_درج((size_t) (*__ctype_b_loc() - 128),
                        384 * اندازه (unsigned short), درخت_2);
    درخت_2 = splay_درج((size_t) __ctype_tolower_loc(),
                        اندازه (__int32_t *), درخت_2);
    درخت_2 = splay_درج((size_t) (*__ctype_tolower_loc() - 128),
                        384 * اندازه (__int32_t), درخت_2);
    درخت_2 = splay_درج((size_t) __ctype_toupper_loc(),
                        اندازه (__int32_t *), درخت_2);
    درخت_2 = splay_درج((size_t) (*__ctype_toupper_loc() - 128),
                        384 * اندازه (__int32_t), درخت_2);
#endif
#endif
#اگر HAVE_ERRNO
    درخت_2 = splay_درج((size_t) (&errno), اندازه (صحیح), درخت_2);
#endif

add_bounds:
    اگر (!p)
        برو no_bounds;

    /* add all static bound check values */
    وقتی (p[0] != 0) {
        درخت_2 = splay_درج(p[0], p[1], درخت_2);
#اگر BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (تهی *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

تهی
#اگر (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(صحیح argc, نویسه **argv, نویسه **envp)
{
    __bound_init (0, -1);
    اگر (argc && argv) {
        صحیح i;

        WAIT_SEM ();
        برای (i = 0; i < argc; i++)
            درخت_2 = splay_درج((size_t) argv[i], strlen (argv[i]) + 1, درخت_2);
        درخت_2 = splay_درج((size_t) argv, (argc + 1) * اندازه(نویسه *), درخت_2);
        POST_SEM ();
#اگر BOUND_DEBUG
        اگر (print_calls) {
            برای (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (صحیح)((argc + 1) * اندازه(نویسه *)));
        }
#endif
    }

    اگر (envp && *envp) {
        نویسه **p = envp;

        WAIT_SEM ();
        وقتی (*p) {
            درخت_2 = splay_درج((size_t) *p, strlen (*p) + 1, درخت_2);
            ++p;
        }
        درخت_2 = splay_درج((size_t) envp, (++p - envp) * اندازه(نویسه *), درخت_2);
        POST_SEM ();
#اگر BOUND_DEBUG
        اگر (print_calls) {
            p = envp;
            وقتی (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (صحیح)((++p - envp) * اندازه(نویسه *)));
        }
#endif
    }
}

تهی __attribute__((destructor)) __bound_exit(تهی)
{
    صحیح i;
    ایستا ثابت نویسه * ثابت alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    اگر (inited) {
#اگر !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        اگر (print_heap) {
            بیرونی تهی __libc_freeres (تهی);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        وقتی (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            درخت_2 = splay_delete ((size_t) alloca_list->p, درخت_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        وقتی (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        برای (i = 0; i < FREE_REUSE_SIZE; i++) {
            اگر (free_reuse_list[i]) {
                درخت_2 = splay_delete ((size_t) free_reuse_list[i], درخت_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        وقتی (درخت_2) {
            اگر (print_heap && درخت_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[درخت_2->type],
                         (unsigned long) درخت_2->size);
            درخت_2 = splay_delete (درخت_2->start, درخت_2);
        }
#اگر درخت_REUSE
        وقتی (درخت_free_list) {
            درخت *next = درخت_free_list->چپ;
            BOUND_FREE (درخت_free_list);
            درخت_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
        TlsFree(no_checking_کلید);
#وگرنه
        pthread_key_delete(no_checking_کلید);
#endif
#endif
        inited = 0;
        اگر (print_statistic) {
#اگر BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_شمار);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_شمار);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_شمار);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_شمار);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_شمار);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_شمار);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_شمار);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_شمار);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_شمار);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_شمار);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_شمار);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_شمار);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_شمار);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_شمار);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_شمار);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_شمار);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_شمار);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_شمار);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_شمار);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_شمار);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_شمار);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_شمار);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_شمار);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_شمار);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_شمار);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_شمار);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_شمار);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_شمار);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_شمار);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_شمار);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_شمار);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_شمار);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_شمار);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#اگر BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_درج);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

تهی __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    اگر (p) {
        WAIT_SEM ();
	وقتی (p[0] != 0) {
	    درخت_2 = splay_delete(p[0], درخت_2);
#اگر BOUND_DEBUG
            اگر (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (تهی *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#اگر HAVE_PTHREAD_CREATE
تعریفنوع ساختار {
    تهی *(*start_routine) (تهی *);
    تهی *arg;
    sigset_t old_mask;
} bound_thread_create_type;

ایستا تهی *bound_thread_create(تهی *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    تهی *retval;
#اگر HAVE_TLS_FUNC
    صحیح *p = (صحیح *) BOUND_MALLOC(اندازه(صحیح));
  
    اگر (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_کلید, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, پوچ);
    retval = data->start_routine(data->arg);
#اگر HAVE_TLS_FUNC
    pthread_setspecific(no_checking_کلید, پوچ);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    بازگشت retval;
}

صحیح pthread_create(pthread_t *thread, ثابت pthread_attr_t *attr,
                   تهی *(*start_routine) (تهی *), تهی *arg)
{
    صحیح retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(اندازه(bound_thread_create_type));
    اگر (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, پوچ);
    بازگشت retval;
}
#endif

#اگر HAVE_SIGNAL || HAVE_SIGACTION
تعریفنوع اجتماع {
#اگر HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#اگر HAVE_SIGACTION
    تهی (*sig_handler)(صحیح);
    تهی (*sig_sigaction)(صحیح, siginfo_t *, تهی *);
#endif
} bound_sig_type;

ایستا unsigned نویسه bound_sig_used[NSIG];
ایستا bound_sig_type bound_sig_data[NSIG];
#endif

#اگر HAVE_SIGNAL
ایستا تهی signal_handler(صحیح sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig سیگنال(صحیح signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    اگر (retval != SIG_ERR) {
        اگر (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        اگر (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    بازگشت retval;
}
#endif

#اگر HAVE_SIGACTION
ایستا تهی sig_handler(صحیح sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ایستا تهی sig_sigaction(صحیح sig, siginfo_t *info, تهی *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

صحیح sigaction(صحیح signum, ثابت ساختار sigaction *act, ساختار sigaction *oldact)
{
    صحیح retval;
    ساختار sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    اگر (sigaction_redir == پوچ)
        __bound_init(0,-1);

    اگر (act) {
        nact = *act;
        اگر (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        وگرنه
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    وگرنه
        retval = sigaction_redir(signum, act, &oact);
    اگر (retval >= 0) {
        اگر (bound_sig_used[signum]) {
            اگر (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            وگرنه
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        اگر (oldact) {
            *oldact = oact;
        }
        اگر (act) {
            bound_sig_used[signum] = 1;
            اگر (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            وگرنه
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    بازگشت retval;
}
#endif

#اگر HAVE_FORK
pid_t fork(تهی)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    اگر (retval == 0)
        INIT_SEM();
    وگرنه
        POST_SEM();
    بازگشت retval;
}
#endif

#اگر MALLOC_REDIR
تهی *malloc(size_t size)
#وگرنه
تهی *__bound_malloc(size_t size, ثابت تهی *caller)
#endif
{
    تهی *ptr;
    
#اگر MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    اگر (malloc_redir == پوچ) {
        __bound_init (0, -1);
        اگر (malloc_redir == پوچ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            اگر (pool_index >= اندازه (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            بازگشت ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    اگر (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_malloc_شمار);

        اگر (ptr) {
            درخت_2 = splay_درج ((size_t) ptr, size ? size : size + 1, درخت_2);
            اگر (درخت_2 && درخت_2->start == (size_t) ptr)
                درخت_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    بازگشت ptr;
}

#اگر MALLOC_REDIR
تهی *memalign(size_t align, size_t size)
#وگرنه
تهی *__bound_memalign(size_t align, size_t size, ثابت تهی *caller)
#endif
{
    تهی *ptr;

#اگر HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#وگرنه
    اگر (align > 4) {
        /* XXX: handle it ? */
        ptr = پوچ;
    } وگرنه {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    اگر (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_memalign_شمار);

        اگر (ptr) {
            درخت_2 = splay_درج((size_t) ptr, size ? size : size + 1, درخت_2);
            اگر (درخت_2 && درخت_2->start == (size_t) ptr)
                درخت_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    بازگشت ptr;
}

#اگر MALLOC_REDIR
تهی آزاد(تهی *ptr)
#وگرنه
تهی __bound_free(تهی *ptr, ثابت تهی *caller)
#endif
{
    size_t addr = (size_t) ptr;
    تهی *p;

    اگر (ptr == پوچ || درخت_2 == پوچ
#اگر MALLOC_REDIR
        || ((unsigned نویسه *) ptr >= &initial_pool[0] &&
            (unsigned نویسه *) ptr < &initial_pool[اندازه(initial_pool)])
#endif
        )
        بازگشت;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    اگر (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_free_شمار);
        درخت_2 = splay (addr, درخت_2);
        اگر (درخت_2->start == addr) {
            اگر (درخت_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                بازگشت;
            }
            درخت_2->is_invalid = 1;
            memset (ptr, 0x5a, درخت_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            اگر (p)
                درخت_2 = splay_delete((size_t)p, درخت_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#اگر MALLOC_REDIR
تهی *realloc(تهی *ptr, size_t size)
#وگرنه
تهی *__bound_realloc(تهی *ptr, size_t size, ثابت تهی *caller)
#endif
{
    تهی *new_ptr;

    اگر (size == 0) {
#اگر MALLOC_REDIR
        آزاد(ptr);
#وگرنه
        __bound_free(ptr, caller);
#endif
        بازگشت پوچ;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    اگر (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_realloc_شمار);

        اگر (ptr)
            درخت_2 = splay_delete ((size_t) ptr, درخت_2);
        اگر (new_ptr) {
            درخت_2 = splay_درج ((size_t) new_ptr, size ? size : size + 1, درخت_2);
            اگر (درخت_2 && درخت_2->start == (size_t) new_ptr)
                درخت_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    بازگشت new_ptr;
}

#اگر MALLOC_REDIR
تهی *calloc(size_t nmemb, size_t size)
#وگرنه
تهی *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    تهی *ptr;

    size *= nmemb;
#اگر MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    اگر (malloc_redir == پوچ) {
        __bound_init (0, -1);
        اگر (malloc_redir == پوچ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            اگر (pool_index >= اندازه (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            بازگشت ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    اگر (ptr) {
        memset (ptr, 0, size);
        اگر (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_شمار(bound_calloc_شمار);
            درخت_2 = splay_درج ((size_t) ptr, size ? size : size + 1, درخت_2);
            اگر (درخت_2 && درخت_2->start == (size_t) ptr)
                درخت_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    بازگشت ptr;
}

#اگر !defined(_WIN32)
تهی *__bound_mmap (تهی *start, size_t size, صحیح prot,
                    صحیح flags, صحیح fd, off_t offset)
{
    تهی *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    اگر (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_mmap_شمار);
        درخت_2 = splay_درج((size_t)result, size, درخت_2);
        POST_SEM ();
    }
    بازگشت result;
}

صحیح __bound_munmap (تهی *start, size_t size)
{
    صحیح result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    اگر (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمار(bound_munmap_شمار);
        درخت_2 = splay_delete ((size_t) start, درخت_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    بازگشت result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ایستا تهی __bound_check(ثابت تهی *p, size_t size, ثابت نویسه *function)
{
    اگر (size != 0 && __bound_ptr_add((تهی *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

ایستا صحیح check_overlap (ثابت تهی *p1, size_t n1,
                          ثابت تهی *p2, size_t n2,
                          ثابت نویسه *function)
{
    ثابت تهی *p1e = (ثابت تهی *) ((ثابت نویسه *) p1 + n1);
    ثابت تهی *p2e = (ثابت تهی *) ((ثابت نویسه *) p2 + n2);

    اگر (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        بازگشت never_fatal < 0;
    }
    بازگشت 0;
}

تهی *__bound_memcpy(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_mempcy_شمار);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    اگر (check_overlap(dest, n, src, n, "memcpy"))
        بازگشت dest;
    بازگشت memcpy(dest, src, n);
}

صحیح __bound_memcmp(ثابت تهی *s1, ثابت تهی *s2, size_t n)
{
    ثابت unsigned نویسه *u1 = (ثابت unsigned نویسه *) s1;
    ثابت unsigned نویسه *u2 = (ثابت unsigned نویسه *) s2;
    صحیح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_شمار(bound_memcmp_شمار);
    برای (;;) {
        اگر ((ssize_t) --n == -1)
            بشکن;
        وگرنه اگر (*u1 != *u2) {
            retval = *u1++ - *u2++;
            بشکن;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ثابت تهی *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ثابت تهی *)u2 - s2, "memcmp s2");
    بازگشت retval;
}

تهی *__bound_memmove(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_memmove_شمار);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    بازگشت memmove(dest, src, n);
}

تهی *__bound_memset(تهی *s, صحیح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_شمار(bound_memset_شمار);
    __bound_check(s, n, "memset");
    بازگشت memset(s, c, n);
}

#اگر defined(__arm__) && defined(__ARM_EABI__)
تهی *__bound___aeabi_memcpy(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_mempcy_شمار);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    اگر (check_overlap(dest, n, src, n, "memcpy"))
        بازگشت dest;
    بازگشت __aeabi_memcpy(dest, src, n);
}

تهی *__bound___aeabi_memmove(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_memmove_شمار);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    بازگشت __aeabi_memmove(dest, src, n);
}

تهی *__bound___aeabi_memmove4(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_memmove_شمار);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    بازگشت __aeabi_memmove4(dest, src, n);
}

تهی *__bound___aeabi_memmove8(تهی *dest, ثابت تهی *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_memmove_شمار);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    بازگشت __aeabi_memmove8(dest, src, n);
}

تهی *__bound___aeabi_memset(تهی *s, صحیح c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_شمار(bound_memset_شمار);
    __bound_check(s, n, "memset");
    بازگشت __aeabi_memset(s, c, n);
}
#endif

صحیح __bound_strlen(ثابت نویسه *s)
{
    ثابت نویسه *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_شمار(bound_strlen_شمار);
    وقتی (*p++);
    __bound_check(s, p - s, "strlen");
    بازگشت (p - s) - 1;
}

نویسه *__bound_strcpy(نویسه *dest, ثابت نویسه *src)
{
    size_t len;
    ثابت نویسه *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_شمار(bound_strcpy_شمار);
    وقتی (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    اگر (check_overlap(dest, len, src, len, "strcpy"))
        بازگشت dest;
    بازگشت strcpy (dest, src);
}

نویسه *__bound_strncpy(نویسه *dest, ثابت نویسه *src, size_t n)
{
    size_t len = n;
    ثابت نویسه *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_strncpy_شمار);
    وقتی (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    اگر (check_overlap(dest, len, src, len, "strncpy"))
        بازگشت dest;
    بازگشت strncpy(dest, src, n);
}

صحیح __bound_strcmp(ثابت نویسه *s1, ثابت نویسه *s2)
{
    ثابت unsigned نویسه *u1 = (ثابت unsigned نویسه *) s1;
    ثابت unsigned نویسه *u2 = (ثابت unsigned نویسه *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_شمار(bound_strcmp_شمار);
    وقتی (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت نویسه *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت نویسه *)u2 - s2) + 1, "strcmp s2");
    بازگشت *u1 - *u2;
}

صحیح __bound_strncmp(ثابت نویسه *s1, ثابت نویسه *s2, size_t n)
{
    ثابت unsigned نویسه *u1 = (ثابت unsigned نویسه *) s1;
    ثابت unsigned نویسه *u2 = (ثابت unsigned نویسه *) s2;
    صحیح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_شمار(bound_strncmp_شمار);
    انجامبده {
        اگر ((ssize_t) --n == -1)
            بشکن;
        وگرنه اگر (*u1 != *u2) {
            retval = *u1++ - *u2++;
            بشکن;
        }
        ++u2;
    } وقتی (*u1++);
    __bound_check(s1, (ثابت نویسه *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ثابت نویسه *)u2 - s2, "strncmp s2");
    بازگشت retval;
}

نویسه *__bound_strcat(نویسه *dest, ثابت نویسه *src)
{
    نویسه *r = dest;
    ثابت نویسه *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_شمار(bound_strcat_شمار);
    وقتی (*dest++);
    وقتی (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    اگر (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        بازگشت dest;
    بازگشت strcat(r, s);
}

نویسه *__bound_strncat(نویسه *dest, ثابت نویسه *src, size_t n)
{
    نویسه *r = dest;
    ثابت نویسه *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_شمار(bound_strncat_شمار);
    وقتی (*dest++);
    وقتی (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    اگر (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        بازگشت dest;
    بازگشت strncat(r, s, n);
}

نویسه *__bound_strchr(ثابت نویسه *s, صحیح c)
{
    ثابت unsigned نویسه *str = (ثابت unsigned نویسه *) s;
    unsigned نویسه ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_شمار(bound_strchr_شمار);
    وقتی (*str) {
        اگر (*str == ch)
            بشکن;
        ++str;
    }
    __bound_check(s, ((ثابت نویسه *)str - s) + 1, "strchr");
    بازگشت *str == ch ? (نویسه *) str : پوچ;
}

نویسه *__bound_strrchr(ثابت نویسه *s, صحیح c)
{
    ثابت unsigned نویسه *str = (ثابت unsigned نویسه *) s;
    unsigned نویسه ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_شمار(bound_strrchr_شمار);
    وقتی (*str++);
    __bound_check(s, (ثابت نویسه *)str - s, "strrchr");
    وقتی (str != (ثابت unsigned نویسه *)s) {
        اگر (*--str == ch)
            بشکن;
    }
    __bound_check(s, (ثابت نویسه *)str - s, "strrchr");
    بازگشت *str == ch ? (نویسه *) str : پوچ;
}

نویسه *__bound_strdup(ثابت نویسه *s)
{
    ثابت نویسه *p = s;
    نویسه *new;

    INCR_شمار(bound_strdup_شمار);
    وقتی (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    اگر (new) {
        اگر (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            درخت_2 = splay_درج((size_t)new, p - s, درخت_2);
            اگر (درخت_2 && درخت_2->start == (size_t) new)
                درخت_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    بازگشت new;
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

ایستا درخت * splay (size_t addr, درخت *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    درخت N, *l, *r, *y;
    صحیح comp;
    
    INCR_شمار_SPLAY(bound_splay);
    اگر (t == پوچ) بازگشت t;
    N.چپ = N.راست = پوچ;
    l = r = &N;
 
    برای (;;) {
        comp = compare(addr, t->start, t->size);
        اگر (comp < 0) {
            y = t->چپ;
            اگر (y == پوچ) بشکن;
            اگر (compare(addr, y->start, y->size) < 0) {
                t->چپ = y->راست;                    /* rotate right */
                y->راست = t;
                t = y;
                اگر (t->چپ == پوچ) بشکن;
            }
            r->چپ = t;                               /* link right */
            r = t;
            t = t->چپ;
        } وگرنه اگر (comp > 0) {
            y = t->راست;
            اگر (y == پوچ) بشکن;
            اگر (compare(addr, y->start, y->size) > 0) {
                t->راست = y->چپ;                    /* rotate left */
                y->چپ = t;
                t = y;
                اگر (t->راست == پوچ) بشکن;
            }
            l->راست = t;                              /* link left */
            l = t;
            t = t->راست;
        } وگرنه {
            بشکن;
        }
    }
    l->راست = t->چپ;                                /* assemble */
    r->چپ = t->راست;
    t->چپ = N.راست;
    t->راست = N.چپ;

    بازگشت t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

ایستا درخت * splay_end (size_t addr, درخت *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    درخت N, *l, *r, *y;
    صحیح comp;
    
    INCR_شمار_SPLAY(bound_splay_end);
    اگر (t == پوچ) بازگشت t;
    N.چپ = N.راست = پوچ;
    l = r = &N;
 
    برای (;;) {
        comp = compare_end(addr, t->start + t->size);
        اگر (comp < 0) {
            y = t->چپ;
            اگر (y == پوچ) بشکن;
            اگر (compare_end(addr, y->start + y->size) < 0) {
                t->چپ = y->راست;                    /* rotate right */
                y->راست = t;
                t = y;
                اگر (t->چپ == پوچ) بشکن;
            }
            r->چپ = t;                               /* link right */
            r = t;
            t = t->چپ;
        } وگرنه اگر (comp > 0) {
            y = t->راست;
            اگر (y == پوچ) بشکن;
            اگر (compare_end(addr, y->start + y->size) > 0) {
                t->راست = y->چپ;                    /* rotate left */
                y->چپ = t;
                t = y;
                اگر (t->راست == پوچ) بشکن;
            }
            l->راست = t;                              /* link left */
            l = t;
            t = t->راست;
        } وگرنه {
            بشکن;
        }
    }
    l->راست = t->چپ;                                /* assemble */
    r->چپ = t->راست;
    t->چپ = N.راست;
    t->راست = N.چپ;

    بازگشت t;
}

ایستا درخت * splay_درج(size_t addr, size_t size, درخت * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    درخت * new;

    INCR_شمار_SPLAY(bound_splay_درج);
    اگر (t != پوچ) {
        t = splay(addr,t);
        اگر (compare(addr, t->start, t->size)==0) {
            بازگشت t;  /* it's already there */
        }
    }
#اگر درخت_REUSE
    اگر (درخت_free_list) {
          new = درخت_free_list;
          درخت_free_list = new->چپ;
    }
    وگرنه
#endif
    {
        new = (درخت *) BOUND_MALLOC (اندازه (درخت));
    }
    اگر (new == پوچ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    وگرنه {
        اگر (t == پوچ) {
            new->چپ = new->راست = پوچ;
        } وگرنه اگر (compare(addr, t->start, t->size) < 0) {
            new->چپ = t->چپ;
            new->راست = t;
            t->چپ = پوچ;
        } وگرنه {
            new->راست = t->راست;
            new->چپ = t;
            t->راست = پوچ;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    بازگشت new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

ایستا درخت * splay_delete(size_t addr, درخت *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    درخت * x;

    INCR_شمار_SPLAY(bound_splay_delete);
    اگر (t==پوچ) بازگشت پوچ;
    t = splay(addr,t);
    اگر (compare_destroy(addr, t->start) == 0) {        /* found it */
        اگر (t->چپ == پوچ) {
            x = t->راست;
        } وگرنه {
            x = splay(addr, t->چپ);
            x->راست = t->راست;
        }
#اگر درخت_REUSE
        t->چپ = درخت_free_list;
        درخت_free_list = t;
#وگرنه
        BOUND_FREE(t);
#endif
        بازگشت x;
    } وگرنه {
        بازگشت t;                                      /* It wasn't there */
    }
}

تهی splay_printtree(درخت * t, صحیح d)
{
    صحیح i;
    اگر (t == پوچ) بازگشت;
    splay_printtree(t->راست, d+1);
    برای (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (تهی *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->چپ, d+1);
}
