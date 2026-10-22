#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; ចំនួនគត់ mem[];
};
ចំនួនគត់ f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ត្រឡប់ !s[0];
}
ចំនួនគត់ f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ត្រឡប់ !s[0];
}
ចំនួនគត់ empty[] = {}; // GNU extension
ចំនួនគត់ main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ប្រសិនបើ (f1char() || f1int())
     printf ("bla\n");
   ត្រឡប់ !s[0];
}
