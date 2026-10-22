#include <stdio.h>

puur_naa_nka main()
{
   printf("#include test\n");

#ꦪꦼꦤ꧀ 1
#ꦪꦼꦤ꧀ 0
   printf("a\n");
#ꦭꦶꦪ
   printf("b\n");
#endif
#ꦭꦶꦪ
#ꦪꦼꦤ꧀ 0
   printf("c\n");
#ꦭꦶꦪ
   printf("d\n");
#endif
#endif

#ꦪꦼꦤ꧀ 0
#ꦪꦼꦤ꧀ 1
   printf("e\n");
#ꦭꦶꦪ
   printf("f\n");
#endif
#ꦭꦶꦪ
#ꦪꦼꦤ꧀ 1
   printf("g\n");
#ꦭꦶꦪ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ꦭꦶꦪ
   printf("j\n");
#endif
#ꦭꦶꦪ
#ifdef DEF
   printf("k\n");
#ꦭꦶꦪ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ꦭꦶꦪ
   printf("n\n");
#endif
#ꦭꦶꦪ
#ifndef DEF
   printf("o\n");
#ꦭꦶꦪ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ꦪꦼꦤ꧀ ONE
#ꦪꦼꦤ꧀ ZERO
   printf("q\n");
#ꦭꦶꦪ
   printf("r\n");
#endif
#ꦭꦶꦪ
#ꦪꦼꦤ꧀ ZERO
   printf("s\n");
#ꦭꦶꦪ
   printf("t\n");
#endif
#endif

   ꦮꦭꦶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
