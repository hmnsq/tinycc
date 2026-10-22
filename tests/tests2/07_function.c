#include <stdio.h>

цео myfunc(цео x)
{
   врати x * x;
}

void vfunc(цео a)
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

цео main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   врати 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
