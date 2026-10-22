#ضمن <stdio.h>

صحيح اصلی()
{
   چاپ_کن("including\n");
#ضمن "18_include.h"
#تعریف_کن  test_missing_nl
   چاپ_کن("done\n");

#تعریف_کن  INC   "18_include.h"

#اگر_تعریف_شده __has_include
#إذا defined __has_include
#إذا __has_include("18_include.h")
   چاپ_کن("has_include\n");
#پایان_اگر
#إذا __has_include(INC)
   چاپ_کن("has_include\n");
#پایان_اگر
#إذا __has_include("not_found_18_include.h")
   چاپ_کن("has_include not found\n");
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __has_include_next
#إذا defined __has_include_next
#إذا __has_include_next("18_include.h")
   چاپ_کن("has_include_next\n");
#پایان_اگر
#إذا __has_include_next(INC)
   چاپ_کن("has_include_next\n");
#پایان_اگر
#إذا __has_include_next("not_found_18_include.h")
   چاپ_کن("has_include_next not found\n");
#پایان_اگر
#پایان_اگر
#پایان_اگر

#ضمن "18_include2.h"
#ضمن "./18_include2.h"
#ضمن "../tests2/18_include2.h"

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
