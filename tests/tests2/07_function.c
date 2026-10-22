#include <stdio.h>

số_nguyên myfunc(số_nguyên x)
{
   trả_về x * x;
}

void vfunc(số_nguyên a)
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

số_nguyên main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   trả_về 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
