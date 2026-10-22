#include <stdio.h>

ចំនួនគត់ main()
{
   printf("#include test\n");

#ប្រសិនបើ 1
#ប្រសិនបើ 0
   printf("a\n");
#បើមិនដូច្នេះ
   printf("b\n");
#endif
#បើមិនដូច្នេះ
#ប្រសិនបើ 0
   printf("c\n");
#បើមិនដូច្នេះ
   printf("d\n");
#endif
#endif

#ប្រសិនបើ 0
#ប្រសិនបើ 1
   printf("e\n");
#បើមិនដូច្នេះ
   printf("f\n");
#endif
#បើមិនដូច្នេះ
#ប្រសិនបើ 1
   printf("g\n");
#បើមិនដូច្នេះ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#បើមិនដូច្នេះ
   printf("j\n");
#endif
#បើមិនដូច្នេះ
#ifdef DEF
   printf("k\n");
#បើមិនដូច្នេះ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#បើមិនដូច្នេះ
   printf("n\n");
#endif
#បើមិនដូច្នេះ
#ifndef DEF
   printf("o\n");
#បើមិនដូច្នេះ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ប្រសិនបើ ONE
#ប្រសិនបើ ZERO
   printf("q\n");
#បើមិនដូច្នេះ
   printf("r\n");
#endif
#បើមិនដូច្នេះ
#ប្រសិនបើ ZERO
   printf("s\n");
#បើមិនដូច្នេះ
   printf("t\n");
#endif
#endif

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
