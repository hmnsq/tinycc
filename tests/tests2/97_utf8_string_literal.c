// this file contains BMP chars encoded in UTF-8
#ضمن <stdio.h>
#ضمن <wchar.h>
#ضمن <stdlib.h>
#ضمن <string.h>

صحيح مکيه()
{
    حرف hello_world_اندريون_czech[] = "čau, světe";
    حرف hello_world_اندريون_czech_ucn[] = "\u010dau, sv\u011bte";
    إذا (حجم(hello_world_اندريون_czech) != حجم(hello_world_اندريون_czech_ucn)
            || strcmp(hello_world_اندريون_czech, hello_world_اندريون_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    لكل (p = s; *p; p++) لکو("%04X ", (بنانشان) *p);
    لکو("\n");
    أرجع 0;
}
