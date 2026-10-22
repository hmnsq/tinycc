வெளி முழு printf(மாறிலி எழுத்து *format, ...);
நிலையான வெறுமை kb_wait_1(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                போது (1)
                    printf("error\n");
            })
        );
        timeout--;
    } போது (timeout);
}
நிலையான வெறுமை kb_wait_2(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                க்கு (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } போது (timeout);
}
நிலையான வெறுமை kb_wait_2_1(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                செய் {
                    printf("error\n");
		} போது (1);
            })
        );
        timeout--;
    } போது (timeout);
}
நிலையான வெறுமை kb_wait_2_2(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		செல் label;
            })
        );
        timeout--;
    } போது (timeout);
}
நிலையான வெறுமை kb_wait_3(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                முழு i = 1;
                செல் label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } போது (timeout);
}
நிலையான வெறுமை kb_wait_4(வெறுமை)
{
    unsigned long timeout = 2;
    செய் {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                தேர்வு(timeout) {
                    நிலை 2:
                        printf("timeout is 2");
                        நிறுத்து;
                    நிலை 1:
                        printf("timeout is 1");
                        நிறுத்து;
                    இயல்பு:
                        printf("timeout is 0?");
                        நிறுத்து;
                };
                // return;
            })
        );
        timeout--;
    } போது (timeout);
}
முழு முதன்மை()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    திரும்பு 0;
}
