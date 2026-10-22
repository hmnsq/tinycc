#ಅನ್ತರ್ಭಾವ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ಪ್ರತ್ಯಾಗಮ 0;
}
