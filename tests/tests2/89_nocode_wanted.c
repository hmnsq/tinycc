extern ចំនួនគត់ printf(const var_na *format, ...);
static void kb_wait_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ខណៈពេល (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ខណៈពេល (timeout);
}
static void kb_wait_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                សម្រាប់ (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ខណៈពេល (timeout);
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
		} ខណៈពេល (1);
            })
        );
        timeout--;
    } ខណៈពេល (timeout);
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
    } ខណៈពេល (timeout);
}
static void kb_wait_3(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ចំនួនគត់ i = 1;
                goto label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ខណៈពេល (timeout);
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
    } ខណៈពេល (timeout);
}
ចំនួនគត់ main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ត្រឡប់ 0;
}
