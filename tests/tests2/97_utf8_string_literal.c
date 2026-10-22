// this file contains BMP chars encoded in UTF-8
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <wchar.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

ਪੂਰਨ ਮੁੱਖ()
{
    ਅੱਖਰ hello_world_ਵਿੱਚ_czech[] = "čau, světe";
    ਅੱਖਰ hello_world_ਵਿੱਚ_czech_ucn[] = "\u010dau, sv\u011bte";
    ਜੇ (ਆਕਾਰ(hello_world_ਵਿੱਚ_czech) != ਆਕਾਰ(hello_world_ਵਿੱਚ_czech_ucn)
            || strcmp(hello_world_ਵਿੱਚ_czech, hello_world_ਵਿੱਚ_czech_ucn))
        abort();

    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    ਲਈ (p = s; *p; p++) ਲਿਖੋ("%04X ", (ਬਿਨਾਨਿਸ਼ਾਨੀ) *p);
    ਲਿਖੋ("\n");
    ਵਾਪਸ 0;
}
