#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਬਣਤਰ ziggy
{
   ਪੂਰਨ a;
   ਪੂਰਨ b;
   ਪੂਰਨ c;
} bolshevic;

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ a;
   ਪੂਰਨ *b;
   ਪੂਰਨ c;

   a = 42;
   b = &a;
   ਲਿਖੋ("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   ਲਿਖੋ("bolshevic.a = %d\n", bolshevic.a);
   ਲਿਖੋ("bolshevic.b = %d\n", bolshevic.b);
   ਲਿਖੋ("bolshevic.c = %d\n", bolshevic.c);

   ਬਣਤਰ ziggy *tsar = &bolshevic;

   ਲਿਖੋ("tsar->a = %d\n", tsar->a);
   ਲਿਖੋ("tsar->b = %d\n", tsar->b);
   ਲਿਖੋ("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   ਲਿਖੋ("bolshevic.b = %d\n", *b);

   ਵਾਪਸ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
