#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা myfunc(পূর্ণসংখ্যা x)
{
   ফেরত x * x;
}

শূন্য vfunc(পূর্ণসংখ্যা a)
{
   printf("a=%d\n", a);
}

শূন্য qfunc()
{
   printf("qfunc()\n");
}

শূন্য zfunc()
{
	((শূন্য (*)(শূন্য))0) ();
}

পূর্ণসংখ্যা প্রধান()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ফেরত 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
