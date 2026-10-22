#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ x = 'a';
   ਅੱਖਰ y = x;

   ਅੱਖਰ *a = "hello";

   ਲਿਖੋ("%s\n", a);

   ਪੂਰਨ c;
   c = *a;

   ਅੱਖਰ *b;
   ਲਈ (b = a; *b != 0; b++)
      ਲਿਖੋ("%c: %d\n", *b, *b);

   ਅੱਖਰ destarray[10];
   ਅੱਖਰ *dest = &destarray[0];
   ਅੱਖਰ *src = a;

   ਜਦੋਂ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   ਲਿਖੋ("copied string is %s\n", destarray);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
