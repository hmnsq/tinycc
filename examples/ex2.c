#include <stdlib.h>
#include <stdio.h>

#define N 20

целое nb_num;
целое tab[N];
целое stack_ptr;
целое stack_op[N];
целое stack_res[60];
целое result;

целое find(целое n, целое i1, целое a, целое b, целое op)
{
    целое i, j;
    целое c;

    если (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        если (n == result)
            вернуть 1;
        tab[i1] = n;
    }

    для(i=0;i<nb_num;i++) {
        для(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            если (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                если (find(a + b, i, a, b, '+'))
                    вернуть 1;
                если (find(a - b, i, a, b, '-'))
                    вернуть 1;
                если (find(b - a, i, b, a, '-'))
                    вернуть 1;
                если (find(a * b, i, a, b, '*'))
                    вернуть 1;
                если (b != 0) {
                    c = a / b;
                    если (find(c, i, a, b, '/'))
                        вернуть 1;
                }

                если (a != 0) {
                    c = b / a;
                    если (find(c, i, b, a, '/'))
                        вернуть 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    вернуть 0;
}

целое основной(целое argc, char **argv)
{
    целое i, res, p;

    если (argc < 3) {
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
    если (res) {
        для(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        вернуть 0;
    } иначе {
        printf("Impossible\n");
        вернуть 1;
    }
}
