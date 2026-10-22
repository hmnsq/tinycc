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
    ལོག !s[0];
}
ཧྲིལ f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ལོག !s[0];
}
ཧྲིལ empty[] = {}; // GNU extension
ཧྲིལ main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   གལ་སྲིད (f1char() || f1int())
     printf ("bla\n");
   ལོག !s[0];
}
