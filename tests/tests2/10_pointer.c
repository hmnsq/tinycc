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
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   संरचना ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   पटिनिवत्त 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
