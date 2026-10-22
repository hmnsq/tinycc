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

   إذا (b == عدم)
      printf("b is NULL\n");
   وإلا
      printf("b is not NULL\n");

   إذا (c == عدم)
      printf("c is NULL\n");
   وإلا
      printf("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
