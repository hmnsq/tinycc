#ଅନ୍ତର୍ଭାଵ <stdio.h>

ଶୂନ୍ୟ fred(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
   ବାଛ (x)
   {
      ସ୍ଥିତି 1: printf("1\n"); ଫେରନ୍ତୁ;
      ସ୍ଥିତି 2: printf("2\n"); ଭାଙ୍ଗ;
      ସ୍ଥିତି 3: printf("3\n"); ଫେରନ୍ତୁ;
   }

   printf("out\n");
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   fred(1);
   fred(2);
   fred(3);

   ଫେରନ୍ତୁ 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
