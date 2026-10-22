#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   printf("#include test\n");

#ຖ້າ 1
#ຖ້າ 0
   printf("a\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("b\n");
#endif
#ບໍ່ດັ່ງນັ້ນ
#ຖ້າ 0
   printf("c\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("d\n");
#endif
#endif

#ຖ້າ 0
#ຖ້າ 1
   printf("e\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("f\n");
#endif
#ບໍ່ດັ່ງນັ້ນ
#ຖ້າ 1
   printf("g\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("j\n");
#endif
#ບໍ່ດັ່ງນັ້ນ
#ifdef DEF
   printf("k\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("n\n");
#endif
#ບໍ່ດັ່ງນັ້ນ
#ifndef DEF
   printf("o\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ຖ້າ ONE
#ຖ້າ ZERO
   printf("q\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("r\n");
#endif
#ບໍ່ດັ່ງນັ້ນ
#ຖ້າ ZERO
   printf("s\n");
#ບໍ່ດັ່ງນັ້ນ
   printf("t\n");
#endif
#endif

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
