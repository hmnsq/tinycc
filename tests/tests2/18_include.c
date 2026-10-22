#समावेश <stdio.h>

पूर्णांक मुख्य()
{
   म_लिखो("including\n");
#समावेश "18_include.h"
#घोषणा  test_missing_nl
   म_लिखो("done\n");

#घोषणा  INC   "18_include.h"

#अगर_घोषित __has_include
#अगर defined __has_include
#अगर __has_include("18_include.h")
   म_लिखो("has_include\n");
#पूर्ण_अगर
#अगर __has_include(INC)
   म_लिखो("has_include\n");
#पूर्ण_अगर
#अगर __has_include("not_found_18_include.h")
   म_लिखो("has_include not found\n");
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __has_include_next
#अगर defined __has_include_next
#अगर __has_include_next("18_include.h")
   म_लिखो("has_include_next\n");
#पूर्ण_अगर
#अगर __has_include_next(INC)
   म_लिखो("has_include_next\n");
#पूर्ण_अगर
#अगर __has_include_next("not_found_18_include.h")
   म_लिखो("has_include_next not found\n");
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#समावेश "18_include2.h"
#समावेश "./18_include2.h"
#समावेश "../tests2/18_include2.h"

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
