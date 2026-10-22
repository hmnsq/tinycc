#ضمن <stdio.h>
بنية wchar {
    حرف *data; حرف mem[];
};
بنية wint {
    حرف *data; صحيح mem[];
};
صحيح f1char (فراغ) {
    حرف s[9]="nonono";
    بنية wchar q = {"bugs"};
    החזר !s[0];
}
صحيح f1int (فراغ) {
    حرف s[9]="nonono";
    بنية wint q = {"bugs"};
    החזר !s[0];
}
صحيح empty[] = {}; // GNU extension
صحيح main (فراغ) {
   حرف s[9]="nonono";
   ساكن بنية wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   אם (f1char() || f1int())
     printf ("bla\n");
   החזר !s[0];
}
