#ضمن <stdio.h>	// printf()

#وصف_ڪريو CAT2(a,b) a##b
#وصف_ڪريو CAT(a,b) CAT2(a,b)
#وصف_ڪريو AB(x) CAT(x,y)

صحيح مکيه(فراغ)
{
  صحيح xy = 42;
  لکو("%d\n", CAT(A,B)(x));
  أرجع 0;
}
