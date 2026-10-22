#ଅନ୍ତର୍ଭାଵ <stdio.h>
ସଂରଚନା wchar {
    ଅକ୍ଷର *data; ଅକ୍ଷର mem[];
};
ସଂରଚନା wint {
    ଅକ୍ଷର *data; ପୂର୍ଣ୍ଣସଂଖ୍ୟା mem[];
};
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1char (ଶୂନ୍ୟ) {
    ଅକ୍ଷର s[9]="nonono";
    ସଂରଚନା wchar q = {"bugs"};
    ଫେରନ୍ତୁ !s[0];
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1int (ଶୂନ୍ୟ) {
    ଅକ୍ଷର s[9]="nonono";
    ସଂରଚନା wint q = {"bugs"};
    ଫେରନ୍ତୁ !s[0];
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା empty[] = {}; // GNU extension
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ (ଶୂନ୍ୟ) {
   ଅକ୍ଷର s[9]="nonono";
   ସ୍ଥିର ସଂରଚନା wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ଯଦି (f1char() || f1int())
     printf ("bla\n");
   ଫେରନ୍ତୁ !s[0];
}
