#include <stdio.h>

sa_nracanaa ziggy
{
   จำนวนเต็ม a;
   จำนวนเต็ม b;
   จำนวนเต็ม c;
} bolshevic;

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม a;
   จำนวนเต็ม *b;
   จำนวนเต็ม c;

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

   คืน 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
