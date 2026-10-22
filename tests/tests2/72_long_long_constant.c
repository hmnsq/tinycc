#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
    long long පූර්ණ_සංඛ්‍යා res = 0;

    නම් (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ආපසු 1;
    }
    නැතහොත්
    නම් (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ආපසු 2;
    }
    නැතහොත්
        printf("long long constant test ok.\n");
    ආපසු 0;
}
