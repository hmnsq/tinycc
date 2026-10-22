/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#അന്തര്ഭാവ <stdarg.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#അല്ലെങ്കിൽ
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#എങ്കിൽ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic തള്ളുക
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

തരനിർവചനം ഘടന rt_frame {
    ശൂന്യം *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
പൂർണ്ണസംഖ്യ _tcc_backtrace(rt_frame *f, സ്ഥിരം അക്ഷരം *fmt, va_list ap);

DLL_EXPORT പൂർണ്ണസംഖ്യ tcc_backtrace(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap;
    പൂർണ്ണസംഖ്യ ret;

    എങ്കിൽ (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } അല്ലെങ്കിൽ {
        സ്ഥിരം അക്ഷരം *p, *nl = "\n";
        എങ്കിൽ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        എങ്കിൽ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    തിരികെ ret;
}

#എങ്കിൽ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic എടുക്കുക
#endif
