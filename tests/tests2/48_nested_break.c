#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
   ଅକ୍ଷର b;

   a = 0;
   ଯେତେବେଳେ (a < 2)
   {
      printf("%d", a++);
      ଭାଙ୍ଗ;

      b = 'A';
      ଯେତେବେଳେ (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
