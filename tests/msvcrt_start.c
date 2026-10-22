/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#यदि 0

#define REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(exit)\
 \
 REDIR(puts)\
 REDIR(printf)\
 REDIR(putchar)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(strlen)\
 REDIR(malloc)\
 REDIR(मुक्त)\

#यदि defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#अन्यथा
# define _(s) #s
#endif

#define REDIR(s) शून्य *s;
स्थिर संरचना { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
स्थिर ध्रुव वर्ण all_names[] = REDIR_ALL;
#undef REDIR

#यदि __aarch64__
  #यदि defined __TINYC__
  # define ALIGN ".align 8"
  #अन्यथा
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #endif
# define REDIR(s) \
    __asm__("\n"_(s)":"); \
    __asm__(".int 0x58000090"); /* ldr x16, [pc, #16] */ \
    __asm__(".int 0xf9400210"); /* ldr x16, [x16] */ \
    __asm__(".int 0xd61f0200"); /* br x16 */ \
    __asm__(".int 0xd503201f"); /* nop for alignment */ \
    __asm__(".quad all_ptrs + (. - all_jmps - 16) / 24 * 8"); \
    __asm__(".global "_(s));

    __asm__("\t.text\n\t"ALIGN"\nall_jmps:");
    REDIR_ALL
#अन्यथा
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    स्थिर शून्य all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#यदि 0
# include <windows.h>
#अन्यथा
# यदि __i386__
#  define STDCALL __declspec(stdcall)
# अन्यथा
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE शून्य*
# define HANDLE शून्य*
S TDCALL HMODULE LoadLibraryA(ध्रुव वर्ण *);
S TDCALL HMODULE GetProcAddress(HMODULE , वर्ण*);
S TDCALL शून्य ExitProcess(पूर्णाङ्क);
S TDCALL पूर्णाङ्क WriteFile(HANDLE, ध्रुव शून्य*, DWORD, DWORD*, शून्य*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL पूर्णाङ्क FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

स्थिर शून्य eput(ध्रुव वर्ण *s)
{
    DWORD n_out;
    पूर्णाङ्क n = 0;
    यावत् (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

स्थिर शून्य rt_reloc()
{
    ध्रुव वर्ण *s = all_names;
    शून्य **p = (शून्य**)&all_ptrs;
    शून्य *dll = LoadLibraryA("msvcrt.dll");
    कुरु {
        वर्ण buf[100], *d = buf;
        *p = (शून्य*)GetProcAddress(dll, (वर्ण*)s);
        *d++ = '_'; कुरु *d++ = *s; यावत् (*s++);
        यदि (0 == *p)
            *p = (शून्य*)GetProcAddress(dll, buf);
        यदि (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } यावत् (*s);
}

#अन्यथा
# define rt_reloc()
#endif

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv, वर्ण **env);
शून्य exit(पूर्णाङ्क);
शून्य __set_app_type(पूर्णाङ्क apptype);

प्रकारनिर्देश संरचना { पूर्णाङ्क newmode; } _startupinfo;
पूर्णाङ्क __getmainargs(पूर्णाङ्क *pargc, वर्ण ***pargv, वर्ण ***penv, पूर्णाङ्क globb, _startupinfo*);

शून्य _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

पूर्णाङ्क __argc;
वर्ण **__argv;
वर्ण **environ;
_startupinfo start_info = {0};

शून्य mainCRTStartup(शून्य)
{
    rt_reloc();
#यदि defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(main(__argc, __argv, environ));
}

#अन्तर्भाव <stdarg.h>
#define size_t __SIZE_TYPE__
पूर्णाङ्क printf(ध्रुव वर्ण *, ...);
पूर्णाङ्क _vsnprintf(वर्ण *, size_t, ध्रुव वर्ण *, va_list);

/* undefined on windows-11-arm64 */
पूर्णाङ्क vprintf(ध्रुव वर्ण *format, va_list ap)
{
    वर्ण buf[1000];
    _vsnprintf(buf, परिमाण buf, format, ap);
    प्रत्यागम printf("%s", buf);
}

शून्य __main() {} /* for gcc */
शून्य _pei386_runtime_relocator(शून्य) {} /* for gcc */
शून्य __chkstk(unsigned n) {} /* for clang */
