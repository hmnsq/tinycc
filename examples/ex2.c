#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>

#define N 20

પૂર્ણાંક nb_અંક;
પૂર્ણાંક tab[N];
પૂર્ણાંક ઢગલો_ptr;
પૂર્ણાંક ઢગલો_op[N];
પૂર્ણાંક ઢગલો_res[60];
પૂર્ણાંક result;

પૂર્ણાંક find(પૂર્ણાંક n, પૂર્ણાંક i1, પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક op)
{
    પૂર્ણાંક i, j;
    પૂર્ણાંક c;

    જો (ઢગલો_ptr >= 0) {
        ઢગલો_res[3*ઢગલો_ptr] = a;
        ઢગલો_op[ઢગલો_ptr] = op;
        ઢગલો_res[3*ઢગલો_ptr+1] = b;
        ઢગલો_res[3*ઢગલો_ptr+2] = n;
        જો (n == result)
            પાછા 1;
        tab[i1] = n;
    }

    માટે(i=0;i<nb_અંક;i++) {
        માટે(j=i+1;j<nb_અંક;j++) {
            a = tab[i];
            b = tab[j];
            જો (a != 0 && b != 0) {

                tab[j] = 0;
                ઢગલો_ptr++;

                જો (find(a + b, i, a, b, '+'))
                    પાછા 1;
                જો (find(a - b, i, a, b, '-'))
                    પાછા 1;
                જો (find(b - a, i, b, a, '-'))
                    પાછા 1;
                જો (find(a * b, i, a, b, '*'))
                    પાછા 1;
                જો (b != 0) {
                    c = a / b;
                    જો (find(c, i, a, b, '/'))
                        પાછા 1;
                }

                જો (a != 0) {
                    c = b / a;
                    જો (find(c, i, b, a, '/'))
                        પાછા 1;
                }

                ઢગલો_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    પાછા 0;
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક i, res, p;

    જો (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_અંક = 0;
    માટે(i=p+1;i<argc;i++) {
        tab[nb_અંક++] = atoi(argv[i]);
    }

    ઢગલો_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    જો (res) {
        માટે(i=0;i<=ઢગલો_ptr;i++) {
            printf("%d %c %d = %d\n",
                   ઢગલો_res[3*i], ઢગલો_op[i],
                   ઢગલો_res[3*i+1], ઢગલો_res[3*i+2]);
        }
        પાછા 0;
    } નહીંતર {
        printf("Impossible\n");
        પાછા 1;
    }
}
