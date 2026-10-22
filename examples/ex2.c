#include <stdlib.h>
#include <stdio.h>

#define N 20

số_nguyên nb_num;
số_nguyên tab[N];
số_nguyên stack_ptr;
số_nguyên stack_op[N];
số_nguyên stack_res[60];
số_nguyên result;

số_nguyên find(số_nguyên n, số_nguyên i1, số_nguyên a, số_nguyên b, số_nguyên op)
{
    số_nguyên i, j;
    số_nguyên c;

    nếu (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        nếu (n == result)
            trả_về 1;
        tab[i1] = n;
    }

    cho(i=0;i<nb_num;i++) {
        cho(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            nếu (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                nếu (find(a + b, i, a, b, '+'))
                    trả_về 1;
                nếu (find(a - b, i, a, b, '-'))
                    trả_về 1;
                nếu (find(b - a, i, b, a, '-'))
                    trả_về 1;
                nếu (find(a * b, i, a, b, '*'))
                    trả_về 1;
                nếu (b != 0) {
                    c = a / b;
                    nếu (find(c, i, a, b, '/'))
                        trả_về 1;
                }

                nếu (a != 0) {
                    c = b / a;
                    nếu (find(c, i, b, a, '/'))
                        trả_về 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    trả_về 0;
}

số_nguyên main(số_nguyên argc, char **argv)
{
    số_nguyên i, res, p;

    nếu (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    cho(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    nếu (res) {
        cho(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        trả_về 0;
    } không_thì {
        printf("Impossible\n");
        trả_về 1;
    }
}
