#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ fred = 1234;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ joe;

ಶೂನ್ಯ henry()
{
   ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ fred = 4567;

   ಬರೆ("%d\n", fred);
   fred++;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಬರೆ("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   ಬರೆ("%d\n", fred);
   fred = 8901;
   joe = 2345;
   ಬರೆ("%d\n", fred);
   ಬರೆ("%d\n", joe);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
