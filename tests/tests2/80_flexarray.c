#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; ཧྲིལ mem[];
};
ཧྲིལ f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ཕྱིར !s[0];
}
ཧྲིལ f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ཕྱིར !s[0];
}
ཧྲིལ empty[] = {}; // GNU extension
ཧྲིལ གཙོ (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   གལ་ཏེ (f1char() || f1int())
     printf ("bla\n");
   ཕྱིར !s[0];
}
