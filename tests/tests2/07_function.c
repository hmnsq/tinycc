#include <stdio.h>

整数 myfunc(整数 x)
{
   戻る x * x;
}

void vfunc(整数 a)
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

整数 メインページ()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   戻る 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
