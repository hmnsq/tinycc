#समावेश <stdio.h>

काष्ठा ziggy
{
   पूर्णांक a;
   पूर्णांक b;
   पूर्णांक c;
} bolshevic;

पूर्णांक मुख्य()
{
   पूर्णांक a;
   पूर्णांक *b;
   पूर्णांक c;

   a = 42;
   b = &a;
   म_लिखो("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   म_लिखो("bolshevic.a = %d\n", bolshevic.a);
   म_लिखो("bolshevic.b = %d\n", bolshevic.b);
   म_लिखो("bolshevic.c = %d\n", bolshevic.c);

   काष्ठा ziggy *tsar = &bolshevic;

   म_लिखो("tsar->a = %d\n", tsar->a);
   म_लिखो("tsar->b = %d\n", tsar->b);
   म_लिखो("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   म_लिखो("bolshevic.b = %d\n", *b);

   वापस 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
