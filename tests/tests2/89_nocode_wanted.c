बाह्य पूर्णाङ्क म_लिखो(अचर वर्ण *format, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                जबसम्म (1)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
स्थिर शून्य kb_wait_2(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                लागि (;;)
                    म_लिखो("error\n");
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
स्थिर शून्य kb_wait_2_1(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                गर {
                    म_लिखो("error\n");
		} जबसम्म (1);
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
स्थिर शून्य kb_wait_2_2(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                label:
                    म_लिखो("error\n");
		गच्छ label;
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
स्थिर शून्य kb_wait_3(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                पूर्णाङ्क i = 1;
                गच्छ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
स्थिर शून्य kb_wait_4(शून्य)
{
    अचिन्हित दीर्घ timeout = 2;
    गर {
        (1 ?
            म_लिखो("timeout=%ld\n", timeout) :
            ({
                विकल्प(timeout) {
                    पक्ष 2:
                        म_लिखो("timeout is 2");
                        रोक;
                    पक्ष 1:
                        म_लिखो("timeout is 1");
                        रोक;
                    स्वभाव:
                        म_लिखो("timeout is 0?");
                        रोक;
                };
                // return;
            })
        );
        timeout--;
    } जबसम्म (timeout);
}
पूर्णाङ्क main()
{
    म_लिखो("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    म_लिखो("end\n");
    फर्काऊ 0;
}
