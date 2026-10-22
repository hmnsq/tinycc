// this file contains BMP chars encoded in UTF-8
#ضمن <stdio.h>
#ضمن <wchar.h>
#ضمن <stdlib.h>
#ضمن <string.h>

صحيح main()
{
    حرف hello_world_in_czech[] = "čau, světe";
    حرف hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    ܐܢ (حجم(hello_world_in_czech) != حجم(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    لكل (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    ܦܢܐ 0;
}
