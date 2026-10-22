#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା *b;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା *c;

   a = 42;
   b = &a;
   c = ଖାଲି;

   printf("%d\n", *b);

   ଯଦି (b == ଖାଲି)
      printf("b is NULL\n");
   ଅନ୍ୟଥା
      printf("b is not NULL\n");

   ଯଦି (c == ଖାଲି)
      printf("c is NULL\n");
   ଅନ୍ୟଥା
      printf("c is not NULL\n");

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
