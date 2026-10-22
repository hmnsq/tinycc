#ضمن <stdlib.h>
#ضمن <stdio.h>

#define N 20

صحيح nb_num;
صحيح tab[N];
صحيح stack_ptr;
صحيح stack_op[N];
صحيح stack_res[60];
صحيح result;

صحيح find(صحيح n, صحيح i1, صحيح a, صحيح b, صحيح op)
{
    صحيح i, j;
    صحيح c;

    אם (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        אם (n == result)
            החזר 1;
        tab[i1] = n;
    }

    עבור(i=0;i<nb_num;i++) {
        עבור(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            אם (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                אם (find(a + b, i, a, b, '+'))
                    החזר 1;
                אם (find(a - b, i, a, b, '-'))
                    החזר 1;
                אם (find(b - a, i, b, a, '-'))
                    החזר 1;
                אם (find(a * b, i, a, b, '*'))
                    החזר 1;
                אם (b != 0) {
                    c = a / b;
                    אם (find(c, i, a, b, '/'))
                        החזר 1;
                }

                אם (a != 0) {
                    c = b / a;
                    אם (find(c, i, b, a, '/'))
                        החזר 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    החזר 0;
}

صحيح main(صحيح argc, حرف **argv)
{
    صحيح i, res, p;

    אם (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    עבור(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    אם (res) {
        עבור(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        החזר 0;
    } אחרת {
        printf("Impossible\n");
        החזר 1;
    }
}
