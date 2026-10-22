#include <stdio.h>

static void f(පූර්ණ_සංඛ්‍යා x)
{
     printf("f(%d)\n", x);
}

පූර්ණ_සංඛ්‍යා main(void)
{
     පූර්ණ_සංඛ්‍යා count = 0, i = 0;
     සඳහා (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ආපසු count == 1 ? 0 : 1;
}
