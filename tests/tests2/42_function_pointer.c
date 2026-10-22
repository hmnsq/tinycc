#include <stdio.h>

ཧྲིལ fred(ཧྲིལ p)
{
   printf("yo %d\n", p);
   ལོག 42;
}

ཧྲིལ (*f)(ཧྲིལ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ཧྲིལ (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

ཧྲིལ main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
