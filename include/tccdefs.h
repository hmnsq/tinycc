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
    #تعریف_کړه __SIZE_TYPE__ بینښه اوږد
    #تعریف_کړه __PTRDIFF_TYPE__ اوږد
#وإلا
    #تعریف_کړه __SIZE_TYPE__ بینښه صحيح
    #تعریف_کړه __PTRDIFF_TYPE__ صحيح
#د_که_پای
    #تعریف_کړه __ILP32__ 1
    #تعریف_کړه __INT64_TYPE__ اوږد اوږد
#وإلاإذا __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #تعریف_کړه __SIZE_TYPE__ بینښه اوږد اوږد
    #تعریف_کړه __PTRDIFF_TYPE__ اوږد اوږد
    #تعریف_کړه __LLP64__ 1
    #تعریف_کړه __INT64_TYPE__ اوږد اوږد
#وإلا
    /* Other 64bit systems. */
    #تعریف_کړه __SIZE_TYPE__ بینښه اوږد
    #تعریف_کړه __PTRDIFF_TYPE__ اوږد
    #تعریف_کړه __LP64__ 1
# إذا defined __linux__
    #تعریف_کړه __INT64_TYPE__ اوږد
# وإلا /* APPLE, BSD */
    #تعریف_کړه __INT64_TYPE__ اوږد اوږد
# endif
#د_که_پای
    #تعریف_کړه __SIZEOF_INT__ 4
    #تعریف_کړه __INT_MAX__ 0x7fffffff
#إذا __SIZEOF_LONG__ == 4
    #تعریف_کړه __LONG_MAX__ 0x7fffffffL
#وإلا
    #تعریف_کړه __LONG_MAX__ 0x7fffffffffffffffL
#د_که_پای
    #تعریف_کړه __SIZEOF_LONG_LONG__ 8
    #تعریف_کړه __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #تعریف_کړه __CHAR_BIT__ 8
    #تعریف_کړه __ORDER_LITTLE_ENDIAN__ 1234
    #تعریف_کړه __ORDER_BIG_ENDIAN__ 4321
    #تعریف_کړه __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#إذا defined _WIN32
    #تعریف_کړه __WCHAR_TYPE__ بینښه لنډ
    #تعریف_کړه __WINT_TYPE__ بینښه لنډ
#وإلاإذا defined __linux__
    #تعریف_کړه __WCHAR_TYPE__ صحيح
    #تعریف_کړه __WINT_TYPE__ بینښه صحيح
#وإلا
    #تعریف_کړه __WCHAR_TYPE__ صحيح
    #تعریف_کړه __WINT_TYPE__ صحيح
#د_که_پای

    #إذا __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#إذا !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#د_که_پای
    #د_که_پای

#إذا defined _WIN32
    #تعریف_کړه __declspec(x) __attribute__((x))
    #تعریف_کړه __cdecl

#وإلاإذا defined __FreeBSD__
    #تعریف_کړه __GNUC__ 9
    #تعریف_کړه __GNUC_MINOR__ 3
    #تعریف_کړه __GNUC_PATCHLEVEL__ 0
    #تعریف_کړه __GNUC_STDC_INLINE__ 1
    #تعریف_کړه __NO_TLS 1
    #تعریف_کړه __RUNETYPE_INTERNAL 1
# إذا __SIZEOF_POINTER__ == 8
    #تعریف_کړه __SIZEOF_SIZE_T__ 8
    #تعریف_کړه __SIZEOF_PTRDIFF_T__ 8
#وإلا
    #تعریف_کړه __SIZEOF_SIZE_T__ 4
    #تعریف_کړه __SIZEOF_PTRDIFF_T__ 4
# endif

#وإلاإذا defined __FreeBSD_kernel__

#وإلاإذا defined __NetBSD__
    #تعریف_کړه __GNUC__ 4
    #تعریف_کړه __GNUC_MINOR__ 1
    #تعریف_کړه __GNUC_PATCHLEVEL__ 0
    #تعریف_کړه _Pragma(x)
    #تعریف_کړه __ELF__ 1
#إذا defined __aarch64__
    #تعریف_کړه _LOCORE /* avoids usage of __asm */
#د_که_پای

#وإلاإذا defined __OpenBSD__
    #تعریف_کړه __GNUC__ 4
    #تعریف_کړه _ANSI_LIBRARY 1

#وإلاإذا defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #تعریف_کړه __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #تعریف_کړه __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #تعریف_کړه __LITTLE_ENDIAN__ 1
    #تعریف_کړه _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #تعریف_کړه __FINITE_MATH_ONLY__ 1
    #تعریف_کړه FORTIFY_سرچینه 0
    //#define __has_builtin(x) 0
    #تعریف_کړه _Float16 لنډ بینښه صحيح /* fake type just for size & alignment (macOS Sequoia) */

#وإلاإذا defined __ANDROID__
    #تعریف_کړه  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#وإلا
    /* Linux */

#د_که_پای

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#که_نه_تعریف_شوی __NetBSD__
    #تعریف_کړه __UINTPTR_TYPE__ بینښه __PTRDIFF_TYPE__
    #تعریف_کړه __INTPTR_TYPE__ __PTRDIFF_TYPE__
#د_که_پای
    #تعریف_کړه __INT32_TYPE__ صحيح

#إذا !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #تعریف_کړه __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #تعریف_کړه __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #تعریف_کړه __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#د_که_پای

    /* not implemented */
    #تعریف_کړه  __PRETTY_FUNCTION__ __FUNCTION__
    #تعریف_کړه __has_builtin(x) 0
    #تعریف_کړه __has_feature(x) 0
    #تعریف_کړه __has_attribute(x) 0
    /* C23 Keywords */
    #تعریف_کړه _Nonnull
    #تعریف_کړه _Nullable
    #تعریف_کړه Nullable_پایله
    #تعریف_کړه _Null_unspecified

    /* skip __builtin... with -E */
    #که_نه_تعریف_شوی __TCC_PP__

    #تعریف_کړه __builtin_offsetof(type, ډګر) ((__SIZE_TYPE__)&((type*)0)->ډګر)
    #تعریف_کړه __builtin_extract_return_addr(x) x
#إذا !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #تعریف_کړه __builtin_huge_val() 1e500
    #تعریف_کړه __builtin_huge_valf() 1e50f
    #تعریف_کړه __builtin_huge_vall() 1e5000L
# إذا defined __APPLE__
    #تعریف_کړه __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #تعریف_کړه __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #تعریف_کړه __builtin_bzero(p, ignored_اندازه) bzero(p, حجم(*(p)))
# وإلا
    #تعریف_کړه __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#د_که_پای

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    بنية __uint128__ { حرف x[16]; } __attribute((__aligned__(16)));
    #تعریف_کړه __int128_t بنية __uint128__
    #تعریف_کړه __uint128_t بنية __uint128__

    /* __builtin_va_list */
#إذا defined __x86_64__
#إذا !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    تعريفنوع بنية {
        بینښه gp_دننه_واټن, fp_دننه_واټن;
        اتحاد {
            بینښه ډکېدنه_دننه_واټن;
            حرف *ډکېدنه_arg_area;
        };
        حرف *reg_save_area;
    } __builtin_va_list[1];

    فراغ *__va_arg(__builtin_va_list ap, صحيح arg_type, صحيح اندازه, صحيح align);
    #تعریف_کړه __builtin_va_start(ap, وروستی) \
       (*(ap) = *(__builtin_va_list)((حرف*)__builtin_frame_address(0) - 24))
    #تعریف_کړه __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), حجم(t), __alignof__(t))))
    #تعریف_کړه __builtin_va_copy(dest, src) (*(dest) = *(src))

#وإلا /* _WIN64 */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کړه __builtin_va_arg(ap, t) ((حجم(t) > 8 || (حجم(t) & (حجم(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#د_که_پای

#وإلاإذا defined __arm__
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کړه _tcc_alignof(type) ((صحيح)&((بنية {حرف c;type x;} *)0)->x)
    #تعریف_کړه _tcc_align(addr,type) (((بینښه)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #تعریف_کړه __builtin_va_start(ap,وروستی) (ap = ((حرف *)&(وروستی)) + ((حجم(وروستی)+3)&~3))
    #تعریف_کړه __builtin_va_arg(ap,type) (ap = (فراغ *) ((_tcc_align(ap,type)+حجم(type)+3) \
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

#د_که_پای
#وإلاإذا defined __riscv
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کړه __va_reg_size (__riscv_xlen >> 3)
    #تعریف_کړه _tcc_align(addr,type) (((بینښه اوږد)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #تعریف_کړه __builtin_va_arg(ap,type) (*(حجم(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (حجم(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((حجم(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#وإلا /* __i386__ */
    تعريفنوع حرف *__builtin_va_list;
    #تعریف_کړه __builtin_va_start(ap,وروستی) (ap = ((حرف *)&(وروستی)) + ((حجم(وروستی)+3)&~3))
    #تعریف_کړه __builtin_va_arg(ap,t) (*(t*)((ap+=(حجم(t)+3)&~3)-((حجم(t)+3)&~3)))

#د_که_پای
    #تعریف_کړه __builtin_va_end(ap) (فراغ)(ap)
    #که_نه_تعریف_شوی __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #د_که_پای

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #که_تعریف_شوی __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #وإلا
    # define __RENAME(X) __asm__(X)
    #د_که_پای

    #که_تعریف_شوی __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #وإلا
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #د_که_پای
#که_تعریف_شوی _WIN32
    #تعریف_کړه __BOTH __BOUND
    #تعریف_کړه __BUILTIN(ret,name,params)
#وإلا
    #تعریف_کړه __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #تعریف_کړه __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#د_که_پای

    __BOTH(فراغ*, حافظه_نقل, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memmove, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memset, (فراغ *, صحيح, __SIZE_TYPE__))
    __BOTH(صحيح, memcmp, (ثابت فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, مزي_اوږدوالی, (ثابت حرف *))
    __BOTH(حرف*, strcpy, (حرف *, ثابت حرف *))
    __BOTH(حرف*, strncpy, (حرف *, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(صحيح, strcmp, (ثابت حرف*, ثابت حرف*))
    __BOTH(صحيح, مزي_پرتله, (ثابت حرف*, ثابت حرف*, __SIZE_TYPE__))
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
#د_که_پای

#إذا defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #تعریف_کړه __MAYBE_REDIR __BUILTIN
#وإلا
    #تعریف_کړه __MAYBE_REDIR __BOTH
#د_که_پای
    __MAYBE_REDIR(فراغ*, حافظه_ورکړه, (__SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, realloc, (فراغ *, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, حافظه_صفر_ورکړه, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ, حرر, (فراغ*))
    __BOTH(فراغ*, alloca, (__SIZE_TYPE__))
    فراغ *alloca(__SIZE_TYPE__);
    __BUILTIN(فراغ, abort, (فراغ))
    __BOUND(فراغ, longjmp, ())
#إذا !defined _WIN32
    __BOUND(فراغ*, mmap, ())
    __BOUND(صحيح, munmap, ())
#د_که_پای
    #تعریف_لغوه __BUILTINBC
    #تعریف_لغوه __BUILTIN
    #تعریف_لغوه __BOUND
    #تعریف_لغوه __BOTH
    #تعریف_لغوه __MAYBE_REDIR
    #تعریف_لغوه __RENAME

    #تعریف_کړه __BUILTIN_EXTERN(name,u) 		\
        صحيح __builtin_##name(u صحيح);		\
        صحيح __builtin_##name##l(u اوږد);	\
        صحيح __builtin_##name##ll(u اوږد اوږد);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, بینښه)
    __BUILTIN_EXTERN(ctz, بینښه)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, بینښه)
    __BUILTIN_EXTERN(parity, بینښه)
    #تعریف_لغوه __BUILTIN_EXTERN

    #د_که_پای /* ndef __TCC_PP__ */
