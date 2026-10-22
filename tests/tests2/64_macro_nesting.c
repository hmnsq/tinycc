#شامل <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

صحیح اصلی(تهی)
{
  صحیح xy = 42;
  printf("%d\n", CAT(A,B)(x));
  بازگشت 0;
}
