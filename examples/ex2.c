#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>

#define N 20

পূর্ণসংখ্যা nb_অঙ্ক;
পূর্ণসংখ্যা tab[N];
পূর্ণসংখ্যা স্তূপ_ptr;
পূর্ণসংখ্যা স্তূপ_op[N];
পূর্ণসংখ্যা স্তূপ_res[60];
পূর্ণসংখ্যা ফলাফল;

পূর্ণসংখ্যা find(পূর্ণসংখ্যা n, পূর্ণসংখ্যা i1, পূর্ণসংখ্যা a, পূর্ণসংখ্যা b, পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা i, j;
    পূর্ণসংখ্যা c;

    যদি (স্তূপ_ptr >= 0) {
        স্তূপ_res[3*স্তূপ_ptr] = a;
        স্তূপ_op[স্তূপ_ptr] = op;
        স্তূপ_res[3*স্তূপ_ptr+1] = b;
        স্তূপ_res[3*স্তূপ_ptr+2] = n;
        যদি (n == ফলাফল)
            ফেরত 1;
        tab[i1] = n;
    }

    জন্য(i=0;i<nb_অঙ্ক;i++) {
        জন্য(j=i+1;j<nb_অঙ্ক;j++) {
            a = tab[i];
            b = tab[j];
            যদি (a != 0 && b != 0) {

                tab[j] = 0;
                স্তূপ_ptr++;

                যদি (find(a + b, i, a, b, '+'))
                    ফেরত 1;
                যদি (find(a - b, i, a, b, '-'))
                    ফেরত 1;
                যদি (find(b - a, i, b, a, '-'))
                    ফেরত 1;
                যদি (find(a * b, i, a, b, '*'))
                    ফেরত 1;
                যদি (b != 0) {
                    c = a / b;
                    যদি (find(c, i, a, b, '/'))
                        ফেরত 1;
                }

                যদি (a != 0) {
                    c = b / a;
                    যদি (find(c, i, b, a, '/'))
                        ফেরত 1;
                }

                স্তূপ_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ফেরত 0;
}

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    পূর্ণসংখ্যা i, res, p;

    যদি (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    ফলাফল = atoi(argv[p]);
    printf("result=%d\n", ফলাফল);
    nb_অঙ্ক = 0;
    জন্য(i=p+1;i<argc;i++) {
        tab[nb_অঙ্ক++] = atoi(argv[i]);
    }

    স্তূপ_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    যদি (res) {
        জন্য(i=0;i<=স্তূপ_ptr;i++) {
            printf("%d %c %d = %d\n",
                   স্তূপ_res[3*i], স্তূপ_op[i],
                   স্তূপ_res[3*i+1], স্তূপ_res[3*i+2]);
        }
        ফেরত 0;
    } অন্যথা {
        printf("Impossible\n");
        ফেরত 1;
    }
}
