/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#اگر 0

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
 REDIR(حافظہ_دو)\
 REDIR(آزاد)\

#اگر defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#اگر_ختم

#اگر_تعریف_شدہ __leading_underscore
# define _(s) "_"#s
#ورنہ
# define _(s) #s
#اگر_ختم

#تعریف_کرو REDIR(s) خالی *s;
ساکن ساخت { REDIR_ALL } all_ptrs;
#تعریف_منسوخ REDIR

#تعریف_کرو REDIR(s) #s"\0"
ساکن ثابت حرف all_نام[] = REDIR_ALL;
#تعریف_منسوخ REDIR

#اگر __aarch64__
  #اگر defined __TINYC__
  # define ALIGN ".align 8"
  #ورنہ
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #اگر_ختم
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
#ورنہ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ساکن خالی all_jmps() { REDIR_ALL }
#اگر_ختم
#تعریف_منسوخ REDIR

#اگر 0
# include <windows.h>
#ورنہ
# اگر __i386__
#  define STDCALL __declspec(stdcall)
# ورنہ
#  define STDCALL
# endif
# define DWORD طویل غیرعلامتی
# define HMODULE خالی*
# define HANDLE خالی*
S TDCALL HMODULE بھرو_Library_A(ثابت حرف *);
S TDCALL HMODULE Get_Proc_پتہ(HMODULE , حرف*);
S TDCALL خالی ExitProcess(صحیح);
S TDCALL صحیح WriteFile(HANDLE, ثابت خالی*, DWORD, DWORD*, خالی*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL صحیح FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#اگر_ختم

ساکن خالی eput(ثابت حرف *s)
{
    DWORD n_برآمد;
    صحیح n = 0;
    جب (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_برآمد, 0);
}

ساکن خالی rt_reloc()
{
    ثابت حرف *s = all_نام;
    خالی **p = (خالی**)&all_ptrs;
    خالی *dll = بھرو_Library_A("msvcrt.dll");
    کرو {
        حرف buf[100], *d = buf;
        *p = (خالی*)Get_Proc_پتہ(dll, (حرف*)s);
        *d++ = '_'; کرو *d++ = *s; جب (*s++);
        اگر (0 == *p)
            *p = (خالی*)Get_Proc_پتہ(dll, buf);
        اگر (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } جب (*s);
}

#ورنہ
# define rt_reloc()
#اگر_ختم

صحیح مین(صحیح argc, حرف **argv, حرف **env);
خالی باہر_نکلو(صحیح);
خالی __set_app_type(صحیح apptype);

قسمتعریف ساخت { صحیح newmode; } _startupinfo;
صحیح __getmainargs(صحیح *pargc, حرف ***pargv, حرف ***penv, صحیح globb, _startupinfo*);

خالی _controlfp(غیرعلامتی a, غیرعلامتی b);
#تعریف_کرو _MCW_PC 0x00030000 // Precision Control
#تعریف_کرو _PC_53 0x00010000 // 53 bits

صحیح __argc;
حرف **__argv;
حرف **environ;
_startupinfo آغاز_info = {0};

خالی mainCRTStartup(خالی)
{
    rt_reloc();
#اگر defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#اگر_ختم
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &آغاز_info);
    باہر_نکلو(مین(__argc, __argv, environ));
}

#شامل <stdarg.h>
#تعریف_کرو سائز_t __SIZE_TYPE__
صحیح لکھو(ثابت حرف *, ...);
صحیح _vsnprintf(حرف *, سائز_t, ثابت حرف *, va_list);

/* undefined on windows-11-arm64 */
صحیح vprintf(ثابت حرف *format, va_list ap)
{
    حرف buf[1000];
    _vsnprintf(buf, حجم buf, format, ap);
    واپس لکھو("%s", buf);
}

خالی __main() {} /* for gcc */
خالی _pei386_runtime_relocator(خالی) {} /* for gcc */
خالی __chkstk(غیرعلامتی n) {} /* for clang */
