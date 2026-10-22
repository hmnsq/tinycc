/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#অন্তর্ভাব <stdarg.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#অন্যথা
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ঠেলো
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

প্রকারলেখ কাঠামো rt_frame {
    শূন্য *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
পূর্ণসংখ্যা _tcc_backtrace(rt_frame *f, ধ্রুবক অক্ষর *fmt, va_list ap);

DLL_EXPORT পূর্ণসংখ্যা tcc_backtrace(ধ্রুবক অক্ষর *fmt, ...)
{
    va_list ap;
    পূর্ণসংখ্যা ret;

    যদি (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } অন্যথা {
        ধ্রুবক অক্ষর *p, *nl = "\n";
        যদি (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        যদি (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ফেরত ret;
}

#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic বের_করো
#endif
