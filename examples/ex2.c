#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

#define N 20

ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ଅଙ୍କ;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[N];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଦା_ptr;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଦା_op[N];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଦା_res[60];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା result;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା i1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;

    ଯଦି (ଗଦା_ptr >= 0) {
        ଗଦା_res[3*ଗଦା_ptr] = a;
        ଗଦା_op[ଗଦା_ptr] = op;
        ଗଦା_res[3*ଗଦା_ptr+1] = b;
        ଗଦା_res[3*ଗଦା_ptr+2] = n;
        ଯଦି (n == result)
            ଫେରନ୍ତୁ 1;
        tab[i1] = n;
    }

    ପାଇଁ(i=0;i<nb_ଅଙ୍କ;i++) {
        ପାଇଁ(j=i+1;j<nb_ଅଙ୍କ;j++) {
            a = tab[i];
            b = tab[j];
            ଯଦି (a != 0 && b != 0) {

                tab[j] = 0;
                ଗଦା_ptr++;

                ଯଦି (find(a + b, i, a, b, '+'))
                    ଫେରନ୍ତୁ 1;
                ଯଦି (find(a - b, i, a, b, '-'))
                    ଫେରନ୍ତୁ 1;
                ଯଦି (find(b - a, i, b, a, '-'))
                    ଫେରନ୍ତୁ 1;
                ଯଦି (find(a * b, i, a, b, '*'))
                    ଫେରନ୍ତୁ 1;
                ଯଦି (b != 0) {
                    c = a / b;
                    ଯଦି (find(c, i, a, b, '/'))
                        ଫେରନ୍ତୁ 1;
                }

                ଯଦି (a != 0) {
                    c = b / a;
                    ଯଦି (find(c, i, b, a, '/'))
                        ଫେରନ୍ତୁ 1;
                }

                ଗଦା_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, res, p;

    ଯଦି (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_ଅଙ୍କ = 0;
    ପାଇଁ(i=p+1;i<argc;i++) {
        tab[nb_ଅଙ୍କ++] = atoi(argv[i]);
    }

    ଗଦା_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ଯଦି (res) {
        ପାଇଁ(i=0;i<=ଗଦା_ptr;i++) {
            printf("%d %c %d = %d\n",
                   ଗଦା_res[3*i], ଗଦା_op[i],
                   ଗଦା_res[3*i+1], ଗଦା_res[3*i+2]);
        }
        ଫେରନ୍ତୁ 0;
    } ଅନ୍ୟଥା {
        printf("Impossible\n");
        ଫେରନ୍ତୁ 1;
    }
}
