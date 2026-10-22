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

#ଯଦି __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ଯଦି defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#ଅନ୍ୟଥା
    #define __SIZE_TYPE__ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା
    #define __PTRDIFF_TYPE__ ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#ନଚେତଯଦି __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#ଅନ୍ୟଥା
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# ଯଦି defined __linux__
    #define __INT64_TYPE__ long
# ଅନ୍ୟଥା /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#ଯଦି __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#ଅନ୍ୟଥା
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ଯଦି defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#ନଚେତଯଦି defined __linux__
    #define __WCHAR_TYPE__ ପୂର୍ଣ୍ଣସଂଖ୍ୟା
    #define __WINT_TYPE__ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#ଅନ୍ୟଥା
    #define __WCHAR_TYPE__ ପୂର୍ଣ୍ଣସଂଖ୍ୟା
    #define __WINT_TYPE__ ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#endif

    #ଯଦି __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ଯଦି !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#ଯଦି defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#ନଚେତଯଦି defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# ଯଦି __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#ଅନ୍ୟଥା
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#ନଚେତଯଦି defined __FreeBSD_kernel__

#ନଚେତଯଦି defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#ଯଦି defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#ନଚେତଯଦି defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#ନଚେତଯଦି defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା /* fake type just for size & alignment (macOS Sequoia) */

#ନଚେତଯଦି defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ଅନ୍ୟଥା
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ ପୂର୍ଣ୍ଣସଂଖ୍ୟା

#ଯଦି !defined _WIN32
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
#ଯଦି !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# ଯଦି defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, ଆକାର(*(p)))
# ଅନ୍ୟଥା
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ସଂରଚନା __uint128__ { ଅକ୍ଷର x[16]; } __attribute((__aligned__(16)));
    #define __int128_t ସଂରଚନା __uint128__
    #define __uint128_t ସଂରଚନା __uint128__

    /* __builtin_va_list */
#ଯଦି defined __x86_64__
#ଯଦି !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
        unsigned gp_offset, fp_offset;
        ସଂଘ {
            unsigned overflow_offset;
            ଅକ୍ଷର *overflow_arg_area;
        };
        ଅକ୍ଷର *reg_save_area;
    } __builtin_va_list[1];

    ଶୂନ୍ୟ *__va_arg(__builtin_va_list ap, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg_type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((ଅକ୍ଷର*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), ଆକାର(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#ଅନ୍ୟଥା /* _WIN64 */
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((ଆକାର(t) > 8 || (ଆକାର(t) & (ଆକାର(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#ନଚେତଯଦି defined __arm__
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *__builtin_va_list;
    #define _tcc_alignof(type) ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)&((ସଂରଚନା {ଅକ୍ଷର c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((ଅକ୍ଷର *)&(last)) + ((ଆକାର(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (ଶୂନ୍ୟ *) ((_tcc_align(ap,type)+ଆକାର(type)+3) \
                           &~3), *(type *)(ap - ((ଆକାର(type)+3)&~3)))

#ନଚେତଯଦି defined __aarch64__
#ଯଦି defined _WIN32
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *__builtin_va_list;
#ନଚେତଯଦି defined __APPLE__
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
        ଶୂନ୍ୟ *__stack;
    } __builtin_va_list;

#ଅନ୍ୟଥା
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
        ଶୂନ୍ୟ *__stack, *__gr_top, *__vr_top;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#ନଚେତଯଦି defined __riscv
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(ଆକାର(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (ଆକାର(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((ଆକାର(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ଅନ୍ୟଥା /* __i386__ */
    ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((ଅକ୍ଷର *)&(last)) + ((ଆକାର(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(ଆକାର(t)+3)&~3)-((ଆକାର(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (ଶୂନ୍ୟ)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ଅନ୍ୟଥା
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ଅନ୍ୟଥା
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#ଅନ୍ୟଥା
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(ଶୂନ୍ୟ*, memcpy, (ଶୂନ୍ୟ *, ଅଚଳ ଶୂନ୍ୟ*, __SIZE_TYPE__))
    __BOTH(ଶୂନ୍ୟ*, memmove, (ଶୂନ୍ୟ *, ଅଚଳ ଶୂନ୍ୟ*, __SIZE_TYPE__))
    __BOTH(ଶୂନ୍ୟ*, memset, (ଶୂନ୍ୟ *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, __SIZE_TYPE__))
    __BOTH(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, memcmp, (ଅଚଳ ଶୂନ୍ୟ *, ଅଚଳ ଶୂନ୍ୟ*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (ଅଚଳ ଅକ୍ଷର *))
    __BOTH(ଅକ୍ଷର*, strcpy, (ଅକ୍ଷର *, ଅଚଳ ଅକ୍ଷର *))
    __BOTH(ଅକ୍ଷର*, strncpy, (ଅକ୍ଷର *, ଅଚଳ ଅକ୍ଷର*, __SIZE_TYPE__))
    __BOTH(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, strcmp, (ଅଚଳ ଅକ୍ଷର*, ଅଚଳ ଅକ୍ଷର*))
    __BOTH(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, strncmp, (ଅଚଳ ଅକ୍ଷର*, ଅଚଳ ଅକ୍ଷର*, __SIZE_TYPE__))
    __BOTH(ଅକ୍ଷର*, strcat, (ଅକ୍ଷର*, ଅଚଳ ଅକ୍ଷର*))
    __BOTH(ଅକ୍ଷର*, strncat, (ଅକ୍ଷର*, ଅଚଳ ଅକ୍ଷର*, __SIZE_TYPE__))
    __BOTH(ଅକ୍ଷର*, strchr, (ଅଚଳ ଅକ୍ଷର*, ପୂର୍ଣ୍ଣସଂଖ୍ୟା))
    __BOTH(ଅକ୍ଷର*, strrchr, (ଅଚଳ ଅକ୍ଷର*, ପୂର୍ଣ୍ଣସଂଖ୍ୟା))
    __BOTH(ଅକ୍ଷର*, strdup, (ଅଚଳ ଅକ୍ଷର*))
#ଯଦି defined __ARM_EABI__
    __BOUND(ଶୂନ୍ୟ*,__aeabi_memcpy,(ଶୂନ୍ୟ*,ଅଚଳ ଶୂନ୍ୟ*,__SIZE_TYPE__))
    __BOUND(ଶୂନ୍ୟ*,__aeabi_memmove,(ଶୂନ୍ୟ*,ଅଚଳ ଶୂନ୍ୟ*,__SIZE_TYPE__))
    __BOUND(ଶୂନ୍ୟ*,__aeabi_memmove4,(ଶୂନ୍ୟ*,ଅଚଳ ଶୂନ୍ୟ*,__SIZE_TYPE__))
    __BOUND(ଶୂନ୍ୟ*,__aeabi_memmove8,(ଶୂନ୍ୟ*,ଅଚଳ ଶୂନ୍ୟ*,__SIZE_TYPE__))
    __BOUND(ଶୂନ୍ୟ*,__aeabi_memset,(ଶୂନ୍ୟ*,ପୂର୍ଣ୍ଣସଂଖ୍ୟା,__SIZE_TYPE__))
#endif

#ଯଦି defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#ଅନ୍ୟଥା
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(ଶୂନ୍ୟ*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(ଶୂନ୍ୟ*, realloc, (ଶୂନ୍ୟ *, __SIZE_TYPE__))
    __MAYBE_REDIR(ଶୂନ୍ୟ*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ଶୂନ୍ୟ*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ଶୂନ୍ୟ, ମୁକ୍ତ, (ଶୂନ୍ୟ*))
    __BOTH(ଶୂନ୍ୟ*, alloca, (__SIZE_TYPE__))
    ଶୂନ୍ୟ *alloca(__SIZE_TYPE__);
    __BUILTIN(ଶୂନ୍ୟ, abort, (ଶୂନ୍ୟ))
    __BOUND(ଶୂନ୍ୟ, longjmp, ())
#ଯଦି !defined _WIN32
    __BOUND(ଶୂନ୍ୟ*, mmap, ())
    __BOUND(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା __builtin_##name(u ପୂର୍ଣ୍ଣସଂଖ୍ୟା);		\
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା __builtin_##name##l(u long);	\
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
