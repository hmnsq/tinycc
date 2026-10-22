#ضمن <stdio.h>

صحيح اصلي()
{
   صحيح a;
   صحيح *b;
   صحيح *c;

   a = 42;
   b = &a;
   c = عدم;

   چاپ_کړه("%d\n", *b);

   إذا (b == عدم)
      چاپ_کړه("b is NULL\n");
   وإلا
      چاپ_کړه("b is not NULL\n");

   إذا (c == عدم)
      چاپ_کړه("c is NULL\n");
   وإلا
      چاپ_کړه("c is not NULL\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
