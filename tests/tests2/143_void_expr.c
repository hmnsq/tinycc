#include <stdio.h>

static void f(ကိန်းပြည့် x)
{
     printf("f(%d)\n", x);
}

ကိန်းပြည့် main(void)
{
     ကိန်းပြည့် count = 0, i = 0;
     အတွက် (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ပြန်ပေး count == 1 ? 0 : 1;
}
