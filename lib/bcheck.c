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
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdarg.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <setjmp.h>
#অন্তর্ভাব <stdatomic.h>

#যদি !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#অন্তর্ভাব <malloc.h>
#endif

#যদি !defined(_WIN32)
#অন্তর্ভাব <unistd.h>
#অন্তর্ভাব <sys/syscall.h>
#endif

#অন্তর্ভাব "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#যদি BOUND_DEBUG
 #define dprintf(a...)         যদি (print_calls) { bounds_loc(a); }
#অন্যথা
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#অন্যথা
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#অন্যথা
# define DLL_EXPORT
#endif

#যদি defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#অন্তর্ভাব <sys/mman.h>
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

#নতুবা_যদি defined(_WIN32)

#অন্তর্ভাব <windows.h>
#অন্তর্ভাব <signal.h>
স্থির CRITICAL_SECTION bounds_sem;
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

#অন্যথা

#define __USE_GNU              /* get RTLD_NEXT */
#অন্তর্ভাব <sys/mman.h>
#অন্তর্ভাব <ctype.h>
#অন্তর্ভাব <pthread.h>
#অন্তর্ভাব <dlfcn.h>
#অন্তর্ভাব <errno.h>
#অন্তর্ভাব <signal.h>
#ifdef __APPLE__
#অন্তর্ভাব <dispatch/dispatch.h>
স্থির dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             যদি (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             যদি (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              যদি (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#নতুবা_যদি 0
#অন্তর্ভাব <semaphore.h>
স্থির sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             যদি (use_sem) যখন (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             যদি (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              যদি (use_sem) যখন (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#নতুবা_যদি 0
স্থির pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, ফাঁকা)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             যদি (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             যদি (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              যদি (use_sem) pthread_mutex_trylock (&bounds_mtx)
#অন্যথা
স্থির pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             যদি (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             যদি (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              যদি (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#যদি defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#অন্যথা
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#যদি defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#যদি MALLOC_REDIR
স্থির শূন্য *(*malloc_redir) (আকার_t);
স্থির শূন্য *(*calloc_redir) (আকার_t, আকার_t);
স্থির শূন্য (*free_redir) (শূন্য *);
স্থির শূন্য *(*realloc_redir) (শূন্য *, আকার_t);
স্থির unsigned পূর্ণসংখ্যা pool_সূচক;
স্থির unsigned অক্ষর __attribute__((aligned(16))) initial_pool[256];
#endif
#যদি HAVE_MEMALIGN
স্থির শূন্য *(*memalign_redir) (আকার_t, আকার_t);
#endif
#যদি HAVE_PTHREAD_CREATE
স্থির পূর্ণসংখ্যা (*pthread_create_redir) (pthread_t *thread,
                                    ধ্রুবক pthread_attr_t *attr,
                                    শূন্য *(*start_routine)(শূন্য *), শূন্য *arg);
#endif
#যদি HAVE_SIGNAL
প্রকারলেখ শূন্য (*bound_sig)(পূর্ণসংখ্যা);
স্থির bound_sig (*signal_redir) (পূর্ণসংখ্যা signum, bound_sig handler);
#endif
#যদি HAVE_SIGACTION
স্থির পূর্ণসংখ্যা (*sigaction_redir) (পূর্ণসংখ্যা signum, ধ্রুবক কাঠামো sigaction *act,
                               কাঠামো sigaction *oldact);
#endif
#যদি HAVE_FORK
স্থির পূর্ণসংখ্যা (*fork_redir) (শূন্য);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((শূন্য *)(-2))

প্রকারলেখ কাঠামো বৃক্ষ_গ্রন্থি বৃক্ষ;
কাঠামো বৃক্ষ_গ্রন্থি {
    বৃক্ষ * বাম, * ডান;
    আকার_t start;
    আকার_t আকার_2;
    unsigned অক্ষর type;
    unsigned অক্ষর is_invalid; /* true if pointers outside region are invalid */
};

প্রকারলেখ কাঠামো alloca_list_struct {
    আকার_t fp;
    শূন্য *p;
    আকার_t আকার_2;
    কাঠামো alloca_list_struct *পরবর্তী;
} alloca_list_type;

#যদি defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#নতুবা_যদি defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#নতুবা_যদি defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#নতুবা_যদি  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#নতুবা_যদি defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#অন্যথা
#define BOUND_TID_TYPE		পূর্ণসংখ্যা
#define BOUND_GET_TID(id)	id = 0
#endif

প্রকারলেখ কাঠামো jmp_list_struct {
    শূন্য *penv;
    আকার_t fp;
    আকার_t end_fp;
    BOUND_TID_TYPE tid;
    কাঠামো jmp_list_struct *পরবর্তী;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
স্থির বৃক্ষ * splay (আকার_t addr, বৃক্ষ *t);
স্থির বৃক্ষ * splay_end (আকার_t addr, বৃক্ষ *t);
স্থির বৃক্ষ * splay_ঢোকাও(আকার_t addr, আকার_t আকার_2, বৃক্ষ * t);
স্থির বৃক্ষ * splay_delete(আকার_t addr, বৃক্ষ *t);
শূন্য splay_printtree(বৃক্ষ * t, পূর্ণসংখ্যা d);

/* external interface */
শূন্য __bounds_checking (পূর্ণসংখ্যা no_check);
শূন্য __bound_checking_lock (শূন্য);
শূন্য __bound_checking_unlock (শূন্য);
শূন্য __bound_never_fatal (পূর্ণসংখ্যা no_check);
DLL_EXPORT শূন্য * __bound_ptr_add(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir1(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir2(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir4(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir8(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir12(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir16(শূন্য *p, আকার_t offset);
DLL_EXPORT শূন্য FASTCALL __bound_local_new(শূন্য *p1);
DLL_EXPORT শূন্য FASTCALL __bound_local_delete(শূন্য *p1);
শূন্য __bound_init(আকার_t *, পূর্ণসংখ্যা);
শূন্য __bound_main_arg(পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **envp);
শূন্য __bound_exit(শূন্য);
শূন্য __bound_exit_dll(আকার_t *);
#যদি !defined(_WIN32)
শূন্য *__bound_mmap (শূন্য *start, আকার_t আকার_2, পূর্ণসংখ্যা prot, পূর্ণসংখ্যা flags, পূর্ণসংখ্যা fd,
                    off_t offset);
পূর্ণসংখ্যা __bound_munmap (শূন্য *start, আকার_t আকার_2);
DLL_EXPORT শূন্য __bound_siglongjmp(jmp_buf env, পূর্ণসংখ্যা val);
#endif
DLL_EXPORT শূন্য __bound_new_region(শূন্য *p, আকার_t আকার_2);
DLL_EXPORT শূন্য __bound_setjmp(jmp_buf env);
DLL_EXPORT শূন্য __bound_longjmp(jmp_buf env, পূর্ণসংখ্যা val);
DLL_EXPORT শূন্য *__bound_memcpy(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT পূর্ণসংখ্যা __bound_memcmp(ধ্রুবক শূন্য *s1, ধ্রুবক শূন্য *s2, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound_memmove(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound_memset(শূন্য *dst, পূর্ণসংখ্যা c, আকার_t আকার_2);
DLL_EXPORT পূর্ণসংখ্যা __bound_strlen(ধ্রুবক অক্ষর *s);
DLL_EXPORT অক্ষর *__bound_strcpy(অক্ষর *dst, ধ্রুবক অক্ষর *src);
DLL_EXPORT অক্ষর *__bound_strncpy(অক্ষর *dst, ধ্রুবক অক্ষর *src, আকার_t n);
DLL_EXPORT পূর্ণসংখ্যা __bound_strcmp(ধ্রুবক অক্ষর *s1, ধ্রুবক অক্ষর *s2);
DLL_EXPORT পূর্ণসংখ্যা __bound_strncmp(ধ্রুবক অক্ষর *s1, ধ্রুবক অক্ষর *s2, আকার_t n);
DLL_EXPORT অক্ষর *__bound_strcat(অক্ষর *dest, ধ্রুবক অক্ষর *src);
DLL_EXPORT অক্ষর *__bound_strncat(অক্ষর *dest, ধ্রুবক অক্ষর *src, আকার_t n);
DLL_EXPORT অক্ষর *__bound_strchr(ধ্রুবক অক্ষর *string, পূর্ণসংখ্যা ch);
DLL_EXPORT অক্ষর *__bound_strrchr(ধ্রুবক অক্ষর *string, পূর্ণসংখ্যা ch);
DLL_EXPORT অক্ষর *__bound_strdup(ধ্রুবক অক্ষর *s);

#যদি defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT শূন্য *__bound___aeabi_memcpy(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound___aeabi_memmove(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound___aeabi_memmove4(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound___aeabi_memmove8(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__bound___aeabi_memset(শূন্য *dst, পূর্ণসংখ্যা c, আকার_t আকার_2);
DLL_EXPORT শূন্য *__aeabi_memcpy(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__aeabi_memmove(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__aeabi_memmove4(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__aeabi_memmove8(শূন্য *dst, ধ্রুবক শূন্য *src, আকার_t আকার_2);
DLL_EXPORT শূন্য *__aeabi_memset(শূন্য *dst, পূর্ণসংখ্যা c, আকার_t আকার_2);
#endif

#যদি MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#অন্যথা
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            মুক্ত(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT শূন্য *__bound_malloc(আকার_t আকার_2, ধ্রুবক শূন্য *caller);
DLL_EXPORT শূন্য *__bound_memalign(আকার_t align, আকার_t আকার_2, ধ্রুবক শূন্য *caller);
DLL_EXPORT শূন্য __bound_free(শূন্য *ptr, ধ্রুবক শূন্য *caller);
DLL_EXPORT শূন্য *__bound_realloc(শূন্য *ptr, আকার_t আকার_2, ধ্রুবক শূন্য *caller);
DLL_EXPORT শূন্য *__bound_calloc(আকার_t nmemb, আকার_t আকার_2);
#endif

#define FREE_REUSE_আকার (100)
স্থির unsigned পূর্ণসংখ্যা free_reuse_সূচক;
স্থির শূন্য *free_reuse_list[FREE_REUSE_আকার];

স্থির বৃক্ষ *বৃক্ষ_2 = ফাঁকা;
#define বৃক্ষ_REUSE      (1)
#যদি বৃক্ষ_REUSE
স্থির বৃক্ষ *বৃক্ষ_free_list;
#endif
স্থির alloca_list_type *alloca_list;
স্থির jmp_list_type *jmp_list;

স্থির unsigned অক্ষর inited;
স্থির unsigned অক্ষর print_warn_ptr_add;
স্থির unsigned অক্ষর print_calls;
স্থির unsigned অক্ষর print_heap;
স্থির unsigned অক্ষর print_statistic;
স্থির unsigned অক্ষর no_strdup;
স্থির unsigned অক্ষর use_sem;
স্থির _Atomic পূর্ণসংখ্যা never_fatal;
#যদি HAVE_TLS_FUNC
#যদি defined(_WIN32)
স্থির পূর্ণসংখ্যা no_checking = 0;
স্থির DWORD no_checking_চাবি;
#define NO_CHECKING_CHECK() যদি (!p) {                                         \
                                  p = (পূর্ণসংখ্যা *) LocalAlloc(LPTR, আকার(পূর্ণসংখ্যা));  \
                                  যদি (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_মান(no_checking_চাবি, p);            \
                            }
#define NO_CHECKING_GET()   ({ পূর্ণসংখ্যা *p = Tls_Get_মান(no_checking_চাবি);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { পূর্ণসংখ্যা *p = Tls_Get_মান(no_checking_চাবি);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#অন্যথা
স্থির পূর্ণসংখ্যা no_checking = 0;
স্থির pthread_key_t no_checking_চাবি;
#define NO_CHECKING_CHECK() যদি (!p) {                                         \
                                  p = (পূর্ণসংখ্যা *) BOUND_MALLOC(আকার(পূর্ণসংখ্যা));      \
                                  যদি (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_চাবি, p);    \
                            }
#define NO_CHECKING_GET()   ({ পূর্ণসংখ্যা *p = pthread_getspecific(no_checking_চাবি); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { পূর্ণসংখ্যা *p = pthread_getspecific(no_checking_চাবি);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#নতুবা_যদি HAVE_TLS_VAR
স্থির __thread পূর্ণসংখ্যা no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#অন্যথা
স্থির _Atomic পূর্ণসংখ্যা no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
স্থির অক্ষর exec[100];

#যদি BOUND_STATISTIC
স্থির unsigned long long bound_ptr_add_গুনতি;
স্থির unsigned long long bound_ptr_indir1_গুনতি;
স্থির unsigned long long bound_ptr_indir2_গুনতি;
স্থির unsigned long long bound_ptr_indir4_গুনতি;
স্থির unsigned long long bound_ptr_indir8_গুনতি;
স্থির unsigned long long bound_ptr_indir12_গুনতি;
স্থির unsigned long long bound_ptr_indir16_গুনতি;
স্থির unsigned long long bound_local_new_গুনতি;
স্থির unsigned long long bound_local_delete_গুনতি;
স্থির unsigned long long bound_malloc_গুনতি;
স্থির unsigned long long bound_calloc_গুনতি;
স্থির unsigned long long bound_realloc_গুনতি;
স্থির unsigned long long bound_free_গুনতি;
স্থির unsigned long long bound_memalign_গুনতি;
স্থির unsigned long long bound_mmap_গুনতি;
স্থির unsigned long long bound_munmap_গুনতি;
স্থির unsigned long long bound_alloca_গুনতি;
স্থির unsigned long long bound_setjmp_গুনতি;
স্থির unsigned long long bound_longjmp_গুনতি;
স্থির unsigned long long bound_mempcy_গুনতি;
স্থির unsigned long long bound_memcmp_গুনতি;
স্থির unsigned long long bound_memmove_গুনতি;
স্থির unsigned long long bound_memset_গুনতি;
স্থির unsigned long long bound_strlen_গুনতি;
স্থির unsigned long long bound_strcpy_গুনতি;
স্থির unsigned long long bound_strncpy_গুনতি;
স্থির unsigned long long bound_strcmp_গুনতি;
স্থির unsigned long long bound_strncmp_গুনতি;
স্থির unsigned long long bound_strcat_গুনতি;
স্থির unsigned long long bound_strncat_গুনতি;
স্থির unsigned long long bound_strchr_গুনতি;
স্থির unsigned long long bound_strrchr_গুনতি;
স্থির unsigned long long bound_strdup_গুনতি;
স্থির unsigned long long bound_not_found;
#define INCR_গুনতি(x)          ++x
#অন্যথা
#define INCR_গুনতি(x)
#endif
#যদি BOUND_STATISTIC_SPLAY
স্থির unsigned long long bound_splay;
স্থির unsigned long long bound_splay_end;
স্থির unsigned long long bound_splay_ঢোকাও;
স্থির unsigned long long bound_splay_delete;
#define INCR_গুনতি_SPLAY(x)    ++x
#অন্যথা
#define INCR_গুনতি_SPLAY(x)
#endif

পূর্ণসংখ্যা tcc_backtrace(ধ্রুবক অক্ষর *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    করো {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } যখন (0)

#define bound_error(...)            \
    করো {                            \
        bound_warning(__VA_ARGS__); \
        যদি (never_fatal == 0)       \
            exit(255);              \
    } যখন (0)

#define bounds_loc(fp, ...) \
    করো {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } যখন (0)

স্থির শূন্য bound_alloc_error(ধ্রুবক অক্ষর *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

স্থির শূন্য bound_not_found_warning(ধ্রুবক অক্ষর *file, ধ্রুবক অক্ষর *function,
                                    শূন্য *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
শূন্য __bounds_checking (পূর্ণসংখ্যা no_check)
{
#যদি HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#অন্যথা
    atomic_fetch_add (&no_checking, no_check);
#endif
}

শূন্য __bound_checking_lock(শূন্য)
{
    WAIT_SEM ();
}

শূন্য __bound_checking_unlock(শূন্য)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
শূন্য __bound_never_fatal (পূর্ণসংখ্যা neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
শূন্য * __bound_ptr_add(শূন্য *p, আকার_t offset)
{
    আকার_t addr = (আকার_t)p;

    যদি (NO_CHECKING_GET())
        ফেরত p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_গুনতি(bound_ptr_add_গুনতি);
    যদি (বৃক্ষ_2) {
        addr -= বৃক্ষ_2->start;
        যদি (addr >= বৃক্ষ_2->আকার_2) {
            addr = (আকার_t)p;
            বৃক্ষ_2 = splay (addr, বৃক্ষ_2);
            addr -= বৃক্ষ_2->start;
        }
        যদি (addr >= বৃক্ষ_2->আকার_2) {
            addr = (আকার_t)p;
            বৃক্ষ_2 = splay_end (addr, বৃক্ষ_2);
            addr -= বৃক্ষ_2->start;
        }
        যদি (addr <= বৃক্ষ_2->আকার_2) {
            যদি (বৃক্ষ_2->is_invalid || addr + offset > বৃক্ষ_2->আকার_2) {
                POST_SEM ();
                যদি (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)বৃক্ষ_2->start,
                                  (long)(বৃক্ষ_2->start + বৃক্ষ_2->আকার_2 - 1));
                যদি (never_fatal <= 0)
                    ফেরত INVALID_POINTER; /* return an invalid pointer */
                ফেরত p + offset;
            }
        }
        অন্যথা যদি (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_গুনতি(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            ফেরত p + offset;
        }
    }
    POST_SEM ();
    ফেরত p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
শূন্য * __bound_ptr_indir ## dsize (শূন্য *p, আকার_t offset)                     \
{                                                                              \
    আকার_t addr = (আকার_t)p;                                                   \
                                                                               \
    যদি (NO_CHECKING_GET())                                                     \
        ফেরত p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_গুনতি(bound_ptr_indir ## dsize ## গুনতি);                            \
    যদি (বৃক্ষ_2) {                                                                \
        addr -= বৃক্ষ_2->start;                                                   \
        যদি (addr >= বৃক্ষ_2->আকার_2) {                                              \
            addr = (আকার_t)p;                                                  \
            বৃক্ষ_2 = splay (addr, বৃক্ষ_2);                                         \
            addr -= বৃক্ষ_2->start;                                               \
        }                                                                      \
        যদি (addr >= বৃক্ষ_2->আকার_2) {                                              \
            addr = (আকার_t)p;                                                  \
            বৃক্ষ_2 = splay_end (addr, বৃক্ষ_2);                                     \
            addr -= বৃক্ষ_2->start;                                               \
        }                                                                      \
        যদি (addr <= বৃক্ষ_2->আকার_2) {                                              \
            যদি (বৃক্ষ_2->is_invalid || addr + offset + dsize > বৃক্ষ_2->আকার_2) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)বৃক্ষ_2->start,            \
                              (long)(বৃক্ষ_2->start + বৃক্ষ_2->আকার_2 - 1));           \
                যদি (never_fatal <= 0)                                          \
                    ফেরত INVALID_POINTER; /* return an invalid pointer */    \
                ফেরত p + offset;                                             \
            }                                                                  \
        }                                                                      \
        অন্যথা {                                                                 \
            INCR_গুনতি(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            ফেরত p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ফেরত p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic ঠেলো
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (আকার_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
শূন্য FASTCALL __bound_local_new(শূন্য *p1) 
{
    আকার_t addr, fp, *p = p1;

    যদি (NO_CHECKING_GET())
         ফেরত;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (শূন্য *)fp);
    WAIT_SEM ();
    যখন ((addr = p[0])) {
        INCR_গুনতি(bound_local_new_গুনতি);
        বৃক্ষ_2 = splay_ঢোকাও(addr + fp, p[1], বৃক্ষ_2);
        p += 2;
    }
    POST_SEM ();
#যদি BOUND_DEBUG
    যদি (print_calls) {
        p = p1;
        যখন ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (শূন্য *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
শূন্য FASTCALL __bound_local_delete(শূন্য *p1) 
{
    আকার_t addr, fp, *p = p1;

    যদি (NO_CHECKING_GET())
         ফেরত;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (শূন্য *)fp);
    WAIT_SEM ();
    যখন ((addr = p[0])) {
        INCR_গুনতি(bound_local_delete_গুনতি);
        বৃক্ষ_2 = splay_delete(addr + fp, বৃক্ষ_2);
        p += 2;
    }
    যদি (alloca_list) {
        alloca_list_type *last = ফাঁকা;
        alloca_list_type *cur = alloca_list;

        করো {
            যদি (cur->fp == fp) {
                যদি (last)
                    last->পরবর্তী = cur->পরবর্তী;
                অন্যথা
                    alloca_list = cur->পরবর্তী;
                বৃক্ষ_2 = splay_delete ((আকার_t) cur->p, বৃক্ষ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->পরবর্তী : alloca_list;
             }
             অন্যথা {
                 last = cur;
                 cur = cur->পরবর্তী;
             }
        } যখন (cur);
    }
    যদি (jmp_list) {
        jmp_list_type *last = ফাঁকা;
        jmp_list_type *cur = jmp_list;

        করো {
            যদি (cur->fp == fp) {
                যদি (last)
                    last->পরবর্তী = cur->পরবর্তী;
                অন্যথা
                    jmp_list = cur->পরবর্তী;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->পরবর্তী : jmp_list;
            }
            অন্যথা {
                last = cur;
                cur = cur->পরবর্তী;
            }
        } যখন (cur);
    }

    POST_SEM ();
#যদি BOUND_DEBUG
    যদি (print_calls) {
        p = p1;
        যখন ((addr = p[0])) {
            যদি (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (শূন্য *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
শূন্য __bound_new_region(শূন্য *p, আকার_t আকার_2)
{
    আকার_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    যদি (NO_CHECKING_GET())
        ফেরত;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)আকার_2);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (আকার (alloca_list_type));
    WAIT_SEM ();
    INCR_গুনতি(bound_alloca_গুনতি);
    last = ফাঁকা;
    cur = alloca_list;
    যখন (cur) {
#যদি defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        পূর্ণসংখ্যা align = 4;
#নতুবা_যদি defined(__arm__)
        পূর্ণসংখ্যা align = 8;
#অন্যথা
        পূর্ণসংখ্যা align = 16;
#endif
        শূন্য *cure = (শূন্য *)((অক্ষর *)cur->p + ((cur->আকার_2 + align) & -align));
        শূন্য *pe = (শূন্য *)((অক্ষর *)p + ((আকার_2 + align) & -align));
        যদি (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            যদি (last)
                last->পরবর্তী = cur->পরবর্তী;
            অন্যথা
                alloca_list = cur->পরবর্তী;
            বৃক্ষ_2 = splay_delete((আকার_t)cur->p, বৃক্ষ_2);
            বিরতি;
        }
        last = cur;
        cur = cur->পরবর্তী;
    }
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t)p, আকার_2, বৃক্ষ_2);
    যদি (new) {
        new->fp = fp;
        new->p = p;
        new->আকার_2 = আকার_2;
        new->পরবর্তী = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    যদি (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

শূন্য __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    শূন্য *e = (শূন্য *) env;

    যদি (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_গুনতি(bound_setjmp_গুনতি);
        jl = jmp_list;
        যখন (jl) {
            যদি (jl->penv == e)
                বিরতি;
            jl = jl->পরবর্তী;
        }
        যদি (jl == ফাঁকা) {
            jl = BOUND_MALLOC (আকার (jmp_list_type));
            যদি (jl) {
                jl->penv = e;
                jl->পরবর্তী = jmp_list;
                jmp_list = jl;
            }
        }
        যদি (jl) {
            আকার_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (আকার_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

স্থির শূন্য __bound_long_jump(jmp_buf env, পূর্ণসংখ্যা val, পূর্ণসংখ্যা sig, ধ্রুবক অক্ষর *func)
{
    jmp_list_type *jl;
    শূন্য *e;
    BOUND_TID_TYPE tid;

    যদি (NO_CHECKING_GET() == 0) {
        e = (শূন্য *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_গুনতি(bound_longjmp_গুনতি);
        jl = jmp_list;
        যখন (jl) {
            যদি (jl->penv == e && jl->tid == tid) {
                আকার_t start_fp = (আকার_t)__builtin_frame_address(0);
                আকার_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = ফাঁকা;

                যখন (cur->penv != e || cur->tid != tid) {
                    যদি (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        যদি (last)
                            last->পরবর্তী = cur->পরবর্তী;
                        অন্যথা
                            jmp_list = cur->পরবর্তী;
                        BOUND_FREE (cur);
                        cur = last ? last->পরবর্তী : jmp_list;
                    }
                    অন্যথা {
                        last = cur;
                        cur = cur->পরবর্তী;
                    }
                }
                জন্য (;;) {
                    বৃক্ষ *t = বৃক্ষ_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    যখন (t && (t->start < start_fp || t->start > end_fp))
                        যদি (t->start < start_fp)
                            t = t->ডান;
                        অন্যথা
                            t = t->বাম;
                    যদি (t == ফাঁকা)
                        বিরতি;
                    last = ফাঁকা;
                    cur = alloca_list;
                    যখন (cur) {
                         যদি ((আকার_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             যদি (last)
                                 last->পরবর্তী = cur->পরবর্তী;
                             অন্যথা
                                 alloca_list = cur->পরবর্তী;
                             BOUND_FREE (cur);
                             বিরতি;
                         }
                         last = cur;
                         cur = cur->পরবর্তী;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (শূন্য *) t->start);
                    বৃক্ষ_2 = splay_delete(t->start, বৃক্ষ_2);
                }
                বিরতি;
            }
            jl = jl->পরবর্তী;
        }
        POST_SEM();
    }
#যদি !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

শূন্য __bound_longjmp(jmp_buf env, পূর্ণসংখ্যা val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#যদি !defined(_WIN32)
শূন্য __bound_siglongjmp(jmp_buf env, পূর্ণসংখ্যা val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic বের_করো
#endif

শূন্য __bound_init(আকার_t *p, পূর্ণসংখ্যা mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    যদি (inited) {
        WAIT_SEM();
        যাও add_bounds;
    }
    inited = 1;

#যদি HAVE_TLS_FUNC
#যদি defined(_WIN32)
    no_checking_চাবি = TlsAlloc();
    Tls_Set_মান(no_checking_চাবি, &no_checking);
#অন্যথা
    pthread_key_create(&no_checking_চাবি, ফাঁকা);
    pthread_setspecific(no_checking_চাবি, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ফাঁকা;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ফাঁকা;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != ফাঁকা;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ফাঁকা;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ফাঁকা;

    INIT_SEM ();

#যদি MALLOC_REDIR
    {
        শূন্য *addr = mode > 0 ? RTLD_DEFAULT : RTLD_পরবর্তী;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(শূন্য **) (&malloc_redir) = dlsym (addr, "malloc");
        যদি (malloc_redir == ফাঁকা) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(শূন্য **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(শূন্য **) (&calloc_redir) = dlsym (addr, "calloc");
        *(শূন্য **) (&free_redir) = dlsym (addr, "free");
        *(শূন্য **) (&realloc_redir) = dlsym (addr, "realloc");
        *(শূন্য **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        যদি (malloc_redir == ফাঁকা || free_redir == ফাঁকা)
            bound_alloc_error ("Cannot redirect malloc/free");
#যদি HAVE_PTHREAD_CREATE
        *(শূন্য **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        যদি (pthread_create_redir == ফাঁকা)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#যদি HAVE_SIGNAL
        *(শূন্য **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        যদি (signal_redir == ফাঁকা)
            bound_alloc_error ("Cannot redirect signal");
#endif
#যদি HAVE_SIGACTION
        *(শূন্য **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        যদি (sigaction_redir == ফাঁকা)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#যদি HAVE_FORK
        *(শূন্য **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        যদি (fork_redir == ফাঁকা)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned অক্ষর found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        অক্ষর সারি[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        যদি (fp) {
            memset (exec, 0, আকার(exec));
            fread (exec, 1, আকার(exec) - 2, fp);
            যদি (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        যদি (fp) {
            যখন (fgets (সারি, আকার(সারি), fp)) {
                যদি (sscanf (সারি, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    বিরতি;
                }
                যদি (strstr (সারি,"[heap]"))
                    বিরতি;
            }
            fclose (fp);
        }
        যদি (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#যদি HAVE_CTYPE
#ifdef __APPLE__
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) &_DefaultRuneLocale,
                        আকার (_DefaultRuneLocale), বৃক্ষ_2);
#অন্যথা
    /* XXX: Does not work if locale is changed */
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) __ctype_b_loc(),
                        আকার (unsigned short *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) (*__ctype_b_loc() - 128),
                        384 * আকার (unsigned short), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) __ctype_tolower_loc(),
                        আকার (__int32_t *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) (*__ctype_tolower_loc() - 128),
                        384 * আকার (__int32_t), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) __ctype_toupper_loc(),
                        আকার (__int32_t *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) (*__ctype_toupper_loc() - 128),
                        384 * আকার (__int32_t), বৃক্ষ_2);
#endif
#endif
#যদি HAVE_ERRNO
    বৃক্ষ_2 = splay_ঢোকাও((আকার_t) (&errno), আকার (পূর্ণসংখ্যা), বৃক্ষ_2);
#endif

add_bounds:
    যদি (!p)
        যাও no_bounds;

    /* add all static bound check values */
    যখন (p[0] != 0) {
        বৃক্ষ_2 = splay_ঢোকাও(p[0], p[1], বৃক্ষ_2);
#যদি BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (শূন্য *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

শূন্য
#যদি (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **envp)
{
    __bound_init (0, -1);
    যদি (argc && argv) {
        পূর্ণসংখ্যা i;

        WAIT_SEM ();
        জন্য (i = 0; i < argc; i++)
            বৃক্ষ_2 = splay_ঢোকাও((আকার_t) argv[i], strlen (argv[i]) + 1, বৃক্ষ_2);
        বৃক্ষ_2 = splay_ঢোকাও((আকার_t) argv, (argc + 1) * আকার(অক্ষর *), বৃক্ষ_2);
        POST_SEM ();
#যদি BOUND_DEBUG
        যদি (print_calls) {
            জন্য (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (পূর্ণসংখ্যা)((argc + 1) * আকার(অক্ষর *)));
        }
#endif
    }

    যদি (envp && *envp) {
        অক্ষর **p = envp;

        WAIT_SEM ();
        যখন (*p) {
            বৃক্ষ_2 = splay_ঢোকাও((আকার_t) *p, strlen (*p) + 1, বৃক্ষ_2);
            ++p;
        }
        বৃক্ষ_2 = splay_ঢোকাও((আকার_t) envp, (++p - envp) * আকার(অক্ষর *), বৃক্ষ_2);
        POST_SEM ();
#যদি BOUND_DEBUG
        যদি (print_calls) {
            p = envp;
            যখন (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (পূর্ণসংখ্যা)((++p - envp) * আকার(অক্ষর *)));
        }
#endif
    }
}

শূন্য __attribute__((destructor)) __bound_exit(শূন্য)
{
    পূর্ণসংখ্যা i;
    স্থির ধ্রুবক অক্ষর * ধ্রুবক alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    যদি (inited) {
#যদি !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        যদি (print_heap) {
            বাহ্যিক শূন্য __libc_freeres (শূন্য);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        যখন (alloca_list) {
            alloca_list_type *পরবর্তী = alloca_list->পরবর্তী;

            বৃক্ষ_2 = splay_delete ((আকার_t) alloca_list->p, বৃক্ষ_2);
            BOUND_FREE (alloca_list);
            alloca_list = পরবর্তী;
        }
        যখন (jmp_list) {
           jmp_list_type *পরবর্তী  = jmp_list->পরবর্তী;

           BOUND_FREE (jmp_list);
           jmp_list = পরবর্তী;
        }
        জন্য (i = 0; i < FREE_REUSE_আকার; i++) {
            যদি (free_reuse_list[i]) {
                বৃক্ষ_2 = splay_delete ((আকার_t) free_reuse_list[i], বৃক্ষ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        যখন (বৃক্ষ_2) {
            যদি (print_heap && বৃক্ষ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[বৃক্ষ_2->type],
                         (unsigned long) বৃক্ষ_2->আকার_2);
            বৃক্ষ_2 = splay_delete (বৃক্ষ_2->start, বৃক্ষ_2);
        }
#যদি বৃক্ষ_REUSE
        যখন (বৃক্ষ_free_list) {
            বৃক্ষ *পরবর্তী = বৃক্ষ_free_list->বাম;
            BOUND_FREE (বৃক্ষ_free_list);
            বৃক্ষ_free_list = পরবর্তী;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#যদি HAVE_TLS_FUNC
#যদি defined(_WIN32)
        TlsFree(no_checking_চাবি);
#অন্যথা
        pthread_key_delete(no_checking_চাবি);
#endif
#endif
        inited = 0;
        যদি (print_statistic) {
#যদি BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_গুনতি);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_গুনতি);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_গুনতি);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_গুনতি);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_গুনতি);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_গুনতি);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_গুনতি);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_গুনতি);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_গুনতি);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_গুনতি);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_গুনতি);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_গুনতি);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_গুনতি);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_গুনতি);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_গুনতি);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_গুনতি);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_গুনতি);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_গুনতি);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_গুনতি);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_গুনতি);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_গুনতি);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_গুনতি);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_গুনতি);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_গুনতি);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_গুনতি);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_গুনতি);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_গুনতি);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_গুনতি);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_গুনতি);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_গুনতি);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_গুনতি);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_গুনতি);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_গুনতি);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#যদি BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ঢোকাও);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

শূন্য __bound_exit_dll(আকার_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    যদি (p) {
        WAIT_SEM ();
	যখন (p[0] != 0) {
	    বৃক্ষ_2 = splay_delete(p[0], বৃক্ষ_2);
#যদি BOUND_DEBUG
            যদি (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (শূন্য *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#যদি HAVE_PTHREAD_CREATE
প্রকারলেখ কাঠামো {
    শূন্য *(*start_routine) (শূন্য *);
    শূন্য *arg;
    sigset_t old_mask;
} bound_thread_create_type;

স্থির শূন্য *bound_thread_create(শূন্য *bdata)
{
    bound_thread_create_type *তথ্য = (bound_thread_create_type *) bdata;
    শূন্য *retval;
#যদি HAVE_TLS_FUNC
    পূর্ণসংখ্যা *p = (পূর্ণসংখ্যা *) BOUND_MALLOC(আকার(পূর্ণসংখ্যা));
  
    যদি (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_চাবি, p);
#endif
    pthread_sigmask(SIG_SETMASK, &তথ্য->old_mask, ফাঁকা);
    retval = তথ্য->start_routine(তথ্য->arg);
#যদি HAVE_TLS_FUNC
    pthread_setspecific(no_checking_চাবি, ফাঁকা);
    BOUND_FREE (p);
#endif
    BOUND_FREE (তথ্য);
    ফেরত retval;
}

পূর্ণসংখ্যা pthread_create(pthread_t *thread, ধ্রুবক pthread_attr_t *attr,
                   শূন্য *(*start_routine) (শূন্য *), শূন্য *arg)
{
    পূর্ণসংখ্যা retval;
    bound_thread_create_type *তথ্য;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    তথ্য = (bound_thread_create_type *) BOUND_MALLOC(আকার(bound_thread_create_type));
    যদি (!তথ্য) bound_alloc_error("bound_thread_create malloc");
    তথ্য->start_routine = start_routine;
    তথ্য->arg = arg;
    তথ্য->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, তথ্য);
    pthread_sigmask(SIG_SETMASK, &old_mask, ফাঁকা);
    ফেরত retval;
}
#endif

#যদি HAVE_SIGNAL || HAVE_SIGACTION
প্রকারলেখ সংঘ {
#যদি HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#যদি HAVE_SIGACTION
    শূন্য (*sig_handler)(পূর্ণসংখ্যা);
    শূন্য (*sig_sigaction)(পূর্ণসংখ্যা, siginfo_t *, শূন্য *);
#endif
} bound_sig_type;

স্থির unsigned অক্ষর bound_sig_used[NSIG];
স্থির bound_sig_type bound_sig_তথ্য[NSIG];
#endif

#যদি HAVE_SIGNAL
স্থির শূন্য signal_handler(পূর্ণসংখ্যা sig)
{
   __bounds_checking(1);
   bound_sig_তথ্য[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig সংকেত(পূর্ণসংখ্যা signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    যদি (retval != SIG_ERR) {
        যদি (bound_sig_used[signum])
            retval = bound_sig_তথ্য[signum].signal_handler;
        যদি (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_তথ্য[signum].signal_handler = handler;
        }
    }
    ফেরত retval;
}
#endif

#যদি HAVE_SIGACTION
স্থির শূন্য sig_handler(পূর্ণসংখ্যা sig)
{
   __bounds_checking(1);
   bound_sig_তথ্য[sig].sig_handler(sig);
   __bounds_checking(-1);
}

স্থির শূন্য sig_sigaction(পূর্ণসংখ্যা sig, siginfo_t *info, শূন্য *ucontext)
{
   __bounds_checking(1);
   bound_sig_তথ্য[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

পূর্ণসংখ্যা sigaction(পূর্ণসংখ্যা signum, ধ্রুবক কাঠামো sigaction *act, কাঠামো sigaction *oldact)
{
    পূর্ণসংখ্যা retval;
    কাঠামো sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    যদি (sigaction_redir == ফাঁকা)
        __bound_init(0,-1);

    যদি (act) {
        nact = *act;
        যদি (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        অন্যথা
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    অন্যথা
        retval = sigaction_redir(signum, act, &oact);
    যদি (retval >= 0) {
        যদি (bound_sig_used[signum]) {
            যদি (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_তথ্য[signum].sig_sigaction;
            অন্যথা
                oact.sa_handler = bound_sig_তথ্য[signum].sig_handler;
        }
        যদি (oldact) {
            *oldact = oact;
        }
        যদি (act) {
            bound_sig_used[signum] = 1;
            যদি (act->sa_flags & SA_SIGINFO)
                bound_sig_তথ্য[signum].sig_sigaction = act->sa_sigaction;
            অন্যথা
                bound_sig_তথ্য[signum].sig_handler = act->sa_handler;
        }
    }
    ফেরত retval;
}
#endif

#যদি HAVE_FORK
pid_t fork(শূন্য)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    যদি (retval == 0)
        INIT_SEM();
    অন্যথা
        POST_SEM();
    ফেরত retval;
}
#endif

#যদি MALLOC_REDIR
শূন্য *malloc(আকার_t আকার_2)
#অন্যথা
শূন্য *__bound_malloc(আকার_t আকার_2, ধ্রুবক শূন্য *caller)
#endif
{
    শূন্য *ptr;
    
#যদি MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    যদি (malloc_redir == ফাঁকা) {
        __bound_init (0, -1);
        যদি (malloc_redir == ফাঁকা) {
            ptr = &initial_pool[pool_সূচক];
            pool_সূচক = (pool_সূচক + আকার_2 + 15) & ~15;
            যদি (pool_সূচক >= আকার (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)আকার_2);
            ফেরত ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (আকার_2 + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)আকার_2);
    
    যদি (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_malloc_গুনতি);

        যদি (ptr) {
            বৃক্ষ_2 = splay_ঢোকাও ((আকার_t) ptr, আকার_2 ? আকার_2 : আকার_2 + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (আকার_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ফেরত ptr;
}

#যদি MALLOC_REDIR
শূন্য *memalign(আকার_t align, আকার_t আকার_2)
#অন্যথা
শূন্য *__bound_memalign(আকার_t align, আকার_t আকার_2, ধ্রুবক শূন্য *caller)
#endif
{
    শূন্য *ptr;

#যদি HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, আকার_2 + 1);
#অন্যথা
    যদি (align > 4) {
        /* XXX: handle it ? */
        ptr = ফাঁকা;
    } অন্যথা {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(আকার_2 + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)আকার_2);

    যদি (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_memalign_গুনতি);

        যদি (ptr) {
            বৃক্ষ_2 = splay_ঢোকাও((আকার_t) ptr, আকার_2 ? আকার_2 : আকার_2 + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (আকার_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ফেরত ptr;
}

#যদি MALLOC_REDIR
শূন্য মুক্ত(শূন্য *ptr)
#অন্যথা
শূন্য __bound_free(শূন্য *ptr, ধ্রুবক শূন্য *caller)
#endif
{
    আকার_t addr = (আকার_t) ptr;
    শূন্য *p;

    যদি (ptr == ফাঁকা || বৃক্ষ_2 == ফাঁকা
#যদি MALLOC_REDIR
        || ((unsigned অক্ষর *) ptr >= &initial_pool[0] &&
            (unsigned অক্ষর *) ptr < &initial_pool[আকার(initial_pool)])
#endif
        )
        ফেরত;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    যদি (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_free_গুনতি);
        বৃক্ষ_2 = splay (addr, বৃক্ষ_2);
        যদি (বৃক্ষ_2->start == addr) {
            যদি (বৃক্ষ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ফেরত;
            }
            বৃক্ষ_2->is_invalid = 1;
            memset (ptr, 0x5a, বৃক্ষ_2->আকার_2);
            p = free_reuse_list[free_reuse_সূচক];
            free_reuse_list[free_reuse_সূচক] = ptr;
            free_reuse_সূচক = (free_reuse_সূচক + 1) % FREE_REUSE_আকার;
            যদি (p)
                বৃক্ষ_2 = splay_delete((আকার_t)p, বৃক্ষ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#যদি MALLOC_REDIR
শূন্য *realloc(শূন্য *ptr, আকার_t আকার_2)
#অন্যথা
শূন্য *__bound_realloc(শূন্য *ptr, আকার_t আকার_2, ধ্রুবক শূন্য *caller)
#endif
{
    শূন্য *new_ptr;

    যদি (আকার_2 == 0) {
#যদি MALLOC_REDIR
        মুক্ত(ptr);
#অন্যথা
        __bound_free(ptr, caller);
#endif
        ফেরত ফাঁকা;
    }

    new_ptr = BOUND_REALLOC (ptr, আকার_2 + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)আকার_2);

    যদি (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_realloc_গুনতি);

        যদি (ptr)
            বৃক্ষ_2 = splay_delete ((আকার_t) ptr, বৃক্ষ_2);
        যদি (new_ptr) {
            বৃক্ষ_2 = splay_ঢোকাও ((আকার_t) new_ptr, আকার_2 ? আকার_2 : আকার_2 + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (আকার_t) new_ptr)
                বৃক্ষ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ফেরত new_ptr;
}

#যদি MALLOC_REDIR
শূন্য *calloc(আকার_t nmemb, আকার_t আকার_2)
#অন্যথা
শূন্য *__bound_calloc(আকার_t nmemb, আকার_t আকার_2)
#endif
{
    শূন্য *ptr;

    আকার_2 *= nmemb;
#যদি MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    যদি (malloc_redir == ফাঁকা) {
        __bound_init (0, -1);
        যদি (malloc_redir == ফাঁকা) {
            ptr = &initial_pool[pool_সূচক];
            pool_সূচক = (pool_সূচক + আকার_2 + 15) & ~15;
            যদি (pool_সূচক >= আকার (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)আকার_2);
            memset (ptr, 0, আকার_2);
            ফেরত ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(আকার_2 + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)আকার_2);

    যদি (ptr) {
        memset (ptr, 0, আকার_2);
        যদি (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_গুনতি(bound_calloc_গুনতি);
            বৃক্ষ_2 = splay_ঢোকাও ((আকার_t) ptr, আকার_2 ? আকার_2 : আকার_2 + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (আকার_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ফেরত ptr;
}

#যদি !defined(_WIN32)
শূন্য *__bound_mmap (শূন্য *start, আকার_t আকার_2, পূর্ণসংখ্যা prot,
                    পূর্ণসংখ্যা flags, পূর্ণসংখ্যা fd, off_t offset)
{
    শূন্য *ফলাফল;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)আকার_2);
    ফলাফল = mmap (start, আকার_2, prot, flags, fd, offset);
    যদি (ফলাফল && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_mmap_গুনতি);
        বৃক্ষ_2 = splay_ঢোকাও((আকার_t)ফলাফল, আকার_2, বৃক্ষ_2);
        POST_SEM ();
    }
    ফেরত ফলাফল;
}

পূর্ণসংখ্যা __bound_munmap (শূন্য *start, আকার_t আকার_2)
{
    পূর্ণসংখ্যা ফলাফল;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)আকার_2);
    যদি (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_munmap_গুনতি);
        বৃক্ষ_2 = splay_delete ((আকার_t) start, বৃক্ষ_2);
        POST_SEM ();
    }
    ফলাফল = munmap (start, আকার_2);
    ফেরত ফলাফল;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
স্থির শূন্য __bound_check(ধ্রুবক শূন্য *p, আকার_t আকার_2, ধ্রুবক অক্ষর *function)
{
    যদি (আকার_2 != 0 && __bound_ptr_add((শূন্য *)p, আকার_2) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)আকার_2, function);
    }
}

স্থির পূর্ণসংখ্যা check_overlap (ধ্রুবক শূন্য *p1, আকার_t n1,
                          ধ্রুবক শূন্য *p2, আকার_t n2,
                          ধ্রুবক অক্ষর *function)
{
    ধ্রুবক শূন্য *p1e = (ধ্রুবক শূন্য *) ((ধ্রুবক অক্ষর *) p1 + n1);
    ধ্রুবক শূন্য *p2e = (ধ্রুবক শূন্য *) ((ধ্রুবক অক্ষর *) p2 + n2);

    যদি (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        ফেরত never_fatal < 0;
    }
    ফেরত 0;
}

শূন্য *__bound_memcpy(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_mempcy_গুনতি);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    যদি (check_overlap(dest, n, src, n, "memcpy"))
        ফেরত dest;
    ফেরত memcpy(dest, src, n);
}

পূর্ণসংখ্যা __bound_memcmp(ধ্রুবক শূন্য *s1, ধ্রুবক শূন্য *s2, আকার_t n)
{
    ধ্রুবক unsigned অক্ষর *u1 = (ধ্রুবক unsigned অক্ষর *) s1;
    ধ্রুবক unsigned অক্ষর *u2 = (ধ্রুবক unsigned অক্ষর *) s2;
    পূর্ণসংখ্যা retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_গুনতি(bound_memcmp_গুনতি);
    জন্য (;;) {
        যদি ((ssize_t) --n == -1)
            বিরতি;
        অন্যথা যদি (*u1 != *u2) {
            retval = *u1++ - *u2++;
            বিরতি;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ধ্রুবক শূন্য *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ধ্রুবক শূন্য *)u2 - s2, "memcmp s2");
    ফেরত retval;
}

শূন্য *__bound_memmove(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ফেরত memmove(dest, src, n);
}

শূন্য *__bound_memset(শূন্য *s, পূর্ণসংখ্যা c, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_গুনতি(bound_memset_গুনতি);
    __bound_check(s, n, "memset");
    ফেরত memset(s, c, n);
}

#যদি defined(__arm__) && defined(__ARM_EABI__)
শূন্য *__bound___aeabi_memcpy(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_mempcy_গুনতি);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    যদি (check_overlap(dest, n, src, n, "memcpy"))
        ফেরত dest;
    ফেরত __aeabi_memcpy(dest, src, n);
}

শূন্য *__bound___aeabi_memmove(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ফেরত __aeabi_memmove(dest, src, n);
}

শূন্য *__bound___aeabi_memmove4(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ফেরত __aeabi_memmove4(dest, src, n);
}

শূন্য *__bound___aeabi_memmove8(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ফেরত __aeabi_memmove8(dest, src, n);
}

শূন্য *__bound___aeabi_memset(শূন্য *s, পূর্ণসংখ্যা c, আকার_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_গুনতি(bound_memset_গুনতি);
    __bound_check(s, n, "memset");
    ফেরত __aeabi_memset(s, c, n);
}
#endif

পূর্ণসংখ্যা __bound_strlen(ধ্রুবক অক্ষর *s)
{
    ধ্রুবক অক্ষর *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_গুনতি(bound_strlen_গুনতি);
    যখন (*p++);
    __bound_check(s, p - s, "strlen");
    ফেরত (p - s) - 1;
}

অক্ষর *__bound_strcpy(অক্ষর *dest, ধ্রুবক অক্ষর *src)
{
    আকার_t len;
    ধ্রুবক অক্ষর *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_গুনতি(bound_strcpy_গুনতি);
    যখন (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    যদি (check_overlap(dest, len, src, len, "strcpy"))
        ফেরত dest;
    ফেরত strcpy (dest, src);
}

অক্ষর *__bound_strncpy(অক্ষর *dest, ধ্রুবক অক্ষর *src, আকার_t n)
{
    আকার_t len = n;
    ধ্রুবক অক্ষর *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_strncpy_গুনতি);
    যখন (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    যদি (check_overlap(dest, len, src, len, "strncpy"))
        ফেরত dest;
    ফেরত strncpy(dest, src, n);
}

পূর্ণসংখ্যা __bound_strcmp(ধ্রুবক অক্ষর *s1, ধ্রুবক অক্ষর *s2)
{
    ধ্রুবক unsigned অক্ষর *u1 = (ধ্রুবক unsigned অক্ষর *) s1;
    ধ্রুবক unsigned অক্ষর *u2 = (ধ্রুবক unsigned অক্ষর *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_গুনতি(bound_strcmp_গুনতি);
    যখন (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ধ্রুবক অক্ষর *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ধ্রুবক অক্ষর *)u2 - s2) + 1, "strcmp s2");
    ফেরত *u1 - *u2;
}

পূর্ণসংখ্যা __bound_strncmp(ধ্রুবক অক্ষর *s1, ধ্রুবক অক্ষর *s2, আকার_t n)
{
    ধ্রুবক unsigned অক্ষর *u1 = (ধ্রুবক unsigned অক্ষর *) s1;
    ধ্রুবক unsigned অক্ষর *u2 = (ধ্রুবক unsigned অক্ষর *) s2;
    পূর্ণসংখ্যা retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_গুনতি(bound_strncmp_গুনতি);
    করো {
        যদি ((ssize_t) --n == -1)
            বিরতি;
        অন্যথা যদি (*u1 != *u2) {
            retval = *u1++ - *u2++;
            বিরতি;
        }
        ++u2;
    } যখন (*u1++);
    __bound_check(s1, (ধ্রুবক অক্ষর *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ধ্রুবক অক্ষর *)u2 - s2, "strncmp s2");
    ফেরত retval;
}

অক্ষর *__bound_strcat(অক্ষর *dest, ধ্রুবক অক্ষর *src)
{
    অক্ষর *r = dest;
    ধ্রুবক অক্ষর *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_গুনতি(bound_strcat_গুনতি);
    যখন (*dest++);
    যখন (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    যদি (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ফেরত dest;
    ফেরত strcat(r, s);
}

অক্ষর *__bound_strncat(অক্ষর *dest, ধ্রুবক অক্ষর *src, আকার_t n)
{
    অক্ষর *r = dest;
    ধ্রুবক অক্ষর *s = src;
    আকার_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_strncat_গুনতি);
    যখন (*dest++);
    যখন (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    যদি (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ফেরত dest;
    ফেরত strncat(r, s, n);
}

অক্ষর *__bound_strchr(ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা c)
{
    ধ্রুবক unsigned অক্ষর *str = (ধ্রুবক unsigned অক্ষর *) s;
    unsigned অক্ষর ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_গুনতি(bound_strchr_গুনতি);
    যখন (*str) {
        যদি (*str == ch)
            বিরতি;
        ++str;
    }
    __bound_check(s, ((ধ্রুবক অক্ষর *)str - s) + 1, "strchr");
    ফেরত *str == ch ? (অক্ষর *) str : ফাঁকা;
}

অক্ষর *__bound_strrchr(ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা c)
{
    ধ্রুবক unsigned অক্ষর *str = (ধ্রুবক unsigned অক্ষর *) s;
    unsigned অক্ষর ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_গুনতি(bound_strrchr_গুনতি);
    যখন (*str++);
    __bound_check(s, (ধ্রুবক অক্ষর *)str - s, "strrchr");
    যখন (str != (ধ্রুবক unsigned অক্ষর *)s) {
        যদি (*--str == ch)
            বিরতি;
    }
    __bound_check(s, (ধ্রুবক অক্ষর *)str - s, "strrchr");
    ফেরত *str == ch ? (অক্ষর *) str : ফাঁকা;
}

অক্ষর *__bound_strdup(ধ্রুবক অক্ষর *s)
{
    ধ্রুবক অক্ষর *p = s;
    অক্ষর *new;

    INCR_গুনতি(bound_strdup_গুনতি);
    যখন (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    যদি (new) {
        যদি (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            বৃক্ষ_2 = splay_ঢোকাও((আকার_t)new, p - s, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (আকার_t) new)
                বৃক্ষ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    ফেরত new;
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

স্থির বৃক্ষ * splay (আকার_t addr, বৃক্ষ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    বৃক্ষ N, *l, *r, *y;
    পূর্ণসংখ্যা comp;
    
    INCR_গুনতি_SPLAY(bound_splay);
    যদি (t == ফাঁকা) ফেরত t;
    N.বাম = N.ডান = ফাঁকা;
    l = r = &N;
 
    জন্য (;;) {
        comp = compare(addr, t->start, t->আকার_2);
        যদি (comp < 0) {
            y = t->বাম;
            যদি (y == ফাঁকা) বিরতি;
            যদি (compare(addr, y->start, y->আকার_2) < 0) {
                t->বাম = y->ডান;                    /* rotate right */
                y->ডান = t;
                t = y;
                যদি (t->বাম == ফাঁকা) বিরতি;
            }
            r->বাম = t;                               /* link right */
            r = t;
            t = t->বাম;
        } অন্যথা যদি (comp > 0) {
            y = t->ডান;
            যদি (y == ফাঁকা) বিরতি;
            যদি (compare(addr, y->start, y->আকার_2) > 0) {
                t->ডান = y->বাম;                    /* rotate left */
                y->বাম = t;
                t = y;
                যদি (t->ডান == ফাঁকা) বিরতি;
            }
            l->ডান = t;                              /* link left */
            l = t;
            t = t->ডান;
        } অন্যথা {
            বিরতি;
        }
    }
    l->ডান = t->বাম;                                /* assemble */
    r->বাম = t->ডান;
    t->বাম = N.ডান;
    t->ডান = N.বাম;

    ফেরত t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

স্থির বৃক্ষ * splay_end (আকার_t addr, বৃক্ষ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    বৃক্ষ N, *l, *r, *y;
    পূর্ণসংখ্যা comp;
    
    INCR_গুনতি_SPLAY(bound_splay_end);
    যদি (t == ফাঁকা) ফেরত t;
    N.বাম = N.ডান = ফাঁকা;
    l = r = &N;
 
    জন্য (;;) {
        comp = compare_end(addr, t->start + t->আকার_2);
        যদি (comp < 0) {
            y = t->বাম;
            যদি (y == ফাঁকা) বিরতি;
            যদি (compare_end(addr, y->start + y->আকার_2) < 0) {
                t->বাম = y->ডান;                    /* rotate right */
                y->ডান = t;
                t = y;
                যদি (t->বাম == ফাঁকা) বিরতি;
            }
            r->বাম = t;                               /* link right */
            r = t;
            t = t->বাম;
        } অন্যথা যদি (comp > 0) {
            y = t->ডান;
            যদি (y == ফাঁকা) বিরতি;
            যদি (compare_end(addr, y->start + y->আকার_2) > 0) {
                t->ডান = y->বাম;                    /* rotate left */
                y->বাম = t;
                t = y;
                যদি (t->ডান == ফাঁকা) বিরতি;
            }
            l->ডান = t;                              /* link left */
            l = t;
            t = t->ডান;
        } অন্যথা {
            বিরতি;
        }
    }
    l->ডান = t->বাম;                                /* assemble */
    r->বাম = t->ডান;
    t->বাম = N.ডান;
    t->ডান = N.বাম;

    ফেরত t;
}

স্থির বৃক্ষ * splay_ঢোকাও(আকার_t addr, আকার_t আকার_2, বৃক্ষ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    বৃক্ষ * new;

    INCR_গুনতি_SPLAY(bound_splay_ঢোকাও);
    যদি (t != ফাঁকা) {
        t = splay(addr,t);
        যদি (compare(addr, t->start, t->আকার_2)==0) {
            ফেরত t;  /* it's already there */
        }
    }
#যদি বৃক্ষ_REUSE
    যদি (বৃক্ষ_free_list) {
          new = বৃক্ষ_free_list;
          বৃক্ষ_free_list = new->বাম;
    }
    অন্যথা
#endif
    {
        new = (বৃক্ষ *) BOUND_MALLOC (আকার (বৃক্ষ));
    }
    যদি (new == ফাঁকা) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    অন্যথা {
        যদি (t == ফাঁকা) {
            new->বাম = new->ডান = ফাঁকা;
        } অন্যথা যদি (compare(addr, t->start, t->আকার_2) < 0) {
            new->বাম = t->বাম;
            new->ডান = t;
            t->বাম = ফাঁকা;
        } অন্যথা {
            new->ডান = t->ডান;
            new->বাম = t;
            t->ডান = ফাঁকা;
        }
        new->start = addr;
        new->আকার_2 = আকার_2;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ফেরত new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

স্থির বৃক্ষ * splay_delete(আকার_t addr, বৃক্ষ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    বৃক্ষ * x;

    INCR_গুনতি_SPLAY(bound_splay_delete);
    যদি (t==ফাঁকা) ফেরত ফাঁকা;
    t = splay(addr,t);
    যদি (compare_destroy(addr, t->start) == 0) {        /* found it */
        যদি (t->বাম == ফাঁকা) {
            x = t->ডান;
        } অন্যথা {
            x = splay(addr, t->বাম);
            x->ডান = t->ডান;
        }
#যদি বৃক্ষ_REUSE
        t->বাম = বৃক্ষ_free_list;
        বৃক্ষ_free_list = t;
#অন্যথা
        BOUND_FREE(t);
#endif
        ফেরত x;
    } অন্যথা {
        ফেরত t;                                      /* It wasn't there */
    }
}

শূন্য splay_printtree(বৃক্ষ * t, পূর্ণসংখ্যা d)
{
    পূর্ণসংখ্যা i;
    যদি (t == ফাঁকা) ফেরত;
    splay_printtree(t->ডান, d+1);
    জন্য (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (শূন্য *) t->start, (unsigned long) t->আকার_2,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->বাম, d+1);
}
