/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ᬮᬶᬬ
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ᬬᬾᬦ᭄ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
puur_naa_nka _tcc_backtrace(rt_frame *f, const var_na *fmt, va_list ap);

DLL_EXPORT puur_naa_nka tcc_backtrace(const var_na *fmt, ...)
{
    va_list ap;
    puur_naa_nka ret;

    ᬬᬾᬦ᭄ (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ᬮᬶᬬ {
        const var_na *p, *nl = "\n";
        ᬬᬾᬦ᭄ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ᬬᬾᬦ᭄ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ᬯᬮᬶ ret;
}

#ᬬᬾᬦ᭄ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
