#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
   पूर्णांक a;
   पूर्णांक *b;
   पूर्णांक *c;

   a = 42;
   b = &a;
   c = रिक्त;

   म_लिखो("%d\n", *b);

   जर (b == रिक्त)
      म_लिखो("b is NULL\n");
   अन्यथा
      म_लिखो("b is not NULL\n");

   जर (c == रिक्त)
      म_लिखो("c is NULL\n");
   अन्यथा
      म_लिखो("c is not NULL\n");

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
