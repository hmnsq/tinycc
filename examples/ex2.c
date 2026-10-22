#include <stdlib.h>
#include <stdio.h>

#define N 20

puur_naa_nka nb_num;
puur_naa_nka tab[N];
puur_naa_nka stack_ptr;
puur_naa_nka stack_op[N];
puur_naa_nka stack_res[60];
puur_naa_nka result;

puur_naa_nka find(puur_naa_nka n, puur_naa_nka i1, puur_naa_nka a, puur_naa_nka b, puur_naa_nka op)
{
    puur_naa_nka i, j;
    puur_naa_nka c;

    ᯀᯮᯝ (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        ᯀᯮᯝ (n == result)
            ᯀᯮᯞ 1;
        tab[i1] = n;
    }

    for(i=0;i<nb_num;i++) {
        for(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            ᯀᯮᯝ (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                ᯀᯮᯝ (find(a + b, i, a, b, '+'))
                    ᯀᯮᯞ 1;
                ᯀᯮᯝ (find(a - b, i, a, b, '-'))
                    ᯀᯮᯞ 1;
                ᯀᯮᯝ (find(b - a, i, b, a, '-'))
                    ᯀᯮᯞ 1;
                ᯀᯮᯝ (find(a * b, i, a, b, '*'))
                    ᯀᯮᯞ 1;
                ᯀᯮᯝ (b != 0) {
                    c = a / b;
                    ᯀᯮᯝ (find(c, i, a, b, '/'))
                        ᯀᯮᯞ 1;
                }

                ᯀᯮᯝ (a != 0) {
                    c = b / a;
                    ᯀᯮᯝ (find(c, i, b, a, '/'))
                        ᯀᯮᯞ 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ᯀᯮᯞ 0;
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    puur_naa_nka i, res, p;

    ᯀᯮᯝ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    for(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ᯀᯮᯝ (res) {
        for(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        ᯀᯮᯞ 0;
    } ᯀᯮᯝᯂᯪ {
        printf("Impossible\n");
        ᯀᯮᯞ 1;
    }
}
