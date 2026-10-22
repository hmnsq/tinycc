#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ x = 'a';
   ವರ್ಣ y = x;

   ವರ್ಣ *a = "hello";

   printf("%s\n", a);

   ಪೂರ್ಣಾಙ್ಕ c;
   c = *a;

   ವರ್ಣ *b;
   ಪ್ರತಿ (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   ವರ್ಣ destarray[10];
   ವರ್ಣ *dest = &destarray[0];
   ವರ್ಣ *src = a;

   ಯಾವತ್ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
