#include <stdio.h>

පූර්ණ_සංඛ්‍යා fred(පූර්ණ_සංඛ්‍යා p)
{
   printf("yo %d\n", p);
   ආපසු 42;
}

පූර්ණ_සංඛ්‍යා (*f)(පූර්ණ_සංඛ්‍යා) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
පූර්ණ_සංඛ්‍යා (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

පූර්ණ_සංඛ්‍යා main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
