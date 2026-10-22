బాహ్య పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం *format, ...);
స్థిర శూన్య kb_wait_1(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                అయితే (1)
                    రాయి("error\n");
            })
        );
        timeout--;
    } అయితే (timeout);
}
స్థిర శూన్య kb_wait_2(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                కొరకు (;;)
                    రాయి("error\n");
            })
        );
        timeout--;
    } అయితే (timeout);
}
స్థిర శూన్య kb_wait_2_1(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                చేయి {
                    రాయి("error\n");
		} అయితే (1);
            })
        );
        timeout--;
    } అయితే (timeout);
}
స్థిర శూన్య kb_wait_2_2(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                label:
                    రాయి("error\n");
		వెళ్ళు label;
            })
        );
        timeout--;
    } అయితే (timeout);
}
స్థిర శూన్య kb_wait_3(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                పూర్ణాంకం i = 1;
                వెళ్ళు label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } అయితే (timeout);
}
స్థిర శూన్య kb_wait_4(శూన్య)
{
    గుర్తులేని దీర్ఘ timeout = 2;
    చేయి {
        (1 ?
            రాయి("timeout=%ld\n", timeout) :
            ({
                ఎంపిక(timeout) {
                    స్థితి 2:
                        రాయి("timeout is 2");
                        ఆపు;
                    స్థితి 1:
                        రాయి("timeout is 1");
                        ఆపు;
                    అప్రమేయ:
                        రాయి("timeout is 0?");
                        ఆపు;
                };
                // return;
            })
        );
        timeout--;
    } అయితే (timeout);
}
పూర్ణాంకం ప్రధాన()
{
    రాయి("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    రాయి("end\n");
    తిరిగి 0;
}
