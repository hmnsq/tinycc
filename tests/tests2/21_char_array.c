#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಪೂರ್ಣಾಂಕ x = 'a';
   ಅಕ್ಷರ y = x;

   ಅಕ್ಷರ *a = "hello";

   ಬರೆ("%s\n", a);

   ಪೂರ್ಣಾಂಕ c;
   c = *a;

   ಅಕ್ಷರ *b;
   ಗಾಗಿ (b = a; *b != 0; b++)
      ಬರೆ("%c: %d\n", *b, *b);

   ಅಕ್ಷರ destarray[10];
   ಅಕ್ಷರ *dest = &destarray[0];
   ಅಕ್ಷರ *src = a;

   ಆಗ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   ಬರೆ("copied string is %s\n", destarray);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
