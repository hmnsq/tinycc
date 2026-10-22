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
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdarg.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <setjmp.h>
#അന്തര്ഭാവ <stdatomic.h>

#എങ്കിൽ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#അന്തര്ഭാവ <malloc.h>
#endif

#എങ്കിൽ !defined(_WIN32)
#അന്തര്ഭാവ <unistd.h>
#അന്തര്ഭാവ <sys/syscall.h>
#endif

#അന്തര്ഭാവ "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#എങ്കിൽ BOUND_DEBUG
 #define dprintf(a...)         എങ്കിൽ (print_calls) { bounds_loc(a); }
#അല്ലെങ്കിൽ
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#അല്ലെങ്കിൽ
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#അല്ലെങ്കിൽ
# define DLL_EXPORT
#endif

#എങ്കിൽ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#അന്തര്ഭാവ <sys/mman.h>
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

#അല്ലെങ്കിലെങ്കിൽ defined(_WIN32)

#അന്തര്ഭാവ <windows.h>
#അന്തര്ഭാവ <signal.h>
സ്ഥിതം CRITICAL_SECTION bounds_sem;
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

#അല്ലെങ്കിൽ

#define __USE_GNU              /* get RTLD_NEXT */
#അന്തര്ഭാവ <sys/mman.h>
#അന്തര്ഭാവ <ctype.h>
#അന്തര്ഭാവ <pthread.h>
#അന്തര്ഭാവ <dlfcn.h>
#അന്തര്ഭാവ <errno.h>
#അന്തര്ഭാവ <signal.h>
#ifdef __APPLE__
#അന്തര്ഭാവ <dispatch/dispatch.h>
സ്ഥിതം dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             എങ്കിൽ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             എങ്കിൽ (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              എങ്കിൽ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#അല്ലെങ്കിലെങ്കിൽ 0
#അന്തര്ഭാവ <semaphore.h>
സ്ഥിതം sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             എങ്കിൽ (use_sem) ആകുമ്പോൾ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             എങ്കിൽ (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              എങ്കിൽ (use_sem) ആകുമ്പോൾ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#അല്ലെങ്കിലെങ്കിൽ 0
സ്ഥിതം pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, ശൂന്യ)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             എങ്കിൽ (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             എങ്കിൽ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              എങ്കിൽ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#അല്ലെങ്കിൽ
സ്ഥിതം pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             എങ്കിൽ (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             എങ്കിൽ (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              എങ്കിൽ (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#എങ്കിൽ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#അല്ലെങ്കിൽ
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#എങ്കിൽ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#എങ്കിൽ MALLOC_REDIR
സ്ഥിതം ശൂന്യം *(*malloc_redir) (size_t);
സ്ഥിതം ശൂന്യം *(*calloc_redir) (size_t, size_t);
സ്ഥിതം ശൂന്യം (*free_redir) (ശൂന്യം *);
സ്ഥിതം ശൂന്യം *(*realloc_redir) (ശൂന്യം *, size_t);
സ്ഥിതം unsigned പൂർണ്ണസംഖ്യ pool_index;
സ്ഥിതം unsigned അക്ഷരം __attribute__((aligned(16))) initial_pool[256];
#endif
#എങ്കിൽ HAVE_MEMALIGN
സ്ഥിതം ശൂന്യം *(*memalign_redir) (size_t, size_t);
#endif
#എങ്കിൽ HAVE_PTHREAD_CREATE
സ്ഥിതം പൂർണ്ണസംഖ്യ (*pthread_create_redir) (pthread_t *thread,
                                    സ്ഥിരം pthread_attr_t *attr,
                                    ശൂന്യം *(*start_routine)(ശൂന്യം *), ശൂന്യം *arg);
#endif
#എങ്കിൽ HAVE_SIGNAL
തരനിർവചനം ശൂന്യം (*bound_sig)(പൂർണ്ണസംഖ്യ);
സ്ഥിതം bound_sig (*signal_redir) (പൂർണ്ണസംഖ്യ signum, bound_sig handler);
#endif
#എങ്കിൽ HAVE_SIGACTION
സ്ഥിതം പൂർണ്ണസംഖ്യ (*sigaction_redir) (പൂർണ്ണസംഖ്യ signum, സ്ഥിരം ഘടന sigaction *act,
                               ഘടന sigaction *oldact);
#endif
#എങ്കിൽ HAVE_FORK
സ്ഥിതം പൂർണ്ണസംഖ്യ (*fork_redir) (ശൂന്യം);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((ശൂന്യം *)(-2))

തരനിർവചനം ഘടന വൃക്ഷ_കണ്ണി വൃക്ഷം;
ഘടന വൃക്ഷ_കണ്ണി {
    വൃക്ഷം * ഇടത്, * വലത്;
    size_t start;
    size_t size;
    unsigned അക്ഷരം type;
    unsigned അക്ഷരം is_invalid; /* true if pointers outside region are invalid */
};

തരനിർവചനം ഘടന alloca_list_struct {
    size_t fp;
    ശൂന്യം *p;
    size_t size;
    ഘടന alloca_list_struct *next;
} alloca_list_type;

#എങ്കിൽ defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#അല്ലെങ്കിലെങ്കിൽ defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#അല്ലെങ്കിലെങ്കിൽ defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#അല്ലെങ്കിലെങ്കിൽ  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#അല്ലെങ്കിലെങ്കിൽ defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#അല്ലെങ്കിൽ
#define BOUND_TID_TYPE		പൂർണ്ണസംഖ്യ
#define BOUND_GET_TID(id)	id = 0
#endif

തരനിർവചനം ഘടന jmp_list_struct {
    ശൂന്യം *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    ഘടന jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
സ്ഥിതം വൃക്ഷം * splay (size_t addr, വൃക്ഷം *t);
സ്ഥിതം വൃക്ഷം * splay_end (size_t addr, വൃക്ഷം *t);
സ്ഥിതം വൃക്ഷം * splay_തിരുകുക(size_t addr, size_t size, വൃക്ഷം * t);
സ്ഥിതം വൃക്ഷം * splay_delete(size_t addr, വൃക്ഷം *t);
ശൂന്യം splay_printtree(വൃക്ഷം * t, പൂർണ്ണസംഖ്യ d);

/* external interface */
ശൂന്യം __bounds_checking (പൂർണ്ണസംഖ്യ no_check);
ശൂന്യം __bound_checking_lock (ശൂന്യം);
ശൂന്യം __bound_checking_unlock (ശൂന്യം);
ശൂന്യം __bound_never_fatal (പൂർണ്ണസംഖ്യ no_check);
DLL_EXPORT ശൂന്യം * __bound_ptr_add(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir1(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir2(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir4(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir8(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir12(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം * __bound_ptr_indir16(ശൂന്യം *p, size_t offset);
DLL_EXPORT ശൂന്യം FASTCALL __bound_local_new(ശൂന്യം *p1);
DLL_EXPORT ശൂന്യം FASTCALL __bound_local_delete(ശൂന്യം *p1);
ശൂന്യം __bound_init(size_t *, പൂർണ്ണസംഖ്യ);
ശൂന്യം __bound_main_arg(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **envp);
ശൂന്യം __bound_exit(ശൂന്യം);
ശൂന്യം __bound_exit_dll(size_t *);
#എങ്കിൽ !defined(_WIN32)
ശൂന്യം *__bound_mmap (ശൂന്യം *start, size_t size, പൂർണ്ണസംഖ്യ prot, പൂർണ്ണസംഖ്യ flags, പൂർണ്ണസംഖ്യ fd,
                    off_t offset);
പൂർണ്ണസംഖ്യ __bound_munmap (ശൂന്യം *start, size_t size);
DLL_EXPORT ശൂന്യം __bound_siglongjmp(jmp_buf env, പൂർണ്ണസംഖ്യ val);
#endif
DLL_EXPORT ശൂന്യം __bound_new_region(ശൂന്യം *p, size_t size);
DLL_EXPORT ശൂന്യം __bound_setjmp(jmp_buf env);
DLL_EXPORT ശൂന്യം __bound_longjmp(jmp_buf env, പൂർണ്ണസംഖ്യ val);
DLL_EXPORT ശൂന്യം *__bound_memcpy(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT പൂർണ്ണസംഖ്യ __bound_memcmp(സ്ഥിരം ശൂന്യം *s1, സ്ഥിരം ശൂന്യം *s2, size_t size);
DLL_EXPORT ശൂന്യം *__bound_memmove(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__bound_memset(ശൂന്യം *dst, പൂർണ്ണസംഖ്യ c, size_t size);
DLL_EXPORT പൂർണ്ണസംഖ്യ __bound_strlen(സ്ഥിരം അക്ഷരം *s);
DLL_EXPORT അക്ഷരം *__bound_strcpy(അക്ഷരം *dst, സ്ഥിരം അക്ഷരം *src);
DLL_EXPORT അക്ഷരം *__bound_strncpy(അക്ഷരം *dst, സ്ഥിരം അക്ഷരം *src, size_t n);
DLL_EXPORT പൂർണ്ണസംഖ്യ __bound_strcmp(സ്ഥിരം അക്ഷരം *s1, സ്ഥിരം അക്ഷരം *s2);
DLL_EXPORT പൂർണ്ണസംഖ്യ __bound_strncmp(സ്ഥിരം അക്ഷരം *s1, സ്ഥിരം അക്ഷരം *s2, size_t n);
DLL_EXPORT അക്ഷരം *__bound_strcat(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src);
DLL_EXPORT അക്ഷരം *__bound_strncat(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src, size_t n);
DLL_EXPORT അക്ഷരം *__bound_strchr(സ്ഥിരം അക്ഷരം *string, പൂർണ്ണസംഖ്യ ch);
DLL_EXPORT അക്ഷരം *__bound_strrchr(സ്ഥിരം അക്ഷരം *string, പൂർണ്ണസംഖ്യ ch);
DLL_EXPORT അക്ഷരം *__bound_strdup(സ്ഥിരം അക്ഷരം *s);

#എങ്കിൽ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT ശൂന്യം *__bound___aeabi_memcpy(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__bound___aeabi_memmove(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__bound___aeabi_memmove4(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__bound___aeabi_memmove8(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__bound___aeabi_memset(ശൂന്യം *dst, പൂർണ്ണസംഖ്യ c, size_t size);
DLL_EXPORT ശൂന്യം *__aeabi_memcpy(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__aeabi_memmove(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__aeabi_memmove4(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__aeabi_memmove8(ശൂന്യം *dst, സ്ഥിരം ശൂന്യം *src, size_t size);
DLL_EXPORT ശൂന്യം *__aeabi_memset(ശൂന്യം *dst, പൂർണ്ണസംഖ്യ c, size_t size);
#endif

#എങ്കിൽ MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#അല്ലെങ്കിൽ
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            സ്വതന്ത്രം(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT ശൂന്യം *__bound_malloc(size_t size, സ്ഥിരം ശൂന്യം *caller);
DLL_EXPORT ശൂന്യം *__bound_memalign(size_t align, size_t size, സ്ഥിരം ശൂന്യം *caller);
DLL_EXPORT ശൂന്യം __bound_free(ശൂന്യം *ptr, സ്ഥിരം ശൂന്യം *caller);
DLL_EXPORT ശൂന്യം *__bound_realloc(ശൂന്യം *ptr, size_t size, സ്ഥിരം ശൂന്യം *caller);
DLL_EXPORT ശൂന്യം *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
സ്ഥിതം unsigned പൂർണ്ണസംഖ്യ free_reuse_index;
സ്ഥിതം ശൂന്യം *free_reuse_list[FREE_REUSE_SIZE];

സ്ഥിതം വൃക്ഷം *വൃക്ഷം_2 = ശൂന്യ;
#define വൃക്ഷം_REUSE      (1)
#എങ്കിൽ വൃക്ഷം_REUSE
സ്ഥിതം വൃക്ഷം *വൃക്ഷം_free_list;
#endif
സ്ഥിതം alloca_list_type *alloca_list;
സ്ഥിതം jmp_list_type *jmp_list;

സ്ഥിതം unsigned അക്ഷരം inited;
സ്ഥിതം unsigned അക്ഷരം print_warn_ptr_add;
സ്ഥിതം unsigned അക്ഷരം print_calls;
സ്ഥിതം unsigned അക്ഷരം print_heap;
സ്ഥിതം unsigned അക്ഷരം print_statistic;
സ്ഥിതം unsigned അക്ഷരം no_strdup;
സ്ഥിതം unsigned അക്ഷരം use_sem;
സ്ഥിതം _Atomic പൂർണ്ണസംഖ്യ never_fatal;
#എങ്കിൽ HAVE_TLS_FUNC
#എങ്കിൽ defined(_WIN32)
സ്ഥിതം പൂർണ്ണസംഖ്യ no_checking = 0;
സ്ഥിതം DWORD no_checking_താക്കോൽ;
#define NO_CHECKING_CHECK() എങ്കിൽ (!p) {                                         \
                                  p = (പൂർണ്ണസംഖ്യ *) LocalAlloc(LPTR, വലുപ്പം(പൂർണ്ണസംഖ്യ));  \
                                  എങ്കിൽ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_മൂല്യം(no_checking_താക്കോൽ, p);            \
                            }
#define NO_CHECKING_GET()   ({ പൂർണ്ണസംഖ്യ *p = Tls_Get_മൂല്യം(no_checking_താക്കോൽ);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { പൂർണ്ണസംഖ്യ *p = Tls_Get_മൂല്യം(no_checking_താക്കോൽ);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#അല്ലെങ്കിൽ
സ്ഥിതം പൂർണ്ണസംഖ്യ no_checking = 0;
സ്ഥിതം pthread_key_t no_checking_താക്കോൽ;
#define NO_CHECKING_CHECK() എങ്കിൽ (!p) {                                         \
                                  p = (പൂർണ്ണസംഖ്യ *) BOUND_MALLOC(വലുപ്പം(പൂർണ്ണസംഖ്യ));      \
                                  എങ്കിൽ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_താക്കോൽ, p);    \
                            }
#define NO_CHECKING_GET()   ({ പൂർണ്ണസംഖ്യ *p = pthread_getspecific(no_checking_താക്കോൽ); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { പൂർണ്ണസംഖ്യ *p = pthread_getspecific(no_checking_താക്കോൽ);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#അല്ലെങ്കിലെങ്കിൽ HAVE_TLS_VAR
സ്ഥിതം __thread പൂർണ്ണസംഖ്യ no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#അല്ലെങ്കിൽ
സ്ഥിതം _Atomic പൂർണ്ണസംഖ്യ no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
സ്ഥിതം അക്ഷരം exec[100];

#എങ്കിൽ BOUND_STATISTIC
സ്ഥിതം unsigned long long bound_ptr_add_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir1_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir2_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir4_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir8_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir12_എണ്ണം;
സ്ഥിതം unsigned long long bound_ptr_indir16_എണ്ണം;
സ്ഥിതം unsigned long long bound_local_new_എണ്ണം;
സ്ഥിതം unsigned long long bound_local_delete_എണ്ണം;
സ്ഥിതം unsigned long long bound_malloc_എണ്ണം;
സ്ഥിതം unsigned long long bound_calloc_എണ്ണം;
സ്ഥിതം unsigned long long bound_realloc_എണ്ണം;
സ്ഥിതം unsigned long long bound_free_എണ്ണം;
സ്ഥിതം unsigned long long bound_memalign_എണ്ണം;
സ്ഥിതം unsigned long long bound_mmap_എണ്ണം;
സ്ഥിതം unsigned long long bound_munmap_എണ്ണം;
സ്ഥിതം unsigned long long bound_alloca_എണ്ണം;
സ്ഥിതം unsigned long long bound_setjmp_എണ്ണം;
സ്ഥിതം unsigned long long bound_longjmp_എണ്ണം;
സ്ഥിതം unsigned long long bound_mempcy_എണ്ണം;
സ്ഥിതം unsigned long long bound_memcmp_എണ്ണം;
സ്ഥിതം unsigned long long bound_memmove_എണ്ണം;
സ്ഥിതം unsigned long long bound_memset_എണ്ണം;
സ്ഥിതം unsigned long long bound_strlen_എണ്ണം;
സ്ഥിതം unsigned long long bound_strcpy_എണ്ണം;
സ്ഥിതം unsigned long long bound_strncpy_എണ്ണം;
സ്ഥിതം unsigned long long bound_strcmp_എണ്ണം;
സ്ഥിതം unsigned long long bound_strncmp_എണ്ണം;
സ്ഥിതം unsigned long long bound_strcat_എണ്ണം;
സ്ഥിതം unsigned long long bound_strncat_എണ്ണം;
സ്ഥിതം unsigned long long bound_strchr_എണ്ണം;
സ്ഥിതം unsigned long long bound_strrchr_എണ്ണം;
സ്ഥിതം unsigned long long bound_strdup_എണ്ണം;
സ്ഥിതം unsigned long long bound_not_found;
#define INCR_എണ്ണം(x)          ++x
#അല്ലെങ്കിൽ
#define INCR_എണ്ണം(x)
#endif
#എങ്കിൽ BOUND_STATISTIC_SPLAY
സ്ഥിതം unsigned long long bound_splay;
സ്ഥിതം unsigned long long bound_splay_end;
സ്ഥിതം unsigned long long bound_splay_തിരുകുക;
സ്ഥിതം unsigned long long bound_splay_delete;
#define INCR_എണ്ണം_SPLAY(x)    ++x
#അല്ലെങ്കിൽ
#define INCR_എണ്ണം_SPLAY(x)
#endif

പൂർണ്ണസംഖ്യ tcc_backtrace(സ്ഥിരം അക്ഷരം *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    ചെയ്യുക {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ആകുമ്പോൾ (0)

#define bound_error(...)            \
    ചെയ്യുക {                            \
        bound_warning(__VA_ARGS__); \
        എങ്കിൽ (never_fatal == 0)       \
            exit(255);              \
    } ആകുമ്പോൾ (0)

#define bounds_loc(fp, ...) \
    ചെയ്യുക {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ആകുമ്പോൾ (0)

സ്ഥിതം ശൂന്യം bound_alloc_error(സ്ഥിരം അക്ഷരം *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

സ്ഥിതം ശൂന്യം bound_not_found_warning(സ്ഥിരം അക്ഷരം *file, സ്ഥിരം അക്ഷരം *function,
                                    ശൂന്യം *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
ശൂന്യം __bounds_checking (പൂർണ്ണസംഖ്യ no_check)
{
#എങ്കിൽ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#അല്ലെങ്കിൽ
    atomic_fetch_add (&no_checking, no_check);
#endif
}

ശൂന്യം __bound_checking_lock(ശൂന്യം)
{
    WAIT_SEM ();
}

ശൂന്യം __bound_checking_unlock(ശൂന്യം)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
ശൂന്യം __bound_never_fatal (പൂർണ്ണസംഖ്യ neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
ശൂന്യം * __bound_ptr_add(ശൂന്യം *p, size_t offset)
{
    size_t addr = (size_t)p;

    എങ്കിൽ (NO_CHECKING_GET())
        തിരികെ p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_എണ്ണം(bound_ptr_add_എണ്ണം);
    എങ്കിൽ (വൃക്ഷം_2) {
        addr -= വൃക്ഷം_2->start;
        എങ്കിൽ (addr >= വൃക്ഷം_2->size) {
            addr = (size_t)p;
            വൃക്ഷം_2 = splay (addr, വൃക്ഷം_2);
            addr -= വൃക്ഷം_2->start;
        }
        എങ്കിൽ (addr >= വൃക്ഷം_2->size) {
            addr = (size_t)p;
            വൃക്ഷം_2 = splay_end (addr, വൃക്ഷം_2);
            addr -= വൃക്ഷം_2->start;
        }
        എങ്കിൽ (addr <= വൃക്ഷം_2->size) {
            എങ്കിൽ (വൃക്ഷം_2->is_invalid || addr + offset > വൃക്ഷം_2->size) {
                POST_SEM ();
                എങ്കിൽ (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)വൃക്ഷം_2->start,
                                  (long)(വൃക്ഷം_2->start + വൃക്ഷം_2->size - 1));
                എങ്കിൽ (never_fatal <= 0)
                    തിരികെ INVALID_POINTER; /* return an invalid pointer */
                തിരികെ p + offset;
            }
        }
        അല്ലെങ്കിൽ എങ്കിൽ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_എണ്ണം(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            തിരികെ p + offset;
        }
    }
    POST_SEM ();
    തിരികെ p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
ശൂന്യം * __bound_ptr_indir ## dsize (ശൂന്യം *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    എങ്കിൽ (NO_CHECKING_GET())                                                     \
        തിരികെ p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_എണ്ണം(bound_ptr_indir ## dsize ## എണ്ണം);                            \
    എങ്കിൽ (വൃക്ഷം_2) {                                                                \
        addr -= വൃക്ഷം_2->start;                                                   \
        എങ്കിൽ (addr >= വൃക്ഷം_2->size) {                                              \
            addr = (size_t)p;                                                  \
            വൃക്ഷം_2 = splay (addr, വൃക്ഷം_2);                                         \
            addr -= വൃക്ഷം_2->start;                                               \
        }                                                                      \
        എങ്കിൽ (addr >= വൃക്ഷം_2->size) {                                              \
            addr = (size_t)p;                                                  \
            വൃക്ഷം_2 = splay_end (addr, വൃക്ഷം_2);                                     \
            addr -= വൃക്ഷം_2->start;                                               \
        }                                                                      \
        എങ്കിൽ (addr <= വൃക്ഷം_2->size) {                                              \
            എങ്കിൽ (വൃക്ഷം_2->is_invalid || addr + offset + dsize > വൃക്ഷം_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)വൃക്ഷം_2->start,            \
                              (long)(വൃക്ഷം_2->start + വൃക്ഷം_2->size - 1));           \
                എങ്കിൽ (never_fatal <= 0)                                          \
                    തിരികെ INVALID_POINTER; /* return an invalid pointer */    \
                തിരികെ p + offset;                                             \
            }                                                                  \
        }                                                                      \
        അല്ലെങ്കിൽ {                                                                 \
            INCR_എണ്ണം(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            തിരികെ p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    തിരികെ p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#എങ്കിൽ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic തള്ളുക
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
ശൂന്യം FASTCALL __bound_local_new(ശൂന്യം *p1) 
{
    size_t addr, fp, *p = p1;

    എങ്കിൽ (NO_CHECKING_GET())
         തിരികെ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ശൂന്യം *)fp);
    WAIT_SEM ();
    ആകുമ്പോൾ ((addr = p[0])) {
        INCR_എണ്ണം(bound_local_new_എണ്ണം);
        വൃക്ഷം_2 = splay_തിരുകുക(addr + fp, p[1], വൃക്ഷം_2);
        p += 2;
    }
    POST_SEM ();
#എങ്കിൽ BOUND_DEBUG
    എങ്കിൽ (print_calls) {
        p = p1;
        ആകുമ്പോൾ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (ശൂന്യം *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
ശൂന്യം FASTCALL __bound_local_delete(ശൂന്യം *p1) 
{
    size_t addr, fp, *p = p1;

    എങ്കിൽ (NO_CHECKING_GET())
         തിരികെ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ശൂന്യം *)fp);
    WAIT_SEM ();
    ആകുമ്പോൾ ((addr = p[0])) {
        INCR_എണ്ണം(bound_local_delete_എണ്ണം);
        വൃക്ഷം_2 = splay_delete(addr + fp, വൃക്ഷം_2);
        p += 2;
    }
    എങ്കിൽ (alloca_list) {
        alloca_list_type *last = ശൂന്യ;
        alloca_list_type *cur = alloca_list;

        ചെയ്യുക {
            എങ്കിൽ (cur->fp == fp) {
                എങ്കിൽ (last)
                    last->next = cur->next;
                അല്ലെങ്കിൽ
                    alloca_list = cur->next;
                വൃക്ഷം_2 = splay_delete ((size_t) cur->p, വൃക്ഷം_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             അല്ലെങ്കിൽ {
                 last = cur;
                 cur = cur->next;
             }
        } ആകുമ്പോൾ (cur);
    }
    എങ്കിൽ (jmp_list) {
        jmp_list_type *last = ശൂന്യ;
        jmp_list_type *cur = jmp_list;

        ചെയ്യുക {
            എങ്കിൽ (cur->fp == fp) {
                എങ്കിൽ (last)
                    last->next = cur->next;
                അല്ലെങ്കിൽ
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            അല്ലെങ്കിൽ {
                last = cur;
                cur = cur->next;
            }
        } ആകുമ്പോൾ (cur);
    }

    POST_SEM ();
#എങ്കിൽ BOUND_DEBUG
    എങ്കിൽ (print_calls) {
        p = p1;
        ആകുമ്പോൾ ((addr = p[0])) {
            എങ്കിൽ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ശൂന്യം *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
ശൂന്യം __bound_new_region(ശൂന്യം *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    എങ്കിൽ (NO_CHECKING_GET())
        തിരികെ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (വലുപ്പം (alloca_list_type));
    WAIT_SEM ();
    INCR_എണ്ണം(bound_alloca_എണ്ണം);
    last = ശൂന്യ;
    cur = alloca_list;
    ആകുമ്പോൾ (cur) {
#എങ്കിൽ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        പൂർണ്ണസംഖ്യ align = 4;
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__)
        പൂർണ്ണസംഖ്യ align = 8;
#അല്ലെങ്കിൽ
        പൂർണ്ണസംഖ്യ align = 16;
#endif
        ശൂന്യം *cure = (ശൂന്യം *)((അക്ഷരം *)cur->p + ((cur->size + align) & -align));
        ശൂന്യം *pe = (ശൂന്യം *)((അക്ഷരം *)p + ((size + align) & -align));
        എങ്കിൽ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            എങ്കിൽ (last)
                last->next = cur->next;
            അല്ലെങ്കിൽ
                alloca_list = cur->next;
            വൃക്ഷം_2 = splay_delete((size_t)cur->p, വൃക്ഷം_2);
            നിർത്തുക;
        }
        last = cur;
        cur = cur->next;
    }
    വൃക്ഷം_2 = splay_തിരുകുക((size_t)p, size, വൃക്ഷം_2);
    എങ്കിൽ (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    എങ്കിൽ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

ശൂന്യം __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    ശൂന്യം *e = (ശൂന്യം *) env;

    എങ്കിൽ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_എണ്ണം(bound_setjmp_എണ്ണം);
        jl = jmp_list;
        ആകുമ്പോൾ (jl) {
            എങ്കിൽ (jl->penv == e)
                നിർത്തുക;
            jl = jl->next;
        }
        എങ്കിൽ (jl == ശൂന്യ) {
            jl = BOUND_MALLOC (വലുപ്പം (jmp_list_type));
            എങ്കിൽ (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        എങ്കിൽ (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

സ്ഥിതം ശൂന്യം __bound_long_jump(jmp_buf env, പൂർണ്ണസംഖ്യ val, പൂർണ്ണസംഖ്യ sig, സ്ഥിരം അക്ഷരം *func)
{
    jmp_list_type *jl;
    ശൂന്യം *e;
    BOUND_TID_TYPE tid;

    എങ്കിൽ (NO_CHECKING_GET() == 0) {
        e = (ശൂന്യം *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_എണ്ണം(bound_longjmp_എണ്ണം);
        jl = jmp_list;
        ആകുമ്പോൾ (jl) {
            എങ്കിൽ (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = ശൂന്യ;

                ആകുമ്പോൾ (cur->penv != e || cur->tid != tid) {
                    എങ്കിൽ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        എങ്കിൽ (last)
                            last->next = cur->next;
                        അല്ലെങ്കിൽ
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    അല്ലെങ്കിൽ {
                        last = cur;
                        cur = cur->next;
                    }
                }
                വേണ്ടി (;;) {
                    വൃക്ഷം *t = വൃക്ഷം_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    ആകുമ്പോൾ (t && (t->start < start_fp || t->start > end_fp))
                        എങ്കിൽ (t->start < start_fp)
                            t = t->വലത്;
                        അല്ലെങ്കിൽ
                            t = t->ഇടത്;
                    എങ്കിൽ (t == ശൂന്യ)
                        നിർത്തുക;
                    last = ശൂന്യ;
                    cur = alloca_list;
                    ആകുമ്പോൾ (cur) {
                         എങ്കിൽ ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             എങ്കിൽ (last)
                                 last->next = cur->next;
                             അല്ലെങ്കിൽ
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             നിർത്തുക;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (ശൂന്യം *) t->start);
                    വൃക്ഷം_2 = splay_delete(t->start, വൃക്ഷം_2);
                }
                നിർത്തുക;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#എങ്കിൽ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

ശൂന്യം __bound_longjmp(jmp_buf env, പൂർണ്ണസംഖ്യ val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#എങ്കിൽ !defined(_WIN32)
ശൂന്യം __bound_siglongjmp(jmp_buf env, പൂർണ്ണസംഖ്യ val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#എങ്കിൽ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic എടുക്കുക
#endif

ശൂന്യം __bound_init(size_t *p, പൂർണ്ണസംഖ്യ mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    എങ്കിൽ (inited) {
        WAIT_SEM();
        പോകുക add_bounds;
    }
    inited = 1;

#എങ്കിൽ HAVE_TLS_FUNC
#എങ്കിൽ defined(_WIN32)
    no_checking_താക്കോൽ = TlsAlloc();
    Tls_Set_മൂല്യം(no_checking_താക്കോൽ, &no_checking);
#അല്ലെങ്കിൽ
    pthread_key_create(&no_checking_താക്കോൽ, ശൂന്യ);
    pthread_setspecific(no_checking_താക്കോൽ, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ശൂന്യ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ശൂന്യ;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != ശൂന്യ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ശൂന്യ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ശൂന്യ;

    INIT_SEM ();

#എങ്കിൽ MALLOC_REDIR
    {
        ശൂന്യം *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(ശൂന്യം **) (&malloc_redir) = dlsym (addr, "malloc");
        എങ്കിൽ (malloc_redir == ശൂന്യ) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(ശൂന്യം **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(ശൂന്യം **) (&calloc_redir) = dlsym (addr, "calloc");
        *(ശൂന്യം **) (&free_redir) = dlsym (addr, "free");
        *(ശൂന്യം **) (&realloc_redir) = dlsym (addr, "realloc");
        *(ശൂന്യം **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        എങ്കിൽ (malloc_redir == ശൂന്യ || free_redir == ശൂന്യ)
            bound_alloc_error ("Cannot redirect malloc/free");
#എങ്കിൽ HAVE_PTHREAD_CREATE
        *(ശൂന്യം **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        എങ്കിൽ (pthread_create_redir == ശൂന്യ)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#എങ്കിൽ HAVE_SIGNAL
        *(ശൂന്യം **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        എങ്കിൽ (signal_redir == ശൂന്യ)
            bound_alloc_error ("Cannot redirect signal");
#endif
#എങ്കിൽ HAVE_SIGACTION
        *(ശൂന്യം **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        എങ്കിൽ (sigaction_redir == ശൂന്യ)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#എങ്കിൽ HAVE_FORK
        *(ശൂന്യം **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        എങ്കിൽ (fork_redir == ശൂന്യ)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned അക്ഷരം found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        അക്ഷരം വരി[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        എങ്കിൽ (fp) {
            memset (exec, 0, വലുപ്പം(exec));
            fread (exec, 1, വലുപ്പം(exec) - 2, fp);
            എങ്കിൽ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        എങ്കിൽ (fp) {
            ആകുമ്പോൾ (fgets (വരി, വലുപ്പം(വരി), fp)) {
                എങ്കിൽ (sscanf (വരി, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    നിർത്തുക;
                }
                എങ്കിൽ (strstr (വരി,"[heap]"))
                    നിർത്തുക;
            }
            fclose (fp);
        }
        എങ്കിൽ (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#എങ്കിൽ HAVE_CTYPE
#ifdef __APPLE__
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) &_DefaultRuneLocale,
                        വലുപ്പം (_DefaultRuneLocale), വൃക്ഷം_2);
#അല്ലെങ്കിൽ
    /* XXX: Does not work if locale is changed */
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) __ctype_b_loc(),
                        വലുപ്പം (unsigned short *), വൃക്ഷം_2);
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) (*__ctype_b_loc() - 128),
                        384 * വലുപ്പം (unsigned short), വൃക്ഷം_2);
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) __ctype_tolower_loc(),
                        വലുപ്പം (__int32_t *), വൃക്ഷം_2);
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) (*__ctype_tolower_loc() - 128),
                        384 * വലുപ്പം (__int32_t), വൃക്ഷം_2);
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) __ctype_toupper_loc(),
                        വലുപ്പം (__int32_t *), വൃക്ഷം_2);
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) (*__ctype_toupper_loc() - 128),
                        384 * വലുപ്പം (__int32_t), വൃക്ഷം_2);
#endif
#endif
#എങ്കിൽ HAVE_ERRNO
    വൃക്ഷം_2 = splay_തിരുകുക((size_t) (&errno), വലുപ്പം (പൂർണ്ണസംഖ്യ), വൃക്ഷം_2);
#endif

add_bounds:
    എങ്കിൽ (!p)
        പോകുക no_bounds;

    /* add all static bound check values */
    ആകുമ്പോൾ (p[0] != 0) {
        വൃക്ഷം_2 = splay_തിരുകുക(p[0], p[1], വൃക്ഷം_2);
#എങ്കിൽ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (ശൂന്യം *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

ശൂന്യം
#എങ്കിൽ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **envp)
{
    __bound_init (0, -1);
    എങ്കിൽ (argc && argv) {
        പൂർണ്ണസംഖ്യ i;

        WAIT_SEM ();
        വേണ്ടി (i = 0; i < argc; i++)
            വൃക്ഷം_2 = splay_തിരുകുക((size_t) argv[i], strlen (argv[i]) + 1, വൃക്ഷം_2);
        വൃക്ഷം_2 = splay_തിരുകുക((size_t) argv, (argc + 1) * വലുപ്പം(അക്ഷരം *), വൃക്ഷം_2);
        POST_SEM ();
#എങ്കിൽ BOUND_DEBUG
        എങ്കിൽ (print_calls) {
            വേണ്ടി (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (പൂർണ്ണസംഖ്യ)((argc + 1) * വലുപ്പം(അക്ഷരം *)));
        }
#endif
    }

    എങ്കിൽ (envp && *envp) {
        അക്ഷരം **p = envp;

        WAIT_SEM ();
        ആകുമ്പോൾ (*p) {
            വൃക്ഷം_2 = splay_തിരുകുക((size_t) *p, strlen (*p) + 1, വൃക്ഷം_2);
            ++p;
        }
        വൃക്ഷം_2 = splay_തിരുകുക((size_t) envp, (++p - envp) * വലുപ്പം(അക്ഷരം *), വൃക്ഷം_2);
        POST_SEM ();
#എങ്കിൽ BOUND_DEBUG
        എങ്കിൽ (print_calls) {
            p = envp;
            ആകുമ്പോൾ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (പൂർണ്ണസംഖ്യ)((++p - envp) * വലുപ്പം(അക്ഷരം *)));
        }
#endif
    }
}

ശൂന്യം __attribute__((destructor)) __bound_exit(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;
    സ്ഥിതം സ്ഥിരം അക്ഷരം * സ്ഥിരം alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    എങ്കിൽ (inited) {
#എങ്കിൽ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        എങ്കിൽ (print_heap) {
            ബാഹ്യ ശൂന്യം __libc_freeres (ശൂന്യം);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        ആകുമ്പോൾ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            വൃക്ഷം_2 = splay_delete ((size_t) alloca_list->p, വൃക്ഷം_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        ആകുമ്പോൾ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        വേണ്ടി (i = 0; i < FREE_REUSE_SIZE; i++) {
            എങ്കിൽ (free_reuse_list[i]) {
                വൃക്ഷം_2 = splay_delete ((size_t) free_reuse_list[i], വൃക്ഷം_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ആകുമ്പോൾ (വൃക്ഷം_2) {
            എങ്കിൽ (print_heap && വൃക്ഷം_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[വൃക്ഷം_2->type],
                         (unsigned long) വൃക്ഷം_2->size);
            വൃക്ഷം_2 = splay_delete (വൃക്ഷം_2->start, വൃക്ഷം_2);
        }
#എങ്കിൽ വൃക്ഷം_REUSE
        ആകുമ്പോൾ (വൃക്ഷം_free_list) {
            വൃക്ഷം *next = വൃക്ഷം_free_list->ഇടത്;
            BOUND_FREE (വൃക്ഷം_free_list);
            വൃക്ഷം_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#എങ്കിൽ HAVE_TLS_FUNC
#എങ്കിൽ defined(_WIN32)
        TlsFree(no_checking_താക്കോൽ);
#അല്ലെങ്കിൽ
        pthread_key_delete(no_checking_താക്കോൽ);
#endif
#endif
        inited = 0;
        എങ്കിൽ (print_statistic) {
#എങ്കിൽ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_എണ്ണം);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_എണ്ണം);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_എണ്ണം);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_എണ്ണം);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_എണ്ണം);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_എണ്ണം);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_എണ്ണം);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_എണ്ണം);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_എണ്ണം);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_എണ്ണം);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_എണ്ണം);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_എണ്ണം);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_എണ്ണം);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_എണ്ണം);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_എണ്ണം);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_എണ്ണം);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_എണ്ണം);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_എണ്ണം);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_എണ്ണം);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_എണ്ണം);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_എണ്ണം);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_എണ്ണം);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_എണ്ണം);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_എണ്ണം);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_എണ്ണം);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_എണ്ണം);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_എണ്ണം);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_എണ്ണം);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#എങ്കിൽ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_തിരുകുക);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

ശൂന്യം __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    എങ്കിൽ (p) {
        WAIT_SEM ();
	ആകുമ്പോൾ (p[0] != 0) {
	    വൃക്ഷം_2 = splay_delete(p[0], വൃക്ഷം_2);
#എങ്കിൽ BOUND_DEBUG
            എങ്കിൽ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ശൂന്യം *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#എങ്കിൽ HAVE_PTHREAD_CREATE
തരനിർവചനം ഘടന {
    ശൂന്യം *(*start_routine) (ശൂന്യം *);
    ശൂന്യം *arg;
    sigset_t old_mask;
} bound_thread_create_type;

സ്ഥിതം ശൂന്യം *bound_thread_create(ശൂന്യം *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    ശൂന്യം *retval;
#എങ്കിൽ HAVE_TLS_FUNC
    പൂർണ്ണസംഖ്യ *p = (പൂർണ്ണസംഖ്യ *) BOUND_MALLOC(വലുപ്പം(പൂർണ്ണസംഖ്യ));
  
    എങ്കിൽ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_താക്കോൽ, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, ശൂന്യ);
    retval = data->start_routine(data->arg);
#എങ്കിൽ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_താക്കോൽ, ശൂന്യ);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    തിരികെ retval;
}

പൂർണ്ണസംഖ്യ pthread_create(pthread_t *thread, സ്ഥിരം pthread_attr_t *attr,
                   ശൂന്യം *(*start_routine) (ശൂന്യം *), ശൂന്യം *arg)
{
    പൂർണ്ണസംഖ്യ retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(വലുപ്പം(bound_thread_create_type));
    എങ്കിൽ (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, ശൂന്യ);
    തിരികെ retval;
}
#endif

#എങ്കിൽ HAVE_SIGNAL || HAVE_SIGACTION
തരനിർവചനം സംഘം {
#എങ്കിൽ HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#എങ്കിൽ HAVE_SIGACTION
    ശൂന്യം (*sig_handler)(പൂർണ്ണസംഖ്യ);
    ശൂന്യം (*sig_sigaction)(പൂർണ്ണസംഖ്യ, siginfo_t *, ശൂന്യം *);
#endif
} bound_sig_type;

സ്ഥിതം unsigned അക്ഷരം bound_sig_used[NSIG];
സ്ഥിതം bound_sig_type bound_sig_data[NSIG];
#endif

#എങ്കിൽ HAVE_SIGNAL
സ്ഥിതം ശൂന്യം signal_handler(പൂർണ്ണസംഖ്യ sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig സൂചന(പൂർണ്ണസംഖ്യ signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    എങ്കിൽ (retval != SIG_ERR) {
        എങ്കിൽ (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        എങ്കിൽ (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    തിരികെ retval;
}
#endif

#എങ്കിൽ HAVE_SIGACTION
സ്ഥിതം ശൂന്യം sig_handler(പൂർണ്ണസംഖ്യ sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

സ്ഥിതം ശൂന്യം sig_sigaction(പൂർണ്ണസംഖ്യ sig, siginfo_t *info, ശൂന്യം *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

പൂർണ്ണസംഖ്യ sigaction(പൂർണ്ണസംഖ്യ signum, സ്ഥിരം ഘടന sigaction *act, ഘടന sigaction *oldact)
{
    പൂർണ്ണസംഖ്യ retval;
    ഘടന sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    എങ്കിൽ (sigaction_redir == ശൂന്യ)
        __bound_init(0,-1);

    എങ്കിൽ (act) {
        nact = *act;
        എങ്കിൽ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        അല്ലെങ്കിൽ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    അല്ലെങ്കിൽ
        retval = sigaction_redir(signum, act, &oact);
    എങ്കിൽ (retval >= 0) {
        എങ്കിൽ (bound_sig_used[signum]) {
            എങ്കിൽ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            അല്ലെങ്കിൽ
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        എങ്കിൽ (oldact) {
            *oldact = oact;
        }
        എങ്കിൽ (act) {
            bound_sig_used[signum] = 1;
            എങ്കിൽ (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            അല്ലെങ്കിൽ
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    തിരികെ retval;
}
#endif

#എങ്കിൽ HAVE_FORK
pid_t fork(ശൂന്യം)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    എങ്കിൽ (retval == 0)
        INIT_SEM();
    അല്ലെങ്കിൽ
        POST_SEM();
    തിരികെ retval;
}
#endif

#എങ്കിൽ MALLOC_REDIR
ശൂന്യം *malloc(size_t size)
#അല്ലെങ്കിൽ
ശൂന്യം *__bound_malloc(size_t size, സ്ഥിരം ശൂന്യം *caller)
#endif
{
    ശൂന്യം *ptr;
    
#എങ്കിൽ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    എങ്കിൽ (malloc_redir == ശൂന്യ) {
        __bound_init (0, -1);
        എങ്കിൽ (malloc_redir == ശൂന്യ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            എങ്കിൽ (pool_index >= വലുപ്പം (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            തിരികെ ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    എങ്കിൽ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_malloc_എണ്ണം);

        എങ്കിൽ (ptr) {
            വൃക്ഷം_2 = splay_തിരുകുക ((size_t) ptr, size ? size : size + 1, വൃക്ഷം_2);
            എങ്കിൽ (വൃക്ഷം_2 && വൃക്ഷം_2->start == (size_t) ptr)
                വൃക്ഷം_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    തിരികെ ptr;
}

#എങ്കിൽ MALLOC_REDIR
ശൂന്യം *memalign(size_t align, size_t size)
#അല്ലെങ്കിൽ
ശൂന്യം *__bound_memalign(size_t align, size_t size, സ്ഥിരം ശൂന്യം *caller)
#endif
{
    ശൂന്യം *ptr;

#എങ്കിൽ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#അല്ലെങ്കിൽ
    എങ്കിൽ (align > 4) {
        /* XXX: handle it ? */
        ptr = ശൂന്യ;
    } അല്ലെങ്കിൽ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    എങ്കിൽ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_memalign_എണ്ണം);

        എങ്കിൽ (ptr) {
            വൃക്ഷം_2 = splay_തിരുകുക((size_t) ptr, size ? size : size + 1, വൃക്ഷം_2);
            എങ്കിൽ (വൃക്ഷം_2 && വൃക്ഷം_2->start == (size_t) ptr)
                വൃക്ഷം_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    തിരികെ ptr;
}

#എങ്കിൽ MALLOC_REDIR
ശൂന്യം സ്വതന്ത്രം(ശൂന്യം *ptr)
#അല്ലെങ്കിൽ
ശൂന്യം __bound_free(ശൂന്യം *ptr, സ്ഥിരം ശൂന്യം *caller)
#endif
{
    size_t addr = (size_t) ptr;
    ശൂന്യം *p;

    എങ്കിൽ (ptr == ശൂന്യ || വൃക്ഷം_2 == ശൂന്യ
#എങ്കിൽ MALLOC_REDIR
        || ((unsigned അക്ഷരം *) ptr >= &initial_pool[0] &&
            (unsigned അക്ഷരം *) ptr < &initial_pool[വലുപ്പം(initial_pool)])
#endif
        )
        തിരികെ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    എങ്കിൽ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_free_എണ്ണം);
        വൃക്ഷം_2 = splay (addr, വൃക്ഷം_2);
        എങ്കിൽ (വൃക്ഷം_2->start == addr) {
            എങ്കിൽ (വൃക്ഷം_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                തിരികെ;
            }
            വൃക്ഷം_2->is_invalid = 1;
            memset (ptr, 0x5a, വൃക്ഷം_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            എങ്കിൽ (p)
                വൃക്ഷം_2 = splay_delete((size_t)p, വൃക്ഷം_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#എങ്കിൽ MALLOC_REDIR
ശൂന്യം *realloc(ശൂന്യം *ptr, size_t size)
#അല്ലെങ്കിൽ
ശൂന്യം *__bound_realloc(ശൂന്യം *ptr, size_t size, സ്ഥിരം ശൂന്യം *caller)
#endif
{
    ശൂന്യം *new_ptr;

    എങ്കിൽ (size == 0) {
#എങ്കിൽ MALLOC_REDIR
        സ്വതന്ത്രം(ptr);
#അല്ലെങ്കിൽ
        __bound_free(ptr, caller);
#endif
        തിരികെ ശൂന്യ;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    എങ്കിൽ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_realloc_എണ്ണം);

        എങ്കിൽ (ptr)
            വൃക്ഷം_2 = splay_delete ((size_t) ptr, വൃക്ഷം_2);
        എങ്കിൽ (new_ptr) {
            വൃക്ഷം_2 = splay_തിരുകുക ((size_t) new_ptr, size ? size : size + 1, വൃക്ഷം_2);
            എങ്കിൽ (വൃക്ഷം_2 && വൃക്ഷം_2->start == (size_t) new_ptr)
                വൃക്ഷം_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    തിരികെ new_ptr;
}

#എങ്കിൽ MALLOC_REDIR
ശൂന്യം *calloc(size_t nmemb, size_t size)
#അല്ലെങ്കിൽ
ശൂന്യം *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    ശൂന്യം *ptr;

    size *= nmemb;
#എങ്കിൽ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    എങ്കിൽ (malloc_redir == ശൂന്യ) {
        __bound_init (0, -1);
        എങ്കിൽ (malloc_redir == ശൂന്യ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            എങ്കിൽ (pool_index >= വലുപ്പം (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            തിരികെ ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    എങ്കിൽ (ptr) {
        memset (ptr, 0, size);
        എങ്കിൽ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_എണ്ണം(bound_calloc_എണ്ണം);
            വൃക്ഷം_2 = splay_തിരുകുക ((size_t) ptr, size ? size : size + 1, വൃക്ഷം_2);
            എങ്കിൽ (വൃക്ഷം_2 && വൃക്ഷം_2->start == (size_t) ptr)
                വൃക്ഷം_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    തിരികെ ptr;
}

#എങ്കിൽ !defined(_WIN32)
ശൂന്യം *__bound_mmap (ശൂന്യം *start, size_t size, പൂർണ്ണസംഖ്യ prot,
                    പൂർണ്ണസംഖ്യ flags, പൂർണ്ണസംഖ്യ fd, off_t offset)
{
    ശൂന്യം *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    എങ്കിൽ (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_mmap_എണ്ണം);
        വൃക്ഷം_2 = splay_തിരുകുക((size_t)result, size, വൃക്ഷം_2);
        POST_SEM ();
    }
    തിരികെ result;
}

പൂർണ്ണസംഖ്യ __bound_munmap (ശൂന്യം *start, size_t size)
{
    പൂർണ്ണസംഖ്യ result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    എങ്കിൽ (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_എണ്ണം(bound_munmap_എണ്ണം);
        വൃക്ഷം_2 = splay_delete ((size_t) start, വൃക്ഷം_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    തിരികെ result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
സ്ഥിതം ശൂന്യം __bound_check(സ്ഥിരം ശൂന്യം *p, size_t size, സ്ഥിരം അക്ഷരം *function)
{
    എങ്കിൽ (size != 0 && __bound_ptr_add((ശൂന്യം *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ check_overlap (സ്ഥിരം ശൂന്യം *p1, size_t n1,
                          സ്ഥിരം ശൂന്യം *p2, size_t n2,
                          സ്ഥിരം അക്ഷരം *function)
{
    സ്ഥിരം ശൂന്യം *p1e = (സ്ഥിരം ശൂന്യം *) ((സ്ഥിരം അക്ഷരം *) p1 + n1);
    സ്ഥിരം ശൂന്യം *p2e = (സ്ഥിരം ശൂന്യം *) ((സ്ഥിരം അക്ഷരം *) p2 + n2);

    എങ്കിൽ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        തിരികെ never_fatal < 0;
    }
    തിരികെ 0;
}

ശൂന്യം *__bound_memcpy(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_mempcy_എണ്ണം);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    എങ്കിൽ (check_overlap(dest, n, src, n, "memcpy"))
        തിരികെ dest;
    തിരികെ memcpy(dest, src, n);
}

പൂർണ്ണസംഖ്യ __bound_memcmp(സ്ഥിരം ശൂന്യം *s1, സ്ഥിരം ശൂന്യം *s2, size_t n)
{
    സ്ഥിരം unsigned അക്ഷരം *u1 = (സ്ഥിരം unsigned അക്ഷരം *) s1;
    സ്ഥിരം unsigned അക്ഷരം *u2 = (സ്ഥിരം unsigned അക്ഷരം *) s2;
    പൂർണ്ണസംഖ്യ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_എണ്ണം(bound_memcmp_എണ്ണം);
    വേണ്ടി (;;) {
        എങ്കിൽ ((ssize_t) --n == -1)
            നിർത്തുക;
        അല്ലെങ്കിൽ എങ്കിൽ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            നിർത്തുക;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (സ്ഥിരം ശൂന്യം *)u1 - s1, "memcmp s1");
    __bound_check(s2, (സ്ഥിരം ശൂന്യം *)u2 - s2, "memcmp s2");
    തിരികെ retval;
}

ശൂന്യം *__bound_memmove(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_memmove_എണ്ണം);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    തിരികെ memmove(dest, src, n);
}

ശൂന്യം *__bound_memset(ശൂന്യം *s, പൂർണ്ണസംഖ്യ c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_എണ്ണം(bound_memset_എണ്ണം);
    __bound_check(s, n, "memset");
    തിരികെ memset(s, c, n);
}

#എങ്കിൽ defined(__arm__) && defined(__ARM_EABI__)
ശൂന്യം *__bound___aeabi_memcpy(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_mempcy_എണ്ണം);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    എങ്കിൽ (check_overlap(dest, n, src, n, "memcpy"))
        തിരികെ dest;
    തിരികെ __aeabi_memcpy(dest, src, n);
}

ശൂന്യം *__bound___aeabi_memmove(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_memmove_എണ്ണം);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    തിരികെ __aeabi_memmove(dest, src, n);
}

ശൂന്യം *__bound___aeabi_memmove4(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_memmove_എണ്ണം);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    തിരികെ __aeabi_memmove4(dest, src, n);
}

ശൂന്യം *__bound___aeabi_memmove8(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_memmove_എണ്ണം);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    തിരികെ __aeabi_memmove8(dest, src, n);
}

ശൂന്യം *__bound___aeabi_memset(ശൂന്യം *s, പൂർണ്ണസംഖ്യ c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_എണ്ണം(bound_memset_എണ്ണം);
    __bound_check(s, n, "memset");
    തിരികെ __aeabi_memset(s, c, n);
}
#endif

പൂർണ്ണസംഖ്യ __bound_strlen(സ്ഥിരം അക്ഷരം *s)
{
    സ്ഥിരം അക്ഷരം *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_എണ്ണം(bound_strlen_എണ്ണം);
    ആകുമ്പോൾ (*p++);
    __bound_check(s, p - s, "strlen");
    തിരികെ (p - s) - 1;
}

അക്ഷരം *__bound_strcpy(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src)
{
    size_t len;
    സ്ഥിരം അക്ഷരം *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_എണ്ണം(bound_strcpy_എണ്ണം);
    ആകുമ്പോൾ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    എങ്കിൽ (check_overlap(dest, len, src, len, "strcpy"))
        തിരികെ dest;
    തിരികെ strcpy (dest, src);
}

അക്ഷരം *__bound_strncpy(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src, size_t n)
{
    size_t len = n;
    സ്ഥിരം അക്ഷരം *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_strncpy_എണ്ണം);
    ആകുമ്പോൾ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    എങ്കിൽ (check_overlap(dest, len, src, len, "strncpy"))
        തിരികെ dest;
    തിരികെ strncpy(dest, src, n);
}

പൂർണ്ണസംഖ്യ __bound_strcmp(സ്ഥിരം അക്ഷരം *s1, സ്ഥിരം അക്ഷരം *s2)
{
    സ്ഥിരം unsigned അക്ഷരം *u1 = (സ്ഥിരം unsigned അക്ഷരം *) s1;
    സ്ഥിരം unsigned അക്ഷരം *u2 = (സ്ഥിരം unsigned അക്ഷരം *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_എണ്ണം(bound_strcmp_എണ്ണം);
    ആകുമ്പോൾ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((സ്ഥിരം അക്ഷരം *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((സ്ഥിരം അക്ഷരം *)u2 - s2) + 1, "strcmp s2");
    തിരികെ *u1 - *u2;
}

പൂർണ്ണസംഖ്യ __bound_strncmp(സ്ഥിരം അക്ഷരം *s1, സ്ഥിരം അക്ഷരം *s2, size_t n)
{
    സ്ഥിരം unsigned അക്ഷരം *u1 = (സ്ഥിരം unsigned അക്ഷരം *) s1;
    സ്ഥിരം unsigned അക്ഷരം *u2 = (സ്ഥിരം unsigned അക്ഷരം *) s2;
    പൂർണ്ണസംഖ്യ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_എണ്ണം(bound_strncmp_എണ്ണം);
    ചെയ്യുക {
        എങ്കിൽ ((ssize_t) --n == -1)
            നിർത്തുക;
        അല്ലെങ്കിൽ എങ്കിൽ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            നിർത്തുക;
        }
        ++u2;
    } ആകുമ്പോൾ (*u1++);
    __bound_check(s1, (സ്ഥിരം അക്ഷരം *)u1 - s1, "strncmp s1");
    __bound_check(s2, (സ്ഥിരം അക്ഷരം *)u2 - s2, "strncmp s2");
    തിരികെ retval;
}

അക്ഷരം *__bound_strcat(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src)
{
    അക്ഷരം *r = dest;
    സ്ഥിരം അക്ഷരം *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_എണ്ണം(bound_strcat_എണ്ണം);
    ആകുമ്പോൾ (*dest++);
    ആകുമ്പോൾ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    എങ്കിൽ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        തിരികെ dest;
    തിരികെ strcat(r, s);
}

അക്ഷരം *__bound_strncat(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src, size_t n)
{
    അക്ഷരം *r = dest;
    സ്ഥിരം അക്ഷരം *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_എണ്ണം(bound_strncat_എണ്ണം);
    ആകുമ്പോൾ (*dest++);
    ആകുമ്പോൾ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    എങ്കിൽ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        തിരികെ dest;
    തിരികെ strncat(r, s, n);
}

അക്ഷരം *__bound_strchr(സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ c)
{
    സ്ഥിരം unsigned അക്ഷരം *str = (സ്ഥിരം unsigned അക്ഷരം *) s;
    unsigned അക്ഷരം ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_എണ്ണം(bound_strchr_എണ്ണം);
    ആകുമ്പോൾ (*str) {
        എങ്കിൽ (*str == ch)
            നിർത്തുക;
        ++str;
    }
    __bound_check(s, ((സ്ഥിരം അക്ഷരം *)str - s) + 1, "strchr");
    തിരികെ *str == ch ? (അക്ഷരം *) str : ശൂന്യ;
}

അക്ഷരം *__bound_strrchr(സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ c)
{
    സ്ഥിരം unsigned അക്ഷരം *str = (സ്ഥിരം unsigned അക്ഷരം *) s;
    unsigned അക്ഷരം ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_എണ്ണം(bound_strrchr_എണ്ണം);
    ആകുമ്പോൾ (*str++);
    __bound_check(s, (സ്ഥിരം അക്ഷരം *)str - s, "strrchr");
    ആകുമ്പോൾ (str != (സ്ഥിരം unsigned അക്ഷരം *)s) {
        എങ്കിൽ (*--str == ch)
            നിർത്തുക;
    }
    __bound_check(s, (സ്ഥിരം അക്ഷരം *)str - s, "strrchr");
    തിരികെ *str == ch ? (അക്ഷരം *) str : ശൂന്യ;
}

അക്ഷരം *__bound_strdup(സ്ഥിരം അക്ഷരം *s)
{
    സ്ഥിരം അക്ഷരം *p = s;
    അക്ഷരം *new;

    INCR_എണ്ണം(bound_strdup_എണ്ണം);
    ആകുമ്പോൾ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    എങ്കിൽ (new) {
        എങ്കിൽ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            വൃക്ഷം_2 = splay_തിരുകുക((size_t)new, p - s, വൃക്ഷം_2);
            എങ്കിൽ (വൃക്ഷം_2 && വൃക്ഷം_2->start == (size_t) new)
                വൃക്ഷം_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    തിരികെ new;
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

സ്ഥിതം വൃക്ഷം * splay (size_t addr, വൃക്ഷം *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    വൃക്ഷം N, *l, *r, *y;
    പൂർണ്ണസംഖ്യ comp;
    
    INCR_എണ്ണം_SPLAY(bound_splay);
    എങ്കിൽ (t == ശൂന്യ) തിരികെ t;
    N.ഇടത് = N.വലത് = ശൂന്യ;
    l = r = &N;
 
    വേണ്ടി (;;) {
        comp = compare(addr, t->start, t->size);
        എങ്കിൽ (comp < 0) {
            y = t->ഇടത്;
            എങ്കിൽ (y == ശൂന്യ) നിർത്തുക;
            എങ്കിൽ (compare(addr, y->start, y->size) < 0) {
                t->ഇടത് = y->വലത്;                    /* rotate right */
                y->വലത് = t;
                t = y;
                എങ്കിൽ (t->ഇടത് == ശൂന്യ) നിർത്തുക;
            }
            r->ഇടത് = t;                               /* link right */
            r = t;
            t = t->ഇടത്;
        } അല്ലെങ്കിൽ എങ്കിൽ (comp > 0) {
            y = t->വലത്;
            എങ്കിൽ (y == ശൂന്യ) നിർത്തുക;
            എങ്കിൽ (compare(addr, y->start, y->size) > 0) {
                t->വലത് = y->ഇടത്;                    /* rotate left */
                y->ഇടത് = t;
                t = y;
                എങ്കിൽ (t->വലത് == ശൂന്യ) നിർത്തുക;
            }
            l->വലത് = t;                              /* link left */
            l = t;
            t = t->വലത്;
        } അല്ലെങ്കിൽ {
            നിർത്തുക;
        }
    }
    l->വലത് = t->ഇടത്;                                /* assemble */
    r->ഇടത് = t->വലത്;
    t->ഇടത് = N.വലത്;
    t->വലത് = N.ഇടത്;

    തിരികെ t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

സ്ഥിതം വൃക്ഷം * splay_end (size_t addr, വൃക്ഷം *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    വൃക്ഷം N, *l, *r, *y;
    പൂർണ്ണസംഖ്യ comp;
    
    INCR_എണ്ണം_SPLAY(bound_splay_end);
    എങ്കിൽ (t == ശൂന്യ) തിരികെ t;
    N.ഇടത് = N.വലത് = ശൂന്യ;
    l = r = &N;
 
    വേണ്ടി (;;) {
        comp = compare_end(addr, t->start + t->size);
        എങ്കിൽ (comp < 0) {
            y = t->ഇടത്;
            എങ്കിൽ (y == ശൂന്യ) നിർത്തുക;
            എങ്കിൽ (compare_end(addr, y->start + y->size) < 0) {
                t->ഇടത് = y->വലത്;                    /* rotate right */
                y->വലത് = t;
                t = y;
                എങ്കിൽ (t->ഇടത് == ശൂന്യ) നിർത്തുക;
            }
            r->ഇടത് = t;                               /* link right */
            r = t;
            t = t->ഇടത്;
        } അല്ലെങ്കിൽ എങ്കിൽ (comp > 0) {
            y = t->വലത്;
            എങ്കിൽ (y == ശൂന്യ) നിർത്തുക;
            എങ്കിൽ (compare_end(addr, y->start + y->size) > 0) {
                t->വലത് = y->ഇടത്;                    /* rotate left */
                y->ഇടത് = t;
                t = y;
                എങ്കിൽ (t->വലത് == ശൂന്യ) നിർത്തുക;
            }
            l->വലത് = t;                              /* link left */
            l = t;
            t = t->വലത്;
        } അല്ലെങ്കിൽ {
            നിർത്തുക;
        }
    }
    l->വലത് = t->ഇടത്;                                /* assemble */
    r->ഇടത് = t->വലത്;
    t->ഇടത് = N.വലത്;
    t->വലത് = N.ഇടത്;

    തിരികെ t;
}

സ്ഥിതം വൃക്ഷം * splay_തിരുകുക(size_t addr, size_t size, വൃക്ഷം * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    വൃക്ഷം * new;

    INCR_എണ്ണം_SPLAY(bound_splay_തിരുകുക);
    എങ്കിൽ (t != ശൂന്യ) {
        t = splay(addr,t);
        എങ്കിൽ (compare(addr, t->start, t->size)==0) {
            തിരികെ t;  /* it's already there */
        }
    }
#എങ്കിൽ വൃക്ഷം_REUSE
    എങ്കിൽ (വൃക്ഷം_free_list) {
          new = വൃക്ഷം_free_list;
          വൃക്ഷം_free_list = new->ഇടത്;
    }
    അല്ലെങ്കിൽ
#endif
    {
        new = (വൃക്ഷം *) BOUND_MALLOC (വലുപ്പം (വൃക്ഷം));
    }
    എങ്കിൽ (new == ശൂന്യ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    അല്ലെങ്കിൽ {
        എങ്കിൽ (t == ശൂന്യ) {
            new->ഇടത് = new->വലത് = ശൂന്യ;
        } അല്ലെങ്കിൽ എങ്കിൽ (compare(addr, t->start, t->size) < 0) {
            new->ഇടത് = t->ഇടത്;
            new->വലത് = t;
            t->ഇടത് = ശൂന്യ;
        } അല്ലെങ്കിൽ {
            new->വലത് = t->വലത്;
            new->ഇടത് = t;
            t->വലത് = ശൂന്യ;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    തിരികെ new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

സ്ഥിതം വൃക്ഷം * splay_delete(size_t addr, വൃക്ഷം *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    വൃക്ഷം * x;

    INCR_എണ്ണം_SPLAY(bound_splay_delete);
    എങ്കിൽ (t==ശൂന്യ) തിരികെ ശൂന്യ;
    t = splay(addr,t);
    എങ്കിൽ (compare_destroy(addr, t->start) == 0) {        /* found it */
        എങ്കിൽ (t->ഇടത് == ശൂന്യ) {
            x = t->വലത്;
        } അല്ലെങ്കിൽ {
            x = splay(addr, t->ഇടത്);
            x->വലത് = t->വലത്;
        }
#എങ്കിൽ വൃക്ഷം_REUSE
        t->ഇടത് = വൃക്ഷം_free_list;
        വൃക്ഷം_free_list = t;
#അല്ലെങ്കിൽ
        BOUND_FREE(t);
#endif
        തിരികെ x;
    } അല്ലെങ്കിൽ {
        തിരികെ t;                                      /* It wasn't there */
    }
}

ശൂന്യം splay_printtree(വൃക്ഷം * t, പൂർണ്ണസംഖ്യ d)
{
    പൂർണ്ണസംഖ്യ i;
    എങ്കിൽ (t == ശൂന്യ) തിരികെ;
    splay_printtree(t->വലത്, d+1);
    വേണ്ടി (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (ശൂന്യം *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->ഇടത്, d+1);
}
