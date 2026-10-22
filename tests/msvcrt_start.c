/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ܐܢ 0

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
 REDIR(حرر)\

#ܐܢ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#ܐܚܪܢܐ
# define _(s) #s
#endif

#define REDIR(s) فراغ *s;
ساكن بنية { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
ساكن ثابت حرف all_names[] = REDIR_ALL;
#undef REDIR

#ܐܢ __aarch64__
  #ܐܢ defined __TINYC__
  # define ALIGN ".align 8"
  #ܐܚܪܢܐ
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
#ܐܚܪܢܐ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ساكن فراغ all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#ܐܢ 0
# include <windows.h>
#ܐܚܪܢܐ
# ܐܢ __i386__
#  define STDCALL __declspec(stdcall)
# ܐܚܪܢܐ
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE فراغ*
# define HANDLE فراغ*
S TDCALL HMODULE LoadLibraryA(ثابت حرف *);
S TDCALL HMODULE GetProcAddress(HMODULE , حرف*);
S TDCALL فراغ ExitProcess(صحيح);
S TDCALL صحيح WriteFile(HANDLE, ثابت فراغ*, DWORD, DWORD*, فراغ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL صحيح FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

ساكن فراغ eput(ثابت حرف *s)
{
    DWORD n_out;
    صحيح n = 0;
    ܟܡܐ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

ساكن فراغ rt_reloc()
{
    ثابت حرف *s = all_names;
    فراغ **p = (فراغ**)&all_ptrs;
    فراغ *dll = LoadLibraryA("msvcrt.dll");
    ܥܒܕ {
        حرف buf[100], *d = buf;
        *p = (فراغ*)GetProcAddress(dll, (حرف*)s);
        *d++ = '_'; ܥܒܕ *d++ = *s; ܟܡܐ (*s++);
        ܐܢ (0 == *p)
            *p = (فراغ*)GetProcAddress(dll, buf);
        ܐܢ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ܟܡܐ (*s);
}

#ܐܚܪܢܐ
# define rt_reloc()
#endif

صحيح main(صحيح argc, حرف **argv, حرف **env);
فراغ exit(صحيح);
فراغ __set_app_type(صحيح apptype);

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __getmainargs(صحيح *pargc, حرف ***pargv, حرف ***penv, صحيح globb, _startupinfo*);

فراغ _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

صحيح __argc;
حرف **__argv;
حرف **environ;
_startupinfo start_info = {0};

فراغ mainCRTStartup(فراغ)
{
    rt_reloc();
#ܐܢ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(main(__argc, __argv, environ));
}

#ضمن <stdarg.h>
#define size_t __SIZE_TYPE__
صحيح printf(ثابت حرف *, ...);
صحيح _vsnprintf(حرف *, size_t, ثابت حرف *, va_list);

/* undefined on windows-11-arm64 */
صحيح vprintf(ثابت حرف *format, va_list ap)
{
    حرف buf[1000];
    _vsnprintf(buf, حجم buf, format, ap);
    ܦܢܐ printf("%s", buf);
}

فراغ __main() {} /* for gcc */
فراغ _pei386_runtime_relocator(فراغ) {} /* for gcc */
فراغ __chkstk(unsigned n) {} /* for clang */
