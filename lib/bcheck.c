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
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdarg.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#अन्तर्भाव <stdatomic.h>

#जइ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#अन्तर्भाव <malloc.h>
#endif

#जइ !defined(_WIN32)
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/syscall.h>
#endif

#अन्तर्भाव "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#जइ BOUND_DEBUG
 #define dprintf(a...)         जइ (print_calls) { bounds_loc(a); }
#अण्णहा
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#अण्णहा
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अण्णहा
# define DLL_EXPORT
#endif

#जइ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#अन्तर्भाव <sys/mman.h>
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

#नोचेद्यदि defined(_WIN32)

#अन्तर्भाव <windows.h>
#अन्तर्भाव <signal.h>
स्थिर CRITICAL_SECTION bounds_sem;
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

#अण्णहा

#define __USE_GNU              /* get RTLD_NEXT */
#अन्तर्भाव <sys/mman.h>
#अन्तर्भाव <ctype.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <dlfcn.h>
#अन्तर्भाव <errno.h>
#अन्तर्भाव <signal.h>
#ifdef __APPLE__
#अन्तर्भाव <dispatch/dispatch.h>
स्थिर dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             जइ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             जइ (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              जइ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#नोचेद्यदि 0
#अन्तर्भाव <semaphore.h>
स्थिर sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             जइ (use_sem) जाव (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             जइ (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              जइ (use_sem) जाव (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#नोचेद्यदि 0
स्थिर pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, रिक्त)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             जइ (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             जइ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              जइ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#अण्णहा
स्थिर pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             जइ (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             जइ (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              जइ (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#जइ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#अण्णहा
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#जइ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#जइ MALLOC_REDIR
स्थिर शून्य *(*malloc_redir) (size_t);
स्थिर शून्य *(*calloc_redir) (size_t, size_t);
स्थिर शून्य (*free_redir) (शून्य *);
स्थिर शून्य *(*realloc_redir) (शून्य *, size_t);
स्थिर unsigned पूर्णाङ्क pool_index;
स्थिर unsigned वर्ण __attribute__((aligned(16))) initial_pool[256];
#endif
#जइ HAVE_MEMALIGN
स्थिर शून्य *(*memalign_redir) (size_t, size_t);
#endif
#जइ HAVE_PTHREAD_CREATE
स्थिर पूर्णाङ्क (*pthread_create_redir) (pthread_t *thread,
                                    ध्रुव pthread_attr_t *attr,
                                    शून्य *(*start_routine)(शून्य *), शून्य *arg);
#endif
#जइ HAVE_SIGNAL
प्रकारनिर्देश शून्य (*bound_sig)(पूर्णाङ्क);
स्थिर bound_sig (*signal_redir) (पूर्णाङ्क signum, bound_sig handler);
#endif
#जइ HAVE_SIGACTION
स्थिर पूर्णाङ्क (*sigaction_redir) (पूर्णाङ्क signum, ध्रुव संरचना sigaction *act,
                               संरचना sigaction *oldact);
#endif
#जइ HAVE_FORK
स्थिर पूर्णाङ्क (*fork_redir) (शून्य);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((शून्य *)(-2))

प्रकारनिर्देश संरचना वृक्ष_ग्रन्थिः वृक्षः;
संरचना वृक्ष_ग्रन्थिः {
    वृक्षः * वामः, * दक्षिणः;
    size_t start;
    size_t size;
    unsigned वर्ण type;
    unsigned वर्ण is_invalid; /* true if pointers outside region are invalid */
};

प्रकारनिर्देश संरचना alloca_list_struct {
    size_t fp;
    शून्य *p;
    size_t size;
    संरचना alloca_list_struct *next;
} alloca_list_type;

#जइ defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#नोचेद्यदि defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#नोचेद्यदि defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#नोचेद्यदि  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#नोचेद्यदि defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#अण्णहा
#define BOUND_TID_TYPE		पूर्णाङ्क
#define BOUND_GET_TID(id)	id = 0
#endif

प्रकारनिर्देश संरचना jmp_list_struct {
    शून्य *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    संरचना jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
स्थिर वृक्षः * splay (size_t addr, वृक्षः *t);
स्थिर वृक्षः * splay_end (size_t addr, वृक्षः *t);
स्थिर वृक्षः * splay_निवेशय(size_t addr, size_t size, वृक्षः * t);
स्थिर वृक्षः * splay_delete(size_t addr, वृक्षः *t);
शून्य splay_printtree(वृक्षः * t, पूर्णाङ्क d);

/* external interface */
शून्य __bounds_checking (पूर्णाङ्क no_check);
शून्य __bound_checking_lock (शून्य);
शून्य __bound_checking_unlock (शून्य);
शून्य __bound_never_fatal (पूर्णाङ्क no_check);
DLL_EXPORT शून्य * __bound_ptr_add(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir1(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir2(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir4(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir8(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir12(शून्य *p, size_t offset);
DLL_EXPORT शून्य * __bound_ptr_indir16(शून्य *p, size_t offset);
DLL_EXPORT शून्य FASTCALL __bound_local_new(शून्य *p1);
DLL_EXPORT शून्य FASTCALL __bound_local_delete(शून्य *p1);
शून्य __bound_init(size_t *, पूर्णाङ्क);
शून्य __bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
शून्य __bound_exit(शून्य);
शून्य __bound_exit_dll(size_t *);
#जइ !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, size_t size, पूर्णाङ्क prot, पूर्णाङ्क flags, पूर्णाङ्क fd,
                    off_t offset);
पूर्णाङ्क __bound_munmap (शून्य *start, size_t size);
DLL_EXPORT शून्य __bound_siglongjmp(jmp_buf env, पूर्णाङ्क val);
#endif
DLL_EXPORT शून्य __bound_new_region(शून्य *p, size_t size);
DLL_EXPORT शून्य __bound_setjmp(jmp_buf env);
DLL_EXPORT शून्य __bound_longjmp(jmp_buf env, पूर्णाङ्क val);
DLL_EXPORT शून्य *__bound_memcpy(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, size_t size);
DLL_EXPORT शून्य *__bound_memmove(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__bound_memset(शून्य *dst, पूर्णाङ्क c, size_t size);
DLL_EXPORT पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s);
DLL_EXPORT वर्ण *__bound_strcpy(वर्ण *dst, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncpy(वर्ण *dst, ध्रुव वर्ण *src, size_t n);
DLL_EXPORT पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2);
DLL_EXPORT पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, size_t n);
DLL_EXPORT वर्ण *__bound_strcat(वर्ण *dest, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, size_t n);
DLL_EXPORT वर्ण *__bound_strchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strrchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strdup(ध्रुव वर्ण *s);

#जइ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT शून्य *__bound___aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__bound___aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__bound___aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__bound___aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__bound___aeabi_memset(शून्य *dst, पूर्णाङ्क c, size_t size);
DLL_EXPORT शून्य *__aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, size_t size);
DLL_EXPORT शून्य *__aeabi_memset(शून्य *dst, पूर्णाङ्क c, size_t size);
#endif

#जइ MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#अण्णहा
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            मुक्त(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT शून्य *__bound_malloc(size_t size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_memalign(size_t align, size_t size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_realloc(शून्य *ptr, size_t size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
स्थिर unsigned पूर्णाङ्क free_reuse_index;
स्थिर शून्य *free_reuse_list[FREE_REUSE_SIZE];

स्थिर वृक्षः *वृक्षः_2 = रिक्त;
#define वृक्षः_REUSE      (1)
#जइ वृक्षः_REUSE
स्थिर वृक्षः *वृक्षः_free_list;
#endif
स्थिर alloca_list_type *alloca_list;
स्थिर jmp_list_type *jmp_list;

स्थिर unsigned वर्ण inited;
स्थिर unsigned वर्ण print_warn_ptr_add;
स्थिर unsigned वर्ण print_calls;
स्थिर unsigned वर्ण print_heap;
स्थिर unsigned वर्ण print_statistic;
स्थिर unsigned वर्ण no_strdup;
स्थिर unsigned वर्ण use_sem;
स्थिर _Atomic पूर्णाङ्क never_fatal;
#जइ HAVE_TLS_FUNC
#जइ defined(_WIN32)
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर DWORD no_checking_कुञ्चिका;
#define NO_CHECKING_CHECK() जइ (!p) {                                         \
                                  p = (पूर्णाङ्क *) LocalAlloc(LPTR, परिमाण(पूर्णाङ्क));  \
                                  जइ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_मानम्(no_checking_कुञ्चिका, p);            \
                            }
#define NO_CHECKING_GET()   ({ पूर्णाङ्क *p = Tls_Get_मानम्(no_checking_कुञ्चिका);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णाङ्क *p = Tls_Get_मानम्(no_checking_कुञ्चिका);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#अण्णहा
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर pthread_key_t no_checking_कुञ्चिका;
#define NO_CHECKING_CHECK() जइ (!p) {                                         \
                                  p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));      \
                                  जइ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_कुञ्चिका, p);    \
                            }
#define NO_CHECKING_GET()   ({ पूर्णाङ्क *p = pthread_getspecific(no_checking_कुञ्चिका); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णाङ्क *p = pthread_getspecific(no_checking_कुञ्चिका);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#नोचेद्यदि HAVE_TLS_VAR
स्थिर __thread पूर्णाङ्क no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#अण्णहा
स्थिर _Atomic पूर्णाङ्क no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
स्थिर वर्ण exec[100];

#जइ BOUND_STATISTIC
स्थिर unsigned long long bound_ptr_add_गणनम्;
स्थिर unsigned long long bound_ptr_indir1_गणनम्;
स्थिर unsigned long long bound_ptr_indir2_गणनम्;
स्थिर unsigned long long bound_ptr_indir4_गणनम्;
स्थिर unsigned long long bound_ptr_indir8_गणनम्;
स्थिर unsigned long long bound_ptr_indir12_गणनम्;
स्थिर unsigned long long bound_ptr_indir16_गणनम्;
स्थिर unsigned long long bound_local_new_गणनम्;
स्थिर unsigned long long bound_local_delete_गणनम्;
स्थिर unsigned long long bound_malloc_गणनम्;
स्थिर unsigned long long bound_calloc_गणनम्;
स्थिर unsigned long long bound_realloc_गणनम्;
स्थिर unsigned long long bound_free_गणनम्;
स्थिर unsigned long long bound_memalign_गणनम्;
स्थिर unsigned long long bound_mmap_गणनम्;
स्थिर unsigned long long bound_munmap_गणनम्;
स्थिर unsigned long long bound_alloca_गणनम्;
स्थिर unsigned long long bound_setjmp_गणनम्;
स्थिर unsigned long long bound_longjmp_गणनम्;
स्थिर unsigned long long bound_mempcy_गणनम्;
स्थिर unsigned long long bound_memcmp_गणनम्;
स्थिर unsigned long long bound_memmove_गणनम्;
स्थिर unsigned long long bound_memset_गणनम्;
स्थिर unsigned long long bound_strlen_गणनम्;
स्थिर unsigned long long bound_strcpy_गणनम्;
स्थिर unsigned long long bound_strncpy_गणनम्;
स्थिर unsigned long long bound_strcmp_गणनम्;
स्थिर unsigned long long bound_strncmp_गणनम्;
स्थिर unsigned long long bound_strcat_गणनम्;
स्थिर unsigned long long bound_strncat_गणनम्;
स्थिर unsigned long long bound_strchr_गणनम्;
स्थिर unsigned long long bound_strrchr_गणनम्;
स्थिर unsigned long long bound_strdup_गणनम्;
स्थिर unsigned long long bound_not_found;
#define INCR_गणनम्(x)          ++x
#अण्णहा
#define INCR_गणनम्(x)
#endif
#जइ BOUND_STATISTIC_SPLAY
स्थिर unsigned long long bound_splay;
स्थिर unsigned long long bound_splay_end;
स्थिर unsigned long long bound_splay_निवेशय;
स्थिर unsigned long long bound_splay_delete;
#define INCR_गणनम्_SPLAY(x)    ++x
#अण्णहा
#define INCR_गणनम्_SPLAY(x)
#endif

पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    करेहि {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } जाव (0)

#define bound_error(...)            \
    करेहि {                            \
        bound_warning(__VA_ARGS__); \
        जइ (never_fatal == 0)       \
            exit(255);              \
    } जाव (0)

#define bounds_loc(fp, ...) \
    करेहि {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } जाव (0)

स्थिर शून्य bound_alloc_error(ध्रुव वर्ण *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

स्थिर शून्य bound_not_found_warning(ध्रुव वर्ण *file, ध्रुव वर्ण *function,
                                    शून्य *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
शून्य __bounds_checking (पूर्णाङ्क no_check)
{
#जइ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#अण्णहा
    atomic_fetch_add (&no_checking, no_check);
#endif
}

शून्य __bound_checking_lock(शून्य)
{
    WAIT_SEM ();
}

शून्य __bound_checking_unlock(शून्य)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
शून्य __bound_never_fatal (पूर्णाङ्क neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
शून्य * __bound_ptr_add(शून्य *p, size_t offset)
{
    size_t addr = (size_t)p;

    जइ (NO_CHECKING_GET())
        प्रत्यागम p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_गणनम्(bound_ptr_add_गणनम्);
    जइ (वृक्षः_2) {
        addr -= वृक्षः_2->start;
        जइ (addr >= वृक्षः_2->size) {
            addr = (size_t)p;
            वृक्षः_2 = splay (addr, वृक्षः_2);
            addr -= वृक्षः_2->start;
        }
        जइ (addr >= वृक्षः_2->size) {
            addr = (size_t)p;
            वृक्षः_2 = splay_end (addr, वृक्षः_2);
            addr -= वृक्षः_2->start;
        }
        जइ (addr <= वृक्षः_2->size) {
            जइ (वृक्षः_2->is_invalid || addr + offset > वृक्षः_2->size) {
                POST_SEM ();
                जइ (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)वृक्षः_2->start,
                                  (long)(वृक्षः_2->start + वृक्षः_2->size - 1));
                जइ (never_fatal <= 0)
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */
                प्रत्यागम p + offset;
            }
        }
        अण्णहा जइ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_गणनम्(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            प्रत्यागम p + offset;
        }
    }
    POST_SEM ();
    प्रत्यागम p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
शून्य * __bound_ptr_indir ## dsize (शून्य *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    जइ (NO_CHECKING_GET())                                                     \
        प्रत्यागम p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_गणनम्(bound_ptr_indir ## dsize ## गणनम्);                            \
    जइ (वृक्षः_2) {                                                                \
        addr -= वृक्षः_2->start;                                                   \
        जइ (addr >= वृक्षः_2->size) {                                              \
            addr = (size_t)p;                                                  \
            वृक्षः_2 = splay (addr, वृक्षः_2);                                         \
            addr -= वृक्षः_2->start;                                               \
        }                                                                      \
        जइ (addr >= वृक्षः_2->size) {                                              \
            addr = (size_t)p;                                                  \
            वृक्षः_2 = splay_end (addr, वृक्षः_2);                                     \
            addr -= वृक्षः_2->start;                                               \
        }                                                                      \
        जइ (addr <= वृक्षः_2->size) {                                              \
            जइ (वृक्षः_2->is_invalid || addr + offset + dsize > वृक्षः_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)वृक्षः_2->start,            \
                              (long)(वृक्षः_2->start + वृक्षः_2->size - 1));           \
                जइ (never_fatal <= 0)                                          \
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */    \
                प्रत्यागम p + offset;                                             \
            }                                                                  \
        }                                                                      \
        अण्णहा {                                                                 \
            INCR_गणनम्(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            प्रत्यागम p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    प्रत्यागम p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#जइ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic प्रक्षिप
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
शून्य FASTCALL __bound_local_new(शून्य *p1) 
{
    size_t addr, fp, *p = p1;

    जइ (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    जाव ((addr = p[0])) {
        INCR_गणनम्(bound_local_new_गणनम्);
        वृक्षः_2 = splay_निवेशय(addr + fp, p[1], वृक्षः_2);
        p += 2;
    }
    POST_SEM ();
#जइ BOUND_DEBUG
    जइ (print_calls) {
        p = p1;
        जाव ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (शून्य *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
शून्य FASTCALL __bound_local_delete(शून्य *p1) 
{
    size_t addr, fp, *p = p1;

    जइ (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    जाव ((addr = p[0])) {
        INCR_गणनम्(bound_local_delete_गणनम्);
        वृक्षः_2 = splay_delete(addr + fp, वृक्षः_2);
        p += 2;
    }
    जइ (alloca_list) {
        alloca_list_type *last = रिक्त;
        alloca_list_type *cur = alloca_list;

        करेहि {
            जइ (cur->fp == fp) {
                जइ (last)
                    last->next = cur->next;
                अण्णहा
                    alloca_list = cur->next;
                वृक्षः_2 = splay_delete ((size_t) cur->p, वृक्षः_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             अण्णहा {
                 last = cur;
                 cur = cur->next;
             }
        } जाव (cur);
    }
    जइ (jmp_list) {
        jmp_list_type *last = रिक्त;
        jmp_list_type *cur = jmp_list;

        करेहि {
            जइ (cur->fp == fp) {
                जइ (last)
                    last->next = cur->next;
                अण्णहा
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            अण्णहा {
                last = cur;
                cur = cur->next;
            }
        } जाव (cur);
    }

    POST_SEM ();
#जइ BOUND_DEBUG
    जइ (print_calls) {
        p = p1;
        जाव ((addr = p[0])) {
            जइ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
शून्य __bound_new_region(शून्य *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    जइ (NO_CHECKING_GET())
        प्रत्यागम;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (परिमाण (alloca_list_type));
    WAIT_SEM ();
    INCR_गणनम्(bound_alloca_गणनम्);
    last = रिक्त;
    cur = alloca_list;
    जाव (cur) {
#जइ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        पूर्णाङ्क align = 4;
#नोचेद्यदि defined(__arm__)
        पूर्णाङ्क align = 8;
#अण्णहा
        पूर्णाङ्क align = 16;
#endif
        शून्य *cure = (शून्य *)((वर्ण *)cur->p + ((cur->size + align) & -align));
        शून्य *pe = (शून्य *)((वर्ण *)p + ((size + align) & -align));
        जइ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            जइ (last)
                last->next = cur->next;
            अण्णहा
                alloca_list = cur->next;
            वृक्षः_2 = splay_delete((size_t)cur->p, वृक्षः_2);
            भङ्ग;
        }
        last = cur;
        cur = cur->next;
    }
    वृक्षः_2 = splay_निवेशय((size_t)p, size, वृक्षः_2);
    जइ (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    जइ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

शून्य __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    शून्य *e = (शून्य *) env;

    जइ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_गणनम्(bound_setjmp_गणनम्);
        jl = jmp_list;
        जाव (jl) {
            जइ (jl->penv == e)
                भङ्ग;
            jl = jl->next;
        }
        जइ (jl == रिक्त) {
            jl = BOUND_MALLOC (परिमाण (jmp_list_type));
            जइ (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        जइ (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

स्थिर शून्य __bound_long_jump(jmp_buf env, पूर्णाङ्क val, पूर्णाङ्क sig, ध्रुव वर्ण *func)
{
    jmp_list_type *jl;
    शून्य *e;
    BOUND_TID_TYPE tid;

    जइ (NO_CHECKING_GET() == 0) {
        e = (शून्य *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_गणनम्(bound_longjmp_गणनम्);
        jl = jmp_list;
        जाव (jl) {
            जइ (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = रिक्त;

                जाव (cur->penv != e || cur->tid != tid) {
                    जइ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        जइ (last)
                            last->next = cur->next;
                        अण्णहा
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    अण्णहा {
                        last = cur;
                        cur = cur->next;
                    }
                }
                प्रति (;;) {
                    वृक्षः *t = वृक्षः_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    जाव (t && (t->start < start_fp || t->start > end_fp))
                        जइ (t->start < start_fp)
                            t = t->दक्षिणः;
                        अण्णहा
                            t = t->वामः;
                    जइ (t == रिक्त)
                        भङ्ग;
                    last = रिक्त;
                    cur = alloca_list;
                    जाव (cur) {
                         जइ ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             जइ (last)
                                 last->next = cur->next;
                             अण्णहा
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             भङ्ग;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (शून्य *) t->start);
                    वृक्षः_2 = splay_delete(t->start, वृक्षः_2);
                }
                भङ्ग;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#जइ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

शून्य __bound_longjmp(jmp_buf env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#जइ !defined(_WIN32)
शून्य __bound_siglongjmp(jmp_buf env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#जइ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic निष्कासय
#endif

शून्य __bound_init(size_t *p, पूर्णाङ्क mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    जइ (inited) {
        WAIT_SEM();
        गच्छ add_bounds;
    }
    inited = 1;

#जइ HAVE_TLS_FUNC
#जइ defined(_WIN32)
    no_checking_कुञ्चिका = TlsAlloc();
    Tls_Set_मानम्(no_checking_कुञ्चिका, &no_checking);
#अण्णहा
    pthread_key_create(&no_checking_कुञ्चिका, रिक्त);
    pthread_setspecific(no_checking_कुञ्चिका, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != रिक्त;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != रिक्त;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != रिक्त;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != रिक्त;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != रिक्त;

    INIT_SEM ();

#जइ MALLOC_REDIR
    {
        शून्य *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        जइ (malloc_redir == रिक्त) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(शून्य **) (&calloc_redir) = dlsym (addr, "calloc");
        *(शून्य **) (&free_redir) = dlsym (addr, "free");
        *(शून्य **) (&realloc_redir) = dlsym (addr, "realloc");
        *(शून्य **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        जइ (malloc_redir == रिक्त || free_redir == रिक्त)
            bound_alloc_error ("Cannot redirect malloc/free");
#जइ HAVE_PTHREAD_CREATE
        *(शून्य **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        जइ (pthread_create_redir == रिक्त)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#जइ HAVE_SIGNAL
        *(शून्य **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        जइ (signal_redir == रिक्त)
            bound_alloc_error ("Cannot redirect signal");
#endif
#जइ HAVE_SIGACTION
        *(शून्य **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        जइ (sigaction_redir == रिक्त)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#जइ HAVE_FORK
        *(शून्य **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        जइ (fork_redir == रिक्त)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned वर्ण found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        वर्ण पङ्क्तिः[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        जइ (fp) {
            memset (exec, 0, परिमाण(exec));
            fread (exec, 1, परिमाण(exec) - 2, fp);
            जइ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        जइ (fp) {
            जाव (fgets (पङ्क्तिः, परिमाण(पङ्क्तिः), fp)) {
                जइ (sscanf (पङ्क्तिः, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    भङ्ग;
                }
                जइ (strstr (पङ्क्तिः,"[heap]"))
                    भङ्ग;
            }
            fclose (fp);
        }
        जइ (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#जइ HAVE_CTYPE
#ifdef __APPLE__
    वृक्षः_2 = splay_निवेशय((size_t) &_DefaultRuneLocale,
                        परिमाण (_DefaultRuneLocale), वृक्षः_2);
#अण्णहा
    /* XXX: Does not work if locale is changed */
    वृक्षः_2 = splay_निवेशय((size_t) __ctype_b_loc(),
                        परिमाण (unsigned short *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((size_t) (*__ctype_b_loc() - 128),
                        384 * परिमाण (unsigned short), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((size_t) __ctype_tolower_loc(),
                        परिमाण (__int32_t *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((size_t) (*__ctype_tolower_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((size_t) __ctype_toupper_loc(),
                        परिमाण (__int32_t *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((size_t) (*__ctype_toupper_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्षः_2);
#endif
#endif
#जइ HAVE_ERRNO
    वृक्षः_2 = splay_निवेशय((size_t) (&errno), परिमाण (पूर्णाङ्क), वृक्षः_2);
#endif

add_bounds:
    जइ (!p)
        गच्छ no_bounds;

    /* add all static bound check values */
    जाव (p[0] != 0) {
        वृक्षः_2 = splay_निवेशय(p[0], p[1], वृक्षः_2);
#जइ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (शून्य *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

शून्य
#जइ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp)
{
    __bound_init (0, -1);
    जइ (argc && argv) {
        पूर्णाङ्क i;

        WAIT_SEM ();
        प्रति (i = 0; i < argc; i++)
            वृक्षः_2 = splay_निवेशय((size_t) argv[i], strlen (argv[i]) + 1, वृक्षः_2);
        वृक्षः_2 = splay_निवेशय((size_t) argv, (argc + 1) * परिमाण(वर्ण *), वृक्षः_2);
        POST_SEM ();
#जइ BOUND_DEBUG
        जइ (print_calls) {
            प्रति (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (पूर्णाङ्क)((argc + 1) * परिमाण(वर्ण *)));
        }
#endif
    }

    जइ (envp && *envp) {
        वर्ण **p = envp;

        WAIT_SEM ();
        जाव (*p) {
            वृक्षः_2 = splay_निवेशय((size_t) *p, strlen (*p) + 1, वृक्षः_2);
            ++p;
        }
        वृक्षः_2 = splay_निवेशय((size_t) envp, (++p - envp) * परिमाण(वर्ण *), वृक्षः_2);
        POST_SEM ();
#जइ BOUND_DEBUG
        जइ (print_calls) {
            p = envp;
            जाव (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (पूर्णाङ्क)((++p - envp) * परिमाण(वर्ण *)));
        }
#endif
    }
}

शून्य __attribute__((destructor)) __bound_exit(शून्य)
{
    पूर्णाङ्क i;
    स्थिर ध्रुव वर्ण * ध्रुव alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    जइ (inited) {
#जइ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        जइ (print_heap) {
            बाह्य शून्य __libc_freeres (शून्य);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        जाव (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            वृक्षः_2 = splay_delete ((size_t) alloca_list->p, वृक्षः_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        जाव (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        प्रति (i = 0; i < FREE_REUSE_SIZE; i++) {
            जइ (free_reuse_list[i]) {
                वृक्षः_2 = splay_delete ((size_t) free_reuse_list[i], वृक्षः_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        जाव (वृक्षः_2) {
            जइ (print_heap && वृक्षः_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[वृक्षः_2->type],
                         (unsigned long) वृक्षः_2->size);
            वृक्षः_2 = splay_delete (वृक्षः_2->start, वृक्षः_2);
        }
#जइ वृक्षः_REUSE
        जाव (वृक्षः_free_list) {
            वृक्षः *next = वृक्षः_free_list->वामः;
            BOUND_FREE (वृक्षः_free_list);
            वृक्षः_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#जइ HAVE_TLS_FUNC
#जइ defined(_WIN32)
        TlsFree(no_checking_कुञ्चिका);
#अण्णहा
        pthread_key_delete(no_checking_कुञ्चिका);
#endif
#endif
        inited = 0;
        जइ (print_statistic) {
#जइ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_गणनम्);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_गणनम्);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_गणनम्);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_गणनम्);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_गणनम्);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_गणनम्);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_गणनम्);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_गणनम्);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_गणनम्);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_गणनम्);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_गणनम्);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_गणनम्);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_गणनम्);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_गणनम्);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_गणनम्);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_गणनम्);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_गणनम्);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_गणनम्);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_गणनम्);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_गणनम्);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_गणनम्);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_गणनम्);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_गणनम्);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_गणनम्);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_गणनम्);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_गणनम्);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_गणनम्);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_गणनम्);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_गणनम्);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_गणनम्);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_गणनम्);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_गणनम्);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_गणनम्);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#जइ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_निवेशय);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

शून्य __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    जइ (p) {
        WAIT_SEM ();
	जाव (p[0] != 0) {
	    वृक्षः_2 = splay_delete(p[0], वृक्षः_2);
#जइ BOUND_DEBUG
            जइ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#जइ HAVE_PTHREAD_CREATE
प्रकारनिर्देश संरचना {
    शून्य *(*start_routine) (शून्य *);
    शून्य *arg;
    sigset_t old_mask;
} bound_thread_create_type;

स्थिर शून्य *bound_thread_create(शून्य *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    शून्य *retval;
#जइ HAVE_TLS_FUNC
    पूर्णाङ्क *p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));
  
    जइ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_कुञ्चिका, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, रिक्त);
    retval = data->start_routine(data->arg);
#जइ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_कुञ्चिका, रिक्त);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    प्रत्यागम retval;
}

पूर्णाङ्क pthread_create(pthread_t *thread, ध्रुव pthread_attr_t *attr,
                   शून्य *(*start_routine) (शून्य *), शून्य *arg)
{
    पूर्णाङ्क retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(परिमाण(bound_thread_create_type));
    जइ (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, रिक्त);
    प्रत्यागम retval;
}
#endif

#जइ HAVE_SIGNAL || HAVE_SIGACTION
प्रकारनिर्देश सङ्घ {
#जइ HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#जइ HAVE_SIGACTION
    शून्य (*sig_handler)(पूर्णाङ्क);
    शून्य (*sig_sigaction)(पूर्णाङ्क, siginfo_t *, शून्य *);
#endif
} bound_sig_type;

स्थिर unsigned वर्ण bound_sig_used[NSIG];
स्थिर bound_sig_type bound_sig_data[NSIG];
#endif

#जइ HAVE_SIGNAL
स्थिर शून्य signal_handler(पूर्णाङ्क sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig सङ्केत(पूर्णाङ्क signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    जइ (retval != SIG_ERR) {
        जइ (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        जइ (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    प्रत्यागम retval;
}
#endif

#जइ HAVE_SIGACTION
स्थिर शून्य sig_handler(पूर्णाङ्क sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

स्थिर शून्य sig_sigaction(पूर्णाङ्क sig, siginfo_t *info, शून्य *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

पूर्णाङ्क sigaction(पूर्णाङ्क signum, ध्रुव संरचना sigaction *act, संरचना sigaction *oldact)
{
    पूर्णाङ्क retval;
    संरचना sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    जइ (sigaction_redir == रिक्त)
        __bound_init(0,-1);

    जइ (act) {
        nact = *act;
        जइ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        अण्णहा
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    अण्णहा
        retval = sigaction_redir(signum, act, &oact);
    जइ (retval >= 0) {
        जइ (bound_sig_used[signum]) {
            जइ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            अण्णहा
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        जइ (oldact) {
            *oldact = oact;
        }
        जइ (act) {
            bound_sig_used[signum] = 1;
            जइ (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            अण्णहा
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    प्रत्यागम retval;
}
#endif

#जइ HAVE_FORK
pid_t fork(शून्य)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    जइ (retval == 0)
        INIT_SEM();
    अण्णहा
        POST_SEM();
    प्रत्यागम retval;
}
#endif

#जइ MALLOC_REDIR
शून्य *malloc(size_t size)
#अण्णहा
शून्य *__bound_malloc(size_t size, ध्रुव शून्य *caller)
#endif
{
    शून्य *ptr;
    
#जइ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    जइ (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        जइ (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            जइ (pool_index >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            प्रत्यागम ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    जइ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_malloc_गणनम्);

        जइ (ptr) {
            वृक्षः_2 = splay_निवेशय ((size_t) ptr, size ? size : size + 1, वृक्षः_2);
            जइ (वृक्षः_2 && वृक्षः_2->start == (size_t) ptr)
                वृक्षः_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#जइ MALLOC_REDIR
शून्य *memalign(size_t align, size_t size)
#अण्णहा
शून्य *__bound_memalign(size_t align, size_t size, ध्रुव शून्य *caller)
#endif
{
    शून्य *ptr;

#जइ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#अण्णहा
    जइ (align > 4) {
        /* XXX: handle it ? */
        ptr = रिक्त;
    } अण्णहा {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    जइ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_memalign_गणनम्);

        जइ (ptr) {
            वृक्षः_2 = splay_निवेशय((size_t) ptr, size ? size : size + 1, वृक्षः_2);
            जइ (वृक्षः_2 && वृक्षः_2->start == (size_t) ptr)
                वृक्षः_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#जइ MALLOC_REDIR
शून्य मुक्त(शून्य *ptr)
#अण्णहा
शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller)
#endif
{
    size_t addr = (size_t) ptr;
    शून्य *p;

    जइ (ptr == रिक्त || वृक्षः_2 == रिक्त
#जइ MALLOC_REDIR
        || ((unsigned वर्ण *) ptr >= &initial_pool[0] &&
            (unsigned वर्ण *) ptr < &initial_pool[परिमाण(initial_pool)])
#endif
        )
        प्रत्यागम;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    जइ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_free_गणनम्);
        वृक्षः_2 = splay (addr, वृक्षः_2);
        जइ (वृक्षः_2->start == addr) {
            जइ (वृक्षः_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                प्रत्यागम;
            }
            वृक्षः_2->is_invalid = 1;
            memset (ptr, 0x5a, वृक्षः_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            जइ (p)
                वृक्षः_2 = splay_delete((size_t)p, वृक्षः_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#जइ MALLOC_REDIR
शून्य *realloc(शून्य *ptr, size_t size)
#अण्णहा
शून्य *__bound_realloc(शून्य *ptr, size_t size, ध्रुव शून्य *caller)
#endif
{
    शून्य *new_ptr;

    जइ (size == 0) {
#जइ MALLOC_REDIR
        मुक्त(ptr);
#अण्णहा
        __bound_free(ptr, caller);
#endif
        प्रत्यागम रिक्त;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    जइ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_realloc_गणनम्);

        जइ (ptr)
            वृक्षः_2 = splay_delete ((size_t) ptr, वृक्षः_2);
        जइ (new_ptr) {
            वृक्षः_2 = splay_निवेशय ((size_t) new_ptr, size ? size : size + 1, वृक्षः_2);
            जइ (वृक्षः_2 && वृक्षः_2->start == (size_t) new_ptr)
                वृक्षः_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम new_ptr;
}

#जइ MALLOC_REDIR
शून्य *calloc(size_t nmemb, size_t size)
#अण्णहा
शून्य *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    शून्य *ptr;

    size *= nmemb;
#जइ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    जइ (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        जइ (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            जइ (pool_index >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            प्रत्यागम ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    जइ (ptr) {
        memset (ptr, 0, size);
        जइ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_गणनम्(bound_calloc_गणनम्);
            वृक्षः_2 = splay_निवेशय ((size_t) ptr, size ? size : size + 1, वृक्षः_2);
            जइ (वृक्षः_2 && वृक्षः_2->start == (size_t) ptr)
                वृक्षः_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    प्रत्यागम ptr;
}

#जइ !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, size_t size, पूर्णाङ्क prot,
                    पूर्णाङ्क flags, पूर्णाङ्क fd, off_t offset)
{
    शून्य *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    जइ (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_mmap_गणनम्);
        वृक्षः_2 = splay_निवेशय((size_t)result, size, वृक्षः_2);
        POST_SEM ();
    }
    प्रत्यागम result;
}

पूर्णाङ्क __bound_munmap (शून्य *start, size_t size)
{
    पूर्णाङ्क result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    जइ (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_munmap_गणनम्);
        वृक्षः_2 = splay_delete ((size_t) start, वृक्षः_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    प्रत्यागम result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
स्थिर शून्य __bound_check(ध्रुव शून्य *p, size_t size, ध्रुव वर्ण *function)
{
    जइ (size != 0 && __bound_ptr_add((शून्य *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

स्थिर पूर्णाङ्क check_overlap (ध्रुव शून्य *p1, size_t n1,
                          ध्रुव शून्य *p2, size_t n2,
                          ध्रुव वर्ण *function)
{
    ध्रुव शून्य *p1e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p1 + n1);
    ध्रुव शून्य *p2e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p2 + n2);

    जइ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        प्रत्यागम never_fatal < 0;
    }
    प्रत्यागम 0;
}

शून्य *__bound_memcpy(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_mempcy_गणनम्);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    जइ (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम memcpy(dest, src, n);
}

पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, size_t n)
{
    ध्रुव unsigned वर्ण *u1 = (ध्रुव unsigned वर्ण *) s1;
    ध्रुव unsigned वर्ण *u2 = (ध्रुव unsigned वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_गणनम्(bound_memcmp_गणनम्);
    प्रति (;;) {
        जइ ((ssize_t) --n == -1)
            भङ्ग;
        अण्णहा जइ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            भङ्ग;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ध्रुव शून्य *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ध्रुव शून्य *)u2 - s2, "memcmp s2");
    प्रत्यागम retval;
}

शून्य *__bound_memmove(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम memmove(dest, src, n);
}

शून्य *__bound_memset(शून्य *s, पूर्णाङ्क c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_गणनम्(bound_memset_गणनम्);
    __bound_check(s, n, "memset");
    प्रत्यागम memset(s, c, n);
}

#जइ defined(__arm__) && defined(__ARM_EABI__)
शून्य *__bound___aeabi_memcpy(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_mempcy_गणनम्);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    जइ (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम __aeabi_memcpy(dest, src, n);
}

शून्य *__bound___aeabi_memmove(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove(dest, src, n);
}

शून्य *__bound___aeabi_memmove4(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove4(dest, src, n);
}

शून्य *__bound___aeabi_memmove8(शून्य *dest, ध्रुव शून्य *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove8(dest, src, n);
}

शून्य *__bound___aeabi_memset(शून्य *s, पूर्णाङ्क c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_गणनम्(bound_memset_गणनम्);
    __bound_check(s, n, "memset");
    प्रत्यागम __aeabi_memset(s, c, n);
}
#endif

पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s)
{
    ध्रुव वर्ण *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_गणनम्(bound_strlen_गणनम्);
    जाव (*p++);
    __bound_check(s, p - s, "strlen");
    प्रत्यागम (p - s) - 1;
}

वर्ण *__bound_strcpy(वर्ण *dest, ध्रुव वर्ण *src)
{
    size_t len;
    ध्रुव वर्ण *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_गणनम्(bound_strcpy_गणनम्);
    जाव (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    जइ (check_overlap(dest, len, src, len, "strcpy"))
        प्रत्यागम dest;
    प्रत्यागम strcpy (dest, src);
}

वर्ण *__bound_strncpy(वर्ण *dest, ध्रुव वर्ण *src, size_t n)
{
    size_t len = n;
    ध्रुव वर्ण *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_strncpy_गणनम्);
    जाव (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    जइ (check_overlap(dest, len, src, len, "strncpy"))
        प्रत्यागम dest;
    प्रत्यागम strncpy(dest, src, n);
}

पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2)
{
    ध्रुव unsigned वर्ण *u1 = (ध्रुव unsigned वर्ण *) s1;
    ध्रुव unsigned वर्ण *u2 = (ध्रुव unsigned वर्ण *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_गणनम्(bound_strcmp_गणनम्);
    जाव (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ध्रुव वर्ण *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ध्रुव वर्ण *)u2 - s2) + 1, "strcmp s2");
    प्रत्यागम *u1 - *u2;
}

पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, size_t n)
{
    ध्रुव unsigned वर्ण *u1 = (ध्रुव unsigned वर्ण *) s1;
    ध्रुव unsigned वर्ण *u2 = (ध्रुव unsigned वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_गणनम्(bound_strncmp_गणनम्);
    करेहि {
        जइ ((ssize_t) --n == -1)
            भङ्ग;
        अण्णहा जइ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            भङ्ग;
        }
        ++u2;
    } जाव (*u1++);
    __bound_check(s1, (ध्रुव वर्ण *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ध्रुव वर्ण *)u2 - s2, "strncmp s2");
    प्रत्यागम retval;
}

वर्ण *__bound_strcat(वर्ण *dest, ध्रुव वर्ण *src)
{
    वर्ण *r = dest;
    ध्रुव वर्ण *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_गणनम्(bound_strcat_गणनम्);
    जाव (*dest++);
    जाव (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    जइ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        प्रत्यागम dest;
    प्रत्यागम strcat(r, s);
}

वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, size_t n)
{
    वर्ण *r = dest;
    ध्रुव वर्ण *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_गणनम्(bound_strncat_गणनम्);
    जाव (*dest++);
    जाव (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    जइ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        प्रत्यागम dest;
    प्रत्यागम strncat(r, s, n);
}

वर्ण *__bound_strchr(ध्रुव वर्ण *s, पूर्णाङ्क c)
{
    ध्रुव unsigned वर्ण *str = (ध्रुव unsigned वर्ण *) s;
    unsigned वर्ण ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गणनम्(bound_strchr_गणनम्);
    जाव (*str) {
        जइ (*str == ch)
            भङ्ग;
        ++str;
    }
    __bound_check(s, ((ध्रुव वर्ण *)str - s) + 1, "strchr");
    प्रत्यागम *str == ch ? (वर्ण *) str : रिक्त;
}

वर्ण *__bound_strrchr(ध्रुव वर्ण *s, पूर्णाङ्क c)
{
    ध्रुव unsigned वर्ण *str = (ध्रुव unsigned वर्ण *) s;
    unsigned वर्ण ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गणनम्(bound_strrchr_गणनम्);
    जाव (*str++);
    __bound_check(s, (ध्रुव वर्ण *)str - s, "strrchr");
    जाव (str != (ध्रुव unsigned वर्ण *)s) {
        जइ (*--str == ch)
            भङ्ग;
    }
    __bound_check(s, (ध्रुव वर्ण *)str - s, "strrchr");
    प्रत्यागम *str == ch ? (वर्ण *) str : रिक्त;
}

वर्ण *__bound_strdup(ध्रुव वर्ण *s)
{
    ध्रुव वर्ण *p = s;
    वर्ण *new;

    INCR_गणनम्(bound_strdup_गणनम्);
    जाव (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    जइ (new) {
        जइ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            वृक्षः_2 = splay_निवेशय((size_t)new, p - s, वृक्षः_2);
            जइ (वृक्षः_2 && वृक्षः_2->start == (size_t) new)
                वृक्षः_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    प्रत्यागम new;
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

स्थिर वृक्षः * splay (size_t addr, वृक्षः *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    वृक्षः N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गणनम्_SPLAY(bound_splay);
    जइ (t == रिक्त) प्रत्यागम t;
    N.वामः = N.दक्षिणः = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare(addr, t->start, t->size);
        जइ (comp < 0) {
            y = t->वामः;
            जइ (y == रिक्त) भङ्ग;
            जइ (compare(addr, y->start, y->size) < 0) {
                t->वामः = y->दक्षिणः;                    /* rotate right */
                y->दक्षिणः = t;
                t = y;
                जइ (t->वामः == रिक्त) भङ्ग;
            }
            r->वामः = t;                               /* link right */
            r = t;
            t = t->वामः;
        } अण्णहा जइ (comp > 0) {
            y = t->दक्षिणः;
            जइ (y == रिक्त) भङ्ग;
            जइ (compare(addr, y->start, y->size) > 0) {
                t->दक्षिणः = y->वामः;                    /* rotate left */
                y->वामः = t;
                t = y;
                जइ (t->दक्षिणः == रिक्त) भङ्ग;
            }
            l->दक्षिणः = t;                              /* link left */
            l = t;
            t = t->दक्षिणः;
        } अण्णहा {
            भङ्ग;
        }
    }
    l->दक्षिणः = t->वामः;                                /* assemble */
    r->वामः = t->दक्षिणः;
    t->वामः = N.दक्षिणः;
    t->दक्षिणः = N.वामः;

    प्रत्यागम t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

स्थिर वृक्षः * splay_end (size_t addr, वृक्षः *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    वृक्षः N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गणनम्_SPLAY(bound_splay_end);
    जइ (t == रिक्त) प्रत्यागम t;
    N.वामः = N.दक्षिणः = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare_end(addr, t->start + t->size);
        जइ (comp < 0) {
            y = t->वामः;
            जइ (y == रिक्त) भङ्ग;
            जइ (compare_end(addr, y->start + y->size) < 0) {
                t->वामः = y->दक्षिणः;                    /* rotate right */
                y->दक्षिणः = t;
                t = y;
                जइ (t->वामः == रिक्त) भङ्ग;
            }
            r->वामः = t;                               /* link right */
            r = t;
            t = t->वामः;
        } अण्णहा जइ (comp > 0) {
            y = t->दक्षिणः;
            जइ (y == रिक्त) भङ्ग;
            जइ (compare_end(addr, y->start + y->size) > 0) {
                t->दक्षिणः = y->वामः;                    /* rotate left */
                y->वामः = t;
                t = y;
                जइ (t->दक्षिणः == रिक्त) भङ्ग;
            }
            l->दक्षिणः = t;                              /* link left */
            l = t;
            t = t->दक्षिणः;
        } अण्णहा {
            भङ्ग;
        }
    }
    l->दक्षिणः = t->वामः;                                /* assemble */
    r->वामः = t->दक्षिणः;
    t->वामः = N.दक्षिणः;
    t->दक्षिणः = N.वामः;

    प्रत्यागम t;
}

स्थिर वृक्षः * splay_निवेशय(size_t addr, size_t size, वृक्षः * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    वृक्षः * new;

    INCR_गणनम्_SPLAY(bound_splay_निवेशय);
    जइ (t != रिक्त) {
        t = splay(addr,t);
        जइ (compare(addr, t->start, t->size)==0) {
            प्रत्यागम t;  /* it's already there */
        }
    }
#जइ वृक्षः_REUSE
    जइ (वृक्षः_free_list) {
          new = वृक्षः_free_list;
          वृक्षः_free_list = new->वामः;
    }
    अण्णहा
#endif
    {
        new = (वृक्षः *) BOUND_MALLOC (परिमाण (वृक्षः));
    }
    जइ (new == रिक्त) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    अण्णहा {
        जइ (t == रिक्त) {
            new->वामः = new->दक्षिणः = रिक्त;
        } अण्णहा जइ (compare(addr, t->start, t->size) < 0) {
            new->वामः = t->वामः;
            new->दक्षिणः = t;
            t->वामः = रिक्त;
        } अण्णहा {
            new->दक्षिणः = t->दक्षिणः;
            new->वामः = t;
            t->दक्षिणः = रिक्त;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    प्रत्यागम new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

स्थिर वृक्षः * splay_delete(size_t addr, वृक्षः *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    वृक्षः * x;

    INCR_गणनम्_SPLAY(bound_splay_delete);
    जइ (t==रिक्त) प्रत्यागम रिक्त;
    t = splay(addr,t);
    जइ (compare_destroy(addr, t->start) == 0) {        /* found it */
        जइ (t->वामः == रिक्त) {
            x = t->दक्षिणः;
        } अण्णहा {
            x = splay(addr, t->वामः);
            x->दक्षिणः = t->दक्षिणः;
        }
#जइ वृक्षः_REUSE
        t->वामः = वृक्षः_free_list;
        वृक्षः_free_list = t;
#अण्णहा
        BOUND_FREE(t);
#endif
        प्रत्यागम x;
    } अण्णहा {
        प्रत्यागम t;                                      /* It wasn't there */
    }
}

शून्य splay_printtree(वृक्षः * t, पूर्णाङ्क d)
{
    पूर्णाङ्क i;
    जइ (t == रिक्त) प्रत्यागम;
    splay_printtree(t->दक्षिणः, d+1);
    प्रति (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (शून्य *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->वामः, d+1);
}
