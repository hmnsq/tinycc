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
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಅನ್ತರ್ಭಾವ <stdatomic.h>

#ಯದಿ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ಅನ್ತರ್ಭಾವ <malloc.h>
#endif

#ಯದಿ !defined(_WIN32)
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <sys/syscall.h>
#endif

#ಅನ್ತರ್ಭಾವ "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#ಯದಿ BOUND_DEBUG
 #define dprintf(a...)         ಯದಿ (print_calls) { bounds_loc(a); }
#ಅನ್ಯಥಾ
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#ಅನ್ಯಥಾ
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ಅನ್ಯಥಾ
# define DLL_EXPORT
#endif

#ಯದಿ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ಅನ್ತರ್ಭಾವ <sys/mman.h>
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

#ನೋಚೇದ್ಯದಿ defined(_WIN32)

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
ಸ್ಥಿರ CRITICAL_SECTION bounds_sem;
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

#ಅನ್ಯಥಾ

#define __USE_GNU              /* get RTLD_NEXT */
#ಅನ್ತರ್ಭಾವ <sys/mman.h>
#ಅನ್ತರ್ಭಾವ <ctype.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <dlfcn.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
#ifdef __APPLE__
#ಅನ್ತರ್ಭಾವ <dispatch/dispatch.h>
ಸ್ಥಿರ dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             ಯದಿ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             ಯದಿ (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              ಯದಿ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#ನೋಚೇದ್ಯದಿ 0
#ಅನ್ತರ್ಭಾವ <semaphore.h>
ಸ್ಥಿರ sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             ಯದಿ (use_sem) ಯಾವತ್ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             ಯದಿ (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              ಯದಿ (use_sem) ಯಾವತ್ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ನೋಚೇದ್ಯದಿ 0
ಸ್ಥಿರ pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, ರಿಕ್ತ)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             ಯದಿ (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             ಯದಿ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              ಯದಿ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ಅನ್ಯಥಾ
ಸ್ಥಿರ pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             ಯದಿ (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             ಯದಿ (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              ಯದಿ (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#ಯದಿ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#ಅನ್ಯಥಾ
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#ಯದಿ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#ಯದಿ MALLOC_REDIR
ಸ್ಥಿರ ಶೂನ್ಯ *(*malloc_redir) (size_t);
ಸ್ಥಿರ ಶೂನ್ಯ *(*calloc_redir) (size_t, size_t);
ಸ್ಥಿರ ಶೂನ್ಯ (*free_redir) (ಶೂನ್ಯ *);
ಸ್ಥಿರ ಶೂನ್ಯ *(*realloc_redir) (ಶೂನ್ಯ *, size_t);
ಸ್ಥಿರ unsigned ಪೂರ್ಣಾಙ್ಕ pool_index;
ಸ್ಥಿರ unsigned ವರ್ಣ __attribute__((aligned(16))) initial_pool[256];
#endif
#ಯದಿ HAVE_MEMALIGN
ಸ್ಥಿರ ಶೂನ್ಯ *(*memalign_redir) (size_t, size_t);
#endif
#ಯದಿ HAVE_PTHREAD_CREATE
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ (*pthread_create_redir) (pthread_t *thread,
                                    ಧ್ರುವ pthread_attr_t *attr,
                                    ಶೂನ್ಯ *(*start_routine)(ಶೂನ್ಯ *), ಶೂನ್ಯ *arg);
#endif
#ಯದಿ HAVE_SIGNAL
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (*bound_sig)(ಪೂರ್ಣಾಙ್ಕ);
ಸ್ಥಿರ bound_sig (*signal_redir) (ಪೂರ್ಣಾಙ್ಕ signum, bound_sig handler);
#endif
#ಯದಿ HAVE_SIGACTION
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ (*sigaction_redir) (ಪೂರ್ಣಾಙ್ಕ signum, ಧ್ರುವ ಸಂರಚನಾ sigaction *act,
                               ಸಂರಚನಾ sigaction *oldact);
#endif
#ಯದಿ HAVE_FORK
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ (*fork_redir) (ಶೂನ್ಯ);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((ಶೂನ್ಯ *)(-2))

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ವೃಕ್ಷ_ಗಂಟು ವೃಕ್ಷ;
ಸಂರಚನಾ ವೃಕ್ಷ_ಗಂಟು {
    ವೃಕ್ಷ * ಎಡ, * ಬಲ;
    size_t start;
    size_t size;
    unsigned ವರ್ಣ type;
    unsigned ವರ್ಣ is_invalid; /* true if pointers outside region are invalid */
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ alloca_list_struct {
    size_t fp;
    ಶೂನ್ಯ *p;
    size_t size;
    ಸಂರಚನಾ alloca_list_struct *next;
} alloca_list_type;

#ಯದಿ defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#ನೋಚೇದ್ಯದಿ defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#ನೋಚೇದ್ಯದಿ defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#ನೋಚೇದ್ಯದಿ  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#ನೋಚೇದ್ಯದಿ defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ಅನ್ಯಥಾ
#define BOUND_TID_TYPE		ಪೂರ್ಣಾಙ್ಕ
#define BOUND_GET_TID(id)	id = 0
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ jmp_list_struct {
    ಶೂನ್ಯ *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    ಸಂರಚನಾ jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
ಸ್ಥಿರ ವೃಕ್ಷ * splay (size_t addr, ವೃಕ್ಷ *t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_end (size_t addr, ವೃಕ್ಷ *t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಸೇರಿಸು(size_t addr, size_t size, ವೃಕ್ಷ * t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_delete(size_t addr, ವೃಕ್ಷ *t);
ಶೂನ್ಯ splay_printtree(ವೃಕ್ಷ * t, ಪೂರ್ಣಾಙ್ಕ d);

/* external interface */
ಶೂನ್ಯ __bounds_checking (ಪೂರ್ಣಾಙ್ಕ no_check);
ಶೂನ್ಯ __bound_checking_lock (ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_checking_unlock (ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_never_fatal (ಪೂರ್ಣಾಙ್ಕ no_check);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_add(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir1(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir2(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir4(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir8(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir12(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir16(ಶೂನ್ಯ *p, size_t offset);
DLL_EXPORT ಶೂನ್ಯ FASTCALL __bound_local_new(ಶೂನ್ಯ *p1);
DLL_EXPORT ಶೂನ್ಯ FASTCALL __bound_local_delete(ಶೂನ್ಯ *p1);
ಶೂನ್ಯ __bound_init(size_t *, ಪೂರ್ಣಾಙ್ಕ);
ಶೂನ್ಯ __bound_main_arg(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **envp);
ಶೂನ್ಯ __bound_exit(ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_exit_dll(size_t *);
#ಯದಿ !defined(_WIN32)
ಶೂನ್ಯ *__bound_mmap (ಶೂನ್ಯ *start, size_t size, ಪೂರ್ಣಾಙ್ಕ prot, ಪೂರ್ಣಾಙ್ಕ flags, ಪೂರ್ಣಾಙ್ಕ fd,
                    off_t offset);
ಪೂರ್ಣಾಙ್ಕ __bound_munmap (ಶೂನ್ಯ *start, size_t size);
DLL_EXPORT ಶೂನ್ಯ __bound_siglongjmp(jmp_buf env, ಪೂರ್ಣಾಙ್ಕ val);
#endif
DLL_EXPORT ಶೂನ್ಯ __bound_new_region(ಶೂನ್ಯ *p, size_t size);
DLL_EXPORT ಶೂನ್ಯ __bound_setjmp(jmp_buf env);
DLL_EXPORT ಶೂನ್ಯ __bound_longjmp(jmp_buf env, ಪೂರ್ಣಾಙ್ಕ val);
DLL_EXPORT ಶೂನ್ಯ *__bound_memcpy(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಪೂರ್ಣಾಙ್ಕ __bound_memcmp(ಧ್ರುವ ಶೂನ್ಯ *s1, ಧ್ರುವ ಶೂನ್ಯ *s2, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound_memmove(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಙ್ಕ c, size_t size);
DLL_EXPORT ಪೂರ್ಣಾಙ್ಕ __bound_strlen(ಧ್ರುವ ವರ್ಣ *s);
DLL_EXPORT ವರ್ಣ *__bound_strcpy(ವರ್ಣ *dst, ಧ್ರುವ ವರ್ಣ *src);
DLL_EXPORT ವರ್ಣ *__bound_strncpy(ವರ್ಣ *dst, ಧ್ರುವ ವರ್ಣ *src, size_t n);
DLL_EXPORT ಪೂರ್ಣಾಙ್ಕ __bound_strcmp(ಧ್ರುವ ವರ್ಣ *s1, ಧ್ರುವ ವರ್ಣ *s2);
DLL_EXPORT ಪೂರ್ಣಾಙ್ಕ __bound_strncmp(ಧ್ರುವ ವರ್ಣ *s1, ಧ್ರುವ ವರ್ಣ *s2, size_t n);
DLL_EXPORT ವರ್ಣ *__bound_strcat(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src);
DLL_EXPORT ವರ್ಣ *__bound_strncat(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src, size_t n);
DLL_EXPORT ವರ್ಣ *__bound_strchr(ಧ್ರುವ ವರ್ಣ *string, ಪೂರ್ಣಾಙ್ಕ ch);
DLL_EXPORT ವರ್ಣ *__bound_strrchr(ಧ್ರುವ ವರ್ಣ *string, ಪೂರ್ಣಾಙ್ಕ ch);
DLL_EXPORT ವರ್ಣ *__bound_strdup(ಧ್ರುವ ವರ್ಣ *s);

#ಯದಿ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memcpy(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove4(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove8(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಙ್ಕ c, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memcpy(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove4(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove8(ಶೂನ್ಯ *dst, ಧ್ರುವ ಶೂನ್ಯ *src, size_t size);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಙ್ಕ c, size_t size);
#endif

#ಯದಿ MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ಅನ್ಯಥಾ
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            ಮುಕ್ತ(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT ಶೂನ್ಯ *__bound_malloc(size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_memalign(size_t align, size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ __bound_free(ಶೂನ್ಯ *ptr, ಧ್ರುವ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_realloc(ಶೂನ್ಯ *ptr, size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
ಸ್ಥಿರ unsigned ಪೂರ್ಣಾಙ್ಕ free_reuse_index;
ಸ್ಥಿರ ಶೂನ್ಯ *free_reuse_list[FREE_REUSE_SIZE];

ಸ್ಥಿರ ವೃಕ್ಷ *ವೃಕ್ಷ_2 = ರಿಕ್ತ;
#define ವೃಕ್ಷ_REUSE      (1)
#ಯದಿ ವೃಕ್ಷ_REUSE
ಸ್ಥಿರ ವೃಕ್ಷ *ವೃಕ್ಷ_free_list;
#endif
ಸ್ಥಿರ alloca_list_type *alloca_list;
ಸ್ಥಿರ jmp_list_type *jmp_list;

ಸ್ಥಿರ unsigned ವರ್ಣ inited;
ಸ್ಥಿರ unsigned ವರ್ಣ print_warn_ptr_add;
ಸ್ಥಿರ unsigned ವರ್ಣ print_calls;
ಸ್ಥಿರ unsigned ವರ್ಣ print_heap;
ಸ್ಥಿರ unsigned ವರ್ಣ print_statistic;
ಸ್ಥಿರ unsigned ವರ್ಣ no_strdup;
ಸ್ಥಿರ unsigned ವರ್ಣ use_sem;
ಸ್ಥಿರ _Atomic ಪೂರ್ಣಾಙ್ಕ never_fatal;
#ಯದಿ HAVE_TLS_FUNC
#ಯದಿ defined(_WIN32)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ no_checking = 0;
ಸ್ಥಿರ DWORD no_checking_ಕೀಲಿ;
#define NO_CHECKING_CHECK() ಯದಿ (!p) {                                         \
                                  p = (ಪೂರ್ಣಾಙ್ಕ *) LocalAlloc(LPTR, ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));  \
                                  ಯದಿ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ, p);            \
                            }
#define NO_CHECKING_GET()   ({ ಪೂರ್ಣಾಙ್ಕ *p = Tls_Get_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { ಪೂರ್ಣಾಙ್ಕ *p = Tls_Get_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ಅನ್ಯಥಾ
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ no_checking = 0;
ಸ್ಥಿರ pthread_key_t no_checking_ಕೀಲಿ;
#define NO_CHECKING_CHECK() ಯದಿ (!p) {                                         \
                                  p = (ಪೂರ್ಣಾಙ್ಕ *) BOUND_MALLOC(ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));      \
                                  ಯದಿ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ಕೀಲಿ, p);    \
                            }
#define NO_CHECKING_GET()   ({ ಪೂರ್ಣಾಙ್ಕ *p = pthread_getspecific(no_checking_ಕೀಲಿ); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { ಪೂರ್ಣಾಙ್ಕ *p = pthread_getspecific(no_checking_ಕೀಲಿ);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#ನೋಚೇದ್ಯದಿ HAVE_TLS_VAR
ಸ್ಥಿರ __thread ಪೂರ್ಣಾಙ್ಕ no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#ಅನ್ಯಥಾ
ಸ್ಥಿರ _Atomic ಪೂರ್ಣಾಙ್ಕ no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
ಸ್ಥಿರ ವರ್ಣ exec[100];

#ಯದಿ BOUND_STATISTIC
ಸ್ಥಿರ unsigned long long bound_ptr_add_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir1_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir2_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir4_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir8_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir12_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_ptr_indir16_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_local_new_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_local_delete_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_malloc_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_calloc_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_realloc_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_free_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_memalign_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_mmap_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_munmap_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_alloca_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_setjmp_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_longjmp_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_mempcy_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_memcmp_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_memmove_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_memset_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strlen_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strcpy_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strncpy_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strcmp_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strncmp_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strcat_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strncat_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strchr_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strrchr_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_strdup_ಎಣಿಕೆ;
ಸ್ಥಿರ unsigned long long bound_not_found;
#define INCR_ಎಣಿಕೆ(x)          ++x
#ಅನ್ಯಥಾ
#define INCR_ಎಣಿಕೆ(x)
#endif
#ಯದಿ BOUND_STATISTIC_SPLAY
ಸ್ಥಿರ unsigned long long bound_splay;
ಸ್ಥಿರ unsigned long long bound_splay_end;
ಸ್ಥಿರ unsigned long long bound_splay_ಸೇರಿಸು;
ಸ್ಥಿರ unsigned long long bound_splay_delete;
#define INCR_ಎಣಿಕೆ_SPLAY(x)    ++x
#ಅನ್ಯಥಾ
#define INCR_ಎಣಿಕೆ_SPLAY(x)
#endif

ಪೂರ್ಣಾಙ್ಕ tcc_backtrace(ಧ್ರುವ ವರ್ಣ *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    ಕುರು {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ಯಾವತ್ (0)

#define bound_error(...)            \
    ಕುರು {                            \
        bound_warning(__VA_ARGS__); \
        ಯದಿ (never_fatal == 0)       \
            exit(255);              \
    } ಯಾವತ್ (0)

#define bounds_loc(fp, ...) \
    ಕುರು {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ಯಾವತ್ (0)

ಸ್ಥಿರ ಶೂನ್ಯ bound_alloc_error(ಧ್ರುವ ವರ್ಣ *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

ಸ್ಥಿರ ಶೂನ್ಯ bound_not_found_warning(ಧ್ರುವ ವರ್ಣ *file, ಧ್ರುವ ವರ್ಣ *function,
                                    ಶೂನ್ಯ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
ಶೂನ್ಯ __bounds_checking (ಪೂರ್ಣಾಙ್ಕ no_check)
{
#ಯದಿ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#ಅನ್ಯಥಾ
    atomic_fetch_add (&no_checking, no_check);
#endif
}

ಶೂನ್ಯ __bound_checking_lock(ಶೂನ್ಯ)
{
    WAIT_SEM ();
}

ಶೂನ್ಯ __bound_checking_unlock(ಶೂನ್ಯ)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
ಶೂನ್ಯ __bound_never_fatal (ಪೂರ್ಣಾಙ್ಕ neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
ಶೂನ್ಯ * __bound_ptr_add(ಶೂನ್ಯ *p, size_t offset)
{
    size_t addr = (size_t)p;

    ಯದಿ (NO_CHECKING_GET())
        ಪ್ರತ್ಯಾಗಮ p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_ಎಣಿಕೆ(bound_ptr_add_ಎಣಿಕೆ);
    ಯದಿ (ವೃಕ್ಷ_2) {
        addr -= ವೃಕ್ಷ_2->start;
        ಯದಿ (addr >= ವೃಕ್ಷ_2->size) {
            addr = (size_t)p;
            ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);
            addr -= ವೃಕ್ಷ_2->start;
        }
        ಯದಿ (addr >= ವೃಕ್ಷ_2->size) {
            addr = (size_t)p;
            ವೃಕ್ಷ_2 = splay_end (addr, ವೃಕ್ಷ_2);
            addr -= ವೃಕ್ಷ_2->start;
        }
        ಯದಿ (addr <= ವೃಕ್ಷ_2->size) {
            ಯದಿ (ವೃಕ್ಷ_2->is_invalid || addr + offset > ವೃಕ್ಷ_2->size) {
                POST_SEM ();
                ಯದಿ (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)ವೃಕ್ಷ_2->start,
                                  (long)(ವೃಕ್ಷ_2->start + ವೃಕ್ಷ_2->size - 1));
                ಯದಿ (never_fatal <= 0)
                    ಪ್ರತ್ಯಾಗಮ INVALID_POINTER; /* return an invalid pointer */
                ಪ್ರತ್ಯಾಗಮ p + offset;
            }
        }
        ಅನ್ಯಥಾ ಯದಿ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ಎಣಿಕೆ(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            ಪ್ರತ್ಯಾಗಮ p + offset;
        }
    }
    POST_SEM ();
    ಪ್ರತ್ಯಾಗಮ p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
ಶೂನ್ಯ * __bound_ptr_indir ## dsize (ಶೂನ್ಯ *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    ಯದಿ (NO_CHECKING_GET())                                                     \
        ಪ್ರತ್ಯಾಗಮ p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_ಎಣಿಕೆ(bound_ptr_indir ## dsize ## ಎಣಿಕೆ);                            \
    ಯದಿ (ವೃಕ್ಷ_2) {                                                                \
        addr -= ವೃಕ್ಷ_2->start;                                                   \
        ಯದಿ (addr >= ವೃಕ್ಷ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);                                         \
            addr -= ವೃಕ್ಷ_2->start;                                               \
        }                                                                      \
        ಯದಿ (addr >= ವೃಕ್ಷ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            ವೃಕ್ಷ_2 = splay_end (addr, ವೃಕ್ಷ_2);                                     \
            addr -= ವೃಕ್ಷ_2->start;                                               \
        }                                                                      \
        ಯದಿ (addr <= ವೃಕ್ಷ_2->size) {                                              \
            ಯದಿ (ವೃಕ್ಷ_2->is_invalid || addr + offset + dsize > ವೃಕ್ಷ_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)ವೃಕ್ಷ_2->start,            \
                              (long)(ವೃಕ್ಷ_2->start + ವೃಕ್ಷ_2->size - 1));           \
                ಯದಿ (never_fatal <= 0)                                          \
                    ಪ್ರತ್ಯಾಗಮ INVALID_POINTER; /* return an invalid pointer */    \
                ಪ್ರತ್ಯಾಗಮ p + offset;                                             \
            }                                                                  \
        }                                                                      \
        ಅನ್ಯಥಾ {                                                                 \
            INCR_ಎಣಿಕೆ(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            ಪ್ರತ್ಯಾಗಮ p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ಪ್ರತ್ಯಾಗಮ p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ಯದಿ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic ತಳ್ಳು
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
ಶೂನ್ಯ FASTCALL __bound_local_new(ಶೂನ್ಯ *p1) 
{
    size_t addr, fp, *p = p1;

    ಯದಿ (NO_CHECKING_GET())
         ಪ್ರತ್ಯಾಗಮ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ಶೂನ್ಯ *)fp);
    WAIT_SEM ();
    ಯಾವತ್ ((addr = p[0])) {
        INCR_ಎಣಿಕೆ(bound_local_new_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು(addr + fp, p[1], ವೃಕ್ಷ_2);
        p += 2;
    }
    POST_SEM ();
#ಯದಿ BOUND_DEBUG
    ಯದಿ (print_calls) {
        p = p1;
        ಯಾವತ್ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (ಶೂನ್ಯ *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
ಶೂನ್ಯ FASTCALL __bound_local_delete(ಶೂನ್ಯ *p1) 
{
    size_t addr, fp, *p = p1;

    ಯದಿ (NO_CHECKING_GET())
         ಪ್ರತ್ಯಾಗಮ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ಶೂನ್ಯ *)fp);
    WAIT_SEM ();
    ಯಾವತ್ ((addr = p[0])) {
        INCR_ಎಣಿಕೆ(bound_local_delete_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_delete(addr + fp, ವೃಕ್ಷ_2);
        p += 2;
    }
    ಯದಿ (alloca_list) {
        alloca_list_type *last = ರಿಕ್ತ;
        alloca_list_type *cur = alloca_list;

        ಕುರು {
            ಯದಿ (cur->fp == fp) {
                ಯದಿ (last)
                    last->next = cur->next;
                ಅನ್ಯಥಾ
                    alloca_list = cur->next;
                ವೃಕ್ಷ_2 = splay_delete ((size_t) cur->p, ವೃಕ್ಷ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             ಅನ್ಯಥಾ {
                 last = cur;
                 cur = cur->next;
             }
        } ಯಾವತ್ (cur);
    }
    ಯದಿ (jmp_list) {
        jmp_list_type *last = ರಿಕ್ತ;
        jmp_list_type *cur = jmp_list;

        ಕುರು {
            ಯದಿ (cur->fp == fp) {
                ಯದಿ (last)
                    last->next = cur->next;
                ಅನ್ಯಥಾ
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            ಅನ್ಯಥಾ {
                last = cur;
                cur = cur->next;
            }
        } ಯಾವತ್ (cur);
    }

    POST_SEM ();
#ಯದಿ BOUND_DEBUG
    ಯದಿ (print_calls) {
        p = p1;
        ಯಾವತ್ ((addr = p[0])) {
            ಯದಿ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ಶೂನ್ಯ *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
ಶೂನ್ಯ __bound_new_region(ಶೂನ್ಯ *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    ಯದಿ (NO_CHECKING_GET())
        ಪ್ರತ್ಯಾಗಮ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (ಪರಿಮಾಣ (alloca_list_type));
    WAIT_SEM ();
    INCR_ಎಣಿಕೆ(bound_alloca_ಎಣಿಕೆ);
    last = ರಿಕ್ತ;
    cur = alloca_list;
    ಯಾವತ್ (cur) {
#ಯದಿ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        ಪೂರ್ಣಾಙ್ಕ align = 4;
#ನೋಚೇದ್ಯದಿ defined(__arm__)
        ಪೂರ್ಣಾಙ್ಕ align = 8;
#ಅನ್ಯಥಾ
        ಪೂರ್ಣಾಙ್ಕ align = 16;
#endif
        ಶೂನ್ಯ *cure = (ಶೂನ್ಯ *)((ವರ್ಣ *)cur->p + ((cur->size + align) & -align));
        ಶೂನ್ಯ *pe = (ಶೂನ್ಯ *)((ವರ್ಣ *)p + ((size + align) & -align));
        ಯದಿ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ಯದಿ (last)
                last->next = cur->next;
            ಅನ್ಯಥಾ
                alloca_list = cur->next;
            ವೃಕ್ಷ_2 = splay_delete((size_t)cur->p, ವೃಕ್ಷ_2);
            ಭಙ್ಗ;
        }
        last = cur;
        cur = cur->next;
    }
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t)p, size, ವೃಕ್ಷ_2);
    ಯದಿ (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ಯದಿ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

ಶೂನ್ಯ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    ಶೂನ್ಯ *e = (ಶೂನ್ಯ *) env;

    ಯದಿ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_setjmp_ಎಣಿಕೆ);
        jl = jmp_list;
        ಯಾವತ್ (jl) {
            ಯದಿ (jl->penv == e)
                ಭಙ್ಗ;
            jl = jl->next;
        }
        ಯದಿ (jl == ರಿಕ್ತ) {
            jl = BOUND_MALLOC (ಪರಿಮಾಣ (jmp_list_type));
            ಯದಿ (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        ಯದಿ (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ __bound_long_jump(jmp_buf env, ಪೂರ್ಣಾಙ್ಕ val, ಪೂರ್ಣಾಙ್ಕ sig, ಧ್ರುವ ವರ್ಣ *func)
{
    jmp_list_type *jl;
    ಶೂನ್ಯ *e;
    BOUND_TID_TYPE tid;

    ಯದಿ (NO_CHECKING_GET() == 0) {
        e = (ಶೂನ್ಯ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ಎಣಿಕೆ(bound_longjmp_ಎಣಿಕೆ);
        jl = jmp_list;
        ಯಾವತ್ (jl) {
            ಯದಿ (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = ರಿಕ್ತ;

                ಯಾವತ್ (cur->penv != e || cur->tid != tid) {
                    ಯದಿ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ಯದಿ (last)
                            last->next = cur->next;
                        ಅನ್ಯಥಾ
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    ಅನ್ಯಥಾ {
                        last = cur;
                        cur = cur->next;
                    }
                }
                ಪ್ರತಿ (;;) {
                    ವೃಕ್ಷ *t = ವೃಕ್ಷ_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    ಯಾವತ್ (t && (t->start < start_fp || t->start > end_fp))
                        ಯದಿ (t->start < start_fp)
                            t = t->ಬಲ;
                        ಅನ್ಯಥಾ
                            t = t->ಎಡ;
                    ಯದಿ (t == ರಿಕ್ತ)
                        ಭಙ್ಗ;
                    last = ರಿಕ್ತ;
                    cur = alloca_list;
                    ಯಾವತ್ (cur) {
                         ಯದಿ ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ಯದಿ (last)
                                 last->next = cur->next;
                             ಅನ್ಯಥಾ
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             ಭಙ್ಗ;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (ಶೂನ್ಯ *) t->start);
                    ವೃಕ್ಷ_2 = splay_delete(t->start, ವೃಕ್ಷ_2);
                }
                ಭಙ್ಗ;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#ಯದಿ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

ಶೂನ್ಯ __bound_longjmp(jmp_buf env, ಪೂರ್ಣಾಙ್ಕ val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ಯದಿ !defined(_WIN32)
ಶೂನ್ಯ __bound_siglongjmp(jmp_buf env, ಪೂರ್ಣಾಙ್ಕ val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#ಯದಿ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ತೆಗೆ
#endif

ಶೂನ್ಯ __bound_init(size_t *p, ಪೂರ್ಣಾಙ್ಕ mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    ಯದಿ (inited) {
        WAIT_SEM();
        ಗಚ್ಛ add_bounds;
    }
    inited = 1;

#ಯದಿ HAVE_TLS_FUNC
#ಯದಿ defined(_WIN32)
    no_checking_ಕೀಲಿ = TlsAlloc();
    Tls_Set_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ, &no_checking);
#ಅನ್ಯಥಾ
    pthread_key_create(&no_checking_ಕೀಲಿ, ರಿಕ್ತ);
    pthread_setspecific(no_checking_ಕೀಲಿ, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ರಿಕ್ತ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ರಿಕ್ತ;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != ರಿಕ್ತ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ರಿಕ್ತ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ರಿಕ್ತ;

    INIT_SEM ();

#ಯದಿ MALLOC_REDIR
    {
        ಶೂನ್ಯ *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(ಶೂನ್ಯ **) (&malloc_redir) = dlsym (addr, "malloc");
        ಯದಿ (malloc_redir == ರಿಕ್ತ) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(ಶೂನ್ಯ **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(ಶೂನ್ಯ **) (&calloc_redir) = dlsym (addr, "calloc");
        *(ಶೂನ್ಯ **) (&free_redir) = dlsym (addr, "free");
        *(ಶೂನ್ಯ **) (&realloc_redir) = dlsym (addr, "realloc");
        *(ಶೂನ್ಯ **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        ಯದಿ (malloc_redir == ರಿಕ್ತ || free_redir == ರಿಕ್ತ)
            bound_alloc_error ("Cannot redirect malloc/free");
#ಯದಿ HAVE_PTHREAD_CREATE
        *(ಶೂನ್ಯ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ಯದಿ (pthread_create_redir == ರಿಕ್ತ)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#ಯದಿ HAVE_SIGNAL
        *(ಶೂನ್ಯ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ಯದಿ (signal_redir == ರಿಕ್ತ)
            bound_alloc_error ("Cannot redirect signal");
#endif
#ಯದಿ HAVE_SIGACTION
        *(ಶೂನ್ಯ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ಯದಿ (sigaction_redir == ರಿಕ್ತ)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#ಯದಿ HAVE_FORK
        *(ಶೂನ್ಯ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ಯದಿ (fork_redir == ರಿಕ್ತ)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned ವರ್ಣ found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        ವರ್ಣ ಸಾಲು[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ಯದಿ (fp) {
            memset (exec, 0, ಪರಿಮಾಣ(exec));
            fread (exec, 1, ಪರಿಮಾಣ(exec) - 2, fp);
            ಯದಿ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        ಯದಿ (fp) {
            ಯಾವತ್ (fgets (ಸಾಲು, ಪರಿಮಾಣ(ಸಾಲು), fp)) {
                ಯದಿ (sscanf (ಸಾಲು, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    ಭಙ್ಗ;
                }
                ಯದಿ (strstr (ಸಾಲು,"[heap]"))
                    ಭಙ್ಗ;
            }
            fclose (fp);
        }
        ಯದಿ (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#ಯದಿ HAVE_CTYPE
#ifdef __APPLE__
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) &_DefaultRuneLocale,
                        ಪರಿಮಾಣ (_DefaultRuneLocale), ವೃಕ್ಷ_2);
#ಅನ್ಯಥಾ
    /* XXX: Does not work if locale is changed */
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) __ctype_b_loc(),
                        ಪರಿಮಾಣ (unsigned short *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) (*__ctype_b_loc() - 128),
                        384 * ಪರಿಮಾಣ (unsigned short), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) __ctype_tolower_loc(),
                        ಪರಿಮಾಣ (__int32_t *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) (*__ctype_tolower_loc() - 128),
                        384 * ಪರಿಮಾಣ (__int32_t), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) __ctype_toupper_loc(),
                        ಪರಿಮಾಣ (__int32_t *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) (*__ctype_toupper_loc() - 128),
                        384 * ಪರಿಮಾಣ (__int32_t), ವೃಕ್ಷ_2);
#endif
#endif
#ಯದಿ HAVE_ERRNO
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) (&errno), ಪರಿಮಾಣ (ಪೂರ್ಣಾಙ್ಕ), ವೃಕ್ಷ_2);
#endif

add_bounds:
    ಯದಿ (!p)
        ಗಚ್ಛ no_bounds;

    /* add all static bound check values */
    ಯಾವತ್ (p[0] != 0) {
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು(p[0], p[1], ವೃಕ್ಷ_2);
#ಯದಿ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (ಶೂನ್ಯ *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

ಶೂನ್ಯ
#ಯದಿ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **envp)
{
    __bound_init (0, -1);
    ಯದಿ (argc && argv) {
        ಪೂರ್ಣಾಙ್ಕ i;

        WAIT_SEM ();
        ಪ್ರತಿ (i = 0; i < argc; i++)
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) argv[i], strlen (argv[i]) + 1, ವೃಕ್ಷ_2);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) argv, (argc + 1) * ಪರಿಮಾಣ(ವರ್ಣ *), ವೃಕ್ಷ_2);
        POST_SEM ();
#ಯದಿ BOUND_DEBUG
        ಯದಿ (print_calls) {
            ಪ್ರತಿ (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (ಪೂರ್ಣಾಙ್ಕ)((argc + 1) * ಪರಿಮಾಣ(ವರ್ಣ *)));
        }
#endif
    }

    ಯದಿ (envp && *envp) {
        ವರ್ಣ **p = envp;

        WAIT_SEM ();
        ಯಾವತ್ (*p) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) *p, strlen (*p) + 1, ವೃಕ್ಷ_2);
            ++p;
        }
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) envp, (++p - envp) * ಪರಿಮಾಣ(ವರ್ಣ *), ವೃಕ್ಷ_2);
        POST_SEM ();
#ಯದಿ BOUND_DEBUG
        ಯದಿ (print_calls) {
            p = envp;
            ಯಾವತ್ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (ಪೂರ್ಣಾಙ್ಕ)((++p - envp) * ಪರಿಮಾಣ(ವರ್ಣ *)));
        }
#endif
    }
}

ಶೂನ್ಯ __attribute__((destructor)) __bound_exit(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ಯದಿ (inited) {
#ಯದಿ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ಯದಿ (print_heap) {
            ಬಾಹ್ಯ ಶೂನ್ಯ __libc_freeres (ಶೂನ್ಯ);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        ಯಾವತ್ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            ವೃಕ್ಷ_2 = splay_delete ((size_t) alloca_list->p, ವೃಕ್ಷ_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        ಯಾವತ್ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        ಪ್ರತಿ (i = 0; i < FREE_REUSE_SIZE; i++) {
            ಯದಿ (free_reuse_list[i]) {
                ವೃಕ್ಷ_2 = splay_delete ((size_t) free_reuse_list[i], ವೃಕ್ಷ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ಯಾವತ್ (ವೃಕ್ಷ_2) {
            ಯದಿ (print_heap && ವೃಕ್ಷ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[ವೃಕ್ಷ_2->type],
                         (unsigned long) ವೃಕ್ಷ_2->size);
            ವೃಕ್ಷ_2 = splay_delete (ವೃಕ್ಷ_2->start, ವೃಕ್ಷ_2);
        }
#ಯದಿ ವೃಕ್ಷ_REUSE
        ಯಾವತ್ (ವೃಕ್ಷ_free_list) {
            ವೃಕ್ಷ *next = ವೃಕ್ಷ_free_list->ಎಡ;
            BOUND_FREE (ವೃಕ್ಷ_free_list);
            ವೃಕ್ಷ_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#ಯದಿ HAVE_TLS_FUNC
#ಯದಿ defined(_WIN32)
        TlsFree(no_checking_ಕೀಲಿ);
#ಅನ್ಯಥಾ
        pthread_key_delete(no_checking_ಕೀಲಿ);
#endif
#endif
        inited = 0;
        ಯದಿ (print_statistic) {
#ಯದಿ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_ಎಣಿಕೆ);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_ಎಣಿಕೆ);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_ಎಣಿಕೆ);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_ಎಣಿಕೆ);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_ಎಣಿಕೆ);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_ಎಣಿಕೆ);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_ಎಣಿಕೆ);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_ಎಣಿಕೆ);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_ಎಣಿಕೆ);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_ಎಣಿಕೆ);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_ಎಣಿಕೆ);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_ಎಣಿಕೆ);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_ಎಣಿಕೆ);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_ಎಣಿಕೆ);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_ಎಣಿಕೆ);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_ಎಣಿಕೆ);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_ಎಣಿಕೆ);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_ಎಣಿಕೆ);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_ಎಣಿಕೆ);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#ಯದಿ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ಸೇರಿಸು);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

ಶೂನ್ಯ __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ಯದಿ (p) {
        WAIT_SEM ();
	ಯಾವತ್ (p[0] != 0) {
	    ವೃಕ್ಷ_2 = splay_delete(p[0], ವೃಕ್ಷ_2);
#ಯದಿ BOUND_DEBUG
            ಯದಿ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ಶೂನ್ಯ *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#ಯದಿ HAVE_PTHREAD_CREATE
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ಶೂನ್ಯ *(*start_routine) (ಶೂನ್ಯ *);
    ಶೂನ್ಯ *arg;
    sigset_t old_mask;
} bound_thread_create_type;

ಸ್ಥಿರ ಶೂನ್ಯ *bound_thread_create(ಶೂನ್ಯ *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    ಶೂನ್ಯ *retval;
#ಯದಿ HAVE_TLS_FUNC
    ಪೂರ್ಣಾಙ್ಕ *p = (ಪೂರ್ಣಾಙ್ಕ *) BOUND_MALLOC(ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
  
    ಯದಿ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ಕೀಲಿ, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, ರಿಕ್ತ);
    retval = data->start_routine(data->arg);
#ಯದಿ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ಕೀಲಿ, ರಿಕ್ತ);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    ಪ್ರತ್ಯಾಗಮ retval;
}

ಪೂರ್ಣಾಙ್ಕ pthread_create(pthread_t *thread, ಧ್ರುವ pthread_attr_t *attr,
                   ಶೂನ್ಯ *(*start_routine) (ಶೂನ್ಯ *), ಶೂನ್ಯ *arg)
{
    ಪೂರ್ಣಾಙ್ಕ retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(ಪರಿಮಾಣ(bound_thread_create_type));
    ಯದಿ (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, ರಿಕ್ತ);
    ಪ್ರತ್ಯಾಗಮ retval;
}
#endif

#ಯದಿ HAVE_SIGNAL || HAVE_SIGACTION
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ {
#ಯದಿ HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#ಯದಿ HAVE_SIGACTION
    ಶೂನ್ಯ (*sig_handler)(ಪೂರ್ಣಾಙ್ಕ);
    ಶೂನ್ಯ (*sig_sigaction)(ಪೂರ್ಣಾಙ್ಕ, siginfo_t *, ಶೂನ್ಯ *);
#endif
} bound_sig_type;

ಸ್ಥಿರ unsigned ವರ್ಣ bound_sig_used[NSIG];
ಸ್ಥಿರ bound_sig_type bound_sig_data[NSIG];
#endif

#ಯದಿ HAVE_SIGNAL
ಸ್ಥಿರ ಶೂನ್ಯ signal_handler(ಪೂರ್ಣಾಙ್ಕ sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig ಸಙ್ಕೇತ(ಪೂರ್ಣಾಙ್ಕ signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ಯದಿ (retval != SIG_ERR) {
        ಯದಿ (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        ಯದಿ (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    ಪ್ರತ್ಯಾಗಮ retval;
}
#endif

#ಯದಿ HAVE_SIGACTION
ಸ್ಥಿರ ಶೂನ್ಯ sig_handler(ಪೂರ್ಣಾಙ್ಕ sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ಸ್ಥಿರ ಶೂನ್ಯ sig_sigaction(ಪೂರ್ಣಾಙ್ಕ sig, siginfo_t *info, ಶೂನ್ಯ *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

ಪೂರ್ಣಾಙ್ಕ sigaction(ಪೂರ್ಣಾಙ್ಕ signum, ಧ್ರುವ ಸಂರಚನಾ sigaction *act, ಸಂರಚನಾ sigaction *oldact)
{
    ಪೂರ್ಣಾಙ್ಕ retval;
    ಸಂರಚನಾ sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ಯದಿ (sigaction_redir == ರಿಕ್ತ)
        __bound_init(0,-1);

    ಯದಿ (act) {
        nact = *act;
        ಯದಿ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ಅನ್ಯಥಾ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ಅನ್ಯಥಾ
        retval = sigaction_redir(signum, act, &oact);
    ಯದಿ (retval >= 0) {
        ಯದಿ (bound_sig_used[signum]) {
            ಯದಿ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            ಅನ್ಯಥಾ
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        ಯದಿ (oldact) {
            *oldact = oact;
        }
        ಯದಿ (act) {
            bound_sig_used[signum] = 1;
            ಯದಿ (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            ಅನ್ಯಥಾ
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    ಪ್ರತ್ಯಾಗಮ retval;
}
#endif

#ಯದಿ HAVE_FORK
pid_t fork(ಶೂನ್ಯ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ಯದಿ (retval == 0)
        INIT_SEM();
    ಅನ್ಯಥಾ
        POST_SEM();
    ಪ್ರತ್ಯಾಗಮ retval;
}
#endif

#ಯದಿ MALLOC_REDIR
ಶೂನ್ಯ *malloc(size_t size)
#ಅನ್ಯಥಾ
ಶೂನ್ಯ *__bound_malloc(size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller)
#endif
{
    ಶೂನ್ಯ *ptr;
    
#ಯದಿ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ಯದಿ (malloc_redir == ರಿಕ್ತ) {
        __bound_init (0, -1);
        ಯದಿ (malloc_redir == ರಿಕ್ತ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ಯದಿ (pool_index >= ಪರಿಮಾಣ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            ಪ್ರತ್ಯಾಗಮ ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    ಯದಿ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_malloc_ಎಣಿಕೆ);

        ಯದಿ (ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((size_t) ptr, size ? size : size + 1, ವೃಕ್ಷ_2);
            ಯದಿ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->start == (size_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ಪ್ರತ್ಯಾಗಮ ptr;
}

#ಯದಿ MALLOC_REDIR
ಶೂನ್ಯ *memalign(size_t align, size_t size)
#ಅನ್ಯಥಾ
ಶೂನ್ಯ *__bound_memalign(size_t align, size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller)
#endif
{
    ಶೂನ್ಯ *ptr;

#ಯದಿ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#ಅನ್ಯಥಾ
    ಯದಿ (align > 4) {
        /* XXX: handle it ? */
        ptr = ರಿಕ್ತ;
    } ಅನ್ಯಥಾ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ಯದಿ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_memalign_ಎಣಿಕೆ);

        ಯದಿ (ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t) ptr, size ? size : size + 1, ವೃಕ್ಷ_2);
            ಯದಿ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->start == (size_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ಪ್ರತ್ಯಾಗಮ ptr;
}

#ಯದಿ MALLOC_REDIR
ಶೂನ್ಯ ಮುಕ್ತ(ಶೂನ್ಯ *ptr)
#ಅನ್ಯಥಾ
ಶೂನ್ಯ __bound_free(ಶೂನ್ಯ *ptr, ಧ್ರುವ ಶೂನ್ಯ *caller)
#endif
{
    size_t addr = (size_t) ptr;
    ಶೂನ್ಯ *p;

    ಯದಿ (ptr == ರಿಕ್ತ || ವೃಕ್ಷ_2 == ರಿಕ್ತ
#ಯದಿ MALLOC_REDIR
        || ((unsigned ವರ್ಣ *) ptr >= &initial_pool[0] &&
            (unsigned ವರ್ಣ *) ptr < &initial_pool[ಪರಿಮಾಣ(initial_pool)])
#endif
        )
        ಪ್ರತ್ಯಾಗಮ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ಯದಿ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_free_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);
        ಯದಿ (ವೃಕ್ಷ_2->start == addr) {
            ಯದಿ (ವೃಕ್ಷ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ಪ್ರತ್ಯಾಗಮ;
            }
            ವೃಕ್ಷ_2->is_invalid = 1;
            memset (ptr, 0x5a, ವೃಕ್ಷ_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            ಯದಿ (p)
                ವೃಕ್ಷ_2 = splay_delete((size_t)p, ವೃಕ್ಷ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ಯದಿ MALLOC_REDIR
ಶೂನ್ಯ *realloc(ಶೂನ್ಯ *ptr, size_t size)
#ಅನ್ಯಥಾ
ಶೂನ್ಯ *__bound_realloc(ಶೂನ್ಯ *ptr, size_t size, ಧ್ರುವ ಶೂನ್ಯ *caller)
#endif
{
    ಶೂನ್ಯ *new_ptr;

    ಯದಿ (size == 0) {
#ಯದಿ MALLOC_REDIR
        ಮುಕ್ತ(ptr);
#ಅನ್ಯಥಾ
        __bound_free(ptr, caller);
#endif
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    ಯದಿ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_realloc_ಎಣಿಕೆ);

        ಯದಿ (ptr)
            ವೃಕ್ಷ_2 = splay_delete ((size_t) ptr, ವೃಕ್ಷ_2);
        ಯದಿ (new_ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((size_t) new_ptr, size ? size : size + 1, ವೃಕ್ಷ_2);
            ಯದಿ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->start == (size_t) new_ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ಪ್ರತ್ಯಾಗಮ new_ptr;
}

#ಯದಿ MALLOC_REDIR
ಶೂನ್ಯ *calloc(size_t nmemb, size_t size)
#ಅನ್ಯಥಾ
ಶೂನ್ಯ *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    ಶೂನ್ಯ *ptr;

    size *= nmemb;
#ಯದಿ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ಯದಿ (malloc_redir == ರಿಕ್ತ) {
        __bound_init (0, -1);
        ಯದಿ (malloc_redir == ರಿಕ್ತ) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ಯದಿ (pool_index >= ಪರಿಮಾಣ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            ಪ್ರತ್ಯಾಗಮ ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ಯದಿ (ptr) {
        memset (ptr, 0, size);
        ಯದಿ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ಎಣಿಕೆ(bound_calloc_ಎಣಿಕೆ);
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((size_t) ptr, size ? size : size + 1, ವೃಕ್ಷ_2);
            ಯದಿ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->start == (size_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ಪ್ರತ್ಯಾಗಮ ptr;
}

#ಯದಿ !defined(_WIN32)
ಶೂನ್ಯ *__bound_mmap (ಶೂನ್ಯ *start, size_t size, ಪೂರ್ಣಾಙ್ಕ prot,
                    ಪೂರ್ಣಾಙ್ಕ flags, ಪೂರ್ಣಾಙ್ಕ fd, off_t offset)
{
    ಶೂನ್ಯ *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    ಯದಿ (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_mmap_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t)result, size, ವೃಕ್ಷ_2);
        POST_SEM ();
    }
    ಪ್ರತ್ಯಾಗಮ result;
}

ಪೂರ್ಣಾಙ್ಕ __bound_munmap (ಶೂನ್ಯ *start, size_t size)
{
    ಪೂರ್ಣಾಙ್ಕ result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    ಯದಿ (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_munmap_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_delete ((size_t) start, ವೃಕ್ಷ_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    ಪ್ರತ್ಯಾಗಮ result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ಸ್ಥಿರ ಶೂನ್ಯ __bound_check(ಧ್ರುವ ಶೂನ್ಯ *p, size_t size, ಧ್ರುವ ವರ್ಣ *function)
{
    ಯದಿ (size != 0 && __bound_ptr_add((ಶೂನ್ಯ *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ check_overlap (ಧ್ರುವ ಶೂನ್ಯ *p1, size_t n1,
                          ಧ್ರುವ ಶೂನ್ಯ *p2, size_t n2,
                          ಧ್ರುವ ವರ್ಣ *function)
{
    ಧ್ರುವ ಶೂನ್ಯ *p1e = (ಧ್ರುವ ಶೂನ್ಯ *) ((ಧ್ರುವ ವರ್ಣ *) p1 + n1);
    ಧ್ರುವ ಶೂನ್ಯ *p2e = (ಧ್ರುವ ಶೂನ್ಯ *) ((ಧ್ರುವ ವರ್ಣ *) p2 + n2);

    ಯದಿ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        ಪ್ರತ್ಯಾಗಮ never_fatal < 0;
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ *__bound_memcpy(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_mempcy_ಎಣಿಕೆ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ಯದಿ (check_overlap(dest, n, src, n, "memcpy"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ memcpy(dest, src, n);
}

ಪೂರ್ಣಾಙ್ಕ __bound_memcmp(ಧ್ರುವ ಶೂನ್ಯ *s1, ಧ್ರುವ ಶೂನ್ಯ *s2, size_t n)
{
    ಧ್ರುವ unsigned ವರ್ಣ *u1 = (ಧ್ರುವ unsigned ವರ್ಣ *) s1;
    ಧ್ರುವ unsigned ವರ್ಣ *u2 = (ಧ್ರುವ unsigned ವರ್ಣ *) s2;
    ಪೂರ್ಣಾಙ್ಕ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memcmp_ಎಣಿಕೆ);
    ಪ್ರತಿ (;;) {
        ಯದಿ ((ssize_t) --n == -1)
            ಭಙ್ಗ;
        ಅನ್ಯಥಾ ಯದಿ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ಭಙ್ಗ;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ಧ್ರುವ ಶೂನ್ಯ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ಧ್ರುವ ಶೂನ್ಯ *)u2 - s2, "memcmp s2");
    ಪ್ರತ್ಯಾಗಮ retval;
}

ಶೂನ್ಯ *__bound_memmove(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಪ್ರತ್ಯಾಗಮ memmove(dest, src, n);
}

ಶೂನ್ಯ *__bound_memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಙ್ಕ c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memset_ಎಣಿಕೆ);
    __bound_check(s, n, "memset");
    ಪ್ರತ್ಯಾಗಮ memset(s, c, n);
}

#ಯದಿ defined(__arm__) && defined(__ARM_EABI__)
ಶೂನ್ಯ *__bound___aeabi_memcpy(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_mempcy_ಎಣಿಕೆ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ಯದಿ (check_overlap(dest, n, src, n, "memcpy"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ __aeabi_memcpy(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಪ್ರತ್ಯಾಗಮ __aeabi_memmove(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove4(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಪ್ರತ್ಯಾಗಮ __aeabi_memmove4(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove8(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಪ್ರತ್ಯಾಗಮ __aeabi_memmove8(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಙ್ಕ c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_memset_ಎಣಿಕೆ);
    __bound_check(s, n, "memset");
    ಪ್ರತ್ಯಾಗಮ __aeabi_memset(s, c, n);
}
#endif

ಪೂರ್ಣಾಙ್ಕ __bound_strlen(ಧ್ರುವ ವರ್ಣ *s)
{
    ಧ್ರುವ ವರ್ಣ *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ಎಣಿಕೆ(bound_strlen_ಎಣಿಕೆ);
    ಯಾವತ್ (*p++);
    __bound_check(s, p - s, "strlen");
    ಪ್ರತ್ಯಾಗಮ (p - s) - 1;
}

ವರ್ಣ *__bound_strcpy(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src)
{
    size_t len;
    ಧ್ರುವ ವರ್ಣ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ಎಣಿಕೆ(bound_strcpy_ಎಣಿಕೆ);
    ಯಾವತ್ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ಯದಿ (check_overlap(dest, len, src, len, "strcpy"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ strcpy (dest, src);
}

ವರ್ಣ *__bound_strncpy(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src, size_t n)
{
    size_t len = n;
    ಧ್ರುವ ವರ್ಣ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_strncpy_ಎಣಿಕೆ);
    ಯಾವತ್ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ಯದಿ (check_overlap(dest, len, src, len, "strncpy"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ strncpy(dest, src, n);
}

ಪೂರ್ಣಾಙ್ಕ __bound_strcmp(ಧ್ರುವ ವರ್ಣ *s1, ಧ್ರುವ ವರ್ಣ *s2)
{
    ಧ್ರುವ unsigned ವರ್ಣ *u1 = (ಧ್ರುವ unsigned ವರ್ಣ *) s1;
    ಧ್ರುವ unsigned ವರ್ಣ *u2 = (ಧ್ರುವ unsigned ವರ್ಣ *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ಎಣಿಕೆ(bound_strcmp_ಎಣಿಕೆ);
    ಯಾವತ್ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ಧ್ರುವ ವರ್ಣ *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ಧ್ರುವ ವರ್ಣ *)u2 - s2) + 1, "strcmp s2");
    ಪ್ರತ್ಯಾಗಮ *u1 - *u2;
}

ಪೂರ್ಣಾಙ್ಕ __bound_strncmp(ಧ್ರುವ ವರ್ಣ *s1, ಧ್ರುವ ವರ್ಣ *s2, size_t n)
{
    ಧ್ರುವ unsigned ವರ್ಣ *u1 = (ಧ್ರುವ unsigned ವರ್ಣ *) s1;
    ಧ್ರುವ unsigned ವರ್ಣ *u2 = (ಧ್ರುವ unsigned ವರ್ಣ *) s2;
    ಪೂರ್ಣಾಙ್ಕ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_strncmp_ಎಣಿಕೆ);
    ಕುರು {
        ಯದಿ ((ssize_t) --n == -1)
            ಭಙ್ಗ;
        ಅನ್ಯಥಾ ಯದಿ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ಭಙ್ಗ;
        }
        ++u2;
    } ಯಾವತ್ (*u1++);
    __bound_check(s1, (ಧ್ರುವ ವರ್ಣ *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ಧ್ರುವ ವರ್ಣ *)u2 - s2, "strncmp s2");
    ಪ್ರತ್ಯಾಗಮ retval;
}

ವರ್ಣ *__bound_strcat(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src)
{
    ವರ್ಣ *r = dest;
    ಧ್ರುವ ವರ್ಣ *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ಎಣಿಕೆ(bound_strcat_ಎಣಿಕೆ);
    ಯಾವತ್ (*dest++);
    ಯಾವತ್ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ಯದಿ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ strcat(r, s);
}

ವರ್ಣ *__bound_strncat(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src, size_t n)
{
    ವರ್ಣ *r = dest;
    ಧ್ರುವ ವರ್ಣ *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ಎಣಿಕೆ(bound_strncat_ಎಣಿಕೆ);
    ಯಾವತ್ (*dest++);
    ಯಾವತ್ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ಯದಿ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ಪ್ರತ್ಯಾಗಮ dest;
    ಪ್ರತ್ಯಾಗಮ strncat(r, s, n);
}

ವರ್ಣ *__bound_strchr(ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಧ್ರುವ unsigned ವರ್ಣ *str = (ಧ್ರುವ unsigned ವರ್ಣ *) s;
    unsigned ವರ್ಣ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ಎಣಿಕೆ(bound_strchr_ಎಣಿಕೆ);
    ಯಾವತ್ (*str) {
        ಯದಿ (*str == ch)
            ಭಙ್ಗ;
        ++str;
    }
    __bound_check(s, ((ಧ್ರುವ ವರ್ಣ *)str - s) + 1, "strchr");
    ಪ್ರತ್ಯಾಗಮ *str == ch ? (ವರ್ಣ *) str : ರಿಕ್ತ;
}

ವರ್ಣ *__bound_strrchr(ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಧ್ರುವ unsigned ವರ್ಣ *str = (ಧ್ರುವ unsigned ವರ್ಣ *) s;
    unsigned ವರ್ಣ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ಎಣಿಕೆ(bound_strrchr_ಎಣಿಕೆ);
    ಯಾವತ್ (*str++);
    __bound_check(s, (ಧ್ರುವ ವರ್ಣ *)str - s, "strrchr");
    ಯಾವತ್ (str != (ಧ್ರುವ unsigned ವರ್ಣ *)s) {
        ಯದಿ (*--str == ch)
            ಭಙ್ಗ;
    }
    __bound_check(s, (ಧ್ರುವ ವರ್ಣ *)str - s, "strrchr");
    ಪ್ರತ್ಯಾಗಮ *str == ch ? (ವರ್ಣ *) str : ರಿಕ್ತ;
}

ವರ್ಣ *__bound_strdup(ಧ್ರುವ ವರ್ಣ *s)
{
    ಧ್ರುವ ವರ್ಣ *p = s;
    ವರ್ಣ *new;

    INCR_ಎಣಿಕೆ(bound_strdup_ಎಣಿಕೆ);
    ಯಾವತ್ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    ಯದಿ (new) {
        ಯದಿ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((size_t)new, p - s, ವೃಕ್ಷ_2);
            ಯದಿ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->start == (size_t) new)
                ವೃಕ್ಷ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    ಪ್ರತ್ಯಾಗಮ new;
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

ಸ್ಥಿರ ವೃಕ್ಷ * splay (size_t addr, ವೃಕ್ಷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    ವೃಕ್ಷ N, *l, *r, *y;
    ಪೂರ್ಣಾಙ್ಕ comp;
    
    INCR_ಎಣಿಕೆ_SPLAY(bound_splay);
    ಯದಿ (t == ರಿಕ್ತ) ಪ್ರತ್ಯಾಗಮ t;
    N.ಎಡ = N.ಬಲ = ರಿಕ್ತ;
    l = r = &N;
 
    ಪ್ರತಿ (;;) {
        comp = compare(addr, t->start, t->size);
        ಯದಿ (comp < 0) {
            y = t->ಎಡ;
            ಯದಿ (y == ರಿಕ್ತ) ಭಙ್ಗ;
            ಯದಿ (compare(addr, y->start, y->size) < 0) {
                t->ಎಡ = y->ಬಲ;                    /* rotate right */
                y->ಬಲ = t;
                t = y;
                ಯದಿ (t->ಎಡ == ರಿಕ್ತ) ಭಙ್ಗ;
            }
            r->ಎಡ = t;                               /* link right */
            r = t;
            t = t->ಎಡ;
        } ಅನ್ಯಥಾ ಯದಿ (comp > 0) {
            y = t->ಬಲ;
            ಯದಿ (y == ರಿಕ್ತ) ಭಙ್ಗ;
            ಯದಿ (compare(addr, y->start, y->size) > 0) {
                t->ಬಲ = y->ಎಡ;                    /* rotate left */
                y->ಎಡ = t;
                t = y;
                ಯದಿ (t->ಬಲ == ರಿಕ್ತ) ಭಙ್ಗ;
            }
            l->ಬಲ = t;                              /* link left */
            l = t;
            t = t->ಬಲ;
        } ಅನ್ಯಥಾ {
            ಭಙ್ಗ;
        }
    }
    l->ಬಲ = t->ಎಡ;                                /* assemble */
    r->ಎಡ = t->ಬಲ;
    t->ಎಡ = N.ಬಲ;
    t->ಬಲ = N.ಎಡ;

    ಪ್ರತ್ಯಾಗಮ t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

ಸ್ಥಿರ ವೃಕ್ಷ * splay_end (size_t addr, ವೃಕ್ಷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    ವೃಕ್ಷ N, *l, *r, *y;
    ಪೂರ್ಣಾಙ್ಕ comp;
    
    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_end);
    ಯದಿ (t == ರಿಕ್ತ) ಪ್ರತ್ಯಾಗಮ t;
    N.ಎಡ = N.ಬಲ = ರಿಕ್ತ;
    l = r = &N;
 
    ಪ್ರತಿ (;;) {
        comp = compare_end(addr, t->start + t->size);
        ಯದಿ (comp < 0) {
            y = t->ಎಡ;
            ಯದಿ (y == ರಿಕ್ತ) ಭಙ್ಗ;
            ಯದಿ (compare_end(addr, y->start + y->size) < 0) {
                t->ಎಡ = y->ಬಲ;                    /* rotate right */
                y->ಬಲ = t;
                t = y;
                ಯದಿ (t->ಎಡ == ರಿಕ್ತ) ಭಙ್ಗ;
            }
            r->ಎಡ = t;                               /* link right */
            r = t;
            t = t->ಎಡ;
        } ಅನ್ಯಥಾ ಯದಿ (comp > 0) {
            y = t->ಬಲ;
            ಯದಿ (y == ರಿಕ್ತ) ಭಙ್ಗ;
            ಯದಿ (compare_end(addr, y->start + y->size) > 0) {
                t->ಬಲ = y->ಎಡ;                    /* rotate left */
                y->ಎಡ = t;
                t = y;
                ಯದಿ (t->ಬಲ == ರಿಕ್ತ) ಭಙ್ಗ;
            }
            l->ಬಲ = t;                              /* link left */
            l = t;
            t = t->ಬಲ;
        } ಅನ್ಯಥಾ {
            ಭಙ್ಗ;
        }
    }
    l->ಬಲ = t->ಎಡ;                                /* assemble */
    r->ಎಡ = t->ಬಲ;
    t->ಎಡ = N.ಬಲ;
    t->ಬಲ = N.ಎಡ;

    ಪ್ರತ್ಯಾಗಮ t;
}

ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಸೇರಿಸು(size_t addr, size_t size, ವೃಕ್ಷ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    ವೃಕ್ಷ * new;

    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_ಸೇರಿಸು);
    ಯದಿ (t != ರಿಕ್ತ) {
        t = splay(addr,t);
        ಯದಿ (compare(addr, t->start, t->size)==0) {
            ಪ್ರತ್ಯಾಗಮ t;  /* it's already there */
        }
    }
#ಯದಿ ವೃಕ್ಷ_REUSE
    ಯದಿ (ವೃಕ್ಷ_free_list) {
          new = ವೃಕ್ಷ_free_list;
          ವೃಕ್ಷ_free_list = new->ಎಡ;
    }
    ಅನ್ಯಥಾ
#endif
    {
        new = (ವೃಕ್ಷ *) BOUND_MALLOC (ಪರಿಮಾಣ (ವೃಕ್ಷ));
    }
    ಯದಿ (new == ರಿಕ್ತ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ಅನ್ಯಥಾ {
        ಯದಿ (t == ರಿಕ್ತ) {
            new->ಎಡ = new->ಬಲ = ರಿಕ್ತ;
        } ಅನ್ಯಥಾ ಯದಿ (compare(addr, t->start, t->size) < 0) {
            new->ಎಡ = t->ಎಡ;
            new->ಬಲ = t;
            t->ಎಡ = ರಿಕ್ತ;
        } ಅನ್ಯಥಾ {
            new->ಬಲ = t->ಬಲ;
            new->ಎಡ = t;
            t->ಬಲ = ರಿಕ್ತ;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ಪ್ರತ್ಯಾಗಮ new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

ಸ್ಥಿರ ವೃಕ್ಷ * splay_delete(size_t addr, ವೃಕ್ಷ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    ವೃಕ್ಷ * x;

    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_delete);
    ಯದಿ (t==ರಿಕ್ತ) ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    t = splay(addr,t);
    ಯದಿ (compare_destroy(addr, t->start) == 0) {        /* found it */
        ಯದಿ (t->ಎಡ == ರಿಕ್ತ) {
            x = t->ಬಲ;
        } ಅನ್ಯಥಾ {
            x = splay(addr, t->ಎಡ);
            x->ಬಲ = t->ಬಲ;
        }
#ಯದಿ ವೃಕ್ಷ_REUSE
        t->ಎಡ = ವೃಕ್ಷ_free_list;
        ವೃಕ್ಷ_free_list = t;
#ಅನ್ಯಥಾ
        BOUND_FREE(t);
#endif
        ಪ್ರತ್ಯಾಗಮ x;
    } ಅನ್ಯಥಾ {
        ಪ್ರತ್ಯಾಗಮ t;                                      /* It wasn't there */
    }
}

ಶೂನ್ಯ splay_printtree(ವೃಕ್ಷ * t, ಪೂರ್ಣಾಙ್ಕ d)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಯದಿ (t == ರಿಕ್ತ) ಪ್ರತ್ಯಾಗಮ;
    splay_printtree(t->ಬಲ, d+1);
    ಪ್ರತಿ (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (ಶೂನ್ಯ *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->ಎಡ, d+1);
}
