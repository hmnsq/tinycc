/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#إذا 0

#تعریف_کرو REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(باہر_نکلو)\
 \
 REDIR(puts)\
 REDIR(لکھو)\
 REDIR(حرف_لکھو)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(لڑی_لمبائی)\
 REDIR(حافظہ_دیو)\
 REDIR(حرر)\

#إذا defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#جے_انت

#جے_تعریف_شدہ __leading_underscore
# define _(s) "_"#s
#وإلا
# define _(s) #s
#جے_انت

#تعریف_کرو REDIR(s) فراغ *s;
ساكن بنية { REDIR_ALL } all_ptrs;
#تعریف_رد REDIR

#تعریف_کرو REDIR(s) #s"\0"
ساكن ثابت حرف all_ناں[] = REDIR_ALL;
#تعریف_رد REDIR

#إذا __aarch64__
  #إذا defined __TINYC__
  # define ALIGN ".align 8"
  #وإلا
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #جے_انت
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
#جے_انت
#تعریف_رد REDIR

#إذا 0
# include <windows.h>
#وإلا
# إذا __i386__
#  define STDCALL __declspec(stdcall)
# وإلا
#  define STDCALL
# endif
# define DWORD لما بنانشانی
# define HMODULE فراغ*
# define HANDLE فراغ*
S TDCALL HMODULE لدو_Library_A(ثابت حرف *);
S TDCALL HMODULE Get_Proc_پتہ(HMODULE , حرف*);
S TDCALL فراغ ExitProcess(صحيح);
S TDCALL صحيح WriteFile(HANDLE, ثابت فراغ*, DWORD, DWORD*, فراغ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL صحيح FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#جے_انت

ساكن فراغ eput(ثابت حرف *s)
{
    DWORD n_باہرلا;
    صحيح n = 0;
    طالما (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_باہرلا, 0);
}

ساكن فراغ rt_reloc()
{
    ثابت حرف *s = all_ناں;
    فراغ **p = (فراغ**)&all_ptrs;
    فراغ *dll = لدو_Library_A("msvcrt.dll");
    افعل {
        حرف buf[100], *d = buf;
        *p = (فراغ*)Get_Proc_پتہ(dll, (حرف*)s);
        *d++ = '_'; افعل *d++ = *s; طالما (*s++);
        إذا (0 == *p)
            *p = (فراغ*)Get_Proc_پتہ(dll, buf);
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
#جے_انت

صحيح مکھ(صحيح argc, حرف **argv, حرف **env);
فراغ باہر_نکلو(صحيح);
فراغ __set_app_type(صحيح apptype);

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __getmainargs(صحيح *pargc, حرف ***pargv, حرف ***penv, صحيح globb, _startupinfo*);

فراغ _controlfp(بنانشانی a, بنانشانی b);
#تعریف_کرو _MCW_PC 0x00030000 // Precision Control
#تعریف_کرو _PC_53 0x00010000 // 53 bits

صحيح __argc;
حرف **__argv;
حرف **environ;
_startupinfo شروع_info = {0};

فراغ mainCRTStartup(فراغ)
{
    rt_reloc();
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#جے_انت
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &شروع_info);
    باہر_نکلو(مکھ(__argc, __argv, environ));
}

#ضمن <stdarg.h>
#تعریف_کرو ناپ_t __SIZE_TYPE__
صحيح لکھو(ثابت حرف *, ...);
صحيح _vsnprintf(حرف *, ناپ_t, ثابت حرف *, va_list);

/* undefined on windows-11-arm64 */
صحيح vprintf(ثابت حرف *format, va_list ap)
{
    حرف buf[1000];
    _vsnprintf(buf, حجم buf, format, ap);
    أرجع لکھو("%s", buf);
}

فراغ __main() {} /* for gcc */
فراغ _pei386_runtime_relocator(فراغ) {} /* for gcc */
فراغ __chkstk(بنانشانی n) {} /* for clang */
