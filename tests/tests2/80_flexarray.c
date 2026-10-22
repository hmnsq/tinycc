#अन्तर्भाव <stdio.h>
संरचना wchar {
    अक्षर *data; अक्षर mem[];
};
संरचना wint {
    अक्षर *data; पूर्णांक mem[];
};
पूर्णांक f1char (शून्य) {
    अक्षर s[9]="nonono";
    संरचना wchar q = {"bugs"};
    परत !s[0];
}
पूर्णांक f1int (शून्य) {
    अक्षर s[9]="nonono";
    संरचना wint q = {"bugs"};
    परत !s[0];
}
पूर्णांक empty[] = {}; // GNU extension
पूर्णांक main (शून्य) {
   अक्षर s[9]="nonono";
   स्थिर संरचना wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   जर (f1char() || f1int())
     म_लिखो ("bla\n");
   परत !s[0];
}
