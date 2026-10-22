// this file contains BMP chars encoded in UTF-8
#شامل <stdio.h>
#شامل <wchar.h>
#شامل <stdlib.h>
#شامل <string.h>

صحیح مین()
{
    حرف hello_world_اندر_czech[] = "čau, světe";
    حرف hello_world_اندر_czech_ucn[] = "\u010dau, sv\u011bte";
    اگر (حجم(hello_world_اندر_czech) != حجم(hello_world_اندر_czech_ucn)
            || strcmp(hello_world_اندر_czech, hello_world_اندر_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    برائے (p = s; *p; p++) لکھو("%04X ", (غیرعلامتی) *p);
    لکھو("\n");
    واپس 0;
}
