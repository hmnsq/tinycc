extern ကိန်းပြည့် printf(const var_na *format, ...);
static void kb_wait_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                နေစဉ် (1)
                    printf("error\n");
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
static void kb_wait_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                အတွက် (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
static void kb_wait_2_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                do {
                    printf("error\n");
		} နေစဉ် (1);
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
static void kb_wait_2_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		goto label;
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
static void kb_wait_3(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ကိန်းပြည့် i = 1;
                goto label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
static void kb_wait_4(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                switch(timeout) {
                    pak_sa 2:
                        printf("timeout is 2");
                        bha_nga;
                    pak_sa 1:
                        printf("timeout is 1");
                        bha_nga;
                    default:
                        printf("timeout is 0?");
                        bha_nga;
                };
                // return;
            })
        );
        timeout--;
    } နေစဉ် (timeout);
}
ကိန်းပြည့် main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ပြန်ပေး 0;
}
