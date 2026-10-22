#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_رەقەم;
صحيح tab[N];
صحيح دۆۋە_ptr;
صحيح دۆۋە_op[N];
صحيح دۆۋە_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    إذا (دۆۋە_ptr >= 0) {
        دۆۋە_res[3*دۆۋە_ptr] = a;
        دۆۋە_op[دۆۋە_ptr] = op;
        دۆۋە_res[3*دۆۋە_ptr+1] = b;
        دۆۋە_res[3*دۆۋە_ptr+2] = n;
        إذا (n == result)
            أرجع 1;
        tab[i1] = n;
    }

    لكل(i=0;i<nb_رەقەم;i++) {
        لكل(j=i+1;j<nb_رەقەم;j++) {
            a = tab[i];
            b = tab[j];
            إذا (a != 0 && b != 0) {

                tab[j] = 0;
                دۆۋە_ptr++;

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

                دۆۋە_ptr--;
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
    nb_رەقەم = 0;
    لكل(i=p+1;i<argc;i++) {
        tab[nb_رەقەم++] = atoi(argv[i]);
    }

    دۆۋە_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    إذا (res) {
        لكل(i=0;i<=دۆۋە_ptr;i++) {
            printf("%d %c %d = %d\n",
                   دۆۋە_res[3*i], دۆۋە_op[i],
                   دۆۋە_res[3*i+1], دۆۋە_res[3*i+2]);
        }
        أرجع 0;
    } وإلا {
        printf("Impossible\n");
        أرجع 1;
    }
}
