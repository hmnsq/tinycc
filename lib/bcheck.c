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
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdarg.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <setjmp.h>
#అన్తర్భావ <stdatomic.h>

#ఒకవేళ !defined(__FreeBSD__) \
 && !defined(__FreeBSD_kernel__) \
 && !defined(__DragonFly__) \
 && !defined(__OpenBSD__) \
 && !defined(__APPLE__) \
 && !defined(__NetBSD__)
#అన్తర్భావ <malloc.h>
#అయితే_ముగింపు

#ఒకవేళ !defined(_WIN32)
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <sys/syscall.h>
#అయితే_ముగింపు

#అన్తర్భావ "config.h"

#నిర్వచించు BOUND_DEBUG             (1)
#నిర్వచించు BOUND_STATISTIC         (1)

#ఒకవేళ BOUND_DEBUG
 #నిర్వచించు dprintf(a...)         ఒకవేళ (print_calls) { bounds_loc(a); }
#లేకపోతే
 #నిర్వచించు dprintf(a...)
#అయితే_ముగింపు

#నిర్వచితమైతే __attribute__
  /* an __attribute__ macro is defined in the system headers */
  #నిర్వచనం_రద్దు __attribute__ 
#అయితే_ముగింపు
#నిర్వచితమైతే __i386__
#నిర్వచించు FASTCALL __attribute__((regparm(3)))
#లేకపోతే
#నిర్వచించు FASTCALL
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN32
# define DLL_EXPORT __declspec(dllexport)
#లేకపోతే
# define DLL_EXPORT
#అయితే_ముగింపు

#ఒకవేళ defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__)

#అన్తర్భావ <sys/mman.h>
#నిర్వచించు INIT_SEM()
#నిర్వచించు EXIT_SEM()
#నిర్వచించు WAIT_SEM()
#నిర్వచించు POST_SEM()
#నిర్వచించు TRY_SEM()
#నిర్వచించు HAVE_MEMALIGN          (0)
#నిర్వచించు MALLOC_REDIR           (0)
#నిర్వచించు HAVE_PTHREAD_CREATE    (0)
#నిర్వచించు HAVE_CTYPE             (0)
#నిర్వచించు HAVE_ERRNO             (0)
#నిర్వచించు HAVE_SIGNAL            (0)
#నిర్వచించు HAVE_SIGACTION         (0)
#నిర్వచించు HAVE_FORK              (0)
#నిర్వచించు HAVE_TLS_FUNC          (0)
#నిర్వచించు HAVE_TLS_VAR           (0)

#లేదావేళ defined(_WIN32)

#అన్తర్భావ <windows.h>
#అన్తర్భావ <signal.h>
స్థిర CRITICAL_SECTION bounds_sem;
#నిర్వచించు INIT_SEM()             InitializeCriticalSection(&bounds_sem)
#నిర్వచించు EXIT_SEM()             DeleteCriticalSection(&bounds_sem)
#నిర్వచించు WAIT_SEM()             EnterCriticalSection(&bounds_sem)
#నిర్వచించు POST_SEM()             LeaveCriticalSection(&bounds_sem)
#నిర్వచించు TRY_SEM()              TryEnterCriticalSection(&bounds_sem)
#నిర్వచించు HAVE_MEMALIGN          (0)
#నిర్వచించు MALLOC_REDIR           (0)
#నిర్వచించు HAVE_PTHREAD_CREATE    (0)
#నిర్వచించు HAVE_CTYPE             (0)
#నిర్వచించు HAVE_ERRNO             (0)
#నిర్వచించు HAVE_SIGNAL            (1)
#నిర్వచించు HAVE_SIGACTION         (0)
#నిర్వచించు HAVE_FORK              (0)
#నిర్వచించు HAVE_TLS_FUNC          (1)
#నిర్వచించు HAVE_TLS_VAR           (0)

#లేకపోతే

#నిర్వచించు __USE_GNU              /* get RTLD_NEXT */
#అన్తర్భావ <sys/mman.h>
#అన్తర్భావ <ctype.h>
#అన్తర్భావ <pthread.h>
#అన్తర్భావ <dlfcn.h>
#అన్తర్భావ <errno.h>
#అన్తర్భావ <signal.h>
#నిర్వచితమైతే __APPLE__
#అన్తర్భావ <dispatch/dispatch.h>
స్థిర dispatch_semaphore_t bounds_sem;
#నిర్వచించు INIT_SEM()             bounds_sem = dispatch_semaphore_create(1)
#నిర్వచించు EXIT_SEM()             dispatch_release(*(dispatch_object_t*)&bounds_sem)
#నిర్వచించు WAIT_SEM()             ఒకవేళ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_సమయం_FOREVER)
#నిర్వచించు POST_SEM()             ఒకవేళ (use_sem) dispatch_semaphore_signal(bounds_sem)
#నిర్వచించు TRY_SEM()              ఒకవేళ (use_sem) dispatch_semaphore_wait(bounds_sem, DISPATCH_సమయం_NOW)
#లేదావేళ 0
#అన్తర్భావ <semaphore.h>
స్థిర sem_t bounds_sem;
#నిర్వచించు INIT_SEM()             sem_init (&bounds_sem, 0, 1)
#నిర్వచించు EXIT_SEM()             sem_destroy (&bounds_sem)
#నిర్వచించు WAIT_SEM()             ఒకవేళ (use_sem) అయితే (sem_wait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#నిర్వచించు POST_SEM()             ఒకవేళ (use_sem) sem_post (&bounds_sem)
#నిర్వచించు TRY_SEM()              ఒకవేళ (use_sem) అయితే (sem_trywait (&bounds_sem) < 0 \
                                                   && errno == EINTR)
#లేదావేళ 0
స్థిర pthread_mutex_t bounds_mtx;
#నిర్వచించు INIT_SEM()             pthread_mutex_init (&bounds_mtx, ఖాళీ)
#నిర్వచించు EXIT_SEM()             pthread_mutex_destroy (&bounds_mtx)
#నిర్వచించు WAIT_SEM()             ఒకవేళ (use_sem) pthread_mutex_lock (&bounds_mtx)
#నిర్వచించు POST_SEM()             ఒకవేళ (use_sem) pthread_mutex_unlock (&bounds_mtx)
#నిర్వచించు TRY_SEM()              ఒకవేళ (use_sem) pthread_mutex_trylock (&bounds_mtx)
#లేకపోతే
స్థిర pthread_spinlock_t bounds_spin;
/* about 25% faster then semaphore. */
#నిర్వచించు INIT_SEM()             pthread_spin_init (&bounds_spin, 0)
#నిర్వచించు EXIT_SEM()             pthread_spin_destroy (&bounds_spin)
#నిర్వచించు WAIT_SEM()             ఒకవేళ (use_sem) pthread_spin_lock (&bounds_spin)
#నిర్వచించు POST_SEM()             ఒకవేళ (use_sem) pthread_spin_unlock (&bounds_spin)
#నిర్వచించు TRY_SEM()              ఒకవేళ (use_sem) pthread_spin_trylock (&bounds_spin)
#అయితే_ముగింపు
#నిర్వచించు HAVE_MEMALIGN          (1)
#నిర్వచించు MALLOC_REDIR           (1)
#నిర్వచించు HAVE_PTHREAD_CREATE    (1)
#నిర్వచించు HAVE_CTYPE             (1)
#నిర్వచించు HAVE_ERRNO             (1)
#నిర్వచించు HAVE_SIGNAL            (1)
#నిర్వచించు HAVE_SIGACTION         (1)
#నిర్వచించు HAVE_FORK              (1)
#ఒకవేళ defined(__APPLE__) || defined(__arm__) || defined(__GNUC__) || defined(BCHECK_నిరంతరం)
#నిర్వచించు HAVE_TLS_FUNC          (1)
#నిర్వచించు HAVE_TLS_VAR           (0)
#లేకపోతే
#నిర్వచించు HAVE_TLS_FUNC          (0)
#నిర్వచించు HAVE_TLS_VAR           (1)
#అయితే_ముగింపు
#ఒకవేళ defined CONFIG_TCC_MUSL || defined __ANDROID__
# undef HAVE_CTYPE
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ MALLOC_REDIR
స్థిర శూన్య *(*malloc_redir) (కొలత_t);
స్థిర శూన్య *(*calloc_redir) (కొలత_t, కొలత_t);
స్థిర శూన్య (*free_redir) (శూన్య *);
స్థిర శూన్య *(*realloc_redir) (శూన్య *, కొలత_t);
స్థిర గుర్తులేని పూర్ణాంకం pool_సూచీ;
స్థిర గుర్తులేని అక్షరం __attribute__((aligned(16))) initial_pool[256];
#అయితే_ముగింపు
#ఒకవేళ HAVE_MEMALIGN
స్థిర శూన్య *(*memalign_redir) (కొలత_t, కొలత_t);
#అయితే_ముగింపు
#ఒకవేళ HAVE_PTHREAD_CREATE
స్థిర పూర్ణాంకం (*pthread_create_redir) (pthread_t *thread,
                                    స్థిరరాశి pthread_attr_t *attr,
                                    శూన్య *(*ప్రారంభం_routine)(శూన్య *), శూన్య *arg);
#అయితే_ముగింపు
#ఒకవేళ HAVE_SIGNAL
రకనిర్వచనం శూన్య (*bound_sig)(పూర్ణాంకం);
స్థిర bound_sig (*signal_redir) (పూర్ణాంకం signum, bound_sig handler);
#అయితే_ముగింపు
#ఒకవేళ HAVE_SIGACTION
స్థిర పూర్ణాంకం (*sigaction_redir) (పూర్ణాంకం signum, స్థిరరాశి నిర్మాణం sigaction *act,
                               నిర్మాణం sigaction *oldact);
#అయితే_ముగింపు
#ఒకవేళ HAVE_FORK
స్థిర పూర్ణాంకం (*fork_redir) (శూన్య);
#అయితే_ముగింపు

#నిర్వచించు TCC_TYPE_NONE           (0)
#నిర్వచించు TCC_TYPE_MALLOC         (1)
#నిర్వచించు TCC_TYPE_CALLOC         (2)
#నిర్వచించు TCC_TYPE_REALLOC        (3)
#నిర్వచించు TCC_TYPE_MEMALIGN       (4)
#నిర్వచించు TCC_TYPE_STRDUP         (5)

/* this pointer is generated when bound check is incorrect */
#నిర్వచించు INVALID_సూచిక ((శూన్య *)(-2))

రకనిర్వచనం నిర్మాణం వృక్ష_కణుపు వృక్షం;
నిర్మాణం వృక్ష_కణుపు {
    వృక్షం * ఎడమ, * కుడి;
    కొలత_t ప్రారంభం;
    కొలత_t కొలత;
    గుర్తులేని అక్షరం type;
    గుర్తులేని అక్షరం is_invalid; /* true if pointers outside region are invalid */
};

రకనిర్వచనం నిర్మాణం alloca_list_struct {
    కొలత_t fp;
    శూన్య *p;
    కొలత_t కొలత;
    నిర్మాణం alloca_list_struct *తదుపరి;
} alloca_list_type;

#ఒకవేళ defined(_WIN32)
#నిర్వచించు BOUND_TID_TYPE		DWORD
#నిర్వచించు BOUND_GET_TID(id)	id = GetCurrentThreadId()
#లేదావేళ defined(__OpenBSD__)
#నిర్వచించు BOUND_TID_TYPE		pid_t
#నిర్వచించు BOUND_GET_TID(id)	id = getthrid()
#లేదావేళ defined(__FreeBSD__)
#నిర్వచించు BOUND_TID_TYPE		pid_t
#నిర్వచించు BOUND_GET_TID(id)	syscall (SYS_thr_self, &id)
#లేదావేళ  defined(__NetBSD__)
#నిర్వచించు BOUND_TID_TYPE		pid_t
#నిర్వచించు BOUND_GET_TID(id)	id = syscall (SYS__lwp_self)
#లేదావేళ defined(__linux__)
#నిర్వచించు BOUND_TID_TYPE		pid_t
#నిర్వచించు BOUND_GET_TID(id)	id = syscall (SYS_gettid)
#లేకపోతే
#నిర్వచించు BOUND_TID_TYPE		పూర్ణాంకం
#నిర్వచించు BOUND_GET_TID(id)	id = 0
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం jmp_list_struct {
    శూన్య *penv;
    కొలత_t fp;
    కొలత_t చివర_fp;
    BOUND_TID_TYPE tid;
    నిర్మాణం jmp_list_struct *తదుపరి;
} jmp_list_type;

#నిర్వచించు BOUND_STATISTIC_SPLAY   (0)
స్థిర వృక్షం * splay (కొలత_t addr, వృక్షం *t);
స్థిర వృక్షం * splay_చివర (కొలత_t addr, వృక్షం *t);
స్థిర వృక్షం * splay_చొప్పించు(కొలత_t addr, కొలత_t కొలత, వృక్షం * t);
స్థిర వృక్షం * splay_delete(కొలత_t addr, వృక్షం *t);
శూన్య splay_printtree(వృక్షం * t, పూర్ణాంకం d);

/* external interface */
శూన్య __bounds_checking (పూర్ణాంకం no_check);
శూన్య __bound_checking_lock (శూన్య);
శూన్య __bound_checking_unlock (శూన్య);
శూన్య __bound_never_fatal (పూర్ణాంకం no_check);
DLL_EXPORT శూన్య * __bound_ptr_add(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir1(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir2(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir4(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir8(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir12(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య * __bound_ptr_indir16(శూన్య *p, కొలత_t స్థానభ్రంశం);
DLL_EXPORT శూన్య FASTCALL __bound_local_new(శూన్య *p1);
DLL_EXPORT శూన్య FASTCALL __bound_local_delete(శూన్య *p1);
శూన్య __bound_init(కొలత_t *, పూర్ణాంకం);
శూన్య __bound_main_arg(పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **envp);
శూన్య __bound_exit(శూన్య);
శూన్య __bound_exit_dll(కొలత_t *);
#ఒకవేళ !defined(_WIN32)
శూన్య *__bound_mmap (శూన్య *ప్రారంభం, కొలత_t కొలత, పూర్ణాంకం prot, పూర్ణాంకం flags, పూర్ణాంకం fd,
                    off_t స్థానభ్రంశం);
పూర్ణాంకం __bound_munmap (శూన్య *ప్రారంభం, కొలత_t కొలత);
DLL_EXPORT శూన్య __bound_siglongjmp(jmp_buf env, పూర్ణాంకం val);
#అయితే_ముగింపు
DLL_EXPORT శూన్య __bound_new_region(శూన్య *p, కొలత_t కొలత);
DLL_EXPORT శూన్య __bound_setjmp(jmp_buf env);
DLL_EXPORT శూన్య __bound_longjmp(jmp_buf env, పూర్ణాంకం val);
DLL_EXPORT శూన్య *__bound_memcpy(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT పూర్ణాంకం __bound_memcmp(స్థిరరాశి శూన్య *s1, స్థిరరాశి శూన్య *s2, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound_memmove(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound_memset(శూన్య *dst, పూర్ణాంకం c, కొలత_t కొలత);
DLL_EXPORT పూర్ణాంకం __bound_strlen(స్థిరరాశి అక్షరం *s);
DLL_EXPORT అక్షరం *__bound_strcpy(అక్షరం *dst, స్థిరరాశి అక్షరం *src);
DLL_EXPORT అక్షరం *__bound_strncpy(అక్షరం *dst, స్థిరరాశి అక్షరం *src, కొలత_t n);
DLL_EXPORT పూర్ణాంకం __bound_strcmp(స్థిరరాశి అక్షరం *s1, స్థిరరాశి అక్షరం *s2);
DLL_EXPORT పూర్ణాంకం __bound_strncmp(స్థిరరాశి అక్షరం *s1, స్థిరరాశి అక్షరం *s2, కొలత_t n);
DLL_EXPORT అక్షరం *__bound_strcat(అక్షరం *dest, స్థిరరాశి అక్షరం *src);
DLL_EXPORT అక్షరం *__bound_strncat(అక్షరం *dest, స్థిరరాశి అక్షరం *src, కొలత_t n);
DLL_EXPORT అక్షరం *__bound_strchr(స్థిరరాశి అక్షరం *string, పూర్ణాంకం ch);
DLL_EXPORT అక్షరం *__bound_strrchr(స్థిరరాశి అక్షరం *string, పూర్ణాంకం ch);
DLL_EXPORT అక్షరం *__bound_strdup(స్థిరరాశి అక్షరం *s);

#ఒకవేళ defined(__arm__) && defined(__ARM_EABI__)
DLL_EXPORT శూన్య *__bound___aeabi_memcpy(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound___aeabi_memmove(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound___aeabi_memmove4(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound___aeabi_memmove8(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__bound___aeabi_memset(శూన్య *dst, పూర్ణాంకం c, కొలత_t కొలత);
DLL_EXPORT శూన్య *__aeabi_memcpy(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__aeabi_memmove(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__aeabi_memmove4(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__aeabi_memmove8(శూన్య *dst, స్థిరరాశి శూన్య *src, కొలత_t కొలత);
DLL_EXPORT శూన్య *__aeabi_memset(శూన్య *dst, పూర్ణాంకం c, కొలత_t కొలత);
#అయితే_ముగింపు

#ఒకవేళ MALLOC_REDIR
#నిర్వచించు BOUND_MALLOC(a)          malloc_redir(a)
#నిర్వచించు BOUND_MEMALIGN(a,b)      memalign_redir(a,b)
#నిర్వచించు BOUND_FREE(a)            free_redir(a)
#నిర్వచించు BOUND_REALLOC(a,b)       realloc_redir(a,b)
#నిర్వచించు BOUND_CALLOC(a,b)        calloc_redir(a,b)
#లేకపోతే
#నిర్వచించు BOUND_MALLOC(a)          జ్ఞాపకం_ఇవ్వు(a)
#నిర్వచించు BOUND_MEMALIGN(a,b)      memalign(a,b)
#నిర్వచించు BOUND_FREE(a)            విడుదల(a)
#నిర్వచించు BOUND_REALLOC(a,b)       realloc(a,b)
#నిర్వచించు BOUND_CALLOC(a,b)        సున్నా_జ్ఞాపకం_ఇవ్వు(a,b)
DLL_EXPORT శూన్య *__bound_malloc(కొలత_t కొలత, స్థిరరాశి శూన్య *caller);
DLL_EXPORT శూన్య *__bound_memalign(కొలత_t align, కొలత_t కొలత, స్థిరరాశి శూన్య *caller);
DLL_EXPORT శూన్య __bound_free(శూన్య *ptr, స్థిరరాశి శూన్య *caller);
DLL_EXPORT శూన్య *__bound_realloc(శూన్య *ptr, కొలత_t కొలత, స్థిరరాశి శూన్య *caller);
DLL_EXPORT శూన్య *__bound_calloc(కొలత_t nmemb, కొలత_t కొలత);
#అయితే_ముగింపు

#నిర్వచించు FREE_REUSE_కొలత (100)
స్థిర గుర్తులేని పూర్ణాంకం free_reuse_సూచీ;
స్థిర శూన్య *free_reuse_list[FREE_REUSE_కొలత];

స్థిర వృక్షం *వృక్షం_2 = ఖాళీ;
#నిర్వచించు వృక్షం_REUSE      (1)
#ఒకవేళ వృక్షం_REUSE
స్థిర వృక్షం *వృక్షం_free_list;
#అయితే_ముగింపు
స్థిర alloca_list_type *alloca_list;
స్థిర jmp_list_type *jmp_list;

స్థిర గుర్తులేని అక్షరం inited;
స్థిర గుర్తులేని అక్షరం print_warn_ptr_కూడు;
స్థిర గుర్తులేని అక్షరం print_calls;
స్థిర గుర్తులేని అక్షరం print_కుప్ప;
స్థిర గుర్తులేని అక్షరం print_statistic;
స్థిర గుర్తులేని అక్షరం no_strdup;
స్థిర గుర్తులేని అక్షరం use_sem;
స్థిర _Atomic పూర్ణాంకం never_fatal;
#ఒకవేళ HAVE_TLS_FUNC
#ఒకవేళ defined(_WIN32)
స్థిర పూర్ణాంకం no_checking = 0;
స్థిర DWORD no_checking_కీలకం;
#నిర్వచించు NO_CHECKING_CHECK() ఒకవేళ (!p) {                                         \
                                  p = (పూర్ణాంకం *) LocalAlloc(LPTR, పరిమాణం(పూర్ణాంకం));  \
                                  ఒకవేళ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  Tls_సమితి_విలువ(no_checking_కీలకం, p);            \
                            }
#నిర్వచించు NO_CHECKING_GET()   ({ పూర్ణాంకం *p = Tls_Get_విలువ(no_checking_కీలకం);         \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#నిర్వచించు NO_CHECKING_సమితి(v)  { పూర్ణాంకం *p = Tls_Get_విలువ(no_checking_కీలకం);          \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#లేకపోతే
స్థిర పూర్ణాంకం no_checking = 0;
స్థిర pthread_key_t no_checking_కీలకం;
#నిర్వచించు NO_CHECKING_CHECK() ఒకవేళ (!p) {                                         \
                                  p = (పూర్ణాంకం *) BOUND_MALLOC(పరిమాణం(పూర్ణాంకం));      \
                                  ఒకవేళ (!p) bound_alloc_error("tls malloc");    \
                                  *p = 0;                                     \
                                  pthread_setspecific(no_checking_కీలకం, p);    \
                            }
#నిర్వచించు NO_CHECKING_GET()   ({ పూర్ణాంకం *p = pthread_getspecific(no_checking_కీలకం); \
                               NO_CHECKING_CHECK();                           \
                               *p;                                            \
                            })
#నిర్వచించు NO_CHECKING_సమితి(v)  { పూర్ణాంకం *p = pthread_getspecific(no_checking_కీలకం);  \
                              NO_CHECKING_CHECK();                            \
                              *p = v;                                         \
                            }
#అయితే_ముగింపు
#లేదావేళ HAVE_TLS_VAR
స్థిర __thread పూర్ణాంకం no_checking = 0;
#నిర్వచించు NO_CHECKING_GET()  no_checking
#నిర్వచించు NO_CHECKING_సమితి(v) no_checking = v 
#లేకపోతే
స్థిర _Atomic పూర్ణాంకం no_checking = 0;
#నిర్వచించు NO_CHECKING_GET()  no_checking
#నిర్వచించు NO_CHECKING_సమితి(v) no_checking = v 
#అయితే_ముగింపు
స్థిర అక్షరం exec[100];

#ఒకవేళ BOUND_STATISTIC
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_కూడు_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir1_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir2_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir4_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir8_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir12_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_ptr_indir16_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_local_new_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_local_delete_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_malloc_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_calloc_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_realloc_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_free_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_memalign_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_mmap_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_munmap_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_alloca_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_setjmp_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_longjmp_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_mempcy_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_memcmp_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_memmove_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_memset_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strlen_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strcpy_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strncpy_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strcmp_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strncmp_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strcat_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strncat_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strchr_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strrchr_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_strdup_లెక్క;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_not_దొరికింది;
#నిర్వచించు INCR_లెక్క(x)          ++x
#లేకపోతే
#నిర్వచించు INCR_లెక్క(x)
#అయితే_ముగింపు
#ఒకవేళ BOUND_STATISTIC_SPLAY
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_splay;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_splay_చివర;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_splay_చొప్పించు;
స్థిర గుర్తులేని దీర్ఘ దీర్ఘ bound_splay_delete;
#నిర్వచించు INCR_లెక్క_SPLAY(x)    ++x
#లేకపోతే
#నిర్వచించు INCR_లెక్క_SPLAY(x)
#అయితే_ముగింపు

పూర్ణాంకం tcc_backtrace(స్థిరరాశి అక్షరం *fmt, ...);

/* print a bound error message */
#నిర్వచించు bound_warning(...) \
    చేయి {                                                 \
        WAIT_SEM ();                                     \
        tcc_backtrace("^bcheck.c^BCHECK: " __VA_ARGS__); \
        POST_SEM ();                                     \
    } అయితే (0)

#నిర్వచించు bound_error(...)            \
    చేయి {                            \
        bound_warning(__VA_ARGS__); \
        ఒకవేళ (never_fatal == 0)       \
            నిష్క్రమించు(255);              \
    } అయితే (0)

#నిర్వచించు bounds_loc(fp, ...) \
    చేయి {                            \
        WAIT_SEM (); \
        tcc_backtrace("^bcheck.c^\001" __VA_ARGS__); \
        POST_SEM (); \
    } అయితే (0)

స్థిర శూన్య bound_alloc_error(స్థిరరాశి అక్షరం *s)
{
    fprintf(stderr,"FATAL: %s\n",s);
    నిష్క్రమించు (1);
}

స్థిర శూన్య bound_not_దొరికింది_warning(స్థిరరాశి అక్షరం *file, స్థిరరాశి అక్షరం *function,
                                    శూన్య *ptr)
{
    dprintf(stderr, "%s%s, %s(): Not found %p\n", exec, file, function, ptr);
}

/* enable/disable checking. This can be used in signal handlers. */
శూన్య __bounds_checking (పూర్ణాంకం no_check)
{
#ఒకవేళ HAVE_TLS_FUNC || HAVE_TLS_VAR
    NO_CHECKING_సమితి(NO_CHECKING_GET() + no_check);
#లేకపోతే
    atomic_fetch_add (&no_checking, no_check);
#అయితే_ముగింపు
}

శూన్య __bound_checking_lock(శూన్య)
{
    WAIT_SEM ();
}

శూన్య __bound_checking_unlock(శూన్య)
{
    POST_SEM ();
}

/* enable/disable checking. This can be used in signal handlers. */
శూన్య __bound_never_fatal (పూర్ణాంకం neverfatal)
{
    atomic_fetch_add (&never_fatal, neverfatal);
}

/* return '(p + offset)' for pointer arithmetic (a pointer can reach
   the end of a region in this case */
శూన్య * __bound_ptr_add(శూన్య *p, కొలత_t స్థానభ్రంశం)
{
    కొలత_t addr = (కొలత_t)p;

    ఒకవేళ (NO_CHECKING_GET())
        తిరిగి p + స్థానభ్రంశం;

    dprintf(stderr, "%s, %s(): %p 0x%lx\n",
            __FILE__, __FUNCTION__, p, (గుర్తులేని దీర్ఘ)స్థానభ్రంశం);

    WAIT_SEM ();
    INCR_లెక్క(bound_ptr_కూడు_లెక్క);
    ఒకవేళ (వృక్షం_2) {
        addr -= వృక్షం_2->ప్రారంభం;
        ఒకవేళ (addr >= వృక్షం_2->కొలత) {
            addr = (కొలత_t)p;
            వృక్షం_2 = splay (addr, వృక్షం_2);
            addr -= వృక్షం_2->ప్రారంభం;
        }
        ఒకవేళ (addr >= వృక్షం_2->కొలత) {
            addr = (కొలత_t)p;
            వృక్షం_2 = splay_చివర (addr, వృక్షం_2);
            addr -= వృక్షం_2->ప్రారంభం;
        }
        ఒకవేళ (addr <= వృక్షం_2->కొలత) {
            ఒకవేళ (వృక్షం_2->is_invalid || addr + స్థానభ్రంశం > వృక్షం_2->కొలత) {
                POST_SEM ();
                ఒకవేళ (print_warn_ptr_కూడు)
                    bound_warning("%p is outside of the region (0x%lx..0x%lx)",
                                  p + స్థానభ్రంశం, (దీర్ఘ)వృక్షం_2->ప్రారంభం,
                                  (దీర్ఘ)(వృక్షం_2->ప్రారంభం + వృక్షం_2->కొలత - 1));
                ఒకవేళ (never_fatal <= 0)
                    తిరిగి INVALID_సూచిక; /* return an invalid pointer */
                తిరిగి p + స్థానభ్రంశం;
            }
        }
        లేకపోతే ఒకవేళ (p) { /* Allow NULL + offset. offsetoff is using it. */
            INCR_లెక్క(bound_not_దొరికింది);
            POST_SEM ();
            bound_not_దొరికింది_warning (__FILE__, __FUNCTION__, p);
            తిరిగి p + స్థానభ్రంశం;
        }
    }
    POST_SEM ();
    తిరిగి p + స్థానభ్రంశం;
}

/* return '(p + offset)' for pointer indirection (the resulting must
   be strictly inside the region */
#నిర్వచించు BOUND_PTR_INDIR(dsize)                                                 \
శూన్య * __bound_ptr_indir ## dsize (శూన్య *p, కొలత_t స్థానభ్రంశం)                     \
{                                                                              \
    కొలత_t addr = (కొలత_t)p;                                                   \
                                                                               \
    ఒకవేళ (NO_CHECKING_GET())                                                     \
        తిరిగి p + స్థానభ్రంశం;                                                     \
                                                                               \
    dprintf(stderr, "%s, %s(): %p 0x%lx\n",                                    \
            __FILE__, __FUNCTION__, p, (గుర్తులేని దీర్ఘ)స్థానభ్రంశం);                 \
    WAIT_SEM ();                                                               \
    INCR_లెక్క(bound_ptr_indir ## dsize ## లెక్క);                            \
    ఒకవేళ (వృక్షం_2) {                                                                \
        addr -= వృక్షం_2->ప్రారంభం;                                                   \
        ఒకవేళ (addr >= వృక్షం_2->కొలత) {                                              \
            addr = (కొలత_t)p;                                                  \
            వృక్షం_2 = splay (addr, వృక్షం_2);                                         \
            addr -= వృక్షం_2->ప్రారంభం;                                               \
        }                                                                      \
        ఒకవేళ (addr >= వృక్షం_2->కొలత) {                                              \
            addr = (కొలత_t)p;                                                  \
            వృక్షం_2 = splay_చివర (addr, వృక్షం_2);                                     \
            addr -= వృక్షం_2->ప్రారంభం;                                               \
        }                                                                      \
        ఒకవేళ (addr <= వృక్షం_2->కొలత) {                                              \
            ఒకవేళ (వృక్షం_2->is_invalid || addr + స్థానభ్రంశం + dsize > వృక్షం_2->కొలత) {      \
                POST_SEM ();                                                   \
                bound_warning("%p (size %d) is outside of the region "         \
                              "(0x%lx..0x%lx)",                                \
                              p + స్థానభ్రంశం, dsize, (దీర్ఘ)వృక్షం_2->ప్రారంభం,            \
                              (దీర్ఘ)(వృక్షం_2->ప్రారంభం + వృక్షం_2->కొలత - 1));           \
                ఒకవేళ (never_fatal <= 0)                                          \
                    తిరిగి INVALID_సూచిక; /* return an invalid pointer */    \
                తిరిగి p + స్థానభ్రంశం;                                             \
            }                                                                  \
        }                                                                      \
        లేకపోతే {                                                                 \
            INCR_లెక్క(bound_not_దొరికింది);                                       \
            POST_SEM ();                                                       \
            bound_not_దొరికింది_warning (__FILE__, __FUNCTION__, p);               \
            తిరిగి p + స్థానభ్రంశం;                                                 \
        }                                                                      \
    }                                                                          \
    POST_SEM ();                                                               \
    తిరిగి p + స్థానభ్రంశం;                                                         \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ఒకవేళ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#సూచన GCC diagnostic నెట్టు
#సూచన GCC diagnostic ignored "-Wframe-address"
#అయితే_ముగింపు

/* return the frame pointer of the caller */
#నిర్వచించు GET_CALLER_FP(fp)\
{\
    fp = (కొలత_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
శూన్య FASTCALL __bound_local_new(శూన్య *p1) 
{
    కొలత_t addr, fp, *p = p1;

    ఒకవేళ (NO_CHECKING_GET())
         తిరిగి;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (శూన్య *)fp);
    WAIT_SEM ();
    అయితే ((addr = p[0])) {
        INCR_లెక్క(bound_local_new_లెక్క);
        వృక్షం_2 = splay_చొప్పించు(addr + fp, p[1], వృక్షం_2);
        p += 2;
    }
    POST_SEM ();
#ఒకవేళ BOUND_DEBUG
    ఒకవేళ (print_calls) {
        p = p1;
        అయితే ((addr = p[0])) {
            dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                    __FILE__, __FUNCTION__,
                    (శూన్య *) (addr + fp), (గుర్తులేని దీర్ఘ) p[1]);
            p += 2;
        }
    }
#అయితే_ముగింపు
}

/* called when leaving a function to delete all the local regions */
శూన్య FASTCALL __bound_local_delete(శూన్య *p1) 
{
    కొలత_t addr, fp, *p = p1;

    ఒకవేళ (NO_CHECKING_GET())
         తిరిగి;
    GET_CALLER_FP(fp);
    dprintf(stderr, "%s, %s(): p1=%p fp=%p\n",
            __FILE__, __FUNCTION__, p, (శూన్య *)fp);
    WAIT_SEM ();
    అయితే ((addr = p[0])) {
        INCR_లెక్క(bound_local_delete_లెక్క);
        వృక్షం_2 = splay_delete(addr + fp, వృక్షం_2);
        p += 2;
    }
    ఒకవేళ (alloca_list) {
        alloca_list_type *చివరి = ఖాళీ;
        alloca_list_type *cur = alloca_list;

        చేయి {
            ఒకవేళ (cur->fp == fp) {
                ఒకవేళ (చివరి)
                    చివరి->తదుపరి = cur->తదుపరి;
                లేకపోతే
                    alloca_list = cur->తదుపరి;
                వృక్షం_2 = splay_delete ((కొలత_t) cur->p, వృక్షం_2);
                dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                        __FILE__, __FUNCTION__, cur->p);
                BOUND_FREE (cur);
                cur = చివరి ? చివరి->తదుపరి : alloca_list;
             }
             లేకపోతే {
                 చివరి = cur;
                 cur = cur->తదుపరి;
             }
        } అయితే (cur);
    }
    ఒకవేళ (jmp_list) {
        jmp_list_type *చివరి = ఖాళీ;
        jmp_list_type *cur = jmp_list;

        చేయి {
            ఒకవేళ (cur->fp == fp) {
                ఒకవేళ (చివరి)
                    చివరి->తదుపరి = cur->తదుపరి;
                లేకపోతే
                    jmp_list = cur->తదుపరి;
                dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                       __FILE__, __FUNCTION__, cur->penv);
                BOUND_FREE (cur);
                cur = చివరి ? చివరి->తదుపరి : jmp_list;
            }
            లేకపోతే {
                చివరి = cur;
                cur = cur->తదుపరి;
            }
        } అయితే (cur);
    }

    POST_SEM ();
#ఒకవేళ BOUND_DEBUG
    ఒకవేళ (print_calls) {
        p = p1;
        అయితే ((addr = p[0])) {
            ఒకవేళ (addr != 1) {
                dprintf(stderr, "%s, %s(): %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (శూన్య *) (addr + fp), (గుర్తులేని దీర్ఘ) p[1]);
            }
            p+= 2;
        }
    }
#అయితే_ముగింపు
}

/* used by alloca */
శూన్య __bound_new_region(శూన్య *p, కొలత_t కొలత)
{
    కొలత_t fp;
    alloca_list_type *చివరి;
    alloca_list_type *cur;
    alloca_list_type *new;

    ఒకవేళ (NO_CHECKING_GET())
        తిరిగి;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, p, (గుర్తులేని దీర్ఘ)కొలత);
    GET_CALLER_FP (fp);
    new = BOUND_MALLOC (పరిమాణం (alloca_list_type));
    WAIT_SEM ();
    INCR_లెక్క(bound_alloca_లెక్క);
    చివరి = ఖాళీ;
    cur = alloca_list;
    అయితే (cur) {
#ఒకవేళ defined(__i386__) || (defined(__arm__) && !defined(__ARM_EABI__))
        పూర్ణాంకం align = 4;
#లేదావేళ defined(__arm__)
        పూర్ణాంకం align = 8;
#లేకపోతే
        పూర్ణాంకం align = 16;
#అయితే_ముగింపు
        శూన్య *cure = (శూన్య *)((అక్షరం *)cur->p + ((cur->కొలత + align) & -align));
        శూన్య *pe = (శూన్య *)((అక్షరం *)p + ((కొలత + align) & -align));
        ఒకవేళ (cur->fp == fp && ((cur->p <= p && cure > p) ||
                              (p <= cur->p && pe > cur->p))) {
            ఒకవేళ (చివరి)
                చివరి->తదుపరి = cur->తదుపరి;
            లేకపోతే
                alloca_list = cur->తదుపరి;
            వృక్షం_2 = splay_delete((కొలత_t)cur->p, వృక్షం_2);
            ఆపు;
        }
        చివరి = cur;
        cur = cur->తదుపరి;
    }
    వృక్షం_2 = splay_చొప్పించు((కొలత_t)p, కొలత, వృక్షం_2);
    ఒకవేళ (new) {
        new->fp = fp;
        new->p = p;
        new->కొలత = కొలత;
        new->తదుపరి = alloca_list;
        alloca_list = new;
    }
    POST_SEM ();
    ఒకవేళ (cur) {
        dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                __FILE__, __FUNCTION__, cur->p);
        BOUND_FREE (cur);
    }
}

శూన్య __bound_setjmp(jmp_buf env)
{
    jmp_list_type *jl;
    శూన్య *e = (శూన్య *) env;

    ఒకవేళ (NO_CHECKING_GET() == 0) {
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, e);
        WAIT_SEM ();
        INCR_లెక్క(bound_setjmp_లెక్క);
        jl = jmp_list;
        అయితే (jl) {
            ఒకవేళ (jl->penv == e)
                ఆపు;
            jl = jl->తదుపరి;
        }
        ఒకవేళ (jl == ఖాళీ) {
            jl = BOUND_MALLOC (పరిమాణం (jmp_list_type));
            ఒకవేళ (jl) {
                jl->penv = e;
                jl->తదుపరి = jmp_list;
                jmp_list = jl;
            }
        }
        ఒకవేళ (jl) {
            కొలత_t fp;

            GET_CALLER_FP (fp);
            jl->fp = fp;
            jl->చివర_fp = (కొలత_t)__builtin_frame_address(0);
            BOUND_GET_TID(jl->tid);
        }
        POST_SEM ();
    }
}

స్థిర శూన్య __bound_long_jump(jmp_buf env, పూర్ణాంకం val, పూర్ణాంకం sig, స్థిరరాశి అక్షరం *func)
{
    jmp_list_type *jl;
    శూన్య *e;
    BOUND_TID_TYPE tid;

    ఒకవేళ (NO_CHECKING_GET() == 0) {
        e = (శూన్య *)env;
        BOUND_GET_TID(tid);
        dprintf(stderr, "%s, %s(): %p\n", __FILE__, func, e);
        WAIT_SEM();
        INCR_లెక్క(bound_longjmp_లెక్క);
        jl = jmp_list;
        అయితే (jl) {
            ఒకవేళ (jl->penv == e && jl->tid == tid) {
                కొలత_t ప్రారంభం_fp = (కొలత_t)__builtin_frame_address(0);
                కొలత_t చివర_fp = jl->చివర_fp;
                jmp_list_type *cur = jmp_list;
                jmp_list_type *చివరి = ఖాళీ;

                అయితే (cur->penv != e || cur->tid != tid) {
                    ఒకవేళ (cur->tid == tid) {
                        dprintf(stderr, "%s, %s(): remove setjmp %p\n",
                                __FILE__, func, cur->penv);
                        ఒకవేళ (చివరి)
                            చివరి->తదుపరి = cur->తదుపరి;
                        లేకపోతే
                            jmp_list = cur->తదుపరి;
                        BOUND_FREE (cur);
                        cur = చివరి ? చివరి->తదుపరి : jmp_list;
                    }
                    లేకపోతే {
                        చివరి = cur;
                        cur = cur->తదుపరి;
                    }
                }
                కొరకు (;;) {
                    వృక్షం *t = వృక్షం_2;
                    alloca_list_type *చివరి;
                    alloca_list_type *cur;

                    అయితే (t && (t->ప్రారంభం < ప్రారంభం_fp || t->ప్రారంభం > చివర_fp))
                        ఒకవేళ (t->ప్రారంభం < ప్రారంభం_fp)
                            t = t->కుడి;
                        లేకపోతే
                            t = t->ఎడమ;
                    ఒకవేళ (t == ఖాళీ)
                        ఆపు;
                    చివరి = ఖాళీ;
                    cur = alloca_list;
                    అయితే (cur) {
                         ఒకవేళ ((కొలత_t) cur->p == t->ప్రారంభం) {
                             dprintf(stderr, "%s, %s(): remove alloca/vla %p\n",
                                     __FILE__, func, cur->p);
                             ఒకవేళ (చివరి)
                                 చివరి->తదుపరి = cur->తదుపరి;
                             లేకపోతే
                                 alloca_list = cur->తదుపరి;
                             BOUND_FREE (cur);
                             ఆపు;
                         }
                         చివరి = cur;
                         cur = cur->తదుపరి;
                    }
                    dprintf(stderr, "%s, %s(): delete %p\n",
                            __FILE__, func, (శూన్య *) t->ప్రారంభం);
                    వృక్షం_2 = splay_delete(t->ప్రారంభం, వృక్షం_2);
                }
                ఆపు;
            }
            jl = jl->తదుపరి;
        }
        POST_SEM();
    }
#ఒకవేళ !defined(_WIN32)
    sig ? siglongjmp(env, val) :
#అయితే_ముగింపు
    longjmp (env, val);
}

శూన్య __bound_longjmp(jmp_buf env, పూర్ణాంకం val)
{
    __bound_long_jump(env,val, 0, __FUNCTION__);
}

#ఒకవేళ !defined(_WIN32)
శూన్య __bound_siglongjmp(jmp_buf env, పూర్ణాంకం val)
{
    __bound_long_jump(env,val, 1, __FUNCTION__);
}
#అయితే_ముగింపు

#ఒకవేళ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#సూచన GCC diagnostic తీయి
#అయితే_ముగింపు

శూన్య __bound_init(కొలత_t *p, పూర్ణాంకం బహుళకం)
{
    dprintf(stderr, "%s, %s(): start %s\n", __FILE__, __FUNCTION__,
            బహుళకం < 0 ? "lazy" : బహుళకం == 0 ? "normal use" : "for -run");

    ఒకవేళ (inited) {
        WAIT_SEM();
        వెళ్ళు కూడు_bounds;
    }
    inited = 1;

#ఒకవేళ HAVE_TLS_FUNC
#ఒకవేళ defined(_WIN32)
    no_checking_కీలకం = TlsAlloc();
    Tls_సమితి_విలువ(no_checking_కీలకం, &no_checking);
#లేకపోతే
    pthread_key_create(&no_checking_కీలకం, ఖాళీ);
    pthread_setspecific(no_checking_కీలకం, &no_checking);
#అయితే_ముగింపు
#అయితే_ముగింపు
    NO_CHECKING_సమితి(1);

    print_warn_ptr_కూడు = getenv ("TCC_BOUNDS_WARN_POINTER_ADD") != ఖాళీ;
    print_calls = getenv ("TCC_BOUNDS_PRINT_CALLS") != ఖాళీ;
    print_కుప్ప = getenv ("TCC_BOUNDS_PRINT_HEAP") != ఖాళీ;
    print_statistic = getenv ("TCC_BOUNDS_PRINT_STATISTIC") != ఖాళీ;
    never_fatal = getenv ("TCC_BOUNDS_NEVER_FATAL") != ఖాళీ;

    INIT_SEM ();

#ఒకవేళ MALLOC_REDIR
    {
        శూన్య *addr = బహుళకం > 0 ? RTLD_DEFAULT : RTLD_తదుపరి;

        /* tcc -run required RTLD_DEFAULT. Normal usage requires RTLD_NEXT,
           but using RTLD_NEXT with -run segfaults on MacOS in dyld as the
           generated code segment isn't registered with dyld and hence the
           caller image of dlsym isn't known to it */
        *(శూన్య **) (&malloc_redir) = dlsym (addr, "malloc");
        ఒకవేళ (malloc_redir == ఖాళీ) {
            dprintf(stderr, "%s, %s(): use RTLD_DEFAULT\n",
                    __FILE__, __FUNCTION__);
            addr = RTLD_DEFAULT;
            *(శూన్య **) (&malloc_redir) = dlsym (addr, "malloc");
        }
        *(శూన్య **) (&calloc_redir) = dlsym (addr, "calloc");
        *(శూన్య **) (&free_redir) = dlsym (addr, "free");
        *(శూన్య **) (&realloc_redir) = dlsym (addr, "realloc");
        *(శూన్య **) (&memalign_redir) = dlsym (addr, "memalign");
        dprintf(stderr, "%s, %s(): malloc_redir %p\n",
                __FILE__, __FUNCTION__, malloc_redir);
        dprintf(stderr, "%s, %s(): free_redir %p\n",
                __FILE__, __FUNCTION__, free_redir);
        dprintf(stderr, "%s, %s(): realloc_redir %p\n",
                __FILE__, __FUNCTION__, realloc_redir);
        dprintf(stderr, "%s, %s(): memalign_redir %p\n",
                __FILE__, __FUNCTION__, memalign_redir);
        ఒకవేళ (malloc_redir == ఖాళీ || free_redir == ఖాళీ)
            bound_alloc_error ("Cannot redirect malloc/free");
#ఒకవేళ HAVE_PTHREAD_CREATE
        *(శూన్య **) (&pthread_create_redir) = dlsym (addr, "pthread_create");
        dprintf(stderr, "%s, %s(): pthread_create_redir %p\n",
                __FILE__, __FUNCTION__, pthread_create_redir);
        ఒకవేళ (pthread_create_redir == ఖాళీ)
            bound_alloc_error ("Cannot redirect pthread_create");
#అయితే_ముగింపు
#ఒకవేళ HAVE_SIGNAL
        *(శూన్య **) (&signal_redir) = dlsym (addr, "signal");
        dprintf(stderr, "%s, %s(): signal_redir %p\n",
                __FILE__, __FUNCTION__, signal_redir);
        ఒకవేళ (signal_redir == ఖాళీ)
            bound_alloc_error ("Cannot redirect signal");
#అయితే_ముగింపు
#ఒకవేళ HAVE_SIGACTION
        *(శూన్య **) (&sigaction_redir) = dlsym (addr, "sigaction");
        dprintf(stderr, "%s, %s(): sigaction_redir %p\n",
                __FILE__, __FUNCTION__, sigaction_redir);
        ఒకవేళ (sigaction_redir == ఖాళీ)
            bound_alloc_error ("Cannot redirect sigaction");
#అయితే_ముగింపు
#ఒకవేళ HAVE_FORK
        *(శూన్య **) (&fork_redir) = dlsym (addr, "fork");
        dprintf(stderr, "%s, %s(): fork_redir %p\n",
                __FILE__, __FUNCTION__, fork_redir);
        ఒకవేళ (fork_redir == ఖాళీ)
            bound_alloc_error ("Cannot redirect fork");
#అయితే_ముగింపు
    }
#అయితే_ముగింపు

#నిర్వచితమైతే __linux__
    {
        FILE *fp;
        గుర్తులేని అక్షరం దొరికింది;
        గుర్తులేని దీర్ఘ ప్రారంభం;
        గుర్తులేని దీర్ఘ చివర;
        గుర్తులేని దీర్ఘ ad =
            (గుర్తులేని దీర్ఘ) __builtin_return_address(0);
        అక్షరం పంక్తి[1000];

        /* Display exec name. Usefull when a lot of code is compiled with tcc */
        fp = fopen ("/proc/self/comm", "r");
        ఒకవేళ (fp) {
            memset (exec, 0, పరిమాణం(exec));
            fread (exec, 1, పరిమాణం(exec) - 2, fp);
            ఒకవేళ (strchr(exec,'\n'))
                *strchr(exec,'\n') = '\0';
            strcat (exec, ":");
            fclose (fp);
        }
        /* check if dlopen is used (is threre a better way?) */ 
        దొరికింది = 0;
        fp = fopen ("/proc/self/maps", "r");
        ఒకవేళ (fp) {
            అయితే (fgets (పంక్తి, పరిమాణం(పంక్తి), fp)) {
                ఒకవేళ (అక్షరశ్రేణి_చదువు (పంక్తి, "%lx-%lx", &ప్రారంభం, &చివర) == 2 &&
                            ad >= ప్రారంభం && ad < చివర) {
                    దొరికింది = 1;
                    ఆపు;
                }
                ఒకవేళ (అక్షరశ్రేణి_శోధన (పంక్తి,"[heap]"))
                    ఆపు;
            }
            fclose (fp);
        }
        ఒకవేళ (దొరికింది == 0) {
            use_sem = 1;
            no_strdup = 1;
        }
    }
#అయితే_ముగింపు

    WAIT_SEM ();

#ఒకవేళ HAVE_CTYPE
#నిర్వచితమైతే __APPLE__
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) &_DefaultRuneLocale,
                        పరిమాణం (_DefaultRuneLocale), వృక్షం_2);
#లేకపోతే
    /* XXX: Does not work if locale is changed */
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) __ctype_b_loc(),
                        పరిమాణం (గుర్తులేని పొట్టి *), వృక్షం_2);
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) (*__ctype_b_loc() - 128),
                        384 * పరిమాణం (గుర్తులేని పొట్టి), వృక్షం_2);
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) __ctype_tolower_loc(),
                        పరిమాణం (__int32_t *), వృక్షం_2);
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) (*__ctype_tolower_loc() - 128),
                        384 * పరిమాణం (__int32_t), వృక్షం_2);
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) __ctype_toupper_loc(),
                        పరిమాణం (__int32_t *), వృక్షం_2);
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) (*__ctype_toupper_loc() - 128),
                        384 * పరిమాణం (__int32_t), వృక్షం_2);
#అయితే_ముగింపు
#అయితే_ముగింపు
#ఒకవేళ HAVE_ERRNO
    వృక్షం_2 = splay_చొప్పించు((కొలత_t) (&errno), పరిమాణం (పూర్ణాంకం), వృక్షం_2);
#అయితే_ముగింపు

కూడు_bounds:
    ఒకవేళ (!p)
        వెళ్ళు no_bounds;

    /* add all static bound check values */
    అయితే (p[0] != 0) {
        వృక్షం_2 = splay_చొప్పించు(p[0], p[1], వృక్షం_2);
#ఒకవేళ BOUND_DEBUG
        dprintf(stderr, "%s, %s(): static var %p 0x%lx\n",
                __FILE__, __FUNCTION__,
                (శూన్య *) p[0], (గుర్తులేని దీర్ఘ) p[1]);
#అయితే_ముగింపు
        p += 2;
    }
no_bounds:

    POST_SEM ();
    NO_CHECKING_సమితి(0);
    dprintf(stderr, "%s, %s(): end\n\n", __FILE__, __FUNCTION__);
}

శూన్య
#ఒకవేళ (defined(__GLIBC__) && (__GLIBC_MINOR__ >= 4)) || defined(_WIN32)
__attribute__((constructor))
#అయితే_ముగింపు
__bound_main_arg(పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **envp)
{
    __bound_init (0, -1);
    ఒకవేళ (argc && argv) {
        పూర్ణాంకం i;

        WAIT_SEM ();
        కొరకు (i = 0; i < argc; i++)
            వృక్షం_2 = splay_చొప్పించు((కొలత_t) argv[i], అక్షరశ్రేణి_పొడవు (argv[i]) + 1, వృక్షం_2);
        వృక్షం_2 = splay_చొప్పించు((కొలత_t) argv, (argc + 1) * పరిమాణం(అక్షరం *), వృక్షం_2);
        POST_SEM ();
#ఒకవేళ BOUND_DEBUG
        ఒకవేళ (print_calls) {
            కొరకు (i = 0; i < argc; i++)
                dprintf(stderr, "%s, %s(): arg %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        argv[i], (గుర్తులేని దీర్ఘ)(అక్షరశ్రేణి_పొడవు (argv[i]) + 1));
            dprintf(stderr, "%s, %s(): argv %p %d\n",
                    __FILE__, __FUNCTION__, argv,
                    (పూర్ణాంకం)((argc + 1) * పరిమాణం(అక్షరం *)));
        }
#అయితే_ముగింపు
    }

    ఒకవేళ (envp && *envp) {
        అక్షరం **p = envp;

        WAIT_SEM ();
        అయితే (*p) {
            వృక్షం_2 = splay_చొప్పించు((కొలత_t) *p, అక్షరశ్రేణి_పొడవు (*p) + 1, వృక్షం_2);
            ++p;
        }
        వృక్షం_2 = splay_చొప్పించు((కొలత_t) envp, (++p - envp) * పరిమాణం(అక్షరం *), వృక్షం_2);
        POST_SEM ();
#ఒకవేళ BOUND_DEBUG
        ఒకవేళ (print_calls) {
            p = envp;
            అయితే (*p) {
                dprintf(stderr, "%s, %s(): env %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        *p, (గుర్తులేని దీర్ఘ)(అక్షరశ్రేణి_పొడవు (*p) + 1));
                ++p;
            }
            dprintf(stderr, "%s, %s(): environ %p %d\n",
                    __FILE__, __FUNCTION__, envp,
                    (పూర్ణాంకం)((++p - envp) * పరిమాణం(అక్షరం *)));
        }
#అయితే_ముగింపు
    }
}

శూన్య __attribute__((destructor)) __bound_exit(శూన్య)
{
    పూర్ణాంకం i;
    స్థిర స్థిరరాశి అక్షరం * స్థిరరాశి alloc_type[] = {
        "", "malloc", "calloc", "realloc", "memalign", "strdup"
    };

    dprintf(stderr, "%s, %s():\n", __FILE__, __FUNCTION__);

    ఒకవేళ (inited) {
#ఒకవేళ !defined(_WIN32) && !defined(__APPLE__) && !defined CONFIG_TCC_MUSL && \
    !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
    !defined(__ANDROID__)
        ఒకవేళ (print_కుప్ప) {
            బాహ్య శూన్య __libc_freeres (శూన్య);
            __libc_freeres ();
        }
#అయితే_ముగింపు

        NO_CHECKING_సమితి(1);

        TRY_SEM ();
        అయితే (alloca_list) {
            alloca_list_type *తదుపరి = alloca_list->తదుపరి;

            వృక్షం_2 = splay_delete ((కొలత_t) alloca_list->p, వృక్షం_2);
            BOUND_FREE (alloca_list);
            alloca_list = తదుపరి;
        }
        అయితే (jmp_list) {
           jmp_list_type *తదుపరి  = jmp_list->తదుపరి;

           BOUND_FREE (jmp_list);
           jmp_list = తదుపరి;
        }
        కొరకు (i = 0; i < FREE_REUSE_కొలత; i++) {
            ఒకవేళ (free_reuse_list[i]) {
                వృక్షం_2 = splay_delete ((కొలత_t) free_reuse_list[i], వృక్షం_2);
                BOUND_FREE (free_reuse_list[i]);
             }
        }
        అయితే (వృక్షం_2) {
            ఒకవేళ (print_కుప్ప && వృక్షం_2->type != 0)
                fprintf (stderr, "%s, %s(): %s found size %lu\n",
                         __FILE__, __FUNCTION__, alloc_type[వృక్షం_2->type],
                         (గుర్తులేని దీర్ఘ) వృక్షం_2->కొలత);
            వృక్షం_2 = splay_delete (వృక్షం_2->ప్రారంభం, వృక్షం_2);
        }
#ఒకవేళ వృక్షం_REUSE
        అయితే (వృక్షం_free_list) {
            వృక్షం *తదుపరి = వృక్షం_free_list->ఎడమ;
            BOUND_FREE (వృక్షం_free_list);
            వృక్షం_free_list = తదుపరి;
        }
#అయితే_ముగింపు
        POST_SEM ();
        EXIT_SEM ();
#ఒకవేళ HAVE_TLS_FUNC
#ఒకవేళ defined(_WIN32)
        TlsFree(no_checking_కీలకం);
#లేకపోతే
        pthread_key_delete(no_checking_కీలకం);
#అయితే_ముగింపు
#అయితే_ముగింపు
        inited = 0;
        ఒకవేళ (print_statistic) {
#ఒకవేళ BOUND_STATISTIC
            fprintf (stderr, "bound_ptr_add_count      %llu\n", bound_ptr_కూడు_లెక్క);
            fprintf (stderr, "bound_ptr_indir1_count   %llu\n", bound_ptr_indir1_లెక్క);
            fprintf (stderr, "bound_ptr_indir2_count   %llu\n", bound_ptr_indir2_లెక్క);
            fprintf (stderr, "bound_ptr_indir4_count   %llu\n", bound_ptr_indir4_లెక్క);
            fprintf (stderr, "bound_ptr_indir8_count   %llu\n", bound_ptr_indir8_లెక్క);
            fprintf (stderr, "bound_ptr_indir12_count  %llu\n", bound_ptr_indir12_లెక్క);
            fprintf (stderr, "bound_ptr_indir16_count  %llu\n", bound_ptr_indir16_లెక్క);
            fprintf (stderr, "bound_local_new_count    %llu\n", bound_local_new_లెక్క);
            fprintf (stderr, "bound_local_delete_count %llu\n", bound_local_delete_లెక్క);
            fprintf (stderr, "bound_malloc_count       %llu\n", bound_malloc_లెక్క);
            fprintf (stderr, "bound_calloc_count       %llu\n", bound_calloc_లెక్క);
            fprintf (stderr, "bound_realloc_count      %llu\n", bound_realloc_లెక్క);
            fprintf (stderr, "bound_free_count         %llu\n", bound_free_లెక్క);
            fprintf (stderr, "bound_memalign_count     %llu\n", bound_memalign_లెక్క);
            fprintf (stderr, "bound_mmap_count         %llu\n", bound_mmap_లెక్క);
            fprintf (stderr, "bound_munmap_count       %llu\n", bound_munmap_లెక్క);
            fprintf (stderr, "bound_alloca_count       %llu\n", bound_alloca_లెక్క);
            fprintf (stderr, "bound_setjmp_count       %llu\n", bound_setjmp_లెక్క);
            fprintf (stderr, "bound_longjmp_count      %llu\n", bound_longjmp_లెక్క);
            fprintf (stderr, "bound_mempcy_count       %llu\n", bound_mempcy_లెక్క);
            fprintf (stderr, "bound_memcmp_count       %llu\n", bound_memcmp_లెక్క);
            fprintf (stderr, "bound_memmove_count      %llu\n", bound_memmove_లెక్క);
            fprintf (stderr, "bound_memset_count       %llu\n", bound_memset_లెక్క);
            fprintf (stderr, "bound_strlen_count       %llu\n", bound_strlen_లెక్క);
            fprintf (stderr, "bound_strcpy_count       %llu\n", bound_strcpy_లెక్క);
            fprintf (stderr, "bound_strncpy_count      %llu\n", bound_strncpy_లెక్క);
            fprintf (stderr, "bound_strcmp_count       %llu\n", bound_strcmp_లెక్క);
            fprintf (stderr, "bound_strncmp_count      %llu\n", bound_strncmp_లెక్క);
            fprintf (stderr, "bound_strcat_count       %llu\n", bound_strcat_లెక్క);
            fprintf (stderr, "bound_strncat_count      %llu\n", bound_strncat_లెక్క);
            fprintf (stderr, "bound_strchr_count       %llu\n", bound_strchr_లెక్క);
            fprintf (stderr, "bound_strrchr_count      %llu\n", bound_strrchr_లెక్క);
            fprintf (stderr, "bound_strdup_count       %llu\n", bound_strdup_లెక్క);
            fprintf (stderr, "bound_not_found          %llu\n", bound_not_దొరికింది);
#అయితే_ముగింపు
#ఒకవేళ BOUND_STATISTIC_SPLAY
            fprintf (stderr, "bound_splay              %llu\n", bound_splay);
            fprintf (stderr, "bound_splay_end          %llu\n", bound_splay_చివర);
            fprintf (stderr, "bound_splay_insert       %llu\n", bound_splay_చొప్పించు);
            fprintf (stderr, "bound_splay_delete       %llu\n", bound_splay_delete);
#అయితే_ముగింపు
        }
    }
}

శూన్య __bound_exit_dll(కొలత_t *p)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);

    ఒకవేళ (p) {
        WAIT_SEM ();
	అయితే (p[0] != 0) {
	    వృక్షం_2 = splay_delete(p[0], వృక్షం_2);
#ఒకవేళ BOUND_DEBUG
            ఒకవేళ (print_calls) {
                dprintf(stderr, "%s, %s(): remove static var %p 0x%lx\n",
                        __FILE__, __FUNCTION__,
                        (శూన్య *) p[0], (గుర్తులేని దీర్ఘ) p[1]);
            }
#అయితే_ముగింపు
	    p += 2;
	}
        POST_SEM ();
    }
}

#ఒకవేళ HAVE_PTHREAD_CREATE
రకనిర్వచనం నిర్మాణం {
    శూన్య *(*ప్రారంభం_routine) (శూన్య *);
    శూన్య *arg;
    sigset_t old_ముసుగు;
} bound_thread_create_type;

స్థిర శూన్య *bound_thread_create(శూన్య *bdata)
{
    bound_thread_create_type *దత్తాంశం = (bound_thread_create_type *) bdata;
    శూన్య *retval;
#ఒకవేళ HAVE_TLS_FUNC
    పూర్ణాంకం *p = (పూర్ణాంకం *) BOUND_MALLOC(పరిమాణం(పూర్ణాంకం));
  
    ఒకవేళ (!p) bound_alloc_error("bound_thread_create malloc");
    *p = 0;
    pthread_setspecific(no_checking_కీలకం, p);
#అయితే_ముగింపు
    pthread_sigmask(SIG_SETMASK, &దత్తాంశం->old_ముసుగు, ఖాళీ);
    retval = దత్తాంశం->ప్రారంభం_routine(దత్తాంశం->arg);
#ఒకవేళ HAVE_TLS_FUNC
    pthread_setspecific(no_checking_కీలకం, ఖాళీ);
    BOUND_FREE (p);
#అయితే_ముగింపు
    BOUND_FREE (దత్తాంశం);
    తిరిగి retval;
}

పూర్ణాంకం pthread_create(pthread_t *thread, స్థిరరాశి pthread_attr_t *attr,
                   శూన్య *(*ప్రారంభం_routine) (శూన్య *), శూన్య *arg)
{
    పూర్ణాంకం retval;
    bound_thread_create_type *దత్తాంశం;
    sigset_t ముసుగు;
    sigset_t old_ముసుగు;
  
    use_sem = 1;
    dprintf (stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    sigfillset(&ముసుగు);
    pthread_sigmask(SIG_SETMASK, &ముసుగు, &old_ముసుగు);
    దత్తాంశం = (bound_thread_create_type *) BOUND_MALLOC(పరిమాణం(bound_thread_create_type));
    ఒకవేళ (!దత్తాంశం) bound_alloc_error("bound_thread_create malloc");
    దత్తాంశం->ప్రారంభం_routine = ప్రారంభం_routine;
    దత్తాంశం->arg = arg;
    దత్తాంశం->old_ముసుగు = old_ముసుగు;
    retval = pthread_create_redir(thread, attr, bound_thread_create, దత్తాంశం);
    pthread_sigmask(SIG_SETMASK, &old_ముసుగు, ఖాళీ);
    తిరిగి retval;
}
#అయితే_ముగింపు

#ఒకవేళ HAVE_SIGNAL || HAVE_SIGACTION
రకనిర్వచనం సంఘం {
#ఒకవేళ HAVE_SIGNAL
    bound_sig signal_handler;
#అయితే_ముగింపు
#ఒకవేళ HAVE_SIGACTION
    శూన్య (*sig_handler)(పూర్ణాంకం);
    శూన్య (*sig_sigaction)(పూర్ణాంకం, siginfo_t *, శూన్య *);
#అయితే_ముగింపు
} bound_sig_type;

స్థిర గుర్తులేని అక్షరం bound_sig_వాడిన[NSIG];
స్థిర bound_sig_type bound_sig_దత్తాంశం[NSIG];
#అయితే_ముగింపు

#ఒకవేళ HAVE_SIGNAL
స్థిర శూన్య signal_handler(పూర్ణాంకం sig)
{
   __bounds_checking(1);
   bound_sig_దత్తాంశం[sig].signal_handler(sig);
   __bounds_checking(-1);
}

bound_sig సంకేతం(పూర్ణాంకం signum, bound_sig handler)
{
    bound_sig retval;

    dprintf (stderr, "%s, %s() %d %p\n", __FILE__, __FUNCTION__,
             signum, handler);
    retval = signal_redir(signum, handler ? signal_handler : handler);
    ఒకవేళ (retval != SIG_ERR) {
        ఒకవేళ (bound_sig_వాడిన[signum])
            retval = bound_sig_దత్తాంశం[signum].signal_handler;
        ఒకవేళ (handler) {
            bound_sig_వాడిన[signum] = 1;
            bound_sig_దత్తాంశం[signum].signal_handler = handler;
        }
    }
    తిరిగి retval;
}
#అయితే_ముగింపు

#ఒకవేళ HAVE_SIGACTION
స్థిర శూన్య sig_handler(పూర్ణాంకం sig)
{
   __bounds_checking(1);
   bound_sig_దత్తాంశం[sig].sig_handler(sig);
   __bounds_checking(-1);
}

స్థిర శూన్య sig_sigaction(పూర్ణాంకం sig, siginfo_t *info, శూన్య *ucontext)
{
   __bounds_checking(1);
   bound_sig_దత్తాంశం[sig].sig_sigaction(sig, info, ucontext);
   __bounds_checking(-1);
}

పూర్ణాంకం sigaction(పూర్ణాంకం signum, స్థిరరాశి నిర్మాణం sigaction *act, నిర్మాణం sigaction *oldact)
{
    పూర్ణాంకం retval;
    నిర్మాణం sigaction nact, oact;

    dprintf (stderr, "%s, %s() %d %p %p\n", __FILE__, __FUNCTION__,
             signum, act, oldact);

    ఒకవేళ (sigaction_redir == ఖాళీ)
        __bound_init(0,-1);

    ఒకవేళ (act) {
        nact = *act;
        ఒకవేళ (nact.sa_flags & SA_SIGINFO)
            nact.sa_sigaction = sig_sigaction;
        లేకపోతే
            nact.sa_handler = sig_handler;
        retval = sigaction_redir(signum, &nact, &oact);
    }
    లేకపోతే
        retval = sigaction_redir(signum, act, &oact);
    ఒకవేళ (retval >= 0) {
        ఒకవేళ (bound_sig_వాడిన[signum]) {
            ఒకవేళ (oact.sa_flags & SA_SIGINFO)
                oact.sa_sigaction = bound_sig_దత్తాంశం[signum].sig_sigaction;
            లేకపోతే
                oact.sa_handler = bound_sig_దత్తాంశం[signum].sig_handler;
        }
        ఒకవేళ (oldact) {
            *oldact = oact;
        }
        ఒకవేళ (act) {
            bound_sig_వాడిన[signum] = 1;
            ఒకవేళ (act->sa_flags & SA_SIGINFO)
                bound_sig_దత్తాంశం[signum].sig_sigaction = act->sa_sigaction;
            లేకపోతే
                bound_sig_దత్తాంశం[signum].sig_handler = act->sa_handler;
        }
    }
    తిరిగి retval;
}
#అయితే_ముగింపు

#ఒకవేళ HAVE_FORK
pid_t fork(శూన్య)
{
    pid_t retval;

    WAIT_SEM();
    retval = (*fork_redir)();
    ఒకవేళ (retval == 0)
        INIT_SEM();
    లేకపోతే
        POST_SEM();
    తిరిగి retval;
}
#అయితే_ముగింపు

#ఒకవేళ MALLOC_REDIR
శూన్య *జ్ఞాపకం_ఇవ్వు(కొలత_t కొలత)
#లేకపోతే
శూన్య *__bound_malloc(కొలత_t కొలత, స్థిరరాశి శూన్య *caller)
#అయితే_ముగింపు
{
    శూన్య *ptr;
    
#ఒకవేళ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ఒకవేళ (malloc_redir == ఖాళీ) {
        __bound_init (0, -1);
        ఒకవేళ (malloc_redir == ఖాళీ) {
            ptr = &initial_pool[pool_సూచీ];
            pool_సూచీ = (pool_సూచీ + కొలత + 15) & ~15;
            ఒకవేళ (pool_సూచీ >= పరిమాణం (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (గుర్తులేని దీర్ఘ)కొలత);
            తిరిగి ptr;
        }
    }
#అయితే_ముగింపు
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MALLOC (కొలత + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (గుర్తులేని దీర్ఘ)కొలత);
    
    ఒకవేళ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_malloc_లెక్క);

        ఒకవేళ (ptr) {
            వృక్షం_2 = splay_చొప్పించు ((కొలత_t) ptr, కొలత ? కొలత : కొలత + 1, వృక్షం_2);
            ఒకవేళ (వృక్షం_2 && వృక్షం_2->ప్రారంభం == (కొలత_t) ptr)
                వృక్షం_2->type = TCC_TYPE_MALLOC;
        }
        POST_SEM ();
    }
    తిరిగి ptr;
}

#ఒకవేళ MALLOC_REDIR
శూన్య *memalign(కొలత_t align, కొలత_t కొలత)
#లేకపోతే
శూన్య *__bound_memalign(కొలత_t align, కొలత_t కొలత, స్థిరరాశి శూన్య *caller)
#అయితే_ముగింపు
{
    శూన్య *ptr;

#ఒకవేళ HAVE_MEMALIGN
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = BOUND_MEMALIGN(align, కొలత + 1);
#లేకపోతే
    ఒకవేళ (align > 4) {
        /* XXX: handle it ? */
        ptr = ఖాళీ;
    } లేకపోతే {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = BOUND_MALLOC(కొలత + 1);
    }
#అయితే_ముగింపు
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ptr, (గుర్తులేని దీర్ఘ)కొలత);

    ఒకవేళ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_memalign_లెక్క);

        ఒకవేళ (ptr) {
            వృక్షం_2 = splay_చొప్పించు((కొలత_t) ptr, కొలత ? కొలత : కొలత + 1, వృక్షం_2);
            ఒకవేళ (వృక్షం_2 && వృక్షం_2->ప్రారంభం == (కొలత_t) ptr)
                వృక్షం_2->type = TCC_TYPE_MEMALIGN;
        }
        POST_SEM ();
    }
    తిరిగి ptr;
}

#ఒకవేళ MALLOC_REDIR
శూన్య విడుదల(శూన్య *ptr)
#లేకపోతే
శూన్య __bound_free(శూన్య *ptr, స్థిరరాశి శూన్య *caller)
#అయితే_ముగింపు
{
    కొలత_t addr = (కొలత_t) ptr;
    శూన్య *p;

    ఒకవేళ (ptr == ఖాళీ || వృక్షం_2 == ఖాళీ
#ఒకవేళ MALLOC_REDIR
        || ((గుర్తులేని అక్షరం *) ptr >= &initial_pool[0] &&
            (గుర్తులేని అక్షరం *) ptr < &initial_pool[పరిమాణం(initial_pool)])
#అయితే_ముగింపు
        )
        తిరిగి;

    dprintf(stderr, "%s, %s(): %p\n", __FILE__, __FUNCTION__, ptr);

    ఒకవేళ (inited && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_free_లెక్క);
        వృక్షం_2 = splay (addr, వృక్షం_2);
        ఒకవేళ (వృక్షం_2->ప్రారంభం == addr) {
            ఒకవేళ (వృక్షం_2->is_invalid) {
                POST_SEM ();
                bound_error("freeing invalid region");
                తిరిగి;
            }
            వృక్షం_2->is_invalid = 1;
            memset (ptr, 0x5a, వృక్షం_2->కొలత);
            p = free_reuse_list[free_reuse_సూచీ];
            free_reuse_list[free_reuse_సూచీ] = ptr;
            free_reuse_సూచీ = (free_reuse_సూచీ + 1) % FREE_REUSE_కొలత;
            ఒకవేళ (p)
                వృక్షం_2 = splay_delete((కొలత_t)p, వృక్షం_2);
            ptr = p;
        }
        POST_SEM ();
    }
    BOUND_FREE (ptr);
}

#ఒకవేళ MALLOC_REDIR
శూన్య *realloc(శూన్య *ptr, కొలత_t కొలత)
#లేకపోతే
శూన్య *__bound_realloc(శూన్య *ptr, కొలత_t కొలత, స్థిరరాశి శూన్య *caller)
#అయితే_ముగింపు
{
    శూన్య *new_ptr;

    ఒకవేళ (కొలత == 0) {
#ఒకవేళ MALLOC_REDIR
        విడుదల(ptr);
#లేకపోతే
        __bound_free(ptr, caller);
#అయితే_ముగింపు
        తిరిగి ఖాళీ;
    }

    new_ptr = BOUND_REALLOC (ptr, కొలత + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new_ptr, (గుర్తులేని దీర్ఘ)కొలత);

    ఒకవేళ (NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_realloc_లెక్క);

        ఒకవేళ (ptr)
            వృక్షం_2 = splay_delete ((కొలత_t) ptr, వృక్షం_2);
        ఒకవేళ (new_ptr) {
            వృక్షం_2 = splay_చొప్పించు ((కొలత_t) new_ptr, కొలత ? కొలత : కొలత + 1, వృక్షం_2);
            ఒకవేళ (వృక్షం_2 && వృక్షం_2->ప్రారంభం == (కొలత_t) new_ptr)
                వృక్షం_2->type = TCC_TYPE_REALLOC;
        }
        POST_SEM ();
    }
    తిరిగి new_ptr;
}

#ఒకవేళ MALLOC_REDIR
శూన్య *సున్నా_జ్ఞాపకం_ఇవ్వు(కొలత_t nmemb, కొలత_t కొలత)
#లేకపోతే
శూన్య *__bound_calloc(కొలత_t nmemb, కొలత_t కొలత)
#అయితే_ముగింపు
{
    శూన్య *ptr;

    కొలత *= nmemb;
#ఒకవేళ MALLOC_REDIR
    /* This will catch the first dlsym call from __bound_init */
    ఒకవేళ (malloc_redir == ఖాళీ) {
        __bound_init (0, -1);
        ఒకవేళ (malloc_redir == ఖాళీ) {
            ptr = &initial_pool[pool_సూచీ];
            pool_సూచీ = (pool_సూచీ + కొలత + 15) & ~15;
            ఒకవేళ (pool_సూచీ >= పరిమాణం (initial_pool))
                bound_alloc_error ("initial memory pool too small");
            dprintf (stderr, "%s, %s(): initial %p, 0x%lx\n",
                     __FILE__, __FUNCTION__, ptr, (గుర్తులేని దీర్ఘ)కొలత);
            memset (ptr, 0, కొలత);
            తిరిగి ptr;
        }
    }
#అయితే_ముగింపు
    ptr = BOUND_MALLOC(కొలత + 1);
    dprintf (stderr, "%s, %s(): %p, 0x%lx\n",
             __FILE__, __FUNCTION__, ptr, (గుర్తులేని దీర్ఘ)కొలత);

    ఒకవేళ (ptr) {
        memset (ptr, 0, కొలత);
        ఒకవేళ (NO_CHECKING_GET() == 0) {
            WAIT_SEM ();
            INCR_లెక్క(bound_calloc_లెక్క);
            వృక్షం_2 = splay_చొప్పించు ((కొలత_t) ptr, కొలత ? కొలత : కొలత + 1, వృక్షం_2);
            ఒకవేళ (వృక్షం_2 && వృక్షం_2->ప్రారంభం == (కొలత_t) ptr)
                వృక్షం_2->type = TCC_TYPE_CALLOC;
            POST_SEM ();
        }
    }
    తిరిగి ptr;
}

#ఒకవేళ !defined(_WIN32)
శూన్య *__bound_mmap (శూన్య *ప్రారంభం, కొలత_t కొలత, పూర్ణాంకం prot,
                    పూర్ణాంకం flags, పూర్ణాంకం fd, off_t స్థానభ్రంశం)
{
    శూన్య *ఫలితం;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ప్రారంభం, (గుర్తులేని దీర్ఘ)కొలత);
    ఫలితం = mmap (ప్రారంభం, కొలత, prot, flags, fd, స్థానభ్రంశం);
    ఒకవేళ (ఫలితం && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_mmap_లెక్క);
        వృక్షం_2 = splay_చొప్పించు((కొలత_t)ఫలితం, కొలత, వృక్షం_2);
        POST_SEM ();
    }
    తిరిగి ఫలితం;
}

పూర్ణాంకం __bound_munmap (శూన్య *ప్రారంభం, కొలత_t కొలత)
{
    పూర్ణాంకం ఫలితం;

    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, ప్రారంభం, (గుర్తులేని దీర్ఘ)కొలత);
    ఒకవేళ (ప్రారంభం && NO_CHECKING_GET() == 0) {
        WAIT_SEM ();
        INCR_లెక్క(bound_munmap_లెక్క);
        వృక్షం_2 = splay_delete ((కొలత_t) ప్రారంభం, వృక్షం_2);
        POST_SEM ();
    }
    ఫలితం = munmap (ప్రారంభం, కొలత);
    తిరిగి ఫలితం;
}
#అయితే_ముగింపు

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, if any */
స్థిర శూన్య __bound_check(స్థిరరాశి శూన్య *p, కొలత_t కొలత, స్థిరరాశి అక్షరం *function)
{
    ఒకవేళ (కొలత != 0 && __bound_ptr_add((శూన్య *)p, కొలత) == INVALID_సూచిక) {
        bound_error("invalid pointer %p, size 0x%lx in %s",
                p, (గుర్తులేని దీర్ఘ)కొలత, function);
    }
}

స్థిర పూర్ణాంకం check_overlap (స్థిరరాశి శూన్య *p1, కొలత_t n1,
                          స్థిరరాశి శూన్య *p2, కొలత_t n2,
                          స్థిరరాశి అక్షరం *function)
{
    స్థిరరాశి శూన్య *p1e = (స్థిరరాశి శూన్య *) ((స్థిరరాశి అక్షరం *) p1 + n1);
    స్థిరరాశి శూన్య *p2e = (స్థిరరాశి శూన్య *) ((స్థిరరాశి అక్షరం *) p2 + n2);

    ఒకవేళ (NO_CHECKING_GET() == 0 && n1 != 0 && n2 !=0 &&
        ((p1 <= p2 && p1e > p2) ||     /* p1----p2====p1e----p2e */
         (p2 <= p1 && p2e > p1))) {    /* p2----p1====p2e----p1e */
        bound_error("overlapping regions %p(0x%lx), %p(0x%lx) in %s",
                p1, (గుర్తులేని దీర్ఘ)n1, p2, (గుర్తులేని దీర్ఘ)n2, function);
        తిరిగి never_fatal < 0;
    }
    తిరిగి 0;
}

శూన్య *__bound_memcpy(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_mempcy_లెక్క);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ఒకవేళ (check_overlap(dest, n, src, n, "memcpy"))
        తిరిగి dest;
    తిరిగి జ్ఞాపకం_నకలు(dest, src, n);
}

పూర్ణాంకం __bound_memcmp(స్థిరరాశి శూన్య *s1, స్థిరరాశి శూన్య *s2, కొలత_t n)
{
    స్థిరరాశి గుర్తులేని అక్షరం *u1 = (స్థిరరాశి గుర్తులేని అక్షరం *) s1;
    స్థిరరాశి గుర్తులేని అక్షరం *u2 = (స్థిరరాశి గుర్తులేని అక్షరం *) s2;
    పూర్ణాంకం retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memcmp_లెక్క);
    కొరకు (;;) {
        ఒకవేళ ((ssize_t) --n == -1)
            ఆపు;
        లేకపోతే ఒకవేళ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ఆపు;
        }
        ++u1;
        ++u2;
    }
    __bound_check(s1, (స్థిరరాశి శూన్య *)u1 - s1, "memcmp s1");
    __bound_check(s2, (స్థిరరాశి శూన్య *)u2 - s2, "memcmp s2");
    తిరిగి retval;
}

శూన్య *__bound_memmove(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memmove_లెక్క);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    తిరిగి memmove(dest, src, n);
}

శూన్య *__bound_memset(శూన్య *s, పూర్ణాంకం c, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memset_లెక్క);
    __bound_check(s, n, "memset");
    తిరిగి memset(s, c, n);
}

#ఒకవేళ defined(__arm__) && defined(__ARM_EABI__)
శూన్య *__bound___aeabi_memcpy(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_mempcy_లెక్క);
    __bound_check(dest, n, "memcpy dest");
    __bound_check(src, n, "memcpy src");
    ఒకవేళ (check_overlap(dest, n, src, n, "memcpy"))
        తిరిగి dest;
    తిరిగి __aeabi_memcpy(dest, src, n);
}

శూన్య *__bound___aeabi_memmove(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memmove_లెక్క);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    తిరిగి __aeabi_memmove(dest, src, n);
}

శూన్య *__bound___aeabi_memmove4(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memmove_లెక్క);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    తిరిగి __aeabi_memmove4(dest, src, n);
}

శూన్య *__bound___aeabi_memmove8(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memmove_లెక్క);
    __bound_check(dest, n, "memmove dest");
    __bound_check(src, n, "memmove src");
    తిరిగి __aeabi_memmove8(dest, src, n);
}

శూన్య *__bound___aeabi_memset(శూన్య *s, పూర్ణాంకం c, కొలత_t n)
{
    dprintf(stderr, "%s, %s(): %p, %d, 0x%lx\n",
            __FILE__, __FUNCTION__, s, c, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_memset_లెక్క);
    __bound_check(s, n, "memset");
    తిరిగి __aeabi_memset(s, c, n);
}
#అయితే_ముగింపు

పూర్ణాంకం __bound_strlen(స్థిరరాశి అక్షరం *s)
{
    స్థిరరాశి అక్షరం *p = s;

    dprintf(stderr, "%s, %s(): %p\n",
            __FILE__, __FUNCTION__, s);
    INCR_లెక్క(bound_strlen_లెక్క);
    అయితే (*p++);
    __bound_check(s, p - s, "strlen");
    తిరిగి (p - s) - 1;
}

అక్షరం *__bound_strcpy(అక్షరం *dest, స్థిరరాశి అక్షరం *src)
{
    కొలత_t len;
    స్థిరరాశి అక్షరం *p = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_లెక్క(bound_strcpy_లెక్క);
    అయితే (*p++);
    len = p - src;
    __bound_check(dest, len, "strcpy dest");
    __bound_check(src, len, "strcpy src");
    ఒకవేళ (check_overlap(dest, len, src, len, "strcpy"))
        తిరిగి dest;
    తిరిగి strcpy (dest, src);
}

అక్షరం *__bound_strncpy(అక్షరం *dest, స్థిరరాశి అక్షరం *src, కొలత_t n)
{
    కొలత_t len = n;
    స్థిరరాశి అక్షరం *p = src;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_strncpy_లెక్క);
    అయితే (len-- && *p++);
    len = p - src;
    __bound_check(dest, len, "strncpy dest");
    __bound_check(src, len, "strncpy src");
    ఒకవేళ (check_overlap(dest, len, src, len, "strncpy"))
        తిరిగి dest;
    తిరిగి strncpy(dest, src, n);
}

పూర్ణాంకం __bound_strcmp(స్థిరరాశి అక్షరం *s1, స్థిరరాశి అక్షరం *s2)
{
    స్థిరరాశి గుర్తులేని అక్షరం *u1 = (స్థిరరాశి గుర్తులేని అక్షరం *) s1;
    స్థిరరాశి గుర్తులేని అక్షరం *u2 = (స్థిరరాశి గుర్తులేని అక్షరం *) s2;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, s1, s2);
    INCR_లెక్క(bound_strcmp_లెక్క);
    అయితే (*u1 && *u1 == *u2) {
        ++u1;
        ++u2;
    }
    __bound_check(s1, ((స్థిరరాశి అక్షరం *)u1 - s1) + 1, "strcmp s1");
    __bound_check(s2, ((స్థిరరాశి అక్షరం *)u2 - s2) + 1, "strcmp s2");
    తిరిగి *u1 - *u2;
}

పూర్ణాంకం __bound_strncmp(స్థిరరాశి అక్షరం *s1, స్థిరరాశి అక్షరం *s2, కొలత_t n)
{
    స్థిరరాశి గుర్తులేని అక్షరం *u1 = (స్థిరరాశి గుర్తులేని అక్షరం *) s1;
    స్థిరరాశి గుర్తులేని అక్షరం *u2 = (స్థిరరాశి గుర్తులేని అక్షరం *) s2;
    పూర్ణాంకం retval = 0;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, s1, s2, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_strncmp_లెక్క);
    చేయి {
        ఒకవేళ ((ssize_t) --n == -1)
            ఆపు;
        లేకపోతే ఒకవేళ (*u1 != *u2) {
            retval = *u1++ - *u2++;
            ఆపు;
        }
        ++u2;
    } అయితే (*u1++);
    __bound_check(s1, (స్థిరరాశి అక్షరం *)u1 - s1, "strncmp s1");
    __bound_check(s2, (స్థిరరాశి అక్షరం *)u2 - s2, "strncmp s2");
    తిరిగి retval;
}

అక్షరం *__bound_strcat(అక్షరం *dest, స్థిరరాశి అక్షరం *src)
{
    అక్షరం *r = dest;
    స్థిరరాశి అక్షరం *s = src;

    dprintf(stderr, "%s, %s(): %p, %p\n",
            __FILE__, __FUNCTION__, dest, src);
    INCR_లెక్క(bound_strcat_లెక్క);
    అయితే (*dest++);
    అయితే (*src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strcat dest");
    __bound_check(s, src - s, "strcat src");
    ఒకవేళ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strcat"))
        తిరిగి dest;
    తిరిగి strcat(r, s);
}

అక్షరం *__bound_strncat(అక్షరం *dest, స్థిరరాశి అక్షరం *src, కొలత_t n)
{
    అక్షరం *r = dest;
    స్థిరరాశి అక్షరం *s = src;
    కొలత_t len = n;

    dprintf(stderr, "%s, %s(): %p, %p, 0x%lx\n",
            __FILE__, __FUNCTION__, dest, src, (గుర్తులేని దీర్ఘ)n);
    INCR_లెక్క(bound_strncat_లెక్క);
    అయితే (*dest++);
    అయితే (len-- && *src++);
    __bound_check(r, (dest - r) + (src - s) - 1, "strncat dest");
    __bound_check(s, src - s, "strncat src");
    ఒకవేళ (check_overlap(r, (dest - r) + (src - s) - 1, s, src - s, "strncat"))
        తిరిగి dest;
    తిరిగి strncat(r, s, n);
}

అక్షరం *__bound_strchr(స్థిరరాశి అక్షరం *s, పూర్ణాంకం c)
{
    స్థిరరాశి గుర్తులేని అక్షరం *str = (స్థిరరాశి గుర్తులేని అక్షరం *) s;
    గుర్తులేని అక్షరం ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_లెక్క(bound_strchr_లెక్క);
    అయితే (*str) {
        ఒకవేళ (*str == ch)
            ఆపు;
        ++str;
    }
    __bound_check(s, ((స్థిరరాశి అక్షరం *)str - s) + 1, "strchr");
    తిరిగి *str == ch ? (అక్షరం *) str : ఖాళీ;
}

అక్షరం *__bound_strrchr(స్థిరరాశి అక్షరం *s, పూర్ణాంకం c)
{
    స్థిరరాశి గుర్తులేని అక్షరం *str = (స్థిరరాశి గుర్తులేని అక్షరం *) s;
    గుర్తులేని అక్షరం ch = c;

    dprintf(stderr, "%s, %s(): %p, %d\n",
            __FILE__, __FUNCTION__, s, ch);
    INCR_లెక్క(bound_strrchr_లెక్క);
    అయితే (*str++);
    __bound_check(s, (స్థిరరాశి అక్షరం *)str - s, "strrchr");
    అయితే (str != (స్థిరరాశి గుర్తులేని అక్షరం *)s) {
        ఒకవేళ (*--str == ch)
            ఆపు;
    }
    __bound_check(s, (స్థిరరాశి అక్షరం *)str - s, "strrchr");
    తిరిగి *str == ch ? (అక్షరం *) str : ఖాళీ;
}

అక్షరం *__bound_strdup(స్థిరరాశి అక్షరం *s)
{
    స్థిరరాశి అక్షరం *p = s;
    అక్షరం *new;

    INCR_లెక్క(bound_strdup_లెక్క);
    అయితే (*p++);
    __bound_check(s, p - s, "strdup");
    new = BOUND_MALLOC ((p - s) + 1);
    dprintf(stderr, "%s, %s(): %p, 0x%lx\n",
            __FILE__, __FUNCTION__, new, (గుర్తులేని దీర్ఘ)(p -s));
    ఒకవేళ (new) {
        ఒకవేళ (NO_CHECKING_GET() == 0 && no_strdup == 0) {
            WAIT_SEM ();
            వృక్షం_2 = splay_చొప్పించు((కొలత_t)new, p - s, వృక్షం_2);
            ఒకవేళ (వృక్షం_2 && వృక్షం_2->ప్రారంభం == (కొలత_t) new)
                వృక్షం_2->type = TCC_TYPE_STRDUP;
            POST_SEM ();
        }
        జ్ఞాపకం_నకలు (new, s, p - s);
    }
    తిరిగి new;
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

#నిర్వచించు compare(ప్రారంభం,tstart,tsize) (ప్రారంభం < tstart ? -1 : \
                                     ప్రారంభం >= tstart+tsize  ? 1 : 0)

స్థిర వృక్షం * splay (కొలత_t addr, వృక్షం *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat      */
{
    వృక్షం N, *l, *r, *y;
    పూర్ణాంకం comp;
    
    INCR_లెక్క_SPLAY(bound_splay);
    ఒకవేళ (t == ఖాళీ) తిరిగి t;
    N.ఎడమ = N.కుడి = ఖాళీ;
    l = r = &N;
 
    కొరకు (;;) {
        comp = compare(addr, t->ప్రారంభం, t->కొలత);
        ఒకవేళ (comp < 0) {
            y = t->ఎడమ;
            ఒకవేళ (y == ఖాళీ) ఆపు;
            ఒకవేళ (compare(addr, y->ప్రారంభం, y->కొలత) < 0) {
                t->ఎడమ = y->కుడి;                    /* rotate right */
                y->కుడి = t;
                t = y;
                ఒకవేళ (t->ఎడమ == ఖాళీ) ఆపు;
            }
            r->ఎడమ = t;                               /* link right */
            r = t;
            t = t->ఎడమ;
        } లేకపోతే ఒకవేళ (comp > 0) {
            y = t->కుడి;
            ఒకవేళ (y == ఖాళీ) ఆపు;
            ఒకవేళ (compare(addr, y->ప్రారంభం, y->కొలత) > 0) {
                t->కుడి = y->ఎడమ;                    /* rotate left */
                y->ఎడమ = t;
                t = y;
                ఒకవేళ (t->కుడి == ఖాళీ) ఆపు;
            }
            l->కుడి = t;                              /* link left */
            l = t;
            t = t->కుడి;
        } లేకపోతే {
            ఆపు;
        }
    }
    l->కుడి = t->ఎడమ;                                /* assemble */
    r->ఎడమ = t->కుడి;
    t->ఎడమ = N.కుడి;
    t->కుడి = N.ఎడమ;

    తిరిగి t;
}

#నిర్వచించు compare_చివర(ప్రారంభం,tend) (ప్రారంభం < tend ? -1 : \
                                 ప్రారంభం > tend  ? 1 : 0)

స్థిర వృక్షం * splay_చివర (కొలత_t addr, వృక్షం *t)
/* Splay using the key start (which may or may not be in the tree.) */
/* The starting root is t, and the tree used is defined by rat  */
{
    వృక్షం N, *l, *r, *y;
    పూర్ణాంకం comp;
    
    INCR_లెక్క_SPLAY(bound_splay_చివర);
    ఒకవేళ (t == ఖాళీ) తిరిగి t;
    N.ఎడమ = N.కుడి = ఖాళీ;
    l = r = &N;
 
    కొరకు (;;) {
        comp = compare_చివర(addr, t->ప్రారంభం + t->కొలత);
        ఒకవేళ (comp < 0) {
            y = t->ఎడమ;
            ఒకవేళ (y == ఖాళీ) ఆపు;
            ఒకవేళ (compare_చివర(addr, y->ప్రారంభం + y->కొలత) < 0) {
                t->ఎడమ = y->కుడి;                    /* rotate right */
                y->కుడి = t;
                t = y;
                ఒకవేళ (t->ఎడమ == ఖాళీ) ఆపు;
            }
            r->ఎడమ = t;                               /* link right */
            r = t;
            t = t->ఎడమ;
        } లేకపోతే ఒకవేళ (comp > 0) {
            y = t->కుడి;
            ఒకవేళ (y == ఖాళీ) ఆపు;
            ఒకవేళ (compare_చివర(addr, y->ప్రారంభం + y->కొలత) > 0) {
                t->కుడి = y->ఎడమ;                    /* rotate left */
                y->ఎడమ = t;
                t = y;
                ఒకవేళ (t->కుడి == ఖాళీ) ఆపు;
            }
            l->కుడి = t;                              /* link left */
            l = t;
            t = t->కుడి;
        } లేకపోతే {
            ఆపు;
        }
    }
    l->కుడి = t->ఎడమ;                                /* assemble */
    r->ఎడమ = t->కుడి;
    t->ఎడమ = N.కుడి;
    t->కుడి = N.ఎడమ;

    తిరిగి t;
}

స్థిర వృక్షం * splay_చొప్పించు(కొలత_t addr, కొలత_t కొలత, వృక్షం * t)
/* Insert key start into the tree t, if it is not already there. */
/* Return a pointer to the resulting tree.                       */
{
    వృక్షం * new;

    INCR_లెక్క_SPLAY(bound_splay_చొప్పించు);
    ఒకవేళ (t != ఖాళీ) {
        t = splay(addr,t);
        ఒకవేళ (compare(addr, t->ప్రారంభం, t->కొలత)==0) {
            తిరిగి t;  /* it's already there */
        }
    }
#ఒకవేళ వృక్షం_REUSE
    ఒకవేళ (వృక్షం_free_list) {
          new = వృక్షం_free_list;
          వృక్షం_free_list = new->ఎడమ;
    }
    లేకపోతే
#అయితే_ముగింపు
    {
        new = (వృక్షం *) BOUND_MALLOC (పరిమాణం (వృక్షం));
    }
    ఒకవేళ (new == ఖాళీ) {
        bound_alloc_error("not enough memory for bound checking code");
    }
    లేకపోతే {
        ఒకవేళ (t == ఖాళీ) {
            new->ఎడమ = new->కుడి = ఖాళీ;
        } లేకపోతే ఒకవేళ (compare(addr, t->ప్రారంభం, t->కొలత) < 0) {
            new->ఎడమ = t->ఎడమ;
            new->కుడి = t;
            t->ఎడమ = ఖాళీ;
        } లేకపోతే {
            new->కుడి = t->కుడి;
            new->ఎడమ = t;
            t->కుడి = ఖాళీ;
        }
        new->ప్రారంభం = addr;
        new->కొలత = కొలత;
        new->type = TCC_TYPE_NONE;
        new->is_invalid = 0;
    }
    తిరిగి new;
}

#నిర్వచించు compare_destroy(ప్రారంభం,tstart) (ప్రారంభం < tstart ? -1 : \
                                       ప్రారంభం > tstart  ? 1 : 0)

స్థిర వృక్షం * splay_delete(కొలత_t addr, వృక్షం *t)
/* Deletes addr from the tree if it's there.               */
/* Return a pointer to the resulting tree.                 */
{
    వృక్షం * x;

    INCR_లెక్క_SPLAY(bound_splay_delete);
    ఒకవేళ (t==ఖాళీ) తిరిగి ఖాళీ;
    t = splay(addr,t);
    ఒకవేళ (compare_destroy(addr, t->ప్రారంభం) == 0) {        /* found it */
        ఒకవేళ (t->ఎడమ == ఖాళీ) {
            x = t->కుడి;
        } లేకపోతే {
            x = splay(addr, t->ఎడమ);
            x->కుడి = t->కుడి;
        }
#ఒకవేళ వృక్షం_REUSE
        t->ఎడమ = వృక్షం_free_list;
        వృక్షం_free_list = t;
#లేకపోతే
        BOUND_FREE(t);
#అయితే_ముగింపు
        తిరిగి x;
    } లేకపోతే {
        తిరిగి t;                                      /* It wasn't there */
    }
}

శూన్య splay_printtree(వృక్షం * t, పూర్ణాంకం d)
{
    పూర్ణాంకం i;
    ఒకవేళ (t == ఖాళీ) తిరిగి;
    splay_printtree(t->కుడి, d+1);
    కొరకు (i=0; i<d; i++) fprintf(stderr," ");
    fprintf(stderr,"%p(0x%lx:%u:%u)\n",
            (శూన్య *) t->ప్రారంభం, (గుర్తులేని దీర్ఘ) t->కొలత,
            (గుర్తులేని)t->type, (గుర్తులేని)t->is_invalid);
    splay_printtree(t->ఎడమ, d+1);
}
