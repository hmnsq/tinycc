#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>

#define N 20

पूर्णाङ्क nb_अंक;
पूर्णाङ्क tab[N];
पूर्णाङ्क ढेर_ptr;
पूर्णाङ्क ढेर_op[N];
पूर्णाङ्क ढेर_res[60];
पूर्णाङ्क result;

पूर्णाङ्क find(पूर्णाङ्क n, पूर्णाङ्क i1, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क op)
{
    पूर्णाङ्क i, j;
    पूर्णाङ्क c;

    यदि (ढेर_ptr >= 0) {
        ढेर_res[3*ढेर_ptr] = a;
        ढेर_op[ढेर_ptr] = op;
        ढेर_res[3*ढेर_ptr+1] = b;
        ढेर_res[3*ढेर_ptr+2] = n;
        यदि (n == result)
            प्रत्यागम 1;
        tab[i1] = n;
    }

    प्रति(i=0;i<nb_अंक;i++) {
        प्रति(j=i+1;j<nb_अंक;j++) {
            a = tab[i];
            b = tab[j];
            यदि (a != 0 && b != 0) {

                tab[j] = 0;
                ढेर_ptr++;

                यदि (find(a + b, i, a, b, '+'))
                    प्रत्यागम 1;
                यदि (find(a - b, i, a, b, '-'))
                    प्रत्यागम 1;
                यदि (find(b - a, i, b, a, '-'))
                    प्रत्यागम 1;
                यदि (find(a * b, i, a, b, '*'))
                    प्रत्यागम 1;
                यदि (b != 0) {
                    c = a / b;
                    यदि (find(c, i, a, b, '/'))
                        प्रत्यागम 1;
                }

                यदि (a != 0) {
                    c = b / a;
                    यदि (find(c, i, b, a, '/'))
                        प्रत्यागम 1;
                }

                ढेर_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    प्रत्यागम 0;
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क i, res, p;

    यदि (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_अंक = 0;
    प्रति(i=p+1;i<argc;i++) {
        tab[nb_अंक++] = atoi(argv[i]);
    }

    ढेर_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    यदि (res) {
        प्रति(i=0;i<=ढेर_ptr;i++) {
            printf("%d %c %d = %d\n",
                   ढेर_res[3*i], ढेर_op[i],
                   ढेर_res[3*i+1], ढेर_res[3*i+2]);
        }
        प्रत्यागम 0;
    } अन्यथा {
        printf("Impossible\n");
        प्रत्यागम 1;
    }
}
