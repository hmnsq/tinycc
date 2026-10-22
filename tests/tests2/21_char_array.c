#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
   पूर्णांक x = 'a';
   अक्षर y = x;

   अक्षर *a = "hello";

   म_लिखो("%s\n", a);

   पूर्णांक c;
   c = *a;

   अक्षर *b;
   साठी (b = a; *b != 0; b++)
      म_लिखो("%c: %d\n", *b, *b);

   अक्षर destarray[10];
   अक्षर *dest = &destarray[0];
   अक्षर *src = a;

   पर्यंत (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   म_लिखो("copied string is %s\n", destarray);

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
