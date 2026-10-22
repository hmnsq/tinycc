#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   পূর্ণাঙ্ক *b;
   পূর্ণাঙ্ক *c;

   a = 42;
   b = &a;
   c = রিক্ত;

   printf("%d\n", *b);

   যদি (b == রিক্ত)
      printf("b is NULL\n");
   অন্যথা
      printf("b is not NULL\n");

   যদি (c == রিক্ত)
      printf("c is NULL\n");
   অন্যথা
      printf("c is not NULL\n");

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
