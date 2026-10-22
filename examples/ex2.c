#include <stdlib.h>
#include <stdio.h>

#define N 20

int nb_नुमेरो;
int tab[N];
int सालानसान_ptr;
int सालानसान_op[N];
int सालानसान_res[60];
int result;

int find(int n, int i1, int a, int b, int op)
{
    int i, j;
    int c;

    if (सालानसान_ptr >= 0) {
        सालानसान_res[3*सालानसान_ptr] = a;
        सालानसान_op[सालानसान_ptr] = op;
        सालानसान_res[3*सालानसान_ptr+1] = b;
        सालानसान_res[3*सालानसान_ptr+2] = n;
        if (n == result)
            return 1;
        tab[i1] = n;
    }

    for(i=0;i<nb_नुमेरो;i++) {
        for(j=i+1;j<nb_नुमेरो;j++) {
            a = tab[i];
            b = tab[j];
            if (a != 0 && b != 0) {

                tab[j] = 0;
                सालानसान_ptr++;

                if (find(a + b, i, a, b, '+'))
                    return 1;
                if (find(a - b, i, a, b, '-'))
                    return 1;
                if (find(b - a, i, b, a, '-'))
                    return 1;
                if (find(a * b, i, a, b, '*'))
                    return 1;
                if (b != 0) {
                    c = a / b;
                    if (find(c, i, a, b, '/'))
                        return 1;
                }

                if (a != 0) {
                    c = b / a;
                    if (find(c, i, b, a, '/'))
                        return 1;
                }

                सालानसान_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    int i, res, p;

    if (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_नुमेरो = 0;
    for(i=p+1;i<argc;i++) {
        tab[nb_नुमेरो++] = atoi(argv[i]);
    }

    सालानसान_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    if (res) {
        for(i=0;i<=सालानसान_ptr;i++) {
            printf("%d %c %d = %d\n",
                   सालानसान_res[3*i], सालानसान_op[i],
                   सालानसान_res[3*i+1], सालानसान_res[3*i+2]);
        }
        return 0;
    } else {
        printf("Impossible\n");
        return 1;
    }
}
