#ଅନ୍ତର୍ଭାଵ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ଫେରନ୍ତୁ 0;
}
