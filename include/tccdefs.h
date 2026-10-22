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

#إذا __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#إذا defined  __OpenBSD__
    #تعریف_کن __SIZE_TYPE__ بیعلامت دراز
    #تعریف_کن __PTRDIFF_TYPE__ دراز
#وإلا
    #تعریف_کن __SIZE_TYPE__ بیعلامت صحيح
    #تعریف_کن __PTRDIFF_TYPE__ صحيح
#پایان_اگر
    #تعریف_کن __ILP32__ 1
    #تعریف_کن __INT64_TYPE__ دراز دراز
#وإلاإذا __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #تعریف_کن __SIZE_TYPE__ بیعلامت دراز دراز
    #تعریف_کن __PTRDIFF_TYPE__ دراز دراز
    #تعریف_کن __LLP64__ 1
    #تعریف_کن __INT64_TYPE__ دراز دراز
#وإلا
    /* Other 64bit systems. */
    #تعریف_کن __SIZE_TYPE__ بیعلامت دراز
    #تعریف_کن __PTRDIFF_TYPE__ دراز
    #تعریف_کن __LP64__ 1
# إذا defined __linux__
    #تعریف_کن __INT64_TYPE__ دراز
# وإلا /* APPLE, BSD */
    #تعریف_کن __INT64_TYPE__ دراز دراز
# endif
#پایان_اگر
    #تعریف_کن __SIZEOF_INT__ 4
    #تعریف_کن __INT_MAX__ 0x7fffffff
#إذا __SIZEOF_LONG__ == 4
    #تعریف_کن __LONG_MAX__ 0x7fffffffL
#وإلا
    #تعریف_کن __LONG_MAX__ 0x7fffffffffffffffL
#پایان_اگر
    #تعریف_کن __SIZEOF_LONG_LONG__ 8
    #تعریف_کن __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #تعریف_کن __CHAR_BIT__ 8
    #تعریف_کن __ORDER_LITTLE_ENDIAN__ 1234
    #تعریف_کن __ORDER_BIG_ENDIAN__ 4321
    #تعریف_کن __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#إذا defined _WIN32
    #تعریف_کن __WCHAR_TYPE__ بیعلامت کوتاه
    #تعریف_کن __WINT_TYPE__ بیعلامت کوتاه
#وإلاإذا defined __linux__
    #تعریف_کن __WCHAR_TYPE__ صحيح
    #تعریف_کن __WINT_TYPE__ بیعلامت صحيح
#وإلا
    #تعریف_کن __WCHAR_TYPE__ صحيح
    #تعریف_کن __WINT_TYPE__ صحيح
#پایان_اگر

    #إذا __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#إذا !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#پایان_اگر
    #پایان_اگر

#إذا defined _WIN32
    #تعریف_کن __declspec(x) __attribute__((x))
    #تعریف_کن __cdecl

#وإلاإذا defined __FreeBSD__
    #تعریف_کن __GNUC__ 9
    #تعریف_کن __GNUC_MINOR__ 3
    #تعریف_کن __GNUC_PATCHLEVEL__ 0
    #تعریف_کن __GNUC_STDC_INLINE__ 1
    #تعریف_کن __NO_TLS 1
    #تعریف_کن __RUNETYPE_INTERNAL 1
# إذا __SIZEOF_POINTER__ == 8
    #تعریف_کن __SIZEOF_SIZE_T__ 8
    #تعریف_کن __SIZEOF_PTRDIFF_T__ 8
#وإلا
    #تعریف_کن __SIZEOF_SIZE_T__ 4
    #تعریف_کن __SIZEOF_PTRDIFF_T__ 4
# endif

#وإلاإذا defined __FreeBSD_kernel__

#وإلاإذا defined __NetBSD__
    #تعریف_کن __GNUC__ 4
    #تعریف_کن __GNUC_MINOR__ 1
    #تعریف_کن __GNUC_PATCHLEVEL__ 0
    #تعریف_کن _Pragma(x)
    #تعریف_کن __ELF__ 1
#إذا defined __aarch64__
    #تعریف_کن _LOCORE /* avoids usage of __asm */
#پایان_اگر

#وإلاإذا defined __OpenBSD__
    #تعریف_کن __GNUC__ 4
    #تعریف_کن _ANSI_LIBRARY 1

#وإلاإذا defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #تعریف_کن __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #تعریف_کن __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #تعریف_کن __LITTLE_ENDIAN__ 1
    #تعریف_کن _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #تعریف_کن __FINITE_MATH_ONLY__ 1
    #تعریف_کن FORTIFY_منبع 0
    //#define __has_builtin(x) 0
    #تعریف_کن _Float16 کوتاه بیعلامت صحيح /* fake type just for size & alignment (macOS Sequoia) */

#وإلاإذا defined __ANDROID__
    #تعریف_کن  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#وإلا
    /* Linux */

#پایان_اگر

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#اگر_تعریف_نشده __NetBSD__
    #تعریف_کن __UINTPTR_TYPE__ بیعلامت __PTRDIFF_TYPE__
    #تعریف_کن __INTPTR_TYPE__ __PTRDIFF_TYPE__
#پایان_اگر
    #تعریف_کن __INT32_TYPE__ صحيح

#إذا !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #تعریف_کن __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #تعریف_کن __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #تعریف_کن __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#پایان_اگر

    /* not implemented */
    #تعریف_کن  __PRETTY_FUNCTION__ __FUNCTION__
    #تعریف_کن __has_builtin(x) 0
    #تعریف_کن __has_feature(x) 0
    #تعریف_کن __has_attribute(x) 0
    /* C23 Keywords */
    #تعریف_کن _Nonnull
    #تعریف_کن _Nullable
    #تعریف_کن Nullable_نتیجه
    #تعریف_کن _Null_unspecified

    /* skip __builtin... with -E */
    #اگر_تعریف_نشده __TCC_PP__

    #تعریف_کن __builtin_offsetof(type, فیلد) ((__SIZE_TYPE__)&((type*)0)->فیلد)
    #تعریف_کن __builtin_extract_return_addr(x) x
#إذا !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #تعریف_کن __builtin_huge_val() 1e500
    #تعریف_کن __builtin_huge_valf() 1e50f
    #تعریف_کن __builtin_huge_vall() 1e5000L
# إذا defined __APPLE__
    #تعریف_کن __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #تعریف_کن __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #تعریف_کن __builtin_bzero(p, ignored_اندازه) bzero(p, حجم(*(p)))
# وإلا
    #تعریف_کن __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#پایان_اگر

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    بنية __uint128__ { حرف x[16]; } __attribute((__aligned__(16)));
    #تعریف_کن __int128_t بنية __uint128__
    #تعریف_کن __uint128_t بنية __uint128__

    /* __builtin_va_list */
#إذا defined __x86_64__
#إذا !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    تعريفنوع بنية {
        بیعلامت gp_جابه_جایی, fp_جابه_جایی;
        اتحاد {
            بیعلامت سرریز_جابه_جایی;
            حرف *سرریز_arg_area;
        };
        حرف *reg_save_area;
    } __builtin_va_list[1];

    فراغ *__va_arg(__builtin_va_list ap, صحيح arg_type, صحيح اندازه, صحيح align);
    #تعریف_کن __builtin_va_start(ap, آخرین) \
       (*(ap) = *(__builtin_va_list)((حرف*)__builtin_frame_address(0) - 24))
    #تعریف_کن __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), حجم(t), __alignof__(t))))
    #تعریف_کن __builtin_va_copy(dest, src) (*(dest) = *(src))

#وإلا /* _WIN64 */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کن __builtin_va_arg(ap, t) ((حجم(t) > 8 || (حجم(t) & (حجم(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#پایان_اگر

#وإلاإذا defined __arm__
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کن _tcc_alignof(type) ((صحيح)&((بنية {حرف c;type x;} *)0)->x)
    #تعریف_کن _tcc_align(addr,type) (((بیعلامت)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #تعریف_کن __builtin_va_start(ap,آخرین) (ap = ((حرف *)&(آخرین)) + ((حجم(آخرین)+3)&~3))
    #تعریف_کن __builtin_va_arg(ap,type) (ap = (فراغ *) ((_tcc_align(ap,type)+حجم(type)+3) \
                           &~3), *(type *)(ap - ((حجم(type)+3)&~3)))

#وإلاإذا defined __aarch64__
#إذا defined _WIN32
    تعريفنوع حرف *__builtin_va_list;
#وإلاإذا defined __APPLE__
    تعريفنوع بنية {
        فراغ *__stack;
    } __builtin_va_list;

#وإلا
    تعريفنوع بنية {
        فراغ *__stack, *__gr_top, *__vr_top;
        صحيح   __gr_offs, __vr_offs;
    } __builtin_va_list;

#پایان_اگر
#وإلاإذا defined __riscv
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کن __va_reg_size (__riscv_xlen >> 3)
    #تعریف_کن _tcc_align(addr,type) (((بیعلامت دراز)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #تعریف_کن __builtin_va_arg(ap,type) (*(حجم(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (حجم(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((حجم(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#وإلا /* __i386__ */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کن __builtin_va_start(ap,آخرین) (ap = ((حرف *)&(آخرین)) + ((حجم(آخرین)+3)&~3))
    #تعریف_کن __builtin_va_arg(ap,t) (*(t*)((ap+=(حجم(t)+3)&~3)-((حجم(t)+3)&~3)))

#پایان_اگر
    #تعریف_کن __builtin_va_end(ap) (فراغ)(ap)
    #اگر_تعریف_نشده __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #پایان_اگر

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #اگر_تعریف_شده __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #وإلا
    # define __RENAME(X) __asm__(X)
    #پایان_اگر

    #اگر_تعریف_شده __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #وإلا
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #پایان_اگر
#اگر_تعریف_شده _WIN32
    #تعریف_کن __BOTH __BOUND
    #تعریف_کن __BUILTIN(ret,name,params)
#وإلا
    #تعریف_کن __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #تعریف_کن __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#پایان_اگر

    __BOTH(فراغ*, کپی_حافظه, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memmove, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memset, (فراغ *, صحيح, __SIZE_TYPE__))
    __BOTH(صحيح, memcmp, (ثابت فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, طول_رشته, (ثابت حرف *))
    __BOTH(حرف*, strcpy, (حرف *, ثابت حرف *))
    __BOTH(حرف*, strncpy, (حرف *, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(صحيح, strcmp, (ثابت حرف*, ثابت حرف*))
    __BOTH(صحيح, مقایسه_رشته, (ثابت حرف*, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(حرف*, strcat, (حرف*, ثابت حرف*))
    __BOTH(حرف*, strncat, (حرف*, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(حرف*, strchr, (ثابت حرف*, صحيح))
    __BOTH(حرف*, strrchr, (ثابت حرف*, صحيح))
    __BOTH(حرف*, strdup, (ثابت حرف*))
#إذا defined __ARM_EABI__
    __BOUND(فراغ*,__aeabi_memcpy,(فراغ*,ثابت فراغ*,__SIZE_TYPE__))
    __BOUND(فراغ*,__aeabi_memmove,(فراغ*,ثابت فراغ*,__SIZE_TYPE__))
    __BOUND(فراغ*,__aeabi_memmove4,(فراغ*,ثابت فراغ*,__SIZE_TYPE__))
    __BOUND(فراغ*,__aeabi_memmove8,(فراغ*,ثابت فراغ*,__SIZE_TYPE__))
    __BOUND(فراغ*,__aeabi_memset,(فراغ*,صحيح,__SIZE_TYPE__))
#پایان_اگر

#إذا defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #تعریف_کن __MAYBE_REDIR __BUILTIN
#وإلا
    #تعریف_کن __MAYBE_REDIR __BOTH
#پایان_اگر
    __MAYBE_REDIR(فراغ*, حافظه_بده, (__SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, realloc, (فراغ *, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, حافظه_صفر_بده, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ, حرر, (فراغ*))
    __BOTH(فراغ*, alloca, (__SIZE_TYPE__))
    فراغ *alloca(__SIZE_TYPE__);
    __BUILTIN(فراغ, abort, (فراغ))
    __BOUND(فراغ, longjmp, ())
#إذا !defined _WIN32
    __BOUND(فراغ*, mmap, ())
    __BOUND(صحيح, munmap, ())
#پایان_اگر
    #لغو_تعریف __BUILTINBC
    #لغو_تعریف __BUILTIN
    #لغو_تعریف __BOUND
    #لغو_تعریف __BOTH
    #لغو_تعریف __MAYBE_REDIR
    #لغو_تعریف __RENAME

    #تعریف_کن __BUILTIN_EXTERN(name,u) 		\
        صحيح __builtin_##name(u صحيح);		\
        صحيح __builtin_##name##l(u دراز);	\
        صحيح __builtin_##name##ll(u دراز دراز);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, بیعلامت)
    __BUILTIN_EXTERN(ctz, بیعلامت)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, بیعلامت)
    __BUILTIN_EXTERN(parity, بیعلامت)
    #لغو_تعریف __BUILTIN_EXTERN

    #پایان_اگر /* ndef __TCC_PP__ */
