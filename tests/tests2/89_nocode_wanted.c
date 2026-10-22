बाह्य पूर्णाङ्क printf(ध्रुव वर्ण *format, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                जाव (1)
                    printf("error\n");
            })
        );
        timeout--;
    } जाव (timeout);
}
स्थिर शून्य kb_wait_2(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                प्रति (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } जाव (timeout);
}
स्थिर शून्य kb_wait_2_1(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                करेहि {
                    printf("error\n");
		} जाव (1);
            })
        );
        timeout--;
    } जाव (timeout);
}
स्थिर शून्य kb_wait_2_2(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		गच्छ label;
            })
        );
        timeout--;
    } जाव (timeout);
}
स्थिर शून्य kb_wait_3(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                पूर्णाङ्क i = 1;
                गच्छ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } जाव (timeout);
}
स्थिर शून्य kb_wait_4(शून्य)
{
    unsigned long timeout = 2;
    करेहि {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                विकल्प(timeout) {
                    पक्ष 2:
                        printf("timeout is 2");
                        भङ्ग;
                    पक्ष 1:
                        printf("timeout is 1");
                        भङ्ग;
                    स्वभाव:
                        printf("timeout is 0?");
                        भङ्ग;
                };
                // return;
            })
        );
        timeout--;
    } जाव (timeout);
}
पूर्णाङ्क main()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    प्रत्यागम 0;
}
