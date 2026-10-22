#अन्तर्भाव <stdio.h>

संरचना ziggy
{
   पूर्णाङ्क a;
   पूर्णाङ्क b;
   पूर्णाङ्क c;
} bolshevic;

पूर्णाङ्क मुख्यम्()
{
   पूर्णाङ्क a;
   पूर्णाङ्क *b;
   पूर्णाङ्क c;

   a = 42;
   b = &a;
   प्रारूप_लिख("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   प्रारूप_लिख("bolshevic.a = %d\n", bolshevic.a);
   प्रारूप_लिख("bolshevic.b = %d\n", bolshevic.b);
   प्रारूप_लिख("bolshevic.c = %d\n", bolshevic.c);

   संरचना ziggy *tsar = &bolshevic;

   प्रारूप_लिख("tsar->a = %d\n", tsar->a);
   प्रारूप_लिख("tsar->b = %d\n", tsar->b);
   प्रारूप_लिख("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   प्रारूप_लिख("bolshevic.b = %d\n", *b);

   प्रत्यागम 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
