#ضمن <stdio.h>	// printf()

#تعریف_کن CAT2(a,b) a##b
#تعریف_کن CAT(a,b) CAT2(a,b)
#تعریف_کن AB(x) CAT(x,y)

صحيح اصلی(فراغ)
{
  صحيح xy = 42;
  چاپ_کن("%d\n", CAT(A,B)(x));
  أرجع 0;
}
