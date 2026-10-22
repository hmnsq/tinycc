#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   ৱর্ণ b;

   a = 0;
   যেতিয়ালৈ (a < 2)
   {
      printf("%d", a++);
      ভঙ্গ;

      b = 'A';
      যেতিয়ালৈ (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
