#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   पूर्णाङ्क a;
   पूर्णाङ्क b;
   पूर्णाङ्क *d;
   पूर्णाङ्क *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
