// this file contains BMP chars encoded in UTF-8
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <wchar.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <string.h>

पूर्णाङ्क main()
{
    वर्ण hello_world_in_czech[] = "čau, světe";
    वर्ण hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    यदि (परिमाण(hello_world_in_czech) != परिमाण(hello_world_in_czech_ucn)
            || strcmp(hello_world_in_czech, hello_world_in_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    प्रति (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    प्रत्यागम 0;
}
