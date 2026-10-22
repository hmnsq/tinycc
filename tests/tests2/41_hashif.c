#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   printf("#include test\n");

#जइ 1
#जइ 0
   printf("a\n");
#अण्णहा
   printf("b\n");
#endif
#अण्णहा
#जइ 0
   printf("c\n");
#अण्णहा
   printf("d\n");
#endif
#endif

#जइ 0
#जइ 1
   printf("e\n");
#अण्णहा
   printf("f\n");
#endif
#अण्णहा
#जइ 1
   printf("g\n");
#अण्णहा
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#अण्णहा
   printf("j\n");
#endif
#अण्णहा
#ifdef DEF
   printf("k\n");
#अण्णहा
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#अण्णहा
   printf("n\n");
#endif
#अण्णहा
#ifndef DEF
   printf("o\n");
#अण्णहा
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#जइ ONE
#जइ ZERO
   printf("q\n");
#अण्णहा
   printf("r\n");
#endif
#अण्णहा
#जइ ZERO
   printf("s\n");
#अण्णहा
   printf("t\n");
#endif
#endif

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
