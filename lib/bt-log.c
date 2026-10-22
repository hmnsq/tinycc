/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __attribute__

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# define DLL_EXPORT __declspec(dllexport)
#ਨਹੀਂਤਾਂ
# define DLL_EXPORT
#ਜੇ_ਅੰਤ

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ਜੇ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ਹਦਾਇਤ GCC diagnostic ਧੱਕੋ
#ਹਦਾਇਤ GCC diagnostic ignored "-Wframe-address"
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ rt_ਚੌਖਟਾ {
    ਖਾਲੀ *ip, *fp, *sp;
} rt_ਚੌਖਟਾ;

__attribute__((weak))
ਪੂਰਨ _tcc_backtrace(rt_ਚੌਖਟਾ *f, ਅਚਲ ਅੱਖਰ *fmt, va_list ap);

DLL_EXPORT ਪੂਰਨ tcc_backtrace(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap;
    ਪੂਰਨ ret;

    ਜੇ (_tcc_backtrace) {
        rt_ਚੌਖਟਾ f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } ਨਹੀਂਤਾਂ {
        ਅਚਲ ਅੱਖਰ *p, *nl = "\n";
        ਜੇ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ਜੇ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    ਵਾਪਸ ret;
}

#ਜੇ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#ਹਦਾਇਤ GCC diagnostic ਕੱਢੋ
#ਜੇ_ਅੰਤ
