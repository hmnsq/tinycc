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
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdarg.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <setjmp.h>
#અન્તર્ભાવ <stdatomic.h>

#જો !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#અન્તર્ભાવ <malloc.h>
#endif

#જો !defined(_WIN32)
#અન્તર્ભાવ <unistd.h>
#અન્તર્ભાવ <sys/syscall.h>
#endif

#અન્તર્ભાવ "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#જો BOUND_DEBUG
 #define dprintf(a...)         જો (print_calls) { bounds_loc(a); }
#નહીંતર
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#નહીંતર
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#નહીંતર
# define DLL_EXPORT
#endif

#જો defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#અન્તર્ભાવ <sys/mman.h>
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

#અથવાજો defined(_WIN32)

#અન્તર્ભાવ <windows.h>
#અન્તર્ભાવ <signal.h>
સ્થિર CRITICAL_SECTION bounds_sem;
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

#નહીંતર

#define __USE_GNU              /* get RTLD_NEXT */
#અન્તર્ભાવ <sys/mman.h>
#અન્તર્ભાવ <ctype.h>
#અન્તર્ભાવ <pthread.h>
#અન્તર્ભાવ <dlfcn.h>
#અન્તર્ભાવ <errno.h>
#અન્તર્ભાવ <signal.h>
#ifdef __APPLE__
#અન્તર્ભાવ <dispatch/dispatch.h>
સ્થિર dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             જો (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             જો (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              જો (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#અથવાજો 0
#અન્તર્ભાવ <semaphore.h>
સ્થિર sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             જો (use_sem) જ્યારે (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             જો (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              જો (use_sem) જ્યારે (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#અથવાજો 0
સ્થિર pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, ખાલી)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             જો (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             જો (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              જો (use_sem) pthread_mutex_trylock (&bounds_mtx)
#નહીંતર
સ્થિર pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             જો (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             જો (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              જો (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#જો defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#નહીંતર
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#જો defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#જો MALLOC_REDIR
સ્થિર શૂન્ય *(*malloc_redir) (size_t);
સ્થિર શૂન્ય *(*calloc_redir) (size_t, size_t);
સ્થિર શૂન્ય (*free_redir) (શૂન્ય *);
સ્થિર શૂન્ય *(*realloc_redir) (શૂન્ય *, size_t);
સ્થિર unsigned પૂર્ણાંક pool_index;
સ્થિર unsigned અક્ષર __attribute__((aligned(16))) initial_pool[256];
#endif
#જો HAVE_MEMALIGN
સ્થિર શૂન્ય *(*memalign_redir) (size_t, size_t);
#endif
#જો HAVE_PTHREAD_CREATE
સ્થિર પૂર્ણાંક (*pthread_create_redir) (pthread_t *thread,
                                    અચલ pthread_attr_t *attr,
                                    શૂન્ય *(*start_routine)(શૂન્ય *), શૂન્ય *arg);
#endif
#જો HAVE_SIGNAL
પ્રકારવ્યાખ્યા શૂન્ય (*bound_sig)(પૂર્ણાંક);
સ્થિર bound_sig (*signal_redir) (પૂર્ણાંક signum, bound_sig handler);
#endif
#જો HAVE_SIGACTION
સ્થિર પૂર્ણાંક (*sigaction_redir) (પૂર્ણાંક signum, અચલ સંરચના sigaction *act,
                               સંરચના sigaction *oldact);
#endif
#જો HAVE_FORK
સ્થિર પૂર્ણાંક (*fork_redir) (શૂન્ય);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((શૂન્ય *)(-2))

પ્રકારવ્યાખ્યા સંરચના વૃક્ષ_ગાંઠ વૃક્ષ;
સંરચના વૃક્ષ_ગાંઠ {
    વૃક્ષ * ડાબું, * જમણું;
    size_t start;
    size_t size;
    unsigned અક્ષર type;
    unsigned અક્ષર is_invalid; /* true if pointers outside region are invalid */
};

પ્રકારવ્યાખ્યા સંરચના alloca_list_struct {
    size_t fp;
    શૂન્ય *p;
    size_t size;
    સંરચના alloca_list_struct *next;
} alloca_list_type;

#જો defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#અથવાજો defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#અથવાજો defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#અથવાજો  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#અથવાજો defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#નહીંતર
#define BOUND_TID_TYPE		પૂર્ણાંક
#define BOUND_GET_TID(id)	id = 0
#endif

પ્રકારવ્યાખ્યા સંરચના jmp_list_struct {
    શૂન્ય *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    સંરચના jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
સ્થિર વૃક્ષ * splay (size_t addr, વૃક્ષ *t);
સ્થિર વૃક્ષ * splay_end (size_t addr, વૃક્ષ *t);
સ્થિર વૃક્ષ * splay_ઉમેરો(size_t addr, size_t size, વૃક્ષ * t);
સ્થિર વૃક્ષ * splay_delete(size_t addr, વૃક્ષ *t);
શૂન્ય splay_printtree(વૃક્ષ * t, પૂર્ણાંક d);

/* external interface */
શૂન્ય __bounds_checking (પૂર્ણાંક no_check);
શૂન્ય __bound_checking_lock (શૂન્ય);
શૂન્ય __bound_checking_unlock (શૂન્ય);
શૂન્ય __bound_never_fatal (પૂર્ણાંક no_check);
DLL_EXPORT શૂન્ય * __bound_ptr_add(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir1(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir2(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir4(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir8(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir12(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય * __bound_ptr_indir16(શૂન્ય *p, size_t offset);
DLL_EXPORT શૂન્ય FASTCALL __bound_local_new(શૂન્ય *p1);
DLL_EXPORT શૂન્ય FASTCALL __bound_local_delete(શૂન્ય *p1);
શૂન્ય __bound_init(size_t *, પૂર્ણાંક);
શૂન્ય __bound_main_arg(પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **envp);
શૂન્ય __bound_exit(શૂન્ય);
શૂન્ય __bound_exit_dll(size_t *);
#જો !defined(_WIN32)
શૂન્ય *__bound_mmap (શૂન્ય *start, size_t size, પૂર્ણાંક prot, પૂર્ણાંક flags, પૂર્ણાંક fd,
                    off_t offset);
પૂર્ણાંક __bound_munmap (શૂન્ય *start, size_t size);
DLL_EXPORT શૂન્ય __bound_siglongjmp(jmp_buf env, પૂર્ણાંક val);
#endif
DLL_EXPORT શૂન્ય __bound_new_region(શૂન્ય *p, size_t size);
DLL_EXPORT શૂન્ય __bound_setjmp(jmp_buf env);
DLL_EXPORT શૂન્ય __bound_longjmp(jmp_buf env, પૂર્ણાંક val);
DLL_EXPORT શૂન્ય *__bound_memcpy(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT પૂર્ણાંક __bound_memcmp(અચલ શૂન્ય *s1, અચલ શૂન્ય *s2, size_t size);
DLL_EXPORT શૂન્ય *__bound_memmove(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__bound_memset(શૂન્ય *dst, પૂર્ણાંક c, size_t size);
DLL_EXPORT પૂર્ણાંક __bound_strlen(અચલ અક્ષર *s);
DLL_EXPORT અક્ષર *__bound_strcpy(અક્ષર *dst, અચલ અક્ષર *src);
DLL_EXPORT અક્ષર *__bound_strncpy(અક્ષર *dst, અચલ અક્ષર *src, size_t n);
DLL_EXPORT પૂર્ણાંક __bound_strcmp(અચલ અક્ષર *s1, અચલ અક્ષર *s2);
DLL_EXPORT પૂર્ણાંક __bound_strncmp(અચલ અક્ષર *s1, અચલ અક્ષર *s2, size_t n);
DLL_EXPORT અક્ષર *__bound_strcat(અક્ષર *dest, અચલ અક્ષર *src);
DLL_EXPORT અક્ષર *__bound_strncat(અક્ષર *dest, અચલ અક્ષર *src, size_t n);
DLL_EXPORT અક્ષર *__bound_strchr(અચલ અક્ષર *string, પૂર્ણાંક ch);
DLL_EXPORT અક્ષર *__bound_strrchr(અચલ અક્ષર *string, પૂર્ણાંક ch);
DLL_EXPORT અક્ષર *__bound_strdup(અચલ અક્ષર *s);

#જો defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT શૂન્ય *__bound___aeabi_memcpy(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__bound___aeabi_memmove(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__bound___aeabi_memmove4(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__bound___aeabi_memmove8(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__bound___aeabi_memset(શૂન્ય *dst, પૂર્ણાંક c, size_t size);
DLL_EXPORT શૂન્ય *__aeabi_memcpy(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__aeabi_memmove(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__aeabi_memmove4(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__aeabi_memmove8(શૂન્ય *dst, અચલ શૂન્ય *src, size_t size);
DLL_EXPORT શૂન્ય *__aeabi_memset(શૂન્ય *dst, પૂર્ણાંક c, size_t size);
#endif

#જો MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#નહીંતર
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            મુક્ત(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT શૂન્ય *__bound_malloc(size_t size, અચલ શૂન્ય *caller);
DLL_EXPORT શૂન્ય *__bound_memalign(size_t align, size_t size, અચલ શૂન્ય *caller);
DLL_EXPORT શૂન્ય __bound_free(શૂન્ય *ptr, અચલ શૂન્ય *caller);
DLL_EXPORT શૂન્ય *__bound_realloc(શૂન્ય *ptr, size_t size, અચલ શૂન્ય *caller);
DLL_EXPORT શૂન્ય *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
સ્થિર unsigned પૂર્ણાંક free_reuse_index;
સ્થિર શૂન્ય *free_reuse_list[FREE_REUSE_SIZE];

સ્થિર વૃક્ષ *વૃક્ષ_2 = ખાલી;
#define વૃક્ષ_REUSE      (1)
#જો વૃક્ષ_REUSE
સ્થિર વૃક્ષ *વૃક્ષ_free_list;
#endif
સ્થિર alloca_list_type *alloca_list;
સ્થિર jmp_list_type *jmp_list;

સ્થિર unsigned અક્ષર inited;
સ્થિર unsigned અક્ષર print_warn_ptr_add;
સ્થિર unsigned અક્ષર print_calls;
સ્થિર unsigned અક્ષર print_heap;
સ્થિર unsigned અક્ષર print_statistic;
સ્થિર unsigned અક્ષર no_strdup;
સ્થિર unsigned અક્ષર use_sem;
સ્થિર _Atomic પૂર્ણાંક never_fatal;
#જો HAVE_TLS_FUNC
#જો defined(_WIN32)
સ્થિર પૂર્ણાંક no_checking = 0;
સ્થિર DWORD no_checking_ચાવી;
#define NO_CHECKING_CHECK() જો (!p) {                                         \
                                  p = (પૂર્ણાંક *) LocalAlloc(LPTR, કદ(પૂર્ણાંક));  \
                                  જો (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_કિંમત(no_checking_ચાવી, p);            \
                            }
#define NO_CHECKING_GET()   ({ પૂર્ણાંક *p = Tls_Get_કિંમત(no_checking_ચાવી);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { પૂર્ણાંક *p = Tls_Get_કિંમત(no_checking_ચાવી);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#નહીંતર
સ્થિર પૂર્ણાંક no_checking = 0;
સ્થિર pthread_key_t no_checking_ચાવી;
#define NO_CHECKING_CHECK() જો (!p) {                                         \
                                  p = (પૂર્ણાંક *) BOUND_MALLOC(કદ(પૂર્ણાંક));      \
                                  જો (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ચાવી, p);    \
                            }
#define NO_CHECKING_GET()   ({ પૂર્ણાંક *p = pthread_getspecific(no_checking_ચાવી); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { પૂર્ણાંક *p = pthread_getspecific(no_checking_ચાવી);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#અથવાજો HAVE_TLS_VAR
સ્થિર __thread પૂર્ણાંક no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#નહીંતર
સ્થિર _Atomic પૂર્ણાંક no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
સ્થિર અક્ષર exec[100];

#જો BOUND_STATISTIC
સ્થિર unsigned long long bound_ptr_add_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir1_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir2_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir4_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir8_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir12_ગણતરી;
સ્થિર unsigned long long bound_ptr_indir16_ગણતરી;
સ્થિર unsigned long long bound_local_new_ગણતરી;
સ્થિર unsigned long long bound_local_delete_ગણતરી;
સ્થિર unsigned long long bound_malloc_ગણતરી;
સ્થિર unsigned long long bound_calloc_ગણતરી;
સ્થિર unsigned long long bound_realloc_ગણતરી;
સ્થિર unsigned long long bound_free_ગણતરી;
સ્થિર unsigned long long bound_memalign_ગણતરી;
સ્થિર unsigned long long bound_mmap_ગણતરી;
સ્થિર unsigned long long bound_munmap_ગણતરી;
સ્થિર unsigned long long bound_alloca_ગણતરી;
સ્થિર unsigned long long bound_setjmp_ગણતરી;
સ્થિર unsigned long long bound_longjmp_ગણતરી;
સ્થિર unsigned long long bound_mempcy_ગણતરી;
સ્થિર unsigned long long bound_memcmp_ગણતરી;
સ્થિર unsigned long long bound_memmove_ગણતરી;
સ્થિર unsigned long long bound_memset_ગણતરી;
સ્થિર unsigned long long bound_strlen_ગણતરી;
સ્થિર unsigned long long bound_strcpy_ગણતરી;
સ્થિર unsigned long long bound_strncpy_ગણતરી;
સ્થિર unsigned long long bound_strcmp_ગણતરી;
સ્થિર unsigned long long bound_strncmp_ગણતરી;
સ્થિર unsigned long long bound_strcat_ગણતરી;
સ્થિર unsigned long long bound_strncat_ગણતરી;
સ્થિર unsigned long long bound_strchr_ગણતરી;
સ્થિર unsigned long long bound_strrchr_ગણતરી;
સ્થિર unsigned long long bound_strdup_ગણતરી;
સ્થિર unsigned long long bound_not_found;
#define INCR_ગણતરી(x)          ++x
#નહીંતર
#define INCR_ગણતરી(x)
#endif
#જો BOUND_STATISTIC_SPLAY
સ્થિર unsigned long long bound_splay;
સ્થિર unsigned long long bound_splay_end;
સ્થિર unsigned long long bound_splay_ઉમેરો;
સ્થિર unsigned long long bound_splay_delete;
#define INCR_ગણતરી_SPLAY(x)    ++x
#નહીંતર
#define INCR_ગણતરી_SPLAY(x)
#endif

પૂર્ણાંક tcc_backtrace(અચલ અક્ષર *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    કરો {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } જ્યારે (0)

#define bound_error(...)            \
    કરો {                            \
        bound_warning(__VA_ARGS__); \
        જો (never_fatal == 0)       \
            exit(255);              \
    } જ્યારે (0)

#define bounds_loc(fp, ...) \
    કરો {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } જ્યારે (0)

સ્થિર શૂન્ય bound_alloc_error(અચલ અક્ષર *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

સ્થિર શૂન્ય bound_not_found_warning(અચલ અક્ષર *file, અચલ અક્ષર *function,
                                    શૂન્ય *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
શૂન્ય __bounds_checking (પૂર્ણાંક no_check)
{
#જો HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#નહીંતર
    atomic_fetch_add (&no_checking, no_check);
#endif
}

શૂન્ય __bound_checking_lock(શૂન્ય)
{
    WAIT_SEM ();
}

શૂન્ય __bound_checking_unlock(શૂન્ય)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
શૂન્ય __bound_never_fatal (પૂર્ણાંક neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
શૂન્ય * __bound_ptr_add(શૂન્ય *p, size_t offset)
{
    size_t addr = (size_t)p;

    જો (NO_CHECKING_GET())
        પાછા p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_ગણતરી(bound_ptr_add_ગણતરી);
    જો (વૃક્ષ_2) {
        addr -= વૃક્ષ_2->start;
        જો (addr >= વૃક્ષ_2->size) {
            addr = (size_t)p;
            વૃક્ષ_2 = splay (addr, વૃક્ષ_2);
            addr -= વૃક્ષ_2->start;
        }
        જો (addr >= વૃક્ષ_2->size) {
            addr = (size_t)p;
            વૃક્ષ_2 = splay_end (addr, વૃક્ષ_2);
            addr -= વૃક્ષ_2->start;
        }
        જો (addr <= વૃક્ષ_2->size) {
            જો (વૃક્ષ_2->is_invalid || addr + offset > વૃક્ષ_2->size) {
                POST_SEM ();
                જો (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)વૃક્ષ_2->start,
                                  (long)(વૃક્ષ_2->start + વૃક્ષ_2->size - 1));
                જો (never_fatal <= 0)
                    પાછા INVALID_POINTER; /* return an invalid pointer */
                પાછા p + offset;
            }
        }
        નહીંતર જો (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ગણતરી(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            પાછા p + offset;
        }
    }
    POST_SEM ();
    પાછા p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
શૂન્ય * __bound_ptr_indir ## dsize (શૂન્ય *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    જો (NO_CHECKING_GET())                                                     \
        પાછા p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_ગણતરી(bound_ptr_indir ## dsize ## ગણતરી);                            \
    જો (વૃક્ષ_2) {                                                                \
        addr -= વૃક્ષ_2->start;                                                   \
        જો (addr >= વૃક્ષ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            વૃક્ષ_2 = splay (addr, વૃક્ષ_2);                                         \
            addr -= વૃક્ષ_2->start;                                               \
        }                                                                      \
        જો (addr >= વૃક્ષ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            વૃક્ષ_2 = splay_end (addr, વૃક્ષ_2);                                     \
            addr -= વૃક્ષ_2->start;                                               \
        }                                                                      \
        જો (addr <= વૃક્ષ_2->size) {                                              \
            જો (વૃક્ષ_2->is_invalid || addr + offset + dsize > વૃક્ષ_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)વૃક્ષ_2->start,            \
                              (long)(વૃક્ષ_2->start + વૃક્ષ_2->size - 1));           \
                જો (never_fatal <= 0)                                          \
                    પાછા INVALID_POINTER; /* return an invalid pointer */    \
                પાછા p + offset;                                             \
            }                                                                  \
        }                                                                      \
        નહીંતર {                                                                 \
            INCR_ગણતરી(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            પાછા p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    પાછા p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#જો (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic ધકેલો
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
શૂન્ય FASTCALL __bound_local_new(શૂન્ય *p1) 
{
    size_t addr, fp, *p = p1;

    જો (NO_CHECKING_GET())
         પાછા;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (શૂન્ય *)fp);
    WAIT_SEM ();
    જ્યારે ((addr = p[0])) {
        INCR_ગણતરી(bound_local_new_ગણતરી);
        વૃક્ષ_2 = splay_ઉમેરો(addr + fp, p[1], વૃક્ષ_2);
        p += 2;
    }
    POST_SEM ();
#જો BOUND_DEBUG
    જો (print_calls) {
        p = p1;
        જ્યારે ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (શૂન્ય *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
શૂન્ય FASTCALL __bound_local_delete(શૂન્ય *p1) 
{
    size_t addr, fp, *p = p1;

    જો (NO_CHECKING_GET())
         પાછા;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (શૂન્ય *)fp);
    WAIT_SEM ();
    જ્યારે ((addr = p[0])) {
        INCR_ગણતરી(bound_local_delete_ગણતરી);
        વૃક્ષ_2 = splay_delete(addr + fp, વૃક્ષ_2);
        p += 2;
    }
    જો (alloca_list) {
        alloca_list_type *last = ખાલી;
        alloca_list_type *cur = alloca_list;

        કરો {
            જો (cur->fp == fp) {
                જો (last)
                    last->next = cur->next;
                નહીંતર
                    alloca_list = cur->next;
                વૃક્ષ_2 = splay_delete ((size_t) cur->p, વૃક્ષ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             નહીંતર {
                 last = cur;
                 cur = cur->next;
             }
        } જ્યારે (cur);
    }
    જો (jmp_list) {
        jmp_list_type *last = ખાલી;
        jmp_list_type *cur = jmp_list;

        કરો {
            જો (cur->fp == fp) {
                જો (last)
                    last->next = cur->next;
                નહીંતર
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            નહીંતર {
                last = cur;
                cur = cur->next;
            }
        } જ્યારે (cur);
    }

    POST_SEM ();
#જો BOUND_DEBUG
    જો (print_calls) {
        p = p1;
        જ્યારે ((addr = p[0])) {
            જો (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (શૂન્ય *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
શૂન્ય __bound_new_region(શૂન્ય *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    જો (NO_CHECKING_GET())
        પાછા;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (કદ (alloca_list_type));
    WAIT_SEM ();
    INCR_ગણતરી(bound_alloca_ગણતરી);
    last = ખાલી;
    cur = alloca_list;
    જ્યારે (cur) {
#જો defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        પૂર્ણાંક align = 4;
#અથવાજો defined(__arm__)
        પૂર્ણાંક align = 8;
#નહીંતર
        પૂર્ણાંક align = 16;
#endif
        શૂન્ય *cure = (શૂન્ય *)((અક્ષર *)cur->p + ((cur->size + align) & -align));
        શૂન્ય *pe = (શૂન્ય *)((અક્ષર *)p + ((size + align) & -align));
        જો (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            જો (last)
                last->next = cur->next;
            નહીંતર
                alloca_list = cur->next;
            વૃક્ષ_2 = splay_delete((size_t)cur->p, વૃક્ષ_2);
            તોડો;
        }
        last = cur;
        cur = cur->next;
    }
    વૃક્ષ_2 = splay_ઉમેરો((size_t)p, size, વૃક્ષ_2);
    જો (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    જો (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

શૂન્ય __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    શૂન્ય *e = (શૂન્ય *) env;

    જો (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ગણતરી(bound_setjmp_ગણતરી);
        jl = jmp_list;
        જ્યારે (jl) {
            જો (jl->penv == e)
                તોડો;
            jl = jl->next;
        }
        જો (jl == ખાલી) {
            jl = BOUND_MALLOC (કદ (jmp_list_type));
            જો (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        જો (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

સ્થિર શૂન્ય __bound_long_jump(jmp_buf env, પૂર્ણાંક val, પૂર્ણાંક sig, અચલ અક્ષર *func)
{
    jmp_list_type *jl;
    શૂન્ય *e;
    BOUND_TID_TYPE tid;

    જો (NO_CHECKING_GET() == 0) {
        e = (શૂન્ય *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ગણતરી(bound_longjmp_ગણતરી);
        jl = jmp_list;
        જ્યારે (jl) {
            જો (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = ખાલી;

                જ્યારે (cur->penv != e || cur->tid != tid) {
                    જો (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        જો (last)
                            last->next = cur->next;
                        નહીંતર
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    નહીંતર {
                        last = cur;
                        cur = cur->next;
                    }
                }
                માટે (;;) {
                    વૃક્ષ *t = વૃક્ષ_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    જ્યારે (t && (t->start < start_fp || t->start > end_fp))
                        જો (t->start < start_fp)
                            t = t->જમણું;
                        નહીંતર
                            t = t->ડાબું;
                    જો (t == ખાલી)
                        તોડો;
                    last = ખાલી;
                    cur = alloca_list;
                    જ્યારે (cur) {
                         જો ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             જો (last)
                                 last->next = cur->next;
                             નહીંતર
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             તોડો;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (શૂન્ય *) t->start);
                    વૃક્ષ_2 = splay_delete(t->start, વૃક્ષ_2);
                }
                તોડો;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#જો !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

શૂન્ય __bound_longjmp(jmp_buf env, પૂર્ણાંક val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#જો !defined(_WIN32)
શૂન્ય __bound_siglongjmp(jmp_buf env, પૂર્ણાંક val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#જો (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic કાઢો
#endif

શૂન્ય __bound_init(size_t *p, પૂર્ણાંક mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    જો (inited) {
        WAIT_SEM();
        જાઓ add_bounds;
    }
    inited = 1;

#જો HAVE_TLS_FUNC
#જો defined(_WIN32)
    no_checking_ચાવી = TlsAlloc();
    Tls_Set_કિંમત(no_checking_ચાવી, &no_checking);
#નહીંતર
    pthread_key_create(&no_checking_ચાવી, ખાલી);
    pthread_setspecific(no_checking_ચાવી, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ખાલી;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ખાલી;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != ખાલી;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ખાલી;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ખાલી;

    INIT_SEM ();

#જો MALLOC_REDIR
    {
        શૂન્ય *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(શૂન્ય **) (&malloc_redir) = dlsym (addr, "malloc");
        જો (malloc_redir == ખાલી) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(શૂન્ય **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(શૂન્ય **) (&calloc_redir) = dlsym (addr, "calloc");
        *(શૂન્ય **) (&free_redir) = dlsym (addr, "free");
        *(શૂન્ય **) (&realloc_redir) = dlsym (addr, "realloc");
        *(શૂન્ય **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        જો (malloc_redir == ખાલી || free_redir == ખાલી)
            bound_alloc_error ("Cannot redirect malloc/free");
#જો HAVE_PTHREAD_CREATE
        *(શૂન્ય **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        જો (pthread_create_redir == ખાલી)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#જો HAVE_SIGNAL
        *(શૂન્ય **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        જો (signal_redir == ખાલી)
            bound_alloc_error ("Cannot redirect signal");
#endif
#જો HAVE_SIGACTION
        *(શૂન્ય **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        જો (sigaction_redir == ખાલી)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#જો HAVE_FORK
        *(શૂન્ય **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        જો (fork_redir == ખાલી)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned અક્ષર found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        અક્ષર લીટી[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        જો (fp) {
            memset (exec, 0, કદ(exec));
            fread (exec, 1, કદ(exec) - 2, fp);
            જો (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        જો (fp) {
            જ્યારે (fgets (લીટી, કદ(લીટી), fp)) {
                જો (sscanf (લીટી, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    તોડો;
                }
                જો (strstr (લીટી,"[heap]"))
                    તોડો;
            }
            fclose (fp);
        }
        જો (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#જો HAVE_CTYPE
#ifdef __APPLE__
    વૃક્ષ_2 = splay_ઉમેરો((size_t) &_DefaultRuneLocale,
                        કદ (_DefaultRuneLocale), વૃક્ષ_2);
#નહીંતર
    /* XXX: Does not work if locale is changed */
    વૃક્ષ_2 = splay_ઉમેરો((size_t) __ctype_b_loc(),
                        કદ (unsigned short *), વૃક્ષ_2);
    વૃક્ષ_2 = splay_ઉમેરો((size_t) (*__ctype_b_loc() - 128),
                        384 * કદ (unsigned short), વૃક્ષ_2);
    વૃક્ષ_2 = splay_ઉમેરો((size_t) __ctype_tolower_loc(),
                        કદ (__int32_t *), વૃક્ષ_2);
    વૃક્ષ_2 = splay_ઉમેરો((size_t) (*__ctype_tolower_loc() - 128),
                        384 * કદ (__int32_t), વૃક્ષ_2);
    વૃક્ષ_2 = splay_ઉમેરો((size_t) __ctype_toupper_loc(),
                        કદ (__int32_t *), વૃક્ષ_2);
    વૃક્ષ_2 = splay_ઉમેરો((size_t) (*__ctype_toupper_loc() - 128),
                        384 * કદ (__int32_t), વૃક્ષ_2);
#endif
#endif
#જો HAVE_ERRNO
    વૃક્ષ_2 = splay_ઉમેરો((size_t) (&errno), કદ (પૂર્ણાંક), વૃક્ષ_2);
#endif

add_bounds:
    જો (!p)
        જાઓ no_bounds;

    /* add all static bound check values */
    જ્યારે (p[0] != 0) {
        વૃક્ષ_2 = splay_ઉમેરો(p[0], p[1], વૃક્ષ_2);
#જો BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (શૂન્ય *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

શૂન્ય
#જો (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **envp)
{
    __bound_init (0, -1);
    જો (argc && argv) {
        પૂર્ણાંક i;

        WAIT_SEM ();
        માટે (i = 0; i < argc; i++)
            વૃક્ષ_2 = splay_ઉમેરો((size_t) argv[i], strlen (argv[i]) + 1, વૃક્ષ_2);
        વૃક્ષ_2 = splay_ઉમેરો((size_t) argv, (argc + 1) * કદ(અક્ષર *), વૃક્ષ_2);
        POST_SEM ();
#જો BOUND_DEBUG
        જો (print_calls) {
            માટે (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (પૂર્ણાંક)((argc + 1) * કદ(અક્ષર *)));
        }
#endif
    }

    જો (envp && *envp) {
        અક્ષર **p = envp;

        WAIT_SEM ();
        જ્યારે (*p) {
            વૃક્ષ_2 = splay_ઉમેરો((size_t) *p, strlen (*p) + 1, વૃક્ષ_2);
            ++p;
        }
        વૃક્ષ_2 = splay_ઉમેરો((size_t) envp, (++p - envp) * કદ(અક્ષર *), વૃક્ષ_2);
        POST_SEM ();
#જો BOUND_DEBUG
        જો (print_calls) {
            p = envp;
            જ્યારે (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (પૂર્ણાંક)((++p - envp) * કદ(અક્ષર *)));
        }
#endif
    }
}

શૂન્ય __attribute__((destructor)) __bound_exit(શૂન્ય)
{
    પૂર્ણાંક i;
    સ્થિર અચલ અક્ષર * અચલ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    જો (inited) {
#જો !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        જો (print_heap) {
            બાહ્ય શૂન્ય __libc_freeres (શૂન્ય);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        જ્યારે (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            વૃક્ષ_2 = splay_delete ((size_t) alloca_list->p, વૃક્ષ_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        જ્યારે (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        માટે (i = 0; i < FREE_REUSE_SIZE; i++) {
            જો (free_reuse_list[i]) {
                વૃક્ષ_2 = splay_delete ((size_t) free_reuse_list[i], વૃક્ષ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        જ્યારે (વૃક્ષ_2) {
            જો (print_heap && વૃક્ષ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[વૃક્ષ_2->type],
                         (unsigned long) વૃક્ષ_2->size);
            વૃક્ષ_2 = splay_delete (વૃક્ષ_2->start, વૃક્ષ_2);
        }
#જો વૃક્ષ_REUSE
        જ્યારે (વૃક્ષ_free_list) {
            વૃક્ષ *next = વૃક્ષ_free_list->ડાબું;
            BOUND_FREE (વૃક્ષ_free_list);
            વૃક્ષ_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#જો HAVE_TLS_FUNC
#જો defined(_WIN32)
        TlsFree(no_checking_ચાવી);
#નહીંતર
        pthread_key_delete(no_checking_ચાવી);
#endif
#endif
        inited = 0;
        જો (print_statistic) {
#જો BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_ગણતરી);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_ગણતરી);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_ગણતરી);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_ગણતરી);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_ગણતરી);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_ગણતરી);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_ગણતરી);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_ગણતરી);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_ગણતરી);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_ગણતરી);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_ગણતરી);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_ગણતરી);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_ગણતરી);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_ગણતરી);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_ગણતરી);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_ગણતરી);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_ગણતરી);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_ગણતરી);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_ગણતરી);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_ગણતરી);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_ગણતરી);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_ગણતરી);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_ગણતરી);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_ગણતરી);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_ગણતરી);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_ગણતરી);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_ગણતરી);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_ગણતરી);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_ગણતરી);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_ગણતરી);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_ગણતરી);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_ગણતરી);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_ગણતરી);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#જો BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ઉમેરો);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

શૂન્ય __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    જો (p) {
        WAIT_SEM ();
	જ્યારે (p[0] != 0) {
	    વૃક્ષ_2 = splay_delete(p[0], વૃક્ષ_2);
#જો BOUND_DEBUG
            જો (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (શૂન્ય *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#જો HAVE_PTHREAD_CREATE
પ્રકારવ્યાખ્યા સંરચના {
    શૂન્ય *(*start_routine) (શૂન્ય *);
    શૂન્ય *arg;
    sigset_t old_mask;
} bound_thread_create_type;

સ્થિર શૂન્ય *bound_thread_create(શૂન્ય *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    શૂન્ય *retval;
#જો HAVE_TLS_FUNC
    પૂર્ણાંક *p = (પૂર્ણાંક *) BOUND_MALLOC(કદ(પૂર્ણાંક));
  
    જો (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ચાવી, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, ખાલી);
    retval = data->start_routine(data->arg);
#જો HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ચાવી, ખાલી);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    પાછા retval;
}

પૂર્ણાંક pthread_create(pthread_t *thread, અચલ pthread_attr_t *attr,
                   શૂન્ય *(*start_routine) (શૂન્ય *), શૂન્ય *arg)
{
    પૂર્ણાંક retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(કદ(bound_thread_create_type));
    જો (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, ખાલી);
    પાછા retval;
}
#endif

#જો HAVE_SIGNAL || HAVE_SIGACTION
પ્રકારવ્યાખ્યા સંઘ {
#જો HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#જો HAVE_SIGACTION
    શૂન્ય (*sig_handler)(પૂર્ણાંક);
    શૂન્ય (*sig_sigaction)(પૂર્ણાંક, siginfo_t *, શૂન્ય *);
#endif
} bound_sig_type;

સ્થિર unsigned અક્ષર bound_sig_used[NSIG];
સ્થિર bound_sig_type bound_sig_data[NSIG];
#endif

#જો HAVE_SIGNAL
સ્થિર શૂન્ય signal_handler(પૂર્ણાંક sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig સંકેત(પૂર્ણાંક signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    જો (retval != SIG_ERR) {
        જો (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        જો (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    પાછા retval;
}
#endif

#જો HAVE_SIGACTION
સ્થિર શૂન્ય sig_handler(પૂર્ણાંક sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

સ્થિર શૂન્ય sig_sigaction(પૂર્ણાંક sig, siginfo_t *info, શૂન્ય *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

પૂર્ણાંક sigaction(પૂર્ણાંક signum, અચલ સંરચના sigaction *act, સંરચના sigaction *oldact)
{
    પૂર્ણાંક retval;
    સંરચના sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    જો (sigaction_redir == ખાલી)
        __bound_init(0,-1);

    જો (act) {
        nact = *act;
        જો (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        નહીંતર
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    નહીંતર
        retval = sigaction_redir(signum, act, &oact);
    જો (retval >= 0) {
        જો (bound_sig_used[signum]) {
            જો (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            નહીંતર
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        જો (oldact) {
            *oldact = oact;
        }
        જો (act) {
            bound_sig_used[signum] = 1;
            જો (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            નહીંતર
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    પાછા retval;
}
#endif

#જો HAVE_FORK
pid_t fork(શૂન્ય)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    જો (retval == 0)
        INIT_SEM();
    નહીંતર
        POST_SEM();
    પાછા retval;
}
#endif

#જો MALLOC_REDIR
શૂન્ય *malloc(size_t size)
#નહીંતર
શૂન્ય *__bound_malloc(size_t size, અચલ શૂન્ય *caller)
#endif
{
    શૂન્ય *ptr;
    
#જો MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    જો (malloc_redir == ખાલી) {
        __bound_init (0, -1);
        જો (malloc_redir == ખાલી) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            જો (pool_index >= કદ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            પાછા ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    જો (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_malloc_ગણતરી);

        જો (ptr) {
            વૃક્ષ_2 = splay_ઉમેરો ((size_t) ptr, size ? size : size + 1, વૃક્ષ_2);
            જો (વૃક્ષ_2 && વૃક્ષ_2->start == (size_t) ptr)
                વૃક્ષ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    પાછા ptr;
}

#જો MALLOC_REDIR
શૂન્ય *memalign(size_t align, size_t size)
#નહીંતર
શૂન્ય *__bound_memalign(size_t align, size_t size, અચલ શૂન્ય *caller)
#endif
{
    શૂન્ય *ptr;

#જો HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#નહીંતર
    જો (align > 4) {
        /* XXX: handle it ? */
        ptr = ખાલી;
    } નહીંતર {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    જો (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_memalign_ગણતરી);

        જો (ptr) {
            વૃક્ષ_2 = splay_ઉમેરો((size_t) ptr, size ? size : size + 1, વૃક્ષ_2);
            જો (વૃક્ષ_2 && વૃક્ષ_2->start == (size_t) ptr)
                વૃક્ષ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    પાછા ptr;
}

#જો MALLOC_REDIR
શૂન્ય મુક્ત(શૂન્ય *ptr)
#નહીંતર
શૂન્ય __bound_free(શૂન્ય *ptr, અચલ શૂન્ય *caller)
#endif
{
    size_t addr = (size_t) ptr;
    શૂન્ય *p;

    જો (ptr == ખાલી || વૃક્ષ_2 == ખાલી
#જો MALLOC_REDIR
        || ((unsigned અક્ષર *) ptr >= &initial_pool[0] &&
            (unsigned અક્ષર *) ptr < &initial_pool[કદ(initial_pool)])
#endif
        )
        પાછા;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    જો (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_free_ગણતરી);
        વૃક્ષ_2 = splay (addr, વૃક્ષ_2);
        જો (વૃક્ષ_2->start == addr) {
            જો (વૃક્ષ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                પાછા;
            }
            વૃક્ષ_2->is_invalid = 1;
            memset (ptr, 0x5a, વૃક્ષ_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            જો (p)
                વૃક્ષ_2 = splay_delete((size_t)p, વૃક્ષ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#જો MALLOC_REDIR
શૂન્ય *realloc(શૂન્ય *ptr, size_t size)
#નહીંતર
શૂન્ય *__bound_realloc(શૂન્ય *ptr, size_t size, અચલ શૂન્ય *caller)
#endif
{
    શૂન્ય *new_ptr;

    જો (size == 0) {
#જો MALLOC_REDIR
        મુક્ત(ptr);
#નહીંતર
        __bound_free(ptr, caller);
#endif
        પાછા ખાલી;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    જો (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_realloc_ગણતરી);

        જો (ptr)
            વૃક્ષ_2 = splay_delete ((size_t) ptr, વૃક્ષ_2);
        જો (new_ptr) {
            વૃક્ષ_2 = splay_ઉમેરો ((size_t) new_ptr, size ? size : size + 1, વૃક્ષ_2);
            જો (વૃક્ષ_2 && વૃક્ષ_2->start == (size_t) new_ptr)
                વૃક્ષ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    પાછા new_ptr;
}

#જો MALLOC_REDIR
શૂન્ય *calloc(size_t nmemb, size_t size)
#નહીંતર
શૂન્ય *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    શૂન્ય *ptr;

    size *= nmemb;
#જો MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    જો (malloc_redir == ખાલી) {
        __bound_init (0, -1);
        જો (malloc_redir == ખાલી) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            જો (pool_index >= કદ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            પાછા ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    જો (ptr) {
        memset (ptr, 0, size);
        જો (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ગણતરી(bound_calloc_ગણતરી);
            વૃક્ષ_2 = splay_ઉમેરો ((size_t) ptr, size ? size : size + 1, વૃક્ષ_2);
            જો (વૃક્ષ_2 && વૃક્ષ_2->start == (size_t) ptr)
                વૃક્ષ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    પાછા ptr;
}

#જો !defined(_WIN32)
શૂન્ય *__bound_mmap (શૂન્ય *start, size_t size, પૂર્ણાંક prot,
                    પૂર્ણાંક flags, પૂર્ણાંક fd, off_t offset)
{
    શૂન્ય *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    જો (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_mmap_ગણતરી);
        વૃક્ષ_2 = splay_ઉમેરો((size_t)result, size, વૃક્ષ_2);
        POST_SEM ();
    }
    પાછા result;
}

પૂર્ણાંક __bound_munmap (શૂન્ય *start, size_t size)
{
    પૂર્ણાંક result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    જો (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ગણતરી(bound_munmap_ગણતરી);
        વૃક્ષ_2 = splay_delete ((size_t) start, વૃક્ષ_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    પાછા result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
સ્થિર શૂન્ય __bound_check(અચલ શૂન્ય *p, size_t size, અચલ અક્ષર *function)
{
    જો (size != 0 && __bound_ptr_add((શૂન્ય *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

સ્થિર પૂર્ણાંક check_overlap (અચલ શૂન્ય *p1, size_t n1,
                          અચલ શૂન્ય *p2, size_t n2,
                          અચલ અક્ષર *function)
{
    અચલ શૂન્ય *p1e = (અચલ શૂન્ય *) ((અચલ અક્ષર *) p1 + n1);
    અચલ શૂન્ય *p2e = (અચલ શૂન્ય *) ((અચલ અક્ષર *) p2 + n2);

    જો (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        પાછા never_fatal < 0;
    }
    પાછા 0;
}

શૂન્ય *__bound_memcpy(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_mempcy_ગણતરી);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    જો (check_overlap(dest, n, src, n, "memcpy"))
        પાછા dest;
    પાછા memcpy(dest, src, n);
}

પૂર્ણાંક __bound_memcmp(અચલ શૂન્ય *s1, અચલ શૂન્ય *s2, size_t n)
{
    અચલ unsigned અક્ષર *u1 = (અચલ unsigned અક્ષર *) s1;
    અચલ unsigned અક્ષર *u2 = (અચલ unsigned અક્ષર *) s2;
    પૂર્ણાંક retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ગણતરી(bound_memcmp_ગણતરી);
    માટે (;;) {
        જો ((ssize_t) --n == -1)
            તોડો;
        નહીંતર જો (*u1 != *u2) {
            retval = *u1++ - *u2++;
            તોડો;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (અચલ શૂન્ય *)u1 - s1, "memcmp s1");
    __bound_check(s2, (અચલ શૂન્ય *)u2 - s2, "memcmp s2");
    પાછા retval;
}

શૂન્ય *__bound_memmove(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_memmove_ગણતરી);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    પાછા memmove(dest, src, n);
}

શૂન્ય *__bound_memset(શૂન્ય *s, પૂર્ણાંક c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ગણતરી(bound_memset_ગણતરી);
    __bound_check(s, n, "memset");
    પાછા memset(s, c, n);
}

#જો defined(__arm__) && defined(__ARM_EABI__)
શૂન્ય *__bound___aeabi_memcpy(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_mempcy_ગણતરી);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    જો (check_overlap(dest, n, src, n, "memcpy"))
        પાછા dest;
    પાછા __aeabi_memcpy(dest, src, n);
}

શૂન્ય *__bound___aeabi_memmove(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_memmove_ગણતરી);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    પાછા __aeabi_memmove(dest, src, n);
}

શૂન્ય *__bound___aeabi_memmove4(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_memmove_ગણતરી);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    પાછા __aeabi_memmove4(dest, src, n);
}

શૂન્ય *__bound___aeabi_memmove8(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_memmove_ગણતરી);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    પાછા __aeabi_memmove8(dest, src, n);
}

શૂન્ય *__bound___aeabi_memset(શૂન્ય *s, પૂર્ણાંક c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ગણતરી(bound_memset_ગણતરી);
    __bound_check(s, n, "memset");
    પાછા __aeabi_memset(s, c, n);
}
#endif

પૂર્ણાંક __bound_strlen(અચલ અક્ષર *s)
{
    અચલ અક્ષર *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ગણતરી(bound_strlen_ગણતરી);
    જ્યારે (*p++);
    __bound_check(s, p - s, "strlen");
    પાછા (p - s) - 1;
}

અક્ષર *__bound_strcpy(અક્ષર *dest, અચલ અક્ષર *src)
{
    size_t len;
    અચલ અક્ષર *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ગણતરી(bound_strcpy_ગણતરી);
    જ્યારે (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    જો (check_overlap(dest, len, src, len, "strcpy"))
        પાછા dest;
    પાછા strcpy (dest, src);
}

અક્ષર *__bound_strncpy(અક્ષર *dest, અચલ અક્ષર *src, size_t n)
{
    size_t len = n;
    અચલ અક્ષર *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_strncpy_ગણતરી);
    જ્યારે (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    જો (check_overlap(dest, len, src, len, "strncpy"))
        પાછા dest;
    પાછા strncpy(dest, src, n);
}

પૂર્ણાંક __bound_strcmp(અચલ અક્ષર *s1, અચલ અક્ષર *s2)
{
    અચલ unsigned અક્ષર *u1 = (અચલ unsigned અક્ષર *) s1;
    અચલ unsigned અક્ષર *u2 = (અચલ unsigned અક્ષર *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ગણતરી(bound_strcmp_ગણતરી);
    જ્યારે (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((અચલ અક્ષર *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((અચલ અક્ષર *)u2 - s2) + 1, "strcmp s2");
    પાછા *u1 - *u2;
}

પૂર્ણાંક __bound_strncmp(અચલ અક્ષર *s1, અચલ અક્ષર *s2, size_t n)
{
    અચલ unsigned અક્ષર *u1 = (અચલ unsigned અક્ષર *) s1;
    અચલ unsigned અક્ષર *u2 = (અચલ unsigned અક્ષર *) s2;
    પૂર્ણાંક retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ગણતરી(bound_strncmp_ગણતરી);
    કરો {
        જો ((ssize_t) --n == -1)
            તોડો;
        નહીંતર જો (*u1 != *u2) {
            retval = *u1++ - *u2++;
            તોડો;
        }
        ++u2;
    } જ્યારે (*u1++);
    __bound_check(s1, (અચલ અક્ષર *)u1 - s1, "strncmp s1");
    __bound_check(s2, (અચલ અક્ષર *)u2 - s2, "strncmp s2");
    પાછા retval;
}

અક્ષર *__bound_strcat(અક્ષર *dest, અચલ અક્ષર *src)
{
    અક્ષર *r = dest;
    અચલ અક્ષર *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ગણતરી(bound_strcat_ગણતરી);
    જ્યારે (*dest++);
    જ્યારે (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    જો (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        પાછા dest;
    પાછા strcat(r, s);
}

અક્ષર *__bound_strncat(અક્ષર *dest, અચલ અક્ષર *src, size_t n)
{
    અક્ષર *r = dest;
    અચલ અક્ષર *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ગણતરી(bound_strncat_ગણતરી);
    જ્યારે (*dest++);
    જ્યારે (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    જો (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        પાછા dest;
    પાછા strncat(r, s, n);
}

અક્ષર *__bound_strchr(અચલ અક્ષર *s, પૂર્ણાંક c)
{
    અચલ unsigned અક્ષર *str = (અચલ unsigned અક્ષર *) s;
    unsigned અક્ષર ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ગણતરી(bound_strchr_ગણતરી);
    જ્યારે (*str) {
        જો (*str == ch)
            તોડો;
        ++str;
    }
    __bound_check(s, ((અચલ અક્ષર *)str - s) + 1, "strchr");
    પાછા *str == ch ? (અક્ષર *) str : ખાલી;
}

અક્ષર *__bound_strrchr(અચલ અક્ષર *s, પૂર્ણાંક c)
{
    અચલ unsigned અક્ષર *str = (અચલ unsigned અક્ષર *) s;
    unsigned અક્ષર ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ગણતરી(bound_strrchr_ગણતરી);
    જ્યારે (*str++);
    __bound_check(s, (અચલ અક્ષર *)str - s, "strrchr");
    જ્યારે (str != (અચલ unsigned અક્ષર *)s) {
        જો (*--str == ch)
            તોડો;
    }
    __bound_check(s, (અચલ અક્ષર *)str - s, "strrchr");
    પાછા *str == ch ? (અક્ષર *) str : ખાલી;
}

અક્ષર *__bound_strdup(અચલ અક્ષર *s)
{
    અચલ અક્ષર *p = s;
    અક્ષર *new;

    INCR_ગણતરી(bound_strdup_ગણતરી);
    જ્યારે (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    જો (new) {
        જો (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            વૃક્ષ_2 = splay_ઉમેરો((size_t)new, p - s, વૃક્ષ_2);
            જો (વૃક્ષ_2 && વૃક્ષ_2->start == (size_t) new)
                વૃક્ષ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    પાછા new;
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

સ્થિર વૃક્ષ * splay (size_t addr, વૃક્ષ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    વૃક્ષ N, *l, *r, *y;
    પૂર્ણાંક comp;
    
    INCR_ગણતરી_SPLAY(bound_splay);
    જો (t == ખાલી) પાછા t;
    N.ડાબું = N.જમણું = ખાલી;
    l = r = &N;
 
    માટે (;;) {
        comp = compare(addr, t->start, t->size);
        જો (comp < 0) {
            y = t->ડાબું;
            જો (y == ખાલી) તોડો;
            જો (compare(addr, y->start, y->size) < 0) {
                t->ડાબું = y->જમણું;                    /* rotate right */
                y->જમણું = t;
                t = y;
                જો (t->ડાબું == ખાલી) તોડો;
            }
            r->ડાબું = t;                               /* link right */
            r = t;
            t = t->ડાબું;
        } નહીંતર જો (comp > 0) {
            y = t->જમણું;
            જો (y == ખાલી) તોડો;
            જો (compare(addr, y->start, y->size) > 0) {
                t->જમણું = y->ડાબું;                    /* rotate left */
                y->ડાબું = t;
                t = y;
                જો (t->જમણું == ખાલી) તોડો;
            }
            l->જમણું = t;                              /* link left */
            l = t;
            t = t->જમણું;
        } નહીંતર {
            તોડો;
        }
    }
    l->જમણું = t->ડાબું;                                /* assemble */
    r->ડાબું = t->જમણું;
    t->ડાબું = N.જમણું;
    t->જમણું = N.ડાબું;

    પાછા t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

સ્થિર વૃક્ષ * splay_end (size_t addr, વૃક્ષ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    વૃક્ષ N, *l, *r, *y;
    પૂર્ણાંક comp;
    
    INCR_ગણતરી_SPLAY(bound_splay_end);
    જો (t == ખાલી) પાછા t;
    N.ડાબું = N.જમણું = ખાલી;
    l = r = &N;
 
    માટે (;;) {
        comp = compare_end(addr, t->start + t->size);
        જો (comp < 0) {
            y = t->ડાબું;
            જો (y == ખાલી) તોડો;
            જો (compare_end(addr, y->start + y->size) < 0) {
                t->ડાબું = y->જમણું;                    /* rotate right */
                y->જમણું = t;
                t = y;
                જો (t->ડાબું == ખાલી) તોડો;
            }
            r->ડાબું = t;                               /* link right */
            r = t;
            t = t->ડાબું;
        } નહીંતર જો (comp > 0) {
            y = t->જમણું;
            જો (y == ખાલી) તોડો;
            જો (compare_end(addr, y->start + y->size) > 0) {
                t->જમણું = y->ડાબું;                    /* rotate left */
                y->ડાબું = t;
                t = y;
                જો (t->જમણું == ખાલી) તોડો;
            }
            l->જમણું = t;                              /* link left */
            l = t;
            t = t->જમણું;
        } નહીંતર {
            તોડો;
        }
    }
    l->જમણું = t->ડાબું;                                /* assemble */
    r->ડાબું = t->જમણું;
    t->ડાબું = N.જમણું;
    t->જમણું = N.ડાબું;

    પાછા t;
}

સ્થિર વૃક્ષ * splay_ઉમેરો(size_t addr, size_t size, વૃક્ષ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    વૃક્ષ * new;

    INCR_ગણતરી_SPLAY(bound_splay_ઉમેરો);
    જો (t != ખાલી) {
        t = splay(addr,t);
        જો (compare(addr, t->start, t->size)==0) {
            પાછા t;  /* it's already there */
        }
    }
#જો વૃક્ષ_REUSE
    જો (વૃક્ષ_free_list) {
          new = વૃક્ષ_free_list;
          વૃક્ષ_free_list = new->ડાબું;
    }
    નહીંતર
#endif
    {
        new = (વૃક્ષ *) BOUND_MALLOC (કદ (વૃક્ષ));
    }
    જો (new == ખાલી) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    નહીંતર {
        જો (t == ખાલી) {
            new->ડાબું = new->જમણું = ખાલી;
        } નહીંતર જો (compare(addr, t->start, t->size) < 0) {
            new->ડાબું = t->ડાબું;
            new->જમણું = t;
            t->ડાબું = ખાલી;
        } નહીંતર {
            new->જમણું = t->જમણું;
            new->ડાબું = t;
            t->જમણું = ખાલી;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    પાછા new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

સ્થિર વૃક્ષ * splay_delete(size_t addr, વૃક્ષ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    વૃક્ષ * x;

    INCR_ગણતરી_SPLAY(bound_splay_delete);
    જો (t==ખાલી) પાછા ખાલી;
    t = splay(addr,t);
    જો (compare_destroy(addr, t->start) == 0) {        /* found it */
        જો (t->ડાબું == ખાલી) {
            x = t->જમણું;
        } નહીંતર {
            x = splay(addr, t->ડાબું);
            x->જમણું = t->જમણું;
        }
#જો વૃક્ષ_REUSE
        t->ડાબું = વૃક્ષ_free_list;
        વૃક્ષ_free_list = t;
#નહીંતર
        BOUND_FREE(t);
#endif
        પાછા x;
    } નહીંતર {
        પાછા t;                                      /* It wasn't there */
    }
}

શૂન્ય splay_printtree(વૃક્ષ * t, પૂર્ણાંક d)
{
    પૂર્ણાંક i;
    જો (t == ખાલી) પાછા;
    splay_printtree(t->જમણું, d+1);
    માટે (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (શૂન્ય *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->ડાબું, d+1);
}
