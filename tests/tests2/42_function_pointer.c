#include <stdio.h>

цео fred(цео p)
{
   printf("yo %d\n", p);
   врати 42;
}

цео (*f)(цео) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
цео (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

цео main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
