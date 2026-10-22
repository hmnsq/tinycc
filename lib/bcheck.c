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

#ಆದರೆ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ಅನ್ತರ್ಭಾವ <malloc.h>
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(_WIN32)
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <sys/syscall.h>
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ "config.h"

#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_DEBUG             (1)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_STATISTIC         (1)

#ಆದರೆ BOUND_DEBUG
 #ವ್ಯಾಖ್ಯಾನಿಸು dprintf(a...)         ಆದರೆ (print_calls) { bounds_loc(a); }
#ಇಲ್ಲದಿದ್ದರೆ
 #ವ್ಯಾಖ್ಯಾನಿಸು dprintf(a...)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __attribute__ 
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __i386__
#ವ್ಯಾಖ್ಯಾನಿಸು FASTCALL __attribute__((regparm(3)))
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು FASTCALL
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ಇಲ್ಲದಿದ್ದರೆ
# define DLL_EXPORT
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ಅನ್ತರ್ಭಾವ <sys/mman.h>
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_MEMALIGN          (0)
#ವ್ಯಾಖ್ಯಾನಿಸು MALLOC_REDIR           (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_PTHREAD_CREATE    (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_CTYPE             (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_ERRNO             (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGNAL            (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGACTION         (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_FORK              (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_FUNC          (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_VAR           (0)

#ಅಥವಾಆದರೆ defined(_WIN32)

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
ಸ್ಥಿರ CRITICAL_SECTION bounds_sem;
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()             LeaveCriticalSection(&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_MEMALIGN          (0)
#ವ್ಯಾಖ್ಯಾನಿಸು MALLOC_REDIR           (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_PTHREAD_CREATE    (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_CTYPE             (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_ERRNO             (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGNAL            (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGACTION         (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_FORK              (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_FUNC          (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_VAR           (0)

#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು __USE_GNU              /* get RTLD_NEXT */
#ಅನ್ತರ್ಭಾವ <sys/mman.h>
#ಅನ್ತರ್ಭಾವ <ctype.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <dlfcn.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __APPLE__
#ಅನ್ತರ್ಭಾವ <dispatch/dispatch.h>
ಸ್ಥಿರ dispatch_semaphore_t bounds_sem;
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()             ಆದರೆ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_ಸಮಯ_FOREVER)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()             ಆದರೆ (use_sem) dispatch_semaphore_signal(bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()              ಆದರೆ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_ಸಮಯ_NOW)
#ಅಥವಾಆದರೆ 0
#ಅನ್ತರ್ಭಾವ <semaphore.h>
ಸ್ಥಿರ sem_t bounds_sem;
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()             sem_destroy (&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()             ಆದರೆ (use_sem) ಆಗ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()             ಆದರೆ (use_sem) sem_post (&bounds_sem)
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()              ಆದರೆ (use_sem) ಆಗ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ಅಥವಾಆದರೆ 0
ಸ್ಥಿರ pthread_mutex_t bounds_mtx;
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()             pthread_mutex_init (&bounds_mtx, ಖಾಲಿ)
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()             ಆದರೆ (use_sem) pthread_mutex_lock (&bounds_mtx)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()             ಆದರೆ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()              ಆದರೆ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#ವ್ಯಾಖ್ಯಾನಿಸು INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM()             ಆದರೆ (use_sem) pthread_spin_lock (&bounds_spin)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM()             ಆದರೆ (use_sem) pthread_spin_unlock (&bounds_spin)
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_SEM()              ಆದರೆ (use_sem) pthread_spin_trylock (&bounds_spin)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_MEMALIGN          (1)
#ವ್ಯಾಖ್ಯಾನಿಸು MALLOC_REDIR           (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_PTHREAD_CREATE    (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_CTYPE             (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_ERRNO             (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGNAL            (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_SIGACTION         (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_FORK              (1)
#ಆದರೆ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_ಸತತ)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_FUNC          (1)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_VAR           (0)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_FUNC          (0)
#ವ್ಯಾಖ್ಯಾನಿಸು HAVE_TLS_VAR           (1)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ MALLOC_REDIR
ಸ್ಥಿರ ಶೂನ್ಯ *(*malloc_redir) (ಗಾತ್ರ_t);
ಸ್ಥಿರ ಶೂನ್ಯ *(*calloc_redir) (ಗಾತ್ರ_t, ಗಾತ್ರ_t);
ಸ್ಥಿರ ಶೂನ್ಯ (*free_redir) (ಶೂನ್ಯ *);
ಸ್ಥಿರ ಶೂನ್ಯ *(*realloc_redir) (ಶೂನ್ಯ *, ಗಾತ್ರ_t);
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ pool_ಸೂಚ್ಯಂಕ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ __attribute__((aligned(16))) initial_pool[256];
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_MEMALIGN
ಸ್ಥಿರ ಶೂನ್ಯ *(*memalign_redir) (ಗಾತ್ರ_t, ಗಾತ್ರ_t);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_PTHREAD_CREATE
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*pthread_create_redir) (pthread_t *thread,
                                    ಸ್ಥಿರಾಂಕ pthread_attr_t *attr,
                                    ಶೂನ್ಯ *(*ಆರಂಭ_routine)(ಶೂನ್ಯ *), ಶೂನ್ಯ *arg);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_SIGNAL
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (*bound_sig)(ಪೂರ್ಣಾಂಕ);
ಸ್ಥಿರ bound_sig (*signal_redir) (ಪೂರ್ಣಾಂಕ signum, bound_sig handler);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_SIGACTION
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*sigaction_redir) (ಪೂರ್ಣಾಂಕ signum, ಸ್ಥಿರಾಂಕ ರಚನೆ sigaction *act,
                               ರಚನೆ sigaction *oldact);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_FORK
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*fork_redir) (ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_NONE           (0)
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_MALLOC         (1)
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_CALLOC         (2)
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_REALLOC        (3)
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_MEMALIGN       (4)
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_ಸೂಚಕ ((ಶೂನ್ಯ *)(-2))

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ವೃಕ್ಷ_ಗಂಟು ವೃಕ್ಷ;
ರಚನೆ ವೃಕ್ಷ_ಗಂಟು {
    ವೃಕ್ಷ * ಎಡ, * ಬಲ;
    ಗಾತ್ರ_t ಆರಂಭ;
    ಗಾತ್ರ_t ಗಾತ್ರ_2;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ type;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ is_invalid; /* true if pointers outside region are invalid */
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ alloca_list_struct {
    ಗಾತ್ರ_t fp;
    ಶೂನ್ಯ *p;
    ಗಾತ್ರ_t ಗಾತ್ರ_2;
    ರಚನೆ alloca_list_struct *ಮುಂದಿನ;
} alloca_list_type;

#ಆದರೆ defined(_WIN32)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		DWORD
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	id = GetCurrentThreadId()
#ಅಥವಾಆದರೆ defined(__OpenBSD__)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		pid_t
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	id = getthrid()
#ಅಥವಾಆದರೆ defined(__FreeBSD__)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		pid_t
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#ಅಥವಾಆದರೆ  defined(__NetBSD__)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		pid_t
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#ಅಥವಾಆದರೆ defined(__linux__)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		pid_t
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_TID_TYPE		ಪೂರ್ಣಾಂಕ
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_GET_TID(id)	id = 0
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ jmp_list_struct {
    ಶೂನ್ಯ *penv;
    ಗಾತ್ರ_t fp;
    ಗಾತ್ರ_t ಕೊನೆ_fp;
    BOUND_TID_TYPE tid;
    ರಚನೆ jmp_list_struct *ಮುಂದಿನ;
} jmp_list_type;

#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_STATISTIC_SPLAY   (0)
ಸ್ಥಿರ ವೃಕ್ಷ * splay (ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಕೊನೆ (ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಸೇರಿಸು(ಗಾತ್ರ_t addr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ವೃಕ್ಷ * t);
ಸ್ಥಿರ ವೃಕ್ಷ * splay_delete(ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t);
ಶೂನ್ಯ splay_printtree(ವೃಕ್ಷ * t, ಪೂರ್ಣಾಂಕ d);

/* external interface */
ಶೂನ್ಯ __bounds_checking (ಪೂರ್ಣಾಂಕ no_check);
ಶೂನ್ಯ __bound_checking_lock (ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_checking_unlock (ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_never_fatal (ಪೂರ್ಣಾಂಕ no_check);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_add(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir1(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir2(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir4(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir8(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir12(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ * __bound_ptr_indir16(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ);
DLL_EXPORT ಶೂನ್ಯ FASTCALL __bound_local_new(ಶೂನ್ಯ *p1);
DLL_EXPORT ಶೂನ್ಯ FASTCALL __bound_local_delete(ಶೂನ್ಯ *p1);
ಶೂನ್ಯ __bound_init(ಗಾತ್ರ_t *, ಪೂರ್ಣಾಂಕ);
ಶೂನ್ಯ __bound_main_arg(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **envp);
ಶೂನ್ಯ __bound_exit(ಶೂನ್ಯ);
ಶೂನ್ಯ __bound_exit_dll(ಗಾತ್ರ_t *);
#ಆದರೆ !defined(_WIN32)
ಶೂನ್ಯ *__bound_mmap (ಶೂನ್ಯ *ಆರಂಭ, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ prot, ಪೂರ್ಣಾಂಕ flags, ಪೂರ್ಣಾಂಕ fd,
                    off_t ಸ್ಥಾನಾಂತರ);
ಪೂರ್ಣಾಂಕ __bound_munmap (ಶೂನ್ಯ *ಆರಂಭ, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ __bound_siglongjmp(jmp_buf env, ಪೂರ್ಣಾಂಕ val);
#ಆದರೆ_ಅಂತ್ಯ
DLL_EXPORT ಶೂನ್ಯ __bound_new_region(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ __bound_setjmp(jmp_buf env);
DLL_EXPORT ಶೂನ್ಯ __bound_longjmp(jmp_buf env, ಪೂರ್ಣಾಂಕ val);
DLL_EXPORT ಶೂನ್ಯ *__bound_memcpy(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಪೂರ್ಣಾಂಕ __bound_memcmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *s1, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *s2, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound_memmove(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಪೂರ್ಣಾಂಕ __bound_strlen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
DLL_EXPORT ಅಕ್ಷರ *__bound_strcpy(ಅಕ್ಷರ *dst, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src);
DLL_EXPORT ಅಕ್ಷರ *__bound_strncpy(ಅಕ್ಷರ *dst, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src, ಗಾತ್ರ_t n);
DLL_EXPORT ಪೂರ್ಣಾಂಕ __bound_strcmp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s2);
DLL_EXPORT ಪೂರ್ಣಾಂಕ __bound_strncmp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s2, ಗಾತ್ರ_t n);
DLL_EXPORT ಅಕ್ಷರ *__bound_strcat(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src);
DLL_EXPORT ಅಕ್ಷರ *__bound_strncat(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src, ಗಾತ್ರ_t n);
DLL_EXPORT ಅಕ್ಷರ *__bound_strchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *string, ಪೂರ್ಣಾಂಕ ch);
DLL_EXPORT ಅಕ್ಷರ *__bound_strrchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *string, ಪೂರ್ಣಾಂಕ ch);
DLL_EXPORT ಅಕ್ಷರ *__bound_strdup(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);

#ಆದರೆ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memcpy(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove4(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memmove8(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__bound___aeabi_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memcpy(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove4(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memmove8(ಶೂನ್ಯ *dst, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t ಗಾತ್ರ_2);
DLL_EXPORT ಶೂನ್ಯ *__aeabi_memset(ಶೂನ್ಯ *dst, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t ಗಾತ್ರ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ MALLOC_REDIR
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_MALLOC(a)          malloc_redir(a)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_FREE(a)            free_redir(a)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_REALLOC(a,b)       realloc_redir(a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_MALLOC(a)          ಸ್ಮರಣೆ_ಕೊಡು(a)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_MEMALIGN(a,b)      memalign(a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_FREE(a)            ಬಿಡುಗಡೆ(a)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_REALLOC(a,b)       realloc(a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_CALLOC(a,b)        ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು(a,b)
DLL_EXPORT ಶೂನ್ಯ *__bound_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_memalign(ಗಾತ್ರ_t align, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ __bound_free(ಶೂನ್ಯ *ptr, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_realloc(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller);
DLL_EXPORT ಶೂನ್ಯ *__bound_calloc(ಗಾತ್ರ_t nmemb, ಗಾತ್ರ_t ಗಾತ್ರ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು FREE_REUSE_ಗಾತ್ರ (100)
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ free_reuse_ಸೂಚ್ಯಂಕ;
ಸ್ಥಿರ ಶೂನ್ಯ *free_reuse_list[FREE_REUSE_ಗಾತ್ರ];

ಸ್ಥಿರ ವೃಕ್ಷ *ವೃಕ್ಷ_2 = ಖಾಲಿ;
#ವ್ಯಾಖ್ಯಾನಿಸು ವೃಕ್ಷ_REUSE      (1)
#ಆದರೆ ವೃಕ್ಷ_REUSE
ಸ್ಥಿರ ವೃಕ್ಷ *ವೃಕ್ಷ_free_list;
#ಆದರೆ_ಅಂತ್ಯ
ಸ್ಥಿರ alloca_list_type *alloca_list;
ಸ್ಥಿರ jmp_list_type *jmp_list;

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ inited;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ print_warn_ptr_ಕೂಡಿಸು;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ print_calls;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ print_ರಾಶಿ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ print_statistic;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ no_strdup;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ use_sem;
ಸ್ಥಿರ _Atomic ಪೂರ್ಣಾಂಕ never_fatal;
#ಆದರೆ HAVE_TLS_FUNC
#ಆದರೆ defined(_WIN32)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ no_checking = 0;
ಸ್ಥಿರ DWORD no_checking_ಕೀಲಿ;
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_CHECK() ಆದರೆ (!p) {                                         \
                                  p = (ಪೂರ್ಣಾಂಕ *) LocalAlloc(LPTR, ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));  \
                                  ಆದರೆ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_ಗಣ_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ, p);            \
                            }
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_GET()   ({ ಪೂರ್ಣಾಂಕ *p = Tls_Get_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_ಗಣ(v)  { ಪೂರ್ಣಾಂಕ *p = Tls_Get_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ no_checking = 0;
ಸ್ಥಿರ pthread_key_t no_checking_ಕೀಲಿ;
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_CHECK() ಆದರೆ (!p) {                                         \
                                  p = (ಪೂರ್ಣಾಂಕ *) BOUND_MALLOC(ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));      \
                                  ಆದರೆ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ಕೀಲಿ, p);    \
                            }
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_GET()   ({ ಪೂರ್ಣಾಂಕ *p = pthread_getspecific(no_checking_ಕೀಲಿ); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_ಗಣ(v)  { ಪೂರ್ಣಾಂಕ *p = pthread_getspecific(no_checking_ಕೀಲಿ);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ಆದರೆ_ಅಂತ್ಯ
#ಅಥವಾಆದರೆ HAVE_TLS_VAR
ಸ್ಥಿರ __thread ಪೂರ್ಣಾಂಕ no_checking = 0;
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_GET()  no_checking
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_ಗಣ(v) no_checking = v 
#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ _Atomic ಪೂರ್ಣಾಂಕ no_checking = 0;
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_GET()  no_checking
#ವ್ಯಾಖ್ಯಾನಿಸು NO_CHECKING_ಗಣ(v) no_checking = v 
#ಆದರೆ_ಅಂತ್ಯ
ಸ್ಥಿರ ಅಕ್ಷರ exec[100];

#ಆದರೆ BOUND_STATISTIC
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_ಕೂಡಿಸು_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir1_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir2_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir4_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir8_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir12_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_ptr_indir16_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_local_new_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_local_delete_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_malloc_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_calloc_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_realloc_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_free_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_memalign_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_mmap_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_munmap_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_alloca_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_setjmp_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_longjmp_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_mempcy_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_memcmp_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_memmove_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_memset_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strlen_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strcpy_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strncpy_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strcmp_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strncmp_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strcat_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strncat_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strchr_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strrchr_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_strdup_ಎಣಿಕೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_not_ಸಿಕ್ಕಿತು;
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_ಎಣಿಕೆ(x)          ++x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_ಎಣಿಕೆ(x)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ BOUND_STATISTIC_SPLAY
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_splay;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_splay_ಕೊನೆ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_splay_ಸೇರಿಸು;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ bound_splay_delete;
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_ಎಣಿಕೆ_SPLAY(x)    ++x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_ಎಣಿಕೆ_SPLAY(x)
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ tcc_backtrace(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...);

/* print a bound error message */
#ವ್ಯಾಖ್ಯಾನಿಸು bound_warning(...) \
    ಮಾಡು {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ಆಗ (0)

#ವ್ಯಾಖ್ಯಾನಿಸು bound_error(...)            \
    ಮಾಡು {                            \
        bound_warning(__VA_ARGS__); \
        ಆದರೆ (never_fatal == 0)       \
            ನಿರ್ಗಮಿಸು(255);              \
    } ಆಗ (0)

#ವ್ಯಾಖ್ಯಾನಿಸು bounds_loc(fp, ...) \
    ಮಾಡು {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ಆಗ (0)

ಸ್ಥಿರ ಶೂನ್ಯ bound_alloc_error(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    ನಿರ್ಗಮಿಸು (1);
}

ಸ್ಥಿರ ಶೂನ್ಯ bound_not_ಸಿಕ್ಕಿತು_warning(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *function,
                                    ಶೂನ್ಯ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
ಶೂನ್ಯ __bounds_checking (ಪೂರ್ಣಾಂಕ no_check)
{
#ಆದರೆ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_ಗಣ(NO_CHECKING_GET() + no_check);
#ಇಲ್ಲದಿದ್ದರೆ
    atomic_fetch_add (&no_checking, no_check);
#ಆದರೆ_ಅಂತ್ಯ
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
ಶೂನ್ಯ __bound_never_fatal (ಪೂರ್ಣಾಂಕ neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
ಶೂನ್ಯ * __bound_ptr_add(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ)
{
    ಗಾತ್ರ_t addr = (ಗಾತ್ರ_t)p;

    ಆದರೆ (NO_CHECKING_GET())
        ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಸ್ಥಾನಾಂತರ);

    WAIT_SEM ();
    INCR_ಎಣಿಕೆ(bound_ptr_ಕೂಡಿಸು_ಎಣಿಕೆ);
    ಆದರೆ (ವೃಕ್ಷ_2) {
        addr -= ವೃಕ್ಷ_2->ಆರಂಭ;
        ಆದರೆ (addr >= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {
            addr = (ಗಾತ್ರ_t)p;
            ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);
            addr -= ವೃಕ್ಷ_2->ಆರಂಭ;
        }
        ಆದರೆ (addr >= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {
            addr = (ಗಾತ್ರ_t)p;
            ವೃಕ್ಷ_2 = splay_ಕೊನೆ (addr, ವೃಕ್ಷ_2);
            addr -= ವೃಕ್ಷ_2->ಆರಂಭ;
        }
        ಆದರೆ (addr <= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {
            ಆದರೆ (ವೃಕ್ಷ_2->is_invalid || addr + ಸ್ಥಾನಾಂತರ > ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {
                POST_SEM ();
                ಆದರೆ (print_warn_ptr_ಕೂಡಿಸು)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + ಸ್ಥಾನಾಂತರ, (ದೀರ್ಘ)ವೃಕ್ಷ_2->ಆರಂಭ,
                                  (ದೀರ್ಘ)(ವೃಕ್ಷ_2->ಆರಂಭ + ವೃಕ್ಷ_2->ಗಾತ್ರ_2 - 1));
                ಆದರೆ (never_fatal <= 0)
                    ಹಿಂತಿರುಗಿ INVALID_ಸೂಚಕ; /* return an invalid pointer */
                ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;
            }
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ಎಣಿಕೆ(bound_not_ಸಿಕ್ಕಿತು);
            POST_SEM ();
            bound_not_ಸಿಕ್ಕಿತು_warning (__FILE__, __FUNCTION__, p);
            ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;
        }
    }
    POST_SEM ();
    ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#ವ್ಯಾಖ್ಯಾನಿಸು BOUND_PTR_INDIR(dsize)                                                 \
ಶೂನ್ಯ * __bound_ptr_indir ## dsize (ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ)                     \
{                                                                              \
    ಗಾತ್ರ_t addr = (ಗಾತ್ರ_t)p;                                                   \
                                                                               \
    ಆದರೆ (NO_CHECKING_GET())                                                     \
        ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಸ್ಥಾನಾಂತರ);                 \
    WAIT_SEM ();                                                               \
    INCR_ಎಣಿಕೆ(bound_ptr_indir ## dsize ## ಎಣಿಕೆ_2);                            \
    ಆದರೆ (ವೃಕ್ಷ_2) {                                                                \
        addr -= ವೃಕ್ಷ_2->ಆರಂಭ;                                                   \
        ಆದರೆ (addr >= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {                                              \
            addr = (ಗಾತ್ರ_t)p;                                                  \
            ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);                                         \
            addr -= ವೃಕ್ಷ_2->ಆರಂಭ;                                               \
        }                                                                      \
        ಆದರೆ (addr >= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {                                              \
            addr = (ಗಾತ್ರ_t)p;                                                  \
            ವೃಕ್ಷ_2 = splay_ಕೊನೆ (addr, ವೃಕ್ಷ_2);                                     \
            addr -= ವೃಕ್ಷ_2->ಆರಂಭ;                                               \
        }                                                                      \
        ಆದರೆ (addr <= ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {                                              \
            ಆದರೆ (ವೃಕ್ಷ_2->is_invalid || addr + ಸ್ಥಾನಾಂತರ + dsize > ವೃಕ್ಷ_2->ಗಾತ್ರ_2) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + ಸ್ಥಾನಾಂತರ, dsize, (ದೀರ್ಘ)ವೃಕ್ಷ_2->ಆರಂಭ,            \
                              (ದೀರ್ಘ)(ವೃಕ್ಷ_2->ಆರಂಭ + ವೃಕ್ಷ_2->ಗಾತ್ರ_2 - 1));           \
                ಆದರೆ (never_fatal <= 0)                                          \
                    ಹಿಂತಿರುಗಿ INVALID_ಸೂಚಕ; /* return an invalid pointer */    \
                ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;                                             \
            }                                                                  \
        }                                                                      \
        ಇಲ್ಲದಿದ್ದರೆ {                                                                 \
            INCR_ಎಣಿಕೆ(bound_not_ಸಿಕ್ಕಿತು);                                       \
            POST_SEM ();                                                       \
            bound_not_ಸಿಕ್ಕಿತು_warning (__FILE__, __FUNCTION__, p);               \
            ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ಹಿಂತಿರುಗಿ p + ಸ್ಥಾನಾಂತರ;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ಆದರೆ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#ಸೂಚನೆ GCC diagnostic ತಳ್ಳು
#ಸೂಚನೆ GCC diagnostic ignored "-Wframe-address"
#ಆದರೆ_ಅಂತ್ಯ

/* return the frame pointer of the caller */
#ವ್ಯಾಖ್ಯಾನಿಸು GET_CALLER_FP(fp)\
{\
    fp = (ಗಾತ್ರ_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
ಶೂನ್ಯ FASTCALL __bound_local_new(ಶೂನ್ಯ *p1) 
{
    ಗಾತ್ರ_t addr, fp, *p = p1;

    ಆದರೆ (NO_CHECKING_GET())
         ಹಿಂತಿರುಗಿ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ಶೂನ್ಯ *)fp);
    WAIT_SEM ();
    ಆಗ ((addr = p[0])) {
        INCR_ಎಣಿಕೆ(bound_local_new_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು(addr + fp, p[1], ವೃಕ್ಷ_2);
        p += 2;
    }
    POST_SEM ();
#ಆದರೆ BOUND_DEBUG
    ಆದರೆ (print_calls) {
        p = p1;
        ಆಗ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (ಶೂನ್ಯ *) (addr + fp), (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) p[1]);
            p += 2;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
}

/* called when leaving a function to delete all the local regions */
ಶೂನ್ಯ FASTCALL __bound_local_delete(ಶೂನ್ಯ *p1) 
{
    ಗಾತ್ರ_t addr, fp, *p = p1;

    ಆದರೆ (NO_CHECKING_GET())
         ಹಿಂತಿರುಗಿ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ಶೂನ್ಯ *)fp);
    WAIT_SEM ();
    ಆಗ ((addr = p[0])) {
        INCR_ಎಣಿಕೆ(bound_local_delete_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_delete(addr + fp, ವೃಕ್ಷ_2);
        p += 2;
    }
    ಆದರೆ (alloca_list) {
        alloca_list_type *ಕೊನೆಯ = ಖಾಲಿ;
        alloca_list_type *cur = alloca_list;

        ಮಾಡು {
            ಆದರೆ (cur->fp == fp) {
                ಆದರೆ (ಕೊನೆಯ)
                    ಕೊನೆಯ->ಮುಂದಿನ = cur->ಮುಂದಿನ;
                ಇಲ್ಲದಿದ್ದರೆ
                    alloca_list = cur->ಮುಂದಿನ;
                ವೃಕ್ಷ_2 = splay_delete ((ಗಾತ್ರ_t) cur->p, ವೃಕ್ಷ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = ಕೊನೆಯ ? ಕೊನೆಯ->ಮುಂದಿನ : alloca_list;
             }
             ಇಲ್ಲದಿದ್ದರೆ {
                 ಕೊನೆಯ = cur;
                 cur = cur->ಮುಂದಿನ;
             }
        } ಆಗ (cur);
    }
    ಆದರೆ (jmp_list) {
        jmp_list_type *ಕೊನೆಯ = ಖಾಲಿ;
        jmp_list_type *cur = jmp_list;

        ಮಾಡು {
            ಆದರೆ (cur->fp == fp) {
                ಆದರೆ (ಕೊನೆಯ)
                    ಕೊನೆಯ->ಮುಂದಿನ = cur->ಮುಂದಿನ;
                ಇಲ್ಲದಿದ್ದರೆ
                    jmp_list = cur->ಮುಂದಿನ;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = ಕೊನೆಯ ? ಕೊನೆಯ->ಮುಂದಿನ : jmp_list;
            }
            ಇಲ್ಲದಿದ್ದರೆ {
                ಕೊನೆಯ = cur;
                cur = cur->ಮುಂದಿನ;
            }
        } ಆಗ (cur);
    }

    POST_SEM ();
#ಆದರೆ BOUND_DEBUG
    ಆದರೆ (print_calls) {
        p = p1;
        ಆಗ ((addr = p[0])) {
            ಆದರೆ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ಶೂನ್ಯ *) (addr + fp), (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) p[1]);
            }
            p+= 2;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
}

/* used by alloca */
ಶೂನ್ಯ __bound_new_region(ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಗಾತ್ರ_2)
{
    ಗಾತ್ರ_t fp;
    alloca_list_type *ಕೊನೆಯ;
    alloca_list_type *cur;
    alloca_list_type *new;

    ಆದರೆ (NO_CHECKING_GET())
        ಹಿಂತಿರುಗಿ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (ಗಾತ್ರ (alloca_list_type));
    WAIT_SEM ();
    INCR_ಎಣಿಕೆ(bound_alloca_ಎಣಿಕೆ);
    ಕೊನೆಯ = ಖಾಲಿ;
    cur = alloca_list;
    ಆಗ (cur) {
#ಆದರೆ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        ಪೂರ್ಣಾಂಕ align = 4;
#ಅಥವಾಆದರೆ defined(__arm__)
        ಪೂರ್ಣಾಂಕ align = 8;
#ಇಲ್ಲದಿದ್ದರೆ
        ಪೂರ್ಣಾಂಕ align = 16;
#ಆದರೆ_ಅಂತ್ಯ
        ಶೂನ್ಯ *cure = (ಶೂನ್ಯ *)((ಅಕ್ಷರ *)cur->p + ((cur->ಗಾತ್ರ_2 + align) & -align));
        ಶೂನ್ಯ *pe = (ಶೂನ್ಯ *)((ಅಕ್ಷರ *)p + ((ಗಾತ್ರ_2 + align) & -align));
        ಆದರೆ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ಆದರೆ (ಕೊನೆಯ)
                ಕೊನೆಯ->ಮುಂದಿನ = cur->ಮುಂದಿನ;
            ಇಲ್ಲದಿದ್ದರೆ
                alloca_list = cur->ಮುಂದಿನ;
            ವೃಕ್ಷ_2 = splay_delete((ಗಾತ್ರ_t)cur->p, ವೃಕ್ಷ_2);
            ನಿಲ್ಲಿಸು;
        }
        ಕೊನೆಯ = cur;
        cur = cur->ಮುಂದಿನ;
    }
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t)p, ಗಾತ್ರ_2, ವೃಕ್ಷ_2);
    ಆದರೆ (new) {
        new->fp = fp;
        new->p = p;
        new->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
        new->ಮುಂದಿನ = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ಆದರೆ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

ಶೂನ್ಯ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    ಶೂನ್ಯ *e = (ಶೂನ್ಯ *) env;

    ಆದರೆ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_setjmp_ಎಣಿಕೆ);
        jl = jmp_list;
        ಆಗ (jl) {
            ಆದರೆ (jl->penv == e)
                ನಿಲ್ಲಿಸು;
            jl = jl->ಮುಂದಿನ;
        }
        ಆದರೆ (jl == ಖಾಲಿ) {
            jl = BOUND_MALLOC (ಗಾತ್ರ (jmp_list_type));
            ಆದರೆ (jl) {
                jl->penv = e;
                jl->ಮುಂದಿನ = jmp_list;
                jmp_list = jl;
            }
        }
        ಆದರೆ (jl) {
            ಗಾತ್ರ_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->ಕೊನೆ_fp = (ಗಾತ್ರ_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ __bound_long_jump(jmp_buf env, ಪೂರ್ಣಾಂಕ val, ಪೂರ್ಣಾಂಕ sig, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *func)
{
    jmp_list_type *jl;
    ಶೂನ್ಯ *e;
    BOUND_TID_TYPE tid;

    ಆದರೆ (NO_CHECKING_GET() == 0) {
        e = (ಶೂನ್ಯ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ಎಣಿಕೆ(bound_longjmp_ಎಣಿಕೆ);
        jl = jmp_list;
        ಆಗ (jl) {
            ಆದರೆ (jl->penv == e && jl->tid == tid) {
                ಗಾತ್ರ_t ಆರಂಭ_fp = (ಗಾತ್ರ_t)__builtin_frame_address(0);
                ಗಾತ್ರ_t ಕೊನೆ_fp = jl->ಕೊನೆ_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *ಕೊನೆಯ = ಖಾಲಿ;

                ಆಗ (cur->penv != e || cur->tid != tid) {
                    ಆದರೆ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ಆದರೆ (ಕೊನೆಯ)
                            ಕೊನೆಯ->ಮುಂದಿನ = cur->ಮುಂದಿನ;
                        ಇಲ್ಲದಿದ್ದರೆ
                            jmp_list = cur->ಮುಂದಿನ;
                        BOUND_FREE (cur);
                        cur = ಕೊನೆಯ ? ಕೊನೆಯ->ಮುಂದಿನ : jmp_list;
                    }
                    ಇಲ್ಲದಿದ್ದರೆ {
                        ಕೊನೆಯ = cur;
                        cur = cur->ಮುಂದಿನ;
                    }
                }
                ಗಾಗಿ (;;) {
                    ವೃಕ್ಷ *t = ವೃಕ್ಷ_2;
                    alloca_list_type *ಕೊನೆಯ;
                    alloca_list_type *cur;

                    ಆಗ (t && (t->ಆರಂಭ < ಆರಂಭ_fp || t->ಆರಂಭ > ಕೊನೆ_fp))
                        ಆದರೆ (t->ಆರಂಭ < ಆರಂಭ_fp)
                            t = t->ಬಲ;
                        ಇಲ್ಲದಿದ್ದರೆ
                            t = t->ಎಡ;
                    ಆದರೆ (t == ಖಾಲಿ)
                        ನಿಲ್ಲಿಸು;
                    ಕೊನೆಯ = ಖಾಲಿ;
                    cur = alloca_list;
                    ಆಗ (cur) {
                         ಆದರೆ ((ಗಾತ್ರ_t) cur->p == t->ಆರಂಭ) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ಆದರೆ (ಕೊನೆಯ)
                                 ಕೊನೆಯ->ಮುಂದಿನ = cur->ಮುಂದಿನ;
                             ಇಲ್ಲದಿದ್ದರೆ
                                 alloca_list = cur->ಮುಂದಿನ;
                             BOUND_FREE (cur);
                             ನಿಲ್ಲಿಸು;
                         }
                         ಕೊನೆಯ = cur;
                         cur = cur->ಮುಂದಿನ;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (ಶೂನ್ಯ *) t->ಆರಂಭ);
                    ವೃಕ್ಷ_2 = splay_delete(t->ಆರಂಭ, ವೃಕ್ಷ_2);
                }
                ನಿಲ್ಲಿಸು;
            }
            jl = jl->ಮುಂದಿನ;
        }
        POST_SEM();
    }
#ಆದರೆ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#ಆದರೆ_ಅಂತ್ಯ
    longjmp (env, val);
}

ಶೂನ್ಯ __bound_longjmp(jmp_buf env, ಪೂರ್ಣಾಂಕ val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ಆದರೆ !defined(_WIN32)
ಶೂನ್ಯ __bound_siglongjmp(jmp_buf env, ಪೂರ್ಣಾಂಕ val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ಸೂಚನೆ GCC diagnostic ತೆಗೆ
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ __bound_init(ಗಾತ್ರ_t *p, ಪೂರ್ಣಾಂಕ ಬಹುಲಕ)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            ಬಹುಲಕ < 0 ? "lazy" : ಬಹುಲಕ == 0 ? "normal use" : "for -run");

    ಆದರೆ (inited) {
        WAIT_SEM();
        ಹೋಗು ಕೂಡಿಸು_bounds;
    }
    inited = 1;

#ಆದರೆ HAVE_TLS_FUNC
#ಆದರೆ defined(_WIN32)
    no_checking_ಕೀಲಿ = TlsAlloc();
    Tls_ಗಣ_ಮೌಲ್ಯ(no_checking_ಕೀಲಿ, &no_checking);
#ಇಲ್ಲದಿದ್ದರೆ
    pthread_key_create(&no_checking_ಕೀಲಿ, ಖಾಲಿ);
    pthread_setspecific(no_checking_ಕೀಲಿ, &no_checking);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
    NO_CHECKING_ಗಣ(1);

    print_warn_ptr_ಕೂಡಿಸು = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ಖಾಲಿ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ಖಾಲಿ;
    print_ರಾಶಿ = getenv ("TCC_BOUNDS_PRINT_HEAP") != ಖಾಲಿ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ಖಾಲಿ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ಖಾಲಿ;

    INIT_SEM ();

#ಆದರೆ MALLOC_REDIR
    {
        ಶೂನ್ಯ *addr = ಬಹುಲಕ > 0 ? RTLD_DEFAULT : RTLD_ಮುಂದಿನ;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(ಶೂನ್ಯ **) (&malloc_redir) = dlsym (addr, "malloc");
        ಆದರೆ (malloc_redir == ಖಾಲಿ) {
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
        ಆದರೆ (malloc_redir == ಖಾಲಿ || free_redir == ಖಾಲಿ)
            bound_alloc_error ("Cannot redirect malloc/free");
#ಆದರೆ HAVE_PTHREAD_CREATE
        *(ಶೂನ್ಯ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ಆದರೆ (pthread_create_redir == ಖಾಲಿ)
            bound_alloc_error ("Cannot redirect pthread_create");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_SIGNAL
        *(ಶೂನ್ಯ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ಆದರೆ (signal_redir == ಖಾಲಿ)
            bound_alloc_error ("Cannot redirect signal");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_SIGACTION
        *(ಶೂನ್ಯ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ಆದರೆ (sigaction_redir == ಖಾಲಿ)
            bound_alloc_error ("Cannot redirect sigaction");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_FORK
        *(ಶೂನ್ಯ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ಆದರೆ (fork_redir == ಖಾಲಿ)
            bound_alloc_error ("Cannot redirect fork");
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __linux__
    {
        FILE *fp;
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸಿಕ್ಕಿತು;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಆರಂಭ;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಕೊನೆ;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ad =
            (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) __builtin_return_address(0);
        ಅಕ್ಷರ ಸಾಲು[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ಆದರೆ (fp) {
            memset (exec, 0, ಗಾತ್ರ(exec));
            fread (exec, 1, ಗಾತ್ರ(exec) - 2, fp);
            ಆದರೆ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        ಸಿಕ್ಕಿತು = 0;
        fp = fopen ("/proc/self/maps", "r");
        ಆದರೆ (fp) {
            ಆಗ (fgets (ಸಾಲು, ಗಾತ್ರ(ಸಾಲು), fp)) {
                ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಓದು (ಸಾಲು, "%lx-%lx", &ಆರಂಭ, &ಕೊನೆ) == 2 &&
                            ad >= ಆರಂಭ && ad < ಕೊನೆ) {
                    ಸಿಕ್ಕಿತು = 1;
                    ನಿಲ್ಲಿಸು;
                }
                ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು (ಸಾಲು,"[heap]"))
                    ನಿಲ್ಲಿಸು;
            }
            fclose (fp);
        }
        ಆದರೆ (ಸಿಕ್ಕಿತು == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ

    WAIT_SEM ();

#ಆದರೆ HAVE_CTYPE
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __APPLE__
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) &_DefaultRuneLocale,
                        ಗಾತ್ರ (_DefaultRuneLocale), ವೃಕ್ಷ_2);
#ಇಲ್ಲದಿದ್ದರೆ
    /* XXX: Does not work if locale is changed */
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) __ctype_b_loc(),
                        ಗಾತ್ರ (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) (*__ctype_b_loc() - 128),
                        384 * ಗಾತ್ರ (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) __ctype_tolower_loc(),
                        ಗಾತ್ರ (__int32_t *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) (*__ctype_tolower_loc() - 128),
                        384 * ಗಾತ್ರ (__int32_t), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) __ctype_toupper_loc(),
                        ಗಾತ್ರ (__int32_t *), ವೃಕ್ಷ_2);
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) (*__ctype_toupper_loc() - 128),
                        384 * ಗಾತ್ರ (__int32_t), ವೃಕ್ಷ_2);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_ERRNO
    ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) (&errno), ಗಾತ್ರ (ಪೂರ್ಣಾಂಕ), ವೃಕ್ಷ_2);
#ಆದರೆ_ಅಂತ್ಯ

ಕೂಡಿಸು_bounds:
    ಆದರೆ (!p)
        ಹೋಗು no_bounds;

    /* add all static bound check values */
    ಆಗ (p[0] != 0) {
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು(p[0], p[1], ವೃಕ್ಷ_2);
#ಆದರೆ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (ಶೂನ್ಯ *) p[0], (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) p[1]);
#ಆದರೆ_ಅಂತ್ಯ
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_ಗಣ(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

ಶೂನ್ಯ
#ಆದರೆ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#ಆದರೆ_ಅಂತ್ಯ
__bound_main_arg(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **envp)
{
    __bound_init (0, -1);
    ಆದರೆ (argc && argv) {
        ಪೂರ್ಣಾಂಕ i;

        WAIT_SEM ();
        ಗಾಗಿ (i = 0; i < argc; i++)
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) argv[i], ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (argv[i]) + 1, ವೃಕ್ಷ_2);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) argv, (argc + 1) * ಗಾತ್ರ(ಅಕ್ಷರ *), ವೃಕ್ಷ_2);
        POST_SEM ();
#ಆದರೆ BOUND_DEBUG
        ಆದರೆ (print_calls) {
            ಗಾಗಿ (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (ಪೂರ್ಣಾಂಕ)((argc + 1) * ಗಾತ್ರ(ಅಕ್ಷರ *)));
        }
#ಆದರೆ_ಅಂತ್ಯ
    }

    ಆದರೆ (envp && *envp) {
        ಅಕ್ಷರ **p = envp;

        WAIT_SEM ();
        ಆಗ (*p) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) *p, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (*p) + 1, ವೃಕ್ಷ_2);
            ++p;
        }
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) envp, (++p - envp) * ಗಾತ್ರ(ಅಕ್ಷರ *), ವೃಕ್ಷ_2);
        POST_SEM ();
#ಆದರೆ BOUND_DEBUG
        ಆದರೆ (print_calls) {
            p = envp;
            ಆಗ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (ಪೂರ್ಣಾಂಕ)((++p - envp) * ಗಾತ್ರ(ಅಕ್ಷರ *)));
        }
#ಆದರೆ_ಅಂತ್ಯ
    }
}

ಶೂನ್ಯ __attribute__((destructor)) __bound_exit(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i;
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ಆದರೆ (inited) {
#ಆದರೆ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ಆದರೆ (print_ರಾಶಿ) {
            ಬಾಹ್ಯ ಶೂನ್ಯ __libc_freeres (ಶೂನ್ಯ);
            __libc_freeres ();
        }
#ಆದರೆ_ಅಂತ್ಯ

        NO_CHECKING_ಗಣ(1);

        TRY_SEM ();
        ಆಗ (alloca_list) {
            alloca_list_type *ಮುಂದಿನ = alloca_list->ಮುಂದಿನ;

            ವೃಕ್ಷ_2 = splay_delete ((ಗಾತ್ರ_t) alloca_list->p, ವೃಕ್ಷ_2);
            BOUND_FREE (alloca_list);
            alloca_list = ಮುಂದಿನ;
        }
        ಆಗ (jmp_list) {
           jmp_list_type *ಮುಂದಿನ  = jmp_list->ಮುಂದಿನ;

           BOUND_FREE (jmp_list);
           jmp_list = ಮುಂದಿನ;
        }
        ಗಾಗಿ (i = 0; i < FREE_REUSE_ಗಾತ್ರ; i++) {
            ಆದರೆ (free_reuse_list[i]) {
                ವೃಕ್ಷ_2 = splay_delete ((ಗಾತ್ರ_t) free_reuse_list[i], ವೃಕ್ಷ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ಆಗ (ವೃಕ್ಷ_2) {
            ಆದರೆ (print_ರಾಶಿ && ವೃಕ್ಷ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[ವೃಕ್ಷ_2->type],
                         (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) ವೃಕ್ಷ_2->ಗಾತ್ರ_2);
            ವೃಕ್ಷ_2 = splay_delete (ವೃಕ್ಷ_2->ಆರಂಭ, ವೃಕ್ಷ_2);
        }
#ಆದರೆ ವೃಕ್ಷ_REUSE
        ಆಗ (ವೃಕ್ಷ_free_list) {
            ವೃಕ್ಷ *ಮುಂದಿನ = ವೃಕ್ಷ_free_list->ಎಡ;
            BOUND_FREE (ವೃಕ್ಷ_free_list);
            ವೃಕ್ಷ_free_list = ಮುಂದಿನ;
        }
#ಆದರೆ_ಅಂತ್ಯ
        POST_SEM ();
        EXIT_SEM ();
#ಆದರೆ HAVE_TLS_FUNC
#ಆದರೆ defined(_WIN32)
        TlsFree(no_checking_ಕೀಲಿ);
#ಇಲ್ಲದಿದ್ದರೆ
        pthread_key_delete(no_checking_ಕೀಲಿ);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
        inited = 0;
        ಆದರೆ (print_statistic) {
#ಆದರೆ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_ಕೂಡಿಸು_ಎಣಿಕೆ);
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
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_ಸಿಕ್ಕಿತು);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_ಕೊನೆ);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ಸೇರಿಸು);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#ಆದರೆ_ಅಂತ್ಯ
        }
    }
}

ಶೂನ್ಯ __bound_exit_dll(ಗಾತ್ರ_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ಆದರೆ (p) {
        WAIT_SEM ();
	ಆಗ (p[0] != 0) {
	    ವೃಕ್ಷ_2 = splay_delete(p[0], ವೃಕ್ಷ_2);
#ಆದರೆ BOUND_DEBUG
            ಆದರೆ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ಶೂನ್ಯ *) p[0], (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) p[1]);
            }
#ಆದರೆ_ಅಂತ್ಯ
	    p += 2;
	}
        POST_SEM ();
    }
}

#ಆದರೆ HAVE_PTHREAD_CREATE
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಶೂನ್ಯ *(*ಆರಂಭ_routine) (ಶೂನ್ಯ *);
    ಶೂನ್ಯ *arg;
    sigset_t old_ಮುಖವಾಡ;
} bound_thread_create_type;

ಸ್ಥಿರ ಶೂನ್ಯ *bound_thread_create(ಶೂನ್ಯ *bdata)
{
    bound_thread_create_type *ದತ್ತಾಂಶ = (bound_thread_create_type *) bdata;
    ಶೂನ್ಯ *retval;
#ಆದರೆ HAVE_TLS_FUNC
    ಪೂರ್ಣಾಂಕ *p = (ಪೂರ್ಣಾಂಕ *) BOUND_MALLOC(ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
  
    ಆದರೆ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ಕೀಲಿ, p);
#ಆದರೆ_ಅಂತ್ಯ
    pthread_sigmask(SIG_SETMASK, &ದತ್ತಾಂಶ->old_ಮುಖವಾಡ, ಖಾಲಿ);
    retval = ದತ್ತಾಂಶ->ಆರಂಭ_routine(ದತ್ತಾಂಶ->arg);
#ಆದರೆ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ಕೀಲಿ, ಖಾಲಿ);
    BOUND_FREE (p);
#ಆದರೆ_ಅಂತ್ಯ
    BOUND_FREE (ದತ್ತಾಂಶ);
    ಹಿಂತಿರುಗಿ retval;
}

ಪೂರ್ಣಾಂಕ pthread_create(pthread_t *thread, ಸ್ಥಿರಾಂಕ pthread_attr_t *attr,
                   ಶೂನ್ಯ *(*ಆರಂಭ_routine) (ಶೂನ್ಯ *), ಶೂನ್ಯ *arg)
{
    ಪೂರ್ಣಾಂಕ retval;
    bound_thread_create_type *ದತ್ತಾಂಶ;
    sigset_t ಮುಖವಾಡ;
    sigset_t old_ಮುಖವಾಡ;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&ಮುಖವಾಡ);
    pthread_sigmask(SIG_SETMASK, &ಮುಖವಾಡ, &old_ಮುಖವಾಡ);
    ದತ್ತಾಂಶ = (bound_thread_create_type *) BOUND_MALLOC(ಗಾತ್ರ(bound_thread_create_type));
    ಆದರೆ (!ದತ್ತಾಂಶ) bound_alloc_error("bound_thread_create malloc");
    ದತ್ತಾಂಶ->ಆರಂಭ_routine = ಆರಂಭ_routine;
    ದತ್ತಾಂಶ->arg = arg;
    ದತ್ತಾಂಶ->old_ಮುಖವಾಡ = old_ಮುಖವಾಡ;
    retval = pthread_create_redir(thread, attr, bound_thread_create, ದತ್ತಾಂಶ);
    pthread_sigmask(SIG_SETMASK, &old_ಮುಖವಾಡ, ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ retval;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ HAVE_SIGNAL || HAVE_SIGACTION
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ {
#ಆದರೆ HAVE_SIGNAL
    bound_sig signal_handler;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ HAVE_SIGACTION
    ಶೂನ್ಯ (*sig_handler)(ಪೂರ್ಣಾಂಕ);
    ಶೂನ್ಯ (*sig_sigaction)(ಪೂರ್ಣಾಂಕ, siginfo_t *, ಶೂನ್ಯ *);
#ಆದರೆ_ಅಂತ್ಯ
} bound_sig_type;

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ bound_sig_ಬಳಸಿದ[NSIG];
ಸ್ಥಿರ bound_sig_type bound_sig_ದತ್ತಾಂಶ[NSIG];
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ HAVE_SIGNAL
ಸ್ಥಿರ ಶೂನ್ಯ signal_handler(ಪೂರ್ಣಾಂಕ sig)
{
   __bounds_checking(1);
   bound_sig_ದತ್ತಾಂಶ[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig ಸಂಕೇತ(ಪೂರ್ಣಾಂಕ signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ಆದರೆ (retval != SIG_ERR) {
        ಆದರೆ (bound_sig_ಬಳಸಿದ[signum])
            retval = bound_sig_ದತ್ತಾಂಶ[signum].signal_handler;
        ಆದರೆ (handler) {
            bound_sig_ಬಳಸಿದ[signum] = 1;
            bound_sig_ದತ್ತಾಂಶ[signum].signal_handler = handler;
        }
    }
    ಹಿಂತಿರುಗಿ retval;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ HAVE_SIGACTION
ಸ್ಥಿರ ಶೂನ್ಯ sig_handler(ಪೂರ್ಣಾಂಕ sig)
{
   __bounds_checking(1);
   bound_sig_ದತ್ತಾಂಶ[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ಸ್ಥಿರ ಶೂನ್ಯ sig_sigaction(ಪೂರ್ಣಾಂಕ sig, siginfo_t *info, ಶೂನ್ಯ *ucontext)
{
   __bounds_checking(1);
   bound_sig_ದತ್ತಾಂಶ[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

ಪೂರ್ಣಾಂಕ sigaction(ಪೂರ್ಣಾಂಕ signum, ಸ್ಥಿರಾಂಕ ರಚನೆ sigaction *act, ರಚನೆ sigaction *oldact)
{
    ಪೂರ್ಣಾಂಕ retval;
    ರಚನೆ sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ಆದರೆ (sigaction_redir == ಖಾಲಿ)
        __bound_init(0,-1);

    ಆದರೆ (act) {
        nact = *act;
        ಆದರೆ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ಇಲ್ಲದಿದ್ದರೆ
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ಇಲ್ಲದಿದ್ದರೆ
        retval = sigaction_redir(signum, act, &oact);
    ಆದರೆ (retval >= 0) {
        ಆದರೆ (bound_sig_ಬಳಸಿದ[signum]) {
            ಆದರೆ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_ದತ್ತಾಂಶ[signum].sig_sigaction;
            ಇಲ್ಲದಿದ್ದರೆ
                oact.sa_handler = bound_sig_ದತ್ತಾಂಶ[signum].sig_handler;
        }
        ಆದರೆ (oldact) {
            *oldact = oact;
        }
        ಆದರೆ (act) {
            bound_sig_ಬಳಸಿದ[signum] = 1;
            ಆದರೆ (act->sa_flags & SA_SIGINFO)
                bound_sig_ದತ್ತಾಂಶ[signum].sig_sigaction = act->sa_sigaction;
            ಇಲ್ಲದಿದ್ದರೆ
                bound_sig_ದತ್ತಾಂಶ[signum].sig_handler = act->sa_handler;
        }
    }
    ಹಿಂತಿರುಗಿ retval;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ HAVE_FORK
pid_t fork(ಶೂನ್ಯ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ಆದರೆ (retval == 0)
        INIT_SEM();
    ಇಲ್ಲದಿದ್ದರೆ
        POST_SEM();
    ಹಿಂತಿರುಗಿ retval;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ MALLOC_REDIR
ಶೂನ್ಯ *ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಗಾತ್ರ_2)
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ *__bound_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller)
#ಆದರೆ_ಅಂತ್ಯ
{
    ಶೂನ್ಯ *ptr;
    
#ಆದರೆ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ಆದರೆ (malloc_redir == ಖಾಲಿ) {
        __bound_init (0, -1);
        ಆದರೆ (malloc_redir == ಖಾಲಿ) {
            ptr = &initial_pool[pool_ಸೂಚ್ಯಂಕ];
            pool_ಸೂಚ್ಯಂಕ = (pool_ಸೂಚ್ಯಂಕ + ಗಾತ್ರ_2 + 15) & ~15;
            ಆದರೆ (pool_ಸೂಚ್ಯಂಕ >= ಗಾತ್ರ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
            ಹಿಂತಿರುಗಿ ptr;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (ಗಾತ್ರ_2 + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
    
    ಆದರೆ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_malloc_ಎಣಿಕೆ);

        ಆದರೆ (ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((ಗಾತ್ರ_t) ptr, ಗಾತ್ರ_2 ? ಗಾತ್ರ_2 : ಗಾತ್ರ_2 + 1, ವೃಕ್ಷ_2);
            ಆದರೆ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->ಆರಂಭ == (ಗಾತ್ರ_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ಹಿಂತಿರುಗಿ ptr;
}

#ಆದರೆ MALLOC_REDIR
ಶೂನ್ಯ *memalign(ಗಾತ್ರ_t align, ಗಾತ್ರ_t ಗಾತ್ರ_2)
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ *__bound_memalign(ಗಾತ್ರ_t align, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller)
#ಆದರೆ_ಅಂತ್ಯ
{
    ಶೂನ್ಯ *ptr;

#ಆದರೆ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, ಗಾತ್ರ_2 + 1);
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (align > 4) {
        /* XXX: handle it ? */
        ptr = ಖಾಲಿ;
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(ಗಾತ್ರ_2 + 1);
    }
#ಆದರೆ_ಅಂತ್ಯ
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);

    ಆದರೆ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_memalign_ಎಣಿಕೆ);

        ಆದರೆ (ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t) ptr, ಗಾತ್ರ_2 ? ಗಾತ್ರ_2 : ಗಾತ್ರ_2 + 1, ವೃಕ್ಷ_2);
            ಆದರೆ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->ಆರಂಭ == (ಗಾತ್ರ_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ಹಿಂತಿರುಗಿ ptr;
}

#ಆದರೆ MALLOC_REDIR
ಶೂನ್ಯ ಬಿಡುಗಡೆ(ಶೂನ್ಯ *ptr)
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ __bound_free(ಶೂನ್ಯ *ptr, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller)
#ಆದರೆ_ಅಂತ್ಯ
{
    ಗಾತ್ರ_t addr = (ಗಾತ್ರ_t) ptr;
    ಶೂನ್ಯ *p;

    ಆದರೆ (ptr == ಖಾಲಿ || ವೃಕ್ಷ_2 == ಖಾಲಿ
#ಆದರೆ MALLOC_REDIR
        || ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) ptr >= &initial_pool[0] &&
            (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) ptr < &initial_pool[ಗಾತ್ರ(initial_pool)])
#ಆದರೆ_ಅಂತ್ಯ
        )
        ಹಿಂತಿರುಗಿ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ಆದರೆ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_free_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay (addr, ವೃಕ್ಷ_2);
        ಆದರೆ (ವೃಕ್ಷ_2->ಆರಂಭ == addr) {
            ಆದರೆ (ವೃಕ್ಷ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ಹಿಂತಿರುಗಿ;
            }
            ವೃಕ್ಷ_2->is_invalid = 1;
            memset (ptr, 0x5a, ವೃಕ್ಷ_2->ಗಾತ್ರ_2);
            p = free_reuse_list[free_reuse_ಸೂಚ್ಯಂಕ];
            free_reuse_list[free_reuse_ಸೂಚ್ಯಂಕ] = ptr;
            free_reuse_ಸೂಚ್ಯಂಕ = (free_reuse_ಸೂಚ್ಯಂಕ + 1) % FREE_REUSE_ಗಾತ್ರ;
            ಆದರೆ (p)
                ವೃಕ್ಷ_2 = splay_delete((ಗಾತ್ರ_t)p, ವೃಕ್ಷ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ಆದರೆ MALLOC_REDIR
ಶೂನ್ಯ *realloc(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2)
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ *__bound_realloc(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *caller)
#ಆದರೆ_ಅಂತ್ಯ
{
    ಶೂನ್ಯ *new_ptr;

    ಆದರೆ (ಗಾತ್ರ_2 == 0) {
#ಆದರೆ MALLOC_REDIR
        ಬಿಡುಗಡೆ(ptr);
#ಇಲ್ಲದಿದ್ದರೆ
        __bound_free(ptr, caller);
#ಆದರೆ_ಅಂತ್ಯ
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    }

    new_ptr = BOUND_REALLOC (ptr, ಗಾತ್ರ_2 + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);

    ಆದರೆ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_realloc_ಎಣಿಕೆ);

        ಆದರೆ (ptr)
            ವೃಕ್ಷ_2 = splay_delete ((ಗಾತ್ರ_t) ptr, ವೃಕ್ಷ_2);
        ಆದರೆ (new_ptr) {
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((ಗಾತ್ರ_t) new_ptr, ಗಾತ್ರ_2 ? ಗಾತ್ರ_2 : ಗಾತ್ರ_2 + 1, ವೃಕ್ಷ_2);
            ಆದರೆ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->ಆರಂಭ == (ಗಾತ್ರ_t) new_ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ಹಿಂತಿರುಗಿ new_ptr;
}

#ಆದರೆ MALLOC_REDIR
ಶೂನ್ಯ *ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t nmemb, ಗಾತ್ರ_t ಗಾತ್ರ_2)
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ *__bound_calloc(ಗಾತ್ರ_t nmemb, ಗಾತ್ರ_t ಗಾತ್ರ_2)
#ಆದರೆ_ಅಂತ್ಯ
{
    ಶೂನ್ಯ *ptr;

    ಗಾತ್ರ_2 *= nmemb;
#ಆದರೆ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ಆದರೆ (malloc_redir == ಖಾಲಿ) {
        __bound_init (0, -1);
        ಆದರೆ (malloc_redir == ಖಾಲಿ) {
            ptr = &initial_pool[pool_ಸೂಚ್ಯಂಕ];
            pool_ಸೂಚ್ಯಂಕ = (pool_ಸೂಚ್ಯಂಕ + ಗಾತ್ರ_2 + 15) & ~15;
            ಆದರೆ (pool_ಸೂಚ್ಯಂಕ >= ಗಾತ್ರ (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
            memset (ptr, 0, ಗಾತ್ರ_2);
            ಹಿಂತಿರುಗಿ ptr;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
    ptr = BOUND_MALLOC(ಗಾತ್ರ_2 + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);

    ಆದರೆ (ptr) {
        memset (ptr, 0, ಗಾತ್ರ_2);
        ಆದರೆ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ಎಣಿಕೆ(bound_calloc_ಎಣಿಕೆ);
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು ((ಗಾತ್ರ_t) ptr, ಗಾತ್ರ_2 ? ಗಾತ್ರ_2 : ಗಾತ್ರ_2 + 1, ವೃಕ್ಷ_2);
            ಆದರೆ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->ಆರಂಭ == (ಗಾತ್ರ_t) ptr)
                ವೃಕ್ಷ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ಹಿಂತಿರುಗಿ ptr;
}

#ಆದರೆ !defined(_WIN32)
ಶೂನ್ಯ *__bound_mmap (ಶೂನ್ಯ *ಆರಂಭ, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ prot,
                    ಪೂರ್ಣಾಂಕ flags, ಪೂರ್ಣಾಂಕ fd, off_t ಸ್ಥಾನಾಂತರ)
{
    ಶೂನ್ಯ *ಫಲಿತಾಂಶ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ಆರಂಭ, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
    ಫಲಿತಾಂಶ = mmap (ಆರಂಭ, ಗಾತ್ರ_2, prot, flags, fd, ಸ್ಥಾನಾಂತರ);
    ಆದರೆ (ಫಲಿತಾಂಶ && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_mmap_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t)ಫಲಿತಾಂಶ, ಗಾತ್ರ_2, ವೃಕ್ಷ_2);
        POST_SEM ();
    }
    ಹಿಂತಿರುಗಿ ಫಲಿತಾಂಶ;
}

ಪೂರ್ಣಾಂಕ __bound_munmap (ಶೂನ್ಯ *ಆರಂಭ, ಗಾತ್ರ_t ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ ಫಲಿತಾಂಶ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ಆರಂಭ, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2);
    ಆದರೆ (ಆರಂಭ && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ಎಣಿಕೆ(bound_munmap_ಎಣಿಕೆ);
        ವೃಕ್ಷ_2 = splay_delete ((ಗಾತ್ರ_t) ಆರಂಭ, ವೃಕ್ಷ_2);
        POST_SEM ();
    }
    ಫಲಿತಾಂಶ = munmap (ಆರಂಭ, ಗಾತ್ರ_2);
    ಹಿಂತಿರುಗಿ ಫಲಿತಾಂಶ;
}
#ಆದರೆ_ಅಂತ್ಯ

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ಸ್ಥಿರ ಶೂನ್ಯ __bound_check(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *function)
{
    ಆದರೆ (ಗಾತ್ರ_2 != 0 && __bound_ptr_add((ಶೂನ್ಯ *)p, ಗಾತ್ರ_2) == INVALID_ಸೂಚಕ) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ಗಾತ್ರ_2, function);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check_overlap (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p1, ಗಾತ್ರ_t n1,
                          ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p2, ಗಾತ್ರ_t n2,
                          ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *function)
{
    ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p1e = (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *) ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) p1 + n1);
    ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p2e = (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *) ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) p2 + n2);

    ಆದರೆ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n1, p2, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n2, function);
        ಹಿಂತಿರುಗಿ never_fatal < 0;
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ *__bound_memcpy(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_mempcy_ಎಣಿಕೆ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ಆದರೆ (check_overlap(dest, n, src, n, "memcpy"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ ಸ್ಮರಣೆ_ನಕಲು(dest, src, n);
}

ಪೂರ್ಣಾಂಕ __bound_memcmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *s1, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *s2, ಗಾತ್ರ_t n)
{
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u1 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s1;
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u2 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s2;
    ಪೂರ್ಣಾಂಕ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memcmp_ಎಣಿಕೆ);
    ಗಾಗಿ (;;) {
        ಆದರೆ ((ssize_t) --n == -1)
            ನಿಲ್ಲಿಸು;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ನಿಲ್ಲಿಸು;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *)u2 - s2, "memcmp s2");
    ಹಿಂತಿರುಗಿ retval;
}

ಶೂನ್ಯ *__bound_memmove(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಹಿಂತಿರುಗಿ memmove(dest, src, n);
}

ಶೂನ್ಯ *__bound_memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memset_ಎಣಿಕೆ);
    __bound_check(s, n, "memset");
    ಹಿಂತಿರುಗಿ memset(s, c, n);
}

#ಆದರೆ defined(__arm__) && defined(__ARM_EABI__)
ಶೂನ್ಯ *__bound___aeabi_memcpy(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_mempcy_ಎಣಿಕೆ);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ಆದರೆ (check_overlap(dest, n, src, n, "memcpy"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ __aeabi_memcpy(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಹಿಂತಿರುಗಿ __aeabi_memmove(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove4(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಹಿಂತಿರುಗಿ __aeabi_memmove4(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memmove8(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memmove_ಎಣಿಕೆ);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ಹಿಂತಿರುಗಿ __aeabi_memmove8(dest, src, n);
}

ಶೂನ್ಯ *__bound___aeabi_memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_memset_ಎಣಿಕೆ);
    __bound_check(s, n, "memset");
    ಹಿಂತಿರುಗಿ __aeabi_memset(s, c, n);
}
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ __bound_strlen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ಎಣಿಕೆ(bound_strlen_ಎಣಿಕೆ);
    ಆಗ (*p++);
    __bound_check(s, p - s, "strlen");
    ಹಿಂತಿರುಗಿ (p - s) - 1;
}

ಅಕ್ಷರ *__bound_strcpy(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src)
{
    ಗಾತ್ರ_t len;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ಎಣಿಕೆ(bound_strcpy_ಎಣಿಕೆ);
    ಆಗ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ಆದರೆ (check_overlap(dest, len, src, len, "strcpy"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ strcpy (dest, src);
}

ಅಕ್ಷರ *__bound_strncpy(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src, ಗಾತ್ರ_t n)
{
    ಗಾತ್ರ_t len = n;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_strncpy_ಎಣಿಕೆ);
    ಆಗ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ಆದರೆ (check_overlap(dest, len, src, len, "strncpy"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ strncpy(dest, src, n);
}

ಪೂರ್ಣಾಂಕ __bound_strcmp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s2)
{
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u1 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s1;
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u2 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ಎಣಿಕೆ(bound_strcmp_ಎಣಿಕೆ);
    ಆಗ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)u2 - s2) + 1, "strcmp s2");
    ಹಿಂತಿರುಗಿ *u1 - *u2;
}

ಪೂರ್ಣಾಂಕ __bound_strncmp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s2, ಗಾತ್ರ_t n)
{
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u1 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s1;
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *u2 = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s2;
    ಪೂರ್ಣಾಂಕ retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_strncmp_ಎಣಿಕೆ);
    ಮಾಡು {
        ಆದರೆ ((ssize_t) --n == -1)
            ನಿಲ್ಲಿಸು;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ನಿಲ್ಲಿಸು;
        }
        ++u2;
    } ಆಗ (*u1++);
    __bound_check(s1, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)u2 - s2, "strncmp s2");
    ಹಿಂತಿರುಗಿ retval;
}

ಅಕ್ಷರ *__bound_strcat(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src)
{
    ಅಕ್ಷರ *r = dest;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ಎಣಿಕೆ(bound_strcat_ಎಣಿಕೆ);
    ಆಗ (*dest++);
    ಆಗ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ಆದರೆ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ strcat(r, s);
}

ಅಕ್ಷರ *__bound_strncat(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src, ಗಾತ್ರ_t n)
{
    ಅಕ್ಷರ *r = dest;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = src;
    ಗಾತ್ರ_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)n);
    INCR_ಎಣಿಕೆ(bound_strncat_ಎಣಿಕೆ);
    ಆಗ (*dest++);
    ಆಗ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ಆದರೆ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ಹಿಂತಿರುಗಿ dest;
    ಹಿಂತಿರುಗಿ strncat(r, s, n);
}

ಅಕ್ಷರ *__bound_strchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ c)
{
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *str = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ಎಣಿಕೆ(bound_strchr_ಎಣಿಕೆ);
    ಆಗ (*str) {
        ಆದರೆ (*str == ch)
            ನಿಲ್ಲಿಸು;
        ++str;
    }
    __bound_check(s, ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)str - s) + 1, "strchr");
    ಹಿಂತಿರುಗಿ *str == ch ? (ಅಕ್ಷರ *) str : ಖಾಲಿ;
}

ಅಕ್ಷರ *__bound_strrchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ c)
{
    ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *str = (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) s;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ಎಣಿಕೆ(bound_strrchr_ಎಣಿಕೆ);
    ಆಗ (*str++);
    __bound_check(s, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)str - s, "strrchr");
    ಆಗ (str != (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)s) {
        ಆದರೆ (*--str == ch)
            ನಿಲ್ಲಿಸು;
    }
    __bound_check(s, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)str - s, "strrchr");
    ಹಿಂತಿರುಗಿ *str == ch ? (ಅಕ್ಷರ *) str : ಖಾಲಿ;
}

ಅಕ್ಷರ *__bound_strdup(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p = s;
    ಅಕ್ಷರ *new;

    INCR_ಎಣಿಕೆ(bound_strdup_ಎಣಿಕೆ);
    ಆಗ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)(p -s));
    ಆದರೆ (new) {
        ಆದರೆ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            ವೃಕ್ಷ_2 = splay_ಸೇರಿಸು((ಗಾತ್ರ_t)new, p - s, ವೃಕ್ಷ_2);
            ಆದರೆ (ವೃಕ್ಷ_2 && ವೃಕ್ಷ_2->ಆರಂಭ == (ಗಾತ್ರ_t) new)
                ವೃಕ್ಷ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        ಸ್ಮರಣೆ_ನಕಲು (new, s, p - s);
    }
    ಹಿಂತಿರುಗಿ new;
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

#ವ್ಯಾಖ್ಯಾನಿಸು compare(ಆರಂಭ,tstart,tsize) (ಆರಂಭ < tstart ? -1 : \
                                     ಆರಂಭ >= tstart+tsize  ? 1 : 0)

ಸ್ಥಿರ ವೃಕ್ಷ * splay (ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    ವೃಕ್ಷ N, *l, *r, *y;
    ಪೂರ್ಣಾಂಕ comp;
    
    INCR_ಎಣಿಕೆ_SPLAY(bound_splay);
    ಆದರೆ (t == ಖಾಲಿ) ಹಿಂತಿರುಗಿ t;
    N.ಎಡ = N.ಬಲ = ಖಾಲಿ;
    l = r = &N;
 
    ಗಾಗಿ (;;) {
        comp = compare(addr, t->ಆರಂಭ, t->ಗಾತ್ರ_2);
        ಆದರೆ (comp < 0) {
            y = t->ಎಡ;
            ಆದರೆ (y == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            ಆದರೆ (compare(addr, y->ಆರಂಭ, y->ಗಾತ್ರ_2) < 0) {
                t->ಎಡ = y->ಬಲ;                    /* rotate right */
                y->ಬಲ = t;
                t = y;
                ಆದರೆ (t->ಎಡ == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            }
            r->ಎಡ = t;                               /* link right */
            r = t;
            t = t->ಎಡ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (comp > 0) {
            y = t->ಬಲ;
            ಆದರೆ (y == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            ಆದರೆ (compare(addr, y->ಆರಂಭ, y->ಗಾತ್ರ_2) > 0) {
                t->ಬಲ = y->ಎಡ;                    /* rotate left */
                y->ಎಡ = t;
                t = y;
                ಆದರೆ (t->ಬಲ == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            }
            l->ಬಲ = t;                              /* link left */
            l = t;
            t = t->ಬಲ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ನಿಲ್ಲಿಸು;
        }
    }
    l->ಬಲ = t->ಎಡ;                                /* assemble */
    r->ಎಡ = t->ಬಲ;
    t->ಎಡ = N.ಬಲ;
    t->ಬಲ = N.ಎಡ;

    ಹಿಂತಿರುಗಿ t;
}

#ವ್ಯಾಖ್ಯಾನಿಸು compare_ಕೊನೆ(ಆರಂಭ,tend) (ಆರಂಭ < tend ? -1 : \
                                 ಆರಂಭ > tend  ? 1 : 0)

ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಕೊನೆ (ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    ವೃಕ್ಷ N, *l, *r, *y;
    ಪೂರ್ಣಾಂಕ comp;
    
    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_ಕೊನೆ);
    ಆದರೆ (t == ಖಾಲಿ) ಹಿಂತಿರುಗಿ t;
    N.ಎಡ = N.ಬಲ = ಖಾಲಿ;
    l = r = &N;
 
    ಗಾಗಿ (;;) {
        comp = compare_ಕೊನೆ(addr, t->ಆರಂಭ + t->ಗಾತ್ರ_2);
        ಆದರೆ (comp < 0) {
            y = t->ಎಡ;
            ಆದರೆ (y == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            ಆದರೆ (compare_ಕೊನೆ(addr, y->ಆರಂಭ + y->ಗಾತ್ರ_2) < 0) {
                t->ಎಡ = y->ಬಲ;                    /* rotate right */
                y->ಬಲ = t;
                t = y;
                ಆದರೆ (t->ಎಡ == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            }
            r->ಎಡ = t;                               /* link right */
            r = t;
            t = t->ಎಡ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (comp > 0) {
            y = t->ಬಲ;
            ಆದರೆ (y == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            ಆದರೆ (compare_ಕೊನೆ(addr, y->ಆರಂಭ + y->ಗಾತ್ರ_2) > 0) {
                t->ಬಲ = y->ಎಡ;                    /* rotate left */
                y->ಎಡ = t;
                t = y;
                ಆದರೆ (t->ಬಲ == ಖಾಲಿ) ನಿಲ್ಲಿಸು;
            }
            l->ಬಲ = t;                              /* link left */
            l = t;
            t = t->ಬಲ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ನಿಲ್ಲಿಸು;
        }
    }
    l->ಬಲ = t->ಎಡ;                                /* assemble */
    r->ಎಡ = t->ಬಲ;
    t->ಎಡ = N.ಬಲ;
    t->ಬಲ = N.ಎಡ;

    ಹಿಂತಿರುಗಿ t;
}

ಸ್ಥಿರ ವೃಕ್ಷ * splay_ಸೇರಿಸು(ಗಾತ್ರ_t addr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ವೃಕ್ಷ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    ವೃಕ್ಷ * new;

    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_ಸೇರಿಸು);
    ಆದರೆ (t != ಖಾಲಿ) {
        t = splay(addr,t);
        ಆದರೆ (compare(addr, t->ಆರಂಭ, t->ಗಾತ್ರ_2)==0) {
            ಹಿಂತಿರುಗಿ t;  /* it's already there */
        }
    }
#ಆದರೆ ವೃಕ್ಷ_REUSE
    ಆದರೆ (ವೃಕ್ಷ_free_list) {
          new = ವೃಕ್ಷ_free_list;
          ವೃಕ್ಷ_free_list = new->ಎಡ;
    }
    ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    {
        new = (ವೃಕ್ಷ *) BOUND_MALLOC (ಗಾತ್ರ (ವೃಕ್ಷ));
    }
    ಆದರೆ (new == ಖಾಲಿ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (t == ಖಾಲಿ) {
            new->ಎಡ = new->ಬಲ = ಖಾಲಿ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (compare(addr, t->ಆರಂಭ, t->ಗಾತ್ರ_2) < 0) {
            new->ಎಡ = t->ಎಡ;
            new->ಬಲ = t;
            t->ಎಡ = ಖಾಲಿ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            new->ಬಲ = t->ಬಲ;
            new->ಎಡ = t;
            t->ಬಲ = ಖಾಲಿ;
        }
        new->ಆರಂಭ = addr;
        new->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ಹಿಂತಿರುಗಿ new;
}

#ವ್ಯಾಖ್ಯಾನಿಸು compare_destroy(ಆರಂಭ,tstart) (ಆರಂಭ < tstart ? -1 : \
                                       ಆರಂಭ > tstart  ? 1 : 0)

ಸ್ಥಿರ ವೃಕ್ಷ * splay_delete(ಗಾತ್ರ_t addr, ವೃಕ್ಷ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    ವೃಕ್ಷ * x;

    INCR_ಎಣಿಕೆ_SPLAY(bound_splay_delete);
    ಆದರೆ (t==ಖಾಲಿ) ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    t = splay(addr,t);
    ಆದರೆ (compare_destroy(addr, t->ಆರಂಭ) == 0) {        /* found it */
        ಆದರೆ (t->ಎಡ == ಖಾಲಿ) {
            x = t->ಬಲ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            x = splay(addr, t->ಎಡ);
            x->ಬಲ = t->ಬಲ;
        }
#ಆದರೆ ವೃಕ್ಷ_REUSE
        t->ಎಡ = ವೃಕ್ಷ_free_list;
        ವೃಕ್ಷ_free_list = t;
#ಇಲ್ಲದಿದ್ದರೆ
        BOUND_FREE(t);
#ಆದರೆ_ಅಂತ್ಯ
        ಹಿಂತಿರುಗಿ x;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಹಿಂತಿರುಗಿ t;                                      /* It wasn't there */
    }
}

ಶೂನ್ಯ splay_printtree(ವೃಕ್ಷ * t, ಪೂರ್ಣಾಂಕ d)
{
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ (t == ಖಾಲಿ) ಹಿಂತಿರುಗಿ;
    splay_printtree(t->ಬಲ, d+1);
    ಗಾಗಿ (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (ಶೂನ್ಯ *) t->ಆರಂಭ, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) t->ಗಾತ್ರ_2,
            (ಚಿಹ್ನೆರಹಿತ)t->type, (ಚಿಹ್ನೆರಹಿತ)t->is_invalid);
    splay_printtree(t->ಎಡ, d+1);
}
