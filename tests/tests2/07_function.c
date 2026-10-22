#include <stdio.h>

целое myfunc(целое x)
{
   вернуть x * x;
}

void vfunc(целое a)
{
   printf("a=%d\n", a);
}

void qfunc()
{
   printf("qfunc()\n");
}

void zfunc()
{
	((void (*)(void))0) ();
}

целое основной()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   вернуть 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
