#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক x = 'a';
   বর্ণ y = x;

   বর্ণ *a = "hello";

   printf("%s\n", a);

   পূর্ণাঙ্ক c;
   c = *a;

   বর্ণ *b;
   প্রতি (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   বর্ণ destarray[10];
   বর্ণ *dest = &destarray[0];
   বর্ণ *src = a;

   যাবত্ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
