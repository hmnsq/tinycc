#অন্তর্ভাব <stdio.h>
সংরচনা wchar {
    বর্ণ *data; বর্ণ mem[];
};
সংরচনা wint {
    বর্ণ *data; পূর্ণাঙ্ক mem[];
};
পূর্ণাঙ্ক f1char (শূন্য) {
    বর্ণ s[9]="nonono";
    সংরচনা wchar q = {"bugs"};
    প্রত্যাগম !s[0];
}
পূর্ণাঙ্ক f1int (শূন্য) {
    বর্ণ s[9]="nonono";
    সংরচনা wint q = {"bugs"};
    প্রত্যাগম !s[0];
}
পূর্ণাঙ্ক empty[] = {}; // GNU extension
পূর্ণাঙ্ক main (শূন্য) {
   বর্ণ s[9]="nonono";
   স্থির সংরচনা wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   যদি (f1char() || f1int())
     printf ("bla\n");
   প্রত্যাগম !s[0];
}
