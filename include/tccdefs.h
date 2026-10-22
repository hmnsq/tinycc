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

#ਜੇ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ਜੇ defined  __OpenBSD__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZE_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PTRDIFF_TYPE__ ਲੰਮਾ
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZE_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PTRDIFF_TYPE__ ਪੂਰਨ
#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ILP32__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT64_TYPE__ ਲੰਮਾ ਲੰਮਾ
#ਜਾਂਜੇ __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZE_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PTRDIFF_TYPE__ ਲੰਮਾ ਲੰਮਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LLP64__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT64_TYPE__ ਲੰਮਾ ਲੰਮਾ
#ਨਹੀਂਤਾਂ
    /* Other 64bit systems. */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZE_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PTRDIFF_TYPE__ ਲੰਮਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LP64__ 1
# ਜੇ defined __linux__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT64_TYPE__ ਲੰਮਾ
# ਨਹੀਂਤਾਂ /* APPLE, BSD */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT64_TYPE__ ਲੰਮਾ ਲੰਮਾ
# endif
#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_INT__ 4
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT_MAX__ 0x7fffffff
#ਜੇ __SIZEOF_LONG__ == 4
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LONG_MAX__ 0x7fffffffL
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LONG_MAX__ 0x7fffffffffffffffL
#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_LONG_LONG__ 8
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CHAR_BIT__ 8
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ORDER_LITTLE_ENDIAN__ 1234
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ORDER_BIG_ENDIAN__ 4321
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ਜੇ defined _WIN32
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WCHAR_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WINT_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ
#ਜਾਂਜੇ defined __linux__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WCHAR_TYPE__ ਪੂਰਨ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WINT_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WCHAR_TYPE__ ਪੂਰਨ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __WINT_TYPE__ ਪੂਰਨ
#ਜੇ_ਅੰਤ

    #ਜੇ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ਜੇ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#ਜੇ_ਅੰਤ
    #ਜੇ_ਅੰਤ

#ਜੇ defined _WIN32
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __declspec(x) __attribute__((x))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __cdecl

#ਜਾਂਜੇ defined __FreeBSD__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC__ 9
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_MINOR__ 3
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_PATCHLEVEL__ 0
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_STDC_INLINE__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __NO_TLS 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __RUNETYPE_INTERNAL 1
# ਜੇ __SIZEOF_POINTER__ == 8
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_SIZE_T__ 8
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_PTRDIFF_T__ 8
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_SIZE_T__ 4
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __SIZEOF_PTRDIFF_T__ 4
# endif

#ਜਾਂਜੇ defined __FreeBSD_kernel__

#ਜਾਂਜੇ defined __NetBSD__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC__ 4
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_MINOR__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_PATCHLEVEL__ 0
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _Pragma(x)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ELF__ 1
#ਜੇ defined __aarch64__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LOCORE /* avoids usage of __asm */
#ਜੇ_ਅੰਤ

#ਜਾਂਜੇ defined __OpenBSD__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC__ 4
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ANSI_LIBRARY 1

#ਜਾਂਜੇ defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LITTLE_ENDIAN__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __FINITE_MATH_ONLY__ 1
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORTIFY_ਸਰੋਤ 0
    //#define __has_builtin(x) 0
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _Float16 ਛੋਟਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ /* fake type just for size & alignment (macOS Sequoia) */

#ਜਾਂਜੇ defined __ANDROID__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ਨਹੀਂਤਾਂ
    /* Linux */

#ਜੇ_ਅੰਤ

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NetBSD__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __UINTPTR_TYPE__ ਬਿਨਾਨਿਸ਼ਾਨੀ __PTRDIFF_TYPE__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INTPTR_TYPE__ __PTRDIFF_TYPE__
#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT32_TYPE__ ਪੂਰਨ

#ਜੇ !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#ਜੇ_ਅੰਤ

    /* not implemented */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  __PRETTY_FUNCTION__ __FUNCTION__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __has_builtin(x) 0
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __has_feature(x) 0
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __has_attribute(x) 0
    /* C23 Keywords */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _Nonnull
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _Nullable
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Nullable_ਨਤੀਜਾ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _Null_unspecified

    /* skip __builtin... with -E */
    #ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TCC_PP__

    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_offsetof(type, ਖੇਤਰ) ((__SIZE_TYPE__)&((type*)0)->ਖੇਤਰ)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_extract_return_addr(x) x
#ਜੇ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_huge_val() 1e500
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_huge_valf() 1e50f
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_huge_vall() 1e5000L
# ਜੇ defined __APPLE__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_bzero(p, ignored_ਮਾਪ) bzero(p, ਆਕਾਰ(*(p)))
# ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#ਜੇ_ਅੰਤ

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ਬਣਤਰ __uint128__ { ਅੱਖਰ x[16]; } __attribute((__aligned__(16)));
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int128_t ਬਣਤਰ __uint128__
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __uint128_t ਬਣਤਰ __uint128__

    /* __builtin_va_list */
#ਜੇ defined __x86_64__
#ਜੇ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ gp_ਵਿੱਥ, fp_ਵਿੱਥ;
        ਸੰਘ {
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਉਛਾਲ_ਵਿੱਥ;
            ਅੱਖਰ *ਉਛਾਲ_arg_area;
        };
        ਅੱਖਰ *reg_save_area;
    } __builtin_va_list[1];

    ਖਾਲੀ *__va_arg(__builtin_va_list ap, ਪੂਰਨ arg_type, ਪੂਰਨ ਮਾਪ, ਪੂਰਨ align);
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_start(ap, ਆਖਰੀ) \
       (*(ap) = *(__builtin_va_list)((ਅੱਖਰ*)__builtin_frame_address(0) - 24))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), ਆਕਾਰ(t), __alignof__(t))))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_copy(dest, src) (*(dest) = *(src))

#ਨਹੀਂਤਾਂ /* _WIN64 */
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *__builtin_va_list;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_arg(ap, t) ((ਆਕਾਰ(t) > 8 || (ਆਕਾਰ(t) & (ਆਕਾਰ(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#ਜੇ_ਅੰਤ

#ਜਾਂਜੇ defined __arm__
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *__builtin_va_list;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tcc_alignof(type) ((ਪੂਰਨ)&((ਬਣਤਰ {ਅੱਖਰ c;type x;} *)0)->x)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tcc_align(addr,type) (((ਬਿਨਾਨਿਸ਼ਾਨੀ)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_start(ap,ਆਖਰੀ) (ap = ((ਅੱਖਰ *)&(ਆਖਰੀ)) + ((ਆਕਾਰ(ਆਖਰੀ)+3)&~3))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_arg(ap,type) (ap = (ਖਾਲੀ *) ((_tcc_align(ap,type)+ਆਕਾਰ(type)+3) \
                           &~3), *(type *)(ap - ((ਆਕਾਰ(type)+3)&~3)))

#ਜਾਂਜੇ defined __aarch64__
#ਜੇ defined _WIN32
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *__builtin_va_list;
#ਜਾਂਜੇ defined __APPLE__
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
        ਖਾਲੀ *__stack;
    } __builtin_va_list;

#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
        ਖਾਲੀ *__stack, *__gr_top, *__vr_top;
        ਪੂਰਨ   __gr_offs, __vr_offs;
    } __builtin_va_list;

#ਜੇ_ਅੰਤ
#ਜਾਂਜੇ defined __riscv
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *__builtin_va_list;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __va_reg_size (__riscv_xlen >> 3)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tcc_align(addr,type) (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_arg(ap,type) (*(ਆਕਾਰ(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (ਆਕਾਰ(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((ਆਕਾਰ(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ਨਹੀਂਤਾਂ /* __i386__ */
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *__builtin_va_list;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_start(ap,ਆਖਰੀ) (ap = ((ਅੱਖਰ *)&(ਆਖਰੀ)) + ((ਆਕਾਰ(ਆਖਰੀ)+3)&~3))
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_arg(ap,t) (*(t*)((ap+=(ਆਕਾਰ(t)+3)&~3)-((ਆਕਾਰ(t)+3)&~3)))

#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __builtin_va_end(ap) (ਖਾਲੀ)(ap)
    #ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #ਜੇ_ਅੰਤ

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ਨਹੀਂਤਾਂ
    # define __RENAME(X) __asm__(X)
    #ਜੇ_ਅੰਤ

    #ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ਨਹੀਂਤਾਂ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BOTH __BOUND
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BUILTIN(ret,name,params)
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#ਜੇ_ਅੰਤ

    __BOTH(ਖਾਲੀ*, ਸਮ੍ਰਿਤੀ_ਨਕਲ, (ਖਾਲੀ *, ਅਚਲ ਖਾਲੀ*, __SIZE_TYPE__))
    __BOTH(ਖਾਲੀ*, memmove, (ਖਾਲੀ *, ਅਚਲ ਖਾਲੀ*, __SIZE_TYPE__))
    __BOTH(ਖਾਲੀ*, memset, (ਖਾਲੀ *, ਪੂਰਨ, __SIZE_TYPE__))
    __BOTH(ਪੂਰਨ, memcmp, (ਅਚਲ ਖਾਲੀ *, ਅਚਲ ਖਾਲੀ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, ਲੜੀ_ਲੰਬਾਈ, (ਅਚਲ ਅੱਖਰ *))
    __BOTH(ਅੱਖਰ*, strcpy, (ਅੱਖਰ *, ਅਚਲ ਅੱਖਰ *))
    __BOTH(ਅੱਖਰ*, strncpy, (ਅੱਖਰ *, ਅਚਲ ਅੱਖਰ*, __SIZE_TYPE__))
    __BOTH(ਪੂਰਨ, strcmp, (ਅਚਲ ਅੱਖਰ*, ਅਚਲ ਅੱਖਰ*))
    __BOTH(ਪੂਰਨ, ਲੜੀ_ਤੁਲਨਾ, (ਅਚਲ ਅੱਖਰ*, ਅਚਲ ਅੱਖਰ*, __SIZE_TYPE__))
    __BOTH(ਅੱਖਰ*, strcat, (ਅੱਖਰ*, ਅਚਲ ਅੱਖਰ*))
    __BOTH(ਅੱਖਰ*, strncat, (ਅੱਖਰ*, ਅਚਲ ਅੱਖਰ*, __SIZE_TYPE__))
    __BOTH(ਅੱਖਰ*, strchr, (ਅਚਲ ਅੱਖਰ*, ਪੂਰਨ))
    __BOTH(ਅੱਖਰ*, strrchr, (ਅਚਲ ਅੱਖਰ*, ਪੂਰਨ))
    __BOTH(ਅੱਖਰ*, strdup, (ਅਚਲ ਅੱਖਰ*))
#ਜੇ defined __ARM_EABI__
    __BOUND(ਖਾਲੀ*,__aeabi_memcpy,(ਖਾਲੀ*,ਅਚਲ ਖਾਲੀ*,__SIZE_TYPE__))
    __BOUND(ਖਾਲੀ*,__aeabi_memmove,(ਖਾਲੀ*,ਅਚਲ ਖਾਲੀ*,__SIZE_TYPE__))
    __BOUND(ਖਾਲੀ*,__aeabi_memmove4,(ਖਾਲੀ*,ਅਚਲ ਖਾਲੀ*,__SIZE_TYPE__))
    __BOUND(ਖਾਲੀ*,__aeabi_memmove8,(ਖਾਲੀ*,ਅਚਲ ਖਾਲੀ*,__SIZE_TYPE__))
    __BOUND(ਖਾਲੀ*,__aeabi_memset,(ਖਾਲੀ*,ਪੂਰਨ,__SIZE_TYPE__))
#ਜੇ_ਅੰਤ

#ਜੇ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MAYBE_REDIR __BUILTIN
#ਨਹੀਂਤਾਂ
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MAYBE_REDIR __BOTH
#ਜੇ_ਅੰਤ
    __MAYBE_REDIR(ਖਾਲੀ*, ਸਮ੍ਰਿਤੀ_ਦਿਓ, (__SIZE_TYPE__))
    __MAYBE_REDIR(ਖਾਲੀ*, realloc, (ਖਾਲੀ *, __SIZE_TYPE__))
    __MAYBE_REDIR(ਖਾਲੀ*, ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ਖਾਲੀ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ਖਾਲੀ, ਮੁਕਤ, (ਖਾਲੀ*))
    __BOTH(ਖਾਲੀ*, alloca, (__SIZE_TYPE__))
    ਖਾਲੀ *alloca(__SIZE_TYPE__);
    __BUILTIN(ਖਾਲੀ, abort, (ਖਾਲੀ))
    __BOUND(ਖਾਲੀ, longjmp, ())
#ਜੇ !defined _WIN32
    __BOUND(ਖਾਲੀ*, mmap, ())
    __BOUND(ਪੂਰਨ, munmap, ())
#ਜੇ_ਅੰਤ
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __BUILTINBC
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __BUILTIN
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __BOUND
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __BOTH
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __MAYBE_REDIR
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __RENAME

    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __BUILTIN_EXTERN(name,u) 		\
        ਪੂਰਨ __builtin_##name(u ਪੂਰਨ);		\
        ਪੂਰਨ __builtin_##name##l(u ਲੰਮਾ);	\
        ਪੂਰਨ __builtin_##name##ll(u ਲੰਮਾ ਲੰਮਾ);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, ਬਿਨਾਨਿਸ਼ਾਨੀ)
    __BUILTIN_EXTERN(ctz, ਬਿਨਾਨਿਸ਼ਾਨੀ)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, ਬਿਨਾਨਿਸ਼ਾਨੀ)
    __BUILTIN_EXTERN(parity, ਬਿਨਾਨਿਸ਼ਾਨੀ)
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __BUILTIN_EXTERN

    #ਜੇ_ਅੰਤ /* ndef __TCC_PP__ */
