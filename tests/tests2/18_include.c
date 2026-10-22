#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
   printf("including\n");
#অন্তর্ভাব "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#যদি defined __has_include
#যদি __has_include("18_include.h")
   printf("has_include\n");
#endif
#যদি __has_include(INC)
   printf("has_include\n");
#endif
#যদি __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#যদি defined __has_include_next
#যদি __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#যদি __has_include_next(INC)
   printf("has_include_next\n");
#endif
#যদি __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#অন্তর্ভাব "18_include2.h"
#অন্তর্ভাব "./18_include2.h"
#অন্তর্ভাব "../tests2/18_include2.h"

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
