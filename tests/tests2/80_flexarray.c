#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; ຈຳນວນເຕັມ mem[];
};
ຈຳນວນເຕັມ f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ສົ່ງຄືນ !s[0];
}
ຈຳນວນເຕັມ f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ສົ່ງຄືນ !s[0];
}
ຈຳນວນເຕັມ empty[] = {}; // GNU extension
ຈຳນວນເຕັມ main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ຖ້າ (f1char() || f1int())
     printf ("bla\n");
   ສົ່ງຄືນ !s[0];
}
