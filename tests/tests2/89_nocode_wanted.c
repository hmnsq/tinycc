extern จำนวนเต็ม printf(const var_na *format, ...);
static void kb_wait_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ขณะ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ขณะ (timeout);
}
static void kb_wait_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                สำหรับ (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ขณะ (timeout);
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
		} ขณะ (1);
            })
        );
        timeout--;
    } ขณะ (timeout);
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
    } ขณะ (timeout);
}
static void kb_wait_3(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                จำนวนเต็ม i = 1;
                goto label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ขณะ (timeout);
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
    } ขณะ (timeout);
}
จำนวนเต็ม หลัก()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    คืน 0;
}
