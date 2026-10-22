#ضمن <stdio.h>

صحيح main()
{
   صحيح a;
   صحيح *b;
   صحيح *c;

   a = 42;
   b = &a;
   c = عدم;

   printf("%d\n", *b);

   אם (b == عدم)
      printf("b is NULL\n");
   אחרת
      printf("b is not NULL\n");

   אם (c == عدم)
      printf("c is NULL\n");
   אחרת
      printf("c is not NULL\n");

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
