#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   printf("#include test\n");

#ಯದಿ 1
#ಯದಿ 0
   printf("a\n");
#ಅನ್ಯಥಾ
   printf("b\n");
#endif
#ಅನ್ಯಥಾ
#ಯದಿ 0
   printf("c\n");
#ಅನ್ಯಥಾ
   printf("d\n");
#endif
#endif

#ಯದಿ 0
#ಯದಿ 1
   printf("e\n");
#ಅನ್ಯಥಾ
   printf("f\n");
#endif
#ಅನ್ಯಥಾ
#ಯದಿ 1
   printf("g\n");
#ಅನ್ಯಥಾ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ಅನ್ಯಥಾ
   printf("j\n");
#endif
#ಅನ್ಯಥಾ
#ifdef DEF
   printf("k\n");
#ಅನ್ಯಥಾ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ಅನ್ಯಥಾ
   printf("n\n");
#endif
#ಅನ್ಯಥಾ
#ifndef DEF
   printf("o\n");
#ಅನ್ಯಥಾ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ಯದಿ ONE
#ಯದಿ ZERO
   printf("q\n");
#ಅನ್ಯಥಾ
   printf("r\n");
#endif
#ಅನ್ಯಥಾ
#ಯದಿ ZERO
   printf("s\n");
#ಅನ್ಯಥಾ
   printf("t\n");
#endif
#endif

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
