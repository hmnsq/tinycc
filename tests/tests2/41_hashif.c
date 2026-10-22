#include <stdio.h>

puur_naa_nka main()
{
   printf("#include test\n");

#ᰀᰧ 1
#ᰀᰧ 0
   printf("a\n");
#ᰀᰧᰀ
   printf("b\n");
#endif
#ᰀᰧᰀ
#ᰀᰧ 0
   printf("c\n");
#ᰀᰧᰀ
   printf("d\n");
#endif
#endif

#ᰀᰧ 0
#ᰀᰧ 1
   printf("e\n");
#ᰀᰧᰀ
   printf("f\n");
#endif
#ᰀᰧᰀ
#ᰀᰧ 1
   printf("g\n");
#ᰀᰧᰀ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ᰀᰧᰀ
   printf("j\n");
#endif
#ᰀᰧᰀ
#ifdef DEF
   printf("k\n");
#ᰀᰧᰀ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ᰀᰧᰀ
   printf("n\n");
#endif
#ᰀᰧᰀ
#ifndef DEF
   printf("o\n");
#ᰀᰧᰀ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ᰀᰧ ONE
#ᰀᰧ ZERO
   printf("q\n");
#ᰀᰧᰀ
   printf("r\n");
#endif
#ᰀᰧᰀ
#ᰀᰧ ZERO
   printf("s\n");
#ᰀᰧᰀ
   printf("t\n");
#endif
#endif

   ᰀᰧᰌ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
