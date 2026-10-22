#ضمن <stdio.h>

صحيح main()
{
   printf("#include test\n");

#𐤀𐤌 1
#𐤀𐤌 0
   printf("a\n");
#وإلا
   printf("b\n");
#endif
#وإلا
#𐤀𐤌 0
   printf("c\n");
#وإلا
   printf("d\n");
#endif
#endif

#𐤀𐤌 0
#𐤀𐤌 1
   printf("e\n");
#وإلا
   printf("f\n");
#endif
#وإلا
#𐤀𐤌 1
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

#𐤀𐤌 ONE
#𐤀𐤌 ZERO
   printf("q\n");
#وإلا
   printf("r\n");
#endif
#وإلا
#𐤀𐤌 ZERO
   printf("s\n");
#وإلا
   printf("t\n");
#endif
#endif

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
