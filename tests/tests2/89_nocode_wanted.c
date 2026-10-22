extern පූර්ණ_සංඛ්‍යා printf(const var_na *format, ...);
static void kb_wait_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                අතරතුර (1)
                    printf("error\n");
            })
        );
        timeout--;
    } අතරතුර (timeout);
}
static void kb_wait_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                සඳහා (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } අතරතුර (timeout);
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
		} අතරතුර (1);
            })
        );
        timeout--;
    } අතරතුර (timeout);
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
    } අතරතුර (timeout);
}
static void kb_wait_3(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                පූර්ණ_සංඛ්‍යා i = 1;
                goto label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } අතරතුර (timeout);
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
    } අතරතුර (timeout);
}
පූර්ණ_සංඛ්‍යා main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ආපසු 0;
}
