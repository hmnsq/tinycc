/* ------------------------------------------------------------- */
/* minimal startup with runtime linker to msvcrt */

#ఒకవేళ 0

#నిర్వచించు REDIR_ALL \
 REDIR(__set_app_type)\
 REDIR(__getmainargs)\
 REDIR(_controlfp)\
 REDIR(_vsnprintf)\
 REDIR(నిష్క్రమించు)\
 \
 REDIR(puts)\
 REDIR(రాయి)\
 REDIR(అక్షరం_రాయి)\
 REDIR(strtod)\
 REDIR(memset)\
 REDIR(strcpy)\
 REDIR(అక్షరశ్రేణి_పొడవు)\
 REDIR(జ్ఞాపకం_ఇవ్వు)\
 REDIR(విడుదల)\

#ఒకవేళ defined __i386__ && !defined __TINYC__
# define __leading_underscore 1
#అయితే_ముగింపు

#నిర్వచితమైతే __leading_underscore
# define _(s) "_"#s
#లేకపోతే
# define _(s) #s
#అయితే_ముగింపు

#నిర్వచించు REDIR(s) శూన్య *s;
స్థిర నిర్మాణం { REDIR_ALL } all_ptrs;
#నిర్వచనం_రద్దు REDIR

#నిర్వచించు REDIR(s) #s"\0"
స్థిర స్థిరరాశి అక్షరం all_పేర్లు[] = REDIR_ALL;
#నిర్వచనం_రద్దు REDIR

#ఒకవేళ __aarch64__
  #ఒకవేళ defined __TINYC__
  # define ALIGN ".align 8"
  #లేకపోతే
  # define ALIGN ".align 3" /* .align is power of 2 on non-ELF platforms */
  #అయితే_ముగింపు
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
#లేకపోతే
# define REDIR(s) \
    __asm__("\n"_(s)":");\
    __asm__("jmp *%0"::"m"(all_ptrs.s));\
    __asm__(".global "_(s));

    స్థిర శూన్య all_jmps() { REDIR_ALL }
#అయితే_ముగింపు
#నిర్వచనం_రద్దు REDIR

#ఒకవేళ 0
# include <windows.h>
#లేకపోతే
# ఒకవేళ __i386__
#  define STDCALL __declspec(stdcall)
# లేకపోతే
#  define STDCALL
# endif
# define DWORD దీర్ఘ గుర్తులేని
# define HMODULE శూన్య*
# define HANDLE శూన్య*
S TDCALL HMODULE ఎక్కించు_Library_A(స్థిరరాశి అక్షరం *);
S TDCALL HMODULE Get_Proc_చిరునామా(HMODULE , అక్షరం*);
S TDCALL శూన్య ExitProcess(పూర్ణాంకం);
S TDCALL పూర్ణాంకం WriteFile(HANDLE, స్థిరరాశి శూన్య*, DWORD, DWORD*, శూన్య*);
S TDCALL HANDLE GetStdHandle(DWORD);
S TDCALL పూర్ణాంకం FlushFileBuffers(HANDLE);
# define STD_ERROR_HANDLE -12
#అయితే_ముగింపు

స్థిర శూన్య eput(స్థిరరాశి అక్షరం *s)
{
    DWORD n_బహిర్గతం;
    పూర్ణాంకం n = 0;
    అయితే (s[n])
        ++n;
    WriteFile(GetStdHandle(STD_ERROR_HANDLE), s, n, &n_బహిర్గతం, 0);
}

స్థిర శూన్య rt_reloc()
{
    స్థిరరాశి అక్షరం *s = all_పేర్లు;
    శూన్య **p = (శూన్య**)&all_ptrs;
    శూన్య *dll = ఎక్కించు_Library_A("msvcrt.dll");
    చేయి {
        అక్షరం buf[100], *d = buf;
        *p = (శూన్య*)Get_Proc_చిరునామా(dll, (అక్షరం*)s);
        *d++ = '_'; చేయి *d++ = *s; అయితే (*s++);
        ఒకవేళ (0 == *p)
            *p = (శూన్య*)Get_Proc_చిరునామా(dll, buf);
        ఒకవేళ (0 == *p) {
            eput("MSVCRT_START.C: RUNTIME RELOCATION ERROR: '");
            eput(buf+1);
            eput("'\n");
            ExitProcess(-1);
        }
        ++p;
    } అయితే (*s);
}

#లేకపోతే
# define rt_reloc()
#అయితే_ముగింపు

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **env);
శూన్య నిష్క్రమించు(పూర్ణాంకం);
శూన్య __set_app_type(పూర్ణాంకం apptype);

రకనిర్వచనం నిర్మాణం { పూర్ణాంకం newmode; } _startupinfo;
పూర్ణాంకం __getmainargs(పూర్ణాంకం *pargc, అక్షరం ***pargv, అక్షరం ***penv, పూర్ణాంకం globb, _startupinfo*);

శూన్య _controlfp(గుర్తులేని a, గుర్తులేని b);
#నిర్వచించు _MCW_PC 0x00030000 // Precision Control
#నిర్వచించు _PC_53 0x00010000 // 53 bits

పూర్ణాంకం __argc;
అక్షరం **__argv;
అక్షరం **environ;
_startupinfo ప్రారంభం_info = {0};

శూన్య mainCRTStartup(శూన్య)
{
    rt_reloc();
#ఒకవేళ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#అయితే_ముగింపు
    __set_app_type(1);
    __getmainargs(&__argc, &__argv, &environ, 0, &ప్రారంభం_info);
    నిష్క్రమించు(ప్రధాన(__argc, __argv, environ));
}

#అన్తర్భావ <stdarg.h>
#నిర్వచించు కొలత_t __SIZE_TYPE__
పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం *, ...);
పూర్ణాంకం _vsnprintf(అక్షరం *, కొలత_t, స్థిరరాశి అక్షరం *, va_list);

/* undefined on windows-11-arm64 */
పూర్ణాంకం vprintf(స్థిరరాశి అక్షరం *format, va_list ap)
{
    అక్షరం buf[1000];
    _vsnprintf(buf, పరిమాణం buf, format, ap);
    తిరిగి రాయి("%s", buf);
}

శూన్య __main() {} /* for gcc */
శూన్య _pei386_runtime_relocator(శూన్య) {} /* for gcc */
శూన్య __chkstk(గుర్తులేని n) {} /* for clang */
