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
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdarg.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <setjmp.h>
#அந்தர்பாவ <stdatomic.h>

#எனில் !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#அந்தர்பாவ <malloc.h>
#endif

#எனில் !defined(_WIN32)
#அந்தர்பாவ <unistd.h>
#அந்தர்பாவ <sys/syscall.h>
#endif

#அந்தர்பாவ "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#எனில் BOUND_DEBUG
 #define dprintf(a...)         எனில் (print_calls) { bounds_loc(a); }
#இல்லையெனில்
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#இல்லையெனில்
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#இல்லையெனில்
# define DLL_EXPORT
#endif

#எனில் defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#அந்தர்பாவ <sys/mman.h>
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

#அல்லதெனில் defined(_WIN32)

#அந்தர்பாவ <windows.h>
#அந்தர்பாவ <signal.h>
நிலையான CRITICAL_SECTION bounds_sem;
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

#இல்லையெனில்

#define __USE_GNU              /* get RTLD_NEXT */
#அந்தர்பாவ <sys/mman.h>
#அந்தர்பாவ <ctype.h>
#அந்தர்பாவ <pthread.h>
#அந்தர்பாவ <dlfcn.h>
#அந்தர்பாவ <errno.h>
#அந்தர்பாவ <signal.h>
#ifdef __APPLE__
#அந்தர்பாவ <dispatch/dispatch.h>
நிலையான dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             எனில் (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             எனில் (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              எனில் (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#அல்லதெனில் 0
#அந்தர்பாவ <semaphore.h>
நிலையான sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             எனில் (use_sem) போது (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             எனில் (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              எனில் (use_sem) போது (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#அல்லதெனில் 0
நிலையான pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, வெற்று)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             எனில் (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             எனில் (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              எனில் (use_sem) pthread_mutex_trylock (&bounds_mtx)
#இல்லையெனில்
நிலையான pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             எனில் (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             எனில் (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              எனில் (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#எனில் defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#இல்லையெனில்
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#எனில் defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#எனில் MALLOC_REDIR
நிலையான வெறுமை *(*malloc_redir) (size_t);
நிலையான வெறுமை *(*calloc_redir) (size_t, size_t);
நிலையான வெறுமை (*free_redir) (வெறுமை *);
நிலையான வெறுமை *(*realloc_redir) (வெறுமை *, size_t);
நிலையான unsigned முழு pool_index;
நிலையான unsigned எழுத்து __attribute__((aligned(16))) initial_pool[256];
#endif
#எனில் HAVE_MEMALIGN
நிலையான வெறுமை *(*memalign_redir) (size_t, size_t);
#endif
#எனில் HAVE_PTHREAD_CREATE
நிலையான முழு (*pthread_create_redir) (pthread_t *thread,
                                    மாறிலி pthread_attr_t *attr,
                                    வெறுமை *(*start_routine)(வெறுமை *), வெறுமை *arg);
#endif
#எனில் HAVE_SIGNAL
வகைவரை வெறுமை (*bound_sig)(முழு);
நிலையான bound_sig (*signal_redir) (முழு signum, bound_sig handler);
#endif
#எனில் HAVE_SIGACTION
நிலையான முழு (*sigaction_redir) (முழு signum, மாறிலி கட்டமைப்பு sigaction *act,
                               கட்டமைப்பு sigaction *oldact);
#endif
#எனில் HAVE_FORK
நிலையான முழு (*fork_redir) (வெறுமை);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((வெறுமை *)(-2))

வகைவரை கட்டமைப்பு மர_முனை மரம்;
கட்டமைப்பு மர_முனை {
    மரம் * இடது, * வலது;
    size_t start;
    size_t size;
    unsigned எழுத்து type;
    unsigned எழுத்து is_invalid; /* true if pointers outside region are invalid */
};

வகைவரை கட்டமைப்பு alloca_list_struct {
    size_t fp;
    வெறுமை *p;
    size_t size;
    கட்டமைப்பு alloca_list_struct *next;
} alloca_list_type;

#எனில் defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#அல்லதெனில் defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#அல்லதெனில் defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#அல்லதெனில்  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#அல்லதெனில் defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#இல்லையெனில்
#define BOUND_TID_TYPE		முழு
#define BOUND_GET_TID(id)	id = 0
#endif

வகைவரை கட்டமைப்பு jmp_list_struct {
    வெறுமை *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    கட்டமைப்பு jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
நிலையான மரம் * splay (size_t addr, மரம் *t);
நிலையான மரம் * splay_end (size_t addr, மரம் *t);
நிலையான மரம் * splay_செருகு(size_t addr, size_t size, மரம் * t);
நிலையான மரம் * splay_delete(size_t addr, மரம் *t);
வெறுமை splay_printtree(மரம் * t, முழு d);

/* external interface */
வெறுமை __bounds_checking (முழு no_check);
வெறுமை __bound_checking_lock (வெறுமை);
வெறுமை __bound_checking_unlock (வெறுமை);
வெறுமை __bound_never_fatal (முழு no_check);
DLL_EXPORT வெறுமை * __bound_ptr_add(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir1(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir2(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir4(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir8(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir12(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை * __bound_ptr_indir16(வெறுமை *p, size_t offset);
DLL_EXPORT வெறுமை FASTCALL __bound_local_new(வெறுமை *p1);
DLL_EXPORT வெறுமை FASTCALL __bound_local_delete(வெறுமை *p1);
வெறுமை __bound_init(size_t *, முழு);
வெறுமை __bound_main_arg(முழு argc, எழுத்து **argv, எழுத்து **envp);
வெறுமை __bound_exit(வெறுமை);
வெறுமை __bound_exit_dll(size_t *);
#எனில் !defined(_WIN32)
வெறுமை *__bound_mmap (வெறுமை *start, size_t size, முழு prot, முழு flags, முழு fd,
                    off_t offset);
முழு __bound_munmap (வெறுமை *start, size_t size);
DLL_EXPORT வெறுமை __bound_siglongjmp(jmp_buf env, முழு val);
#endif
DLL_EXPORT வெறுமை __bound_new_region(வெறுமை *p, size_t size);
DLL_EXPORT வெறுமை __bound_setjmp(jmp_buf env);
DLL_EXPORT வெறுமை __bound_longjmp(jmp_buf env, முழு val);
DLL_EXPORT வெறுமை *__bound_memcpy(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT முழு __bound_memcmp(மாறிலி வெறுமை *s1, மாறிலி வெறுமை *s2, size_t size);
DLL_EXPORT வெறுமை *__bound_memmove(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__bound_memset(வெறுமை *dst, முழு c, size_t size);
DLL_EXPORT முழு __bound_strlen(மாறிலி எழுத்து *s);
DLL_EXPORT எழுத்து *__bound_strcpy(எழுத்து *dst, மாறிலி எழுத்து *src);
DLL_EXPORT எழுத்து *__bound_strncpy(எழுத்து *dst, மாறிலி எழுத்து *src, size_t n);
DLL_EXPORT முழு __bound_strcmp(மாறிலி எழுத்து *s1, மாறிலி எழுத்து *s2);
DLL_EXPORT முழு __bound_strncmp(மாறிலி எழுத்து *s1, மாறிலி எழுத்து *s2, size_t n);
DLL_EXPORT எழுத்து *__bound_strcat(எழுத்து *dest, மாறிலி எழுத்து *src);
DLL_EXPORT எழுத்து *__bound_strncat(எழுத்து *dest, மாறிலி எழுத்து *src, size_t n);
DLL_EXPORT எழுத்து *__bound_strchr(மாறிலி எழுத்து *string, முழு ch);
DLL_EXPORT எழுத்து *__bound_strrchr(மாறிலி எழுத்து *string, முழு ch);
DLL_EXPORT எழுத்து *__bound_strdup(மாறிலி எழுத்து *s);

#எனில் defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT வெறுமை *__bound___aeabi_memcpy(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__bound___aeabi_memmove(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__bound___aeabi_memmove4(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__bound___aeabi_memmove8(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__bound___aeabi_memset(வெறுமை *dst, முழு c, size_t size);
DLL_EXPORT வெறுமை *__aeabi_memcpy(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__aeabi_memmove(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__aeabi_memmove4(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__aeabi_memmove8(வெறுமை *dst, மாறிலி வெறுமை *src, size_t size);
DLL_EXPORT வெறுமை *__aeabi_memset(வெறுமை *dst, முழு c, size_t size);
#endif

#எனில் MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#இல்லையெனில்
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            விடுவி(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT வெறுமை *__bound_malloc(size_t size, மாறிலி வெறுமை *caller);
DLL_EXPORT வெறுமை *__bound_memalign(size_t align, size_t size, மாறிலி வெறுமை *caller);
DLL_EXPORT வெறுமை __bound_free(வெறுமை *ptr, மாறிலி வெறுமை *caller);
DLL_EXPORT வெறுமை *__bound_realloc(வெறுமை *ptr, size_t size, மாறிலி வெறுமை *caller);
DLL_EXPORT வெறுமை *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
நிலையான unsigned முழு free_reuse_index;
நிலையான வெறுமை *free_reuse_list[FREE_REUSE_SIZE];

நிலையான மரம் *மரம்_2 = வெற்று;
#define மரம்_REUSE      (1)
#எனில் மரம்_REUSE
நிலையான மரம் *மரம்_free_list;
#endif
நிலையான alloca_list_type *alloca_list;
நிலையான jmp_list_type *jmp_list;

நிலையான unsigned எழுத்து inited;
நிலையான unsigned எழுத்து print_warn_ptr_add;
நிலையான unsigned எழுத்து print_calls;
நிலையான unsigned எழுத்து print_heap;
நிலையான unsigned எழுத்து print_statistic;
நிலையான unsigned எழுத்து no_strdup;
நிலையான unsigned எழுத்து use_sem;
நிலையான _Atomic முழு never_fatal;
#எனில் HAVE_TLS_FUNC
#எனில் defined(_WIN32)
நிலையான முழு no_checking = 0;
நிலையான DWORD no_checking_சாவி;
#define NO_CHECKING_CHECK() எனில் (!p) {                                         \
                                  p = (முழு *) LocalAlloc(LPTR, அளவு(முழு));  \
                                  எனில் (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_மதிப்பு(no_checking_சாவி, p);            \
                            }
#define NO_CHECKING_GET()   ({ முழு *p = Tls_Get_மதிப்பு(no_checking_சாவி);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { முழு *p = Tls_Get_மதிப்பு(no_checking_சாவி);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#இல்லையெனில்
நிலையான முழு no_checking = 0;
நிலையான pthread_key_t no_checking_சாவி;
#define NO_CHECKING_CHECK() எனில் (!p) {                                         \
                                  p = (முழு *) BOUND_MALLOC(அளவு(முழு));      \
                                  எனில் (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_சாவி, p);    \
                            }
#define NO_CHECKING_GET()   ({ முழு *p = pthread_getspecific(no_checking_சாவி); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { முழு *p = pthread_getspecific(no_checking_சாவி);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#அல்லதெனில் HAVE_TLS_VAR
நிலையான __thread முழு no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#இல்லையெனில்
நிலையான _Atomic முழு no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
நிலையான எழுத்து exec[100];

#எனில் BOUND_STATISTIC
நிலையான unsigned long long bound_ptr_add_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir1_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir2_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir4_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir8_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir12_மொத்தம்;
நிலையான unsigned long long bound_ptr_indir16_மொத்தம்;
நிலையான unsigned long long bound_local_new_மொத்தம்;
நிலையான unsigned long long bound_local_delete_மொத்தம்;
நிலையான unsigned long long bound_malloc_மொத்தம்;
நிலையான unsigned long long bound_calloc_மொத்தம்;
நிலையான unsigned long long bound_realloc_மொத்தம்;
நிலையான unsigned long long bound_free_மொத்தம்;
நிலையான unsigned long long bound_memalign_மொத்தம்;
நிலையான unsigned long long bound_mmap_மொத்தம்;
நிலையான unsigned long long bound_munmap_மொத்தம்;
நிலையான unsigned long long bound_alloca_மொத்தம்;
நிலையான unsigned long long bound_setjmp_மொத்தம்;
நிலையான unsigned long long bound_longjmp_மொத்தம்;
நிலையான unsigned long long bound_mempcy_மொத்தம்;
நிலையான unsigned long long bound_memcmp_மொத்தம்;
நிலையான unsigned long long bound_memmove_மொத்தம்;
நிலையான unsigned long long bound_memset_மொத்தம்;
நிலையான unsigned long long bound_strlen_மொத்தம்;
நிலையான unsigned long long bound_strcpy_மொத்தம்;
நிலையான unsigned long long bound_strncpy_மொத்தம்;
நிலையான unsigned long long bound_strcmp_மொத்தம்;
நிலையான unsigned long long bound_strncmp_மொத்தம்;
நிலையான unsigned long long bound_strcat_மொத்தம்;
நிலையான unsigned long long bound_strncat_மொத்தம்;
நிலையான unsigned long long bound_strchr_மொத்தம்;
நிலையான unsigned long long bound_strrchr_மொத்தம்;
நிலையான unsigned long long bound_strdup_மொத்தம்;
நிலையான unsigned long long bound_not_found;
#define INCR_மொத்தம்(x)          ++x
#இல்லையெனில்
#define INCR_மொத்தம்(x)
#endif
#எனில் BOUND_STATISTIC_SPLAY
நிலையான unsigned long long bound_splay;
நிலையான unsigned long long bound_splay_end;
நிலையான unsigned long long bound_splay_செருகு;
நிலையான unsigned long long bound_splay_delete;
#define INCR_மொத்தம்_SPLAY(x)    ++x
#இல்லையெனில்
#define INCR_மொத்தம்_SPLAY(x)
#endif

முழு tcc_backtrace(மாறிலி எழுத்து *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    செய் {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } போது (0)

#define bound_error(...)            \
    செய் {                            \
        bound_warning(__VA_ARGS__); \
        எனில் (never_fatal == 0)       \
            exit(255);              \
    } போது (0)

#define bounds_loc(fp, ...) \
    செய் {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } போது (0)

நிலையான வெறுமை bound_alloc_error(மாறிலி எழுத்து *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

நிலையான வெறுமை bound_not_found_warning(மாறிலி எழுத்து *file, மாறிலி எழுத்து *function,
                                    வெறுமை *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
வெறுமை __bounds_checking (முழு no_check)
{
#எனில் HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#இல்லையெனில்
    atomic_fetch_add (&no_checking, no_check);
#endif
}

வெறுமை __bound_checking_lock(வெறுமை)
{
    WAIT_SEM ();
}

வெறுமை __bound_checking_unlock(வெறுமை)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
வெறுமை __bound_never_fatal (முழு neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
வெறுமை * __bound_ptr_add(வெறுமை *p, size_t offset)
{
    size_t addr = (size_t)p;

    எனில் (NO_CHECKING_GET())
        திரும்பு p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_மொத்தம்(bound_ptr_add_மொத்தம்);
    எனில் (மரம்_2) {
        addr -= மரம்_2->start;
        எனில் (addr >= மரம்_2->size) {
            addr = (size_t)p;
            மரம்_2 = splay (addr, மரம்_2);
            addr -= மரம்_2->start;
        }
        எனில் (addr >= மரம்_2->size) {
            addr = (size_t)p;
            மரம்_2 = splay_end (addr, மரம்_2);
            addr -= மரம்_2->start;
        }
        எனில் (addr <= மரம்_2->size) {
            எனில் (மரம்_2->is_invalid || addr + offset > மரம்_2->size) {
                POST_SEM ();
                எனில் (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)மரம்_2->start,
                                  (long)(மரம்_2->start + மரம்_2->size - 1));
                எனில் (never_fatal <= 0)
                    திரும்பு INVALID_POINTER; /* return an invalid pointer */
                திரும்பு p + offset;
            }
        }
        இல்லையெனில் எனில் (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_மொத்தம்(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            திரும்பு p + offset;
        }
    }
    POST_SEM ();
    திரும்பு p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
வெறுமை * __bound_ptr_indir ## dsize (வெறுமை *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    எனில் (NO_CHECKING_GET())                                                     \
        திரும்பு p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_மொத்தம்(bound_ptr_indir ## dsize ## மொத்தம்);                            \
    எனில் (மரம்_2) {                                                                \
        addr -= மரம்_2->start;                                                   \
        எனில் (addr >= மரம்_2->size) {                                              \
            addr = (size_t)p;                                                  \
            மரம்_2 = splay (addr, மரம்_2);                                         \
            addr -= மரம்_2->start;                                               \
        }                                                                      \
        எனில் (addr >= மரம்_2->size) {                                              \
            addr = (size_t)p;                                                  \
            மரம்_2 = splay_end (addr, மரம்_2);                                     \
            addr -= மரம்_2->start;                                               \
        }                                                                      \
        எனில் (addr <= மரம்_2->size) {                                              \
            எனில் (மரம்_2->is_invalid || addr + offset + dsize > மரம்_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)மரம்_2->start,            \
                              (long)(மரம்_2->start + மரம்_2->size - 1));           \
                எனில் (never_fatal <= 0)                                          \
                    திரும்பு INVALID_POINTER; /* return an invalid pointer */    \
                திரும்பு p + offset;                                             \
            }                                                                  \
        }                                                                      \
        இல்லையெனில் {                                                                 \
            INCR_மொத்தம்(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            திரும்பு p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    திரும்பு p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#எனில் (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic தள்ளு
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
வெறுமை FASTCALL __bound_local_new(வெறுமை *p1) 
{
    size_t addr, fp, *p = p1;

    எனில் (NO_CHECKING_GET())
         திரும்பு;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (வெறுமை *)fp);
    WAIT_SEM ();
    போது ((addr = p[0])) {
        INCR_மொத்தம்(bound_local_new_மொத்தம்);
        மரம்_2 = splay_செருகு(addr + fp, p[1], மரம்_2);
        p += 2;
    }
    POST_SEM ();
#எனில் BOUND_DEBUG
    எனில் (print_calls) {
        p = p1;
        போது ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (வெறுமை *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
வெறுமை FASTCALL __bound_local_delete(வெறுமை *p1) 
{
    size_t addr, fp, *p = p1;

    எனில் (NO_CHECKING_GET())
         திரும்பு;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (வெறுமை *)fp);
    WAIT_SEM ();
    போது ((addr = p[0])) {
        INCR_மொத்தம்(bound_local_delete_மொத்தம்);
        மரம்_2 = splay_delete(addr + fp, மரம்_2);
        p += 2;
    }
    எனில் (alloca_list) {
        alloca_list_type *last = வெற்று;
        alloca_list_type *cur = alloca_list;

        செய் {
            எனில் (cur->fp == fp) {
                எனில் (last)
                    last->next = cur->next;
                இல்லையெனில்
                    alloca_list = cur->next;
                மரம்_2 = splay_delete ((size_t) cur->p, மரம்_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             இல்லையெனில் {
                 last = cur;
                 cur = cur->next;
             }
        } போது (cur);
    }
    எனில் (jmp_list) {
        jmp_list_type *last = வெற்று;
        jmp_list_type *cur = jmp_list;

        செய் {
            எனில் (cur->fp == fp) {
                எனில் (last)
                    last->next = cur->next;
                இல்லையெனில்
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            இல்லையெனில் {
                last = cur;
                cur = cur->next;
            }
        } போது (cur);
    }

    POST_SEM ();
#எனில் BOUND_DEBUG
    எனில் (print_calls) {
        p = p1;
        போது ((addr = p[0])) {
            எனில் (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (வெறுமை *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
வெறுமை __bound_new_region(வெறுமை *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    எனில் (NO_CHECKING_GET())
        திரும்பு;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (அளவு (alloca_list_type));
    WAIT_SEM ();
    INCR_மொத்தம்(bound_alloca_மொத்தம்);
    last = வெற்று;
    cur = alloca_list;
    போது (cur) {
#எனில் defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        முழு align = 4;
#அல்லதெனில் defined(__arm__)
        முழு align = 8;
#இல்லையெனில்
        முழு align = 16;
#endif
        வெறுமை *cure = (வெறுமை *)((எழுத்து *)cur->p + ((cur->size + align) & -align));
        வெறுமை *pe = (வெறுமை *)((எழுத்து *)p + ((size + align) & -align));
        எனில் (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            எனில் (last)
                last->next = cur->next;
            இல்லையெனில்
                alloca_list = cur->next;
            மரம்_2 = splay_delete((size_t)cur->p, மரம்_2);
            நிறுத்து;
        }
        last = cur;
        cur = cur->next;
    }
    மரம்_2 = splay_செருகு((size_t)p, size, மரம்_2);
    எனில் (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    எனில் (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

வெறுமை __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    வெறுமை *e = (வெறுமை *) env;

    எனில் (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_மொத்தம்(bound_setjmp_மொத்தம்);
        jl = jmp_list;
        போது (jl) {
            எனில் (jl->penv == e)
                நிறுத்து;
            jl = jl->next;
        }
        எனில் (jl == வெற்று) {
            jl = BOUND_MALLOC (அளவு (jmp_list_type));
            எனில் (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        எனில் (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

நிலையான வெறுமை __bound_long_jump(jmp_buf env, முழு val, முழு sig, மாறிலி எழுத்து *func)
{
    jmp_list_type *jl;
    வெறுமை *e;
    BOUND_TID_TYPE tid;

    எனில் (NO_CHECKING_GET() == 0) {
        e = (வெறுமை *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_மொத்தம்(bound_longjmp_மொத்தம்);
        jl = jmp_list;
        போது (jl) {
            எனில் (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = வெற்று;

                போது (cur->penv != e || cur->tid != tid) {
                    எனில் (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        எனில் (last)
                            last->next = cur->next;
                        இல்லையெனில்
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    இல்லையெனில் {
                        last = cur;
                        cur = cur->next;
                    }
                }
                க்கு (;;) {
                    மரம் *t = மரம்_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    போது (t && (t->start < start_fp || t->start > end_fp))
                        எனில் (t->start < start_fp)
                            t = t->வலது;
                        இல்லையெனில்
                            t = t->இடது;
                    எனில் (t == வெற்று)
                        நிறுத்து;
                    last = வெற்று;
                    cur = alloca_list;
                    போது (cur) {
                         எனில் ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             எனில் (last)
                                 last->next = cur->next;
                             இல்லையெனில்
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             நிறுத்து;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (வெறுமை *) t->start);
                    மரம்_2 = splay_delete(t->start, மரம்_2);
                }
                நிறுத்து;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#எனில் !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

வெறுமை __bound_longjmp(jmp_buf env, முழு val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#எனில் !defined(_WIN32)
வெறுமை __bound_siglongjmp(jmp_buf env, முழு val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#எனில் (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic எடு
#endif

வெறுமை __bound_init(size_t *p, முழு mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    எனில் (inited) {
        WAIT_SEM();
        செல் add_bounds;
    }
    inited = 1;

#எனில் HAVE_TLS_FUNC
#எனில் defined(_WIN32)
    no_checking_சாவி = TlsAlloc();
    Tls_Set_மதிப்பு(no_checking_சாவி, &no_checking);
#இல்லையெனில்
    pthread_key_create(&no_checking_சாவி, வெற்று);
    pthread_setspecific(no_checking_சாவி, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != வெற்று;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != வெற்று;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != வெற்று;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != வெற்று;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != வெற்று;

    INIT_SEM ();

#எனில் MALLOC_REDIR
    {
        வெறுமை *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(வெறுமை **) (&malloc_redir) = dlsym (addr, "malloc");
        எனில் (malloc_redir == வெற்று) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(வெறுமை **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(வெறுமை **) (&calloc_redir) = dlsym (addr, "calloc");
        *(வெறுமை **) (&free_redir) = dlsym (addr, "free");
        *(வெறுமை **) (&realloc_redir) = dlsym (addr, "realloc");
        *(வெறுமை **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        எனில் (malloc_redir == வெற்று || free_redir == வெற்று)
            bound_alloc_error ("Cannot redirect malloc/free");
#எனில் HAVE_PTHREAD_CREATE
        *(வெறுமை **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        எனில் (pthread_create_redir == வெற்று)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#எனில் HAVE_SIGNAL
        *(வெறுமை **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        எனில் (signal_redir == வெற்று)
            bound_alloc_error ("Cannot redirect signal");
#endif
#எனில் HAVE_SIGACTION
        *(வெறுமை **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        எனில் (sigaction_redir == வெற்று)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#எனில் HAVE_FORK
        *(வெறுமை **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        எனில் (fork_redir == வெற்று)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned எழுத்து found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        எழுத்து வரி[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        எனில் (fp) {
            memset (exec, 0, அளவு(exec));
            fread (exec, 1, அளவு(exec) - 2, fp);
            எனில் (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        எனில் (fp) {
            போது (fgets (வரி, அளவு(வரி), fp)) {
                எனில் (sscanf (வரி, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    நிறுத்து;
                }
                எனில் (strstr (வரி,"[heap]"))
                    நிறுத்து;
            }
            fclose (fp);
        }
        எனில் (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#எனில் HAVE_CTYPE
#ifdef __APPLE__
    மரம்_2 = splay_செருகு((size_t) &_DefaultRuneLocale,
                        அளவு (_DefaultRuneLocale), மரம்_2);
#இல்லையெனில்
    /* XXX: Does not work if locale is changed */
    மரம்_2 = splay_செருகு((size_t) __ctype_b_loc(),
                        அளவு (unsigned short *), மரம்_2);
    மரம்_2 = splay_செருகு((size_t) (*__ctype_b_loc() - 128),
                        384 * அளவு (unsigned short), மரம்_2);
    மரம்_2 = splay_செருகு((size_t) __ctype_tolower_loc(),
                        அளவு (__int32_t *), மரம்_2);
    மரம்_2 = splay_செருகு((size_t) (*__ctype_tolower_loc() - 128),
                        384 * அளவு (__int32_t), மரம்_2);
    மரம்_2 = splay_செருகு((size_t) __ctype_toupper_loc(),
                        அளவு (__int32_t *), மரம்_2);
    மரம்_2 = splay_செருகு((size_t) (*__ctype_toupper_loc() - 128),
                        384 * அளவு (__int32_t), மரம்_2);
#endif
#endif
#எனில் HAVE_ERRNO
    மரம்_2 = splay_செருகு((size_t) (&errno), அளவு (முழு), மரம்_2);
#endif

add_bounds:
    எனில் (!p)
        செல் no_bounds;

    /* add all static bound check values */
    போது (p[0] != 0) {
        மரம்_2 = splay_செருகு(p[0], p[1], மரம்_2);
#எனில் BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (வெறுமை *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

வெறுமை
#எனில் (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(முழு argc, எழுத்து **argv, எழுத்து **envp)
{
    __bound_init (0, -1);
    எனில் (argc && argv) {
        முழு i;

        WAIT_SEM ();
        க்கு (i = 0; i < argc; i++)
            மரம்_2 = splay_செருகு((size_t) argv[i], strlen (argv[i]) + 1, மரம்_2);
        மரம்_2 = splay_செருகு((size_t) argv, (argc + 1) * அளவு(எழுத்து *), மரம்_2);
        POST_SEM ();
#எனில் BOUND_DEBUG
        எனில் (print_calls) {
            க்கு (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (முழு)((argc + 1) * அளவு(எழுத்து *)));
        }
#endif
    }

    எனில் (envp && *envp) {
        எழுத்து **p = envp;

        WAIT_SEM ();
        போது (*p) {
            மரம்_2 = splay_செருகு((size_t) *p, strlen (*p) + 1, மரம்_2);
            ++p;
        }
        மரம்_2 = splay_செருகு((size_t) envp, (++p - envp) * அளவு(எழுத்து *), மரம்_2);
        POST_SEM ();
#எனில் BOUND_DEBUG
        எனில் (print_calls) {
            p = envp;
            போது (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (முழு)((++p - envp) * அளவு(எழுத்து *)));
        }
#endif
    }
}

வெறுமை __attribute__((destructor)) __bound_exit(வெறுமை)
{
    முழு i;
    நிலையான மாறிலி எழுத்து * மாறிலி alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    எனில் (inited) {
#எனில் !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        எனில் (print_heap) {
            வெளி வெறுமை __libc_freeres (வெறுமை);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        போது (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            மரம்_2 = splay_delete ((size_t) alloca_list->p, மரம்_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        போது (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        க்கு (i = 0; i < FREE_REUSE_SIZE; i++) {
            எனில் (free_reuse_list[i]) {
                மரம்_2 = splay_delete ((size_t) free_reuse_list[i], மரம்_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        போது (மரம்_2) {
            எனில் (print_heap && மரம்_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[மரம்_2->type],
                         (unsigned long) மரம்_2->size);
            மரம்_2 = splay_delete (மரம்_2->start, மரம்_2);
        }
#எனில் மரம்_REUSE
        போது (மரம்_free_list) {
            மரம் *next = மரம்_free_list->இடது;
            BOUND_FREE (மரம்_free_list);
            மரம்_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#எனில் HAVE_TLS_FUNC
#எனில் defined(_WIN32)
        TlsFree(no_checking_சாவி);
#இல்லையெனில்
        pthread_key_delete(no_checking_சாவி);
#endif
#endif
        inited = 0;
        எனில் (print_statistic) {
#எனில் BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_மொத்தம்);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_மொத்தம்);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_மொத்தம்);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_மொத்தம்);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_மொத்தம்);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_மொத்தம்);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_மொத்தம்);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_மொத்தம்);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_மொத்தம்);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_மொத்தம்);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_மொத்தம்);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_மொத்தம்);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_மொத்தம்);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_மொத்தம்);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_மொத்தம்);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_மொத்தம்);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_மொத்தம்);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_மொத்தம்);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_மொத்தம்);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_மொத்தம்);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_மொத்தம்);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_மொத்தம்);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_மொத்தம்);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_மொத்தம்);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_மொத்தம்);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_மொத்தம்);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_மொத்தம்);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_மொத்தம்);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#எனில் BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_செருகு);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

வெறுமை __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    எனில் (p) {
        WAIT_SEM ();
	போது (p[0] != 0) {
	    மரம்_2 = splay_delete(p[0], மரம்_2);
#எனில் BOUND_DEBUG
            எனில் (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (வெறுமை *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#எனில் HAVE_PTHREAD_CREATE
வகைவரை கட்டமைப்பு {
    வெறுமை *(*start_routine) (வெறுமை *);
    வெறுமை *arg;
    sigset_t old_mask;
} bound_thread_create_type;

நிலையான வெறுமை *bound_thread_create(வெறுமை *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    வெறுமை *retval;
#எனில் HAVE_TLS_FUNC
    முழு *p = (முழு *) BOUND_MALLOC(அளவு(முழு));
  
    எனில் (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_சாவி, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, வெற்று);
    retval = data->start_routine(data->arg);
#எனில் HAVE_TLS_FUNC
    pthread_setspecific(no_checking_சாவி, வெற்று);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    திரும்பு retval;
}

முழு pthread_create(pthread_t *thread, மாறிலி pthread_attr_t *attr,
                   வெறுமை *(*start_routine) (வெறுமை *), வெறுமை *arg)
{
    முழு retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(அளவு(bound_thread_create_type));
    எனில் (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, வெற்று);
    திரும்பு retval;
}
#endif

#எனில் HAVE_SIGNAL || HAVE_SIGACTION
வகைவரை ஒன்றிப்பு {
#எனில் HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#எனில் HAVE_SIGACTION
    வெறுமை (*sig_handler)(முழு);
    வெறுமை (*sig_sigaction)(முழு, siginfo_t *, வெறுமை *);
#endif
} bound_sig_type;

நிலையான unsigned எழுத்து bound_sig_used[NSIG];
நிலையான bound_sig_type bound_sig_data[NSIG];
#endif

#எனில் HAVE_SIGNAL
நிலையான வெறுமை signal_handler(முழு sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig சமிக்ஞை(முழு signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    எனில் (retval != SIG_ERR) {
        எனில் (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        எனில் (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    திரும்பு retval;
}
#endif

#எனில் HAVE_SIGACTION
நிலையான வெறுமை sig_handler(முழு sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

நிலையான வெறுமை sig_sigaction(முழு sig, siginfo_t *info, வெறுமை *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

முழு sigaction(முழு signum, மாறிலி கட்டமைப்பு sigaction *act, கட்டமைப்பு sigaction *oldact)
{
    முழு retval;
    கட்டமைப்பு sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    எனில் (sigaction_redir == வெற்று)
        __bound_init(0,-1);

    எனில் (act) {
        nact = *act;
        எனில் (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        இல்லையெனில்
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    இல்லையெனில்
        retval = sigaction_redir(signum, act, &oact);
    எனில் (retval >= 0) {
        எனில் (bound_sig_used[signum]) {
            எனில் (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            இல்லையெனில்
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        எனில் (oldact) {
            *oldact = oact;
        }
        எனில் (act) {
            bound_sig_used[signum] = 1;
            எனில் (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            இல்லையெனில்
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    திரும்பு retval;
}
#endif

#எனில் HAVE_FORK
pid_t fork(வெறுமை)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    எனில் (retval == 0)
        INIT_SEM();
    இல்லையெனில்
        POST_SEM();
    திரும்பு retval;
}
#endif

#எனில் MALLOC_REDIR
வெறுமை *malloc(size_t size)
#இல்லையெனில்
வெறுமை *__bound_malloc(size_t size, மாறிலி வெறுமை *caller)
#endif
{
    வெறுமை *ptr;
    
#எனில் MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    எனில் (malloc_redir == வெற்று) {
        __bound_init (0, -1);
        எனில் (malloc_redir == வெற்று) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            எனில் (pool_index >= அளவு (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            திரும்பு ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    எனில் (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_malloc_மொத்தம்);

        எனில் (ptr) {
            மரம்_2 = splay_செருகு ((size_t) ptr, size ? size : size + 1, மரம்_2);
            எனில் (மரம்_2 && மரம்_2->start == (size_t) ptr)
                மரம்_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    திரும்பு ptr;
}

#எனில் MALLOC_REDIR
வெறுமை *memalign(size_t align, size_t size)
#இல்லையெனில்
வெறுமை *__bound_memalign(size_t align, size_t size, மாறிலி வெறுமை *caller)
#endif
{
    வெறுமை *ptr;

#எனில் HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#இல்லையெனில்
    எனில் (align > 4) {
        /* XXX: handle it ? */
        ptr = வெற்று;
    } இல்லையெனில் {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    எனில் (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_memalign_மொத்தம்);

        எனில் (ptr) {
            மரம்_2 = splay_செருகு((size_t) ptr, size ? size : size + 1, மரம்_2);
            எனில் (மரம்_2 && மரம்_2->start == (size_t) ptr)
                மரம்_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    திரும்பு ptr;
}

#எனில் MALLOC_REDIR
வெறுமை விடுவி(வெறுமை *ptr)
#இல்லையெனில்
வெறுமை __bound_free(வெறுமை *ptr, மாறிலி வெறுமை *caller)
#endif
{
    size_t addr = (size_t) ptr;
    வெறுமை *p;

    எனில் (ptr == வெற்று || மரம்_2 == வெற்று
#எனில் MALLOC_REDIR
        || ((unsigned எழுத்து *) ptr >= &initial_pool[0] &&
            (unsigned எழுத்து *) ptr < &initial_pool[அளவு(initial_pool)])
#endif
        )
        திரும்பு;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    எனில் (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_free_மொத்தம்);
        மரம்_2 = splay (addr, மரம்_2);
        எனில் (மரம்_2->start == addr) {
            எனில் (மரம்_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                திரும்பு;
            }
            மரம்_2->is_invalid = 1;
            memset (ptr, 0x5a, மரம்_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            எனில் (p)
                மரம்_2 = splay_delete((size_t)p, மரம்_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#எனில் MALLOC_REDIR
வெறுமை *realloc(வெறுமை *ptr, size_t size)
#இல்லையெனில்
வெறுமை *__bound_realloc(வெறுமை *ptr, size_t size, மாறிலி வெறுமை *caller)
#endif
{
    வெறுமை *new_ptr;

    எனில் (size == 0) {
#எனில் MALLOC_REDIR
        விடுவி(ptr);
#இல்லையெனில்
        __bound_free(ptr, caller);
#endif
        திரும்பு வெற்று;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    எனில் (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_realloc_மொத்தம்);

        எனில் (ptr)
            மரம்_2 = splay_delete ((size_t) ptr, மரம்_2);
        எனில் (new_ptr) {
            மரம்_2 = splay_செருகு ((size_t) new_ptr, size ? size : size + 1, மரம்_2);
            எனில் (மரம்_2 && மரம்_2->start == (size_t) new_ptr)
                மரம்_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    திரும்பு new_ptr;
}

#எனில் MALLOC_REDIR
வெறுமை *calloc(size_t nmemb, size_t size)
#இல்லையெனில்
வெறுமை *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    வெறுமை *ptr;

    size *= nmemb;
#எனில் MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    எனில் (malloc_redir == வெற்று) {
        __bound_init (0, -1);
        எனில் (malloc_redir == வெற்று) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            எனில் (pool_index >= அளவு (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            திரும்பு ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    எனில் (ptr) {
        memset (ptr, 0, size);
        எனில் (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_மொத்தம்(bound_calloc_மொத்தம்);
            மரம்_2 = splay_செருகு ((size_t) ptr, size ? size : size + 1, மரம்_2);
            எனில் (மரம்_2 && மரம்_2->start == (size_t) ptr)
                மரம்_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    திரும்பு ptr;
}

#எனில் !defined(_WIN32)
வெறுமை *__bound_mmap (வெறுமை *start, size_t size, முழு prot,
                    முழு flags, முழு fd, off_t offset)
{
    வெறுமை *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    எனில் (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_mmap_மொத்தம்);
        மரம்_2 = splay_செருகு((size_t)result, size, மரம்_2);
        POST_SEM ();
    }
    திரும்பு result;
}

முழு __bound_munmap (வெறுமை *start, size_t size)
{
    முழு result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    எனில் (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_மொத்தம்(bound_munmap_மொத்தம்);
        மரம்_2 = splay_delete ((size_t) start, மரம்_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    திரும்பு result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
நிலையான வெறுமை __bound_check(மாறிலி வெறுமை *p, size_t size, மாறிலி எழுத்து *function)
{
    எனில் (size != 0 && __bound_ptr_add((வெறுமை *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

நிலையான முழு check_overlap (மாறிலி வெறுமை *p1, size_t n1,
                          மாறிலி வெறுமை *p2, size_t n2,
                          மாறிலி எழுத்து *function)
{
    மாறிலி வெறுமை *p1e = (மாறிலி வெறுமை *) ((மாறிலி எழுத்து *) p1 + n1);
    மாறிலி வெறுமை *p2e = (மாறிலி வெறுமை *) ((மாறிலி எழுத்து *) p2 + n2);

    எனில் (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        திரும்பு never_fatal < 0;
    }
    திரும்பு 0;
}

வெறுமை *__bound_memcpy(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_mempcy_மொத்தம்);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    எனில் (check_overlap(dest, n, src, n, "memcpy"))
        திரும்பு dest;
    திரும்பு memcpy(dest, src, n);
}

முழு __bound_memcmp(மாறிலி வெறுமை *s1, மாறிலி வெறுமை *s2, size_t n)
{
    மாறிலி unsigned எழுத்து *u1 = (மாறிலி unsigned எழுத்து *) s1;
    மாறிலி unsigned எழுத்து *u2 = (மாறிலி unsigned எழுத்து *) s2;
    முழு retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_மொத்தம்(bound_memcmp_மொத்தம்);
    க்கு (;;) {
        எனில் ((ssize_t) --n == -1)
            நிறுத்து;
        இல்லையெனில் எனில் (*u1 != *u2) {
            retval = *u1++ - *u2++;
            நிறுத்து;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (மாறிலி வெறுமை *)u1 - s1, "memcmp s1");
    __bound_check(s2, (மாறிலி வெறுமை *)u2 - s2, "memcmp s2");
    திரும்பு retval;
}

வெறுமை *__bound_memmove(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_memmove_மொத்தம்);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    திரும்பு memmove(dest, src, n);
}

வெறுமை *__bound_memset(வெறுமை *s, முழு c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_மொத்தம்(bound_memset_மொத்தம்);
    __bound_check(s, n, "memset");
    திரும்பு memset(s, c, n);
}

#எனில் defined(__arm__) && defined(__ARM_EABI__)
வெறுமை *__bound___aeabi_memcpy(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_mempcy_மொத்தம்);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    எனில் (check_overlap(dest, n, src, n, "memcpy"))
        திரும்பு dest;
    திரும்பு __aeabi_memcpy(dest, src, n);
}

வெறுமை *__bound___aeabi_memmove(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_memmove_மொத்தம்);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    திரும்பு __aeabi_memmove(dest, src, n);
}

வெறுமை *__bound___aeabi_memmove4(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_memmove_மொத்தம்);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    திரும்பு __aeabi_memmove4(dest, src, n);
}

வெறுமை *__bound___aeabi_memmove8(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_memmove_மொத்தம்);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    திரும்பு __aeabi_memmove8(dest, src, n);
}

வெறுமை *__bound___aeabi_memset(வெறுமை *s, முழு c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_மொத்தம்(bound_memset_மொத்தம்);
    __bound_check(s, n, "memset");
    திரும்பு __aeabi_memset(s, c, n);
}
#endif

முழு __bound_strlen(மாறிலி எழுத்து *s)
{
    மாறிலி எழுத்து *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_மொத்தம்(bound_strlen_மொத்தம்);
    போது (*p++);
    __bound_check(s, p - s, "strlen");
    திரும்பு (p - s) - 1;
}

எழுத்து *__bound_strcpy(எழுத்து *dest, மாறிலி எழுத்து *src)
{
    size_t len;
    மாறிலி எழுத்து *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_மொத்தம்(bound_strcpy_மொத்தம்);
    போது (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    எனில் (check_overlap(dest, len, src, len, "strcpy"))
        திரும்பு dest;
    திரும்பு strcpy (dest, src);
}

எழுத்து *__bound_strncpy(எழுத்து *dest, மாறிலி எழுத்து *src, size_t n)
{
    size_t len = n;
    மாறிலி எழுத்து *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_strncpy_மொத்தம்);
    போது (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    எனில் (check_overlap(dest, len, src, len, "strncpy"))
        திரும்பு dest;
    திரும்பு strncpy(dest, src, n);
}

முழு __bound_strcmp(மாறிலி எழுத்து *s1, மாறிலி எழுத்து *s2)
{
    மாறிலி unsigned எழுத்து *u1 = (மாறிலி unsigned எழுத்து *) s1;
    மாறிலி unsigned எழுத்து *u2 = (மாறிலி unsigned எழுத்து *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_மொத்தம்(bound_strcmp_மொத்தம்);
    போது (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((மாறிலி எழுத்து *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((மாறிலி எழுத்து *)u2 - s2) + 1, "strcmp s2");
    திரும்பு *u1 - *u2;
}

முழு __bound_strncmp(மாறிலி எழுத்து *s1, மாறிலி எழுத்து *s2, size_t n)
{
    மாறிலி unsigned எழுத்து *u1 = (மாறிலி unsigned எழுத்து *) s1;
    மாறிலி unsigned எழுத்து *u2 = (மாறிலி unsigned எழுத்து *) s2;
    முழு retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_மொத்தம்(bound_strncmp_மொத்தம்);
    செய் {
        எனில் ((ssize_t) --n == -1)
            நிறுத்து;
        இல்லையெனில் எனில் (*u1 != *u2) {
            retval = *u1++ - *u2++;
            நிறுத்து;
        }
        ++u2;
    } போது (*u1++);
    __bound_check(s1, (மாறிலி எழுத்து *)u1 - s1, "strncmp s1");
    __bound_check(s2, (மாறிலி எழுத்து *)u2 - s2, "strncmp s2");
    திரும்பு retval;
}

எழுத்து *__bound_strcat(எழுத்து *dest, மாறிலி எழுத்து *src)
{
    எழுத்து *r = dest;
    மாறிலி எழுத்து *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_மொத்தம்(bound_strcat_மொத்தம்);
    போது (*dest++);
    போது (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    எனில் (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        திரும்பு dest;
    திரும்பு strcat(r, s);
}

எழுத்து *__bound_strncat(எழுத்து *dest, மாறிலி எழுத்து *src, size_t n)
{
    எழுத்து *r = dest;
    மாறிலி எழுத்து *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_மொத்தம்(bound_strncat_மொத்தம்);
    போது (*dest++);
    போது (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    எனில் (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        திரும்பு dest;
    திரும்பு strncat(r, s, n);
}

எழுத்து *__bound_strchr(மாறிலி எழுத்து *s, முழு c)
{
    மாறிலி unsigned எழுத்து *str = (மாறிலி unsigned எழுத்து *) s;
    unsigned எழுத்து ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_மொத்தம்(bound_strchr_மொத்தம்);
    போது (*str) {
        எனில் (*str == ch)
            நிறுத்து;
        ++str;
    }
    __bound_check(s, ((மாறிலி எழுத்து *)str - s) + 1, "strchr");
    திரும்பு *str == ch ? (எழுத்து *) str : வெற்று;
}

எழுத்து *__bound_strrchr(மாறிலி எழுத்து *s, முழு c)
{
    மாறிலி unsigned எழுத்து *str = (மாறிலி unsigned எழுத்து *) s;
    unsigned எழுத்து ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_மொத்தம்(bound_strrchr_மொத்தம்);
    போது (*str++);
    __bound_check(s, (மாறிலி எழுத்து *)str - s, "strrchr");
    போது (str != (மாறிலி unsigned எழுத்து *)s) {
        எனில் (*--str == ch)
            நிறுத்து;
    }
    __bound_check(s, (மாறிலி எழுத்து *)str - s, "strrchr");
    திரும்பு *str == ch ? (எழுத்து *) str : வெற்று;
}

எழுத்து *__bound_strdup(மாறிலி எழுத்து *s)
{
    மாறிலி எழுத்து *p = s;
    எழுத்து *new;

    INCR_மொத்தம்(bound_strdup_மொத்தம்);
    போது (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    எனில் (new) {
        எனில் (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            மரம்_2 = splay_செருகு((size_t)new, p - s, மரம்_2);
            எனில் (மரம்_2 && மரம்_2->start == (size_t) new)
                மரம்_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    திரும்பு new;
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

நிலையான மரம் * splay (size_t addr, மரம் *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    மரம் N, *l, *r, *y;
    முழு comp;
    
    INCR_மொத்தம்_SPLAY(bound_splay);
    எனில் (t == வெற்று) திரும்பு t;
    N.இடது = N.வலது = வெற்று;
    l = r = &N;
 
    க்கு (;;) {
        comp = compare(addr, t->start, t->size);
        எனில் (comp < 0) {
            y = t->இடது;
            எனில் (y == வெற்று) நிறுத்து;
            எனில் (compare(addr, y->start, y->size) < 0) {
                t->இடது = y->வலது;                    /* rotate right */
                y->வலது = t;
                t = y;
                எனில் (t->இடது == வெற்று) நிறுத்து;
            }
            r->இடது = t;                               /* link right */
            r = t;
            t = t->இடது;
        } இல்லையெனில் எனில் (comp > 0) {
            y = t->வலது;
            எனில் (y == வெற்று) நிறுத்து;
            எனில் (compare(addr, y->start, y->size) > 0) {
                t->வலது = y->இடது;                    /* rotate left */
                y->இடது = t;
                t = y;
                எனில் (t->வலது == வெற்று) நிறுத்து;
            }
            l->வலது = t;                              /* link left */
            l = t;
            t = t->வலது;
        } இல்லையெனில் {
            நிறுத்து;
        }
    }
    l->வலது = t->இடது;                                /* assemble */
    r->இடது = t->வலது;
    t->இடது = N.வலது;
    t->வலது = N.இடது;

    திரும்பு t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

நிலையான மரம் * splay_end (size_t addr, மரம் *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    மரம் N, *l, *r, *y;
    முழு comp;
    
    INCR_மொத்தம்_SPLAY(bound_splay_end);
    எனில் (t == வெற்று) திரும்பு t;
    N.இடது = N.வலது = வெற்று;
    l = r = &N;
 
    க்கு (;;) {
        comp = compare_end(addr, t->start + t->size);
        எனில் (comp < 0) {
            y = t->இடது;
            எனில் (y == வெற்று) நிறுத்து;
            எனில் (compare_end(addr, y->start + y->size) < 0) {
                t->இடது = y->வலது;                    /* rotate right */
                y->வலது = t;
                t = y;
                எனில் (t->இடது == வெற்று) நிறுத்து;
            }
            r->இடது = t;                               /* link right */
            r = t;
            t = t->இடது;
        } இல்லையெனில் எனில் (comp > 0) {
            y = t->வலது;
            எனில் (y == வெற்று) நிறுத்து;
            எனில் (compare_end(addr, y->start + y->size) > 0) {
                t->வலது = y->இடது;                    /* rotate left */
                y->இடது = t;
                t = y;
                எனில் (t->வலது == வெற்று) நிறுத்து;
            }
            l->வலது = t;                              /* link left */
            l = t;
            t = t->வலது;
        } இல்லையெனில் {
            நிறுத்து;
        }
    }
    l->வலது = t->இடது;                                /* assemble */
    r->இடது = t->வலது;
    t->இடது = N.வலது;
    t->வலது = N.இடது;

    திரும்பு t;
}

நிலையான மரம் * splay_செருகு(size_t addr, size_t size, மரம் * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    மரம் * new;

    INCR_மொத்தம்_SPLAY(bound_splay_செருகு);
    எனில் (t != வெற்று) {
        t = splay(addr,t);
        எனில் (compare(addr, t->start, t->size)==0) {
            திரும்பு t;  /* it's already there */
        }
    }
#எனில் மரம்_REUSE
    எனில் (மரம்_free_list) {
          new = மரம்_free_list;
          மரம்_free_list = new->இடது;
    }
    இல்லையெனில்
#endif
    {
        new = (மரம் *) BOUND_MALLOC (அளவு (மரம்));
    }
    எனில் (new == வெற்று) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    இல்லையெனில் {
        எனில் (t == வெற்று) {
            new->இடது = new->வலது = வெற்று;
        } இல்லையெனில் எனில் (compare(addr, t->start, t->size) < 0) {
            new->இடது = t->இடது;
            new->வலது = t;
            t->இடது = வெற்று;
        } இல்லையெனில் {
            new->வலது = t->வலது;
            new->இடது = t;
            t->வலது = வெற்று;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    திரும்பு new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

நிலையான மரம் * splay_delete(size_t addr, மரம் *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    மரம் * x;

    INCR_மொத்தம்_SPLAY(bound_splay_delete);
    எனில் (t==வெற்று) திரும்பு வெற்று;
    t = splay(addr,t);
    எனில் (compare_destroy(addr, t->start) == 0) {        /* found it */
        எனில் (t->இடது == வெற்று) {
            x = t->வலது;
        } இல்லையெனில் {
            x = splay(addr, t->இடது);
            x->வலது = t->வலது;
        }
#எனில் மரம்_REUSE
        t->இடது = மரம்_free_list;
        மரம்_free_list = t;
#இல்லையெனில்
        BOUND_FREE(t);
#endif
        திரும்பு x;
    } இல்லையெனில் {
        திரும்பு t;                                      /* It wasn't there */
    }
}

வெறுமை splay_printtree(மரம் * t, முழு d)
{
    முழு i;
    எனில் (t == வெற்று) திரும்பு;
    splay_printtree(t->வலது, d+1);
    க்கு (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (வெறுமை *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->இடது, d+1);
}
