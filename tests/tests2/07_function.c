#include <stdio.h>

puur_naa_nka myfunc(puur_naa_nka x)
{
   ᤀᤡᤴ x * x;
}

void vfunc(puur_naa_nka a)
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

puur_naa_nka main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ᤀᤡᤴ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
