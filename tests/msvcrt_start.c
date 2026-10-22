/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#যদি 0

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
 REDIR(মুক্ত)\

#যদি defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#অন্যথা
# define _(s) #s
#endif

#define REDIR(s) শূন্য *s;
স্থির কাঠামো { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
স্থির ধ্রুবক অক্ষর all_names[] = REDIR_ALL;
#undef REDIR

#যদি __aarch64__
  #যদি defined __TINYC__
  # define ALIGN ".align 8"
  #অন্যথা
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
#অন্যথা
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    স্থির শূন্য all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#যদি 0
# include <windows.h>
#অন্যথা
# যদি __i386__
#  define STDCALL __declspec(stdcall)
# অন্যথা
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE শূন্য*
# define HANDLE শূন্য*
S TDCALL HMODULE LoadLibraryA(ধ্রুবক অক্ষর *);
S TDCALL HMODULE GetProcAddress(HMODULE , অক্ষর*);
S TDCALL শূন্য ExitProcess(পূর্ণসংখ্যা);
S TDCALL পূর্ণসংখ্যা WriteFile(HANDLE, ধ্রুবক শূন্য*, DWORD, DWORD*, শূন্য*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL পূর্ণসংখ্যা FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

স্থির শূন্য eput(ধ্রুবক অক্ষর *s)
{
    DWORD n_out;
    পূর্ণসংখ্যা n = 0;
    যখন (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

স্থির শূন্য rt_reloc()
{
    ধ্রুবক অক্ষর *s = all_names;
    শূন্য **p = (শূন্য**)&all_ptrs;
    শূন্য *dll = LoadLibraryA("msvcrt.dll");
    করো {
        অক্ষর buf[100], *d = buf;
        *p = (শূন্য*)GetProcAddress(dll, (অক্ষর*)s);
        *d++ = '_'; করো *d++ = *s; যখন (*s++);
        যদি (0 == *p)
            *p = (শূন্য*)GetProcAddress(dll, buf);
        যদি (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } যখন (*s);
}

#অন্যথা
# define rt_reloc()
#endif

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **env);
শূন্য exit(পূর্ণসংখ্যা);
শূন্য __set_app_type(পূর্ণসংখ্যা apptype);

প্রকারলেখ কাঠামো { পূর্ণসংখ্যা newmode; } _startupinfo;
পূর্ণসংখ্যা __getmainargs(পূর্ণসংখ্যা *pargc, অক্ষর ***pargv, অক্ষর ***penv, পূর্ণসংখ্যা globb, _startupinfo*);

শূন্য _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

পূর্ণসংখ্যা __argc;
অক্ষর **__argv;
অক্ষর **environ;
_startupinfo start_info = {0};

শূন্য mainCRTStartup(শূন্য)
{
    rt_reloc();
#যদি defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(প্রধান(__argc, __argv, environ));
}

#অন্তর্ভাব <stdarg.h>
#define আকার_t __SIZE_TYPE__
পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);
পূর্ণসংখ্যা _vsnprintf(অক্ষর *, আকার_t, ধ্রুবক অক্ষর *, va_list);

/* undefined on windows-11-arm64 */
পূর্ণসংখ্যা vprintf(ধ্রুবক অক্ষর *format, va_list ap)
{
    অক্ষর buf[1000];
    _vsnprintf(buf, আকার buf, format, ap);
    ফেরত printf("%s", buf);
}

শূন্য __main() {} /* for gcc */
শূন্য _pei386_runtime_relocator(শূন্য) {} /* for gcc */
শূন্য __chkstk(unsigned n) {} /* for clang */
