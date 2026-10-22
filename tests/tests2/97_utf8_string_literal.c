// this file contains BMP chars encoded in UTF-8
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <wchar.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <string.h>

પૂર્ણાંક મુખ્ય()
{
    અક્ષર hello_world_in_czech[] = "čau, světe";
    અક્ષર hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    જો (કદ(hello_world_in_czech) != કદ(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    માટે (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    પાછા 0;
}
