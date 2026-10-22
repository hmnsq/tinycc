#include <stdio.h>

static void f(ཧྲིལ x)
{
     printf("f(%d)\n", x);
}

ཧྲིལ main(void)
{
     ཧྲིལ count = 0, i = 0;
     དོན་ལུ (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ལོག count == 1 ? 0 : 1;
}
