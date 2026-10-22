#include <stdlib.h>
#include <stdio.h>

#define N 20

ціле nb_num;
ціле tab[N];
ціле stack_ptr;
ціле stack_op[N];
ціле stack_res[60];
ціле result;

ціле find(ціле n, ціле i1, ціле a, ціле b, ціле op)
{
    ціле i, j;
    ціле c;

    якщо (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        якщо (n == result)
            повернути 1;
        tab[i1] = n;
    }

    для(i=0;i<nb_num;i++) {
        для(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            якщо (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                якщо (find(a + b, i, a, b, '+'))
                    повернути 1;
                якщо (find(a - b, i, a, b, '-'))
                    повернути 1;
                якщо (find(b - a, i, b, a, '-'))
                    повернути 1;
                якщо (find(a * b, i, a, b, '*'))
                    повернути 1;
                якщо (b != 0) {
                    c = a / b;
                    якщо (find(c, i, a, b, '/'))
                        повернути 1;
                }

                якщо (a != 0) {
                    c = b / a;
                    якщо (find(c, i, b, a, '/'))
                        повернути 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    повернути 0;
}

ціле main(ціле argc, char **argv)
{
    ціле i, res, p;

    якщо (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    для(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    якщо (res) {
        для(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        повернути 0;
    } інакше {
        printf("Impossible\n");
        повернути 1;
    }
}
