#अन्तर्भाव <stdio.h>

शून्य charfunc(अक्षर a)
{
   म_लिखो("char: %c\n", a);
}

शून्य intfunc(पूर्णांक a)
{
   म_लिखो("int: %d\n", a);
}

शून्य floatfunc(दशांश a)
{
   म_लिखो("float: %f\n", a);
}

पूर्णांक main()
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

   अक्षर b = 97;
   अक्षर c = 97.0;

   म_लिखो("%d %d\n", b, c);

   पूर्णांक d = 'a';
   पूर्णांक e = 97.0;

   म_लिखो("%d %d\n", d, e);

   दशांश f = 'a';
   दशांश g = 97;

   म_लिखो("%f %f\n", f, g);

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
