#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক factorial(পূর্ণাঙ্ক i) 
{
   যদি (i < 2)
      ঘূৰাই i;
   অন্যথা
      ঘূৰাই i * factorial(i - 1);
}

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক গুনতি_3;

   বাবে (গুনতি_3 = 1; গুনতি_3 <= 10; গুনতি_3++)
      printf("%d\n", factorial(গুনতি_3));

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
