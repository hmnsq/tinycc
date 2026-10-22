#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক myfunc(পূর্ণাঙ্ক x)
{
   প্রত্যাগম x * x;
}

শূন্য vfunc(পূর্ণাঙ্ক a)
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

পূর্ণাঙ্ক main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   প্রত্যাগম 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
