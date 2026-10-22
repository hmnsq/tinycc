#include <stdio.h>

ཧྲིལ fred(ཧྲིལ p)
{
   printf("yo %d\n", p);
   ཕྱིར 42;
}

ཧྲིལ (*f)(ཧྲིལ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ཧྲིལ (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

ཧྲིལ གཙོ()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
