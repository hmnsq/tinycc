#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   printf("including\n");
#include "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#ຖ້າ defined __has_include
#ຖ້າ __has_include("18_include.h")
   printf("has_include\n");
#endif
#ຖ້າ __has_include(INC)
   printf("has_include\n");
#endif
#ຖ້າ __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#ຖ້າ defined __has_include_next
#ຖ້າ __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#ຖ້າ __has_include_next(INC)
   printf("has_include_next\n");
#endif
#ຖ້າ __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#include "18_include2.h"
#include "./18_include2.h"
#include "../tests2/18_include2.h"

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
