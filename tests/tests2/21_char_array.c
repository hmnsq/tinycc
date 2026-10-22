#ضمن <stdio.h>

صحيح اصلی()
{
   صحيح x = 'a';
   حرف y = x;

   حرف *a = "hello";

   چاپ_کن("%s\n", a);

   صحيح c;
   c = *a;

   حرف *b;
   لكل (b = a; *b != 0; b++)
      چاپ_کن("%c: %d\n", *b, *b);

   حرف destarray[10];
   حرف *dest = &destarray[0];
   حرف *src = a;

   طالما (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   چاپ_کن("copied string is %s\n", destarray);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
