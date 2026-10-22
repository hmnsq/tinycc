/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#иначе
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ако (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
цяло _tcc_backtrace(rt_frame *f, const char *fmt, va_list ap);

DLL_EXPORT цяло tcc_backtrace(const char *fmt, ...)
{
    va_list ap;
    цяло ret;

    ако (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } иначе {
        const char *p, *nl = "\n";
        ако (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ако (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    върни ret;
}

#ако (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
