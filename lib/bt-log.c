/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#अन्तर्भाव <stdarg.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अञ्ञथा
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#सचे (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic प्रक्षिप
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

प्रकारनिर्देश संरचना rt_frame {
    शून्य *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
पूर्णाङ्क _tcc_backtrace(rt_frame *f, ध्रुव वर्ण *fmt, va_list ap);

DLL_EXPORT पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    पूर्णाङ्क ret;

    सचे (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        va_start(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        va_end(ap);
    } अञ्ञथा {
        ध्रुव वर्ण *p, *nl = "\n";
        सचे (fmt[0] == '^' && (p = strchr(fmt + 1, fmt[0])))
            fmt = p + 1;
        सचे (fmt[0] == '\001')
            ++fmt, nl = "";
        va_start(ap, fmt);
        ret = vfprintf(stderr, fmt, ap);
        va_end(ap);
        fprintf(stderr, "%s", nl), fflush(stderr);
    }
    पटिनिवत्त ret;
}

#सचे (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic निष्कासय
#endif
