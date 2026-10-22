خارجي صحيح لکھو(ثابت حرف *format, ...);
ساكن فراغ kb_wait_1(فراغ)
{
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                طالما (1)
                    لکھو("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2(فراغ)
{
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                لكل (;;)
                    لکھو("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_1(فراغ)
{
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                افعل {
                    لکھو("error\n");
		} طالما (1);
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_2(فراغ)
{
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                label:
                    لکھو("error\n");
		اذهب label;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_3(فراغ)
{
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
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
    بنانشانی لما timeout = 2;
    افعل {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                بدل(timeout) {
                    حالة 2:
                        لکھو("timeout is 2");
                        اكسر;
                    حالة 1:
                        لکھو("timeout is 1");
                        اكسر;
                    افتراضي:
                        لکھو("timeout is 0?");
                        اكسر;
                };
                // return;
            })
        );
        timeout--;
    } طالما (timeout);
}
صحيح مکھ()
{
    لکھو("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    لکھو("end\n");
    أرجع 0;
}
