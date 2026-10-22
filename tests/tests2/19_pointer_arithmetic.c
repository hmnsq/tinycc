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

   सचे (b == रिक्त)
      printf("b is NULL\n");
   अञ्ञथा
      printf("b is not NULL\n");

   सचे (c == रिक्त)
      printf("c is NULL\n");
   अञ्ञथा
      printf("c is not NULL\n");

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
