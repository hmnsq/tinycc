#அந்தர்பாவ <stdio.h>

முழு myfunc(முழு x)
{
   திரும்பு x * x;
}

வெறுமை vfunc(முழு a)
{
   printf("a=%d\n", a);
}

வெறுமை qfunc()
{
   printf("qfunc()\n");
}

வெறுமை zfunc()
{
	((வெறுமை (*)(வெறுமை))0) ();
}

முழு முதன்மை()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   திரும்பு 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
