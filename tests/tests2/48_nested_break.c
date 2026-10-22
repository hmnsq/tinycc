#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક a;
   અક્ષર b;

   a = 0;
   જ્યારે (a < 2)
   {
      printf("%d", a++);
      તોડો;

      b = 'A';
      જ્યારે (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
