#include <stdio.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

整数 メインページ(void)
{
    整数 bob, jim = 21;
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    戻る 0;
}
