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
    #تعریف_کرو __SIZE_TYPE__ بنانشانی لما
    #تعریف_کرو __PTRDIFF_TYPE__ لما
#وإلا
    #تعریف_کرو __SIZE_TYPE__ بنانشانی صحيح
    #تعریف_کرو __PTRDIFF_TYPE__ صحيح
#جے_انت
    #تعریف_کرو __ILP32__ 1
    #تعریف_کرو __INT64_TYPE__ لما لما
#وإلاإذا __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #تعریف_کرو __SIZE_TYPE__ بنانشانی لما لما
    #تعریف_کرو __PTRDIFF_TYPE__ لما لما
    #تعریف_کرو __LLP64__ 1
    #تعریف_کرو __INT64_TYPE__ لما لما
#وإلا
    /* Other 64bit systems. */
    #تعریف_کرو __SIZE_TYPE__ بنانشانی لما
    #تعریف_کرو __PTRDIFF_TYPE__ لما
    #تعریف_کرو __LP64__ 1
# إذا defined __linux__
    #تعریف_کرو __INT64_TYPE__ لما
# وإلا /* APPLE, BSD */
    #تعریف_کرو __INT64_TYPE__ لما لما
# endif
#جے_انت
    #تعریف_کرو __SIZEOF_INT__ 4
    #تعریف_کرو __INT_MAX__ 0x7fffffff
#إذا __SIZEOF_LONG__ == 4
    #تعریف_کرو __LONG_MAX__ 0x7fffffffL
#وإلا
    #تعریف_کرو __LONG_MAX__ 0x7fffffffffffffffL
#جے_انت
    #تعریف_کرو __SIZEOF_LONG_LONG__ 8
    #تعریف_کرو __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #تعریف_کرو __CHAR_BIT__ 8
    #تعریف_کرو __ORDER_LITTLE_ENDIAN__ 1234
    #تعریف_کرو __ORDER_BIG_ENDIAN__ 4321
    #تعریف_کرو __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#إذا defined _WIN32
    #تعریف_کرو __WCHAR_TYPE__ بنانشانی چھوٹا
    #تعریف_کرو __WINT_TYPE__ بنانشانی چھوٹا
#وإلاإذا defined __linux__
    #تعریف_کرو __WCHAR_TYPE__ صحيح
    #تعریف_کرو __WINT_TYPE__ بنانشانی صحيح
#وإلا
    #تعریف_کرو __WCHAR_TYPE__ صحيح
    #تعریف_کرو __WINT_TYPE__ صحيح
#جے_انت

    #إذا __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#إذا !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#جے_انت
    #جے_انت

#إذا defined _WIN32
    #تعریف_کرو __declspec(x) __attribute__((x))
    #تعریف_کرو __cdecl

#وإلاإذا defined __FreeBSD__
    #تعریف_کرو __GNUC__ 9
    #تعریف_کرو __GNUC_MINOR__ 3
    #تعریف_کرو __GNUC_PATCHLEVEL__ 0
    #تعریف_کرو __GNUC_STDC_INLINE__ 1
    #تعریف_کرو __NO_TLS 1
    #تعریف_کرو __RUNETYPE_INTERNAL 1
# إذا __SIZEOF_POINTER__ == 8
    #تعریف_کرو __SIZEOF_SIZE_T__ 8
    #تعریف_کرو __SIZEOF_PTRDIFF_T__ 8
#وإلا
    #تعریف_کرو __SIZEOF_SIZE_T__ 4
    #تعریف_کرو __SIZEOF_PTRDIFF_T__ 4
# endif

#وإلاإذا defined __FreeBSD_kernel__

#وإلاإذا defined __NetBSD__
    #تعریف_کرو __GNUC__ 4
    #تعریف_کرو __GNUC_MINOR__ 1
    #تعریف_کرو __GNUC_PATCHLEVEL__ 0
    #تعریف_کرو _Pragma(x)
    #تعریف_کرو __ELF__ 1
#إذا defined __aarch64__
    #تعریف_کرو _LOCORE /* avoids usage of __asm */
#جے_انت

#وإلاإذا defined __OpenBSD__
    #تعریف_کرو __GNUC__ 4
    #تعریف_کرو _ANSI_LIBRARY 1

#وإلاإذا defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #تعریف_کرو __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #تعریف_کرو __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #تعریف_کرو __LITTLE_ENDIAN__ 1
    #تعریف_کرو _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #تعریف_کرو __FINITE_MATH_ONLY__ 1
    #تعریف_کرو FORTIFY_سروت 0
    //#define __has_builtin(x) 0
    #تعریف_کرو _Float16 چھوٹا بنانشانی صحيح /* fake type just for size & alignment (macOS Sequoia) */

#وإلاإذا defined __ANDROID__
    #تعریف_کرو  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#وإلا
    /* Linux */

#جے_انت

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#جے_بنا_تعریف __NetBSD__
    #تعریف_کرو __UINTPTR_TYPE__ بنانشانی __PTRDIFF_TYPE__
    #تعریف_کرو __INTPTR_TYPE__ __PTRDIFF_TYPE__
#جے_انت
    #تعریف_کرو __INT32_TYPE__ صحيح

#إذا !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #تعریف_کرو __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #تعریف_کرو __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #تعریف_کرو __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#جے_انت

    /* not implemented */
    #تعریف_کرو  __PRETTY_FUNCTION__ __FUNCTION__
    #تعریف_کرو __has_builtin(x) 0
    #تعریف_کرو __has_feature(x) 0
    #تعریف_کرو __has_attribute(x) 0
    /* C23 Keywords */
    #تعریف_کرو _Nonnull
    #تعریف_کرو _Nullable
    #تعریف_کرو Nullable_نتیجہ
    #تعریف_کرو _Null_unspecified

    /* skip __builtin... with -E */
    #جے_بنا_تعریف __TCC_PP__

    #تعریف_کرو __builtin_offsetof(type, میدان) ((__SIZE_TYPE__)&((type*)0)->میدان)
    #تعریف_کرو __builtin_extract_return_addr(x) x
#إذا !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #تعریف_کرو __builtin_huge_val() 1e500
    #تعریف_کرو __builtin_huge_valf() 1e50f
    #تعریف_کرو __builtin_huge_vall() 1e5000L
# إذا defined __APPLE__
    #تعریف_کرو __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #تعریف_کرو __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #تعریف_کرو __builtin_bzero(p, ignored_ناپ) bzero(p, حجم(*(p)))
# وإلا
    #تعریف_کرو __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#جے_انت

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    بنية __uint128__ { حرف x[16]; } __attribute((__aligned__(16)));
    #تعریف_کرو __int128_t بنية __uint128__
    #تعریف_کرو __uint128_t بنية __uint128__

    /* __builtin_va_list */
#إذا defined __x86_64__
#إذا !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    تعريفنوع بنية {
        بنانشانی gp_وتھ, fp_وتھ;
        اتحاد {
            بنانشانی حد_توں_ودھ_وتھ;
            حرف *حد_توں_ودھ_arg_area;
        };
        حرف *reg_save_area;
    } __builtin_va_list[1];

    فراغ *__va_arg(__builtin_va_list ap, صحيح arg_type, صحيح ناپ, صحيح align);
    #تعریف_کرو __builtin_va_start(ap, آخری) \
       (*(ap) = *(__builtin_va_list)((حرف*)__builtin_frame_address(0) - 24))
    #تعریف_کرو __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), حجم(t), __alignof__(t))))
    #تعریف_کرو __builtin_va_copy(dest, src) (*(dest) = *(src))

#وإلا /* _WIN64 */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کرو __builtin_va_arg(ap, t) ((حجم(t) > 8 || (حجم(t) & (حجم(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#جے_انت

#وإلاإذا defined __arm__
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کرو _tcc_alignof(type) ((صحيح)&((بنية {حرف c;type x;} *)0)->x)
    #تعریف_کرو _tcc_align(addr,type) (((بنانشانی)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #تعریف_کرو __builtin_va_start(ap,آخری) (ap = ((حرف *)&(آخری)) + ((حجم(آخری)+3)&~3))
    #تعریف_کرو __builtin_va_arg(ap,type) (ap = (فراغ *) ((_tcc_align(ap,type)+حجم(type)+3) \
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

#جے_انت
#وإلاإذا defined __riscv
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کرو __va_reg_size (__riscv_xlen >> 3)
    #تعریف_کرو _tcc_align(addr,type) (((بنانشانی لما)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #تعریف_کرو __builtin_va_arg(ap,type) (*(حجم(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (حجم(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((حجم(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#وإلا /* __i386__ */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کرو __builtin_va_start(ap,آخری) (ap = ((حرف *)&(آخری)) + ((حجم(آخری)+3)&~3))
    #تعریف_کرو __builtin_va_arg(ap,t) (*(t*)((ap+=(حجم(t)+3)&~3)-((حجم(t)+3)&~3)))

#جے_انت
    #تعریف_کرو __builtin_va_end(ap) (فراغ)(ap)
    #جے_بنا_تعریف __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #جے_انت

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #جے_تعریف_شدہ __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #وإلا
    # define __RENAME(X) __asm__(X)
    #جے_انت

    #جے_تعریف_شدہ __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #وإلا
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #جے_انت
#جے_تعریف_شدہ _WIN32
    #تعریف_کرو __BOTH __BOUND
    #تعریف_کرو __BUILTIN(ret,name,params)
#وإلا
    #تعریف_کرو __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #تعریف_کرو __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#جے_انت

    __BOTH(فراغ*, حافظہ_نقل, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memmove, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memset, (فراغ *, صحيح, __SIZE_TYPE__))
    __BOTH(صحيح, memcmp, (ثابت فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, لڑی_لمبائی, (ثابت حرف *))
    __BOTH(حرف*, strcpy, (حرف *, ثابت حرف *))
    __BOTH(حرف*, strncpy, (حرف *, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(صحيح, strcmp, (ثابت حرف*, ثابت حرف*))
    __BOTH(صحيح, لڑی_مقابلہ, (ثابت حرف*, ثابت حرف*, __SIZE_TYPE__))
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
#جے_انت

#إذا defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #تعریف_کرو __MAYBE_REDIR __BUILTIN
#وإلا
    #تعریف_کرو __MAYBE_REDIR __BOTH
#جے_انت
    __MAYBE_REDIR(فراغ*, حافظہ_دیو, (__SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, realloc, (فراغ *, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, صفر_حافظہ_دیو, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ, حرر, (فراغ*))
    __BOTH(فراغ*, alloca, (__SIZE_TYPE__))
    فراغ *alloca(__SIZE_TYPE__);
    __BUILTIN(فراغ, abort, (فراغ))
    __BOUND(فراغ, longjmp, ())
#إذا !defined _WIN32
    __BOUND(فراغ*, mmap, ())
    __BOUND(صحيح, munmap, ())
#جے_انت
    #تعریف_رد __BUILTINBC
    #تعریف_رد __BUILTIN
    #تعریف_رد __BOUND
    #تعریف_رد __BOTH
    #تعریف_رد __MAYBE_REDIR
    #تعریف_رد __RENAME

    #تعریف_کرو __BUILTIN_EXTERN(name,u) 		\
        صحيح __builtin_##name(u صحيح);		\
        صحيح __builtin_##name##l(u لما);	\
        صحيح __builtin_##name##ll(u لما لما);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, بنانشانی)
    __BUILTIN_EXTERN(ctz, بنانشانی)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, بنانشانی)
    __BUILTIN_EXTERN(parity, بنانشانی)
    #تعریف_رد __BUILTIN_EXTERN

    #جے_انت /* ndef __TCC_PP__ */
