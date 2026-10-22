#include <stdio.h>

ціле fred(ціле p)
{
   printf("yo %d\n", p);
   повернути 42;
}

ціле (*f)(ціле) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ціле (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

ціле main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
