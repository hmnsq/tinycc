#समावेश <stdio.h>

व्योम charfunc(अक्षर a)
{
   म_लिखो("char: %c\n", a);
}

व्योम intfunc(पूर्णांक a)
{
   म_लिखो("int: %d\n", a);
}

व्योम floatfunc(भग्न a)
{
   म_लिखो("float: %f\n", a);
}

पूर्णांक मुख्य()
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

   भग्न f = 'a';
   भग्न g = 97;

   म_लिखो("%f %f\n", f, g);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
