#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

ကိန်းပြည့် main(void)
{
  ကိန်းပြည့် xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ပြန်ပေး 0;
}
