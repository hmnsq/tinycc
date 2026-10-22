#ضمن <stdio.h>

صحيح myfunc(صحيح x)
{
   أرجع x * x;
}

فراغ vfunc(صحيح a)
{
   لکھو("a=%d\n", a);
}

فراغ qfunc()
{
   لکھو("qfunc()\n");
}

فراغ zfunc()
{
	((فراغ (*)(فراغ))0) ();
}

صحيح مکھ()
{
   لکھو("%d\n", myfunc(3));
   لکھو("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
