#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
    long long પૂર્ણાંક res = 0;

    જો (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        પાછા 1;
    }
    નહીંતર
    જો (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        પાછા 2;
    }
    નહીંતર
        printf("long long constant test ok.\n");
    પાછા 0;
}
