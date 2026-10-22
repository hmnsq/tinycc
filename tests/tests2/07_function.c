#include <stdio.h>

정수 myfunc(정수 x)
{
   반환 x * x;
}

void vfunc(정수 a)
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

정수 main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   반환 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
