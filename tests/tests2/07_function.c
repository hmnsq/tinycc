#include <stdio.h>

ចំនួនគត់ myfunc(ចំនួនគត់ x)
{
   ត្រឡប់ x * x;
}

void vfunc(ចំនួនគត់ a)
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

ចំនួនគត់ main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ត្រឡប់ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
