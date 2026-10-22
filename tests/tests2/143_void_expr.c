#include <stdio.h>

static void f(ຈຳນວນເຕັມ x)
{
     printf("f(%d)\n", x);
}

ຈຳນວນເຕັມ main(void)
{
     ຈຳນວນເຕັມ count = 0, i = 0;
     ສຳລັບ (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ສົ່ງຄືນ count == 1 ? 0 : 1;
}
