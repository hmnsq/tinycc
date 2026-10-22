#ضمن <stdio.h>

صحيح الرئيسية()
{
   صحيح x = 'a';
   حرف y = x;

   حرف *a = "hello";

   printf("%s\n", a);

   صحيح c;
   c = *a;

   حرف *b;
   لكل (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   حرف destarray[10];
   حرف *dest = &destarray[0];
   حرف *src = a;

   بينما (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
