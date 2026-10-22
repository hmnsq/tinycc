#شامل <stdio.h>

صحیح myfunc(صحیح x)
{
   واپس x * x;
}

خالی vfunc(صحیح a)
{
   لکھو("a=%d\n", a);
}

خالی qfunc()
{
   لکھو("qfunc()\n");
}

خالی zfunc()
{
	((خالی (*)(خالی))0) ();
}

صحیح مین()
{
   لکھو("%d\n", myfunc(3));
   لکھو("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   واپس 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
