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
    #وصف_ڪريو __SIZE_TYPE__ بنانشان ڊگهو
    #وصف_ڪريو __PTRDIFF_TYPE__ ڊگهو
#وإلا
    #وصف_ڪريو __SIZE_TYPE__ بنانشان صحيح
    #وصف_ڪريو __PTRDIFF_TYPE__ صحيح
#جيڪڏهن_پورو
    #وصف_ڪريو __ILP32__ 1
    #وصف_ڪريو __INT64_TYPE__ ڊگهو ڊگهو
#وإلاإذا __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #وصف_ڪريو __SIZE_TYPE__ بنانشان ڊگهو ڊگهو
    #وصف_ڪريو __PTRDIFF_TYPE__ ڊگهو ڊگهو
    #وصف_ڪريو __LLP64__ 1
    #وصف_ڪريو __INT64_TYPE__ ڊگهو ڊگهو
#وإلا
    /* Other 64bit systems. */
    #وصف_ڪريو __SIZE_TYPE__ بنانشان ڊگهو
    #وصف_ڪريو __PTRDIFF_TYPE__ ڊگهو
    #وصف_ڪريو __LP64__ 1
# إذا defined __linux__
    #وصف_ڪريو __INT64_TYPE__ ڊگهو
# وإلا /* APPLE, BSD */
    #وصف_ڪريو __INT64_TYPE__ ڊگهو ڊگهو
# endif
#جيڪڏهن_پورو
    #وصف_ڪريو __SIZEOF_INT__ 4
    #وصف_ڪريو __INT_MAX__ 0x7fffffff
#إذا __SIZEOF_LONG__ == 4
    #وصف_ڪريو __LONG_MAX__ 0x7fffffffL
#وإلا
    #وصف_ڪريو __LONG_MAX__ 0x7fffffffffffffffL
#جيڪڏهن_پورو
    #وصف_ڪريو __SIZEOF_LONG_LONG__ 8
    #وصف_ڪريو __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #وصف_ڪريو __CHAR_BIT__ 8
    #وصف_ڪريو __ORDER_LITTLE_ENDIAN__ 1234
    #وصف_ڪريو __ORDER_BIG_ENDIAN__ 4321
    #وصف_ڪريو __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#إذا defined _WIN32
    #وصف_ڪريو __WCHAR_TYPE__ بنانشان ننڍو
    #وصف_ڪريو __WINT_TYPE__ بنانشان ننڍو
#وإلاإذا defined __linux__
    #وصف_ڪريو __WCHAR_TYPE__ صحيح
    #وصف_ڪريو __WINT_TYPE__ بنانشان صحيح
#وإلا
    #وصف_ڪريو __WCHAR_TYPE__ صحيح
    #وصف_ڪريو __WINT_TYPE__ صحيح
#جيڪڏهن_پورو

    #إذا __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#إذا !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#جيڪڏهن_پورو
    #جيڪڏهن_پورو

#إذا defined _WIN32
    #وصف_ڪريو __declspec(x) __attribute__((x))
    #وصف_ڪريو __cdecl

#وإلاإذا defined __FreeBSD__
    #وصف_ڪريو __GNUC__ 9
    #وصف_ڪريو __GNUC_MINOR__ 3
    #وصف_ڪريو __GNUC_PATCHLEVEL__ 0
    #وصف_ڪريو __GNUC_STDC_INLINE__ 1
    #وصف_ڪريو __NO_TLS 1
    #وصف_ڪريو __RUNETYPE_INTERNAL 1
# إذا __SIZEOF_POINTER__ == 8
    #وصف_ڪريو __SIZEOF_SIZE_T__ 8
    #وصف_ڪريو __SIZEOF_PTRDIFF_T__ 8
#وإلا
    #وصف_ڪريو __SIZEOF_SIZE_T__ 4
    #وصف_ڪريو __SIZEOF_PTRDIFF_T__ 4
# endif

#وإلاإذا defined __FreeBSD_kernel__

#وإلاإذا defined __NetBSD__
    #وصف_ڪريو __GNUC__ 4
    #وصف_ڪريو __GNUC_MINOR__ 1
    #وصف_ڪريو __GNUC_PATCHLEVEL__ 0
    #وصف_ڪريو _Pragma(x)
    #وصف_ڪريو __ELF__ 1
#إذا defined __aarch64__
    #وصف_ڪريو _LOCORE /* avoids usage of __asm */
#جيڪڏهن_پورو

#وإلاإذا defined __OpenBSD__
    #وصف_ڪريو __GNUC__ 4
    #وصف_ڪريو _ANSI_LIBRARY 1

#وإلاإذا defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #وصف_ڪريو __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #وصف_ڪريو __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #وصف_ڪريو __LITTLE_ENDIAN__ 1
    #وصف_ڪريو _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #وصف_ڪريو __FINITE_MATH_ONLY__ 1
    #وصف_ڪريو FORTIFY_ذريعو 0
    //#define __has_builtin(x) 0
    #وصف_ڪريو _Float16 ننڍو بنانشان صحيح /* fake type just for size & alignment (macOS Sequoia) */

#وإلاإذا defined __ANDROID__
    #وصف_ڪريو  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#وإلا
    /* Linux */

#جيڪڏهن_پورو

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#جيڪڏهن_وصف_نه_ٿيل __NetBSD__
    #وصف_ڪريو __UINTPTR_TYPE__ بنانشان __PTRDIFF_TYPE__
    #وصف_ڪريو __INTPTR_TYPE__ __PTRDIFF_TYPE__
#جيڪڏهن_پورو
    #وصف_ڪريو __INT32_TYPE__ صحيح

#إذا !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #وصف_ڪريو __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #وصف_ڪريو __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #وصف_ڪريو __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#جيڪڏهن_پورو

    /* not implemented */
    #وصف_ڪريو  __PRETTY_FUNCTION__ __FUNCTION__
    #وصف_ڪريو __has_builtin(x) 0
    #وصف_ڪريو __has_feature(x) 0
    #وصف_ڪريو __has_attribute(x) 0
    /* C23 Keywords */
    #وصف_ڪريو _Nonnull
    #وصف_ڪريو _Nullable
    #وصف_ڪريو Nullable_نتيجو
    #وصف_ڪريو _Null_unspecified

    /* skip __builtin... with -E */
    #جيڪڏهن_وصف_نه_ٿيل __TCC_PP__

    #وصف_ڪريو __builtin_offsetof(type, ميدان) ((__SIZE_TYPE__)&((type*)0)->ميدان)
    #وصف_ڪريو __builtin_extract_return_addr(x) x
#إذا !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #وصف_ڪريو __builtin_huge_val() 1e500
    #وصف_ڪريو __builtin_huge_valf() 1e50f
    #وصف_ڪريو __builtin_huge_vall() 1e5000L
# إذا defined __APPLE__
    #وصف_ڪريو __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #وصف_ڪريو __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #وصف_ڪريو __builtin_bzero(p, ignored_سائيز) bzero(p, حجم(*(p)))
# وإلا
    #وصف_ڪريو __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#جيڪڏهن_پورو

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    بنية __uint128__ { حرف x[16]; } __attribute((__aligned__(16)));
    #وصف_ڪريو __int128_t بنية __uint128__
    #وصف_ڪريو __uint128_t بنية __uint128__

    /* __builtin_va_list */
#إذا defined __x86_64__
#إذا !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    تعريفنوع بنية {
        بنانشان gp_وٿي, fp_وٿي;
        اتحاد {
            بنانشان حد_کان_مٿي_وٿي;
            حرف *حد_کان_مٿي_arg_area;
        };
        حرف *reg_save_area;
    } __builtin_va_list[1];

    فراغ *__va_arg(__builtin_va_list ap, صحيح arg_type, صحيح سائيز, صحيح align);
    #وصف_ڪريو __builtin_va_start(ap, آخري) \
       (*(ap) = *(__builtin_va_list)((حرف*)__builtin_frame_address(0) - 24))
    #وصف_ڪريو __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), حجم(t), __alignof__(t))))
    #وصف_ڪريو __builtin_va_copy(dest, src) (*(dest) = *(src))

#وإلا /* _WIN64 */
    تعريفنوع حرف *__builtin_va_list;
    #وصف_ڪريو __builtin_va_arg(ap, t) ((حجم(t) > 8 || (حجم(t) & (حجم(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#جيڪڏهن_پورو

#وإلاإذا defined __arm__
    تعريفنوع حرف *__builtin_va_list;
    #وصف_ڪريو _tcc_alignof(type) ((صحيح)&((بنية {حرف c;type x;} *)0)->x)
    #وصف_ڪريو _tcc_align(addr,type) (((بنانشان)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #وصف_ڪريو __builtin_va_start(ap,آخري) (ap = ((حرف *)&(آخري)) + ((حجم(آخري)+3)&~3))
    #وصف_ڪريو __builtin_va_arg(ap,type) (ap = (فراغ *) ((_tcc_align(ap,type)+حجم(type)+3) \
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

#جيڪڏهن_پورو
#وإلاإذا defined __riscv
    تعريفنوع حرف *__builtin_va_list;
    #وصف_ڪريو __va_reg_size (__riscv_xlen >> 3)
    #وصف_ڪريو _tcc_align(addr,type) (((بنانشان ڊگهو)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #وصف_ڪريو __builtin_va_arg(ap,type) (*(حجم(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (حجم(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((حجم(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#وإلا /* __i386__ */
    تعريفنوع حرف *__builtin_va_list;
    #وصف_ڪريو __builtin_va_start(ap,آخري) (ap = ((حرف *)&(آخري)) + ((حجم(آخري)+3)&~3))
    #وصف_ڪريو __builtin_va_arg(ap,t) (*(t*)((ap+=(حجم(t)+3)&~3)-((حجم(t)+3)&~3)))

#جيڪڏهن_پورو
    #وصف_ڪريو __builtin_va_end(ap) (فراغ)(ap)
    #جيڪڏهن_وصف_نه_ٿيل __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #جيڪڏهن_پورو

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #جيڪڏهن_وصف_ٿيل __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #وإلا
    # define __RENAME(X) __asm__(X)
    #جيڪڏهن_پورو

    #جيڪڏهن_وصف_ٿيل __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #وإلا
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل _WIN32
    #وصف_ڪريو __BOTH __BOUND
    #وصف_ڪريو __BUILTIN(ret,name,params)
#وإلا
    #وصف_ڪريو __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #وصف_ڪريو __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#جيڪڏهن_پورو

    __BOTH(فراغ*, يادگيري_نقل, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memmove, (فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(فراغ*, memset, (فراغ *, صحيح, __SIZE_TYPE__))
    __BOTH(صحيح, memcmp, (ثابت فراغ *, ثابت فراغ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, لڙي_ڊيگهه, (ثابت حرف *))
    __BOTH(حرف*, strcpy, (حرف *, ثابت حرف *))
    __BOTH(حرف*, strncpy, (حرف *, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(صحيح, strcmp, (ثابت حرف*, ثابت حرف*))
    __BOTH(صحيح, لڙي_ڀيٽ, (ثابت حرف*, ثابت حرف*, __SIZE_TYPE__))
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
#جيڪڏهن_پورو

#إذا defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #وصف_ڪريو __MAYBE_REDIR __BUILTIN
#وإلا
    #وصف_ڪريو __MAYBE_REDIR __BOTH
#جيڪڏهن_پورو
    __MAYBE_REDIR(فراغ*, يادگيري_ڏيو, (__SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, realloc, (فراغ *, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, صفر_يادگيري_ڏيو, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(فراغ, حرر, (فراغ*))
    __BOTH(فراغ*, alloca, (__SIZE_TYPE__))
    فراغ *alloca(__SIZE_TYPE__);
    __BUILTIN(فراغ, abort, (فراغ))
    __BOUND(فراغ, longjmp, ())
#إذا !defined _WIN32
    __BOUND(فراغ*, mmap, ())
    __BOUND(صحيح, munmap, ())
#جيڪڏهن_پورو
    #وصف_رد __BUILTINBC
    #وصف_رد __BUILTIN
    #وصف_رد __BOUND
    #وصف_رد __BOTH
    #وصف_رد __MAYBE_REDIR
    #وصف_رد __RENAME

    #وصف_ڪريو __BUILTIN_EXTERN(name,u) 		\
        صحيح __builtin_##name(u صحيح);		\
        صحيح __builtin_##name##l(u ڊگهو);	\
        صحيح __builtin_##name##ll(u ڊگهو ڊگهو);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, بنانشان)
    __BUILTIN_EXTERN(ctz, بنانشان)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, بنانشان)
    __BUILTIN_EXTERN(parity, بنانشان)
    #وصف_رد __BUILTIN_EXTERN

    #جيڪڏهن_پورو /* ndef __TCC_PP__ */
