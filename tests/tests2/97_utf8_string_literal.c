// this file contains BMP chars encoded in UTF-8
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

ចំនួនគត់ main()
{
    var_na hello_world_in_czech[] = "čau, světe";
    var_na hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    ប្រសិនបើ (parimaa_na(hello_world_in_czech) != parimaa_na(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    សម្រាប់ (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    ត្រឡប់ 0;
}
