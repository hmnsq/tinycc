// this file contains BMP chars encoded in UTF-8
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <wchar.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <string.h>

முழு முதன்மை()
{
    எழுத்து hello_world_in_czech[] = "čau, světe";
    எழுத்து hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    எனில் (அளவு(hello_world_in_czech) != அளவு(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    க்கு (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    திரும்பு 0;
}
