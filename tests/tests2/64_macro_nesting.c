#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

số_nguyên main(void)
{
  số_nguyên xy = 42;
  printf("%d\n", CAT(A,B)(x));
  trả_về 0;
}
