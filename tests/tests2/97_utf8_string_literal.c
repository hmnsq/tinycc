// this file contains BMP chars encoded in UTF-8
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

整数 メインページ()
{
    char hello_world_in_czech[] = "čau, světe";
    char hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    もし (sizeof(hello_world_in_czech) != sizeof(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    ために (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    戻る 0;
}
