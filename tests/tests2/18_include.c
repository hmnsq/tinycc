#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   printf("including\n");
#ಅನ್ತರ್ಭಾವ "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#ಯದಿ defined __has_include
#ಯದಿ __has_include("18_include.h")
   printf("has_include\n");
#endif
#ಯದಿ __has_include(INC)
   printf("has_include\n");
#endif
#ಯದಿ __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#ಯದಿ defined __has_include_next
#ಯದಿ __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#ಯದಿ __has_include_next(INC)
   printf("has_include_next\n");
#endif
#ಯದಿ __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#ಅನ್ತರ್ಭಾವ "18_include2.h"
#ಅನ್ತರ್ಭಾವ "./18_include2.h"
#ಅನ್ತರ್ಭಾವ "../tests2/18_include2.h"

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
