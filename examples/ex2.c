#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>

#define N 20

पूर्णाङ्क nb_अङ्क;
पूर्णाङ्क tab[N];
पूर्णाङ्क थाक_ptr;
पूर्णाङ्क थाक_op[N];
पूर्णाङ्क थाक_res[60];
पूर्णाङ्क result;

पूर्णाङ्क find(पूर्णाङ्क n, पूर्णाङ्क i1, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क op)
{
    पूर्णाङ्क i, j;
    पूर्णाङ्क c;

    यदि (थाक_ptr >= 0) {
        थाक_res[3*थाक_ptr] = a;
        थाक_op[थाक_ptr] = op;
        थाक_res[3*थाक_ptr+1] = b;
        थाक_res[3*थाक_ptr+2] = n;
        यदि (n == result)
            फर्काऊ 1;
        tab[i1] = n;
    }

    लागि(i=0;i<nb_अङ्क;i++) {
        लागि(j=i+1;j<nb_अङ्क;j++) {
            a = tab[i];
            b = tab[j];
            यदि (a != 0 && b != 0) {

                tab[j] = 0;
                थाक_ptr++;

                यदि (find(a + b, i, a, b, '+'))
                    फर्काऊ 1;
                यदि (find(a - b, i, a, b, '-'))
                    फर्काऊ 1;
                यदि (find(b - a, i, b, a, '-'))
                    फर्काऊ 1;
                यदि (find(a * b, i, a, b, '*'))
                    फर्काऊ 1;
                यदि (b != 0) {
                    c = a / b;
                    यदि (find(c, i, a, b, '/'))
                        फर्काऊ 1;
                }

                यदि (a != 0) {
                    c = b / a;
                    यदि (find(c, i, b, a, '/'))
                        फर्काऊ 1;
                }

                थाक_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    फर्काऊ 0;
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क i, res, p;

    यदि (argc < 3) {
        म_लिखो("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        निकास(1);
    }

    p = 1;
    result = म_से_प(argv[p]);
    म_लिखो("result=%d\n", result);
    nb_अङ्क = 0;
    लागि(i=p+1;i<argc;i++) {
        tab[nb_अङ्क++] = म_से_प(argv[i]);
    }

    थाक_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    यदि (res) {
        लागि(i=0;i<=थाक_ptr;i++) {
            म_लिखो("%d %c %d = %d\n",
                   थाक_res[3*i], थाक_op[i],
                   थाक_res[3*i+1], थाक_res[3*i+2]);
        }
        फर्काऊ 0;
    } अन्यथा {
        म_लिखो("Impossible\n");
        फर्काऊ 1;
    }
}
