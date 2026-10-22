#ضمن <stdio.h>

صحيح اصلی()
{
   صحيح a;
   صحيح *b;
   صحيح *c;

   a = 42;
   b = &a;
   c = عدم;

   چاپ_کن("%d\n", *b);

   إذا (b == عدم)
      چاپ_کن("b is NULL\n");
   وإلا
      چاپ_کن("b is not NULL\n");

   إذا (c == عدم)
      چاپ_کن("c is NULL\n");
   وإلا
      چاپ_کن("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
