#ضمن <stdio.h>
بنية wchar {
    حرف *معلومات; حرف mem[];
};
بنية wint {
    حرف *معلومات; صحيح mem[];
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
صحيح خالي_جايون[] = {}; // GNU extension
صحيح مکيه (فراغ) {
   حرف s[9]="nonono";
   ساكن بنية wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   إذا (f1char() || f1int())
     لکو ("bla\n");
   أرجع !s[0];
}
