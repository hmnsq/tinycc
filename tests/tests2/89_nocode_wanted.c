خارجی صحیح لکھو(ثابت حرف *format, ...);
ساکن خالی kb_wait_1(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                جب (1)
                    لکھو("error\n");
            })
        );
        timeout--;
    } جب (timeout);
}
ساکن خالی kb_wait_2(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                برائے (;;)
                    لکھو("error\n");
            })
        );
        timeout--;
    } جب (timeout);
}
ساکن خالی kb_wait_2_1(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                کرو {
                    لکھو("error\n");
		} جب (1);
            })
        );
        timeout--;
    } جب (timeout);
}
ساکن خالی kb_wait_2_2(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                label:
                    لکھو("error\n");
		جاؤ label;
            })
        );
        timeout--;
    } جب (timeout);
}
ساکن خالی kb_wait_3(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                صحیح i = 1;
                جاؤ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } جب (timeout);
}
ساکن خالی kb_wait_4(خالی)
{
    غیرعلامتی طویل timeout = 2;
    کرو {
        (1 ?
            لکھو("timeout=%ld\n", timeout) :
            ({
                انتخاب(timeout) {
                    حالت 2:
                        لکھو("timeout is 2");
                        توڑو;
                    حالت 1:
                        لکھو("timeout is 1");
                        توڑو;
                    طےشدہ:
                        لکھو("timeout is 0?");
                        توڑو;
                };
                // return;
            })
        );
        timeout--;
    } جب (timeout);
}
صحیح مین()
{
    لکھو("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    لکھو("end\n");
    واپس 0;
}
