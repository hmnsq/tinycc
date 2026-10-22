#अन्तर्भाव <stdio.h>

पूर्णाङ्क मुख्यम्()
{
   प्रारूप_लिख("including\n");
#अन्तर्भाव "18_include.h"
#परिभाषय  test_missing_nl
   प्रारूप_लिख("done\n");

#परिभाषय  INC   "18_include.h"

#यदि_परिभाषितम् __has_include
#यदि defined __has_include
#यदि __has_include("18_include.h")
   प्रारूप_लिख("has_include\n");
#यदि_अन्तः
#यदि __has_include(INC)
   प्रारूप_लिख("has_include\n");
#यदि_अन्तः
#यदि __has_include("not_found_18_include.h")
   प्रारूप_लिख("has_include not found\n");
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __has_include_next
#यदि defined __has_include_next
#यदि __has_include_next("18_include.h")
   प्रारूप_लिख("has_include_next\n");
#यदि_अन्तः
#यदि __has_include_next(INC)
   प्रारूप_लिख("has_include_next\n");
#यदि_अन्तः
#यदि __has_include_next("not_found_18_include.h")
   प्रारूप_लिख("has_include_next not found\n");
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#अन्तर्भाव "18_include2.h"
#अन्तर्भाव "./18_include2.h"
#अन्तर्भाव "../tests2/18_include2.h"

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
