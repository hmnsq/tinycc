#include <stdio.h>

ကိန်းပြည့် fred(ကိန်းပြည့် p)
{
   printf("yo %d\n", p);
   ပြန်ပေး 42;
}

ကိန်းပြည့် (*f)(ကိန်းပြည့်) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ကိန်းပြည့် (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

ကိန်းပြည့် main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
