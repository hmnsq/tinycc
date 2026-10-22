/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#यदि 0

#परिभाषय REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(निर्गच्छ)\
 \
 REDIR(पङ्क्तिं_लिख)\
 REDIR(प्रारूप_लिख)\
 REDIR(अक्षरं_लिख)\
 REDIR(strtod)\
 REDIR(स्मृतिं_पूरय)\
 REDIR(वाक्यं_प्रतिलिख)\
 REDIR(वाक्यदैर्घ्यम्)\
 REDIR(स्मृतिं_देहि)\
 REDIR(मुक्त)\

#यदि defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#यदि_अन्तः

#यदि_परिभाषितम् __leading_underscore
# define _(s) "_"#s
#अन्यथा
# define _(s) #s
#यदि_अन्तः

#परिभाषय REDIR(s) शून्य *s;
स्थिर संरचना { REDIR_ALL } all_ptrs;
#अपरिभाषय REDIR

#परिभाषय REDIR(s) #s"\0"
स्थिर ध्रुव वर्ण all_नामानि[] = REDIR_ALL;
#अपरिभाषय REDIR

#यदि __aarch64__
  #यदि defined __TINYC__
  # define ALIGN ".align 8"
  #अन्यथा
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #यदि_अन्तः
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
#यदि_अन्तः
#अपरिभाषय REDIR

#यदि 0
# include <windows.h>
#अन्यथा
# यदि __i386__
#  define STDCALL __declspec(stdcall)
# अन्यथा
#  define STDCALL
# endif
# define DWORD दीर्घ अचिह्नित
# define HMODULE शून्य*
# define HANDLE शून्य*
S TDCALL HMODULE आरोपय_Library_A(ध्रुव वर्ण *);
S TDCALL HMODULE Get_Proc_स्थानाङ्कः(HMODULE , वर्ण*);
S TDCALL शून्य ExitProcess(पूर्णाङ्क);
S TDCALL पूर्णाङ्क WriteFile(HANDLE, ध्रुव शून्य*, DWORD, DWORD*, शून्य*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL पूर्णाङ्क FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#यदि_अन्तः

स्थिर शून्य eput(ध्रुव वर्ण *s)
{
    DWORD n_बहिर्गमनम्;
    पूर्णाङ्क n = 0;
    यावत् (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_बहिर्गमनम्, 0);
}

स्थिर शून्य rt_reloc()
{
    ध्रुव वर्ण *s = all_नामानि;
    शून्य **p = (शून्य**)&all_ptrs;
    शून्य *dll = आरोपय_Library_A("msvcrt.dll");
    कुरु {
        वर्ण buf[100], *d = buf;
        *p = (शून्य*)Get_Proc_स्थानाङ्कः(dll, (वर्ण*)s);
        *d++ = '_'; कुरु *d++ = *s; यावत् (*s++);
        यदि (0 == *p)
            *p = (शून्य*)Get_Proc_स्थानाङ्कः(dll, buf);
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
#यदि_अन्तः

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv, वर्ण **env);
शून्य निर्गच्छ(पूर्णाङ्क);
शून्य __set_app_type(पूर्णाङ्क apptype);

प्रकारनिर्देश संरचना { पूर्णाङ्क newmode; } _startupinfo;
पूर्णाङ्क __getmainargs(पूर्णाङ्क *pargc, वर्ण ***pargv, वर्ण ***penv, पूर्णाङ्क globb, _startupinfo*);

शून्य _controlfp(अचिह्नित a, अचिह्नित b);
#परिभाषय _MCW_PC 0x00030000 // Precision Control
#परिभाषय _PC_53 0x00010000 // 53 bits

पूर्णाङ्क __argc;
वर्ण **__argv;
वर्ण **environ;
_startupinfo start_info = {0};

शून्य mainCRTStartup(शून्य)
{
    rt_reloc();
#यदि defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#यदि_अन्तः
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    निर्गच्छ(मुख्यम्(__argc, __argv, environ));
}

#अन्तर्भाव <stdarg.h>
#परिभाषय आकार_t __SIZE_TYPE__
पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण *, ...);
पूर्णाङ्क _vsnprintf(वर्ण *, आकार_t, ध्रुव वर्ण *, va_list);

/* undefined on windows-11-arm64 */
पूर्णाङ्क vprintf(ध्रुव वर्ण *format, va_list ap)
{
    वर्ण buf[1000];
    _vsnprintf(buf, परिमाण buf, format, ap);
    प्रत्यागम प्रारूप_लिख("%s", buf);
}

शून्य __main() {} /* for gcc */
शून्य _pei386_runtime_relocator(शून्य) {} /* for gcc */
शून्य __chkstk(अचिह्नित n) {} /* for clang */
