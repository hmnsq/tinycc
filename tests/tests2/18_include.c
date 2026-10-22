#ضمن <stdio.h>

صحيح مکيه()
{
   لکو("including\n");
#ضمن "18_include.h"
#وصف_ڪريو  test_missing_nl
   لکو("done\n");

#وصف_ڪريو  INC   "18_include.h"

#جيڪڏهن_وصف_ٿيل __has_include
#إذا defined __has_include
#إذا __has_include("18_include.h")
   لکو("has_include\n");
#جيڪڏهن_پورو
#إذا __has_include(INC)
   لکو("has_include\n");
#جيڪڏهن_پورو
#إذا __has_include("not_found_18_include.h")
   لکو("has_include not found\n");
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __has_include_next
#إذا defined __has_include_next
#إذا __has_include_next("18_include.h")
   لکو("has_include_next\n");
#جيڪڏهن_پورو
#إذا __has_include_next(INC)
   لکو("has_include_next\n");
#جيڪڏهن_پورو
#إذا __has_include_next("not_found_18_include.h")
   لکو("has_include_next not found\n");
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#ضمن "18_include2.h"
#ضمن "./18_include2.h"
#ضمن "../tests2/18_include2.h"

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
