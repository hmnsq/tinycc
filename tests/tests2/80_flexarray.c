#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; จำนวนเต็ม mem[];
};
จำนวนเต็ม f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    คืน !s[0];
}
จำนวนเต็ม f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    คืน !s[0];
}
จำนวนเต็ม empty[] = {}; // GNU extension
จำนวนเต็ม หลัก (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ถ้า (f1char() || f1int())
     printf ("bla\n");
   คืน !s[0];
}
