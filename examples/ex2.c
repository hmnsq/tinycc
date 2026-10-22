#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_اڠک;
صحيح tab[N];
صحيح تيندنن_ptr;
صحيح تيندنن_op[N];
صحيح تيندنن_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    إذا (تيندنن_ptr >= 0) {
        تيندنن_res[3*تيندنن_ptr] = a;
        تيندنن_op[تيندنن_ptr] = op;
        تيندنن_res[3*تيندنن_ptr+1] = b;
        تيندنن_res[3*تيندنن_ptr+2] = n;
        إذا (n == result)
            أرجع 1;
        tab[i1] = n;
    }

    لكل(i=0;i<nb_اڠک;i++) {
        لكل(j=i+1;j<nb_اڠک;j++) {
            a = tab[i];
            b = tab[j];
            إذا (a != 0 && b != 0) {

                tab[j] = 0;
                تيندنن_ptr++;

                إذا (find(a + b, i, a, b, '+'))
                    أرجع 1;
                إذا (find(a - b, i, a, b, '-'))
                    أرجع 1;
                إذا (find(b - a, i, b, a, '-'))
                    أرجع 1;
                إذا (find(a * b, i, a, b, '*'))
                    أرجع 1;
                إذا (b != 0) {
                    c = a / b;
                    إذا (find(c, i, a, b, '/'))
                        أرجع 1;
                }

                إذا (a != 0) {
                    c = b / a;
                    إذا (find(c, i, b, a, '/'))
                        أرجع 1;
                }

                تيندنن_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    أرجع 0;
}

صحيح main(صحيح argc, حرف **argv)
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
    nb_اڠک = 0;
    لكل(i=p+1;i<argc;i++) {
        tab[nb_اڠک++] = atoi(argv[i]);
    }

    تيندنن_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    إذا (res) {
        لكل(i=0;i<=تيندنن_ptr;i++) {
            printf("%d %c %d = %d\n",
                   تيندنن_res[3*i], تيندنن_op[i],
                   تيندنن_res[3*i+1], تيندنن_res[3*i+2]);
        }
        أرجع 0;
    } وإلا {
        printf("Impossible\n");
        أرجع 1;
    }
}
