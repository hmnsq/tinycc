#include <stdio.h>

целое основной()
{
   printf("#include test\n");

#если 1
#если 0
   printf("a\n");
#иначе
   printf("b\n");
#endif
#иначе
#если 0
   printf("c\n");
#иначе
   printf("d\n");
#endif
#endif

#если 0
#если 1
   printf("e\n");
#иначе
   printf("f\n");
#endif
#иначе
#если 1
   printf("g\n");
#иначе
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#иначе
   printf("j\n");
#endif
#иначе
#ifdef DEF
   printf("k\n");
#иначе
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#иначе
   printf("n\n");
#endif
#иначе
#ifndef DEF
   printf("o\n");
#иначе
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#если ONE
#если ZERO
   printf("q\n");
#иначе
   printf("r\n");
#endif
#иначе
#если ZERO
   printf("s\n");
#иначе
   printf("t\n");
#endif
#endif

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
