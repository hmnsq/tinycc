#समावेश <stdio.h>

पूर्णांक मुख्य()
{
   पूर्णांक x = 'a';
   अक्षर y = x;

   अक्षर *a = "hello";

   म_लिखो("%s\n", a);

   पूर्णांक c;
   c = *a;

   अक्षर *b;
   क्रम (b = a; *b != 0; b++)
      म_लिखो("%c: %d\n", *b, *b);

   अक्षर destarray[10];
   अक्षर *dest = &destarray[0];
   अक्षर *src = a;

   जबतक (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   म_लिखो("copied string is %s\n", destarray);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
