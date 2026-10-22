#ضمن <stdio.h>

صحيح مکيه()
{
   صحيح a;
   صحيح *b;
   صحيح *c;

   a = 42;
   b = &a;
   c = عدم;

   لکو("%d\n", *b);

   إذا (b == عدم)
      لکو("b is NULL\n");
   وإلا
      لکو("b is not NULL\n");

   إذا (c == عدم)
      لکو("c is NULL\n");
   وإلا
      لکو("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
