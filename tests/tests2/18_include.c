#include <stdio.h>

puur_naa_nka main()
{
   printf("including\n");
#include "18_include.h"
#define  test_missing_nl
   printf("done\n");

#define  INC   "18_include.h"

#ifdef __has_include
#ᯀᯮᯝ defined __has_include
#ᯀᯮᯝ __has_include("18_include.h")
   printf("has_include\n");
#endif
#ᯀᯮᯝ __has_include(INC)
   printf("has_include\n");
#endif
#ᯀᯮᯝ __has_include("not_found_18_include.h")
   printf("has_include not found\n");
#endif
#endif
#endif

#ifdef __has_include_next
#ᯀᯮᯝ defined __has_include_next
#ᯀᯮᯝ __has_include_next("18_include.h")
   printf("has_include_next\n");
#endif
#ᯀᯮᯝ __has_include_next(INC)
   printf("has_include_next\n");
#endif
#ᯀᯮᯝ __has_include_next("not_found_18_include.h")
   printf("has_include_next not found\n");
#endif
#endif
#endif

#include "18_include2.h"
#include "./18_include2.h"
#include "../tests2/18_include2.h"

   ᯀᯮᯞ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
