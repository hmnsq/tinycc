#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   म_लिखो("including\n");
#अन्तर्भाव "18_include.h"
#define  test_missing_nl
   म_लिखो("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#यदि defined __has_include
#यदि __has_include("18_include.h")
   म_लिखो("has_include\n");
#endif
#यदि __has_include(INC)
   म_लिखो("has_include\n");
#endif
#यदि __has_include("not_found_18_include.h")
   म_लिखो("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#यदि defined __has_include_next
#यदि __has_include_next("18_include.h")
   म_लिखो("has_include_next\n");
#endif
#यदि __has_include_next(INC)
   म_लिखो("has_include_next\n");
#endif
#यदि __has_include_next("not_found_18_include.h")
   म_लिखो("has_include_next not found\n");
#endif
#endif
#endif

#अन्तर्भाव "18_include2.h"
#अन्तर्भाव "./18_include2.h"
#अन्तर्भाव "../tests2/18_include2.h"

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
