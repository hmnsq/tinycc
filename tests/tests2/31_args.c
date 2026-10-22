#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_4;

   printf("hello world %d\n", argc);
   ପାଇଁ (ଗଣନା_4 = 1; ଗଣନା_4 < argc; ଗଣନା_4++)
      printf("arg %d: %s\n", ଗଣନା_4, argv[ଗଣନା_4]);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
