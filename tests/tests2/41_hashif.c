#ضمن <stdio.h>

صحيح الرئيسية()
{
   printf("#include test\n");

#إذا 1
#إذا 0
   printf("a\n");
#وإلا
   printf("b\n");
#endif
#وإلا
#إذا 0
   printf("c\n");
#وإلا
   printf("d\n");
#endif
#endif

#إذا 0
#إذا 1
   printf("e\n");
#وإلا
   printf("f\n");
#endif
#وإلا
#إذا 1
   printf("g\n");
#وإلا
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#وإلا
   printf("j\n");
#endif
#وإلا
#ifdef DEF
   printf("k\n");
#وإلا
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#وإلا
   printf("n\n");
#endif
#وإلا
#ifndef DEF
   printf("o\n");
#وإلا
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#إذا ONE
#إذا ZERO
   printf("q\n");
#وإلا
   printf("r\n");
#endif
#وإلا
#إذا ZERO
   printf("s\n");
#وإلا
   printf("t\n");
#endif
#endif

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
