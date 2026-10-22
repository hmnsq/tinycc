#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

整数 主要(void)
{
  整数 xy = 42;
  printf("%d\n", CAT(A,B)(x));
  返回 0;
}
