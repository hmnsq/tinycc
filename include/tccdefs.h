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

#यदि __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#यदि defined  __OpenBSD__
    #परिभाषय __SIZE_TYPE__ अचिह्नित दीर्घ
    #परिभाषय __PTRDIFF_TYPE__ दीर्घ
#अन्यथा
    #परिभाषय __SIZE_TYPE__ अचिह्नित पूर्णाङ्क
    #परिभाषय __PTRDIFF_TYPE__ पूर्णाङ्क
#यदि_अन्तः
    #परिभाषय __ILP32__ 1
    #परिभाषय __INT64_TYPE__ दीर्घ दीर्घ
#नोचेद्यदि __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #परिभाषय __SIZE_TYPE__ अचिह्नित दीर्घ दीर्घ
    #परिभाषय __PTRDIFF_TYPE__ दीर्घ दीर्घ
    #परिभाषय __LLP64__ 1
    #परिभाषय __INT64_TYPE__ दीर्घ दीर्घ
#अन्यथा
    /* Other 64bit systems. */
    #परिभाषय __SIZE_TYPE__ अचिह्नित दीर्घ
    #परिभाषय __PTRDIFF_TYPE__ दीर्घ
    #परिभाषय __LP64__ 1
# यदि defined __linux__
    #परिभाषय __INT64_TYPE__ दीर्घ
# अन्यथा /* APPLE, BSD */
    #परिभाषय __INT64_TYPE__ दीर्घ दीर्घ
# endif
#यदि_अन्तः
    #परिभाषय __SIZEOF_INT__ 4
    #परिभाषय __INT_MAX__ 0x7fffffff
#यदि __SIZEOF_LONG__ == 4
    #परिभाषय __LONG_MAX__ 0x7fffffffL
#अन्यथा
    #परिभाषय __LONG_MAX__ 0x7fffffffffffffffL
#यदि_अन्तः
    #परिभाषय __SIZEOF_LONG_LONG__ 8
    #परिभाषय __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #परिभाषय __CHAR_BIT__ 8
    #परिभाषय __ORDER_LITTLE_ENDIAN__ 1234
    #परिभाषय __ORDER_BIG_ENDIAN__ 4321
    #परिभाषय __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#यदि defined _WIN32
    #परिभाषय __WCHAR_TYPE__ अचिह्नित ह्रस्व
    #परिभाषय __WINT_TYPE__ अचिह्नित ह्रस्व
#नोचेद्यदि defined __linux__
    #परिभाषय __WCHAR_TYPE__ पूर्णाङ्क
    #परिभाषय __WINT_TYPE__ अचिह्नित पूर्णाङ्क
#अन्यथा
    #परिभाषय __WCHAR_TYPE__ पूर्णाङ्क
    #परिभाषय __WINT_TYPE__ पूर्णाङ्क
#यदि_अन्तः

    #यदि __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#यदि !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#यदि_अन्तः
    #यदि_अन्तः

#यदि defined _WIN32
    #परिभाषय __declspec(x) __attribute__((x))
    #परिभाषय __cdecl

#नोचेद्यदि defined __FreeBSD__
    #परिभाषय __GNUC__ 9
    #परिभाषय __GNUC_MINOR__ 3
    #परिभाषय __GNUC_PATCHLEVEL__ 0
    #परिभाषय __GNUC_STDC_INLINE__ 1
    #परिभाषय __NO_TLS 1
    #परिभाषय __RUNETYPE_INTERNAL 1
# यदि __SIZEOF_POINTER__ == 8
    #परिभाषय __SIZEOF_SIZE_T__ 8
    #परिभाषय __SIZEOF_PTRDIFF_T__ 8
#अन्यथा
    #परिभाषय __SIZEOF_SIZE_T__ 4
    #परिभाषय __SIZEOF_PTRDIFF_T__ 4
# endif

#नोचेद्यदि defined __FreeBSD_kernel__

#नोचेद्यदि defined __NetBSD__
    #परिभाषय __GNUC__ 4
    #परिभाषय __GNUC_MINOR__ 1
    #परिभाषय __GNUC_PATCHLEVEL__ 0
    #परिभाषय _Pragma(x)
    #परिभाषय __ELF__ 1
#यदि defined __aarch64__
    #परिभाषय _LOCORE /* avoids usage of __asm */
#यदि_अन्तः

#नोचेद्यदि defined __OpenBSD__
    #परिभाषय __GNUC__ 4
    #परिभाषय _ANSI_LIBRARY 1

#नोचेद्यदि defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #परिभाषय __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #परिभाषय __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #परिभाषय __LITTLE_ENDIAN__ 1
    #परिभाषय _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #परिभाषय __FINITE_MATH_ONLY__ 1
    #परिभाषय _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #परिभाषय _Float16 ह्रस्व अचिह्नित पूर्णाङ्क /* fake type just for size & alignment (macOS Sequoia) */

#नोचेद्यदि defined __ANDROID__
    #परिभाषय  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#अन्यथा
    /* Linux */

#यदि_अन्तः

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#यदि_अपरिभाषितम् __NetBSD__
    #परिभाषय __UINTPTR_TYPE__ अचिह्नित __PTRDIFF_TYPE__
    #परिभाषय __INTPTR_TYPE__ __PTRDIFF_TYPE__
#यदि_अन्तः
    #परिभाषय __INT32_TYPE__ पूर्णाङ्क

#यदि !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #परिभाषय __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #परिभाषय __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #परिभाषय __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#यदि_अन्तः

    /* not implemented */
    #परिभाषय  __PRETTY_FUNCTION__ __FUNCTION__
    #परिभाषय __has_builtin(x) 0
    #परिभाषय __has_feature(x) 0
    #परिभाषय __has_attribute(x) 0
    /* C23 Keywords */
    #परिभाषय _Nonnull
    #परिभाषय _Nullable
    #परिभाषय Nullable_परिणाम
    #परिभाषय _Null_unspecified

    /* skip __builtin... with -E */
    #यदि_अपरिभाषितम् __TCC_PP__

    #परिभाषय __builtin_offsetof(type, क्षेत्रम्) ((__SIZE_TYPE__)&((type*)0)->क्षेत्रम्)
    #परिभाषय __builtin_extract_return_addr(x) x
#यदि !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #परिभाषय __builtin_huge_val() 1e500
    #परिभाषय __builtin_huge_valf() 1e50f
    #परिभाषय __builtin_huge_vall() 1e5000L
# यदि defined __APPLE__
    #परिभाषय __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #परिभाषय __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #परिभाषय __builtin_bzero(p, ignored_आकार) bzero(p, परिमाण(*(p)))
# अन्यथा
    #परिभाषय __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#यदि_अन्तः

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    संरचना __uint128__ { वर्ण x[16]; } __attribute((__aligned__(16)));
    #परिभाषय __int128_t संरचना __uint128__
    #परिभाषय __uint128_t संरचना __uint128__

    /* __builtin_va_list */
#यदि defined __x86_64__
#यदि !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    प्रकारनिर्देश संरचना {
        अचिह्नित gp_विस्थापनम्, fp_विस्थापनम्;
        सङ्घ {
            अचिह्नित अतिप्रवाहः_विस्थापनम्;
            वर्ण *अतिप्रवाहः_arg_area;
        };
        वर्ण *reg_save_area;
    } __builtin_va_list[1];

    शून्य *__va_arg(__builtin_va_list ap, पूर्णाङ्क arg_type, पूर्णाङ्क आकार, पूर्णाङ्क align);
    #परिभाषय __builtin_va_start(ap, चरमः) \
       (*(ap) = *(__builtin_va_list)((वर्ण*)__builtin_frame_address(0) - 24))
    #परिभाषय __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), परिमाण(t), __alignof__(t))))
    #परिभाषय __builtin_va_copy(dest, src) (*(dest) = *(src))

#अन्यथा /* _WIN64 */
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #परिभाषय __builtin_va_arg(ap, t) ((परिमाण(t) > 8 || (परिमाण(t) & (परिमाण(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#यदि_अन्तः

#नोचेद्यदि defined __arm__
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #परिभाषय _tcc_alignof(type) ((पूर्णाङ्क)&((संरचना {वर्ण c;type x;} *)0)->x)
    #परिभाषय _tcc_align(addr,type) (((अचिह्नित)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #परिभाषय __builtin_va_start(ap,चरमः) (ap = ((वर्ण *)&(चरमः)) + ((परिमाण(चरमः)+3)&~3))
    #परिभाषय __builtin_va_arg(ap,type) (ap = (शून्य *) ((_tcc_align(ap,type)+परिमाण(type)+3) \
                           &~3), *(type *)(ap - ((परिमाण(type)+3)&~3)))

#नोचेद्यदि defined __aarch64__
#यदि defined _WIN32
    प्रकारनिर्देश वर्ण *__builtin_va_list;
#नोचेद्यदि defined __APPLE__
    प्रकारनिर्देश संरचना {
        शून्य *__stack;
    } __builtin_va_list;

#अन्यथा
    प्रकारनिर्देश संरचना {
        शून्य *__stack, *__gr_top, *__vr_top;
        पूर्णाङ्क   __gr_offs, __vr_offs;
    } __builtin_va_list;

#यदि_अन्तः
#नोचेद्यदि defined __riscv
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #परिभाषय __va_reg_size (__riscv_xlen >> 3)
    #परिभाषय _tcc_align(addr,type) (((अचिह्नित दीर्घ)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #परिभाषय __builtin_va_arg(ap,type) (*(परिमाण(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (va_list)(_tcc_align(ap,type) + (परिमाण(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((परिमाण(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#अन्यथा /* __i386__ */
    प्रकारनिर्देश वर्ण *__builtin_va_list;
    #परिभाषय __builtin_va_start(ap,चरमः) (ap = ((वर्ण *)&(चरमः)) + ((परिमाण(चरमः)+3)&~3))
    #परिभाषय __builtin_va_arg(ap,t) (*(t*)((ap+=(परिमाण(t)+3)&~3)-((परिमाण(t)+3)&~3)))

#यदि_अन्तः
    #परिभाषय __builtin_va_end(ap) (शून्य)(ap)
    #यदि_अपरिभाषितम् __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #यदि_अन्तः

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #यदि_परिभाषितम् __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #अन्यथा
    # define __RENAME(X) __asm__(X)
    #यदि_अन्तः

    #यदि_परिभाषितम् __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #अन्यथा
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #यदि_अन्तः
#यदि_परिभाषितम् _WIN32
    #परिभाषय __BOTH __BOUND
    #परिभाषय __BUILTIN(ret,name,params)
#अन्यथा
    #परिभाषय __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #परिभाषय __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#यदि_अन्तः

    __BOTH(शून्य*, स्मृतिं_प्रतिलिख, (शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(शून्य*, memmove, (शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(शून्य*, स्मृतिं_पूरय, (शून्य *, पूर्णाङ्क, __SIZE_TYPE__))
    __BOTH(पूर्णाङ्क, memcmp, (ध्रुव शून्य *, ध्रुव शून्य*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, वाक्यदैर्घ्यम्, (ध्रुव वर्ण *))
    __BOTH(वर्ण*, वाक्यं_प्रतिलिख, (वर्ण *, ध्रुव वर्ण *))
    __BOTH(वर्ण*, strncpy, (वर्ण *, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(पूर्णाङ्क, वाक्यं_तुलय, (ध्रुव वर्ण*, ध्रुव वर्ण*))
    __BOTH(पूर्णाङ्क, वाक्ये_तुलय, (ध्रुव वर्ण*, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(वर्ण*, वाक्यं_योजय, (वर्ण*, ध्रुव वर्ण*))
    __BOTH(वर्ण*, strncat, (वर्ण*, ध्रुव वर्ण*, __SIZE_TYPE__))
    __BOTH(वर्ण*, strchr, (ध्रुव वर्ण*, पूर्णाङ्क))
    __BOTH(वर्ण*, strrchr, (ध्रुव वर्ण*, पूर्णाङ्क))
    __BOTH(वर्ण*, strdup, (ध्रुव वर्ण*))
#यदि defined __ARM_EABI__
    __BOUND(शून्य*,__aeabi_memcpy,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove4,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memmove8,(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__))
    __BOUND(शून्य*,__aeabi_memset,(शून्य*,पूर्णाङ्क,__SIZE_TYPE__))
#यदि_अन्तः

#यदि defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #परिभाषय __MAYBE_REDIR __BUILTIN
#अन्यथा
    #परिभाषय __MAYBE_REDIR __BOTH
#यदि_अन्तः
    __MAYBE_REDIR(शून्य*, स्मृतिं_देहि, (__SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, realloc, (शून्य *, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, शून्यस्मृतिं_देहि, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(शून्य, मुक्त, (शून्य*))
    __BOTH(शून्य*, alloca, (__SIZE_TYPE__))
    शून्य *alloca(__SIZE_TYPE__);
    __BUILTIN(शून्य, abort, (शून्य))
    __BOUND(शून्य, longjmp, ())
#यदि !defined _WIN32
    __BOUND(शून्य*, mmap, ())
    __BOUND(पूर्णाङ्क, munmap, ())
#यदि_अन्तः
    #अपरिभाषय __BUILTINBC
    #अपरिभाषय __BUILTIN
    #अपरिभाषय __BOUND
    #अपरिभाषय __BOTH
    #अपरिभाषय __MAYBE_REDIR
    #अपरिभाषय __RENAME

    #परिभाषय __BUILTIN_EXTERN(name,u) 		\
        पूर्णाङ्क __builtin_##name(u पूर्णाङ्क);		\
        पूर्णाङ्क __builtin_##name##l(u दीर्घ);	\
        पूर्णाङ्क __builtin_##name##ll(u दीर्घ दीर्घ);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, अचिह्नित)
    __BUILTIN_EXTERN(ctz, अचिह्नित)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, अचिह्नित)
    __BUILTIN_EXTERN(parity, अचिह्नित)
    #अपरिभाषय __BUILTIN_EXTERN

    #यदि_अन्तः /* ndef __TCC_PP__ */
