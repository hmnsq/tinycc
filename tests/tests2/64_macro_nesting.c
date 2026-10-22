#ضمن <stdio.h>	// printf()

#تعریف_کرو CAT2(a,b) a##b
#تعریف_کرو CAT(a,b) CAT2(a,b)
#تعریف_کرو AB(x) CAT(x,y)

صحيح مکھ(فراغ)
{
  صحيح xy = 42;
  لکھو("%d\n", CAT(A,B)(x));
  أرجع 0;
}
