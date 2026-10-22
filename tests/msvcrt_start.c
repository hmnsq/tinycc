/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#जर 0

#define REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(निकास)\
 \
 REDIR(माला_दो)\
 REDIR(म_लिखो)\
 REDIR(अक्षर_दो)\
 REDIR(म_से_भग्न)\
 REDIR(स_रखो)\
 REDIR(म_नकल)\
 REDIR(म_माप)\
 REDIR(दो_स्मृति)\
 REDIR(मुक्त)\

#जर defined __i386__ && !defined __TINYC__
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
स्थिर स्थिरांक अक्षर all_names[] = REDIR_ALL;
#undef REDIR

#जर __aarch64__
  #जर defined __TINYC__
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

#जर 0
# include <windows.h>
#अन्यथा
# जर __i386__
#  define STDCALL __declspec(stdcall)
# अन्यथा
#  define STDCALL
# endif
# define DWORD दीर्घ अचिन्हित
# define HMODULE शून्य*
# define HANDLE शून्य*
S TDCALL HMODULE LoadLibraryA(स्थिरांक अक्षर *);
S TDCALL HMODULE GetProcAddress(HMODULE , अक्षर*);
S TDCALL शून्य ExitProcess(पूर्णांक);
S TDCALL पूर्णांक WriteFile(HANDLE, स्थिरांक शून्य*, DWORD, DWORD*, शून्य*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL पूर्णांक FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

स्थिर शून्य eput(स्थिरांक अक्षर *s)
{
    DWORD n_out;
    पूर्णांक n = 0;
    पर्यंत (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

स्थिर शून्य rt_reloc()
{
    स्थिरांक अक्षर *s = all_names;
    शून्य **p = (शून्य**)&all_ptrs;
    शून्य *dll = LoadLibraryA("msvcrt.dll");
    करा {
        अक्षर buf[100], *d = buf;
        *p = (शून्य*)GetProcAddress(dll, (अक्षर*)s);
        *d++ = '_'; करा *d++ = *s; पर्यंत (*s++);
        जर (0 == *p)
            *p = (शून्य*)GetProcAddress(dll, buf);
        जर (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } पर्यंत (*s);
}

#अन्यथा
# define rt_reloc()
#endif

पूर्णांक main(पूर्णांक argc, अक्षर **argv, अक्षर **env);
शून्य निकास(पूर्णांक);
शून्य __set_app_type(पूर्णांक apptype);

प्रकारव्याख्या संरचना { पूर्णांक newmode; } _startupinfo;
पूर्णांक __getmainargs(पूर्णांक *pargc, अक्षर ***pargv, अक्षर ***penv, पूर्णांक globb, _startupinfo*);

शून्य _controlfp(अचिन्हित a, अचिन्हित b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

पूर्णांक __argc;
अक्षर **__argv;
अक्षर **environ;
_startupinfo start_info = {0};

शून्य mainCRTStartup(शून्य)
{
    rt_reloc();
#जर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    निकास(main(__argc, __argv, environ));
}

#अन्तर्भाव <stdarg.h>
#define माप_प्रकार __SIZE_TYPE__
पूर्णांक म_लिखो(स्थिरांक अक्षर *, ...);
पूर्णांक _vsnprintf(अक्षर *, माप_प्रकार, स्थिरांक अक्षर *, बहु_सूची);

/* undefined on windows-11-arm64 */
पूर्णांक भ_लिखो(स्थिरांक अक्षर *format, बहु_सूची ap)
{
    अक्षर buf[1000];
    _vsnprintf(buf, आकार buf, format, ap);
    परत म_लिखो("%s", buf);
}

शून्य __main() {} /* for gcc */
शून्य _pei386_runtime_relocator(शून्य) {} /* for gcc */
शून्य __chkstk(अचिन्हित n) {} /* for clang */
