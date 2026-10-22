#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   পূর্ণাঙ্ক p;
   পূর্ণাঙ্ক t;

   a = 1;
   p = 0;
   t = 0;

   যাবত্ (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   প্রত্যাগম 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
