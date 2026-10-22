#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   printf("#include test\n");

#නම් 1
#නම් 0
   printf("a\n");
#නැතහොත්
   printf("b\n");
#endif
#නැතහොත්
#නම් 0
   printf("c\n");
#නැතහොත්
   printf("d\n");
#endif
#endif

#නම් 0
#නම් 1
   printf("e\n");
#නැතහොත්
   printf("f\n");
#endif
#නැතහොත්
#නම් 1
   printf("g\n");
#නැතහොත්
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#නැතහොත්
   printf("j\n");
#endif
#නැතහොත්
#ifdef DEF
   printf("k\n");
#නැතහොත්
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#නැතහොත්
   printf("n\n");
#endif
#නැතහොත්
#ifndef DEF
   printf("o\n");
#නැතහොත්
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#නම් ONE
#නම් ZERO
   printf("q\n");
#නැතහොත්
   printf("r\n");
#endif
#නැතහොත්
#නම් ZERO
   printf("s\n");
#නැතහොත්
   printf("t\n");
#endif
#endif

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
