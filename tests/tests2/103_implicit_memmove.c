/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ಸಂರಚನಾ S { ಪೂರ್ಣಾಙ್ಕ a,b,c,d, e[1024];};
ಪೂರ್ಣಾಙ್ಕ foo (ಸಂರಚನಾ S *a, ಸಂರಚನಾ S *b)
{
  *a = *b;
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ *memmove(ಶೂನ್ಯ*,ಧ್ರುವ ಶೂನ್ಯ*,__SIZE_TYPE__);
ಶೂನ್ಯ foo2 (ಸಂರಚನಾ S *a, ಸಂರಚನಾ S *b)
{
  memmove(a, b, ಪರಿಮಾಣ *a);
}

ಪೂರ್ಣಾಙ್ಕ main()
{
  ಪ್ರತ್ಯಾಗಮ 0;
}
