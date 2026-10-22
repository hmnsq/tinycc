#include <stdio.h>

ціле main()
{
   printf("#include test\n");

#якщо 1
#якщо 0
   printf("a\n");
#інакше
   printf("b\n");
#endif
#інакше
#якщо 0
   printf("c\n");
#інакше
   printf("d\n");
#endif
#endif

#якщо 0
#якщо 1
   printf("e\n");
#інакше
   printf("f\n");
#endif
#інакше
#якщо 1
   printf("g\n");
#інакше
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#інакше
   printf("j\n");
#endif
#інакше
#ifdef DEF
   printf("k\n");
#інакше
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#інакше
   printf("n\n");
#endif
#інакше
#ifndef DEF
   printf("o\n");
#інакше
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#якщо ONE
#якщо ZERO
   printf("q\n");
#інакше
   printf("r\n");
#endif
#інакше
#якщо ZERO
   printf("s\n");
#інакше
   printf("t\n");
#endif
#endif

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
