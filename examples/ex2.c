#include <stdlib.h>
#include <stdio.h>

#define N 20

цео nb_num;
цео tab[N];
цео stack_ptr;
цео stack_op[N];
цео stack_res[60];
цео result;

цео find(цео n, цео i1, цео a, цео b, цео op)
{
    цео i, j;
    цео c;

    ако (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ако (n == result)
            врати 1;
        tab[i1] = n;
    }

    за(i=0;i<nb_num;i++) {
        за(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            ако (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                ако (find(a + b, i, a, b, '+'))
                    врати 1;
                ако (find(a - b, i, a, b, '-'))
                    врати 1;
                ако (find(b - a, i, b, a, '-'))
                    врати 1;
                ако (find(a * b, i, a, b, '*'))
                    врати 1;
                ако (b != 0) {
                    c = a / b;
                    ако (find(c, i, a, b, '/'))
                        врати 1;
                }

                ако (a != 0) {
                    c = b / a;
                    ако (find(c, i, b, a, '/'))
                        врати 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    врати 0;
}

цео main(цео argc, char **argv)
{
    цео i, res, p;

    ако (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    за(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ако (res) {
        за(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        врати 0;
    } инако {
        printf("Impossible\n");
        врати 1;
    }
}
