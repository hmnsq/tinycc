#include <stdlib.h>
#include <stdio.h>

#define N 20

ຈຳນວນເຕັມ nb_num;
ຈຳນວນເຕັມ tab[N];
ຈຳນວນເຕັມ stack_ptr;
ຈຳນວນເຕັມ stack_op[N];
ຈຳນວນເຕັມ stack_res[60];
ຈຳນວນເຕັມ result;

ຈຳນວນເຕັມ find(ຈຳນວນເຕັມ n, ຈຳນວນເຕັມ i1, ຈຳນວນເຕັມ a, ຈຳນວນເຕັມ b, ຈຳນວນເຕັມ op)
{
    ຈຳນວນເຕັມ i, j;
    ຈຳນວນເຕັມ c;

    ຖ້າ (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ຖ້າ (n == result)
            ສົ່ງຄືນ 1;
        tab[i1] = n;
    }

    ສຳລັບ(i=0;i<nb_num;i++) {
        ສຳລັບ(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            ຖ້າ (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                ຖ້າ (find(a + b, i, a, b, '+'))
                    ສົ່ງຄືນ 1;
                ຖ້າ (find(a - b, i, a, b, '-'))
                    ສົ່ງຄືນ 1;
                ຖ້າ (find(b - a, i, b, a, '-'))
                    ສົ່ງຄືນ 1;
                ຖ້າ (find(a * b, i, a, b, '*'))
                    ສົ່ງຄືນ 1;
                ຖ້າ (b != 0) {
                    c = a / b;
                    ຖ້າ (find(c, i, a, b, '/'))
                        ສົ່ງຄືນ 1;
                }

                ຖ້າ (a != 0) {
                    c = b / a;
                    ຖ້າ (find(c, i, b, a, '/'))
                        ສົ່ງຄືນ 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    ຈຳນວນເຕັມ i, res, p;

    ຖ້າ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    ສຳລັບ(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ຖ້າ (res) {
        ສຳລັບ(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ສົ່ງຄືນ 0;
    } ບໍ່ດັ່ງນັ້ນ {
        printf("Impossible\n");
        ສົ່ງຄືນ 1;
    }
}
