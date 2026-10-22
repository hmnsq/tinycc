#ضمن <stdio.h>
بنية wchar {
    حرف *انکڑے; حرف mem[];
};
بنية wint {
    حرف *انکڑے; صحيح mem[];
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
صحيح خالی_تھاواں[] = {}; // GNU extension
صحيح مکھ (فراغ) {
   حرف s[9]="nonono";
   ساكن بنية wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   إذا (f1char() || f1int())
     لکھو ("bla\n");
   أرجع !s[0];
}
