ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *format, ...);
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_1(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ଯେତେବେଳେ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_2(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ପାଇଁ (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_2_1(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                କର {
                    printf("error\n");
		} ଯେତେବେଳେ (1);
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_2_2(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		ଯାଅ label;
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_3(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 1;
                ଯାଅ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_4(ଶୂନ୍ୟ)
{
    unsigned long timeout = 2;
    କର {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ବାଛ(timeout) {
                    ସ୍ଥିତି 2:
                        printf("timeout is 2");
                        ଭାଙ୍ଗ;
                    ସ୍ଥିତି 1:
                        printf("timeout is 1");
                        ଭାଙ୍ଗ;
                    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                        printf("timeout is 0?");
                        ଭାଙ୍ଗ;
                };
                // return;
            })
        );
        timeout--;
    } ଯେତେବେଳେ (timeout);
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ଫେରନ୍ତୁ 0;
}
