#অন্তর্ভাৱ <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

পূর্ণাঙ্ক main(শূন্য)
{
  পূর্ণাঙ্ক xy = 42;
  printf("%d\n", CAT(A,B)(x));
  ঘূৰাই 0;
}
