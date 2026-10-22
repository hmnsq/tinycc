#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা a;
   অক্ষর b;

   a = 0;
   যখন (a < 2)
   {
      printf("%d", a++);
      বিরতি;

      b = 'A';
      যখন (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
