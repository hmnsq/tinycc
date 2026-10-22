#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

ចំនួនគត់ main(void)
{
  ចំនួនគត់ xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ត្រឡប់ 0;
}
