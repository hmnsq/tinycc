#شامل <stdio.h>

صحیح myfunc(صحیح x)
{
   بازگشت x * x;
}

تهی vfunc(صحیح a)
{
   printf("a=%d\n", a);
}

تهی qfunc()
{
   printf("qfunc()\n");
}

تهی zfunc()
{
	((تهی (*)(تهی))0) ();
}

صحیح اصلی()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   بازگشت 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
