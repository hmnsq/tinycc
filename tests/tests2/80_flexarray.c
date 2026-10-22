#شامل <stdio.h>
ساختار wchar {
    نویسه *data; نویسه mem[];
};
ساختار wint {
    نویسه *data; صحیح mem[];
};
صحیح f1char (تهی) {
    نویسه s[9]="nonono";
    ساختار wchar q = {"bugs"};
    بازگشت !s[0];
}
صحیح f1int (تهی) {
    نویسه s[9]="nonono";
    ساختار wint q = {"bugs"};
    بازگشت !s[0];
}
صحیح empty[] = {}; // GNU extension
صحیح اصلی (تهی) {
   نویسه s[9]="nonono";
   ایستا ساختار wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   اگر (f1char() || f1int())
     printf ("bla\n");
   بازگشت !s[0];
}
