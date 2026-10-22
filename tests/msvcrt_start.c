/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ಆದರೆ 0

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(ನಿರ್ಗಮಿಸು)\
 \
 REDIR(puts)\
 REDIR(ಬರೆ)\
 REDIR(ಅಕ್ಷರ_ಬರೆ)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ)\
 REDIR(ಸ್ಮರಣೆ_ಕೊಡು)\
 REDIR(ಬಿಡುಗಡೆ)\

#ಆದರೆ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
# define _(s) "_"#s
#ಇಲ್ಲದಿದ್ದರೆ
# define _(s) #s
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR(s) ಶೂನ್ಯ *s;
ಸ್ಥಿರ ರಚನೆ { REDIR_ALL } all_ptrs;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR(s) #s"\0"
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ all_ಹೆಸರುಗಳು[] = REDIR_ALL;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

#ಆದರೆ __aarch64__
  #ಆದರೆ defined __TINYC__
  # define ALIGN ".align 8"
  #ಇಲ್ಲದಿದ್ದರೆ
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #ಆದರೆ_ಅಂತ್ಯ
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
#ಇಲ್ಲದಿದ್ದರೆ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ಸ್ಥಿರ ಶೂನ್ಯ all_jmps() { REDIR_ALL }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

#ಆದರೆ 0
# include <windows.h>
#ಇಲ್ಲದಿದ್ದರೆ
# ಆದರೆ __i386__
#  define STDCALL __declspec(stdcall)
# ಇಲ್ಲದಿದ್ದರೆ
#  define STDCALL
# endif
# define DWORD ದೀರ್ಘ ಚಿಹ್ನೆರಹಿತ
# define HMODULE ಶೂನ್ಯ*
# define HANDLE ಶೂನ್ಯ*
S TDCALL HMODULE ತುಂಬು_Library_A(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);
S TDCALL HMODULE Get_Proc_ವಿಳಾಸ(HMODULE , ಅಕ್ಷರ*);
S TDCALL ಶೂನ್ಯ ExitProcess(ಪೂರ್ಣಾಂಕ);
S TDCALL ಪೂರ್ಣಾಂಕ WriteFile(HANDLE, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*, DWORD, DWORD*, ಶೂನ್ಯ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL ಪೂರ್ಣಾಂಕ FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ eput(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    DWORD n_ಹೊರಹೋಗು;
    ಪೂರ್ಣಾಂಕ n = 0;
    ಆಗ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_ಹೊರಹೋಗು, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ rt_reloc()
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = all_ಹೆಸರುಗಳು;
    ಶೂನ್ಯ **p = (ಶೂನ್ಯ**)&all_ptrs;
    ಶೂನ್ಯ *dll = ತುಂಬು_Library_A("msvcrt.dll");
    ಮಾಡು {
        ಅಕ್ಷರ buf[100], *d = buf;
        *p = (ಶೂನ್ಯ*)Get_Proc_ವಿಳಾಸ(dll, (ಅಕ್ಷರ*)s);
        *d++ = '_'; ಮಾಡು *d++ = *s; ಆಗ (*s++);
        ಆದರೆ (0 == *p)
            *p = (ಶೂನ್ಯ*)Get_Proc_ವಿಳಾಸ(dll, buf);
        ಆದರೆ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ಆಗ (*s);
}

#ಇಲ್ಲದಿದ್ದರೆ
# define rt_reloc()
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **env);
ಶೂನ್ಯ ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ);
ಶೂನ್ಯ __set_app_type(ಪೂರ್ಣಾಂಕ apptype);

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಂಕ __getmainargs(ಪೂರ್ಣಾಂಕ *pargc, ಅಕ್ಷರ ***pargv, ಅಕ್ಷರ ***penv, ಪೂರ್ಣಾಂಕ globb, _startupinfo*);

ಶೂನ್ಯ _controlfp(ಚಿಹ್ನೆರಹಿತ a, ಚಿಹ್ನೆರಹಿತ b);
#ವ್ಯಾಖ್ಯಾನಿಸು _MCW_PC 0x00030000 // Precision Control
#ವ್ಯಾಖ್ಯಾನಿಸು _PC_53 0x00010000 // 53 bits

ಪೂರ್ಣಾಂಕ __argc;
ಅಕ್ಷರ **__argv;
ಅಕ್ಷರ **environ;
_startupinfo ಆರಂಭ_info = {0};

ಶೂನ್ಯ mainCRTStartup(ಶೂನ್ಯ)
{
    rt_reloc();
#ಆದರೆ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ಆದರೆ_ಅಂತ್ಯ
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &ಆರಂಭ_info);
    ನಿರ್ಗಮಿಸು(ಮುಖ್ಯ(__argc, __argv, environ));
}

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_t __SIZE_TYPE__
ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಪೂರ್ಣಾಂಕ _vsnprintf(ಅಕ್ಷರ *, ಗಾತ್ರ_t, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, va_list);

/* undefined on windows-11-arm64 */
ಪೂರ್ಣಾಂಕ vprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, va_list ap)
{
    ಅಕ್ಷರ buf[1000];
    _vsnprintf(buf, ಗಾತ್ರ buf, format, ap);
    ಹಿಂತಿರುಗಿ ಬರೆ("%s", buf);
}

ಶೂನ್ಯ __main() {} /* for gcc */
ಶೂನ್ಯ _pei386_runtime_relocator(ಶೂನ್ಯ) {} /* for gcc */
ಶೂನ್ಯ __chkstk(ಚಿಹ್ನೆರಹಿತ n) {} /* for clang */
