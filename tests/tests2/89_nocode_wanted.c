ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *format, ...);
ਸਥਿਰ ਖਾਲੀ kb_wait_1(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                ਜਦੋਂ (1)
                    ਲਿਖੋ("error\n");
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਸਥਿਰ ਖਾਲੀ kb_wait_2(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                ਲਈ (;;)
                    ਲਿਖੋ("error\n");
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਸਥਿਰ ਖਾਲੀ kb_wait_2_1(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                ਕਰੋ {
                    ਲਿਖੋ("error\n");
		} ਜਦੋਂ (1);
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਸਥਿਰ ਖਾਲੀ kb_wait_2_2(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                label:
                    ਲਿਖੋ("error\n");
		ਜਾਓ label;
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਸਥਿਰ ਖਾਲੀ kb_wait_3(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                ਪੂਰਨ i = 1;
                ਜਾਓ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਸਥਿਰ ਖਾਲੀ kb_wait_4(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
    ਕਰੋ {
        (1 ?
            ਲਿਖੋ("timeout=%ld\n", timeout) :
            ({
                ਚੋਣ(timeout) {
                    ਹਾਲਤ 2:
                        ਲਿਖੋ("timeout is 2");
                        ਰੋਕੋ;
                    ਹਾਲਤ 1:
                        ਲਿਖੋ("timeout is 1");
                        ਰੋਕੋ;
                    ਮੂਲ:
                        ਲਿਖੋ("timeout is 0?");
                        ਰੋਕੋ;
                };
                // return;
            })
        );
        timeout--;
    } ਜਦੋਂ (timeout);
}
ਪੂਰਨ ਮੁੱਖ()
{
    ਲਿਖੋ("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    ਲਿਖੋ("end\n");
    ਵਾਪਸ 0;
}
