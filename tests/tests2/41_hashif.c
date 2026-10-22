#شامل <stdio.h>

صحیح اصلی()
{
   printf("#include test\n");

#اگر 1
#اگر 0
   printf("a\n");
#وگرنه
   printf("b\n");
#endif
#وگرنه
#اگر 0
   printf("c\n");
#وگرنه
   printf("d\n");
#endif
#endif

#اگر 0
#اگر 1
   printf("e\n");
#وگرنه
   printf("f\n");
#endif
#وگرنه
#اگر 1
   printf("g\n");
#وگرنه
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#وگرنه
   printf("j\n");
#endif
#وگرنه
#ifdef DEF
   printf("k\n");
#وگرنه
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#وگرنه
   printf("n\n");
#endif
#وگرنه
#ifndef DEF
   printf("o\n");
#وگرنه
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#اگر ONE
#اگر ZERO
   printf("q\n");
#وگرنه
   printf("r\n");
#endif
#وگرنه
#اگر ZERO
   printf("s\n");
#وگرنه
   printf("t\n");
#endif
#endif

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
