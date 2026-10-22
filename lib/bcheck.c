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
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdatomic.h>

#ਜੇ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ਅਨ੍ਤਰ੍ਭਾਵ <malloc.h>
#ਜੇ_ਅੰਤ

#ਜੇ !defined(_WIN32)
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/syscall.h>
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ "config.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_DEBUG             (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_STATISTIC         (1)

#ਜੇ BOUND_DEBUG
 #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dprintf(a...)         ਜੇ (print_calls) { bounds_loc(a); }
#ਨਹੀਂਤਾਂ
 #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dprintf(a...)
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __attribute__ 
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __i386__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FASTCALL __attribute__((regparm(3)))
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FASTCALL
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ਨਹੀਂਤਾਂ
# define DLL_EXPORT
#ਜੇ_ਅੰਤ

#ਜੇ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ਅਨ੍ਤਰ੍ਭਾਵ <sys/mman.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_MEMALIGN          (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MALLOC_REDIR           (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_PTHREAD_CREATE    (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_CTYPE             (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_ERRNO             (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGNAL            (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGACTION         (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_FORK              (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_FUNC          (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_VAR           (0)

#ਜਾਂਜੇ defined(_WIN32)

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <signal.h>
ਸਥਿਰ CRITICAL_SECTION bounds_sem;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()             LeaveCriticalSection(&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_MEMALIGN          (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MALLOC_REDIR           (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_PTHREAD_CREATE    (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_CTYPE             (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_ERRNO             (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGNAL            (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGACTION         (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_FORK              (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_FUNC          (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_VAR           (0)

#ਨਹੀਂਤਾਂ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __USE_GNU              /* get RTLD_NEXT */
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/mman.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <ctype.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <dlfcn.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <errno.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <signal.h>
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __APPLE__
#ਅਨ੍ਤਰ੍ਭਾਵ <dispatch/dispatch.h>
ਸਥਿਰ dispatch_semaphore_t bounds_sem;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()             ਜੇ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_ਸਮਾਂ_FOREVER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()             ਜੇ (use_sem) dispatch_semaphore_signal(bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()              ਜੇ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_ਸਮਾਂ_NOW)
#ਜਾਂਜੇ 0
#ਅਨ੍ਤਰ੍ਭਾਵ <semaphore.h>
ਸਥਿਰ sem_t bounds_sem;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()             sem_destroy (&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()             ਜੇ (use_sem) ਜਦੋਂ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()             ਜੇ (use_sem) sem_post (&bounds_sem)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()              ਜੇ (use_sem) ਜਦੋਂ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ਜਾਂਜੇ 0
ਸਥਿਰ pthread_mutex_t bounds_mtx;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()             pthread_mutex_init (&bounds_mtx, ਨਿਰਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()             ਜੇ (use_sem) pthread_mutex_lock (&bounds_mtx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()             ਜੇ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()              ਜੇ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ਨਹੀਂਤਾਂ
ਸਥਿਰ pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM()             ਜੇ (use_sem) pthread_spin_lock (&bounds_spin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM()             ਜੇ (use_sem) pthread_spin_unlock (&bounds_spin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_SEM()              ਜੇ (use_sem) pthread_spin_trylock (&bounds_spin)
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_MEMALIGN          (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MALLOC_REDIR           (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_PTHREAD_CREATE    (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_CTYPE             (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_ERRNO             (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGNAL            (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_SIGACTION         (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_FORK              (1)
#ਜੇ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_ਲੜੀਵਾਰ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_FUNC          (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_VAR           (0)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_FUNC          (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HAVE_TLS_VAR           (1)
#ਜੇ_ਅੰਤ
#ਜੇ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ MALLOC_REDIR
ਸਥਿਰ ਖਾਲੀ *(*malloc_redir) (ਮਾਪ_t);
ਸਥਿਰ ਖਾਲੀ *(*calloc_redir) (ਮਾਪ_t, ਮਾਪ_t);
ਸਥਿਰ ਖਾਲੀ (*free_redir) (ਖਾਲੀ *);
ਸਥਿਰ ਖਾਲੀ *(*realloc_redir) (ਖਾਲੀ *, ਮਾਪ_t);
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ pool_ਸੂਚਕਾਂਕ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ __attribute__((aligned(16))) initial_pool[256];
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_MEMALIGN
ਸਥਿਰ ਖਾਲੀ *(*memalign_redir) (ਮਾਪ_t, ਮਾਪ_t);
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_PTHREAD_CREATE
ਸਥਿਰ ਪੂਰਨ (*pthread_create_redir) (pthread_t *thread,
                                    ਅਚਲ pthread_attr_t *attr,
                                    ਖਾਲੀ *(*ਸ਼ੁਰੂ_routine)(ਖਾਲੀ *), ਖਾਲੀ *arg);
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_SIGNAL
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (*bound_sig)(ਪੂਰਨ);
ਸਥਿਰ bound_sig (*signal_redir) (ਪੂਰਨ signum, bound_sig handler);
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_SIGACTION
ਸਥਿਰ ਪੂਰਨ (*sigaction_redir) (ਪੂਰਨ signum, ਅਚਲ ਬਣਤਰ sigaction *act,
                               ਬਣਤਰ sigaction *oldact);
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_FORK
ਸਥਿਰ ਪੂਰਨ (*fork_redir) (ਖਾਲੀ);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_NONE           (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_MALLOC         (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_CALLOC         (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_REALLOC        (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_MEMALIGN       (4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_ਸੂਚਕ ((ਖਾਲੀ *)(-2))

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਰੁੱਖ_ਗੰਢ ਰੁੱਖ;
ਬਣਤਰ ਰੁੱਖ_ਗੰਢ {
    ਰੁੱਖ * ਖੱਬਾ, * ਸੱਜਾ;
    ਮਾਪ_t ਸ਼ੁਰੂ;
    ਮਾਪ_t ਮਾਪ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ type;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ is_invalid; /* true if pointers outside region are invalid */
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ alloca_list_struct {
    ਮਾਪ_t fp;
    ਖਾਲੀ *p;
    ਮਾਪ_t ਮਾਪ;
    ਬਣਤਰ alloca_list_struct *ਅਗਲਾ;
} alloca_list_type;

#ਜੇ defined(_WIN32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		DWORD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	id = GetCurrentThreadId()
#ਜਾਂਜੇ defined(__OpenBSD__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		pid_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	id = getthrid()
#ਜਾਂਜੇ defined(__FreeBSD__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		pid_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#ਜਾਂਜੇ  defined(__NetBSD__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		pid_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#ਜਾਂਜੇ defined(__linux__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		pid_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_TID_TYPE		ਪੂਰਨ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_GET_TID(id)	id = 0
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ jmp_list_struct {
    ਖਾਲੀ *penv;
    ਮਾਪ_t fp;
    ਮਾਪ_t ਸਿਰਾ_fp;
    BOUND_TID_TYPE tid;
    ਬਣਤਰ jmp_list_struct *ਅਗਲਾ;
} jmp_list_type;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_STATISTIC_SPLAY   (0)
ਸਥਿਰ ਰੁੱਖ * splay (ਮਾਪ_t addr, ਰੁੱਖ *t);
ਸਥਿਰ ਰੁੱਖ * splay_ਸਿਰਾ (ਮਾਪ_t addr, ਰੁੱਖ *t);
ਸਥਿਰ ਰੁੱਖ * splay_ਪਾਓ(ਮਾਪ_t addr, ਮਾਪ_t ਮਾਪ, ਰੁੱਖ * t);
ਸਥਿਰ ਰੁੱਖ * splay_delete(ਮਾਪ_t addr, ਰੁੱਖ *t);
ਖਾਲੀ splay_printtree(ਰੁੱਖ * t, ਪੂਰਨ d);

/* external interface */
ਖਾਲੀ __bounds_checking (ਪੂਰਨ no_check);
ਖਾਲੀ __bound_checking_lock (ਖਾਲੀ);
ਖਾਲੀ __bound_checking_unlock (ਖਾਲੀ);
ਖਾਲੀ __bound_never_fatal (ਪੂਰਨ no_check);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_add(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir1(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir2(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir4(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir8(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir12(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ * __bound_ptr_indir16(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ);
DLL_EXPORT ਖਾਲੀ FASTCALL __bound_local_new(ਖਾਲੀ *p1);
DLL_EXPORT ਖਾਲੀ FASTCALL __bound_local_delete(ਖਾਲੀ *p1);
ਖਾਲੀ __bound_init(ਮਾਪ_t *, ਪੂਰਨ);
ਖਾਲੀ __bound_main_arg(ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **envp);
ਖਾਲੀ __bound_exit(ਖਾਲੀ);
ਖਾਲੀ __bound_exit_dll(ਮਾਪ_t *);
#ਜੇ !defined(_WIN32)
ਖਾਲੀ *__bound_mmap (ਖਾਲੀ *ਸ਼ੁਰੂ, ਮਾਪ_t ਮਾਪ, ਪੂਰਨ prot, ਪੂਰਨ flags, ਪੂਰਨ fd,
                    off_t ਵਿੱਥ);
ਪੂਰਨ __bound_munmap (ਖਾਲੀ *ਸ਼ੁਰੂ, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ __bound_siglongjmp(jmp_buf env, ਪੂਰਨ val);
#ਜੇ_ਅੰਤ
DLL_EXPORT ਖਾਲੀ __bound_new_region(ਖਾਲੀ *p, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ __bound_setjmp(jmp_buf env);
DLL_EXPORT ਖਾਲੀ __bound_longjmp(jmp_buf env, ਪੂਰਨ val);
DLL_EXPORT ਖਾਲੀ *__bound_memcpy(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਪੂਰਨ __bound_memcmp(ਅਚਲ ਖਾਲੀ *s1, ਅਚਲ ਖਾਲੀ *s2, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound_memmove(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound_memset(ਖਾਲੀ *dst, ਪੂਰਨ c, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਪੂਰਨ __bound_strlen(ਅਚਲ ਅੱਖਰ *s);
DLL_EXPORT ਅੱਖਰ *__bound_strcpy(ਅੱਖਰ *dst, ਅਚਲ ਅੱਖਰ *src);
DLL_EXPORT ਅੱਖਰ *__bound_strncpy(ਅੱਖਰ *dst, ਅਚਲ ਅੱਖਰ *src, ਮਾਪ_t n);
DLL_EXPORT ਪੂਰਨ __bound_strcmp(ਅਚਲ ਅੱਖਰ *s1, ਅਚਲ ਅੱਖਰ *s2);
DLL_EXPORT ਪੂਰਨ __bound_strncmp(ਅਚਲ ਅੱਖਰ *s1, ਅਚਲ ਅੱਖਰ *s2, ਮਾਪ_t n);
DLL_EXPORT ਅੱਖਰ *__bound_strcat(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src);
DLL_EXPORT ਅੱਖਰ *__bound_strncat(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src, ਮਾਪ_t n);
DLL_EXPORT ਅੱਖਰ *__bound_strchr(ਅਚਲ ਅੱਖਰ *string, ਪੂਰਨ ch);
DLL_EXPORT ਅੱਖਰ *__bound_strrchr(ਅਚਲ ਅੱਖਰ *string, ਪੂਰਨ ch);
DLL_EXPORT ਅੱਖਰ *__bound_strdup(ਅਚਲ ਅੱਖਰ *s);

#ਜੇ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT ਖਾਲੀ *__bound___aeabi_memcpy(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound___aeabi_memmove(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound___aeabi_memmove4(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound___aeabi_memmove8(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__bound___aeabi_memset(ਖਾਲੀ *dst, ਪੂਰਨ c, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__aeabi_memcpy(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__aeabi_memmove(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__aeabi_memmove4(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__aeabi_memmove8(ਖਾਲੀ *dst, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t ਮਾਪ);
DLL_EXPORT ਖਾਲੀ *__aeabi_memset(ਖਾਲੀ *dst, ਪੂਰਨ c, ਮਾਪ_t ਮਾਪ);
#ਜੇ_ਅੰਤ

#ਜੇ MALLOC_REDIR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_MALLOC(a)          malloc_redir(a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_FREE(a)            free_redir(a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_REALLOC(a,b)       realloc_redir(a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_MALLOC(a)          ਸਮ੍ਰਿਤੀ_ਦਿਓ(a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_MEMALIGN(a,b)      memalign(a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_FREE(a)            ਮੁਕਤ(a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_REALLOC(a,b)       realloc(a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_CALLOC(a,b)        ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ(a,b)
DLL_EXPORT ਖਾਲੀ *__bound_malloc(ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller);
DLL_EXPORT ਖਾਲੀ *__bound_memalign(ਮਾਪ_t align, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller);
DLL_EXPORT ਖਾਲੀ __bound_free(ਖਾਲੀ *ptr, ਅਚਲ ਖਾਲੀ *caller);
DLL_EXPORT ਖਾਲੀ *__bound_realloc(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller);
DLL_EXPORT ਖਾਲੀ *__bound_calloc(ਮਾਪ_t nmemb, ਮਾਪ_t ਮਾਪ);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FREE_REUSE_ਮਾਪ (100)
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ free_reuse_ਸੂਚਕਾਂਕ;
ਸਥਿਰ ਖਾਲੀ *free_reuse_list[FREE_REUSE_ਮਾਪ];

ਸਥਿਰ ਰੁੱਖ *ਰੁੱਖ_2 = ਨਿਰਾ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰੁੱਖ_REUSE      (1)
#ਜੇ ਰੁੱਖ_REUSE
ਸਥਿਰ ਰੁੱਖ *ਰੁੱਖ_free_list;
#ਜੇ_ਅੰਤ
ਸਥਿਰ alloca_list_type *alloca_list;
ਸਥਿਰ jmp_list_type *jmp_list;

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ inited;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ print_warn_ptr_ਜੋੜੋ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ print_calls;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ print_ਢੇਰ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ print_statistic;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ no_strdup;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ use_sem;
ਸਥਿਰ _Atomic ਪੂਰਨ never_fatal;
#ਜੇ HAVE_TLS_FUNC
#ਜੇ defined(_WIN32)
ਸਥਿਰ ਪੂਰਨ no_checking = 0;
ਸਥਿਰ DWORD no_checking_ਕੁੰਜੀ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_CHECK() ਜੇ (!p) {                                         \
                                  p = (ਪੂਰਨ *) LocalAlloc(LPTR, ਆਕਾਰ(ਪੂਰਨ));  \
                                  ਜੇ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_ਸੈੱਟ_ਮੁੱਲ(no_checking_ਕੁੰਜੀ, p);            \
                            }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_GET()   ({ ਪੂਰਨ *p = Tls_Get_ਮੁੱਲ(no_checking_ਕੁੰਜੀ);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_ਸੈੱਟ(v)  { ਪੂਰਨ *p = Tls_Get_ਮੁੱਲ(no_checking_ਕੁੰਜੀ);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ਨਹੀਂਤਾਂ
ਸਥਿਰ ਪੂਰਨ no_checking = 0;
ਸਥਿਰ pthread_key_t no_checking_ਕੁੰਜੀ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_CHECK() ਜੇ (!p) {                                         \
                                  p = (ਪੂਰਨ *) BOUND_MALLOC(ਆਕਾਰ(ਪੂਰਨ));      \
                                  ਜੇ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ਕੁੰਜੀ, p);    \
                            }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_GET()   ({ ਪੂਰਨ *p = pthread_getspecific(no_checking_ਕੁੰਜੀ); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_ਸੈੱਟ(v)  { ਪੂਰਨ *p = pthread_getspecific(no_checking_ਕੁੰਜੀ);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ਜੇ_ਅੰਤ
#ਜਾਂਜੇ HAVE_TLS_VAR
ਸਥਿਰ __thread ਪੂਰਨ no_checking = 0;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_GET()  no_checking
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_ਸੈੱਟ(v) no_checking = v 
#ਨਹੀਂਤਾਂ
ਸਥਿਰ _Atomic ਪੂਰਨ no_checking = 0;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_GET()  no_checking
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_CHECKING_ਸੈੱਟ(v) no_checking = v 
#ਜੇ_ਅੰਤ
ਸਥਿਰ ਅੱਖਰ exec[100];

#ਜੇ BOUND_STATISTIC
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_ਜੋੜੋ_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir1_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir2_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir4_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir8_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir12_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_ptr_indir16_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_local_new_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_local_delete_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_malloc_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_calloc_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_realloc_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_free_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_memalign_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_mmap_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_munmap_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_alloca_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_setjmp_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_longjmp_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_mempcy_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_memcmp_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_memmove_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_memset_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strlen_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strcpy_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strncpy_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strcmp_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strncmp_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strcat_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strncat_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strchr_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strrchr_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_strdup_ਗਿਣਤੀ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_not_ਮਿਲਿਆ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_ਗਿਣਤੀ(x)          ++x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_ਗਿਣਤੀ(x)
#ਜੇ_ਅੰਤ
#ਜੇ BOUND_STATISTIC_SPLAY
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_splay;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_splay_ਸਿਰਾ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_splay_ਪਾਓ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ bound_splay_delete;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_ਗਿਣਤੀ_SPLAY(x)    ++x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_ਗਿਣਤੀ_SPLAY(x)
#ਜੇ_ਅੰਤ

ਪੂਰਨ tcc_backtrace(ਅਚਲ ਅੱਖਰ *fmt, ...);

/* print a bound error message */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bound_warning(...) \
    ਕਰੋ {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ਜਦੋਂ (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bound_error(...)            \
    ਕਰੋ {                            \
        bound_warning(__VA_ARGS__); \
        ਜੇ (never_fatal == 0)       \
            ਬਾਹਰ_ਨਿਕਲੋ(255);              \
    } ਜਦੋਂ (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bounds_loc(fp, ...) \
    ਕਰੋ {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ਜਦੋਂ (0)

ਸਥਿਰ ਖਾਲੀ bound_alloc_error(ਅਚਲ ਅੱਖਰ *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    ਬਾਹਰ_ਨਿਕਲੋ (1);
}

ਸਥਿਰ ਖਾਲੀ bound_not_ਮਿਲਿਆ_warning(ਅਚਲ ਅੱਖਰ *file, ਅਚਲ ਅੱਖਰ *function,
                                    ਖਾਲੀ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
ਖਾਲੀ __bounds_checking (ਪੂਰਨ no_check)
{
#ਜੇ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_ਸੈੱਟ(NO_CHECKING_GET() + no_check);
#ਨਹੀਂਤਾਂ
    atomic_fetch_add (&no_checking, no_check);
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ __bound_checking_lock(ਖਾਲੀ)
{
    WAIT_SEM ();
}

ਖਾਲੀ __bound_checking_unlock(ਖਾਲੀ)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
ਖਾਲੀ __bound_never_fatal (ਪੂਰਨ neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
ਖਾਲੀ * __bound_ptr_add(ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ)
{
    ਮਾਪ_t addr = (ਮਾਪ_t)p;

    ਜੇ (NO_CHECKING_GET())
        ਵਾਪਸ p + ਵਿੱਥ;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਵਿੱਥ);

    WAIT_SEM ();
    INCR_ਗਿਣਤੀ(bound_ptr_ਜੋੜੋ_ਗਿਣਤੀ);
    ਜੇ (ਰੁੱਖ_2) {
        addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;
        ਜੇ (addr >= ਰੁੱਖ_2->ਮਾਪ) {
            addr = (ਮਾਪ_t)p;
            ਰੁੱਖ_2 = splay (addr, ਰੁੱਖ_2);
            addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;
        }
        ਜੇ (addr >= ਰੁੱਖ_2->ਮਾਪ) {
            addr = (ਮਾਪ_t)p;
            ਰੁੱਖ_2 = splay_ਸਿਰਾ (addr, ਰੁੱਖ_2);
            addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;
        }
        ਜੇ (addr <= ਰੁੱਖ_2->ਮਾਪ) {
            ਜੇ (ਰੁੱਖ_2->is_invalid || addr + ਵਿੱਥ > ਰੁੱਖ_2->ਮਾਪ) {
                POST_SEM ();
                ਜੇ (print_warn_ptr_ਜੋੜੋ)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + ਵਿੱਥ, (ਲੰਮਾ)ਰੁੱਖ_2->ਸ਼ੁਰੂ,
                                  (ਲੰਮਾ)(ਰੁੱਖ_2->ਸ਼ੁਰੂ + ਰੁੱਖ_2->ਮਾਪ - 1));
                ਜੇ (never_fatal <= 0)
                    ਵਾਪਸ INVALID_ਸੂਚਕ; /* return an invalid pointer */
                ਵਾਪਸ p + ਵਿੱਥ;
            }
        }
        ਨਹੀਂਤਾਂ ਜੇ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ਗਿਣਤੀ(bound_not_ਮਿਲਿਆ);
            POST_SEM ();
            bound_not_ਮਿਲਿਆ_warning (__FILE__, __FUNCTION__, p);
            ਵਾਪਸ p + ਵਿੱਥ;
        }
    }
    POST_SEM ();
    ਵਾਪਸ p + ਵਿੱਥ;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOUND_PTR_INDIR(dsize)                                                 \
ਖਾਲੀ * __bound_ptr_indir ## dsize (ਖਾਲੀ *p, ਮਾਪ_t ਵਿੱਥ)                     \
{                                                                              \
    ਮਾਪ_t addr = (ਮਾਪ_t)p;                                                   \
                                                                               \
    ਜੇ (NO_CHECKING_GET())                                                     \
        ਵਾਪਸ p + ਵਿੱਥ;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਵਿੱਥ);                 \
    WAIT_SEM ();                                                               \
    INCR_ਗਿਣਤੀ(bound_ptr_indir ## dsize ## ਗਿਣਤੀ_2);                            \
    ਜੇ (ਰੁੱਖ_2) {                                                                \
        addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;                                                   \
        ਜੇ (addr >= ਰੁੱਖ_2->ਮਾਪ) {                                              \
            addr = (ਮਾਪ_t)p;                                                  \
            ਰੁੱਖ_2 = splay (addr, ਰੁੱਖ_2);                                         \
            addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;                                               \
        }                                                                      \
        ਜੇ (addr >= ਰੁੱਖ_2->ਮਾਪ) {                                              \
            addr = (ਮਾਪ_t)p;                                                  \
            ਰੁੱਖ_2 = splay_ਸਿਰਾ (addr, ਰੁੱਖ_2);                                     \
            addr -= ਰੁੱਖ_2->ਸ਼ੁਰੂ;                                               \
        }                                                                      \
        ਜੇ (addr <= ਰੁੱਖ_2->ਮਾਪ) {                                              \
            ਜੇ (ਰੁੱਖ_2->is_invalid || addr + ਵਿੱਥ + dsize > ਰੁੱਖ_2->ਮਾਪ) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + ਵਿੱਥ, dsize, (ਲੰਮਾ)ਰੁੱਖ_2->ਸ਼ੁਰੂ,            \
                              (ਲੰਮਾ)(ਰੁੱਖ_2->ਸ਼ੁਰੂ + ਰੁੱਖ_2->ਮਾਪ - 1));           \
                ਜੇ (never_fatal <= 0)                                          \
                    ਵਾਪਸ INVALID_ਸੂਚਕ; /* return an invalid pointer */    \
                ਵਾਪਸ p + ਵਿੱਥ;                                             \
            }                                                                  \
        }                                                                      \
        ਨਹੀਂਤਾਂ {                                                                 \
            INCR_ਗਿਣਤੀ(bound_not_ਮਿਲਿਆ);                                       \
            POST_SEM ();                                                       \
            bound_not_ਮਿਲਿਆ_warning (__FILE__, __FUNCTION__, p);               \
            ਵਾਪਸ p + ਵਿੱਥ;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ਵਾਪਸ p + ਵਿੱਥ;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ਜੇ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#ਹਦਾਇਤ GCC diagnostic ਧੱਕੋ
#ਹਦਾਇਤ GCC diagnostic ignored "-Wframe-address"
#ਜੇ_ਅੰਤ

/* return the frame pointer of the caller */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_CALLER_FP(fp)\
{\
    fp = (ਮਾਪ_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
ਖਾਲੀ FASTCALL __bound_local_new(ਖਾਲੀ *p1) 
{
    ਮਾਪ_t addr, fp, *p = p1;

    ਜੇ (NO_CHECKING_GET())
         ਵਾਪਸ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ਖਾਲੀ *)fp);
    WAIT_SEM ();
    ਜਦੋਂ ((addr = p[0])) {
        INCR_ਗਿਣਤੀ(bound_local_new_ਗਿਣਤੀ);
        ਰੁੱਖ_2 = splay_ਪਾਓ(addr + fp, p[1], ਰੁੱਖ_2);
        p += 2;
    }
    POST_SEM ();
#ਜੇ BOUND_DEBUG
    ਜੇ (print_calls) {
        p = p1;
        ਜਦੋਂ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (ਖਾਲੀ *) (addr + fp), (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) p[1]);
            p += 2;
        }
    }
#ਜੇ_ਅੰਤ
}

/* called when leaving a function to delete all the local regions */
ਖਾਲੀ FASTCALL __bound_local_delete(ਖਾਲੀ *p1) 
{
    ਮਾਪ_t addr, fp, *p = p1;

    ਜੇ (NO_CHECKING_GET())
         ਵਾਪਸ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ਖਾਲੀ *)fp);
    WAIT_SEM ();
    ਜਦੋਂ ((addr = p[0])) {
        INCR_ਗਿਣਤੀ(bound_local_delete_ਗਿਣਤੀ);
        ਰੁੱਖ_2 = splay_delete(addr + fp, ਰੁੱਖ_2);
        p += 2;
    }
    ਜੇ (alloca_list) {
        alloca_list_type *ਆਖਰੀ = ਨਿਰਾ;
        alloca_list_type *cur = alloca_list;

        ਕਰੋ {
            ਜੇ (cur->fp == fp) {
                ਜੇ (ਆਖਰੀ)
                    ਆਖਰੀ->ਅਗਲਾ = cur->ਅਗਲਾ;
                ਨਹੀਂਤਾਂ
                    alloca_list = cur->ਅਗਲਾ;
                ਰੁੱਖ_2 = splay_delete ((ਮਾਪ_t) cur->p, ਰੁੱਖ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = ਆਖਰੀ ? ਆਖਰੀ->ਅਗਲਾ : alloca_list;
             }
             ਨਹੀਂਤਾਂ {
                 ਆਖਰੀ = cur;
                 cur = cur->ਅਗਲਾ;
             }
        } ਜਦੋਂ (cur);
    }
    ਜੇ (jmp_list) {
        jmp_list_type *ਆਖਰੀ = ਨਿਰਾ;
        jmp_list_type *cur = jmp_list;

        ਕਰੋ {
            ਜੇ (cur->fp == fp) {
                ਜੇ (ਆਖਰੀ)
                    ਆਖਰੀ->ਅਗਲਾ = cur->ਅਗਲਾ;
                ਨਹੀਂਤਾਂ
                    jmp_list = cur->ਅਗਲਾ;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = ਆਖਰੀ ? ਆਖਰੀ->ਅਗਲਾ : jmp_list;
            }
            ਨਹੀਂਤਾਂ {
                ਆਖਰੀ = cur;
                cur = cur->ਅਗਲਾ;
            }
        } ਜਦੋਂ (cur);
    }

    POST_SEM ();
#ਜੇ BOUND_DEBUG
    ਜੇ (print_calls) {
        p = p1;
        ਜਦੋਂ ((addr = p[0])) {
            ਜੇ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ਖਾਲੀ *) (addr + fp), (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) p[1]);
            }
            p+= 2;
        }
    }
#ਜੇ_ਅੰਤ
}

/* used by alloca */
ਖਾਲੀ __bound_new_region(ਖਾਲੀ *p, ਮਾਪ_t ਮਾਪ)
{
    ਮਾਪ_t fp;
    alloca_list_type *ਆਖਰੀ;
    alloca_list_type *cur;
    alloca_list_type *new;

    ਜੇ (NO_CHECKING_GET())
        ਵਾਪਸ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (ਆਕਾਰ (alloca_list_type));
    WAIT_SEM ();
    INCR_ਗਿਣਤੀ(bound_alloca_ਗਿਣਤੀ);
    ਆਖਰੀ = ਨਿਰਾ;
    cur = alloca_list;
    ਜਦੋਂ (cur) {
#ਜੇ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        ਪੂਰਨ align = 4;
#ਜਾਂਜੇ defined(__arm__)
        ਪੂਰਨ align = 8;
#ਨਹੀਂਤਾਂ
        ਪੂਰਨ align = 16;
#ਜੇ_ਅੰਤ
        ਖਾਲੀ *cure = (ਖਾਲੀ *)((ਅੱਖਰ *)cur->p + ((cur->ਮਾਪ + align) & -align));
        ਖਾਲੀ *pe = (ਖਾਲੀ *)((ਅੱਖਰ *)p + ((ਮਾਪ + align) & -align));
        ਜੇ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ਜੇ (ਆਖਰੀ)
                ਆਖਰੀ->ਅਗਲਾ = cur->ਅਗਲਾ;
            ਨਹੀਂਤਾਂ
                alloca_list = cur->ਅਗਲਾ;
            ਰੁੱਖ_2 = splay_delete((ਮਾਪ_t)cur->p, ਰੁੱਖ_2);
            ਰੋਕੋ;
        }
        ਆਖਰੀ = cur;
        cur = cur->ਅਗਲਾ;
    }
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t)p, ਮਾਪ, ਰੁੱਖ_2);
    ਜੇ (new) {
        new->fp = fp;
        new->p = p;
        new->ਮਾਪ = ਮਾਪ;
        new->ਅਗਲਾ = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ਜੇ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

ਖਾਲੀ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    ਖਾਲੀ *e = (ਖਾਲੀ *) env;

    ਜੇ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_setjmp_ਗਿਣਤੀ);
        jl = jmp_list;
        ਜਦੋਂ (jl) {
            ਜੇ (jl->penv == e)
                ਰੋਕੋ;
            jl = jl->ਅਗਲਾ;
        }
        ਜੇ (jl == ਨਿਰਾ) {
            jl = BOUND_MALLOC (ਆਕਾਰ (jmp_list_type));
            ਜੇ (jl) {
                jl->penv = e;
                jl->ਅਗਲਾ = jmp_list;
                jmp_list = jl;
            }
        }
        ਜੇ (jl) {
            ਮਾਪ_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->ਸਿਰਾ_fp = (ਮਾਪ_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ਸਥਿਰ ਖਾਲੀ __bound_long_jump(jmp_buf env, ਪੂਰਨ val, ਪੂਰਨ sig, ਅਚਲ ਅੱਖਰ *func)
{
    jmp_list_type *jl;
    ਖਾਲੀ *e;
    BOUND_TID_TYPE tid;

    ਜੇ (NO_CHECKING_GET() == 0) {
        e = (ਖਾਲੀ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ਗਿਣਤੀ(bound_longjmp_ਗਿਣਤੀ);
        jl = jmp_list;
        ਜਦੋਂ (jl) {
            ਜੇ (jl->penv == e && jl->tid == tid) {
                ਮਾਪ_t ਸ਼ੁਰੂ_fp = (ਮਾਪ_t)__builtin_frame_address(0);
                ਮਾਪ_t ਸਿਰਾ_fp = jl->ਸਿਰਾ_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *ਆਖਰੀ = ਨਿਰਾ;

                ਜਦੋਂ (cur->penv != e || cur->tid != tid) {
                    ਜੇ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ਜੇ (ਆਖਰੀ)
                            ਆਖਰੀ->ਅਗਲਾ = cur->ਅਗਲਾ;
                        ਨਹੀਂਤਾਂ
                            jmp_list = cur->ਅਗਲਾ;
                        BOUND_FREE (cur);
                        cur = ਆਖਰੀ ? ਆਖਰੀ->ਅਗਲਾ : jmp_list;
                    }
                    ਨਹੀਂਤਾਂ {
                        ਆਖਰੀ = cur;
                        cur = cur->ਅਗਲਾ;
                    }
                }
                ਲਈ (;;) {
                    ਰੁੱਖ *t = ਰੁੱਖ_2;
                    alloca_list_type *ਆਖਰੀ;
                    alloca_list_type *cur;

                    ਜਦੋਂ (t && (t->ਸ਼ੁਰੂ < ਸ਼ੁਰੂ_fp || t->ਸ਼ੁਰੂ > ਸਿਰਾ_fp))
                        ਜੇ (t->ਸ਼ੁਰੂ < ਸ਼ੁਰੂ_fp)
                            t = t->ਸੱਜਾ;
                        ਨਹੀਂਤਾਂ
                            t = t->ਖੱਬਾ;
                    ਜੇ (t == ਨਿਰਾ)
                        ਰੋਕੋ;
                    ਆਖਰੀ = ਨਿਰਾ;
                    cur = alloca_list;
                    ਜਦੋਂ (cur) {
                         ਜੇ ((ਮਾਪ_t) cur->p == t->ਸ਼ੁਰੂ) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ਜੇ (ਆਖਰੀ)
                                 ਆਖਰੀ->ਅਗਲਾ = cur->ਅਗਲਾ;
                             ਨਹੀਂਤਾਂ
                                 alloca_list = cur->ਅਗਲਾ;
                             BOUND_FREE (cur);
                             ਰੋਕੋ;
                         }
                         ਆਖਰੀ = cur;
                         cur = cur->ਅਗਲਾ;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (ਖਾਲੀ *) t->ਸ਼ੁਰੂ);
                    ਰੁੱਖ_2 = splay_delete(t->ਸ਼ੁਰੂ, ਰੁੱਖ_2);
                }
                ਰੋਕੋ;
            }
            jl = jl->ਅਗਲਾ;
        }
        POST_SEM();
    }
#ਜੇ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#ਜੇ_ਅੰਤ
    longjmp (env, val);
}

ਖਾਲੀ __bound_longjmp(jmp_buf env, ਪੂਰਨ val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ਜੇ !defined(_WIN32)
ਖਾਲੀ __bound_siglongjmp(jmp_buf env, ਪੂਰਨ val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#ਜੇ_ਅੰਤ

#ਜੇ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ਹਦਾਇਤ GCC diagnostic ਕੱਢੋ
#ਜੇ_ਅੰਤ

ਖਾਲੀ __bound_init(ਮਾਪ_t *p, ਪੂਰਨ ਬਹੁਲਕ)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            ਬਹੁਲਕ < 0 ? "lazy" : ਬਹੁਲਕ == 0 ? "normal use" : "for -run");

    ਜੇ (inited) {
        WAIT_SEM();
        ਜਾਓ ਜੋੜੋ_bounds;
    }
    inited = 1;

#ਜੇ HAVE_TLS_FUNC
#ਜੇ defined(_WIN32)
    no_checking_ਕੁੰਜੀ = TlsAlloc();
    Tls_ਸੈੱਟ_ਮੁੱਲ(no_checking_ਕੁੰਜੀ, &no_checking);
#ਨਹੀਂਤਾਂ
    pthread_key_create(&no_checking_ਕੁੰਜੀ, ਨਿਰਾ);
    pthread_setspecific(no_checking_ਕੁੰਜੀ, &no_checking);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
    NO_CHECKING_ਸੈੱਟ(1);

    print_warn_ptr_ਜੋੜੋ = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ਨਿਰਾ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ਨਿਰਾ;
    print_ਢੇਰ = getenv ("TCC_BOUNDS_PRINT_HEAP") != ਨਿਰਾ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ਨਿਰਾ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ਨਿਰਾ;

    INIT_SEM ();

#ਜੇ MALLOC_REDIR
    {
        ਖਾਲੀ *addr = ਬਹੁਲਕ > 0 ? RTLD_DEFAULT : RTLD_ਅਗਲਾ;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(ਖਾਲੀ **) (&malloc_redir) = dlsym (addr, "malloc");
        ਜੇ (malloc_redir == ਨਿਰਾ) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(ਖਾਲੀ **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(ਖਾਲੀ **) (&calloc_redir) = dlsym (addr, "calloc");
        *(ਖਾਲੀ **) (&free_redir) = dlsym (addr, "free");
        *(ਖਾਲੀ **) (&realloc_redir) = dlsym (addr, "realloc");
        *(ਖਾਲੀ **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        ਜੇ (malloc_redir == ਨਿਰਾ || free_redir == ਨਿਰਾ)
            bound_alloc_error ("Cannot redirect malloc/free");
#ਜੇ HAVE_PTHREAD_CREATE
        *(ਖਾਲੀ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ਜੇ (pthread_create_redir == ਨਿਰਾ)
            bound_alloc_error ("Cannot redirect pthread_create");
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_SIGNAL
        *(ਖਾਲੀ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ਜੇ (signal_redir == ਨਿਰਾ)
            bound_alloc_error ("Cannot redirect signal");
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_SIGACTION
        *(ਖਾਲੀ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ਜੇ (sigaction_redir == ਨਿਰਾ)
            bound_alloc_error ("Cannot redirect sigaction");
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_FORK
        *(ਖਾਲੀ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ਜੇ (fork_redir == ਨਿਰਾ)
            bound_alloc_error ("Cannot redirect fork");
#ਜੇ_ਅੰਤ
    }
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __linux__
    {
        FILE *fp;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਮਿਲਿਆ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਸ਼ੁਰੂ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਸਿਰਾ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ad =
            (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) __builtin_return_address(0);
        ਅੱਖਰ ਸਤਰ[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ਜੇ (fp) {
            memset (exec, 0, ਆਕਾਰ(exec));
            fread (exec, 1, ਆਕਾਰ(exec) - 2, fp);
            ਜੇ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        ਮਿਲਿਆ = 0;
        fp = fopen ("/proc/self/maps", "r");
        ਜੇ (fp) {
            ਜਦੋਂ (fgets (ਸਤਰ, ਆਕਾਰ(ਸਤਰ), fp)) {
                ਜੇ (ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ (ਸਤਰ, "%lx-%lx", &ਸ਼ੁਰੂ, &ਸਿਰਾ) == 2 &&
                            ad >= ਸ਼ੁਰੂ && ad < ਸਿਰਾ) {
                    ਮਿਲਿਆ = 1;
                    ਰੋਕੋ;
                }
                ਜੇ (ਲੜੀ_ਖੋਜ (ਸਤਰ,"[heap]"))
                    ਰੋਕੋ;
            }
            fclose (fp);
        }
        ਜੇ (ਮਿਲਿਆ == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#ਜੇ_ਅੰਤ

    WAIT_SEM ();

#ਜੇ HAVE_CTYPE
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __APPLE__
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) &_DefaultRuneLocale,
                        ਆਕਾਰ (_DefaultRuneLocale), ਰੁੱਖ_2);
#ਨਹੀਂਤਾਂ
    /* XXX: Does not work if locale is changed */
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) __ctype_b_loc(),
                        ਆਕਾਰ (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *), ਰੁੱਖ_2);
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) (*__ctype_b_loc() - 128),
                        384 * ਆਕਾਰ (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ), ਰੁੱਖ_2);
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) __ctype_tolower_loc(),
                        ਆਕਾਰ (__int32_t *), ਰੁੱਖ_2);
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) (*__ctype_tolower_loc() - 128),
                        384 * ਆਕਾਰ (__int32_t), ਰੁੱਖ_2);
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) __ctype_toupper_loc(),
                        ਆਕਾਰ (__int32_t *), ਰੁੱਖ_2);
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) (*__ctype_toupper_loc() - 128),
                        384 * ਆਕਾਰ (__int32_t), ਰੁੱਖ_2);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_ERRNO
    ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) (&errno), ਆਕਾਰ (ਪੂਰਨ), ਰੁੱਖ_2);
#ਜੇ_ਅੰਤ

ਜੋੜੋ_bounds:
    ਜੇ (!p)
        ਜਾਓ no_bounds;

    /* add all static bound check values */
    ਜਦੋਂ (p[0] != 0) {
        ਰੁੱਖ_2 = splay_ਪਾਓ(p[0], p[1], ਰੁੱਖ_2);
#ਜੇ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (ਖਾਲੀ *) p[0], (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) p[1]);
#ਜੇ_ਅੰਤ
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_ਸੈੱਟ(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

ਖਾਲੀ
#ਜੇ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#ਜੇ_ਅੰਤ
__bound_main_arg(ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **envp)
{
    __bound_init (0, -1);
    ਜੇ (argc && argv) {
        ਪੂਰਨ i;

        WAIT_SEM ();
        ਲਈ (i = 0; i < argc; i++)
            ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) argv[i], ਲੜੀ_ਲੰਬਾਈ (argv[i]) + 1, ਰੁੱਖ_2);
        ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) argv, (argc + 1) * ਆਕਾਰ(ਅੱਖਰ *), ਰੁੱਖ_2);
        POST_SEM ();
#ਜੇ BOUND_DEBUG
        ਜੇ (print_calls) {
            ਲਈ (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)(ਲੜੀ_ਲੰਬਾਈ (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (ਪੂਰਨ)((argc + 1) * ਆਕਾਰ(ਅੱਖਰ *)));
        }
#ਜੇ_ਅੰਤ
    }

    ਜੇ (envp && *envp) {
        ਅੱਖਰ **p = envp;

        WAIT_SEM ();
        ਜਦੋਂ (*p) {
            ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) *p, ਲੜੀ_ਲੰਬਾਈ (*p) + 1, ਰੁੱਖ_2);
            ++p;
        }
        ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) envp, (++p - envp) * ਆਕਾਰ(ਅੱਖਰ *), ਰੁੱਖ_2);
        POST_SEM ();
#ਜੇ BOUND_DEBUG
        ਜੇ (print_calls) {
            p = envp;
            ਜਦੋਂ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)(ਲੜੀ_ਲੰਬਾਈ (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (ਪੂਰਨ)((++p - envp) * ਆਕਾਰ(ਅੱਖਰ *)));
        }
#ਜੇ_ਅੰਤ
    }
}

ਖਾਲੀ __attribute__((destructor)) __bound_exit(ਖਾਲੀ)
{
    ਪੂਰਨ i;
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ * ਅਚਲ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ਜੇ (inited) {
#ਜੇ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ਜੇ (print_ਢੇਰ) {
            ਬਾਹਰੀ ਖਾਲੀ __libc_freeres (ਖਾਲੀ);
            __libc_freeres ();
        }
#ਜੇ_ਅੰਤ

        NO_CHECKING_ਸੈੱਟ(1);

        TRY_SEM ();
        ਜਦੋਂ (alloca_list) {
            alloca_list_type *ਅਗਲਾ = alloca_list->ਅਗਲਾ;

            ਰੁੱਖ_2 = splay_delete ((ਮਾਪ_t) alloca_list->p, ਰੁੱਖ_2);
            BOUND_FREE (alloca_list);
            alloca_list = ਅਗਲਾ;
        }
        ਜਦੋਂ (jmp_list) {
           jmp_list_type *ਅਗਲਾ  = jmp_list->ਅਗਲਾ;

           BOUND_FREE (jmp_list);
           jmp_list = ਅਗਲਾ;
        }
        ਲਈ (i = 0; i < FREE_REUSE_ਮਾਪ; i++) {
            ਜੇ (free_reuse_list[i]) {
                ਰੁੱਖ_2 = splay_delete ((ਮਾਪ_t) free_reuse_list[i], ਰੁੱਖ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ਜਦੋਂ (ਰੁੱਖ_2) {
            ਜੇ (print_ਢੇਰ && ਰੁੱਖ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[ਰੁੱਖ_2->type],
                         (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) ਰੁੱਖ_2->ਮਾਪ);
            ਰੁੱਖ_2 = splay_delete (ਰੁੱਖ_2->ਸ਼ੁਰੂ, ਰੁੱਖ_2);
        }
#ਜੇ ਰੁੱਖ_REUSE
        ਜਦੋਂ (ਰੁੱਖ_free_list) {
            ਰੁੱਖ *ਅਗਲਾ = ਰੁੱਖ_free_list->ਖੱਬਾ;
            BOUND_FREE (ਰੁੱਖ_free_list);
            ਰੁੱਖ_free_list = ਅਗਲਾ;
        }
#ਜੇ_ਅੰਤ
        POST_SEM ();
        EXIT_SEM ();
#ਜੇ HAVE_TLS_FUNC
#ਜੇ defined(_WIN32)
        TlsFree(no_checking_ਕੁੰਜੀ);
#ਨਹੀਂਤਾਂ
        pthread_key_delete(no_checking_ਕੁੰਜੀ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
        inited = 0;
        ਜੇ (print_statistic) {
#ਜੇ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_ਜੋੜੋ_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_ਗਿਣਤੀ);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_ਗਿਣਤੀ);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_ਗਿਣਤੀ);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_ਗਿਣਤੀ);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_ਗਿਣਤੀ);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_ਗਿਣਤੀ);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_ਗਿਣਤੀ);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_ਗਿਣਤੀ);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_ਗਿਣਤੀ);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_ਗਿਣਤੀ);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_ਗਿਣਤੀ);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_ਗਿਣਤੀ);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_ਗਿਣਤੀ);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_ਗਿਣਤੀ);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_ਗਿਣਤੀ);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_ਗਿਣਤੀ);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_ਗਿਣਤੀ);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_ਗਿਣਤੀ);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_ਗਿਣਤੀ);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_ਮਿਲਿਆ);
#ਜੇ_ਅੰਤ
#ਜੇ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_ਸਿਰਾ);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ਪਾਓ);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#ਜੇ_ਅੰਤ
        }
    }
}

ਖਾਲੀ __bound_exit_dll(ਮਾਪ_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ਜੇ (p) {
        WAIT_SEM ();
	ਜਦੋਂ (p[0] != 0) {
	    ਰੁੱਖ_2 = splay_delete(p[0], ਰੁੱਖ_2);
#ਜੇ BOUND_DEBUG
            ਜੇ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ਖਾਲੀ *) p[0], (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) p[1]);
            }
#ਜੇ_ਅੰਤ
	    p += 2;
	}
        POST_SEM ();
    }
}

#ਜੇ HAVE_PTHREAD_CREATE
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਖਾਲੀ *(*ਸ਼ੁਰੂ_routine) (ਖਾਲੀ *);
    ਖਾਲੀ *arg;
    sigset_t old_ਨਕਾਬ;
} bound_thread_create_type;

ਸਥਿਰ ਖਾਲੀ *bound_thread_create(ਖਾਲੀ *bdata)
{
    bound_thread_create_type *ਅੰਕੜੇ = (bound_thread_create_type *) bdata;
    ਖਾਲੀ *retval;
#ਜੇ HAVE_TLS_FUNC
    ਪੂਰਨ *p = (ਪੂਰਨ *) BOUND_MALLOC(ਆਕਾਰ(ਪੂਰਨ));
  
    ਜੇ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ਕੁੰਜੀ, p);
#ਜੇ_ਅੰਤ
    pthread_sigmask(SIG_SETMASK, &ਅੰਕੜੇ->old_ਨਕਾਬ, ਨਿਰਾ);
    retval = ਅੰਕੜੇ->ਸ਼ੁਰੂ_routine(ਅੰਕੜੇ->arg);
#ਜੇ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ਕੁੰਜੀ, ਨਿਰਾ);
    BOUND_FREE (p);
#ਜੇ_ਅੰਤ
    BOUND_FREE (ਅੰਕੜੇ);
    ਵਾਪਸ retval;
}

ਪੂਰਨ pthread_create(pthread_t *thread, ਅਚਲ pthread_attr_t *attr,
                   ਖਾਲੀ *(*ਸ਼ੁਰੂ_routine) (ਖਾਲੀ *), ਖਾਲੀ *arg)
{
    ਪੂਰਨ retval;
    bound_thread_create_type *ਅੰਕੜੇ;
    sigset_t ਨਕਾਬ;
    sigset_t old_ਨਕਾਬ;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&ਨਕਾਬ);
    pthread_sigmask(SIG_SETMASK, &ਨਕਾਬ, &old_ਨਕਾਬ);
    ਅੰਕੜੇ = (bound_thread_create_type *) BOUND_MALLOC(ਆਕਾਰ(bound_thread_create_type));
    ਜੇ (!ਅੰਕੜੇ) bound_alloc_error("bound_thread_create malloc");
    ਅੰਕੜੇ->ਸ਼ੁਰੂ_routine = ਸ਼ੁਰੂ_routine;
    ਅੰਕੜੇ->arg = arg;
    ਅੰਕੜੇ->old_ਨਕਾਬ = old_ਨਕਾਬ;
    retval = pthread_create_redir(thread, attr, bound_thread_create, ਅੰਕੜੇ);
    pthread_sigmask(SIG_SETMASK, &old_ਨਕਾਬ, ਨਿਰਾ);
    ਵਾਪਸ retval;
}
#ਜੇ_ਅੰਤ

#ਜੇ HAVE_SIGNAL || HAVE_SIGACTION
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ {
#ਜੇ HAVE_SIGNAL
    bound_sig signal_handler;
#ਜੇ_ਅੰਤ
#ਜੇ HAVE_SIGACTION
    ਖਾਲੀ (*sig_handler)(ਪੂਰਨ);
    ਖਾਲੀ (*sig_sigaction)(ਪੂਰਨ, siginfo_t *, ਖਾਲੀ *);
#ਜੇ_ਅੰਤ
} bound_sig_type;

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ bound_sig_ਵਰਤਿਆ[NSIG];
ਸਥਿਰ bound_sig_type bound_sig_ਅੰਕੜੇ[NSIG];
#ਜੇ_ਅੰਤ

#ਜੇ HAVE_SIGNAL
ਸਥਿਰ ਖਾਲੀ signal_handler(ਪੂਰਨ sig)
{
   __bounds_checking(1);
   bound_sig_ਅੰਕੜੇ[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig ਸੰਕੇਤ(ਪੂਰਨ signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ਜੇ (retval != SIG_ERR) {
        ਜੇ (bound_sig_ਵਰਤਿਆ[signum])
            retval = bound_sig_ਅੰਕੜੇ[signum].signal_handler;
        ਜੇ (handler) {
            bound_sig_ਵਰਤਿਆ[signum] = 1;
            bound_sig_ਅੰਕੜੇ[signum].signal_handler = handler;
        }
    }
    ਵਾਪਸ retval;
}
#ਜੇ_ਅੰਤ

#ਜੇ HAVE_SIGACTION
ਸਥਿਰ ਖਾਲੀ sig_handler(ਪੂਰਨ sig)
{
   __bounds_checking(1);
   bound_sig_ਅੰਕੜੇ[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ਸਥਿਰ ਖਾਲੀ sig_sigaction(ਪੂਰਨ sig, siginfo_t *info, ਖਾਲੀ *ucontext)
{
   __bounds_checking(1);
   bound_sig_ਅੰਕੜੇ[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

ਪੂਰਨ sigaction(ਪੂਰਨ signum, ਅਚਲ ਬਣਤਰ sigaction *act, ਬਣਤਰ sigaction *oldact)
{
    ਪੂਰਨ retval;
    ਬਣਤਰ sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ਜੇ (sigaction_redir == ਨਿਰਾ)
        __bound_init(0,-1);

    ਜੇ (act) {
        nact = *act;
        ਜੇ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ਨਹੀਂਤਾਂ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ਨਹੀਂਤਾਂ
        retval = sigaction_redir(signum, act, &oact);
    ਜੇ (retval >= 0) {
        ਜੇ (bound_sig_ਵਰਤਿਆ[signum]) {
            ਜੇ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_ਅੰਕੜੇ[signum].sig_sigaction;
            ਨਹੀਂਤਾਂ
                oact.sa_handler = bound_sig_ਅੰਕੜੇ[signum].sig_handler;
        }
        ਜੇ (oldact) {
            *oldact = oact;
        }
        ਜੇ (act) {
            bound_sig_ਵਰਤਿਆ[signum] = 1;
            ਜੇ (act->sa_flags & SA_SIGINFO)
                bound_sig_ਅੰਕੜੇ[signum].sig_sigaction = act->sa_sigaction;
            ਨਹੀਂਤਾਂ
                bound_sig_ਅੰਕੜੇ[signum].sig_handler = act->sa_handler;
        }
    }
    ਵਾਪਸ retval;
}
#ਜੇ_ਅੰਤ

#ਜੇ HAVE_FORK
pid_t fork(ਖਾਲੀ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ਜੇ (retval == 0)
        INIT_SEM();
    ਨਹੀਂਤਾਂ
        POST_SEM();
    ਵਾਪਸ retval;
}
#ਜੇ_ਅੰਤ

#ਜੇ MALLOC_REDIR
ਖਾਲੀ *ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਮਾਪ)
#ਨਹੀਂਤਾਂ
ਖਾਲੀ *__bound_malloc(ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller)
#ਜੇ_ਅੰਤ
{
    ਖਾਲੀ *ptr;
    
#ਜੇ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ਜੇ (malloc_redir == ਨਿਰਾ) {
        __bound_init (0, -1);
        ਜੇ (malloc_redir == ਨਿਰਾ) {
            ptr = &initial_pool[pool_ਸੂਚਕਾਂਕ];
            pool_ਸੂਚਕਾਂਕ = (pool_ਸੂਚਕਾਂਕ + ਮਾਪ + 15) & ~15;
            ਜੇ (pool_ਸੂਚਕਾਂਕ >= ਆਕਾਰ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
            ਵਾਪਸ ptr;
        }
    }
#ਜੇ_ਅੰਤ
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (ਮਾਪ + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
    
    ਜੇ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_malloc_ਗਿਣਤੀ);

        ਜੇ (ptr) {
            ਰੁੱਖ_2 = splay_ਪਾਓ ((ਮਾਪ_t) ptr, ਮਾਪ ? ਮਾਪ : ਮਾਪ + 1, ਰੁੱਖ_2);
            ਜੇ (ਰੁੱਖ_2 && ਰੁੱਖ_2->ਸ਼ੁਰੂ == (ਮਾਪ_t) ptr)
                ਰੁੱਖ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ਵਾਪਸ ptr;
}

#ਜੇ MALLOC_REDIR
ਖਾਲੀ *memalign(ਮਾਪ_t align, ਮਾਪ_t ਮਾਪ)
#ਨਹੀਂਤਾਂ
ਖਾਲੀ *__bound_memalign(ਮਾਪ_t align, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller)
#ਜੇ_ਅੰਤ
{
    ਖਾਲੀ *ptr;

#ਜੇ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, ਮਾਪ + 1);
#ਨਹੀਂਤਾਂ
    ਜੇ (align > 4) {
        /* XXX: handle it ? */
        ptr = ਨਿਰਾ;
    } ਨਹੀਂਤਾਂ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(ਮਾਪ + 1);
    }
#ਜੇ_ਅੰਤ
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);

    ਜੇ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_memalign_ਗਿਣਤੀ);

        ਜੇ (ptr) {
            ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t) ptr, ਮਾਪ ? ਮਾਪ : ਮਾਪ + 1, ਰੁੱਖ_2);
            ਜੇ (ਰੁੱਖ_2 && ਰੁੱਖ_2->ਸ਼ੁਰੂ == (ਮਾਪ_t) ptr)
                ਰੁੱਖ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ਵਾਪਸ ptr;
}

#ਜੇ MALLOC_REDIR
ਖਾਲੀ ਮੁਕਤ(ਖਾਲੀ *ptr)
#ਨਹੀਂਤਾਂ
ਖਾਲੀ __bound_free(ਖਾਲੀ *ptr, ਅਚਲ ਖਾਲੀ *caller)
#ਜੇ_ਅੰਤ
{
    ਮਾਪ_t addr = (ਮਾਪ_t) ptr;
    ਖਾਲੀ *p;

    ਜੇ (ptr == ਨਿਰਾ || ਰੁੱਖ_2 == ਨਿਰਾ
#ਜੇ MALLOC_REDIR
        || ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) ptr >= &initial_pool[0] &&
            (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) ptr < &initial_pool[ਆਕਾਰ(initial_pool)])
#ਜੇ_ਅੰਤ
        )
        ਵਾਪਸ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ਜੇ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_free_ਗਿਣਤੀ);
        ਰੁੱਖ_2 = splay (addr, ਰੁੱਖ_2);
        ਜੇ (ਰੁੱਖ_2->ਸ਼ੁਰੂ == addr) {
            ਜੇ (ਰੁੱਖ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ਵਾਪਸ;
            }
            ਰੁੱਖ_2->is_invalid = 1;
            memset (ptr, 0x5a, ਰੁੱਖ_2->ਮਾਪ);
            p = free_reuse_list[free_reuse_ਸੂਚਕਾਂਕ];
            free_reuse_list[free_reuse_ਸੂਚਕਾਂਕ] = ptr;
            free_reuse_ਸੂਚਕਾਂਕ = (free_reuse_ਸੂਚਕਾਂਕ + 1) % FREE_REUSE_ਮਾਪ;
            ਜੇ (p)
                ਰੁੱਖ_2 = splay_delete((ਮਾਪ_t)p, ਰੁੱਖ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ਜੇ MALLOC_REDIR
ਖਾਲੀ *realloc(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ)
#ਨਹੀਂਤਾਂ
ਖਾਲੀ *__bound_realloc(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਖਾਲੀ *caller)
#ਜੇ_ਅੰਤ
{
    ਖਾਲੀ *new_ptr;

    ਜੇ (ਮਾਪ == 0) {
#ਜੇ MALLOC_REDIR
        ਮੁਕਤ(ptr);
#ਨਹੀਂਤਾਂ
        __bound_free(ptr, caller);
#ਜੇ_ਅੰਤ
        ਵਾਪਸ ਨਿਰਾ;
    }

    new_ptr = BOUND_REALLOC (ptr, ਮਾਪ + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);

    ਜੇ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_realloc_ਗਿਣਤੀ);

        ਜੇ (ptr)
            ਰੁੱਖ_2 = splay_delete ((ਮਾਪ_t) ptr, ਰੁੱਖ_2);
        ਜੇ (new_ptr) {
            ਰੁੱਖ_2 = splay_ਪਾਓ ((ਮਾਪ_t) new_ptr, ਮਾਪ ? ਮਾਪ : ਮਾਪ + 1, ਰੁੱਖ_2);
            ਜੇ (ਰੁੱਖ_2 && ਰੁੱਖ_2->ਸ਼ੁਰੂ == (ਮਾਪ_t) new_ptr)
                ਰੁੱਖ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ਵਾਪਸ new_ptr;
}

#ਜੇ MALLOC_REDIR
ਖਾਲੀ *ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t nmemb, ਮਾਪ_t ਮਾਪ)
#ਨਹੀਂਤਾਂ
ਖਾਲੀ *__bound_calloc(ਮਾਪ_t nmemb, ਮਾਪ_t ਮਾਪ)
#ਜੇ_ਅੰਤ
{
    ਖਾਲੀ *ptr;

    ਮਾਪ *= nmemb;
#ਜੇ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ਜੇ (malloc_redir == ਨਿਰਾ) {
        __bound_init (0, -1);
        ਜੇ (malloc_redir == ਨਿਰਾ) {
            ptr = &initial_pool[pool_ਸੂਚਕਾਂਕ];
            pool_ਸੂਚਕਾਂਕ = (pool_ਸੂਚਕਾਂਕ + ਮਾਪ + 15) & ~15;
            ਜੇ (pool_ਸੂਚਕਾਂਕ >= ਆਕਾਰ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
            memset (ptr, 0, ਮਾਪ);
            ਵਾਪਸ ptr;
        }
    }
#ਜੇ_ਅੰਤ
    ptr = BOUND_MALLOC(ਮਾਪ + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);

    ਜੇ (ptr) {
        memset (ptr, 0, ਮਾਪ);
        ਜੇ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ਗਿਣਤੀ(bound_calloc_ਗਿਣਤੀ);
            ਰੁੱਖ_2 = splay_ਪਾਓ ((ਮਾਪ_t) ptr, ਮਾਪ ? ਮਾਪ : ਮਾਪ + 1, ਰੁੱਖ_2);
            ਜੇ (ਰੁੱਖ_2 && ਰੁੱਖ_2->ਸ਼ੁਰੂ == (ਮਾਪ_t) ptr)
                ਰੁੱਖ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ਵਾਪਸ ptr;
}

#ਜੇ !defined(_WIN32)
ਖਾਲੀ *__bound_mmap (ਖਾਲੀ *ਸ਼ੁਰੂ, ਮਾਪ_t ਮਾਪ, ਪੂਰਨ prot,
                    ਪੂਰਨ flags, ਪੂਰਨ fd, off_t ਵਿੱਥ)
{
    ਖਾਲੀ *ਨਤੀਜਾ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ਸ਼ੁਰੂ, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
    ਨਤੀਜਾ = mmap (ਸ਼ੁਰੂ, ਮਾਪ, prot, flags, fd, ਵਿੱਥ);
    ਜੇ (ਨਤੀਜਾ && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_mmap_ਗਿਣਤੀ);
        ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t)ਨਤੀਜਾ, ਮਾਪ, ਰੁੱਖ_2);
        POST_SEM ();
    }
    ਵਾਪਸ ਨਤੀਜਾ;
}

ਪੂਰਨ __bound_munmap (ਖਾਲੀ *ਸ਼ੁਰੂ, ਮਾਪ_t ਮਾਪ)
{
    ਪੂਰਨ ਨਤੀਜਾ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ਸ਼ੁਰੂ, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ);
    ਜੇ (ਸ਼ੁਰੂ && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ਗਿਣਤੀ(bound_munmap_ਗਿਣਤੀ);
        ਰੁੱਖ_2 = splay_delete ((ਮਾਪ_t) ਸ਼ੁਰੂ, ਰੁੱਖ_2);
        POST_SEM ();
    }
    ਨਤੀਜਾ = munmap (ਸ਼ੁਰੂ, ਮਾਪ);
    ਵਾਪਸ ਨਤੀਜਾ;
}
#ਜੇ_ਅੰਤ

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ਸਥਿਰ ਖਾਲੀ __bound_check(ਅਚਲ ਖਾਲੀ *p, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਅੱਖਰ *function)
{
    ਜੇ (ਮਾਪ != 0 && __bound_ptr_add((ਖਾਲੀ *)p, ਮਾਪ) == INVALID_ਸੂਚਕ) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ਮਾਪ, function);
    }
}

ਸਥਿਰ ਪੂਰਨ check_overlap (ਅਚਲ ਖਾਲੀ *p1, ਮਾਪ_t n1,
                          ਅਚਲ ਖਾਲੀ *p2, ਮਾਪ_t n2,
                          ਅਚਲ ਅੱਖਰ *function)
{
    ਅਚਲ ਖਾਲੀ *p1e = (ਅਚਲ ਖਾਲੀ *) ((ਅਚਲ ਅੱਖਰ *) p1 + n1);
    ਅਚਲ ਖਾਲੀ *p2e = (ਅਚਲ ਖਾਲੀ *) ((ਅਚਲ ਅੱਖਰ *) p2 + n2);

    ਜੇ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n1, p2, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n2, function);
        ਵਾਪਸ never_fatal < 0;
    }
    ਵਾਪਸ 0;
}

ਖਾਲੀ *__bound_memcpy(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_mempcy_ਗਿਣਤੀ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ਜੇ (check_overlap(dest, n, src, n, "memcpy"))
        ਵਾਪਸ dest;
    ਵਾਪਸ ਸਮ੍ਰਿਤੀ_ਨਕਲ(dest, src, n);
}

ਪੂਰਨ __bound_memcmp(ਅਚਲ ਖਾਲੀ *s1, ਅਚਲ ਖਾਲੀ *s2, ਮਾਪ_t n)
{
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u1 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s1;
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u2 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s2;
    ਪੂਰਨ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memcmp_ਗਿਣਤੀ);
    ਲਈ (;;) {
        ਜੇ ((ssize_t) --n == -1)
            ਰੋਕੋ;
        ਨਹੀਂਤਾਂ ਜੇ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ਰੋਕੋ;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ਅਚਲ ਖਾਲੀ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ਅਚਲ ਖਾਲੀ *)u2 - s2, "memcmp s2");
    ਵਾਪਸ retval;
}

ਖਾਲੀ *__bound_memmove(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memmove_ਗਿਣਤੀ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ਵਾਪਸ memmove(dest, src, n);
}

ਖਾਲੀ *__bound_memset(ਖਾਲੀ *s, ਪੂਰਨ c, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memset_ਗਿਣਤੀ);
    __bound_check(s, n, "memset");
    ਵਾਪਸ memset(s, c, n);
}

#ਜੇ defined(__arm__) && defined(__ARM_EABI__)
ਖਾਲੀ *__bound___aeabi_memcpy(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_mempcy_ਗਿਣਤੀ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ਜੇ (check_overlap(dest, n, src, n, "memcpy"))
        ਵਾਪਸ dest;
    ਵਾਪਸ __aeabi_memcpy(dest, src, n);
}

ਖਾਲੀ *__bound___aeabi_memmove(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memmove_ਗਿਣਤੀ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ਵਾਪਸ __aeabi_memmove(dest, src, n);
}

ਖਾਲੀ *__bound___aeabi_memmove4(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memmove_ਗਿਣਤੀ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ਵਾਪਸ __aeabi_memmove4(dest, src, n);
}

ਖਾਲੀ *__bound___aeabi_memmove8(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memmove_ਗਿਣਤੀ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ਵਾਪਸ __aeabi_memmove8(dest, src, n);
}

ਖਾਲੀ *__bound___aeabi_memset(ਖਾਲੀ *s, ਪੂਰਨ c, ਮਾਪ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_memset_ਗਿਣਤੀ);
    __bound_check(s, n, "memset");
    ਵਾਪਸ __aeabi_memset(s, c, n);
}
#ਜੇ_ਅੰਤ

ਪੂਰਨ __bound_strlen(ਅਚਲ ਅੱਖਰ *s)
{
    ਅਚਲ ਅੱਖਰ *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ਗਿਣਤੀ(bound_strlen_ਗਿਣਤੀ);
    ਜਦੋਂ (*p++);
    __bound_check(s, p - s, "strlen");
    ਵਾਪਸ (p - s) - 1;
}

ਅੱਖਰ *__bound_strcpy(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src)
{
    ਮਾਪ_t len;
    ਅਚਲ ਅੱਖਰ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ਗਿਣਤੀ(bound_strcpy_ਗਿਣਤੀ);
    ਜਦੋਂ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ਜੇ (check_overlap(dest, len, src, len, "strcpy"))
        ਵਾਪਸ dest;
    ਵਾਪਸ strcpy (dest, src);
}

ਅੱਖਰ *__bound_strncpy(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src, ਮਾਪ_t n)
{
    ਮਾਪ_t len = n;
    ਅਚਲ ਅੱਖਰ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_strncpy_ਗਿਣਤੀ);
    ਜਦੋਂ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ਜੇ (check_overlap(dest, len, src, len, "strncpy"))
        ਵਾਪਸ dest;
    ਵਾਪਸ strncpy(dest, src, n);
}

ਪੂਰਨ __bound_strcmp(ਅਚਲ ਅੱਖਰ *s1, ਅਚਲ ਅੱਖਰ *s2)
{
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u1 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s1;
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u2 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ਗਿਣਤੀ(bound_strcmp_ਗਿਣਤੀ);
    ਜਦੋਂ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ਅਚਲ ਅੱਖਰ *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ਅਚਲ ਅੱਖਰ *)u2 - s2) + 1, "strcmp s2");
    ਵਾਪਸ *u1 - *u2;
}

ਪੂਰਨ __bound_strncmp(ਅਚਲ ਅੱਖਰ *s1, ਅਚਲ ਅੱਖਰ *s2, ਮਾਪ_t n)
{
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u1 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s1;
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *u2 = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s2;
    ਪੂਰਨ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_strncmp_ਗਿਣਤੀ);
    ਕਰੋ {
        ਜੇ ((ssize_t) --n == -1)
            ਰੋਕੋ;
        ਨਹੀਂਤਾਂ ਜੇ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ਰੋਕੋ;
        }
        ++u2;
    } ਜਦੋਂ (*u1++);
    __bound_check(s1, (ਅਚਲ ਅੱਖਰ *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ਅਚਲ ਅੱਖਰ *)u2 - s2, "strncmp s2");
    ਵਾਪਸ retval;
}

ਅੱਖਰ *__bound_strcat(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src)
{
    ਅੱਖਰ *r = dest;
    ਅਚਲ ਅੱਖਰ *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ਗਿਣਤੀ(bound_strcat_ਗਿਣਤੀ);
    ਜਦੋਂ (*dest++);
    ਜਦੋਂ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ਜੇ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ਵਾਪਸ dest;
    ਵਾਪਸ strcat(r, s);
}

ਅੱਖਰ *__bound_strncat(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src, ਮਾਪ_t n)
{
    ਅੱਖਰ *r = dest;
    ਅਚਲ ਅੱਖਰ *s = src;
    ਮਾਪ_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)n);
    INCR_ਗਿਣਤੀ(bound_strncat_ਗਿਣਤੀ);
    ਜਦੋਂ (*dest++);
    ਜਦੋਂ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ਜੇ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ਵਾਪਸ dest;
    ਵਾਪਸ strncat(r, s, n);
}

ਅੱਖਰ *__bound_strchr(ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ c)
{
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *str = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ਗਿਣਤੀ(bound_strchr_ਗਿਣਤੀ);
    ਜਦੋਂ (*str) {
        ਜੇ (*str == ch)
            ਰੋਕੋ;
        ++str;
    }
    __bound_check(s, ((ਅਚਲ ਅੱਖਰ *)str - s) + 1, "strchr");
    ਵਾਪਸ *str == ch ? (ਅੱਖਰ *) str : ਨਿਰਾ;
}

ਅੱਖਰ *__bound_strrchr(ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ c)
{
    ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *str = (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) s;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ਗਿਣਤੀ(bound_strrchr_ਗਿਣਤੀ);
    ਜਦੋਂ (*str++);
    __bound_check(s, (ਅਚਲ ਅੱਖਰ *)str - s, "strrchr");
    ਜਦੋਂ (str != (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)s) {
        ਜੇ (*--str == ch)
            ਰੋਕੋ;
    }
    __bound_check(s, (ਅਚਲ ਅੱਖਰ *)str - s, "strrchr");
    ਵਾਪਸ *str == ch ? (ਅੱਖਰ *) str : ਨਿਰਾ;
}

ਅੱਖਰ *__bound_strdup(ਅਚਲ ਅੱਖਰ *s)
{
    ਅਚਲ ਅੱਖਰ *p = s;
    ਅੱਖਰ *new;

    INCR_ਗਿਣਤੀ(bound_strdup_ਗਿਣਤੀ);
    ਜਦੋਂ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)(p -s));
    ਜੇ (new) {
        ਜੇ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            ਰੁੱਖ_2 = splay_ਪਾਓ((ਮਾਪ_t)new, p - s, ਰੁੱਖ_2);
            ਜੇ (ਰੁੱਖ_2 && ਰੁੱਖ_2->ਸ਼ੁਰੂ == (ਮਾਪ_t) new)
                ਰੁੱਖ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        ਸਮ੍ਰਿਤੀ_ਨਕਲ (new, s, p - s);
    }
    ਵਾਪਸ new;
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ compare(ਸ਼ੁਰੂ,tstart,tsize) (ਸ਼ੁਰੂ < tstart ? -1 : \
                                     ਸ਼ੁਰੂ >= tstart+tsize  ? 1 : 0)

ਸਥਿਰ ਰੁੱਖ * splay (ਮਾਪ_t addr, ਰੁੱਖ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    ਰੁੱਖ N, *l, *r, *y;
    ਪੂਰਨ comp;
    
    INCR_ਗਿਣਤੀ_SPLAY(bound_splay);
    ਜੇ (t == ਨਿਰਾ) ਵਾਪਸ t;
    N.ਖੱਬਾ = N.ਸੱਜਾ = ਨਿਰਾ;
    l = r = &N;
 
    ਲਈ (;;) {
        comp = compare(addr, t->ਸ਼ੁਰੂ, t->ਮਾਪ);
        ਜੇ (comp < 0) {
            y = t->ਖੱਬਾ;
            ਜੇ (y == ਨਿਰਾ) ਰੋਕੋ;
            ਜੇ (compare(addr, y->ਸ਼ੁਰੂ, y->ਮਾਪ) < 0) {
                t->ਖੱਬਾ = y->ਸੱਜਾ;                    /* rotate right */
                y->ਸੱਜਾ = t;
                t = y;
                ਜੇ (t->ਖੱਬਾ == ਨਿਰਾ) ਰੋਕੋ;
            }
            r->ਖੱਬਾ = t;                               /* link right */
            r = t;
            t = t->ਖੱਬਾ;
        } ਨਹੀਂਤਾਂ ਜੇ (comp > 0) {
            y = t->ਸੱਜਾ;
            ਜੇ (y == ਨਿਰਾ) ਰੋਕੋ;
            ਜੇ (compare(addr, y->ਸ਼ੁਰੂ, y->ਮਾਪ) > 0) {
                t->ਸੱਜਾ = y->ਖੱਬਾ;                    /* rotate left */
                y->ਖੱਬਾ = t;
                t = y;
                ਜੇ (t->ਸੱਜਾ == ਨਿਰਾ) ਰੋਕੋ;
            }
            l->ਸੱਜਾ = t;                              /* link left */
            l = t;
            t = t->ਸੱਜਾ;
        } ਨਹੀਂਤਾਂ {
            ਰੋਕੋ;
        }
    }
    l->ਸੱਜਾ = t->ਖੱਬਾ;                                /* assemble */
    r->ਖੱਬਾ = t->ਸੱਜਾ;
    t->ਖੱਬਾ = N.ਸੱਜਾ;
    t->ਸੱਜਾ = N.ਖੱਬਾ;

    ਵਾਪਸ t;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ compare_ਸਿਰਾ(ਸ਼ੁਰੂ,tend) (ਸ਼ੁਰੂ < tend ? -1 : \
                                 ਸ਼ੁਰੂ > tend  ? 1 : 0)

ਸਥਿਰ ਰੁੱਖ * splay_ਸਿਰਾ (ਮਾਪ_t addr, ਰੁੱਖ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    ਰੁੱਖ N, *l, *r, *y;
    ਪੂਰਨ comp;
    
    INCR_ਗਿਣਤੀ_SPLAY(bound_splay_ਸਿਰਾ);
    ਜੇ (t == ਨਿਰਾ) ਵਾਪਸ t;
    N.ਖੱਬਾ = N.ਸੱਜਾ = ਨਿਰਾ;
    l = r = &N;
 
    ਲਈ (;;) {
        comp = compare_ਸਿਰਾ(addr, t->ਸ਼ੁਰੂ + t->ਮਾਪ);
        ਜੇ (comp < 0) {
            y = t->ਖੱਬਾ;
            ਜੇ (y == ਨਿਰਾ) ਰੋਕੋ;
            ਜੇ (compare_ਸਿਰਾ(addr, y->ਸ਼ੁਰੂ + y->ਮਾਪ) < 0) {
                t->ਖੱਬਾ = y->ਸੱਜਾ;                    /* rotate right */
                y->ਸੱਜਾ = t;
                t = y;
                ਜੇ (t->ਖੱਬਾ == ਨਿਰਾ) ਰੋਕੋ;
            }
            r->ਖੱਬਾ = t;                               /* link right */
            r = t;
            t = t->ਖੱਬਾ;
        } ਨਹੀਂਤਾਂ ਜੇ (comp > 0) {
            y = t->ਸੱਜਾ;
            ਜੇ (y == ਨਿਰਾ) ਰੋਕੋ;
            ਜੇ (compare_ਸਿਰਾ(addr, y->ਸ਼ੁਰੂ + y->ਮਾਪ) > 0) {
                t->ਸੱਜਾ = y->ਖੱਬਾ;                    /* rotate left */
                y->ਖੱਬਾ = t;
                t = y;
                ਜੇ (t->ਸੱਜਾ == ਨਿਰਾ) ਰੋਕੋ;
            }
            l->ਸੱਜਾ = t;                              /* link left */
            l = t;
            t = t->ਸੱਜਾ;
        } ਨਹੀਂਤਾਂ {
            ਰੋਕੋ;
        }
    }
    l->ਸੱਜਾ = t->ਖੱਬਾ;                                /* assemble */
    r->ਖੱਬਾ = t->ਸੱਜਾ;
    t->ਖੱਬਾ = N.ਸੱਜਾ;
    t->ਸੱਜਾ = N.ਖੱਬਾ;

    ਵਾਪਸ t;
}

ਸਥਿਰ ਰੁੱਖ * splay_ਪਾਓ(ਮਾਪ_t addr, ਮਾਪ_t ਮਾਪ, ਰੁੱਖ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    ਰੁੱਖ * new;

    INCR_ਗਿਣਤੀ_SPLAY(bound_splay_ਪਾਓ);
    ਜੇ (t != ਨਿਰਾ) {
        t = splay(addr,t);
        ਜੇ (compare(addr, t->ਸ਼ੁਰੂ, t->ਮਾਪ)==0) {
            ਵਾਪਸ t;  /* it's already there */
        }
    }
#ਜੇ ਰੁੱਖ_REUSE
    ਜੇ (ਰੁੱਖ_free_list) {
          new = ਰੁੱਖ_free_list;
          ਰੁੱਖ_free_list = new->ਖੱਬਾ;
    }
    ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    {
        new = (ਰੁੱਖ *) BOUND_MALLOC (ਆਕਾਰ (ਰੁੱਖ));
    }
    ਜੇ (new == ਨਿਰਾ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ਨਹੀਂਤਾਂ {
        ਜੇ (t == ਨਿਰਾ) {
            new->ਖੱਬਾ = new->ਸੱਜਾ = ਨਿਰਾ;
        } ਨਹੀਂਤਾਂ ਜੇ (compare(addr, t->ਸ਼ੁਰੂ, t->ਮਾਪ) < 0) {
            new->ਖੱਬਾ = t->ਖੱਬਾ;
            new->ਸੱਜਾ = t;
            t->ਖੱਬਾ = ਨਿਰਾ;
        } ਨਹੀਂਤਾਂ {
            new->ਸੱਜਾ = t->ਸੱਜਾ;
            new->ਖੱਬਾ = t;
            t->ਸੱਜਾ = ਨਿਰਾ;
        }
        new->ਸ਼ੁਰੂ = addr;
        new->ਮਾਪ = ਮਾਪ;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ਵਾਪਸ new;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ compare_destroy(ਸ਼ੁਰੂ,tstart) (ਸ਼ੁਰੂ < tstart ? -1 : \
                                       ਸ਼ੁਰੂ > tstart  ? 1 : 0)

ਸਥਿਰ ਰੁੱਖ * splay_delete(ਮਾਪ_t addr, ਰੁੱਖ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    ਰੁੱਖ * x;

    INCR_ਗਿਣਤੀ_SPLAY(bound_splay_delete);
    ਜੇ (t==ਨਿਰਾ) ਵਾਪਸ ਨਿਰਾ;
    t = splay(addr,t);
    ਜੇ (compare_destroy(addr, t->ਸ਼ੁਰੂ) == 0) {        /* found it */
        ਜੇ (t->ਖੱਬਾ == ਨਿਰਾ) {
            x = t->ਸੱਜਾ;
        } ਨਹੀਂਤਾਂ {
            x = splay(addr, t->ਖੱਬਾ);
            x->ਸੱਜਾ = t->ਸੱਜਾ;
        }
#ਜੇ ਰੁੱਖ_REUSE
        t->ਖੱਬਾ = ਰੁੱਖ_free_list;
        ਰੁੱਖ_free_list = t;
#ਨਹੀਂਤਾਂ
        BOUND_FREE(t);
#ਜੇ_ਅੰਤ
        ਵਾਪਸ x;
    } ਨਹੀਂਤਾਂ {
        ਵਾਪਸ t;                                      /* It wasn't there */
    }
}

ਖਾਲੀ splay_printtree(ਰੁੱਖ * t, ਪੂਰਨ d)
{
    ਪੂਰਨ i;
    ਜੇ (t == ਨਿਰਾ) ਵਾਪਸ;
    splay_printtree(t->ਸੱਜਾ, d+1);
    ਲਈ (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (ਖਾਲੀ *) t->ਸ਼ੁਰੂ, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) t->ਮਾਪ,
            (ਬਿਨਾਨਿਸ਼ਾਨੀ)t->type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)t->is_invalid);
    splay_printtree(t->ਖੱਬਾ, d+1);
}
