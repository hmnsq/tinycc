#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   বর্ণ b;

   a = 0;
   যাবত্ (a < 2)
   {
      printf("%d", a++);
      ভঙ্গ;

      b = 'A';
      যাবত্ (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
