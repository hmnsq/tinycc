#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
ਬਣਤਰ wchar {
    ਅੱਖਰ *ਅੰਕੜੇ; ਅੱਖਰ mem[];
};
ਬਣਤਰ wint {
    ਅੱਖਰ *ਅੰਕੜੇ; ਪੂਰਨ mem[];
};
ਪੂਰਨ f1char (ਖਾਲੀ) {
    ਅੱਖਰ s[9]="nonono";
    ਬਣਤਰ wchar q = {"bugs"};
    ਵਾਪਸ !s[0];
}
ਪੂਰਨ f1int (ਖਾਲੀ) {
    ਅੱਖਰ s[9]="nonono";
    ਬਣਤਰ wint q = {"bugs"};
    ਵਾਪਸ !s[0];
}
ਪੂਰਨ ਖਾਲੀ_ਥਾਵਾਂ[] = {}; // GNU extension
ਪੂਰਨ ਮੁੱਖ (ਖਾਲੀ) {
   ਅੱਖਰ s[9]="nonono";
   ਸਥਿਰ ਬਣਤਰ wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ਜੇ (f1char() || f1int())
     ਲਿਖੋ ("bla\n");
   ਵਾਪਸ !s[0];
}
