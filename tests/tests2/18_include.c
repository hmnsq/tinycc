#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   printf("including\n");
#அந்தர்பாவ "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#எனில் defined __has_include
#எனில் __has_include("18_include.h")
   printf("has_include\n");
#endif
#எனில் __has_include(INC)
   printf("has_include\n");
#endif
#எனில் __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#எனில் defined __has_include_next
#எனில் __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#எனில் __has_include_next(INC)
   printf("has_include_next\n");
#endif
#எனில் __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#அந்தர்பாவ "18_include2.h"
#அந்தர்பாவ "./18_include2.h"
#அந்தர்பாவ "../tests2/18_include2.h"

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
