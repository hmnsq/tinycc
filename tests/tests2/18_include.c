#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   printf("including\n");
#અન્તર્ભાવ "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#જો defined __has_include
#જો __has_include("18_include.h")
   printf("has_include\n");
#endif
#જો __has_include(INC)
   printf("has_include\n");
#endif
#જો __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#જો defined __has_include_next
#જો __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#જો __has_include_next(INC)
   printf("has_include_next\n");
#endif
#જો __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#અન્તર્ભાવ "18_include2.h"
#અન્તર્ભાવ "./18_include2.h"
#અન્તર્ભાવ "../tests2/18_include2.h"

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
