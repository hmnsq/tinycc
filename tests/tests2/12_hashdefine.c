#include <stdio.h>

#define FRED 12
#define BLOGGS(x) (12*(x))

цяло main()
{
   printf("%d\n", FRED);
   printf("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));

   върни 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
