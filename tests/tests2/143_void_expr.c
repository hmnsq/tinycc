#include <stdio.h>

static void f(ཧྲིལ x)
{
     printf("f(%d)\n", x);
}

ཧྲིལ གཙོ(void)
{
     ཧྲིལ count = 0, i = 0;
     ཆེད་དུ (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ཕྱིར count == 1 ? 0 : 1;
}
