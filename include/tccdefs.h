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

#ಯದಿ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ಯದಿ defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#ಅನ್ಯಥಾ
    #define __SIZE_TYPE__ unsigned ಪೂರ್ಣಾಙ್ಕ
    #define __PTRDIFF_TYPE__ ಪೂರ್ಣಾಙ್ಕ
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#ನೋಚೇದ್ಯದಿ __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#ಅನ್ಯಥಾ
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# ಯದಿ defined __linux__
    #define __INT64_TYPE__ long
# ಅನ್ಯಥಾ /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#ಯದಿ __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#ಅನ್ಯಥಾ
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ಯದಿ defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#ನೋಚೇದ್ಯದಿ defined __linux__
    #define __WCHAR_TYPE__ ಪೂರ್ಣಾಙ್ಕ
    #define __WINT_TYPE__ unsigned ಪೂರ್ಣಾಙ್ಕ
#ಅನ್ಯಥಾ
    #define __WCHAR_TYPE__ ಪೂರ್ಣಾಙ್ಕ
    #define __WINT_TYPE__ ಪೂರ್ಣಾಙ್ಕ
#endif

    #ಯದಿ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ಯದಿ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#ಯದಿ defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#ನೋಚೇದ್ಯದಿ defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# ಯದಿ __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#ಅನ್ಯಥಾ
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#ನೋಚೇದ್ಯದಿ defined __FreeBSD_kernel__

#ನೋಚೇದ್ಯದಿ defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#ಯದಿ defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#ನೋಚೇದ್ಯದಿ defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#ನೋಚೇದ್ಯದಿ defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned ಪೂರ್ಣಾಙ್ಕ /* fake type just for size & alignment (macOS Sequoia) */

#ನೋಚೇದ್ಯದಿ defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ಅನ್ಯಥಾ
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ ಪೂರ್ಣಾಙ್ಕ

#ಯದಿ !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #define __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #define __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #define __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#endif

    /* not implemented */
    #define  __PRETTY_FUNCTION__ __FUNCTION__
    #define __has_builtin(x) 0
    #define __has_feature(x) 0
    #define __has_attribute(x) 0
    /* C23 Keywords */
    #define _Nonnull
    #define _Nullable
    #define _Nullable_result
    #define _Null_unspecified

    /* skip __builtin... with -E */
    #ifndef __TCC_PP__

    #define __builtin_offsetof(type, field) ((__SIZE_TYPE__)&((type*)0)->field)
    #define __builtin_extract_return_addr(x) x
#ಯದಿ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# ಯದಿ defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, ಪರಿಮಾಣ(*(p)))
# ಅನ್ಯಥಾ
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ಸಂರಚನಾ __uint128__ { ವರ್ಣ x[16]; } __attribute((__aligned__(16)));
    #define __int128_t ಸಂರಚನಾ __uint128__
    #define __uint128_t ಸಂರಚನಾ __uint128__

    /* __builtin_va_list */
#ಯದಿ defined __x86_64__
#ಯದಿ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
        unsigned gp_offset, fp_offset;
        ಸಙ್ಘ {
            unsigned overflow_offset;
            ವರ್ಣ *overflow_arg_area;
        };
        ವರ್ಣ *reg_save_area;
    } __builtin_va_list[1];

    ಶೂನ್ಯ *__va_arg(__builtin_va_list ap, ಪೂರ್ಣಾಙ್ಕ arg_type, ಪೂರ್ಣಾಙ್ಕ size, ಪೂರ್ಣಾಙ್ಕ align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((ವರ್ಣ*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), ಪರಿಮಾಣ(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#ಅನ್ಯಥಾ /* _WIN64 */
    ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((ಪರಿಮಾಣ(t) > 8 || (ಪರಿಮಾಣ(t) & (ಪರಿಮಾಣ(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#ನೋಚೇದ್ಯದಿ defined __arm__
    ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *__builtin_va_list;
    #define _tcc_alignof(type) ((ಪೂರ್ಣಾಙ್ಕ)&((ಸಂರಚನಾ {ವರ್ಣ c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((ವರ್ಣ *)&(last)) + ((ಪರಿಮಾಣ(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (ಶೂನ್ಯ *) ((_tcc_align(ap,type)+ಪರಿಮಾಣ(type)+3) \
                           &~3), *(type *)(ap - ((ಪರಿಮಾಣ(type)+3)&~3)))

#ನೋಚೇದ್ಯದಿ defined __aarch64__
#ಯದಿ defined _WIN32
    ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *__builtin_va_list;
#ನೋಚೇದ್ಯದಿ defined __APPLE__
    ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
        ಶೂನ್ಯ *__stack;
    } __builtin_va_list;

#ಅನ್ಯಥಾ
    ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
        ಶೂನ್ಯ *__stack, *__gr_top, *__vr_top;
        ಪೂರ್ಣಾಙ್ಕ   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#ನೋಚೇದ್ಯದಿ defined __riscv
    ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(ಪರಿಮಾಣ(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (ಪರಿಮಾಣ(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((ಪರಿಮಾಣ(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ಅನ್ಯಥಾ /* __i386__ */
    ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((ವರ್ಣ *)&(last)) + ((ಪರಿಮಾಣ(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(ಪರಿಮಾಣ(t)+3)&~3)-((ಪರಿಮಾಣ(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (ಶೂನ್ಯ)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ಅನ್ಯಥಾ
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ಅನ್ಯಥಾ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#ಅನ್ಯಥಾ
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(ಶೂನ್ಯ*, memcpy, (ಶೂನ್ಯ *, ಧ್ರುವ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(ಶೂನ್ಯ*, memmove, (ಶೂನ್ಯ *, ಧ್ರುವ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(ಶೂನ್ಯ*, memset, (ಶೂನ್ಯ *, ಪೂರ್ಣಾಙ್ಕ, __SIZE_TYPE__))
    __BOTH(ಪೂರ್ಣಾಙ್ಕ, memcmp, (ಧ್ರುವ ಶೂನ್ಯ *, ಧ್ರುವ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (ಧ್ರುವ ವರ್ಣ *))
    __BOTH(ವರ್ಣ*, strcpy, (ವರ್ಣ *, ಧ್ರುವ ವರ್ಣ *))
    __BOTH(ವರ್ಣ*, strncpy, (ವರ್ಣ *, ಧ್ರುವ ವರ್ಣ*, __SIZE_TYPE__))
    __BOTH(ಪೂರ್ಣಾಙ್ಕ, strcmp, (ಧ್ರುವ ವರ್ಣ*, ಧ್ರುವ ವರ್ಣ*))
    __BOTH(ಪೂರ್ಣಾಙ್ಕ, strncmp, (ಧ್ರುವ ವರ್ಣ*, ಧ್ರುವ ವರ್ಣ*, __SIZE_TYPE__))
    __BOTH(ವರ್ಣ*, strcat, (ವರ್ಣ*, ಧ್ರುವ ವರ್ಣ*))
    __BOTH(ವರ್ಣ*, strncat, (ವರ್ಣ*, ಧ್ರುವ ವರ್ಣ*, __SIZE_TYPE__))
    __BOTH(ವರ್ಣ*, strchr, (ಧ್ರುವ ವರ್ಣ*, ಪೂರ್ಣಾಙ್ಕ))
    __BOTH(ವರ್ಣ*, strrchr, (ಧ್ರುವ ವರ್ಣ*, ಪೂರ್ಣಾಙ್ಕ))
    __BOTH(ವರ್ಣ*, strdup, (ಧ್ರುವ ವರ್ಣ*))
#ಯದಿ defined __ARM_EABI__
    __BOUND(ಶೂನ್ಯ*,__aeabi_memcpy,(ಶೂನ್ಯ*,ಧ್ರುವ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove,(ಶೂನ್ಯ*,ಧ್ರುವ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove4,(ಶೂನ್ಯ*,ಧ್ರುವ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove8,(ಶೂನ್ಯ*,ಧ್ರುವ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memset,(ಶೂನ್ಯ*,ಪೂರ್ಣಾಙ್ಕ,__SIZE_TYPE__))
#endif

#ಯದಿ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#ಅನ್ಯಥಾ
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(ಶೂನ್ಯ*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, realloc, (ಶೂನ್ಯ *, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ, ಮುಕ್ತ, (ಶೂನ್ಯ*))
    __BOTH(ಶೂನ್ಯ*, alloca, (__SIZE_TYPE__))
    ಶೂನ್ಯ *alloca(__SIZE_TYPE__);
    __BUILTIN(ಶೂನ್ಯ, abort, (ಶೂನ್ಯ))
    __BOUND(ಶೂನ್ಯ, longjmp, ())
#ಯದಿ !defined _WIN32
    __BOUND(ಶೂನ್ಯ*, mmap, ())
    __BOUND(ಪೂರ್ಣಾಙ್ಕ, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        ಪೂರ್ಣಾಙ್ಕ __builtin_##name(u ಪೂರ್ಣಾಙ್ಕ);		\
        ಪೂರ್ಣಾಙ್ಕ __builtin_##name##l(u long);	\
        ಪೂರ್ಣಾಙ್ಕ __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
