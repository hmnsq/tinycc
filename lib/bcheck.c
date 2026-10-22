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

#यदि !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#अन्तर्भाव <malloc.h>
#यदि_अन्तः

#यदि !defined(_WIN32)
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/syscall.h>
#यदि_अन्तः

#अन्तर्भाव "config.h"

#परिभाषय BOUND_DEBUG             (1)
#परिभाषय BOUND_STATISTIC         (1)

#यदि BOUND_DEBUG
 #परिभाषय dprintf(a...)         यदि (print_calls) { bounds_loc(a); }
#अन्यथा
 #परिभाषय dprintf(a...)
#यदि_अन्तः

#यदि_परिभाषितम् __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #अपरिभाषय __attribute__ 
#यदि_अन्तः
#यदि_परिभाषितम् __i386__
#परिभाषय FASTCALL __attribute__((regparm(3)))
#अन्यथा
#परिभाषय FASTCALL
#यदि_अन्तः

#यदि_परिभाषितम् _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अन्यथा
# define DLL_EXPORT
#यदि_अन्तः

#यदि defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#अन्तर्भाव <sys/mman.h>
#परिभाषय INIT_SEM()
#परिभाषय EXIT_SEM()
#परिभाषय WAIT_SEM()
#परिभाषय POST_SEM()
#परिभाषय TRY_SEM()
#परिभाषय HAVE_MEMALIGN          (0)
#परिभाषय MALLOC_REDIR           (0)
#परिभाषय HAVE_PTHREAD_CREATE    (0)
#परिभाषय HAVE_CTYPE             (0)
#परिभाषय HAVE_ERRNO             (0)
#परिभाषय HAVE_SIGNAL            (0)
#परिभाषय HAVE_SIGACTION         (0)
#परिभाषय HAVE_FORK              (0)
#परिभाषय HAVE_TLS_FUNC          (0)
#परिभाषय HAVE_TLS_VAR           (0)

#नोचेद्यदि defined(_WIN32)

#अन्तर्भाव <windows.h>
#अन्तर्भाव <signal.h>
स्थिर CRITICAL_SECTION bounds_sem;
#परिभाषय INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#परिभाषय EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#परिभाषय WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#परिभाषय POST_SEM()             LeaveCriticalSection(&bounds_sem)
#परिभाषय TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#परिभाषय HAVE_MEMALIGN          (0)
#परिभाषय MALLOC_REDIR           (0)
#परिभाषय HAVE_PTHREAD_CREATE    (0)
#परिभाषय HAVE_CTYPE             (0)
#परिभाषय HAVE_ERRNO             (0)
#परिभाषय HAVE_SIGNAL            (1)
#परिभाषय HAVE_SIGACTION         (0)
#परिभाषय HAVE_FORK              (0)
#परिभाषय HAVE_TLS_FUNC          (1)
#परिभाषय HAVE_TLS_VAR           (0)

#अन्यथा

#परिभाषय __USE_GNU              /* get RTLD_NEXT */
#अन्तर्भाव <sys/mman.h>
#अन्तर्भाव <ctype.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <dlfcn.h>
#अन्तर्भाव <errno.h>
#अन्तर्भाव <signal.h>
#यदि_परिभाषितम् __APPLE__
#अन्तर्भाव <dispatch/dispatch.h>
स्थिर dispatch_semaphore_t bounds_sem;
#परिभाषय INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#परिभाषय EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#परिभाषय WAIT_SEM()             यदि (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#परिभाषय POST_SEM()             यदि (use_sem) dispatch_semaphore_signal(bounds_sem)
#परिभाषय TRY_SEM()              यदि (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#नोचेद्यदि 0
#अन्तर्भाव <semaphore.h>
स्थिर sem_t bounds_sem;
#परिभाषय INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#परिभाषय EXIT_SEM()             sem_destroy (&bounds_sem)
#परिभाषय WAIT_SEM()             यदि (use_sem) यावत् (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#परिभाषय POST_SEM()             यदि (use_sem) sem_post (&bounds_sem)
#परिभाषय TRY_SEM()              यदि (use_sem) यावत् (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#नोचेद्यदि 0
स्थिर pthread_mutex_t bounds_mtx;
#परिभाषय INIT_SEM()             pthread_mutex_init (&bounds_mtx, रिक्त)
#परिभाषय EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#परिभाषय WAIT_SEM()             यदि (use_sem) pthread_mutex_lock (&bounds_mtx)
#परिभाषय POST_SEM()             यदि (use_sem) pthread_mutex_unlock (&bounds_mtx)
#परिभाषय TRY_SEM()              यदि (use_sem) pthread_mutex_trylock (&bounds_mtx)
#अन्यथा
स्थिर pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#परिभाषय INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#परिभाषय EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#परिभाषय WAIT_SEM()             यदि (use_sem) pthread_spin_lock (&bounds_spin)
#परिभाषय POST_SEM()             यदि (use_sem) pthread_spin_unlock (&bounds_spin)
#परिभाषय TRY_SEM()              यदि (use_sem) pthread_spin_trylock (&bounds_spin)
#यदि_अन्तः
#परिभाषय HAVE_MEMALIGN          (1)
#परिभाषय MALLOC_REDIR           (1)
#परिभाषय HAVE_PTHREAD_CREATE    (1)
#परिभाषय HAVE_CTYPE             (1)
#परिभाषय HAVE_ERRNO             (1)
#परिभाषय HAVE_SIGNAL            (1)
#परिभाषय HAVE_SIGACTION         (1)
#परिभाषय HAVE_FORK              (1)
#यदि defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_सततम्)
#परिभाषय HAVE_TLS_FUNC          (1)
#परिभाषय HAVE_TLS_VAR           (0)
#अन्यथा
#परिभाषय HAVE_TLS_FUNC          (0)
#परिभाषय HAVE_TLS_VAR           (1)
#यदि_अन्तः
#यदि defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#यदि_अन्तः
#यदि_अन्तः

#यदि MALLOC_REDIR
स्थिर शून्य *(*malloc_redir) (आकार_t);
स्थिर शून्य *(*calloc_redir) (आकार_t, आकार_t);
स्थिर शून्य (*free_redir) (शून्य *);
स्थिर शून्य *(*realloc_redir) (शून्य *, आकार_t);
स्थिर अचिह्नित पूर्णाङ्क pool_सूचकांक;
स्थिर अचिह्नित वर्ण __attribute__((aligned(16))) initial_pool[256];
#यदि_अन्तः
#यदि HAVE_MEMALIGN
स्थिर शून्य *(*memalign_redir) (आकार_t, आकार_t);
#यदि_अन्तः
#यदि HAVE_PTHREAD_CREATE
स्थिर पूर्णाङ्क (*pthread_create_redir) (pthread_t *thread,
                                    ध्रुव pthread_attr_t *attr,
                                    शून्य *(*start_routine)(शून्य *), शून्य *arg);
#यदि_अन्तः
#यदि HAVE_SIGNAL
प्रकारनिर्देश शून्य (*bound_sig)(पूर्णाङ्क);
स्थिर bound_sig (*signal_redir) (पूर्णाङ्क signum, bound_sig handler);
#यदि_अन्तः
#यदि HAVE_SIGACTION
स्थिर पूर्णाङ्क (*sigaction_redir) (पूर्णाङ्क signum, ध्रुव संरचना sigaction *act,
                               संरचना sigaction *oldact);
#यदि_अन्तः
#यदि HAVE_FORK
स्थिर पूर्णाङ्क (*fork_redir) (शून्य);
#यदि_अन्तः

#परिभाषय TCC_TYPE_NONE           (0)
#परिभाषय TCC_TYPE_MALLOC         (1)
#परिभाषय TCC_TYPE_CALLOC         (2)
#परिभाषय TCC_TYPE_REALLOC        (3)
#परिभाषय TCC_TYPE_MEMALIGN       (4)
#परिभाषय TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#परिभाषय INVALID_POINTER ((शून्य *)(-2))

प्रकारनिर्देश संरचना वृक्ष_ग्रन्थिः वृक्षः;
संरचना वृक्ष_ग्रन्थिः {
    वृक्षः * वामः, * दक्षिणः;
    आकार_t start;
    आकार_t आकार;
    अचिह्नित वर्ण type;
    अचिह्नित वर्ण is_invalid; /* true if pointers outside region are invalid */
};

प्रकारनिर्देश संरचना alloca_list_struct {
    आकार_t fp;
    शून्य *p;
    आकार_t आकार;
    संरचना alloca_list_struct *अग्र;
} alloca_list_type;

#यदि defined(_WIN32)
#परिभाषय BOUND_TID_TYPE		DWORD
#परिभाषय BOUND_GET_TID(id)	id = GetCurrentThreadId()
#नोचेद्यदि defined(__OpenBSD__)
#परिभाषय BOUND_TID_TYPE		pid_t
#परिभाषय BOUND_GET_TID(id)	id = getthrid()
#नोचेद्यदि defined(__FreeBSD__)
#परिभाषय BOUND_TID_TYPE		pid_t
#परिभाषय BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#नोचेद्यदि  defined(__NetBSD__)
#परिभाषय BOUND_TID_TYPE		pid_t
#परिभाषय BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#नोचेद्यदि defined(__linux__)
#परिभाषय BOUND_TID_TYPE		pid_t
#परिभाषय BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#अन्यथा
#परिभाषय BOUND_TID_TYPE		पूर्णाङ्क
#परिभाषय BOUND_GET_TID(id)	id = 0
#यदि_अन्तः

प्रकारनिर्देश संरचना jmp_list_struct {
    शून्य *penv;
    आकार_t fp;
    आकार_t अन्तः_fp;
    BOUND_TID_TYPE tid;
    संरचना jmp_list_struct *अग्र;
} jmp_list_type;

#परिभाषय BOUND_STATISTIC_SPLAY   (0)
स्थिर वृक्षः * splay (आकार_t addr, वृक्षः *t);
स्थिर वृक्षः * splay_अन्तः (आकार_t addr, वृक्षः *t);
स्थिर वृक्षः * splay_निवेशय(आकार_t addr, आकार_t आकार, वृक्षः * t);
स्थिर वृक्षः * splay_delete(आकार_t addr, वृक्षः *t);
शून्य splay_printtree(वृक्षः * t, पूर्णाङ्क d);

/* external interface */
शून्य __bounds_checking (पूर्णाङ्क no_check);
शून्य __bound_checking_lock (शून्य);
शून्य __bound_checking_unlock (शून्य);
शून्य __bound_never_fatal (पूर्णाङ्क no_check);
DLL_EXPORT शून्य * __bound_ptr_add(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir1(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir2(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir4(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir8(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir12(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य * __bound_ptr_indir16(शून्य *p, आकार_t विस्थापनम्);
DLL_EXPORT शून्य FASTCALL __bound_local_new(शून्य *p1);
DLL_EXPORT शून्य FASTCALL __bound_local_delete(शून्य *p1);
शून्य __bound_init(आकार_t *, पूर्णाङ्क);
शून्य __bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
शून्य __bound_exit(शून्य);
शून्य __bound_exit_dll(आकार_t *);
#यदि !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, आकार_t आकार, पूर्णाङ्क prot, पूर्णाङ्क flags, पूर्णाङ्क fd,
                    off_t विस्थापनम्);
पूर्णाङ्क __bound_munmap (शून्य *start, आकार_t आकार);
DLL_EXPORT शून्य __bound_siglongjmp(jmp_buf env, पूर्णाङ्क val);
#यदि_अन्तः
DLL_EXPORT शून्य __bound_new_region(शून्य *p, आकार_t आकार);
DLL_EXPORT शून्य __bound_setjmp(jmp_buf env);
DLL_EXPORT शून्य __bound_longjmp(jmp_buf env, पूर्णाङ्क val);
DLL_EXPORT शून्य *__bound_memcpy(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, आकार_t आकार);
DLL_EXPORT शून्य *__bound_memmove(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__bound_memset(शून्य *dst, पूर्णाङ्क c, आकार_t आकार);
DLL_EXPORT पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s);
DLL_EXPORT वर्ण *__bound_strcpy(वर्ण *dst, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncpy(वर्ण *dst, ध्रुव वर्ण *src, आकार_t n);
DLL_EXPORT पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2);
DLL_EXPORT पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, आकार_t n);
DLL_EXPORT वर्ण *__bound_strcat(वर्ण *dest, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, आकार_t n);
DLL_EXPORT वर्ण *__bound_strchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strrchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strdup(ध्रुव वर्ण *s);

#यदि defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT शून्य *__bound___aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__bound___aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__bound___aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__bound___aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__bound___aeabi_memset(शून्य *dst, पूर्णाङ्क c, आकार_t आकार);
DLL_EXPORT शून्य *__aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, आकार_t आकार);
DLL_EXPORT शून्य *__aeabi_memset(शून्य *dst, पूर्णाङ्क c, आकार_t आकार);
#यदि_अन्तः

#यदि MALLOC_REDIR
#परिभाषय BOUND_MALLOC(a)          malloc_redir(a)
#परिभाषय BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#परिभाषय BOUND_FREE(a)            free_redir(a)
#परिभाषय BOUND_REALLOC(a,b)       realloc_redir(a,b)
#परिभाषय BOUND_CALLOC(a,b)        calloc_redir(a,b)
#अन्यथा
#परिभाषय BOUND_MALLOC(a)          स्मृतिं_देहि(a)
#परिभाषय BOUND_MEMALIGN(a,b)      memalign(a,b)
#परिभाषय BOUND_FREE(a)            मुक्त(a)
#परिभाषय BOUND_REALLOC(a,b)       realloc(a,b)
#परिभाषय BOUND_CALLOC(a,b)        शून्यस्मृतिं_देहि(a,b)
DLL_EXPORT शून्य *__bound_malloc(आकार_t आकार, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_memalign(आकार_t align, आकार_t आकार, ध्रुव शून्य *caller);
DLL_EXPORT शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_realloc(शून्य *ptr, आकार_t आकार, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_calloc(आकार_t nmemb, आकार_t आकार);
#यदि_अन्तः

#परिभाषय FREE_REUSE_आकार (100)
स्थिर अचिह्नित पूर्णाङ्क free_reuse_सूचकांक;
स्थिर शून्य *free_reuse_list[FREE_REUSE_आकार];

स्थिर वृक्षः *वृक्षः_2 = रिक्त;
#परिभाषय वृक्षः_REUSE      (1)
#यदि वृक्षः_REUSE
स्थिर वृक्षः *वृक्षः_free_list;
#यदि_अन्तः
स्थिर alloca_list_type *alloca_list;
स्थिर jmp_list_type *jmp_list;

स्थिर अचिह्नित वर्ण inited;
स्थिर अचिह्नित वर्ण print_warn_ptr_सङ्कलय;
स्थिर अचिह्नित वर्ण print_calls;
स्थिर अचिह्नित वर्ण print_heap;
स्थिर अचिह्नित वर्ण print_statistic;
स्थिर अचिह्नित वर्ण no_strdup;
स्थिर अचिह्नित वर्ण use_sem;
स्थिर _Atomic पूर्णाङ्क never_fatal;
#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर DWORD no_checking_कुञ्चिका;
#परिभाषय NO_CHECKING_CHECK() यदि (!p) {                                         \
                                  p = (पूर्णाङ्क *) LocalAlloc(LPTR, परिमाण(पूर्णाङ्क));  \
                                  यदि (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_समुच्चयः_मानम्(no_checking_कुञ्चिका, p);            \
                            }
#परिभाषय NO_CHECKING_GET()   ({ पूर्णाङ्क *p = Tls_Get_मानम्(no_checking_कुञ्चिका);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#परिभाषय NO_CHECKING_समुच्चयः(v)  { पूर्णाङ्क *p = Tls_Get_मानम्(no_checking_कुञ्चिका);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#अन्यथा
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर pthread_key_t no_checking_कुञ्चिका;
#परिभाषय NO_CHECKING_CHECK() यदि (!p) {                                         \
                                  p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));      \
                                  यदि (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_कुञ्चिका, p);    \
                            }
#परिभाषय NO_CHECKING_GET()   ({ पूर्णाङ्क *p = pthread_getspecific(no_checking_कुञ्चिका); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#परिभाषय NO_CHECKING_समुच्चयः(v)  { पूर्णाङ्क *p = pthread_getspecific(no_checking_कुञ्चिका);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#यदि_अन्तः
#नोचेद्यदि HAVE_TLS_VAR
स्थिर __thread पूर्णाङ्क no_checking = 0;
#परिभाषय NO_CHECKING_GET()  no_checking
#परिभाषय NO_CHECKING_समुच्चयः(v) no_checking = v 
#अन्यथा
स्थिर _Atomic पूर्णाङ्क no_checking = 0;
#परिभाषय NO_CHECKING_GET()  no_checking
#परिभाषय NO_CHECKING_समुच्चयः(v) no_checking = v 
#यदि_अन्तः
स्थिर वर्ण exec[100];

#यदि BOUND_STATISTIC
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_सङ्कलय_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir1_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir2_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir4_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir8_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir12_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_ptr_indir16_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_local_new_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_local_delete_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_malloc_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_calloc_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_realloc_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_free_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_memalign_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_mmap_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_munmap_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_alloca_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_setjmp_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_longjmp_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_mempcy_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_memcmp_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_memmove_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_memset_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strlen_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strcpy_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strncpy_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strcmp_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strncmp_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strcat_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strncat_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strchr_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strrchr_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_strdup_गणनम्;
स्थिर अचिह्नित दीर्घ दीर्घ bound_not_प्राप्तम्;
#परिभाषय INCR_गणनम्(x)          ++x
#अन्यथा
#परिभाषय INCR_गणनम्(x)
#यदि_अन्तः
#यदि BOUND_STATISTIC_SPLAY
स्थिर अचिह्नित दीर्घ दीर्घ bound_splay;
स्थिर अचिह्नित दीर्घ दीर्घ bound_splay_अन्तः;
स्थिर अचिह्नित दीर्घ दीर्घ bound_splay_निवेशय;
स्थिर अचिह्नित दीर्घ दीर्घ bound_splay_delete;
#परिभाषय INCR_गणनम्_SPLAY(x)    ++x
#अन्यथा
#परिभाषय INCR_गणनम्_SPLAY(x)
#यदि_अन्तः

पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण *fmt, ...);

/* print a bound error message */
#परिभाषय bound_warning(...) \
    कुरु {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } यावत् (0)

#परिभाषय bound_error(...)            \
    कुरु {                            \
        bound_warning(__VA_ARGS__); \
        यदि (never_fatal == 0)       \
            निर्गच्छ(255);              \
    } यावत् (0)

#परिभाषय bounds_loc(fp, ...) \
    कुरु {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } यावत् (0)

स्थिर शून्य bound_alloc_error(ध्रुव वर्ण *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    निर्गच्छ (1);
}

स्थिर शून्य bound_not_प्राप्तम्_warning(ध्रुव वर्ण *file, ध्रुव वर्ण *function,
                                    शून्य *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
शून्य __bounds_checking (पूर्णाङ्क no_check)
{
#यदि HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_समुच्चयः(NO_CHECKING_GET() + no_check);
#अन्यथा
    atomic_fetch_add (&no_checking, no_check);
#यदि_अन्तः
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
शून्य * __bound_ptr_add(शून्य *p, आकार_t विस्थापनम्)
{
    आकार_t addr = (आकार_t)p;

    यदि (NO_CHECKING_GET())
        प्रत्यागम p + विस्थापनम्;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिह्नित दीर्घ)विस्थापनम्);

    WAIT_SEM ();
    INCR_गणनम्(bound_ptr_सङ्कलय_गणनम्);
    यदि (वृक्षः_2) {
        addr -= वृक्षः_2->start;
        यदि (addr >= वृक्षः_2->आकार) {
            addr = (आकार_t)p;
            वृक्षः_2 = splay (addr, वृक्षः_2);
            addr -= वृक्षः_2->start;
        }
        यदि (addr >= वृक्षः_2->आकार) {
            addr = (आकार_t)p;
            वृक्षः_2 = splay_अन्तः (addr, वृक्षः_2);
            addr -= वृक्षः_2->start;
        }
        यदि (addr <= वृक्षः_2->आकार) {
            यदि (वृक्षः_2->is_invalid || addr + विस्थापनम् > वृक्षः_2->आकार) {
                POST_SEM ();
                यदि (print_warn_ptr_सङ्कलय)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + विस्थापनम्, (दीर्घ)वृक्षः_2->start,
                                  (दीर्घ)(वृक्षः_2->start + वृक्षः_2->आकार - 1));
                यदि (never_fatal <= 0)
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */
                प्रत्यागम p + विस्थापनम्;
            }
        }
        अन्यथा यदि (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_गणनम्(bound_not_प्राप्तम्);
            POST_SEM ();
            bound_not_प्राप्तम्_warning (__FILE__, __FUNCTION__, p);
            प्रत्यागम p + विस्थापनम्;
        }
    }
    POST_SEM ();
    प्रत्यागम p + विस्थापनम्;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#परिभाषय BOUND_PTR_INDIR(dsize)                                                 \
शून्य * __bound_ptr_indir ## dsize (शून्य *p, आकार_t विस्थापनम्)                     \
{                                                                              \
    आकार_t addr = (आकार_t)p;                                                   \
                                                                               \
    यदि (NO_CHECKING_GET())                                                     \
        प्रत्यागम p + विस्थापनम्;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (अचिह्नित दीर्घ)विस्थापनम्);                 \
    WAIT_SEM ();                                                               \
    INCR_गणनम्(bound_ptr_indir ## dsize ## गणनम्);                            \
    यदि (वृक्षः_2) {                                                                \
        addr -= वृक्षः_2->start;                                                   \
        यदि (addr >= वृक्षः_2->आकार) {                                              \
            addr = (आकार_t)p;                                                  \
            वृक्षः_2 = splay (addr, वृक्षः_2);                                         \
            addr -= वृक्षः_2->start;                                               \
        }                                                                      \
        यदि (addr >= वृक्षः_2->आकार) {                                              \
            addr = (आकार_t)p;                                                  \
            वृक्षः_2 = splay_अन्तः (addr, वृक्षः_2);                                     \
            addr -= वृक्षः_2->start;                                               \
        }                                                                      \
        यदि (addr <= वृक्षः_2->आकार) {                                              \
            यदि (वृक्षः_2->is_invalid || addr + विस्थापनम् + dsize > वृक्षः_2->आकार) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + विस्थापनम्, dsize, (दीर्घ)वृक्षः_2->start,            \
                              (दीर्घ)(वृक्षः_2->start + वृक्षः_2->आकार - 1));           \
                यदि (never_fatal <= 0)                                          \
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */    \
                प्रत्यागम p + विस्थापनम्;                                             \
            }                                                                  \
        }                                                                      \
        अन्यथा {                                                                 \
            INCR_गणनम्(bound_not_प्राप्तम्);                                       \
            POST_SEM ();                                                       \
            bound_not_प्राप्तम्_warning (__FILE__, __FUNCTION__, p);               \
            प्रत्यागम p + विस्थापनम्;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    प्रत्यागम p + विस्थापनम्;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#यदि (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#निर्देशः GCC diagnostic प्रक्षिप
#निर्देशः GCC diagnostic ignored "-Wframe-address"
#यदि_अन्तः

/* return the frame pointer of the caller */
#परिभाषय GET_CALLER_FP(fp)\
{\
    fp = (आकार_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
शून्य FASTCALL __bound_local_new(शून्य *p1) 
{
    आकार_t addr, fp, *p = p1;

    यदि (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    यावत् ((addr = p[0])) {
        INCR_गणनम्(bound_local_new_गणनम्);
        वृक्षः_2 = splay_निवेशय(addr + fp, p[1], वृक्षः_2);
        p += 2;
    }
    POST_SEM ();
#यदि BOUND_DEBUG
    यदि (print_calls) {
        p = p1;
        यावत् ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (शून्य *) (addr + fp), (अचिह्नित दीर्घ) p[1]);
            p += 2;
        }
    }
#यदि_अन्तः
}

/* called when leaving a function to delete all the local regions */
शून्य FASTCALL __bound_local_delete(शून्य *p1) 
{
    आकार_t addr, fp, *p = p1;

    यदि (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    यावत् ((addr = p[0])) {
        INCR_गणनम्(bound_local_delete_गणनम्);
        वृक्षः_2 = splay_delete(addr + fp, वृक्षः_2);
        p += 2;
    }
    यदि (alloca_list) {
        alloca_list_type *चरमः = रिक्त;
        alloca_list_type *cur = alloca_list;

        कुरु {
            यदि (cur->fp == fp) {
                यदि (चरमः)
                    चरमः->अग्र = cur->अग्र;
                अन्यथा
                    alloca_list = cur->अग्र;
                वृक्षः_2 = splay_delete ((आकार_t) cur->p, वृक्षः_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = चरमः ? चरमः->अग्र : alloca_list;
             }
             अन्यथा {
                 चरमः = cur;
                 cur = cur->अग्र;
             }
        } यावत् (cur);
    }
    यदि (jmp_list) {
        jmp_list_type *चरमः = रिक्त;
        jmp_list_type *cur = jmp_list;

        कुरु {
            यदि (cur->fp == fp) {
                यदि (चरमः)
                    चरमः->अग्र = cur->अग्र;
                अन्यथा
                    jmp_list = cur->अग्र;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = चरमः ? चरमः->अग्र : jmp_list;
            }
            अन्यथा {
                चरमः = cur;
                cur = cur->अग्र;
            }
        } यावत् (cur);
    }

    POST_SEM ();
#यदि BOUND_DEBUG
    यदि (print_calls) {
        p = p1;
        यावत् ((addr = p[0])) {
            यदि (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) (addr + fp), (अचिह्नित दीर्घ) p[1]);
            }
            p+= 2;
        }
    }
#यदि_अन्तः
}

/* used by alloca */
शून्य __bound_new_region(शून्य *p, आकार_t आकार)
{
    आकार_t fp;
    alloca_list_type *चरमः;
    alloca_list_type *cur;
    alloca_list_type *new;

    यदि (NO_CHECKING_GET())
        प्रत्यागम;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिह्नित दीर्घ)आकार);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (परिमाण (alloca_list_type));
    WAIT_SEM ();
    INCR_गणनम्(bound_alloca_गणनम्);
    चरमः = रिक्त;
    cur = alloca_list;
    यावत् (cur) {
#यदि defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        पूर्णाङ्क align = 4;
#नोचेद्यदि defined(__arm__)
        पूर्णाङ्क align = 8;
#अन्यथा
        पूर्णाङ्क align = 16;
#यदि_अन्तः
        शून्य *cure = (शून्य *)((वर्ण *)cur->p + ((cur->आकार + align) & -align));
        शून्य *pe = (शून्य *)((वर्ण *)p + ((आकार + align) & -align));
        यदि (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            यदि (चरमः)
                चरमः->अग्र = cur->अग्र;
            अन्यथा
                alloca_list = cur->अग्र;
            वृक्षः_2 = splay_delete((आकार_t)cur->p, वृक्षः_2);
            भङ्ग;
        }
        चरमः = cur;
        cur = cur->अग्र;
    }
    वृक्षः_2 = splay_निवेशय((आकार_t)p, आकार, वृक्षः_2);
    यदि (new) {
        new->fp = fp;
        new->p = p;
        new->आकार = आकार;
        new->अग्र = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    यदि (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

शून्य __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    शून्य *e = (शून्य *) env;

    यदि (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_गणनम्(bound_setjmp_गणनम्);
        jl = jmp_list;
        यावत् (jl) {
            यदि (jl->penv == e)
                भङ्ग;
            jl = jl->अग्र;
        }
        यदि (jl == रिक्त) {
            jl = BOUND_MALLOC (परिमाण (jmp_list_type));
            यदि (jl) {
                jl->penv = e;
                jl->अग्र = jmp_list;
                jmp_list = jl;
            }
        }
        यदि (jl) {
            आकार_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->अन्तः_fp = (आकार_t)__builtin_frame_address(0);
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

    यदि (NO_CHECKING_GET() == 0) {
        e = (शून्य *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_गणनम्(bound_longjmp_गणनम्);
        jl = jmp_list;
        यावत् (jl) {
            यदि (jl->penv == e && jl->tid == tid) {
                आकार_t start_fp = (आकार_t)__builtin_frame_address(0);
                आकार_t अन्तः_fp = jl->अन्तः_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *चरमः = रिक्त;

                यावत् (cur->penv != e || cur->tid != tid) {
                    यदि (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        यदि (चरमः)
                            चरमः->अग्र = cur->अग्र;
                        अन्यथा
                            jmp_list = cur->अग्र;
                        BOUND_FREE (cur);
                        cur = चरमः ? चरमः->अग्र : jmp_list;
                    }
                    अन्यथा {
                        चरमः = cur;
                        cur = cur->अग्र;
                    }
                }
                प्रति (;;) {
                    वृक्षः *t = वृक्षः_2;
                    alloca_list_type *चरमः;
                    alloca_list_type *cur;

                    यावत् (t && (t->start < start_fp || t->start > अन्तः_fp))
                        यदि (t->start < start_fp)
                            t = t->दक्षिणः;
                        अन्यथा
                            t = t->वामः;
                    यदि (t == रिक्त)
                        भङ्ग;
                    चरमः = रिक्त;
                    cur = alloca_list;
                    यावत् (cur) {
                         यदि ((आकार_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             यदि (चरमः)
                                 चरमः->अग्र = cur->अग्र;
                             अन्यथा
                                 alloca_list = cur->अग्र;
                             BOUND_FREE (cur);
                             भङ्ग;
                         }
                         चरमः = cur;
                         cur = cur->अग्र;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (शून्य *) t->start);
                    वृक्षः_2 = splay_delete(t->start, वृक्षः_2);
                }
                भङ्ग;
            }
            jl = jl->अग्र;
        }
        POST_SEM();
    }
#यदि !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#यदि_अन्तः
    longjmp (env, val);
}

शून्य __bound_longjmp(jmp_buf env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#यदि !defined(_WIN32)
शून्य __bound_siglongjmp(jmp_buf env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#यदि_अन्तः

#यदि (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#निर्देशः GCC diagnostic निष्कासय
#यदि_अन्तः

शून्य __bound_init(आकार_t *p, पूर्णाङ्क बहुलकम्)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            बहुलकम् < 0 ? "lazy" : बहुलकम् == 0 ? "normal use" : "for -run");

    यदि (inited) {
        WAIT_SEM();
        गच्छ सङ्कलय_bounds;
    }
    inited = 1;

#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
    no_checking_कुञ्चिका = TlsAlloc();
    Tls_समुच्चयः_मानम्(no_checking_कुञ्चिका, &no_checking);
#अन्यथा
    pthread_key_create(&no_checking_कुञ्चिका, रिक्त);
    pthread_setspecific(no_checking_कुञ्चिका, &no_checking);
#यदि_अन्तः
#यदि_अन्तः
    NO_CHECKING_समुच्चयः(1);

    print_warn_ptr_सङ्कलय = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != रिक्त;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != रिक्त;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != रिक्त;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != रिक्त;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != रिक्त;

    INIT_SEM ();

#यदि MALLOC_REDIR
    {
        शून्य *addr = बहुलकम् > 0 ? RTLD_DEFAULT : RTLD_अग्र;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        यदि (malloc_redir == रिक्त) {
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
        यदि (malloc_redir == रिक्त || free_redir == रिक्त)
            bound_alloc_error ("Cannot redirect malloc/free");
#यदि HAVE_PTHREAD_CREATE
        *(शून्य **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        यदि (pthread_create_redir == रिक्त)
            bound_alloc_error ("Cannot redirect pthread_create");
#यदि_अन्तः
#यदि HAVE_SIGNAL
        *(शून्य **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        यदि (signal_redir == रिक्त)
            bound_alloc_error ("Cannot redirect signal");
#यदि_अन्तः
#यदि HAVE_SIGACTION
        *(शून्य **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        यदि (sigaction_redir == रिक्त)
            bound_alloc_error ("Cannot redirect sigaction");
#यदि_अन्तः
#यदि HAVE_FORK
        *(शून्य **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        यदि (fork_redir == रिक्त)
            bound_alloc_error ("Cannot redirect fork");
#यदि_अन्तः
    }
#यदि_अन्तः

#यदि_परिभाषितम् __linux__
    {
        FILE *fp;
        अचिह्नित वर्ण प्राप्तम्;
        अचिह्नित दीर्घ start;
        अचिह्नित दीर्घ अन्तः;
        अचिह्नित दीर्घ ad =
            (अचिह्नित दीर्घ) __builtin_return_address(0);
        वर्ण पङ्क्तिः[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        यदि (fp) {
            स्मृतिं_पूरय (exec, 0, परिमाण(exec));
            fread (exec, 1, परिमाण(exec) - 2, fp);
            यदि (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            वाक्यं_योजय (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        प्राप्तम् = 0;
        fp = fopen ("/proc/self/maps", "r");
        यदि (fp) {
            यावत् (fgets (पङ्क्तिः, परिमाण(पङ्क्तिः), fp)) {
                यदि (वाक्यात्_पठ (पङ्क्तिः, "%lx-%lx", &start, &अन्तः) == 2 &&
                            ad >= start && ad < अन्तः) {
                    प्राप्तम् = 1;
                    भङ्ग;
                }
                यदि (वाक्ये_अन्विष (पङ्क्तिः,"[heap]"))
                    भङ्ग;
            }
            fclose (fp);
        }
        यदि (प्राप्तम् == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#यदि_अन्तः

    WAIT_SEM ();

#यदि HAVE_CTYPE
#यदि_परिभाषितम् __APPLE__
    वृक्षः_2 = splay_निवेशय((आकार_t) &_DefaultRuneLocale,
                        परिमाण (_DefaultRuneLocale), वृक्षः_2);
#अन्यथा
    /* XXX: Does not work if locale is changed */
    वृक्षः_2 = splay_निवेशय((आकार_t) __ctype_b_loc(),
                        परिमाण (अचिह्नित ह्रस्व *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((आकार_t) (*__ctype_b_loc() - 128),
                        384 * परिमाण (अचिह्नित ह्रस्व), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((आकार_t) __ctype_tolower_loc(),
                        परिमाण (__int32_t *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((आकार_t) (*__ctype_tolower_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((आकार_t) __ctype_toupper_loc(),
                        परिमाण (__int32_t *), वृक्षः_2);
    वृक्षः_2 = splay_निवेशय((आकार_t) (*__ctype_toupper_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्षः_2);
#यदि_अन्तः
#यदि_अन्तः
#यदि HAVE_ERRNO
    वृक्षः_2 = splay_निवेशय((आकार_t) (&errno), परिमाण (पूर्णाङ्क), वृक्षः_2);
#यदि_अन्तः

सङ्कलय_bounds:
    यदि (!p)
        गच्छ no_bounds;

    /* add all static bound check values */
    यावत् (p[0] != 0) {
        वृक्षः_2 = splay_निवेशय(p[0], p[1], वृक्षः_2);
#यदि BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (शून्य *) p[0], (अचिह्नित दीर्घ) p[1]);
#यदि_अन्तः
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_समुच्चयः(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

शून्य
#यदि (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#यदि_अन्तः
__bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp)
{
    __bound_init (0, -1);
    यदि (argc && argv) {
        पूर्णाङ्क i;

        WAIT_SEM ();
        प्रति (i = 0; i < argc; i++)
            वृक्षः_2 = splay_निवेशय((आकार_t) argv[i], वाक्यदैर्घ्यम् (argv[i]) + 1, वृक्षः_2);
        वृक्षः_2 = splay_निवेशय((आकार_t) argv, (argc + 1) * परिमाण(वर्ण *), वृक्षः_2);
        POST_SEM ();
#यदि BOUND_DEBUG
        यदि (print_calls) {
            प्रति (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (अचिह्नित दीर्घ)(वाक्यदैर्घ्यम् (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (पूर्णाङ्क)((argc + 1) * परिमाण(वर्ण *)));
        }
#यदि_अन्तः
    }

    यदि (envp && *envp) {
        वर्ण **p = envp;

        WAIT_SEM ();
        यावत् (*p) {
            वृक्षः_2 = splay_निवेशय((आकार_t) *p, वाक्यदैर्घ्यम् (*p) + 1, वृक्षः_2);
            ++p;
        }
        वृक्षः_2 = splay_निवेशय((आकार_t) envp, (++p - envp) * परिमाण(वर्ण *), वृक्षः_2);
        POST_SEM ();
#यदि BOUND_DEBUG
        यदि (print_calls) {
            p = envp;
            यावत् (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (अचिह्नित दीर्घ)(वाक्यदैर्घ्यम् (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (पूर्णाङ्क)((++p - envp) * परिमाण(वर्ण *)));
        }
#यदि_अन्तः
    }
}

शून्य __attribute__((destructor)) __bound_exit(शून्य)
{
    पूर्णाङ्क i;
    स्थिर ध्रुव वर्ण * ध्रुव alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    यदि (inited) {
#यदि !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        यदि (print_heap) {
            बाह्य शून्य __libc_freeres (शून्य);
            __libc_freeres ();
        }
#यदि_अन्तः

        NO_CHECKING_समुच्चयः(1);

        TRY_SEM ();
        यावत् (alloca_list) {
            alloca_list_type *अग्र = alloca_list->अग्र;

            वृक्षः_2 = splay_delete ((आकार_t) alloca_list->p, वृक्षः_2);
            BOUND_FREE (alloca_list);
            alloca_list = अग्र;
        }
        यावत् (jmp_list) {
           jmp_list_type *अग्र  = jmp_list->अग्र;

           BOUND_FREE (jmp_list);
           jmp_list = अग्र;
        }
        प्रति (i = 0; i < FREE_REUSE_आकार; i++) {
            यदि (free_reuse_list[i]) {
                वृक्षः_2 = splay_delete ((आकार_t) free_reuse_list[i], वृक्षः_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        यावत् (वृक्षः_2) {
            यदि (print_heap && वृक्षः_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[वृक्षः_2->type],
                         (अचिह्नित दीर्घ) वृक्षः_2->आकार);
            वृक्षः_2 = splay_delete (वृक्षः_2->start, वृक्षः_2);
        }
#यदि वृक्षः_REUSE
        यावत् (वृक्षः_free_list) {
            वृक्षः *अग्र = वृक्षः_free_list->वामः;
            BOUND_FREE (वृक्षः_free_list);
            वृक्षः_free_list = अग्र;
        }
#यदि_अन्तः
        POST_SEM ();
        EXIT_SEM ();
#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
        TlsFree(no_checking_कुञ्चिका);
#अन्यथा
        pthread_key_delete(no_checking_कुञ्चिका);
#यदि_अन्तः
#यदि_अन्तः
        inited = 0;
        यदि (print_statistic) {
#यदि BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_सङ्कलय_गणनम्);
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
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_प्राप्तम्);
#यदि_अन्तः
#यदि BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_अन्तः);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_निवेशय);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#यदि_अन्तः
        }
    }
}

शून्य __bound_exit_dll(आकार_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    यदि (p) {
        WAIT_SEM ();
	यावत् (p[0] != 0) {
	    वृक्षः_2 = splay_delete(p[0], वृक्षः_2);
#यदि BOUND_DEBUG
            यदि (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) p[0], (अचिह्नित दीर्घ) p[1]);
            }
#यदि_अन्तः
	    p += 2;
	}
        POST_SEM ();
    }
}

#यदि HAVE_PTHREAD_CREATE
प्रकारनिर्देश संरचना {
    शून्य *(*start_routine) (शून्य *);
    शून्य *arg;
    sigset_t old_आवरणम्;
} bound_thread_create_type;

स्थिर शून्य *bound_thread_create(शून्य *bdata)
{
    bound_thread_create_type *दत्त = (bound_thread_create_type *) bdata;
    शून्य *retval;
#यदि HAVE_TLS_FUNC
    पूर्णाङ्क *p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));
  
    यदि (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_कुञ्चिका, p);
#यदि_अन्तः
    pthread_sigmask(SIG_SETMASK, &दत्त->old_आवरणम्, रिक्त);
    retval = दत्त->start_routine(दत्त->arg);
#यदि HAVE_TLS_FUNC
    pthread_setspecific(no_checking_कुञ्चिका, रिक्त);
    BOUND_FREE (p);
#यदि_अन्तः
    BOUND_FREE (दत्त);
    प्रत्यागम retval;
}

पूर्णाङ्क pthread_create(pthread_t *thread, ध्रुव pthread_attr_t *attr,
                   शून्य *(*start_routine) (शून्य *), शून्य *arg)
{
    पूर्णाङ्क retval;
    bound_thread_create_type *दत्त;
    sigset_t आवरणम्;
    sigset_t old_आवरणम्;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&आवरणम्);
    pthread_sigmask(SIG_SETMASK, &आवरणम्, &old_आवरणम्);
    दत्त = (bound_thread_create_type *) BOUND_MALLOC(परिमाण(bound_thread_create_type));
    यदि (!दत्त) bound_alloc_error("bound_thread_create malloc");
    दत्त->start_routine = start_routine;
    दत्त->arg = arg;
    दत्त->old_आवरणम् = old_आवरणम्;
    retval = pthread_create_redir(thread, attr, bound_thread_create, दत्त);
    pthread_sigmask(SIG_SETMASK, &old_आवरणम्, रिक्त);
    प्रत्यागम retval;
}
#यदि_अन्तः

#यदि HAVE_SIGNAL || HAVE_SIGACTION
प्रकारनिर्देश सङ्घ {
#यदि HAVE_SIGNAL
    bound_sig signal_handler;
#यदि_अन्तः
#यदि HAVE_SIGACTION
    शून्य (*sig_handler)(पूर्णाङ्क);
    शून्य (*sig_sigaction)(पूर्णाङ्क, siginfo_t *, शून्य *);
#यदि_अन्तः
} bound_sig_type;

स्थिर अचिह्नित वर्ण bound_sig_प्रयुक्तम्[NSIG];
स्थिर bound_sig_type bound_sig_दत्त[NSIG];
#यदि_अन्तः

#यदि HAVE_SIGNAL
स्थिर शून्य signal_handler(पूर्णाङ्क sig)
{
   __bounds_checking(1);
   bound_sig_दत्त[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig सङ्केत(पूर्णाङ्क signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    यदि (retval != SIG_ERR) {
        यदि (bound_sig_प्रयुक्तम्[signum])
            retval = bound_sig_दत्त[signum].signal_handler;
        यदि (handler) {
            bound_sig_प्रयुक्तम्[signum] = 1;
            bound_sig_दत्त[signum].signal_handler = handler;
        }
    }
    प्रत्यागम retval;
}
#यदि_अन्तः

#यदि HAVE_SIGACTION
स्थिर शून्य sig_handler(पूर्णाङ्क sig)
{
   __bounds_checking(1);
   bound_sig_दत्त[sig].sig_handler(sig);
   __bounds_checking(-1);
}

स्थिर शून्य sig_sigaction(पूर्णाङ्क sig, siginfo_t *info, शून्य *ucontext)
{
   __bounds_checking(1);
   bound_sig_दत्त[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

पूर्णाङ्क sigaction(पूर्णाङ्क signum, ध्रुव संरचना sigaction *act, संरचना sigaction *oldact)
{
    पूर्णाङ्क retval;
    संरचना sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    यदि (sigaction_redir == रिक्त)
        __bound_init(0,-1);

    यदि (act) {
        nact = *act;
        यदि (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        अन्यथा
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    अन्यथा
        retval = sigaction_redir(signum, act, &oact);
    यदि (retval >= 0) {
        यदि (bound_sig_प्रयुक्तम्[signum]) {
            यदि (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_दत्त[signum].sig_sigaction;
            अन्यथा
                oact.sa_handler = bound_sig_दत्त[signum].sig_handler;
        }
        यदि (oldact) {
            *oldact = oact;
        }
        यदि (act) {
            bound_sig_प्रयुक्तम्[signum] = 1;
            यदि (act->sa_flags & SA_SIGINFO)
                bound_sig_दत्त[signum].sig_sigaction = act->sa_sigaction;
            अन्यथा
                bound_sig_दत्त[signum].sig_handler = act->sa_handler;
        }
    }
    प्रत्यागम retval;
}
#यदि_अन्तः

#यदि HAVE_FORK
pid_t fork(शून्य)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    यदि (retval == 0)
        INIT_SEM();
    अन्यथा
        POST_SEM();
    प्रत्यागम retval;
}
#यदि_अन्तः

#यदि MALLOC_REDIR
शून्य *स्मृतिं_देहि(आकार_t आकार)
#अन्यथा
शून्य *__bound_malloc(आकार_t आकार, ध्रुव शून्य *caller)
#यदि_अन्तः
{
    शून्य *ptr;
    
#यदि MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    यदि (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        यदि (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_सूचकांक];
            pool_सूचकांक = (pool_सूचकांक + आकार + 15) & ~15;
            यदि (pool_सूचकांक >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिह्नित दीर्घ)आकार);
            प्रत्यागम ptr;
        }
    }
#यदि_अन्तः
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (आकार + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिह्नित दीर्घ)आकार);
    
    यदि (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_malloc_गणनम्);

        यदि (ptr) {
            वृक्षः_2 = splay_निवेशय ((आकार_t) ptr, आकार ? आकार : आकार + 1, वृक्षः_2);
            यदि (वृक्षः_2 && वृक्षः_2->start == (आकार_t) ptr)
                वृक्षः_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#यदि MALLOC_REDIR
शून्य *memalign(आकार_t align, आकार_t आकार)
#अन्यथा
शून्य *__bound_memalign(आकार_t align, आकार_t आकार, ध्रुव शून्य *caller)
#यदि_अन्तः
{
    शून्य *ptr;

#यदि HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, आकार + 1);
#अन्यथा
    यदि (align > 4) {
        /* XXX: handle it ? */
        ptr = रिक्त;
    } अन्यथा {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(आकार + 1);
    }
#यदि_अन्तः
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिह्नित दीर्घ)आकार);

    यदि (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_memalign_गणनम्);

        यदि (ptr) {
            वृक्षः_2 = splay_निवेशय((आकार_t) ptr, आकार ? आकार : आकार + 1, वृक्षः_2);
            यदि (वृक्षः_2 && वृक्षः_2->start == (आकार_t) ptr)
                वृक्षः_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#यदि MALLOC_REDIR
शून्य मुक्त(शून्य *ptr)
#अन्यथा
शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller)
#यदि_अन्तः
{
    आकार_t addr = (आकार_t) ptr;
    शून्य *p;

    यदि (ptr == रिक्त || वृक्षः_2 == रिक्त
#यदि MALLOC_REDIR
        || ((अचिह्नित वर्ण *) ptr >= &initial_pool[0] &&
            (अचिह्नित वर्ण *) ptr < &initial_pool[परिमाण(initial_pool)])
#यदि_अन्तः
        )
        प्रत्यागम;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    यदि (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_free_गणनम्);
        वृक्षः_2 = splay (addr, वृक्षः_2);
        यदि (वृक्षः_2->start == addr) {
            यदि (वृक्षः_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                प्रत्यागम;
            }
            वृक्षः_2->is_invalid = 1;
            स्मृतिं_पूरय (ptr, 0x5a, वृक्षः_2->आकार);
            p = free_reuse_list[free_reuse_सूचकांक];
            free_reuse_list[free_reuse_सूचकांक] = ptr;
            free_reuse_सूचकांक = (free_reuse_सूचकांक + 1) % FREE_REUSE_आकार;
            यदि (p)
                वृक्षः_2 = splay_delete((आकार_t)p, वृक्षः_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#यदि MALLOC_REDIR
शून्य *realloc(शून्य *ptr, आकार_t आकार)
#अन्यथा
शून्य *__bound_realloc(शून्य *ptr, आकार_t आकार, ध्रुव शून्य *caller)
#यदि_अन्तः
{
    शून्य *new_ptr;

    यदि (आकार == 0) {
#यदि MALLOC_REDIR
        मुक्त(ptr);
#अन्यथा
        __bound_free(ptr, caller);
#यदि_अन्तः
        प्रत्यागम रिक्त;
    }

    new_ptr = BOUND_REALLOC (ptr, आकार + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (अचिह्नित दीर्घ)आकार);

    यदि (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_realloc_गणनम्);

        यदि (ptr)
            वृक्षः_2 = splay_delete ((आकार_t) ptr, वृक्षः_2);
        यदि (new_ptr) {
            वृक्षः_2 = splay_निवेशय ((आकार_t) new_ptr, आकार ? आकार : आकार + 1, वृक्षः_2);
            यदि (वृक्षः_2 && वृक्षः_2->start == (आकार_t) new_ptr)
                वृक्षः_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम new_ptr;
}

#यदि MALLOC_REDIR
शून्य *शून्यस्मृतिं_देहि(आकार_t nmemb, आकार_t आकार)
#अन्यथा
शून्य *__bound_calloc(आकार_t nmemb, आकार_t आकार)
#यदि_अन्तः
{
    शून्य *ptr;

    आकार *= nmemb;
#यदि MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    यदि (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        यदि (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_सूचकांक];
            pool_सूचकांक = (pool_सूचकांक + आकार + 15) & ~15;
            यदि (pool_सूचकांक >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिह्नित दीर्घ)आकार);
            स्मृतिं_पूरय (ptr, 0, आकार);
            प्रत्यागम ptr;
        }
    }
#यदि_अन्तः
    ptr = BOUND_MALLOC(आकार + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (अचिह्नित दीर्घ)आकार);

    यदि (ptr) {
        स्मृतिं_पूरय (ptr, 0, आकार);
        यदि (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_गणनम्(bound_calloc_गणनम्);
            वृक्षः_2 = splay_निवेशय ((आकार_t) ptr, आकार ? आकार : आकार + 1, वृक्षः_2);
            यदि (वृक्षः_2 && वृक्षः_2->start == (आकार_t) ptr)
                वृक्षः_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    प्रत्यागम ptr;
}

#यदि !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, आकार_t आकार, पूर्णाङ्क prot,
                    पूर्णाङ्क flags, पूर्णाङ्क fd, off_t विस्थापनम्)
{
    शून्य *परिणाम;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिह्नित दीर्घ)आकार);
    परिणाम = mmap (start, आकार, prot, flags, fd, विस्थापनम्);
    यदि (परिणाम && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_mmap_गणनम्);
        वृक्षः_2 = splay_निवेशय((आकार_t)परिणाम, आकार, वृक्षः_2);
        POST_SEM ();
    }
    प्रत्यागम परिणाम;
}

पूर्णाङ्क __bound_munmap (शून्य *start, आकार_t आकार)
{
    पूर्णाङ्क परिणाम;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिह्नित दीर्घ)आकार);
    यदि (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गणनम्(bound_munmap_गणनम्);
        वृक्षः_2 = splay_delete ((आकार_t) start, वृक्षः_2);
        POST_SEM ();
    }
    परिणाम = munmap (start, आकार);
    प्रत्यागम परिणाम;
}
#यदि_अन्तः

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
स्थिर शून्य __bound_check(ध्रुव शून्य *p, आकार_t आकार, ध्रुव वर्ण *function)
{
    यदि (आकार != 0 && __bound_ptr_add((शून्य *)p, आकार) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (अचिह्नित दीर्घ)आकार, function);
    }
}

स्थिर पूर्णाङ्क check_overlap (ध्रुव शून्य *p1, आकार_t n1,
                          ध्रुव शून्य *p2, आकार_t n2,
                          ध्रुव वर्ण *function)
{
    ध्रुव शून्य *p1e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p1 + n1);
    ध्रुव शून्य *p2e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p2 + n2);

    यदि (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (अचिह्नित दीर्घ)n1, p2, (अचिह्नित दीर्घ)n2, function);
        प्रत्यागम never_fatal < 0;
    }
    प्रत्यागम 0;
}

शून्य *__bound_memcpy(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_mempcy_गणनम्);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    यदि (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम स्मृतिं_प्रतिलिख(dest, src, n);
}

पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, आकार_t n)
{
    ध्रुव अचिह्नित वर्ण *u1 = (ध्रुव अचिह्नित वर्ण *) s1;
    ध्रुव अचिह्नित वर्ण *u2 = (ध्रुव अचिह्नित वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memcmp_गणनम्);
    प्रति (;;) {
        यदि ((ssize_t) --n == -1)
            भङ्ग;
        अन्यथा यदि (*u1 != *u2) {
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

शून्य *__bound_memmove(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम memmove(dest, src, n);
}

शून्य *__bound_memset(शून्य *s, पूर्णाङ्क c, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memset_गणनम्);
    __bound_check(s, n, "memset");
    प्रत्यागम स्मृतिं_पूरय(s, c, n);
}

#यदि defined(__arm__) && defined(__ARM_EABI__)
शून्य *__bound___aeabi_memcpy(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_mempcy_गणनम्);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    यदि (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम __aeabi_memcpy(dest, src, n);
}

शून्य *__bound___aeabi_memmove(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove(dest, src, n);
}

शून्य *__bound___aeabi_memmove4(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove4(dest, src, n);
}

शून्य *__bound___aeabi_memmove8(शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memmove_गणनम्);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove8(dest, src, n);
}

शून्य *__bound___aeabi_memset(शून्य *s, पूर्णाङ्क c, आकार_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_memset_गणनम्);
    __bound_check(s, n, "memset");
    प्रत्यागम __aeabi_memset(s, c, n);
}
#यदि_अन्तः

पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s)
{
    ध्रुव वर्ण *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_गणनम्(bound_strlen_गणनम्);
    यावत् (*p++);
    __bound_check(s, p - s, "strlen");
    प्रत्यागम (p - s) - 1;
}

वर्ण *__bound_strcpy(वर्ण *dest, ध्रुव वर्ण *src)
{
    आकार_t len;
    ध्रुव वर्ण *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_गणनम्(bound_strcpy_गणनम्);
    यावत् (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    यदि (check_overlap(dest, len, src, len, "strcpy"))
        प्रत्यागम dest;
    प्रत्यागम वाक्यं_प्रतिलिख (dest, src);
}

वर्ण *__bound_strncpy(वर्ण *dest, ध्रुव वर्ण *src, आकार_t n)
{
    आकार_t len = n;
    ध्रुव वर्ण *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_strncpy_गणनम्);
    यावत् (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    यदि (check_overlap(dest, len, src, len, "strncpy"))
        प्रत्यागम dest;
    प्रत्यागम strncpy(dest, src, n);
}

पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2)
{
    ध्रुव अचिह्नित वर्ण *u1 = (ध्रुव अचिह्नित वर्ण *) s1;
    ध्रुव अचिह्नित वर्ण *u2 = (ध्रुव अचिह्नित वर्ण *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_गणनम्(bound_strcmp_गणनम्);
    यावत् (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ध्रुव वर्ण *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ध्रुव वर्ण *)u2 - s2) + 1, "strcmp s2");
    प्रत्यागम *u1 - *u2;
}

पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, आकार_t n)
{
    ध्रुव अचिह्नित वर्ण *u1 = (ध्रुव अचिह्नित वर्ण *) s1;
    ध्रुव अचिह्नित वर्ण *u2 = (ध्रुव अचिह्नित वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_strncmp_गणनम्);
    कुरु {
        यदि ((ssize_t) --n == -1)
            भङ्ग;
        अन्यथा यदि (*u1 != *u2) {
            retval = *u1++ - *u2++;
            भङ्ग;
        }
        ++u2;
    } यावत् (*u1++);
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
    यावत् (*dest++);
    यावत् (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    यदि (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        प्रत्यागम dest;
    प्रत्यागम वाक्यं_योजय(r, s);
}

वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, आकार_t n)
{
    वर्ण *r = dest;
    ध्रुव वर्ण *s = src;
    आकार_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिह्नित दीर्घ)n);
    INCR_गणनम्(bound_strncat_गणनम्);
    यावत् (*dest++);
    यावत् (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    यदि (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        प्रत्यागम dest;
    प्रत्यागम strncat(r, s, n);
}

वर्ण *__bound_strchr(ध्रुव वर्ण *s, पूर्णाङ्क c)
{
    ध्रुव अचिह्नित वर्ण *str = (ध्रुव अचिह्नित वर्ण *) s;
    अचिह्नित वर्ण ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गणनम्(bound_strchr_गणनम्);
    यावत् (*str) {
        यदि (*str == ch)
            भङ्ग;
        ++str;
    }
    __bound_check(s, ((ध्रुव वर्ण *)str - s) + 1, "strchr");
    प्रत्यागम *str == ch ? (वर्ण *) str : रिक्त;
}

वर्ण *__bound_strrchr(ध्रुव वर्ण *s, पूर्णाङ्क c)
{
    ध्रुव अचिह्नित वर्ण *str = (ध्रुव अचिह्नित वर्ण *) s;
    अचिह्नित वर्ण ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गणनम्(bound_strrchr_गणनम्);
    यावत् (*str++);
    __bound_check(s, (ध्रुव वर्ण *)str - s, "strrchr");
    यावत् (str != (ध्रुव अचिह्नित वर्ण *)s) {
        यदि (*--str == ch)
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
    यावत् (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (अचिह्नित दीर्घ)(p -s));
    यदि (new) {
        यदि (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            वृक्षः_2 = splay_निवेशय((आकार_t)new, p - s, वृक्षः_2);
            यदि (वृक्षः_2 && वृक्षः_2->start == (आकार_t) new)
                वृक्षः_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        स्मृतिं_प्रतिलिख (new, s, p - s);
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

#परिभाषय compare(start,tstart,tsize) (start < tstart ? -1 : \
                                     start >= tstart+tsize  ? 1 : 0)

स्थिर वृक्षः * splay (आकार_t addr, वृक्षः *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    वृक्षः N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गणनम्_SPLAY(bound_splay);
    यदि (t == रिक्त) प्रत्यागम t;
    N.वामः = N.दक्षिणः = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare(addr, t->start, t->आकार);
        यदि (comp < 0) {
            y = t->वामः;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare(addr, y->start, y->आकार) < 0) {
                t->वामः = y->दक्षिणः;                    /* rotate right */
                y->दक्षिणः = t;
                t = y;
                यदि (t->वामः == रिक्त) भङ्ग;
            }
            r->वामः = t;                               /* link right */
            r = t;
            t = t->वामः;
        } अन्यथा यदि (comp > 0) {
            y = t->दक्षिणः;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare(addr, y->start, y->आकार) > 0) {
                t->दक्षिणः = y->वामः;                    /* rotate left */
                y->वामः = t;
                t = y;
                यदि (t->दक्षिणः == रिक्त) भङ्ग;
            }
            l->दक्षिणः = t;                              /* link left */
            l = t;
            t = t->दक्षिणः;
        } अन्यथा {
            भङ्ग;
        }
    }
    l->दक्षिणः = t->वामः;                                /* assemble */
    r->वामः = t->दक्षिणः;
    t->वामः = N.दक्षिणः;
    t->दक्षिणः = N.वामः;

    प्रत्यागम t;
}

#परिभाषय compare_अन्तः(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

स्थिर वृक्षः * splay_अन्तः (आकार_t addr, वृक्षः *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    वृक्षः N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गणनम्_SPLAY(bound_splay_अन्तः);
    यदि (t == रिक्त) प्रत्यागम t;
    N.वामः = N.दक्षिणः = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare_अन्तः(addr, t->start + t->आकार);
        यदि (comp < 0) {
            y = t->वामः;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare_अन्तः(addr, y->start + y->आकार) < 0) {
                t->वामः = y->दक्षिणः;                    /* rotate right */
                y->दक्षिणः = t;
                t = y;
                यदि (t->वामः == रिक्त) भङ्ग;
            }
            r->वामः = t;                               /* link right */
            r = t;
            t = t->वामः;
        } अन्यथा यदि (comp > 0) {
            y = t->दक्षिणः;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare_अन्तः(addr, y->start + y->आकार) > 0) {
                t->दक्षिणः = y->वामः;                    /* rotate left */
                y->वामः = t;
                t = y;
                यदि (t->दक्षिणः == रिक्त) भङ्ग;
            }
            l->दक्षिणः = t;                              /* link left */
            l = t;
            t = t->दक्षिणः;
        } अन्यथा {
            भङ्ग;
        }
    }
    l->दक्षिणः = t->वामः;                                /* assemble */
    r->वामः = t->दक्षिणः;
    t->वामः = N.दक्षिणः;
    t->दक्षिणः = N.वामः;

    प्रत्यागम t;
}

स्थिर वृक्षः * splay_निवेशय(आकार_t addr, आकार_t आकार, वृक्षः * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    वृक्षः * new;

    INCR_गणनम्_SPLAY(bound_splay_निवेशय);
    यदि (t != रिक्त) {
        t = splay(addr,t);
        यदि (compare(addr, t->start, t->आकार)==0) {
            प्रत्यागम t;  /* it's already there */
        }
    }
#यदि वृक्षः_REUSE
    यदि (वृक्षः_free_list) {
          new = वृक्षः_free_list;
          वृक्षः_free_list = new->वामः;
    }
    अन्यथा
#यदि_अन्तः
    {
        new = (वृक्षः *) BOUND_MALLOC (परिमाण (वृक्षः));
    }
    यदि (new == रिक्त) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    अन्यथा {
        यदि (t == रिक्त) {
            new->वामः = new->दक्षिणः = रिक्त;
        } अन्यथा यदि (compare(addr, t->start, t->आकार) < 0) {
            new->वामः = t->वामः;
            new->दक्षिणः = t;
            t->वामः = रिक्त;
        } अन्यथा {
            new->दक्षिणः = t->दक्षिणः;
            new->वामः = t;
            t->दक्षिणः = रिक्त;
        }
        new->start = addr;
        new->आकार = आकार;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    प्रत्यागम new;
}

#परिभाषय compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

स्थिर वृक्षः * splay_delete(आकार_t addr, वृक्षः *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    वृक्षः * x;

    INCR_गणनम्_SPLAY(bound_splay_delete);
    यदि (t==रिक्त) प्रत्यागम रिक्त;
    t = splay(addr,t);
    यदि (compare_destroy(addr, t->start) == 0) {        /* found it */
        यदि (t->वामः == रिक्त) {
            x = t->दक्षिणः;
        } अन्यथा {
            x = splay(addr, t->वामः);
            x->दक्षिणः = t->दक्षिणः;
        }
#यदि वृक्षः_REUSE
        t->वामः = वृक्षः_free_list;
        वृक्षः_free_list = t;
#अन्यथा
        BOUND_FREE(t);
#यदि_अन्तः
        प्रत्यागम x;
    } अन्यथा {
        प्रत्यागम t;                                      /* It wasn't there */
    }
}

शून्य splay_printtree(वृक्षः * t, पूर्णाङ्क d)
{
    पूर्णाङ्क i;
    यदि (t == रिक्त) प्रत्यागम;
    splay_printtree(t->दक्षिणः, d+1);
    प्रति (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (शून्य *) t->start, (अचिह्नित दीर्घ) t->आकार,
            (अचिह्नित)t->type, (अचिह्नित)t->is_invalid);
    splay_printtree(t->वामः, d+1);
}
