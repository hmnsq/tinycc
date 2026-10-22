#include <stdio.h>

số_nguyên fred(số_nguyên p)
{
   printf("yo %d\n", p);
   trả_về 42;
}

số_nguyên (*f)(số_nguyên) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
số_nguyên (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

số_nguyên main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
