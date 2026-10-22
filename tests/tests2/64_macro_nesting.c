#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

정수 main(void)
{
  정수 xy = 42;
  printf("%d\n", CAT(A,B)(x));
  반환 0;
}
