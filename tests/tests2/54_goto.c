#ಅನ್ತರ್ಭಾವ <stdio.h>

ಶೂನ್ಯ fred()
{
   ಬರೆ("In fred()\n");
   ಹೋಗು ಮುಗಿದ;
   ಬರೆ("In middle\n");
ಮುಗಿದ:
   ಬರೆ("At end\n");
}

ಶೂನ್ಯ joe()
{
   ಪೂರ್ಣಾಂಕ b = 5678;

   ಬರೆ("In joe()\n");

   {
      ಪೂರ್ಣಾಂಕ c = 1234;
      ಬರೆ("c = %d\n", c);
      ಹೋಗು outer;
      ಬರೆ("uh-oh\n");
   }

outer:    

   ಬರೆ("done\n");
}

ಶೂನ್ಯ henry()
{
   ಪೂರ್ಣಾಂಕ a;

   ಬರೆ("In henry()\n");
   ಹೋಗು inner;

   {
      ಪೂರ್ಣಾಂಕ b;
inner:    
      b = 1234;
      ಬರೆ("b = %d\n", b);
   }

   ಬರೆ("done\n");
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   fred();
   joe();
   henry();

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
