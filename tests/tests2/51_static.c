#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fred = 1234;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ joe;

ಶೂನ್ಯ henry()
{
   ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
