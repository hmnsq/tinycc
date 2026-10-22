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

#إذا !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ضمن <malloc.h>
#جيڪڏهن_پورو

#إذا !defined(_WIN32)
#ضمن <unistd.h>
#ضمن <sys/syscall.h>
#جيڪڏهن_پورو

#ضمن "config.h"

#وصف_ڪريو BOUND_DEBUG             (1)
#وصف_ڪريو BOUND_STATISTIC         (1)

#إذا BOUND_DEBUG
 #وصف_ڪريو dprintf(a...)         إذا (print_calls) { bounds_loc(a); }
#وإلا
 #وصف_ڪريو dprintf(a...)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #وصف_رد __attribute__ 
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل __i386__
#وصف_ڪريو FASTCALL __attribute__((regparm(3)))
#وإلا
#وصف_ڪريو FASTCALL
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وإلا
# define DLL_EXPORT
#جيڪڏهن_پورو

#إذا defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ضمن <sys/mman.h>
#وصف_ڪريو INIT_SEM()
#وصف_ڪريو EXIT_SEM()
#وصف_ڪريو WAIT_SEM()
#وصف_ڪريو POST_SEM()
#وصف_ڪريو TRY_SEM()
#وصف_ڪريو HAVE_MEMALIGN          (0)
#وصف_ڪريو MALLOC_REDIR           (0)
#وصف_ڪريو HAVE_PTHREAD_CREATE    (0)
#وصف_ڪريو HAVE_CTYPE             (0)
#وصف_ڪريو HAVE_ERRNO             (0)
#وصف_ڪريو HAVE_SIGNAL            (0)
#وصف_ڪريو HAVE_SIGACTION         (0)
#وصف_ڪريو HAVE_FORK              (0)
#وصف_ڪريو HAVE_TLS_FUNC          (0)
#وصف_ڪريو HAVE_TLS_VAR           (0)

#وإلاإذا defined(_WIN32)

#ضمن <windows.h>
#ضمن <signal.h>
ساكن CRITICAL_SECTION bounds_sem;
#وصف_ڪريو INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#وصف_ڪريو EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#وصف_ڪريو WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#وصف_ڪريو POST_SEM()             LeaveCriticalSection(&bounds_sem)
#وصف_ڪريو TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#وصف_ڪريو HAVE_MEMALIGN          (0)
#وصف_ڪريو MALLOC_REDIR           (0)
#وصف_ڪريو HAVE_PTHREAD_CREATE    (0)
#وصف_ڪريو HAVE_CTYPE             (0)
#وصف_ڪريو HAVE_ERRNO             (0)
#وصف_ڪريو HAVE_SIGNAL            (1)
#وصف_ڪريو HAVE_SIGACTION         (0)
#وصف_ڪريو HAVE_FORK              (0)
#وصف_ڪريو HAVE_TLS_FUNC          (1)
#وصف_ڪريو HAVE_TLS_VAR           (0)

#وإلا

#وصف_ڪريو __USE_GNU              /* get RTLD_NEXT */
#ضمن <sys/mman.h>
#ضمن <ctype.h>
#ضمن <pthread.h>
#ضمن <dlfcn.h>
#ضمن <errno.h>
#ضمن <signal.h>
#جيڪڏهن_وصف_ٿيل __APPLE__
#ضمن <dispatch/dispatch.h>
ساكن dispatch_semaphore_t bounds_sem;
#وصف_ڪريو INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#وصف_ڪريو EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#وصف_ڪريو WAIT_SEM()             إذا (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وقت_FOREVER)
#وصف_ڪريو POST_SEM()             إذا (use_sem) dispatch_semaphore_signal(bounds_sem)
#وصف_ڪريو TRY_SEM()              إذا (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وقت_NOW)
#وإلاإذا 0
#ضمن <semaphore.h>
ساكن sem_t bounds_sem;
#وصف_ڪريو INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#وصف_ڪريو EXIT_SEM()             sem_destroy (&bounds_sem)
#وصف_ڪريو WAIT_SEM()             إذا (use_sem) طالما (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وصف_ڪريو POST_SEM()             إذا (use_sem) sem_post (&bounds_sem)
#وصف_ڪريو TRY_SEM()              إذا (use_sem) طالما (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وإلاإذا 0
ساكن pthread_mutex_t bounds_mtx;
#وصف_ڪريو INIT_SEM()             pthread_mutex_init (&bounds_mtx, عدم)
#وصف_ڪريو EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#وصف_ڪريو WAIT_SEM()             إذا (use_sem) pthread_mutex_lock (&bounds_mtx)
#وصف_ڪريو POST_SEM()             إذا (use_sem) pthread_mutex_unlock (&bounds_mtx)
#وصف_ڪريو TRY_SEM()              إذا (use_sem) pthread_mutex_trylock (&bounds_mtx)
#وإلا
ساكن pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#وصف_ڪريو INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#وصف_ڪريو EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#وصف_ڪريو WAIT_SEM()             إذا (use_sem) pthread_spin_lock (&bounds_spin)
#وصف_ڪريو POST_SEM()             إذا (use_sem) pthread_spin_unlock (&bounds_spin)
#وصف_ڪريو TRY_SEM()              إذا (use_sem) pthread_spin_trylock (&bounds_spin)
#جيڪڏهن_پورو
#وصف_ڪريو HAVE_MEMALIGN          (1)
#وصف_ڪريو MALLOC_REDIR           (1)
#وصف_ڪريو HAVE_PTHREAD_CREATE    (1)
#وصف_ڪريو HAVE_CTYPE             (1)
#وصف_ڪريو HAVE_ERRNO             (1)
#وصف_ڪريو HAVE_SIGNAL            (1)
#وصف_ڪريو HAVE_SIGACTION         (1)
#وصف_ڪريو HAVE_FORK              (1)
#إذا defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_لاڳيتو)
#وصف_ڪريو HAVE_TLS_FUNC          (1)
#وصف_ڪريو HAVE_TLS_VAR           (0)
#وإلا
#وصف_ڪريو HAVE_TLS_FUNC          (0)
#وصف_ڪريو HAVE_TLS_VAR           (1)
#جيڪڏهن_پورو
#إذا defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا MALLOC_REDIR
ساكن فراغ *(*malloc_redir) (سائيز_t);
ساكن فراغ *(*calloc_redir) (سائيز_t, سائيز_t);
ساكن فراغ (*free_redir) (فراغ *);
ساكن فراغ *(*realloc_redir) (فراغ *, سائيز_t);
ساكن بنانشان صحيح pool_اشاريو;
ساكن بنانشان حرف __attribute__((aligned(16))) initial_pool[256];
#جيڪڏهن_پورو
#إذا HAVE_MEMALIGN
ساكن فراغ *(*memalign_redir) (سائيز_t, سائيز_t);
#جيڪڏهن_پورو
#إذا HAVE_PTHREAD_CREATE
ساكن صحيح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    فراغ *(*شروعات_routine)(فراغ *), فراغ *arg);
#جيڪڏهن_پورو
#إذا HAVE_SIGNAL
تعريفنوع فراغ (*bound_sig)(صحيح);
ساكن bound_sig (*signal_redir) (صحيح signum, bound_sig handler);
#جيڪڏهن_پورو
#إذا HAVE_SIGACTION
ساكن صحيح (*sigaction_redir) (صحيح signum, ثابت بنية sigaction *act,
                               بنية sigaction *oldact);
#جيڪڏهن_پورو
#إذا HAVE_FORK
ساكن صحيح (*fork_redir) (فراغ);
#جيڪڏهن_پورو

#وصف_ڪريو TCC_TYPE_NONE           (0)
#وصف_ڪريو TCC_TYPE_MALLOC         (1)
#وصف_ڪريو TCC_TYPE_CALLOC         (2)
#وصف_ڪريو TCC_TYPE_REALLOC        (3)
#وصف_ڪريو TCC_TYPE_MEMALIGN       (4)
#وصف_ڪريو TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#وصف_ڪريو INVALID_اشارو ((فراغ *)(-2))

تعريفنوع بنية وڻ_ڳنڍ وڻ;
بنية وڻ_ڳنڍ {
    وڻ * کاٻو, * ساڄو;
    سائيز_t شروعات;
    سائيز_t سائيز;
    بنانشان حرف type;
    بنانشان حرف is_invalid; /* true if pointers outside region are invalid */
};

تعريفنوع بنية alloca_list_struct {
    سائيز_t fp;
    فراغ *p;
    سائيز_t سائيز;
    بنية alloca_list_struct *ايندڙ;
} alloca_list_type;

#إذا defined(_WIN32)
#وصف_ڪريو BOUND_TID_TYPE		DWORD
#وصف_ڪريو BOUND_GET_TID(id)	id = GetCurrentThreadId()
#وإلاإذا defined(__OpenBSD__)
#وصف_ڪريو BOUND_TID_TYPE		pid_t
#وصف_ڪريو BOUND_GET_TID(id)	id = getthrid()
#وإلاإذا defined(__FreeBSD__)
#وصف_ڪريو BOUND_TID_TYPE		pid_t
#وصف_ڪريو BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#وإلاإذا  defined(__NetBSD__)
#وصف_ڪريو BOUND_TID_TYPE		pid_t
#وصف_ڪريو BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#وإلاإذا defined(__linux__)
#وصف_ڪريو BOUND_TID_TYPE		pid_t
#وصف_ڪريو BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#وإلا
#وصف_ڪريو BOUND_TID_TYPE		صحيح
#وصف_ڪريو BOUND_GET_TID(id)	id = 0
#جيڪڏهن_پورو

تعريفنوع بنية jmp_list_struct {
    فراغ *penv;
    سائيز_t fp;
    سائيز_t پڇاڙي_fp;
    BOUND_TID_TYPE tid;
    بنية jmp_list_struct *ايندڙ;
} jmp_list_type;

#وصف_ڪريو BOUND_STATISTIC_SPLAY   (0)
ساكن وڻ * splay (سائيز_t addr, وڻ *t);
ساكن وڻ * splay_پڇاڙي (سائيز_t addr, وڻ *t);
ساكن وڻ * splay_وجهو(سائيز_t addr, سائيز_t سائيز, وڻ * t);
ساكن وڻ * splay_delete(سائيز_t addr, وڻ *t);
فراغ splay_printtree(وڻ * t, صحيح d);

/* external interface */
فراغ __bounds_checking (صحيح no_check);
فراغ __bound_checking_lock (فراغ);
فراغ __bound_checking_unlock (فراغ);
فراغ __bound_never_fatal (صحيح no_check);
DLL_EXPORT فراغ * __bound_ptr_add(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir1(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir2(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir4(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir8(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir12(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ * __bound_ptr_indir16(فراغ *p, سائيز_t وٿي);
DLL_EXPORT فراغ FASTCALL __bound_local_new(فراغ *p1);
DLL_EXPORT فراغ FASTCALL __bound_local_delete(فراغ *p1);
فراغ __bound_init(سائيز_t *, صحيح);
فراغ __bound_main_arg(صحيح argc, حرف **argv, حرف **envp);
فراغ __bound_exit(فراغ);
فراغ __bound_exit_dll(سائيز_t *);
#إذا !defined(_WIN32)
فراغ *__bound_mmap (فراغ *شروعات, سائيز_t سائيز, صحيح prot, صحيح flags, صحيح fd,
                    off_t وٿي);
صحيح __bound_munmap (فراغ *شروعات, سائيز_t سائيز);
DLL_EXPORT فراغ __bound_siglongjmp(jmp_buf env, صحيح val);
#جيڪڏهن_پورو
DLL_EXPORT فراغ __bound_new_region(فراغ *p, سائيز_t سائيز);
DLL_EXPORT فراغ __bound_setjmp(jmp_buf env);
DLL_EXPORT فراغ __bound_longjmp(jmp_buf env, صحيح val);
DLL_EXPORT فراغ *__bound_memcpy(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound_memmove(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound_memset(فراغ *dst, صحيح c, سائيز_t سائيز);
DLL_EXPORT صحيح __bound_strlen(ثابت حرف *s);
DLL_EXPORT حرف *__bound_strcpy(حرف *dst, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncpy(حرف *dst, ثابت حرف *src, سائيز_t n);
DLL_EXPORT صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2);
DLL_EXPORT صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, سائيز_t n);
DLL_EXPORT حرف *__bound_strcat(حرف *dest, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncat(حرف *dest, ثابت حرف *src, سائيز_t n);
DLL_EXPORT حرف *__bound_strchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strrchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strdup(ثابت حرف *s);

#إذا defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT فراغ *__bound___aeabi_memcpy(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound___aeabi_memmove(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound___aeabi_memmove4(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound___aeabi_memmove8(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__bound___aeabi_memset(فراغ *dst, صحيح c, سائيز_t سائيز);
DLL_EXPORT فراغ *__aeabi_memcpy(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__aeabi_memmove(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__aeabi_memmove4(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__aeabi_memmove8(فراغ *dst, ثابت فراغ *src, سائيز_t سائيز);
DLL_EXPORT فراغ *__aeabi_memset(فراغ *dst, صحيح c, سائيز_t سائيز);
#جيڪڏهن_پورو

#إذا MALLOC_REDIR
#وصف_ڪريو BOUND_MALLOC(a)          malloc_redir(a)
#وصف_ڪريو BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#وصف_ڪريو BOUND_FREE(a)            free_redir(a)
#وصف_ڪريو BOUND_REALLOC(a,b)       realloc_redir(a,b)
#وصف_ڪريو BOUND_CALLOC(a,b)        calloc_redir(a,b)
#وإلا
#وصف_ڪريو BOUND_MALLOC(a)          يادگيري_ڏيو(a)
#وصف_ڪريو BOUND_MEMALIGN(a,b)      memalign(a,b)
#وصف_ڪريو BOUND_FREE(a)            حرر(a)
#وصف_ڪريو BOUND_REALLOC(a,b)       realloc(a,b)
#وصف_ڪريو BOUND_CALLOC(a,b)        صفر_يادگيري_ڏيو(a,b)
DLL_EXPORT فراغ *__bound_malloc(سائيز_t سائيز, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_memalign(سائيز_t align, سائيز_t سائيز, ثابت فراغ *caller);
DLL_EXPORT فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_realloc(فراغ *ptr, سائيز_t سائيز, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_calloc(سائيز_t nmemb, سائيز_t سائيز);
#جيڪڏهن_پورو

#وصف_ڪريو FREE_REUSE_سائيز (100)
ساكن بنانشان صحيح free_reuse_اشاريو;
ساكن فراغ *free_reuse_list[FREE_REUSE_سائيز];

ساكن وڻ *وڻ_2 = عدم;
#وصف_ڪريو وڻ_REUSE      (1)
#إذا وڻ_REUSE
ساكن وڻ *وڻ_free_list;
#جيڪڏهن_پورو
ساكن alloca_list_type *alloca_list;
ساكن jmp_list_type *jmp_list;

ساكن بنانشان حرف inited;
ساكن بنانشان حرف print_warn_ptr_جوڙيو;
ساكن بنانشان حرف print_calls;
ساكن بنانشان حرف print_ڍير;
ساكن بنانشان حرف print_statistic;
ساكن بنانشان حرف no_strdup;
ساكن بنانشان حرف use_sem;
ساكن _Atomic صحيح never_fatal;
#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
ساكن صحيح no_checking = 0;
ساكن DWORD no_checking_ڪنجي;
#وصف_ڪريو NO_CHECKING_CHECK() إذا (!p) {                                         \
                                  p = (صحيح *) LocalAlloc(LPTR, حجم(صحيح));  \
                                  إذا (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_سيٽ_قدر(no_checking_ڪنجي, p);            \
                            }
#وصف_ڪريو NO_CHECKING_GET()   ({ صحيح *p = Tls_Get_قدر(no_checking_ڪنجي);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#وصف_ڪريو NO_CHECKING_سيٽ(v)  { صحيح *p = Tls_Get_قدر(no_checking_ڪنجي);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#وإلا
ساكن صحيح no_checking = 0;
ساكن pthread_key_t no_checking_ڪنجي;
#وصف_ڪريو NO_CHECKING_CHECK() إذا (!p) {                                         \
                                  p = (صحيح *) BOUND_MALLOC(حجم(صحيح));      \
                                  إذا (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ڪنجي, p);    \
                            }
#وصف_ڪريو NO_CHECKING_GET()   ({ صحيح *p = pthread_getspecific(no_checking_ڪنجي); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#وصف_ڪريو NO_CHECKING_سيٽ(v)  { صحيح *p = pthread_getspecific(no_checking_ڪنجي);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#جيڪڏهن_پورو
#وإلاإذا HAVE_TLS_VAR
ساكن __thread صحيح no_checking = 0;
#وصف_ڪريو NO_CHECKING_GET()  no_checking
#وصف_ڪريو NO_CHECKING_سيٽ(v) no_checking = v 
#وإلا
ساكن _Atomic صحيح no_checking = 0;
#وصف_ڪريو NO_CHECKING_GET()  no_checking
#وصف_ڪريو NO_CHECKING_سيٽ(v) no_checking = v 
#جيڪڏهن_پورو
ساكن حرف exec[100];

#إذا BOUND_STATISTIC
ساكن بنانشان ڊگهو ڊگهو bound_ptr_جوڙيو_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir1_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir2_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir4_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir8_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir12_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_ptr_indir16_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_local_new_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_local_delete_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_malloc_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_calloc_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_realloc_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_free_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_memalign_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_mmap_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_munmap_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_alloca_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_setjmp_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_longjmp_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_mempcy_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_memcmp_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_memmove_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_memset_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strlen_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strcpy_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strncpy_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strcmp_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strncmp_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strcat_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strncat_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strchr_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strrchr_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_strdup_ڳڻپ;
ساكن بنانشان ڊگهو ڊگهو bound_not_مليو;
#وصف_ڪريو INCR_ڳڻپ(x)          ++x
#وإلا
#وصف_ڪريو INCR_ڳڻپ(x)
#جيڪڏهن_پورو
#إذا BOUND_STATISTIC_SPLAY
ساكن بنانشان ڊگهو ڊگهو bound_splay;
ساكن بنانشان ڊگهو ڊگهو bound_splay_پڇاڙي;
ساكن بنانشان ڊگهو ڊگهو bound_splay_وجهو;
ساكن بنانشان ڊگهو ڊگهو bound_splay_delete;
#وصف_ڪريو INCR_ڳڻپ_SPLAY(x)    ++x
#وإلا
#وصف_ڪريو INCR_ڳڻپ_SPLAY(x)
#جيڪڏهن_پورو

صحيح tcc_backtrace(ثابت حرف *fmt, ...);

/* print a bound error message */
#وصف_ڪريو bound_warning(...) \
    افعل {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } طالما (0)

#وصف_ڪريو bound_error(...)            \
    افعل {                            \
        bound_warning(__VA_ARGS__); \
        إذا (never_fatal == 0)       \
            ٻاهر_نڪرو(255);              \
    } طالما (0)

#وصف_ڪريو bounds_loc(fp, ...) \
    افعل {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } طالما (0)

ساكن فراغ bound_alloc_error(ثابت حرف *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    ٻاهر_نڪرو (1);
}

ساكن فراغ bound_not_مليو_warning(ثابت حرف *file, ثابت حرف *function,
                                    فراغ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
فراغ __bounds_checking (صحيح no_check)
{
#إذا HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_سيٽ(NO_CHECKING_GET() + no_check);
#وإلا
    atomic_fetch_add (&no_checking, no_check);
#جيڪڏهن_پورو
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
فراغ * __bound_ptr_add(فراغ *p, سائيز_t وٿي)
{
    سائيز_t addr = (سائيز_t)p;

    إذا (NO_CHECKING_GET())
        أرجع p + وٿي;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (بنانشان ڊگهو)وٿي);

    WAIT_SEM ();
    INCR_ڳڻپ(bound_ptr_جوڙيو_ڳڻپ);
    إذا (وڻ_2) {
        addr -= وڻ_2->شروعات;
        إذا (addr >= وڻ_2->سائيز) {
            addr = (سائيز_t)p;
            وڻ_2 = splay (addr, وڻ_2);
            addr -= وڻ_2->شروعات;
        }
        إذا (addr >= وڻ_2->سائيز) {
            addr = (سائيز_t)p;
            وڻ_2 = splay_پڇاڙي (addr, وڻ_2);
            addr -= وڻ_2->شروعات;
        }
        إذا (addr <= وڻ_2->سائيز) {
            إذا (وڻ_2->is_invalid || addr + وٿي > وڻ_2->سائيز) {
                POST_SEM ();
                إذا (print_warn_ptr_جوڙيو)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + وٿي, (ڊگهو)وڻ_2->شروعات,
                                  (ڊگهو)(وڻ_2->شروعات + وڻ_2->سائيز - 1));
                إذا (never_fatal <= 0)
                    أرجع INVALID_اشارو; /* return an invalid pointer */
                أرجع p + وٿي;
            }
        }
        وإلا إذا (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ڳڻپ(bound_not_مليو);
            POST_SEM ();
            bound_not_مليو_warning (__FILE__, __FUNCTION__, p);
            أرجع p + وٿي;
        }
    }
    POST_SEM ();
    أرجع p + وٿي;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#وصف_ڪريو BOUND_PTR_INDIR(dsize)                                                 \
فراغ * __bound_ptr_indir ## dsize (فراغ *p, سائيز_t وٿي)                     \
{                                                                              \
    سائيز_t addr = (سائيز_t)p;                                                   \
                                                                               \
    إذا (NO_CHECKING_GET())                                                     \
        أرجع p + وٿي;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (بنانشان ڊگهو)وٿي);                 \
    WAIT_SEM ();                                                               \
    INCR_ڳڻپ(bound_ptr_indir ## dsize ## ڳڻپ);                            \
    إذا (وڻ_2) {                                                                \
        addr -= وڻ_2->شروعات;                                                   \
        إذا (addr >= وڻ_2->سائيز) {                                              \
            addr = (سائيز_t)p;                                                  \
            وڻ_2 = splay (addr, وڻ_2);                                         \
            addr -= وڻ_2->شروعات;                                               \
        }                                                                      \
        إذا (addr >= وڻ_2->سائيز) {                                              \
            addr = (سائيز_t)p;                                                  \
            وڻ_2 = splay_پڇاڙي (addr, وڻ_2);                                     \
            addr -= وڻ_2->شروعات;                                               \
        }                                                                      \
        إذا (addr <= وڻ_2->سائيز) {                                              \
            إذا (وڻ_2->is_invalid || addr + وٿي + dsize > وڻ_2->سائيز) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + وٿي, dsize, (ڊگهو)وڻ_2->شروعات,            \
                              (ڊگهو)(وڻ_2->شروعات + وڻ_2->سائيز - 1));           \
                إذا (never_fatal <= 0)                                          \
                    أرجع INVALID_اشارو; /* return an invalid pointer */    \
                أرجع p + وٿي;                                             \
            }                                                                  \
        }                                                                      \
        وإلا {                                                                 \
            INCR_ڳڻپ(bound_not_مليو);                                       \
            POST_SEM ();                                                       \
            bound_not_مليو_warning (__FILE__, __FUNCTION__, p);               \
            أرجع p + وٿي;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    أرجع p + وٿي;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#إذا (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#هدايت GCC diagnostic ڌڪو
#هدايت GCC diagnostic ignored "-Wframe-address"
#جيڪڏهن_پورو

/* return the frame pointer of the caller */
#وصف_ڪريو GET_CALLER_FP(fp)\
{\
    fp = (سائيز_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
فراغ FASTCALL __bound_local_new(فراغ *p1) 
{
    سائيز_t addr, fp, *p = p1;

    إذا (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_ڳڻپ(bound_local_new_ڳڻپ);
        وڻ_2 = splay_وجهو(addr + fp, p[1], وڻ_2);
        p += 2;
    }
    POST_SEM ();
#إذا BOUND_DEBUG
    إذا (print_calls) {
        p = p1;
        طالما ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (فراغ *) (addr + fp), (بنانشان ڊگهو) p[1]);
            p += 2;
        }
    }
#جيڪڏهن_پورو
}

/* called when leaving a function to delete all the local regions */
فراغ FASTCALL __bound_local_delete(فراغ *p1) 
{
    سائيز_t addr, fp, *p = p1;

    إذا (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_ڳڻپ(bound_local_delete_ڳڻپ);
        وڻ_2 = splay_delete(addr + fp, وڻ_2);
        p += 2;
    }
    إذا (alloca_list) {
        alloca_list_type *آخري = عدم;
        alloca_list_type *cur = alloca_list;

        افعل {
            إذا (cur->fp == fp) {
                إذا (آخري)
                    آخري->ايندڙ = cur->ايندڙ;
                وإلا
                    alloca_list = cur->ايندڙ;
                وڻ_2 = splay_delete ((سائيز_t) cur->p, وڻ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = آخري ? آخري->ايندڙ : alloca_list;
             }
             وإلا {
                 آخري = cur;
                 cur = cur->ايندڙ;
             }
        } طالما (cur);
    }
    إذا (jmp_list) {
        jmp_list_type *آخري = عدم;
        jmp_list_type *cur = jmp_list;

        افعل {
            إذا (cur->fp == fp) {
                إذا (آخري)
                    آخري->ايندڙ = cur->ايندڙ;
                وإلا
                    jmp_list = cur->ايندڙ;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = آخري ? آخري->ايندڙ : jmp_list;
            }
            وإلا {
                آخري = cur;
                cur = cur->ايندڙ;
            }
        } طالما (cur);
    }

    POST_SEM ();
#إذا BOUND_DEBUG
    إذا (print_calls) {
        p = p1;
        طالما ((addr = p[0])) {
            إذا (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (فراغ *) (addr + fp), (بنانشان ڊگهو) p[1]);
            }
            p+= 2;
        }
    }
#جيڪڏهن_پورو
}

/* used by alloca */
فراغ __bound_new_region(فراغ *p, سائيز_t سائيز)
{
    سائيز_t fp;
    alloca_list_type *آخري;
    alloca_list_type *cur;
    alloca_list_type *new;

    إذا (NO_CHECKING_GET())
        أرجع;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (بنانشان ڊگهو)سائيز);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (حجم (alloca_list_type));
    WAIT_SEM ();
    INCR_ڳڻپ(bound_alloca_ڳڻپ);
    آخري = عدم;
    cur = alloca_list;
    طالما (cur) {
#إذا defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحيح align = 4;
#وإلاإذا defined(__arm__)
        صحيح align = 8;
#وإلا
        صحيح align = 16;
#جيڪڏهن_پورو
        فراغ *cure = (فراغ *)((حرف *)cur->p + ((cur->سائيز + align) & -align));
        فراغ *pe = (فراغ *)((حرف *)p + ((سائيز + align) & -align));
        إذا (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            إذا (آخري)
                آخري->ايندڙ = cur->ايندڙ;
            وإلا
                alloca_list = cur->ايندڙ;
            وڻ_2 = splay_delete((سائيز_t)cur->p, وڻ_2);
            اكسر;
        }
        آخري = cur;
        cur = cur->ايندڙ;
    }
    وڻ_2 = splay_وجهو((سائيز_t)p, سائيز, وڻ_2);
    إذا (new) {
        new->fp = fp;
        new->p = p;
        new->سائيز = سائيز;
        new->ايندڙ = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    إذا (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

فراغ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    فراغ *e = (فراغ *) env;

    إذا (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ڳڻپ(bound_setjmp_ڳڻپ);
        jl = jmp_list;
        طالما (jl) {
            إذا (jl->penv == e)
                اكسر;
            jl = jl->ايندڙ;
        }
        إذا (jl == عدم) {
            jl = BOUND_MALLOC (حجم (jmp_list_type));
            إذا (jl) {
                jl->penv = e;
                jl->ايندڙ = jmp_list;
                jmp_list = jl;
            }
        }
        إذا (jl) {
            سائيز_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->پڇاڙي_fp = (سائيز_t)__builtin_frame_address(0);
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

    إذا (NO_CHECKING_GET() == 0) {
        e = (فراغ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ڳڻپ(bound_longjmp_ڳڻپ);
        jl = jmp_list;
        طالما (jl) {
            إذا (jl->penv == e && jl->tid == tid) {
                سائيز_t شروعات_fp = (سائيز_t)__builtin_frame_address(0);
                سائيز_t پڇاڙي_fp = jl->پڇاڙي_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *آخري = عدم;

                طالما (cur->penv != e || cur->tid != tid) {
                    إذا (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        إذا (آخري)
                            آخري->ايندڙ = cur->ايندڙ;
                        وإلا
                            jmp_list = cur->ايندڙ;
                        BOUND_FREE (cur);
                        cur = آخري ? آخري->ايندڙ : jmp_list;
                    }
                    وإلا {
                        آخري = cur;
                        cur = cur->ايندڙ;
                    }
                }
                لكل (;;) {
                    وڻ *t = وڻ_2;
                    alloca_list_type *آخري;
                    alloca_list_type *cur;

                    طالما (t && (t->شروعات < شروعات_fp || t->شروعات > پڇاڙي_fp))
                        إذا (t->شروعات < شروعات_fp)
                            t = t->ساڄو;
                        وإلا
                            t = t->کاٻو;
                    إذا (t == عدم)
                        اكسر;
                    آخري = عدم;
                    cur = alloca_list;
                    طالما (cur) {
                         إذا ((سائيز_t) cur->p == t->شروعات) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             إذا (آخري)
                                 آخري->ايندڙ = cur->ايندڙ;
                             وإلا
                                 alloca_list = cur->ايندڙ;
                             BOUND_FREE (cur);
                             اكسر;
                         }
                         آخري = cur;
                         cur = cur->ايندڙ;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (فراغ *) t->شروعات);
                    وڻ_2 = splay_delete(t->شروعات, وڻ_2);
                }
                اكسر;
            }
            jl = jl->ايندڙ;
        }
        POST_SEM();
    }
#إذا !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#جيڪڏهن_پورو
    longjmp (env, val);
}

فراغ __bound_longjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#إذا !defined(_WIN32)
فراغ __bound_siglongjmp(jmp_buf env, صحيح val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#جيڪڏهن_پورو

#إذا (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#هدايت GCC diagnostic ڪڍو
#جيڪڏهن_پورو

فراغ __bound_init(سائيز_t *p, صحيح گهڻائي)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            گهڻائي < 0 ? "lazy" : گهڻائي == 0 ? "normal use" : "for -run");

    إذا (inited) {
        WAIT_SEM();
        اذهب جوڙيو_bounds;
    }
    inited = 1;

#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
    no_checking_ڪنجي = TlsAlloc();
    Tls_سيٽ_قدر(no_checking_ڪنجي, &no_checking);
#وإلا
    pthread_key_create(&no_checking_ڪنجي, عدم);
    pthread_setspecific(no_checking_ڪنجي, &no_checking);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
    NO_CHECKING_سيٽ(1);

    print_warn_ptr_جوڙيو = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != عدم;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != عدم;
    print_ڍير = getenv ("TCC_BOUNDS_PRINT_HEAP") != عدم;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != عدم;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != عدم;

    INIT_SEM ();

#إذا MALLOC_REDIR
    {
        فراغ *addr = گهڻائي > 0 ? RTLD_DEFAULT : RTLD_ايندڙ;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(فراغ **) (&malloc_redir) = dlsym (addr, "malloc");
        إذا (malloc_redir == عدم) {
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
        إذا (malloc_redir == عدم || free_redir == عدم)
            bound_alloc_error ("Cannot redirect malloc/free");
#إذا HAVE_PTHREAD_CREATE
        *(فراغ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        إذا (pthread_create_redir == عدم)
            bound_alloc_error ("Cannot redirect pthread_create");
#جيڪڏهن_پورو
#إذا HAVE_SIGNAL
        *(فراغ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        إذا (signal_redir == عدم)
            bound_alloc_error ("Cannot redirect signal");
#جيڪڏهن_پورو
#إذا HAVE_SIGACTION
        *(فراغ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        إذا (sigaction_redir == عدم)
            bound_alloc_error ("Cannot redirect sigaction");
#جيڪڏهن_پورو
#إذا HAVE_FORK
        *(فراغ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        إذا (fork_redir == عدم)
            bound_alloc_error ("Cannot redirect fork");
#جيڪڏهن_پورو
    }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __linux__
    {
        FILE *fp;
        بنانشان حرف مليو;
        بنانشان ڊگهو شروعات;
        بنانشان ڊگهو پڇاڙي;
        بنانشان ڊگهو ad =
            (بنانشان ڊگهو) __builtin_return_address(0);
        حرف سٽ[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        إذا (fp) {
            memset (exec, 0, حجم(exec));
            fread (exec, 1, حجم(exec) - 2, fp);
            إذا (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        مليو = 0;
        fp = fopen ("/proc/self/maps", "r");
        إذا (fp) {
            طالما (fgets (سٽ, حجم(سٽ), fp)) {
                إذا (لڙي_مان_پڙهو (سٽ, "%lx-%lx", &شروعات, &پڇاڙي) == 2 &&
                            ad >= شروعات && ad < پڇاڙي) {
                    مليو = 1;
                    اكسر;
                }
                إذا (لڙي_ڳولا (سٽ,"[heap]"))
                    اكسر;
            }
            fclose (fp);
        }
        إذا (مليو == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#جيڪڏهن_پورو

    WAIT_SEM ();

#إذا HAVE_CTYPE
#جيڪڏهن_وصف_ٿيل __APPLE__
    وڻ_2 = splay_وجهو((سائيز_t) &_DefaultRuneLocale,
                        حجم (_DefaultRuneLocale), وڻ_2);
#وإلا
    /* XXX: Does not work if locale is changed */
    وڻ_2 = splay_وجهو((سائيز_t) __ctype_b_loc(),
                        حجم (بنانشان ننڍو *), وڻ_2);
    وڻ_2 = splay_وجهو((سائيز_t) (*__ctype_b_loc() - 128),
                        384 * حجم (بنانشان ننڍو), وڻ_2);
    وڻ_2 = splay_وجهو((سائيز_t) __ctype_tolower_loc(),
                        حجم (__int32_t *), وڻ_2);
    وڻ_2 = splay_وجهو((سائيز_t) (*__ctype_tolower_loc() - 128),
                        384 * حجم (__int32_t), وڻ_2);
    وڻ_2 = splay_وجهو((سائيز_t) __ctype_toupper_loc(),
                        حجم (__int32_t *), وڻ_2);
    وڻ_2 = splay_وجهو((سائيز_t) (*__ctype_toupper_loc() - 128),
                        384 * حجم (__int32_t), وڻ_2);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#إذا HAVE_ERRNO
    وڻ_2 = splay_وجهو((سائيز_t) (&errno), حجم (صحيح), وڻ_2);
#جيڪڏهن_پورو

جوڙيو_bounds:
    إذا (!p)
        اذهب no_bounds;

    /* add all static bound check values */
    طالما (p[0] != 0) {
        وڻ_2 = splay_وجهو(p[0], p[1], وڻ_2);
#إذا BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (فراغ *) p[0], (بنانشان ڊگهو) p[1]);
#جيڪڏهن_پورو
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_سيٽ(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

فراغ
#إذا (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#جيڪڏهن_پورو
__bound_main_arg(صحيح argc, حرف **argv, حرف **envp)
{
    __bound_init (0, -1);
    إذا (argc && argv) {
        صحيح i;

        WAIT_SEM ();
        لكل (i = 0; i < argc; i++)
            وڻ_2 = splay_وجهو((سائيز_t) argv[i], لڙي_ڊيگهه (argv[i]) + 1, وڻ_2);
        وڻ_2 = splay_وجهو((سائيز_t) argv, (argc + 1) * حجم(حرف *), وڻ_2);
        POST_SEM ();
#إذا BOUND_DEBUG
        إذا (print_calls) {
            لكل (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (بنانشان ڊگهو)(لڙي_ڊيگهه (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (صحيح)((argc + 1) * حجم(حرف *)));
        }
#جيڪڏهن_پورو
    }

    إذا (envp && *envp) {
        حرف **p = envp;

        WAIT_SEM ();
        طالما (*p) {
            وڻ_2 = splay_وجهو((سائيز_t) *p, لڙي_ڊيگهه (*p) + 1, وڻ_2);
            ++p;
        }
        وڻ_2 = splay_وجهو((سائيز_t) envp, (++p - envp) * حجم(حرف *), وڻ_2);
        POST_SEM ();
#إذا BOUND_DEBUG
        إذا (print_calls) {
            p = envp;
            طالما (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (بنانشان ڊگهو)(لڙي_ڊيگهه (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (صحيح)((++p - envp) * حجم(حرف *)));
        }
#جيڪڏهن_پورو
    }
}

فراغ __attribute__((destructor)) __bound_exit(فراغ)
{
    صحيح i;
    ساكن ثابت حرف * ثابت alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    إذا (inited) {
#إذا !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        إذا (print_ڍير) {
            خارجي فراغ __libc_freeres (فراغ);
            __libc_freeres ();
        }
#جيڪڏهن_پورو

        NO_CHECKING_سيٽ(1);

        TRY_SEM ();
        طالما (alloca_list) {
            alloca_list_type *ايندڙ = alloca_list->ايندڙ;

            وڻ_2 = splay_delete ((سائيز_t) alloca_list->p, وڻ_2);
            BOUND_FREE (alloca_list);
            alloca_list = ايندڙ;
        }
        طالما (jmp_list) {
           jmp_list_type *ايندڙ  = jmp_list->ايندڙ;

           BOUND_FREE (jmp_list);
           jmp_list = ايندڙ;
        }
        لكل (i = 0; i < FREE_REUSE_سائيز; i++) {
            إذا (free_reuse_list[i]) {
                وڻ_2 = splay_delete ((سائيز_t) free_reuse_list[i], وڻ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        طالما (وڻ_2) {
            إذا (print_ڍير && وڻ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[وڻ_2->type],
                         (بنانشان ڊگهو) وڻ_2->سائيز);
            وڻ_2 = splay_delete (وڻ_2->شروعات, وڻ_2);
        }
#إذا وڻ_REUSE
        طالما (وڻ_free_list) {
            وڻ *ايندڙ = وڻ_free_list->کاٻو;
            BOUND_FREE (وڻ_free_list);
            وڻ_free_list = ايندڙ;
        }
#جيڪڏهن_پورو
        POST_SEM ();
        EXIT_SEM ();
#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
        TlsFree(no_checking_ڪنجي);
#وإلا
        pthread_key_delete(no_checking_ڪنجي);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
        inited = 0;
        إذا (print_statistic) {
#إذا BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_جوڙيو_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_ڳڻپ);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_ڳڻپ);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_ڳڻپ);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_ڳڻپ);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_ڳڻپ);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_ڳڻپ);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_ڳڻپ);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_ڳڻپ);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_ڳڻپ);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_ڳڻپ);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_ڳڻپ);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_ڳڻپ);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_ڳڻپ);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_ڳڻپ);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_ڳڻپ);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_ڳڻپ);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_ڳڻپ);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_ڳڻپ);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_ڳڻپ);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_ڳڻپ);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_ڳڻپ);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_ڳڻپ);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_ڳڻپ);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_ڳڻپ);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_ڳڻپ);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_ڳڻپ);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_ڳڻپ);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_ڳڻپ);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_مليو);
#جيڪڏهن_پورو
#إذا BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_پڇاڙي);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_وجهو);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#جيڪڏهن_پورو
        }
    }
}

فراغ __bound_exit_dll(سائيز_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    إذا (p) {
        WAIT_SEM ();
	طالما (p[0] != 0) {
	    وڻ_2 = splay_delete(p[0], وڻ_2);
#إذا BOUND_DEBUG
            إذا (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (فراغ *) p[0], (بنانشان ڊگهو) p[1]);
            }
#جيڪڏهن_پورو
	    p += 2;
	}
        POST_SEM ();
    }
}

#إذا HAVE_PTHREAD_CREATE
تعريفنوع بنية {
    فراغ *(*شروعات_routine) (فراغ *);
    فراغ *arg;
    sigset_t old_نقاب;
} bound_thread_create_type;

ساكن فراغ *bound_thread_create(فراغ *bdata)
{
    bound_thread_create_type *معلومات = (bound_thread_create_type *) bdata;
    فراغ *retval;
#إذا HAVE_TLS_FUNC
    صحيح *p = (صحيح *) BOUND_MALLOC(حجم(صحيح));
  
    إذا (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ڪنجي, p);
#جيڪڏهن_پورو
    pthread_sigmask(SIG_SETMASK, &معلومات->old_نقاب, عدم);
    retval = معلومات->شروعات_routine(معلومات->arg);
#إذا HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ڪنجي, عدم);
    BOUND_FREE (p);
#جيڪڏهن_پورو
    BOUND_FREE (معلومات);
    أرجع retval;
}

صحيح pthread_create(pthread_t *thread, ثابت pthread_attr_t *attr,
                   فراغ *(*شروعات_routine) (فراغ *), فراغ *arg)
{
    صحيح retval;
    bound_thread_create_type *معلومات;
    sigset_t نقاب;
    sigset_t old_نقاب;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&نقاب);
    pthread_sigmask(SIG_SETMASK, &نقاب, &old_نقاب);
    معلومات = (bound_thread_create_type *) BOUND_MALLOC(حجم(bound_thread_create_type));
    إذا (!معلومات) bound_alloc_error("bound_thread_create malloc");
    معلومات->شروعات_routine = شروعات_routine;
    معلومات->arg = arg;
    معلومات->old_نقاب = old_نقاب;
    retval = pthread_create_redir(thread, attr, bound_thread_create, معلومات);
    pthread_sigmask(SIG_SETMASK, &old_نقاب, عدم);
    أرجع retval;
}
#جيڪڏهن_پورو

#إذا HAVE_SIGNAL || HAVE_SIGACTION
تعريفنوع اتحاد {
#إذا HAVE_SIGNAL
    bound_sig signal_handler;
#جيڪڏهن_پورو
#إذا HAVE_SIGACTION
    فراغ (*sig_handler)(صحيح);
    فراغ (*sig_sigaction)(صحيح, siginfo_t *, فراغ *);
#جيڪڏهن_پورو
} bound_sig_type;

ساكن بنانشان حرف bound_sig_استعمال_ٿيل[NSIG];
ساكن bound_sig_type bound_sig_معلومات[NSIG];
#جيڪڏهن_پورو

#إذا HAVE_SIGNAL
ساكن فراغ signal_handler(صحيح sig)
{
   __bounds_checking(1);
   bound_sig_معلومات[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig إشارة(صحيح signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    إذا (retval != SIG_ERR) {
        إذا (bound_sig_استعمال_ٿيل[signum])
            retval = bound_sig_معلومات[signum].signal_handler;
        إذا (handler) {
            bound_sig_استعمال_ٿيل[signum] = 1;
            bound_sig_معلومات[signum].signal_handler = handler;
        }
    }
    أرجع retval;
}
#جيڪڏهن_پورو

#إذا HAVE_SIGACTION
ساكن فراغ sig_handler(صحيح sig)
{
   __bounds_checking(1);
   bound_sig_معلومات[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ساكن فراغ sig_sigaction(صحيح sig, siginfo_t *info, فراغ *ucontext)
{
   __bounds_checking(1);
   bound_sig_معلومات[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

صحيح sigaction(صحيح signum, ثابت بنية sigaction *act, بنية sigaction *oldact)
{
    صحيح retval;
    بنية sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    إذا (sigaction_redir == عدم)
        __bound_init(0,-1);

    إذا (act) {
        nact = *act;
        إذا (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        وإلا
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    وإلا
        retval = sigaction_redir(signum, act, &oact);
    إذا (retval >= 0) {
        إذا (bound_sig_استعمال_ٿيل[signum]) {
            إذا (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_معلومات[signum].sig_sigaction;
            وإلا
                oact.sa_handler = bound_sig_معلومات[signum].sig_handler;
        }
        إذا (oldact) {
            *oldact = oact;
        }
        إذا (act) {
            bound_sig_استعمال_ٿيل[signum] = 1;
            إذا (act->sa_flags & SA_SIGINFO)
                bound_sig_معلومات[signum].sig_sigaction = act->sa_sigaction;
            وإلا
                bound_sig_معلومات[signum].sig_handler = act->sa_handler;
        }
    }
    أرجع retval;
}
#جيڪڏهن_پورو

#إذا HAVE_FORK
pid_t fork(فراغ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    إذا (retval == 0)
        INIT_SEM();
    وإلا
        POST_SEM();
    أرجع retval;
}
#جيڪڏهن_پورو

#إذا MALLOC_REDIR
فراغ *يادگيري_ڏيو(سائيز_t سائيز)
#وإلا
فراغ *__bound_malloc(سائيز_t سائيز, ثابت فراغ *caller)
#جيڪڏهن_پورو
{
    فراغ *ptr;
    
#إذا MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    إذا (malloc_redir == عدم) {
        __bound_init (0, -1);
        إذا (malloc_redir == عدم) {
            ptr = &initial_pool[pool_اشاريو];
            pool_اشاريو = (pool_اشاريو + سائيز + 15) & ~15;
            إذا (pool_اشاريو >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (بنانشان ڊگهو)سائيز);
            أرجع ptr;
        }
    }
#جيڪڏهن_پورو
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (سائيز + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (بنانشان ڊگهو)سائيز);
    
    إذا (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_malloc_ڳڻپ);

        إذا (ptr) {
            وڻ_2 = splay_وجهو ((سائيز_t) ptr, سائيز ? سائيز : سائيز + 1, وڻ_2);
            إذا (وڻ_2 && وڻ_2->شروعات == (سائيز_t) ptr)
                وڻ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#إذا MALLOC_REDIR
فراغ *memalign(سائيز_t align, سائيز_t سائيز)
#وإلا
فراغ *__bound_memalign(سائيز_t align, سائيز_t سائيز, ثابت فراغ *caller)
#جيڪڏهن_پورو
{
    فراغ *ptr;

#إذا HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, سائيز + 1);
#وإلا
    إذا (align > 4) {
        /* XXX: handle it ? */
        ptr = عدم;
    } وإلا {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(سائيز + 1);
    }
#جيڪڏهن_پورو
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (بنانشان ڊگهو)سائيز);

    إذا (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_memalign_ڳڻپ);

        إذا (ptr) {
            وڻ_2 = splay_وجهو((سائيز_t) ptr, سائيز ? سائيز : سائيز + 1, وڻ_2);
            إذا (وڻ_2 && وڻ_2->شروعات == (سائيز_t) ptr)
                وڻ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#إذا MALLOC_REDIR
فراغ حرر(فراغ *ptr)
#وإلا
فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller)
#جيڪڏهن_پورو
{
    سائيز_t addr = (سائيز_t) ptr;
    فراغ *p;

    إذا (ptr == عدم || وڻ_2 == عدم
#إذا MALLOC_REDIR
        || ((بنانشان حرف *) ptr >= &initial_pool[0] &&
            (بنانشان حرف *) ptr < &initial_pool[حجم(initial_pool)])
#جيڪڏهن_پورو
        )
        أرجع;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    إذا (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_free_ڳڻپ);
        وڻ_2 = splay (addr, وڻ_2);
        إذا (وڻ_2->شروعات == addr) {
            إذا (وڻ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                أرجع;
            }
            وڻ_2->is_invalid = 1;
            memset (ptr, 0x5a, وڻ_2->سائيز);
            p = free_reuse_list[free_reuse_اشاريو];
            free_reuse_list[free_reuse_اشاريو] = ptr;
            free_reuse_اشاريو = (free_reuse_اشاريو + 1) % FREE_REUSE_سائيز;
            إذا (p)
                وڻ_2 = splay_delete((سائيز_t)p, وڻ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#إذا MALLOC_REDIR
فراغ *realloc(فراغ *ptr, سائيز_t سائيز)
#وإلا
فراغ *__bound_realloc(فراغ *ptr, سائيز_t سائيز, ثابت فراغ *caller)
#جيڪڏهن_پورو
{
    فراغ *new_ptr;

    إذا (سائيز == 0) {
#إذا MALLOC_REDIR
        حرر(ptr);
#وإلا
        __bound_free(ptr, caller);
#جيڪڏهن_پورو
        أرجع عدم;
    }

    new_ptr = BOUND_REALLOC (ptr, سائيز + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (بنانشان ڊگهو)سائيز);

    إذا (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_realloc_ڳڻپ);

        إذا (ptr)
            وڻ_2 = splay_delete ((سائيز_t) ptr, وڻ_2);
        إذا (new_ptr) {
            وڻ_2 = splay_وجهو ((سائيز_t) new_ptr, سائيز ? سائيز : سائيز + 1, وڻ_2);
            إذا (وڻ_2 && وڻ_2->شروعات == (سائيز_t) new_ptr)
                وڻ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    أرجع new_ptr;
}

#إذا MALLOC_REDIR
فراغ *صفر_يادگيري_ڏيو(سائيز_t nmemb, سائيز_t سائيز)
#وإلا
فراغ *__bound_calloc(سائيز_t nmemb, سائيز_t سائيز)
#جيڪڏهن_پورو
{
    فراغ *ptr;

    سائيز *= nmemb;
#إذا MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    إذا (malloc_redir == عدم) {
        __bound_init (0, -1);
        إذا (malloc_redir == عدم) {
            ptr = &initial_pool[pool_اشاريو];
            pool_اشاريو = (pool_اشاريو + سائيز + 15) & ~15;
            إذا (pool_اشاريو >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (بنانشان ڊگهو)سائيز);
            memset (ptr, 0, سائيز);
            أرجع ptr;
        }
    }
#جيڪڏهن_پورو
    ptr = BOUND_MALLOC(سائيز + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (بنانشان ڊگهو)سائيز);

    إذا (ptr) {
        memset (ptr, 0, سائيز);
        إذا (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ڳڻپ(bound_calloc_ڳڻپ);
            وڻ_2 = splay_وجهو ((سائيز_t) ptr, سائيز ? سائيز : سائيز + 1, وڻ_2);
            إذا (وڻ_2 && وڻ_2->شروعات == (سائيز_t) ptr)
                وڻ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    أرجع ptr;
}

#إذا !defined(_WIN32)
فراغ *__bound_mmap (فراغ *شروعات, سائيز_t سائيز, صحيح prot,
                    صحيح flags, صحيح fd, off_t وٿي)
{
    فراغ *نتيجو;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, شروعات, (بنانشان ڊگهو)سائيز);
    نتيجو = mmap (شروعات, سائيز, prot, flags, fd, وٿي);
    إذا (نتيجو && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_mmap_ڳڻپ);
        وڻ_2 = splay_وجهو((سائيز_t)نتيجو, سائيز, وڻ_2);
        POST_SEM ();
    }
    أرجع نتيجو;
}

صحيح __bound_munmap (فراغ *شروعات, سائيز_t سائيز)
{
    صحيح نتيجو;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, شروعات, (بنانشان ڊگهو)سائيز);
    إذا (شروعات && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ڳڻپ(bound_munmap_ڳڻپ);
        وڻ_2 = splay_delete ((سائيز_t) شروعات, وڻ_2);
        POST_SEM ();
    }
    نتيجو = munmap (شروعات, سائيز);
    أرجع نتيجو;
}
#جيڪڏهن_پورو

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ساكن فراغ __bound_check(ثابت فراغ *p, سائيز_t سائيز, ثابت حرف *function)
{
    إذا (سائيز != 0 && __bound_ptr_add((فراغ *)p, سائيز) == INVALID_اشارو) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (بنانشان ڊگهو)سائيز, function);
    }
}

ساكن صحيح check_overlap (ثابت فراغ *p1, سائيز_t n1,
                          ثابت فراغ *p2, سائيز_t n2,
                          ثابت حرف *function)
{
    ثابت فراغ *p1e = (ثابت فراغ *) ((ثابت حرف *) p1 + n1);
    ثابت فراغ *p2e = (ثابت فراغ *) ((ثابت حرف *) p2 + n2);

    إذا (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (بنانشان ڊگهو)n1, p2, (بنانشان ڊگهو)n2, function);
        أرجع never_fatal < 0;
    }
    أرجع 0;
}

فراغ *__bound_memcpy(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_mempcy_ڳڻپ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    إذا (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع يادگيري_نقل(dest, src, n);
}

صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, سائيز_t n)
{
    ثابت بنانشان حرف *u1 = (ثابت بنانشان حرف *) s1;
    ثابت بنانشان حرف *u2 = (ثابت بنانشان حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memcmp_ڳڻپ);
    لكل (;;) {
        إذا ((ssize_t) --n == -1)
            اكسر;
        وإلا إذا (*u1 != *u2) {
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

فراغ *__bound_memmove(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memmove_ڳڻپ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع memmove(dest, src, n);
}

فراغ *__bound_memset(فراغ *s, صحيح c, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memset_ڳڻپ);
    __bound_check(s, n, "memset");
    أرجع memset(s, c, n);
}

#إذا defined(__arm__) && defined(__ARM_EABI__)
فراغ *__bound___aeabi_memcpy(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_mempcy_ڳڻپ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    إذا (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع __aeabi_memcpy(dest, src, n);
}

فراغ *__bound___aeabi_memmove(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memmove_ڳڻپ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove(dest, src, n);
}

فراغ *__bound___aeabi_memmove4(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memmove_ڳڻپ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove4(dest, src, n);
}

فراغ *__bound___aeabi_memmove8(فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memmove_ڳڻپ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove8(dest, src, n);
}

فراغ *__bound___aeabi_memset(فراغ *s, صحيح c, سائيز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_memset_ڳڻپ);
    __bound_check(s, n, "memset");
    أرجع __aeabi_memset(s, c, n);
}
#جيڪڏهن_پورو

صحيح __bound_strlen(ثابت حرف *s)
{
    ثابت حرف *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ڳڻپ(bound_strlen_ڳڻپ);
    طالما (*p++);
    __bound_check(s, p - s, "strlen");
    أرجع (p - s) - 1;
}

حرف *__bound_strcpy(حرف *dest, ثابت حرف *src)
{
    سائيز_t len;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ڳڻپ(bound_strcpy_ڳڻپ);
    طالما (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    إذا (check_overlap(dest, len, src, len, "strcpy"))
        أرجع dest;
    أرجع strcpy (dest, src);
}

حرف *__bound_strncpy(حرف *dest, ثابت حرف *src, سائيز_t n)
{
    سائيز_t len = n;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_strncpy_ڳڻپ);
    طالما (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    إذا (check_overlap(dest, len, src, len, "strncpy"))
        أرجع dest;
    أرجع strncpy(dest, src, n);
}

صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2)
{
    ثابت بنانشان حرف *u1 = (ثابت بنانشان حرف *) s1;
    ثابت بنانشان حرف *u2 = (ثابت بنانشان حرف *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ڳڻپ(bound_strcmp_ڳڻپ);
    طالما (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت حرف *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت حرف *)u2 - s2) + 1, "strcmp s2");
    أرجع *u1 - *u2;
}

صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, سائيز_t n)
{
    ثابت بنانشان حرف *u1 = (ثابت بنانشان حرف *) s1;
    ثابت بنانشان حرف *u2 = (ثابت بنانشان حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_strncmp_ڳڻپ);
    افعل {
        إذا ((ssize_t) --n == -1)
            اكسر;
        وإلا إذا (*u1 != *u2) {
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
    INCR_ڳڻپ(bound_strcat_ڳڻپ);
    طالما (*dest++);
    طالما (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    إذا (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        أرجع dest;
    أرجع strcat(r, s);
}

حرف *__bound_strncat(حرف *dest, ثابت حرف *src, سائيز_t n)
{
    حرف *r = dest;
    ثابت حرف *s = src;
    سائيز_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بنانشان ڊگهو)n);
    INCR_ڳڻپ(bound_strncat_ڳڻپ);
    طالما (*dest++);
    طالما (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    إذا (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        أرجع dest;
    أرجع strncat(r, s, n);
}

حرف *__bound_strchr(ثابت حرف *s, صحيح c)
{
    ثابت بنانشان حرف *str = (ثابت بنانشان حرف *) s;
    بنانشان حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ڳڻپ(bound_strchr_ڳڻپ);
    طالما (*str) {
        إذا (*str == ch)
            اكسر;
        ++str;
    }
    __bound_check(s, ((ثابت حرف *)str - s) + 1, "strchr");
    أرجع *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strrchr(ثابت حرف *s, صحيح c)
{
    ثابت بنانشان حرف *str = (ثابت بنانشان حرف *) s;
    بنانشان حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ڳڻپ(bound_strrchr_ڳڻپ);
    طالما (*str++);
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    طالما (str != (ثابت بنانشان حرف *)s) {
        إذا (*--str == ch)
            اكسر;
    }
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    أرجع *str == ch ? (حرف *) str : عدم;
}

حرف *__bound_strdup(ثابت حرف *s)
{
    ثابت حرف *p = s;
    حرف *new;

    INCR_ڳڻپ(bound_strdup_ڳڻپ);
    طالما (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (بنانشان ڊگهو)(p -s));
    إذا (new) {
        إذا (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            وڻ_2 = splay_وجهو((سائيز_t)new, p - s, وڻ_2);
            إذا (وڻ_2 && وڻ_2->شروعات == (سائيز_t) new)
                وڻ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        يادگيري_نقل (new, s, p - s);
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

#وصف_ڪريو compare(شروعات,tstart,tsize) (شروعات < tstart ? -1 : \
                                     شروعات >= tstart+tsize  ? 1 : 0)

ساكن وڻ * splay (سائيز_t addr, وڻ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    وڻ N, *l, *r, *y;
    صحيح comp;
    
    INCR_ڳڻپ_SPLAY(bound_splay);
    إذا (t == عدم) أرجع t;
    N.کاٻو = N.ساڄو = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare(addr, t->شروعات, t->سائيز);
        إذا (comp < 0) {
            y = t->کاٻو;
            إذا (y == عدم) اكسر;
            إذا (compare(addr, y->شروعات, y->سائيز) < 0) {
                t->کاٻو = y->ساڄو;                    /* rotate right */
                y->ساڄو = t;
                t = y;
                إذا (t->کاٻو == عدم) اكسر;
            }
            r->کاٻو = t;                               /* link right */
            r = t;
            t = t->کاٻو;
        } وإلا إذا (comp > 0) {
            y = t->ساڄو;
            إذا (y == عدم) اكسر;
            إذا (compare(addr, y->شروعات, y->سائيز) > 0) {
                t->ساڄو = y->کاٻو;                    /* rotate left */
                y->کاٻو = t;
                t = y;
                إذا (t->ساڄو == عدم) اكسر;
            }
            l->ساڄو = t;                              /* link left */
            l = t;
            t = t->ساڄو;
        } وإلا {
            اكسر;
        }
    }
    l->ساڄو = t->کاٻو;                                /* assemble */
    r->کاٻو = t->ساڄو;
    t->کاٻو = N.ساڄو;
    t->ساڄو = N.کاٻو;

    أرجع t;
}

#وصف_ڪريو compare_پڇاڙي(شروعات,tend) (شروعات < tend ? -1 : \
                                 شروعات > tend  ? 1 : 0)

ساكن وڻ * splay_پڇاڙي (سائيز_t addr, وڻ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    وڻ N, *l, *r, *y;
    صحيح comp;
    
    INCR_ڳڻپ_SPLAY(bound_splay_پڇاڙي);
    إذا (t == عدم) أرجع t;
    N.کاٻو = N.ساڄو = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare_پڇاڙي(addr, t->شروعات + t->سائيز);
        إذا (comp < 0) {
            y = t->کاٻو;
            إذا (y == عدم) اكسر;
            إذا (compare_پڇاڙي(addr, y->شروعات + y->سائيز) < 0) {
                t->کاٻو = y->ساڄو;                    /* rotate right */
                y->ساڄو = t;
                t = y;
                إذا (t->کاٻو == عدم) اكسر;
            }
            r->کاٻو = t;                               /* link right */
            r = t;
            t = t->کاٻو;
        } وإلا إذا (comp > 0) {
            y = t->ساڄو;
            إذا (y == عدم) اكسر;
            إذا (compare_پڇاڙي(addr, y->شروعات + y->سائيز) > 0) {
                t->ساڄو = y->کاٻو;                    /* rotate left */
                y->کاٻو = t;
                t = y;
                إذا (t->ساڄو == عدم) اكسر;
            }
            l->ساڄو = t;                              /* link left */
            l = t;
            t = t->ساڄو;
        } وإلا {
            اكسر;
        }
    }
    l->ساڄو = t->کاٻو;                                /* assemble */
    r->کاٻو = t->ساڄو;
    t->کاٻو = N.ساڄو;
    t->ساڄو = N.کاٻو;

    أرجع t;
}

ساكن وڻ * splay_وجهو(سائيز_t addr, سائيز_t سائيز, وڻ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    وڻ * new;

    INCR_ڳڻپ_SPLAY(bound_splay_وجهو);
    إذا (t != عدم) {
        t = splay(addr,t);
        إذا (compare(addr, t->شروعات, t->سائيز)==0) {
            أرجع t;  /* it's already there */
        }
    }
#إذا وڻ_REUSE
    إذا (وڻ_free_list) {
          new = وڻ_free_list;
          وڻ_free_list = new->کاٻو;
    }
    وإلا
#جيڪڏهن_پورو
    {
        new = (وڻ *) BOUND_MALLOC (حجم (وڻ));
    }
    إذا (new == عدم) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    وإلا {
        إذا (t == عدم) {
            new->کاٻو = new->ساڄو = عدم;
        } وإلا إذا (compare(addr, t->شروعات, t->سائيز) < 0) {
            new->کاٻو = t->کاٻو;
            new->ساڄو = t;
            t->کاٻو = عدم;
        } وإلا {
            new->ساڄو = t->ساڄو;
            new->کاٻو = t;
            t->ساڄو = عدم;
        }
        new->شروعات = addr;
        new->سائيز = سائيز;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    أرجع new;
}

#وصف_ڪريو compare_destroy(شروعات,tstart) (شروعات < tstart ? -1 : \
                                       شروعات > tstart  ? 1 : 0)

ساكن وڻ * splay_delete(سائيز_t addr, وڻ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    وڻ * x;

    INCR_ڳڻپ_SPLAY(bound_splay_delete);
    إذا (t==عدم) أرجع عدم;
    t = splay(addr,t);
    إذا (compare_destroy(addr, t->شروعات) == 0) {        /* found it */
        إذا (t->کاٻو == عدم) {
            x = t->ساڄو;
        } وإلا {
            x = splay(addr, t->کاٻو);
            x->ساڄو = t->ساڄو;
        }
#إذا وڻ_REUSE
        t->کاٻو = وڻ_free_list;
        وڻ_free_list = t;
#وإلا
        BOUND_FREE(t);
#جيڪڏهن_پورو
        أرجع x;
    } وإلا {
        أرجع t;                                      /* It wasn't there */
    }
}

فراغ splay_printtree(وڻ * t, صحيح d)
{
    صحيح i;
    إذا (t == عدم) أرجع;
    splay_printtree(t->ساڄو, d+1);
    لكل (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (فراغ *) t->شروعات, (بنانشان ڊگهو) t->سائيز,
            (بنانشان)t->type, (بنانشان)t->is_invalid);
    splay_printtree(t->کاٻو, d+1);
}
