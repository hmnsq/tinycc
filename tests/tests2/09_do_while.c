#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   পূর্ণাঙ্ক p;
   পূর্ণাঙ্ক t;

   a = 1;
   p = 0;
   t = 0;

   কৰা
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } যেতিয়ালৈ (a < 100);

   ঘূৰাই 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
