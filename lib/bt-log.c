/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#অন্তর্ভাৱ <stdarg.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>
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

প্রকারনির্দেশ সংরচনা rt_frame {
    শূন্য *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
পূর্ণাঙ্ক _tcc_backtrace(rt_frame *f, ধ্রুৱ ৱর্ণ *fmt, va_list ap);

DLL_EXPORT পূর্ণাঙ্ক tcc_backtrace(ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list ap;
    পূর্ণাঙ্ক ret;

    যদি (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } অন্যথা {
        ধ্রুৱ ৱর্ণ *p, *nl = "\n";
        যদি (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        যদি (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ঘূৰাই ret;
}

#যদি (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic বেৰ_কৰো
#endif
