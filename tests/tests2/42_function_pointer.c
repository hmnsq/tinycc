#include <stdio.h>

정수 fred(정수 p)
{
   printf("yo %d\n", p);
   반환 42;
}

정수 (*f)(정수) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
정수 (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

정수 main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
