#include <stdio.h>

целое fred(целое p)
{
   printf("yo %d\n", p);
   вернуть 42;
}

целое (*f)(целое) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
целое (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

целое основной()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
