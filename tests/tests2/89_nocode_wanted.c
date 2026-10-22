बाह्य पूर्णाङ्क printf(ध्रुव वर्ण *format, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                यावत् (1)
                    printf("error\n");
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                प्रति (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2_1(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                कुरु {
                    printf("error\n");
		} यावत् (1);
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2_2(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		गच्छ label;
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_3(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
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
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_4(शून्य)
{
    unsigned long timeout = 2;
    कुरु {
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
    } यावत् (timeout);
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
