ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *format, ...);
സ്ഥിതം ശൂന്യം kb_wait_1(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ആകുമ്പോൾ (1)
                    printf("error\n");
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
സ്ഥിതം ശൂന്യം kb_wait_2(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                വേണ്ടി (;;)
                    printf("error\n");
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
സ്ഥിതം ശൂന്യം kb_wait_2_1(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                ചെയ്യുക {
                    printf("error\n");
		} ആകുമ്പോൾ (1);
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
സ്ഥിതം ശൂന്യം kb_wait_2_2(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                label:
                    printf("error\n");
		പോകുക label;
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
സ്ഥിതം ശൂന്യം kb_wait_3(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                പൂർണ്ണസംഖ്യ i = 1;
                പോകുക label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
സ്ഥിതം ശൂന്യം kb_wait_4(ശൂന്യം)
{
    unsigned long timeout = 2;
    ചെയ്യുക {
        (1 ?
            printf("timeout=%ld\n", timeout) :
            ({
                തിരഞ്ഞെടുപ്പ്(timeout) {
                    അവസ്ഥ 2:
                        printf("timeout is 2");
                        നിർത്തുക;
                    അവസ്ഥ 1:
                        printf("timeout is 1");
                        നിർത്തുക;
                    സ്ഥിരസ്ഥിതി:
                        printf("timeout is 0?");
                        നിർത്തുക;
                };
                // return;
            })
        );
        timeout--;
    } ആകുമ്പോൾ (timeout);
}
പൂർണ്ണസംഖ്യ പ്രധാന()
{
    printf("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    printf("end\n");
    തിരികെ 0;
}
