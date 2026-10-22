#include <stdio.h>

ཧྲིལ myfunc(ཧྲིལ x)
{
   ཕྱིར x * x;
}

void vfunc(ཧྲིལ a)
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

ཧྲིལ གཙོ()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ཕྱིར 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
