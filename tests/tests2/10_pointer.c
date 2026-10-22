#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಂರಚನಾ ziggy
{
   ಪೂರ್ಣಾಙ್ಕ a;
   ಪೂರ್ಣಾಙ್ಕ b;
   ಪೂರ್ಣಾಙ್ಕ c;
} bolshevic;

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ a;
   ಪೂರ್ಣಾಙ್ಕ *b;
   ಪೂರ್ಣಾಙ್ಕ c;

   a = 42;
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   ಸಂರಚನಾ ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   ಪ್ರತ್ಯಾಗಮ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
