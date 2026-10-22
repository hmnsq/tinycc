/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ਜੇ 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(ਬਾਹਰ_ਨਿਕਲੋ)\
 \
 REDIR(puts)\
 REDIR(ਲਿਖੋ)\
 REDIR(ਅੱਖਰ_ਲਿਖੋ)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(ਲੜੀ_ਲੰਬਾਈ)\
 REDIR(ਸਮ੍ਰਿਤੀ_ਦਿਓ)\
 REDIR(ਮੁਕਤ)\

#ਜੇ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
# define _(s) "_"#s
#ਨਹੀਂਤਾਂ
# define _(s) #s
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR(s) ਖਾਲੀ *s;
ਸਥਿਰ ਬਣਤਰ { REDIR_ALL } all_ptrs;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR(s) #s"\0"
ਸਥਿਰ ਅਚਲ ਅੱਖਰ all_ਨਾਂ[] = REDIR_ALL;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

#ਜੇ __aarch64__
  #ਜੇ defined __TINYC__
  # define ALIGN ".align 8"
  #ਨਹੀਂਤਾਂ
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #ਜੇ_ਅੰਤ
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
#ਨਹੀਂਤਾਂ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ਸਥਿਰ ਖਾਲੀ all_jmps() { REDIR_ALL }
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

#ਜੇ 0
# include <windows.h>
#ਨਹੀਂਤਾਂ
# ਜੇ __i386__
#  define STDCALL __declspec(stdcall)
# ਨਹੀਂਤਾਂ
#  define STDCALL
# endif
# define DWORD ਲੰਮਾ ਬਿਨਾਨਿਸ਼ਾਨੀ
# define HMODULE ਖਾਲੀ*
# define HANDLE ਖਾਲੀ*
S TDCALL HMODULE ਲੱਦੋ_Library_A(ਅਚਲ ਅੱਖਰ *);
S TDCALL HMODULE Get_Proc_ਪਤਾ(HMODULE , ਅੱਖਰ*);
S TDCALL ਖਾਲੀ ExitProcess(ਪੂਰਨ);
S TDCALL ਪੂਰਨ WriteFile(HANDLE, ਅਚਲ ਖਾਲੀ*, DWORD, DWORD*, ਖਾਲੀ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL ਪੂਰਨ FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ eput(ਅਚਲ ਅੱਖਰ *s)
{
    DWORD n_ਬਾਹਰਲਾ;
    ਪੂਰਨ n = 0;
    ਜਦੋਂ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_ਬਾਹਰਲਾ, 0);
}

ਸਥਿਰ ਖਾਲੀ rt_reloc()
{
    ਅਚਲ ਅੱਖਰ *s = all_ਨਾਂ;
    ਖਾਲੀ **p = (ਖਾਲੀ**)&all_ptrs;
    ਖਾਲੀ *dll = ਲੱਦੋ_Library_A("msvcrt.dll");
    ਕਰੋ {
        ਅੱਖਰ buf[100], *d = buf;
        *p = (ਖਾਲੀ*)Get_Proc_ਪਤਾ(dll, (ਅੱਖਰ*)s);
        *d++ = '_'; ਕਰੋ *d++ = *s; ਜਦੋਂ (*s++);
        ਜੇ (0 == *p)
            *p = (ਖਾਲੀ*)Get_Proc_ਪਤਾ(dll, buf);
        ਜੇ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ਜਦੋਂ (*s);
}

#ਨਹੀਂਤਾਂ
# define rt_reloc()
#ਜੇ_ਅੰਤ

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **env);
ਖਾਲੀ ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ);
ਖਾਲੀ __set_app_type(ਪੂਰਨ apptype);

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ newmode; } _startupinfo;
ਪੂਰਨ __getmainargs(ਪੂਰਨ *pargc, ਅੱਖਰ ***pargv, ਅੱਖਰ ***penv, ਪੂਰਨ globb, _startupinfo*);

ਖਾਲੀ _controlfp(ਬਿਨਾਨਿਸ਼ਾਨੀ a, ਬਿਨਾਨਿਸ਼ਾਨੀ b);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MCW_PC 0x00030000 // Precision Control
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PC_53 0x00010000 // 53 bits

ਪੂਰਨ __argc;
ਅੱਖਰ **__argv;
ਅੱਖਰ **environ;
_startupinfo ਸ਼ੁਰੂ_info = {0};

ਖਾਲੀ mainCRTStartup(ਖਾਲੀ)
{
    rt_reloc();
#ਜੇ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ਜੇ_ਅੰਤ
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &ਸ਼ੁਰੂ_info);
    ਬਾਹਰ_ਨਿਕਲੋ(ਮੁੱਖ(__argc, __argv, environ));
}

#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_t __SIZE_TYPE__
ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *, ...);
ਪੂਰਨ _vsnprintf(ਅੱਖਰ *, ਮਾਪ_t, ਅਚਲ ਅੱਖਰ *, va_list);

/* undefined on windows-11-arm64 */
ਪੂਰਨ vprintf(ਅਚਲ ਅੱਖਰ *format, va_list ap)
{
    ਅੱਖਰ buf[1000];
    _vsnprintf(buf, ਆਕਾਰ buf, format, ap);
    ਵਾਪਸ ਲਿਖੋ("%s", buf);
}

ਖਾਲੀ __main() {} /* for gcc */
ਖਾਲੀ _pei386_runtime_relocator(ਖਾਲੀ) {} /* for gcc */
ਖਾਲੀ __chkstk(ਬਿਨਾਨਿਸ਼ਾਨੀ n) {} /* for clang */
