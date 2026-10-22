#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>

#define N 20

முழு nb_இலக்கம்;
முழு tab[N];
முழு அடுக்கு_ptr;
முழு அடுக்கு_op[N];
முழு அடுக்கு_res[60];
முழு result;

முழு find(முழு n, முழு i1, முழு a, முழு b, முழு op)
{
    முழு i, j;
    முழு c;

    எனில் (அடுக்கு_ptr >= 0) {
        அடுக்கு_res[3*அடுக்கு_ptr] = a;
        அடுக்கு_op[அடுக்கு_ptr] = op;
        அடுக்கு_res[3*அடுக்கு_ptr+1] = b;
        அடுக்கு_res[3*அடுக்கு_ptr+2] = n;
        எனில் (n == result)
            திரும்பு 1;
        tab[i1] = n;
    }

    க்கு(i=0;i<nb_இலக்கம்;i++) {
        க்கு(j=i+1;j<nb_இலக்கம்;j++) {
            a = tab[i];
            b = tab[j];
            எனில் (a != 0 && b != 0) {

                tab[j] = 0;
                அடுக்கு_ptr++;

                எனில் (find(a + b, i, a, b, '+'))
                    திரும்பு 1;
                எனில் (find(a - b, i, a, b, '-'))
                    திரும்பு 1;
                எனில் (find(b - a, i, b, a, '-'))
                    திரும்பு 1;
                எனில் (find(a * b, i, a, b, '*'))
                    திரும்பு 1;
                எனில் (b != 0) {
                    c = a / b;
                    எனில் (find(c, i, a, b, '/'))
                        திரும்பு 1;
                }

                எனில் (a != 0) {
                    c = b / a;
                    எனில் (find(c, i, b, a, '/'))
                        திரும்பு 1;
                }

                அடுக்கு_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    திரும்பு 0;
}

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    முழு i, res, p;

    எனில் (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_இலக்கம் = 0;
    க்கு(i=p+1;i<argc;i++) {
        tab[nb_இலக்கம்++] = atoi(argv[i]);
    }

    அடுக்கு_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    எனில் (res) {
        க்கு(i=0;i<=அடுக்கு_ptr;i++) {
            printf("%d %c %d = %d\n",
                   அடுக்கு_res[3*i], அடுக்கு_op[i],
                   அடுக்கு_res[3*i+1], அடுக்கு_res[3*i+2]);
        }
        திரும்பு 0;
    } இல்லையெனில் {
        printf("Impossible\n");
        திரும்பு 1;
    }
}
