#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_عدد;
صحيح tab[N];
صحيح ڈھیر_ptr;
صحيح ڈھیر_op[N];
صحيح ڈھیر_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    إذا (ڈھیر_ptr >= 0) {
        ڈھیر_res[3*ڈھیر_ptr] = a;
        ڈھیر_op[ڈھیر_ptr] = op;
        ڈھیر_res[3*ڈھیر_ptr+1] = b;
        ڈھیر_res[3*ڈھیر_ptr+2] = n;
        إذا (n == result)
            أرجع 1;
        tab[i1] = n;
    }

    لكل(i=0;i<nb_عدد;i++) {
        لكل(j=i+1;j<nb_عدد;j++) {
            a = tab[i];
            b = tab[j];
            إذا (a != 0 && b != 0) {

                tab[j] = 0;
                ڈھیر_ptr++;

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

                ڈھیر_ptr--;
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
    nb_عدد = 0;
    لكل(i=p+1;i<argc;i++) {
        tab[nb_عدد++] = atoi(argv[i]);
    }

    ڈھیر_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    إذا (res) {
        لكل(i=0;i<=ڈھیر_ptr;i++) {
            printf("%d %c %d = %d\n",
                   ڈھیر_res[3*i], ڈھیر_op[i],
                   ڈھیر_res[3*i+1], ڈھیر_res[3*i+2]);
        }
        أرجع 0;
    } وإلا {
        printf("Impossible\n");
        أرجع 1;
    }
}
