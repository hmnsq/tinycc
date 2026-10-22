#include <stdio.h>

整数
メインページ (void)
{
    整数 n = 0;
    整数  first=1;
    整数 *p[101];
    もし (0) {
        lab:;
    }
    整数 x[n % 100 + 1];
    もし (first == 0) {
        もし (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            戻る(1);
        }
    }
    否则 {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    もし (n < 100000)
        goto lab;
    printf ("OK\n");
    戻る 0;
}

