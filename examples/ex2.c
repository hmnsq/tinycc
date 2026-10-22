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

    सचे (राशिः_ptr >= 0) {
        राशिः_res[3*राशिः_ptr] = a;
        राशिः_op[राशिः_ptr] = op;
        राशिः_res[3*राशिः_ptr+1] = b;
        राशिः_res[3*राशिः_ptr+2] = n;
        सचे (n == result)
            पटिनिवत्त 1;
        tab[i1] = n;
    }

    अत्थाय(i=0;i<nb_अङ्कः;i++) {
        अत्थाय(j=i+1;j<nb_अङ्कः;j++) {
            a = tab[i];
            b = tab[j];
            सचे (a != 0 && b != 0) {

                tab[j] = 0;
                राशिः_ptr++;

                सचे (find(a + b, i, a, b, '+'))
                    पटिनिवत्त 1;
                सचे (find(a - b, i, a, b, '-'))
                    पटिनिवत्त 1;
                सचे (find(b - a, i, b, a, '-'))
                    पटिनिवत्त 1;
                सचे (find(a * b, i, a, b, '*'))
                    पटिनिवत्त 1;
                सचे (b != 0) {
                    c = a / b;
                    सचे (find(c, i, a, b, '/'))
                        पटिनिवत्त 1;
                }

                सचे (a != 0) {
                    c = b / a;
                    सचे (find(c, i, b, a, '/'))
                        पटिनिवत्त 1;
                }

                राशिः_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    पटिनिवत्त 0;
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क i, res, p;

    सचे (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_अङ्कः = 0;
    अत्थाय(i=p+1;i<argc;i++) {
        tab[nb_अङ्कः++] = atoi(argv[i]);
    }

    राशिः_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    सचे (res) {
        अत्थाय(i=0;i<=राशिः_ptr;i++) {
            printf("%d %c %d = %d\n",
                   राशिः_res[3*i], राशिः_op[i],
                   राशिः_res[3*i+1], राशिः_res[3*i+2]);
        }
        पटिनिवत्त 0;
    } अञ्ञथा {
        printf("Impossible\n");
        पटिनिवत्त 1;
    }
}
