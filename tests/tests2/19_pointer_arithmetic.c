#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   முழு a;
   முழு *b;
   முழு *c;

   a = 42;
   b = &a;
   c = வெற்று;

   printf("%d\n", *b);

   எனில் (b == வெற்று)
      printf("b is NULL\n");
   இல்லையெனில்
      printf("b is not NULL\n");

   எனில் (c == வெற்று)
      printf("c is NULL\n");
   இல்லையெனில்
      printf("c is not NULL\n");

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
