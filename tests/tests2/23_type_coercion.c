#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਖਾਲੀ charfunc(ਅੱਖਰ a)
{
   ਲਿਖੋ("char: %c\n", a);
}

ਖਾਲੀ intfunc(ਪੂਰਨ a)
{
   ਲਿਖੋ("int: %d\n", a);
}

ਖਾਲੀ floatfunc(ਦਸ਼ਮਲਵ a)
{
   ਲਿਖੋ("float: %f\n", a);
}

ਪੂਰਨ ਮੁੱਖ()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   ਅੱਖਰ b = 97;
   ਅੱਖਰ c = 97.0;

   ਲਿਖੋ("%d %d\n", b, c);

   ਪੂਰਨ d = 'a';
   ਪੂਰਨ e = 97.0;

   ਲਿਖੋ("%d %d\n", d, e);

   ਦਸ਼ਮਲਵ f = 'a';
   ਦਸ਼ਮਲਵ g = 97;

   ਲਿਖੋ("%f %f\n", f, g);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
