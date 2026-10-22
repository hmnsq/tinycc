#અન્તર્ભાવ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
  પૂર્ણાંક xy = 42;
  printf("%d\n", CAT(A,B)(x));
  પાછા 0;
}
