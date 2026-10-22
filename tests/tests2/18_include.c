#అన్తర్భావ <stdio.h>

పూర్ణాంకం ప్రధాన()
{
   రాయి("including\n");
#అన్తర్భావ "18_include.h"
#నిర్వచించు  test_missing_nl
   రాయి("done\n");

#నిర్వచించు  INC   "18_include.h"

#నిర్వచితమైతే __has_include
#ఒకవేళ defined __has_include
#ఒకవేళ __has_include("18_include.h")
   రాయి("has_include\n");
#అయితే_ముగింపు
#ఒకవేళ __has_include(INC)
   రాయి("has_include\n");
#అయితే_ముగింపు
#ఒకవేళ __has_include("not_found_18_include.h")
   రాయి("has_include not found\n");
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __has_include_next
#ఒకవేళ defined __has_include_next
#ఒకవేళ __has_include_next("18_include.h")
   రాయి("has_include_next\n");
#అయితే_ముగింపు
#ఒకవేళ __has_include_next(INC)
   రాయి("has_include_next\n");
#అయితే_ముగింపు
#ఒకవేళ __has_include_next("not_found_18_include.h")
   రాయి("has_include_next not found\n");
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#అన్తర్భావ "18_include2.h"
#అన్తర్భావ "./18_include2.h"
#అన్తర్భావ "../tests2/18_include2.h"

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
