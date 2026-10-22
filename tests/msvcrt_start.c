/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#જો 0

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
 REDIR(મુક્ત)\

#જો defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#નહીંતર
# define _(s) #s
#endif

#define REDIR(s) શૂન્ય *s;
સ્થિર સંરચના { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
સ્થિર અચલ અક્ષર all_names[] = REDIR_ALL;
#undef REDIR

#જો __aarch64__
  #જો defined __TINYC__
  # define ALIGN ".align 8"
  #નહીંતર
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
#નહીંતર
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    સ્થિર શૂન્ય all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#જો 0
# include <windows.h>
#નહીંતર
# જો __i386__
#  define STDCALL __declspec(stdcall)
# નહીંતર
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE શૂન્ય*
# define HANDLE શૂન્ય*
S TDCALL HMODULE LoadLibraryA(અચલ અક્ષર *);
S TDCALL HMODULE GetProcAddress(HMODULE , અક્ષર*);
S TDCALL શૂન્ય ExitProcess(પૂર્ણાંક);
S TDCALL પૂર્ણાંક WriteFile(HANDLE, અચલ શૂન્ય*, DWORD, DWORD*, શૂન્ય*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL પૂર્ણાંક FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

સ્થિર શૂન્ય eput(અચલ અક્ષર *s)
{
    DWORD n_out;
    પૂર્ણાંક n = 0;
    જ્યારે (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

સ્થિર શૂન્ય rt_reloc()
{
    અચલ અક્ષર *s = all_names;
    શૂન્ય **p = (શૂન્ય**)&all_ptrs;
    શૂન્ય *dll = LoadLibraryA("msvcrt.dll");
    કરો {
        અક્ષર buf[100], *d = buf;
        *p = (શૂન્ય*)GetProcAddress(dll, (અક્ષર*)s);
        *d++ = '_'; કરો *d++ = *s; જ્યારે (*s++);
        જો (0 == *p)
            *p = (શૂન્ય*)GetProcAddress(dll, buf);
        જો (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } જ્યારે (*s);
}

#નહીંતર
# define rt_reloc()
#endif

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **env);
શૂન્ય exit(પૂર્ણાંક);
શૂન્ય __set_app_type(પૂર્ણાંક apptype);

પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક newmode; } _startupinfo;
પૂર્ણાંક __getmainargs(પૂર્ણાંક *pargc, અક્ષર ***pargv, અક્ષર ***penv, પૂર્ણાંક globb, _startupinfo*);

શૂન્ય _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

પૂર્ણાંક __argc;
અક્ષર **__argv;
અક્ષર **environ;
_startupinfo start_info = {0};

શૂન્ય mainCRTStartup(શૂન્ય)
{
    rt_reloc();
#જો defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(મુખ્ય(__argc, __argv, environ));
}

#અન્તર્ભાવ <stdarg.h>
#define size_t __SIZE_TYPE__
પૂર્ણાંક printf(અચલ અક્ષર *, ...);
પૂર્ણાંક _vsnprintf(અક્ષર *, size_t, અચલ અક્ષર *, va_list);

/* undefined on windows-11-arm64 */
પૂર્ણાંક vprintf(અચલ અક્ષર *format, va_list ap)
{
    અક્ષર buf[1000];
    _vsnprintf(buf, કદ buf, format, ap);
    પાછા printf("%s", buf);
}

શૂન્ય __main() {} /* for gcc */
શૂન્ય _pei386_runtime_relocator(શૂન્ય) {} /* for gcc */
શૂન્ય __chkstk(unsigned n) {} /* for clang */
