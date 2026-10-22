/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#அந்தர்பாவ <stdarg.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#இல்லையெனில்
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#எனில் (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic தள்ளு
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

வகைவரை கட்டமைப்பு rt_frame {
    வெறுமை *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
முழு _tcc_backtrace(rt_frame *f, மாறிலி எழுத்து *fmt, va_list ap);

DLL_EXPORT முழு tcc_backtrace(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap;
    முழு ret;

    எனில் (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } இல்லையெனில் {
        மாறிலி எழுத்து *p, *nl = "\n";
        எனில் (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        எனில் (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    திரும்பு ret;
}

#எனில் (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic எடு
#endif
