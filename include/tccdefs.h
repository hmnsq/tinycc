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

#ಆದರೆ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ಆದರೆ defined  __OpenBSD__
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZE_TYPE__ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ
    #ವ್ಯಾಖ್ಯಾನಿಸು __PTRDIFF_TYPE__ ದೀರ್ಘ
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZE_TYPE__ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ
    #ವ್ಯಾಖ್ಯಾನಿಸು __PTRDIFF_TYPE__ ಪೂರ್ಣಾಂಕ
#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನಿಸು __ILP32__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT64_TYPE__ ದೀರ್ಘ ದೀರ್ಘ
#ಅಥವಾಆದರೆ __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZE_TYPE__ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ
    #ವ್ಯಾಖ್ಯಾನಿಸು __PTRDIFF_TYPE__ ದೀರ್ಘ ದೀರ್ಘ
    #ವ್ಯಾಖ್ಯಾನಿಸು __LLP64__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT64_TYPE__ ದೀರ್ಘ ದೀರ್ಘ
#ಇಲ್ಲದಿದ್ದರೆ
    /* Other 64bit systems. */
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZE_TYPE__ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ
    #ವ್ಯಾಖ್ಯಾನಿಸು __PTRDIFF_TYPE__ ದೀರ್ಘ
    #ವ್ಯಾಖ್ಯಾನಿಸು __LP64__ 1
# ಆದರೆ defined __linux__
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT64_TYPE__ ದೀರ್ಘ
# ಇಲ್ಲದಿದ್ದರೆ /* APPLE, BSD */
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT64_TYPE__ ದೀರ್ಘ ದೀರ್ಘ
# endif
#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_INT__ 4
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT_MAX__ 0x7fffffff
#ಆದರೆ __SIZEOF_LONG__ == 4
    #ವ್ಯಾಖ್ಯಾನಿಸು __LONG_MAX__ 0x7fffffffL
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __LONG_MAX__ 0x7fffffffffffffffL
#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_LONG_LONG__ 8
    #ವ್ಯಾಖ್ಯಾನಿಸು __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #ವ್ಯಾಖ್ಯಾನಿಸು __CHAR_BIT__ 8
    #ವ್ಯಾಖ್ಯಾನಿಸು __ORDER_LITTLE_ENDIAN__ 1234
    #ವ್ಯಾಖ್ಯಾನಿಸು __ORDER_BIG_ENDIAN__ 4321
    #ವ್ಯಾಖ್ಯಾನಿಸು __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ಆದರೆ defined _WIN32
    #ವ್ಯಾಖ್ಯಾನಿಸು __WCHAR_TYPE__ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ
    #ವ್ಯಾಖ್ಯಾನಿಸು __WINT_TYPE__ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ
#ಅಥವಾಆದರೆ defined __linux__
    #ವ್ಯಾಖ್ಯಾನಿಸು __WCHAR_TYPE__ ಪೂರ್ಣಾಂಕ
    #ವ್ಯಾಖ್ಯಾನಿಸು __WINT_TYPE__ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __WCHAR_TYPE__ ಪೂರ್ಣಾಂಕ
    #ವ್ಯಾಖ್ಯಾನಿಸು __WINT_TYPE__ ಪೂರ್ಣಾಂಕ
#ಆದರೆ_ಅಂತ್ಯ

    #ಆದರೆ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ಆದರೆ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#ಆದರೆ_ಅಂತ್ಯ
    #ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined _WIN32
    #ವ್ಯಾಖ್ಯಾನಿಸು __declspec(x) __attribute__((x))
    #ವ್ಯಾಖ್ಯಾನಿಸು __cdecl

#ಅಥವಾಆದರೆ defined __FreeBSD__
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC__ 9
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_MINOR__ 3
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_PATCHLEVEL__ 0
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_STDC_INLINE__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು __NO_TLS 1
    #ವ್ಯಾಖ್ಯಾನಿಸು __RUNETYPE_INTERNAL 1
# ಆದರೆ __SIZEOF_POINTER__ == 8
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_SIZE_T__ 8
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_PTRDIFF_T__ 8
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_SIZE_T__ 4
    #ವ್ಯಾಖ್ಯಾನಿಸು __SIZEOF_PTRDIFF_T__ 4
# endif

#ಅಥವಾಆದರೆ defined __FreeBSD_kernel__

#ಅಥವಾಆದರೆ defined __NetBSD__
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC__ 4
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_MINOR__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_PATCHLEVEL__ 0
    #ವ್ಯಾಖ್ಯಾನಿಸು _Pragma(x)
    #ವ್ಯಾಖ್ಯಾನಿಸು __ELF__ 1
#ಆದರೆ defined __aarch64__
    #ವ್ಯಾಖ್ಯಾನಿಸು _LOCORE /* avoids usage of __asm */
#ಆದರೆ_ಅಂತ್ಯ

#ಅಥವಾಆದರೆ defined __OpenBSD__
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC__ 4
    #ವ್ಯಾಖ್ಯಾನಿಸು _ANSI_LIBRARY 1

#ಅಥವಾಆದರೆ defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #ವ್ಯಾಖ್ಯಾನಿಸು __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #ವ್ಯಾಖ್ಯಾನಿಸು __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #ವ್ಯಾಖ್ಯಾನಿಸು __LITTLE_ENDIAN__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #ವ್ಯಾಖ್ಯಾನಿಸು __FINITE_MATH_ONLY__ 1
    #ವ್ಯಾಖ್ಯಾನಿಸು FORTIFY_ಮೂಲ 0
    //#define __has_builtin(x) 0
    #ವ್ಯಾಖ್ಯಾನಿಸು _Float16 ಗಿಡ್ಡ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ /* fake type just for size & alignment (macOS Sequoia) */

#ಅಥವಾಆದರೆ defined __ANDROID__
    #ವ್ಯಾಖ್ಯಾನಿಸು  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ಇಲ್ಲದಿದ್ದರೆ
    /* Linux */

#ಆದರೆ_ಅಂತ್ಯ

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NetBSD__
    #ವ್ಯಾಖ್ಯಾನಿಸು __UINTPTR_TYPE__ ಚಿಹ್ನೆರಹಿತ __PTRDIFF_TYPE__
    #ವ್ಯಾಖ್ಯಾನಿಸು __INTPTR_TYPE__ __PTRDIFF_TYPE__
#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನಿಸು __INT32_TYPE__ ಪೂರ್ಣಾಂಕ

#ಆದರೆ !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #ವ್ಯಾಖ್ಯಾನಿಸು __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #ವ್ಯಾಖ್ಯಾನಿಸು __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #ವ್ಯಾಖ್ಯಾನಿಸು __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#ಆದರೆ_ಅಂತ್ಯ

    /* not implemented */
    #ವ್ಯಾಖ್ಯಾನಿಸು  __PRETTY_FUNCTION__ __FUNCTION__
    #ವ್ಯಾಖ್ಯಾನಿಸು __has_builtin(x) 0
    #ವ್ಯಾಖ್ಯಾನಿಸು __has_feature(x) 0
    #ವ್ಯಾಖ್ಯಾನಿಸು __has_attribute(x) 0
    /* C23 Keywords */
    #ವ್ಯಾಖ್ಯಾನಿಸು _Nonnull
    #ವ್ಯಾಖ್ಯಾನಿಸು _Nullable
    #ವ್ಯಾಖ್ಯಾನಿಸು Nullable_ಫಲಿತಾಂಶ
    #ವ್ಯಾಖ್ಯಾನಿಸು _Null_unspecified

    /* skip __builtin... with -E */
    #ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TCC_PP__

    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_offsetof(type, ಕ್ಷೇತ್ರ) ((__SIZE_TYPE__)&((type*)0)->ಕ್ಷೇತ್ರ)
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_extract_return_addr(x) x
#ಆದರೆ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_huge_val() 1e500
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_huge_valf() 1e50f
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_huge_vall() 1e5000L
# ಆದರೆ defined __APPLE__
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_bzero(p, ignored_ಗಾತ್ರ) bzero(p, ಗಾತ್ರ(*(p)))
# ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#ಆದರೆ_ಅಂತ್ಯ

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ರಚನೆ __uint128__ { ಅಕ್ಷರ x[16]; } __attribute((__aligned__(16)));
    #ವ್ಯಾಖ್ಯಾನಿಸು __int128_t ರಚನೆ __uint128__
    #ವ್ಯಾಖ್ಯಾನಿಸು __uint128_t ರಚನೆ __uint128__

    /* __builtin_va_list */
#ಆದರೆ defined __x86_64__
#ಆದರೆ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
        ಚಿಹ್ನೆರಹಿತ gp_ಸ್ಥಾನಾಂತರ, fp_ಸ್ಥಾನಾಂತರ;
        ಒಕ್ಕೂಟ {
            ಚಿಹ್ನೆರಹಿತ ಅತಿಪ್ರವಾಹ_ಸ್ಥಾನಾಂತರ;
            ಅಕ್ಷರ *ಅತಿಪ್ರವಾಹ_arg_area;
        };
        ಅಕ್ಷರ *reg_save_area;
    } __builtin_va_list[1];

    ಶೂನ್ಯ *__va_arg(__builtin_va_list ap, ಪೂರ್ಣಾಂಕ arg_type, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ align);
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_start(ap, ಕೊನೆಯ) \
       (*(ap) = *(__builtin_va_list)((ಅಕ್ಷರ*)__builtin_frame_address(0) - 24))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), ಗಾತ್ರ(t), __alignof__(t))))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_copy(dest, src) (*(dest) = *(src))

#ಇಲ್ಲದಿದ್ದರೆ /* _WIN64 */
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *__builtin_va_list;
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_arg(ap, t) ((ಗಾತ್ರ(t) > 8 || (ಗಾತ್ರ(t) & (ಗಾತ್ರ(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#ಆದರೆ_ಅಂತ್ಯ

#ಅಥವಾಆದರೆ defined __arm__
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *__builtin_va_list;
    #ವ್ಯಾಖ್ಯಾನಿಸು _tcc_alignof(type) ((ಪೂರ್ಣಾಂಕ)&((ರಚನೆ {ಅಕ್ಷರ c;type x;} *)0)->x)
    #ವ್ಯಾಖ್ಯಾನಿಸು _tcc_align(addr,type) (((ಚಿಹ್ನೆರಹಿತ)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_start(ap,ಕೊನೆಯ) (ap = ((ಅಕ್ಷರ *)&(ಕೊನೆಯ)) + ((ಗಾತ್ರ(ಕೊನೆಯ)+3)&~3))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_arg(ap,type) (ap = (ಶೂನ್ಯ *) ((_tcc_align(ap,type)+ಗಾತ್ರ(type)+3) \
                           &~3), *(type *)(ap - ((ಗಾತ್ರ(type)+3)&~3)))

#ಅಥವಾಆದರೆ defined __aarch64__
#ಆದರೆ defined _WIN32
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *__builtin_va_list;
#ಅಥವಾಆದರೆ defined __APPLE__
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
        ಶೂನ್ಯ *__stack;
    } __builtin_va_list;

#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
        ಶೂನ್ಯ *__stack, *__gr_top, *__vr_top;
        ಪೂರ್ಣಾಂಕ   __gr_offs, __vr_offs;
    } __builtin_va_list;

#ಆದರೆ_ಅಂತ್ಯ
#ಅಥವಾಆದರೆ defined __riscv
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *__builtin_va_list;
    #ವ್ಯಾಖ್ಯಾನಿಸು __va_reg_size (__riscv_xlen >> 3)
    #ವ್ಯಾಖ್ಯಾನಿಸು _tcc_align(addr,type) (((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_arg(ap,type) (*(ಗಾತ್ರ(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (ಗಾತ್ರ(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((ಗಾತ್ರ(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ಇಲ್ಲದಿದ್ದರೆ /* __i386__ */
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *__builtin_va_list;
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_start(ap,ಕೊನೆಯ) (ap = ((ಅಕ್ಷರ *)&(ಕೊನೆಯ)) + ((ಗಾತ್ರ(ಕೊನೆಯ)+3)&~3))
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_arg(ap,t) (*(t*)((ap+=(ಗಾತ್ರ(t)+3)&~3)-((ಗಾತ್ರ(t)+3)&~3)))

#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನಿಸು __builtin_va_end(ap) (ಶೂನ್ಯ)(ap)
    #ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #ಆದರೆ_ಅಂತ್ಯ

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ಇಲ್ಲದಿದ್ದರೆ
    # define __RENAME(X) __asm__(X)
    #ಆದರೆ_ಅಂತ್ಯ

    #ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ಇಲ್ಲದಿದ್ದರೆ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    #ವ್ಯಾಖ್ಯಾನಿಸು __BOTH __BOUND
    #ವ್ಯಾಖ್ಯಾನಿಸು __BUILTIN(ret,name,params)
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #ವ್ಯಾಖ್ಯಾನಿಸು __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#ಆದರೆ_ಅಂತ್ಯ

    __BOTH(ಶೂನ್ಯ*, ಸ್ಮರಣೆ_ನಕಲು, (ಶೂನ್ಯ *, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(ಶೂನ್ಯ*, memmove, (ಶೂನ್ಯ *, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(ಶೂನ್ಯ*, memset, (ಶೂನ್ಯ *, ಪೂರ್ಣಾಂಕ, __SIZE_TYPE__))
    __BOTH(ಪೂರ್ಣಾಂಕ, memcmp, (ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *))
    __BOTH(ಅಕ್ಷರ*, strcpy, (ಅಕ್ಷರ *, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *))
    __BOTH(ಅಕ್ಷರ*, strncpy, (ಅಕ್ಷರ *, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, __SIZE_TYPE__))
    __BOTH(ಪೂರ್ಣಾಂಕ, strcmp, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*))
    __BOTH(ಪೂರ್ಣಾಂಕ, ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, __SIZE_TYPE__))
    __BOTH(ಅಕ್ಷರ*, strcat, (ಅಕ್ಷರ*, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*))
    __BOTH(ಅಕ್ಷರ*, strncat, (ಅಕ್ಷರ*, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, __SIZE_TYPE__))
    __BOTH(ಅಕ್ಷರ*, strchr, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ಪೂರ್ಣಾಂಕ))
    __BOTH(ಅಕ್ಷರ*, strrchr, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ಪೂರ್ಣಾಂಕ))
    __BOTH(ಅಕ್ಷರ*, strdup, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*))
#ಆದರೆ defined __ARM_EABI__
    __BOUND(ಶೂನ್ಯ*,__aeabi_memcpy,(ಶೂನ್ಯ*,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove,(ಶೂನ್ಯ*,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove4,(ಶೂನ್ಯ*,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memmove8,(ಶೂನ್ಯ*,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*,__SIZE_TYPE__))
    __BOUND(ಶೂನ್ಯ*,__aeabi_memset,(ಶೂನ್ಯ*,ಪೂರ್ಣಾಂಕ,__SIZE_TYPE__))
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #ವ್ಯಾಖ್ಯಾನಿಸು __MAYBE_REDIR __BUILTIN
#ಇಲ್ಲದಿದ್ದರೆ
    #ವ್ಯಾಖ್ಯಾನಿಸು __MAYBE_REDIR __BOTH
#ಆದರೆ_ಅಂತ್ಯ
    __MAYBE_REDIR(ಶೂನ್ಯ*, ಸ್ಮರಣೆ_ಕೊಡು, (__SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, realloc, (ಶೂನ್ಯ *, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ಶೂನ್ಯ, ಬಿಡುಗಡೆ, (ಶೂನ್ಯ*))
    __BOTH(ಶೂನ್ಯ*, alloca, (__SIZE_TYPE__))
    ಶೂನ್ಯ *alloca(__SIZE_TYPE__);
    __BUILTIN(ಶೂನ್ಯ, abort, (ಶೂನ್ಯ))
    __BOUND(ಶೂನ್ಯ, longjmp, ())
#ಆದರೆ !defined _WIN32
    __BOUND(ಶೂನ್ಯ*, mmap, ())
    __BOUND(ಪೂರ್ಣಾಂಕ, munmap, ())
#ಆದರೆ_ಅಂತ್ಯ
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __BUILTINBC
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __BUILTIN
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __BOUND
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __BOTH
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __MAYBE_REDIR
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __RENAME

    #ವ್ಯಾಖ್ಯಾನಿಸು __BUILTIN_EXTERN(name,u) 		\
        ಪೂರ್ಣಾಂಕ __builtin_##name(u ಪೂರ್ಣಾಂಕ);		\
        ಪೂರ್ಣಾಂಕ __builtin_##name##l(u ದೀರ್ಘ);	\
        ಪೂರ್ಣಾಂಕ __builtin_##name##ll(u ದೀರ್ಘ ದೀರ್ಘ);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, ಚಿಹ್ನೆರಹಿತ)
    __BUILTIN_EXTERN(ctz, ಚಿಹ್ನೆರಹಿತ)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, ಚಿಹ್ನೆರಹಿತ)
    __BUILTIN_EXTERN(parity, ಚಿಹ್ನೆರಹಿತ)
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __BUILTIN_EXTERN

    #ಆದರೆ_ಅಂತ್ಯ /* ndef __TCC_PP__ */
