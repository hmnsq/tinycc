#شامل <stdio.h>

صحیح مین()
{
   لکھو("including\n");
#شامل "18_include.h"
#تعریف_کرو  test_missing_nl
   لکھو("done\n");

#تعریف_کرو  INC   "18_include.h"

#اگر_تعریف_شدہ __has_include
#اگر defined __has_include
#اگر __has_include("18_include.h")
   لکھو("has_include\n");
#اگر_ختم
#اگر __has_include(INC)
   لکھو("has_include\n");
#اگر_ختم
#اگر __has_include("not_found_18_include.h")
   لکھو("has_include not found\n");
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __has_include_next
#اگر defined __has_include_next
#اگر __has_include_next("18_include.h")
   لکھو("has_include_next\n");
#اگر_ختم
#اگر __has_include_next(INC)
   لکھو("has_include_next\n");
#اگر_ختم
#اگر __has_include_next("not_found_18_include.h")
   لکھو("has_include_next not found\n");
#اگر_ختم
#اگر_ختم
#اگر_ختم

#شامل "18_include2.h"
#شامل "./18_include2.h"
#شامل "../tests2/18_include2.h"

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
