#include <stdio.h>

ཧྲིལ གཙོ()
{
   printf("#include test\n");

#གལ་ཏེ 1
#གལ་ཏེ 0
   printf("a\n");
#དེ་མིན
   printf("b\n");
#endif
#དེ་མིན
#གལ་ཏེ 0
   printf("c\n");
#དེ་མིན
   printf("d\n");
#endif
#endif

#གལ་ཏེ 0
#གལ་ཏེ 1
   printf("e\n");
#དེ་མིན
   printf("f\n");
#endif
#དེ་མིན
#གལ་ཏེ 1
   printf("g\n");
#དེ་མིན
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#དེ་མིན
   printf("j\n");
#endif
#དེ་མིན
#ifdef DEF
   printf("k\n");
#དེ་མིན
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#དེ་མིན
   printf("n\n");
#endif
#དེ་མིན
#ifndef DEF
   printf("o\n");
#དེ་མིན
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#གལ་ཏེ ONE
#གལ་ཏེ ZERO
   printf("q\n");
#དེ་མིན
   printf("r\n");
#endif
#དེ་མིན
#གལ་ཏེ ZERO
   printf("s\n");
#དེ་མིན
   printf("t\n");
#endif
#endif

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
