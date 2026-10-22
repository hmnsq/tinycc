#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>

#define N 20

पूर्णांक nb_अंक;
पूर्णांक tab[N];
पूर्णांक चळत_ptr;
पूर्णांक चळत_op[N];
पूर्णांक चळत_res[60];
पूर्णांक result;

पूर्णांक find(पूर्णांक n, पूर्णांक i1, पूर्णांक a, पूर्णांक b, पूर्णांक op)
{
    पूर्णांक i, j;
    पूर्णांक c;

    जर (चळत_ptr >= 0) {
        चळत_res[3*चळत_ptr] = a;
        चळत_op[चळत_ptr] = op;
        चळत_res[3*चळत_ptr+1] = b;
        चळत_res[3*चळत_ptr+2] = n;
        जर (n == result)
            परत 1;
        tab[i1] = n;
    }

    साठी(i=0;i<nb_अंक;i++) {
        साठी(j=i+1;j<nb_अंक;j++) {
            a = tab[i];
            b = tab[j];
            जर (a != 0 && b != 0) {

                tab[j] = 0;
                चळत_ptr++;

                जर (find(a + b, i, a, b, '+'))
                    परत 1;
                जर (find(a - b, i, a, b, '-'))
                    परत 1;
                जर (find(b - a, i, b, a, '-'))
                    परत 1;
                जर (find(a * b, i, a, b, '*'))
                    परत 1;
                जर (b != 0) {
                    c = a / b;
                    जर (find(c, i, a, b, '/'))
                        परत 1;
                }

                जर (a != 0) {
                    c = b / a;
                    जर (find(c, i, b, a, '/'))
                        परत 1;
                }

                चळत_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    परत 0;
}

पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक i, res, p;

    जर (argc < 3) {
        म_लिखो("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        निकास(1);
    }

    p = 1;
    result = म_से_प(argv[p]);
    म_लिखो("result=%d\n", result);
    nb_अंक = 0;
    साठी(i=p+1;i<argc;i++) {
        tab[nb_अंक++] = म_से_प(argv[i]);
    }

    चळत_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    जर (res) {
        साठी(i=0;i<=चळत_ptr;i++) {
            म_लिखो("%d %c %d = %d\n",
                   चळत_res[3*i], चळत_op[i],
                   चळत_res[3*i+1], चळत_res[3*i+2]);
        }
        परत 0;
    } अन्यथा {
        म_लिखो("Impossible\n");
        परत 1;
    }
}
