// this file contains BMP chars encoded in UTF-8
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <wchar.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <string.h>

পূর্ণাঙ্ক main()
{
    বর্ণ hello_world_in_czech[] = "čau, světe";
    বর্ণ hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    যদি (পরিমাণ(hello_world_in_czech) != পরিমাণ(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    প্রতি (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    প্রত্যাগম 0;
}
