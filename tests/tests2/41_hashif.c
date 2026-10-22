#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   printf("#include test\n");

#જો 1
#જો 0
   printf("a\n");
#નહીંતર
   printf("b\n");
#endif
#નહીંતર
#જો 0
   printf("c\n");
#નહીંતર
   printf("d\n");
#endif
#endif

#જો 0
#જો 1
   printf("e\n");
#નહીંતર
   printf("f\n");
#endif
#નહીંતર
#જો 1
   printf("g\n");
#નહીંતર
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#નહીંતર
   printf("j\n");
#endif
#નહીંતર
#ifdef DEF
   printf("k\n");
#નહીંતર
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#નહીંતર
   printf("n\n");
#endif
#નહીંતર
#ifndef DEF
   printf("o\n");
#નહીંતર
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#જો ONE
#જો ZERO
   printf("q\n");
#નહીંતર
   printf("r\n");
#endif
#નહીંતર
#જો ZERO
   printf("s\n");
#નહીંતર
   printf("t\n");
#endif
#endif

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
