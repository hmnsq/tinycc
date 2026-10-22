#ضمن <stdio.h>

صحيح مکھ()
{
   لکھو("including\n");
#ضمن "18_include.h"
#تعریف_کرو  test_missing_nl
   لکھو("done\n");

#تعریف_کرو  INC   "18_include.h"

#جے_تعریف_شدہ __has_include
#إذا defined __has_include
#إذا __has_include("18_include.h")
   لکھو("has_include\n");
#جے_انت
#إذا __has_include(INC)
   لکھو("has_include\n");
#جے_انت
#إذا __has_include("not_found_18_include.h")
   لکھو("has_include not found\n");
#جے_انت
#جے_انت
#جے_انت

#جے_تعریف_شدہ __has_include_next
#إذا defined __has_include_next
#إذا __has_include_next("18_include.h")
   لکھو("has_include_next\n");
#جے_انت
#إذا __has_include_next(INC)
   لکھو("has_include_next\n");
#جے_انت
#إذا __has_include_next("not_found_18_include.h")
   لکھو("has_include_next not found\n");
#جے_انت
#جے_انت
#جے_انت

#ضمن "18_include2.h"
#ضمن "./18_include2.h"
#ضمن "../tests2/18_include2.h"

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
