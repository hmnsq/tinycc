#شامل <stdlib.h>
#شامل <stdio.h>

#define N 20

صحیح nb_رقم;
صحیح tab[N];
صحیح پشته_ptr;
صحیح پشته_op[N];
صحیح پشته_res[60];
صحیح result;

صحیح find(صحیح n, صحیح i1, صحیح a, صحیح b, صحیح op)
{
    صحیح i, j;
    صحیح c;

    اگر (پشته_ptr >= 0) {
        پشته_res[3*پشته_ptr] = a;
        پشته_op[پشته_ptr] = op;
        پشته_res[3*پشته_ptr+1] = b;
        پشته_res[3*پشته_ptr+2] = n;
        اگر (n == result)
            بازگشت 1;
        tab[i1] = n;
    }

    برای(i=0;i<nb_رقم;i++) {
        برای(j=i+1;j<nb_رقم;j++) {
            a = tab[i];
            b = tab[j];
            اگر (a != 0 && b != 0) {

                tab[j] = 0;
                پشته_ptr++;

                اگر (find(a + b, i, a, b, '+'))
                    بازگشت 1;
                اگر (find(a - b, i, a, b, '-'))
                    بازگشت 1;
                اگر (find(b - a, i, b, a, '-'))
                    بازگشت 1;
                اگر (find(a * b, i, a, b, '*'))
                    بازگشت 1;
                اگر (b != 0) {
                    c = a / b;
                    اگر (find(c, i, a, b, '/'))
                        بازگشت 1;
                }

                اگر (a != 0) {
                    c = b / a;
                    اگر (find(c, i, b, a, '/'))
                        بازگشت 1;
                }

                پشته_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    بازگشت 0;
}

صحیح اصلی(صحیح argc, نویسه **argv)
{
    صحیح i, res, p;

    اگر (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_رقم = 0;
    برای(i=p+1;i<argc;i++) {
        tab[nb_رقم++] = atoi(argv[i]);
    }

    پشته_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    اگر (res) {
        برای(i=0;i<=پشته_ptr;i++) {
            printf("%d %c %d = %d\n",
                   پشته_res[3*i], پشته_op[i],
                   پشته_res[3*i+1], پشته_res[3*i+2]);
        }
        بازگشت 0;
    } وگرنه {
        printf("Impossible\n");
        بازگشت 1;
    }
}
