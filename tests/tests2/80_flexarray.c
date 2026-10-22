#অন্তর্ভাৱ <stdio.h>
সংরচনা wchar {
    ৱর্ণ *data; ৱর্ণ mem[];
};
সংরচনা wint {
    ৱর্ণ *data; পূর্ণাঙ্ক mem[];
};
পূর্ণাঙ্ক f1char (শূন্য) {
    ৱর্ণ s[9]="nonono";
    সংরচনা wchar q = {"bugs"};
    ঘূৰাই !s[0];
}
পূর্ণাঙ্ক f1int (শূন্য) {
    ৱর্ণ s[9]="nonono";
    সংরচনা wint q = {"bugs"};
    ঘূৰাই !s[0];
}
পূর্ণাঙ্ক empty[] = {}; // GNU extension
পূর্ণাঙ্ক main (শূন্য) {
   ৱর্ণ s[9]="nonono";
   স্থির সংরচনা wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   যদি (f1char() || f1int())
     printf ("bla\n");
   ঘূৰাই !s[0];
}
