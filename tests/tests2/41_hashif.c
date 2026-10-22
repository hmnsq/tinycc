#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   printf("#include test\n");

#ଯଦି 1
#ଯଦି 0
   printf("a\n");
#ଅନ୍ୟଥା
   printf("b\n");
#endif
#ଅନ୍ୟଥା
#ଯଦି 0
   printf("c\n");
#ଅନ୍ୟଥା
   printf("d\n");
#endif
#endif

#ଯଦି 0
#ଯଦି 1
   printf("e\n");
#ଅନ୍ୟଥା
   printf("f\n");
#endif
#ଅନ୍ୟଥା
#ଯଦି 1
   printf("g\n");
#ଅନ୍ୟଥା
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ଅନ୍ୟଥା
   printf("j\n");
#endif
#ଅନ୍ୟଥା
#ifdef DEF
   printf("k\n");
#ଅନ୍ୟଥା
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ଅନ୍ୟଥା
   printf("n\n");
#endif
#ଅନ୍ୟଥା
#ifndef DEF
   printf("o\n");
#ଅନ୍ୟଥା
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ଯଦି ONE
#ଯଦି ZERO
   printf("q\n");
#ଅନ୍ୟଥା
   printf("r\n");
#endif
#ଅନ୍ୟଥା
#ଯଦି ZERO
   printf("s\n");
#ଅନ୍ୟଥା
   printf("t\n");
#endif
#endif

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
