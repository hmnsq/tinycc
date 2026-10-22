#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ myfunc(ਪੂਰਨ x)
{
   ਵਾਪਸ x * x;
}

ਖਾਲੀ vfunc(ਪੂਰਨ a)
{
   ਲਿਖੋ("a=%d\n", a);
}

ਖਾਲੀ qfunc()
{
   ਲਿਖੋ("qfunc()\n");
}

ਖਾਲੀ zfunc()
{
	((ਖਾਲੀ (*)(ਖਾਲੀ))0) ();
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਲਿਖੋ("%d\n", myfunc(3));
   ਲਿਖੋ("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ਵਾਪਸ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
