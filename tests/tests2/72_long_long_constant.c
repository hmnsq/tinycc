#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
    long long முழு res = 0;

    எனில் (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        திரும்பு 1;
    }
    இல்லையெனில்
    எனில் (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        திரும்பு 2;
    }
    இல்லையெனில்
        printf("long long constant test ok.\n");
    திரும்பு 0;
}
