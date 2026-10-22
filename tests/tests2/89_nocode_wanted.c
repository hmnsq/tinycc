بیرونی صحیح printf(ثابت نویسه *format, ...);
ایستا تهی kb_wait_1(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                وقتی (1)
                    printf("error\n");
            })
        );
        timeout--;
    } وقتی (timeout);
}
ایستا تهی kb_wait_2(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                برای (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } وقتی (timeout);
}
ایستا تهی kb_wait_2_1(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                انجامبده {
                    printf("error\n");
		} وقتی (1);
            })
        );
        timeout--;
    } وقتی (timeout);
}
ایستا تهی kb_wait_2_2(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		برو label;
            })
        );
        timeout--;
    } وقتی (timeout);
}
ایستا تهی kb_wait_3(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                صحیح i = 1;
                برو label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } وقتی (timeout);
}
ایستا تهی kb_wait_4(تهی)
{
    unsigned long timeout = 2;
    انجامبده {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                انتخاب(timeout) {
                    حالت 2:
                        printf("timeout is 2");
                        بشکن;
                    حالت 1:
                        printf("timeout is 1");
                        بشکن;
                    پیشفرض:
                        printf("timeout is 0?");
                        بشکن;
                };
                // return;
            })
        );
        timeout--;
    } وقتی (timeout);
}
صحیح اصلی()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    بازگشت 0;
}
