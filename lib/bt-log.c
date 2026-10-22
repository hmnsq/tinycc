/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ଅନ୍ୟଥା
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ଯଦି (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ଠେଲ
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା rt_frame {
    ଶୂନ୍ୟ *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_backtrace(rt_frame *f, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap);

DLL_EXPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_backtrace(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;

    ଯଦି (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ଅନ୍ୟଥା {
        ଅଚଳ ଅକ୍ଷର *p, *nl = "\n";
        ଯଦି (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ଯଦି (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ଫେରନ୍ତୁ ret;
}

#ଯଦି (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic କାଢ଼
#endif
