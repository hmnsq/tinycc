#अन्तर्भाव <stdio.h>

शून्य charfunc(वर्ण a)
{
   printf("char: %c\n", a);
}

शून्य intfunc(पूर्णाङ्क a)
{
   printf("int: %d\n", a);
}

शून्य floatfunc(भिन्न a)
{
   printf("float: %f\n", a);
}

पूर्णाङ्क main()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   वर्ण b = 97;
   वर्ण c = 97.0;

   printf("%d %d\n", b, c);

   पूर्णाङ्क d = 'a';
   पूर्णाङ्क e = 97.0;

   printf("%d %d\n", d, e);

   भिन्न f = 'a';
   भिन्न g = 97;

   printf("%f %f\n", f, g);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
