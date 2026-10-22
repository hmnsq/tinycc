#अन्तर्भाव <stdio.h>

पूर्णाङ्क myfunc(पूर्णाङ्क x)
{
   प्रत्यागम x * x;
}

शून्य vfunc(पूर्णाङ्क a)
{
   म_लिखो("a=%d\n", a);
}

शून्य qfunc()
{
   म_लिखो("qfunc()\n");
}

शून्य zfunc()
{
	((शून्य (*)(शून्य))0) ();
}

पूर्णाङ्क main()
{
   म_लिखो("%d\n", myfunc(3));
   म_लिखो("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   प्रत्यागम 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
