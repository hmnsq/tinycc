बाह्य पूर्णांक म_लिखो(स्थिरांक अक्षर *format, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                पर्यंत (1)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
स्थिर शून्य kb_wait_2(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                साठी (;;)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
स्थिर शून्य kb_wait_2_1(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                करा {
                    म_लिखो("error\n");
		} पर्यंत (1);
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
स्थिर शून्य kb_wait_2_2(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                label:
                    म_लिखो("error\n");
		जा label;
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
स्थिर शून्य kb_wait_3(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                पूर्णांक i = 1;
                जा label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
स्थिर शून्य kb_wait_4(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    करा {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                निवड(timeout) {
                    स्थिती 2:
                        म_लिखो("timeout is 2");
                        थांबा;
                    स्थिती 1:
                        म_लिखो("timeout is 1");
                        थांबा;
                    पूर्वनिर्धारित:
                        म_लिखो("timeout is 0?");
                        थांबा;
                };
                // return;
            })
        );
        timeout--;
    } पर्यंत (timeout);
}
पूर्णांक main()
{
    म_लिखो("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    म_लिखो("end\n");
    परत 0;
}
