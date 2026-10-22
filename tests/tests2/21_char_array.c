#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક x = 'a';
   અક્ષર y = x;

   અક્ષર *a = "hello";

   printf("%s\n", a);

   પૂર્ણાંક c;
   c = *a;

   અક્ષર *b;
   માટે (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   અક્ષર destarray[10];
   અક્ષર *dest = &destarray[0];
   અક્ષર *src = a;

   જ્યારે (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
