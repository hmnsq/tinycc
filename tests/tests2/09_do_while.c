#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ a;
   ਪੂਰਨ p;
   ਪੂਰਨ t;

   a = 1;
   p = 0;
   t = 0;

   ਕਰੋ
   {
      ਲਿਖੋ("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ਜਦੋਂ (a < 100);

   ਵਾਪਸ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
