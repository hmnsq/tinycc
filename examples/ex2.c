#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

#define N 20

ಪೂರ್ಣಾಙ್ಕ nb_ಅಂಕೆ;
ಪೂರ್ಣಾಙ್ಕ tab[N];
ಪೂರ್ಣಾಙ್ಕ ರಾಶಿ_ptr;
ಪೂರ್ಣಾಙ್ಕ ರಾಶಿ_op[N];
ಪೂರ್ಣಾಙ್ಕ ರಾಶಿ_res[60];
ಪೂರ್ಣಾಙ್ಕ result;

ಪೂರ್ಣಾಙ್ಕ find(ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ i1, ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ i, j;
    ಪೂರ್ಣಾಙ್ಕ c;

    ಯದಿ (ರಾಶಿ_ptr >= 0) {
        ರಾಶಿ_res[3*ರಾಶಿ_ptr] = a;
        ರಾಶಿ_op[ರಾಶಿ_ptr] = op;
        ರಾಶಿ_res[3*ರಾಶಿ_ptr+1] = b;
        ರಾಶಿ_res[3*ರಾಶಿ_ptr+2] = n;
        ಯದಿ (n == result)
            ಪ್ರತ್ಯಾಗಮ 1;
        tab[i1] = n;
    }

    ಪ್ರತಿ(i=0;i<nb_ಅಂಕೆ;i++) {
        ಪ್ರತಿ(j=i+1;j<nb_ಅಂಕೆ;j++) {
            a = tab[i];
            b = tab[j];
            ಯದಿ (a != 0 && b != 0) {

                tab[j] = 0;
                ರಾಶಿ_ptr++;

                ಯದಿ (find(a + b, i, a, b, '+'))
                    ಪ್ರತ್ಯಾಗಮ 1;
                ಯದಿ (find(a - b, i, a, b, '-'))
                    ಪ್ರತ್ಯಾಗಮ 1;
                ಯದಿ (find(b - a, i, b, a, '-'))
                    ಪ್ರತ್ಯಾಗಮ 1;
                ಯದಿ (find(a * b, i, a, b, '*'))
                    ಪ್ರತ್ಯಾಗಮ 1;
                ಯದಿ (b != 0) {
                    c = a / b;
                    ಯದಿ (find(c, i, a, b, '/'))
                        ಪ್ರತ್ಯಾಗಮ 1;
                }

                ಯದಿ (a != 0) {
                    c = b / a;
                    ಯದಿ (find(c, i, b, a, '/'))
                        ಪ್ರತ್ಯಾಗಮ 1;
                }

                ರಾಶಿ_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ i, res, p;

    ಯದಿ (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_ಅಂಕೆ = 0;
    ಪ್ರತಿ(i=p+1;i<argc;i++) {
        tab[nb_ಅಂಕೆ++] = atoi(argv[i]);
    }

    ರಾಶಿ_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    ಯದಿ (res) {
        ಪ್ರತಿ(i=0;i<=ರಾಶಿ_ptr;i++) {
            printf("%d %c %d = %d\n",
                   ರಾಶಿ_res[3*i], ರಾಶಿ_op[i],
                   ರಾಶಿ_res[3*i+1], ರಾಶಿ_res[3*i+2]);
        }
        ಪ್ರತ್ಯಾಗಮ 0;
    } ಅನ್ಯಥಾ {
        printf("Impossible\n");
        ಪ್ರತ್ಯಾಗಮ 1;
    }
}
