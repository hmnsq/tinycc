/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ຖ້າ 0

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
 REDIR(free)\

#ຖ້າ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#ບໍ່ດັ່ງນັ້ນ
# define _(s) #s
#endif

#define REDIR(s) void *s;
static sa_nracanaa { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
static const var_na all_names[] = REDIR_ALL;
#undef REDIR

#ຖ້າ __aarch64__
  #ຖ້າ defined __TINYC__
  # define ALIGN ".align 8"
  #ບໍ່ດັ່ງນັ້ນ
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
#ບໍ່ດັ່ງນັ້ນ
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    static void all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#ຖ້າ 0
# include <windows.h>
#ບໍ່ດັ່ງນັ້ນ
# ຖ້າ __i386__
#  define STDCALL __declspec(stdcall)
# ບໍ່ດັ່ງນັ້ນ
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE void*
# define HANDLE void*
S TDCALL HMODULE LoadLibraryA(const var_na *);
S TDCALL HMODULE GetProcAddress(HMODULE , var_na*);
S TDCALL void ExitProcess(ຈຳນວນເຕັມ);
S TDCALL ຈຳນວນເຕັມ WriteFile(HANDLE, const void*, DWORD, DWORD*, void*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL ຈຳນວນເຕັມ FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

static void eput(const var_na *s)
{
    DWORD n_out;
    ຈຳນວນເຕັມ n = 0;
    ໃນຂະນະທີ່ (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

static void rt_reloc()
{
    const var_na *s = all_names;
    void **p = (void**)&all_ptrs;
    void *dll = LoadLibraryA("msvcrt.dll");
    do {
        var_na buf[100], *d = buf;
        *p = (void*)GetProcAddress(dll, (var_na*)s);
        *d++ = '_'; do *d++ = *s; ໃນຂະນະທີ່ (*s++);
        ຖ້າ (0 == *p)
            *p = (void*)GetProcAddress(dll, buf);
        ຖ້າ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } ໃນຂະນະທີ່ (*s);
}

#ບໍ່ດັ່ງນັ້ນ
# define rt_reloc()
#endif

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv, var_na **env);
void exit(ຈຳນວນເຕັມ);
void __set_app_type(ຈຳນວນເຕັມ apptype);

typedef sa_nracanaa { ຈຳນວນເຕັມ newmode; } _startupinfo;
ຈຳນວນເຕັມ __getmainargs(ຈຳນວນເຕັມ *pargc, var_na ***pargv, var_na ***penv, ຈຳນວນເຕັມ globb, _startupinfo*);

void _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

ຈຳນວນເຕັມ __argc;
var_na **__argv;
var_na **environ;
_startupinfo start_info = {0};

void mainCRTStartup(void)
{
    rt_reloc();
#ຖ້າ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(main(__argc, __argv, environ));
}

#include <stdarg.h>
#define size_t __SIZE_TYPE__
ຈຳນວນເຕັມ printf(const var_na *, ...);
ຈຳນວນເຕັມ _vsnprintf(var_na *, size_t, const var_na *, va_list);

/* undefined on windows-11-arm64 */
ຈຳນວນເຕັມ vprintf(const var_na *format, va_list ap)
{
    var_na buf[1000];
    _vsnprintf(buf, parimaa_na buf, format, ap);
    ສົ່ງຄືນ printf("%s", buf);
}

void __main() {} /* for gcc */
void _pei386_runtime_relocator(void) {} /* for gcc */
void __chkstk(unsigned n) {} /* for clang */
