#समावेश <stdio.h>
काष्ठा wchar {
    अक्षर *तथ्य; अक्षर mem[];
};
काष्ठा wint {
    अक्षर *तथ्य; पूर्णांक mem[];
};
पूर्णांक f1char (व्योम) {
    अक्षर s[9]="nonono";
    काष्ठा wchar q = {"bugs"};
    वापस !s[0];
}
पूर्णांक f1int (व्योम) {
    अक्षर s[9]="nonono";
    काष्ठा wint q = {"bugs"};
    वापस !s[0];
}
पूर्णांक empty[] = {}; // GNU extension
पूर्णांक मुख्य (व्योम) {
   अक्षर s[9]="nonono";
   अटल काष्ठा wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   अगर (f1char() || f1int())
     म_लिखो ("bla\n");
   वापस !s[0];
}
