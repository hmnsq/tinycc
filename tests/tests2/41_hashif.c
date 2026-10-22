#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   printf("#include test\n");

#यदि 1
#यदि 0
   printf("a\n");
#अन्यथा
   printf("b\n");
#endif
#अन्यथा
#यदि 0
   printf("c\n");
#अन्यथा
   printf("d\n");
#endif
#endif

#यदि 0
#यदि 1
   printf("e\n");
#अन्यथा
   printf("f\n");
#endif
#अन्यथा
#यदि 1
   printf("g\n");
#अन्यथा
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#अन्यथा
   printf("j\n");
#endif
#अन्यथा
#ifdef DEF
   printf("k\n");
#अन्यथा
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#अन्यथा
   printf("n\n");
#endif
#अन्यथा
#ifndef DEF
   printf("o\n");
#अन्यथा
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#यदि ONE
#यदि ZERO
   printf("q\n");
#अन्यथा
   printf("r\n");
#endif
#अन्यथा
#यदि ZERO
   printf("s\n");
#अन्यथा
   printf("t\n");
#endif
#endif

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
