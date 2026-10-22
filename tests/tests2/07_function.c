#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା myfunc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
   ଫେରନ୍ତୁ x * x;
}

ଶୂନ୍ୟ vfunc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
   printf("a=%d\n", a);
}

ଶୂନ୍ୟ qfunc()
{
   printf("qfunc()\n");
}

ଶୂନ୍ୟ zfunc()
{
	((ଶୂନ୍ୟ (*)(ଶୂନ୍ୟ))0) ();
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ଫେରନ୍ତୁ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
