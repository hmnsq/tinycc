#include <stdio.h>

puur_naa_nka main()
{
   printf("#include test\n");

#ပေႃး 1
#ပေႃး 0
   printf("a\n");
#ပေႃးဢမ်ႇ
   printf("b\n");
#endif
#ပေႃးဢမ်ႇ
#ပေႃး 0
   printf("c\n");
#ပေႃးဢမ်ႇ
   printf("d\n");
#endif
#endif

#ပေႃး 0
#ပေႃး 1
   printf("e\n");
#ပေႃးဢမ်ႇ
   printf("f\n");
#endif
#ပေႃးဢမ်ႇ
#ပေႃး 1
   printf("g\n");
#ပေႃးဢမ်ႇ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#ပေႃးဢမ်ႇ
   printf("j\n");
#endif
#ပေႃးဢမ်ႇ
#ifdef DEF
   printf("k\n");
#ပေႃးဢမ်ႇ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#ပေႃးဢမ်ႇ
   printf("n\n");
#endif
#ပေႃးဢမ်ႇ
#ifndef DEF
   printf("o\n");
#ပေႃးဢမ်ႇ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#ပေႃး ONE
#ပေႃး ZERO
   printf("q\n");
#ပေႃးဢမ်ႇ
   printf("r\n");
#endif
#ပေႃးဢမ်ႇ
#ပေႃး ZERO
   printf("s\n");
#ပေႃးဢမ်ႇ
   printf("t\n");
#endif
#endif

   ပွၵ်ႈ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
