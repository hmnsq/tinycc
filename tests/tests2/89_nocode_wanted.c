خارجي صحيح چاپ_کن(ثابت حرف *format, ...);
ساكن فراغ kb_wait_1(فراغ)
{
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
            ({
                طالما (1)
                    چاپ_کن("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2(فراغ)
{
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
            ({
                لكل (;;)
                    چاپ_کن("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_1(فراغ)
{
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
            ({
                افعل {
                    چاپ_کن("error\n");
		} طالما (1);
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_2(فراغ)
{
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
            ({
                label:
                    چاپ_کن("error\n");
		اذهب label;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_3(فراغ)
{
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
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
    بیعلامت دراز timeout = 2;
    افعل {
        (1 ?
            چاپ_کن("timeout=%ld\n", timeout) :
            ({
                بدل(timeout) {
                    حالة 2:
                        چاپ_کن("timeout is 2");
                        اكسر;
                    حالة 1:
                        چاپ_کن("timeout is 1");
                        اكسر;
                    افتراضي:
                        چاپ_کن("timeout is 0?");
                        اكسر;
                };
                // return;
            })
        );
        timeout--;
    } طالما (timeout);
}
صحيح اصلی()
{
    چاپ_کن("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    چاپ_کن("end\n");
    أرجع 0;
}
