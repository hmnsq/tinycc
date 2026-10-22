#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক myfunc(পূর্ণাঙ্ক x)
{
   ঘূৰাই x * x;
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

   ঘূৰাই 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
