#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ a;
   ਪੂਰਨ *b;
   ਪੂਰਨ *c;

   a = 42;
   b = &a;
   c = ਨਿਰਾ;

   ਲਿਖੋ("%d\n", *b);

   ਜੇ (b == ਨਿਰਾ)
      ਲਿਖੋ("b is NULL\n");
   ਨਹੀਂਤਾਂ
      ਲਿਖੋ("b is not NULL\n");

   ਜੇ (c == ਨਿਰਾ)
      ਲਿਖੋ("c is NULL\n");
   ਨਹੀਂਤਾਂ
      ਲਿਖੋ("c is not NULL\n");

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
