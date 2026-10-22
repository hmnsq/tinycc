/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#اگر 0

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
 REDIR(آزاد)\

#اگر defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#وگرنه
# define _(s) #s
#endif

#define REDIR(s) تهی *s;
ایستا ساختار { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
ایستا ثابت نویسه all_names[] = REDIR_ALL;
#undef REDIR

#اگر __aarch64__
  #اگر defined __TINYC__
  # define ALIGN ".align 8"
  #وگرنه
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
#وگرنه
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    ایستا تهی all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#اگر 0
# include <windows.h>
#وگرنه
# اگر __i386__
#  define STDCALL __declspec(stdcall)
# وگرنه
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE تهی*
# define HANDLE تهی*
S TDCALL HMODULE LoadLibraryA(ثابت نویسه *);
S TDCALL HMODULE GetProcAddress(HMODULE , نویسه*);
S TDCALL تهی ExitProcess(صحیح);
S TDCALL صحیح WriteFile(HANDLE, ثابت تهی*, DWORD, DWORD*, تهی*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL صحیح FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

ایستا تهی eput(ثابت نویسه *s)
{
    DWORD n_out;
    صحیح n = 0;
    وقتی (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

ایستا تهی rt_reloc()
{
    ثابت نویسه *s = all_names;
    تهی **p = (تهی**)&all_ptrs;
    تهی *dll = LoadLibraryA("msvcrt.dll");
    انجامبده {
        نویسه buf[100], *d = buf;
        *p = (تهی*)GetProcAddress(dll, (نویسه*)s);
        *d++ = '_'; انجامبده *d++ = *s; وقتی (*s++);
        اگر (0 == *p)
            *p = (تهی*)GetProcAddress(dll, buf);
        اگر (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } وقتی (*s);
}

#وگرنه
# define rt_reloc()
#endif

صحیح اصلی(صحیح argc, نویسه **argv, نویسه **env);
تهی exit(صحیح);
تهی __set_app_type(صحیح apptype);

تعریفنوع ساختار { صحیح newmode; } _startupinfo;
صحیح __getmainargs(صحیح *pargc, نویسه ***pargv, نویسه ***penv, صحیح globb, _startupinfo*);

تهی _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

صحیح __argc;
نویسه **__argv;
نویسه **environ;
_startupinfo start_info = {0};

تهی mainCRTStartup(تهی)
{
    rt_reloc();
#اگر defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(اصلی(__argc, __argv, environ));
}

#شامل <stdarg.h>
#define size_t __SIZE_TYPE__
صحیح printf(ثابت نویسه *, ...);
صحیح _vsnprintf(نویسه *, size_t, ثابت نویسه *, va_list);

/* undefined on windows-11-arm64 */
صحیح vprintf(ثابت نویسه *format, va_list ap)
{
    نویسه buf[1000];
    _vsnprintf(buf, اندازه buf, format, ap);
    بازگشت printf("%s", buf);
}

تهی __main() {} /* for gcc */
تهی _pei386_runtime_relocator(تهی) {} /* for gcc */
تهی __chkstk(unsigned n) {} /* for clang */
