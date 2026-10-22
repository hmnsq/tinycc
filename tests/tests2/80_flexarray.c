#അന്തര്ഭാവ <stdio.h>
ഘടന wchar {
    അക്ഷരം *data; അക്ഷരം mem[];
};
ഘടന wint {
    അക്ഷരം *data; പൂർണ്ണസംഖ്യ mem[];
};
പൂർണ്ണസംഖ്യ f1char (ശൂന്യം) {
    അക്ഷരം s[9]="nonono";
    ഘടന wchar q = {"bugs"};
    തിരികെ !s[0];
}
പൂർണ്ണസംഖ്യ f1int (ശൂന്യം) {
    അക്ഷരം s[9]="nonono";
    ഘടന wint q = {"bugs"};
    തിരികെ !s[0];
}
പൂർണ്ണസംഖ്യ empty[] = {}; // GNU extension
പൂർണ്ണസംഖ്യ പ്രധാന (ശൂന്യം) {
   അക്ഷരം s[9]="nonono";
   സ്ഥിതം ഘടന wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   എങ്കിൽ (f1char() || f1int())
     printf ("bla\n");
   തിരികെ !s[0];
}
