#include <stdlib.h>
#include <stdio.h>

#define N 20

ចំនួនគត់ nb_num;
ចំនួនគត់ tab[N];
ចំនួនគត់ stack_ptr;
ចំនួនគត់ stack_op[N];
ចំនួនគត់ stack_res[60];
ចំនួនគត់ result;

ចំនួនគត់ find(ចំនួនគត់ n, ចំនួនគត់ i1, ចំនួនគត់ a, ចំនួនគត់ b, ចំនួនគត់ op)
{
    ចំនួនគត់ i, j;
    ចំនួនគត់ c;

    ប្រសិនបើ (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ប្រសិនបើ (n == result)
            ត្រឡប់ 1;
        tab[i1] = n;
    }

    សម្រាប់(i=0;i<nb_num;i++) {
        សម្រាប់(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            ប្រសិនបើ (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                ប្រសិនបើ (find(a + b, i, a, b, '+'))
                    ត្រឡប់ 1;
                ប្រសិនបើ (find(a - b, i, a, b, '-'))
                    ត្រឡប់ 1;
                ប្រសិនបើ (find(b - a, i, b, a, '-'))
                    ត្រឡប់ 1;
                ប្រសិនបើ (find(a * b, i, a, b, '*'))
                    ត្រឡប់ 1;
                ប្រសិនបើ (b != 0) {
                    c = a / b;
                    ប្រសិនបើ (find(c, i, a, b, '/'))
                        ត្រឡប់ 1;
                }

                ប្រសិនបើ (a != 0) {
                    c = b / a;
                    ប្រសិនបើ (find(c, i, b, a, '/'))
                        ត្រឡប់ 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ត្រឡប់ 0;
}

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    ចំនួនគត់ i, res, p;

    ប្រសិនបើ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    សម្រាប់(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ប្រសិនបើ (res) {
        សម្រាប់(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ត្រឡប់ 0;
    } បើមិនដូច្នេះ {
        printf("Impossible\n");
        ត្រឡប់ 1;
    }
}
