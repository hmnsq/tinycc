// this file contains BMP chars encoded in UTF-8
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <wchar.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <string.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଅକ୍ଷର hello_world_in_czech[] = "čau, světe";
    ଅକ୍ଷର hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    ଯଦି (ଆକାର(hello_world_in_czech) != ଆକାର(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    ପାଇଁ (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    ଫେରନ୍ତୁ 0;
}
