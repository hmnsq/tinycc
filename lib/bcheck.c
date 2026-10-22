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
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>
#ଅନ୍ତର୍ଭାଵ <stdatomic.h>

#ଯଦି !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#ଅନ୍ତର୍ଭାଵ <malloc.h>
#endif

#ଯଦି !defined(_WIN32)
#ଅନ୍ତର୍ଭାଵ <unistd.h>
#ଅନ୍ତର୍ଭାଵ <sys/syscall.h>
#endif

#ଅନ୍ତର୍ଭାଵ "config.h"

#define BOUND_DEBUG             (1)
#define BOUND_STATISTIC         (1)

#ଯଦି BOUND_DEBUG
 #define dprintf(a...)         ଯଦି (print_calls) { bounds_loc(a); }
#ଅନ୍ୟଥା
 #define dprintf(a...)
#endif

#ifdef __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #undef __attribute__ 
#endif
#ifdef __i386__
#define FASTCALL __attribute__((regparm(3)))
#ଅନ୍ୟଥା
#define FASTCALL
#endif

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ଅନ୍ୟଥା
# define DLL_EXPORT
#endif

#ଯଦି defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#ଅନ୍ତର୍ଭାଵ <sys/mman.h>
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

#ନଚେତଯଦି defined(_WIN32)

#ଅନ୍ତର୍ଭାଵ <windows.h>
#ଅନ୍ତର୍ଭାଵ <signal.h>
ସ୍ଥିର CRITICAL_SECTION bounds_sem;
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

#ଅନ୍ୟଥା

#define __USE_GNU              /* get RTLD_NEXT */
#ଅନ୍ତର୍ଭାଵ <sys/mman.h>
#ଅନ୍ତର୍ଭାଵ <ctype.h>
#ଅନ୍ତର୍ଭାଵ <pthread.h>
#ଅନ୍ତର୍ଭାଵ <dlfcn.h>
#ଅନ୍ତର୍ଭାଵ <errno.h>
#ଅନ୍ତର୍ଭାଵ <signal.h>
#ifdef __APPLE__
#ଅନ୍ତର୍ଭାଵ <dispatch/dispatch.h>
ସ୍ଥିର dispatch_semaphore_t bounds_sem;
#define INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#define EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#define WAIT_SEM()             ଯଦି (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_FOREVER)
#define POST_SEM()             ଯଦି (use_sem) dispatch_semaphore_signal(bounds_sem)
#define TRY_SEM()              ଯଦି (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_TIME_NOW)
#ନଚେତଯଦି 0
#ଅନ୍ତର୍ଭାଵ <semaphore.h>
ସ୍ଥିର sem_t bounds_sem;
#define INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#define EXIT_SEM()             sem_destroy (&bounds_sem)
#define WAIT_SEM()             ଯଦି (use_sem) ଯେତେବେଳେ (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#define POST_SEM()             ଯଦି (use_sem) sem_post (&bounds_sem)
#define TRY_SEM()              ଯଦି (use_sem) ଯେତେବେଳେ (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#ନଚେତଯଦି 0
ସ୍ଥିର pthread_mutex_t bounds_mtx;
#define INIT_SEM()             pthread_mutex_init (&bounds_mtx, ଖାଲି)
#define EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#define WAIT_SEM()             ଯଦି (use_sem) pthread_mutex_lock (&bounds_mtx)
#define POST_SEM()             ଯଦି (use_sem) pthread_mutex_unlock (&bounds_mtx)
#define TRY_SEM()              ଯଦି (use_sem) pthread_mutex_trylock (&bounds_mtx)
#ଅନ୍ୟଥା
ସ୍ଥିର pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#define INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#define EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#define WAIT_SEM()             ଯଦି (use_sem) pthread_spin_lock (&bounds_spin)
#define POST_SEM()             ଯଦି (use_sem) pthread_spin_unlock (&bounds_spin)
#define TRY_SEM()              ଯଦି (use_sem) pthread_spin_trylock (&bounds_spin)
#endif
#define HAVE_MEMALIGN          (1)
#define MALLOC_REDIR           (1)
#define HAVE_PTHREAD_CREATE    (1)
#define HAVE_CTYPE             (1)
#define HAVE_ERRNO             (1)
#define HAVE_SIGNAL            (1)
#define HAVE_SIGACTION         (1)
#define HAVE_FORK              (1)
#ଯଦି defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_RUN)
#define HAVE_TLS_FUNC          (1)
#define HAVE_TLS_VAR           (0)
#ଅନ୍ୟଥା
#define HAVE_TLS_FUNC          (0)
#define HAVE_TLS_VAR           (1)
#endif
#ଯଦି defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#endif
#endif

#ଯଦି MALLOC_REDIR
ସ୍ଥିର ଶୂନ୍ୟ *(*malloc_redir) (size_t);
ସ୍ଥିର ଶୂନ୍ୟ *(*calloc_redir) (size_t, size_t);
ସ୍ଥିର ଶୂନ୍ୟ (*free_redir) (ଶୂନ୍ୟ *);
ସ୍ଥିର ଶୂନ୍ୟ *(*realloc_redir) (ଶୂନ୍ୟ *, size_t);
ସ୍ଥିର unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା pool_index;
ସ୍ଥିର unsigned ଅକ୍ଷର __attribute__((aligned(16))) initial_pool[256];
#endif
#ଯଦି HAVE_MEMALIGN
ସ୍ଥିର ଶୂନ୍ୟ *(*memalign_redir) (size_t, size_t);
#endif
#ଯଦି HAVE_PTHREAD_CREATE
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*pthread_create_redir) (pthread_t *thread,
                                    ଅଚଳ pthread_attr_t *attr,
                                    ଶୂନ୍ୟ *(*start_routine)(ଶୂନ୍ୟ *), ଶୂନ୍ୟ *arg);
#endif
#ଯଦି HAVE_SIGNAL
ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (*bound_sig)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ସ୍ଥିର bound_sig (*signal_redir) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା signum, bound_sig handler);
#endif
#ଯଦି HAVE_SIGACTION
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*sigaction_redir) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା signum, ଅଚଳ ସଂରଚନା sigaction *act,
                               ସଂରଚନା sigaction *oldact);
#endif
#ଯଦି HAVE_FORK
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*fork_redir) (ଶୂନ୍ୟ);
#endif

#define TCC_TYPE_NONE           (0)
#define TCC_TYPE_MALLOC         (1)
#define TCC_TYPE_CALLOC         (2)
#define TCC_TYPE_REALLOC        (3)
#define TCC_TYPE_MEMALIGN       (4)
#define TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#define INVALID_POINTER ((ଶୂନ୍ୟ *)(-2))

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ବୃକ୍ଷ_ଗଣ୍ଠି ବୃକ୍ଷ;
ସଂରଚନା ବୃକ୍ଷ_ଗଣ୍ଠି {
    ବୃକ୍ଷ * ବାମ, * ଡାହାଣ;
    size_t start;
    size_t size;
    unsigned ଅକ୍ଷର type;
    unsigned ଅକ୍ଷର is_invalid; /* true if pointers outside region are invalid */
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା alloca_list_struct {
    size_t fp;
    ଶୂନ୍ୟ *p;
    size_t size;
    ସଂରଚନା alloca_list_struct *next;
} alloca_list_type;

#ଯଦି defined(_WIN32)
#define BOUND_TID_TYPE		DWORD
#define BOUND_GET_TID(id)	id = GetCurrentThreadId()
#ନଚେତଯଦି defined(__OpenBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = getthrid()
#ନଚେତଯଦି defined(__FreeBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#ନଚେତଯଦି  defined(__NetBSD__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#ନଚେତଯଦି defined(__linux__)
#define BOUND_TID_TYPE		pid_t
#define BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#ଅନ୍ୟଥା
#define BOUND_TID_TYPE		ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#define BOUND_GET_TID(id)	id = 0
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା jmp_list_struct {
    ଶୂନ୍ୟ *penv;
    size_t fp;
    size_t end_fp;
    BOUND_TID_TYPE tid;
    ସଂରଚନା jmp_list_struct *next;
} jmp_list_type;

#define BOUND_STATISTIC_SPLAY   (0)
ସ୍ଥିର ବୃକ୍ଷ * splay (size_t addr, ବୃକ୍ଷ *t);
ସ୍ଥିର ବୃକ୍ଷ * splay_end (size_t addr, ବୃକ୍ଷ *t);
ସ୍ଥିର ବୃକ୍ଷ * splay_ଭର୍ତ୍ତି(size_t addr, size_t size, ବୃକ୍ଷ * t);
ସ୍ଥିର ବୃକ୍ଷ * splay_delete(size_t addr, ବୃକ୍ଷ *t);
ଶୂନ୍ୟ splay_printtree(ବୃକ୍ଷ * t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d);

/* external interface */
ଶୂନ୍ୟ __bounds_checking (ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_check);
ଶୂନ୍ୟ __bound_checking_lock (ଶୂନ୍ୟ);
ଶୂନ୍ୟ __bound_checking_unlock (ଶୂନ୍ୟ);
ଶୂନ୍ୟ __bound_never_fatal (ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_check);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_add(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir1(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir2(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir4(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir8(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir12(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ * __bound_ptr_indir16(ଶୂନ୍ୟ *p, size_t offset);
DLL_EXPORT ଶୂନ୍ୟ FASTCALL __bound_local_new(ଶୂନ୍ୟ *p1);
DLL_EXPORT ଶୂନ୍ୟ FASTCALL __bound_local_delete(ଶୂନ୍ୟ *p1);
ଶୂନ୍ୟ __bound_init(size_t *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ଶୂନ୍ୟ __bound_main_arg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **envp);
ଶୂନ୍ୟ __bound_exit(ଶୂନ୍ୟ);
ଶୂନ୍ୟ __bound_exit_dll(size_t *);
#ଯଦି !defined(_WIN32)
ଶୂନ୍ୟ *__bound_mmap (ଶୂନ୍ୟ *start, size_t size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା prot, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd,
                    off_t offset);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_munmap (ଶୂନ୍ୟ *start, size_t size);
DLL_EXPORT ଶୂନ୍ୟ __bound_siglongjmp(jmp_buf env, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val);
#endif
DLL_EXPORT ଶୂନ୍ୟ __bound_new_region(ଶୂନ୍ୟ *p, size_t size);
DLL_EXPORT ଶୂନ୍ୟ __bound_setjmp(jmp_buf env);
DLL_EXPORT ଶୂନ୍ୟ __bound_longjmp(jmp_buf env, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val);
DLL_EXPORT ଶୂନ୍ୟ *__bound_memcpy(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_memcmp(ଅଚଳ ଶୂନ୍ୟ *s1, ଅଚଳ ଶୂନ୍ୟ *s2, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound_memmove(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound_memset(ଶୂନ୍ୟ *dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t size);
DLL_EXPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strlen(ଅଚଳ ଅକ୍ଷର *s);
DLL_EXPORT ଅକ୍ଷର *__bound_strcpy(ଅକ୍ଷର *dst, ଅଚଳ ଅକ୍ଷର *src);
DLL_EXPORT ଅକ୍ଷର *__bound_strncpy(ଅକ୍ଷର *dst, ଅଚଳ ଅକ୍ଷର *src, size_t n);
DLL_EXPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strcmp(ଅଚଳ ଅକ୍ଷର *s1, ଅଚଳ ଅକ୍ଷର *s2);
DLL_EXPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strncmp(ଅଚଳ ଅକ୍ଷର *s1, ଅଚଳ ଅକ୍ଷର *s2, size_t n);
DLL_EXPORT ଅକ୍ଷର *__bound_strcat(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src);
DLL_EXPORT ଅକ୍ଷର *__bound_strncat(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src, size_t n);
DLL_EXPORT ଅକ୍ଷର *__bound_strchr(ଅଚଳ ଅକ୍ଷର *string, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch);
DLL_EXPORT ଅକ୍ଷର *__bound_strrchr(ଅଚଳ ଅକ୍ଷର *string, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch);
DLL_EXPORT ଅକ୍ଷର *__bound_strdup(ଅଚଳ ଅକ୍ଷର *s);

#ଯଦି defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT ଶୂନ୍ୟ *__bound___aeabi_memcpy(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound___aeabi_memmove(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound___aeabi_memmove4(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound___aeabi_memmove8(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__bound___aeabi_memset(ଶୂନ୍ୟ *dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__aeabi_memcpy(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__aeabi_memmove(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__aeabi_memmove4(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__aeabi_memmove8(ଶୂନ୍ୟ *dst, ଅଚଳ ଶୂନ୍ୟ *src, size_t size);
DLL_EXPORT ଶୂନ୍ୟ *__aeabi_memset(ଶୂନ୍ୟ *dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t size);
#endif

#ଯଦି MALLOC_REDIR
#define BOUND_MALLOC(a)          malloc_redir(a)
#define BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#define BOUND_FREE(a)            free_redir(a)
#define BOUND_REALLOC(a,b)       realloc_redir(a,b)
#define BOUND_CALLOC(a,b)        calloc_redir(a,b)
#ଅନ୍ୟଥା
#define BOUND_MALLOC(a)          malloc(a)
#define BOUND_MEMALIGN(a,b)      memalign(a,b)
#define BOUND_FREE(a)            ମୁକ୍ତ(a)
#define BOUND_REALLOC(a,b)       realloc(a,b)
#define BOUND_CALLOC(a,b)        calloc(a,b)
DLL_EXPORT ଶୂନ୍ୟ *__bound_malloc(size_t size, ଅଚଳ ଶୂନ୍ୟ *caller);
DLL_EXPORT ଶୂନ୍ୟ *__bound_memalign(size_t align, size_t size, ଅଚଳ ଶୂନ୍ୟ *caller);
DLL_EXPORT ଶୂନ୍ୟ __bound_free(ଶୂନ୍ୟ *ptr, ଅଚଳ ଶୂନ୍ୟ *caller);
DLL_EXPORT ଶୂନ୍ୟ *__bound_realloc(ଶୂନ୍ୟ *ptr, size_t size, ଅଚଳ ଶୂନ୍ୟ *caller);
DLL_EXPORT ଶୂନ୍ୟ *__bound_calloc(size_t nmemb, size_t size);
#endif

#define FREE_REUSE_SIZE (100)
ସ୍ଥିର unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା free_reuse_index;
ସ୍ଥିର ଶୂନ୍ୟ *free_reuse_list[FREE_REUSE_SIZE];

ସ୍ଥିର ବୃକ୍ଷ *ବୃକ୍ଷ_2 = ଖାଲି;
#define ବୃକ୍ଷ_REUSE      (1)
#ଯଦି ବୃକ୍ଷ_REUSE
ସ୍ଥିର ବୃକ୍ଷ *ବୃକ୍ଷ_free_list;
#endif
ସ୍ଥିର alloca_list_type *alloca_list;
ସ୍ଥିର jmp_list_type *jmp_list;

ସ୍ଥିର unsigned ଅକ୍ଷର inited;
ସ୍ଥିର unsigned ଅକ୍ଷର print_warn_ptr_add;
ସ୍ଥିର unsigned ଅକ୍ଷର print_calls;
ସ୍ଥିର unsigned ଅକ୍ଷର print_heap;
ସ୍ଥିର unsigned ଅକ୍ଷର print_statistic;
ସ୍ଥିର unsigned ଅକ୍ଷର no_strdup;
ସ୍ଥିର unsigned ଅକ୍ଷର use_sem;
ସ୍ଥିର _Atomic ପୂର୍ଣ୍ଣସଂଖ୍ୟା never_fatal;
#ଯଦି HAVE_TLS_FUNC
#ଯଦି defined(_WIN32)
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_checking = 0;
ସ୍ଥିର DWORD no_checking_ଚାବି;
#define NO_CHECKING_CHECK() ଯଦି (!p) {                                         \
                                  p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) LocalAlloc(LPTR, ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));  \
                                  ଯଦି (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_Set_ମୂଲ୍ୟ(no_checking_ଚାବି, p);            \
                            }
#define NO_CHECKING_GET()   ({ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = Tls_Get_ମୂଲ୍ୟ(no_checking_ଚାବି);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = Tls_Get_ମୂଲ୍ୟ(no_checking_ଚାବି);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#ଅନ୍ୟଥା
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_checking = 0;
ସ୍ଥିର pthread_key_t no_checking_ଚାବି;
#define NO_CHECKING_CHECK() ଯଦି (!p) {                                         \
                                  p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) BOUND_MALLOC(ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));      \
                                  ଯଦି (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_ଚାବି, p);    \
                            }
#define NO_CHECKING_GET()   ({ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = pthread_getspecific(no_checking_ଚାବି); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#define NO_CHECKING_SET(v)  { ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = pthread_getspecific(no_checking_ଚାବି);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#endif
#ନଚେତଯଦି HAVE_TLS_VAR
ସ୍ଥିର __thread ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#ଅନ୍ୟଥା
ସ୍ଥିର _Atomic ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_checking = 0;
#define NO_CHECKING_GET()  no_checking
#define NO_CHECKING_SET(v) no_checking = v 
#endif
ସ୍ଥିର ଅକ୍ଷର exec[100];

#ଯଦି BOUND_STATISTIC
ସ୍ଥିର unsigned long long bound_ptr_add_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir1_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir2_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir4_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir8_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir12_ଗଣନା;
ସ୍ଥିର unsigned long long bound_ptr_indir16_ଗଣନା;
ସ୍ଥିର unsigned long long bound_local_new_ଗଣନା;
ସ୍ଥିର unsigned long long bound_local_delete_ଗଣନା;
ସ୍ଥିର unsigned long long bound_malloc_ଗଣନା;
ସ୍ଥିର unsigned long long bound_calloc_ଗଣନା;
ସ୍ଥିର unsigned long long bound_realloc_ଗଣନା;
ସ୍ଥିର unsigned long long bound_free_ଗଣନା;
ସ୍ଥିର unsigned long long bound_memalign_ଗଣନା;
ସ୍ଥିର unsigned long long bound_mmap_ଗଣନା;
ସ୍ଥିର unsigned long long bound_munmap_ଗଣନା;
ସ୍ଥିର unsigned long long bound_alloca_ଗଣନା;
ସ୍ଥିର unsigned long long bound_setjmp_ଗଣନା;
ସ୍ଥିର unsigned long long bound_longjmp_ଗଣନା;
ସ୍ଥିର unsigned long long bound_mempcy_ଗଣନା;
ସ୍ଥିର unsigned long long bound_memcmp_ଗଣନା;
ସ୍ଥିର unsigned long long bound_memmove_ଗଣନା;
ସ୍ଥିର unsigned long long bound_memset_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strlen_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strcpy_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strncpy_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strcmp_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strncmp_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strcat_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strncat_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strchr_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strrchr_ଗଣନା;
ସ୍ଥିର unsigned long long bound_strdup_ଗଣନା;
ସ୍ଥିର unsigned long long bound_not_found;
#define INCR_ଗଣନା(x)          ++x
#ଅନ୍ୟଥା
#define INCR_ଗଣନା(x)
#endif
#ଯଦି BOUND_STATISTIC_SPLAY
ସ୍ଥିର unsigned long long bound_splay;
ସ୍ଥିର unsigned long long bound_splay_end;
ସ୍ଥିର unsigned long long bound_splay_ଭର୍ତ୍ତି;
ସ୍ଥିର unsigned long long bound_splay_delete;
#define INCR_ଗଣନା_SPLAY(x)    ++x
#ଅନ୍ୟଥା
#define INCR_ଗଣନା_SPLAY(x)
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_backtrace(ଅଚଳ ଅକ୍ଷର *fmt, ...);

/* print a bound error message */
#define bound_warning(...) \
    କର {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } ଯେତେବେଳେ (0)

#define bound_error(...)            \
    କର {                            \
        bound_warning(__VA_ARGS__); \
        ଯଦି (never_fatal == 0)       \
            exit(255);              \
    } ଯେତେବେଳେ (0)

#define bounds_loc(fp, ...) \
    କର {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } ଯେତେବେଳେ (0)

ସ୍ଥିର ଶୂନ୍ୟ bound_alloc_error(ଅଚଳ ଅକ୍ଷର *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    exit (1);
}

ସ୍ଥିର ଶୂନ୍ୟ bound_not_found_warning(ଅଚଳ ଅକ୍ଷର *file, ଅଚଳ ଅକ୍ଷର *function,
                                    ଶୂନ୍ୟ *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
ଶୂନ୍ୟ __bounds_checking (ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_check)
{
#ଯଦି HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_SET(NO_CHECKING_GET() + no_check);
#ଅନ୍ୟଥା
    atomic_fetch_add (&no_checking, no_check);
#endif
}

ଶୂନ୍ୟ __bound_checking_lock(ଶୂନ୍ୟ)
{
    WAIT_SEM ();
}

ଶୂନ୍ୟ __bound_checking_unlock(ଶୂନ୍ୟ)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
ଶୂନ୍ୟ __bound_never_fatal (ପୂର୍ଣ୍ଣସଂଖ୍ୟା neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
ଶୂନ୍ୟ * __bound_ptr_add(ଶୂନ୍ୟ *p, size_t offset)
{
    size_t addr = (size_t)p;

    ଯଦି (NO_CHECKING_GET())
        ଫେରନ୍ତୁ p + offset;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)offset);

    WAIT_SEM ();
    INCR_ଗଣନା(bound_ptr_add_ଗଣନା);
    ଯଦି (ବୃକ୍ଷ_2) {
        addr -= ବୃକ୍ଷ_2->start;
        ଯଦି (addr >= ବୃକ୍ଷ_2->size) {
            addr = (size_t)p;
            ବୃକ୍ଷ_2 = splay (addr, ବୃକ୍ଷ_2);
            addr -= ବୃକ୍ଷ_2->start;
        }
        ଯଦି (addr >= ବୃକ୍ଷ_2->size) {
            addr = (size_t)p;
            ବୃକ୍ଷ_2 = splay_end (addr, ବୃକ୍ଷ_2);
            addr -= ବୃକ୍ଷ_2->start;
        }
        ଯଦି (addr <= ବୃକ୍ଷ_2->size) {
            ଯଦି (ବୃକ୍ଷ_2->is_invalid || addr + offset > ବୃକ୍ଷ_2->size) {
                POST_SEM ();
                ଯଦି (print_warn_ptr_add)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + offset, (long)ବୃକ୍ଷ_2->start,
                                  (long)(ବୃକ୍ଷ_2->start + ବୃକ୍ଷ_2->size - 1));
                ଯଦି (never_fatal <= 0)
                    ଫେରନ୍ତୁ INVALID_POINTER; /* return an invalid pointer */
                ଫେରନ୍ତୁ p + offset;
            }
        }
        ଅନ୍ୟଥା ଯଦି (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_ଗଣନା(bound_not_found);
            POST_SEM ();
            bound_not_found_warning (__FILE__, __FUNCTION__, p);
            ଫେରନ୍ତୁ p + offset;
        }
    }
    POST_SEM ();
    ଫେରନ୍ତୁ p + offset;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#define BOUND_PTR_INDIR(dsize)                                                 \
ଶୂନ୍ୟ * __bound_ptr_indir ## dsize (ଶୂନ୍ୟ *p, size_t offset)                     \
{                                                                              \
    size_t addr = (size_t)p;                                                   \
                                                                               \
    ଯଦି (NO_CHECKING_GET())                                                     \
        ଫେରନ୍ତୁ p + offset;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (unsigned long)offset);                 \
    WAIT_SEM ();                                                               \
    INCR_ଗଣନା(bound_ptr_indir ## dsize ## ଗଣନା_2);                            \
    ଯଦି (ବୃକ୍ଷ_2) {                                                                \
        addr -= ବୃକ୍ଷ_2->start;                                                   \
        ଯଦି (addr >= ବୃକ୍ଷ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            ବୃକ୍ଷ_2 = splay (addr, ବୃକ୍ଷ_2);                                         \
            addr -= ବୃକ୍ଷ_2->start;                                               \
        }                                                                      \
        ଯଦି (addr >= ବୃକ୍ଷ_2->size) {                                              \
            addr = (size_t)p;                                                  \
            ବୃକ୍ଷ_2 = splay_end (addr, ବୃକ୍ଷ_2);                                     \
            addr -= ବୃକ୍ଷ_2->start;                                               \
        }                                                                      \
        ଯଦି (addr <= ବୃକ୍ଷ_2->size) {                                              \
            ଯଦି (ବୃକ୍ଷ_2->is_invalid || addr + offset + dsize > ବୃକ୍ଷ_2->size) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + offset, dsize, (long)ବୃକ୍ଷ_2->start,            \
                              (long)(ବୃକ୍ଷ_2->start + ବୃକ୍ଷ_2->size - 1));           \
                ଯଦି (never_fatal <= 0)                                          \
                    ଫେରନ୍ତୁ INVALID_POINTER; /* return an invalid pointer */    \
                ଫେରନ୍ତୁ p + offset;                                             \
            }                                                                  \
        }                                                                      \
        ଅନ୍ୟଥା {                                                                 \
            INCR_ଗଣନା(bound_not_found);                                       \
            POST_SEM ();                                                       \
            bound_not_found_warning (__FILE__, __FUNCTION__, p);               \
            ଫେରନ୍ତୁ p + offset;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    ଫେରନ୍ତୁ p + offset;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ଯଦି (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#pragma GCC diagnostic ଠେଲ
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

/* return the frame pointer of the caller */
#define GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
ଶୂନ୍ୟ FASTCALL __bound_local_new(ଶୂନ୍ୟ *p1) 
{
    size_t addr, fp, *p = p1;

    ଯଦି (NO_CHECKING_GET())
         ଫେରନ୍ତୁ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ଶୂନ୍ୟ *)fp);
    WAIT_SEM ();
    ଯେତେବେଳେ ((addr = p[0])) {
        INCR_ଗଣନା(bound_local_new_ଗଣନା);
        ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି(addr + fp, p[1], ବୃକ୍ଷ_2);
        p += 2;
    }
    POST_SEM ();
#ଯଦି BOUND_DEBUG
    ଯଦି (print_calls) {
        p = p1;
        ଯେତେବେଳେ ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (ଶୂନ୍ୟ *) (addr + fp), (unsigned long) p[1]);
            p += 2;
        }
    }
#endif
}

/* called when leaving a function to delete all the local regions */
ଶୂନ୍ୟ FASTCALL __bound_local_delete(ଶୂନ୍ୟ *p1) 
{
    size_t addr, fp, *p = p1;

    ଯଦି (NO_CHECKING_GET())
         ଫେରନ୍ତୁ;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (ଶୂନ୍ୟ *)fp);
    WAIT_SEM ();
    ଯେତେବେଳେ ((addr = p[0])) {
        INCR_ଗଣନା(bound_local_delete_ଗଣନା);
        ବୃକ୍ଷ_2 = splay_delete(addr + fp, ବୃକ୍ଷ_2);
        p += 2;
    }
    ଯଦି (alloca_list) {
        alloca_list_type *last = ଖାଲି;
        alloca_list_type *cur = alloca_list;

        କର {
            ଯଦି (cur->fp == fp) {
                ଯଦି (last)
                    last->next = cur->next;
                ଅନ୍ୟଥା
                    alloca_list = cur->next;
                ବୃକ୍ଷ_2 = splay_delete ((size_t) cur->p, ବୃକ୍ଷ_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = last ? last->next : alloca_list;
             }
             ଅନ୍ୟଥା {
                 last = cur;
                 cur = cur->next;
             }
        } ଯେତେବେଳେ (cur);
    }
    ଯଦି (jmp_list) {
        jmp_list_type *last = ଖାଲି;
        jmp_list_type *cur = jmp_list;

        କର {
            ଯଦି (cur->fp == fp) {
                ଯଦି (last)
                    last->next = cur->next;
                ଅନ୍ୟଥା
                    jmp_list = cur->next;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = last ? last->next : jmp_list;
            }
            ଅନ୍ୟଥା {
                last = cur;
                cur = cur->next;
            }
        } ଯେତେବେଳେ (cur);
    }

    POST_SEM ();
#ଯଦି BOUND_DEBUG
    ଯଦି (print_calls) {
        p = p1;
        ଯେତେବେଳେ ((addr = p[0])) {
            ଯଦି (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ଶୂନ୍ୟ *) (addr + fp), (unsigned long) p[1]);
            }
            p+= 2;
        }
    }
#endif
}

/* used by alloca */
ଶୂନ୍ୟ __bound_new_region(ଶୂନ୍ୟ *p, size_t size)
{
    size_t fp;
    alloca_list_type *last;
    alloca_list_type *cur;
    alloca_list_type *new;

    ଯଦି (NO_CHECKING_GET())
        ଫେରନ୍ତୁ;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (unsigned long)size);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (ଆକାର (alloca_list_type));
    WAIT_SEM ();
    INCR_ଗଣନା(bound_alloca_ଗଣନା);
    last = ଖାଲି;
    cur = alloca_list;
    ଯେତେବେଳେ (cur) {
#ଯଦି defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା align = 4;
#ନଚେତଯଦି defined(__arm__)
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା align = 8;
#ଅନ୍ୟଥା
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା align = 16;
#endif
        ଶୂନ୍ୟ *cure = (ଶୂନ୍ୟ *)((ଅକ୍ଷର *)cur->p + ((cur->size + align) & -align));
        ଶୂନ୍ୟ *pe = (ଶୂନ୍ୟ *)((ଅକ୍ଷର *)p + ((size + align) & -align));
        ଯଦି (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ଯଦି (last)
                last->next = cur->next;
            ଅନ୍ୟଥା
                alloca_list = cur->next;
            ବୃକ୍ଷ_2 = splay_delete((size_t)cur->p, ବୃକ୍ଷ_2);
            ଭାଙ୍ଗ;
        }
        last = cur;
        cur = cur->next;
    }
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t)p, size, ବୃକ୍ଷ_2);
    ଯଦି (new) {
        new->fp = fp;
        new->p = p;
        new->size = size;
        new->next = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ଯଦି (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

ଶୂନ୍ୟ __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    ଶୂନ୍ୟ *e = (ଶୂନ୍ୟ *) env;

    ଯଦି (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_ଗଣନା(bound_setjmp_ଗଣନା);
        jl = jmp_list;
        ଯେତେବେଳେ (jl) {
            ଯଦି (jl->penv == e)
                ଭାଙ୍ଗ;
            jl = jl->next;
        }
        ଯଦି (jl == ଖାଲି) {
            jl = BOUND_MALLOC (ଆକାର (jmp_list_type));
            ଯଦି (jl) {
                jl->penv = e;
                jl->next = jmp_list;
                jmp_list = jl;
            }
        }
        ଯଦି (jl) {
            size_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->end_fp = (size_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

ସ୍ଥିର ଶୂନ୍ୟ __bound_long_jump(jmp_buf env, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig, ଅଚଳ ଅକ୍ଷର *func)
{
    jmp_list_type *jl;
    ଶୂନ୍ୟ *e;
    BOUND_TID_TYPE tid;

    ଯଦି (NO_CHECKING_GET() == 0) {
        e = (ଶୂନ୍ୟ *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_ଗଣନା(bound_longjmp_ଗଣନା);
        jl = jmp_list;
        ଯେତେବେଳେ (jl) {
            ଯଦି (jl->penv == e && jl->tid == tid) {
                size_t start_fp = (size_t)__builtin_frame_address(0);
                size_t end_fp = jl->end_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *last = ଖାଲି;

                ଯେତେବେଳେ (cur->penv != e || cur->tid != tid) {
                    ଯଦି (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ଯଦି (last)
                            last->next = cur->next;
                        ଅନ୍ୟଥା
                            jmp_list = cur->next;
                        BOUND_FREE (cur);
                        cur = last ? last->next : jmp_list;
                    }
                    ଅନ୍ୟଥା {
                        last = cur;
                        cur = cur->next;
                    }
                }
                ପାଇଁ (;;) {
                    ବୃକ୍ଷ *t = ବୃକ୍ଷ_2;
                    alloca_list_type *last;
                    alloca_list_type *cur;

                    ଯେତେବେଳେ (t && (t->start < start_fp || t->start > end_fp))
                        ଯଦି (t->start < start_fp)
                            t = t->ଡାହାଣ;
                        ଅନ୍ୟଥା
                            t = t->ବାମ;
                    ଯଦି (t == ଖାଲି)
                        ଭାଙ୍ଗ;
                    last = ଖାଲି;
                    cur = alloca_list;
                    ଯେତେବେଳେ (cur) {
                         ଯଦି ((size_t) cur->p == t->start) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ଯଦି (last)
                                 last->next = cur->next;
                             ଅନ୍ୟଥା
                                 alloca_list = cur->next;
                             BOUND_FREE (cur);
                             ଭାଙ୍ଗ;
                         }
                         last = cur;
                         cur = cur->next;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (ଶୂନ୍ୟ *) t->start);
                    ବୃକ୍ଷ_2 = splay_delete(t->start, ବୃକ୍ଷ_2);
                }
                ଭାଙ୍ଗ;
            }
            jl = jl->next;
        }
        POST_SEM();
    }
#ଯଦି !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#endif
    longjmp (env, val);
}

ଶୂନ୍ୟ __bound_longjmp(jmp_buf env, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ଯଦି !defined(_WIN32)
ଶୂନ୍ୟ __bound_siglongjmp(jmp_buf env, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#endif

#ଯଦି (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic କାଢ଼
#endif

ଶୂନ୍ୟ __bound_init(size_t *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା mode)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            mode < 0 ? "lazy" : mode == 0 ? "normal use" : "for -run");

    ଯଦି (inited) {
        WAIT_SEM();
        ଯାଅ add_bounds;
    }
    inited = 1;

#ଯଦି HAVE_TLS_FUNC
#ଯଦି defined(_WIN32)
    no_checking_ଚାବି = TlsAlloc();
    Tls_Set_ମୂଲ୍ୟ(no_checking_ଚାବି, &no_checking);
#ଅନ୍ୟଥା
    pthread_key_create(&no_checking_ଚାବି, ଖାଲି);
    pthread_setspecific(no_checking_ଚାବି, &no_checking);
#endif
#endif
    NO_CHECKING_SET(1);

    print_warn_ptr_add = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ଖାଲି;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ଖାଲି;
    print_heap = getenv ("TCC_BOUNDS_PRINT_HEAP") != ଖାଲି;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ଖାଲି;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ଖାଲି;

    INIT_SEM ();

#ଯଦି MALLOC_REDIR
    {
        ଶୂନ୍ୟ *addr = mode > 0 ? RTLD_DEFAULT : RTLD_NEXT;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(ଶୂନ୍ୟ **) (&malloc_redir) = dlsym (addr, "malloc");
        ଯଦି (malloc_redir == ଖାଲି) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(ଶୂନ୍ୟ **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(ଶୂନ୍ୟ **) (&calloc_redir) = dlsym (addr, "calloc");
        *(ଶୂନ୍ୟ **) (&free_redir) = dlsym (addr, "free");
        *(ଶୂନ୍ୟ **) (&realloc_redir) = dlsym (addr, "realloc");
        *(ଶୂନ୍ୟ **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        ଯଦି (malloc_redir == ଖାଲି || free_redir == ଖାଲି)
            bound_alloc_error ("Cannot redirect malloc/free");
#ଯଦି HAVE_PTHREAD_CREATE
        *(ଶୂନ୍ୟ **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ଯଦି (pthread_create_redir == ଖାଲି)
            bound_alloc_error ("Cannot redirect pthread_create");
#endif
#ଯଦି HAVE_SIGNAL
        *(ଶୂନ୍ୟ **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ଯଦି (signal_redir == ଖାଲି)
            bound_alloc_error ("Cannot redirect signal");
#endif
#ଯଦି HAVE_SIGACTION
        *(ଶୂନ୍ୟ **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ଯଦି (sigaction_redir == ଖାଲି)
            bound_alloc_error ("Cannot redirect sigaction");
#endif
#ଯଦି HAVE_FORK
        *(ଶୂନ୍ୟ **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ଯଦି (fork_redir == ଖାଲି)
            bound_alloc_error ("Cannot redirect fork");
#endif
    }
#endif

#ifdef __linux__
    {
        FILE *fp;
        unsigned ଅକ୍ଷର found;
        unsigned long start;
        unsigned long end;
        unsigned long ad =
            (unsigned long) __builtin_return_address(0);
        ଅକ୍ଷର ଧାଡ଼ି[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ଯଦି (fp) {
            memset (exec, 0, ଆକାର(exec));
            fread (exec, 1, ଆକାର(exec) - 2, fp);
            ଯଦି (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        found = 0;
        fp = fopen ("/proc/self/maps", "r");
        ଯଦି (fp) {
            ଯେତେବେଳେ (fgets (ଧାଡ଼ି, ଆକାର(ଧାଡ଼ି), fp)) {
                ଯଦି (sscanf (ଧାଡ଼ି, "%lx-%lx", &start, &end) == 2 &&
                            ad >= start && ad < end) {
                    found = 1;
                    ଭାଙ୍ଗ;
                }
                ଯଦି (strstr (ଧାଡ଼ି,"[heap]"))
                    ଭାଙ୍ଗ;
            }
            fclose (fp);
        }
        ଯଦି (found == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#endif

    WAIT_SEM ();

#ଯଦି HAVE_CTYPE
#ifdef __APPLE__
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) &_DefaultRuneLocale,
                        ଆକାର (_DefaultRuneLocale), ବୃକ୍ଷ_2);
#ଅନ୍ୟଥା
    /* XXX: Does not work if locale is changed */
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) __ctype_b_loc(),
                        ଆକାର (unsigned short *), ବୃକ୍ଷ_2);
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) (*__ctype_b_loc() - 128),
                        384 * ଆକାର (unsigned short), ବୃକ୍ଷ_2);
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) __ctype_tolower_loc(),
                        ଆକାର (__int32_t *), ବୃକ୍ଷ_2);
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) (*__ctype_tolower_loc() - 128),
                        384 * ଆକାର (__int32_t), ବୃକ୍ଷ_2);
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) __ctype_toupper_loc(),
                        ଆକାର (__int32_t *), ବୃକ୍ଷ_2);
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) (*__ctype_toupper_loc() - 128),
                        384 * ଆକାର (__int32_t), ବୃକ୍ଷ_2);
#endif
#endif
#ଯଦି HAVE_ERRNO
    ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) (&errno), ଆକାର (ପୂର୍ଣ୍ଣସଂଖ୍ୟା), ବୃକ୍ଷ_2);
#endif

add_bounds:
    ଯଦି (!p)
        ଯାଅ no_bounds;

    /* add all static bound check values */
    ଯେତେବେଳେ (p[0] != 0) {
        ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି(p[0], p[1], ବୃକ୍ଷ_2);
#ଯଦି BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (ଶୂନ୍ୟ *) p[0], (unsigned long) p[1]);
#endif
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_SET(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

ଶୂନ୍ୟ
#ଯଦି (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#endif
__bound_main_arg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **envp)
{
    __bound_init (0, -1);
    ଯଦି (argc && argv) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

        WAIT_SEM ();
        ପାଇଁ (i = 0; i < argc; i++)
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) argv[i], strlen (argv[i]) + 1, ବୃକ୍ଷ_2);
        ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) argv, (argc + 1) * ଆକାର(ଅକ୍ଷର *), ବୃକ୍ଷ_2);
        POST_SEM ();
#ଯଦି BOUND_DEBUG
        ଯଦି (print_calls) {
            ପାଇଁ (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (unsigned long)(strlen (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((argc + 1) * ଆକାର(ଅକ୍ଷର *)));
        }
#endif
    }

    ଯଦି (envp && *envp) {
        ଅକ୍ଷର **p = envp;

        WAIT_SEM ();
        ଯେତେବେଳେ (*p) {
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) *p, strlen (*p) + 1, ବୃକ୍ଷ_2);
            ++p;
        }
        ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) envp, (++p - envp) * ଆକାର(ଅକ୍ଷର *), ବୃକ୍ଷ_2);
        POST_SEM ();
#ଯଦି BOUND_DEBUG
        ଯଦି (print_calls) {
            p = envp;
            ଯେତେବେଳେ (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (unsigned long)(strlen (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((++p - envp) * ଆକାର(ଅକ୍ଷର *)));
        }
#endif
    }
}

ଶୂନ୍ୟ __attribute__((destructor)) __bound_exit(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର * ଅଚଳ alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ଯଦି (inited) {
#ଯଦି !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ଯଦି (print_heap) {
            ବାହ୍ୟ ଶୂନ୍ୟ __libc_freeres (ଶୂନ୍ୟ);
            __libc_freeres ();
        }
#endif

        NO_CHECKING_SET(1);

        TRY_SEM ();
        ଯେତେବେଳେ (alloca_list) {
            alloca_list_type *next = alloca_list->next;

            ବୃକ୍ଷ_2 = splay_delete ((size_t) alloca_list->p, ବୃକ୍ଷ_2);
            BOUND_FREE (alloca_list);
            alloca_list = next;
        }
        ଯେତେବେଳେ (jmp_list) {
           jmp_list_type *next  = jmp_list->next;

           BOUND_FREE (jmp_list);
           jmp_list = next;
        }
        ପାଇଁ (i = 0; i < FREE_REUSE_SIZE; i++) {
            ଯଦି (free_reuse_list[i]) {
                ବୃକ୍ଷ_2 = splay_delete ((size_t) free_reuse_list[i], ବୃକ୍ଷ_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        ଯେତେବେଳେ (ବୃକ୍ଷ_2) {
            ଯଦି (print_heap && ବୃକ୍ଷ_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[ବୃକ୍ଷ_2->type],
                         (unsigned long) ବୃକ୍ଷ_2->size);
            ବୃକ୍ଷ_2 = splay_delete (ବୃକ୍ଷ_2->start, ବୃକ୍ଷ_2);
        }
#ଯଦି ବୃକ୍ଷ_REUSE
        ଯେତେବେଳେ (ବୃକ୍ଷ_free_list) {
            ବୃକ୍ଷ *next = ବୃକ୍ଷ_free_list->ବାମ;
            BOUND_FREE (ବୃକ୍ଷ_free_list);
            ବୃକ୍ଷ_free_list = next;
        }
#endif
        POST_SEM ();
        EXIT_SEM ();
#ଯଦି HAVE_TLS_FUNC
#ଯଦି defined(_WIN32)
        TlsFree(no_checking_ଚାବି);
#ଅନ୍ୟଥା
        pthread_key_delete(no_checking_ଚାବି);
#endif
#endif
        inited = 0;
        ଯଦି (print_statistic) {
#ଯଦି BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_add_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_ଗଣନା);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_ଗଣନା);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_ଗଣନା);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_ଗଣନା);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_ଗଣନା);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_ଗଣନା);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_ଗଣନା);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_ଗଣନା);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_ଗଣନା);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_ଗଣନା);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_ଗଣନା);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_ଗଣନା);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_ଗଣନା);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_ଗଣନା);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_ଗଣନା);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_ଗଣନା);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_ଗଣନା);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_ଗଣନା);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_ଗଣନା);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_ଗଣନା);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_ଗଣନା);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_ଗଣନା);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_ଗଣନା);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_ଗଣନା);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_ଗଣନା);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_ଗଣନା);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_ଗଣନା);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_ଗଣନା);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_found);
#endif
#ଯଦି BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_end);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_ଭର୍ତ୍ତି);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#endif
        }
    }
}

ଶୂନ୍ୟ __bound_exit_dll(size_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ଯଦି (p) {
        WAIT_SEM ();
	ଯେତେବେଳେ (p[0] != 0) {
	    ବୃକ୍ଷ_2 = splay_delete(p[0], ବୃକ୍ଷ_2);
#ଯଦି BOUND_DEBUG
            ଯଦି (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (ଶୂନ୍ୟ *) p[0], (unsigned long) p[1]);
            }
#endif
	    p += 2;
	}
        POST_SEM ();
    }
}

#ଯଦି HAVE_PTHREAD_CREATE
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ଶୂନ୍ୟ *(*start_routine) (ଶୂନ୍ୟ *);
    ଶୂନ୍ୟ *arg;
    sigset_t old_mask;
} bound_thread_create_type;

ସ୍ଥିର ଶୂନ୍ୟ *bound_thread_create(ଶୂନ୍ୟ *bdata)
{
    bound_thread_create_type *data = (bound_thread_create_type *) bdata;
    ଶୂନ୍ୟ *retval;
#ଯଦି HAVE_TLS_FUNC
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) BOUND_MALLOC(ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
  
    ଯଦି (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_ଚାବି, p);
#endif
    pthread_sigmask(SIG_SETMASK, &data->old_mask, ଖାଲି);
    retval = data->start_routine(data->arg);
#ଯଦି HAVE_TLS_FUNC
    pthread_setspecific(no_checking_ଚାବି, ଖାଲି);
    BOUND_FREE (p);
#endif
    BOUND_FREE (data);
    ଫେରନ୍ତୁ retval;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା pthread_create(pthread_t *thread, ଅଚଳ pthread_attr_t *attr,
                   ଶୂନ୍ୟ *(*start_routine) (ଶୂନ୍ୟ *), ଶୂନ୍ୟ *arg)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval;
    bound_thread_create_type *data;
    sigset_t mask;
    sigset_t old_mask;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, &old_mask);
    data = (bound_thread_create_type *) BOUND_MALLOC(ଆକାର(bound_thread_create_type));
    ଯଦି (!data) bound_alloc_error("bound_thread_create malloc");
    data->start_routine = start_routine;
    data->arg = arg;
    data->old_mask = old_mask;
    retval = pthread_create_redir(thread, attr, bound_thread_create, data);
    pthread_sigmask(SIG_SETMASK, &old_mask, ଖାଲି);
    ଫେରନ୍ତୁ retval;
}
#endif

#ଯଦି HAVE_SIGNAL || HAVE_SIGACTION
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ {
#ଯଦି HAVE_SIGNAL
    bound_sig signal_handler;
#endif
#ଯଦି HAVE_SIGACTION
    ଶୂନ୍ୟ (*sig_handler)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    ଶୂନ୍ୟ (*sig_sigaction)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, siginfo_t *, ଶୂନ୍ୟ *);
#endif
} bound_sig_type;

ସ୍ଥିର unsigned ଅକ୍ଷର bound_sig_used[NSIG];
ସ୍ଥିର bound_sig_type bound_sig_data[NSIG];
#endif

#ଯଦି HAVE_SIGNAL
ସ୍ଥିର ଶୂନ୍ୟ signal_handler(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig ସଙ୍କେତ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ଯଦି (retval != SIG_ERR) {
        ଯଦି (bound_sig_used[signum])
            retval = bound_sig_data[signum].signal_handler;
        ଯଦି (handler) {
            bound_sig_used[signum] = 1;
            bound_sig_data[signum].signal_handler = handler;
        }
    }
    ଫେରନ୍ତୁ retval;
}
#endif

#ଯଦି HAVE_SIGACTION
ସ୍ଥିର ଶୂନ୍ୟ sig_handler(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_handler(sig);
   __bounds_checking(-1);
}

ସ୍ଥିର ଶୂନ୍ୟ sig_sigaction(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig, siginfo_t *info, ଶୂନ୍ୟ *ucontext)
{
   __bounds_checking(1);
   bound_sig_data[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା sigaction(ପୂର୍ଣ୍ଣସଂଖ୍ୟା signum, ଅଚଳ ସଂରଚନା sigaction *act, ସଂରଚନା sigaction *oldact)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval;
    ସଂରଚନା sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ଯଦି (sigaction_redir == ଖାଲି)
        __bound_init(0,-1);

    ଯଦି (act) {
        nact = *act;
        ଯଦି (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        ଅନ୍ୟଥା
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    ଅନ୍ୟଥା
        retval = sigaction_redir(signum, act, &oact);
    ଯଦି (retval >= 0) {
        ଯଦି (bound_sig_used[signum]) {
            ଯଦି (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_data[signum].sig_sigaction;
            ଅନ୍ୟଥା
                oact.sa_handler = bound_sig_data[signum].sig_handler;
        }
        ଯଦି (oldact) {
            *oldact = oact;
        }
        ଯଦି (act) {
            bound_sig_used[signum] = 1;
            ଯଦି (act->sa_flags & SA_SIGINFO)
                bound_sig_data[signum].sig_sigaction = act->sa_sigaction;
            ଅନ୍ୟଥା
                bound_sig_data[signum].sig_handler = act->sa_handler;
        }
    }
    ଫେରନ୍ତୁ retval;
}
#endif

#ଯଦି HAVE_FORK
pid_t fork(ଶୂନ୍ୟ)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ଯଦି (retval == 0)
        INIT_SEM();
    ଅନ୍ୟଥା
        POST_SEM();
    ଫେରନ୍ତୁ retval;
}
#endif

#ଯଦି MALLOC_REDIR
ଶୂନ୍ୟ *malloc(size_t size)
#ଅନ୍ୟଥା
ଶୂନ୍ୟ *__bound_malloc(size_t size, ଅଚଳ ଶୂନ୍ୟ *caller)
#endif
{
    ଶୂନ୍ୟ *ptr;
    
#ଯଦି MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ଯଦି (malloc_redir == ଖାଲି) {
        __bound_init (0, -1);
        ଯଦି (malloc_redir == ଖାଲି) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ଯଦି (pool_index >= ଆକାର (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            ଫେରନ୍ତୁ ptr;
        }
    }
#endif
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);
    
    ଯଦି (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_malloc_ଗଣନା);

        ଯଦି (ptr) {
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି ((size_t) ptr, size ? size : size + 1, ବୃକ୍ଷ_2);
            ଯଦି (ବୃକ୍ଷ_2 && ବୃକ୍ଷ_2->start == (size_t) ptr)
                ବୃକ୍ଷ_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    ଫେରନ୍ତୁ ptr;
}

#ଯଦି MALLOC_REDIR
ଶୂନ୍ୟ *memalign(size_t align, size_t size)
#ଅନ୍ୟଥା
ଶୂନ୍ୟ *__bound_memalign(size_t align, size_t size, ଅଚଳ ଶୂନ୍ୟ *caller)
#endif
{
    ଶୂନ୍ୟ *ptr;

#ଯଦି HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, size + 1);
#ଅନ୍ୟଥା
    ଯଦି (align > 4) {
        /* XXX: handle it ? */
        ptr = ଖାଲି;
    } ଅନ୍ୟଥା {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(size + 1);
    }
#endif
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ଯଦି (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_memalign_ଗଣନା);

        ଯଦି (ptr) {
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t) ptr, size ? size : size + 1, ବୃକ୍ଷ_2);
            ଯଦି (ବୃକ୍ଷ_2 && ବୃକ୍ଷ_2->start == (size_t) ptr)
                ବୃକ୍ଷ_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    ଫେରନ୍ତୁ ptr;
}

#ଯଦି MALLOC_REDIR
ଶୂନ୍ୟ ମୁକ୍ତ(ଶୂନ୍ୟ *ptr)
#ଅନ୍ୟଥା
ଶୂନ୍ୟ __bound_free(ଶୂନ୍ୟ *ptr, ଅଚଳ ଶୂନ୍ୟ *caller)
#endif
{
    size_t addr = (size_t) ptr;
    ଶୂନ୍ୟ *p;

    ଯଦି (ptr == ଖାଲି || ବୃକ୍ଷ_2 == ଖାଲି
#ଯଦି MALLOC_REDIR
        || ((unsigned ଅକ୍ଷର *) ptr >= &initial_pool[0] &&
            (unsigned ଅକ୍ଷର *) ptr < &initial_pool[ଆକାର(initial_pool)])
#endif
        )
        ଫେରନ୍ତୁ;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ଯଦି (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_free_ଗଣନା);
        ବୃକ୍ଷ_2 = splay (addr, ବୃକ୍ଷ_2);
        ଯଦି (ବୃକ୍ଷ_2->start == addr) {
            ଯଦି (ବୃକ୍ଷ_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                ଫେରନ୍ତୁ;
            }
            ବୃକ୍ଷ_2->is_invalid = 1;
            memset (ptr, 0x5a, ବୃକ୍ଷ_2->size);
            p = free_reuse_list[free_reuse_index];
            free_reuse_list[free_reuse_index] = ptr;
            free_reuse_index = (free_reuse_index + 1) % FREE_REUSE_SIZE;
            ଯଦି (p)
                ବୃକ୍ଷ_2 = splay_delete((size_t)p, ବୃକ୍ଷ_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ଯଦି MALLOC_REDIR
ଶୂନ୍ୟ *realloc(ଶୂନ୍ୟ *ptr, size_t size)
#ଅନ୍ୟଥା
ଶୂନ୍ୟ *__bound_realloc(ଶୂନ୍ୟ *ptr, size_t size, ଅଚଳ ଶୂନ୍ୟ *caller)
#endif
{
    ଶୂନ୍ୟ *new_ptr;

    ଯଦି (size == 0) {
#ଯଦି MALLOC_REDIR
        ମୁକ୍ତ(ptr);
#ଅନ୍ୟଥା
        __bound_free(ptr, caller);
#endif
        ଫେରନ୍ତୁ ଖାଲି;
    }

    new_ptr = BOUND_REALLOC (ptr, size + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (unsigned long)size);

    ଯଦି (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_realloc_ଗଣନା);

        ଯଦି (ptr)
            ବୃକ୍ଷ_2 = splay_delete ((size_t) ptr, ବୃକ୍ଷ_2);
        ଯଦି (new_ptr) {
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି ((size_t) new_ptr, size ? size : size + 1, ବୃକ୍ଷ_2);
            ଯଦି (ବୃକ୍ଷ_2 && ବୃକ୍ଷ_2->start == (size_t) new_ptr)
                ବୃକ୍ଷ_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    ଫେରନ୍ତୁ new_ptr;
}

#ଯଦି MALLOC_REDIR
ଶୂନ୍ୟ *calloc(size_t nmemb, size_t size)
#ଅନ୍ୟଥା
ଶୂନ୍ୟ *__bound_calloc(size_t nmemb, size_t size)
#endif
{
    ଶୂନ୍ୟ *ptr;

    size *= nmemb;
#ଯଦି MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ଯଦି (malloc_redir == ଖାଲି) {
        __bound_init (0, -1);
        ଯଦି (malloc_redir == ଖାଲି) {
            ptr = &initial_pool[pool_index];
            pool_index = (pool_index + size + 15) & ~15;
            ଯଦି (pool_index >= ଆକାର (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (unsigned long)size);
            memset (ptr, 0, size);
            ଫେରନ୍ତୁ ptr;
        }
    }
#endif
    ptr = BOUND_MALLOC(size + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (unsigned long)size);

    ଯଦି (ptr) {
        memset (ptr, 0, size);
        ଯଦି (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_ଗଣନା(bound_calloc_ଗଣନା);
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି ((size_t) ptr, size ? size : size + 1, ବୃକ୍ଷ_2);
            ଯଦି (ବୃକ୍ଷ_2 && ବୃକ୍ଷ_2->start == (size_t) ptr)
                ବୃକ୍ଷ_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    ଫେରନ୍ତୁ ptr;
}

#ଯଦି !defined(_WIN32)
ଶୂନ୍ୟ *__bound_mmap (ଶୂନ୍ୟ *start, size_t size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା prot,
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, off_t offset)
{
    ଶୂନ୍ୟ *result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    result = mmap (start, size, prot, flags, fd, offset);
    ଯଦି (result && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_mmap_ଗଣନା);
        ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t)result, size, ବୃକ୍ଷ_2);
        POST_SEM ();
    }
    ଫେରନ୍ତୁ result;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_munmap (ଶୂନ୍ୟ *start, size_t size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା result;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, start, (unsigned long)size);
    ଯଦି (start && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_ଗଣନା(bound_munmap_ଗଣନା);
        ବୃକ୍ଷ_2 = splay_delete ((size_t) start, ବୃକ୍ଷ_2);
        POST_SEM ();
    }
    result = munmap (start, size);
    ଫେରନ୍ତୁ result;
}
#endif

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
ସ୍ଥିର ଶୂନ୍ୟ __bound_check(ଅଚଳ ଶୂନ୍ୟ *p, size_t size, ଅଚଳ ଅକ୍ଷର *function)
{
    ଯଦି (size != 0 && __bound_ptr_add((ଶୂନ୍ୟ *)p, size) == INVALID_POINTER) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (unsigned long)size, function);
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା check_overlap (ଅଚଳ ଶୂନ୍ୟ *p1, size_t n1,
                          ଅଚଳ ଶୂନ୍ୟ *p2, size_t n2,
                          ଅଚଳ ଅକ୍ଷର *function)
{
    ଅଚଳ ଶୂନ୍ୟ *p1e = (ଅଚଳ ଶୂନ୍ୟ *) ((ଅଚଳ ଅକ୍ଷର *) p1 + n1);
    ଅଚଳ ଶୂନ୍ୟ *p2e = (ଅଚଳ ଶୂନ୍ୟ *) ((ଅଚଳ ଅକ୍ଷର *) p2 + n2);

    ଯଦି (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (unsigned long)n1, p2, (unsigned long)n2, function);
        ଫେରନ୍ତୁ never_fatal < 0;
    }
    ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ *__bound_memcpy(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_mempcy_ଗଣନା);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ଯଦି (check_overlap(dest, n, src, n, "memcpy"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ memcpy(dest, src, n);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_memcmp(ଅଚଳ ଶୂନ୍ୟ *s1, ଅଚଳ ଶୂନ୍ୟ *s2, size_t n)
{
    ଅଚଳ unsigned ଅକ୍ଷର *u1 = (ଅଚଳ unsigned ଅକ୍ଷର *) s1;
    ଅଚଳ unsigned ଅକ୍ଷର *u2 = (ଅଚଳ unsigned ଅକ୍ଷର *) s2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ଗଣନା(bound_memcmp_ଗଣନା);
    ପାଇଁ (;;) {
        ଯଦି ((ssize_t) --n == -1)
            ଭାଙ୍ଗ;
        ଅନ୍ୟଥା ଯଦି (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ଭାଙ୍ଗ;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (ଅଚଳ ଶୂନ୍ୟ *)u1 - s1, "memcmp s1");
    __bound_check(s2, (ଅଚଳ ଶୂନ୍ୟ *)u2 - s2, "memcmp s2");
    ଫେରନ୍ତୁ retval;
}

ଶୂନ୍ୟ *__bound_memmove(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_memmove_ଗଣନା);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ଫେରନ୍ତୁ memmove(dest, src, n);
}

ଶୂନ୍ୟ *__bound_memset(ଶୂନ୍ୟ *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ଗଣନା(bound_memset_ଗଣନା);
    __bound_check(s, n, "memset");
    ଫେରନ୍ତୁ memset(s, c, n);
}

#ଯଦି defined(__arm__) && defined(__ARM_EABI__)
ଶୂନ୍ୟ *__bound___aeabi_memcpy(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_mempcy_ଗଣନା);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ଯଦି (check_overlap(dest, n, src, n, "memcpy"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ __aeabi_memcpy(dest, src, n);
}

ଶୂନ୍ୟ *__bound___aeabi_memmove(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_memmove_ଗଣନା);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ଫେରନ୍ତୁ __aeabi_memmove(dest, src, n);
}

ଶୂନ୍ୟ *__bound___aeabi_memmove4(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_memmove_ଗଣନା);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ଫେରନ୍ତୁ __aeabi_memmove4(dest, src, n);
}

ଶୂନ୍ୟ *__bound___aeabi_memmove8(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_memmove_ଗଣନା);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    ଫେରନ୍ତୁ __aeabi_memmove8(dest, src, n);
}

ଶୂନ୍ୟ *__bound___aeabi_memset(ଶୂନ୍ୟ *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (unsigned long)n);
    INCR_ଗଣନା(bound_memset_ଗଣନା);
    __bound_check(s, n, "memset");
    ଫେରନ୍ତୁ __aeabi_memset(s, c, n);
}
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strlen(ଅଚଳ ଅକ୍ଷର *s)
{
    ଅଚଳ ଅକ୍ଷର *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_ଗଣନା(bound_strlen_ଗଣନା);
    ଯେତେବେଳେ (*p++);
    __bound_check(s, p - s, "strlen");
    ଫେରନ୍ତୁ (p - s) - 1;
}

ଅକ୍ଷର *__bound_strcpy(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src)
{
    size_t len;
    ଅଚଳ ଅକ୍ଷର *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ଗଣନା(bound_strcpy_ଗଣନା);
    ଯେତେବେଳେ (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ଯଦି (check_overlap(dest, len, src, len, "strcpy"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ strcpy (dest, src);
}

ଅକ୍ଷର *__bound_strncpy(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src, size_t n)
{
    size_t len = n;
    ଅଚଳ ଅକ୍ଷର *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_strncpy_ଗଣନା);
    ଯେତେବେଳେ (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ଯଦି (check_overlap(dest, len, src, len, "strncpy"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ strncpy(dest, src, n);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strcmp(ଅଚଳ ଅକ୍ଷର *s1, ଅଚଳ ଅକ୍ଷର *s2)
{
    ଅଚଳ unsigned ଅକ୍ଷର *u1 = (ଅଚଳ unsigned ଅକ୍ଷର *) s1;
    ଅଚଳ unsigned ଅକ୍ଷର *u2 = (ଅଚଳ unsigned ଅକ୍ଷର *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_ଗଣନା(bound_strcmp_ଗଣନା);
    ଯେତେବେଳେ (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((ଅଚଳ ଅକ୍ଷର *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((ଅଚଳ ଅକ୍ଷର *)u2 - s2) + 1, "strcmp s2");
    ଫେରନ୍ତୁ *u1 - *u2;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __bound_strncmp(ଅଚଳ ଅକ୍ଷର *s1, ଅଚଳ ଅକ୍ଷର *s2, size_t n)
{
    ଅଚଳ unsigned ଅକ୍ଷର *u1 = (ଅଚଳ unsigned ଅକ୍ଷର *) s1;
    ଅଚଳ unsigned ଅକ୍ଷର *u2 = (ଅଚଳ unsigned ଅକ୍ଷର *) s2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (unsigned long)n);
    INCR_ଗଣନା(bound_strncmp_ଗଣନା);
    କର {
        ଯଦି ((ssize_t) --n == -1)
            ଭାଙ୍ଗ;
        ଅନ୍ୟଥା ଯଦି (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ଭାଙ୍ଗ;
        }
        ++u2;
    } ଯେତେବେଳେ (*u1++);
    __bound_check(s1, (ଅଚଳ ଅକ୍ଷର *)u1 - s1, "strncmp s1");
    __bound_check(s2, (ଅଚଳ ଅକ୍ଷର *)u2 - s2, "strncmp s2");
    ଫେରନ୍ତୁ retval;
}

ଅକ୍ଷର *__bound_strcat(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src)
{
    ଅକ୍ଷର *r = dest;
    ଅଚଳ ଅକ୍ଷର *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_ଗଣନା(bound_strcat_ଗଣନା);
    ଯେତେବେଳେ (*dest++);
    ଯେତେବେଳେ (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ଯଦି (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ strcat(r, s);
}

ଅକ୍ଷର *__bound_strncat(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src, size_t n)
{
    ଅକ୍ଷର *r = dest;
    ଅଚଳ ଅକ୍ଷର *s = src;
    size_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (unsigned long)n);
    INCR_ଗଣନା(bound_strncat_ଗଣନା);
    ଯେତେବେଳେ (*dest++);
    ଯେତେବେଳେ (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ଯଦି (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        ଫେରନ୍ତୁ dest;
    ଫେରନ୍ତୁ strncat(r, s, n);
}

ଅକ୍ଷର *__bound_strchr(ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଅଚଳ unsigned ଅକ୍ଷର *str = (ଅଚଳ unsigned ଅକ୍ଷର *) s;
    unsigned ଅକ୍ଷର ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ଗଣନା(bound_strchr_ଗଣନା);
    ଯେତେବେଳେ (*str) {
        ଯଦି (*str == ch)
            ଭାଙ୍ଗ;
        ++str;
    }
    __bound_check(s, ((ଅଚଳ ଅକ୍ଷର *)str - s) + 1, "strchr");
    ଫେରନ୍ତୁ *str == ch ? (ଅକ୍ଷର *) str : ଖାଲି;
}

ଅକ୍ଷର *__bound_strrchr(ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଅଚଳ unsigned ଅକ୍ଷର *str = (ଅଚଳ unsigned ଅକ୍ଷର *) s;
    unsigned ଅକ୍ଷର ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_ଗଣନା(bound_strrchr_ଗଣନା);
    ଯେତେବେଳେ (*str++);
    __bound_check(s, (ଅଚଳ ଅକ୍ଷର *)str - s, "strrchr");
    ଯେତେବେଳେ (str != (ଅଚଳ unsigned ଅକ୍ଷର *)s) {
        ଯଦି (*--str == ch)
            ଭାଙ୍ଗ;
    }
    __bound_check(s, (ଅଚଳ ଅକ୍ଷର *)str - s, "strrchr");
    ଫେରନ୍ତୁ *str == ch ? (ଅକ୍ଷର *) str : ଖାଲି;
}

ଅକ୍ଷର *__bound_strdup(ଅଚଳ ଅକ୍ଷର *s)
{
    ଅଚଳ ଅକ୍ଷର *p = s;
    ଅକ୍ଷର *new;

    INCR_ଗଣନା(bound_strdup_ଗଣନା);
    ଯେତେବେଳେ (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (unsigned long)(p -s));
    ଯଦି (new) {
        ଯଦି (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            ବୃକ୍ଷ_2 = splay_ଭର୍ତ୍ତି((size_t)new, p - s, ବୃକ୍ଷ_2);
            ଯଦି (ବୃକ୍ଷ_2 && ବୃକ୍ଷ_2->start == (size_t) new)
                ବୃକ୍ଷ_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        memcpy (new, s, p - s);
    }
    ଫେରନ୍ତୁ new;
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

ସ୍ଥିର ବୃକ୍ଷ * splay (size_t addr, ବୃକ୍ଷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    ବୃକ୍ଷ N, *l, *r, *y;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା comp;
    
    INCR_ଗଣନା_SPLAY(bound_splay);
    ଯଦି (t == ଖାଲି) ଫେରନ୍ତୁ t;
    N.ବାମ = N.ଡାହାଣ = ଖାଲି;
    l = r = &N;
 
    ପାଇଁ (;;) {
        comp = compare(addr, t->start, t->size);
        ଯଦି (comp < 0) {
            y = t->ବାମ;
            ଯଦି (y == ଖାଲି) ଭାଙ୍ଗ;
            ଯଦି (compare(addr, y->start, y->size) < 0) {
                t->ବାମ = y->ଡାହାଣ;                    /* rotate right */
                y->ଡାହାଣ = t;
                t = y;
                ଯଦି (t->ବାମ == ଖାଲି) ଭାଙ୍ଗ;
            }
            r->ବାମ = t;                               /* link right */
            r = t;
            t = t->ବାମ;
        } ଅନ୍ୟଥା ଯଦି (comp > 0) {
            y = t->ଡାହାଣ;
            ଯଦି (y == ଖାଲି) ଭାଙ୍ଗ;
            ଯଦି (compare(addr, y->start, y->size) > 0) {
                t->ଡାହାଣ = y->ବାମ;                    /* rotate left */
                y->ବାମ = t;
                t = y;
                ଯଦି (t->ଡାହାଣ == ଖାଲି) ଭାଙ୍ଗ;
            }
            l->ଡାହାଣ = t;                              /* link left */
            l = t;
            t = t->ଡାହାଣ;
        } ଅନ୍ୟଥା {
            ଭାଙ୍ଗ;
        }
    }
    l->ଡାହାଣ = t->ବାମ;                                /* assemble */
    r->ବାମ = t->ଡାହାଣ;
    t->ବାମ = N.ଡାହାଣ;
    t->ଡାହାଣ = N.ବାମ;

    ଫେରନ୍ତୁ t;
}

#define compare_end(start,tend) (start < tend ? -1 : \
                                 start > tend  ? 1 : 0)

ସ୍ଥିର ବୃକ୍ଷ * splay_end (size_t addr, ବୃକ୍ଷ *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    ବୃକ୍ଷ N, *l, *r, *y;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା comp;
    
    INCR_ଗଣନା_SPLAY(bound_splay_end);
    ଯଦି (t == ଖାଲି) ଫେରନ୍ତୁ t;
    N.ବାମ = N.ଡାହାଣ = ଖାଲି;
    l = r = &N;
 
    ପାଇଁ (;;) {
        comp = compare_end(addr, t->start + t->size);
        ଯଦି (comp < 0) {
            y = t->ବାମ;
            ଯଦି (y == ଖାଲି) ଭାଙ୍ଗ;
            ଯଦି (compare_end(addr, y->start + y->size) < 0) {
                t->ବାମ = y->ଡାହାଣ;                    /* rotate right */
                y->ଡାହାଣ = t;
                t = y;
                ଯଦି (t->ବାମ == ଖାଲି) ଭାଙ୍ଗ;
            }
            r->ବାମ = t;                               /* link right */
            r = t;
            t = t->ବାମ;
        } ଅନ୍ୟଥା ଯଦି (comp > 0) {
            y = t->ଡାହାଣ;
            ଯଦି (y == ଖାଲି) ଭାଙ୍ଗ;
            ଯଦି (compare_end(addr, y->start + y->size) > 0) {
                t->ଡାହାଣ = y->ବାମ;                    /* rotate left */
                y->ବାମ = t;
                t = y;
                ଯଦି (t->ଡାହାଣ == ଖାଲି) ଭାଙ୍ଗ;
            }
            l->ଡାହାଣ = t;                              /* link left */
            l = t;
            t = t->ଡାହାଣ;
        } ଅନ୍ୟଥା {
            ଭାଙ୍ଗ;
        }
    }
    l->ଡାହାଣ = t->ବାମ;                                /* assemble */
    r->ବାମ = t->ଡାହାଣ;
    t->ବାମ = N.ଡାହାଣ;
    t->ଡାହାଣ = N.ବାମ;

    ଫେରନ୍ତୁ t;
}

ସ୍ଥିର ବୃକ୍ଷ * splay_ଭର୍ତ୍ତି(size_t addr, size_t size, ବୃକ୍ଷ * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    ବୃକ୍ଷ * new;

    INCR_ଗଣନା_SPLAY(bound_splay_ଭର୍ତ୍ତି);
    ଯଦି (t != ଖାଲି) {
        t = splay(addr,t);
        ଯଦି (compare(addr, t->start, t->size)==0) {
            ଫେରନ୍ତୁ t;  /* it's already there */
        }
    }
#ଯଦି ବୃକ୍ଷ_REUSE
    ଯଦି (ବୃକ୍ଷ_free_list) {
          new = ବୃକ୍ଷ_free_list;
          ବୃକ୍ଷ_free_list = new->ବାମ;
    }
    ଅନ୍ୟଥା
#endif
    {
        new = (ବୃକ୍ଷ *) BOUND_MALLOC (ଆକାର (ବୃକ୍ଷ));
    }
    ଯଦି (new == ଖାଲି) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    ଅନ୍ୟଥା {
        ଯଦି (t == ଖାଲି) {
            new->ବାମ = new->ଡାହାଣ = ଖାଲି;
        } ଅନ୍ୟଥା ଯଦି (compare(addr, t->start, t->size) < 0) {
            new->ବାମ = t->ବାମ;
            new->ଡାହାଣ = t;
            t->ବାମ = ଖାଲି;
        } ଅନ୍ୟଥା {
            new->ଡାହାଣ = t->ଡାହାଣ;
            new->ବାମ = t;
            t->ଡାହାଣ = ଖାଲି;
        }
        new->start = addr;
        new->size = size;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    ଫେରନ୍ତୁ new;
}

#define compare_destroy(start,tstart) (start < tstart ? -1 : \
                                       start > tstart  ? 1 : 0)

ସ୍ଥିର ବୃକ୍ଷ * splay_delete(size_t addr, ବୃକ୍ଷ *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    ବୃକ୍ଷ * x;

    INCR_ଗଣନା_SPLAY(bound_splay_delete);
    ଯଦି (t==ଖାଲି) ଫେରନ୍ତୁ ଖାଲି;
    t = splay(addr,t);
    ଯଦି (compare_destroy(addr, t->start) == 0) {        /* found it */
        ଯଦି (t->ବାମ == ଖାଲି) {
            x = t->ଡାହାଣ;
        } ଅନ୍ୟଥା {
            x = splay(addr, t->ବାମ);
            x->ଡାହାଣ = t->ଡାହାଣ;
        }
#ଯଦି ବୃକ୍ଷ_REUSE
        t->ବାମ = ବୃକ୍ଷ_free_list;
        ବୃକ୍ଷ_free_list = t;
#ଅନ୍ୟଥା
        BOUND_FREE(t);
#endif
        ଫେରନ୍ତୁ x;
    } ଅନ୍ୟଥା {
        ଫେରନ୍ତୁ t;                                      /* It wasn't there */
    }
}

ଶୂନ୍ୟ splay_printtree(ବୃକ୍ଷ * t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ଯଦି (t == ଖାଲି) ଫେରନ୍ତୁ;
    splay_printtree(t->ଡାହାଣ, d+1);
    ପାଇଁ (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (ଶୂନ୍ୟ *) t->start, (unsigned long) t->size,
            (unsigned)t->type, (unsigned)t->is_invalid);
    splay_printtree(t->ବାମ, d+1);
}
