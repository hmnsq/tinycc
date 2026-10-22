// this file contains BMP chars encoded in UTF-8
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <wchar.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <string.h>

পূর্ণসংখ্যা প্রধান()
{
    অক্ষর hello_world_in_czech[] = "čau, světe";
    অক্ষর hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    যদি (আকার(hello_world_in_czech) != আকার(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    জন্য (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    ফেরত 0;
}
