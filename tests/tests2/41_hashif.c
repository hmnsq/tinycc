#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   printf("#include test\n");

#सचे 1
#सचे 0
   printf("a\n");
#अञ्ञथा
   printf("b\n");
#endif
#अञ्ञथा
#सचे 0
   printf("c\n");
#अञ्ञथा
   printf("d\n");
#endif
#endif

#सचे 0
#सचे 1
   printf("e\n");
#अञ्ञथा
   printf("f\n");
#endif
#अञ्ञथा
#सचे 1
   printf("g\n");
#अञ्ञथा
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#अञ्ञथा
   printf("j\n");
#endif
#अञ्ञथा
#ifdef DEF
   printf("k\n");
#अञ्ञथा
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#अञ्ञथा
   printf("n\n");
#endif
#अञ्ञथा
#ifndef DEF
   printf("o\n");
#अञ्ञथा
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#सचे ONE
#सचे ZERO
   printf("q\n");
#अञ्ञथा
   printf("r\n");
#endif
#अञ्ञथा
#सचे ZERO
   printf("s\n");
#अञ्ञथा
   printf("t\n");
#endif
#endif

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
