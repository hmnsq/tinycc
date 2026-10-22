#شامل <stdio.h>

صحیح اصلی()
{
   صحیح a;
   صحیح *b;
   صحیح *c;

   a = 42;
   b = &a;
   c = پوچ;

   printf("%d\n", *b);

   اگر (b == پوچ)
      printf("b is NULL\n");
   وگرنه
      printf("b is not NULL\n");

   اگر (c == پوچ)
      printf("c is NULL\n");
   وگرنه
      printf("c is not NULL\n");

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
