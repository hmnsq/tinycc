#شامل <stdio.h>

صحیح اصلی()
{
   صحیح x = 'a';
   نویسه y = x;

   نویسه *a = "hello";

   printf("%s\n", a);

   صحیح c;
   c = *a;

   نویسه *b;
   برای (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   نویسه destarray[10];
   نویسه *dest = &destarray[0];
   نویسه *src = a;

   وقتی (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
