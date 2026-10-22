#include <stdio.h>

цео main()
{
   printf("#include test\n");

#ако 1
#ако 0
   printf("a\n");
#инако
   printf("b\n");
#endif
#инако
#ако 0
   printf("c\n");
#инако
   printf("d\n");
#endif
#endif

#ако 0
#ако 1
   printf("e\n");
#инако
   printf("f\n");
#endif
#инако
#ако 1
   printf("g\n");
#инако
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#инако
   printf("j\n");
#endif
#инако
#ifdef DEF
   printf("k\n");
#инако
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#инако
   printf("n\n");
#endif
#инако
#ifndef DEF
   printf("o\n");
#инако
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ако ONE
#ако ZERO
   printf("q\n");
#инако
   printf("r\n");
#endif
#инако
#ако ZERO
   printf("s\n");
#инако
   printf("t\n");
#endif
#endif

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
