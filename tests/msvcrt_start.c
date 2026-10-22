/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ଯଦି 0

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
 REDIR(ମୁକ୍ତ)\

#ଯଦି defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#ଅନ୍ୟଥା
# define _(s) #s
#endif

#define REDIR(s) ଶୂନ୍ୟ *s;
ସ୍ଥିର ସଂରଚନା { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
ସ୍ଥିର ଅଚଳ ଅକ୍ଷର all_names[] = REDIR_ALL;
#undef REDIR

#ଯଦି __aarch64__
  #ଯଦି defined __TINYC__
  # define ALIGN ".align 8"
  #ଅନ୍ୟଥା
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
#ଅନ୍ୟଥା
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ସ୍ଥିର ଶୂନ୍ୟ all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#ଯଦି 0
# include <windows.h>
#ଅନ୍ୟଥା
# ଯଦି __i386__
#  define STDCALL __declspec(stdcall)
# ଅନ୍ୟଥା
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE ଶୂନ୍ୟ*
# define HANDLE ଶୂନ୍ୟ*
S TDCALL HMODULE LoadLibraryA(ଅଚଳ ଅକ୍ଷର *);
S TDCALL HMODULE GetProcAddress(HMODULE , ଅକ୍ଷର*);
S TDCALL ଶୂନ୍ୟ ExitProcess(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
S TDCALL ପୂର୍ଣ୍ଣସଂଖ୍ୟା WriteFile(HANDLE, ଅଚଳ ଶୂନ୍ୟ*, DWORD, DWORD*, ଶୂନ୍ୟ*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL ପୂର୍ଣ୍ଣସଂଖ୍ୟା FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

ସ୍ଥିର ଶୂନ୍ୟ eput(ଅଚଳ ଅକ୍ଷର *s)
{
    DWORD n_out;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = 0;
    ଯେତେବେଳେ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

ସ୍ଥିର ଶୂନ୍ୟ rt_reloc()
{
    ଅଚଳ ଅକ୍ଷର *s = all_names;
    ଶୂନ୍ୟ **p = (ଶୂନ୍ୟ**)&all_ptrs;
    ଶୂନ୍ୟ *dll = LoadLibraryA("msvcrt.dll");
    କର {
        ଅକ୍ଷର buf[100], *d = buf;
        *p = (ଶୂନ୍ୟ*)GetProcAddress(dll, (ଅକ୍ଷର*)s);
        *d++ = '_'; କର *d++ = *s; ଯେତେବେଳେ (*s++);
        ଯଦି (0 == *p)
            *p = (ଶୂନ୍ୟ*)GetProcAddress(dll, buf);
        ଯଦି (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ଯେତେବେଳେ (*s);
}

#ଅନ୍ୟଥା
# define rt_reloc()
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **env);
ଶୂନ୍ୟ exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ଶୂନ୍ୟ __set_app_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା apptype);

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା newmode; } _startupinfo;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __getmainargs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pargc, ଅକ୍ଷର ***pargv, ଅକ୍ଷର ***penv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା globb, _startupinfo*);

ଶୂନ୍ୟ _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __argc;
ଅକ୍ଷର **__argv;
ଅକ୍ଷର **environ;
_startupinfo start_info = {0};

ଶୂନ୍ୟ mainCRTStartup(ଶୂନ୍ୟ)
{
    rt_reloc();
#ଯଦି defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(ମୁଖ୍ୟ(__argc, __argv, environ));
}

#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#define size_t __SIZE_TYPE__
ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _vsnprintf(ଅକ୍ଷର *, size_t, ଅଚଳ ଅକ୍ଷର *, va_list);

/* undefined on windows-11-arm64 */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vprintf(ଅଚଳ ଅକ୍ଷର *format, va_list ap)
{
    ଅକ୍ଷର buf[1000];
    _vsnprintf(buf, ଆକାର buf, format, ap);
    ଫେରନ୍ତୁ printf("%s", buf);
}

ଶୂନ୍ୟ __main() {} /* for gcc */
ଶୂନ୍ୟ _pei386_runtime_relocator(ଶୂନ୍ୟ) {} /* for gcc */
ଶୂନ୍ୟ __chkstk(unsigned n) {} /* for clang */
