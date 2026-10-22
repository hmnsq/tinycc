#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା fred = 1234;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା joe;

ଶୂନ୍ୟ henry()
{
   ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
