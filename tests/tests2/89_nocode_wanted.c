extern 整数 printf(const char *format, ...);
static void kb_wait_1(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ながら (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ながら (timeout);
}
static void kb_wait_2(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ために (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ながら (timeout);
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
		} ながら (1);
            })
        );
        timeout--;
    } ながら (timeout);
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
    } ながら (timeout);
}
static void kb_wait_3(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                整数 i = 1;
                goto label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ながら (timeout);
}
static void kb_wait_4(void)
{
    unsigned long timeout = 2;
    do {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                switch(timeout) {
                    case 2:
                        printf("timeout is 2");
                        break;
                    case 1:
                        printf("timeout is 1");
                        break;
                    default:
                        printf("timeout is 0?");
                        break;
                };
                // return;
            })
        );
        timeout--;
    } ながら (timeout);
}
整数 メインページ()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    戻る 0;
}
