#ಅನ್ತರ್ಭಾವ <stdio.h>

ರಚನೆ ziggy
{
   ಪೂರ್ಣಾಂಕ a;
   ಪೂರ್ಣಾಂಕ b;
   ಪೂರ್ಣಾಂಕ c;
} bolshevic;

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಪೂರ್ಣಾಂಕ a;
   ಪೂರ್ಣಾಂಕ *b;
   ಪೂರ್ಣಾಂಕ c;

   a = 42;
   b = &a;
   ಬರೆ("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   ಬರೆ("bolshevic.a = %d\n", bolshevic.a);
   ಬರೆ("bolshevic.b = %d\n", bolshevic.b);
   ಬರೆ("bolshevic.c = %d\n", bolshevic.c);

   ರಚನೆ ziggy *tsar = &bolshevic;

   ಬರೆ("tsar->a = %d\n", tsar->a);
   ಬರೆ("tsar->b = %d\n", tsar->b);
   ಬರೆ("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   ಬರೆ("bolshevic.b = %d\n", *b);

   ಹಿಂತಿರುಗಿ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
