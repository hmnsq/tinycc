#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
   पूर्णांक a;
   पूर्णांक p;
   पूर्णांक t;

   a = 1;
   p = 0;
   t = 0;

   पर्यंत (a < 100)
   {
      म_लिखो("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   परत 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
