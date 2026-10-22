/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#إذا 0

#تعریف_کن REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(خروج)\
 \
 REDIR(puts)\
 REDIR(چاپ_کن)\
 REDIR(حرف_چاپ_کن)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(طول_رشته)\
 REDIR(حافظه_بده)\
 REDIR(حرر)\

#إذا defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#پایان_اگر

#اگر_تعریف_شده __leading_underscore
# define _(s) "_"#s
#وإلا
# define _(s) #s
#پایان_اگر

#تعریف_کن REDIR(s) فراغ *s;
ساكن بنية { REDIR_ALL } all_ptrs;
#لغو_تعریف REDIR

#تعریف_کن REDIR(s) #s"\0"
ساكن ثابت حرف all_نامها[] = REDIR_ALL;
#لغو_تعریف REDIR

#إذا __aarch64__
  #إذا defined __TINYC__
  # define ALIGN ".align 8"
  #وإلا
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #پایان_اگر
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
#وإلا
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ساكن فراغ all_jmps() { REDIR_ALL }
#پایان_اگر
#لغو_تعریف REDIR

#إذا 0
# include <windows.h>
#وإلا
# إذا __i386__
#  define STDCALL __declspec(stdcall)
# وإلا
#  define STDCALL
# endif
# define DWORD دراز بیعلامت
# define HMODULE فراغ*
# define HANDLE فراغ*
S TDCALL HMODULE بارگیری_Library_A(ثابت حرف *);
S TDCALL HMODULE Get_Proc_آدرس(HMODULE , حرف*);
S TDCALL فراغ ExitProcess(صحيح);
S TDCALL صحيح WriteFile(HANDLE, ثابت فراغ*, DWORD, DWORD*, فراغ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL صحيح FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#پایان_اگر

ساكن فراغ eput(ثابت حرف *s)
{
    DWORD n_بیرون;
    صحيح n = 0;
    طالما (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_بیرون, 0);
}

ساكن فراغ rt_reloc()
{
    ثابت حرف *s = all_نامها;
    فراغ **p = (فراغ**)&all_ptrs;
    فراغ *dll = بارگیری_Library_A("msvcrt.dll");
    افعل {
        حرف buf[100], *d = buf;
        *p = (فراغ*)Get_Proc_آدرس(dll, (حرف*)s);
        *d++ = '_'; افعل *d++ = *s; طالما (*s++);
        إذا (0 == *p)
            *p = (فراغ*)Get_Proc_آدرس(dll, buf);
        إذا (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } طالما (*s);
}

#وإلا
# define rt_reloc()
#پایان_اگر

صحيح اصلی(صحيح argc, حرف **argv, حرف **env);
فراغ خروج(صحيح);
فراغ __set_app_type(صحيح apptype);

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __getmainargs(صحيح *pargc, حرف ***pargv, حرف ***penv, صحيح globb, _startupinfo*);

فراغ _controlfp(بیعلامت a, بیعلامت b);
#تعریف_کن _MCW_PC 0x00030000 // Precision Control
#تعریف_کن _PC_53 0x00010000 // 53 bits

صحيح __argc;
حرف **__argv;
حرف **environ;
_startupinfo شروع_info = {0};

فراغ mainCRTStartup(فراغ)
{
    rt_reloc();
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#پایان_اگر
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &شروع_info);
    خروج(اصلی(__argc, __argv, environ));
}

#ضمن <stdarg.h>
#تعریف_کن اندازه_t __SIZE_TYPE__
صحيح چاپ_کن(ثابت حرف *, ...);
صحيح _vsnprintf(حرف *, اندازه_t, ثابت حرف *, va_list);

/* undefined on windows-11-arm64 */
صحيح vprintf(ثابت حرف *format, va_list ap)
{
    حرف buf[1000];
    _vsnprintf(buf, حجم buf, format, ap);
    أرجع چاپ_کن("%s", buf);
}

فراغ __main() {} /* for gcc */
فراغ _pei386_runtime_relocator(فراغ) {} /* for gcc */
فراغ __chkstk(بیعلامت n) {} /* for clang */
