/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ಅನ್ಯಥಾ
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ಯದಿ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ತಳ್ಳು
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ rt_frame {
    ಶೂನ್ಯ *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
ಪೂರ್ಣಾಙ್ಕ _tcc_backtrace(rt_frame *f, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap);

DLL_EXPORT ಪೂರ್ಣಾಙ್ಕ tcc_backtrace(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap;
    ಪೂರ್ಣಾಙ್ಕ ret;

    ಯದಿ (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ಅನ್ಯಥಾ {
        ಧ್ರುವ ವರ್ಣ *p, *nl = "\n";
        ಯದಿ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ಯದಿ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ಪ್ರತ್ಯಾಗಮ ret;
}

#ಯದಿ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ತೆಗೆ
#endif
