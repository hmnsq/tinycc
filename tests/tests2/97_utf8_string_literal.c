// this file contains BMP chars encoded in UTF-8
#समावेश <stdio.h>
#समावेश <wchar.h>
#समावेश <stdlib.h>
#समावेश <string.h>

पूर्णांक मुख्य()
{
    अक्षर hello_world_in_czech[] = "čau, světe";
    अक्षर hello_world_in_czech_ucn[] = "\u010dau, sv\u011bte";
    अगर (माप(hello_world_in_czech) != माप(hello_world_in_czech_ucn)
            || म_भेद(hello_world_in_czech, hello_world_in_czech_ucn))
        पात();

    ब_अक्षर_प्रकार s[] = L"hello$$你好¢¢世界€€world";
    ब_अक्षर_प्रकार *p;
    क्रम (p = s; *p; p++) म_लिखो("%04X ", (अचिन्हित) *p);
    म_लिखो("\n");
    वापस 0;
}
