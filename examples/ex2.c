#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>

#define N 20

പൂർണ്ണസംഖ്യ nb_അക്കം;
പൂർണ്ണസംഖ്യ tab[N];
പൂർണ്ണസംഖ്യ അട്ടി_ptr;
പൂർണ്ണസംഖ്യ അട്ടി_op[N];
പൂർണ്ണസംഖ്യ അട്ടി_res[60];
പൂർണ്ണസംഖ്യ result;

പൂർണ്ണസംഖ്യ find(പൂർണ്ണസംഖ്യ n, പൂർണ്ണസംഖ്യ i1, പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ i, j;
    പൂർണ്ണസംഖ്യ c;

    എങ്കിൽ (അട്ടി_ptr >= 0) {
        അട്ടി_res[3*അട്ടി_ptr] = a;
        അട്ടി_op[അട്ടി_ptr] = op;
        അട്ടി_res[3*അട്ടി_ptr+1] = b;
        അട്ടി_res[3*അട്ടി_ptr+2] = n;
        എങ്കിൽ (n == result)
            തിരികെ 1;
        tab[i1] = n;
    }

    വേണ്ടി(i=0;i<nb_അക്കം;i++) {
        വേണ്ടി(j=i+1;j<nb_അക്കം;j++) {
            a = tab[i];
            b = tab[j];
            എങ്കിൽ (a != 0 && b != 0) {

                tab[j] = 0;
                അട്ടി_ptr++;

                എങ്കിൽ (find(a + b, i, a, b, '+'))
                    തിരികെ 1;
                എങ്കിൽ (find(a - b, i, a, b, '-'))
                    തിരികെ 1;
                എങ്കിൽ (find(b - a, i, b, a, '-'))
                    തിരികെ 1;
                എങ്കിൽ (find(a * b, i, a, b, '*'))
                    തിരികെ 1;
                എങ്കിൽ (b != 0) {
                    c = a / b;
                    എങ്കിൽ (find(c, i, a, b, '/'))
                        തിരികെ 1;
                }

                എങ്കിൽ (a != 0) {
                    c = b / a;
                    എങ്കിൽ (find(c, i, b, a, '/'))
                        തിരികെ 1;
                }

                അട്ടി_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    തിരികെ 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ i, res, p;

    എങ്കിൽ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_അക്കം = 0;
    വേണ്ടി(i=p+1;i<argc;i++) {
        tab[nb_അക്കം++] = atoi(argv[i]);
    }

    അട്ടി_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    എങ്കിൽ (res) {
        വേണ്ടി(i=0;i<=അട്ടി_ptr;i++) {
            printf("%d %c %d = %d\n",
                   അട്ടി_res[3*i], അട്ടി_op[i],
                   അട്ടി_res[3*i+1], അട്ടി_res[3*i+2]);
        }
        തിരികെ 0;
    } അല്ലെങ്കിൽ {
        printf("Impossible\n");
        തിരികെ 1;
    }
}
