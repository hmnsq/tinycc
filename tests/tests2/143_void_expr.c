#include <stdio.h>

static void f(puur_naa_nka x)
{
     printf("f(%d)\n", x);
}

puur_naa_nka main(void)
{
     puur_naa_nka count = 0, i = 0;
     for (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ᨀᨘᨒ count == 1 ? 0 : 1;
}
