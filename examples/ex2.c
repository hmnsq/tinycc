#include <stdlib.h>
#include <stdio.h>

#define N 20

정수 nb_num;
정수 tab[N];
정수 stack_ptr;
정수 stack_op[N];
정수 stack_res[60];
정수 result;

정수 find(정수 n, 정수 i1, 정수 a, 정수 b, 정수 op)
{
    정수 i, j;
    정수 c;

    만약 (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        만약 (n == result)
            반환 1;
        tab[i1] = n;
    }

    위해(i=0;i<nb_num;i++) {
        위해(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            만약 (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                만약 (find(a + b, i, a, b, '+'))
                    반환 1;
                만약 (find(a - b, i, a, b, '-'))
                    반환 1;
                만약 (find(b - a, i, b, a, '-'))
                    반환 1;
                만약 (find(a * b, i, a, b, '*'))
                    반환 1;
                만약 (b != 0) {
                    c = a / b;
                    만약 (find(c, i, a, b, '/'))
                        반환 1;
                }

                만약 (a != 0) {
                    c = b / a;
                    만약 (find(c, i, b, a, '/'))
                        반환 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    반환 0;
}

정수 main(정수 argc, char **argv)
{
    정수 i, res, p;

    만약 (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    위해(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    만약 (res) {
        위해(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        반환 0;
    } 아니면 {
        printf("Impossible\n");
        반환 1;
    }
}
