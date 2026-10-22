#include <stdio.h>

số_nguyên main()
{
   printf("#include test\n");

#nếu 1
#nếu 0
   printf("a\n");
#không_thì
   printf("b\n");
#endif
#không_thì
#nếu 0
   printf("c\n");
#không_thì
   printf("d\n");
#endif
#endif

#nếu 0
#nếu 1
   printf("e\n");
#không_thì
   printf("f\n");
#endif
#không_thì
#nếu 1
   printf("g\n");
#không_thì
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#không_thì
   printf("j\n");
#endif
#không_thì
#ifdef DEF
   printf("k\n");
#không_thì
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#không_thì
   printf("n\n");
#endif
#không_thì
#ifndef DEF
   printf("o\n");
#không_thì
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#nếu ONE
#nếu ZERO
   printf("q\n");
#không_thì
   printf("r\n");
#endif
#không_thì
#nếu ZERO
   printf("s\n");
#không_thì
   printf("t\n");
#endif
#endif

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
