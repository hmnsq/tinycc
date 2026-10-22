#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   printf("including\n");
#अन्तर्भाव "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#सचे defined __has_include
#सचे __has_include("18_include.h")
   printf("has_include\n");
#endif
#सचे __has_include(INC)
   printf("has_include\n");
#endif
#सचे __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#सचे defined __has_include_next
#सचे __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#सचे __has_include_next(INC)
   printf("has_include_next\n");
#endif
#सचे __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#अन्तर्भाव "18_include2.h"
#अन्तर्भाव "./18_include2.h"
#अन्तर्भाव "../tests2/18_include2.h"

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
