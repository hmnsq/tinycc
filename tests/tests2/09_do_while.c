#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ a;
   ಪೂರ್ಣಾಙ್ಕ p;
   ಪೂರ್ಣಾಙ್ಕ t;

   a = 1;
   p = 0;
   t = 0;

   ಕುರು
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ಯಾವತ್ (a < 100);

   ಪ್ರತ್ಯಾಗಮ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
