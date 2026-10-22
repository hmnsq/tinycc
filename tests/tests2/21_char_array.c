#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক x = 'a';
   ৱর্ণ y = x;

   ৱর্ণ *a = "hello";

   printf("%s\n", a);

   পূর্ণাঙ্ক c;
   c = *a;

   ৱর্ণ *b;
   বাবে (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   ৱর্ণ destarray[10];
   ৱর্ণ *dest = &destarray[0];
   ৱর্ণ *src = a;

   যেতিয়ালৈ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
