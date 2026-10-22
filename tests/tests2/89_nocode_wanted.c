বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *format, ...);
স্থির শূন্য kb_wait_1(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                যখন (1)
                    printf("error\n");
            })
        );
        timeout--;
    } যখন (timeout);
}
স্থির শূন্য kb_wait_2(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                জন্য (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } যখন (timeout);
}
স্থির শূন্য kb_wait_2_1(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                করো {
                    printf("error\n");
		} যখন (1);
            })
        );
        timeout--;
    } যখন (timeout);
}
স্থির শূন্য kb_wait_2_2(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		যাও label;
            })
        );
        timeout--;
    } যখন (timeout);
}
স্থির শূন্য kb_wait_3(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                পূর্ণসংখ্যা i = 1;
                যাও label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } যখন (timeout);
}
স্থির শূন্য kb_wait_4(শূন্য)
{
    unsigned long timeout = 2;
    করো {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                নির্বাচন(timeout) {
                    ক্ষেত্র 2:
                        printf("timeout is 2");
                        বিরতি;
                    ক্ষেত্র 1:
                        printf("timeout is 1");
                        বিরতি;
                    পূর্বনির্ধারিত:
                        printf("timeout is 0?");
                        বিরতি;
                };
                // return;
            })
        );
        timeout--;
    } যখন (timeout);
}
পূর্ণসংখ্যা প্রধান()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ফেরত 0;
}
