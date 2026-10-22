#شامل <stdio.h>

صحیح اصلی()
{
   printf("including\n");
#شامل "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#اگر defined __has_include
#اگر __has_include("18_include.h")
   printf("has_include\n");
#endif
#اگر __has_include(INC)
   printf("has_include\n");
#endif
#اگر __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#اگر defined __has_include_next
#اگر __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#اگر __has_include_next(INC)
   printf("has_include_next\n");
#endif
#اگر __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#شامل "18_include2.h"
#شامل "./18_include2.h"
#شامل "../tests2/18_include2.h"

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
