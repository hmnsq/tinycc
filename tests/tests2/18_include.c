#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   printf("including\n");
#അന്തര്ഭാവ "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#എങ്കിൽ defined __has_include
#എങ്കിൽ __has_include("18_include.h")
   printf("has_include\n");
#endif
#എങ്കിൽ __has_include(INC)
   printf("has_include\n");
#endif
#എങ്കിൽ __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#എങ്കിൽ defined __has_include_next
#എങ്കിൽ __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#എങ്കിൽ __has_include_next(INC)
   printf("has_include_next\n");
#endif
#എങ്കിൽ __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#അന്തര്ഭാവ "18_include2.h"
#അന്തര്ഭാവ "./18_include2.h"
#അന്തര്ഭാവ "../tests2/18_include2.h"

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
