#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ fred()
{
   ಬರೆ("fred\n");
   ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ joe()
{
   ಬರೆ("joe\n");
   ಹಿಂತಿರುಗಿ 1;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಬರೆ("%d\n", fred() && joe());
   ಬರೆ("%d\n", fred() || joe());
   ಬರೆ("%d\n", joe() && fred());
   ಬರೆ("%d\n", joe() || fred());
   ಬರೆ("%d\n", fred() && (1 + joe()));
   ಬರೆ("%d\n", fred() || (0 + joe()));
   ಬರೆ("%d\n", joe() && (0 + fred()));
   ಬರೆ("%d\n", joe() || (1 + fred()));

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
