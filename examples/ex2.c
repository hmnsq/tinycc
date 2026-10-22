#include <stdlib.h>
#include <stdio.h>

#define N 20

පූර්ණ_සංඛ්‍යා nb_num;
පූර්ණ_සංඛ්‍යා tab[N];
පූර්ණ_සංඛ්‍යා stack_ptr;
පූර්ණ_සංඛ්‍යා stack_op[N];
පූර්ණ_සංඛ්‍යා stack_res[60];
පූර්ණ_සංඛ්‍යා result;

පූර්ණ_සංඛ්‍යා find(පූර්ණ_සංඛ්‍යා n, පූර්ණ_සංඛ්‍යා i1, පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b, පූර්ණ_සංඛ්‍යා op)
{
    පූර්ණ_සංඛ්‍යා i, j;
    පූර්ණ_සංඛ්‍යා c;

    නම් (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        නම් (n == result)
            ආපසු 1;
        tab[i1] = n;
    }

    සඳහා(i=0;i<nb_num;i++) {
        සඳහා(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            නම් (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                නම් (find(a + b, i, a, b, '+'))
                    ආපසු 1;
                නම් (find(a - b, i, a, b, '-'))
                    ආපසු 1;
                නම් (find(b - a, i, b, a, '-'))
                    ආපසු 1;
                නම් (find(a * b, i, a, b, '*'))
                    ආපසු 1;
                නම් (b != 0) {
                    c = a / b;
                    නම් (find(c, i, a, b, '/'))
                        ආපසු 1;
                }

                නම් (a != 0) {
                    c = b / a;
                    නම් (find(c, i, b, a, '/'))
                        ආපසු 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ආපසු 0;
}

පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv)
{
    පූර්ණ_සංඛ්‍යා i, res, p;

    නම් (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    සඳහා(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    නම් (res) {
        සඳහා(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ආපසු 0;
    } නැතහොත් {
        printf("Impossible\n");
        ආපසු 1;
    }
}
