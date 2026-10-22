#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
   ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_3;

   printf("hello world %d\n", argc);
   ಪ್ರತಿ (ಎಣಿಕೆ_3 = 1; ಎಣಿಕೆ_3 < argc; ಎಣಿಕೆ_3++)
      printf("arg %d: %s\n", ಎಣಿಕೆ_3, argv[ಎಣಿಕೆ_3]);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
