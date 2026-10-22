#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fred(ପୂର୍ଣ୍ଣସଂଖ୍ୟା p)
{
   printf("yo %d\n", p);
   ଫେରନ୍ତୁ 42;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*f)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*fprintfptr)(FILE *, ଅଚଳ ଅକ୍ଷର *, ...) = &fprintf;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
