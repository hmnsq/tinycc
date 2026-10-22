#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; puur_naa_nka mem[];
};
puur_naa_nka f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ᱨᱩᱣᱟᱹᱲ !s[0];
}
puur_naa_nka f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ᱨᱩᱣᱟᱹᱲ !s[0];
}
puur_naa_nka empty[] = {}; // GNU extension
puur_naa_nka main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ᱡᱩᱫᱤ (f1char() || f1int())
     printf ("bla\n");
   ᱨᱩᱣᱟᱹᱲ !s[0];
}
