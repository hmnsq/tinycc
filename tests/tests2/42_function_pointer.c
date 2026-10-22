#include <stdio.h>

ចំនួនគត់ fred(ចំនួនគត់ p)
{
   printf("yo %d\n", p);
   ត្រឡប់ 42;
}

ចំនួនគត់ (*f)(ចំនួនគត់) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ចំនួនគត់ (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

ចំនួនគត់ main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
