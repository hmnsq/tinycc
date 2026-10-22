/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#अगर 0

#घोषणा REDIR_ALL \
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

#अगर defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#पूर्ण_अगर

#अगर_घोषित __leading_underscore
# define _(s) "_"#s
#अन्यथा
# define _(s) #s
#पूर्ण_अगर

#घोषणा REDIR(s) व्योम *s;
अटल काष्ठा { REDIR_ALL } all_ptrs;
#अघोषित REDIR

#घोषणा REDIR(s) #s"\0"
अटल स्थिर अक्षर all_names[] = REDIR_ALL;
#अघोषित REDIR

#अगर __aarch64__
  #अगर defined __TINYC__
  # define ALIGN ".align 8"
  #अन्यथा
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #पूर्ण_अगर
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

    अटल व्योम all_jmps() { REDIR_ALL }
#पूर्ण_अगर
#अघोषित REDIR

#अगर 0
# include <windows.h>
#अन्यथा
# अगर __i386__
#  define STDCALL __declspec(stdcall)
# अन्यथा
#  define STDCALL
# endif
# define DWORD दीर्घ अचिन्हित
# define HMODULE व्योम*
# define HANDLE व्योम*
S TDCALL HMODULE LoadLibraryA(स्थिर अक्षर *);
S TDCALL HMODULE GetProcAddress(HMODULE , अक्षर*);
S TDCALL व्योम ExitProcess(पूर्णांक);
S TDCALL पूर्णांक WriteFile(HANDLE, स्थिर व्योम*, DWORD, DWORD*, व्योम*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL पूर्णांक FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#पूर्ण_अगर

अटल व्योम eput(स्थिर अक्षर *s)
{
    DWORD n_out;
    पूर्णांक n = 0;
    जबतक (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

अटल व्योम rt_reloc()
{
    स्थिर अक्षर *s = all_names;
    व्योम **p = (व्योम**)&all_ptrs;
    व्योम *dll = LoadLibraryA("msvcrt.dll");
    करो {
        अक्षर buf[100], *d = buf;
        *p = (व्योम*)GetProcAddress(dll, (अक्षर*)s);
        *d++ = '_'; करो *d++ = *s; जबतक (*s++);
        अगर (0 == *p)
            *p = (व्योम*)GetProcAddress(dll, buf);
        अगर (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } जबतक (*s);
}

#अन्यथा
# define rt_reloc()
#पूर्ण_अगर

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv, अक्षर **env);
व्योम निकास(पूर्णांक);
व्योम __set_app_type(पूर्णांक apptype);

प्रकार काष्ठा { पूर्णांक newmode; } _startupinfo;
पूर्णांक __getmainargs(पूर्णांक *pargc, अक्षर ***pargv, अक्षर ***penv, पूर्णांक globb, _startupinfo*);

व्योम _controlfp(अचिन्हित a, अचिन्हित b);
#घोषणा _MCW_PC 0x00030000 // Precision Control
#घोषणा _PC_53 0x00010000 // 53 bits

पूर्णांक __argc;
अक्षर **__argv;
अक्षर **environ;
_startupinfo start_info = {0};

व्योम mainCRTStartup(व्योम)
{
    rt_reloc();
#अगर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#पूर्ण_अगर
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    निकास(मुख्य(__argc, __argv, environ));
}

#समावेश <stdarg.h>
#घोषणा माप_प्रकार __SIZE_TYPE__
पूर्णांक म_लिखो(स्थिर अक्षर *, ...);
पूर्णांक _vsnprintf(अक्षर *, माप_प्रकार, स्थिर अक्षर *, बहु_सूची);

/* undefined on windows-11-arm64 */
पूर्णांक भ_लिखो(स्थिर अक्षर *format, बहु_सूची ap)
{
    अक्षर buf[1000];
    _vsnprintf(buf, माप buf, format, ap);
    वापस म_लिखो("%s", buf);
}

व्योम __main() {} /* for gcc */
व्योम _pei386_runtime_relocator(व्योम) {} /* for gcc */
व्योम __chkstk(अचिन्हित n) {} /* for clang */
