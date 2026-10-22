#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>

#define N 20

পূর্ণাঙ্ক nb_অঙ্ক;
পূর্ণাঙ্ক tab[N];
পূর্ণাঙ্ক স্তূপ_ptr;
পূর্ণাঙ্ক স্তূপ_op[N];
পূর্ণাঙ্ক স্তূপ_res[60];
পূর্ণাঙ্ক result;

পূর্ণাঙ্ক find(পূর্ণাঙ্ক n, পূর্ণাঙ্ক i1, পূর্ণাঙ্ক a, পূর্ণাঙ্ক b, পূর্ণাঙ্ক op)
{
    পূর্ণাঙ্ক i, j;
    পূর্ণাঙ্ক c;

    যদি (স্তূপ_ptr >= 0) {
        স্তূপ_res[3*স্তূপ_ptr] = a;
        স্তূপ_op[স্তূপ_ptr] = op;
        স্তূপ_res[3*স্তূপ_ptr+1] = b;
        স্তূপ_res[3*স্তূপ_ptr+2] = n;
        যদি (n == result)
            ঘূৰাই 1;
        tab[i1] = n;
    }

    বাবে(i=0;i<nb_অঙ্ক;i++) {
        বাবে(j=i+1;j<nb_অঙ্ক;j++) {
            a = tab[i];
            b = tab[j];
            যদি (a != 0 && b != 0) {

                tab[j] = 0;
                স্তূপ_ptr++;

                যদি (find(a + b, i, a, b, '+'))
                    ঘূৰাই 1;
                যদি (find(a - b, i, a, b, '-'))
                    ঘূৰাই 1;
                যদি (find(b - a, i, b, a, '-'))
                    ঘূৰাই 1;
                যদি (find(a * b, i, a, b, '*'))
                    ঘূৰাই 1;
                যদি (b != 0) {
                    c = a / b;
                    যদি (find(c, i, a, b, '/'))
                        ঘূৰাই 1;
                }

                যদি (a != 0) {
                    c = b / a;
                    যদি (find(c, i, b, a, '/'))
                        ঘূৰাই 1;
                }

                স্তূপ_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ঘূৰাই 0;
}

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    পূর্ণাঙ্ক i, res, p;

    যদি (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_অঙ্ক = 0;
    বাবে(i=p+1;i<argc;i++) {
        tab[nb_অঙ্ক++] = atoi(argv[i]);
    }

    স্তূপ_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    যদি (res) {
        বাবে(i=0;i<=স্তূপ_ptr;i++) {
            printf("%d %c %d = %d\n",
                   স্তূপ_res[3*i], স্তূপ_op[i],
                   স্তূপ_res[3*i+1], স্তূপ_res[3*i+2]);
        }
        ঘূৰাই 0;
    } অন্যথা {
        printf("Impossible\n");
        ঘূৰাই 1;
    }
}
