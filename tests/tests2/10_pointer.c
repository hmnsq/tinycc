#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂରଚନା ziggy
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
} bolshevic;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା *b;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;

   a = 42;
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   ସଂରଚନା ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   ଫେରନ୍ତୁ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
