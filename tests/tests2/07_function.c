#include <stdio.h>

පූර්ණ_සංඛ්‍යා myfunc(පූර්ණ_සංඛ්‍යා x)
{
   ආපසු x * x;
}

void vfunc(පූර්ණ_සංඛ්‍යා a)
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

පූර්ණ_සංඛ්‍යා main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ආපසු 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
