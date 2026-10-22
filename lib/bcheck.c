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
#د_که_پای

#إذا !defined(_WIN32)
#ضمن <unistd.h>
#ضمن <sys/syscall.h>
#د_که_پای

#ضمن "config.h"

#تعریف_کړه BOUND_DEBUG             (1)
#تعریف_کړه BOUND_STATISTIC         (1)

#إذا BOUND_DEBUG
 #تعریف_کړه dprintf(a...)         إذا (print_calls) { bounds_loc(a); }
#وإلا
 #تعریف_کړه dprintf(a...)
#د_که_پای

#که_تعریف_شوی __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #تعریف_لغوه __attribute__ 
#د_که_پای
#که_تعریف_شوی __i386__
#تعریف_کړه FASTCALL __attribute__((regparm(3)))
#وإلا
#تعریف_کړه FASTCALL
#د_که_پای

#که_تعریف_شوی _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وإلا
# define DLL_EXPORT
#د_که_پای

#إذا defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ضمن <sys/mman.h>
#تعریف_کړه INIT_SEM()
#تعریف_کړه EXIT_SEM()
#تعریف_کړه WAIT_SEM()
#تعریف_کړه POST_SEM()
#تعریف_کړه TRY_SEM()
#تعریف_کړه HAVE_MEMALIGN          (0)
#تعریف_کړه MALLOC_REDIR           (0)
#تعریف_کړه HAVE_PTHREAD_CREATE    (0)
#تعریف_کړه HAVE_CTYPE             (0)
#تعریف_کړه HAVE_ERRNO             (0)
#تعریف_کړه HAVE_SIGNAL            (0)
#تعریف_کړه HAVE_SIGACTION         (0)
#تعریف_کړه HAVE_FORK              (0)
#تعریف_کړه HAVE_TLS_FUNC          (0)
#تعریف_کړه HAVE_TLS_VAR           (0)

#وإلاإذا defined(_WIN32)

#ضمن <windows.h>
#ضمن <signal.h>
ساكن CRITICAL_SECTION bounds_sem;
#تعریف_کړه INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#تعریف_کړه EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#تعریف_کړه WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#تعریف_کړه POST_SEM()             LeaveCriticalSection(&bounds_sem)
#تعریف_کړه TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#تعریف_کړه HAVE_MEMALIGN          (0)
#تعریف_کړه MALLOC_REDIR           (0)
#تعریف_کړه HAVE_PTHREAD_CREATE    (0)
#تعریف_کړه HAVE_CTYPE             (0)
#تعریف_کړه HAVE_ERRNO             (0)
#تعریف_کړه HAVE_SIGNAL            (1)
#تعریف_کړه HAVE_SIGACTION         (0)
#تعریف_کړه HAVE_FORK              (0)
#تعریف_کړه HAVE_TLS_FUNC          (1)
#تعریف_کړه HAVE_TLS_VAR           (0)

#وإلا

#تعریف_کړه __USE_GNU              /* get RTLD_NEXT */
#ضمن <sys/mman.h>
#ضمن <ctype.h>
#ضمن <pthread.h>
#ضمن <dlfcn.h>
#ضمن <errno.h>
#ضمن <signal.h>
#که_تعریف_شوی __APPLE__
#ضمن <dispatch/dispatch.h>
ساكن dispatch_semaphore_t bounds_sem;
#تعریف_کړه INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#تعریف_کړه EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#تعریف_کړه WAIT_SEM()             إذا (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وخت_FOREVER)
#تعریف_کړه POST_SEM()             إذا (use_sem) dispatch_semaphore_signal(bounds_sem)
#تعریف_کړه TRY_SEM()              إذا (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وخت_NOW)
#وإلاإذا 0
#ضمن <semaphore.h>
ساكن sem_t bounds_sem;
#تعریف_کړه INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#تعریف_کړه EXIT_SEM()             sem_destroy (&bounds_sem)
#تعریف_کړه WAIT_SEM()             إذا (use_sem) طالما (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#تعریف_کړه POST_SEM()             إذا (use_sem) sem_post (&bounds_sem)
#تعریف_کړه TRY_SEM()              إذا (use_sem) طالما (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وإلاإذا 0
ساكن pthread_mutex_t bounds_mtx;
#تعریف_کړه INIT_SEM()             pthread_mutex_init (&bounds_mtx, عدم)
#تعریف_کړه EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#تعریف_کړه WAIT_SEM()             إذا (use_sem) pthread_mutex_lock (&bounds_mtx)
#تعریف_کړه POST_SEM()             إذا (use_sem) pthread_mutex_unlock (&bounds_mtx)
#تعریف_کړه TRY_SEM()              إذا (use_sem) pthread_mutex_trylock (&bounds_mtx)
#وإلا
ساكن pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#تعریف_کړه INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#تعریف_کړه EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#تعریف_کړه WAIT_SEM()             إذا (use_sem) pthread_spin_lock (&bounds_spin)
#تعریف_کړه POST_SEM()             إذا (use_sem) pthread_spin_unlock (&bounds_spin)
#تعریف_کړه TRY_SEM()              إذا (use_sem) pthread_spin_trylock (&bounds_spin)
#د_که_پای
#تعریف_کړه HAVE_MEMALIGN          (1)
#تعریف_کړه MALLOC_REDIR           (1)
#تعریف_کړه HAVE_PTHREAD_CREATE    (1)
#تعریف_کړه HAVE_CTYPE             (1)
#تعریف_کړه HAVE_ERRNO             (1)
#تعریف_کړه HAVE_SIGNAL            (1)
#تعریف_کړه HAVE_SIGACTION         (1)
#تعریف_کړه HAVE_FORK              (1)
#إذا defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_پرلپسې)
#تعریف_کړه HAVE_TLS_FUNC          (1)
#تعریف_کړه HAVE_TLS_VAR           (0)
#وإلا
#تعریف_کړه HAVE_TLS_FUNC          (0)
#تعریف_کړه HAVE_TLS_VAR           (1)
#د_که_پای
#إذا defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#د_که_پای
#د_که_پای

#إذا MALLOC_REDIR
ساكن فراغ *(*malloc_redir) (اندازه_t);
ساكن فراغ *(*calloc_redir) (اندازه_t, اندازه_t);
ساكن فراغ (*free_redir) (فراغ *);
ساكن فراغ *(*realloc_redir) (فراغ *, اندازه_t);
ساكن بینښه صحيح pool_شاخص;
ساكن بینښه حرف __attribute__((aligned(16))) initial_pool[256];
#د_که_پای
#إذا HAVE_MEMALIGN
ساكن فراغ *(*memalign_redir) (اندازه_t, اندازه_t);
#د_که_پای
#إذا HAVE_PTHREAD_CREATE
ساكن صحيح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    فراغ *(*پیل_routine)(فراغ *), فراغ *arg);
#د_که_پای
#إذا HAVE_SIGNAL
تعريفنوع فراغ (*bound_sig)(صحيح);
ساكن bound_sig (*signal_redir) (صحيح signum, bound_sig handler);
#د_که_پای
#إذا HAVE_SIGACTION
ساكن صحيح (*sigaction_redir) (صحيح signum, ثابت بنية sigaction *act,
                               بنية sigaction *oldact);
#د_که_پای
#إذا HAVE_FORK
ساكن صحيح (*fork_redir) (فراغ);
#د_که_پای

#تعریف_کړه TCC_TYPE_NONE           (0)
#تعریف_کړه TCC_TYPE_MALLOC         (1)
#تعریف_کړه TCC_TYPE_CALLOC         (2)
#تعریف_کړه TCC_TYPE_REALLOC        (3)
#تعریف_کړه TCC_TYPE_MEMALIGN       (4)
#تعریف_کړه TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#تعریف_کړه INVALID_اشاره_ګر ((فراغ *)(-2))

تعريفنوع بنية ونې_غوټه ونه;
بنية ونې_غوټه {
    ونه * کیڼ, * ښی;
    اندازه_t پیل;
    اندازه_t اندازه;
    بینښه حرف type;
    بینښه حرف is_invalid; /* true if pointers outside region are invalid */
};

تعريفنوع بنية alloca_list_struct {
    اندازه_t fp;
    فراغ *p;
    اندازه_t اندازه;
    بنية alloca_list_struct *بل;
} alloca_list_type;

#إذا defined(_WIN32)
#تعریف_کړه BOUND_TID_TYPE		DWORD
#تعریف_کړه BOUND_GET_TID(id)	id = GetCurrentThreadId()
#وإلاإذا defined(__OpenBSD__)
#تعریف_کړه BOUND_TID_TYPE		pid_t
#تعریف_کړه BOUND_GET_TID(id)	id = getthrid()
#وإلاإذا defined(__FreeBSD__)
#تعریف_کړه BOUND_TID_TYPE		pid_t
#تعریف_کړه BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#وإلاإذا  defined(__NetBSD__)
#تعریف_کړه BOUND_TID_TYPE		pid_t
#تعریف_کړه BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#وإلاإذا defined(__linux__)
#تعریف_کړه BOUND_TID_TYPE		pid_t
#تعریف_کړه BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#وإلا
#تعریف_کړه BOUND_TID_TYPE		صحيح
#تعریف_کړه BOUND_GET_TID(id)	id = 0
#د_که_پای

تعريفنوع بنية jmp_list_struct {
    فراغ *penv;
    اندازه_t fp;
    اندازه_t پای_ټکی_fp;
    BOUND_TID_TYPE tid;
    بنية jmp_list_struct *بل;
} jmp_list_type;

#تعریف_کړه BOUND_STATISTIC_SPLAY   (0)
ساكن ونه * splay (اندازه_t addr, ونه *t);
ساكن ونه * splay_پای_ټکی (اندازه_t addr, ونه *t);
ساكن ونه * splay_ورننباسه(اندازه_t addr, اندازه_t اندازه, ونه * t);
ساكن ونه * splay_delete(اندازه_t addr, ونه *t);
فراغ splay_printtree(ونه * t, صحيح d);

/* external interface */
فراغ __bounds_checking (صحيح no_check);
فراغ __bound_checking_lock (فراغ);
فراغ __bound_checking_unlock (فراغ);
فراغ __bound_never_fatal (صحيح no_check);
DLL_EXPORT فراغ * __bound_ptr_add(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir1(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir2(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir4(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir8(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir12(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ * __bound_ptr_indir16(فراغ *p, اندازه_t دننه_واټن);
DLL_EXPORT فراغ FASTCALL __bound_local_new(فراغ *p1);
DLL_EXPORT فراغ FASTCALL __bound_local_delete(فراغ *p1);
فراغ __bound_init(اندازه_t *, صحيح);
فراغ __bound_main_arg(صحيح argc, حرف **argv, حرف **envp);
فراغ __bound_exit(فراغ);
فراغ __bound_exit_dll(اندازه_t *);
#إذا !defined(_WIN32)
فراغ *__bound_mmap (فراغ *پیل, اندازه_t اندازه, صحيح prot, صحيح flags, صحيح fd,
                    off_t دننه_واټن);
صحيح __bound_munmap (فراغ *پیل, اندازه_t اندازه);
DLL_EXPORT فراغ __bound_siglongjmp(jmp_buf env, صحيح val);
#د_که_پای
DLL_EXPORT فراغ __bound_new_region(فراغ *p, اندازه_t اندازه);
DLL_EXPORT فراغ __bound_setjmp(jmp_buf env);
DLL_EXPORT فراغ __bound_longjmp(jmp_buf env, صحيح val);
DLL_EXPORT فراغ *__bound_memcpy(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound_memmove(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound_memset(فراغ *dst, صحيح c, اندازه_t اندازه);
DLL_EXPORT صحيح __bound_strlen(ثابت حرف *s);
DLL_EXPORT حرف *__bound_strcpy(حرف *dst, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncpy(حرف *dst, ثابت حرف *src, اندازه_t n);
DLL_EXPORT صحيح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2);
DLL_EXPORT صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, اندازه_t n);
DLL_EXPORT حرف *__bound_strcat(حرف *dest, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncat(حرف *dest, ثابت حرف *src, اندازه_t n);
DLL_EXPORT حرف *__bound_strchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strrchr(ثابت حرف *string, صحيح ch);
DLL_EXPORT حرف *__bound_strdup(ثابت حرف *s);

#إذا defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT فراغ *__bound___aeabi_memcpy(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound___aeabi_memmove(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound___aeabi_memmove4(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound___aeabi_memmove8(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__bound___aeabi_memset(فراغ *dst, صحيح c, اندازه_t اندازه);
DLL_EXPORT فراغ *__aeabi_memcpy(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__aeabi_memmove(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__aeabi_memmove4(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__aeabi_memmove8(فراغ *dst, ثابت فراغ *src, اندازه_t اندازه);
DLL_EXPORT فراغ *__aeabi_memset(فراغ *dst, صحيح c, اندازه_t اندازه);
#د_که_پای

#إذا MALLOC_REDIR
#تعریف_کړه BOUND_MALLOC(a)          malloc_redir(a)
#تعریف_کړه BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#تعریف_کړه BOUND_FREE(a)            free_redir(a)
#تعریف_کړه BOUND_REALLOC(a,b)       realloc_redir(a,b)
#تعریف_کړه BOUND_CALLOC(a,b)        calloc_redir(a,b)
#وإلا
#تعریف_کړه BOUND_MALLOC(a)          حافظه_ورکړه(a)
#تعریف_کړه BOUND_MEMALIGN(a,b)      memalign(a,b)
#تعریف_کړه BOUND_FREE(a)            حرر(a)
#تعریف_کړه BOUND_REALLOC(a,b)       realloc(a,b)
#تعریف_کړه BOUND_CALLOC(a,b)        حافظه_صفر_ورکړه(a,b)
DLL_EXPORT فراغ *__bound_malloc(اندازه_t اندازه, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_memalign(اندازه_t align, اندازه_t اندازه, ثابت فراغ *caller);
DLL_EXPORT فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_realloc(فراغ *ptr, اندازه_t اندازه, ثابت فراغ *caller);
DLL_EXPORT فراغ *__bound_calloc(اندازه_t nmemb, اندازه_t اندازه);
#د_که_پای

#تعریف_کړه FREE_REUSE_اندازه (100)
ساكن بینښه صحيح free_reuse_شاخص;
ساكن فراغ *free_reuse_list[FREE_REUSE_اندازه];

ساكن ونه *ونه_2 = عدم;
#تعریف_کړه ونه_REUSE      (1)
#إذا ونه_REUSE
ساكن ونه *ونه_free_list;
#د_که_پای
ساكن alloca_list_type *alloca_list;
ساكن jmp_list_type *jmp_list;

ساكن بینښه حرف inited;
ساكن بینښه حرف print_warn_ptr_جمع_کړه;
ساكن بینښه حرف print_calls;
ساكن بینښه حرف print_ډېرۍ;
ساكن بینښه حرف print_statistic;
ساكن بینښه حرف no_strdup;
ساكن بینښه حرف use_sem;
ساكن _Atomic صحيح never_fatal;
#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
ساكن صحيح no_checking = 0;
ساكن DWORD no_checking_کلی;
#تعریف_کړه NO_CHECKING_CHECK() إذا (!p) {                                         \
                                  p = (صحيح *) LocalAlloc(LPTR, حجم(صحيح));  \
                                  إذا (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_سېټ_ارزښت(no_checking_کلی, p);            \
                            }
#تعریف_کړه NO_CHECKING_GET()   ({ صحيح *p = Tls_Get_ارزښت(no_checking_کلی);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#تعریف_کړه NO_CHECKING_سېټ(v)  { صحيح *p = Tls_Get_ارزښت(no_checking_کلی);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#وإلا
ساكن صحيح no_checking = 0;
ساكن pthread_key_t no_checking_کلی;
#تعریف_کړه NO_CHECKING_CHECK() إذا (!p) {                                         \
                                  p = (صحيح *) BOUND_MALLOC(حجم(صحيح));      \
                                  إذا (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_کلی, p);    \
                            }
#تعریف_کړه NO_CHECKING_GET()   ({ صحيح *p = pthread_getspecific(no_checking_کلی); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#تعریف_کړه NO_CHECKING_سېټ(v)  { صحيح *p = pthread_getspecific(no_checking_کلی);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#د_که_پای
#وإلاإذا HAVE_TLS_VAR
ساكن __thread صحيح no_checking = 0;
#تعریف_کړه NO_CHECKING_GET()  no_checking
#تعریف_کړه NO_CHECKING_سېټ(v) no_checking = v 
#وإلا
ساكن _Atomic صحيح no_checking = 0;
#تعریف_کړه NO_CHECKING_GET()  no_checking
#تعریف_کړه NO_CHECKING_سېټ(v) no_checking = v 
#د_که_پای
ساكن حرف exec[100];

#إذا BOUND_STATISTIC
ساكن بینښه اوږد اوږد bound_ptr_جمع_کړه_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir1_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir2_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir4_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir8_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir12_شمېر;
ساكن بینښه اوږد اوږد bound_ptr_indir16_شمېر;
ساكن بینښه اوږد اوږد bound_local_new_شمېر;
ساكن بینښه اوږد اوږد bound_local_delete_شمېر;
ساكن بینښه اوږد اوږد bound_malloc_شمېر;
ساكن بینښه اوږد اوږد bound_calloc_شمېر;
ساكن بینښه اوږد اوږد bound_realloc_شمېر;
ساكن بینښه اوږد اوږد bound_free_شمېر;
ساكن بینښه اوږد اوږد bound_memalign_شمېر;
ساكن بینښه اوږد اوږد bound_mmap_شمېر;
ساكن بینښه اوږد اوږد bound_munmap_شمېر;
ساكن بینښه اوږد اوږد bound_alloca_شمېر;
ساكن بینښه اوږد اوږد bound_setjmp_شمېر;
ساكن بینښه اوږد اوږد bound_longjmp_شمېر;
ساكن بینښه اوږد اوږد bound_mempcy_شمېر;
ساكن بینښه اوږد اوږد bound_memcmp_شمېر;
ساكن بینښه اوږد اوږد bound_memmove_شمېر;
ساكن بینښه اوږد اوږد bound_memset_شمېر;
ساكن بینښه اوږد اوږد bound_strlen_شمېر;
ساكن بینښه اوږد اوږد bound_strcpy_شمېر;
ساكن بینښه اوږد اوږد bound_strncpy_شمېر;
ساكن بینښه اوږد اوږد bound_strcmp_شمېر;
ساكن بینښه اوږد اوږد bound_strncmp_شمېر;
ساكن بینښه اوږد اوږد bound_strcat_شمېر;
ساكن بینښه اوږد اوږد bound_strncat_شمېر;
ساكن بینښه اوږد اوږد bound_strchr_شمېر;
ساكن بینښه اوږد اوږد bound_strrchr_شمېر;
ساكن بینښه اوږد اوږد bound_strdup_شمېر;
ساكن بینښه اوږد اوږد bound_not_وموندل;
#تعریف_کړه INCR_شمېر(x)          ++x
#وإلا
#تعریف_کړه INCR_شمېر(x)
#د_که_پای
#إذا BOUND_STATISTIC_SPLAY
ساكن بینښه اوږد اوږد bound_splay;
ساكن بینښه اوږد اوږد bound_splay_پای_ټکی;
ساكن بینښه اوږد اوږد bound_splay_ورننباسه;
ساكن بینښه اوږد اوږد bound_splay_delete;
#تعریف_کړه INCR_شمېر_SPLAY(x)    ++x
#وإلا
#تعریف_کړه INCR_شمېر_SPLAY(x)
#د_که_پای

صحيح tcc_backtrace(ثابت حرف *fmt, ...);

/* print a bound error message */
#تعریف_کړه bound_warning(...) \
    افعل {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } طالما (0)

#تعریف_کړه bound_error(...)            \
    افعل {                            \
        bound_warning(__VA_ARGS__); \
        إذا (never_fatal == 0)       \
            وتل(255);              \
    } طالما (0)

#تعریف_کړه bounds_loc(fp, ...) \
    افعل {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } طالما (0)

ساكن فراغ bound_alloc_error(ثابت حرف *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    وتل (1);
}

ساكن فراغ bound_not_وموندل_warning(ثابت حرف *file, ثابت حرف *function,
                                    فراغ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
فراغ __bounds_checking (صحيح no_check)
{
#إذا HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_سېټ(NO_CHECKING_GET() + no_check);
#وإلا
    atomic_fetch_add (&no_checking, no_check);
#د_که_پای
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
فراغ * __bound_ptr_add(فراغ *p, اندازه_t دننه_واټن)
{
    اندازه_t addr = (اندازه_t)p;

    إذا (NO_CHECKING_GET())
        أرجع p + دننه_واټن;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (بینښه اوږد)دننه_واټن);

    WAIT_SEM ();
    INCR_شمېر(bound_ptr_جمع_کړه_شمېر);
    إذا (ونه_2) {
        addr -= ونه_2->پیل;
        إذا (addr >= ونه_2->اندازه) {
            addr = (اندازه_t)p;
            ونه_2 = splay (addr, ونه_2);
            addr -= ونه_2->پیل;
        }
        إذا (addr >= ونه_2->اندازه) {
            addr = (اندازه_t)p;
            ونه_2 = splay_پای_ټکی (addr, ونه_2);
            addr -= ونه_2->پیل;
        }
        إذا (addr <= ونه_2->اندازه) {
            إذا (ونه_2->is_invalid || addr + دننه_واټن > ونه_2->اندازه) {
                POST_SEM ();
                إذا (print_warn_ptr_جمع_کړه)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + دننه_واټن, (اوږد)ونه_2->پیل,
                                  (اوږد)(ونه_2->پیل + ونه_2->اندازه - 1));
                إذا (never_fatal <= 0)
                    أرجع INVALID_اشاره_ګر; /* return an invalid pointer */
                أرجع p + دننه_واټن;
            }
        }
        وإلا إذا (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_شمېر(bound_not_وموندل);
            POST_SEM ();
            bound_not_وموندل_warning (__FILE__, __FUNCTION__, p);
            أرجع p + دننه_واټن;
        }
    }
    POST_SEM ();
    أرجع p + دننه_واټن;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#تعریف_کړه BOUND_PTR_INDIR(dsize)                                                 \
فراغ * __bound_ptr_indir ## dsize (فراغ *p, اندازه_t دننه_واټن)                     \
{                                                                              \
    اندازه_t addr = (اندازه_t)p;                                                   \
                                                                               \
    إذا (NO_CHECKING_GET())                                                     \
        أرجع p + دننه_واټن;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (بینښه اوږد)دننه_واټن);                 \
    WAIT_SEM ();                                                               \
    INCR_شمېر(bound_ptr_indir ## dsize ## شمېر);                            \
    إذا (ونه_2) {                                                                \
        addr -= ونه_2->پیل;                                                   \
        إذا (addr >= ونه_2->اندازه) {                                              \
            addr = (اندازه_t)p;                                                  \
            ونه_2 = splay (addr, ونه_2);                                         \
            addr -= ونه_2->پیل;                                               \
        }                                                                      \
        إذا (addr >= ونه_2->اندازه) {                                              \
            addr = (اندازه_t)p;                                                  \
            ونه_2 = splay_پای_ټکی (addr, ونه_2);                                     \
            addr -= ونه_2->پیل;                                               \
        }                                                                      \
        إذا (addr <= ونه_2->اندازه) {                                              \
            إذا (ونه_2->is_invalid || addr + دننه_واټن + dsize > ونه_2->اندازه) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + دننه_واټن, dsize, (اوږد)ونه_2->پیل,            \
                              (اوږد)(ونه_2->پیل + ونه_2->اندازه - 1));           \
                إذا (never_fatal <= 0)                                          \
                    أرجع INVALID_اشاره_ګر; /* return an invalid pointer */    \
                أرجع p + دننه_واټن;                                             \
            }                                                                  \
        }                                                                      \
        وإلا {                                                                 \
            INCR_شمېر(bound_not_وموندل);                                       \
            POST_SEM ();                                                       \
            bound_not_وموندل_warning (__FILE__, __FUNCTION__, p);               \
            أرجع p + دننه_واټن;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    أرجع p + دننه_واټن;                                                         \
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
#لارښوونه GCC diagnostic ټېل
#لارښوونه GCC diagnostic ignored "-Wframe-address"
#د_که_پای

/* return the frame pointer of the caller */
#تعریف_کړه GET_CALLER_FP(fp)\
{\
    fp = (اندازه_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
فراغ FASTCALL __bound_local_new(فراغ *p1) 
{
    اندازه_t addr, fp, *p = p1;

    إذا (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_شمېر(bound_local_new_شمېر);
        ونه_2 = splay_ورننباسه(addr + fp, p[1], ونه_2);
        p += 2;
    }
    POST_SEM ();
#إذا BOUND_DEBUG
    إذا (print_calls) {
        p = p1;
        طالما ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (فراغ *) (addr + fp), (بینښه اوږد) p[1]);
            p += 2;
        }
    }
#د_که_پای
}

/* called when leaving a function to delete all the local regions */
فراغ FASTCALL __bound_local_delete(فراغ *p1) 
{
    اندازه_t addr, fp, *p = p1;

    إذا (NO_CHECKING_GET())
         أرجع;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (فراغ *)fp);
    WAIT_SEM ();
    طالما ((addr = p[0])) {
        INCR_شمېر(bound_local_delete_شمېر);
        ونه_2 = splay_delete(addr + fp, ونه_2);
        p += 2;
    }
    إذا (alloca_list) {
        alloca_list_type *وروستی = عدم;
        alloca_list_type *cur = alloca_list;

        افعل {
            إذا (cur->fp == fp) {
                إذا (وروستی)
                    وروستی->بل = cur->بل;
                وإلا
                    alloca_list = cur->بل;
                ونه_2 = splay_delete ((اندازه_t) cur->p, ونه_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = وروستی ? وروستی->بل : alloca_list;
             }
             وإلا {
                 وروستی = cur;
                 cur = cur->بل;
             }
        } طالما (cur);
    }
    إذا (jmp_list) {
        jmp_list_type *وروستی = عدم;
        jmp_list_type *cur = jmp_list;

        افعل {
            إذا (cur->fp == fp) {
                إذا (وروستی)
                    وروستی->بل = cur->بل;
                وإلا
                    jmp_list = cur->بل;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = وروستی ? وروستی->بل : jmp_list;
            }
            وإلا {
                وروستی = cur;
                cur = cur->بل;
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
                        (فراغ *) (addr + fp), (بینښه اوږد) p[1]);
            }
            p+= 2;
        }
    }
#د_که_پای
}

/* used by alloca */
فراغ __bound_new_region(فراغ *p, اندازه_t اندازه)
{
    اندازه_t fp;
    alloca_list_type *وروستی;
    alloca_list_type *cur;
    alloca_list_type *new;

    إذا (NO_CHECKING_GET())
        أرجع;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (بینښه اوږد)اندازه);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (حجم (alloca_list_type));
    WAIT_SEM ();
    INCR_شمېر(bound_alloca_شمېر);
    وروستی = عدم;
    cur = alloca_list;
    طالما (cur) {
#إذا defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحيح align = 4;
#وإلاإذا defined(__arm__)
        صحيح align = 8;
#وإلا
        صحيح align = 16;
#د_که_پای
        فراغ *cure = (فراغ *)((حرف *)cur->p + ((cur->اندازه + align) & -align));
        فراغ *pe = (فراغ *)((حرف *)p + ((اندازه + align) & -align));
        إذا (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            إذا (وروستی)
                وروستی->بل = cur->بل;
            وإلا
                alloca_list = cur->بل;
            ونه_2 = splay_delete((اندازه_t)cur->p, ونه_2);
            اكسر;
        }
        وروستی = cur;
        cur = cur->بل;
    }
    ونه_2 = splay_ورننباسه((اندازه_t)p, اندازه, ونه_2);
    إذا (new) {
        new->fp = fp;
        new->p = p;
        new->اندازه = اندازه;
        new->بل = alloca_list;
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
        INCR_شمېر(bound_setjmp_شمېر);
        jl = jmp_list;
        طالما (jl) {
            إذا (jl->penv == e)
                اكسر;
            jl = jl->بل;
        }
        إذا (jl == عدم) {
            jl = BOUND_MALLOC (حجم (jmp_list_type));
            إذا (jl) {
                jl->penv = e;
                jl->بل = jmp_list;
                jmp_list = jl;
            }
        }
        إذا (jl) {
            اندازه_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->پای_ټکی_fp = (اندازه_t)__builtin_frame_address(0);
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
        INCR_شمېر(bound_longjmp_شمېر);
        jl = jmp_list;
        طالما (jl) {
            إذا (jl->penv == e && jl->tid == tid) {
                اندازه_t پیل_fp = (اندازه_t)__builtin_frame_address(0);
                اندازه_t پای_ټکی_fp = jl->پای_ټکی_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *وروستی = عدم;

                طالما (cur->penv != e || cur->tid != tid) {
                    إذا (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        إذا (وروستی)
                            وروستی->بل = cur->بل;
                        وإلا
                            jmp_list = cur->بل;
                        BOUND_FREE (cur);
                        cur = وروستی ? وروستی->بل : jmp_list;
                    }
                    وإلا {
                        وروستی = cur;
                        cur = cur->بل;
                    }
                }
                لكل (;;) {
                    ونه *t = ونه_2;
                    alloca_list_type *وروستی;
                    alloca_list_type *cur;

                    طالما (t && (t->پیل < پیل_fp || t->پیل > پای_ټکی_fp))
                        إذا (t->پیل < پیل_fp)
                            t = t->ښی;
                        وإلا
                            t = t->کیڼ;
                    إذا (t == عدم)
                        اكسر;
                    وروستی = عدم;
                    cur = alloca_list;
                    طالما (cur) {
                         إذا ((اندازه_t) cur->p == t->پیل) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             إذا (وروستی)
                                 وروستی->بل = cur->بل;
                             وإلا
                                 alloca_list = cur->بل;
                             BOUND_FREE (cur);
                             اكسر;
                         }
                         وروستی = cur;
                         cur = cur->بل;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (فراغ *) t->پیل);
                    ونه_2 = splay_delete(t->پیل, ونه_2);
                }
                اكسر;
            }
            jl = jl->بل;
        }
        POST_SEM();
    }
#إذا !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#د_که_پای
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
#د_که_پای

#إذا (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#لارښوونه GCC diagnostic راوباسه
#د_که_پای

فراغ __bound_init(اندازه_t *p, صحيح ډېرپېښ)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            ډېرپېښ < 0 ? "lazy" : ډېرپېښ == 0 ? "normal use" : "for -run");

    إذا (inited) {
        WAIT_SEM();
        اذهب جمع_کړه_bounds;
    }
    inited = 1;

#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
    no_checking_کلی = TlsAlloc();
    Tls_سېټ_ارزښت(no_checking_کلی, &no_checking);
#وإلا
    pthread_key_create(&no_checking_کلی, عدم);
    pthread_setspecific(no_checking_کلی, &no_checking);
#د_که_پای
#د_که_پای
    NO_CHECKING_سېټ(1);

    print_warn_ptr_جمع_کړه = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != عدم;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != عدم;
    print_ډېرۍ = getenv ("TCC_BOUNDS_PRINT_HEAP") != عدم;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != عدم;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != عدم;

    INIT_SEM ();

#إذا MALLOC_REDIR
    {
        فراغ *addr = ډېرپېښ > 0 ? RTLD_DEFAULT : RTLD_بل;

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
#د_که_پای
#إذا HAVE_SIGNAL
        *(فراغ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        إذا (signal_redir == عدم)
            bound_alloc_error ("Cannot redirect signal");
#د_که_پای
#إذا HAVE_SIGACTION
        *(فراغ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        إذا (sigaction_redir == عدم)
            bound_alloc_error ("Cannot redirect sigaction");
#د_که_پای
#إذا HAVE_FORK
        *(فراغ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        إذا (fork_redir == عدم)
            bound_alloc_error ("Cannot redirect fork");
#د_که_پای
    }
#د_که_پای

#که_تعریف_شوی __linux__
    {
        FILE *fp;
        بینښه حرف وموندل;
        بینښه اوږد پیل;
        بینښه اوږد پای_ټکی;
        بینښه اوږد ad =
            (بینښه اوږد) __builtin_return_address(0);
        حرف کرښه[1000];

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
        وموندل = 0;
        fp = fopen ("/proc/self/maps", "r");
        إذا (fp) {
            طالما (fgets (کرښه, حجم(کرښه), fp)) {
                إذا (له_مزي_ولوله (کرښه, "%lx-%lx", &پیل, &پای_ټکی) == 2 &&
                            ad >= پیل && ad < پای_ټکی) {
                    وموندل = 1;
                    اكسر;
                }
                إذا (مزي_پلټنه (کرښه,"[heap]"))
                    اكسر;
            }
            fclose (fp);
        }
        إذا (وموندل == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#د_که_پای

    WAIT_SEM ();

#إذا HAVE_CTYPE
#که_تعریف_شوی __APPLE__
    ونه_2 = splay_ورننباسه((اندازه_t) &_DefaultRuneLocale,
                        حجم (_DefaultRuneLocale), ونه_2);
#وإلا
    /* XXX: Does not work if locale is changed */
    ونه_2 = splay_ورننباسه((اندازه_t) __ctype_b_loc(),
                        حجم (بینښه لنډ *), ونه_2);
    ونه_2 = splay_ورننباسه((اندازه_t) (*__ctype_b_loc() - 128),
                        384 * حجم (بینښه لنډ), ونه_2);
    ونه_2 = splay_ورننباسه((اندازه_t) __ctype_tolower_loc(),
                        حجم (__int32_t *), ونه_2);
    ونه_2 = splay_ورننباسه((اندازه_t) (*__ctype_tolower_loc() - 128),
                        384 * حجم (__int32_t), ونه_2);
    ونه_2 = splay_ورننباسه((اندازه_t) __ctype_toupper_loc(),
                        حجم (__int32_t *), ونه_2);
    ونه_2 = splay_ورننباسه((اندازه_t) (*__ctype_toupper_loc() - 128),
                        384 * حجم (__int32_t), ونه_2);
#د_که_پای
#د_که_پای
#إذا HAVE_ERRNO
    ونه_2 = splay_ورننباسه((اندازه_t) (&errno), حجم (صحيح), ونه_2);
#د_که_پای

جمع_کړه_bounds:
    إذا (!p)
        اذهب no_bounds;

    /* add all static bound check values */
    طالما (p[0] != 0) {
        ونه_2 = splay_ورننباسه(p[0], p[1], ونه_2);
#إذا BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (فراغ *) p[0], (بینښه اوږد) p[1]);
#د_که_پای
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_سېټ(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

فراغ
#إذا (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#د_که_پای
__bound_main_arg(صحيح argc, حرف **argv, حرف **envp)
{
    __bound_init (0, -1);
    إذا (argc && argv) {
        صحيح i;

        WAIT_SEM ();
        لكل (i = 0; i < argc; i++)
            ونه_2 = splay_ورننباسه((اندازه_t) argv[i], مزي_اوږدوالی (argv[i]) + 1, ونه_2);
        ونه_2 = splay_ورننباسه((اندازه_t) argv, (argc + 1) * حجم(حرف *), ونه_2);
        POST_SEM ();
#إذا BOUND_DEBUG
        إذا (print_calls) {
            لكل (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (بینښه اوږد)(مزي_اوږدوالی (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (صحيح)((argc + 1) * حجم(حرف *)));
        }
#د_که_پای
    }

    إذا (envp && *envp) {
        حرف **p = envp;

        WAIT_SEM ();
        طالما (*p) {
            ونه_2 = splay_ورننباسه((اندازه_t) *p, مزي_اوږدوالی (*p) + 1, ونه_2);
            ++p;
        }
        ونه_2 = splay_ورننباسه((اندازه_t) envp, (++p - envp) * حجم(حرف *), ونه_2);
        POST_SEM ();
#إذا BOUND_DEBUG
        إذا (print_calls) {
            p = envp;
            طالما (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (بینښه اوږد)(مزي_اوږدوالی (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (صحيح)((++p - envp) * حجم(حرف *)));
        }
#د_که_پای
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
        إذا (print_ډېرۍ) {
            خارجي فراغ __libc_freeres (فراغ);
            __libc_freeres ();
        }
#د_که_پای

        NO_CHECKING_سېټ(1);

        TRY_SEM ();
        طالما (alloca_list) {
            alloca_list_type *بل = alloca_list->بل;

            ونه_2 = splay_delete ((اندازه_t) alloca_list->p, ونه_2);
            BOUND_FREE (alloca_list);
            alloca_list = بل;
        }
        طالما (jmp_list) {
           jmp_list_type *بل  = jmp_list->بل;

           BOUND_FREE (jmp_list);
           jmp_list = بل;
        }
        لكل (i = 0; i < FREE_REUSE_اندازه; i++) {
            إذا (free_reuse_list[i]) {
                ونه_2 = splay_delete ((اندازه_t) free_reuse_list[i], ونه_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        طالما (ونه_2) {
            إذا (print_ډېرۍ && ونه_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[ونه_2->type],
                         (بینښه اوږد) ونه_2->اندازه);
            ونه_2 = splay_delete (ونه_2->پیل, ونه_2);
        }
#إذا ونه_REUSE
        طالما (ونه_free_list) {
            ونه *بل = ونه_free_list->کیڼ;
            BOUND_FREE (ونه_free_list);
            ونه_free_list = بل;
        }
#د_که_پای
        POST_SEM ();
        EXIT_SEM ();
#إذا HAVE_TLS_FUNC
#إذا defined(_WIN32)
        TlsFree(no_checking_کلی);
#وإلا
        pthread_key_delete(no_checking_کلی);
#د_که_پای
#د_که_پای
        inited = 0;
        إذا (print_statistic) {
#إذا BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_جمع_کړه_شمېر);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_شمېر);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_شمېر);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_شمېر);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_شمېر);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_شمېر);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_شمېر);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_شمېر);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_شمېر);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_شمېر);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_شمېر);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_شمېر);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_شمېر);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_شمېر);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_شمېر);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_شمېر);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_شمېر);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_شمېر);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_شمېر);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_شمېر);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_شمېر);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_شمېر);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_شمېر);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_شمېر);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_شمېر);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_شمېر);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_شمېر);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_شمېر);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_شمېر);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_شمېر);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_شمېر);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_شمېر);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_شمېر);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_وموندل);
#د_که_پای
#إذا BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_پای_ټکی);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ورننباسه);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#د_که_پای
        }
    }
}

فراغ __bound_exit_dll(اندازه_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    إذا (p) {
        WAIT_SEM ();
	طالما (p[0] != 0) {
	    ونه_2 = splay_delete(p[0], ونه_2);
#إذا BOUND_DEBUG
            إذا (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (فراغ *) p[0], (بینښه اوږد) p[1]);
            }
#د_که_پای
	    p += 2;
	}
        POST_SEM ();
    }
}

#إذا HAVE_PTHREAD_CREATE
تعريفنوع بنية {
    فراغ *(*پیل_routine) (فراغ *);
    فراغ *arg;
    sigset_t old_ماسک;
} bound_thread_create_type;

ساكن فراغ *bound_thread_create(فراغ *bdata)
{
    bound_thread_create_type *معلومات = (bound_thread_create_type *) bdata;
    فراغ *retval;
#إذا HAVE_TLS_FUNC
    صحيح *p = (صحيح *) BOUND_MALLOC(حجم(صحيح));
  
    إذا (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_کلی, p);
#د_که_پای
    pthread_sigmask(SIG_SETMASK, &معلومات->old_ماسک, عدم);
    retval = معلومات->پیل_routine(معلومات->arg);
#إذا HAVE_TLS_FUNC
    pthread_setspecific(no_checking_کلی, عدم);
    BOUND_FREE (p);
#د_که_پای
    BOUND_FREE (معلومات);
    أرجع retval;
}

صحيح pthread_create(pthread_t *thread, ثابت pthread_attr_t *attr,
                   فراغ *(*پیل_routine) (فراغ *), فراغ *arg)
{
    صحيح retval;
    bound_thread_create_type *معلومات;
    sigset_t ماسک;
    sigset_t old_ماسک;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&ماسک);
    pthread_sigmask(SIG_SETMASK, &ماسک, &old_ماسک);
    معلومات = (bound_thread_create_type *) BOUND_MALLOC(حجم(bound_thread_create_type));
    إذا (!معلومات) bound_alloc_error("bound_thread_create malloc");
    معلومات->پیل_routine = پیل_routine;
    معلومات->arg = arg;
    معلومات->old_ماسک = old_ماسک;
    retval = pthread_create_redir(thread, attr, bound_thread_create, معلومات);
    pthread_sigmask(SIG_SETMASK, &old_ماسک, عدم);
    أرجع retval;
}
#د_که_پای

#إذا HAVE_SIGNAL || HAVE_SIGACTION
تعريفنوع اتحاد {
#إذا HAVE_SIGNAL
    bound_sig signal_handler;
#د_که_پای
#إذا HAVE_SIGACTION
    فراغ (*sig_handler)(صحيح);
    فراغ (*sig_sigaction)(صحيح, siginfo_t *, فراغ *);
#د_که_پای
} bound_sig_type;

ساكن بینښه حرف bound_sig_کارول_شوی[NSIG];
ساكن bound_sig_type bound_sig_معلومات[NSIG];
#د_که_پای

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
        إذا (bound_sig_کارول_شوی[signum])
            retval = bound_sig_معلومات[signum].signal_handler;
        إذا (handler) {
            bound_sig_کارول_شوی[signum] = 1;
            bound_sig_معلومات[signum].signal_handler = handler;
        }
    }
    أرجع retval;
}
#د_که_پای

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
        إذا (bound_sig_کارول_شوی[signum]) {
            إذا (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_معلومات[signum].sig_sigaction;
            وإلا
                oact.sa_handler = bound_sig_معلومات[signum].sig_handler;
        }
        إذا (oldact) {
            *oldact = oact;
        }
        إذا (act) {
            bound_sig_کارول_شوی[signum] = 1;
            إذا (act->sa_flags & SA_SIGINFO)
                bound_sig_معلومات[signum].sig_sigaction = act->sa_sigaction;
            وإلا
                bound_sig_معلومات[signum].sig_handler = act->sa_handler;
        }
    }
    أرجع retval;
}
#د_که_پای

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
#د_که_پای

#إذا MALLOC_REDIR
فراغ *حافظه_ورکړه(اندازه_t اندازه)
#وإلا
فراغ *__bound_malloc(اندازه_t اندازه, ثابت فراغ *caller)
#د_که_پای
{
    فراغ *ptr;
    
#إذا MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    إذا (malloc_redir == عدم) {
        __bound_init (0, -1);
        إذا (malloc_redir == عدم) {
            ptr = &initial_pool[pool_شاخص];
            pool_شاخص = (pool_شاخص + اندازه + 15) & ~15;
            إذا (pool_شاخص >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (بینښه اوږد)اندازه);
            أرجع ptr;
        }
    }
#د_که_پای
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (اندازه + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (بینښه اوږد)اندازه);
    
    إذا (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_malloc_شمېر);

        إذا (ptr) {
            ونه_2 = splay_ورننباسه ((اندازه_t) ptr, اندازه ? اندازه : اندازه + 1, ونه_2);
            إذا (ونه_2 && ونه_2->پیل == (اندازه_t) ptr)
                ونه_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#إذا MALLOC_REDIR
فراغ *memalign(اندازه_t align, اندازه_t اندازه)
#وإلا
فراغ *__bound_memalign(اندازه_t align, اندازه_t اندازه, ثابت فراغ *caller)
#د_که_پای
{
    فراغ *ptr;

#إذا HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, اندازه + 1);
#وإلا
    إذا (align > 4) {
        /* XXX: handle it ? */
        ptr = عدم;
    } وإلا {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(اندازه + 1);
    }
#د_که_پای
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (بینښه اوږد)اندازه);

    إذا (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_memalign_شمېر);

        إذا (ptr) {
            ونه_2 = splay_ورننباسه((اندازه_t) ptr, اندازه ? اندازه : اندازه + 1, ونه_2);
            إذا (ونه_2 && ونه_2->پیل == (اندازه_t) ptr)
                ونه_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    أرجع ptr;
}

#إذا MALLOC_REDIR
فراغ حرر(فراغ *ptr)
#وإلا
فراغ __bound_free(فراغ *ptr, ثابت فراغ *caller)
#د_که_پای
{
    اندازه_t addr = (اندازه_t) ptr;
    فراغ *p;

    إذا (ptr == عدم || ونه_2 == عدم
#إذا MALLOC_REDIR
        || ((بینښه حرف *) ptr >= &initial_pool[0] &&
            (بینښه حرف *) ptr < &initial_pool[حجم(initial_pool)])
#د_که_پای
        )
        أرجع;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    إذا (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_free_شمېر);
        ونه_2 = splay (addr, ونه_2);
        إذا (ونه_2->پیل == addr) {
            إذا (ونه_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                أرجع;
            }
            ونه_2->is_invalid = 1;
            memset (ptr, 0x5a, ونه_2->اندازه);
            p = free_reuse_list[free_reuse_شاخص];
            free_reuse_list[free_reuse_شاخص] = ptr;
            free_reuse_شاخص = (free_reuse_شاخص + 1) % FREE_REUSE_اندازه;
            إذا (p)
                ونه_2 = splay_delete((اندازه_t)p, ونه_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#إذا MALLOC_REDIR
فراغ *realloc(فراغ *ptr, اندازه_t اندازه)
#وإلا
فراغ *__bound_realloc(فراغ *ptr, اندازه_t اندازه, ثابت فراغ *caller)
#د_که_پای
{
    فراغ *new_ptr;

    إذا (اندازه == 0) {
#إذا MALLOC_REDIR
        حرر(ptr);
#وإلا
        __bound_free(ptr, caller);
#د_که_پای
        أرجع عدم;
    }

    new_ptr = BOUND_REALLOC (ptr, اندازه + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (بینښه اوږد)اندازه);

    إذا (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_realloc_شمېر);

        إذا (ptr)
            ونه_2 = splay_delete ((اندازه_t) ptr, ونه_2);
        إذا (new_ptr) {
            ونه_2 = splay_ورننباسه ((اندازه_t) new_ptr, اندازه ? اندازه : اندازه + 1, ونه_2);
            إذا (ونه_2 && ونه_2->پیل == (اندازه_t) new_ptr)
                ونه_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    أرجع new_ptr;
}

#إذا MALLOC_REDIR
فراغ *حافظه_صفر_ورکړه(اندازه_t nmemb, اندازه_t اندازه)
#وإلا
فراغ *__bound_calloc(اندازه_t nmemb, اندازه_t اندازه)
#د_که_پای
{
    فراغ *ptr;

    اندازه *= nmemb;
#إذا MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    إذا (malloc_redir == عدم) {
        __bound_init (0, -1);
        إذا (malloc_redir == عدم) {
            ptr = &initial_pool[pool_شاخص];
            pool_شاخص = (pool_شاخص + اندازه + 15) & ~15;
            إذا (pool_شاخص >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (بینښه اوږد)اندازه);
            memset (ptr, 0, اندازه);
            أرجع ptr;
        }
    }
#د_که_پای
    ptr = BOUND_MALLOC(اندازه + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (بینښه اوږد)اندازه);

    إذا (ptr) {
        memset (ptr, 0, اندازه);
        إذا (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_شمېر(bound_calloc_شمېر);
            ونه_2 = splay_ورننباسه ((اندازه_t) ptr, اندازه ? اندازه : اندازه + 1, ونه_2);
            إذا (ونه_2 && ونه_2->پیل == (اندازه_t) ptr)
                ونه_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    أرجع ptr;
}

#إذا !defined(_WIN32)
فراغ *__bound_mmap (فراغ *پیل, اندازه_t اندازه, صحيح prot,
                    صحيح flags, صحيح fd, off_t دننه_واټن)
{
    فراغ *پایله;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, پیل, (بینښه اوږد)اندازه);
    پایله = mmap (پیل, اندازه, prot, flags, fd, دننه_واټن);
    إذا (پایله && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_mmap_شمېر);
        ونه_2 = splay_ورننباسه((اندازه_t)پایله, اندازه, ونه_2);
        POST_SEM ();
    }
    أرجع پایله;
}

صحيح __bound_munmap (فراغ *پیل, اندازه_t اندازه)
{
    صحيح پایله;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, پیل, (بینښه اوږد)اندازه);
    إذا (پیل && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_شمېر(bound_munmap_شمېر);
        ونه_2 = splay_delete ((اندازه_t) پیل, ونه_2);
        POST_SEM ();
    }
    پایله = munmap (پیل, اندازه);
    أرجع پایله;
}
#د_که_پای

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ساكن فراغ __bound_check(ثابت فراغ *p, اندازه_t اندازه, ثابت حرف *function)
{
    إذا (اندازه != 0 && __bound_ptr_add((فراغ *)p, اندازه) == INVALID_اشاره_ګر) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (بینښه اوږد)اندازه, function);
    }
}

ساكن صحيح check_overlap (ثابت فراغ *p1, اندازه_t n1,
                          ثابت فراغ *p2, اندازه_t n2,
                          ثابت حرف *function)
{
    ثابت فراغ *p1e = (ثابت فراغ *) ((ثابت حرف *) p1 + n1);
    ثابت فراغ *p2e = (ثابت فراغ *) ((ثابت حرف *) p2 + n2);

    إذا (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (بینښه اوږد)n1, p2, (بینښه اوږد)n2, function);
        أرجع never_fatal < 0;
    }
    أرجع 0;
}

فراغ *__bound_memcpy(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_mempcy_شمېر);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    إذا (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع حافظه_نقل(dest, src, n);
}

صحيح __bound_memcmp(ثابت فراغ *s1, ثابت فراغ *s2, اندازه_t n)
{
    ثابت بینښه حرف *u1 = (ثابت بینښه حرف *) s1;
    ثابت بینښه حرف *u2 = (ثابت بینښه حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (بینښه اوږد)n);
    INCR_شمېر(bound_memcmp_شمېر);
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

فراغ *__bound_memmove(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_memmove_شمېر);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع memmove(dest, src, n);
}

فراغ *__bound_memset(فراغ *s, صحيح c, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (بینښه اوږد)n);
    INCR_شمېر(bound_memset_شمېر);
    __bound_check(s, n, "memset");
    أرجع memset(s, c, n);
}

#إذا defined(__arm__) && defined(__ARM_EABI__)
فراغ *__bound___aeabi_memcpy(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_mempcy_شمېر);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    إذا (check_overlap(dest, n, src, n, "memcpy"))
        أرجع dest;
    أرجع __aeabi_memcpy(dest, src, n);
}

فراغ *__bound___aeabi_memmove(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_memmove_شمېر);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove(dest, src, n);
}

فراغ *__bound___aeabi_memmove4(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_memmove_شمېر);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove4(dest, src, n);
}

فراغ *__bound___aeabi_memmove8(فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_memmove_شمېر);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    أرجع __aeabi_memmove8(dest, src, n);
}

فراغ *__bound___aeabi_memset(فراغ *s, صحيح c, اندازه_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (بینښه اوږد)n);
    INCR_شمېر(bound_memset_شمېر);
    __bound_check(s, n, "memset");
    أرجع __aeabi_memset(s, c, n);
}
#د_که_پای

صحيح __bound_strlen(ثابت حرف *s)
{
    ثابت حرف *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_شمېر(bound_strlen_شمېر);
    طالما (*p++);
    __bound_check(s, p - s, "strlen");
    أرجع (p - s) - 1;
}

حرف *__bound_strcpy(حرف *dest, ثابت حرف *src)
{
    اندازه_t len;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_شمېر(bound_strcpy_شمېر);
    طالما (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    إذا (check_overlap(dest, len, src, len, "strcpy"))
        أرجع dest;
    أرجع strcpy (dest, src);
}

حرف *__bound_strncpy(حرف *dest, ثابت حرف *src, اندازه_t n)
{
    اندازه_t len = n;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_strncpy_شمېر);
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
    ثابت بینښه حرف *u1 = (ثابت بینښه حرف *) s1;
    ثابت بینښه حرف *u2 = (ثابت بینښه حرف *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_شمېر(bound_strcmp_شمېر);
    طالما (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت حرف *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت حرف *)u2 - s2) + 1, "strcmp s2");
    أرجع *u1 - *u2;
}

صحيح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, اندازه_t n)
{
    ثابت بینښه حرف *u1 = (ثابت بینښه حرف *) s1;
    ثابت بینښه حرف *u2 = (ثابت بینښه حرف *) s2;
    صحيح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (بینښه اوږد)n);
    INCR_شمېر(bound_strncmp_شمېر);
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
    INCR_شمېر(bound_strcat_شمېر);
    طالما (*dest++);
    طالما (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    إذا (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        أرجع dest;
    أرجع strcat(r, s);
}

حرف *__bound_strncat(حرف *dest, ثابت حرف *src, اندازه_t n)
{
    حرف *r = dest;
    ثابت حرف *s = src;
    اندازه_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (بینښه اوږد)n);
    INCR_شمېر(bound_strncat_شمېر);
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
    ثابت بینښه حرف *str = (ثابت بینښه حرف *) s;
    بینښه حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_شمېر(bound_strchr_شمېر);
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
    ثابت بینښه حرف *str = (ثابت بینښه حرف *) s;
    بینښه حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_شمېر(bound_strrchr_شمېر);
    طالما (*str++);
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    طالما (str != (ثابت بینښه حرف *)s) {
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

    INCR_شمېر(bound_strdup_شمېر);
    طالما (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (بینښه اوږد)(p -s));
    إذا (new) {
        إذا (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            ونه_2 = splay_ورننباسه((اندازه_t)new, p - s, ونه_2);
            إذا (ونه_2 && ونه_2->پیل == (اندازه_t) new)
                ونه_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        حافظه_نقل (new, s, p - s);
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

#تعریف_کړه compare(پیل,tstart,tsize) (پیل < tstart ? -1 : \
                                     پیل >= tstart+tsize  ? 1 : 0)

ساكن ونه * splay (اندازه_t addr, ونه *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    ونه N, *l, *r, *y;
    صحيح comp;
    
    INCR_شمېر_SPLAY(bound_splay);
    إذا (t == عدم) أرجع t;
    N.کیڼ = N.ښی = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare(addr, t->پیل, t->اندازه);
        إذا (comp < 0) {
            y = t->کیڼ;
            إذا (y == عدم) اكسر;
            إذا (compare(addr, y->پیل, y->اندازه) < 0) {
                t->کیڼ = y->ښی;                    /* rotate right */
                y->ښی = t;
                t = y;
                إذا (t->کیڼ == عدم) اكسر;
            }
            r->کیڼ = t;                               /* link right */
            r = t;
            t = t->کیڼ;
        } وإلا إذا (comp > 0) {
            y = t->ښی;
            إذا (y == عدم) اكسر;
            إذا (compare(addr, y->پیل, y->اندازه) > 0) {
                t->ښی = y->کیڼ;                    /* rotate left */
                y->کیڼ = t;
                t = y;
                إذا (t->ښی == عدم) اكسر;
            }
            l->ښی = t;                              /* link left */
            l = t;
            t = t->ښی;
        } وإلا {
            اكسر;
        }
    }
    l->ښی = t->کیڼ;                                /* assemble */
    r->کیڼ = t->ښی;
    t->کیڼ = N.ښی;
    t->ښی = N.کیڼ;

    أرجع t;
}

#تعریف_کړه compare_پای_ټکی(پیل,tend) (پیل < tend ? -1 : \
                                 پیل > tend  ? 1 : 0)

ساكن ونه * splay_پای_ټکی (اندازه_t addr, ونه *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    ونه N, *l, *r, *y;
    صحيح comp;
    
    INCR_شمېر_SPLAY(bound_splay_پای_ټکی);
    إذا (t == عدم) أرجع t;
    N.کیڼ = N.ښی = عدم;
    l = r = &N;
 
    لكل (;;) {
        comp = compare_پای_ټکی(addr, t->پیل + t->اندازه);
        إذا (comp < 0) {
            y = t->کیڼ;
            إذا (y == عدم) اكسر;
            إذا (compare_پای_ټکی(addr, y->پیل + y->اندازه) < 0) {
                t->کیڼ = y->ښی;                    /* rotate right */
                y->ښی = t;
                t = y;
                إذا (t->کیڼ == عدم) اكسر;
            }
            r->کیڼ = t;                               /* link right */
            r = t;
            t = t->کیڼ;
        } وإلا إذا (comp > 0) {
            y = t->ښی;
            إذا (y == عدم) اكسر;
            إذا (compare_پای_ټکی(addr, y->پیل + y->اندازه) > 0) {
                t->ښی = y->کیڼ;                    /* rotate left */
                y->کیڼ = t;
                t = y;
                إذا (t->ښی == عدم) اكسر;
            }
            l->ښی = t;                              /* link left */
            l = t;
            t = t->ښی;
        } وإلا {
            اكسر;
        }
    }
    l->ښی = t->کیڼ;                                /* assemble */
    r->کیڼ = t->ښی;
    t->کیڼ = N.ښی;
    t->ښی = N.کیڼ;

    أرجع t;
}

ساكن ونه * splay_ورننباسه(اندازه_t addr, اندازه_t اندازه, ونه * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    ونه * new;

    INCR_شمېر_SPLAY(bound_splay_ورننباسه);
    إذا (t != عدم) {
        t = splay(addr,t);
        إذا (compare(addr, t->پیل, t->اندازه)==0) {
            أرجع t;  /* it's already there */
        }
    }
#إذا ونه_REUSE
    إذا (ونه_free_list) {
          new = ونه_free_list;
          ونه_free_list = new->کیڼ;
    }
    وإلا
#د_که_پای
    {
        new = (ونه *) BOUND_MALLOC (حجم (ونه));
    }
    إذا (new == عدم) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    وإلا {
        إذا (t == عدم) {
            new->کیڼ = new->ښی = عدم;
        } وإلا إذا (compare(addr, t->پیل, t->اندازه) < 0) {
            new->کیڼ = t->کیڼ;
            new->ښی = t;
            t->کیڼ = عدم;
        } وإلا {
            new->ښی = t->ښی;
            new->کیڼ = t;
            t->ښی = عدم;
        }
        new->پیل = addr;
        new->اندازه = اندازه;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    أرجع new;
}

#تعریف_کړه compare_destroy(پیل,tstart) (پیل < tstart ? -1 : \
                                       پیل > tstart  ? 1 : 0)

ساكن ونه * splay_delete(اندازه_t addr, ونه *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    ونه * x;

    INCR_شمېر_SPLAY(bound_splay_delete);
    إذا (t==عدم) أرجع عدم;
    t = splay(addr,t);
    إذا (compare_destroy(addr, t->پیل) == 0) {        /* found it */
        إذا (t->کیڼ == عدم) {
            x = t->ښی;
        } وإلا {
            x = splay(addr, t->کیڼ);
            x->ښی = t->ښی;
        }
#إذا ونه_REUSE
        t->کیڼ = ونه_free_list;
        ونه_free_list = t;
#وإلا
        BOUND_FREE(t);
#د_که_پای
        أرجع x;
    } وإلا {
        أرجع t;                                      /* It wasn't there */
    }
}

فراغ splay_printtree(ونه * t, صحيح d)
{
    صحيح i;
    إذا (t == عدم) أرجع;
    splay_printtree(t->ښی, d+1);
    لكل (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (فراغ *) t->پیل, (بینښه اوږد) t->اندازه,
            (بینښه)t->type, (بینښه)t->is_invalid);
    splay_printtree(t->کیڼ, d+1);
}
