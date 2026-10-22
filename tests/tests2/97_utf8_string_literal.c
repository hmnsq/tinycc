// this file contains BMP chars encoded in UTF-8
#شامل <stdio.h>
#شامل <wchar.h>
#شامل <stdlib.h>
#شامل <string.h>

صحیح اصلی()
{
    نویسه hello_world_in_czech[] = "čau, světe";
    نویسه hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    اگر (اندازه(hello_world_in_czech) != اندازه(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    برای (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    بازگشت 0;
}
