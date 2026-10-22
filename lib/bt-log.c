/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#अन्तर्भाव <stdarg.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#undef __attribute__

#ifdef _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अन्यथा
# define DLL_EXPORT
#endif

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#जर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic ढकला
#pragma GCC diagnostic ignored "-Wframe-address"
#endif

प्रकारव्याख्या संरचना rt_frame {
    शून्य *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
पूर्णांक _tcc_backtrace(rt_frame *f, स्थिरांक अक्षर *fmt, बहु_सूची ap);

DLL_EXPORT पूर्णांक tcc_backtrace(स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap;
    पूर्णांक ret;

    जर (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        बहु_शुरू(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        बहु_पूर्ण(ap);
    } अन्यथा {
        स्थिरांक अक्षर *p, *nl = "\n";
        जर (fmt[0] == '^' && (p = म_अक्षर(fmt + 1, fmt[0])))
            fmt = p + 1;
        जर (fmt[0] == '\001')
            ++fmt, nl = "";
        बहु_शुरू(ap, fmt);
        ret = भख_लिखो(मानक_त्रुटि, fmt, ap);
        बहु_पूर्ण(ap);
        ख_लिखो(मानक_त्रुटि, "%s", nl), ख_साफ(मानक_त्रुटि);
    }
    परत ret;
}

#जर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#pragma GCC diagnostic काढा
#endif
