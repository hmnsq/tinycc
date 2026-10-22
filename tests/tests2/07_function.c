#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક myfunc(પૂર્ણાંક x)
{
   પાછા x * x;
}

શૂન્ય vfunc(પૂર્ણાંક a)
{
   printf("a=%d\n", a);
}

શૂન્ય qfunc()
{
   printf("qfunc()\n");
}

શૂન્ય zfunc()
{
	((શૂન્ય (*)(શૂન્ય))0) ();
}

પૂર્ણાંક મુખ્ય()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   પાછા 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
