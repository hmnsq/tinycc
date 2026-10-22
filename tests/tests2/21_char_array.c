#شامل <stdio.h>

صحیح مین()
{
   صحیح x = 'a';
   حرف y = x;

   حرف *a = "hello";

   لکھو("%s\n", a);

   صحیح c;
   c = *a;

   حرف *b;
   برائے (b = a; *b != 0; b++)
      لکھو("%c: %d\n", *b, *b);

   حرف destarray[10];
   حرف *dest = &destarray[0];
   حرف *src = a;

   جب (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   لکھو("copied string is %s\n", destarray);

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
