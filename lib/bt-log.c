/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#شامل <stdarg.h>
#شامل <stdio.h>
#شامل <string.h>
#تعریف_منسوخ __attribute__

#اگر_تعریف_شدہ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ورنہ
# define DLL_EXPORT
#اگر_ختم

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ہدایت GCC diagnostic ڈالو
#ہدایت GCC diagnostic ignored "-Wframe-address"
#اگر_ختم

قسمتعریف ساخت rt_چوکھٹا {
    خالی *ip, *fp, *sp;
} rt_چوکھٹا;

__attribute__((weak))
صحیح _tcc_backtrace(rt_چوکھٹا *f, ثابت حرف *fmt, va_list ap);

DLL_EXPORT صحیح tcc_backtrace(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحیح ret;

    اگر (_tcc_backtrace) {
        rt_چوکھٹا f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ورنہ {
        ثابت حرف *p, *nl = "\n";
        اگر (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        اگر (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    واپس ret;
}

#اگر (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ہدایت GCC diagnostic نکالو
#اگر_ختم
