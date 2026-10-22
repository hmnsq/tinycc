#అన్తర్భావ <stdio.h>

పూర్ణాంకం myfunc(పూర్ణాంకం x)
{
   తిరిగి x * x;
}

శూన్య vfunc(పూర్ణాంకం a)
{
   రాయి("a=%d\n", a);
}

శూన్య qfunc()
{
   రాయి("qfunc()\n");
}

శూన్య zfunc()
{
	((శూన్య (*)(శూన్య))0) ();
}

పూర్ణాంకం ప్రధాన()
{
   రాయి("%d\n", myfunc(3));
   రాయి("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   తిరిగి 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
