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

#اگر __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#اگر defined  __OpenBSD__
    #تعریف_کرو __SIZE_TYPE__ غیرعلامتی طویل
    #تعریف_کرو __PTRDIFF_TYPE__ طویل
#ورنہ
    #تعریف_کرو __SIZE_TYPE__ غیرعلامتی صحیح
    #تعریف_کرو __PTRDIFF_TYPE__ صحیح
#اگر_ختم
    #تعریف_کرو __ILP32__ 1
    #تعریف_کرو __INT64_TYPE__ طویل طویل
#وگرنہ_اگر __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #تعریف_کرو __SIZE_TYPE__ غیرعلامتی طویل طویل
    #تعریف_کرو __PTRDIFF_TYPE__ طویل طویل
    #تعریف_کرو __LLP64__ 1
    #تعریف_کرو __INT64_TYPE__ طویل طویل
#ورنہ
    /* Other 64bit systems. */
    #تعریف_کرو __SIZE_TYPE__ غیرعلامتی طویل
    #تعریف_کرو __PTRDIFF_TYPE__ طویل
    #تعریف_کرو __LP64__ 1
# اگر defined __linux__
    #تعریف_کرو __INT64_TYPE__ طویل
# ورنہ /* APPLE, BSD */
    #تعریف_کرو __INT64_TYPE__ طویل طویل
# endif
#اگر_ختم
    #تعریف_کرو __SIZEOF_INT__ 4
    #تعریف_کرو __INT_MAX__ 0x7fffffff
#اگر __SIZEOF_LONG__ == 4
    #تعریف_کرو __LONG_MAX__ 0x7fffffffL
#ورنہ
    #تعریف_کرو __LONG_MAX__ 0x7fffffffffffffffL
#اگر_ختم
    #تعریف_کرو __SIZEOF_LONG_LONG__ 8
    #تعریف_کرو __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #تعریف_کرو __CHAR_BIT__ 8
    #تعریف_کرو __ORDER_LITTLE_ENDIAN__ 1234
    #تعریف_کرو __ORDER_BIG_ENDIAN__ 4321
    #تعریف_کرو __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#اگر defined _WIN32
    #تعریف_کرو __WCHAR_TYPE__ غیرعلامتی مختصر
    #تعریف_کرو __WINT_TYPE__ غیرعلامتی مختصر
#وگرنہ_اگر defined __linux__
    #تعریف_کرو __WCHAR_TYPE__ صحیح
    #تعریف_کرو __WINT_TYPE__ غیرعلامتی صحیح
#ورنہ
    #تعریف_کرو __WCHAR_TYPE__ صحیح
    #تعریف_کرو __WINT_TYPE__ صحیح
#اگر_ختم

    #اگر __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#اگر !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#اگر_ختم
    #اگر_ختم

#اگر defined _WIN32
    #تعریف_کرو __declspec(x) __attribute__((x))
    #تعریف_کرو __cdecl

#وگرنہ_اگر defined __FreeBSD__
    #تعریف_کرو __GNUC__ 9
    #تعریف_کرو __GNUC_MINOR__ 3
    #تعریف_کرو __GNUC_PATCHLEVEL__ 0
    #تعریف_کرو __GNUC_STDC_INLINE__ 1
    #تعریف_کرو __NO_TLS 1
    #تعریف_کرو __RUNETYPE_INTERNAL 1
# اگر __SIZEOF_POINTER__ == 8
    #تعریف_کرو __SIZEOF_SIZE_T__ 8
    #تعریف_کرو __SIZEOF_PTRDIFF_T__ 8
#ورنہ
    #تعریف_کرو __SIZEOF_SIZE_T__ 4
    #تعریف_کرو __SIZEOF_PTRDIFF_T__ 4
# endif

#وگرنہ_اگر defined __FreeBSD_kernel__

#وگرنہ_اگر defined __NetBSD__
    #تعریف_کرو __GNUC__ 4
    #تعریف_کرو __GNUC_MINOR__ 1
    #تعریف_کرو __GNUC_PATCHLEVEL__ 0
    #تعریف_کرو _Pragma(x)
    #تعریف_کرو __ELF__ 1
#اگر defined __aarch64__
    #تعریف_کرو _LOCORE /* avoids usage of __asm */
#اگر_ختم

#وگرنہ_اگر defined __OpenBSD__
    #تعریف_کرو __GNUC__ 4
    #تعریف_کرو _ANSI_LIBRARY 1

#وگرنہ_اگر defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #تعریف_کرو __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #تعریف_کرو __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #تعریف_کرو __LITTLE_ENDIAN__ 1
    #تعریف_کرو _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #تعریف_کرو __FINITE_MATH_ONLY__ 1
    #تعریف_کرو FORTIFY_ماخذ 0
    //#define __has_builtin(x) 0
    #تعریف_کرو _Float16 مختصر غیرعلامتی صحیح /* fake type just for size & alignment (macOS Sequoia) */

#وگرنہ_اگر defined __ANDROID__
    #تعریف_کرو  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ورنہ
    /* Linux */

#اگر_ختم

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#اگر_غیر_تعریف_شدہ __NetBSD__
    #تعریف_کرو __UINTPTR_TYPE__ غیرعلامتی __PTRDIFF_TYPE__
    #تعریف_کرو __INTPTR_TYPE__ __PTRDIFF_TYPE__
#اگر_ختم
    #تعریف_کرو __INT32_TYPE__ صحیح

#اگر !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #تعریف_کرو __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #تعریف_کرو __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #تعریف_کرو __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#اگر_ختم

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
    #اگر_غیر_تعریف_شدہ __TCC_PP__

    #تعریف_کرو __builtin_offsetof(type, میدان) ((__SIZE_TYPE__)&((type*)0)->میدان)
    #تعریف_کرو __builtin_extract_return_addr(x) x
#اگر !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #تعریف_کرو __builtin_huge_val() 1e500
    #تعریف_کرو __builtin_huge_valf() 1e50f
    #تعریف_کرو __builtin_huge_vall() 1e5000L
# اگر defined __APPLE__
    #تعریف_کرو __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #تعریف_کرو __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #تعریف_کرو __builtin_bzero(p, ignored_سائز) bzero(p, حجم(*(p)))
# ورنہ
    #تعریف_کرو __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#اگر_ختم

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ساخت __uint128__ { حرف x[16]; } __attribute((__aligned__(16)));
    #تعریف_کرو __int128_t ساخت __uint128__
    #تعریف_کرو __uint128_t ساخت __uint128__

    /* __builtin_va_list */
#اگر defined __x86_64__
#اگر !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    قسمتعریف ساخت {
        غیرعلامتی gp_انحراف, fp_انحراف;
        اتحاد {
            غیرعلامتی حد_سے_تجاوز_انحراف;
            حرف *حد_سے_تجاوز_arg_area;
        };
        حرف *reg_save_area;
    } __builtin_va_list[1];

    خالی *__va_arg(__builtin_va_list ap, صحیح arg_type, صحیح سائز, صحیح align);
    #تعریف_کرو __builtin_va_start(ap, آخری) \
       (*(ap) = *(__builtin_va_list)((حرف*)__builtin_frame_address(0) - 24))
    #تعریف_کرو __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), حجم(t), __alignof__(t))))
    #تعریف_کرو __builtin_va_copy(dest, src) (*(dest) = *(src))

#ورنہ /* _WIN64 */
    قسمتعریف حرف *__builtin_va_list;
    #تعریف_کرو __builtin_va_arg(ap, t) ((حجم(t) > 8 || (حجم(t) & (حجم(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#اگر_ختم

#وگرنہ_اگر defined __arm__
    قسمتعریف حرف *__builtin_va_list;
    #تعریف_کرو _tcc_alignof(type) ((صحیح)&((ساخت {حرف c;type x;} *)0)->x)
    #تعریف_کرو _tcc_align(addr,type) (((غیرعلامتی)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #تعریف_کرو __builtin_va_start(ap,آخری) (ap = ((حرف *)&(آخری)) + ((حجم(آخری)+3)&~3))
    #تعریف_کرو __builtin_va_arg(ap,type) (ap = (خالی *) ((_tcc_align(ap,type)+حجم(type)+3) \
                           &~3), *(type *)(ap - ((حجم(type)+3)&~3)))

#وگرنہ_اگر defined __aarch64__
#اگر defined _WIN32
    قسمتعریف حرف *__builtin_va_list;
#وگرنہ_اگر defined __APPLE__
    قسمتعریف ساخت {
        خالی *__stack;
    } __builtin_va_list;

#ورنہ
    قسمتعریف ساخت {
        خالی *__stack, *__gr_top, *__vr_top;
        صحیح   __gr_offs, __vr_offs;
    } __builtin_va_list;

#اگر_ختم
#وگرنہ_اگر defined __riscv
    قسمتعریف حرف *__builtin_va_list;
    #تعریف_کرو __va_reg_size (__riscv_xlen >> 3)
    #تعریف_کرو _tcc_align(addr,type) (((غیرعلامتی طویل)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #تعریف_کرو __builtin_va_arg(ap,type) (*(حجم(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (حجم(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((حجم(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ورنہ /* __i386__ */
    قسمتعریف حرف *__builtin_va_list;
    #تعریف_کرو __builtin_va_start(ap,آخری) (ap = ((حرف *)&(آخری)) + ((حجم(آخری)+3)&~3))
    #تعریف_کرو __builtin_va_arg(ap,t) (*(t*)((ap+=(حجم(t)+3)&~3)-((حجم(t)+3)&~3)))

#اگر_ختم
    #تعریف_کرو __builtin_va_end(ap) (خالی)(ap)
    #اگر_غیر_تعریف_شدہ __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #اگر_ختم

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #اگر_تعریف_شدہ __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ورنہ
    # define __RENAME(X) __asm__(X)
    #اگر_ختم

    #اگر_تعریف_شدہ __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ورنہ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #اگر_ختم
#اگر_تعریف_شدہ _WIN32
    #تعریف_کرو __BOTH __BOUND
    #تعریف_کرو __BUILTIN(ret,name,params)
#ورنہ
    #تعریف_کرو __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #تعریف_کرو __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#اگر_ختم

    __BOTH(خالی*, حافظہ_نقل, (خالی *, ثابت خالی*, __SIZE_TYPE__))
    __BOTH(خالی*, memmove, (خالی *, ثابت خالی*, __SIZE_TYPE__))
    __BOTH(خالی*, memset, (خالی *, صحیح, __SIZE_TYPE__))
    __BOTH(صحیح, memcmp, (ثابت خالی *, ثابت خالی*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, لڑی_لمبائی, (ثابت حرف *))
    __BOTH(حرف*, strcpy, (حرف *, ثابت حرف *))
    __BOTH(حرف*, strncpy, (حرف *, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(صحیح, strcmp, (ثابت حرف*, ثابت حرف*))
    __BOTH(صحیح, لڑی_موازنہ, (ثابت حرف*, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(حرف*, strcat, (حرف*, ثابت حرف*))
    __BOTH(حرف*, strncat, (حرف*, ثابت حرف*, __SIZE_TYPE__))
    __BOTH(حرف*, strchr, (ثابت حرف*, صحیح))
    __BOTH(حرف*, strrchr, (ثابت حرف*, صحیح))
    __BOTH(حرف*, strdup, (ثابت حرف*))
#اگر defined __ARM_EABI__
    __BOUND(خالی*,__aeabi_memcpy,(خالی*,ثابت خالی*,__SIZE_TYPE__))
    __BOUND(خالی*,__aeabi_memmove,(خالی*,ثابت خالی*,__SIZE_TYPE__))
    __BOUND(خالی*,__aeabi_memmove4,(خالی*,ثابت خالی*,__SIZE_TYPE__))
    __BOUND(خالی*,__aeabi_memmove8,(خالی*,ثابت خالی*,__SIZE_TYPE__))
    __BOUND(خالی*,__aeabi_memset,(خالی*,صحیح,__SIZE_TYPE__))
#اگر_ختم

#اگر defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #تعریف_کرو __MAYBE_REDIR __BUILTIN
#ورنہ
    #تعریف_کرو __MAYBE_REDIR __BOTH
#اگر_ختم
    __MAYBE_REDIR(خالی*, حافظہ_دو, (__SIZE_TYPE__))
    __MAYBE_REDIR(خالی*, realloc, (خالی *, __SIZE_TYPE__))
    __MAYBE_REDIR(خالی*, صفر_حافظہ_دو, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(خالی*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(خالی, آزاد, (خالی*))
    __BOTH(خالی*, alloca, (__SIZE_TYPE__))
    خالی *alloca(__SIZE_TYPE__);
    __BUILTIN(خالی, abort, (خالی))
    __BOUND(خالی, longjmp, ())
#اگر !defined _WIN32
    __BOUND(خالی*, mmap, ())
    __BOUND(صحیح, munmap, ())
#اگر_ختم
    #تعریف_منسوخ __BUILTINBC
    #تعریف_منسوخ __BUILTIN
    #تعریف_منسوخ __BOUND
    #تعریف_منسوخ __BOTH
    #تعریف_منسوخ __MAYBE_REDIR
    #تعریف_منسوخ __RENAME

    #تعریف_کرو __BUILTIN_EXTERN(name,u) 		\
        صحیح __builtin_##name(u صحیح);		\
        صحیح __builtin_##name##l(u طویل);	\
        صحیح __builtin_##name##ll(u طویل طویل);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, غیرعلامتی)
    __BUILTIN_EXTERN(ctz, غیرعلامتی)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, غیرعلامتی)
    __BUILTIN_EXTERN(parity, غیرعلامتی)
    #تعریف_منسوخ __BUILTIN_EXTERN

    #اگر_ختم /* ndef __TCC_PP__ */
