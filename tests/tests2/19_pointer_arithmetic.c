#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ a;
   ಪೂರ್ಣಾಙ್ಕ *b;
   ಪೂರ್ಣಾಙ್ಕ *c;

   a = 42;
   b = &a;
   c = ರಿಕ್ತ;

   printf("%d\n", *b);

   ಯದಿ (b == ರಿಕ್ತ)
      printf("b is NULL\n");
   ಅನ್ಯಥಾ
      printf("b is not NULL\n");

   ಯದಿ (c == ರಿಕ್ತ)
      printf("c is NULL\n");
   ಅನ್ಯಥಾ
      printf("c is not NULL\n");

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
