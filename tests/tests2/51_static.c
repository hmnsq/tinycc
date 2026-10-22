#অন্তর্ভাব <stdio.h>

স্থির পূর্ণাঙ্ক fred = 1234;
স্থির পূর্ণাঙ্ক joe;

শূন্য henry()
{
   স্থির পূর্ণাঙ্ক fred = 4567;

   printf("%d\n", fred);
   fred++;
}

পূর্ণাঙ্ক main()
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

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
