#شامل <stdio.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

صحیح اصلی(تهی)
{
    صحیح bob, jim = 21;
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    بازگشت 0;
}
