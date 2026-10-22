// this file contains BMP chars encoded in UTF-8
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <wchar.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <string.h>

పూర్ణాంకం ప్రధాన()
{
    అక్షరం hello_world_లోపల_czech[] = "čau, světe";
    అక్షరం hello_world_లోపల_czech_ucn[] = "\u010dau, sv\u011bte";
    ఒకవేళ (పరిమాణం(hello_world_లోపల_czech) != పరిమాణం(hello_world_లోపల_czech_ucn)
            || strcmp(hello_world_లోపల_czech, hello_world_లోపల_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    కొరకు (p = s; *p; p++) రాయి("%04X ", (గుర్తులేని) *p);
    రాయి("\n");
    తిరిగి 0;
}
