#ضمن <stdio.h>

صحيح الرئيسية()
{
   printf("including\n");
#ضمن "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#إذا defined __has_include
#إذا __has_include("18_include.h")
   printf("has_include\n");
#endif
#إذا __has_include(INC)
   printf("has_include\n");
#endif
#إذا __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#إذا defined __has_include_next
#إذا __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#إذا __has_include_next(INC)
   printf("has_include_next\n");
#endif
#إذا __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#ضمن "18_include2.h"
#ضمن "./18_include2.h"
#ضمن "../tests2/18_include2.h"

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
