#include <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

පූර්ණ_සංඛ්‍යා main(void)
{
  පූර්ණ_සංඛ්‍යා xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ආපසු 0;
}
