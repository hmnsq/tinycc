#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   printf("#include test\n");

#எனில் 1
#எனில் 0
   printf("a\n");
#இல்லையெனில்
   printf("b\n");
#endif
#இல்லையெனில்
#எனில் 0
   printf("c\n");
#இல்லையெனில்
   printf("d\n");
#endif
#endif

#எனில் 0
#எனில் 1
   printf("e\n");
#இல்லையெனில்
   printf("f\n");
#endif
#இல்லையெனில்
#எனில் 1
   printf("g\n");
#இல்லையெனில்
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#இல்லையெனில்
   printf("j\n");
#endif
#இல்லையெனில்
#ifdef DEF
   printf("k\n");
#இல்லையெனில்
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#இல்லையெனில்
   printf("n\n");
#endif
#இல்லையெனில்
#ifndef DEF
   printf("o\n");
#இல்லையெனில்
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#எனில் ONE
#எனில் ZERO
   printf("q\n");
#இல்லையெனில்
   printf("r\n");
#endif
#இல்லையெனில்
#எனில் ZERO
   printf("s\n");
#இல்லையெனில்
   printf("t\n");
#endif
#endif

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
