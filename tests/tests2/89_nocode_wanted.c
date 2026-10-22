બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર *format, ...);
સ્થિર શૂન્ય kb_wait_1(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                જ્યારે (1)
                    printf("error\n");
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
સ્થિર શૂન્ય kb_wait_2(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                માટે (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
સ્થિર શૂન્ય kb_wait_2_1(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                કરો {
                    printf("error\n");
		} જ્યારે (1);
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
સ્થિર શૂન્ય kb_wait_2_2(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		જાઓ label;
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
સ્થિર શૂન્ય kb_wait_3(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                પૂર્ણાંક i = 1;
                જાઓ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
સ્થિર શૂન્ય kb_wait_4(શૂન્ય)
{
    unsigned long timeout = 2;
    કરો {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                પસંદગી(timeout) {
                    સ્થિતિ 2:
                        printf("timeout is 2");
                        તોડો;
                    સ્થિતિ 1:
                        printf("timeout is 1");
                        તોડો;
                    મૂળભૂત:
                        printf("timeout is 0?");
                        તોડો;
                };
                // return;
            })
        );
        timeout--;
    } જ્યારે (timeout);
}
પૂર્ણાંક મુખ્ય()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    પાછા 0;
}
