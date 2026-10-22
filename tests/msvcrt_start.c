/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#എങ്കിൽ 0

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
 REDIR(സ്വതന്ത്രം)\

#എങ്കിൽ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#അല്ലെങ്കിൽ
# define _(s) #s
#endif

#define REDIR(s) ശൂന്യം *s;
സ്ഥിതം ഘടന { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
സ്ഥിതം സ്ഥിരം അക്ഷരം all_names[] = REDIR_ALL;
#undef REDIR

#എങ്കിൽ __aarch64__
  #എങ്കിൽ defined __TINYC__
  # define ALIGN ".align 8"
  #അല്ലെങ്കിൽ
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
#അല്ലെങ്കിൽ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    സ്ഥിതം ശൂന്യം all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#എങ്കിൽ 0
# include <windows.h>
#അല്ലെങ്കിൽ
# എങ്കിൽ __i386__
#  define STDCALL __declspec(stdcall)
# അല്ലെങ്കിൽ
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE ശൂന്യം*
# define HANDLE ശൂന്യം*
S TDCALL HMODULE LoadLibraryA(സ്ഥിരം അക്ഷരം *);
S TDCALL HMODULE GetProcAddress(HMODULE , അക്ഷരം*);
S TDCALL ശൂന്യം ExitProcess(പൂർണ്ണസംഖ്യ);
S TDCALL പൂർണ്ണസംഖ്യ WriteFile(HANDLE, സ്ഥിരം ശൂന്യം*, DWORD, DWORD*, ശൂന്യം*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL പൂർണ്ണസംഖ്യ FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

സ്ഥിതം ശൂന്യം eput(സ്ഥിരം അക്ഷരം *s)
{
    DWORD n_out;
    പൂർണ്ണസംഖ്യ n = 0;
    ആകുമ്പോൾ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

സ്ഥിതം ശൂന്യം rt_reloc()
{
    സ്ഥിരം അക്ഷരം *s = all_names;
    ശൂന്യം **p = (ശൂന്യം**)&all_ptrs;
    ശൂന്യം *dll = LoadLibraryA("msvcrt.dll");
    ചെയ്യുക {
        അക്ഷരം buf[100], *d = buf;
        *p = (ശൂന്യം*)GetProcAddress(dll, (അക്ഷരം*)s);
        *d++ = '_'; ചെയ്യുക *d++ = *s; ആകുമ്പോൾ (*s++);
        എങ്കിൽ (0 == *p)
            *p = (ശൂന്യം*)GetProcAddress(dll, buf);
        എങ്കിൽ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ആകുമ്പോൾ (*s);
}

#അല്ലെങ്കിൽ
# define rt_reloc()
#endif

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **env);
ശൂന്യം exit(പൂർണ്ണസംഖ്യ);
ശൂന്യം __set_app_type(പൂർണ്ണസംഖ്യ apptype);

തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ newmode; } _startupinfo;
പൂർണ്ണസംഖ്യ __getmainargs(പൂർണ്ണസംഖ്യ *pargc, അക്ഷരം ***pargv, അക്ഷരം ***penv, പൂർണ്ണസംഖ്യ globb, _startupinfo*);

ശൂന്യം _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

പൂർണ്ണസംഖ്യ __argc;
അക്ഷരം **__argv;
അക്ഷരം **environ;
_startupinfo start_info = {0};

ശൂന്യം mainCRTStartup(ശൂന്യം)
{
    rt_reloc();
#എങ്കിൽ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(പ്രധാന(__argc, __argv, environ));
}

#അന്തര്ഭാവ <stdarg.h>
#define size_t __SIZE_TYPE__
പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);
പൂർണ്ണസംഖ്യ _vsnprintf(അക്ഷരം *, size_t, സ്ഥിരം അക്ഷരം *, va_list);

/* undefined on windows-11-arm64 */
പൂർണ്ണസംഖ്യ vprintf(സ്ഥിരം അക്ഷരം *format, va_list ap)
{
    അക്ഷരം buf[1000];
    _vsnprintf(buf, വലുപ്പം buf, format, ap);
    തിരികെ printf("%s", buf);
}

ശൂന്യം __main() {} /* for gcc */
ശൂന്യം _pei386_runtime_relocator(ശൂന്യം) {} /* for gcc */
ശൂന്യം __chkstk(unsigned n) {} /* for clang */
