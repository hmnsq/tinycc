#include <stdio.h>

цяло fred(цяло p)
{
   printf("yo %d\n", p);
   върни 42;
}

цяло (*f)(цяло) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
цяло (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

цяло main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
