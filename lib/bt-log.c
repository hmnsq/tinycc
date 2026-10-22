/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ضمن <stdarg.h>
#ضمن <stdio.h>
#ضمن <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#אחרת
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#אם (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

تعريفنوع بنية rt_frame {
    فراغ *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
صحيح _tcc_backtrace(rt_frame *f, ثابت حرف *fmt, va_list ap);

DLL_EXPORT صحيح tcc_backtrace(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحيح ret;

    אם (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } אחרת {
        ثابت حرف *p, *nl = "\n";
        אם (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        אם (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    החזר ret;
}

#אם (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
