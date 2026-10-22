#include <stdio.h>

จำนวนเต็ม fred(จำนวนเต็ม p)
{
   printf("yo %d\n", p);
   คืน 42;
}

จำนวนเต็ม (*f)(จำนวนเต็ม) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
จำนวนเต็ม (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

จำนวนเต็ม หลัก()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
