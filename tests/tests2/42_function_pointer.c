#include <stdio.h>

ຈຳນວນເຕັມ fred(ຈຳນວນເຕັມ p)
{
   printf("yo %d\n", p);
   ສົ່ງຄືນ 42;
}

ຈຳນວນເຕັມ (*f)(ຈຳນວນເຕັມ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ຈຳນວນເຕັມ (*fprintfptr)(FILE *, const var_na *, ...) = &fprintf;

ຈຳນວນເຕັມ main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
