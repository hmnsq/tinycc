#ضمن <stdio.h>

صحيح myfunc(صحيح x)
{
   أرجع x * x;
}

فراغ vfunc(صحيح a)
{
   چاپ_کړه("a=%d\n", a);
}

فراغ qfunc()
{
   چاپ_کړه("qfunc()\n");
}

فراغ zfunc()
{
	((فراغ (*)(فراغ))0) ();
}

صحيح اصلي()
{
   چاپ_کړه("%d\n", myfunc(3));
   چاپ_کړه("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
