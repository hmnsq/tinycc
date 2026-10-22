#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা x = 'a';
   অক্ষর y = x;

   অক্ষর *a = "hello";

   printf("%s\n", a);

   পূর্ণসংখ্যা c;
   c = *a;

   অক্ষর *b;
   জন্য (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   অক্ষর destarray[10];
   অক্ষর *dest = &destarray[0];
   অক্ষর *src = a;

   যখন (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
