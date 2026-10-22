#अन्तर्भाव <stdio.h>

पूर्णाङ्क myfunc(पूर्णाङ्क x)
{
   पटिनिवत्त x * x;
}

शून्य vfunc(पूर्णाङ्क a)
{
   printf("a=%d\n", a);
}

शून्य qfunc()
{
   printf("qfunc()\n");
}

शून्य zfunc()
{
	((शून्य (*)(शून्य))0) ();
}

पूर्णाङ्क main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   पटिनिवत्त 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
