#ضمن <stdio.h>
بنية wchar {
    حرف *داده; حرف mem[];
};
بنية wint {
    حرف *داده; صحيح mem[];
};
صحيح f1char (فراغ) {
    حرف s[9]="nonono";
    بنية wchar q = {"bugs"};
    أرجع !s[0];
}
صحيح f1int (فراغ) {
    حرف s[9]="nonono";
    بنية wint q = {"bugs"};
    أرجع !s[0];
}
صحيح خالی[] = {}; // GNU extension
صحيح اصلی (فراغ) {
   حرف s[9]="nonono";
   ساكن بنية wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   إذا (f1char() || f1int())
     چاپ_کن ("bla\n");
   أرجع !s[0];
}
