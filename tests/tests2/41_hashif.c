#include <stdio.h>

ကိန်းပြည့် main()
{
   printf("#include test\n");

#အကယ်၍ 1
#အကယ်၍ 0
   printf("a\n");
#မဟုတ်ပါက
   printf("b\n");
#endif
#မဟုတ်ပါက
#အကယ်၍ 0
   printf("c\n");
#မဟုတ်ပါက
   printf("d\n");
#endif
#endif

#အကယ်၍ 0
#အကယ်၍ 1
   printf("e\n");
#မဟုတ်ပါက
   printf("f\n");
#endif
#မဟုတ်ပါက
#အကယ်၍ 1
   printf("g\n");
#မဟုတ်ပါက
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#မဟုတ်ပါက
   printf("j\n");
#endif
#မဟုတ်ပါက
#ifdef DEF
   printf("k\n");
#မဟုတ်ပါက
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#မဟုတ်ပါက
   printf("n\n");
#endif
#မဟုတ်ပါက
#ifndef DEF
   printf("o\n");
#မဟုတ်ပါက
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#အကယ်၍ ONE
#အကယ်၍ ZERO
   printf("q\n");
#မဟုတ်ပါက
   printf("r\n");
#endif
#မဟုတ်ပါက
#အကယ်၍ ZERO
   printf("s\n");
#မဟုတ်ပါက
   printf("t\n");
#endif
#endif

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
