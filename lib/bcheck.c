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
#endif

#यदि !defined(_WIN32)
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/syscall.h>
#endif

#अन्तर्भाव "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#यदि BOUND_DEBUG
 #define dprintf(a...)         यदि (print_calls) { bounds_loc(a); }
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

#यदि defined(__FreeBSD__) \
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
#define WAIT_SEM()             यदि (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             यदि (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              यदि (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#नोचेद्यदि 0
#अन्तर्भाव <semaphore.h>
स्थिर sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             यदि (use_sem) यावत् (sem_wait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#define POST_SEM()             यदि (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              यदि (use_sem) यावत् (sem_trywait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#नोचेद्यदि 0
स्थिर pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, रिक्त)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             यदि (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             यदि (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              यदि (use_sem) pthread_mutex_trylock (&bounds_mtx)
#अन्यथा
स्थिर pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             यदि (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             यदि (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              यदि (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#यदि defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#अन्यथा
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#यदि defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#यदि MALLOC_REDIR
स्थिर शून्य *(*malloc_redir) (माप_प्रकार);
स्थिर शून्य *(*calloc_redir) (माप_प्रकार, माप_प्रकार);
स्थिर शून्य (*free_redir) (शून्य *);
स्थिर शून्य *(*realloc_redir) (शून्य *, माप_प्रकार);
स्थिर अचिन्हित पूर्णाङ्क pool_index;
स्थिर अचिन्हित वर्ण __attribute__((aligned(16))) initial_pool[256];
#endif
#यदि HAVE_MEMALIGN
स्थिर शून्य *(*memalign_redir) (माप_प्रकार, माप_प्रकार);
#endif
#यदि HAVE_PTHREAD_CREATE
स्थिर पूर्णाङ्क (*pthread_create_redir) (pthread_t *thread,
                                    ध्रुव pthread_attr_t *attr,
                                    शून्य *(*start_routine)(शून्य *), शून्य *arg);
#endif
#यदि HAVE_SIGNAL
प्रकारनिर्देश शून्य (*bound_sig)(पूर्णाङ्क);
स्थिर bound_sig (*signal_redir) (पूर्णाङ्क signum, bound_sig handler);
#endif
#यदि HAVE_SIGACTION
स्थिर पूर्णाङ्क (*sigaction_redir) (पूर्णाङ्क signum, ध्रुव संरचना sigaction *act,
                               संरचना sigaction *oldact);
#endif
#यदि HAVE_FORK
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

प्रकारनिर्देश संरचना वृक्ष_गाँठ वृक्ष;
संरचना वृक्ष_गाँठ {
    वृक्ष * बायाँ, * दायाँ;
    माप_प्रकार start;
    माप_प्रकार size;
    अचिन्हित वर्ण type;
    अचिन्हित वर्ण is_invalid; /* true if pointers outside region are invalid */
};

प्रकारनिर्देश संरचना alloca_list_struct {
    माप_प्रकार fp;
    शून्य *p;
    माप_प्रकार size;
    संरचना alloca_list_struct *next;
} alloca_list_type;

#यदि defined(_WIN32)
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
#अन्यथा
#define BOUND_TID_TYPE		पूर्णाङ्क
#define BOUND_GET_TID(id)	id = 0
#endif

प्रकारनिर्देश संरचना jmp_list_struct {
    शून्य *penv;
    माप_प्रकार fp;
    माप_प्रकार end_fp;
    BOUND_TID_TYPE tid;
    संरचना jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
स्थिर वृक्ष * splay (माप_प्रकार addr, वृक्ष *t);
स्थिर वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t);
स्थिर वृक्ष * splay_जोड़ो(माप_प्रकार addr, माप_प्रकार size, वृक्ष * t);
स्थिर वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t);
शून्य splay_printtree(वृक्ष * t, पूर्णाङ्क d);

/* external interface */
शून्य __bounds_checking (पूर्णाङ्क no_check);
शून्य __bound_checking_lock (शून्य);
शून्य __bound_checking_unlock (शून्य);
शून्य __bound_never_fatal (पूर्णाङ्क no_check);
DLL_EXPORT शून्य * __bound_ptr_add(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir1(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir2(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir4(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir8(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir12(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य * __bound_ptr_indir16(शून्य *p, माप_प्रकार offset);
DLL_EXPORT शून्य FASTCALL __bound_local_new(शून्य *p1);
DLL_EXPORT शून्य FASTCALL __bound_local_delete(शून्य *p1);
शून्य __bound_init(माप_प्रकार *, पूर्णाङ्क);
शून्य __bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
शून्य __bound_exit(शून्य);
शून्य __bound_exit_dll(माप_प्रकार *);
#यदि !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, माप_प्रकार size, पूर्णाङ्क prot, पूर्णाङ्क flags, पूर्णाङ्क fd,
                    off_t offset);
पूर्णाङ्क __bound_munmap (शून्य *start, माप_प्रकार size);
DLL_EXPORT शून्य __bound_siglongjmp(लाँघ_बफ env, पूर्णाङ्क val);
#endif
DLL_EXPORT शून्य __bound_new_region(शून्य *p, माप_प्रकार size);
DLL_EXPORT शून्य __bound_setjmp(लाँघ_बफ env);
DLL_EXPORT शून्य __bound_longjmp(लाँघ_बफ env, पूर्णाङ्क val);
DLL_EXPORT शून्य *__bound_memcpy(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, माप_प्रकार size);
DLL_EXPORT शून्य *__bound_memmove(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound_memset(शून्य *dst, पूर्णाङ्क c, माप_प्रकार size);
DLL_EXPORT पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s);
DLL_EXPORT वर्ण *__bound_strcpy(वर्ण *dst, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncpy(वर्ण *dst, ध्रुव वर्ण *src, माप_प्रकार n);
DLL_EXPORT पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2);
DLL_EXPORT पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, माप_प्रकार n);
DLL_EXPORT वर्ण *__bound_strcat(वर्ण *dest, ध्रुव वर्ण *src);
DLL_EXPORT वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, माप_प्रकार n);
DLL_EXPORT वर्ण *__bound_strchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strrchr(ध्रुव वर्ण *string, पूर्णाङ्क ch);
DLL_EXPORT वर्ण *__bound_strdup(ध्रुव वर्ण *s);

#यदि defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT शून्य *__bound___aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__bound___aeabi_memset(शून्य *dst, पूर्णाङ्क c, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memcpy(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove4(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memmove8(शून्य *dst, ध्रुव शून्य *src, माप_प्रकार size);
DLL_EXPORT शून्य *__aeabi_memset(शून्य *dst, पूर्णाङ्क c, माप_प्रकार size);
#endif

#यदि MALLOC_REDIR
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
DLL_EXPORT शून्य *__bound_malloc(माप_प्रकार size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_memalign(माप_प्रकार align, माप_प्रकार size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_realloc(शून्य *ptr, माप_प्रकार size, ध्रुव शून्य *caller);
DLL_EXPORT शून्य *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार size);
#endif

#define FREE_REUSE_SIZE (100)
स्थिर अचिन्हित पूर्णाङ्क free_reuse_index;
स्थिर शून्य *free_reuse_list[FREE_REUSE_SIZE];

स्थिर वृक्ष *वृक्ष_2 = रिक्त;
#define वृक्ष_REUSE      (1)
#यदि वृक्ष_REUSE
स्थिर वृक्ष *वृक्ष_free_list;
#endif
स्थिर alloca_list_type *alloca_list;
स्थिर jmp_list_type *jmp_list;

स्थिर अचिन्हित वर्ण inited;
स्थिर अचिन्हित वर्ण print_warn_ptr_add;
स्थिर अचिन्हित वर्ण print_calls;
स्थिर अचिन्हित वर्ण print_heap;
स्थिर अचिन्हित वर्ण print_statistic;
स्थिर अचिन्हित वर्ण no_strdup;
स्थिर अचिन्हित वर्ण use_sem;
स्थिर _Atomic पूर्णाङ्क never_fatal;
#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर DWORD no_checking_कुंजी;
#define NO_CHECKING_CHECK() यदि (!p) {                                         \
                                  p = (पूर्णाङ्क *) LocalAlloc(LPTR, परिमाण(पूर्णाङ्क));  \
                                  यदि (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_मूल्य(no_checking_कुंजी, p);            \
                            }
#define NO_CHECKING_GET()   ({ पूर्णाङ्क *p = Tls_Get_मूल्य(no_checking_कुंजी);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णाङ्क *p = Tls_Get_मूल्य(no_checking_कुंजी);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#अन्यथा
स्थिर पूर्णाङ्क no_checking = 0;
स्थिर pthread_key_t no_checking_कुंजी;
#define NO_CHECKING_CHECK() यदि (!p) {                                         \
                                  p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));      \
                                  यदि (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_कुंजी, p);    \
                            }
#define NO_CHECKING_GET()   ({ पूर्णाङ्क *p = pthread_getspecific(no_checking_कुंजी); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { पूर्णाङ्क *p = pthread_getspecific(no_checking_कुंजी);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#नोचेद्यदि HAVE_TLS_VAR
स्थिर __thread पूर्णाङ्क no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#अन्यथा
स्थिर _Atomic पूर्णाङ्क no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
स्थिर वर्ण exec[100];

#यदि BOUND_STATISTIC
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_add_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir1_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir2_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir4_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir8_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir12_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_ptr_indir16_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_local_new_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_local_delete_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_malloc_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_calloc_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_realloc_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_free_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memalign_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_mmap_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_munmap_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_alloca_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_setjmp_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_longjmp_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_mempcy_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memcmp_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memmove_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_memset_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strlen_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcpy_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncpy_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcmp_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncmp_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strcat_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strncat_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strchr_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strrchr_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_strdup_गिनती;
स्थिर अचिन्हित दीर्घ दीर्घ bound_not_found;
#define INCR_गिनती(x)          ++x
#अन्यथा
#define INCR_गिनती(x)
#endif
#यदि BOUND_STATISTIC_SPLAY
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_end;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_जोड़ो;
स्थिर अचिन्हित दीर्घ दीर्घ bound_splay_delete;
#define INCR_गिनती_SPLAY(x)    ++x
#अन्यथा
#define INCR_गिनती_SPLAY(x)
#endif

पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    कुरु {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } यावत् (0)

#define bound_error(...)            \
    कुरु {                            \
        bound_warning(__VA_ARGS__); \
        यदि (never_fatal == 0)       \
            निकास(255);              \
    } यावत् (0)

#define bounds_loc(fp, ...) \
    कुरु {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } यावत् (0)

स्थिर शून्य bound_alloc_error(ध्रुव वर्ण *s)
{
    ख_लिखो(मानक_त्रुटि,"FATAL: %s\n",s);
    निकास (1);
}

स्थिर शून्य bound_not_found_warning(ध्रुव वर्ण *file, ध्रुव वर्ण *function,
                                    शून्य *ptr)
{
    dprintf(मानक_त्रुटि, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
शून्य __bounds_checking (पूर्णाङ्क no_check)
{
#यदि HAVE_TLS_FUNC || HAVE_TLS_VAR
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
शून्य __bound_never_fatal (पूर्णाङ्क neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
शून्य * __bound_ptr_add(शून्य *p, माप_प्रकार offset)
{
    माप_प्रकार addr = (माप_प्रकार)p;

    यदि (NO_CHECKING_GET())
        प्रत्यागम p + offset;

    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);

    WAIT_SEM ();
    INCR_गिनती(bound_ptr_add_गिनती);
    यदि (वृक्ष_2) {
        addr -= वृक्ष_2->start;
        यदि (addr >= वृक्ष_2->size) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        यदि (addr >= वृक्ष_2->size) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay_end (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        यदि (addr <= वृक्ष_2->size) {
            यदि (वृक्ष_2->is_invalid || addr + offset > वृक्ष_2->size) {
                POST_SEM ();
                यदि (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (दीर्घ)वृक्ष_2->start,
                                  (दीर्घ)(वृक्ष_2->start + वृक्ष_2->size - 1));
                यदि (never_fatal <= 0)
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */
                प्रत्यागम p + offset;
            }
        }
        अन्यथा यदि (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_गिनती(bound_not_found);
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
शून्य * __bound_ptr_indir ## dsize (शून्य *p, माप_प्रकार offset)                     \
{                                                                              \
    माप_प्रकार addr = (माप_प्रकार)p;                                                   \
                                                                               \
    यदि (NO_CHECKING_GET())                                                     \
        प्रत्यागम p + offset;                                                     \
                                                                               \
    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_गिनती(bound_ptr_indir ## dsize ## गिनती);                            \
    यदि (वृक्ष_2) {                                                                \
        addr -= वृक्ष_2->start;                                                   \
        यदि (addr >= वृक्ष_2->size) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay (addr, वृक्ष_2);                                         \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        यदि (addr >= वृक्ष_2->size) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay_end (addr, वृक्ष_2);                                     \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        यदि (addr <= वृक्ष_2->size) {                                              \
            यदि (वृक्ष_2->is_invalid || addr + offset + dsize > वृक्ष_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (दीर्घ)वृक्ष_2->start,            \
                              (दीर्घ)(वृक्ष_2->start + वृक्ष_2->size - 1));           \
                यदि (never_fatal <= 0)                                          \
                    प्रत्यागम INVALID_POINTER; /* return an invalid pointer */    \
                प्रत्यागम p + offset;                                             \
            }                                                                  \
        }                                                                      \
        अन्यथा {                                                                 \
            INCR_गिनती(bound_not_found);                                       \
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
#यदि (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic धकेलो
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

    यदि (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    यावत् ((addr = p[0])) {
        INCR_गिनती(bound_local_new_गिनती);
        वृक्ष_2 = splay_जोड़ो(addr + fp, p[1], वृक्ष_2);
        p += 2;
    }
    POST_SEM ();
#यदि BOUND_DEBUG
    यदि (print_calls) {
        p = p1;
        यावत् ((addr = p[0])) {
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

    यदि (NO_CHECKING_GET())
         प्रत्यागम;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (शून्य *)fp);
    WAIT_SEM ();
    यावत् ((addr = p[0])) {
        INCR_गिनती(bound_local_delete_गिनती);
        वृक्ष_2 = splay_delete(addr + fp, वृक्ष_2);
        p += 2;
    }
    यदि (alloca_list) {
        alloca_list_type *last = रिक्त;
        alloca_list_type *cur = alloca_list;

        कुरु {
            यदि (cur->fp == fp) {
                यदि (last)
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
        } यावत् (cur);
    }
    यदि (jmp_list) {
        jmp_list_type *last = रिक्त;
        jmp_list_type *cur = jmp_list;

        कुरु {
            यदि (cur->fp == fp) {
                यदि (last)
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
        } यावत् (cur);
    }

    POST_SEM ();
#यदि BOUND_DEBUG
    यदि (print_calls) {
        p = p1;
        यावत् ((addr = p[0])) {
            यदि (addr != 1) {
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

    यदि (NO_CHECKING_GET())
        प्रत्यागम;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (अचिन्हित दीर्घ)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (परिमाण (alloca_list_type));
    WAIT_SEM ();
    INCR_गिनती(bound_alloca_गिनती);
    last = रिक्त;
    cur = alloca_list;
    यावत् (cur) {
#यदि defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        पूर्णाङ्क align = 4;
#नोचेद्यदि defined(__arm__)
        पूर्णाङ्क align = 8;
#अन्यथा
        पूर्णाङ्क align = 16;
#endif
        शून्य *cure = (शून्य *)((वर्ण *)cur->p + ((cur->size + align) & -align));
        शून्य *pe = (शून्य *)((वर्ण *)p + ((size + align) & -align));
        यदि (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            यदि (last)
                last->next = cur->next;
            अन्यथा
                alloca_list = cur->next;
            वृक्ष_2 = splay_delete((माप_प्रकार)cur->p, वृक्ष_2);
            भङ्ग;
        }
        last = cur;
        cur = cur->next;
    }
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार)p, size, वृक्ष_2);
    यदि (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    यदि (cur) {
        dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

शून्य __bound_setjmp(लाँघ_बफ env)
{
    jmp_list_type *jl;
    शून्य *e = (शून्य *) env;

    यदि (NO_CHECKING_GET() == 0) {
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_गिनती(bound_setjmp_गिनती);
        jl = jmp_list;
        यावत् (jl) {
            यदि (jl->penv == e)
                भङ्ग;
            jl = jl->next;
        }
        यदि (jl == रिक्त) {
            jl = BOUND_MALLOC (परिमाण (jmp_list_type));
            यदि (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        यदि (jl) {
            माप_प्रकार fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (माप_प्रकार)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

स्थिर शून्य __bound_long_jump(लाँघ_बफ env, पूर्णाङ्क val, पूर्णाङ्क sig, ध्रुव वर्ण *func)
{
    jmp_list_type *jl;
    शून्य *e;
    BOUND_TID_TYPE tid;

    यदि (NO_CHECKING_GET() == 0) {
        e = (शून्य *)env;
        BOUND_GET_TID(tid);
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_गिनती(bound_longjmp_गिनती);
        jl = jmp_list;
        यावत् (jl) {
            यदि (jl->penv == e && jl->tid == tid) {
                माप_प्रकार start_fp = (माप_प्रकार)__builtin_frame_address(0);
                माप_प्रकार end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = रिक्त;

                यावत् (cur->penv != e || cur->tid != tid) {
                    यदि (cur->tid == tid) {
                        dprintf(मानक_त्रुटि, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        यदि (last)
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
                प्रति (;;) {
                    वृक्ष *t = वृक्ष_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    यावत् (t && (t->start < start_fp || t->start > end_fp))
                        यदि (t->start < start_fp)
                            t = t->दायाँ;
                        अन्यथा
                            t = t->बायाँ;
                    यदि (t == रिक्त)
                        भङ्ग;
                    last = रिक्त;
                    cur = alloca_list;
                    यावत् (cur) {
                         यदि ((माप_प्रकार) cur->p == t->start) {
                             dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             यदि (last)
                                 last->next = cur->next;
                             अन्यथा
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             भङ्ग;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(मानक_त्रुटि, "%s, %s(): delete %p\n",
                            __FILE__, func, (शून्य *) t->start);
                    वृक्ष_2 = splay_delete(t->start, वृक्ष_2);
                }
                भङ्ग;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#यदि !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    दीर्घ_लाँघ (env, val);
}

शून्य __bound_longjmp(लाँघ_बफ env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#यदि !defined(_WIN32)
शून्य __bound_siglongjmp(लाँघ_बफ env, पूर्णाङ्क val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#यदि (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic निकालो
#endif

शून्य __bound_init(माप_प्रकार *p, पूर्णाङ्क mode)
{
    dprintf(मानक_त्रुटि, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    यदि (inited) {
        WAIT_SEM();
        गच्छ add_bounds;
    }
    inited = 1;

#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
    no_checking_कुंजी = TlsAlloc();
    Tls_Set_मूल्य(no_checking_कुंजी, &no_checking);
#अन्यथा
    pthread_key_create(&no_checking_कुंजी, रिक्त);
    pthread_setspecific(no_checking_कुंजी, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = दो_पर्या ("TCC_BOUNDS_WARN_POINTER_ADD") != रिक्त;
    print_calls = दो_पर्या ("TCC_BOUNDS_PRINT_CALLS") != रिक्त;
    print_heap = दो_पर्या ("TCC_BOUNDS_PRINT_HEAP") != रिक्त;
    print_statistic = दो_पर्या ("TCC_BOUNDS_PRINT_STATISTIC") != रिक्त;
    never_fatal = दो_पर्या ("TCC_BOUNDS_NEVER_FATAL") != रिक्त;

    INIT_SEM ();

#यदि MALLOC_REDIR
    {
        शून्य *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(शून्य **) (&malloc_redir) = dlsym (addr, "malloc");
        यदि (malloc_redir == रिक्त) {
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
        यदि (malloc_redir == रिक्त || free_redir == रिक्त)
            bound_alloc_error ("Cannot redirect malloc/free");
#यदि HAVE_PTHREAD_CREATE
        *(शून्य **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(मानक_त्रुटि, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        यदि (pthread_create_redir == रिक्त)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#यदि HAVE_SIGNAL
        *(शून्य **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(मानक_त्रुटि, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        यदि (signal_redir == रिक्त)
            bound_alloc_error ("Cannot redirect signal");
#endif
#यदि HAVE_SIGACTION
        *(शून्य **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(मानक_त्रुटि, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        यदि (sigaction_redir == रिक्त)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#यदि HAVE_FORK
        *(शून्य **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(मानक_त्रुटि, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        यदि (fork_redir == रिक्त)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        खाता *fp;
        अचिन्हित वर्ण found;
        अचिन्हित दीर्घ start;
        अचिन्हित दीर्घ end;
        अचिन्हित दीर्घ ad =
            (अचिन्हित दीर्घ) __builtin_return_address(0);
        वर्ण पंक्ति[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = ख_खोलो ("/proc/self/comm", "r");
        यदि (fp) {
            स_रखो (exec, 0, परिमाण(exec));
            ख_पढ़ो (exec, 1, परिमाण(exec) - 2, fp);
            यदि (म_अक्षर(exec,'\n'))
                *म_अक्षर(exec,'\n') = '\0';
            म_जोड़ो (exec, ":");
            ख_बंद (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = ख_खोलो ("/proc/self/maps", "r");
        यदि (fp) {
            यावत् (ख_माला_लो (पंक्ति, परिमाण(पंक्ति), fp)) {
                यदि (माला_पूछो (पंक्ति, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    भङ्ग;
                }
                यदि (म_माला (पंक्ति,"[heap]"))
                    भङ्ग;
            }
            ख_बंद (fp);
        }
        यदि (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#यदि HAVE_CTYPE
#ifdef __APPLE__
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) &_DefaultRuneLocale,
                        परिमाण (_DefaultRuneLocale), वृक्ष_2);
#अन्यथा
    /* XXX: Does not work if locale is changed */
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_b_loc(),
                        परिमाण (अचिन्हित लघु *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_b_loc() - 128),
                        384 * परिमाण (अचिन्हित लघु), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_tolower_loc(),
                        परिमाण (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_tolower_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_toupper_loc(),
                        परिमाण (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_toupper_loc() - 128),
                        384 * परिमाण (__int32_t), वृक्ष_2);
#endif
#endif
#यदि HAVE_ERRNO
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (&त्रुटि_सं), परिमाण (पूर्णाङ्क), वृक्ष_2);
#endif

add_bounds:
    यदि (!p)
        गच्छ no_bounds;

    /* add all static bound check values */
    यावत् (p[0] != 0) {
        वृक्ष_2 = splay_जोड़ो(p[0], p[1], वृक्ष_2);
#यदि BOUND_DEBUG
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
#यदि (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp)
{
    __bound_init (0, -1);
    यदि (argc && argv) {
        पूर्णाङ्क i;

        WAIT_SEM ();
        प्रति (i = 0; i < argc; i++)
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) argv[i], म_माप (argv[i]) + 1, वृक्ष_2);
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार) argv, (argc + 1) * परिमाण(वर्ण *), वृक्ष_2);
        POST_SEM ();
#यदि BOUND_DEBUG
        यदि (print_calls) {
            प्रति (i = 0; i < argc; i++)
                dprintf(मानक_त्रुटि, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (अचिन्हित दीर्घ)(म_माप (argv[i]) + 1));
            dprintf(मानक_त्रुटि, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (पूर्णाङ्क)((argc + 1) * परिमाण(वर्ण *)));
        }
#endif
    }

    यदि (envp && *envp) {
        वर्ण **p = envp;

        WAIT_SEM ();
        यावत् (*p) {
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) *p, म_माप (*p) + 1, वृक्ष_2);
            ++p;
        }
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार) envp, (++p - envp) * परिमाण(वर्ण *), वृक्ष_2);
        POST_SEM ();
#यदि BOUND_DEBUG
        यदि (print_calls) {
            p = envp;
            यावत् (*p) {
                dprintf(मानक_त्रुटि, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (अचिन्हित दीर्घ)(म_माप (*p) + 1));
                ++p;
            }
            dprintf(मानक_त्रुटि, "%s, %s(): environ %p %d\n",
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

    dprintf(मानक_त्रुटि, "%s, %s():\n", __FILE__, __FUNCTION__);

    यदि (inited) {
#यदि !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        यदि (print_heap) {
            बाह्य शून्य __libc_freeres (शून्य);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        यावत् (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            वृक्ष_2 = splay_delete ((माप_प्रकार) alloca_list->p, वृक्ष_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        यावत् (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        प्रति (i = 0; i < FREE_REUSE_SIZE; i++) {
            यदि (free_reuse_list[i]) {
                वृक्ष_2 = splay_delete ((माप_प्रकार) free_reuse_list[i], वृक्ष_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        यावत् (वृक्ष_2) {
            यदि (print_heap && वृक्ष_2->type != 0)
                ख_लिखो (मानक_त्रुटि, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[वृक्ष_2->type],
                         (अचिन्हित दीर्घ) वृक्ष_2->size);
            वृक्ष_2 = splay_delete (वृक्ष_2->start, वृक्ष_2);
        }
#यदि वृक्ष_REUSE
        यावत् (वृक्ष_free_list) {
            वृक्ष *next = वृक्ष_free_list->बायाँ;
            BOUND_FREE (वृक्ष_free_list);
            वृक्ष_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#यदि HAVE_TLS_FUNC
#यदि defined(_WIN32)
        TlsFree(no_checking_कुंजी);
#अन्यथा
        pthread_key_delete(no_checking_कुंजी);
#endif
#endif
        inited = 0;
        यदि (print_statistic) {
#यदि BOUND_STATISTIC
            ख_लिखो (मानक_त्रुटि, "bound_ptr_add_count      %llu\n", bound_ptr_add_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_local_new_count    %llu\n", bound_local_new_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_local_delete_count %llu\n", bound_local_delete_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_malloc_count       %llu\n", bound_malloc_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_calloc_count       %llu\n", bound_calloc_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_realloc_count      %llu\n", bound_realloc_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_free_count         %llu\n", bound_free_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_memalign_count     %llu\n", bound_memalign_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_mmap_count         %llu\n", bound_mmap_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_munmap_count       %llu\n", bound_munmap_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_alloca_count       %llu\n", bound_alloca_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_setjmp_count       %llu\n", bound_setjmp_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_longjmp_count      %llu\n", bound_longjmp_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_mempcy_count       %llu\n", bound_mempcy_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_memcmp_count       %llu\n", bound_memcmp_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_memmove_count      %llu\n", bound_memmove_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_memset_count       %llu\n", bound_memset_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strlen_count       %llu\n", bound_strlen_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strcpy_count       %llu\n", bound_strcpy_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strncpy_count      %llu\n", bound_strncpy_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strcmp_count       %llu\n", bound_strcmp_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strncmp_count      %llu\n", bound_strncmp_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strcat_count       %llu\n", bound_strcat_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strncat_count      %llu\n", bound_strncat_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strchr_count       %llu\n", bound_strchr_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strrchr_count      %llu\n", bound_strrchr_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_strdup_count       %llu\n", bound_strdup_गिनती);
            ख_लिखो (मानक_त्रुटि, "bound_not_found          %llu\n", bound_not_found);
#endif
#यदि BOUND_STATISTIC_SPLAY
            ख_लिखो (मानक_त्रुटि, "bound_splay              %llu\n", bound_splay);
            ख_लिखो (मानक_त्रुटि, "bound_splay_end          %llu\n", bound_splay_end);
            ख_लिखो (मानक_त्रुटि, "bound_splay_insert       %llu\n", bound_splay_जोड़ो);
            ख_लिखो (मानक_त्रुटि, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

शून्य __bound_exit_dll(माप_प्रकार *p)
{
    dprintf(मानक_त्रुटि, "%s, %s()\n", __FILE__, __FUNCTION__);

    यदि (p) {
        WAIT_SEM ();
	यावत् (p[0] != 0) {
	    वृक्ष_2 = splay_delete(p[0], वृक्ष_2);
#यदि BOUND_DEBUG
            यदि (print_calls) {
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

#यदि HAVE_PTHREAD_CREATE
प्रकारनिर्देश संरचना {
    शून्य *(*start_routine) (शून्य *);
    शून्य *arg;
    sigset_t old_mask;
} bound_thread_create_type;

स्थिर शून्य *bound_thread_create(शून्य *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    शून्य *retval;
#यदि HAVE_TLS_FUNC
    पूर्णाङ्क *p = (पूर्णाङ्क *) BOUND_MALLOC(परिमाण(पूर्णाङ्क));
  
    यदि (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_कुंजी, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, रिक्त);
    retval = data->start_routine(data->arg);
#यदि HAVE_TLS_FUNC
    pthread_setspecific(no_checking_कुंजी, रिक्त);
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
    dprintf (मानक_त्रुटि, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(परिमाण(bound_thread_create_type));
    यदि (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, रिक्त);
    प्रत्यागम retval;
}
#endif

#यदि HAVE_SIGNAL || HAVE_SIGACTION
प्रकारनिर्देश सङ्घ {
#यदि HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#यदि HAVE_SIGACTION
    शून्य (*sig_handler)(पूर्णाङ्क);
    शून्य (*sig_sigaction)(पूर्णाङ्क, siginfo_t *, शून्य *);
#endif
} bound_sig_type;

स्थिर अचिन्हित वर्ण bound_sig_used[NSIG];
स्थिर bound_sig_type bound_sig_data[NSIG];
#endif

#यदि HAVE_SIGNAL
स्थिर शून्य signal_handler(पूर्णाङ्क sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig सङ्केत(पूर्णाङ्क signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (मानक_त्रुटि, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    यदि (retval != संक_त्रुटि) {
        यदि (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        यदि (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    प्रत्यागम retval;
}
#endif

#यदि HAVE_SIGACTION
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

    dprintf (मानक_त्रुटि, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
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
        यदि (bound_sig_used[signum]) {
            यदि (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            अन्यथा
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        यदि (oldact) {
            *oldact = oact;
        }
        यदि (act) {
            bound_sig_used[signum] = 1;
            यदि (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            अन्यथा
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    प्रत्यागम retval;
}
#endif

#यदि HAVE_FORK
pid_t विभाजन(शून्य)
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
#endif

#यदि MALLOC_REDIR
शून्य *दो_स्मृति(माप_प्रकार size)
#अन्यथा
शून्य *__bound_malloc(माप_प्रकार size, ध्रुव शून्य *caller)
#endif
{
    शून्य *ptr;
    
#यदि MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    यदि (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        यदि (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            यदि (pool_index >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
            प्रत्यागम ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
    
    यदि (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_malloc_गिनती);

        यदि (ptr) {
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            यदि (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#यदि MALLOC_REDIR
शून्य *memalign(माप_प्रकार align, माप_प्रकार size)
#अन्यथा
शून्य *__bound_memalign(माप_प्रकार align, माप_प्रकार size, ध्रुव शून्य *caller)
#endif
{
    शून्य *ptr;

#यदि HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#अन्यथा
    यदि (align > 4) {
        /* XXX: handle it ? */
        ptr = रिक्त;
    } अन्यथा {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);

    यदि (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_memalign_गिनती);

        यदि (ptr) {
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            यदि (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    प्रत्यागम ptr;
}

#यदि MALLOC_REDIR
शून्य मुक्त(शून्य *ptr)
#अन्यथा
शून्य __bound_free(शून्य *ptr, ध्रुव शून्य *caller)
#endif
{
    माप_प्रकार addr = (माप_प्रकार) ptr;
    शून्य *p;

    यदि (ptr == रिक्त || वृक्ष_2 == रिक्त
#यदि MALLOC_REDIR
        || ((अचिन्हित वर्ण *) ptr >= &initial_pool[0] &&
            (अचिन्हित वर्ण *) ptr < &initial_pool[परिमाण(initial_pool)])
#endif
        )
        प्रत्यागम;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    यदि (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_free_गिनती);
        वृक्ष_2 = splay (addr, वृक्ष_2);
        यदि (वृक्ष_2->start == addr) {
            यदि (वृक्ष_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                प्रत्यागम;
            }
            वृक्ष_2->is_invalid = 1;
            स_रखो (ptr, 0x5a, वृक्ष_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            यदि (p)
                वृक्ष_2 = splay_delete((माप_प्रकार)p, वृक्ष_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#यदि MALLOC_REDIR
शून्य *पुनः_स्मृति(शून्य *ptr, माप_प्रकार size)
#अन्यथा
शून्य *__bound_realloc(शून्य *ptr, माप_प्रकार size, ध्रुव शून्य *caller)
#endif
{
    शून्य *new_ptr;

    यदि (size == 0) {
#यदि MALLOC_REDIR
        मुक्त(ptr);
#अन्यथा
        __bound_free(ptr, caller);
#endif
        प्रत्यागम रिक्त;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (अचिन्हित दीर्घ)size);

    यदि (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_realloc_गिनती);

        यदि (ptr)
            वृक्ष_2 = splay_delete ((माप_प्रकार) ptr, वृक्ष_2);
        यदि (new_ptr) {
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) new_ptr, size ? size : size + 1, वृक्ष_2);
            यदि (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new_ptr)
                वृक्ष_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    प्रत्यागम new_ptr;
}

#यदि MALLOC_REDIR
शून्य *सुस्मृति(माप_प्रकार nmemb, माप_प्रकार size)
#अन्यथा
शून्य *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार size)
#endif
{
    शून्य *ptr;

    size *= nmemb;
#यदि MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    यदि (malloc_redir == रिक्त) {
        __bound_init (0, -1);
        यदि (malloc_redir == रिक्त) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            यदि (pool_index >= परिमाण (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);
            स_रखो (ptr, 0, size);
            प्रत्यागम ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)size);

    यदि (ptr) {
        स_रखो (ptr, 0, size);
        यदि (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_गिनती(bound_calloc_गिनती);
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) ptr, size ? size : size + 1, वृक्ष_2);
            यदि (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    प्रत्यागम ptr;
}

#यदि !defined(_WIN32)
शून्य *__bound_mmap (शून्य *start, माप_प्रकार size, पूर्णाङ्क prot,
                    पूर्णाङ्क flags, पूर्णाङ्क fd, off_t offset)
{
    शून्य *result;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिन्हित दीर्घ)size);
    result = mmap (start, size, prot, flags, fd, offset);
    यदि (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_mmap_गिनती);
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार)result, size, वृक्ष_2);
        POST_SEM ();
    }
    प्रत्यागम result;
}

पूर्णाङ्क __bound_munmap (शून्य *start, माप_प्रकार size)
{
    पूर्णाङ्क result;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (अचिन्हित दीर्घ)size);
    यदि (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_munmap_गिनती);
        वृक्ष_2 = splay_delete ((माप_प्रकार) start, वृक्ष_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    प्रत्यागम result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
स्थिर शून्य __bound_check(ध्रुव शून्य *p, माप_प्रकार size, ध्रुव वर्ण *function)
{
    यदि (size != 0 && __bound_ptr_add((शून्य *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (अचिन्हित दीर्घ)size, function);
    }
}

स्थिर पूर्णाङ्क check_overlap (ध्रुव शून्य *p1, माप_प्रकार n1,
                          ध्रुव शून्य *p2, माप_प्रकार n2,
                          ध्रुव वर्ण *function)
{
    ध्रुव शून्य *p1e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p1 + n1);
    ध्रुव शून्य *p2e = (ध्रुव शून्य *) ((ध्रुव वर्ण *) p2 + n2);

    यदि (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (अचिन्हित दीर्घ)n1, p2, (अचिन्हित दीर्घ)n2, function);
        प्रत्यागम never_fatal < 0;
    }
    प्रत्यागम 0;
}

शून्य *__bound_memcpy(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_mempcy_गिनती);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    यदि (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम स_नकल(dest, src, n);
}

पूर्णाङ्क __bound_memcmp(ध्रुव शून्य *s1, ध्रुव शून्य *s2, माप_प्रकार n)
{
    ध्रुव अचिन्हित वर्ण *u1 = (ध्रुव अचिन्हित वर्ण *) s1;
    ध्रुव अचिन्हित वर्ण *u2 = (ध्रुव अचिन्हित वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memcmp_गिनती);
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

शून्य *__bound_memmove(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम स_हटाओ(dest, src, n);
}

शून्य *__bound_memset(शून्य *s, पूर्णाङ्क c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memset_गिनती);
    __bound_check(s, n, "memset");
    प्रत्यागम स_रखो(s, c, n);
}

#यदि defined(__arm__) && defined(__ARM_EABI__)
शून्य *__bound___aeabi_memcpy(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_mempcy_गिनती);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    यदि (check_overlap(dest, n, src, n, "memcpy"))
        प्रत्यागम dest;
    प्रत्यागम __aeabi_memcpy(dest, src, n);
}

शून्य *__bound___aeabi_memmove(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove(dest, src, n);
}

शून्य *__bound___aeabi_memmove4(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove4(dest, src, n);
}

शून्य *__bound___aeabi_memmove8(शून्य *dest, ध्रुव शून्य *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    प्रत्यागम __aeabi_memmove8(dest, src, n);
}

शून्य *__bound___aeabi_memset(शून्य *s, पूर्णाङ्क c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memset_गिनती);
    __bound_check(s, n, "memset");
    प्रत्यागम __aeabi_memset(s, c, n);
}
#endif

पूर्णाङ्क __bound_strlen(ध्रुव वर्ण *s)
{
    ध्रुव वर्ण *p = s;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_गिनती(bound_strlen_गिनती);
    यावत् (*p++);
    __bound_check(s, p - s, "strlen");
    प्रत्यागम (p - s) - 1;
}

वर्ण *__bound_strcpy(वर्ण *dest, ध्रुव वर्ण *src)
{
    माप_प्रकार len;
    ध्रुव वर्ण *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_गिनती(bound_strcpy_गिनती);
    यावत् (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    यदि (check_overlap(dest, len, src, len, "strcpy"))
        प्रत्यागम dest;
    प्रत्यागम म_नकल (dest, src);
}

वर्ण *__bound_strncpy(वर्ण *dest, ध्रुव वर्ण *src, माप_प्रकार n)
{
    माप_प्रकार len = n;
    ध्रुव वर्ण *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncpy_गिनती);
    यावत् (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    यदि (check_overlap(dest, len, src, len, "strncpy"))
        प्रत्यागम dest;
    प्रत्यागम म_नकलन(dest, src, n);
}

पूर्णाङ्क __bound_strcmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2)
{
    ध्रुव अचिन्हित वर्ण *u1 = (ध्रुव अचिन्हित वर्ण *) s1;
    ध्रुव अचिन्हित वर्ण *u2 = (ध्रुव अचिन्हित वर्ण *) s2;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_गिनती(bound_strcmp_गिनती);
    यावत् (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ध्रुव वर्ण *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ध्रुव वर्ण *)u2 - s2) + 1, "strcmp s2");
    प्रत्यागम *u1 - *u2;
}

पूर्णाङ्क __bound_strncmp(ध्रुव वर्ण *s1, ध्रुव वर्ण *s2, माप_प्रकार n)
{
    ध्रुव अचिन्हित वर्ण *u1 = (ध्रुव अचिन्हित वर्ण *) s1;
    ध्रुव अचिन्हित वर्ण *u2 = (ध्रुव अचिन्हित वर्ण *) s2;
    पूर्णाङ्क retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncmp_गिनती);
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

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_गिनती(bound_strcat_गिनती);
    यावत् (*dest++);
    यावत् (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    यदि (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        प्रत्यागम dest;
    प्रत्यागम म_जोड़ो(r, s);
}

वर्ण *__bound_strncat(वर्ण *dest, ध्रुव वर्ण *src, माप_प्रकार n)
{
    वर्ण *r = dest;
    ध्रुव वर्ण *s = src;
    माप_प्रकार len = n;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncat_गिनती);
    यावत् (*dest++);
    यावत् (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    यदि (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        प्रत्यागम dest;
    प्रत्यागम म_जोड़न(r, s, n);
}

वर्ण *__bound_strchr(ध्रुव वर्ण *s, पूर्णाङ्क c)
{
    ध्रुव अचिन्हित वर्ण *str = (ध्रुव अचिन्हित वर्ण *) s;
    अचिन्हित वर्ण ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गिनती(bound_strchr_गिनती);
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
    ध्रुव अचिन्हित वर्ण *str = (ध्रुव अचिन्हित वर्ण *) s;
    अचिन्हित वर्ण ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_गिनती(bound_strrchr_गिनती);
    यावत् (*str++);
    __bound_check(s, (ध्रुव वर्ण *)str - s, "strrchr");
    यावत् (str != (ध्रुव अचिन्हित वर्ण *)s) {
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

    INCR_गिनती(bound_strdup_गिनती);
    यावत् (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (अचिन्हित दीर्घ)(p -s));
    यदि (new) {
        यदि (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार)new, p - s, वृक्ष_2);
            यदि (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new)
                वृक्ष_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        स_नकल (new, s, p - s);
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

स्थिर वृक्ष * splay (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    वृक्ष N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गिनती_SPLAY(bound_splay);
    यदि (t == रिक्त) प्रत्यागम t;
    N.बायाँ = N.दायाँ = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare(addr, t->start, t->size);
        यदि (comp < 0) {
            y = t->बायाँ;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare(addr, y->start, y->size) < 0) {
                t->बायाँ = y->दायाँ;                    /* rotate right */
                y->दायाँ = t;
                t = y;
                यदि (t->बायाँ == रिक्त) भङ्ग;
            }
            r->बायाँ = t;                               /* link right */
            r = t;
            t = t->बायाँ;
        } अन्यथा यदि (comp > 0) {
            y = t->दायाँ;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare(addr, y->start, y->size) > 0) {
                t->दायाँ = y->बायाँ;                    /* rotate left */
                y->बायाँ = t;
                t = y;
                यदि (t->दायाँ == रिक्त) भङ्ग;
            }
            l->दायाँ = t;                              /* link left */
            l = t;
            t = t->दायाँ;
        } अन्यथा {
            भङ्ग;
        }
    }
    l->दायाँ = t->बायाँ;                                /* assemble */
    r->बायाँ = t->दायाँ;
    t->बायाँ = N.दायाँ;
    t->दायाँ = N.बायाँ;

    प्रत्यागम t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

स्थिर वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    वृक्ष N, *l, *r, *y;
    पूर्णाङ्क comp;
    
    INCR_गिनती_SPLAY(bound_splay_end);
    यदि (t == रिक्त) प्रत्यागम t;
    N.बायाँ = N.दायाँ = रिक्त;
    l = r = &N;
 
    प्रति (;;) {
        comp = compare_end(addr, t->start + t->size);
        यदि (comp < 0) {
            y = t->बायाँ;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare_end(addr, y->start + y->size) < 0) {
                t->बायाँ = y->दायाँ;                    /* rotate right */
                y->दायाँ = t;
                t = y;
                यदि (t->बायाँ == रिक्त) भङ्ग;
            }
            r->बायाँ = t;                               /* link right */
            r = t;
            t = t->बायाँ;
        } अन्यथा यदि (comp > 0) {
            y = t->दायाँ;
            यदि (y == रिक्त) भङ्ग;
            यदि (compare_end(addr, y->start + y->size) > 0) {
                t->दायाँ = y->बायाँ;                    /* rotate left */
                y->बायाँ = t;
                t = y;
                यदि (t->दायाँ == रिक्त) भङ्ग;
            }
            l->दायाँ = t;                              /* link left */
            l = t;
            t = t->दायाँ;
        } अन्यथा {
            भङ्ग;
        }
    }
    l->दायाँ = t->बायाँ;                                /* assemble */
    r->बायाँ = t->दायाँ;
    t->बायाँ = N.दायाँ;
    t->दायाँ = N.बायाँ;

    प्रत्यागम t;
}

स्थिर वृक्ष * splay_जोड़ो(माप_प्रकार addr, माप_प्रकार size, वृक्ष * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    वृक्ष * new;

    INCR_गिनती_SPLAY(bound_splay_जोड़ो);
    यदि (t != रिक्त) {
        t = splay(addr,t);
        यदि (compare(addr, t->start, t->size)==0) {
            प्रत्यागम t;  /* it's already there */
        }
    }
#यदि वृक्ष_REUSE
    यदि (वृक्ष_free_list) {
          new = वृक्ष_free_list;
          वृक्ष_free_list = new->बायाँ;
    }
    अन्यथा
#endif
    {
        new = (वृक्ष *) BOUND_MALLOC (परिमाण (वृक्ष));
    }
    यदि (new == रिक्त) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    अन्यथा {
        यदि (t == रिक्त) {
            new->बायाँ = new->दायाँ = रिक्त;
        } अन्यथा यदि (compare(addr, t->start, t->size) < 0) {
            new->बायाँ = t->बायाँ;
            new->दायाँ = t;
            t->बायाँ = रिक्त;
        } अन्यथा {
            new->दायाँ = t->दायाँ;
            new->बायाँ = t;
            t->दायाँ = रिक्त;
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

स्थिर वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    वृक्ष * x;

    INCR_गिनती_SPLAY(bound_splay_delete);
    यदि (t==रिक्त) प्रत्यागम रिक्त;
    t = splay(addr,t);
    यदि (compare_destroy(addr, t->start) == 0) {        /* found it */
        यदि (t->बायाँ == रिक्त) {
            x = t->दायाँ;
        } अन्यथा {
            x = splay(addr, t->बायाँ);
            x->दायाँ = t->दायाँ;
        }
#यदि वृक्ष_REUSE
        t->बायाँ = वृक्ष_free_list;
        वृक्ष_free_list = t;
#अन्यथा
        BOUND_FREE(t);
#endif
        प्रत्यागम x;
    } अन्यथा {
        प्रत्यागम t;                                      /* It wasn't there */
    }
}

शून्य splay_printtree(वृक्ष * t, पूर्णाङ्क d)
{
    पूर्णाङ्क i;
    यदि (t == रिक्त) प्रत्यागम;
    splay_printtree(t->दायाँ, d+1);
    प्रति (i=0; i<d; i++) ख_लिखो(मानक_त्रुटि," ");
    ख_लिखो(मानक_त्रुटि,"%p(0x%lx:%u:%u)\n",
            (शून्य *) t->start, (अचिन्हित दीर्घ) t->size,
            (अचिन्हित)t->type, (अचिन्हित)t->is_invalid);
    splay_printtree(t->बायाँ, d+1);
}
