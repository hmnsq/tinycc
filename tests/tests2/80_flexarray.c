#অন্তর্ভাব <stdio.h>
কাঠামো wchar {
    অক্ষর *তথ্য; অক্ষর mem[];
};
কাঠামো wint {
    অক্ষর *তথ্য; পূর্ণসংখ্যা mem[];
};
পূর্ণসংখ্যা f1char (শূন্য) {
    অক্ষর s[9]="nonono";
    কাঠামো wchar q = {"bugs"};
    ফেরত !s[0];
}
পূর্ণসংখ্যা f1int (শূন্য) {
    অক্ষর s[9]="nonono";
    কাঠামো wint q = {"bugs"};
    ফেরত !s[0];
}
পূর্ণসংখ্যা empty[] = {}; // GNU extension
পূর্ণসংখ্যা প্রধান (শূন্য) {
   অক্ষর s[9]="nonono";
   স্থির কাঠামো wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   যদি (f1char() || f1int())
     printf ("bla\n");
   ফেরত !s[0];
}
