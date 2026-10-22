#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_رقم;
صحيح tab[N];
صحيح مكدس_ptr;
صحيح مكدس_op[N];
صحيح مكدس_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    إذا (مكدس_ptr >= 0) {
        مكدس_res[3*مكدس_ptr] = a;
        مكدس_op[مكدس_ptr] = op;
        مكدس_res[3*مكدس_ptr+1] = b;
        مكدس_res[3*مكدس_ptr+2] = n;
        إذا (n == result)
            إرجاع 1;
        tab[i1] = n;
    }

    لكل(i=0;i<nb_رقم;i++) {
        لكل(j=i+1;j<nb_رقم;j++) {
            a = tab[i];
            b = tab[j];
            إذا (a != 0 && b != 0) {

                tab[j] = 0;
                مكدس_ptr++;

                إذا (find(a + b, i, a, b, '+'))
                    إرجاع 1;
                إذا (find(a - b, i, a, b, '-'))
                    إرجاع 1;
                إذا (find(b - a, i, b, a, '-'))
                    إرجاع 1;
                إذا (find(a * b, i, a, b, '*'))
                    إرجاع 1;
                إذا (b != 0) {
                    c = a / b;
                    إذا (find(c, i, a, b, '/'))
                        إرجاع 1;
                }

                إذا (a != 0) {
                    c = b / a;
                    إذا (find(c, i, b, a, '/'))
                        إرجاع 1;
                }

                مكدس_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    إرجاع 0;
}

صحيح الرئيسية(صحيح argc, حرف **argv)
{
    صحيح i, res, p;

    إذا (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_رقم = 0;
    لكل(i=p+1;i<argc;i++) {
        tab[nb_رقم++] = atoi(argv[i]);
    }

    مكدس_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    إذا (res) {
        لكل(i=0;i<=مكدس_ptr;i++) {
            printf("%d %c %d = %d\n",
                   مكدس_res[3*i], مكدس_op[i],
                   مكدس_res[3*i+1], مكدس_res[3*i+2]);
        }
        إرجاع 0;
    } وإلا {
        printf("Impossible\n");
        إرجاع 1;
    }
}
