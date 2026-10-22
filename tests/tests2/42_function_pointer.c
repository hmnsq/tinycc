#include <stdio.h>

整数 fred(整数 p)
{
   printf("yo %d\n", p);
   戻る 42;
}

整数 (*f)(整数) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
整数 (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

整数 メインページ()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
