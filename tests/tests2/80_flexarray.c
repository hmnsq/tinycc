#include <stdio.h>
sa_nracanaa wchar {
    var_na *data; var_na mem[];
};
sa_nracanaa wint {
    var_na *data; පූර්ණ_සංඛ්‍යා mem[];
};
පූර්ණ_සංඛ්‍යා f1char (void) {
    var_na s[9]="nonono";
    sa_nracanaa wchar q = {"bugs"};
    ආපසු !s[0];
}
පූර්ණ_සංඛ්‍යා f1int (void) {
    var_na s[9]="nonono";
    sa_nracanaa wint q = {"bugs"};
    ආපසු !s[0];
}
පූර්ණ_සංඛ්‍යා empty[] = {}; // GNU extension
පූර්ණ_සංඛ්‍යා main (void) {
   var_na s[9]="nonono";
   static sa_nracanaa wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   නම් (f1char() || f1int())
     printf ("bla\n");
   ආපසු !s[0];
}
