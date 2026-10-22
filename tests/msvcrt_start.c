/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#எனில் 0

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
 REDIR(விடுவி)\

#எனில் defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#endif

#ifdef __leading_underscore
# define _(s) "_"#s
#இல்லையெனில்
# define _(s) #s
#endif

#define REDIR(s) வெறுமை *s;
நிலையான கட்டமைப்பு { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
நிலையான மாறிலி எழுத்து all_names[] = REDIR_ALL;
#undef REDIR

#எனில் __aarch64__
  #எனில் defined __TINYC__
  # define ALIGN ".align 8"
  #இல்லையெனில்
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
#இல்லையெனில்
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    நிலையான வெறுமை all_jmps() { REDIR_ALL }
#endif
#undef REDIR

#எனில் 0
# include <windows.h>
#இல்லையெனில்
# எனில் __i386__
#  define STDCALL __declspec(stdcall)
# இல்லையெனில்
#  define STDCALL
# endif
# define DWORD long unsigned
# define HMODULE வெறுமை*
# define HANDLE வெறுமை*
S TDCALL HMODULE LoadLibraryA(மாறிலி எழுத்து *);
S TDCALL HMODULE GetProcAddress(HMODULE , எழுத்து*);
S TDCALL வெறுமை ExitProcess(முழு);
S TDCALL முழு WriteFile(HANDLE, மாறிலி வெறுமை*, DWORD, DWORD*, வெறுமை*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL முழு FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#endif

நிலையான வெறுமை eput(மாறிலி எழுத்து *s)
{
    DWORD n_out;
    முழு n = 0;
    போது (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_out, 0);
}

நிலையான வெறுமை rt_reloc()
{
    மாறிலி எழுத்து *s = all_names;
    வெறுமை **p = (வெறுமை**)&all_ptrs;
    வெறுமை *dll = LoadLibraryA("msvcrt.dll");
    செய் {
        எழுத்து buf[100], *d = buf;
        *p = (வெறுமை*)GetProcAddress(dll, (எழுத்து*)s);
        *d++ = '_'; செய் *d++ = *s; போது (*s++);
        எனில் (0 == *p)
            *p = (வெறுமை*)GetProcAddress(dll, buf);
        எனில் (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } போது (*s);
}

#இல்லையெனில்
# define rt_reloc()
#endif

முழு முதன்மை(முழு argc, எழுத்து **argv, எழுத்து **env);
வெறுமை exit(முழு);
வெறுமை __set_app_type(முழு apptype);

வகைவரை கட்டமைப்பு { முழு newmode; } _startupinfo;
முழு __getmainargs(முழு *pargc, எழுத்து ***pargv, எழுத்து ***penv, முழு globb, _startupinfo*);

வெறுமை _controlfp(unsigned a, unsigned b);
#define _MCW_PC 0x00030000 // Precision Control
#define _PC_53 0x00010000 // 53 bits

முழு __argc;
எழுத்து **__argv;
எழுத்து **environ;
_startupinfo start_info = {0};

வெறுமை mainCRTStartup(வெறுமை)
{
    rt_reloc();
#எனில் defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &start_info);
    exit(முதன்மை(__argc, __argv, environ));
}

#அந்தர்பாவ <stdarg.h>
#define size_t __SIZE_TYPE__
முழு printf(மாறிலி எழுத்து *, ...);
முழு _vsnprintf(எழுத்து *, size_t, மாறிலி எழுத்து *, va_list);

/* undefined on windows-11-arm64 */
முழு vprintf(மாறிலி எழுத்து *format, va_list ap)
{
    எழுத்து buf[1000];
    _vsnprintf(buf, அளவு buf, format, ap);
    திரும்பு printf("%s", buf);
}

வெறுமை __main() {} /* for gcc */
வெறுமை _pei386_runtime_relocator(வெறுமை) {} /* for gcc */
வெறுமை __chkstk(unsigned n) {} /* for clang */
