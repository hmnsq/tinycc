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

#যদি __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#যদি defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#অন্যথা
    #define __SIZE_TYPE__ unsigned পূর্ণাঙ্ক
    #define __PTRDIFF_TYPE__ পূর্ণাঙ্ক
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#নোচেদ্যদি __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#অন্যথা
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# যদি defined __linux__
    #define __INT64_TYPE__ long
# অন্যথা /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#যদি __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#অন্যথা
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#যদি defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#নোচেদ্যদি defined __linux__
    #define __WCHAR_TYPE__ পূর্ণাঙ্ক
    #define __WINT_TYPE__ unsigned পূর্ণাঙ্ক
#অন্যথা
    #define __WCHAR_TYPE__ পূর্ণাঙ্ক
    #define __WINT_TYPE__ পূর্ণাঙ্ক
#endif

    #যদি __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#যদি !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#যদি defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#নোচেদ্যদি defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# যদি __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#অন্যথা
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#নোচেদ্যদি defined __FreeBSD_kernel__

#নোচেদ্যদি defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#যদি defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#নোচেদ্যদি defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#নোচেদ্যদি defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned পূর্ণাঙ্ক /* fake type just for size & alignment (macOS Sequoia) */

#নোচেদ্যদি defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#অন্যথা
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ পূর্ণাঙ্ক

#যদি !defined _WIN32
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
#যদি !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# যদি defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, পরিমাণ(*(p)))
# অন্যথা
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    সংরচনা __uint128__ { ৱর্ণ x[16]; } __attribute((__aligned__(16)));
    #define __int128_t সংরচনা __uint128__
    #define __uint128_t সংরচনা __uint128__

    /* __builtin_va_list */
#যদি defined __x86_64__
#যদি !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    প্রকারনির্দেশ সংরচনা {
        unsigned gp_offset, fp_offset;
        সঙ্ঘ {
            unsigned overflow_offset;
            ৱর্ণ *overflow_arg_area;
        };
        ৱর্ণ *reg_save_area;
    } __builtin_va_list[1];

    শূন্য *__va_arg(__builtin_va_list ap, পূর্ণাঙ্ক arg_type, পূর্ণাঙ্ক size, পূর্ণাঙ্ক align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((ৱর্ণ*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), পরিমাণ(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#অন্যথা /* _WIN64 */
    প্রকারনির্দেশ ৱর্ণ *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((পরিমাণ(t) > 8 || (পরিমাণ(t) & (পরিমাণ(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#নোচেদ্যদি defined __arm__
    প্রকারনির্দেশ ৱর্ণ *__builtin_va_list;
    #define _tcc_alignof(type) ((পূর্ণাঙ্ক)&((সংরচনা {ৱর্ণ c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((ৱর্ণ *)&(last)) + ((পরিমাণ(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (শূন্য *) ((_tcc_align(ap,type)+পরিমাণ(type)+3) \
                           &~3), *(type *)(ap - ((পরিমাণ(type)+3)&~3)))

#নোচেদ্যদি defined __aarch64__
#যদি defined _WIN32
    প্রকারনির্দেশ ৱর্ণ *__builtin_va_list;
#নোচেদ্যদি defined __APPLE__
    প্রকারনির্দেশ সংরচনা {
        শূন্য *__stack;
    } __builtin_va_list;

#অন্যথা
    প্রকারনির্দেশ সংরচনা {
        শূন্য *__stack, *__gr_top, *__vr_top;
        পূর্ণাঙ্ক   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#নোচেদ্যদি defined __riscv
    প্রকারনির্দেশ ৱর্ণ *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(পরিমাণ(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (পরিমাণ(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((পরিমাণ(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#অন্যথা /* __i386__ */
    প্রকারনির্দেশ ৱর্ণ *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((ৱর্ণ *)&(last)) + ((পরিমাণ(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(পরিমাণ(t)+3)&~3)-((পরিমাণ(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (শূন্য)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #অন্যথা
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #অন্যথা
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#অন্যথা
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(শূন্য*, memcpy, (শূন্য *, ধ্রুৱ শূন্য*, __SIZE_TYPE__))
    __BOTH(শূন্য*, memmove, (শূন্য *, ধ্রুৱ শূন্য*, __SIZE_TYPE__))
    __BOTH(শূন্য*, memset, (শূন্য *, পূর্ণাঙ্ক, __SIZE_TYPE__))
    __BOTH(পূর্ণাঙ্ক, memcmp, (ধ্রুৱ শূন্য *, ধ্রুৱ শূন্য*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (ধ্রুৱ ৱর্ণ *))
    __BOTH(ৱর্ণ*, strcpy, (ৱর্ণ *, ধ্রুৱ ৱর্ণ *))
    __BOTH(ৱর্ণ*, strncpy, (ৱর্ণ *, ধ্রুৱ ৱর্ণ*, __SIZE_TYPE__))
    __BOTH(পূর্ণাঙ্ক, strcmp, (ধ্রুৱ ৱর্ণ*, ধ্রুৱ ৱর্ণ*))
    __BOTH(পূর্ণাঙ্ক, strncmp, (ধ্রুৱ ৱর্ণ*, ধ্রুৱ ৱর্ণ*, __SIZE_TYPE__))
    __BOTH(ৱর্ণ*, strcat, (ৱর্ণ*, ধ্রুৱ ৱর্ণ*))
    __BOTH(ৱর্ণ*, strncat, (ৱর্ণ*, ধ্রুৱ ৱর্ণ*, __SIZE_TYPE__))
    __BOTH(ৱর্ণ*, strchr, (ধ্রুৱ ৱর্ণ*, পূর্ণাঙ্ক))
    __BOTH(ৱর্ণ*, strrchr, (ধ্রুৱ ৱর্ণ*, পূর্ণাঙ্ক))
    __BOTH(ৱর্ণ*, strdup, (ধ্রুৱ ৱর্ণ*))
#যদি defined __ARM_EABI__
    __BOUND(শূন্য*,__aeabi_memcpy,(শূন্য*,ধ্রুৱ শূন্য*,__SIZE_TYPE__))
    __BOUND(শূন্য*,__aeabi_memmove,(শূন্য*,ধ্রুৱ শূন্য*,__SIZE_TYPE__))
    __BOUND(শূন্য*,__aeabi_memmove4,(শূন্য*,ধ্রুৱ শূন্য*,__SIZE_TYPE__))
    __BOUND(শূন্য*,__aeabi_memmove8,(শূন্য*,ধ্রুৱ শূন্য*,__SIZE_TYPE__))
    __BOUND(শূন্য*,__aeabi_memset,(শূন্য*,পূর্ণাঙ্ক,__SIZE_TYPE__))
#endif

#যদি defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#অন্যথা
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(শূন্য*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(শূন্য*, realloc, (শূন্য *, __SIZE_TYPE__))
    __MAYBE_REDIR(শূন্য*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(শূন্য*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(শূন্য, মুক্ত, (শূন্য*))
    __BOTH(শূন্য*, alloca, (__SIZE_TYPE__))
    শূন্য *alloca(__SIZE_TYPE__);
    __BUILTIN(শূন্য, abort, (শূন্য))
    __BOUND(শূন্য, longjmp, ())
#যদি !defined _WIN32
    __BOUND(শূন্য*, mmap, ())
    __BOUND(পূর্ণাঙ্ক, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        পূর্ণাঙ্ক __builtin_##name(u পূর্ণাঙ্ক);		\
        পূর্ণাঙ্ক __builtin_##name##l(u long);	\
        পূর্ণাঙ্ক __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
