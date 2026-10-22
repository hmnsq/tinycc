#अन्तर्भाव <stdio.h>

पूर्णांक myfunc(पूर्णांक x)
{
   परत x * x;
}

शून्य vfunc(पूर्णांक a)
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

पूर्णांक main()
{
   म_लिखो("%d\n", myfunc(3));
   म_लिखो("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   परत 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
