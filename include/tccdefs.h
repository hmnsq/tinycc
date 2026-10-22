/*  tccdefs.h

    Nothing is defined before this file except target machine, target os
    and the few things related to option settings in tccpp.c:tcc_predefs().

    This file is either included at runtime as is, or converted and
    included as C-strings at compile-time (depending on CONFIG_TCC_PREDEFS).

    Note that line indent matters:

    - in lines starting at column 1, platform macros are replaced by
      corresponding TCC target compile-time macros.  See conftest.c for
      the list of platform macros supported in lines starting at column 1.

    - only lines indented >= 4 are actually included into the executable,
      check tccdefs_.h.
*/

#ఒకవేళ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ఒకవేళ defined  __OpenBSD__
    #నిర్వచించు __SIZE_TYPE__ గుర్తులేని దీర్ఘ
    #నిర్వచించు __PTRDIFF_TYPE__ దీర్ఘ
#లేకపోతే
    #నిర్వచించు __SIZE_TYPE__ గుర్తులేని పూర్ణాంకం
    #నిర్వచించు __PTRDIFF_TYPE__ పూర్ణాంకం
#అయితే_ముగింపు
    #నిర్వచించు __ILP32__ 1
    #నిర్వచించు __INT64_TYPE__ దీర్ఘ దీర్ఘ
#లేదావేళ __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #నిర్వచించు __SIZE_TYPE__ గుర్తులేని దీర్ఘ దీర్ఘ
    #నిర్వచించు __PTRDIFF_TYPE__ దీర్ఘ దీర్ఘ
    #నిర్వచించు __LLP64__ 1
    #నిర్వచించు __INT64_TYPE__ దీర్ఘ దీర్ఘ
#లేకపోతే
    /* Other 64bit systems. */
    #నిర్వచించు __SIZE_TYPE__ గుర్తులేని దీర్ఘ
    #నిర్వచించు __PTRDIFF_TYPE__ దీర్ఘ
    #నిర్వచించు __LP64__ 1
# ఒకవేళ defined __linux__
    #నిర్వచించు __INT64_TYPE__ దీర్ఘ
# లేకపోతే /* APPLE, BSD */
    #నిర్వచించు __INT64_TYPE__ దీర్ఘ దీర్ఘ
# endif
#అయితే_ముగింపు
    #నిర్వచించు __SIZEOF_INT__ 4
    #నిర్వచించు __INT_MAX__ 0x7fffffff
#ఒకవేళ __SIZEOF_LONG__ == 4
    #నిర్వచించు __LONG_MAX__ 0x7fffffffL
#లేకపోతే
    #నిర్వచించు __LONG_MAX__ 0x7fffffffffffffffL
#అయితే_ముగింపు
    #నిర్వచించు __SIZEOF_LONG_LONG__ 8
    #నిర్వచించు __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #నిర్వచించు __CHAR_BIT__ 8
    #నిర్వచించు __ORDER_LITTLE_ENDIAN__ 1234
    #నిర్వచించు __ORDER_BIG_ENDIAN__ 4321
    #నిర్వచించు __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ఒకవేళ defined _WIN32
    #నిర్వచించు __WCHAR_TYPE__ గుర్తులేని పొట్టి
    #నిర్వచించు __WINT_TYPE__ గుర్తులేని పొట్టి
#లేదావేళ defined __linux__
    #నిర్వచించు __WCHAR_TYPE__ పూర్ణాంకం
    #నిర్వచించు __WINT_TYPE__ గుర్తులేని పూర్ణాంకం
#లేకపోతే
    #నిర్వచించు __WCHAR_TYPE__ పూర్ణాంకం
    #నిర్వచించు __WINT_TYPE__ పూర్ణాంకం
#అయితే_ముగింపు

    #ఒకవేళ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ఒకవేళ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#అయితే_ముగింపు
    #అయితే_ముగింపు

#ఒకవేళ defined _WIN32
    #నిర్వచించు __declspec(x) __attribute__((x))
    #నిర్వచించు __cdecl

#లేదావేళ defined __FreeBSD__
    #నిర్వచించు __GNUC__ 9
    #నిర్వచించు __GNUC_MINOR__ 3
    #నిర్వచించు __GNUC_PATCHLEVEL__ 0
    #నిర్వచించు __GNUC_STDC_INLINE__ 1
    #నిర్వచించు __NO_TLS 1
    #నిర్వచించు __RUNETYPE_INTERNAL 1
# ఒకవేళ __SIZEOF_POINTER__ == 8
    #నిర్వచించు __SIZEOF_SIZE_T__ 8
    #నిర్వచించు __SIZEOF_PTRDIFF_T__ 8
#లేకపోతే
    #నిర్వచించు __SIZEOF_SIZE_T__ 4
    #నిర్వచించు __SIZEOF_PTRDIFF_T__ 4
# endif

#లేదావేళ defined __FreeBSD_kernel__

#లేదావేళ defined __NetBSD__
    #నిర్వచించు __GNUC__ 4
    #నిర్వచించు __GNUC_MINOR__ 1
    #నిర్వచించు __GNUC_PATCHLEVEL__ 0
    #నిర్వచించు _Pragma(x)
    #నిర్వచించు __ELF__ 1
#ఒకవేళ defined __aarch64__
    #నిర్వచించు _LOCORE /* avoids usage of __asm */
#అయితే_ముగింపు

#లేదావేళ defined __OpenBSD__
    #నిర్వచించు __GNUC__ 4
    #నిర్వచించు _ANSI_LIBRARY 1

#లేదావేళ defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #నిర్వచించు __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #నిర్వచించు __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #నిర్వచించు __LITTLE_ENDIAN__ 1
    #నిర్వచించు _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #నిర్వచించు __FINITE_MATH_ONLY__ 1
    #నిర్వచించు FORTIFY_ఆధారం 0
    //#define __has_builtin(x) 0
    #నిర్వచించు _Float16 పొట్టి గుర్తులేని పూర్ణాంకం /* fake type just for size & alignment (macOS Sequoia) */

#లేదావేళ defined __ANDROID__
    #నిర్వచించు  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#లేకపోతే
    /* Linux */

#అయితే_ముగింపు

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#నిర్వచితం_కాకపోతే __NetBSD__
    #నిర్వచించు __UINTPTR_TYPE__ గుర్తులేని __PTRDIFF_TYPE__
    #నిర్వచించు __INTPTR_TYPE__ __PTRDIFF_TYPE__
#అయితే_ముగింపు
    #నిర్వచించు __INT32_TYPE__ పూర్ణాంకం

#ఒకవేళ !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #నిర్వచించు __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #నిర్వచించు __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #నిర్వచించు __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#అయితే_ముగింపు

    /* not implemented */
    #నిర్వచించు  __PRETTY_FUNCTION__ __FUNCTION__
    #నిర్వచించు __has_builtin(x) 0
    #నిర్వచించు __has_feature(x) 0
    #నిర్వచించు __has_attribute(x) 0
    /* C23 Keywords */
    #నిర్వచించు _Nonnull
    #నిర్వచించు _Nullable
    #నిర్వచించు Nullable_ఫలితం
    #నిర్వచించు _Null_unspecified

    /* skip __builtin... with -E */
    #నిర్వచితం_కాకపోతే __TCC_PP__

    #నిర్వచించు __builtin_offsetof(type, క్షేత్రం) ((__SIZE_TYPE__)&((type*)0)->క్షేత్రం)
    #నిర్వచించు __builtin_extract_return_addr(x) x
#ఒకవేళ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #నిర్వచించు __builtin_huge_val() 1e500
    #నిర్వచించు __builtin_huge_valf() 1e50f
    #నిర్వచించు __builtin_huge_vall() 1e5000L
# ఒకవేళ defined __APPLE__
    #నిర్వచించు __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #నిర్వచించు __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #నిర్వచించు __builtin_bzero(p, ignored_కొలత) bzero(p, పరిమాణం(*(p)))
# లేకపోతే
    #నిర్వచించు __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#అయితే_ముగింపు

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    నిర్మాణం __uint128__ { అక్షరం x[16]; } __attribute((__aligned__(16)));
    #నిర్వచించు __int128_t నిర్మాణం __uint128__
    #నిర్వచించు __uint128_t నిర్మాణం __uint128__

    /* __builtin_va_list */
#ఒకవేళ defined __x86_64__
#ఒకవేళ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    రకనిర్వచనం నిర్మాణం {
        గుర్తులేని gp_స్థానభ్రంశం, fp_స్థానభ్రంశం;
        సంఘం {
            గుర్తులేని అధికప్రవాహం_స్థానభ్రంశం;
            అక్షరం *అధికప్రవాహం_arg_area;
        };
        అక్షరం *reg_save_area;
    } __builtin_va_list[1];

    శూన్య *__va_arg(__builtin_va_list ap, పూర్ణాంకం arg_type, పూర్ణాంకం కొలత, పూర్ణాంకం align);
    #నిర్వచించు __builtin_va_start(ap, చివరి) \
       (*(ap) = *(__builtin_va_list)((అక్షరం*)__builtin_frame_address(0) - 24))
    #నిర్వచించు __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), పరిమాణం(t), __alignof__(t))))
    #నిర్వచించు __builtin_va_copy(dest, src) (*(dest) = *(src))

#లేకపోతే /* _WIN64 */
    రకనిర్వచనం అక్షరం *__builtin_va_list;
    #నిర్వచించు __builtin_va_arg(ap, t) ((పరిమాణం(t) > 8 || (పరిమాణం(t) & (పరిమాణం(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#అయితే_ముగింపు

#లేదావేళ defined __arm__
    రకనిర్వచనం అక్షరం *__builtin_va_list;
    #నిర్వచించు _tcc_alignof(type) ((పూర్ణాంకం)&((నిర్మాణం {అక్షరం c;type x;} *)0)->x)
    #నిర్వచించు _tcc_align(addr,type) (((గుర్తులేని)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #నిర్వచించు __builtin_va_start(ap,చివరి) (ap = ((అక్షరం *)&(చివరి)) + ((పరిమాణం(చివరి)+3)&~3))
    #నిర్వచించు __builtin_va_arg(ap,type) (ap = (శూన్య *) ((_tcc_align(ap,type)+పరిమాణం(type)+3) \
                           &~3), *(type *)(ap - ((పరిమాణం(type)+3)&~3)))

#లేదావేళ defined __aarch64__
#ఒకవేళ defined _WIN32
    రకనిర్వచనం అక్షరం *__builtin_va_list;
#లేదావేళ defined __APPLE__
    రకనిర్వచనం నిర్మాణం {
        శూన్య *__stack;
    } __builtin_va_list;

#లేకపోతే
    రకనిర్వచనం నిర్మాణం {
        శూన్య *__stack, *__gr_top, *__vr_top;
        పూర్ణాంకం   __gr_offs, __vr_offs;
    } __builtin_va_list;

#అయితే_ముగింపు
#లేదావేళ defined __riscv
    రకనిర్వచనం అక్షరం *__builtin_va_list;
    #నిర్వచించు __va_reg_size (__riscv_xlen >> 3)
    #నిర్వచించు _tcc_align(addr,type) (((గుర్తులేని దీర్ఘ)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #నిర్వచించు __builtin_va_arg(ap,type) (*(పరిమాణం(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (పరిమాణం(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((పరిమాణం(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#లేకపోతే /* __i386__ */
    రకనిర్వచనం అక్షరం *__builtin_va_list;
    #నిర్వచించు __builtin_va_start(ap,చివరి) (ap = ((అక్షరం *)&(చివరి)) + ((పరిమాణం(చివరి)+3)&~3))
    #నిర్వచించు __builtin_va_arg(ap,t) (*(t*)((ap+=(పరిమాణం(t)+3)&~3)-((పరిమాణం(t)+3)&~3)))

#అయితే_ముగింపు
    #నిర్వచించు __builtin_va_end(ap) (శూన్య)(ap)
    #నిర్వచితం_కాకపోతే __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #అయితే_ముగింపు

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #నిర్వచితమైతే __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #లేకపోతే
    # define __RENAME(X) __asm__(X)
    #అయితే_ముగింపు

    #నిర్వచితమైతే __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #లేకపోతే
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #అయితే_ముగింపు
#నిర్వచితమైతే _WIN32
    #నిర్వచించు __BOTH __BOUND
    #నిర్వచించు __BUILTIN(ret,name,params)
#లేకపోతే
    #నిర్వచించు __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #నిర్వచించు __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#అయితే_ముగింపు

    __BOTH(శూన్య*, జ్ఞాపకం_నకలు, (శూన్య *, స్థిరరాశి శూన్య*, __SIZE_TYPE__))
    __BOTH(శూన్య*, memmove, (శూన్య *, స్థిరరాశి శూన్య*, __SIZE_TYPE__))
    __BOTH(శూన్య*, memset, (శూన్య *, పూర్ణాంకం, __SIZE_TYPE__))
    __BOTH(పూర్ణాంకం, memcmp, (స్థిరరాశి శూన్య *, స్థిరరాశి శూన్య*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, అక్షరశ్రేణి_పొడవు, (స్థిరరాశి అక్షరం *))
    __BOTH(అక్షరం*, strcpy, (అక్షరం *, స్థిరరాశి అక్షరం *))
    __BOTH(అక్షరం*, strncpy, (అక్షరం *, స్థిరరాశి అక్షరం*, __SIZE_TYPE__))
    __BOTH(పూర్ణాంకం, strcmp, (స్థిరరాశి అక్షరం*, స్థిరరాశి అక్షరం*))
    __BOTH(పూర్ణాంకం, అక్షరశ్రేణి_పోలిక, (స్థిరరాశి అక్షరం*, స్థిరరాశి అక్షరం*, __SIZE_TYPE__))
    __BOTH(అక్షరం*, strcat, (అక్షరం*, స్థిరరాశి అక్షరం*))
    __BOTH(అక్షరం*, strncat, (అక్షరం*, స్థిరరాశి అక్షరం*, __SIZE_TYPE__))
    __BOTH(అక్షరం*, strchr, (స్థిరరాశి అక్షరం*, పూర్ణాంకం))
    __BOTH(అక్షరం*, strrchr, (స్థిరరాశి అక్షరం*, పూర్ణాంకం))
    __BOTH(అక్షరం*, strdup, (స్థిరరాశి అక్షరం*))
#ఒకవేళ defined __ARM_EABI__
    __BOUND(శూన్య*,__aeabi_memcpy,(శూన్య*,స్థిరరాశి శూన్య*,__SIZE_TYPE__))
    __BOUND(శూన్య*,__aeabi_memmove,(శూన్య*,స్థిరరాశి శూన్య*,__SIZE_TYPE__))
    __BOUND(శూన్య*,__aeabi_memmove4,(శూన్య*,స్థిరరాశి శూన్య*,__SIZE_TYPE__))
    __BOUND(శూన్య*,__aeabi_memmove8,(శూన్య*,స్థిరరాశి శూన్య*,__SIZE_TYPE__))
    __BOUND(శూన్య*,__aeabi_memset,(శూన్య*,పూర్ణాంకం,__SIZE_TYPE__))
#అయితే_ముగింపు

#ఒకవేళ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #నిర్వచించు __MAYBE_REDIR __BUILTIN
#లేకపోతే
    #నిర్వచించు __MAYBE_REDIR __BOTH
#అయితే_ముగింపు
    __MAYBE_REDIR(శూన్య*, జ్ఞాపకం_ఇవ్వు, (__SIZE_TYPE__))
    __MAYBE_REDIR(శూన్య*, realloc, (శూన్య *, __SIZE_TYPE__))
    __MAYBE_REDIR(శూన్య*, సున్నా_జ్ఞాపకం_ఇవ్వు, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(శూన్య*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(శూన్య, విడుదల, (శూన్య*))
    __BOTH(శూన్య*, alloca, (__SIZE_TYPE__))
    శూన్య *alloca(__SIZE_TYPE__);
    __BUILTIN(శూన్య, abort, (శూన్య))
    __BOUND(శూన్య, longjmp, ())
#ఒకవేళ !defined _WIN32
    __BOUND(శూన్య*, mmap, ())
    __BOUND(పూర్ణాంకం, munmap, ())
#అయితే_ముగింపు
    #నిర్వచనం_రద్దు __BUILTINBC
    #నిర్వచనం_రద్దు __BUILTIN
    #నిర్వచనం_రద్దు __BOUND
    #నిర్వచనం_రద్దు __BOTH
    #నిర్వచనం_రద్దు __MAYBE_REDIR
    #నిర్వచనం_రద్దు __RENAME

    #నిర్వచించు __BUILTIN_EXTERN(name,u) 		\
        పూర్ణాంకం __builtin_##name(u పూర్ణాంకం);		\
        పూర్ణాంకం __builtin_##name##l(u దీర్ఘ);	\
        పూర్ణాంకం __builtin_##name##ll(u దీర్ఘ దీర్ఘ);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, గుర్తులేని)
    __BUILTIN_EXTERN(ctz, గుర్తులేని)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, గుర్తులేని)
    __BUILTIN_EXTERN(parity, గుర్తులేని)
    #నిర్వచనం_రద్దు __BUILTIN_EXTERN

    #అయితే_ముగింపు /* ndef __TCC_PP__ */
