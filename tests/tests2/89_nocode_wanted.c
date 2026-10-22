बाह्य पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण *format, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                यावत् (1)
                    प्रारूप_लिख("error\n");
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                प्रति (;;)
                    प्रारूप_लिख("error\n");
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2_1(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                कुरु {
                    प्रारूप_लिख("error\n");
		} यावत् (1);
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_2_2(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                label:
                    प्रारूप_लिख("error\n");
		गच्छ label;
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_3(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                पूर्णाङ्क i = 1;
                गच्छ label;
                i = i + 2;
            label:
                i = i + 3;
            })
        );
        timeout--;
    } यावत् (timeout);
}
स्थिर शून्य kb_wait_4(शून्य)
{
    अचिह्नित दीर्घ timeout = 2;
    कुरु {
        (1 ?
            प्रारूप_लिख("timeout=%ld\n", timeout) :
            ({
                विकल्प(timeout) {
                    पक्ष 2:
                        प्रारूप_लिख("timeout is 2");
                        भङ्ग;
                    पक्ष 1:
                        प्रारूप_लिख("timeout is 1");
                        भङ्ग;
                    स्वभाव:
                        प्रारूप_लिख("timeout is 0?");
                        भङ्ग;
                };
                // return;
            })
        );
        timeout--;
    } यावत् (timeout);
}
पूर्णाङ्क मुख्यम्()
{
    प्रारूप_लिख("begin\n");
    kb_wait_1();
    kb_wait_2();
    kb_wait_2_1();
    kb_wait_2_2();
    kb_wait_3();
    kb_wait_4();
    प्रारूप_लिख("end\n");
    प्रत्यागम 0;
}
