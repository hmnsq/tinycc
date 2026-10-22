/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ಯದಿ 0

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
 REDIR(ಮುಕ್ತ)\

#ಯದಿ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#ಅನ್ಯಥಾ
# define _(s) #s
#endif

#define REDIR(s) ಶೂನ್ಯ *s;
ಸ್ಥಿರ ಸಂರಚನಾ { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ all_names[] = REDIR_ALL;
#undef REDIR

#ಯದಿ __aarch64__
  #ಯದಿ defined __TINYC__
  # define ALIGN ".align 8"
  #ಅನ್ಯಥಾ
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
#ಅನ್ಯಥಾ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ಸ್ಥಿರ ಶೂನ್ಯ all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#ಯದಿ 0
# include <windows.h>
#ಅನ್ಯಥಾ
# ಯದಿ __i386__
#  define STDCALL __declspec(stdcall)
# ಅನ್ಯಥಾ
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE ಶೂನ್ಯ*
# define HANDLE ಶೂನ್ಯ*
S TDCALL HMODULE LoadLibraryA(ಧ್ರುವ ವರ್ಣ *);
S TDCALL HMODULE GetProcAddress(HMODULE , ವರ್ಣ*);
S TDCALL ಶೂನ್ಯ ExitProcess(ಪೂರ್ಣಾಙ್ಕ);
S TDCALL ಪೂರ್ಣಾಙ್ಕ WriteFile(HANDLE, ಧ್ರುವ ಶೂನ್ಯ*, DWORD, DWORD*, ಶೂನ್ಯ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL ಪೂರ್ಣಾಙ್ಕ FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

ಸ್ಥಿರ ಶೂನ್ಯ eput(ಧ್ರುವ ವರ್ಣ *s)
{
    DWORD n_out;
    ಪೂರ್ಣಾಙ್ಕ n = 0;
    ಯಾವತ್ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ rt_reloc()
{
    ಧ್ರುವ ವರ್ಣ *s = all_names;
    ಶೂನ್ಯ **p = (ಶೂನ್ಯ**)&all_ptrs;
    ಶೂನ್ಯ *dll = LoadLibraryA("msvcrt.dll");
    ಕುರು {
        ವರ್ಣ buf[100], *d = buf;
        *p = (ಶೂನ್ಯ*)GetProcAddress(dll, (ವರ್ಣ*)s);
        *d++ = '_'; ಕುರು *d++ = *s; ಯಾವತ್ (*s++);
        ಯದಿ (0 == *p)
            *p = (ಶೂನ್ಯ*)GetProcAddress(dll, buf);
        ಯದಿ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ಯಾವತ್ (*s);
}

#ಅನ್ಯಥಾ
# define rt_reloc()
#endif

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **env);
ಶೂನ್ಯ exit(ಪೂರ್ಣಾಙ್ಕ);
ಶೂನ್ಯ __set_app_type(ಪೂರ್ಣಾಙ್ಕ apptype);

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಙ್ಕ __getmainargs(ಪೂರ್ಣಾಙ್ಕ *pargc, ವರ್ಣ ***pargv, ವರ್ಣ ***penv, ಪೂರ್ಣಾಙ್ಕ globb, _startupinfo*);

ಶೂನ್ಯ _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

ಪೂರ್ಣಾಙ್ಕ __argc;
ವರ್ಣ **__argv;
ವರ್ಣ **environ;
_startupinfo start_info = {0};

ಶೂನ್ಯ mainCRTStartup(ಶೂನ್ಯ)
{
    rt_reloc();
#ಯದಿ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(main(__argc, __argv, environ));
}

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#define size_t __SIZE_TYPE__
ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);
ಪೂರ್ಣಾಙ್ಕ _vsnprintf(ವರ್ಣ *, size_t, ಧ್ರುವ ವರ್ಣ *, va_list);

/* undefined on windows-11-arm64 */
ಪೂರ್ಣಾಙ್ಕ vprintf(ಧ್ರುವ ವರ್ಣ *format, va_list ap)
{
    ವರ್ಣ buf[1000];
    _vsnprintf(buf, ಪರಿಮಾಣ buf, format, ap);
    ಪ್ರತ್ಯಾಗಮ printf("%s", buf);
}

ಶೂನ್ಯ __main() {} /* for gcc */
ಶೂನ್ಯ _pei386_runtime_relocator(ಶೂನ್ಯ) {} /* for gcc */
ಶೂನ್ಯ __chkstk(unsigned n) {} /* for clang */
