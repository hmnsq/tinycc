#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; ကိန်းပြည့် mem[];
};
ကိန်းပြည့် f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ပြန်ပေး !s[0];
}
ကိန်းပြည့် f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ပြန်ပေး !s[0];
}
ကိန်းပြည့် empty[] = {}; // GNU extension
ကိန်းပြည့် main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   အကယ်၍ (f1char() || f1int())
     printf ("bla\n");
   ပြန်ပေး !s[0];
}
