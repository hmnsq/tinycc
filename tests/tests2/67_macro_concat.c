#ଅନ୍ତର୍ଭାଵ <stdio.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bob, jim = 21;
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    ଫେରନ୍ତୁ 0;
}
