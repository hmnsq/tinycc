/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ضمن <stdarg.h>
#ضمن <stdio.h>
#ضمن <string.h>
#تعریف_لغوه __attribute__

#که_تعریف_شوی _WIN32
# define DLL_EXPORT __declspec(dllexport)
#وإلا
# define DLL_EXPORT
#د_که_پای

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#إذا (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#لارښوونه GCC diagnostic ټېل
#لارښوونه GCC diagnostic ignored "-Wframe-address"
#د_که_پای

تعريفنوع بنية rt_چوکاټ {
    فراغ *ip, *fp, *sp;
} rt_چوکاټ;

__attribute__((weak))
صحيح _tcc_backtrace(rt_چوکاټ *f, ثابت حرف *fmt, va_list ap);

DLL_EXPORT صحيح tcc_backtrace(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحيح ret;

    إذا (_tcc_backtrace) {
        rt_چوکاټ f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } وإلا {
        ثابت حرف *p, *nl = "\n";
        إذا (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        إذا (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    أرجع ret;
}

#إذا (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#لارښوونه GCC diagnostic راوباسه
#د_که_پای
