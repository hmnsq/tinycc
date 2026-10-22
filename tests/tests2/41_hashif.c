#ضمن <stdio.h>

صحيح main()
{
   printf("#include test\n");

#ܐܢ 1
#ܐܢ 0
   printf("a\n");
#ܐܚܪܢܐ
   printf("b\n");
#endif
#ܐܚܪܢܐ
#ܐܢ 0
   printf("c\n");
#ܐܚܪܢܐ
   printf("d\n");
#endif
#endif

#ܐܢ 0
#ܐܢ 1
   printf("e\n");
#ܐܚܪܢܐ
   printf("f\n");
#endif
#ܐܚܪܢܐ
#ܐܢ 1
   printf("g\n");
#ܐܚܪܢܐ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ܐܚܪܢܐ
   printf("j\n");
#endif
#ܐܚܪܢܐ
#ifdef DEF
   printf("k\n");
#ܐܚܪܢܐ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ܐܚܪܢܐ
   printf("n\n");
#endif
#ܐܚܪܢܐ
#ifndef DEF
   printf("o\n");
#ܐܚܪܢܐ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ܐܢ ONE
#ܐܢ ZERO
   printf("q\n");
#ܐܚܪܢܐ
   printf("r\n");
#endif
#ܐܚܪܢܐ
#ܐܢ ZERO
   printf("s\n");
#ܐܚܪܢܐ
   printf("t\n");
#endif
#endif

   ܦܢܐ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
