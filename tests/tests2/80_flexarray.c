#شامل <stdio.h>
ساخت wchar {
    حرف *ڈیٹا; حرف mem[];
};
ساخت wint {
    حرف *ڈیٹا; صحیح mem[];
};
صحیح f1char (خالی) {
    حرف s[9]="nonono";
    ساخت wchar q = {"bugs"};
    واپس !s[0];
}
صحیح f1int (خالی) {
    حرف s[9]="nonono";
    ساخت wint q = {"bugs"};
    واپس !s[0];
}
صحیح خالی_خانے[] = {}; // GNU extension
صحیح مین (خالی) {
   حرف s[9]="nonono";
   ساکن ساخت wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   اگر (f1char() || f1int())
     لکھو ("bla\n");
   واپس !s[0];
}
