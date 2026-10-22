#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಬರೆ("including\n");
#ಅನ್ತರ್ಭಾವ "18_include.h"
#ವ್ಯಾಖ್ಯಾನಿಸು  test_missing_nl
   ಬರೆ("done\n");

#ವ್ಯಾಖ್ಯಾನಿಸು  INC   "18_include.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __has_include
#ಆದರೆ defined __has_include
#ಆದರೆ __has_include("18_include.h")
   ಬರೆ("has_include\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ __has_include(INC)
   ಬರೆ("has_include\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ __has_include("not_found_18_include.h")
   ಬರೆ("has_include not found\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __has_include_next
#ಆದರೆ defined __has_include_next
#ಆದರೆ __has_include_next("18_include.h")
   ಬರೆ("has_include_next\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ __has_include_next(INC)
   ಬರೆ("has_include_next\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ __has_include_next("not_found_18_include.h")
   ಬರೆ("has_include_next not found\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ "18_include2.h"
#ಅನ್ತರ್ಭಾವ "./18_include2.h"
#ಅನ್ತರ್ಭಾವ "../tests2/18_include2.h"

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
