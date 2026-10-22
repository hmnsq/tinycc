#അന്തര്ഭാവ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ xy = 42;
  printf("%d\n", CAT(A,B)(x));
  തിരികെ 0;
}
