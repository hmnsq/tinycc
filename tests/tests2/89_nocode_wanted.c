خارجي صحيح لکو(ثابت حرف *format, ...);
ساكن فراغ kb_wait_1(فراغ)
{
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
            ({
                طالما (1)
                    لکو("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2(فراغ)
{
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
            ({
                لكل (;;)
                    لکو("error\n");
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_1(فراغ)
{
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
            ({
                افعل {
                    لکو("error\n");
		} طالما (1);
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_2_2(فراغ)
{
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
            ({
                label:
                    لکو("error\n");
		اذهب label;
            })
        );
        timeout--;
    } طالما (timeout);
}
ساكن فراغ kb_wait_3(فراغ)
{
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
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
    بنانشان ڊگهو timeout = 2;
    افعل {
        (1 ?
            لکو("timeout=%ld\n", timeout) :
            ({
                بدل(timeout) {
                    حالة 2:
                        لکو("timeout is 2");
                        اكسر;
                    حالة 1:
                        لکو("timeout is 1");
                        اكسر;
                    افتراضي:
                        لکو("timeout is 0?");
                        اكسر;
                };
                // return;
            })
        );
        timeout--;
    } طالما (timeout);
}
صحيح مکيه()
{
    لکو("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    لکو("end\n");
    أرجع 0;
}
