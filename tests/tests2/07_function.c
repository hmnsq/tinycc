#समावेश <stdio.h>

पूर्णांक myfunc(पूर्णांक x)
{
   वापस x * x;
}

व्योम vfunc(पूर्णांक a)
{
   म_लिखो("a=%d\n", a);
}

व्योम qfunc()
{
   म_लिखो("qfunc()\n");
}

व्योम zfunc()
{
	((व्योम (*)(व्योम))0) ();
}

पूर्णांक मुख्य()
{
   म_लिखो("%d\n", myfunc(3));
   म_लिखो("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   वापस 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
