#அந்தர்பாவ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

முழு முதன்மை(வெறுமை)
{
  முழு xy = 42;
  printf("%d\n", CAT(A,B)(x));
  திரும்பு 0;
}
