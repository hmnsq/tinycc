#include <stdio.h>

จำนวนเต็ม หลัก()
{
   printf("#include test\n");

#ถ้า 1
#ถ้า 0
   printf("a\n");
#มิฉะนั้น
   printf("b\n");
#endif
#มิฉะนั้น
#ถ้า 0
   printf("c\n");
#มิฉะนั้น
   printf("d\n");
#endif
#endif

#ถ้า 0
#ถ้า 1
   printf("e\n");
#มิฉะนั้น
   printf("f\n");
#endif
#มิฉะนั้น
#ถ้า 1
   printf("g\n");
#มิฉะนั้น
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#มิฉะนั้น
   printf("j\n");
#endif
#มิฉะนั้น
#ifdef DEF
   printf("k\n");
#มิฉะนั้น
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#มิฉะนั้น
   printf("n\n");
#endif
#มิฉะนั้น
#ifndef DEF
   printf("o\n");
#มิฉะนั้น
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ถ้า ONE
#ถ้า ZERO
   printf("q\n");
#มิฉะนั้น
   printf("r\n");
#endif
#มิฉะนั้น
#ถ้า ZERO
   printf("s\n");
#มิฉะนั้น
   printf("t\n");
#endif
#endif

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
