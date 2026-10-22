خارجي صحيح printf(ثابت حرف *format, ...);
ساكن فراغ kb_wait_1(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                طالما (1)
                    printf("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                لكل (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_1(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                𐤐𐤏𐤋 {
                    printf("error\n");
		} طالما (1);
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_2(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		اذهب label;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_3(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                صحيح i = 1;
                اذهب label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_4(فراغ)
{
    unsigned long timeout = 2;
    𐤐𐤏𐤋 {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                بدل(timeout) {
                    حالة 2:
                        printf("timeout is 2");
                        اكسر;
                    حالة 1:
                        printf("timeout is 1");
                        اكسر;
                    افتراضي:
                        printf("timeout is 0?");
                        اكسر;
                };
                // return;
            })
        );
        timeout--;
    } طالما (timeout);
}
صحيح main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    أرجع 0;
}
