/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#અન્તર્ભાવ <stdarg.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#નહીંતર
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#જો (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ધકેલો
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

પ્રકારવ્યાખ્યા સંરચના rt_frame {
    શૂન્ય *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
પૂર્ણાંક _tcc_backtrace(rt_frame *f, અચલ અક્ષર *fmt, va_list ap);

DLL_EXPORT પૂર્ણાંક tcc_backtrace(અચલ અક્ષર *fmt, ...)
{
    va_list ap;
    પૂર્ણાંક ret;

    જો (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } નહીંતર {
        અચલ અક્ષર *p, *nl = "\n";
        જો (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        જો (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    પાછા ret;
}

#જો (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic કાઢો
#endif
