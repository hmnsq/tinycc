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
            || म_भेद(hello_world_in_czech, hello_world_in_czech_ucn))
        पात();

    ब_अक्षर_प्रकार s[] = L"hello$$你好¢¢世界€€world";
    ब_अक्षर_प्रकार *p;
    प्रति (p = s; *p; p++) म_लिखो("%04X ", (अचिन्हित) *p);
    म_लिखो("\n");
    प्रत्यागम 0;
}
