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

#എങ്കിൽ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#എങ്കിൽ defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#അല്ലെങ്കിൽ
    #define __SIZE_TYPE__ unsigned പൂർണ്ണസംഖ്യ
    #define __PTRDIFF_TYPE__ പൂർണ്ണസംഖ്യ
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#അല്ലെങ്കിലെങ്കിൽ __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#അല്ലെങ്കിൽ
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# എങ്കിൽ defined __linux__
    #define __INT64_TYPE__ long
# അല്ലെങ്കിൽ /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#എങ്കിൽ __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#അല്ലെങ്കിൽ
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#എങ്കിൽ defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#അല്ലെങ്കിലെങ്കിൽ defined __linux__
    #define __WCHAR_TYPE__ പൂർണ്ണസംഖ്യ
    #define __WINT_TYPE__ unsigned പൂർണ്ണസംഖ്യ
#അല്ലെങ്കിൽ
    #define __WCHAR_TYPE__ പൂർണ്ണസംഖ്യ
    #define __WINT_TYPE__ പൂർണ്ണസംഖ്യ
#endif

    #എങ്കിൽ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#എങ്കിൽ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#എങ്കിൽ defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#അല്ലെങ്കിലെങ്കിൽ defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# എങ്കിൽ __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#അല്ലെങ്കിൽ
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#അല്ലെങ്കിലെങ്കിൽ defined __FreeBSD_kernel__

#അല്ലെങ്കിലെങ്കിൽ defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#എങ്കിൽ defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#അല്ലെങ്കിലെങ്കിൽ defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#അല്ലെങ്കിലെങ്കിൽ defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned പൂർണ്ണസംഖ്യ /* fake type just for size & alignment (macOS Sequoia) */

#അല്ലെങ്കിലെങ്കിൽ defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#അല്ലെങ്കിൽ
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ പൂർണ്ണസംഖ്യ

#എങ്കിൽ !defined _WIN32
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
#എങ്കിൽ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# എങ്കിൽ defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, വലുപ്പം(*(p)))
# അല്ലെങ്കിൽ
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    ഘടന __uint128__ { അക്ഷരം x[16]; } __attribute((__aligned__(16)));
    #define __int128_t ഘടന __uint128__
    #define __uint128_t ഘടന __uint128__

    /* __builtin_va_list */
#എങ്കിൽ defined __x86_64__
#എങ്കിൽ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    തരനിർവചനം ഘടന {
        unsigned gp_offset, fp_offset;
        സംഘം {
            unsigned overflow_offset;
            അക്ഷരം *overflow_arg_area;
        };
        അക്ഷരം *reg_save_area;
    } __builtin_va_list[1];

    ശൂന്യം *__va_arg(__builtin_va_list ap, പൂർണ്ണസംഖ്യ arg_type, പൂർണ്ണസംഖ്യ size, പൂർണ്ണസംഖ്യ align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((അക്ഷരം*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), വലുപ്പം(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#അല്ലെങ്കിൽ /* _WIN64 */
    തരനിർവചനം അക്ഷരം *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((വലുപ്പം(t) > 8 || (വലുപ്പം(t) & (വലുപ്പം(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#അല്ലെങ്കിലെങ്കിൽ defined __arm__
    തരനിർവചനം അക്ഷരം *__builtin_va_list;
    #define _tcc_alignof(type) ((പൂർണ്ണസംഖ്യ)&((ഘടന {അക്ഷരം c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((അക്ഷരം *)&(last)) + ((വലുപ്പം(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (ശൂന്യം *) ((_tcc_align(ap,type)+വലുപ്പം(type)+3) \
                           &~3), *(type *)(ap - ((വലുപ്പം(type)+3)&~3)))

#അല്ലെങ്കിലെങ്കിൽ defined __aarch64__
#എങ്കിൽ defined _WIN32
    തരനിർവചനം അക്ഷരം *__builtin_va_list;
#അല്ലെങ്കിലെങ്കിൽ defined __APPLE__
    തരനിർവചനം ഘടന {
        ശൂന്യം *__stack;
    } __builtin_va_list;

#അല്ലെങ്കിൽ
    തരനിർവചനം ഘടന {
        ശൂന്യം *__stack, *__gr_top, *__vr_top;
        പൂർണ്ണസംഖ്യ   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#അല്ലെങ്കിലെങ്കിൽ defined __riscv
    തരനിർവചനം അക്ഷരം *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(വലുപ്പം(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (വലുപ്പം(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((വലുപ്പം(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#അല്ലെങ്കിൽ /* __i386__ */
    തരനിർവചനം അക്ഷരം *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((അക്ഷരം *)&(last)) + ((വലുപ്പം(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(വലുപ്പം(t)+3)&~3)-((വലുപ്പം(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (ശൂന്യം)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #അല്ലെങ്കിൽ
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #അല്ലെങ്കിൽ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#അല്ലെങ്കിൽ
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(ശൂന്യം*, memcpy, (ശൂന്യം *, സ്ഥിരം ശൂന്യം*, __SIZE_TYPE__))
    __BOTH(ശൂന്യം*, memmove, (ശൂന്യം *, സ്ഥിരം ശൂന്യം*, __SIZE_TYPE__))
    __BOTH(ശൂന്യം*, memset, (ശൂന്യം *, പൂർണ്ണസംഖ്യ, __SIZE_TYPE__))
    __BOTH(പൂർണ്ണസംഖ്യ, memcmp, (സ്ഥിരം ശൂന്യം *, സ്ഥിരം ശൂന്യം*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (സ്ഥിരം അക്ഷരം *))
    __BOTH(അക്ഷരം*, strcpy, (അക്ഷരം *, സ്ഥിരം അക്ഷരം *))
    __BOTH(അക്ഷരം*, strncpy, (അക്ഷരം *, സ്ഥിരം അക്ഷരം*, __SIZE_TYPE__))
    __BOTH(പൂർണ്ണസംഖ്യ, strcmp, (സ്ഥിരം അക്ഷരം*, സ്ഥിരം അക്ഷരം*))
    __BOTH(പൂർണ്ണസംഖ്യ, strncmp, (സ്ഥിരം അക്ഷരം*, സ്ഥിരം അക്ഷരം*, __SIZE_TYPE__))
    __BOTH(അക്ഷരം*, strcat, (അക്ഷരം*, സ്ഥിരം അക്ഷരം*))
    __BOTH(അക്ഷരം*, strncat, (അക്ഷരം*, സ്ഥിരം അക്ഷരം*, __SIZE_TYPE__))
    __BOTH(അക്ഷരം*, strchr, (സ്ഥിരം അക്ഷരം*, പൂർണ്ണസംഖ്യ))
    __BOTH(അക്ഷരം*, strrchr, (സ്ഥിരം അക്ഷരം*, പൂർണ്ണസംഖ്യ))
    __BOTH(അക്ഷരം*, strdup, (സ്ഥിരം അക്ഷരം*))
#എങ്കിൽ defined __ARM_EABI__
    __BOUND(ശൂന്യം*,__aeabi_memcpy,(ശൂന്യം*,സ്ഥിരം ശൂന്യം*,__SIZE_TYPE__))
    __BOUND(ശൂന്യം*,__aeabi_memmove,(ശൂന്യം*,സ്ഥിരം ശൂന്യം*,__SIZE_TYPE__))
    __BOUND(ശൂന്യം*,__aeabi_memmove4,(ശൂന്യം*,സ്ഥിരം ശൂന്യം*,__SIZE_TYPE__))
    __BOUND(ശൂന്യം*,__aeabi_memmove8,(ശൂന്യം*,സ്ഥിരം ശൂന്യം*,__SIZE_TYPE__))
    __BOUND(ശൂന്യം*,__aeabi_memset,(ശൂന്യം*,പൂർണ്ണസംഖ്യ,__SIZE_TYPE__))
#endif

#എങ്കിൽ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#അല്ലെങ്കിൽ
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(ശൂന്യം*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(ശൂന്യം*, realloc, (ശൂന്യം *, __SIZE_TYPE__))
    __MAYBE_REDIR(ശൂന്യം*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ശൂന്യം*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(ശൂന്യം, സ്വതന്ത്രം, (ശൂന്യം*))
    __BOTH(ശൂന്യം*, alloca, (__SIZE_TYPE__))
    ശൂന്യം *alloca(__SIZE_TYPE__);
    __BUILTIN(ശൂന്യം, abort, (ശൂന്യം))
    __BOUND(ശൂന്യം, longjmp, ())
#എങ്കിൽ !defined _WIN32
    __BOUND(ശൂന്യം*, mmap, ())
    __BOUND(പൂർണ്ണസംഖ്യ, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        പൂർണ്ണസംഖ്യ __builtin_##name(u പൂർണ്ണസംഖ്യ);		\
        പൂർണ്ണസംഖ്യ __builtin_##name##l(u long);	\
        പൂർണ്ണസംഖ്യ __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
