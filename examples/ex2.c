#include <stdlib.h>
#include <stdio.h>

#define N 20

ကိန်းပြည့် nb_num;
ကိန်းပြည့် tab[N];
ကိန်းပြည့် stack_ptr;
ကိန်းပြည့် stack_op[N];
ကိန်းပြည့် stack_res[60];
ကိန်းပြည့် result;

ကိန်းပြည့် find(ကိန်းပြည့် n, ကိန်းပြည့် i1, ကိန်းပြည့် a, ကိန်းပြည့် b, ကိန်းပြည့် op)
{
    ကိန်းပြည့် i, j;
    ကိန်းပြည့် c;

    အကယ်၍ (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        အကယ်၍ (n == result)
            ပြန်ပေး 1;
        tab[i1] = n;
    }

    အတွက်(i=0;i<nb_num;i++) {
        အတွက်(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            အကယ်၍ (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                အကယ်၍ (find(a + b, i, a, b, '+'))
                    ပြန်ပေး 1;
                အကယ်၍ (find(a - b, i, a, b, '-'))
                    ပြန်ပေး 1;
                အကယ်၍ (find(b - a, i, b, a, '-'))
                    ပြန်ပေး 1;
                အကယ်၍ (find(a * b, i, a, b, '*'))
                    ပြန်ပေး 1;
                အကယ်၍ (b != 0) {
                    c = a / b;
                    အကယ်၍ (find(c, i, a, b, '/'))
                        ပြန်ပေး 1;
                }

                အကယ်၍ (a != 0) {
                    c = b / a;
                    အကယ်၍ (find(c, i, b, a, '/'))
                        ပြန်ပေး 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ပြန်ပေး 0;
}

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    ကိန်းပြည့် i, res, p;

    အကယ်၍ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    အတွက်(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    အကယ်၍ (res) {
        အတွက်(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ပြန်ပေး 0;
    } မဟုတ်ပါက {
        printf("Impossible\n");
        ပြန်ပေး 1;
    }
}
