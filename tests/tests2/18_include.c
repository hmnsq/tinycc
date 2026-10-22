#ضمن <stdio.h>

صحيح اصلي()
{
   چاپ_کړه("including\n");
#ضمن "18_include.h"
#تعریف_کړه  test_missing_nl
   چاپ_کړه("done\n");

#تعریف_کړه  INC   "18_include.h"

#که_تعریف_شوی __has_include
#إذا defined __has_include
#إذا __has_include("18_include.h")
   چاپ_کړه("has_include\n");
#د_که_پای
#إذا __has_include(INC)
   چاپ_کړه("has_include\n");
#د_که_پای
#إذا __has_include("not_found_18_include.h")
   چاپ_کړه("has_include not found\n");
#د_که_پای
#د_که_پای
#د_که_پای

#که_تعریف_شوی __has_include_next
#إذا defined __has_include_next
#إذا __has_include_next("18_include.h")
   چاپ_کړه("has_include_next\n");
#د_که_پای
#إذا __has_include_next(INC)
   چاپ_کړه("has_include_next\n");
#د_که_پای
#إذا __has_include_next("not_found_18_include.h")
   چاپ_کړه("has_include_next not found\n");
#د_که_پای
#د_که_پای
#د_که_پای

#ضمن "18_include2.h"
#ضمن "./18_include2.h"
#ضمن "../tests2/18_include2.h"

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
