// this file contains BMP chars encoded in UTF-8
#ضمن <stdio.h>
#ضمن <wchar.h>
#ضمن <stdlib.h>
#ضمن <string.h>

صحيح اصلی()
{
    حرف hello_world_درون_czech[] = "čau, světe";
    حرف hello_world_درون_czech_ucn[] = "\u010dau, sv\u011bte";
    إذا (حجم(hello_world_درون_czech) != حجم(hello_world_درون_czech_ucn)
            || strcmp(hello_world_درون_czech, hello_world_درون_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    لكل (p = s; *p; p++) چاپ_کن("%04X ", (بیعلامت) *p);
    چاپ_کن("\n");
    أرجع 0;
}
