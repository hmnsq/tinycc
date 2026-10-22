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

#ᯀᯮᯝ __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#ᯀᯮᯝ defined  __OpenBSD__
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
#ᯀᯮᯝᯂᯪ
    #define __SIZE_TYPE__ unsigned puur_naa_nka
    #define __PTRDIFF_TYPE__ puur_naa_nka
#endif
    #define __ILP32__ 1
    #define __INT64_TYPE__ long long
#elif __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #define __SIZE_TYPE__ unsigned long long
    #define __PTRDIFF_TYPE__ long long
    #define __LLP64__ 1
    #define __INT64_TYPE__ long long
#ᯀᯮᯝᯂᯪ
    /* Other 64bit systems. */
    #define __SIZE_TYPE__ unsigned long
    #define __PTRDIFF_TYPE__ long
    #define __LP64__ 1
# ᯀᯮᯝ defined __linux__
    #define __INT64_TYPE__ long
# ᯀᯮᯝᯂᯪ /* APPLE, BSD */
    #define __INT64_TYPE__ long long
# endif
#endif
    #define __SIZEOF_INT__ 4
    #define __INT_MAX__ 0x7fffffff
#ᯀᯮᯝ __SIZEOF_LONG__ == 4
    #define __LONG_MAX__ 0x7fffffffL
#ᯀᯮᯝᯂᯪ
    #define __LONG_MAX__ 0x7fffffffffffffffL
#endif
    #define __SIZEOF_LONG_LONG__ 8
    #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #define __CHAR_BIT__ 8
    #define __ORDER_LITTLE_ENDIAN__ 1234
    #define __ORDER_BIG_ENDIAN__ 4321
    #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#ᯀᯮᯝ defined _WIN32
    #define __WCHAR_TYPE__ unsigned short
    #define __WINT_TYPE__ unsigned short
#elif defined __linux__
    #define __WCHAR_TYPE__ puur_naa_nka
    #define __WINT_TYPE__ unsigned puur_naa_nka
#ᯀᯮᯝᯂᯪ
    #define __WCHAR_TYPE__ puur_naa_nka
    #define __WINT_TYPE__ puur_naa_nka
#endif

    #ᯀᯮᯝ __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#ᯀᯮᯝ !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#endif
    #endif

#ᯀᯮᯝ defined _WIN32
    #define __declspec(x) __attribute__((x))
    #define __cdecl

#elif defined __FreeBSD__
    #define __GNUC__ 9
    #define __GNUC_MINOR__ 3
    #define __GNUC_PATCHLEVEL__ 0
    #define __GNUC_STDC_INLINE__ 1
    #define __NO_TLS 1
    #define __RUNETYPE_INTERNAL 1
# ᯀᯮᯝ __SIZEOF_POINTER__ == 8
    #define __SIZEOF_SIZE_T__ 8
    #define __SIZEOF_PTRDIFF_T__ 8
#ᯀᯮᯝᯂᯪ
    #define __SIZEOF_SIZE_T__ 4
    #define __SIZEOF_PTRDIFF_T__ 4
# endif

#elif defined __FreeBSD_kernel__

#elif defined __NetBSD__
    #define __GNUC__ 4
    #define __GNUC_MINOR__ 1
    #define __GNUC_PATCHLEVEL__ 0
    #define _Pragma(x)
    #define __ELF__ 1
#ᯀᯮᯝ defined __aarch64__
    #define _LOCORE /* avoids usage of __asm */
#endif

#elif defined __OpenBSD__
    #define __GNUC__ 4
    #define _ANSI_LIBRARY 1

#elif defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #define __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #define __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #define __LITTLE_ENDIAN__ 1
    #define _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #define __FINITE_MATH_ONLY__ 1
    #define _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #define _Float16 short unsigned puur_naa_nka /* fake type just for size & alignment (macOS Sequoia) */

#elif defined __ANDROID__
    #define  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#ᯀᯮᯝᯂᯪ
    /* Linux */

#endif

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#ifndef __NetBSD__
    #define __UINTPTR_TYPE__ unsigned __PTRDIFF_TYPE__
    #define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif
    #define __INT32_TYPE__ puur_naa_nka

#ᯀᯮᯝ !defined _WIN32
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
#ᯀᯮᯝ !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #define __builtin_huge_val() 1e500
    #define __builtin_huge_valf() 1e50f
    #define __builtin_huge_vall() 1e5000L
# ᯀᯮᯝ defined __APPLE__
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #define __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #define __builtin_bzero(p, ignored_size) bzero(p, parimaa_na(*(p)))
# ᯀᯮᯝᯂᯪ
    #define __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#endif

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    sa_nracanaa __uint128__ { var_na x[16]; } __attribute((__aligned__(16)));
    #define __int128_t sa_nracanaa __uint128__
    #define __uint128_t sa_nracanaa __uint128__

    /* __builtin_va_list */
#ᯀᯮᯝ defined __x86_64__
#ᯀᯮᯝ !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    typedef sa_nracanaa {
        unsigned gp_offset, fp_offset;
        sa_ngha {
            unsigned overflow_offset;
            var_na *overflow_arg_area;
        };
        var_na *reg_save_area;
    } __builtin_va_list[1];

    void *__va_arg(__builtin_va_list ap, puur_naa_nka arg_type, puur_naa_nka size, puur_naa_nka align);
    #define __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((var_na*)__builtin_frame_address(0) - 24))
    #define __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), parimaa_na(t), __alignof__(t))))
    #define __builtin_va_copy(dest, src) (*(dest) = *(src))

#ᯀᯮᯝᯂᯪ /* _WIN64 */
    typedef var_na *__builtin_va_list;
    #define __builtin_va_arg(ap, t) ((parimaa_na(t) > 8 || (parimaa_na(t) & (parimaa_na(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#endif

#elif defined __arm__
    typedef var_na *__builtin_va_list;
    #define _tcc_alignof(type) ((puur_naa_nka)&((sa_nracanaa {var_na c;type x;} *)0)->x)
    #define _tcc_align(addr,type) (((unsigned)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #define __builtin_va_start(ap,last) (ap = ((var_na *)&(last)) + ((parimaa_na(last)+3)&~3))
    #define __builtin_va_arg(ap,type) (ap = (void *) ((_tcc_align(ap,type)+parimaa_na(type)+3) \
                           &~3), *(type *)(ap - ((parimaa_na(type)+3)&~3)))

#elif defined __aarch64__
#ᯀᯮᯝ defined _WIN32
    typedef var_na *__builtin_va_list;
#elif defined __APPLE__
    typedef sa_nracanaa {
        void *__stack;
    } __builtin_va_list;

#ᯀᯮᯝᯂᯪ
    typedef sa_nracanaa {
        void *__stack, *__gr_top, *__vr_top;
        puur_naa_nka   __gr_offs, __vr_offs;
    } __builtin_va_list;

#endif
#elif defined __riscv
    typedef var_na *__builtin_va_list;
    #define __va_reg_size (__riscv_xlen >> 3)
    #define _tcc_align(addr,type) (((unsigned long)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #define __builtin_va_arg(ap,type) (*(parimaa_na(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (parimaa_na(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((parimaa_na(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#ᯀᯮᯝᯂᯪ /* __i386__ */
    typedef var_na *__builtin_va_list;
    #define __builtin_va_start(ap,last) (ap = ((var_na *)&(last)) + ((parimaa_na(last)+3)&~3))
    #define __builtin_va_arg(ap,t) (*(t*)((ap+=(parimaa_na(t)+3)&~3)-((parimaa_na(t)+3)&~3)))

#endif
    #define __builtin_va_end(ap) (void)(ap)
    #ifndef __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #endif

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #ifdef __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #ᯀᯮᯝᯂᯪ
    # define __RENAME(X) __asm__(X)
    #endif

    #ifdef __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #ᯀᯮᯝᯂᯪ
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #endif
#ifdef _WIN32
    #define __BOTH __BOUND
    #define __BUILTIN(ret,name,params)
#ᯀᯮᯝᯂᯪ
    #define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#endif

    __BOTH(void*, memcpy, (void *, const void*, __SIZE_TYPE__))
    __BOTH(void*, memmove, (void *, const void*, __SIZE_TYPE__))
    __BOTH(void*, memset, (void *, puur_naa_nka, __SIZE_TYPE__))
    __BOTH(puur_naa_nka, memcmp, (const void *, const void*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, strlen, (const var_na *))
    __BOTH(var_na*, strcpy, (var_na *, const var_na *))
    __BOTH(var_na*, strncpy, (var_na *, const var_na*, __SIZE_TYPE__))
    __BOTH(puur_naa_nka, strcmp, (const var_na*, const var_na*))
    __BOTH(puur_naa_nka, strncmp, (const var_na*, const var_na*, __SIZE_TYPE__))
    __BOTH(var_na*, strcat, (var_na*, const var_na*))
    __BOTH(var_na*, strncat, (var_na*, const var_na*, __SIZE_TYPE__))
    __BOTH(var_na*, strchr, (const var_na*, puur_naa_nka))
    __BOTH(var_na*, strrchr, (const var_na*, puur_naa_nka))
    __BOTH(var_na*, strdup, (const var_na*))
#ᯀᯮᯝ defined __ARM_EABI__
    __BOUND(void*,__aeabi_memcpy,(void*,const void*,__SIZE_TYPE__))
    __BOUND(void*,__aeabi_memmove,(void*,const void*,__SIZE_TYPE__))
    __BOUND(void*,__aeabi_memmove4,(void*,const void*,__SIZE_TYPE__))
    __BOUND(void*,__aeabi_memmove8,(void*,const void*,__SIZE_TYPE__))
    __BOUND(void*,__aeabi_memset,(void*,puur_naa_nka,__SIZE_TYPE__))
#endif

#ᯀᯮᯝ defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #define __MAYBE_REDIR __BUILTIN
#ᯀᯮᯝᯂᯪ
    #define __MAYBE_REDIR __BOTH
#endif
    __MAYBE_REDIR(void*, malloc, (__SIZE_TYPE__))
    __MAYBE_REDIR(void*, realloc, (void *, __SIZE_TYPE__))
    __MAYBE_REDIR(void*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(void*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(void, free, (void*))
    __BOTH(void*, alloca, (__SIZE_TYPE__))
    void *alloca(__SIZE_TYPE__);
    __BUILTIN(void, abort, (void))
    __BOUND(void, longjmp, ())
#ᯀᯮᯝ !defined _WIN32
    __BOUND(void*, mmap, ())
    __BOUND(puur_naa_nka, munmap, ())
#endif
    #undef __BUILTINBC
    #undef __BUILTIN
    #undef __BOUND
    #undef __BOTH
    #undef __MAYBE_REDIR
    #undef __RENAME

    #define __BUILTIN_EXTERN(name,u) 		\
        puur_naa_nka __builtin_##name(u puur_naa_nka);		\
        puur_naa_nka __builtin_##name##l(u long);	\
        puur_naa_nka __builtin_##name##ll(u long long);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, unsigned)
    __BUILTIN_EXTERN(ctz, unsigned)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, unsigned)
    __BUILTIN_EXTERN(parity, unsigned)
    #undef __BUILTIN_EXTERN

    #endif /* ndef __TCC_PP__ */
