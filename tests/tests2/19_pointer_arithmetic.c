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

   𐡄𐡍 (b == عدم)
      printf("b is NULL\n");
   وإلا
      printf("b is not NULL\n");

   𐡄𐡍 (c == عدم)
      printf("c is NULL\n");
   وإلا
      printf("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
