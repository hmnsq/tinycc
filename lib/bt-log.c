/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#అన్తర్భావ <stdarg.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#నిర్వచనం_రద్దు __attribute__

#నిర్వచితమైతే _WIN32
# define DLL_EXPORT __declspec(dllexport)
#లేకపోతే
# define DLL_EXPORT
#అయితే_ముగింపు

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#ఒకవేళ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#సూచన GCC diagnostic నెట్టు
#సూచన GCC diagnostic ignored "-Wframe-address"
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం rt_చట్రం {
    శూన్య *ip, *fp, *sp;
} rt_చట్రం;

__attribute__((weak))
పూర్ణాంకం _tcc_backtrace(rt_చట్రం *f, స్థిరరాశి అక్షరం *fmt, va_list ap);

DLL_EXPORT పూర్ణాంకం tcc_backtrace(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap;
    పూర్ణాంకం ret;

    ఒకవేళ (_tcc_backtrace) {
        rt_చట్రం f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } లేకపోతే {
        స్థిరరాశి అక్షరం *p, *nl = "\n";
        ఒకవేళ (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        ఒకవేళ (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    తిరిగి ret;
}

#ఒకవేళ (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#సూచన GCC diagnostic తీయి
#అయితే_ముగింపు
