बाह्य पूर्णांक म_लिखो(स्थिर अक्षर *format, ...);
अटल व्योम kb_wait_1(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                जबतक (1)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } जबतक (timeout);
}
अटल व्योम kb_wait_2(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                क्रम (;;)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } जबतक (timeout);
}
अटल व्योम kb_wait_2_1(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                करो {
                    म_लिखो("error\n");
		} जबतक (1);
            })
        );
        timeout--;
    } जबतक (timeout);
}
अटल व्योम kb_wait_2_2(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                label:
                    म_लिखो("error\n");
		जाओ label;
            })
        );
        timeout--;
    } जबतक (timeout);
}
अटल व्योम kb_wait_3(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                पूर्णांक i = 1;
                जाओ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } जबतक (timeout);
}
अटल व्योम kb_wait_4(व्योम)
{
    अचिन्हित दीर्घ timeout = 2;
    करो {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                चयन(timeout) {
                    हाल 2:
                        म_लिखो("timeout is 2");
                        अवरोध;
                    हाल 1:
                        म_लिखो("timeout is 1");
                        अवरोध;
                    शेष:
                        म_लिखो("timeout is 0?");
                        अवरोध;
                };
                // return;
            })
        );
        timeout--;
    } जबतक (timeout);
}
पूर्णांक मुख्य()
{
    म_लिखो("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    म_लिखो("end\n");
    वापस 0;
}
