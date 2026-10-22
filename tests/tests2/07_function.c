#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ myfunc(ಪೂರ್ಣಾಂಕ x)
{
   ಹಿಂತಿರುಗಿ x * x;
}

ಶೂನ್ಯ vfunc(ಪೂರ್ಣಾಂಕ a)
{
   ಬರೆ("a=%d\n", a);
}

ಶೂನ್ಯ qfunc()
{
   ಬರೆ("qfunc()\n");
}

ಶೂನ್ಯ zfunc()
{
	((ಶೂನ್ಯ (*)(ಶೂನ್ಯ))0) ();
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಬರೆ("%d\n", myfunc(3));
   ಬರೆ("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   ಹಿಂತಿರುಗಿ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
