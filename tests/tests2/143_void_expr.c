#include <stdio.h>

static void f(int x)
{
     printf("f(%d)\n", x);
}

int main(void)
{
     int बिलांग_2 = 0, i = 0;
     for (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++बिलांग_2));
     }
     printf("count %d\n", बिलांग_2);
     return बिलांग_2 == 1 ? 0 : 1;
}
