// this file contains BMP chars encoded in UTF-8
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <wchar.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <string.h>

पूर्णांक main()
{
    अक्षर hello_world_in_czech[] = "čau, světe";
    अक्षर hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    जर (आकार(hello_world_in_czech) != आकार(hello_world_in_czech_ucn)
            || म_भेद(hello_world_in_czech, hello_world_in_czech_ucn))
        पात();

    ब_अक्षर_प्रकार s[] = L"hello$$你好¢¢世界€€world";
    ब_अक्षर_प्रकार *p;
    साठी (p = s; *p; p++) म_लिखो("%04X ", (अचिन्हित) *p);
    म_लिखो("\n");
    परत 0;
}
