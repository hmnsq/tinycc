#include <stdio.h>

整数 主要()
{
   printf("#include test\n");

#如果 1
#如果 0
   printf("a\n");
#否则
   printf("b\n");
#endif
#否则
#如果 0
   printf("c\n");
#否则
   printf("d\n");
#endif
#endif

#如果 0
#如果 1
   printf("e\n");
#否则
   printf("f\n");
#endif
#否则
#如果 1
   printf("g\n");
#否则
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#否则
   printf("j\n");
#endif
#否则
#ifdef DEF
   printf("k\n");
#否则
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#否则
   printf("n\n");
#endif
#否则
#ifndef DEF
   printf("o\n");
#否则
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#如果 ONE
#如果 ZERO
   printf("q\n");
#否则
   printf("r\n");
#endif
#否则
#如果 ZERO
   printf("s\n");
#否则
   printf("t\n");
#endif
#endif

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
