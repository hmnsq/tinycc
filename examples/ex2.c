#include <stdlib.h>
#include <stdio.h>

#define N 20

整数 nb_num;
整数 tab[N];
整数 stack_ptr;
整数 stack_op[N];
整数 stack_res[60];
整数 result;

整数 find(整数 n, 整数 i1, 整数 a, 整数 b, 整数 op)
{
    整数 i, j;
    整数 c;

    もし (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        もし (n == result)
            戻る 1;
        tab[i1] = n;
    }

    ために(i=0;i<nb_num;i++) {
        ために(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            もし (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                もし (find(a + b, i, a, b, '+'))
                    戻る 1;
                もし (find(a - b, i, a, b, '-'))
                    戻る 1;
                もし (find(b - a, i, b, a, '-'))
                    戻る 1;
                もし (find(a * b, i, a, b, '*'))
                    戻る 1;
                もし (b != 0) {
                    c = a / b;
                    もし (find(c, i, a, b, '/'))
                        戻る 1;
                }

                もし (a != 0) {
                    c = b / a;
                    もし (find(c, i, b, a, '/'))
                        戻る 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    戻る 0;
}

整数 メインページ(整数 argc, char **argv)
{
    整数 i, res, p;

    もし (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    ために(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    もし (res) {
        ために(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        戻る 0;
    } 否则 {
        printf("Impossible\n");
        戻る 1;
    }
}
