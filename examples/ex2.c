#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>

#define N 20

पूर्णाङ्क nb_अङ्कः;
पूर्णाङ्क tab[N];
पूर्णाङ्क राशिः_ptr;
पूर्णाङ्क राशिः_op[N];
पूर्णाङ्क राशिः_res[60];
पूर्णाङ्क result;

पूर्णाङ्क find(पूर्णाङ्क n, पूर्णाङ्क i1, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क op)
{
    पूर्णाङ्क i, j;
    पूर्णाङ्क c;

    जइ (राशिः_ptr >= 0) {
        राशिः_res[3*राशिः_ptr] = a;
        राशिः_op[राशिः_ptr] = op;
        राशिः_res[3*राशिः_ptr+1] = b;
        राशिः_res[3*राशिः_ptr+2] = n;
        जइ (n == result)
            प्रत्यागम 1;
        tab[i1] = n;
    }

    प्रति(i=0;i<nb_अङ्कः;i++) {
        प्रति(j=i+1;j<nb_अङ्कः;j++) {
            a = tab[i];
            b = tab[j];
            जइ (a != 0 && b != 0) {

                tab[j] = 0;
                राशिः_ptr++;

                जइ (find(a + b, i, a, b, '+'))
                    प्रत्यागम 1;
                जइ (find(a - b, i, a, b, '-'))
                    प्रत्यागम 1;
                जइ (find(b - a, i, b, a, '-'))
                    प्रत्यागम 1;
                जइ (find(a * b, i, a, b, '*'))
                    प्रत्यागम 1;
                जइ (b != 0) {
                    c = a / b;
                    जइ (find(c, i, a, b, '/'))
                        प्रत्यागम 1;
                }

                जइ (a != 0) {
                    c = b / a;
                    जइ (find(c, i, b, a, '/'))
                        प्रत्यागम 1;
                }

                राशिः_ptr--;
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

    जइ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_अङ्कः = 0;
    प्रति(i=p+1;i<argc;i++) {
        tab[nb_अङ्कः++] = atoi(argv[i]);
    }

    राशिः_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    जइ (res) {
        प्रति(i=0;i<=राशिः_ptr;i++) {
            printf("%d %c %d = %d\n",
                   राशिः_res[3*i], राशिः_op[i],
                   राशिः_res[3*i+1], राशिः_res[3*i+2]);
        }
        प्रत्यागम 0;
    } अण्णहा {
        printf("Impossible\n");
        प्रत्यागम 1;
    }
}
