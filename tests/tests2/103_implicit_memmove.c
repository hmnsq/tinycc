/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ರಚನೆ S { ಪೂರ್ಣಾಂಕ a,b,c,d, e[1024];};
ಪೂರ್ಣಾಂಕ foo (ರಚನೆ S *a, ರಚನೆ S *b)
{
  *a = *b;
  ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ *memmove(ಶೂನ್ಯ*,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ*,__SIZE_TYPE__);
ಶೂನ್ಯ foo2 (ರಚನೆ S *a, ರಚನೆ S *b)
{
  memmove(a, b, ಗಾತ್ರ *a);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
  ಹಿಂತಿರುಗಿ 0;
}
