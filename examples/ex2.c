#include <stdlib.h>
#include <stdio.h>

#define N 20

จำนวนเต็ม nb_num;
จำนวนเต็ม tab[N];
จำนวนเต็ม stack_ptr;
จำนวนเต็ม stack_op[N];
จำนวนเต็ม stack_res[60];
จำนวนเต็ม result;

จำนวนเต็ม find(จำนวนเต็ม n, จำนวนเต็ม i1, จำนวนเต็ม a, จำนวนเต็ม b, จำนวนเต็ม op)
{
    จำนวนเต็ม i, j;
    จำนวนเต็ม c;

    ถ้า (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ถ้า (n == result)
            คืน 1;
        tab[i1] = n;
    }

    สำหรับ(i=0;i<nb_num;i++) {
        สำหรับ(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            ถ้า (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                ถ้า (find(a + b, i, a, b, '+'))
                    คืน 1;
                ถ้า (find(a - b, i, a, b, '-'))
                    คืน 1;
                ถ้า (find(b - a, i, b, a, '-'))
                    คืน 1;
                ถ้า (find(a * b, i, a, b, '*'))
                    คืน 1;
                ถ้า (b != 0) {
                    c = a / b;
                    ถ้า (find(c, i, a, b, '/'))
                        คืน 1;
                }

                ถ้า (a != 0) {
                    c = b / a;
                    ถ้า (find(c, i, b, a, '/'))
                        คืน 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    คืน 0;
}

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    จำนวนเต็ม i, res, p;

    ถ้า (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    สำหรับ(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ถ้า (res) {
        สำหรับ(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        คืน 0;
    } มิฉะนั้น {
        printf("Impossible\n");
        คืน 1;
    }
}
