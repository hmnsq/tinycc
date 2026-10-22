#अन्तर्भाव <stdio.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क bob, jim = 21;
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    पटिनिवत्त 0;
}
