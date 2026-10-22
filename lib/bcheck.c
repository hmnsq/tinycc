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
#اگر_ختم

#اگر !defined(_WIN32)
#شامل <unistd.h>
#شامل <sys/syscall.h>
#اگر_ختم

#شامل "config.h"

#تعریف_کرو BOUND_DEBUG             (1)
#تعریف_کرو BOUND_STATISTIC         (1)

#اگر BOUND_DEBUG
 #تعریف_کرو dprintf(a...)         اگر (print_calls) { bounds_loc(a); }
#ورنہ
 #تعریف_کرو dprintf(a...)
#اگر_ختم

#اگر_تعریف_شدہ __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #تعریف_منسوخ __attribute__ 
#اگر_ختم
#اگر_تعریف_شدہ __i386__
#تعریف_کرو FASTCALL __attribute__((regparm(3)))
#ورنہ
#تعریف_کرو FASTCALL
#اگر_ختم

#اگر_تعریف_شدہ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ورنہ
# define DLL_EXPORT
#اگر_ختم

#اگر defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#شامل <sys/mman.h>
#تعریف_کرو INIT_SEM()
#تعریف_کرو EXIT_SEM()
#تعریف_کرو WAIT_SEM()
#تعریف_کرو POST_SEM()
#تعریف_کرو TRY_SEM()
#تعریف_کرو HAVE_MEMALIGN          (0)
#تعریف_کرو MALLOC_REDIR           (0)
#تعریف_کرو HAVE_PTHREAD_CREATE    (0)
#تعریف_کرو HAVE_CTYPE             (0)
#تعریف_کرو HAVE_ERRNO             (0)
#تعریف_کرو HAVE_SIGNAL            (0)
#تعریف_کرو HAVE_SIGACTION         (0)
#تعریف_کرو HAVE_FORK              (0)
#تعریف_کرو HAVE_TLS_FUNC          (0)
#تعریف_کرو HAVE_TLS_VAR           (0)

#وگرنہ_اگر defined(_WIN32)

#شامل <windows.h>
#شامل <signal.h>
ساکن CRITICAL_SECTION bounds_sem;
#تعریف_کرو INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#تعریف_کرو EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#تعریف_کرو WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#تعریف_کرو POST_SEM()             LeaveCriticalSection(&bounds_sem)
#تعریف_کرو TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#تعریف_کرو HAVE_MEMALIGN          (0)
#تعریف_کرو MALLOC_REDIR           (0)
#تعریف_کرو HAVE_PTHREAD_CREATE    (0)
#تعریف_کرو HAVE_CTYPE             (0)
#تعریف_کرو HAVE_ERRNO             (0)
#تعریف_کرو HAVE_SIGNAL            (1)
#تعریف_کرو HAVE_SIGACTION         (0)
#تعریف_کرو HAVE_FORK              (0)
#تعریف_کرو HAVE_TLS_FUNC          (1)
#تعریف_کرو HAVE_TLS_VAR           (0)

#ورنہ

#تعریف_کرو __USE_GNU              /* get RTLD_NEXT */
#شامل <sys/mman.h>
#شامل <ctype.h>
#شامل <pthread.h>
#شامل <dlfcn.h>
#شامل <errno.h>
#شامل <signal.h>
#اگر_تعریف_شدہ __APPLE__
#شامل <dispatch/dispatch.h>
ساکن dispatch_semaphore_t bounds_sem;
#تعریف_کرو INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#تعریف_کرو EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#تعریف_کرو WAIT_SEM()             اگر (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وقت_FOREVER)
#تعریف_کرو POST_SEM()             اگر (use_sem) dispatch_semaphore_signal(bounds_sem)
#تعریف_کرو TRY_SEM()              اگر (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_وقت_NOW)
#وگرنہ_اگر 0
#شامل <semaphore.h>
ساکن sem_t bounds_sem;
#تعریف_کرو INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#تعریف_کرو EXIT_SEM()             sem_destroy (&bounds_sem)
#تعریف_کرو WAIT_SEM()             اگر (use_sem) جب (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#تعریف_کرو POST_SEM()             اگر (use_sem) sem_post (&bounds_sem)
#تعریف_کرو TRY_SEM()              اگر (use_sem) جب (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#وگرنہ_اگر 0
ساکن pthread_mutex_t bounds_mtx;
#تعریف_کرو INIT_SEM()             pthread_mutex_init (&bounds_mtx, تہی)
#تعریف_کرو EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#تعریف_کرو WAIT_SEM()             اگر (use_sem) pthread_mutex_lock (&bounds_mtx)
#تعریف_کرو POST_SEM()             اگر (use_sem) pthread_mutex_unlock (&bounds_mtx)
#تعریف_کرو TRY_SEM()              اگر (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ورنہ
ساکن pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#تعریف_کرو INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#تعریف_کرو EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#تعریف_کرو WAIT_SEM()             اگر (use_sem) pthread_spin_lock (&bounds_spin)
#تعریف_کرو POST_SEM()             اگر (use_sem) pthread_spin_unlock (&bounds_spin)
#تعریف_کرو TRY_SEM()              اگر (use_sem) pthread_spin_trylock (&bounds_spin)
#اگر_ختم
#تعریف_کرو HAVE_MEMALIGN          (1)
#تعریف_کرو MALLOC_REDIR           (1)
#تعریف_کرو HAVE_PTHREAD_CREATE    (1)
#تعریف_کرو HAVE_CTYPE             (1)
#تعریف_کرو HAVE_ERRNO             (1)
#تعریف_کرو HAVE_SIGNAL            (1)
#تعریف_کرو HAVE_SIGACTION         (1)
#تعریف_کرو HAVE_FORK              (1)
#اگر defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_تسلسل)
#تعریف_کرو HAVE_TLS_FUNC          (1)
#تعریف_کرو HAVE_TLS_VAR           (0)
#ورنہ
#تعریف_کرو HAVE_TLS_FUNC          (0)
#تعریف_کرو HAVE_TLS_VAR           (1)
#اگر_ختم
#اگر defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#اگر_ختم
#اگر_ختم

#اگر MALLOC_REDIR
ساکن خالی *(*malloc_redir) (سائز_t);
ساکن خالی *(*calloc_redir) (سائز_t, سائز_t);
ساکن خالی (*free_redir) (خالی *);
ساکن خالی *(*realloc_redir) (خالی *, سائز_t);
ساکن غیرعلامتی صحیح pool_اشاریہ;
ساکن غیرعلامتی حرف __attribute__((aligned(16))) initial_pool[256];
#اگر_ختم
#اگر HAVE_MEMALIGN
ساکن خالی *(*memalign_redir) (سائز_t, سائز_t);
#اگر_ختم
#اگر HAVE_PTHREAD_CREATE
ساکن صحیح (*pthread_create_redir) (pthread_t *thread,
                                    ثابت pthread_attr_t *attr,
                                    خالی *(*آغاز_routine)(خالی *), خالی *arg);
#اگر_ختم
#اگر HAVE_SIGNAL
قسمتعریف خالی (*bound_sig)(صحیح);
ساکن bound_sig (*signal_redir) (صحیح signum, bound_sig handler);
#اگر_ختم
#اگر HAVE_SIGACTION
ساکن صحیح (*sigaction_redir) (صحیح signum, ثابت ساخت sigaction *act,
                               ساخت sigaction *oldact);
#اگر_ختم
#اگر HAVE_FORK
ساکن صحیح (*fork_redir) (خالی);
#اگر_ختم

#تعریف_کرو TCC_TYPE_NONE           (0)
#تعریف_کرو TCC_TYPE_MALLOC         (1)
#تعریف_کرو TCC_TYPE_CALLOC         (2)
#تعریف_کرو TCC_TYPE_REALLOC        (3)
#تعریف_کرو TCC_TYPE_MEMALIGN       (4)
#تعریف_کرو TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#تعریف_کرو INVALID_اشارہ_گر ((خالی *)(-2))

قسمتعریف ساخت درخت_گرہ درخت;
ساخت درخت_گرہ {
    درخت * بایاں, * دایاں;
    سائز_t آغاز;
    سائز_t سائز;
    غیرعلامتی حرف type;
    غیرعلامتی حرف is_invalid; /* true if pointers outside region are invalid */
};

قسمتعریف ساخت alloca_list_struct {
    سائز_t fp;
    خالی *p;
    سائز_t سائز;
    ساخت alloca_list_struct *اگلا;
} alloca_list_type;

#اگر defined(_WIN32)
#تعریف_کرو BOUND_TID_TYPE		DWORD
#تعریف_کرو BOUND_GET_TID(id)	id = GetCurrentThreadId()
#وگرنہ_اگر defined(__OpenBSD__)
#تعریف_کرو BOUND_TID_TYPE		pid_t
#تعریف_کرو BOUND_GET_TID(id)	id = getthrid()
#وگرنہ_اگر defined(__FreeBSD__)
#تعریف_کرو BOUND_TID_TYPE		pid_t
#تعریف_کرو BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#وگرنہ_اگر  defined(__NetBSD__)
#تعریف_کرو BOUND_TID_TYPE		pid_t
#تعریف_کرو BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#وگرنہ_اگر defined(__linux__)
#تعریف_کرو BOUND_TID_TYPE		pid_t
#تعریف_کرو BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ورنہ
#تعریف_کرو BOUND_TID_TYPE		صحیح
#تعریف_کرو BOUND_GET_TID(id)	id = 0
#اگر_ختم

قسمتعریف ساخت jmp_list_struct {
    خالی *penv;
    سائز_t fp;
    سائز_t انتہا_fp;
    BOUND_TID_TYPE tid;
    ساخت jmp_list_struct *اگلا;
} jmp_list_type;

#تعریف_کرو BOUND_STATISTIC_SPLAY   (0)
ساکن درخت * splay (سائز_t addr, درخت *t);
ساکن درخت * splay_انتہا (سائز_t addr, درخت *t);
ساکن درخت * splay_داخل_کرو(سائز_t addr, سائز_t سائز, درخت * t);
ساکن درخت * splay_delete(سائز_t addr, درخت *t);
خالی splay_printtree(درخت * t, صحیح d);

/* external interface */
خالی __bounds_checking (صحیح no_check);
خالی __bound_checking_lock (خالی);
خالی __bound_checking_unlock (خالی);
خالی __bound_never_fatal (صحیح no_check);
DLL_EXPORT خالی * __bound_ptr_add(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir1(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir2(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir4(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir8(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir12(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی * __bound_ptr_indir16(خالی *p, سائز_t انحراف);
DLL_EXPORT خالی FASTCALL __bound_local_new(خالی *p1);
DLL_EXPORT خالی FASTCALL __bound_local_delete(خالی *p1);
خالی __bound_init(سائز_t *, صحیح);
خالی __bound_main_arg(صحیح argc, حرف **argv, حرف **envp);
خالی __bound_exit(خالی);
خالی __bound_exit_dll(سائز_t *);
#اگر !defined(_WIN32)
خالی *__bound_mmap (خالی *آغاز, سائز_t سائز, صحیح prot, صحیح flags, صحیح fd,
                    off_t انحراف);
صحیح __bound_munmap (خالی *آغاز, سائز_t سائز);
DLL_EXPORT خالی __bound_siglongjmp(jmp_buf env, صحیح val);
#اگر_ختم
DLL_EXPORT خالی __bound_new_region(خالی *p, سائز_t سائز);
DLL_EXPORT خالی __bound_setjmp(jmp_buf env);
DLL_EXPORT خالی __bound_longjmp(jmp_buf env, صحیح val);
DLL_EXPORT خالی *__bound_memcpy(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT صحیح __bound_memcmp(ثابت خالی *s1, ثابت خالی *s2, سائز_t سائز);
DLL_EXPORT خالی *__bound_memmove(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__bound_memset(خالی *dst, صحیح c, سائز_t سائز);
DLL_EXPORT صحیح __bound_strlen(ثابت حرف *s);
DLL_EXPORT حرف *__bound_strcpy(حرف *dst, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncpy(حرف *dst, ثابت حرف *src, سائز_t n);
DLL_EXPORT صحیح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2);
DLL_EXPORT صحیح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, سائز_t n);
DLL_EXPORT حرف *__bound_strcat(حرف *dest, ثابت حرف *src);
DLL_EXPORT حرف *__bound_strncat(حرف *dest, ثابت حرف *src, سائز_t n);
DLL_EXPORT حرف *__bound_strchr(ثابت حرف *string, صحیح ch);
DLL_EXPORT حرف *__bound_strrchr(ثابت حرف *string, صحیح ch);
DLL_EXPORT حرف *__bound_strdup(ثابت حرف *s);

#اگر defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT خالی *__bound___aeabi_memcpy(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__bound___aeabi_memmove(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__bound___aeabi_memmove4(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__bound___aeabi_memmove8(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__bound___aeabi_memset(خالی *dst, صحیح c, سائز_t سائز);
DLL_EXPORT خالی *__aeabi_memcpy(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__aeabi_memmove(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__aeabi_memmove4(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__aeabi_memmove8(خالی *dst, ثابت خالی *src, سائز_t سائز);
DLL_EXPORT خالی *__aeabi_memset(خالی *dst, صحیح c, سائز_t سائز);
#اگر_ختم

#اگر MALLOC_REDIR
#تعریف_کرو BOUND_MALLOC(a)          malloc_redir(a)
#تعریف_کرو BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#تعریف_کرو BOUND_FREE(a)            free_redir(a)
#تعریف_کرو BOUND_REALLOC(a,b)       realloc_redir(a,b)
#تعریف_کرو BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ورنہ
#تعریف_کرو BOUND_MALLOC(a)          حافظہ_دو(a)
#تعریف_کرو BOUND_MEMALIGN(a,b)      memalign(a,b)
#تعریف_کرو BOUND_FREE(a)            آزاد(a)
#تعریف_کرو BOUND_REALLOC(a,b)       realloc(a,b)
#تعریف_کرو BOUND_CALLOC(a,b)        صفر_حافظہ_دو(a,b)
DLL_EXPORT خالی *__bound_malloc(سائز_t سائز, ثابت خالی *caller);
DLL_EXPORT خالی *__bound_memalign(سائز_t align, سائز_t سائز, ثابت خالی *caller);
DLL_EXPORT خالی __bound_free(خالی *ptr, ثابت خالی *caller);
DLL_EXPORT خالی *__bound_realloc(خالی *ptr, سائز_t سائز, ثابت خالی *caller);
DLL_EXPORT خالی *__bound_calloc(سائز_t nmemb, سائز_t سائز);
#اگر_ختم

#تعریف_کرو FREE_REUSE_سائز (100)
ساکن غیرعلامتی صحیح free_reuse_اشاریہ;
ساکن خالی *free_reuse_list[FREE_REUSE_سائز];

ساکن درخت *درخت_2 = تہی;
#تعریف_کرو درخت_REUSE      (1)
#اگر درخت_REUSE
ساکن درخت *درخت_free_list;
#اگر_ختم
ساکن alloca_list_type *alloca_list;
ساکن jmp_list_type *jmp_list;

ساکن غیرعلامتی حرف inited;
ساکن غیرعلامتی حرف print_warn_ptr_جوڑو;
ساکن غیرعلامتی حرف print_calls;
ساکن غیرعلامتی حرف print_ڈھیر;
ساکن غیرعلامتی حرف print_statistic;
ساکن غیرعلامتی حرف no_strdup;
ساکن غیرعلامتی حرف use_sem;
ساکن _Atomic صحیح never_fatal;
#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
ساکن صحیح no_checking = 0;
ساکن DWORD no_checking_کلید;
#تعریف_کرو NO_CHECKING_CHECK() اگر (!p) {                                         \
                                  p = (صحیح *) LocalAlloc(LPTR, حجم(صحیح));  \
                                  اگر (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_سیٹ_قدر(no_checking_کلید, p);            \
                            }
#تعریف_کرو NO_CHECKING_GET()   ({ صحیح *p = Tls_Get_قدر(no_checking_کلید);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#تعریف_کرو NO_CHECKING_سیٹ(v)  { صحیح *p = Tls_Get_قدر(no_checking_کلید);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ورنہ
ساکن صحیح no_checking = 0;
ساکن pthread_key_t no_checking_کلید;
#تعریف_کرو NO_CHECKING_CHECK() اگر (!p) {                                         \
                                  p = (صحیح *) BOUND_MALLOC(حجم(صحیح));      \
                                  اگر (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_کلید, p);    \
                            }
#تعریف_کرو NO_CHECKING_GET()   ({ صحیح *p = pthread_getspecific(no_checking_کلید); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#تعریف_کرو NO_CHECKING_سیٹ(v)  { صحیح *p = pthread_getspecific(no_checking_کلید);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#اگر_ختم
#وگرنہ_اگر HAVE_TLS_VAR
ساکن __thread صحیح no_checking = 0;
#تعریف_کرو NO_CHECKING_GET()  no_checking
#تعریف_کرو NO_CHECKING_سیٹ(v) no_checking = v 
#ورنہ
ساکن _Atomic صحیح no_checking = 0;
#تعریف_کرو NO_CHECKING_GET()  no_checking
#تعریف_کرو NO_CHECKING_سیٹ(v) no_checking = v 
#اگر_ختم
ساکن حرف exec[100];

#اگر BOUND_STATISTIC
ساکن غیرعلامتی طویل طویل bound_ptr_جوڑو_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir1_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir2_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir4_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir8_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir12_گنتی;
ساکن غیرعلامتی طویل طویل bound_ptr_indir16_گنتی;
ساکن غیرعلامتی طویل طویل bound_local_new_گنتی;
ساکن غیرعلامتی طویل طویل bound_local_delete_گنتی;
ساکن غیرعلامتی طویل طویل bound_malloc_گنتی;
ساکن غیرعلامتی طویل طویل bound_calloc_گنتی;
ساکن غیرعلامتی طویل طویل bound_realloc_گنتی;
ساکن غیرعلامتی طویل طویل bound_free_گنتی;
ساکن غیرعلامتی طویل طویل bound_memalign_گنتی;
ساکن غیرعلامتی طویل طویل bound_mmap_گنتی;
ساکن غیرعلامتی طویل طویل bound_munmap_گنتی;
ساکن غیرعلامتی طویل طویل bound_alloca_گنتی;
ساکن غیرعلامتی طویل طویل bound_setjmp_گنتی;
ساکن غیرعلامتی طویل طویل bound_longjmp_گنتی;
ساکن غیرعلامتی طویل طویل bound_mempcy_گنتی;
ساکن غیرعلامتی طویل طویل bound_memcmp_گنتی;
ساکن غیرعلامتی طویل طویل bound_memmove_گنتی;
ساکن غیرعلامتی طویل طویل bound_memset_گنتی;
ساکن غیرعلامتی طویل طویل bound_strlen_گنتی;
ساکن غیرعلامتی طویل طویل bound_strcpy_گنتی;
ساکن غیرعلامتی طویل طویل bound_strncpy_گنتی;
ساکن غیرعلامتی طویل طویل bound_strcmp_گنتی;
ساکن غیرعلامتی طویل طویل bound_strncmp_گنتی;
ساکن غیرعلامتی طویل طویل bound_strcat_گنتی;
ساکن غیرعلامتی طویل طویل bound_strncat_گنتی;
ساکن غیرعلامتی طویل طویل bound_strchr_گنتی;
ساکن غیرعلامتی طویل طویل bound_strrchr_گنتی;
ساکن غیرعلامتی طویل طویل bound_strdup_گنتی;
ساکن غیرعلامتی طویل طویل bound_not_ملا;
#تعریف_کرو INCR_گنتی(x)          ++x
#ورنہ
#تعریف_کرو INCR_گنتی(x)
#اگر_ختم
#اگر BOUND_STATISTIC_SPLAY
ساکن غیرعلامتی طویل طویل bound_splay;
ساکن غیرعلامتی طویل طویل bound_splay_انتہا;
ساکن غیرعلامتی طویل طویل bound_splay_داخل_کرو;
ساکن غیرعلامتی طویل طویل bound_splay_delete;
#تعریف_کرو INCR_گنتی_SPLAY(x)    ++x
#ورنہ
#تعریف_کرو INCR_گنتی_SPLAY(x)
#اگر_ختم

صحیح tcc_backtrace(ثابت حرف *fmt, ...);

/* print a bound error message */
#تعریف_کرو bound_warning(...) \
    کرو {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } جب (0)

#تعریف_کرو bound_error(...)            \
    کرو {                            \
        bound_warning(__VA_ARGS__); \
        اگر (never_fatal == 0)       \
            باہر_نکلو(255);              \
    } جب (0)

#تعریف_کرو bounds_loc(fp, ...) \
    کرو {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } جب (0)

ساکن خالی bound_alloc_error(ثابت حرف *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    باہر_نکلو (1);
}

ساکن خالی bound_not_ملا_warning(ثابت حرف *file, ثابت حرف *function,
                                    خالی *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
خالی __bounds_checking (صحیح no_check)
{
#اگر HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_سیٹ(NO_CHECKING_GET() + no_check);
#ورنہ
    atomic_fetch_add (&no_checking, no_check);
#اگر_ختم
}

خالی __bound_checking_lock(خالی)
{
    WAIT_SEM ();
}

خالی __bound_checking_unlock(خالی)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
خالی __bound_never_fatal (صحیح neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
خالی * __bound_ptr_add(خالی *p, سائز_t انحراف)
{
    سائز_t addr = (سائز_t)p;

    اگر (NO_CHECKING_GET())
        واپس p + انحراف;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (غیرعلامتی طویل)انحراف);

    WAIT_SEM ();
    INCR_گنتی(bound_ptr_جوڑو_گنتی);
    اگر (درخت_2) {
        addr -= درخت_2->آغاز;
        اگر (addr >= درخت_2->سائز) {
            addr = (سائز_t)p;
            درخت_2 = splay (addr, درخت_2);
            addr -= درخت_2->آغاز;
        }
        اگر (addr >= درخت_2->سائز) {
            addr = (سائز_t)p;
            درخت_2 = splay_انتہا (addr, درخت_2);
            addr -= درخت_2->آغاز;
        }
        اگر (addr <= درخت_2->سائز) {
            اگر (درخت_2->is_invalid || addr + انحراف > درخت_2->سائز) {
                POST_SEM ();
                اگر (print_warn_ptr_جوڑو)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + انحراف, (طویل)درخت_2->آغاز,
                                  (طویل)(درخت_2->آغاز + درخت_2->سائز - 1));
                اگر (never_fatal <= 0)
                    واپس INVALID_اشارہ_گر; /* return an invalid pointer */
                واپس p + انحراف;
            }
        }
        ورنہ اگر (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_گنتی(bound_not_ملا);
            POST_SEM ();
            bound_not_ملا_warning (__FILE__, __FUNCTION__, p);
            واپس p + انحراف;
        }
    }
    POST_SEM ();
    واپس p + انحراف;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#تعریف_کرو BOUND_PTR_INDIR(dsize)                                                 \
خالی * __bound_ptr_indir ## dsize (خالی *p, سائز_t انحراف)                     \
{                                                                              \
    سائز_t addr = (سائز_t)p;                                                   \
                                                                               \
    اگر (NO_CHECKING_GET())                                                     \
        واپس p + انحراف;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (غیرعلامتی طویل)انحراف);                 \
    WAIT_SEM ();                                                               \
    INCR_گنتی(bound_ptr_indir ## dsize ## گنتی);                            \
    اگر (درخت_2) {                                                                \
        addr -= درخت_2->آغاز;                                                   \
        اگر (addr >= درخت_2->سائز) {                                              \
            addr = (سائز_t)p;                                                  \
            درخت_2 = splay (addr, درخت_2);                                         \
            addr -= درخت_2->آغاز;                                               \
        }                                                                      \
        اگر (addr >= درخت_2->سائز) {                                              \
            addr = (سائز_t)p;                                                  \
            درخت_2 = splay_انتہا (addr, درخت_2);                                     \
            addr -= درخت_2->آغاز;                                               \
        }                                                                      \
        اگر (addr <= درخت_2->سائز) {                                              \
            اگر (درخت_2->is_invalid || addr + انحراف + dsize > درخت_2->سائز) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + انحراف, dsize, (طویل)درخت_2->آغاز,            \
                              (طویل)(درخت_2->آغاز + درخت_2->سائز - 1));           \
                اگر (never_fatal <= 0)                                          \
                    واپس INVALID_اشارہ_گر; /* return an invalid pointer */    \
                واپس p + انحراف;                                             \
            }                                                                  \
        }                                                                      \
        ورنہ {                                                                 \
            INCR_گنتی(bound_not_ملا);                                       \
            POST_SEM ();                                                       \
            bound_not_ملا_warning (__FILE__, __FUNCTION__, p);               \
            واپس p + انحراف;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    واپس p + انحراف;                                                         \
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
#ہدایت GCC diagnostic ڈالو
#ہدایت GCC diagnostic ignored "-Wframe-address"
#اگر_ختم

/* return the frame pointer of the caller */
#تعریف_کرو GET_CALLER_FP(fp)\
{\
    fp = (سائز_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
خالی FASTCALL __bound_local_new(خالی *p1) 
{
    سائز_t addr, fp, *p = p1;

    اگر (NO_CHECKING_GET())
         واپس;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (خالی *)fp);
    WAIT_SEM ();
    جب ((addr = p[0])) {
        INCR_گنتی(bound_local_new_گنتی);
        درخت_2 = splay_داخل_کرو(addr + fp, p[1], درخت_2);
        p += 2;
    }
    POST_SEM ();
#اگر BOUND_DEBUG
    اگر (print_calls) {
        p = p1;
        جب ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (خالی *) (addr + fp), (غیرعلامتی طویل) p[1]);
            p += 2;
        }
    }
#اگر_ختم
}

/* called when leaving a function to delete all the local regions */
خالی FASTCALL __bound_local_delete(خالی *p1) 
{
    سائز_t addr, fp, *p = p1;

    اگر (NO_CHECKING_GET())
         واپس;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (خالی *)fp);
    WAIT_SEM ();
    جب ((addr = p[0])) {
        INCR_گنتی(bound_local_delete_گنتی);
        درخت_2 = splay_delete(addr + fp, درخت_2);
        p += 2;
    }
    اگر (alloca_list) {
        alloca_list_type *آخری = تہی;
        alloca_list_type *cur = alloca_list;

        کرو {
            اگر (cur->fp == fp) {
                اگر (آخری)
                    آخری->اگلا = cur->اگلا;
                ورنہ
                    alloca_list = cur->اگلا;
                درخت_2 = splay_delete ((سائز_t) cur->p, درخت_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = آخری ? آخری->اگلا : alloca_list;
             }
             ورنہ {
                 آخری = cur;
                 cur = cur->اگلا;
             }
        } جب (cur);
    }
    اگر (jmp_list) {
        jmp_list_type *آخری = تہی;
        jmp_list_type *cur = jmp_list;

        کرو {
            اگر (cur->fp == fp) {
                اگر (آخری)
                    آخری->اگلا = cur->اگلا;
                ورنہ
                    jmp_list = cur->اگلا;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = آخری ? آخری->اگلا : jmp_list;
            }
            ورنہ {
                آخری = cur;
                cur = cur->اگلا;
            }
        } جب (cur);
    }

    POST_SEM ();
#اگر BOUND_DEBUG
    اگر (print_calls) {
        p = p1;
        جب ((addr = p[0])) {
            اگر (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (خالی *) (addr + fp), (غیرعلامتی طویل) p[1]);
            }
            p+= 2;
        }
    }
#اگر_ختم
}

/* used by alloca */
خالی __bound_new_region(خالی *p, سائز_t سائز)
{
    سائز_t fp;
    alloca_list_type *آخری;
    alloca_list_type *cur;
    alloca_list_type *new;

    اگر (NO_CHECKING_GET())
        واپس;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (غیرعلامتی طویل)سائز);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (حجم (alloca_list_type));
    WAIT_SEM ();
    INCR_گنتی(bound_alloca_گنتی);
    آخری = تہی;
    cur = alloca_list;
    جب (cur) {
#اگر defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        صحیح align = 4;
#وگرنہ_اگر defined(__arm__)
        صحیح align = 8;
#ورنہ
        صحیح align = 16;
#اگر_ختم
        خالی *cure = (خالی *)((حرف *)cur->p + ((cur->سائز + align) & -align));
        خالی *pe = (خالی *)((حرف *)p + ((سائز + align) & -align));
        اگر (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            اگر (آخری)
                آخری->اگلا = cur->اگلا;
            ورنہ
                alloca_list = cur->اگلا;
            درخت_2 = splay_delete((سائز_t)cur->p, درخت_2);
            توڑو;
        }
        آخری = cur;
        cur = cur->اگلا;
    }
    درخت_2 = splay_داخل_کرو((سائز_t)p, سائز, درخت_2);
    اگر (new) {
        new->fp = fp;
        new->p = p;
        new->سائز = سائز;
        new->اگلا = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    اگر (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

خالی __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    خالی *e = (خالی *) env;

    اگر (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_گنتی(bound_setjmp_گنتی);
        jl = jmp_list;
        جب (jl) {
            اگر (jl->penv == e)
                توڑو;
            jl = jl->اگلا;
        }
        اگر (jl == تہی) {
            jl = BOUND_MALLOC (حجم (jmp_list_type));
            اگر (jl) {
                jl->penv = e;
                jl->اگلا = jmp_list;
                jmp_list = jl;
            }
        }
        اگر (jl) {
            سائز_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->انتہا_fp = (سائز_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ساکن خالی __bound_long_jump(jmp_buf env, صحیح val, صحیح sig, ثابت حرف *func)
{
    jmp_list_type *jl;
    خالی *e;
    BOUND_TID_TYPE tid;

    اگر (NO_CHECKING_GET() == 0) {
        e = (خالی *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_گنتی(bound_longjmp_گنتی);
        jl = jmp_list;
        جب (jl) {
            اگر (jl->penv == e && jl->tid == tid) {
                سائز_t آغاز_fp = (سائز_t)__builtin_frame_address(0);
                سائز_t انتہا_fp = jl->انتہا_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *آخری = تہی;

                جب (cur->penv != e || cur->tid != tid) {
                    اگر (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        اگر (آخری)
                            آخری->اگلا = cur->اگلا;
                        ورنہ
                            jmp_list = cur->اگلا;
                        BOUND_FREE (cur);
                        cur = آخری ? آخری->اگلا : jmp_list;
                    }
                    ورنہ {
                        آخری = cur;
                        cur = cur->اگلا;
                    }
                }
                برائے (;;) {
                    درخت *t = درخت_2;
                    alloca_list_type *آخری;
                    alloca_list_type *cur;

                    جب (t && (t->آغاز < آغاز_fp || t->آغاز > انتہا_fp))
                        اگر (t->آغاز < آغاز_fp)
                            t = t->دایاں;
                        ورنہ
                            t = t->بایاں;
                    اگر (t == تہی)
                        توڑو;
                    آخری = تہی;
                    cur = alloca_list;
                    جب (cur) {
                         اگر ((سائز_t) cur->p == t->آغاز) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             اگر (آخری)
                                 آخری->اگلا = cur->اگلا;
                             ورنہ
                                 alloca_list = cur->اگلا;
                             BOUND_FREE (cur);
                             توڑو;
                         }
                         آخری = cur;
                         cur = cur->اگلا;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (خالی *) t->آغاز);
                    درخت_2 = splay_delete(t->آغاز, درخت_2);
                }
                توڑو;
            }
            jl = jl->اگلا;
        }
        POST_SEM();
    }
#اگر !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#اگر_ختم
    longjmp (env, val);
}

خالی __bound_longjmp(jmp_buf env, صحیح val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#اگر !defined(_WIN32)
خالی __bound_siglongjmp(jmp_buf env, صحیح val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#اگر_ختم

#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ہدایت GCC diagnostic نکالو
#اگر_ختم

خالی __bound_init(سائز_t *p, صحیح منوال)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            منوال < 0 ? "lazy" : منوال == 0 ? "normal use" : "for -run");

    اگر (inited) {
        WAIT_SEM();
        جاؤ جوڑو_bounds;
    }
    inited = 1;

#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
    no_checking_کلید = TlsAlloc();
    Tls_سیٹ_قدر(no_checking_کلید, &no_checking);
#ورنہ
    pthread_key_create(&no_checking_کلید, تہی);
    pthread_setspecific(no_checking_کلید, &no_checking);
#اگر_ختم
#اگر_ختم
    NO_CHECKING_سیٹ(1);

    print_warn_ptr_جوڑو = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != تہی;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != تہی;
    print_ڈھیر = getenv ("TCC_BOUNDS_PRINT_HEAP") != تہی;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != تہی;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != تہی;

    INIT_SEM ();

#اگر MALLOC_REDIR
    {
        خالی *addr = منوال > 0 ? RTLD_DEFAULT : RTLD_اگلا;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(خالی **) (&malloc_redir) = dlsym (addr, "malloc");
        اگر (malloc_redir == تہی) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(خالی **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(خالی **) (&calloc_redir) = dlsym (addr, "calloc");
        *(خالی **) (&free_redir) = dlsym (addr, "free");
        *(خالی **) (&realloc_redir) = dlsym (addr, "realloc");
        *(خالی **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        اگر (malloc_redir == تہی || free_redir == تہی)
            bound_alloc_error ("Cannot redirect malloc/free");
#اگر HAVE_PTHREAD_CREATE
        *(خالی **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        اگر (pthread_create_redir == تہی)
            bound_alloc_error ("Cannot redirect pthread_create");
#اگر_ختم
#اگر HAVE_SIGNAL
        *(خالی **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        اگر (signal_redir == تہی)
            bound_alloc_error ("Cannot redirect signal");
#اگر_ختم
#اگر HAVE_SIGACTION
        *(خالی **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        اگر (sigaction_redir == تہی)
            bound_alloc_error ("Cannot redirect sigaction");
#اگر_ختم
#اگر HAVE_FORK
        *(خالی **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        اگر (fork_redir == تہی)
            bound_alloc_error ("Cannot redirect fork");
#اگر_ختم
    }
#اگر_ختم

#اگر_تعریف_شدہ __linux__
    {
        FILE *fp;
        غیرعلامتی حرف ملا;
        غیرعلامتی طویل آغاز;
        غیرعلامتی طویل انتہا;
        غیرعلامتی طویل ad =
            (غیرعلامتی طویل) __builtin_return_address(0);
        حرف سطر[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        اگر (fp) {
            memset (exec, 0, حجم(exec));
            fread (exec, 1, حجم(exec) - 2, fp);
            اگر (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        ملا = 0;
        fp = fopen ("/proc/self/maps", "r");
        اگر (fp) {
            جب (fgets (سطر, حجم(سطر), fp)) {
                اگر (لڑی_سے_پڑھو (سطر, "%lx-%lx", &آغاز, &انتہا) == 2 &&
                            ad >= آغاز && ad < انتہا) {
                    ملا = 1;
                    توڑو;
                }
                اگر (لڑی_تلاش (سطر,"[heap]"))
                    توڑو;
            }
            fclose (fp);
        }
        اگر (ملا == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#اگر_ختم

    WAIT_SEM ();

#اگر HAVE_CTYPE
#اگر_تعریف_شدہ __APPLE__
    درخت_2 = splay_داخل_کرو((سائز_t) &_DefaultRuneLocale,
                        حجم (_DefaultRuneLocale), درخت_2);
#ورنہ
    /* XXX: Does not work if locale is changed */
    درخت_2 = splay_داخل_کرو((سائز_t) __ctype_b_loc(),
                        حجم (غیرعلامتی مختصر *), درخت_2);
    درخت_2 = splay_داخل_کرو((سائز_t) (*__ctype_b_loc() - 128),
                        384 * حجم (غیرعلامتی مختصر), درخت_2);
    درخت_2 = splay_داخل_کرو((سائز_t) __ctype_tolower_loc(),
                        حجم (__int32_t *), درخت_2);
    درخت_2 = splay_داخل_کرو((سائز_t) (*__ctype_tolower_loc() - 128),
                        384 * حجم (__int32_t), درخت_2);
    درخت_2 = splay_داخل_کرو((سائز_t) __ctype_toupper_loc(),
                        حجم (__int32_t *), درخت_2);
    درخت_2 = splay_داخل_کرو((سائز_t) (*__ctype_toupper_loc() - 128),
                        384 * حجم (__int32_t), درخت_2);
#اگر_ختم
#اگر_ختم
#اگر HAVE_ERRNO
    درخت_2 = splay_داخل_کرو((سائز_t) (&errno), حجم (صحیح), درخت_2);
#اگر_ختم

جوڑو_bounds:
    اگر (!p)
        جاؤ no_bounds;

    /* add all static bound check values */
    جب (p[0] != 0) {
        درخت_2 = splay_داخل_کرو(p[0], p[1], درخت_2);
#اگر BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (خالی *) p[0], (غیرعلامتی طویل) p[1]);
#اگر_ختم
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_سیٹ(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

خالی
#اگر (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#اگر_ختم
__bound_main_arg(صحیح argc, حرف **argv, حرف **envp)
{
    __bound_init (0, -1);
    اگر (argc && argv) {
        صحیح i;

        WAIT_SEM ();
        برائے (i = 0; i < argc; i++)
            درخت_2 = splay_داخل_کرو((سائز_t) argv[i], لڑی_لمبائی (argv[i]) + 1, درخت_2);
        درخت_2 = splay_داخل_کرو((سائز_t) argv, (argc + 1) * حجم(حرف *), درخت_2);
        POST_SEM ();
#اگر BOUND_DEBUG
        اگر (print_calls) {
            برائے (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (غیرعلامتی طویل)(لڑی_لمبائی (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (صحیح)((argc + 1) * حجم(حرف *)));
        }
#اگر_ختم
    }

    اگر (envp && *envp) {
        حرف **p = envp;

        WAIT_SEM ();
        جب (*p) {
            درخت_2 = splay_داخل_کرو((سائز_t) *p, لڑی_لمبائی (*p) + 1, درخت_2);
            ++p;
        }
        درخت_2 = splay_داخل_کرو((سائز_t) envp, (++p - envp) * حجم(حرف *), درخت_2);
        POST_SEM ();
#اگر BOUND_DEBUG
        اگر (print_calls) {
            p = envp;
            جب (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (غیرعلامتی طویل)(لڑی_لمبائی (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (صحیح)((++p - envp) * حجم(حرف *)));
        }
#اگر_ختم
    }
}

خالی __attribute__((destructor)) __bound_exit(خالی)
{
    صحیح i;
    ساکن ثابت حرف * ثابت alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    اگر (inited) {
#اگر !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        اگر (print_ڈھیر) {
            خارجی خالی __libc_freeres (خالی);
            __libc_freeres ();
        }
#اگر_ختم

        NO_CHECKING_سیٹ(1);

        TRY_SEM ();
        جب (alloca_list) {
            alloca_list_type *اگلا = alloca_list->اگلا;

            درخت_2 = splay_delete ((سائز_t) alloca_list->p, درخت_2);
            BOUND_FREE (alloca_list);
            alloca_list = اگلا;
        }
        جب (jmp_list) {
           jmp_list_type *اگلا  = jmp_list->اگلا;

           BOUND_FREE (jmp_list);
           jmp_list = اگلا;
        }
        برائے (i = 0; i < FREE_REUSE_سائز; i++) {
            اگر (free_reuse_list[i]) {
                درخت_2 = splay_delete ((سائز_t) free_reuse_list[i], درخت_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        جب (درخت_2) {
            اگر (print_ڈھیر && درخت_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[درخت_2->type],
                         (غیرعلامتی طویل) درخت_2->سائز);
            درخت_2 = splay_delete (درخت_2->آغاز, درخت_2);
        }
#اگر درخت_REUSE
        جب (درخت_free_list) {
            درخت *اگلا = درخت_free_list->بایاں;
            BOUND_FREE (درخت_free_list);
            درخت_free_list = اگلا;
        }
#اگر_ختم
        POST_SEM ();
        EXIT_SEM ();
#اگر HAVE_TLS_FUNC
#اگر defined(_WIN32)
        TlsFree(no_checking_کلید);
#ورنہ
        pthread_key_delete(no_checking_کلید);
#اگر_ختم
#اگر_ختم
        inited = 0;
        اگر (print_statistic) {
#اگر BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_جوڑو_گنتی);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_گنتی);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_گنتی);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_گنتی);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_گنتی);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_گنتی);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_گنتی);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_گنتی);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_گنتی);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_گنتی);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_گنتی);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_گنتی);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_گنتی);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_گنتی);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_گنتی);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_گنتی);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_گنتی);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_گنتی);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_گنتی);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_گنتی);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_گنتی);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_گنتی);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_گنتی);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_گنتی);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_گنتی);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_گنتی);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_گنتی);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_گنتی);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_گنتی);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_گنتی);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_گنتی);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_گنتی);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_گنتی);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_ملا);
#اگر_ختم
#اگر BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_انتہا);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_داخل_کرو);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#اگر_ختم
        }
    }
}

خالی __bound_exit_dll(سائز_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    اگر (p) {
        WAIT_SEM ();
	جب (p[0] != 0) {
	    درخت_2 = splay_delete(p[0], درخت_2);
#اگر BOUND_DEBUG
            اگر (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (خالی *) p[0], (غیرعلامتی طویل) p[1]);
            }
#اگر_ختم
	    p += 2;
	}
        POST_SEM ();
    }
}

#اگر HAVE_PTHREAD_CREATE
قسمتعریف ساخت {
    خالی *(*آغاز_routine) (خالی *);
    خالی *arg;
    sigset_t old_نقاب;
} bound_thread_create_type;

ساکن خالی *bound_thread_create(خالی *bdata)
{
    bound_thread_create_type *ڈیٹا = (bound_thread_create_type *) bdata;
    خالی *retval;
#اگر HAVE_TLS_FUNC
    صحیح *p = (صحیح *) BOUND_MALLOC(حجم(صحیح));
  
    اگر (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_کلید, p);
#اگر_ختم
    pthread_sigmask(SIG_SETMASK, &ڈیٹا->old_نقاب, تہی);
    retval = ڈیٹا->آغاز_routine(ڈیٹا->arg);
#اگر HAVE_TLS_FUNC
    pthread_setspecific(no_checking_کلید, تہی);
    BOUND_FREE (p);
#اگر_ختم
    BOUND_FREE (ڈیٹا);
    واپس retval;
}

صحیح pthread_create(pthread_t *thread, ثابت pthread_attr_t *attr,
                   خالی *(*آغاز_routine) (خالی *), خالی *arg)
{
    صحیح retval;
    bound_thread_create_type *ڈیٹا;
    sigset_t نقاب;
    sigset_t old_نقاب;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&نقاب);
    pthread_sigmask(SIG_SETMASK, &نقاب, &old_نقاب);
    ڈیٹا = (bound_thread_create_type *) BOUND_MALLOC(حجم(bound_thread_create_type));
    اگر (!ڈیٹا) bound_alloc_error("bound_thread_create malloc");
    ڈیٹا->آغاز_routine = آغاز_routine;
    ڈیٹا->arg = arg;
    ڈیٹا->old_نقاب = old_نقاب;
    retval = pthread_create_redir(thread, attr, bound_thread_create, ڈیٹا);
    pthread_sigmask(SIG_SETMASK, &old_نقاب, تہی);
    واپس retval;
}
#اگر_ختم

#اگر HAVE_SIGNAL || HAVE_SIGACTION
قسمتعریف اتحاد {
#اگر HAVE_SIGNAL
    bound_sig signal_handler;
#اگر_ختم
#اگر HAVE_SIGACTION
    خالی (*sig_handler)(صحیح);
    خالی (*sig_sigaction)(صحیح, siginfo_t *, خالی *);
#اگر_ختم
} bound_sig_type;

ساکن غیرعلامتی حرف bound_sig_مستعمل[NSIG];
ساکن bound_sig_type bound_sig_ڈیٹا[NSIG];
#اگر_ختم

#اگر HAVE_SIGNAL
ساکن خالی signal_handler(صحیح sig)
{
   __bounds_checking(1);
   bound_sig_ڈیٹا[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig اشارہ(صحیح signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    اگر (retval != SIG_ERR) {
        اگر (bound_sig_مستعمل[signum])
            retval = bound_sig_ڈیٹا[signum].signal_handler;
        اگر (handler) {
            bound_sig_مستعمل[signum] = 1;
            bound_sig_ڈیٹا[signum].signal_handler = handler;
        }
    }
    واپس retval;
}
#اگر_ختم

#اگر HAVE_SIGACTION
ساکن خالی sig_handler(صحیح sig)
{
   __bounds_checking(1);
   bound_sig_ڈیٹا[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ساکن خالی sig_sigaction(صحیح sig, siginfo_t *info, خالی *ucontext)
{
   __bounds_checking(1);
   bound_sig_ڈیٹا[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

صحیح sigaction(صحیح signum, ثابت ساخت sigaction *act, ساخت sigaction *oldact)
{
    صحیح retval;
    ساخت sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    اگر (sigaction_redir == تہی)
        __bound_init(0,-1);

    اگر (act) {
        nact = *act;
        اگر (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ورنہ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ورنہ
        retval = sigaction_redir(signum, act, &oact);
    اگر (retval >= 0) {
        اگر (bound_sig_مستعمل[signum]) {
            اگر (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_ڈیٹا[signum].sig_sigaction;
            ورنہ
                oact.sa_handler = bound_sig_ڈیٹا[signum].sig_handler;
        }
        اگر (oldact) {
            *oldact = oact;
        }
        اگر (act) {
            bound_sig_مستعمل[signum] = 1;
            اگر (act->sa_flags & SA_SIGINFO)
                bound_sig_ڈیٹا[signum].sig_sigaction = act->sa_sigaction;
            ورنہ
                bound_sig_ڈیٹا[signum].sig_handler = act->sa_handler;
        }
    }
    واپس retval;
}
#اگر_ختم

#اگر HAVE_FORK
pid_t fork(خالی)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    اگر (retval == 0)
        INIT_SEM();
    ورنہ
        POST_SEM();
    واپس retval;
}
#اگر_ختم

#اگر MALLOC_REDIR
خالی *حافظہ_دو(سائز_t سائز)
#ورنہ
خالی *__bound_malloc(سائز_t سائز, ثابت خالی *caller)
#اگر_ختم
{
    خالی *ptr;
    
#اگر MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    اگر (malloc_redir == تہی) {
        __bound_init (0, -1);
        اگر (malloc_redir == تہی) {
            ptr = &initial_pool[pool_اشاریہ];
            pool_اشاریہ = (pool_اشاریہ + سائز + 15) & ~15;
            اگر (pool_اشاریہ >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (غیرعلامتی طویل)سائز);
            واپس ptr;
        }
    }
#اگر_ختم
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (سائز + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (غیرعلامتی طویل)سائز);
    
    اگر (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_malloc_گنتی);

        اگر (ptr) {
            درخت_2 = splay_داخل_کرو ((سائز_t) ptr, سائز ? سائز : سائز + 1, درخت_2);
            اگر (درخت_2 && درخت_2->آغاز == (سائز_t) ptr)
                درخت_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    واپس ptr;
}

#اگر MALLOC_REDIR
خالی *memalign(سائز_t align, سائز_t سائز)
#ورنہ
خالی *__bound_memalign(سائز_t align, سائز_t سائز, ثابت خالی *caller)
#اگر_ختم
{
    خالی *ptr;

#اگر HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, سائز + 1);
#ورنہ
    اگر (align > 4) {
        /* XXX: handle it ? */
        ptr = تہی;
    } ورنہ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(سائز + 1);
    }
#اگر_ختم
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (غیرعلامتی طویل)سائز);

    اگر (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_memalign_گنتی);

        اگر (ptr) {
            درخت_2 = splay_داخل_کرو((سائز_t) ptr, سائز ? سائز : سائز + 1, درخت_2);
            اگر (درخت_2 && درخت_2->آغاز == (سائز_t) ptr)
                درخت_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    واپس ptr;
}

#اگر MALLOC_REDIR
خالی آزاد(خالی *ptr)
#ورنہ
خالی __bound_free(خالی *ptr, ثابت خالی *caller)
#اگر_ختم
{
    سائز_t addr = (سائز_t) ptr;
    خالی *p;

    اگر (ptr == تہی || درخت_2 == تہی
#اگر MALLOC_REDIR
        || ((غیرعلامتی حرف *) ptr >= &initial_pool[0] &&
            (غیرعلامتی حرف *) ptr < &initial_pool[حجم(initial_pool)])
#اگر_ختم
        )
        واپس;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    اگر (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_free_گنتی);
        درخت_2 = splay (addr, درخت_2);
        اگر (درخت_2->آغاز == addr) {
            اگر (درخت_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                واپس;
            }
            درخت_2->is_invalid = 1;
            memset (ptr, 0x5a, درخت_2->سائز);
            p = free_reuse_list[free_reuse_اشاریہ];
            free_reuse_list[free_reuse_اشاریہ] = ptr;
            free_reuse_اشاریہ = (free_reuse_اشاریہ + 1) % FREE_REUSE_سائز;
            اگر (p)
                درخت_2 = splay_delete((سائز_t)p, درخت_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#اگر MALLOC_REDIR
خالی *realloc(خالی *ptr, سائز_t سائز)
#ورنہ
خالی *__bound_realloc(خالی *ptr, سائز_t سائز, ثابت خالی *caller)
#اگر_ختم
{
    خالی *new_ptr;

    اگر (سائز == 0) {
#اگر MALLOC_REDIR
        آزاد(ptr);
#ورنہ
        __bound_free(ptr, caller);
#اگر_ختم
        واپس تہی;
    }

    new_ptr = BOUND_REALLOC (ptr, سائز + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (غیرعلامتی طویل)سائز);

    اگر (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_realloc_گنتی);

        اگر (ptr)
            درخت_2 = splay_delete ((سائز_t) ptr, درخت_2);
        اگر (new_ptr) {
            درخت_2 = splay_داخل_کرو ((سائز_t) new_ptr, سائز ? سائز : سائز + 1, درخت_2);
            اگر (درخت_2 && درخت_2->آغاز == (سائز_t) new_ptr)
                درخت_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    واپس new_ptr;
}

#اگر MALLOC_REDIR
خالی *صفر_حافظہ_دو(سائز_t nmemb, سائز_t سائز)
#ورنہ
خالی *__bound_calloc(سائز_t nmemb, سائز_t سائز)
#اگر_ختم
{
    خالی *ptr;

    سائز *= nmemb;
#اگر MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    اگر (malloc_redir == تہی) {
        __bound_init (0, -1);
        اگر (malloc_redir == تہی) {
            ptr = &initial_pool[pool_اشاریہ];
            pool_اشاریہ = (pool_اشاریہ + سائز + 15) & ~15;
            اگر (pool_اشاریہ >= حجم (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (غیرعلامتی طویل)سائز);
            memset (ptr, 0, سائز);
            واپس ptr;
        }
    }
#اگر_ختم
    ptr = BOUND_MALLOC(سائز + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (غیرعلامتی طویل)سائز);

    اگر (ptr) {
        memset (ptr, 0, سائز);
        اگر (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_گنتی(bound_calloc_گنتی);
            درخت_2 = splay_داخل_کرو ((سائز_t) ptr, سائز ? سائز : سائز + 1, درخت_2);
            اگر (درخت_2 && درخت_2->آغاز == (سائز_t) ptr)
                درخت_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    واپس ptr;
}

#اگر !defined(_WIN32)
خالی *__bound_mmap (خالی *آغاز, سائز_t سائز, صحیح prot,
                    صحیح flags, صحیح fd, off_t انحراف)
{
    خالی *نتیجہ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, آغاز, (غیرعلامتی طویل)سائز);
    نتیجہ = mmap (آغاز, سائز, prot, flags, fd, انحراف);
    اگر (نتیجہ && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_mmap_گنتی);
        درخت_2 = splay_داخل_کرو((سائز_t)نتیجہ, سائز, درخت_2);
        POST_SEM ();
    }
    واپس نتیجہ;
}

صحیح __bound_munmap (خالی *آغاز, سائز_t سائز)
{
    صحیح نتیجہ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, آغاز, (غیرعلامتی طویل)سائز);
    اگر (آغاز && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_گنتی(bound_munmap_گنتی);
        درخت_2 = splay_delete ((سائز_t) آغاز, درخت_2);
        POST_SEM ();
    }
    نتیجہ = munmap (آغاز, سائز);
    واپس نتیجہ;
}
#اگر_ختم

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ساکن خالی __bound_check(ثابت خالی *p, سائز_t سائز, ثابت حرف *function)
{
    اگر (سائز != 0 && __bound_ptr_add((خالی *)p, سائز) == INVALID_اشارہ_گر) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (غیرعلامتی طویل)سائز, function);
    }
}

ساکن صحیح check_overlap (ثابت خالی *p1, سائز_t n1,
                          ثابت خالی *p2, سائز_t n2,
                          ثابت حرف *function)
{
    ثابت خالی *p1e = (ثابت خالی *) ((ثابت حرف *) p1 + n1);
    ثابت خالی *p2e = (ثابت خالی *) ((ثابت حرف *) p2 + n2);

    اگر (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (غیرعلامتی طویل)n1, p2, (غیرعلامتی طویل)n2, function);
        واپس never_fatal < 0;
    }
    واپس 0;
}

خالی *__bound_memcpy(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_mempcy_گنتی);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    اگر (check_overlap(dest, n, src, n, "memcpy"))
        واپس dest;
    واپس حافظہ_نقل(dest, src, n);
}

صحیح __bound_memcmp(ثابت خالی *s1, ثابت خالی *s2, سائز_t n)
{
    ثابت غیرعلامتی حرف *u1 = (ثابت غیرعلامتی حرف *) s1;
    ثابت غیرعلامتی حرف *u2 = (ثابت غیرعلامتی حرف *) s2;
    صحیح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memcmp_گنتی);
    برائے (;;) {
        اگر ((ssize_t) --n == -1)
            توڑو;
        ورنہ اگر (*u1 != *u2) {
            retval = *u1++ - *u2++;
            توڑو;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ثابت خالی *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ثابت خالی *)u2 - s2, "memcmp s2");
    واپس retval;
}

خالی *__bound_memmove(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memmove_گنتی);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    واپس memmove(dest, src, n);
}

خالی *__bound_memset(خالی *s, صحیح c, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memset_گنتی);
    __bound_check(s, n, "memset");
    واپس memset(s, c, n);
}

#اگر defined(__arm__) && defined(__ARM_EABI__)
خالی *__bound___aeabi_memcpy(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_mempcy_گنتی);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    اگر (check_overlap(dest, n, src, n, "memcpy"))
        واپس dest;
    واپس __aeabi_memcpy(dest, src, n);
}

خالی *__bound___aeabi_memmove(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memmove_گنتی);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    واپس __aeabi_memmove(dest, src, n);
}

خالی *__bound___aeabi_memmove4(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memmove_گنتی);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    واپس __aeabi_memmove4(dest, src, n);
}

خالی *__bound___aeabi_memmove8(خالی *dest, ثابت خالی *src, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memmove_گنتی);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    واپس __aeabi_memmove8(dest, src, n);
}

خالی *__bound___aeabi_memset(خالی *s, صحیح c, سائز_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_memset_گنتی);
    __bound_check(s, n, "memset");
    واپس __aeabi_memset(s, c, n);
}
#اگر_ختم

صحیح __bound_strlen(ثابت حرف *s)
{
    ثابت حرف *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_گنتی(bound_strlen_گنتی);
    جب (*p++);
    __bound_check(s, p - s, "strlen");
    واپس (p - s) - 1;
}

حرف *__bound_strcpy(حرف *dest, ثابت حرف *src)
{
    سائز_t len;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_گنتی(bound_strcpy_گنتی);
    جب (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    اگر (check_overlap(dest, len, src, len, "strcpy"))
        واپس dest;
    واپس strcpy (dest, src);
}

حرف *__bound_strncpy(حرف *dest, ثابت حرف *src, سائز_t n)
{
    سائز_t len = n;
    ثابت حرف *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_strncpy_گنتی);
    جب (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    اگر (check_overlap(dest, len, src, len, "strncpy"))
        واپس dest;
    واپس strncpy(dest, src, n);
}

صحیح __bound_strcmp(ثابت حرف *s1, ثابت حرف *s2)
{
    ثابت غیرعلامتی حرف *u1 = (ثابت غیرعلامتی حرف *) s1;
    ثابت غیرعلامتی حرف *u2 = (ثابت غیرعلامتی حرف *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_گنتی(bound_strcmp_گنتی);
    جب (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ثابت حرف *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ثابت حرف *)u2 - s2) + 1, "strcmp s2");
    واپس *u1 - *u2;
}

صحیح __bound_strncmp(ثابت حرف *s1, ثابت حرف *s2, سائز_t n)
{
    ثابت غیرعلامتی حرف *u1 = (ثابت غیرعلامتی حرف *) s1;
    ثابت غیرعلامتی حرف *u2 = (ثابت غیرعلامتی حرف *) s2;
    صحیح retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_strncmp_گنتی);
    کرو {
        اگر ((ssize_t) --n == -1)
            توڑو;
        ورنہ اگر (*u1 != *u2) {
            retval = *u1++ - *u2++;
            توڑو;
        }
        ++u2;
    } جب (*u1++);
    __bound_check(s1, (ثابت حرف *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ثابت حرف *)u2 - s2, "strncmp s2");
    واپس retval;
}

حرف *__bound_strcat(حرف *dest, ثابت حرف *src)
{
    حرف *r = dest;
    ثابت حرف *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_گنتی(bound_strcat_گنتی);
    جب (*dest++);
    جب (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    اگر (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        واپس dest;
    واپس strcat(r, s);
}

حرف *__bound_strncat(حرف *dest, ثابت حرف *src, سائز_t n)
{
    حرف *r = dest;
    ثابت حرف *s = src;
    سائز_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (غیرعلامتی طویل)n);
    INCR_گنتی(bound_strncat_گنتی);
    جب (*dest++);
    جب (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    اگر (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        واپس dest;
    واپس strncat(r, s, n);
}

حرف *__bound_strchr(ثابت حرف *s, صحیح c)
{
    ثابت غیرعلامتی حرف *str = (ثابت غیرعلامتی حرف *) s;
    غیرعلامتی حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_گنتی(bound_strchr_گنتی);
    جب (*str) {
        اگر (*str == ch)
            توڑو;
        ++str;
    }
    __bound_check(s, ((ثابت حرف *)str - s) + 1, "strchr");
    واپس *str == ch ? (حرف *) str : تہی;
}

حرف *__bound_strrchr(ثابت حرف *s, صحیح c)
{
    ثابت غیرعلامتی حرف *str = (ثابت غیرعلامتی حرف *) s;
    غیرعلامتی حرف ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_گنتی(bound_strrchr_گنتی);
    جب (*str++);
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    جب (str != (ثابت غیرعلامتی حرف *)s) {
        اگر (*--str == ch)
            توڑو;
    }
    __bound_check(s, (ثابت حرف *)str - s, "strrchr");
    واپس *str == ch ? (حرف *) str : تہی;
}

حرف *__bound_strdup(ثابت حرف *s)
{
    ثابت حرف *p = s;
    حرف *new;

    INCR_گنتی(bound_strdup_گنتی);
    جب (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (غیرعلامتی طویل)(p -s));
    اگر (new) {
        اگر (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            درخت_2 = splay_داخل_کرو((سائز_t)new, p - s, درخت_2);
            اگر (درخت_2 && درخت_2->آغاز == (سائز_t) new)
                درخت_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        حافظہ_نقل (new, s, p - s);
    }
    واپس new;
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

#تعریف_کرو compare(آغاز,tstart,tsize) (آغاز < tstart ? -1 : \
                                     آغاز >= tstart+tsize  ? 1 : 0)

ساکن درخت * splay (سائز_t addr, درخت *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    درخت N, *l, *r, *y;
    صحیح comp;
    
    INCR_گنتی_SPLAY(bound_splay);
    اگر (t == تہی) واپس t;
    N.بایاں = N.دایاں = تہی;
    l = r = &N;
 
    برائے (;;) {
        comp = compare(addr, t->آغاز, t->سائز);
        اگر (comp < 0) {
            y = t->بایاں;
            اگر (y == تہی) توڑو;
            اگر (compare(addr, y->آغاز, y->سائز) < 0) {
                t->بایاں = y->دایاں;                    /* rotate right */
                y->دایاں = t;
                t = y;
                اگر (t->بایاں == تہی) توڑو;
            }
            r->بایاں = t;                               /* link right */
            r = t;
            t = t->بایاں;
        } ورنہ اگر (comp > 0) {
            y = t->دایاں;
            اگر (y == تہی) توڑو;
            اگر (compare(addr, y->آغاز, y->سائز) > 0) {
                t->دایاں = y->بایاں;                    /* rotate left */
                y->بایاں = t;
                t = y;
                اگر (t->دایاں == تہی) توڑو;
            }
            l->دایاں = t;                              /* link left */
            l = t;
            t = t->دایاں;
        } ورنہ {
            توڑو;
        }
    }
    l->دایاں = t->بایاں;                                /* assemble */
    r->بایاں = t->دایاں;
    t->بایاں = N.دایاں;
    t->دایاں = N.بایاں;

    واپس t;
}

#تعریف_کرو compare_انتہا(آغاز,tend) (آغاز < tend ? -1 : \
                                 آغاز > tend  ? 1 : 0)

ساکن درخت * splay_انتہا (سائز_t addr, درخت *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    درخت N, *l, *r, *y;
    صحیح comp;
    
    INCR_گنتی_SPLAY(bound_splay_انتہا);
    اگر (t == تہی) واپس t;
    N.بایاں = N.دایاں = تہی;
    l = r = &N;
 
    برائے (;;) {
        comp = compare_انتہا(addr, t->آغاز + t->سائز);
        اگر (comp < 0) {
            y = t->بایاں;
            اگر (y == تہی) توڑو;
            اگر (compare_انتہا(addr, y->آغاز + y->سائز) < 0) {
                t->بایاں = y->دایاں;                    /* rotate right */
                y->دایاں = t;
                t = y;
                اگر (t->بایاں == تہی) توڑو;
            }
            r->بایاں = t;                               /* link right */
            r = t;
            t = t->بایاں;
        } ورنہ اگر (comp > 0) {
            y = t->دایاں;
            اگر (y == تہی) توڑو;
            اگر (compare_انتہا(addr, y->آغاز + y->سائز) > 0) {
                t->دایاں = y->بایاں;                    /* rotate left */
                y->بایاں = t;
                t = y;
                اگر (t->دایاں == تہی) توڑو;
            }
            l->دایاں = t;                              /* link left */
            l = t;
            t = t->دایاں;
        } ورنہ {
            توڑو;
        }
    }
    l->دایاں = t->بایاں;                                /* assemble */
    r->بایاں = t->دایاں;
    t->بایاں = N.دایاں;
    t->دایاں = N.بایاں;

    واپس t;
}

ساکن درخت * splay_داخل_کرو(سائز_t addr, سائز_t سائز, درخت * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    درخت * new;

    INCR_گنتی_SPLAY(bound_splay_داخل_کرو);
    اگر (t != تہی) {
        t = splay(addr,t);
        اگر (compare(addr, t->آغاز, t->سائز)==0) {
            واپس t;  /* it's already there */
        }
    }
#اگر درخت_REUSE
    اگر (درخت_free_list) {
          new = درخت_free_list;
          درخت_free_list = new->بایاں;
    }
    ورنہ
#اگر_ختم
    {
        new = (درخت *) BOUND_MALLOC (حجم (درخت));
    }
    اگر (new == تہی) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ورنہ {
        اگر (t == تہی) {
            new->بایاں = new->دایاں = تہی;
        } ورنہ اگر (compare(addr, t->آغاز, t->سائز) < 0) {
            new->بایاں = t->بایاں;
            new->دایاں = t;
            t->بایاں = تہی;
        } ورنہ {
            new->دایاں = t->دایاں;
            new->بایاں = t;
            t->دایاں = تہی;
        }
        new->آغاز = addr;
        new->سائز = سائز;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    واپس new;
}

#تعریف_کرو compare_destroy(آغاز,tstart) (آغاز < tstart ? -1 : \
                                       آغاز > tstart  ? 1 : 0)

ساکن درخت * splay_delete(سائز_t addr, درخت *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    درخت * x;

    INCR_گنتی_SPLAY(bound_splay_delete);
    اگر (t==تہی) واپس تہی;
    t = splay(addr,t);
    اگر (compare_destroy(addr, t->آغاز) == 0) {        /* found it */
        اگر (t->بایاں == تہی) {
            x = t->دایاں;
        } ورنہ {
            x = splay(addr, t->بایاں);
            x->دایاں = t->دایاں;
        }
#اگر درخت_REUSE
        t->بایاں = درخت_free_list;
        درخت_free_list = t;
#ورنہ
        BOUND_FREE(t);
#اگر_ختم
        واپس x;
    } ورنہ {
        واپس t;                                      /* It wasn't there */
    }
}

خالی splay_printtree(درخت * t, صحیح d)
{
    صحیح i;
    اگر (t == تہی) واپس;
    splay_printtree(t->دایاں, d+1);
    برائے (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (خالی *) t->آغاز, (غیرعلامتی طویل) t->سائز,
            (غیرعلامتی)t->type, (غیرعلامتی)t->is_invalid);
    splay_printtree(t->بایاں, d+1);
}
