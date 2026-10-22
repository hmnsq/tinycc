ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_1(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                ಆಗ (1)
                    ಬರೆ("error\n");
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                ಗಾಗಿ (;;)
                    ಬರೆ("error\n");
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2_1(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                ಮಾಡು {
                    ಬರೆ("error\n");
		} ಆಗ (1);
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_2_2(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                label:
                    ಬರೆ("error\n");
		ಹೋಗು label;
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_3(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                ಪೂರ್ಣಾಂಕ i = 1;
                ಹೋಗು label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_4(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
    ಮಾಡು {
        (1 ?
            ಬರೆ("timeout=%ld\n", timeout) :
            ({
                ಆಯ್ಕೆ(timeout) {
                    ಸ್ಥಿತಿ 2:
                        ಬರೆ("timeout is 2");
                        ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ 1:
                        ಬರೆ("timeout is 1");
                        ನಿಲ್ಲಿಸು;
                    ಪೂರ್ವನಿಯೋಜಿತ:
                        ಬರೆ("timeout is 0?");
                        ನಿಲ್ಲಿಸು;
                };
                // return;
            })
        );
        timeout--;
    } ಆಗ (timeout);
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಬರೆ("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    ಬರೆ("end\n");
    ಹಿಂತಿರುಗಿ 0;
}
