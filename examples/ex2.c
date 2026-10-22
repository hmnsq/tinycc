#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_لمب;
صحيح tab[N];
صحيح تر_ptr;
صحيح تر_op[N];
صحيح تر_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    إذا (تر_ptr >= 0) {
        تر_res[3*تر_ptr] = a;
        تر_op[تر_ptr] = op;
        تر_res[3*تر_ptr+1] = b;
        تر_res[3*تر_ptr+2] = n;
        إذا (n == result)
            أرجع 1;
        tab[i1] = n;
    }

    لكل(i=0;i<nb_لمب;i++) {
        لكل(j=i+1;j<nb_لمب;j++) {
            a = tab[i];
            b = tab[j];
            إذا (a != 0 && b != 0) {

                tab[j] = 0;
                تر_ptr++;

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

                تر_ptr--;
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
    nb_لمب = 0;
    لكل(i=p+1;i<argc;i++) {
        tab[nb_لمب++] = atoi(argv[i]);
    }

    تر_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    إذا (res) {
        لكل(i=0;i<=تر_ptr;i++) {
            printf("%d %c %d = %d\n",
                   تر_res[3*i], تر_op[i],
                   تر_res[3*i+1], تر_res[3*i+2]);
        }
        أرجع 0;
    } وإلا {
        printf("Impossible\n");
        أرجع 1;
    }
}
