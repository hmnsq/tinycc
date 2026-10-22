#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   पूर्णाङ्क a;
   पूर्णाङ्क p;
   पूर्णाङ्क t;

   a = 1;
   p = 0;
   t = 0;

   याव (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   पटिनिवत्त 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
