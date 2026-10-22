#include <stdio.h>

정수 main()
{
   printf("#include test\n");

#만약 1
#만약 0
   printf("a\n");
#아니면
   printf("b\n");
#endif
#아니면
#만약 0
   printf("c\n");
#아니면
   printf("d\n");
#endif
#endif

#만약 0
#만약 1
   printf("e\n");
#아니면
   printf("f\n");
#endif
#아니면
#만약 1
   printf("g\n");
#아니면
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#아니면
   printf("j\n");
#endif
#아니면
#ifdef DEF
   printf("k\n");
#아니면
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#아니면
   printf("n\n");
#endif
#아니면
#ifndef DEF
   printf("o\n");
#아니면
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#만약 ONE
#만약 ZERO
   printf("q\n");
#아니면
   printf("r\n");
#endif
#아니면
#만약 ZERO
   printf("s\n");
#아니면
   printf("t\n");
#endif
#endif

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
