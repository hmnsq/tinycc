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
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <stdarg.h>
#অন্তর্ভাৱ <string.h>
#অন্তর্ভাৱ <setjmp.h>
#অন্তর্ভাৱ <stdatomic.h>

#যদি !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#অন্তর্ভাৱ <malloc.h>
#endif

#যদি !defined(_WIN32)
#অন্তর্ভাৱ <unistd.h>
#অন্তর্ভাৱ <sys/syscall.h>
#endif

#অন্তর্ভাৱ "config.h"

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

#অন্তর্ভাৱ <sys/mman.h>
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

#নোচেদ্যদি defined(_WIN32)

#অন্তর্ভাৱ <windows.h>
#অন্তর্ভাৱ <signal.h>
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
#অন্তর্ভাৱ <sys/mman.h>
#অন্তর্ভাৱ <ctype.h>
#অন্তর্ভাৱ <pthread.h>
#অন্তর্ভাৱ <dlfcn.h>
#অন্তর্ভাৱ <errno.h>
#অন্তর্ভাৱ <signal.h>
#ifdef __APPLE__
#অন্তর্ভাৱ <dispatch/dispatch.h>
স্থির dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             যদি (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             যদি (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              যদি (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#নোচেদ্যদি 0
#অন্তর্ভাৱ <semaphore.h>
স্থির sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             যদি (use_sem) যেতিয়ালৈ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             যদি (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              যদি (use_sem) যেতিয়ালৈ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#নোচেদ্যদি 0
স্থির pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, রিক্ত)
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
স্থির শূন্য *(*malloc_redir) (size_t);
স্থির শূন্য *(*calloc_redir) (size_t, size_t);
স্থির শূন্য (*free_redir) (শূন্য *);
স্থির শূন্য *(*realloc_redir) (শূন্য *, size_t);
স্থির unsigned পূর্ণাঙ্ক pool_index;
স্থির unsigned ৱর্ণ __attribute__((aligned(16))) initial_pool[256];
#endif
#যদি HAVE_MEMALIGN
স্থির শূন্য *(*memalign_redir) (size_t, size_t);
#endif
#যদি HAVE_PTHREAD_CREATE
স্থির পূর্ণাঙ্ক (*pthread_create_redir) (pthread_t *thread,
                                    ধ্রুৱ pthread_attr_t *attr,
                                    শূন্য *(*start_routine)(শূন্য *), শূন্য *arg);
#endif
#যদি HAVE_SIGNAL
প্রকারনির্দেশ শূন্য (*bound_sig)(পূর্ণাঙ্ক);
স্থির bound_sig (*signal_redir) (পূর্ণাঙ্ক signum, bound_sig handler);
#endif
#যদি HAVE_SIGACTION
স্থির পূর্ণাঙ্ক (*sigaction_redir) (পূর্ণাঙ্ক signum, ধ্রুৱ সংরচনা sigaction *act,
                               সংরচনা sigaction *oldact);
#endif
#যদি HAVE_FORK
স্থির পূর্ণাঙ্ক (*fork_redir) (শূন্য);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((শূন্য *)(-2))

প্রকারনির্দেশ সংরচনা বৃক্ষ_গ্ৰন্থি বৃক্ষ;
সংরচনা বৃক্ষ_গ্ৰন্থি {
    বৃক্ষ * বাম, * ডান;
    size_t start;
    size_t size;
    unsigned ৱর্ণ type;
    unsigned ৱর্ণ is_invalid; /* true if pointers outside region are invalid */
};

প্রকারনির্দেশ সংরচনা alloca_list_struct {
    size_t fp;
    শূন্য *p;
    size_t size;
    সংরচনা alloca_list_struct *next;
} alloca_list_type;

#যদি defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#নোচেদ্যদি defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#নোচেদ্যদি defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#নোচেদ্যদি  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#নোচেদ্যদি defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#অন্যথা
#define BOUND_TID_TYPE		পূর্ণাঙ্ক
#define BOUND_GET_TID(id)	id = 0
#endif

প্রকারনির্দেশ সংরচনা jmp_list_struct {
    শূন্য *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    সংরচনা jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
স্থির বৃক্ষ * splay (size_t addr, বৃক্ষ *t);
স্থির বৃক্ষ * splay_end (size_t addr, বৃক্ষ *t);
স্থির বৃক্ষ * splay_ঢোকাও(size_t addr, size_t size, বৃক্ষ * t);
স্থির বৃক্ষ * splay_delete(size_t addr, বৃক্ষ *t);
শূন্য splay_printtree(বৃক্ষ * t, পূর্ণাঙ্ক d);

/* external interface */
শূন্য __bounds_checking (পূর্ণাঙ্ক no_check);
শূন্য __bound_checking_lock (শূন্য);
শূন্য __bound_checking_unlock (শূন্য);
শূন্য __bound_never_fatal (পূর্ণাঙ্ক no_check);
DLL_EXPORT শূন্য * __bound_ptr_add(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir1(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir2(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir4(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir8(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir12(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য * __bound_ptr_indir16(শূন্য *p, size_t offset);
DLL_EXPORT শূন্য FASTCALL __bound_local_new(শূন্য *p1);
DLL_EXPORT শূন্য FASTCALL __bound_local_delete(শূন্য *p1);
শূন্য __bound_init(size_t *, পূর্ণাঙ্ক);
শূন্য __bound_main_arg(পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **envp);
শূন্য __bound_exit(শূন্য);
শূন্য __bound_exit_dll(size_t *);
#যদি !defined(_WIN32)
শূন্য *__bound_mmap (শূন্য *start, size_t size, পূর্ণাঙ্ক prot, পূর্ণাঙ্ক flags, পূর্ণাঙ্ক fd,
                    off_t offset);
পূর্ণাঙ্ক __bound_munmap (শূন্য *start, size_t size);
DLL_EXPORT শূন্য __bound_siglongjmp(jmp_buf env, পূর্ণাঙ্ক val);
#endif
DLL_EXPORT শূন্য __bound_new_region(শূন্য *p, size_t size);
DLL_EXPORT শূন্য __bound_setjmp(jmp_buf env);
DLL_EXPORT শূন্য __bound_longjmp(jmp_buf env, পূর্ণাঙ্ক val);
DLL_EXPORT শূন্য *__bound_memcpy(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT পূর্ণাঙ্ক __bound_memcmp(ধ্রুৱ শূন্য *s1, ধ্রুৱ শূন্য *s2, size_t size);
DLL_EXPORT শূন্য *__bound_memmove(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__bound_memset(শূন্য *dst, পূর্ণাঙ্ক c, size_t size);
DLL_EXPORT পূর্ণাঙ্ক __bound_strlen(ধ্রুৱ ৱর্ণ *s);
DLL_EXPORT ৱর্ণ *__bound_strcpy(ৱর্ণ *dst, ধ্রুৱ ৱর্ণ *src);
DLL_EXPORT ৱর্ণ *__bound_strncpy(ৱর্ণ *dst, ধ্রুৱ ৱর্ণ *src, size_t n);
DLL_EXPORT পূর্ণাঙ্ক __bound_strcmp(ধ্রুৱ ৱর্ণ *s1, ধ্রুৱ ৱর্ণ *s2);
DLL_EXPORT পূর্ণাঙ্ক __bound_strncmp(ধ্রুৱ ৱর্ণ *s1, ধ্রুৱ ৱর্ণ *s2, size_t n);
DLL_EXPORT ৱর্ণ *__bound_strcat(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src);
DLL_EXPORT ৱর্ণ *__bound_strncat(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src, size_t n);
DLL_EXPORT ৱর্ণ *__bound_strchr(ধ্রুৱ ৱর্ণ *string, পূর্ণাঙ্ক ch);
DLL_EXPORT ৱর্ণ *__bound_strrchr(ধ্রুৱ ৱর্ণ *string, পূর্ণাঙ্ক ch);
DLL_EXPORT ৱর্ণ *__bound_strdup(ধ্রুৱ ৱর্ণ *s);

#যদি defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT শূন্য *__bound___aeabi_memcpy(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__bound___aeabi_memmove(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__bound___aeabi_memmove4(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__bound___aeabi_memmove8(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__bound___aeabi_memset(শূন্য *dst, পূর্ণাঙ্ক c, size_t size);
DLL_EXPORT শূন্য *__aeabi_memcpy(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__aeabi_memmove(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__aeabi_memmove4(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__aeabi_memmove8(শূন্য *dst, ধ্রুৱ শূন্য *src, size_t size);
DLL_EXPORT শূন্য *__aeabi_memset(শূন্য *dst, পূর্ণাঙ্ক c, size_t size);
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
DLL_EXPORT শূন্য *__bound_malloc(size_t size, ধ্রুৱ শূন্য *caller);
DLL_EXPORT শূন্য *__bound_memalign(size_t align, size_t size, ধ্রুৱ শূন্য *caller);
DLL_EXPORT শূন্য __bound_free(শূন্য *ptr, ধ্রুৱ শূন্য *caller);
DLL_EXPORT শূন্য *__bound_realloc(শূন্য *ptr, size_t size, ধ্রুৱ শূন্য *caller);
DLL_EXPORT শূন্য *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
স্থির unsigned পূর্ণাঙ্ক free_reuse_index;
স্থির শূন্য *free_reuse_list[FREE_REUSE_SIZE];

স্থির বৃক্ষ *বৃক্ষ_2 = রিক্ত;
#define বৃক্ষ_REUSE      (1)
#যদি বৃক্ষ_REUSE
স্থির বৃক্ষ *বৃক্ষ_free_list;
#endif
স্থির alloca_list_type *alloca_list;
স্থির jmp_list_type *jmp_list;

স্থির unsigned ৱর্ণ inited;
স্থির unsigned ৱর্ণ print_warn_ptr_add;
স্থির unsigned ৱর্ণ print_calls;
স্থির unsigned ৱর্ণ print_heap;
স্থির unsigned ৱর্ণ print_statistic;
স্থির unsigned ৱর্ণ no_strdup;
স্থির unsigned ৱর্ণ use_sem;
স্থির _Atomic পূর্ণাঙ্ক never_fatal;
#যদি HAVE_TLS_FUNC
#যদি defined(_WIN32)
স্থির পূর্ণাঙ্ক no_checking = 0;
স্থির DWORD no_checking_চাবি;
#define NO_CHECKING_CHECK() যদি (!p) {                                         \
                                  p = (পূর্ণাঙ্ক *) LocalAlloc(LPTR, পরিমাণ(পূর্ণাঙ্ক));  \
                                  যদি (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_মান(no_checking_চাবি, p);            \
                            }
#define NO_CHECKING_GET()   ({ পূর্ণাঙ্ক *p = Tls_Get_মান(no_checking_চাবি);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { পূর্ণাঙ্ক *p = Tls_Get_মান(no_checking_চাবি);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#অন্যথা
স্থির পূর্ণাঙ্ক no_checking = 0;
স্থির pthread_key_t no_checking_চাবি;
#define NO_CHECKING_CHECK() যদি (!p) {                                         \
                                  p = (পূর্ণাঙ্ক *) BOUND_MALLOC(পরিমাণ(পূর্ণাঙ্ক));      \
                                  যদি (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_চাবি, p);    \
                            }
#define NO_CHECKING_GET()   ({ পূর্ণাঙ্ক *p = pthread_getspecific(no_checking_চাবি); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { পূর্ণাঙ্ক *p = pthread_getspecific(no_checking_চাবি);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#নোচেদ্যদি HAVE_TLS_VAR
স্থির __thread পূর্ণাঙ্ক no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#অন্যথা
স্থির _Atomic পূর্ণাঙ্ক no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
স্থির ৱর্ণ exec[100];

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

পূর্ণাঙ্ক tcc_backtrace(ধ্রুৱ ৱর্ণ *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    কৰা {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } যেতিয়ালৈ (0)

#define bound_error(...)            \
    কৰা {                            \
        bound_warning(__VA_ARGS__); \
        যদি (never_fatal == 0)       \
            exit(255);              \
    } যেতিয়ালৈ (0)

#define bounds_loc(fp, ...) \
    কৰা {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } যেতিয়ালৈ (0)

স্থির শূন্য bound_alloc_error(ধ্রুৱ ৱর্ণ *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

স্থির শূন্য bound_not_found_warning(ধ্রুৱ ৱর্ণ *file, ধ্রুৱ ৱর্ণ *function,
                                    শূন্য *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
শূন্য __bounds_checking (পূর্ণাঙ্ক no_check)
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
শূন্য __bound_never_fatal (পূর্ণাঙ্ক neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
শূন্য * __bound_ptr_add(শূন্য *p, size_t offset)
{
    size_t addr = (size_t)p;

    যদি (NO_CHECKING_GET())
        ঘূৰাই p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_গুনতি(bound_ptr_add_গুনতি);
    যদি (বৃক্ষ_2) {
        addr -= বৃক্ষ_2->start;
        যদি (addr >= বৃক্ষ_2->size) {
            addr = (size_t)p;
            বৃক্ষ_2 = splay (addr, বৃক্ষ_2);
            addr -= বৃক্ষ_2->start;
        }
        যদি (addr >= বৃক্ষ_2->size) {
            addr = (size_t)p;
            বৃক্ষ_2 = splay_end (addr, বৃক্ষ_2);
            addr -= বৃক্ষ_2->start;
        }
        যদি (addr <= বৃক্ষ_2->size) {
            যদি (বৃক্ষ_2->is_invalid || addr + offset > বৃক্ষ_2->size) {
                POST_SEM ();
                যদি (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)বৃক্ষ_2->start,
                                  (long)(বৃক্ষ_2->start + বৃক্ষ_2->size - 1));
                যদি (never_fatal <= 0)
                    ঘূৰাই INVALID_POINTER; /* return an invalid pointer */
                ঘূৰাই p + offset;
            }
        }
        অন্যথা যদি (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_গুনতি(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            ঘূৰাই p + offset;
        }
    }
    POST_SEM ();
    ঘূৰাই p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
শূন্য * __bound_ptr_indir ## dsize (শূন্য *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    যদি (NO_CHECKING_GET())                                                     \
        ঘূৰাই p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_গুনতি(bound_ptr_indir ## dsize ## গুনতি);                            \
    যদি (বৃক্ষ_2) {                                                                \
        addr -= বৃক্ষ_2->start;                                                   \
        যদি (addr >= বৃক্ষ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            বৃক্ষ_2 = splay (addr, বৃক্ষ_2);                                         \
            addr -= বৃক্ষ_2->start;                                               \
        }                                                                      \
        যদি (addr >= বৃক্ষ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            বৃক্ষ_2 = splay_end (addr, বৃক্ষ_2);                                     \
            addr -= বৃক্ষ_2->start;                                               \
        }                                                                      \
        যদি (addr <= বৃক্ষ_2->size) {                                              \
            যদি (বৃক্ষ_2->is_invalid || addr + offset + dsize > বৃক্ষ_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)বৃক্ষ_2->start,            \
                              (long)(বৃক্ষ_2->start + বৃক্ষ_2->size - 1));           \
                যদি (never_fatal <= 0)                                          \
                    ঘূৰাই INVALID_POINTER; /* return an invalid pointer */    \
                ঘূৰাই p + offset;                                             \
            }                                                                  \
        }                                                                      \
        অন্যথা {                                                                 \
            INCR_গুনতি(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            ঘূৰাই p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ঘূৰাই p + offset;                                                         \
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
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
শূন্য FASTCALL __bound_local_new(শূন্য *p1) 
{
    size_t addr, fp, *p = p1;

    যদি (NO_CHECKING_GET())
         ঘূৰাই;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (শূন্য *)fp);
    WAIT_SEM ();
    যেতিয়ালৈ ((addr = p[0])) {
        INCR_গুনতি(bound_local_new_গুনতি);
        বৃক্ষ_2 = splay_ঢোকাও(addr + fp, p[1], বৃক্ষ_2);
        p += 2;
    }
    POST_SEM ();
#যদি BOUND_DEBUG
    যদি (print_calls) {
        p = p1;
        যেতিয়ালৈ ((addr = p[0])) {
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
    size_t addr, fp, *p = p1;

    যদি (NO_CHECKING_GET())
         ঘূৰাই;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (শূন্য *)fp);
    WAIT_SEM ();
    যেতিয়ালৈ ((addr = p[0])) {
        INCR_গুনতি(bound_local_delete_গুনতি);
        বৃক্ষ_2 = splay_delete(addr + fp, বৃক্ষ_2);
        p += 2;
    }
    যদি (alloca_list) {
        alloca_list_type *last = রিক্ত;
        alloca_list_type *cur = alloca_list;

        কৰা {
            যদি (cur->fp == fp) {
                যদি (last)
                    last->next = cur->next;
                অন্যথা
                    alloca_list = cur->next;
                বৃক্ষ_2 = splay_delete ((size_t) cur->p, বৃক্ষ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             অন্যথা {
                 last = cur;
                 cur = cur->next;
             }
        } যেতিয়ালৈ (cur);
    }
    যদি (jmp_list) {
        jmp_list_type *last = রিক্ত;
        jmp_list_type *cur = jmp_list;

        কৰা {
            যদি (cur->fp == fp) {
                যদি (last)
                    last->next = cur->next;
                অন্যথা
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            অন্যথা {
                last = cur;
                cur = cur->next;
            }
        } যেতিয়ালৈ (cur);
    }

    POST_SEM ();
#যদি BOUND_DEBUG
    যদি (print_calls) {
        p = p1;
        যেতিয়ালৈ ((addr = p[0])) {
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
শূন্য __bound_new_region(শূন্য *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    যদি (NO_CHECKING_GET())
        ঘূৰাই;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (পরিমাণ (alloca_list_type));
    WAIT_SEM ();
    INCR_গুনতি(bound_alloca_গুনতি);
    last = রিক্ত;
    cur = alloca_list;
    যেতিয়ালৈ (cur) {
#যদি defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        পূর্ণাঙ্ক align = 4;
#নোচেদ্যদি defined(__arm__)
        পূর্ণাঙ্ক align = 8;
#অন্যথা
        পূর্ণাঙ্ক align = 16;
#endif
        শূন্য *cure = (শূন্য *)((ৱর্ণ *)cur->p + ((cur->size + align) & -align));
        শূন্য *pe = (শূন্য *)((ৱর্ণ *)p + ((size + align) & -align));
        যদি (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            যদি (last)
                last->next = cur->next;
            অন্যথা
                alloca_list = cur->next;
            বৃক্ষ_2 = splay_delete((size_t)cur->p, বৃক্ষ_2);
            ভঙ্গ;
        }
        last = cur;
        cur = cur->next;
    }
    বৃক্ষ_2 = splay_ঢোকাও((size_t)p, size, বৃক্ষ_2);
    যদি (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
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
        যেতিয়ালৈ (jl) {
            যদি (jl->penv == e)
                ভঙ্গ;
            jl = jl->next;
        }
        যদি (jl == রিক্ত) {
            jl = BOUND_MALLOC (পরিমাণ (jmp_list_type));
            যদি (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        যদি (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

স্থির শূন্য __bound_long_jump(jmp_buf env, পূর্ণাঙ্ক val, পূর্ণাঙ্ক sig, ধ্রুৱ ৱর্ণ *func)
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
        যেতিয়ালৈ (jl) {
            যদি (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = রিক্ত;

                যেতিয়ালৈ (cur->penv != e || cur->tid != tid) {
                    যদি (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        যদি (last)
                            last->next = cur->next;
                        অন্যথা
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    অন্যথা {
                        last = cur;
                        cur = cur->next;
                    }
                }
                বাবে (;;) {
                    বৃক্ষ *t = বৃক্ষ_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    যেতিয়ালৈ (t && (t->start < start_fp || t->start > end_fp))
                        যদি (t->start < start_fp)
                            t = t->ডান;
                        অন্যথা
                            t = t->বাম;
                    যদি (t == রিক্ত)
                        ভঙ্গ;
                    last = রিক্ত;
                    cur = alloca_list;
                    যেতিয়ালৈ (cur) {
                         যদি ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             যদি (last)
                                 last->next = cur->next;
                             অন্যথা
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             ভঙ্গ;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (শূন্য *) t->start);
                    বৃক্ষ_2 = splay_delete(t->start, বৃক্ষ_2);
                }
                ভঙ্গ;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#যদি !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

শূন্য __bound_longjmp(jmp_buf env, পূর্ণাঙ্ক val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#যদি !defined(_WIN32)
শূন্য __bound_siglongjmp(jmp_buf env, পূর্ণাঙ্ক val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic বেৰ_কৰো
#endif

শূন্য __bound_init(size_t *p, পূর্ণাঙ্ক mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    যদি (inited) {
        WAIT_SEM();
        গচ্ছ add_bounds;
    }
    inited = 1;

#যদি HAVE_TLS_FUNC
#যদি defined(_WIN32)
    no_checking_চাবি = TlsAlloc();
    Tls_Set_মান(no_checking_চাবি, &no_checking);
#অন্যথা
    pthread_key_create(&no_checking_চাবি, রিক্ত);
    pthread_setspecific(no_checking_চাবি, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != রিক্ত;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != রিক্ত;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != রিক্ত;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != রিক্ত;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != রিক্ত;

    INIT_SEM ();

#যদি MALLOC_REDIR
    {
        শূন্য *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(শূন্য **) (&malloc_redir) = dlsym (addr, "malloc");
        যদি (malloc_redir == রিক্ত) {
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
        যদি (malloc_redir == রিক্ত || free_redir == রিক্ত)
            bound_alloc_error ("Cannot redirect malloc/free");
#যদি HAVE_PTHREAD_CREATE
        *(শূন্য **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        যদি (pthread_create_redir == রিক্ত)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#যদি HAVE_SIGNAL
        *(শূন্য **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        যদি (signal_redir == রিক্ত)
            bound_alloc_error ("Cannot redirect signal");
#endif
#যদি HAVE_SIGACTION
        *(শূন্য **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        যদি (sigaction_redir == রিক্ত)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#যদি HAVE_FORK
        *(শূন্য **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        যদি (fork_redir == রিক্ত)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned ৱর্ণ found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        ৱর্ণ সাৰি[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        যদি (fp) {
            memset (exec, 0, পরিমাণ(exec));
            fread (exec, 1, পরিমাণ(exec) - 2, fp);
            যদি (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        যদি (fp) {
            যেতিয়ালৈ (fgets (সাৰি, পরিমাণ(সাৰি), fp)) {
                যদি (sscanf (সাৰি, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    ভঙ্গ;
                }
                যদি (strstr (সাৰি,"[heap]"))
                    ভঙ্গ;
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
    বৃক্ষ_2 = splay_ঢোকাও((size_t) &_DefaultRuneLocale,
                        পরিমাণ (_DefaultRuneLocale), বৃক্ষ_2);
#অন্যথা
    /* XXX: Does not work if locale is changed */
    বৃক্ষ_2 = splay_ঢোকাও((size_t) __ctype_b_loc(),
                        পরিমাণ (unsigned short *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((size_t) (*__ctype_b_loc() - 128),
                        384 * পরিমাণ (unsigned short), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((size_t) __ctype_tolower_loc(),
                        পরিমাণ (__int32_t *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((size_t) (*__ctype_tolower_loc() - 128),
                        384 * পরিমাণ (__int32_t), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((size_t) __ctype_toupper_loc(),
                        পরিমাণ (__int32_t *), বৃক্ষ_2);
    বৃক্ষ_2 = splay_ঢোকাও((size_t) (*__ctype_toupper_loc() - 128),
                        384 * পরিমাণ (__int32_t), বৃক্ষ_2);
#endif
#endif
#যদি HAVE_ERRNO
    বৃক্ষ_2 = splay_ঢোকাও((size_t) (&errno), পরিমাণ (পূর্ণাঙ্ক), বৃক্ষ_2);
#endif

add_bounds:
    যদি (!p)
        গচ্ছ no_bounds;

    /* add all static bound check values */
    যেতিয়ালৈ (p[0] != 0) {
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
__bound_main_arg(পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **envp)
{
    __bound_init (0, -1);
    যদি (argc && argv) {
        পূর্ণাঙ্ক i;

        WAIT_SEM ();
        বাবে (i = 0; i < argc; i++)
            বৃক্ষ_2 = splay_ঢোকাও((size_t) argv[i], strlen (argv[i]) + 1, বৃক্ষ_2);
        বৃক্ষ_2 = splay_ঢোকাও((size_t) argv, (argc + 1) * পরিমাণ(ৱর্ণ *), বৃক্ষ_2);
        POST_SEM ();
#যদি BOUND_DEBUG
        যদি (print_calls) {
            বাবে (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (পূর্ণাঙ্ক)((argc + 1) * পরিমাণ(ৱর্ণ *)));
        }
#endif
    }

    যদি (envp && *envp) {
        ৱর্ণ **p = envp;

        WAIT_SEM ();
        যেতিয়ালৈ (*p) {
            বৃক্ষ_2 = splay_ঢোকাও((size_t) *p, strlen (*p) + 1, বৃক্ষ_2);
            ++p;
        }
        বৃক্ষ_2 = splay_ঢোকাও((size_t) envp, (++p - envp) * পরিমাণ(ৱর্ণ *), বৃক্ষ_2);
        POST_SEM ();
#যদি BOUND_DEBUG
        যদি (print_calls) {
            p = envp;
            যেতিয়ালৈ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (পূর্ণাঙ্ক)((++p - envp) * পরিমাণ(ৱর্ণ *)));
        }
#endif
    }
}

শূন্য __attribute__((destructor)) __bound_exit(শূন্য)
{
    পূর্ণাঙ্ক i;
    স্থির ধ্রুৱ ৱর্ণ * ধ্রুৱ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    যদি (inited) {
#যদি !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        যদি (print_heap) {
            বাহ্য শূন্য __libc_freeres (শূন্য);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        যেতিয়ালৈ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            বৃক্ষ_2 = splay_delete ((size_t) alloca_list->p, বৃক্ষ_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        যেতিয়ালৈ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        বাবে (i = 0; i < FREE_REUSE_SIZE; i++) {
            যদি (free_reuse_list[i]) {
                বৃক্ষ_2 = splay_delete ((size_t) free_reuse_list[i], বৃক্ষ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        যেতিয়ালৈ (বৃক্ষ_2) {
            যদি (print_heap && বৃক্ষ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[বৃক্ষ_2->type],
                         (unsigned long) বৃক্ষ_2->size);
            বৃক্ষ_2 = splay_delete (বৃক্ষ_2->start, বৃক্ষ_2);
        }
#যদি বৃক্ষ_REUSE
        যেতিয়ালৈ (বৃক্ষ_free_list) {
            বৃক্ষ *next = বৃক্ষ_free_list->বাম;
            BOUND_FREE (বৃক্ষ_free_list);
            বৃক্ষ_free_list = next;
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

শূন্য __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    যদি (p) {
        WAIT_SEM ();
	যেতিয়ালৈ (p[0] != 0) {
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
প্রকারনির্দেশ সংরচনা {
    শূন্য *(*start_routine) (শূন্য *);
    শূন্য *arg;
    sigset_t old_mask;
} bound_thread_create_type;

স্থির শূন্য *bound_thread_create(শূন্য *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    শূন্য *retval;
#যদি HAVE_TLS_FUNC
    পূর্ণাঙ্ক *p = (পূর্ণাঙ্ক *) BOUND_MALLOC(পরিমাণ(পূর্ণাঙ্ক));
  
    যদি (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_চাবি, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, রিক্ত);
    retval = data->start_routine(data->arg);
#যদি HAVE_TLS_FUNC
    pthread_setspecific(no_checking_চাবি, রিক্ত);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    ঘূৰাই retval;
}

পূর্ণাঙ্ক pthread_create(pthread_t *thread, ধ্রুৱ pthread_attr_t *attr,
                   শূন্য *(*start_routine) (শূন্য *), শূন্য *arg)
{
    পূর্ণাঙ্ক retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(পরিমাণ(bound_thread_create_type));
    যদি (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, রিক্ত);
    ঘূৰাই retval;
}
#endif

#যদি HAVE_SIGNAL || HAVE_SIGACTION
প্রকারনির্দেশ সঙ্ঘ {
#যদি HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#যদি HAVE_SIGACTION
    শূন্য (*sig_handler)(পূর্ণাঙ্ক);
    শূন্য (*sig_sigaction)(পূর্ণাঙ্ক, siginfo_t *, শূন্য *);
#endif
} bound_sig_type;

স্থির unsigned ৱর্ণ bound_sig_used[NSIG];
স্থির bound_sig_type bound_sig_data[NSIG];
#endif

#যদি HAVE_SIGNAL
স্থির শূন্য signal_handler(পূর্ণাঙ্ক sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig সঙ্কেত(পূর্ণাঙ্ক signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    যদি (retval != SIG_ERR) {
        যদি (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        যদি (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    ঘূৰাই retval;
}
#endif

#যদি HAVE_SIGACTION
স্থির শূন্য sig_handler(পূর্ণাঙ্ক sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

স্থির শূন্য sig_sigaction(পূর্ণাঙ্ক sig, siginfo_t *info, শূন্য *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

পূর্ণাঙ্ক sigaction(পূর্ণাঙ্ক signum, ধ্রুৱ সংরচনা sigaction *act, সংরচনা sigaction *oldact)
{
    পূর্ণাঙ্ক retval;
    সংরচনা sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    যদি (sigaction_redir == রিক্ত)
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
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            অন্যথা
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        যদি (oldact) {
            *oldact = oact;
        }
        যদি (act) {
            bound_sig_used[signum] = 1;
            যদি (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            অন্যথা
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    ঘূৰাই retval;
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
    ঘূৰাই retval;
}
#endif

#যদি MALLOC_REDIR
শূন্য *malloc(size_t size)
#অন্যথা
শূন্য *__bound_malloc(size_t size, ধ্রুৱ শূন্য *caller)
#endif
{
    শূন্য *ptr;
    
#যদি MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    যদি (malloc_redir == রিক্ত) {
        __bound_init (0, -1);
        যদি (malloc_redir == রিক্ত) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            যদি (pool_index >= পরিমাণ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            ঘূৰাই ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    যদি (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_malloc_গুনতি);

        যদি (ptr) {
            বৃক্ষ_2 = splay_ঢোকাও ((size_t) ptr, size ? size : size + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (size_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ঘূৰাই ptr;
}

#যদি MALLOC_REDIR
শূন্য *memalign(size_t align, size_t size)
#অন্যথা
শূন্য *__bound_memalign(size_t align, size_t size, ধ্রুৱ শূন্য *caller)
#endif
{
    শূন্য *ptr;

#যদি HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#অন্যথা
    যদি (align > 4) {
        /* XXX: handle it ? */
        ptr = রিক্ত;
    } অন্যথা {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    যদি (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_memalign_গুনতি);

        যদি (ptr) {
            বৃক্ষ_2 = splay_ঢোকাও((size_t) ptr, size ? size : size + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (size_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ঘূৰাই ptr;
}

#যদি MALLOC_REDIR
শূন্য মুক্ত(শূন্য *ptr)
#অন্যথা
শূন্য __bound_free(শূন্য *ptr, ধ্রুৱ শূন্য *caller)
#endif
{
    size_t addr = (size_t) ptr;
    শূন্য *p;

    যদি (ptr == রিক্ত || বৃক্ষ_2 == রিক্ত
#যদি MALLOC_REDIR
        || ((unsigned ৱর্ণ *) ptr >= &initial_pool[0] &&
            (unsigned ৱর্ণ *) ptr < &initial_pool[পরিমাণ(initial_pool)])
#endif
        )
        ঘূৰাই;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    যদি (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_free_গুনতি);
        বৃক্ষ_2 = splay (addr, বৃক্ষ_2);
        যদি (বৃক্ষ_2->start == addr) {
            যদি (বৃক্ষ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ঘূৰাই;
            }
            বৃক্ষ_2->is_invalid = 1;
            memset (ptr, 0x5a, বৃক্ষ_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            যদি (p)
                বৃক্ষ_2 = splay_delete((size_t)p, বৃক্ষ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#যদি MALLOC_REDIR
শূন্য *realloc(শূন্য *ptr, size_t size)
#অন্যথা
শূন্য *__bound_realloc(শূন্য *ptr, size_t size, ধ্রুৱ শূন্য *caller)
#endif
{
    শূন্য *new_ptr;

    যদি (size == 0) {
#যদি MALLOC_REDIR
        মুক্ত(ptr);
#অন্যথা
        __bound_free(ptr, caller);
#endif
        ঘূৰাই রিক্ত;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    যদি (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_realloc_গুনতি);

        যদি (ptr)
            বৃক্ষ_2 = splay_delete ((size_t) ptr, বৃক্ষ_2);
        যদি (new_ptr) {
            বৃক্ষ_2 = splay_ঢোকাও ((size_t) new_ptr, size ? size : size + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (size_t) new_ptr)
                বৃক্ষ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ঘূৰাই new_ptr;
}

#যদি MALLOC_REDIR
শূন্য *calloc(size_t nmemb, size_t size)
#অন্যথা
শূন্য *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    শূন্য *ptr;

    size *= nmemb;
#যদি MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    যদি (malloc_redir == রিক্ত) {
        __bound_init (0, -1);
        যদি (malloc_redir == রিক্ত) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            যদি (pool_index >= পরিমাণ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            ঘূৰাই ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    যদি (ptr) {
        memset (ptr, 0, size);
        যদি (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_গুনতি(bound_calloc_গুনতি);
            বৃক্ষ_2 = splay_ঢোকাও ((size_t) ptr, size ? size : size + 1, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (size_t) ptr)
                বৃক্ষ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ঘূৰাই ptr;
}

#যদি !defined(_WIN32)
শূন্য *__bound_mmap (শূন্য *start, size_t size, পূর্ণাঙ্ক prot,
                    পূর্ণাঙ্ক flags, পূর্ণাঙ্ক fd, off_t offset)
{
    শূন্য *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    যদি (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_mmap_গুনতি);
        বৃক্ষ_2 = splay_ঢোকাও((size_t)result, size, বৃক্ষ_2);
        POST_SEM ();
    }
    ঘূৰাই result;
}

পূর্ণাঙ্ক __bound_munmap (শূন্য *start, size_t size)
{
    পূর্ণাঙ্ক result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    যদি (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_গুনতি(bound_munmap_গুনতি);
        বৃক্ষ_2 = splay_delete ((size_t) start, বৃক্ষ_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    ঘূৰাই result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
স্থির শূন্য __bound_check(ধ্রুৱ শূন্য *p, size_t size, ধ্রুৱ ৱর্ণ *function)
{
    যদি (size != 0 && __bound_ptr_add((শূন্য *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

স্থির পূর্ণাঙ্ক check_overlap (ধ্রুৱ শূন্য *p1, size_t n1,
                          ধ্রুৱ শূন্য *p2, size_t n2,
                          ধ্রুৱ ৱর্ণ *function)
{
    ধ্রুৱ শূন্য *p1e = (ধ্রুৱ শূন্য *) ((ধ্রুৱ ৱর্ণ *) p1 + n1);
    ধ্রুৱ শূন্য *p2e = (ধ্রুৱ শূন্য *) ((ধ্রুৱ ৱর্ণ *) p2 + n2);

    যদি (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        ঘূৰাই never_fatal < 0;
    }
    ঘূৰাই 0;
}

শূন্য *__bound_memcpy(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_mempcy_গুনতি);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    যদি (check_overlap(dest, n, src, n, "memcpy"))
        ঘূৰাই dest;
    ঘূৰাই memcpy(dest, src, n);
}

পূর্ণাঙ্ক __bound_memcmp(ধ্রুৱ শূন্য *s1, ধ্রুৱ শূন্য *s2, size_t n)
{
    ধ্রুৱ unsigned ৱর্ণ *u1 = (ধ্রুৱ unsigned ৱর্ণ *) s1;
    ধ্রুৱ unsigned ৱর্ণ *u2 = (ধ্রুৱ unsigned ৱর্ণ *) s2;
    পূর্ণাঙ্ক retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_গুনতি(bound_memcmp_গুনতি);
    বাবে (;;) {
        যদি ((ssize_t) --n == -1)
            ভঙ্গ;
        অন্যথা যদি (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ভঙ্গ;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ধ্রুৱ শূন্য *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ধ্রুৱ শূন্য *)u2 - s2, "memcmp s2");
    ঘূৰাই retval;
}

শূন্য *__bound_memmove(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ঘূৰাই memmove(dest, src, n);
}

শূন্য *__bound_memset(শূন্য *s, পূর্ণাঙ্ক c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_গুনতি(bound_memset_গুনতি);
    __bound_check(s, n, "memset");
    ঘূৰাই memset(s, c, n);
}

#যদি defined(__arm__) && defined(__ARM_EABI__)
শূন্য *__bound___aeabi_memcpy(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_mempcy_গুনতি);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    যদি (check_overlap(dest, n, src, n, "memcpy"))
        ঘূৰাই dest;
    ঘূৰাই __aeabi_memcpy(dest, src, n);
}

শূন্য *__bound___aeabi_memmove(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ঘূৰাই __aeabi_memmove(dest, src, n);
}

শূন্য *__bound___aeabi_memmove4(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ঘূৰাই __aeabi_memmove4(dest, src, n);
}

শূন্য *__bound___aeabi_memmove8(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_memmove_গুনতি);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ঘূৰাই __aeabi_memmove8(dest, src, n);
}

শূন্য *__bound___aeabi_memset(শূন্য *s, পূর্ণাঙ্ক c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_গুনতি(bound_memset_গুনতি);
    __bound_check(s, n, "memset");
    ঘূৰাই __aeabi_memset(s, c, n);
}
#endif

পূর্ণাঙ্ক __bound_strlen(ধ্রুৱ ৱর্ণ *s)
{
    ধ্রুৱ ৱর্ণ *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_গুনতি(bound_strlen_গুনতি);
    যেতিয়ালৈ (*p++);
    __bound_check(s, p - s, "strlen");
    ঘূৰাই (p - s) - 1;
}

ৱর্ণ *__bound_strcpy(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src)
{
    size_t len;
    ধ্রুৱ ৱর্ণ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_গুনতি(bound_strcpy_গুনতি);
    যেতিয়ালৈ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    যদি (check_overlap(dest, len, src, len, "strcpy"))
        ঘূৰাই dest;
    ঘূৰাই strcpy (dest, src);
}

ৱর্ণ *__bound_strncpy(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src, size_t n)
{
    size_t len = n;
    ধ্রুৱ ৱর্ণ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_strncpy_গুনতি);
    যেতিয়ালৈ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    যদি (check_overlap(dest, len, src, len, "strncpy"))
        ঘূৰাই dest;
    ঘূৰাই strncpy(dest, src, n);
}

পূর্ণাঙ্ক __bound_strcmp(ধ্রুৱ ৱর্ণ *s1, ধ্রুৱ ৱর্ণ *s2)
{
    ধ্রুৱ unsigned ৱর্ণ *u1 = (ধ্রুৱ unsigned ৱর্ণ *) s1;
    ধ্রুৱ unsigned ৱর্ণ *u2 = (ধ্রুৱ unsigned ৱর্ণ *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_গুনতি(bound_strcmp_গুনতি);
    যেতিয়ালৈ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ধ্রুৱ ৱর্ণ *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ধ্রুৱ ৱর্ণ *)u2 - s2) + 1, "strcmp s2");
    ঘূৰাই *u1 - *u2;
}

পূর্ণাঙ্ক __bound_strncmp(ধ্রুৱ ৱর্ণ *s1, ধ্রুৱ ৱর্ণ *s2, size_t n)
{
    ধ্রুৱ unsigned ৱর্ণ *u1 = (ধ্রুৱ unsigned ৱর্ণ *) s1;
    ধ্রুৱ unsigned ৱর্ণ *u2 = (ধ্রুৱ unsigned ৱর্ণ *) s2;
    পূর্ণাঙ্ক retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_গুনতি(bound_strncmp_গুনতি);
    কৰা {
        যদি ((ssize_t) --n == -1)
            ভঙ্গ;
        অন্যথা যদি (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ভঙ্গ;
        }
        ++u2;
    } যেতিয়ালৈ (*u1++);
    __bound_check(s1, (ধ্রুৱ ৱর্ণ *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ধ্রুৱ ৱর্ণ *)u2 - s2, "strncmp s2");
    ঘূৰাই retval;
}

ৱর্ণ *__bound_strcat(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src)
{
    ৱর্ণ *r = dest;
    ধ্রুৱ ৱর্ণ *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_গুনতি(bound_strcat_গুনতি);
    যেতিয়ালৈ (*dest++);
    যেতিয়ালৈ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    যদি (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ঘূৰাই dest;
    ঘূৰাই strcat(r, s);
}

ৱর্ণ *__bound_strncat(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src, size_t n)
{
    ৱর্ণ *r = dest;
    ধ্রুৱ ৱর্ণ *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_গুনতি(bound_strncat_গুনতি);
    যেতিয়ালৈ (*dest++);
    যেতিয়ালৈ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    যদি (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ঘূৰাই dest;
    ঘূৰাই strncat(r, s, n);
}

ৱর্ণ *__bound_strchr(ধ্রুৱ ৱর্ণ *s, পূর্ণাঙ্ক c)
{
    ধ্রুৱ unsigned ৱর্ণ *str = (ধ্রুৱ unsigned ৱর্ণ *) s;
    unsigned ৱর্ণ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_গুনতি(bound_strchr_গুনতি);
    যেতিয়ালৈ (*str) {
        যদি (*str == ch)
            ভঙ্গ;
        ++str;
    }
    __bound_check(s, ((ধ্রুৱ ৱর্ণ *)str - s) + 1, "strchr");
    ঘূৰাই *str == ch ? (ৱর্ণ *) str : রিক্ত;
}

ৱর্ণ *__bound_strrchr(ধ্রুৱ ৱর্ণ *s, পূর্ণাঙ্ক c)
{
    ধ্রুৱ unsigned ৱর্ণ *str = (ধ্রুৱ unsigned ৱর্ণ *) s;
    unsigned ৱর্ণ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_গুনতি(bound_strrchr_গুনতি);
    যেতিয়ালৈ (*str++);
    __bound_check(s, (ধ্রুৱ ৱর্ণ *)str - s, "strrchr");
    যেতিয়ালৈ (str != (ধ্রুৱ unsigned ৱর্ণ *)s) {
        যদি (*--str == ch)
            ভঙ্গ;
    }
    __bound_check(s, (ধ্রুৱ ৱর্ণ *)str - s, "strrchr");
    ঘূৰাই *str == ch ? (ৱর্ণ *) str : রিক্ত;
}

ৱর্ণ *__bound_strdup(ধ্রুৱ ৱর্ণ *s)
{
    ধ্রুৱ ৱর্ণ *p = s;
    ৱর্ণ *new;

    INCR_গুনতি(bound_strdup_গুনতি);
    যেতিয়ালৈ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    যদি (new) {
        যদি (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            বৃক্ষ_2 = splay_ঢোকাও((size_t)new, p - s, বৃক্ষ_2);
            যদি (বৃক্ষ_2 && বৃক্ষ_2->start == (size_t) new)
                বৃক্ষ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    ঘূৰাই new;
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

স্থির বৃক্ষ * splay (size_t addr, বৃক্ষ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    বৃক্ষ N, *l, *r, *y;
    পূর্ণাঙ্ক comp;
    
    INCR_গুনতি_SPLAY(bound_splay);
    যদি (t == রিক্ত) ঘূৰাই t;
    N.বাম = N.ডান = রিক্ত;
    l = r = &N;
 
    বাবে (;;) {
        comp = compare(addr, t->start, t->size);
        যদি (comp < 0) {
            y = t->বাম;
            যদি (y == রিক্ত) ভঙ্গ;
            যদি (compare(addr, y->start, y->size) < 0) {
                t->বাম = y->ডান;                    /* rotate right */
                y->ডান = t;
                t = y;
                যদি (t->বাম == রিক্ত) ভঙ্গ;
            }
            r->বাম = t;                               /* link right */
            r = t;
            t = t->বাম;
        } অন্যথা যদি (comp > 0) {
            y = t->ডান;
            যদি (y == রিক্ত) ভঙ্গ;
            যদি (compare(addr, y->start, y->size) > 0) {
                t->ডান = y->বাম;                    /* rotate left */
                y->বাম = t;
                t = y;
                যদি (t->ডান == রিক্ত) ভঙ্গ;
            }
            l->ডান = t;                              /* link left */
            l = t;
            t = t->ডান;
        } অন্যথা {
            ভঙ্গ;
        }
    }
    l->ডান = t->বাম;                                /* assemble */
    r->বাম = t->ডান;
    t->বাম = N.ডান;
    t->ডান = N.বাম;

    ঘূৰাই t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

স্থির বৃক্ষ * splay_end (size_t addr, বৃক্ষ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    বৃক্ষ N, *l, *r, *y;
    পূর্ণাঙ্ক comp;
    
    INCR_গুনতি_SPLAY(bound_splay_end);
    যদি (t == রিক্ত) ঘূৰাই t;
    N.বাম = N.ডান = রিক্ত;
    l = r = &N;
 
    বাবে (;;) {
        comp = compare_end(addr, t->start + t->size);
        যদি (comp < 0) {
            y = t->বাম;
            যদি (y == রিক্ত) ভঙ্গ;
            যদি (compare_end(addr, y->start + y->size) < 0) {
                t->বাম = y->ডান;                    /* rotate right */
                y->ডান = t;
                t = y;
                যদি (t->বাম == রিক্ত) ভঙ্গ;
            }
            r->বাম = t;                               /* link right */
            r = t;
            t = t->বাম;
        } অন্যথা যদি (comp > 0) {
            y = t->ডান;
            যদি (y == রিক্ত) ভঙ্গ;
            যদি (compare_end(addr, y->start + y->size) > 0) {
                t->ডান = y->বাম;                    /* rotate left */
                y->বাম = t;
                t = y;
                যদি (t->ডান == রিক্ত) ভঙ্গ;
            }
            l->ডান = t;                              /* link left */
            l = t;
            t = t->ডান;
        } অন্যথা {
            ভঙ্গ;
        }
    }
    l->ডান = t->বাম;                                /* assemble */
    r->বাম = t->ডান;
    t->বাম = N.ডান;
    t->ডান = N.বাম;

    ঘূৰাই t;
}

স্থির বৃক্ষ * splay_ঢোকাও(size_t addr, size_t size, বৃক্ষ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    বৃক্ষ * new;

    INCR_গুনতি_SPLAY(bound_splay_ঢোকাও);
    যদি (t != রিক্ত) {
        t = splay(addr,t);
        যদি (compare(addr, t->start, t->size)==0) {
            ঘূৰাই t;  /* it's already there */
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
        new = (বৃক্ষ *) BOUND_MALLOC (পরিমাণ (বৃক্ষ));
    }
    যদি (new == রিক্ত) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    অন্যথা {
        যদি (t == রিক্ত) {
            new->বাম = new->ডান = রিক্ত;
        } অন্যথা যদি (compare(addr, t->start, t->size) < 0) {
            new->বাম = t->বাম;
            new->ডান = t;
            t->বাম = রিক্ত;
        } অন্যথা {
            new->ডান = t->ডান;
            new->বাম = t;
            t->ডান = রিক্ত;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ঘূৰাই new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

স্থির বৃক্ষ * splay_delete(size_t addr, বৃক্ষ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    বৃক্ষ * x;

    INCR_গুনতি_SPLAY(bound_splay_delete);
    যদি (t==রিক্ত) ঘূৰাই রিক্ত;
    t = splay(addr,t);
    যদি (compare_destroy(addr, t->start) == 0) {        /* found it */
        যদি (t->বাম == রিক্ত) {
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
        ঘূৰাই x;
    } অন্যথা {
        ঘূৰাই t;                                      /* It wasn't there */
    }
}

শূন্য splay_printtree(বৃক্ষ * t, পূর্ণাঙ্ক d)
{
    পূর্ণাঙ্ক i;
    যদি (t == রিক্ত) ঘূৰাই;
    splay_printtree(t->ডান, d+1);
    বাবে (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (শূন্য *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->বাম, d+1);
}
