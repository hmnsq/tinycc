#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
   ਲਿਖੋ("including\n");
#ਅਨ੍ਤਰ੍ਭਾਵ "18_include.h"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  test_missing_nl
   ਲਿਖੋ("done\n");

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  INC   "18_include.h"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __has_include
#ਜੇ defined __has_include
#ਜੇ __has_include("18_include.h")
   ਲਿਖੋ("has_include\n");
#ਜੇ_ਅੰਤ
#ਜੇ __has_include(INC)
   ਲਿਖੋ("has_include\n");
#ਜੇ_ਅੰਤ
#ਜੇ __has_include("not_found_18_include.h")
   ਲਿਖੋ("has_include not found\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __has_include_next
#ਜੇ defined __has_include_next
#ਜੇ __has_include_next("18_include.h")
   ਲਿਖੋ("has_include_next\n");
#ਜੇ_ਅੰਤ
#ਜੇ __has_include_next(INC)
   ਲਿਖੋ("has_include_next\n");
#ਜੇ_ਅੰਤ
#ਜੇ __has_include_next("not_found_18_include.h")
   ਲਿਖੋ("has_include_next not found\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ "18_include2.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "./18_include2.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "../tests2/18_include2.h"

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
