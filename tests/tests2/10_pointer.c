#अन्तर्भाव <stdio.h>

संरचना ziggy
{
   पूर्णाङ्क a;
   पूर्णाङ्क b;
   पूर्णाङ्क c;
} bolshevic;

पूर्णाङ्क main()
{
   पूर्णाङ्क a;
   पूर्णाङ्क *b;
   पूर्णाङ्क c;

   a = 42;
   b = &a;
   म_लिखो("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   म_लिखो("bolshevic.a = %d\n", bolshevic.a);
   म_लिखो("bolshevic.b = %d\n", bolshevic.b);
   म_लिखो("bolshevic.c = %d\n", bolshevic.c);

   संरचना ziggy *tsar = &bolshevic;

   म_लिखो("tsar->a = %d\n", tsar->a);
   म_लिखो("tsar->b = %d\n", tsar->b);
   म_लिखो("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   म_लिखो("bolshevic.b = %d\n", *b);

   प्रत्यागम 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
