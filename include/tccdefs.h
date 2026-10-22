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

#अगर __SIZEOF_POINTER__ == 4
    /* 32bit systems. */
#अगर defined  __OpenBSD__
    #घोषणा __SIZE_TYPE__ अचिन्हित दीर्घ
    #घोषणा __PTRDIFF_TYPE__ दीर्घ
#अन्यथा
    #घोषणा __SIZE_TYPE__ अचिन्हित पूर्णांक
    #घोषणा __PTRDIFF_TYPE__ पूर्णांक
#पूर्ण_अगर
    #घोषणा __ILP32__ 1
    #घोषणा __INT64_TYPE__ दीर्घ दीर्घ
#या_अगर __SIZEOF_LONG__ == 4
    /* 64bit Windows. */
    #घोषणा __SIZE_TYPE__ अचिन्हित दीर्घ दीर्घ
    #घोषणा __PTRDIFF_TYPE__ दीर्घ दीर्घ
    #घोषणा __LLP64__ 1
    #घोषणा __INT64_TYPE__ दीर्घ दीर्घ
#अन्यथा
    /* Other 64bit systems. */
    #घोषणा __SIZE_TYPE__ अचिन्हित दीर्घ
    #घोषणा __PTRDIFF_TYPE__ दीर्घ
    #घोषणा __LP64__ 1
# अगर defined __linux__
    #घोषणा __INT64_TYPE__ दीर्घ
# अन्यथा /* APPLE, BSD */
    #घोषणा __INT64_TYPE__ दीर्घ दीर्घ
# endif
#पूर्ण_अगर
    #घोषणा __SIZEOF_INT__ 4
    #घोषणा __INT_MAX__ 0x7fffffff
#अगर __SIZEOF_LONG__ == 4
    #घोषणा __LONG_MAX__ 0x7fffffffL
#अन्यथा
    #घोषणा __LONG_MAX__ 0x7fffffffffffffffL
#पूर्ण_अगर
    #घोषणा __SIZEOF_LONG_LONG__ 8
    #घोषणा __LONG_LONG_MAX__ 0x7fffffffffffffffLL
    #घोषणा __CHAR_BIT__ 8
    #घोषणा __ORDER_LITTLE_ENDIAN__ 1234
    #घोषणा __ORDER_BIG_ENDIAN__ 4321
    #घोषणा __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#अगर defined _WIN32
    #घोषणा __WCHAR_TYPE__ अचिन्हित लघु
    #घोषणा __WINT_TYPE__ अचिन्हित लघु
#या_अगर defined __linux__
    #घोषणा __WCHAR_TYPE__ पूर्णांक
    #घोषणा __WINT_TYPE__ अचिन्हित पूर्णांक
#अन्यथा
    #घोषणा __WCHAR_TYPE__ पूर्णांक
    #घोषणा __WINT_TYPE__ पूर्णांक
#पूर्ण_अगर

    #अगर __STDC_VERSION__ >= 201112L
    # define __STDC_NO_ATOMICS__ 1
    # define __STDC_NO_COMPLEX__ 1
    # define __STDC_NO_THREADS__ 1
#अगर !defined _WIN32
    # define __STDC_UTF_16__ 1
    # define __STDC_UTF_32__ 1
#पूर्ण_अगर
    #पूर्ण_अगर

#अगर defined _WIN32
    #घोषणा __declspec(x) __attribute__((x))
    #घोषणा __cdecl

#या_अगर defined __FreeBSD__
    #घोषणा __GNUC__ 9
    #घोषणा __GNUC_MINOR__ 3
    #घोषणा __GNUC_PATCHLEVEL__ 0
    #घोषणा __GNUC_STDC_INLINE__ 1
    #घोषणा __NO_TLS 1
    #घोषणा __RUNETYPE_INTERNAL 1
# अगर __SIZEOF_POINTER__ == 8
    #घोषणा __SIZEOF_SIZE_T__ 8
    #घोषणा __SIZEOF_PTRDIFF_T__ 8
#अन्यथा
    #घोषणा __SIZEOF_SIZE_T__ 4
    #घोषणा __SIZEOF_PTRDIFF_T__ 4
# endif

#या_अगर defined __FreeBSD_kernel__

#या_अगर defined __NetBSD__
    #घोषणा __GNUC__ 4
    #घोषणा __GNUC_MINOR__ 1
    #घोषणा __GNUC_PATCHLEVEL__ 0
    #घोषणा _Pragma(x)
    #घोषणा __ELF__ 1
#अगर defined __aarch64__
    #घोषणा _LOCORE /* avoids usage of __asm */
#पूर्ण_अगर

#या_अगर defined __OpenBSD__
    #घोषणा __GNUC__ 4
    #घोषणा _ANSI_LIBRARY 1

#या_अगर defined __APPLE__
    /* emulate APPLE-GCC to make libc's headerfiles compile: */
    #घोषणा __GNUC__ 4   /* darwin emits warning on GCC<4 */
    #घोषणा __APPLE_CC__ 1 /* for <TargetConditionals.h> */
    #घोषणा __LITTLE_ENDIAN__ 1
    #घोषणा _DONT_USE_CTYPE_INLINE_ 1
    /* avoids usage of GCC/clang specific builtins in libc-headerfiles: */
    #घोषणा __FINITE_MATH_ONLY__ 1
    #घोषणा _FORTIFY_SOURCE 0
    //#define __has_builtin(x) 0
    #घोषणा _Float16 लघु अचिन्हित पूर्णांक /* fake type just for size & alignment (macOS Sequoia) */

#या_अगर defined __ANDROID__
    #घोषणा  BIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD

#अन्यथा
    /* Linux */

#पूर्ण_अगर

    /* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#अगर_अघोषित __NetBSD__
    #घोषणा __UINTPTR_TYPE__ अचिन्हित __PTRDIFF_TYPE__
    #घोषणा __INTPTR_TYPE__ __PTRDIFF_TYPE__
#पूर्ण_अगर
    #घोषणा __INT32_TYPE__ पूर्णांक

#अगर !defined _WIN32
    /* glibc defines. We do not support __USER_NAME_PREFIX__ */
    #घोषणा __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
    #घोषणा __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
    #घोषणा __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL
#पूर्ण_अगर

    /* not implemented */
    #घोषणा  __PRETTY_FUNCTION__ __FUNCTION__
    #घोषणा __has_builtin(x) 0
    #घोषणा __has_feature(x) 0
    #घोषणा __has_attribute(x) 0
    /* C23 Keywords */
    #घोषणा _Nonnull
    #घोषणा _Nullable
    #घोषणा Nullable_परिणाम
    #घोषणा _Null_unspecified

    /* skip __builtin... with -E */
    #अगर_अघोषित __TCC_PP__

    #घोषणा __builtin_offsetof(type, field) ((__SIZE_TYPE__)&((type*)0)->field)
    #घोषणा __builtin_extract_return_addr(x) x
#अगर !defined __linux__ && !defined _WIN32
    /* used by math.h */
    #घोषणा __builtin_huge_val() 1e500
    #घोषणा __builtin_huge_valf() 1e50f
    #घोषणा __builtin_huge_vall() 1e5000L
# अगर defined __APPLE__
    #घोषणा __builtin_nanf(ignored_string) (0.0F/0.0F)
    /* used by floats.h to implement FLT_ROUNDS C99 macro. 1 == to nearest */
    #घोषणा __builtin_flt_rounds() 1
    /* used by _fd_def.h */
    #घोषणा __builtin_bzero(p, ignored_आकार) bzero(p, माप(*(p)))
# अन्यथा
    #घोषणा __builtin_nanf(ignored_string) (0.0F/0.0F)
# endif
#पूर्ण_अगर

    /* GCC's __uint128_t appears in some Linux/OSX header files.
       Just make it some type with same size and alignment. */
    काष्ठा __uint128__ { अक्षर x[16]; } __attribute((__aligned__(16)));
    #घोषणा __int128_t काष्ठा __uint128__
    #घोषणा __uint128_t काष्ठा __uint128__

    /* __builtin_va_list */
#अगर defined __x86_64__
#अगर !defined _WIN32
    /* GCC compatible definition of va_list. */
    /* This should be in sync with the declaration in our lib/va_list.c */
    प्रकार काष्ठा {
        अचिन्हित gp_offset, fp_offset;
        जोड़ {
            अचिन्हित overflow_offset;
            अक्षर *overflow_arg_area;
        };
        अक्षर *reg_save_area;
    } __builtin_va_list[1];

    व्योम *__va_arg(__builtin_va_list ap, पूर्णांक arg_type, पूर्णांक आकार, पूर्णांक align);
    #घोषणा __builtin_va_start(ap, last) \
       (*(ap) = *(__builtin_va_list)((अक्षर*)__builtin_frame_address(0) - 24))
    #घोषणा __builtin_va_arg(ap, t)   \
       (*(t *)(__va_arg(ap, __builtin_va_arg_types(t), माप(t), __alignof__(t))))
    #घोषणा __builtin_va_copy(dest, src) (*(dest) = *(src))

#अन्यथा /* _WIN64 */
    प्रकार अक्षर *__builtin_va_list;
    #घोषणा __builtin_va_arg(ap, t) ((माप(t) > 8 || (माप(t) & (माप(t) - 1))) \
        ? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#पूर्ण_अगर

#या_अगर defined __arm__
    प्रकार अक्षर *__builtin_va_list;
    #घोषणा _tcc_alignof(type) ((पूर्णांक)&((काष्ठा {अक्षर c;type x;} *)0)->x)
    #घोषणा _tcc_align(addr,type) (((अचिन्हित)addr + _tcc_alignof(type) - 1) \
                                  & ~(_tcc_alignof(type) - 1))
    #घोषणा __builtin_va_start(ap,last) (ap = ((अक्षर *)&(last)) + ((माप(last)+3)&~3))
    #घोषणा __builtin_va_arg(ap,type) (ap = (व्योम *) ((_tcc_align(ap,type)+माप(type)+3) \
                           &~3), *(type *)(ap - ((माप(type)+3)&~3)))

#या_अगर defined __aarch64__
#अगर defined _WIN32
    प्रकार अक्षर *__builtin_va_list;
#या_अगर defined __APPLE__
    प्रकार काष्ठा {
        व्योम *__stack;
    } __builtin_va_list;

#अन्यथा
    प्रकार काष्ठा {
        व्योम *__stack, *__gr_top, *__vr_top;
        पूर्णांक   __gr_offs, __vr_offs;
    } __builtin_va_list;

#पूर्ण_अगर
#या_अगर defined __riscv
    प्रकार अक्षर *__builtin_va_list;
    #घोषणा __va_reg_size (__riscv_xlen >> 3)
    #घोषणा _tcc_align(addr,type) (((अचिन्हित दीर्घ)addr + __alignof__(type) - 1) \
                                  & -(__alignof__(type)))
    #घोषणा __builtin_va_arg(ap,type) (*(माप(type) > (2*__va_reg_size) ? *(type **)((ap += __va_reg_size) - __va_reg_size) : (ap = (बहु_सूची)(_tcc_align(ap,type) + (माप(type)+__va_reg_size - 1)& -__va_reg_size), (type *)(ap - ((माप(type)+ __va_reg_size - 1)& -__va_reg_size)))))

#अन्यथा /* __i386__ */
    प्रकार अक्षर *__builtin_va_list;
    #घोषणा __builtin_va_start(ap,last) (ap = ((अक्षर *)&(last)) + ((माप(last)+3)&~3))
    #घोषणा __builtin_va_arg(ap,t) (*(t*)((ap+=(माप(t)+3)&~3)-((माप(t)+3)&~3)))

#पूर्ण_अगर
    #घोषणा __builtin_va_end(ap) (व्योम)(ap)
    #अगर_अघोषित __builtin_va_copy
    # define __builtin_va_copy(dest, src) (dest) = (src)
    #पूर्ण_अगर

    /* TCC BBUILTIN AND BOUNDS ALIASES */
    #अगर_घोषित __leading_underscore
    # define __RENAME(X) __asm__("_"X)
    #अन्यथा
    # define __RENAME(X) __asm__(X)
    #पूर्ण_अगर

    #अगर_घोषित __TCC_BCHECK__
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
    # define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
    #अन्यथा
    # define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
    # define __BOUND(ret,name,params)
    #पूर्ण_अगर
#अगर_घोषित _WIN32
    #घोषणा __BOTH __BOUND
    #घोषणा __BUILTIN(ret,name,params)
#अन्यथा
    #घोषणा __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
    #घोषणा __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);
#पूर्ण_अगर

    __BOTH(व्योम*, स_नकल, (व्योम *, स्थिर व्योम*, __SIZE_TYPE__))
    __BOTH(व्योम*, स_हटाओ, (व्योम *, स्थिर व्योम*, __SIZE_TYPE__))
    __BOTH(व्योम*, स_रखो, (व्योम *, पूर्णांक, __SIZE_TYPE__))
    __BOTH(पूर्णांक, स_भेद, (स्थिर व्योम *, स्थिर व्योम*, __SIZE_TYPE__))
    __BOTH(__SIZE_TYPE__, म_माप, (स्थिर अक्षर *))
    __BOTH(अक्षर*, म_नकल, (अक्षर *, स्थिर अक्षर *))
    __BOTH(अक्षर*, म_नकलन, (अक्षर *, स्थिर अक्षर*, __SIZE_TYPE__))
    __BOTH(पूर्णांक, म_भेद, (स्थिर अक्षर*, स्थिर अक्षर*))
    __BOTH(पूर्णांक, म_भेदन, (स्थिर अक्षर*, स्थिर अक्षर*, __SIZE_TYPE__))
    __BOTH(अक्षर*, म_जोड़ो, (अक्षर*, स्थिर अक्षर*))
    __BOTH(अक्षर*, म_जोड़न, (अक्षर*, स्थिर अक्षर*, __SIZE_TYPE__))
    __BOTH(अक्षर*, म_अक्षर, (स्थिर अक्षर*, पूर्णांक))
    __BOTH(अक्षर*, म_खोजप, (स्थिर अक्षर*, पूर्णांक))
    __BOTH(अक्षर*, strdup, (स्थिर अक्षर*))
#अगर defined __ARM_EABI__
    __BOUND(व्योम*,__aeabi_memcpy,(व्योम*,स्थिर व्योम*,__SIZE_TYPE__))
    __BOUND(व्योम*,__aeabi_memmove,(व्योम*,स्थिर व्योम*,__SIZE_TYPE__))
    __BOUND(व्योम*,__aeabi_memmove4,(व्योम*,स्थिर व्योम*,__SIZE_TYPE__))
    __BOUND(व्योम*,__aeabi_memmove8,(व्योम*,स्थिर व्योम*,__SIZE_TYPE__))
    __BOUND(व्योम*,__aeabi_memset,(व्योम*,पूर्णांक,__SIZE_TYPE__))
#पूर्ण_अगर

#अगर defined __linux__ || defined __APPLE__ // HAVE MALLOC_REDIR
    #घोषणा __MAYBE_REDIR __BUILTIN
#अन्यथा
    #घोषणा __MAYBE_REDIR __BOTH
#पूर्ण_अगर
    __MAYBE_REDIR(व्योम*, दो_स्मृति, (__SIZE_TYPE__))
    __MAYBE_REDIR(व्योम*, पुनः_स्मृति, (व्योम *, __SIZE_TYPE__))
    __MAYBE_REDIR(व्योम*, सुस्मृति, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(व्योम*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
    __MAYBE_REDIR(व्योम, मुक्त, (व्योम*))
    __BOTH(व्योम*, alloca, (__SIZE_TYPE__))
    व्योम *alloca(__SIZE_TYPE__);
    __BUILTIN(व्योम, पात, (व्योम))
    __BOUND(व्योम, दीर्घ_लाँघ, ())
#अगर !defined _WIN32
    __BOUND(व्योम*, mmap, ())
    __BOUND(पूर्णांक, munmap, ())
#पूर्ण_अगर
    #अघोषित __BUILTINBC
    #अघोषित __BUILTIN
    #अघोषित __BOUND
    #अघोषित __BOTH
    #अघोषित __MAYBE_REDIR
    #अघोषित __RENAME

    #घोषणा __BUILTIN_EXTERN(name,u) 		\
        पूर्णांक __builtin_##name(u पूर्णांक);		\
        पूर्णांक __builtin_##name##l(u दीर्घ);	\
        पूर्णांक __builtin_##name##ll(u दीर्घ दीर्घ);
    __BUILTIN_EXTERN(ffs,)
    __BUILTIN_EXTERN(clz, अचिन्हित)
    __BUILTIN_EXTERN(ctz, अचिन्हित)
    __BUILTIN_EXTERN(clrsb,)
    __BUILTIN_EXTERN(popcount, अचिन्हित)
    __BUILTIN_EXTERN(parity, अचिन्हित)
    #अघोषित __BUILTIN_EXTERN

    #पूर्ण_अगर /* ndef __TCC_PP__ */
