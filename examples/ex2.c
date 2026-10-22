#include <stdlib.h>
#include <stdio.h>

#define N 20

цяло nb_num;
цяло tab[N];
цяло stack_ptr;
цяло stack_op[N];
цяло stack_res[60];
цяло result;

цяло find(цяло n, цяло i1, цяло a, цяло b, цяло op)
{
    цяло i, j;
    цяло c;

    ако (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ако (n == result)
            върни 1;
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
                    върни 1;
                ако (find(a - b, i, a, b, '-'))
                    върни 1;
                ако (find(b - a, i, b, a, '-'))
                    върни 1;
                ако (find(a * b, i, a, b, '*'))
                    върни 1;
                ако (b != 0) {
                    c = a / b;
                    ако (find(c, i, a, b, '/'))
                        върни 1;
                }

                ако (a != 0) {
                    c = b / a;
                    ако (find(c, i, b, a, '/'))
                        върни 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    върни 0;
}

цяло main(цяло argc, char **argv)
{
    цяло i, res, p;

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
        върни 0;
    } иначе {
        printf("Impossible\n");
        върни 1;
    }
}
