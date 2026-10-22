#অন্তর্ভাৱ <stdio.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

পূর্ণাঙ্ক main(শূন্য)
{
    পূর্ণাঙ্ক bob, jim = 21;
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    ঘূৰাই 0;
}
