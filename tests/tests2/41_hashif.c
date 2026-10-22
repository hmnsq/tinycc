#ضمن <stdio.h>

صحيح main()
{
   printf("#include test\n");

#אם 1
#אם 0
   printf("a\n");
#אחרת
   printf("b\n");
#endif
#אחרת
#אם 0
   printf("c\n");
#אחרת
   printf("d\n");
#endif
#endif

#אם 0
#אם 1
   printf("e\n");
#אחרת
   printf("f\n");
#endif
#אחרת
#אם 1
   printf("g\n");
#אחרת
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#אחרת
   printf("j\n");
#endif
#אחרת
#ifdef DEF
   printf("k\n");
#אחרת
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#אחרת
   printf("n\n");
#endif
#אחרת
#ifndef DEF
   printf("o\n");
#אחרת
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#אם ONE
#אם ZERO
   printf("q\n");
#אחרת
   printf("r\n");
#endif
#אחרת
#אם ZERO
   printf("s\n");
#אחרת
   printf("t\n");
#endif
#endif

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
