/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#شامل <stdarg.h>
#شامل <stdio.h>
#شامل <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وگرنه
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic افزودن
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

تعریفنوع ساختار rt_frame {
    تهی *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
صحیح _tcc_backtrace(rt_frame *f, ثابت نویسه *fmt, va_list ap);

DLL_EXPORT صحیح tcc_backtrace(ثابت نویسه *fmt, ...)
{
    va_list ap;
    صحیح ret;

    اگر (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } وگرنه {
        ثابت نویسه *p, *nl = "\n";
        اگر (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        اگر (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    بازگشت ret;
}

#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic برداشت
#endif
