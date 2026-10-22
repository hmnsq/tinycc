#ضمن <stdio.h>

صحيح myfunc(صحيح x)
{
   החזר x * x;
}

فراغ vfunc(صحيح a)
{
   printf("a=%d\n", a);
}

فراغ qfunc()
{
   printf("qfunc()\n");
}

فراغ zfunc()
{
	((فراغ (*)(فراغ))0) ();
}

صحيح main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   החזר 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
