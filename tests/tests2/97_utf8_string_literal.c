// this file contains BMP chars encoded in UTF-8
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <wchar.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <string.h>

पूर्णाङ्क मुख्यम्()
{
    वर्ण hello_world_अन्तर्_czech[] = "čau, světe";
    वर्ण hello_world_अन्तर्_czech_ucn[] = "\u010dau, sv\u011bte";
    यदि (परिमाण(hello_world_अन्तर्_czech) != परिमाण(hello_world_अन्तर्_czech_ucn)
            || वाक्यं_तुलय(hello_world_अन्तर्_czech, hello_world_अन्तर्_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    प्रति (p = s; *p; p++) प्रारूप_लिख("%04X ", (अचिह्नित) *p);
    प्रारूप_लिख("\n");
    प्रत्यागम 0;
}
