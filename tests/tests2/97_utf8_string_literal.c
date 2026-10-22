// this file contains BMP chars encoded in UTF-8
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <wchar.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <string.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
    ವರ್ಣ hello_world_in_czech[] = "čau, světe";
    ವರ್ಣ hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    ಯದಿ (ಪರಿಮಾಣ(hello_world_in_czech) != ಪರಿಮಾಣ(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    ಪ್ರತಿ (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    ಪ್ರತ್ಯಾಗಮ 0;
}
