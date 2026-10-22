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

#जइ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#जइ defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#अण्णहा
    #define __SIZE_TYPE__ unsigned पूर्णाङ्क
    #define __PTRDIFF_TYPE__ पूर्णाङ्क
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#नोचेद्यदि __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#अण्णहा
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# जइ defined __linux__
    #define __INT64_TYPE__ long
# अण्णहा /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#जइ __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#अण्णहा
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#जइ defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#नोचेद्यदि defined __linux__
    #define __WCHAR_TYPE__ पूर्णाङ्क
    #define __WINT_TYPE__ unsigned पूर्णाङ्क
#अण्णहा
    #define __WCHAR_TYPE__ पूर्णाङ्क
    #define __WINT_TYPE__ पूर्णाङ्क
#endif

    #जइ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#जइ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#जइ defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#नोचेद्यदि defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# जइ __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#अण्णहा
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#नोचेद्यदि defined __FreeBSD_kernel__

#नोचेद्यदि defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#जइ defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#नोचेद्यदि defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#नोचेद्यदि defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned पूर्णाङ्क /* fake type just for size & alignment (macOS Sequoia) */

#नोचेद्यदि defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#अण्णहा
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ पूर्णाङ्क

#जइ !defined _WIN32
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
#जइ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# जइ defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, परिमाण(*(p)))
# अण्णहा
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    संरचना __uint128__ { वर्ण x[16]; } __attribute((__aligned__(16)));
    #define __int128_t संरचना __uint128__
    #define __uint128_t संरचना __uint128__

    /* __builtin_va_list */
#जइ defined __x86_64__
#जइ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    प्रकारनिर्देश संरचना {
        unsigned gp_offset, fp_offset;
        सङ्घ {
            unsigned overflow_offset;
            वर्ण *overflow_arg_area;
        };
        वर्ण *reg_save_area;
    } __builtin_va_list[1];

    शून्य *__va_arg(__builtin_va_list ap, पूर्णाङ्क arg_type, पूर्णाङ्क size, पूर्णाङ्क align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((वर्ण*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), परिमाण(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#अण्णहा /* _WIN64 */
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((परिमाण(t) > 8 || (परिमाण(t) & (परिमाण(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#नोचेद्यदि defined __arm__
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #define _tcc_alignof(type) ((पूर्णाङ्क)&((संरचना {वर्ण c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((वर्ण *)&(last)) + ((परिमाण(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (शून्य *) ((_tcc_align(ap,type)+परिमाण(type)+3) \
                           &~3), *(type *)(ap - ((परिमाण(type)+3)&~3)))

#नोचेद्यदि defined __aarch64__
#जइ defined _WIN32
    प्रकारनिर्देश वर्ण *__builtin_va_list;
#नोचेद्यदि defined __APPLE__
    प्रकारनिर्देश संरचना {
        शून्य *__stack;
    } __builtin_va_list;

#अण्णहा
    प्रकारनिर्देश संरचना {
        शून्य *__stack, *__gr_top, *__vr_top;
        पूर्णाङ्क   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#नोचेद्यदि defined __riscv
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(परिमाण(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (परिमाण(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((परिमाण(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#अण्णहा /* __i386__ */
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((वर्ण *)&(last)) + ((परिमाण(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(परिमाण(t)+3)&~3)-((परिमाण(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (शून्य)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #अण्णहा
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #अण्णहा
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#अण्णहा
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(शून्य*, memcpy, (शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(शून्य*, memmove, (शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(शून्य*, memset, (शून्य *, पूर्णाङ्क, __SIZE_TYPE__))
    __BOTH(पूर्णाङ्क, memcmp, (ध्रुव शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (ध्रुव वर्ण *))
    __BOTH(वर्ण*, strcpy, (वर्ण *, ध्रुव वर्ण *))
    __BOTH(वर्ण*, strncpy, (वर्ण *, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(पूर्णाङ्क, strcmp, (ध्रुव वर्ण*, ध्रुव वर्ण*))
    __BOTH(पूर्णाङ्क, strncmp, (ध्रुव वर्ण*, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(वर्ण*, strcat, (वर्ण*, ध्रुव वर्ण*))
    __BOTH(वर्ण*, strncat, (वर्ण*, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(वर्ण*, strchr, (ध्रुव वर्ण*, पूर्णाङ्क))
    __BOTH(वर्ण*, strrchr, (ध्रुव वर्ण*, पूर्णाङ्क))
    __BOTH(वर्ण*, strdup, (ध्रुव वर्ण*))
#जइ defined __ARM_EABI__
    __BOUND(शून्य*,__aeabi_memcpy,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove4,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove8,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memset,(शून्य*,पूर्णाङ्क,__SIZE_TYPE__))
#endif

#जइ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#अण्णहा
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(शून्य*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, realloc, (शून्य *, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य, मुक्त, (शून्य*))
    __BOTH(शून्य*, alloca, (__SIZE_TYPE__))
    शून्य *alloca(__SIZE_TYPE__);
    __BUILTIN(शून्य, abort, (शून्य))
    __BOUND(शून्य, longjmp, ())
#जइ !defined _WIN32
    __BOUND(शून्य*, mmap, ())
    __BOUND(पूर्णाङ्क, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        पूर्णाङ्क __builtin_##name(u पूर्णाङ्क);		\
        पूर्णाङ्क __builtin_##name##l(u long);	\
        पूर्णाङ्क __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
