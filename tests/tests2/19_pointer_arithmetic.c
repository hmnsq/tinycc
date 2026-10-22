#ضمن <stdio.h>

صحيح مکھ()
{
   صحيح a;
   صحيح *b;
   صحيح *c;

   a = 42;
   b = &a;
   c = عدم;

   لکھو("%d\n", *b);

   إذا (b == عدم)
      لکھو("b is NULL\n");
   وإلا
      لکھو("b is not NULL\n");

   إذا (c == عدم)
      لکھو("c is NULL\n");
   وإلا
      لکھو("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
