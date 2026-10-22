// this file contains BMP chars encoded in UTF-8
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <wchar.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <string.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಅಕ್ಷರ hello_world_ಒಳ_czech[] = "čau, světe";
    ಅಕ್ಷರ hello_world_ಒಳ_czech_ucn[] = "\u010dau, sv\u011bte";
    ಆದರೆ (ಗಾತ್ರ(hello_world_ಒಳ_czech) != ಗಾತ್ರ(hello_world_ಒಳ_czech_ucn)
            || strcmp(hello_world_ಒಳ_czech, hello_world_ಒಳ_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    ಗಾಗಿ (p = s; *p; p++) ಬರೆ("%04X ", (ಚಿಹ್ನೆರಹಿತ) *p);
    ಬರೆ("\n");
    ಹಿಂತಿರುಗಿ 0;
}
