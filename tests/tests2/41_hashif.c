#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   printf("#include test\n");

#যদি 1
#যদি 0
   printf("a\n");
#অন্যথা
   printf("b\n");
#endif
#অন্যথা
#যদি 0
   printf("c\n");
#অন্যথা
   printf("d\n");
#endif
#endif

#যদি 0
#যদি 1
   printf("e\n");
#অন্যথা
   printf("f\n");
#endif
#অন্যথা
#যদি 1
   printf("g\n");
#অন্যথা
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#অন্যথা
   printf("j\n");
#endif
#অন্যথা
#ifdef DEF
   printf("k\n");
#অন্যথা
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#অন্যথা
   printf("n\n");
#endif
#অন্যথা
#ifndef DEF
   printf("o\n");
#অন্যথা
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#যদি ONE
#যদি ZERO
   printf("q\n");
#অন্যথা
   printf("r\n");
#endif
#অন্যথা
#যদি ZERO
   printf("s\n");
#অন্যথা
   printf("t\n");
#endif
#endif

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
