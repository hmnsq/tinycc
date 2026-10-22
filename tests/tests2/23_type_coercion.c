#ಅನ್ತರ್ಭಾವ <stdio.h>

ಶೂನ್ಯ charfunc(ವರ್ಣ a)
{
   printf("char: %c\n", a);
}

ಶೂನ್ಯ intfunc(ಪೂರ್ಣಾಙ್ಕ a)
{
   printf("int: %d\n", a);
}

ಶೂನ್ಯ floatfunc(ಭಿನ್ನ a)
{
   printf("float: %f\n", a);
}

ಪೂರ್ಣಾಙ್ಕ main()
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

   ವರ್ಣ b = 97;
   ವರ್ಣ c = 97.0;

   printf("%d %d\n", b, c);

   ಪೂರ್ಣಾಙ್ಕ d = 'a';
   ಪೂರ್ಣಾಙ್ಕ e = 97.0;

   printf("%d %d\n", d, e);

   ಭಿನ್ನ f = 'a';
   ಭಿನ್ನ g = 97;

   printf("%f %f\n", f, g);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
