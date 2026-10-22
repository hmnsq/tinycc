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
#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <stdarg.h>
#समावेश <string.h>
#समावेश <setjmp.h>
#समावेश <stdatomic.h>

#अगर !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#समावेश <malloc.h>
#पूर्ण_अगर

#अगर !defined(_WIN32)
#समावेश <unistd.h>
#समावेश <sys/syscall.h>
#पूर्ण_अगर

#समावेश "config.h"

#घोषणा BOUND_DEBUG             (1)
#घोषणा BOUND_STATISTIC         (1)

#अगर BOUND_DEBUG
 #घोषणा dprintf(a...)         अगर (print_calls) { bounds_loc(a); }
#अन्यथा
 #घोषणा dprintf(a...)
#पूर्ण_अगर

#अगर_घोषित __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #अघोषित __attribute__ 
#पूर्ण_अगर
#अगर_घोषित __i386__
#घोषणा FASTCALL __attribute__((regparm(3)))
#अन्यथा
#घोषणा FASTCALL
#पूर्ण_अगर

#अगर_घोषित _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अन्यथा
# define DLL_EXPORT
#पूर्ण_अगर

#अगर defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#समावेश <sys/mman.h>
#घोषणा INIT_SEM()
#घोषणा EXIT_SEM()
#घोषणा WAIT_SEM()
#घोषणा POST_SEM()
#घोषणा TRY_SEM()
#घोषणा HAVE_MEMALIGN          (0)
#घोषणा MALLOC_REDIR           (0)
#घोषणा HAVE_PTHREAD_CREATE    (0)
#घोषणा HAVE_CTYPE             (0)
#घोषणा HAVE_ERRNO             (0)
#घोषणा HAVE_SIGNAL            (0)
#घोषणा HAVE_SIGACTION         (0)
#घोषणा HAVE_FORK              (0)
#घोषणा HAVE_TLS_FUNC          (0)
#घोषणा HAVE_TLS_VAR           (0)

#या_अगर defined(_WIN32)

#समावेश <windows.h>
#समावेश <signal.h>
अटल CRITICAL_SECTION bounds_sem;
#घोषणा INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#घोषणा EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#घोषणा WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#घोषणा POST_SEM()             LeaveCriticalSection(&bounds_sem)
#घोषणा TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#घोषणा HAVE_MEMALIGN          (0)
#घोषणा MALLOC_REDIR           (0)
#घोषणा HAVE_PTHREAD_CREATE    (0)
#घोषणा HAVE_CTYPE             (0)
#घोषणा HAVE_ERRNO             (0)
#घोषणा HAVE_SIGNAL            (1)
#घोषणा HAVE_SIGACTION         (0)
#घोषणा HAVE_FORK              (0)
#घोषणा HAVE_TLS_FUNC          (1)
#घोषणा HAVE_TLS_VAR           (0)

#अन्यथा

#घोषणा __USE_GNU              /* get RTLD_NEXT */
#समावेश <sys/mman.h>
#समावेश <ctype.h>
#समावेश <pthread.h>
#समावेश <dlfcn.h>
#समावेश <errno.h>
#समावेश <signal.h>
#अगर_घोषित __APPLE__
#समावेश <dispatch/dispatch.h>
अटल dispatch_semaphore_t bounds_sem;
#घोषणा INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#घोषणा EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#घोषणा WAIT_SEM()             अगर (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#घोषणा POST_SEM()             अगर (use_sem) dispatch_semaphore_signal(bounds_sem)
#घोषणा TRY_SEM()              अगर (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#या_अगर 0
#समावेश <semaphore.h>
अटल sem_t bounds_sem;
#घोषणा INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#घोषणा EXIT_SEM()             sem_destroy (&bounds_sem)
#घोषणा WAIT_SEM()             अगर (use_sem) जबतक (sem_wait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#घोषणा POST_SEM()             अगर (use_sem) sem_post (&bounds_sem)
#घोषणा TRY_SEM()              अगर (use_sem) जबतक (sem_trywait (&bounds_sem) < 0 \
                                                   && त्रुटि_सं == EINTR)
#या_अगर 0
अटल pthread_mutex_t bounds_mtx;
#घोषणा INIT_SEM()             pthread_mutex_init (&bounds_mtx, शून्य)
#घोषणा EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#घोषणा WAIT_SEM()             अगर (use_sem) pthread_mutex_lock (&bounds_mtx)
#घोषणा POST_SEM()             अगर (use_sem) pthread_mutex_unlock (&bounds_mtx)
#घोषणा TRY_SEM()              अगर (use_sem) pthread_mutex_trylock (&bounds_mtx)
#अन्यथा
अटल pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#घोषणा INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#घोषणा EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#घोषणा WAIT_SEM()             अगर (use_sem) pthread_spin_lock (&bounds_spin)
#घोषणा POST_SEM()             अगर (use_sem) pthread_spin_unlock (&bounds_spin)
#घोषणा TRY_SEM()              अगर (use_sem) pthread_spin_trylock (&bounds_spin)
#पूर्ण_अगर
#घोषणा HAVE_MEMALIGN          (1)
#घोषणा MALLOC_REDIR           (1)
#घोषणा HAVE_PTHREAD_CREATE    (1)
#घोषणा HAVE_CTYPE             (1)
#घोषणा HAVE_ERRNO             (1)
#घोषणा HAVE_SIGNAL            (1)
#घोषणा HAVE_SIGACTION         (1)
#घोषणा HAVE_FORK              (1)
#अगर defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#घोषणा HAVE_TLS_FUNC          (1)
#घोषणा HAVE_TLS_VAR           (0)
#अन्यथा
#घोषणा HAVE_TLS_FUNC          (0)
#घोषणा HAVE_TLS_VAR           (1)
#पूर्ण_अगर
#अगर defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#पूर्ण_अगर
#पूर्ण_अगर

#अगर MALLOC_REDIR
अटल व्योम *(*malloc_redir) (माप_प्रकार);
अटल व्योम *(*calloc_redir) (माप_प्रकार, माप_प्रकार);
अटल व्योम (*free_redir) (व्योम *);
अटल व्योम *(*realloc_redir) (व्योम *, माप_प्रकार);
अटल अचिन्हित पूर्णांक pool_सूचकांक;
अटल अचिन्हित अक्षर __attribute__((aligned(16))) initial_pool[256];
#पूर्ण_अगर
#अगर HAVE_MEMALIGN
अटल व्योम *(*memalign_redir) (माप_प्रकार, माप_प्रकार);
#पूर्ण_अगर
#अगर HAVE_PTHREAD_CREATE
अटल पूर्णांक (*pthread_create_redir) (pthread_t *thread,
                                    स्थिर pthread_attr_t *attr,
                                    व्योम *(*start_routine)(व्योम *), व्योम *arg);
#पूर्ण_अगर
#अगर HAVE_SIGNAL
प्रकार व्योम (*bound_sig)(पूर्णांक);
अटल bound_sig (*signal_redir) (पूर्णांक signum, bound_sig handler);
#पूर्ण_अगर
#अगर HAVE_SIGACTION
अटल पूर्णांक (*sigaction_redir) (पूर्णांक signum, स्थिर काष्ठा sigaction *act,
                               काष्ठा sigaction *oldact);
#पूर्ण_अगर
#अगर HAVE_FORK
अटल पूर्णांक (*fork_redir) (व्योम);
#पूर्ण_अगर

#घोषणा TCC_TYPE_NONE           (0)
#घोषणा TCC_TYPE_MALLOC         (1)
#घोषणा TCC_TYPE_CALLOC         (2)
#घोषणा TCC_TYPE_REALLOC        (3)
#घोषणा TCC_TYPE_MEMALIGN       (4)
#घोषणा TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#घोषणा INVALID_POINTER ((व्योम *)(-2))

प्रकार काष्ठा वृक्ष_गाँठ वृक्ष;
काष्ठा वृक्ष_गाँठ {
    वृक्ष * बायाँ, * दायाँ;
    माप_प्रकार start;
    माप_प्रकार आकार;
    अचिन्हित अक्षर type;
    अचिन्हित अक्षर is_invalid; /* true if pointers outside region are invalid */
};

प्रकार काष्ठा alloca_list_struct {
    माप_प्रकार fp;
    व्योम *p;
    माप_प्रकार आकार;
    काष्ठा alloca_list_struct *अग्र;
} alloca_list_type;

#अगर defined(_WIN32)
#घोषणा BOUND_TID_TYPE		DWORD
#घोषणा BOUND_GET_TID(id)	id = GetCurrentThreadId()
#या_अगर defined(__OpenBSD__)
#घोषणा BOUND_TID_TYPE		pid_t
#घोषणा BOUND_GET_TID(id)	id = getthrid()
#या_अगर defined(__FreeBSD__)
#घोषणा BOUND_TID_TYPE		pid_t
#घोषणा BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#या_अगर  defined(__NetBSD__)
#घोषणा BOUND_TID_TYPE		pid_t
#घोषणा BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#या_अगर defined(__linux__)
#घोषणा BOUND_TID_TYPE		pid_t
#घोषणा BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#अन्यथा
#घोषणा BOUND_TID_TYPE		पूर्णांक
#घोषणा BOUND_GET_TID(id)	id = 0
#पूर्ण_अगर

प्रकार काष्ठा jmp_list_struct {
    व्योम *penv;
    माप_प्रकार fp;
    माप_प्रकार end_fp;
    BOUND_TID_TYPE tid;
    काष्ठा jmp_list_struct *अग्र;
} jmp_list_type;

#घोषणा BOUND_STATISTIC_SPLAY   (0)
अटल वृक्ष * splay (माप_प्रकार addr, वृक्ष *t);
अटल वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t);
अटल वृक्ष * splay_जोड़ो(माप_प्रकार addr, माप_प्रकार आकार, वृक्ष * t);
अटल वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t);
व्योम splay_printtree(वृक्ष * t, पूर्णांक d);

/* external interface */
व्योम __bounds_checking (पूर्णांक no_check);
व्योम __bound_checking_lock (व्योम);
व्योम __bound_checking_unlock (व्योम);
व्योम __bound_never_fatal (पूर्णांक no_check);
DLL_EXPORT व्योम * __bound_ptr_add(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir1(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir2(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir4(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir8(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir12(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम * __bound_ptr_indir16(व्योम *p, माप_प्रकार offset);
DLL_EXPORT व्योम FASTCALL __bound_local_new(व्योम *p1);
DLL_EXPORT व्योम FASTCALL __bound_local_delete(व्योम *p1);
व्योम __bound_init(माप_प्रकार *, पूर्णांक);
व्योम __bound_main_arg(पूर्णांक argc, अक्षर **argv, अक्षर **envp);
व्योम __bound_exit(व्योम);
व्योम __bound_exit_dll(माप_प्रकार *);
#अगर !defined(_WIN32)
व्योम *__bound_mmap (व्योम *start, माप_प्रकार आकार, पूर्णांक prot, पूर्णांक flags, पूर्णांक fd,
                    off_t offset);
पूर्णांक __bound_munmap (व्योम *start, माप_प्रकार आकार);
DLL_EXPORT व्योम __bound_siglongjmp(लाँघ_बफ env, पूर्णांक val);
#पूर्ण_अगर
DLL_EXPORT व्योम __bound_new_region(व्योम *p, माप_प्रकार आकार);
DLL_EXPORT व्योम __bound_setjmp(लाँघ_बफ env);
DLL_EXPORT व्योम __bound_longjmp(लाँघ_बफ env, पूर्णांक val);
DLL_EXPORT व्योम *__bound_memcpy(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT पूर्णांक __bound_memcmp(स्थिर व्योम *s1, स्थिर व्योम *s2, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound_memmove(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound_memset(व्योम *dst, पूर्णांक c, माप_प्रकार आकार);
DLL_EXPORT पूर्णांक __bound_strlen(स्थिर अक्षर *s);
DLL_EXPORT अक्षर *__bound_strcpy(अक्षर *dst, स्थिर अक्षर *src);
DLL_EXPORT अक्षर *__bound_strncpy(अक्षर *dst, स्थिर अक्षर *src, माप_प्रकार n);
DLL_EXPORT पूर्णांक __bound_strcmp(स्थिर अक्षर *s1, स्थिर अक्षर *s2);
DLL_EXPORT पूर्णांक __bound_strncmp(स्थिर अक्षर *s1, स्थिर अक्षर *s2, माप_प्रकार n);
DLL_EXPORT अक्षर *__bound_strcat(अक्षर *dest, स्थिर अक्षर *src);
DLL_EXPORT अक्षर *__bound_strncat(अक्षर *dest, स्थिर अक्षर *src, माप_प्रकार n);
DLL_EXPORT अक्षर *__bound_strchr(स्थिर अक्षर *string, पूर्णांक ch);
DLL_EXPORT अक्षर *__bound_strrchr(स्थिर अक्षर *string, पूर्णांक ch);
DLL_EXPORT अक्षर *__bound_strdup(स्थिर अक्षर *s);

#अगर defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT व्योम *__bound___aeabi_memcpy(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound___aeabi_memmove(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound___aeabi_memmove4(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound___aeabi_memmove8(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__bound___aeabi_memset(व्योम *dst, पूर्णांक c, माप_प्रकार आकार);
DLL_EXPORT व्योम *__aeabi_memcpy(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__aeabi_memmove(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__aeabi_memmove4(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__aeabi_memmove8(व्योम *dst, स्थिर व्योम *src, माप_प्रकार आकार);
DLL_EXPORT व्योम *__aeabi_memset(व्योम *dst, पूर्णांक c, माप_प्रकार आकार);
#पूर्ण_अगर

#अगर MALLOC_REDIR
#घोषणा BOUND_MALLOC(a)          malloc_redir(a)
#घोषणा BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#घोषणा BOUND_FREE(a)            free_redir(a)
#घोषणा BOUND_REALLOC(a,b)       realloc_redir(a,b)
#घोषणा BOUND_CALLOC(a,b)        calloc_redir(a,b)
#अन्यथा
#घोषणा BOUND_MALLOC(a)          दो_स्मृति(a)
#घोषणा BOUND_MEMALIGN(a,b)      memalign(a,b)
#घोषणा BOUND_FREE(a)            मुक्त(a)
#घोषणा BOUND_REALLOC(a,b)       पुनः_स्मृति(a,b)
#घोषणा BOUND_CALLOC(a,b)        सुस्मृति(a,b)
DLL_EXPORT व्योम *__bound_malloc(माप_प्रकार आकार, स्थिर व्योम *caller);
DLL_EXPORT व्योम *__bound_memalign(माप_प्रकार align, माप_प्रकार आकार, स्थिर व्योम *caller);
DLL_EXPORT व्योम __bound_free(व्योम *ptr, स्थिर व्योम *caller);
DLL_EXPORT व्योम *__bound_realloc(व्योम *ptr, माप_प्रकार आकार, स्थिर व्योम *caller);
DLL_EXPORT व्योम *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार आकार);
#पूर्ण_अगर

#घोषणा FREE_REUSE_आकार (100)
अटल अचिन्हित पूर्णांक free_reuse_सूचकांक;
अटल व्योम *free_reuse_list[FREE_REUSE_आकार];

अटल वृक्ष *वृक्ष_2 = शून्य;
#घोषणा वृक्ष_REUSE      (1)
#अगर वृक्ष_REUSE
अटल वृक्ष *वृक्ष_free_list;
#पूर्ण_अगर
अटल alloca_list_type *alloca_list;
अटल jmp_list_type *jmp_list;

अटल अचिन्हित अक्षर inited;
अटल अचिन्हित अक्षर print_warn_ptr_add;
अटल अचिन्हित अक्षर print_calls;
अटल अचिन्हित अक्षर print_heap;
अटल अचिन्हित अक्षर print_statistic;
अटल अचिन्हित अक्षर no_strdup;
अटल अचिन्हित अक्षर use_sem;
अटल _Atomic पूर्णांक never_fatal;
#अगर HAVE_TLS_FUNC
#अगर defined(_WIN32)
अटल पूर्णांक no_checking = 0;
अटल DWORD no_checking_कुंजी;
#घोषणा NO_CHECKING_CHECK() अगर (!p) {                                         \
                                  p = (पूर्णांक *) LocalAlloc(LPTR, माप(पूर्णांक));  \
                                  अगर (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_मूल्य(no_checking_कुंजी, p);            \
                            }
#घोषणा NO_CHECKING_GET()   ({ पूर्णांक *p = Tls_Get_मूल्य(no_checking_कुंजी);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#घोषणा NO_CHECKING_SET(v)  { पूर्णांक *p = Tls_Get_मूल्य(no_checking_कुंजी);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#अन्यथा
अटल पूर्णांक no_checking = 0;
अटल pthread_key_t no_checking_कुंजी;
#घोषणा NO_CHECKING_CHECK() अगर (!p) {                                         \
                                  p = (पूर्णांक *) BOUND_MALLOC(माप(पूर्णांक));      \
                                  अगर (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_कुंजी, p);    \
                            }
#घोषणा NO_CHECKING_GET()   ({ पूर्णांक *p = pthread_getspecific(no_checking_कुंजी); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#घोषणा NO_CHECKING_SET(v)  { पूर्णांक *p = pthread_getspecific(no_checking_कुंजी);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#पूर्ण_अगर
#या_अगर HAVE_TLS_VAR
अटल __thread पूर्णांक no_checking = 0;
#घोषणा NO_CHECKING_GET()  no_checking
#घोषणा NO_CHECKING_SET(v) no_checking = v 
#अन्यथा
अटल _Atomic पूर्णांक no_checking = 0;
#घोषणा NO_CHECKING_GET()  no_checking
#घोषणा NO_CHECKING_SET(v) no_checking = v 
#पूर्ण_अगर
अटल अक्षर exec[100];

#अगर BOUND_STATISTIC
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_add_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir1_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir2_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir4_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir8_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir12_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_ptr_indir16_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_local_new_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_local_delete_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_malloc_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_calloc_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_realloc_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_free_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_memalign_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_mmap_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_munmap_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_alloca_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_setjmp_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_longjmp_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_mempcy_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_memcmp_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_memmove_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_memset_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strlen_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strcpy_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strncpy_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strcmp_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strncmp_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strcat_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strncat_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strchr_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strrchr_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_strdup_गिनती;
अटल अचिन्हित दीर्घ दीर्घ bound_not_found;
#घोषणा INCR_गिनती(x)          ++x
#अन्यथा
#घोषणा INCR_गिनती(x)
#पूर्ण_अगर
#अगर BOUND_STATISTIC_SPLAY
अटल अचिन्हित दीर्घ दीर्घ bound_splay;
अटल अचिन्हित दीर्घ दीर्घ bound_splay_end;
अटल अचिन्हित दीर्घ दीर्घ bound_splay_जोड़ो;
अटल अचिन्हित दीर्घ दीर्घ bound_splay_delete;
#घोषणा INCR_गिनती_SPLAY(x)    ++x
#अन्यथा
#घोषणा INCR_गिनती_SPLAY(x)
#पूर्ण_अगर

पूर्णांक tcc_backtrace(स्थिर अक्षर *fmt, ...);

/* print a bound error message */
#घोषणा bound_warning(...) \
    करो {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } जबतक (0)

#घोषणा bound_error(...)            \
    करो {                            \
        bound_warning(__VA_ARGS__); \
        अगर (never_fatal == 0)       \
            निकास(255);              \
    } जबतक (0)

#घोषणा bounds_loc(fp, ...) \
    करो {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } जबतक (0)

अटल व्योम bound_alloc_error(स्थिर अक्षर *s)
{
    ख_लिखो(मानक_त्रुटि,"FATAL: %s\n",s);
    निकास (1);
}

अटल व्योम bound_not_found_warning(स्थिर अक्षर *file, स्थिर अक्षर *function,
                                    व्योम *ptr)
{
    dprintf(मानक_त्रुटि, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
व्योम __bounds_checking (पूर्णांक no_check)
{
#अगर HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#अन्यथा
    atomic_fetch_add (&no_checking, no_check);
#पूर्ण_अगर
}

व्योम __bound_checking_lock(व्योम)
{
    WAIT_SEM ();
}

व्योम __bound_checking_unlock(व्योम)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
व्योम __bound_never_fatal (पूर्णांक neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
व्योम * __bound_ptr_add(व्योम *p, माप_प्रकार offset)
{
    माप_प्रकार addr = (माप_प्रकार)p;

    अगर (NO_CHECKING_GET())
        वापस p + offset;

    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
            __खाता__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);

    WAIT_SEM ();
    INCR_गिनती(bound_ptr_add_गिनती);
    अगर (वृक्ष_2) {
        addr -= वृक्ष_2->start;
        अगर (addr >= वृक्ष_2->आकार) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        अगर (addr >= वृक्ष_2->आकार) {
            addr = (माप_प्रकार)p;
            वृक्ष_2 = splay_end (addr, वृक्ष_2);
            addr -= वृक्ष_2->start;
        }
        अगर (addr <= वृक्ष_2->आकार) {
            अगर (वृक्ष_2->is_invalid || addr + offset > वृक्ष_2->आकार) {
                POST_SEM ();
                अगर (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (दीर्घ)वृक्ष_2->start,
                                  (दीर्घ)(वृक्ष_2->start + वृक्ष_2->आकार - 1));
                अगर (never_fatal <= 0)
                    वापस INVALID_POINTER; /* return an invalid pointer */
                वापस p + offset;
            }
        }
        अन्यथा अगर (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_गिनती(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__खाता__, __FUNCTION__, p);
            वापस p + offset;
        }
    }
    POST_SEM ();
    वापस p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#घोषणा BOUND_PTR_INDIR(dsize)                                                 \
व्योम * __bound_ptr_indir ## dsize (व्योम *p, माप_प्रकार offset)                     \
{                                                                              \
    माप_प्रकार addr = (माप_प्रकार)p;                                                   \
                                                                               \
    अगर (NO_CHECKING_GET())                                                     \
        वापस p + offset;                                                     \
                                                                               \
    dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",                                    \
            __खाता__, __FUNCTION__, p, (अचिन्हित दीर्घ)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_गिनती(bound_ptr_indir ## dsize ## गिनती);                            \
    अगर (वृक्ष_2) {                                                                \
        addr -= वृक्ष_2->start;                                                   \
        अगर (addr >= वृक्ष_2->आकार) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay (addr, वृक्ष_2);                                         \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        अगर (addr >= वृक्ष_2->आकार) {                                              \
            addr = (माप_प्रकार)p;                                                  \
            वृक्ष_2 = splay_end (addr, वृक्ष_2);                                     \
            addr -= वृक्ष_2->start;                                               \
        }                                                                      \
        अगर (addr <= वृक्ष_2->आकार) {                                              \
            अगर (वृक्ष_2->is_invalid || addr + offset + dsize > वृक्ष_2->आकार) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (दीर्घ)वृक्ष_2->start,            \
                              (दीर्घ)(वृक्ष_2->start + वृक्ष_2->आकार - 1));           \
                अगर (never_fatal <= 0)                                          \
                    वापस INVALID_POINTER; /* return an invalid pointer */    \
                वापस p + offset;                                             \
            }                                                                  \
        }                                                                      \
        अन्यथा {                                                                 \
            INCR_गिनती(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__खाता__, __FUNCTION__, p);               \
            वापस p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    वापस p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#अगर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#आशय GCC diagnostic धकेलो
#आशय GCC diagnostic ignored "-Wframe-address"
#पूर्ण_अगर

/* return the frame pointer of the caller */
#घोषणा GET_CALLER_FP(fp)\
{\
    fp = (माप_प्रकार)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
व्योम FASTCALL __bound_local_new(व्योम *p1) 
{
    माप_प्रकार addr, fp, *p = p1;

    अगर (NO_CHECKING_GET())
         वापस;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __खाता__, __FUNCTION__, p, (व्योम *)fp);
    WAIT_SEM ();
    जबतक ((addr = p[0])) {
        INCR_गिनती(bound_local_new_गिनती);
        वृक्ष_2 = splay_जोड़ो(addr + fp, p[1], वृक्ष_2);
        p += 2;
    }
    POST_SEM ();
#अगर BOUND_DEBUG
    अगर (print_calls) {
        p = p1;
        जबतक ((addr = p[0])) {
            dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
                    __खाता__, __FUNCTION__,
                    (व्योम *) (addr + fp), (अचिन्हित दीर्घ) p[1]);
            p += 2;
        }
    }
#पूर्ण_अगर
}

/* called when leaving a function to delete all the local regions */
व्योम FASTCALL __bound_local_delete(व्योम *p1) 
{
    माप_प्रकार addr, fp, *p = p1;

    अगर (NO_CHECKING_GET())
         वापस;
    GET_CALLER_FP(fp);
    dprintf(मानक_त्रुटि, "%s, %s(): p1=%p fp=%p\n",
            __खाता__, __FUNCTION__, p, (व्योम *)fp);
    WAIT_SEM ();
    जबतक ((addr = p[0])) {
        INCR_गिनती(bound_local_delete_गिनती);
        वृक्ष_2 = splay_delete(addr + fp, वृक्ष_2);
        p += 2;
    }
    अगर (alloca_list) {
        alloca_list_type *last = शून्य;
        alloca_list_type *cur = alloca_list;

        करो {
            अगर (cur->fp == fp) {
                अगर (last)
                    last->अग्र = cur->अग्र;
                अन्यथा
                    alloca_list = cur->अग्र;
                वृक्ष_2 = splay_delete ((माप_प्रकार) cur->p, वृक्ष_2);
                dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                        __खाता__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->अग्र : alloca_list;
             }
             अन्यथा {
                 last = cur;
                 cur = cur->अग्र;
             }
        } जबतक (cur);
    }
    अगर (jmp_list) {
        jmp_list_type *last = शून्य;
        jmp_list_type *cur = jmp_list;

        करो {
            अगर (cur->fp == fp) {
                अगर (last)
                    last->अग्र = cur->अग्र;
                अन्यथा
                    jmp_list = cur->अग्र;
                dprintf(मानक_त्रुटि, "%s, %s(): remove setjmp %p\n",
                       __खाता__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->अग्र : jmp_list;
            }
            अन्यथा {
                last = cur;
                cur = cur->अग्र;
            }
        } जबतक (cur);
    }

    POST_SEM ();
#अगर BOUND_DEBUG
    अगर (print_calls) {
        p = p1;
        जबतक ((addr = p[0])) {
            अगर (addr != 1) {
                dprintf(मानक_त्रुटि, "%s, %s(): %p 0x%lx\n",
                        __खाता__, __FUNCTION__,
                        (व्योम *) (addr + fp), (अचिन्हित दीर्घ) p[1]);
            }
            p+= 2;
        }
    }
#पूर्ण_अगर
}

/* used by alloca */
व्योम __bound_new_region(व्योम *p, माप_प्रकार आकार)
{
    माप_प्रकार fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    अगर (NO_CHECKING_GET())
        वापस;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, p, (अचिन्हित दीर्घ)आकार);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (माप (alloca_list_type));
    WAIT_SEM ();
    INCR_गिनती(bound_alloca_गिनती);
    last = शून्य;
    cur = alloca_list;
    जबतक (cur) {
#अगर defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        पूर्णांक align = 4;
#या_अगर defined(__arm__)
        पूर्णांक align = 8;
#अन्यथा
        पूर्णांक align = 16;
#पूर्ण_अगर
        व्योम *cure = (व्योम *)((अक्षर *)cur->p + ((cur->आकार + align) & -align));
        व्योम *pe = (व्योम *)((अक्षर *)p + ((आकार + align) & -align));
        अगर (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            अगर (last)
                last->अग्र = cur->अग्र;
            अन्यथा
                alloca_list = cur->अग्र;
            वृक्ष_2 = splay_delete((माप_प्रकार)cur->p, वृक्ष_2);
            अवरोध;
        }
        last = cur;
        cur = cur->अग्र;
    }
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार)p, आकार, वृक्ष_2);
    अगर (new) {
        new->fp = fp;
        new->p = p;
        new->आकार = आकार;
        new->अग्र = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    अगर (cur) {
        dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                __खाता__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

व्योम __bound_setjmp(लाँघ_बफ env)
{
    jmp_list_type *jl;
    व्योम *e = (व्योम *) env;

    अगर (NO_CHECKING_GET() == 0) {
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __खाता__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_गिनती(bound_setjmp_गिनती);
        jl = jmp_list;
        जबतक (jl) {
            अगर (jl->penv == e)
                अवरोध;
            jl = jl->अग्र;
        }
        अगर (jl == शून्य) {
            jl = BOUND_MALLOC (माप (jmp_list_type));
            अगर (jl) {
                jl->penv = e;
                jl->अग्र = jmp_list;
                jmp_list = jl;
            }
        }
        अगर (jl) {
            माप_प्रकार fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (माप_प्रकार)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

अटल व्योम __bound_long_jump(लाँघ_बफ env, पूर्णांक val, पूर्णांक sig, स्थिर अक्षर *func)
{
    jmp_list_type *jl;
    व्योम *e;
    BOUND_TID_TYPE tid;

    अगर (NO_CHECKING_GET() == 0) {
        e = (व्योम *)env;
        BOUND_GET_TID(tid);
        dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __खाता__, func, e);
        WAIT_SEM();
        INCR_गिनती(bound_longjmp_गिनती);
        jl = jmp_list;
        जबतक (jl) {
            अगर (jl->penv == e && jl->tid == tid) {
                माप_प्रकार start_fp = (माप_प्रकार)__builtin_frame_address(0);
                माप_प्रकार end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = शून्य;

                जबतक (cur->penv != e || cur->tid != tid) {
                    अगर (cur->tid == tid) {
                        dprintf(मानक_त्रुटि, "%s, %s(): remove setjmp %p\n",
                                __खाता__, func, cur->penv);
                        अगर (last)
                            last->अग्र = cur->अग्र;
                        अन्यथा
                            jmp_list = cur->अग्र;
                        BOUND_FREE (cur);
                        cur = last ? last->अग्र : jmp_list;
                    }
                    अन्यथा {
                        last = cur;
                        cur = cur->अग्र;
                    }
                }
                क्रम (;;) {
                    वृक्ष *t = वृक्ष_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    जबतक (t && (t->start < start_fp || t->start > end_fp))
                        अगर (t->start < start_fp)
                            t = t->दायाँ;
                        अन्यथा
                            t = t->बायाँ;
                    अगर (t == शून्य)
                        अवरोध;
                    last = शून्य;
                    cur = alloca_list;
                    जबतक (cur) {
                         अगर ((माप_प्रकार) cur->p == t->start) {
                             dprintf(मानक_त्रुटि, "%s, %s(): remove alloca/vla %p\n",
                                     __खाता__, func, cur->p);
                             अगर (last)
                                 last->अग्र = cur->अग्र;
                             अन्यथा
                                 alloca_list = cur->अग्र;
                             BOUND_FREE (cur);
                             अवरोध;
                         }
                         last = cur;
                         cur = cur->अग्र;
                    }
                    dprintf(मानक_त्रुटि, "%s, %s(): delete %p\n",
                            __खाता__, func, (व्योम *) t->start);
                    वृक्ष_2 = splay_delete(t->start, वृक्ष_2);
                }
                अवरोध;
            }
            jl = jl->अग्र;
        }
        POST_SEM();
    }
#अगर !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#पूर्ण_अगर
    दीर्घ_लाँघ (env, val);
}

व्योम __bound_longjmp(लाँघ_बफ env, पूर्णांक val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#अगर !defined(_WIN32)
व्योम __bound_siglongjmp(लाँघ_बफ env, पूर्णांक val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#पूर्ण_अगर

#अगर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#आशय GCC diagnostic निकालो
#पूर्ण_अगर

व्योम __bound_init(माप_प्रकार *p, पूर्णांक mode)
{
    dprintf(मानक_त्रुटि, "%s, %s(): start %s\n", __खाता__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    अगर (inited) {
        WAIT_SEM();
        जाओ add_bounds;
    }
    inited = 1;

#अगर HAVE_TLS_FUNC
#अगर defined(_WIN32)
    no_checking_कुंजी = TlsAlloc();
    Tls_Set_मूल्य(no_checking_कुंजी, &no_checking);
#अन्यथा
    pthread_key_create(&no_checking_कुंजी, शून्य);
    pthread_setspecific(no_checking_कुंजी, &no_checking);
#पूर्ण_अगर
#पूर्ण_अगर
    NO_CHECKING_SET(1);

    print_warn_ptr_add = दो_पर्या ("TCC_BOUNDS_WARN_POINTER_ADD") != शून्य;
    print_calls = दो_पर्या ("TCC_BOUNDS_PRINT_CALLS") != शून्य;
    print_heap = दो_पर्या ("TCC_BOUNDS_PRINT_HEAP") != शून्य;
    print_statistic = दो_पर्या ("TCC_BOUNDS_PRINT_STATISTIC") != शून्य;
    never_fatal = दो_पर्या ("TCC_BOUNDS_NEVER_FATAL") != शून्य;

    INIT_SEM ();

#अगर MALLOC_REDIR
    {
        व्योम *addr = mode > 0 ? RTLD_DEFAULT : RTLD_अग्र;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(व्योम **) (&malloc_redir) = dlsym (addr, "malloc");
        अगर (malloc_redir == शून्य) {
            dprintf(मानक_त्रुटि, "%s, %s(): use RTLD_DEFAULT\n",
                    __खाता__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(व्योम **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(व्योम **) (&calloc_redir) = dlsym (addr, "calloc");
        *(व्योम **) (&free_redir) = dlsym (addr, "free");
        *(व्योम **) (&realloc_redir) = dlsym (addr, "realloc");
        *(व्योम **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(मानक_त्रुटि, "%s, %s(): malloc_redir %p\n",
                __खाता__, __FUNCTION__, malloc_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): free_redir %p\n",
                __खाता__, __FUNCTION__, free_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): realloc_redir %p\n",
                __खाता__, __FUNCTION__, realloc_redir);
        dprintf(मानक_त्रुटि, "%s, %s(): memalign_redir %p\n",
                __खाता__, __FUNCTION__, memalign_redir);
        अगर (malloc_redir == शून्य || free_redir == शून्य)
            bound_alloc_error ("Cannot redirect malloc/free");
#अगर HAVE_PTHREAD_CREATE
        *(व्योम **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(मानक_त्रुटि, "%s, %s(): pthread_create_redir %p\n",
                __खाता__, __FUNCTION__, pthread_create_redir);
        अगर (pthread_create_redir == शून्य)
            bound_alloc_error ("Cannot redirect pthread_create");
#पूर्ण_अगर
#अगर HAVE_SIGNAL
        *(व्योम **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(मानक_त्रुटि, "%s, %s(): signal_redir %p\n",
                __खाता__, __FUNCTION__, signal_redir);
        अगर (signal_redir == शून्य)
            bound_alloc_error ("Cannot redirect signal");
#पूर्ण_अगर
#अगर HAVE_SIGACTION
        *(व्योम **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(मानक_त्रुटि, "%s, %s(): sigaction_redir %p\n",
                __खाता__, __FUNCTION__, sigaction_redir);
        अगर (sigaction_redir == शून्य)
            bound_alloc_error ("Cannot redirect sigaction");
#पूर्ण_अगर
#अगर HAVE_FORK
        *(व्योम **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(मानक_त्रुटि, "%s, %s(): fork_redir %p\n",
                __खाता__, __FUNCTION__, fork_redir);
        अगर (fork_redir == शून्य)
            bound_alloc_error ("Cannot redirect fork");
#पूर्ण_अगर
    }
#पूर्ण_अगर

#अगर_घोषित __linux__
    {
        खाता *fp;
        अचिन्हित अक्षर found;
        अचिन्हित दीर्घ start;
        अचिन्हित दीर्घ end;
        अचिन्हित दीर्घ ad =
            (अचिन्हित दीर्घ) __builtin_return_address(0);
        अक्षर पंक्ति_2[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = ख_खोलो ("/proc/self/comm", "r");
        अगर (fp) {
            स_रखो (exec, 0, माप(exec));
            ख_पढ़ो (exec, 1, माप(exec) - 2, fp);
            अगर (म_अक्षर(exec,'\n'))
                *म_अक्षर(exec,'\n') = '\0';
            म_जोड़ो (exec, ":");
            ख_बंद (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = ख_खोलो ("/proc/self/maps", "r");
        अगर (fp) {
            जबतक (ख_माला_लो (पंक्ति_2, माप(पंक्ति_2), fp)) {
                अगर (माला_पूछो (पंक्ति_2, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    अवरोध;
                }
                अगर (म_माला (पंक्ति_2,"[heap]"))
                    अवरोध;
            }
            ख_बंद (fp);
        }
        अगर (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#पूर्ण_अगर

    WAIT_SEM ();

#अगर HAVE_CTYPE
#अगर_घोषित __APPLE__
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) &_DefaultRuneLocale,
                        माप (_DefaultRuneLocale), वृक्ष_2);
#अन्यथा
    /* XXX: Does not work if locale is changed */
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_b_loc(),
                        माप (अचिन्हित लघु *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_b_loc() - 128),
                        384 * माप (अचिन्हित लघु), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_tolower_loc(),
                        माप (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_tolower_loc() - 128),
                        384 * माप (__int32_t), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) __ctype_toupper_loc(),
                        माप (__int32_t *), वृक्ष_2);
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (*__ctype_toupper_loc() - 128),
                        384 * माप (__int32_t), वृक्ष_2);
#पूर्ण_अगर
#पूर्ण_अगर
#अगर HAVE_ERRNO
    वृक्ष_2 = splay_जोड़ो((माप_प्रकार) (&त्रुटि_सं), माप (पूर्णांक), वृक्ष_2);
#पूर्ण_अगर

add_bounds:
    अगर (!p)
        जाओ no_bounds;

    /* add all static bound check values */
    जबतक (p[0] != 0) {
        वृक्ष_2 = splay_जोड़ो(p[0], p[1], वृक्ष_2);
#अगर BOUND_DEBUG
        dprintf(मानक_त्रुटि, "%s, %s(): static var %p 0x%lx\n",
                __खाता__, __FUNCTION__,
                (व्योम *) p[0], (अचिन्हित दीर्घ) p[1]);
#पूर्ण_अगर
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(मानक_त्रुटि, "%s, %s(): end\n\n", __खाता__, __FUNCTION__);
}

व्योम
#अगर (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#पूर्ण_अगर
__bound_main_arg(पूर्णांक argc, अक्षर **argv, अक्षर **envp)
{
    __bound_init (0, -1);
    अगर (argc && argv) {
        पूर्णांक i;

        WAIT_SEM ();
        क्रम (i = 0; i < argc; i++)
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) argv[i], म_माप (argv[i]) + 1, वृक्ष_2);
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार) argv, (argc + 1) * माप(अक्षर *), वृक्ष_2);
        POST_SEM ();
#अगर BOUND_DEBUG
        अगर (print_calls) {
            क्रम (i = 0; i < argc; i++)
                dprintf(मानक_त्रुटि, "%s, %s(): arg %p 0x%lx\n",
                        __खाता__, __FUNCTION__,
                        argv[i], (अचिन्हित दीर्घ)(म_माप (argv[i]) + 1));
            dprintf(मानक_त्रुटि, "%s, %s(): argv %p %d\n",
                    __खाता__, __FUNCTION__, argv,
                    (पूर्णांक)((argc + 1) * माप(अक्षर *)));
        }
#पूर्ण_अगर
    }

    अगर (envp && *envp) {
        अक्षर **p = envp;

        WAIT_SEM ();
        जबतक (*p) {
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) *p, म_माप (*p) + 1, वृक्ष_2);
            ++p;
        }
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार) envp, (++p - envp) * माप(अक्षर *), वृक्ष_2);
        POST_SEM ();
#अगर BOUND_DEBUG
        अगर (print_calls) {
            p = envp;
            जबतक (*p) {
                dprintf(मानक_त्रुटि, "%s, %s(): env %p 0x%lx\n",
                        __खाता__, __FUNCTION__,
                        *p, (अचिन्हित दीर्घ)(म_माप (*p) + 1));
                ++p;
            }
            dprintf(मानक_त्रुटि, "%s, %s(): environ %p %d\n",
                    __खाता__, __FUNCTION__, envp,
                    (पूर्णांक)((++p - envp) * माप(अक्षर *)));
        }
#पूर्ण_अगर
    }
}

व्योम __attribute__((destructor)) __bound_exit(व्योम)
{
    पूर्णांक i;
    अटल स्थिर अक्षर * स्थिर alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(मानक_त्रुटि, "%s, %s():\n", __खाता__, __FUNCTION__);

    अगर (inited) {
#अगर !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        अगर (print_heap) {
            बाह्य व्योम __libc_freeres (व्योम);
            __libc_freeres ();
        }
#पूर्ण_अगर

        NO_CHECKING_SET(1);

        TRY_SEM ();
        जबतक (alloca_list) {
            alloca_list_type *अग्र = alloca_list->अग्र;

            वृक्ष_2 = splay_delete ((माप_प्रकार) alloca_list->p, वृक्ष_2);
            BOUND_FREE (alloca_list);
            alloca_list = अग्र;
        }
        जबतक (jmp_list) {
           jmp_list_type *अग्र  = jmp_list->अग्र;

           BOUND_FREE (jmp_list);
           jmp_list = अग्र;
        }
        क्रम (i = 0; i < FREE_REUSE_आकार; i++) {
            अगर (free_reuse_list[i]) {
                वृक्ष_2 = splay_delete ((माप_प्रकार) free_reuse_list[i], वृक्ष_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        जबतक (वृक्ष_2) {
            अगर (print_heap && वृक्ष_2->type != 0)
                ख_लिखो (मानक_त्रुटि, "%s, %s(): %s found size %lu\n",
                         __खाता__, __FUNCTION__, alloc_type[वृक्ष_2->type],
                         (अचिन्हित दीर्घ) वृक्ष_2->आकार);
            वृक्ष_2 = splay_delete (वृक्ष_2->start, वृक्ष_2);
        }
#अगर वृक्ष_REUSE
        जबतक (वृक्ष_free_list) {
            वृक्ष *अग्र = वृक्ष_free_list->बायाँ;
            BOUND_FREE (वृक्ष_free_list);
            वृक्ष_free_list = अग्र;
        }
#पूर्ण_अगर
        POST_SEM ();
        EXIT_SEM ();
#अगर HAVE_TLS_FUNC
#अगर defined(_WIN32)
        TlsFree(no_checking_कुंजी);
#अन्यथा
        pthread_key_delete(no_checking_कुंजी);
#पूर्ण_अगर
#पूर्ण_अगर
        inited = 0;
        अगर (print_statistic) {
#अगर BOUND_STATISTIC
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
#पूर्ण_अगर
#अगर BOUND_STATISTIC_SPLAY
            ख_लिखो (मानक_त्रुटि, "bound_splay              %llu\n", bound_splay);
            ख_लिखो (मानक_त्रुटि, "bound_splay_end          %llu\n", bound_splay_end);
            ख_लिखो (मानक_त्रुटि, "bound_splay_insert       %llu\n", bound_splay_जोड़ो);
            ख_लिखो (मानक_त्रुटि, "bound_splay_delete       %llu\n", bound_splay_delete);
#पूर्ण_अगर
        }
    }
}

व्योम __bound_exit_dll(माप_प्रकार *p)
{
    dprintf(मानक_त्रुटि, "%s, %s()\n", __खाता__, __FUNCTION__);

    अगर (p) {
        WAIT_SEM ();
	जबतक (p[0] != 0) {
	    वृक्ष_2 = splay_delete(p[0], वृक्ष_2);
#अगर BOUND_DEBUG
            अगर (print_calls) {
                dprintf(मानक_त्रुटि, "%s, %s(): remove static var %p 0x%lx\n",
                        __खाता__, __FUNCTION__,
                        (व्योम *) p[0], (अचिन्हित दीर्घ) p[1]);
            }
#पूर्ण_अगर
	    p += 2;
	}
        POST_SEM ();
    }
}

#अगर HAVE_PTHREAD_CREATE
प्रकार काष्ठा {
    व्योम *(*start_routine) (व्योम *);
    व्योम *arg;
    sigset_t old_mask;
} bound_thread_create_type;

अटल व्योम *bound_thread_create(व्योम *bdata)
{
    bound_thread_create_type *तथ्य = (bound_thread_create_type *) bdata;
    व्योम *retval;
#अगर HAVE_TLS_FUNC
    पूर्णांक *p = (पूर्णांक *) BOUND_MALLOC(माप(पूर्णांक));
  
    अगर (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_कुंजी, p);
#पूर्ण_अगर
    pthread_sigmask(SIG_SETMASK, &तथ्य->old_mask, शून्य);
    retval = तथ्य->start_routine(तथ्य->arg);
#अगर HAVE_TLS_FUNC
    pthread_setspecific(no_checking_कुंजी, शून्य);
    BOUND_FREE (p);
#पूर्ण_अगर
    BOUND_FREE (तथ्य);
    वापस retval;
}

पूर्णांक pthread_create(pthread_t *thread, स्थिर pthread_attr_t *attr,
                   व्योम *(*start_routine) (व्योम *), व्योम *arg)
{
    पूर्णांक retval;
    bound_thread_create_type *तथ्य;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (मानक_त्रुटि, "%s, %s()\n", __खाता__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    तथ्य = (bound_thread_create_type *) BOUND_MALLOC(माप(bound_thread_create_type));
    अगर (!तथ्य) bound_alloc_error("bound_thread_create malloc");
    तथ्य->start_routine = start_routine;
    तथ्य->arg = arg;
    तथ्य->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, तथ्य);
    pthread_sigmask(SIG_SETMASK, &old_mask, शून्य);
    वापस retval;
}
#पूर्ण_अगर

#अगर HAVE_SIGNAL || HAVE_SIGACTION
प्रकार जोड़ {
#अगर HAVE_SIGNAL
    bound_sig signal_handler;
#पूर्ण_अगर
#अगर HAVE_SIGACTION
    व्योम (*sig_handler)(पूर्णांक);
    व्योम (*sig_sigaction)(पूर्णांक, siginfo_t *, व्योम *);
#पूर्ण_अगर
} bound_sig_type;

अटल अचिन्हित अक्षर bound_sig_used[NSIG];
अटल bound_sig_type bound_sig_तथ्य[NSIG];
#पूर्ण_अगर

#अगर HAVE_SIGNAL
अटल व्योम signal_handler(पूर्णांक sig)
{
   __bounds_checking(1);
   bound_sig_तथ्य[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig संकेत(पूर्णांक signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (मानक_त्रुटि, "%s, %s() %d %p\n", __खाता__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    अगर (retval != संक_त्रुटि) {
        अगर (bound_sig_used[signum])
            retval = bound_sig_तथ्य[signum].signal_handler;
        अगर (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_तथ्य[signum].signal_handler = handler;
        }
    }
    वापस retval;
}
#पूर्ण_अगर

#अगर HAVE_SIGACTION
अटल व्योम sig_handler(पूर्णांक sig)
{
   __bounds_checking(1);
   bound_sig_तथ्य[sig].sig_handler(sig);
   __bounds_checking(-1);
}

अटल व्योम sig_sigaction(पूर्णांक sig, siginfo_t *info, व्योम *ucontext)
{
   __bounds_checking(1);
   bound_sig_तथ्य[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

पूर्णांक sigaction(पूर्णांक signum, स्थिर काष्ठा sigaction *act, काष्ठा sigaction *oldact)
{
    पूर्णांक retval;
    काष्ठा sigaction nact, oact;

    dprintf (मानक_त्रुटि, "%s, %s() %d %p %p\n", __खाता__, __FUNCTION__,
             signum, act, oldact);

    अगर (sigaction_redir == शून्य)
        __bound_init(0,-1);

    अगर (act) {
        nact = *act;
        अगर (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        अन्यथा
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    अन्यथा
        retval = sigaction_redir(signum, act, &oact);
    अगर (retval >= 0) {
        अगर (bound_sig_used[signum]) {
            अगर (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_तथ्य[signum].sig_sigaction;
            अन्यथा
                oact.sa_handler = bound_sig_तथ्य[signum].sig_handler;
        }
        अगर (oldact) {
            *oldact = oact;
        }
        अगर (act) {
            bound_sig_used[signum] = 1;
            अगर (act->sa_flags & SA_SIGINFO)
                bound_sig_तथ्य[signum].sig_sigaction = act->sa_sigaction;
            अन्यथा
                bound_sig_तथ्य[signum].sig_handler = act->sa_handler;
        }
    }
    वापस retval;
}
#पूर्ण_अगर

#अगर HAVE_FORK
pid_t विभाजन(व्योम)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    अगर (retval == 0)
        INIT_SEM();
    अन्यथा
        POST_SEM();
    वापस retval;
}
#पूर्ण_अगर

#अगर MALLOC_REDIR
व्योम *दो_स्मृति(माप_प्रकार आकार)
#अन्यथा
व्योम *__bound_malloc(माप_प्रकार आकार, स्थिर व्योम *caller)
#पूर्ण_अगर
{
    व्योम *ptr;
    
#अगर MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    अगर (malloc_redir == शून्य) {
        __bound_init (0, -1);
        अगर (malloc_redir == शून्य) {
            ptr = &initial_pool[pool_सूचकांक];
            pool_सूचकांक = (pool_सूचकांक + आकार + 15) & ~15;
            अगर (pool_सूचकांक >= माप (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __खाता__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)आकार);
            वापस ptr;
        }
    }
#पूर्ण_अगर
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (आकार + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)आकार);
    
    अगर (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_malloc_गिनती);

        अगर (ptr) {
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) ptr, आकार ? आकार : आकार + 1, वृक्ष_2);
            अगर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    वापस ptr;
}

#अगर MALLOC_REDIR
व्योम *memalign(माप_प्रकार align, माप_प्रकार आकार)
#अन्यथा
व्योम *__bound_memalign(माप_प्रकार align, माप_प्रकार आकार, स्थिर व्योम *caller)
#पूर्ण_अगर
{
    व्योम *ptr;

#अगर HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, आकार + 1);
#अन्यथा
    अगर (align > 4) {
        /* XXX: handle it ? */
        ptr = शून्य;
    } अन्यथा {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(आकार + 1);
    }
#पूर्ण_अगर
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)आकार);

    अगर (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_memalign_गिनती);

        अगर (ptr) {
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार) ptr, आकार ? आकार : आकार + 1, वृक्ष_2);
            अगर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    वापस ptr;
}

#अगर MALLOC_REDIR
व्योम मुक्त(व्योम *ptr)
#अन्यथा
व्योम __bound_free(व्योम *ptr, स्थिर व्योम *caller)
#पूर्ण_अगर
{
    माप_प्रकार addr = (माप_प्रकार) ptr;
    व्योम *p;

    अगर (ptr == शून्य || वृक्ष_2 == शून्य
#अगर MALLOC_REDIR
        || ((अचिन्हित अक्षर *) ptr >= &initial_pool[0] &&
            (अचिन्हित अक्षर *) ptr < &initial_pool[माप(initial_pool)])
#पूर्ण_अगर
        )
        वापस;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n", __खाता__, __FUNCTION__, ptr);

    अगर (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_free_गिनती);
        वृक्ष_2 = splay (addr, वृक्ष_2);
        अगर (वृक्ष_2->start == addr) {
            अगर (वृक्ष_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                वापस;
            }
            वृक्ष_2->is_invalid = 1;
            स_रखो (ptr, 0x5a, वृक्ष_2->आकार);
            p = free_reuse_list[free_reuse_सूचकांक];
            free_reuse_list[free_reuse_सूचकांक] = ptr;
            free_reuse_सूचकांक = (free_reuse_सूचकांक + 1) % FREE_REUSE_आकार;
            अगर (p)
                वृक्ष_2 = splay_delete((माप_प्रकार)p, वृक्ष_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#अगर MALLOC_REDIR
व्योम *पुनः_स्मृति(व्योम *ptr, माप_प्रकार आकार)
#अन्यथा
व्योम *__bound_realloc(व्योम *ptr, माप_प्रकार आकार, स्थिर व्योम *caller)
#पूर्ण_अगर
{
    व्योम *new_ptr;

    अगर (आकार == 0) {
#अगर MALLOC_REDIR
        मुक्त(ptr);
#अन्यथा
        __bound_free(ptr, caller);
#पूर्ण_अगर
        वापस शून्य;
    }

    new_ptr = BOUND_REALLOC (ptr, आकार + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, new_ptr, (अचिन्हित दीर्घ)आकार);

    अगर (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_realloc_गिनती);

        अगर (ptr)
            वृक्ष_2 = splay_delete ((माप_प्रकार) ptr, वृक्ष_2);
        अगर (new_ptr) {
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) new_ptr, आकार ? आकार : आकार + 1, वृक्ष_2);
            अगर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new_ptr)
                वृक्ष_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    वापस new_ptr;
}

#अगर MALLOC_REDIR
व्योम *सुस्मृति(माप_प्रकार nmemb, माप_प्रकार आकार)
#अन्यथा
व्योम *__bound_calloc(माप_प्रकार nmemb, माप_प्रकार आकार)
#पूर्ण_अगर
{
    व्योम *ptr;

    आकार *= nmemb;
#अगर MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    अगर (malloc_redir == शून्य) {
        __bound_init (0, -1);
        अगर (malloc_redir == शून्य) {
            ptr = &initial_pool[pool_सूचकांक];
            pool_सूचकांक = (pool_सूचकांक + आकार + 15) & ~15;
            अगर (pool_सूचकांक >= माप (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (मानक_त्रुटि, "%s, %s(): initial %p, 0x%lx\n",
                     __खाता__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)आकार);
            स_रखो (ptr, 0, आकार);
            वापस ptr;
        }
    }
#पूर्ण_अगर
    ptr = BOUND_MALLOC(आकार + 1);
    dprintf (मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
             __खाता__, __FUNCTION__, ptr, (अचिन्हित दीर्घ)आकार);

    अगर (ptr) {
        स_रखो (ptr, 0, आकार);
        अगर (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_गिनती(bound_calloc_गिनती);
            वृक्ष_2 = splay_जोड़ो ((माप_प्रकार) ptr, आकार ? आकार : आकार + 1, वृक्ष_2);
            अगर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) ptr)
                वृक्ष_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    वापस ptr;
}

#अगर !defined(_WIN32)
व्योम *__bound_mmap (व्योम *start, माप_प्रकार आकार, पूर्णांक prot,
                    पूर्णांक flags, पूर्णांक fd, off_t offset)
{
    व्योम *परिणाम;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, start, (अचिन्हित दीर्घ)आकार);
    परिणाम = mmap (start, आकार, prot, flags, fd, offset);
    अगर (परिणाम && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_mmap_गिनती);
        वृक्ष_2 = splay_जोड़ो((माप_प्रकार)परिणाम, आकार, वृक्ष_2);
        POST_SEM ();
    }
    वापस परिणाम;
}

पूर्णांक __bound_munmap (व्योम *start, माप_प्रकार आकार)
{
    पूर्णांक परिणाम;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, start, (अचिन्हित दीर्घ)आकार);
    अगर (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_गिनती(bound_munmap_गिनती);
        वृक्ष_2 = splay_delete ((माप_प्रकार) start, वृक्ष_2);
        POST_SEM ();
    }
    परिणाम = munmap (start, आकार);
    वापस परिणाम;
}
#पूर्ण_अगर

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
अटल व्योम __bound_check(स्थिर व्योम *p, माप_प्रकार आकार, स्थिर अक्षर *function)
{
    अगर (आकार != 0 && __bound_ptr_add((व्योम *)p, आकार) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (अचिन्हित दीर्घ)आकार, function);
    }
}

अटल पूर्णांक check_overlap (स्थिर व्योम *p1, माप_प्रकार n1,
                          स्थिर व्योम *p2, माप_प्रकार n2,
                          स्थिर अक्षर *function)
{
    स्थिर व्योम *p1e = (स्थिर व्योम *) ((स्थिर अक्षर *) p1 + n1);
    स्थिर व्योम *p2e = (स्थिर व्योम *) ((स्थिर अक्षर *) p2 + n2);

    अगर (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (अचिन्हित दीर्घ)n1, p2, (अचिन्हित दीर्घ)n2, function);
        वापस never_fatal < 0;
    }
    वापस 0;
}

व्योम *__bound_memcpy(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_mempcy_गिनती);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    अगर (check_overlap(dest, n, src, n, "memcpy"))
        वापस dest;
    वापस स_नकल(dest, src, n);
}

पूर्णांक __bound_memcmp(स्थिर व्योम *s1, स्थिर व्योम *s2, माप_प्रकार n)
{
    स्थिर अचिन्हित अक्षर *u1 = (स्थिर अचिन्हित अक्षर *) s1;
    स्थिर अचिन्हित अक्षर *u2 = (स्थिर अचिन्हित अक्षर *) s2;
    पूर्णांक retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memcmp_गिनती);
    क्रम (;;) {
        अगर ((ssize_t) --n == -1)
            अवरोध;
        अन्यथा अगर (*u1 != *u2) {
            retval = *u1++ - *u2++;
            अवरोध;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (स्थिर व्योम *)u1 - s1, "memcmp s1");
    __bound_check(s2, (स्थिर व्योम *)u2 - s2, "memcmp s2");
    वापस retval;
}

व्योम *__bound_memmove(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    वापस स_हटाओ(dest, src, n);
}

व्योम *__bound_memset(व्योम *s, पूर्णांक c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __खाता__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memset_गिनती);
    __bound_check(s, n, "memset");
    वापस स_रखो(s, c, n);
}

#अगर defined(__arm__) && defined(__ARM_EABI__)
व्योम *__bound___aeabi_memcpy(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_mempcy_गिनती);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    अगर (check_overlap(dest, n, src, n, "memcpy"))
        वापस dest;
    वापस __aeabi_memcpy(dest, src, n);
}

व्योम *__bound___aeabi_memmove(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    वापस __aeabi_memmove(dest, src, n);
}

व्योम *__bound___aeabi_memmove4(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    वापस __aeabi_memmove4(dest, src, n);
}

व्योम *__bound___aeabi_memmove8(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memmove_गिनती);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    वापस __aeabi_memmove8(dest, src, n);
}

व्योम *__bound___aeabi_memset(व्योम *s, पूर्णांक c, माप_प्रकार n)
{
    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d, 0x%lx\n",
            __खाता__, __FUNCTION__, s, c, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_memset_गिनती);
    __bound_check(s, n, "memset");
    वापस __aeabi_memset(s, c, n);
}
#पूर्ण_अगर

पूर्णांक __bound_strlen(स्थिर अक्षर *s)
{
    स्थिर अक्षर *p = s;

    dprintf(मानक_त्रुटि, "%s, %s(): %p\n",
            __खाता__, __FUNCTION__, s);
    INCR_गिनती(bound_strlen_गिनती);
    जबतक (*p++);
    __bound_check(s, p - s, "strlen");
    वापस (p - s) - 1;
}

अक्षर *__bound_strcpy(अक्षर *dest, स्थिर अक्षर *src)
{
    माप_प्रकार len;
    स्थिर अक्षर *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __खाता__, __FUNCTION__, dest, src);
    INCR_गिनती(bound_strcpy_गिनती);
    जबतक (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    अगर (check_overlap(dest, len, src, len, "strcpy"))
        वापस dest;
    वापस म_नकल (dest, src);
}

अक्षर *__bound_strncpy(अक्षर *dest, स्थिर अक्षर *src, माप_प्रकार n)
{
    माप_प्रकार len = n;
    स्थिर अक्षर *p = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncpy_गिनती);
    जबतक (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    अगर (check_overlap(dest, len, src, len, "strncpy"))
        वापस dest;
    वापस म_नकलन(dest, src, n);
}

पूर्णांक __bound_strcmp(स्थिर अक्षर *s1, स्थिर अक्षर *s2)
{
    स्थिर अचिन्हित अक्षर *u1 = (स्थिर अचिन्हित अक्षर *) s1;
    स्थिर अचिन्हित अक्षर *u2 = (स्थिर अचिन्हित अक्षर *) s2;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __खाता__, __FUNCTION__, s1, s2);
    INCR_गिनती(bound_strcmp_गिनती);
    जबतक (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((स्थिर अक्षर *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((स्थिर अक्षर *)u2 - s2) + 1, "strcmp s2");
    वापस *u1 - *u2;
}

पूर्णांक __bound_strncmp(स्थिर अक्षर *s1, स्थिर अक्षर *s2, माप_प्रकार n)
{
    स्थिर अचिन्हित अक्षर *u1 = (स्थिर अचिन्हित अक्षर *) s1;
    स्थिर अचिन्हित अक्षर *u2 = (स्थिर अचिन्हित अक्षर *) s2;
    पूर्णांक retval = 0;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, s1, s2, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncmp_गिनती);
    करो {
        अगर ((ssize_t) --n == -1)
            अवरोध;
        अन्यथा अगर (*u1 != *u2) {
            retval = *u1++ - *u2++;
            अवरोध;
        }
        ++u2;
    } जबतक (*u1++);
    __bound_check(s1, (स्थिर अक्षर *)u1 - s1, "strncmp s1");
    __bound_check(s2, (स्थिर अक्षर *)u2 - s2, "strncmp s2");
    वापस retval;
}

अक्षर *__bound_strcat(अक्षर *dest, स्थिर अक्षर *src)
{
    अक्षर *r = dest;
    स्थिर अक्षर *s = src;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p\n",
            __खाता__, __FUNCTION__, dest, src);
    INCR_गिनती(bound_strcat_गिनती);
    जबतक (*dest++);
    जबतक (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    अगर (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        वापस dest;
    वापस म_जोड़ो(r, s);
}

अक्षर *__bound_strncat(अक्षर *dest, स्थिर अक्षर *src, माप_प्रकार n)
{
    अक्षर *r = dest;
    स्थिर अक्षर *s = src;
    माप_प्रकार len = n;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %p, 0x%lx\n",
            __खाता__, __FUNCTION__, dest, src, (अचिन्हित दीर्घ)n);
    INCR_गिनती(bound_strncat_गिनती);
    जबतक (*dest++);
    जबतक (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    अगर (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        वापस dest;
    वापस म_जोड़न(r, s, n);
}

अक्षर *__bound_strchr(स्थिर अक्षर *s, पूर्णांक c)
{
    स्थिर अचिन्हित अक्षर *str = (स्थिर अचिन्हित अक्षर *) s;
    अचिन्हित अक्षर ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __खाता__, __FUNCTION__, s, ch);
    INCR_गिनती(bound_strchr_गिनती);
    जबतक (*str) {
        अगर (*str == ch)
            अवरोध;
        ++str;
    }
    __bound_check(s, ((स्थिर अक्षर *)str - s) + 1, "strchr");
    वापस *str == ch ? (अक्षर *) str : शून्य;
}

अक्षर *__bound_strrchr(स्थिर अक्षर *s, पूर्णांक c)
{
    स्थिर अचिन्हित अक्षर *str = (स्थिर अचिन्हित अक्षर *) s;
    अचिन्हित अक्षर ch = c;

    dprintf(मानक_त्रुटि, "%s, %s(): %p, %d\n",
            __खाता__, __FUNCTION__, s, ch);
    INCR_गिनती(bound_strrchr_गिनती);
    जबतक (*str++);
    __bound_check(s, (स्थिर अक्षर *)str - s, "strrchr");
    जबतक (str != (स्थिर अचिन्हित अक्षर *)s) {
        अगर (*--str == ch)
            अवरोध;
    }
    __bound_check(s, (स्थिर अक्षर *)str - s, "strrchr");
    वापस *str == ch ? (अक्षर *) str : शून्य;
}

अक्षर *__bound_strdup(स्थिर अक्षर *s)
{
    स्थिर अक्षर *p = s;
    अक्षर *new;

    INCR_गिनती(bound_strdup_गिनती);
    जबतक (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(मानक_त्रुटि, "%s, %s(): %p, 0x%lx\n",
            __खाता__, __FUNCTION__, new, (अचिन्हित दीर्घ)(p -s));
    अगर (new) {
        अगर (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            वृक्ष_2 = splay_जोड़ो((माप_प्रकार)new, p - s, वृक्ष_2);
            अगर (वृक्ष_2 && वृक्ष_2->start == (माप_प्रकार) new)
                वृक्ष_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        स_नकल (new, s, p - s);
    }
    वापस new;
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

#घोषणा compare(start,tstart,tsize) (start < tstart ? -1 : \
                                     start >= tstart+tsize  ? 1 : 0)

अटल वृक्ष * splay (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    वृक्ष N, *l, *r, *y;
    पूर्णांक comp;
    
    INCR_गिनती_SPLAY(bound_splay);
    अगर (t == शून्य) वापस t;
    N.बायाँ = N.दायाँ = शून्य;
    l = r = &N;
 
    क्रम (;;) {
        comp = compare(addr, t->start, t->आकार);
        अगर (comp < 0) {
            y = t->बायाँ;
            अगर (y == शून्य) अवरोध;
            अगर (compare(addr, y->start, y->आकार) < 0) {
                t->बायाँ = y->दायाँ;                    /* rotate right */
                y->दायाँ = t;
                t = y;
                अगर (t->बायाँ == शून्य) अवरोध;
            }
            r->बायाँ = t;                               /* link right */
            r = t;
            t = t->बायाँ;
        } अन्यथा अगर (comp > 0) {
            y = t->दायाँ;
            अगर (y == शून्य) अवरोध;
            अगर (compare(addr, y->start, y->आकार) > 0) {
                t->दायाँ = y->बायाँ;                    /* rotate left */
                y->बायाँ = t;
                t = y;
                अगर (t->दायाँ == शून्य) अवरोध;
            }
            l->दायाँ = t;                              /* link left */
            l = t;
            t = t->दायाँ;
        } अन्यथा {
            अवरोध;
        }
    }
    l->दायाँ = t->बायाँ;                                /* assemble */
    r->बायाँ = t->दायाँ;
    t->बायाँ = N.दायाँ;
    t->दायाँ = N.बायाँ;

    वापस t;
}

#घोषणा compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

अटल वृक्ष * splay_end (माप_प्रकार addr, वृक्ष *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    वृक्ष N, *l, *r, *y;
    पूर्णांक comp;
    
    INCR_गिनती_SPLAY(bound_splay_end);
    अगर (t == शून्य) वापस t;
    N.बायाँ = N.दायाँ = शून्य;
    l = r = &N;
 
    क्रम (;;) {
        comp = compare_end(addr, t->start + t->आकार);
        अगर (comp < 0) {
            y = t->बायाँ;
            अगर (y == शून्य) अवरोध;
            अगर (compare_end(addr, y->start + y->आकार) < 0) {
                t->बायाँ = y->दायाँ;                    /* rotate right */
                y->दायाँ = t;
                t = y;
                अगर (t->बायाँ == शून्य) अवरोध;
            }
            r->बायाँ = t;                               /* link right */
            r = t;
            t = t->बायाँ;
        } अन्यथा अगर (comp > 0) {
            y = t->दायाँ;
            अगर (y == शून्य) अवरोध;
            अगर (compare_end(addr, y->start + y->आकार) > 0) {
                t->दायाँ = y->बायाँ;                    /* rotate left */
                y->बायाँ = t;
                t = y;
                अगर (t->दायाँ == शून्य) अवरोध;
            }
            l->दायाँ = t;                              /* link left */
            l = t;
            t = t->दायाँ;
        } अन्यथा {
            अवरोध;
        }
    }
    l->दायाँ = t->बायाँ;                                /* assemble */
    r->बायाँ = t->दायाँ;
    t->बायाँ = N.दायाँ;
    t->दायाँ = N.बायाँ;

    वापस t;
}

अटल वृक्ष * splay_जोड़ो(माप_प्रकार addr, माप_प्रकार आकार, वृक्ष * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    वृक्ष * new;

    INCR_गिनती_SPLAY(bound_splay_जोड़ो);
    अगर (t != शून्य) {
        t = splay(addr,t);
        अगर (compare(addr, t->start, t->आकार)==0) {
            वापस t;  /* it's already there */
        }
    }
#अगर वृक्ष_REUSE
    अगर (वृक्ष_free_list) {
          new = वृक्ष_free_list;
          वृक्ष_free_list = new->बायाँ;
    }
    अन्यथा
#पूर्ण_अगर
    {
        new = (वृक्ष *) BOUND_MALLOC (माप (वृक्ष));
    }
    अगर (new == शून्य) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    अन्यथा {
        अगर (t == शून्य) {
            new->बायाँ = new->दायाँ = शून्य;
        } अन्यथा अगर (compare(addr, t->start, t->आकार) < 0) {
            new->बायाँ = t->बायाँ;
            new->दायाँ = t;
            t->बायाँ = शून्य;
        } अन्यथा {
            new->दायाँ = t->दायाँ;
            new->बायाँ = t;
            t->दायाँ = शून्य;
        }
        new->start = addr;
        new->आकार = आकार;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    वापस new;
}

#घोषणा compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

अटल वृक्ष * splay_delete(माप_प्रकार addr, वृक्ष *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    वृक्ष * x;

    INCR_गिनती_SPLAY(bound_splay_delete);
    अगर (t==शून्य) वापस शून्य;
    t = splay(addr,t);
    अगर (compare_destroy(addr, t->start) == 0) {        /* found it */
        अगर (t->बायाँ == शून्य) {
            x = t->दायाँ;
        } अन्यथा {
            x = splay(addr, t->बायाँ);
            x->दायाँ = t->दायाँ;
        }
#अगर वृक्ष_REUSE
        t->बायाँ = वृक्ष_free_list;
        वृक्ष_free_list = t;
#अन्यथा
        BOUND_FREE(t);
#पूर्ण_अगर
        वापस x;
    } अन्यथा {
        वापस t;                                      /* It wasn't there */
    }
}

व्योम splay_printtree(वृक्ष * t, पूर्णांक d)
{
    पूर्णांक i;
    अगर (t == शून्य) वापस;
    splay_printtree(t->दायाँ, d+1);
    क्रम (i=0; i<d; i++) ख_लिखो(मानक_त्रुटि," ");
    ख_लिखो(मानक_त्रुटि,"%p(0x%lx:%u:%u)\n",
            (व्योम *) t->start, (अचिन्हित दीर्घ) t->आकार,
            (अचिन्हित)t->type, (अचिन्हित)t->is_invalid);
    splay_printtree(t->बायाँ, d+1);
}
