// this file contains BMP chars encoded in UTF-8
#ضمن <stdio.h>
#ضمن <wchar.h>
#ضمن <stdlib.h>
#ضمن <string.h>

صحيح اصلي()
{
    حرف hello_world_دننه_czech[] = "čau, světe";
    حرف hello_world_دننه_czech_ucn[] = "\u010dau, sv\u011bte";
    إذا (حجم(hello_world_دننه_czech) != حجم(hello_world_دننه_czech_ucn)
            || strcmp(hello_world_دننه_czech, hello_world_دننه_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    لكل (p = s; *p; p++) چاپ_کړه("%04X ", (بینښه) *p);
    چاپ_کړه("\n");
    أرجع 0;
}
