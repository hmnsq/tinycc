#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ myfunc(ಪೂರ್ಣಾಙ್ಕ x)
{
   ಪ್ರತ್ಯಾಗಮ x * x;
}

ಶೂನ್ಯ vfunc(ಪೂರ್ಣಾಙ್ಕ a)
{
   printf("a=%d\n", a);
}

ಶೂನ್ಯ qfunc()
{
   printf("qfunc()\n");
}

ಶೂನ್ಯ zfunc()
{
	((ಶೂನ್ಯ (*)(ಶೂನ್ಯ))0) ();
}

ಪೂರ್ಣಾಙ್ಕ main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ಪ್ರತ್ಯಾಗಮ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
