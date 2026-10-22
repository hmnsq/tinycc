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

#जर !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#अन्तर्भाव <malloc.h>
#endif

#जर !defined(_WIN32)
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/syscall.h>
#endif

#अन्तर्भाव "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#जर BOUND_DEBUG
 #define dprintf(a...)         जर (print_calls) { bounds_loc(a); }
#अन्यथा
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#अन्यथा
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अन्यथा
# define DLL_EXPORT
#endif

#जर defined(__FreeBSD__) \
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

#किंवाजर defined(_WIN32)

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

#अन्यथा

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
#define WAIT_SEM()             जर (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             जर (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              जर (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#किंवाजर 0
#अन्तर्भाव <semaphore.h>
स्थिर sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             जर (use_sem) पर्यंत (sem_wait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#define POST_SEM()             जर (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              जर (use_sem) पर्यंत (sem_trywait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#किंवाजर 0
स्थिर pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, रिक्त)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             जर (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             जर (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              जर (use_sem) pthread_mutex_trylock (&bounds_mtx)
#अन्यथा
स्थिर pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             जर (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             जर (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              जर (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#जर defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#अन्यथा
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#जर defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#जर MALLOC_REDIR
स्थिर शून्य *(*malloc_redir) (माप_प्रकार);
स्थिर शून्य *(*calloc_redir) (माप_प्रकार, माप_प्रकार);
स्थिर शून्य (*free_redir) (शून्य *);
स्थिर शून्य *(*realloc_redir) (शून्य *, माप_प्रकार);
स्थिर अचिन्हित पूर्णांक pool_index;
स्थिर अचिन्हित अक्षर __attribute__((aligned(16))) initial_pool[256];
#endif
#जर HAVE_MEMALIGN
स्थिर शून्य *(*memalign_redir) (माप_प्रकार, माप_प्रकार);
#endif
#जर HAVE_PTHREAD_CREATE
स्थिर पूर्णांक (*pthread_create_redir) (pthread_t *thread,
                                    स्थिरांक pthread_attr_t *attr,
                                    शून्य *(*start_routine)(शून्य *), शून्य *arg);
#endif
#जर HAVE_SIGNAL
प्रकारव्याख्या शून्य (*bound_sig)(पूर्णांक);
स्थिर bound_sig (*signal_redir) (पूर्णांक signum, bound_sig handler);
#endif
#जर HAVE_SIGACTION
स्थिर पूर्णांक (*sigaction_redir) (पूर्णांक signum, स्थिरांक संरचना sigaction *act,
                               संरचना sigaction *oldact);
#endif
#जर HAVE_FORK
स्थिर पूर्णांक (*fork_redir) (शून्य);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((शून्य *)(-2))

प्रकारव्याख्या संरचना वृक्ष_गाठ वृक्ष;
संरचना वृक्ष_गाठ {
    वृक्ष * डावा, * उजवा;
    माप_प्रकार start;
    माप_प्रकार size;
    अचिन्हित अक्षर type;
    अचिन्हित अक्षर is_invalid; /* true if pointers outside region are invalid */
};

प्रकारव्याख्या संरचना alloca_list_struct {
    माप_प्रकार fp;
    शून्य *p;
    माप_प्रकार size;
    संरचना alloca_list_struct *next;
} alloca_list_type;

#जर defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#किंवाजर defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#किंवाजर defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#किंवाजर  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#किंवाजर defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#अन्यथा
#define BOUND_TID_TYPE		पूर्णांक
#define BOUND_GET_TID(id)	id = 0
#endif

प्रकारव्याख्या संरचना jmp_list_struct {
    शून्य *penv;
    माप_प्रकार fp;
    माप_प्रकार end_fp;
    BOUND_TID_TYPE tid;
    संरचना jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
स्थिर वृक्ष * splay (माप_प्रकार addr, वृक्ष *t);
स्थिर वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t);
स्थिर वृक्ष * splay_घाला(माप_प्रकार addr, माप_प्रकार size, वृक्ष * t);
स्थिर वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t);
शून्य splay_printtree(वृक्ष * t, पूर्णांक d);

/* external interface */
शून्य __bounds_checking (पूर्णांक no_check);
शून्य __bound_checking_lock (शून्य);
शून्य __bound_checking_unlock (शून्य);
शून्य __bound_never_fatal (पूर्णांक no_check);
DLL_EXPORT शून्य * __bound_ptr_add(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir1(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir2(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir4(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir8(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir12(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir16(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य FASTCALL __bound_local_new(शून्य *p1);
DLL_EXPORT शून्य FASTCALL __bound_local_delete(शून्य *p1);
शून्य __bound_init(माप_प्रकार *, पूर्णांक);
शून्य __bound_main_arg(पूर्णांक argc, अक्षर **argv, अक्षर **envp);
शून्य __bound_exit(शून्य);
शून्य __bound_exit_dll(माप_प्रकार *);
#जर !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, माप_प्रकार size, पूर्णांक prot, पूर्णांक flags, पूर्णांक fd,
                    off_t offset);
पूर्णांक __bound_munmap (शून्य *start, माप_प्रकार size);
DLL_EXPORT शून्य __bound_siglongjmp(लाँघ_बफ env, पूर्णांक val);
#endif
DLL_EXPORT शून्य __bound_new_region(शून्य *p, माप_प्रकार size);
DLL_EXPORT शून्य __bound_setjmp(लाँघ_बफ env);
DLL_EXPORT शून्य __bound_longjmp(लाँघ_बफ env, पूर्णांक val);
DLL_EXPORT शून्य *__bound_memcpy(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT पूर्णांक __bound_memcmp(स्थिरांक शून्य *s1, स्थिरांक शून्य *s2, माप_प्रकार size);
DLL_EXPORT शून्य *__bound_memmove(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound_memset(शून्य *dst, पूर्णांक c, माप_प्रकार size);
DLL_EXPORT पूर्णांक __bound_strlen(स्थिरांक अक्षर *s);
DLL_EXPORT अक्षर *__bound_strcpy(अक्षर *dst, स्थिरांक अक्षर *src);
DLL_EXPORT अक्षर *__bound_strncpy(अक्षर *dst, स्थिरांक अक्षर *src, माप_प्रकार n);
DLL_EXPORT पूर्णांक __bound_strcmp(स्थिरांक अक्षर *s1, स्थिरांक अक्षर *s2);
DLL_EXPORT पूर्णांक __bound_strncmp(स्थिरांक अक्षर *s1, स्थिरांक अक्षर *s2, माप_प्रकार n);
DLL_EXPORT अक्षर *__bound_strcat(अक्षर *dest, स्थिरांक अक्षर *src);
DLL_EXPORT अक्षर *__bound_strncat(अक्षर *dest, स्थिरांक अक्षर *src, माप_प्रकार n);
DLL_EXPORT अक्षर *__bound_strchr(स्थिरांक अक्षर *string, पूर्णांक ch);
DLL_EXPORT अक्षर *__bound_strrchr(स्थिरांक अक्षर *string, पूर्णांक ch);
DLL_EXPORT अक्षर *__bound_strdup(स्थिरांक अक्षर *s);

#जर defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT शून्य *__bound___aeabi_memcpy(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove4(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove8(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memset(शून्य *dst, पूर्णांक c, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memcpy(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove4(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove8(शून्य *dst, स्थिरांक शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memset(शून्य *dst, पूर्णांक c, माप_प्रकार size);
#endif

#जर MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#अन्यथा
#define BOUND_MALLOC(a)          दो_स्मृति(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            मुक्त(a)
#define BOUND_REALLOC(a,b)       पुनः_स्मृति(a,b)
#define BOUND_CALLOC(a,b)        सुस्मृति(a,b)
DLL_EXPORT शून्य *__bound_malloc(माप_प्रकार size, स्थिरांक शून्य *caller);
DLL_EXPORT शून्य *__bound_memalign(माप_प्रकार align, माप_प्रकार size, स्थिरांक शून्य *caller);
DLL_EXPORT शून्य __bound_free(शून्य *ptr, स्थिरांक शून्य *caller);
DLL_EXPORT शून्य *__bound_realloc(शून्य *ptr, माप_प्रकार size, स्थिरांक शून्य *caller);
DLL_EXPORT शून्य *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार size);
#endif

#define FREE_REUSE_SIZE (100)
स्थिर अचिन्हित पूर्णांक free_reuse_index;
स्थिर शून्य *free_reuse_list[FREE_REUSE_SIZE];

स्थिर वृक्ष *वृक्ष_2 = रिक्त;
#define वृक्ष_REUSE      (1)
#जर वृक्ष_REUSE
स्थिर वृक्ष *वृक्ष_free_list;
#endif
स्थिर alloca_list_type *alloca_list;
स्थिर jmp_list_type *jmp_list;

स्थिर अचिन्हित अक्षर inited;
स्थिर अचिन्हित अक्षर print_warn_ptr_add;
स्थिर अचिन्हित अक्षर print_calls;
स्थिर अचिन्हित अक्षर print_heap;
स्थिर अचिन्हित अक्षर print_statistic;
स्थिर अचिन्हित अक्षर no_strdup;
स्थिर अचिन्हित अक्षर use_sem;
स्थिर _Atomic पूर्णांक never_fatal;
#जर HAVE_TLS_FUNC
#जर defined(_WIN32)
स्थिर पूर्णांक no_checking = 0;
स्थिर DWORD no_checking_किल्ली;
#define NO_CHECKING_CHECK() जर (!p) {                                         \
                                  p = (पूर्णांक *) LocalAlloc(LPTR, आकार(पूर्णांक));  \
                                  जर (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_मूल्य(no_checking_किल्ली, p);            \
                            }
#define NO_CHECKING_GET()   ({ पूर्णांक *p = Tls_Get_मूल्य(no_checking_किल्ली);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णांक *p = Tls_Get_मूल्य(no_checking_किल्ली);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#अन्यथा
स्थिर पूर्णांक no_checking = 0;
स्थिर pthread_key_t no_checking_किल्ली;
#define NO_CHECKING_CHECK() जर (!p) {                                         \
                                  p = (पूर्णांक *) BOUND_MALLOC(आकार(पूर्णांक));      \
                                  जर (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_किल्ली, p);    \
                            }
#define NO_CHECKING_GET()   ({ पूर्णांक *p = pthread_getspecific(no_checking_किल्ली); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णांक *p = pthread_getspecific(no_checking_किल्ली);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#किंवाजर HAVE_TLS_VAR
स्थिर __thread पूर्णांक no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#अन्यथा
स्थिर _Atomic पूर्णांक no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
स्थिर अक्षर exec[100];

#जर BOUND_STATISTIC
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_add_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir1_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir2_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir4_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir8_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir12_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir16_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_local_new_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_local_delete_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_malloc_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_calloc_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_realloc_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_free_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memalign_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_mmap_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_munmap_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_alloca_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_setjmp_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_longjmp_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_mempcy_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memcmp_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memmove_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memset_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strlen_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcpy_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncpy_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcmp_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncmp_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcat_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncat_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strchr_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strrchr_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strdup_मोजणी;
स्थिर अचिन्हित दीर्घ दीर्घ bound_not_found;
#define INCR_मोजणी(x)          ++x
#अन्यथा
#define INCR_मोजणी(x)
#endif
#जर BOUND_STATISTIC_SPLAY
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_end;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_घाला;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_delete;
#define INCR_मोजणी_SPLAY(x)    ++x
#अन्यथा
#define INCR_मोजणी_SPLAY(x)
#endif

पूर्णांक tcc_backtrace(स्थिरांक अक्षर *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    करा {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } पर्यंत (0)

#define bound_error(...)            \
    करा {                            \
        bound_warning(__VA_ARGS__); \
        जर (never_fatal == 0)       \
            निकास(255);              \
    } पर्यंत (0)

#define bounds_loc(fp, ...) \
    करा {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } पर्यंत (0)

स्थिर शून्य bound_alloc_error(स्थिरांक अक्षर *s)
{
    ख_लिखो(मानक_त्रुटि,"FATAL: %s\n",s);
    निकास (1);
}

स्थिर शून्य bound_not_found_warning(स्थिरांक अक्षर *file, स्थिरांक अक्षर *function,
                                    शून्य *ptr)
{
    dprintf(मानक_त्रुटि, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
शून्य __bounds_checking (पूर्णांक no_check)
{
#जर HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#अन्यथा
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
शून्य __bound_never_fatal (पूर्णांक neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
शून्य * __bound_ptr_add(शून्य *p, माप_प्रकार offset)
{
    माप_प्रकार addr = (माप_प्रकार)p;

    जर (NO_CHECKING_GET())
        परत p + offset;

    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);

    WAIT_SEM ();
    INCR_मोजणी(bound_ptr_add_मोजणी);
    जर (वृक्ष_2) {
        addr -= वृक्ष_2->start;
        जर (addr >= वृक्ष_2->size) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        जर (addr >= वृक्ष_2->size) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay_end (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        जर (addr <= वृक्ष_2->size) {
            जर (वृक्ष_2->is_invalid || addr + offset > वृक्ष_2->size) {
                POST_SEM ();
                जर (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (दीर्घ)वृक्ष_2->start,
                                  (दीर्घ)(वृक्ष_2->start + वृक्ष_2->size - 1));
                जर (never_fatal <= 0)
                    परत INVALID_POINTER; /* return an invalid pointer */
                परत p + offset;
            }
        }
        अन्यथा जर (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_मोजणी(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            परत p + offset;
        }
    }
    POST_SEM ();
    परत p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
शून्य * __bound_ptr_indir ## dsize (शून्य *p, माप_प्रकार offset)                     \
{                                                                              \
    माप_प्रकार addr = (माप_प्रकार)p;                                                   \
                                                                               \
    जर (NO_CHECKING_GET())                                                     \
        परत p + offset;                                                     \
                                                                               \
    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_मोजणी(bound_ptr_indir ## dsize ## मोजणी);                            \
    जर (वृक्ष_2) {                                                                \
        addr -= वृक्ष_2->start;                                                   \
        जर (addr >= वृक्ष_2->size) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay (addr, वृक्ष_2);                                         \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        जर (addr >= वृक्ष_2->size) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay_end (addr, वृक्ष_2);                                     \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        जर (addr <= वृक्ष_2->size) {                                              \
            जर (वृक्ष_2->is_invalid || addr + offset + dsize > वृक्ष_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (दीर्घ)वृक्ष_2->start,            \
                              (दीर्घ)(वृक्ष_2->start + वृक्ष_2->size - 1));           \
                जर (never_fatal <= 0)                                          \
                    परत INVALID_POINTER; /* return an invalid pointer */    \
                परत p + offset;                                             \
            }                                                                  \
        }                                                                      \
        अन्यथा {                                                                 \
            INCR_मोजणी(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            परत p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    परत p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#जर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic ढकला
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (माप_प्रकार)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
शून्य FASTCALL __bound_local_new(शून्य *p1) 
{
    माप_प्रकार addr, fp, *p = p1;

    जर (NO_CHECKING_GET())
         परत;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    पर्यंत ((addr = p[0])) {
        INCR_मोजणी(bound_local_new_मोजणी);
        वृक्ष_2 = splay_घाला(addr + fp, p[1], वृक्ष_2);
        p += 2;
    }
    POST_SEM ();
#जर BOUND_DEBUG
    जर (print_calls) {
        p = p1;
        पर्यंत ((addr = p[0])) {
            dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (शून्य *) (addr + fp), (अचिन्हित दीर्घ) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
शून्य FASTCALL __bound_local_delete(शून्य *p1) 
{
    माप_प्रकार addr, fp, *p = p1;

    जर (NO_CHECKING_GET())
         परत;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    पर्यंत ((addr = p[0])) {
        INCR_मोजणी(bound_local_delete_मोजणी);
        वृक्ष_2 = splay_delete(addr + fp, वृक्ष_2);
        p += 2;
    }
    जर (alloca_list) {
        alloca_list_type *last = रिक्त;
        alloca_list_type *cur = alloca_list;

        करा {
            जर (cur->fp == fp) {
                जर (last)
                    last->next = cur->next;
                अन्यथा
                    alloca_list = cur->next;
                वृक्ष_2 = splay_delete ((माप_प्रकार) cur->p, वृक्ष_2);
                dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             अन्यथा {
                 last = cur;
                 cur = cur->next;
             }
        } पर्यंत (cur);
    }
    जर (jmp_list) {
        jmp_list_type *last = रिक्त;
        jmp_list_type *cur = jmp_list;

        करा {
            जर (cur->fp == fp) {
                जर (last)
                    last->next = cur->next;
                अन्यथा
                    jmp_list = cur->next;
                dprintf(मानक_त्रुटि, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            अन्यथा {
                last = cur;
                cur = cur->next;
            }
        } पर्यंत (cur);
    }

    POST_SEM ();
#जर BOUND_DEBUG
    जर (print_calls) {
        p = p1;
        पर्यंत ((addr = p[0])) {
            जर (addr != 1) {
                dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) (addr + fp), (अचिन्हित दीर्घ) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
शून्य __bound_new_region(शून्य *p, माप_प्रकार size)
{
    माप_प्रकार fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    जर (NO_CHECKING_GET())
        परत;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (आकार (alloca_list_type));
    WAIT_SEM ();
    INCR_मोजणी(bound_alloca_मोजणी);
    last = रिक्त;
    cur = alloca_list;
    पर्यंत (cur) {
#जर defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        पूर्णांक align = 4;
#किंवाजर defined(__arm__)
        पूर्णांक align = 8;
#अन्यथा
        पूर्णांक align = 16;
#endif
        शून्य *cure = (शून्य *)((अक्षर *)cur->p + ((cur->size + align) & -align));
        शून्य *pe = (शून्य *)((अक्षर *)p + ((size + align) & -align));
        जर (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            जर (last)
                last->next = cur->next;
            अन्यथा
                alloca_list = cur->next;
            वृक्ष_2 = splay_delete((माप_प्रकार)cur->p, वृक्ष_2);
            थांबा;
        }
        last = cur;
        cur = cur->next;
    }
    वृक्ष_2 = splay_घाला((माप_प्रकार)p, size, वृक्ष_2);
    जर (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    जर (cur) {
        dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

शून्य __bound_setjmp(लाँघ_बफ env)
{
    jmp_list_type *jl;
    शून्य *e = (शून्य *) env;

    जर (NO_CHECKING_GET() == 0) {
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_मोजणी(bound_setjmp_मोजणी);
        jl = jmp_list;
        पर्यंत (jl) {
            जर (jl->penv == e)
                थांबा;
            jl = jl->next;
        }
        जर (jl == रिक्त) {
            jl = BOUND_MALLOC (आकार (jmp_list_type));
            जर (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        जर (jl) {
            माप_प्रकार fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (माप_प्रकार)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

स्थिर शून्य __bound_long_jump(लाँघ_बफ env, पूर्णांक val, पूर्णांक sig, स्थिरांक अक्षर *func)
{
    jmp_list_type *jl;
    शून्य *e;
    BOUND_TID_TYPE tid;

    जर (NO_CHECKING_GET() == 0) {
        e = (शून्य *)env;
        BOUND_GET_TID(tid);
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_मोजणी(bound_longjmp_मोजणी);
        jl = jmp_list;
        पर्यंत (jl) {
            जर (jl->penv == e && jl->tid == tid) {
                माप_प्रकार start_fp = (माप_प्रकार)__builtin_frame_address(0);
                माप_प्रकार end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = रिक्त;

                पर्यंत (cur->penv != e || cur->tid != tid) {
                    जर (cur->tid == tid) {
                        dprintf(मानक_त्रुटि, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        जर (last)
                            last->next = cur->next;
                        अन्यथा
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    अन्यथा {
                        last = cur;
                        cur = cur->next;
                    }
                }
                साठी (;;) {
                    वृक्ष *t = वृक्ष_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    पर्यंत (t && (t->start < start_fp || t->start > end_fp))
                        जर (t->start < start_fp)
                            t = t->उजवा;
                        अन्यथा
                            t = t->डावा;
                    जर (t == रिक्त)
                        थांबा;
                    last = रिक्त;
                    cur = alloca_list;
                    पर्यंत (cur) {
                         जर ((माप_प्रकार) cur->p == t->start) {
                             dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             जर (last)
                                 last->next = cur->next;
                             अन्यथा
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             थांबा;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(मानक_त्रुटि, "%s, %s(): delete %p\n",
                            __FILE__, func, (शून्य *) t->start);
                    वृक्ष_2 = splay_delete(t->start, वृक्ष_2);
                }
                थांबा;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#जर !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    दीर्घ_लाँघ (env, val);
}

शून्य __bound_longjmp(लाँघ_बफ env, पूर्णांक val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#जर !defined(_WIN32)
शून्य __bound_siglongjmp(लाँघ_बफ env, पूर्णांक val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#जर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic काढा
#endif

शून्य __bound_init(माप_प्रकार *p, पूर्णांक mode)
{
    dprintf(मानक_त्रुटि, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    जर (inited) {
        WAIT_SEM();
        जा add_bounds;
    }
    inited = 1;

#जर HAVE_TLS_FUNC
#जर defined(_WIN32)
    no_checking_किल्ली = TlsAlloc();
    Tls_Set_मूल्य(no_checking_किल्ली, &no_checking);
#अन्यथा
    pthread_key_create(&no_checking_किल्ली, रिक्त);
    pthread_setspecific(no_checking_किल्ली, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = दो_पर्या ("TCC_BOUNDS_WARN_POINTER_ADD") != रिक्त;
    print_calls = दो_पर्या ("TCC_BOUNDS_PRINT_CALLS") != रिक्त;
    print_heap = दो_पर्या ("TCC_BOUNDS_PRINT_HEAP") != रिक्त;
    print_statistic = दो_पर्या ("TCC_BOUNDS_PRINT_STATISTIC") != रिक्त;
    never_fatal = दो_पर्या ("TCC_BOUNDS_NEVER_FATAL") != रिक्त;

    INIT_SEM ();

#जर MALLOC_REDIR
    {
        शून्य *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        जर (malloc_redir == रिक्त) {
            dprintf(मानक_त्रुटि, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(शून्य **) (&calloc_redir) = dlsym (addr, "calloc");
        *(शून्य **) (&free_redir) = dlsym (addr, "free");
        *(शून्य **) (&realloc_redir) = dlsym (addr, "realloc");
        *(शून्य **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(मानक_त्रुटि, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        जर (malloc_redir == रिक्त || free_redir == रिक्त)
            bound_alloc_error ("Cannot redirect malloc/free");
#जर HAVE_PTHREAD_CREATE
        *(शून्य **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(मानक_त्रुटि, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        जर (pthread_create_redir == रिक्त)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#जर HAVE_SIGNAL
        *(शून्य **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(मानक_त्रुटि, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        जर (signal_redir == रिक्त)
            bound_alloc_error ("Cannot redirect signal");
#endif
#जर HAVE_SIGACTION
        *(शून्य **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(मानक_त्रुटि, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        जर (sigaction_redir == रिक्त)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#जर HAVE_FORK
        *(शून्य **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(मानक_त्रुटि, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        जर (fork_redir == रिक्त)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        खाता *fp;
        अचिन्हित अक्षर found;
        अचिन्हित दीर्घ start;
        अचिन्हित दीर्घ end;
        अचिन्हित दीर्घ ad =
            (अचिन्हित दीर्घ) __builtin_return_address(0);
        अक्षर ओळ[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = ख_खोलो ("/proc/self/comm", "r");
        जर (fp) {
            स_रखो (exec, 0, आकार(exec));
            ख_पढ़ो (exec, 1, आकार(exec) - 2, fp);
            जर (म_अक्षर(exec,'\n'))
                *म_अक्षर(exec,'\n') = '\0';
            म_जोड़ो (exec, ":");
            ख_बंद (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = ख_खोलो ("/proc/self/maps", "r");
        जर (fp) {
            पर्यंत (ख_माला_लो (ओळ, आकार(ओळ), fp)) {
                जर (माला_पूछो (ओळ, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    थांबा;
                }
                जर (म_माला (ओळ,"[heap]"))
                    थांबा;
            }
            ख_बंद (fp);
        }
        जर (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#जर HAVE_CTYPE
#ifdef __APPLE__
    वृक्ष_2 = splay_घाला((माप_प्रकार) &_DefaultRuneLocale,
                        आकार (_DefaultRuneLocale), वृक्ष_2);
#अन्यथा
    /* XXX: Does not work if locale is changed */
    वृक्ष_2 = splay_घाला((माप_प्रकार) __ctype_b_loc(),
                        आकार (अचिन्हित लघु *), वृक्ष_2);
    वृक्ष_2 = splay_घाला((माप_प्रकार) (*__ctype_b_loc() - 128),
                        384 * आकार (अचिन्हित लघु), वृक्ष_2);
    वृक्ष_2 = splay_घाला((माप_प्रकार) __ctype_tolower_loc(),
                        आकार (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_घाला((माप_प्रकार) (*__ctype_tolower_loc() - 128),
                        384 * आकार (__int32_t), वृक्ष_2);
    वृक्ष_2 = splay_घाला((माप_प्रकार) __ctype_toupper_loc(),
                        आकार (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_घाला((माप_प्रकार) (*__ctype_toupper_loc() - 128),
                        384 * आकार (__int32_t), वृक्ष_2);
#endif
#endif
#जर HAVE_ERRNO
    वृक्ष_2 = splay_घाला((माप_प्रकार) (&त्रुटि_सं), आकार (पूर्णांक), वृक्ष_2);
#endif

add_bounds:
    जर (!p)
        जा no_bounds;

    /* add all static bound check values */
    पर्यंत (p[0] != 0) {
        वृक्ष_2 = splay_घाला(p[0], p[1], वृक्ष_2);
#जर BOUND_DEBUG
        dprintf(मानक_त्रुटि, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (शून्य *) p[0], (अचिन्हित दीर्घ) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(मानक_त्रुटि, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

शून्य
#जर (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(पूर्णांक argc, अक्षर **argv, अक्षर **envp)
{
    __bound_init (0, -1);
    जर (argc && argv) {
        पूर्णांक i;

        WAIT_SEM ();
        साठी (i = 0; i < argc; i++)
            वृक्ष_2 = splay_घाला((माप_प्रकार) argv[i], म_माप (argv[i]) + 1, वृक्ष_2);
        वृक्ष_2 = splay_घाला((माप_प्रकार) argv, (argc + 1) * आकार(अक्षर *), वृक्ष_2);
        POST_SEM ();
#जर BOUND_DEBUG
        जर (print_calls) {
            साठी (i = 0; i < argc; i++)
                dprintf(मानक_त्रुटि, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (अचिन्हित दीर्घ)(म_माप (argv[i]) + 1));
            dprintf(मानक_त्रुटि, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (पूर्णांक)((argc + 1) * आकार(अक्षर *)));
        }
#endif
    }

    जर (envp && *envp) {
        अक्षर **p = envp;

        WAIT_SEM ();
        पर्यंत (*p) {
            वृक्ष_2 = splay_घाला((माप_प्रकार) *p, म_माप (*p) + 1, वृक्ष_2);
            ++p;
        }
        वृक्ष_2 = splay_घाला((माप_प्रकार) envp, (++p - envp) * आकार(अक्षर *), वृक्ष_2);
        POST_SEM ();
#जर BOUND_DEBUG
        जर (print_calls) {
            p = envp;
            पर्यंत (*p) {
                dprintf(मानक_त्रुटि, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (अचिन्हित दीर्घ)(म_माप (*p) + 1));
                ++p;
            }
            dprintf(मानक_त्रुटि, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (पूर्णांक)((++p - envp) * आकार(अक्षर *)));
        }
#endif
    }
}

शून्य __attribute__((destructor)) __bound_exit(शून्य)
{
    पूर्णांक i;
    स्थिर स्थिरांक अक्षर * स्थिरांक alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(मानक_त्रुटि, "%s, %s():\n", __FILE__, __FUNCTION__);

    जर (inited) {
#जर !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        जर (print_heap) {
            बाह्य शून्य __libc_freeres (शून्य);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        पर्यंत (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            वृक्ष_2 = splay_delete ((माप_प्रकार) alloca_list->p, वृक्ष_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        पर्यंत (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        साठी (i = 0; i < FREE_REUSE_SIZE; i++) {
            जर (free_reuse_list[i]) {
                वृक्ष_2 = splay_delete ((माप_प्रकार) free_reuse_list[i], वृक्ष_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        पर्यंत (वृक्ष_2) {
            जर (print_heap && वृक्ष_2->type != 0)
                ख_लिखो (मानक_त्रुटि, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[वृक्ष_2->type],
                         (अचिन्हित दीर्घ) वृक्ष_2->size);
            वृक्ष_2 = splay_delete (वृक्ष_2->start, वृक्ष_2);
        }
#जर वृक्ष_REUSE
        पर्यंत (वृक्ष_free_list) {
            वृक्ष *next = वृक्ष_free_list->डावा;
            BOUND_FREE (वृक्ष_free_list);
            वृक्ष_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#जर HAVE_TLS_FUNC
#जर defined(_WIN32)
        TlsFree(no_checking_किल्ली);
#अन्यथा
        pthread_key_delete(no_checking_किल्ली);
#endif
#endif
        inited = 0;
        जर (print_statistic) {
#जर BOUND_STATISTIC
            ख_लिखो (मानक_त्रुटि, "bound_ptr_add_count      %llu\n", bound_ptr_add_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_local_new_count    %llu\n", bound_local_new_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_local_delete_count %llu\n", bound_local_delete_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_malloc_count       %llu\n", bound_malloc_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_calloc_count       %llu\n", bound_calloc_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_realloc_count      %llu\n", bound_realloc_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_free_count         %llu\n", bound_free_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_memalign_count     %llu\n", bound_memalign_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_mmap_count         %llu\n", bound_mmap_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_munmap_count       %llu\n", bound_munmap_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_alloca_count       %llu\n", bound_alloca_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_setjmp_count       %llu\n", bound_setjmp_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_longjmp_count      %llu\n", bound_longjmp_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_mempcy_count       %llu\n", bound_mempcy_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_memcmp_count       %llu\n", bound_memcmp_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_memmove_count      %llu\n", bound_memmove_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_memset_count       %llu\n", bound_memset_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strlen_count       %llu\n", bound_strlen_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strcpy_count       %llu\n", bound_strcpy_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strncpy_count      %llu\n", bound_strncpy_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strcmp_count       %llu\n", bound_strcmp_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strncmp_count      %llu\n", bound_strncmp_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strcat_count       %llu\n", bound_strcat_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strncat_count      %llu\n", bound_strncat_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strchr_count       %llu\n", bound_strchr_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strrchr_count      %llu\n", bound_strrchr_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_strdup_count       %llu\n", bound_strdup_मोजणी);
            ख_लिखो (मानक_त्रुटि, "bound_not_found          %llu\n", bound_not_found);
#endif
#जर BOUND_STATISTIC_SPLAY
            ख_लिखो (मानक_त्रुटि, "bound_splay              %llu\n", bound_splay);
            ख_लिखो (मानक_त्रुटि, "bound_splay_end          %llu\n", bound_splay_end);
            ख_लिखो (मानक_त्रुटि, "bound_splay_insert       %llu\n", bound_splay_घाला);
            ख_लिखो (मानक_त्रुटि, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

शून्य __bound_exit_dll(माप_प्रकार *p)
{
    dprintf(मानक_त्रुटि, "%s, %s()\n", __FILE__, __FUNCTION__);

    जर (p) {
        WAIT_SEM ();
	पर्यंत (p[0] != 0) {
	    वृक्ष_2 = splay_delete(p[0], वृक्ष_2);
#जर BOUND_DEBUG
            जर (print_calls) {
                dprintf(मानक_त्रुटि, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (शून्य *) p[0], (अचिन्हित दीर्घ) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#जर HAVE_PTHREAD_CREATE
प्रकारव्याख्या संरचना {
    शून्य *(*start_routine) (शून्य *);
    शून्य *arg;
    sigset_t old_mask;
} bound_thread_create_type;

स्थिर शून्य *bound_thread_create(शून्य *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    शून्य *retval;
#जर HAVE_TLS_FUNC
    पूर्णांक *p = (पूर्णांक *) BOUND_MALLOC(आकार(पूर्णांक));
  
    जर (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_किल्ली, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, रिक्त);
    retval = data->start_routine(data->arg);
#जर HAVE_TLS_FUNC
    pthread_setspecific(no_checking_किल्ली, रिक्त);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    परत retval;
}

पूर्णांक pthread_create(pthread_t *thread, स्थिरांक pthread_attr_t *attr,
                   शून्य *(*start_routine) (शून्य *), शून्य *arg)
{
    पूर्णांक retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (मानक_त्रुटि, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(आकार(bound_thread_create_type));
    जर (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, रिक्त);
    परत retval;
}
#endif

#जर HAVE_SIGNAL || HAVE_SIGACTION
प्रकारव्याख्या संघ {
#जर HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#जर HAVE_SIGACTION
    शून्य (*sig_handler)(पूर्णांक);
    शून्य (*sig_sigaction)(पूर्णांक, siginfo_t *, शून्य *);
#endif
} bound_sig_type;

स्थिर अचिन्हित अक्षर bound_sig_used[NSIG];
स्थिर bound_sig_type bound_sig_data[NSIG];
#endif

#जर HAVE_SIGNAL
स्थिर शून्य signal_handler(पूर्णांक sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig संकेत(पूर्णांक signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (मानक_त्रुटि, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    जर (retval != संक_त्रुटि) {
        जर (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        जर (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    परत retval;
}
#endif

#जर HAVE_SIGACTION
स्थिर शून्य sig_handler(पूर्णांक sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

स्थिर शून्य sig_sigaction(पूर्णांक sig, siginfo_t *info, शून्य *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

पूर्णांक sigaction(पूर्णांक signum, स्थिरांक संरचना sigaction *act, संरचना sigaction *oldact)
{
    पूर्णांक retval;
    संरचना sigaction nact, oact;

    dprintf (मानक_त्रुटि, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    जर (sigaction_redir == रिक्त)
        __bound_init(0,-1);

    जर (act) {
        nact = *act;
        जर (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        अन्यथा
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    अन्यथा
        retval = sigaction_redir(signum, act, &oact);
    जर (retval >= 0) {
        जर (bound_sig_used[signum]) {
            जर (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            अन्यथा
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        जर (oldact) {
            *oldact = oact;
        }
        जर (act) {
            bound_sig_used[signum] = 1;
            जर (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            अन्यथा
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    परत retval;
}
#endif

#जर HAVE_FORK
pid_t विभाजन(शून्य)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    जर (retval == 0)
        INIT_SEM();
    अन्यथा
        POST_SEM();
    परत retval;
}
#endif

#जर MALLOC_REDIR
शून्य *दो_स्मृति(माप_प्रकार size)
#अन्यथा
शून्य *__bound_malloc(माप_प्रकार size, स्थिरांक शून्य *caller)
#endif
{
    शून्य *ptr;
    
#जर MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    जर (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        जर (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            जर (pool_index >= आकार (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
            परत ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
    
    जर (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_malloc_मोजणी);

        जर (ptr) {
            वृक्ष_2 = splay_घाला ((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            जर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    परत ptr;
}

#जर MALLOC_REDIR
शून्य *memalign(माप_प्रकार align, माप_प्रकार size)
#अन्यथा
शून्य *__bound_memalign(माप_प्रकार align, माप_प्रकार size, स्थिरांक शून्य *caller)
#endif
{
    शून्य *ptr;

#जर HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#अन्यथा
    जर (align > 4) {
        /* XXX: handle it ? */
        ptr = रिक्त;
    } अन्यथा {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);

    जर (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_memalign_मोजणी);

        जर (ptr) {
            वृक्ष_2 = splay_घाला((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            जर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    परत ptr;
}

#जर MALLOC_REDIR
शून्य मुक्त(शून्य *ptr)
#अन्यथा
शून्य __bound_free(शून्य *ptr, स्थिरांक शून्य *caller)
#endif
{
    माप_प्रकार addr = (माप_प्रकार) ptr;
    शून्य *p;

    जर (ptr == रिक्त || वृक्ष_2 == रिक्त
#जर MALLOC_REDIR
        || ((अचिन्हित अक्षर *) ptr >= &initial_pool[0] &&
            (अचिन्हित अक्षर *) ptr < &initial_pool[आकार(initial_pool)])
#endif
        )
        परत;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    जर (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_free_मोजणी);
        वृक्ष_2 = splay (addr, वृक्ष_2);
        जर (वृक्ष_2->start == addr) {
            जर (वृक्ष_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                परत;
            }
            वृक्ष_2->is_invalid = 1;
            स_रखो (ptr, 0x5a, वृक्ष_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            जर (p)
                वृक्ष_2 = splay_delete((माप_प्रकार)p, वृक्ष_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#जर MALLOC_REDIR
शून्य *पुनः_स्मृति(शून्य *ptr, माप_प्रकार size)
#अन्यथा
शून्य *__bound_realloc(शून्य *ptr, माप_प्रकार size, स्थिरांक शून्य *caller)
#endif
{
    शून्य *new_ptr;

    जर (size == 0) {
#जर MALLOC_REDIR
        मुक्त(ptr);
#अन्यथा
        __bound_free(ptr, caller);
#endif
        परत रिक्त;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (अचिन्हित दीर्घ)size);

    जर (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_realloc_मोजणी);

        जर (ptr)
            वृक्ष_2 = splay_delete ((माप_प्रकार) ptr, वृक्ष_2);
        जर (new_ptr) {
            वृक्ष_2 = splay_घाला ((माप_प्रकार) new_ptr, size ? size : size + 1, वृक्ष_2);
            जर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new_ptr)
                वृक्ष_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    परत new_ptr;
}

#जर MALLOC_REDIR
शून्य *सुस्मृति(माप_प्रकार nmemb, माप_प्रकार size)
#अन्यथा
शून्य *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार size)
#endif
{
    शून्य *ptr;

    size *= nmemb;
#जर MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    जर (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        जर (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            जर (pool_index >= आकार (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
            स_रखो (ptr, 0, size);
            परत ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);

    जर (ptr) {
        स_रखो (ptr, 0, size);
        जर (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_मोजणी(bound_calloc_मोजणी);
            वृक्ष_2 = splay_घाला ((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            जर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    परत ptr;
}

#जर !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, माप_प्रकार size, पूर्णांक prot,
                    पूर्णांक flags, पूर्णांक fd, off_t offset)
{
    शून्य *result;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिन्हित दीर्घ)size);
    result = mmap (start, size, prot, flags, fd, offset);
    जर (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_mmap_मोजणी);
        वृक्ष_2 = splay_घाला((माप_प्रकार)result, size, वृक्ष_2);
        POST_SEM ();
    }
    परत result;
}

पूर्णांक __bound_munmap (शून्य *start, माप_प्रकार size)
{
    पूर्णांक result;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिन्हित दीर्घ)size);
    जर (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_मोजणी(bound_munmap_मोजणी);
        वृक्ष_2 = splay_delete ((माप_प्रकार) start, वृक्ष_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    परत result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
स्थिर शून्य __bound_check(स्थिरांक शून्य *p, माप_प्रकार size, स्थिरांक अक्षर *function)
{
    जर (size != 0 && __bound_ptr_add((शून्य *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (अचिन्हित दीर्घ)size, function);
    }
}

स्थिर पूर्णांक check_overlap (स्थिरांक शून्य *p1, माप_प्रकार n1,
                          स्थिरांक शून्य *p2, माप_प्रकार n2,
                          स्थिरांक अक्षर *function)
{
    स्थिरांक शून्य *p1e = (स्थिरांक शून्य *) ((स्थिरांक अक्षर *) p1 + n1);
    स्थिरांक शून्य *p2e = (स्थिरांक शून्य *) ((स्थिरांक अक्षर *) p2 + n2);

    जर (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (अचिन्हित दीर्घ)n1, p2, (अचिन्हित दीर्घ)n2, function);
        परत never_fatal < 0;
    }
    परत 0;
}

शून्य *__bound_memcpy(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_mempcy_मोजणी);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    जर (check_overlap(dest, n, src, n, "memcpy"))
        परत dest;
    परत स_नकल(dest, src, n);
}

पूर्णांक __bound_memcmp(स्थिरांक शून्य *s1, स्थिरांक शून्य *s2, माप_प्रकार n)
{
    स्थिरांक अचिन्हित अक्षर *u1 = (स्थिरांक अचिन्हित अक्षर *) s1;
    स्थिरांक अचिन्हित अक्षर *u2 = (स्थिरांक अचिन्हित अक्षर *) s2;
    पूर्णांक retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memcmp_मोजणी);
    साठी (;;) {
        जर ((ssize_t) --n == -1)
            थांबा;
        अन्यथा जर (*u1 != *u2) {
            retval = *u1++ - *u2++;
            थांबा;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (स्थिरांक शून्य *)u1 - s1, "memcmp s1");
    __bound_check(s2, (स्थिरांक शून्य *)u2 - s2, "memcmp s2");
    परत retval;
}

शून्य *__bound_memmove(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memmove_मोजणी);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    परत स_हटाओ(dest, src, n);
}

शून्य *__bound_memset(शून्य *s, पूर्णांक c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memset_मोजणी);
    __bound_check(s, n, "memset");
    परत स_रखो(s, c, n);
}

#जर defined(__arm__) && defined(__ARM_EABI__)
शून्य *__bound___aeabi_memcpy(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_mempcy_मोजणी);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    जर (check_overlap(dest, n, src, n, "memcpy"))
        परत dest;
    परत __aeabi_memcpy(dest, src, n);
}

शून्य *__bound___aeabi_memmove(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memmove_मोजणी);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    परत __aeabi_memmove(dest, src, n);
}

शून्य *__bound___aeabi_memmove4(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memmove_मोजणी);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    परत __aeabi_memmove4(dest, src, n);
}

शून्य *__bound___aeabi_memmove8(शून्य *dest, स्थिरांक शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memmove_मोजणी);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    परत __aeabi_memmove8(dest, src, n);
}

शून्य *__bound___aeabi_memset(शून्य *s, पूर्णांक c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_memset_मोजणी);
    __bound_check(s, n, "memset");
    परत __aeabi_memset(s, c, n);
}
#endif

पूर्णांक __bound_strlen(स्थिरांक अक्षर *s)
{
    स्थिरांक अक्षर *p = s;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_मोजणी(bound_strlen_मोजणी);
    पर्यंत (*p++);
    __bound_check(s, p - s, "strlen");
    परत (p - s) - 1;
}

अक्षर *__bound_strcpy(अक्षर *dest, स्थिरांक अक्षर *src)
{
    माप_प्रकार len;
    स्थिरांक अक्षर *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_मोजणी(bound_strcpy_मोजणी);
    पर्यंत (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    जर (check_overlap(dest, len, src, len, "strcpy"))
        परत dest;
    परत म_नकल (dest, src);
}

अक्षर *__bound_strncpy(अक्षर *dest, स्थिरांक अक्षर *src, माप_प्रकार n)
{
    माप_प्रकार len = n;
    स्थिरांक अक्षर *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_strncpy_मोजणी);
    पर्यंत (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    जर (check_overlap(dest, len, src, len, "strncpy"))
        परत dest;
    परत म_नकलन(dest, src, n);
}

पूर्णांक __bound_strcmp(स्थिरांक अक्षर *s1, स्थिरांक अक्षर *s2)
{
    स्थिरांक अचिन्हित अक्षर *u1 = (स्थिरांक अचिन्हित अक्षर *) s1;
    स्थिरांक अचिन्हित अक्षर *u2 = (स्थिरांक अचिन्हित अक्षर *) s2;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_मोजणी(bound_strcmp_मोजणी);
    पर्यंत (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((स्थिरांक अक्षर *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((स्थिरांक अक्षर *)u2 - s2) + 1, "strcmp s2");
    परत *u1 - *u2;
}

पूर्णांक __bound_strncmp(स्थिरांक अक्षर *s1, स्थिरांक अक्षर *s2, माप_प्रकार n)
{
    स्थिरांक अचिन्हित अक्षर *u1 = (स्थिरांक अचिन्हित अक्षर *) s1;
    स्थिरांक अचिन्हित अक्षर *u2 = (स्थिरांक अचिन्हित अक्षर *) s2;
    पूर्णांक retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_strncmp_मोजणी);
    करा {
        जर ((ssize_t) --n == -1)
            थांबा;
        अन्यथा जर (*u1 != *u2) {
            retval = *u1++ - *u2++;
            थांबा;
        }
        ++u2;
    } पर्यंत (*u1++);
    __bound_check(s1, (स्थिरांक अक्षर *)u1 - s1, "strncmp s1");
    __bound_check(s2, (स्थिरांक अक्षर *)u2 - s2, "strncmp s2");
    परत retval;
}

अक्षर *__bound_strcat(अक्षर *dest, स्थिरांक अक्षर *src)
{
    अक्षर *r = dest;
    स्थिरांक अक्षर *s = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_मोजणी(bound_strcat_मोजणी);
    पर्यंत (*dest++);
    पर्यंत (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    जर (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        परत dest;
    परत म_जोड़ो(r, s);
}

अक्षर *__bound_strncat(अक्षर *dest, स्थिरांक अक्षर *src, माप_प्रकार n)
{
    अक्षर *r = dest;
    स्थिरांक अक्षर *s = src;
    माप_प्रकार len = n;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_मोजणी(bound_strncat_मोजणी);
    पर्यंत (*dest++);
    पर्यंत (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    जर (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        परत dest;
    परत म_जोड़न(r, s, n);
}

अक्षर *__bound_strchr(स्थिरांक अक्षर *s, पूर्णांक c)
{
    स्थिरांक अचिन्हित अक्षर *str = (स्थिरांक अचिन्हित अक्षर *) s;
    अचिन्हित अक्षर ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_मोजणी(bound_strchr_मोजणी);
    पर्यंत (*str) {
        जर (*str == ch)
            थांबा;
        ++str;
    }
    __bound_check(s, ((स्थिरांक अक्षर *)str - s) + 1, "strchr");
    परत *str == ch ? (अक्षर *) str : रिक्त;
}

अक्षर *__bound_strrchr(स्थिरांक अक्षर *s, पूर्णांक c)
{
    स्थिरांक अचिन्हित अक्षर *str = (स्थिरांक अचिन्हित अक्षर *) s;
    अचिन्हित अक्षर ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_मोजणी(bound_strrchr_मोजणी);
    पर्यंत (*str++);
    __bound_check(s, (स्थिरांक अक्षर *)str - s, "strrchr");
    पर्यंत (str != (स्थिरांक अचिन्हित अक्षर *)s) {
        जर (*--str == ch)
            थांबा;
    }
    __bound_check(s, (स्थिरांक अक्षर *)str - s, "strrchr");
    परत *str == ch ? (अक्षर *) str : रिक्त;
}

अक्षर *__bound_strdup(स्थिरांक अक्षर *s)
{
    स्थिरांक अक्षर *p = s;
    अक्षर *new;

    INCR_मोजणी(bound_strdup_मोजणी);
    पर्यंत (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (अचिन्हित दीर्घ)(p -s));
    जर (new) {
        जर (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            वृक्ष_2 = splay_घाला((माप_प्रकार)new, p - s, वृक्ष_2);
            जर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new)
                वृक्ष_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        स_नकल (new, s, p - s);
    }
    परत new;
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

स्थिर वृक्ष * splay (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    वृक्ष N, *l, *r, *y;
    पूर्णांक comp;
    
    INCR_मोजणी_SPLAY(bound_splay);
    जर (t == रिक्त) परत t;
    N.डावा = N.उजवा = रिक्त;
    l = r = &N;
 
    साठी (;;) {
        comp = compare(addr, t->start, t->size);
        जर (comp < 0) {
            y = t->डावा;
            जर (y == रिक्त) थांबा;
            जर (compare(addr, y->start, y->size) < 0) {
                t->डावा = y->उजवा;                    /* rotate right */
                y->उजवा = t;
                t = y;
                जर (t->डावा == रिक्त) थांबा;
            }
            r->डावा = t;                               /* link right */
            r = t;
            t = t->डावा;
        } अन्यथा जर (comp > 0) {
            y = t->उजवा;
            जर (y == रिक्त) थांबा;
            जर (compare(addr, y->start, y->size) > 0) {
                t->उजवा = y->डावा;                    /* rotate left */
                y->डावा = t;
                t = y;
                जर (t->उजवा == रिक्त) थांबा;
            }
            l->उजवा = t;                              /* link left */
            l = t;
            t = t->उजवा;
        } अन्यथा {
            थांबा;
        }
    }
    l->उजवा = t->डावा;                                /* assemble */
    r->डावा = t->उजवा;
    t->डावा = N.उजवा;
    t->उजवा = N.डावा;

    परत t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

स्थिर वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    वृक्ष N, *l, *r, *y;
    पूर्णांक comp;
    
    INCR_मोजणी_SPLAY(bound_splay_end);
    जर (t == रिक्त) परत t;
    N.डावा = N.उजवा = रिक्त;
    l = r = &N;
 
    साठी (;;) {
        comp = compare_end(addr, t->start + t->size);
        जर (comp < 0) {
            y = t->डावा;
            जर (y == रिक्त) थांबा;
            जर (compare_end(addr, y->start + y->size) < 0) {
                t->डावा = y->उजवा;                    /* rotate right */
                y->उजवा = t;
                t = y;
                जर (t->डावा == रिक्त) थांबा;
            }
            r->डावा = t;                               /* link right */
            r = t;
            t = t->डावा;
        } अन्यथा जर (comp > 0) {
            y = t->उजवा;
            जर (y == रिक्त) थांबा;
            जर (compare_end(addr, y->start + y->size) > 0) {
                t->उजवा = y->डावा;                    /* rotate left */
                y->डावा = t;
                t = y;
                जर (t->उजवा == रिक्त) थांबा;
            }
            l->उजवा = t;                              /* link left */
            l = t;
            t = t->उजवा;
        } अन्यथा {
            थांबा;
        }
    }
    l->उजवा = t->डावा;                                /* assemble */
    r->डावा = t->उजवा;
    t->डावा = N.उजवा;
    t->उजवा = N.डावा;

    परत t;
}

स्थिर वृक्ष * splay_घाला(माप_प्रकार addr, माप_प्रकार size, वृक्ष * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    वृक्ष * new;

    INCR_मोजणी_SPLAY(bound_splay_घाला);
    जर (t != रिक्त) {
        t = splay(addr,t);
        जर (compare(addr, t->start, t->size)==0) {
            परत t;  /* it's already there */
        }
    }
#जर वृक्ष_REUSE
    जर (वृक्ष_free_list) {
          new = वृक्ष_free_list;
          वृक्ष_free_list = new->डावा;
    }
    अन्यथा
#endif
    {
        new = (वृक्ष *) BOUND_MALLOC (आकार (वृक्ष));
    }
    जर (new == रिक्त) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    अन्यथा {
        जर (t == रिक्त) {
            new->डावा = new->उजवा = रिक्त;
        } अन्यथा जर (compare(addr, t->start, t->size) < 0) {
            new->डावा = t->डावा;
            new->उजवा = t;
            t->डावा = रिक्त;
        } अन्यथा {
            new->उजवा = t->उजवा;
            new->डावा = t;
            t->उजवा = रिक्त;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    परत new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

स्थिर वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    वृक्ष * x;

    INCR_मोजणी_SPLAY(bound_splay_delete);
    जर (t==रिक्त) परत रिक्त;
    t = splay(addr,t);
    जर (compare_destroy(addr, t->start) == 0) {        /* found it */
        जर (t->डावा == रिक्त) {
            x = t->उजवा;
        } अन्यथा {
            x = splay(addr, t->डावा);
            x->उजवा = t->उजवा;
        }
#जर वृक्ष_REUSE
        t->डावा = वृक्ष_free_list;
        वृक्ष_free_list = t;
#अन्यथा
        BOUND_FREE(t);
#endif
        परत x;
    } अन्यथा {
        परत t;                                      /* It wasn't there */
    }
}

शून्य splay_printtree(वृक्ष * t, पूर्णांक d)
{
    पूर्णांक i;
    जर (t == रिक्त) परत;
    splay_printtree(t->उजवा, d+1);
    साठी (i=0; i<d; i++) ख_लिखो(मानक_त्रुटि," ");
    ख_लिखो(मानक_त्रुटि,"%p(0x%lx:%u:%u)\n",
            (शून्य *) t->start, (अचिन्हित दीर्घ) t->size,
            (अचिन्हित)t->type, (अचिन्हित)t->is_invalid);
    splay_printtree(t->डावा, d+1);
}
