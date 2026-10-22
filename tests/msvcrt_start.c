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
স্থির সংরচনা { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
স্থির ধ্রুৱ ৱর্ণ all_names[] = REDIR_ALL;
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
S TDCALL HMODULE LoadLibraryA(ধ্রুৱ ৱর্ণ *);
S TDCALL HMODULE GetProcAddress(HMODULE , ৱর্ণ*);
S TDCALL শূন্য ExitProcess(পূর্ণাঙ্ক);
S TDCALL পূর্ণাঙ্ক WriteFile(HANDLE, ধ্রুৱ শূন্য*, DWORD, DWORD*, শূন্য*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL পূর্ণাঙ্ক FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

স্থির শূন্য eput(ধ্রুৱ ৱর্ণ *s)
{
    DWORD n_out;
    পূর্ণাঙ্ক n = 0;
    যেতিয়ালৈ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

স্থির শূন্য rt_reloc()
{
    ধ্রুৱ ৱর্ণ *s = all_names;
    শূন্য **p = (শূন্য**)&all_ptrs;
    শূন্য *dll = LoadLibraryA("msvcrt.dll");
    কৰা {
        ৱর্ণ buf[100], *d = buf;
        *p = (শূন্য*)GetProcAddress(dll, (ৱর্ণ*)s);
        *d++ = '_'; কৰা *d++ = *s; যেতিয়ালৈ (*s++);
        যদি (0 == *p)
            *p = (শূন্য*)GetProcAddress(dll, buf);
        যদি (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } যেতিয়ালৈ (*s);
}

#অন্যথা
# define rt_reloc()
#endif

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **env);
শূন্য exit(পূর্ণাঙ্ক);
শূন্য __set_app_type(পূর্ণাঙ্ক apptype);

প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক newmode; } _startupinfo;
পূর্ণাঙ্ক __getmainargs(পূর্ণাঙ্ক *pargc, ৱর্ণ ***pargv, ৱর্ণ ***penv, পূর্ণাঙ্ক globb, _startupinfo*);

শূন্য _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

পূর্ণাঙ্ক __argc;
ৱর্ণ **__argv;
ৱর্ণ **environ;
_startupinfo start_info = {0};

শূন্য mainCRTStartup(শূন্য)
{
    rt_reloc();
#যদি defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(main(__argc, __argv, environ));
}

#অন্তর্ভাৱ <stdarg.h>
#define size_t __SIZE_TYPE__
পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *, ...);
পূর্ণাঙ্ক _vsnprintf(ৱর্ণ *, size_t, ধ্রুৱ ৱর্ণ *, va_list);

/* undefined on windows-11-arm64 */
পূর্ণাঙ্ক vprintf(ধ্রুৱ ৱর্ণ *format, va_list ap)
{
    ৱর্ণ buf[1000];
    _vsnprintf(buf, পরিমাণ buf, format, ap);
    ঘূৰাই printf("%s", buf);
}

শূন্য __main() {} /* for gcc */
শূন্য _pei386_runtime_relocator(শূন্য) {} /* for gcc */
শূন্য __chkstk(unsigned n) {} /* for clang */
