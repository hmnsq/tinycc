#ಅನ್ತರ್ಭಾವ <stdio.h>

ಶೂನ್ಯ charfunc(ಅಕ್ಷರ a)
{
   ಬರೆ("char: %c\n", a);
}

ಶೂನ್ಯ intfunc(ಪೂರ್ಣಾಂಕ a)
{
   ಬರೆ("int: %d\n", a);
}

ಶೂನ್ಯ floatfunc(ದಶಮಾಂಶ a)
{
   ಬರೆ("float: %f\n", a);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   ಅಕ್ಷರ b = 97;
   ಅಕ್ಷರ c = 97.0;

   ಬರೆ("%d %d\n", b, c);

   ಪೂರ್ಣಾಂಕ d = 'a';
   ಪೂರ್ಣಾಂಕ e = 97.0;

   ಬರೆ("%d %d\n", d, e);

   ದಶಮಾಂಶ f = 'a';
   ದಶಮಾಂಶ g = 97;

   ಬರೆ("%f %f\n", f, g);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
