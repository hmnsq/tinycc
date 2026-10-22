#include <stdio.h>

puur_naa_nka fred(puur_naa_nka p)
{
   printf("yo %d\n", p);
   ᨀᨘᨒ 42;
}

puur_naa_nka (*f)(puur_naa_nka) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
puur_naa_nka (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

puur_naa_nka main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ᨀᨘᨒ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
