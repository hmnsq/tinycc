#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 'a';
   ଅକ୍ଷର y = x;

   ଅକ୍ଷର *a = "hello";

   printf("%s\n", a);

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
   c = *a;

   ଅକ୍ଷର *b;
   ପାଇଁ (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   ଅକ୍ଷର destarray[10];
   ଅକ୍ଷର *dest = &destarray[0];
   ଅକ୍ଷର *src = a;

   ଯେତେବେଳେ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
