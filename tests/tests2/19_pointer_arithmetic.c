#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   पूर्णाङ्क a;
   पूर्णाङ्क *b;
   पूर्णाङ्क *c;

   a = 42;
   b = &a;
   c = रिक्त;

   printf("%d\n", *b);

   जइ (b == रिक्त)
      printf("b is NULL\n");
   अण्णहा
      printf("b is not NULL\n");

   जइ (c == रिक्त)
      printf("c is NULL\n");
   अण्णहा
      printf("c is not NULL\n");

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
