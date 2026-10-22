বাহ্য পূর্ণাঙ্ক printf(ধ্রুব বর্ণ *format, ...);
স্থির শূন্য kb_wait_1(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                যাবত্ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
স্থির শূন্য kb_wait_2(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                প্রতি (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
স্থির শূন্য kb_wait_2_1(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                কুরু {
                    printf("error\n");
		} যাবত্ (1);
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
স্থির শূন্য kb_wait_2_2(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		গচ্ছ label;
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
স্থির শূন্য kb_wait_3(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                পূর্ণাঙ্ক i = 1;
                গচ্ছ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
স্থির শূন্য kb_wait_4(শূন্য)
{
    unsigned long timeout = 2;
    কুরু {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                বিকল্প(timeout) {
                    পক্ষ 2:
                        printf("timeout is 2");
                        ভঙ্গ;
                    পক্ষ 1:
                        printf("timeout is 1");
                        ভঙ্গ;
                    স্বভাব:
                        printf("timeout is 0?");
                        ভঙ্গ;
                };
                // return;
            })
        );
        timeout--;
    } যাবত্ (timeout);
}
পূর্ণাঙ্ক main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    প্রত্যাগম 0;
}
