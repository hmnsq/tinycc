/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __attribute__

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ಇಲ್ಲದಿದ್ದರೆ
# define DLL_EXPORT
#ಆದರೆ_ಅಂತ್ಯ

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ಆದರೆ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ಸೂಚನೆ GCC diagnostic ತಳ್ಳು
#ಸೂಚನೆ GCC diagnostic ignored "-Wframe-address"
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ rt_ಚೌಕಟ್ಟು {
    ಶೂನ್ಯ *ip, *fp, *sp;
} rt_ಚೌಕಟ್ಟು;

__attribute__((weak))
ಪೂರ್ಣಾಂಕ _tcc_backtrace(rt_ಚೌಕಟ್ಟು *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap);

DLL_EXPORT ಪೂರ್ಣಾಂಕ tcc_backtrace(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap;
    ಪೂರ್ಣಾಂಕ ret;

    ಆದರೆ (_tcc_backtrace) {
        rt_ಚೌಕಟ್ಟು f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, *nl = "\n";
        ಆದರೆ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ಆದರೆ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ಹಿಂತಿರುಗಿ ret;
}

#ಆದರೆ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ಸೂಚನೆ GCC diagnostic ತೆಗೆ
#ಆದರೆ_ಅಂತ್ಯ
