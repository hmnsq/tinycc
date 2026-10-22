ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *format, ...);
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_1(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ಯಾವತ್ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ಪ್ರತಿ (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2_1(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ಕುರು {
                    printf("error\n");
		} ಯಾವತ್ (1);
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2_2(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		ಗಚ್ಛ label;
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_3(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ಪೂರ್ಣಾಙ್ಕ i = 1;
                ಗಚ್ಛ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_4(ಶೂನ್ಯ)
{
    unsigned long timeout = 2;
    ಕುರು {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ವಿಕಲ್ಪ(timeout) {
                    ಪಕ್ಷ 2:
                        printf("timeout is 2");
                        ಭಙ್ಗ;
                    ಪಕ್ಷ 1:
                        printf("timeout is 1");
                        ಭಙ್ಗ;
                    ಸ್ವಭಾವ:
                        printf("timeout is 0?");
                        ಭಙ್ಗ;
                };
                // return;
            })
        );
        timeout--;
    } ಯಾವತ್ (timeout);
}
ಪೂರ್ಣಾಙ್ಕ main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    ಪ್ರತ್ಯಾಗಮ 0;
}
