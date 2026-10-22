#include <stdio.h>

จำนวนเต็ม myfunc(จำนวนเต็ม x)
{
   คืน x * x;
}

void vfunc(จำนวนเต็ม a)
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

จำนวนเต็ม หลัก()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   คืน 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
