#अन्तर्भाव <stdio.h>
संरचना wchar {
    वर्ण *data; वर्ण mem[];
};
संरचना wint {
    वर्ण *data; पूर्णाङ्क mem[];
};
पूर्णाङ्क f1char (शून्य) {
    वर्ण s[9]="nonono";
    संरचना wchar q = {"bugs"};
    फर्काऊ !s[0];
}
पूर्णाङ्क f1int (शून्य) {
    वर्ण s[9]="nonono";
    संरचना wint q = {"bugs"};
    फर्काऊ !s[0];
}
पूर्णाङ्क empty[] = {}; // GNU extension
पूर्णाङ्क main (शून्य) {
   वर्ण s[9]="nonono";
   स्थिर संरचना wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   यदि (f1char() || f1int())
     म_लिखो ("bla\n");
   फर्काऊ !s[0];
}
