#include <stdio.h>

sa_nracanaa ziggy
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် b;
   ကိန်းပြည့် c;
} bolshevic;

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် *b;
   ကိန်းပြည့် c;

   a = 42;
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   sa_nracanaa ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   ပြန်ပေး 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
