বাহ্য পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *format, ...);
স্থির শূন্য kb_wait_1(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                যেতিয়ালৈ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } যেতিয়ালৈ (timeout);
}
স্থির শূন্য kb_wait_2(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                বাবে (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } যেতিয়ালৈ (timeout);
}
স্থির শূন্য kb_wait_2_1(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                কৰা {
                    printf("error\n");
		} যেতিয়ালৈ (1);
            })
        );
        timeout--;
    } যেতিয়ালৈ (timeout);
}
স্থির শূন্য kb_wait_2_2(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		গচ্ছ label;
            })
        );
        timeout--;
    } যেতিয়ালৈ (timeout);
}
স্থির শূন্য kb_wait_3(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
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
    } যেতিয়ালৈ (timeout);
}
স্থির শূন্য kb_wait_4(শূন্য)
{
    unsigned long timeout = 2;
    কৰা {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ৱিকল্প(timeout) {
                    পক্ষ 2:
                        printf("timeout is 2");
                        ভঙ্গ;
                    পক্ষ 1:
                        printf("timeout is 1");
                        ভঙ্গ;
                    স্ৱভাৱ:
                        printf("timeout is 0?");
                        ভঙ্গ;
                };
                // return;
            })
        );
        timeout--;
    } যেতিয়ালৈ (timeout);
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
    ঘূৰাই 0;
}
