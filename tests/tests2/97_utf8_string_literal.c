// this file contains BMP chars encoded in UTF-8
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <wchar.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <string.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    അക്ഷരം hello_world_in_czech[] = "čau, světe";
    അക്ഷരം hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    എങ്കിൽ (വലുപ്പം(hello_world_in_czech) != വലുപ്പം(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    വേണ്ടി (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    തിരികെ 0;
}
