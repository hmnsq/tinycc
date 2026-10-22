/* ------------------------------------------------------------- */
/* function to get a stack backtrace on demand with a message */

#समावेश <stdarg.h>
#समावेश <stdio.h>
#समावेश <string.h>
#अघोषित __attribute__

#अगर_घोषित _WIN32
# define DLL_EXPORT __declspec(dllexport)
#अन्यथा
# define DLL_EXPORT
#पूर्ण_अगर

/* Needed when using ...libtcc1-usegcc=yes in lib/Makefile */
#अगर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#आशय GCC diagnostic धकेलो
#आशय GCC diagnostic ignored "-Wframe-address"
#पूर्ण_अगर

प्रकार काष्ठा rt_frame {
    व्योम *ip, *fp, *sp;
} rt_frame;

__attribute__((weak))
पूर्णांक _tcc_backtrace(rt_frame *f, स्थिर अक्षर *fmt, बहु_सूची ap);

DLL_EXPORT पूर्णांक tcc_backtrace(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap;
    पूर्णांक ret;

    अगर (_tcc_backtrace) {
        rt_frame f;
        f.fp = __builtin_frame_address(1);
        f.ip = __builtin_return_address(0);
        बहु_शुरू(ap, fmt);
        ret = _tcc_backtrace(&f, fmt, ap);
        बहु_पूर्ण(ap);
    } अन्यथा {
        स्थिर अक्षर *p, *nl = "\n";
        अगर (fmt[0] == '^' && (p = म_अक्षर(fmt + 1, fmt[0])))
            fmt = p + 1;
        अगर (fmt[0] == '\001')
            ++fmt, nl = "";
        बहु_शुरू(ap, fmt);
        ret = भख_लिखो(मानक_त्रुटि, fmt, ap);
        बहु_पूर्ण(ap);
        ख_लिखो(मानक_त्रुटि, "%s", nl), ख_साफ(मानक_त्रुटि);
    }
    वापस ret;
}

#अगर (defined(__GNUC__) && (__GNUC__ >= 6)) || defined(__clang__)
#आशय GCC diagnostic निकालो
#पूर्ण_अगर
