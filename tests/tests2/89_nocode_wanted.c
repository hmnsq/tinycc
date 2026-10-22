خارجي صحيح چاپ_کړه(ثابت حرف *format, ...);
ساكن فراغ kb_wait_1(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                طالما (1)
                    چاپ_کړه("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                لكل (;;)
                    چاپ_کړه("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_1(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                افعل {
                    چاپ_کړه("error\n");
		} طالما (1);
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_2(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                label:
                    چاپ_کړه("error\n");
		اذهب label;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_3(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                صحيح i = 1;
                اذهب label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_4(فراغ)
{
    بینښه اوږد timeout = 2;
    افعل {
        (1 ?
            چاپ_کړه("timeout=%ld\n", timeout) :
            ({
                بدل(timeout) {
                    حالة 2:
                        چاپ_کړه("timeout is 2");
                        اكسر;
                    حالة 1:
                        چاپ_کړه("timeout is 1");
                        اكسر;
                    افتراضي:
                        چاپ_کړه("timeout is 0?");
                        اكسر;
                };
                // return;
            })
        );
        timeout--;
    } طالما (timeout);
}
صحيح اصلي()
{
    چاپ_کړه("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    چاپ_کړه("end\n");
    أرجع 0;
}
