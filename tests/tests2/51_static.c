#অন্তর্ভাব <stdio.h>

স্থির পূর্ণসংখ্যা fred = 1234;
স্থির পূর্ণসংখ্যা joe;

শূন্য henry()
{
   স্থির পূর্ণসংখ্যা fred = 4567;

   printf("%d\n", fred);
   fred++;
}

পূর্ণসংখ্যা প্রধান()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
