#شامل <stdio.h>

صحیح مین()
{
   صحیح a;
   صحیح *b;
   صحیح *c;

   a = 42;
   b = &a;
   c = تہی;

   لکھو("%d\n", *b);

   اگر (b == تہی)
      لکھو("b is NULL\n");
   ورنہ
      لکھو("b is not NULL\n");

   اگر (c == تہی)
      لکھو("c is NULL\n");
   ورنہ
      لکھو("c is not NULL\n");

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
