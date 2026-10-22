#include <stdlib.h>
#include <stdio.h>

#define N 20

ཧྲིལ nb_num;
ཧྲིལ tab[N];
ཧྲིལ stack_ptr;
ཧྲིལ stack_op[N];
ཧྲིལ stack_res[60];
ཧྲིལ result;

ཧྲིལ find(ཧྲིལ n, ཧྲིལ i1, ཧྲིལ a, ཧྲིལ b, ཧྲིལ op)
{
    ཧྲིལ i, j;
    ཧྲིལ c;

    གལ་ཏེ (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        གལ་ཏེ (n == result)
            ཕྱིར 1;
        tab[i1] = n;
    }

    ཆེད་དུ(i=0;i<nb_num;i++) {
        ཆེད་དུ(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            གལ་ཏེ (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                གལ་ཏེ (find(a + b, i, a, b, '+'))
                    ཕྱིར 1;
                གལ་ཏེ (find(a - b, i, a, b, '-'))
                    ཕྱིར 1;
                གལ་ཏེ (find(b - a, i, b, a, '-'))
                    ཕྱིར 1;
                གལ་ཏེ (find(a * b, i, a, b, '*'))
                    ཕྱིར 1;
                གལ་ཏེ (b != 0) {
                    c = a / b;
                    གལ་ཏེ (find(c, i, a, b, '/'))
                        ཕྱིར 1;
                }

                གལ་ཏེ (a != 0) {
                    c = b / a;
                    གལ་ཏེ (find(c, i, b, a, '/'))
                        ཕྱིར 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ཕྱིར 0;
}

ཧྲིལ གཙོ(ཧྲིལ argc, var_na **argv)
{
    ཧྲིལ i, res, p;

    གལ་ཏེ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    ཆེད་དུ(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    གལ་ཏེ (res) {
        ཆེད་དུ(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ཕྱིར 0;
    } དེ་མིན {
        printf("Impossible\n");
        ཕྱིར 1;
    }
}
