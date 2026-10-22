#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   printf("including\n");
#ଅନ୍ତର୍ଭାଵ "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#ଯଦି defined __has_include
#ଯଦି __has_include("18_include.h")
   printf("has_include\n");
#endif
#ଯଦି __has_include(INC)
   printf("has_include\n");
#endif
#ଯଦି __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#ଯଦି defined __has_include_next
#ଯଦି __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#ଯଦି __has_include_next(INC)
   printf("has_include_next\n");
#endif
#ଯଦି __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#ଅନ୍ତର୍ଭାଵ "18_include2.h"
#ଅନ୍ତର୍ଭାଵ "./18_include2.h"
#ଅନ୍ତର୍ଭାଵ "../tests2/18_include2.h"

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
