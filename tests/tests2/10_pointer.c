#ضمن <stdio.h>

بنية ziggy
{
   صحيح a;
   صحيح b;
   صحيح c;
} bolshevic;

صحيح اصلی()
{
   صحيح a;
   صحيح *b;
   صحيح c;

   a = 42;
   b = &a;
   چاپ_کن("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   چاپ_کن("bolshevic.a = %d\n", bolshevic.a);
   چاپ_کن("bolshevic.b = %d\n", bolshevic.b);
   چاپ_کن("bolshevic.c = %d\n", bolshevic.c);

   بنية ziggy *tsar = &bolshevic;

   چاپ_کن("tsar->a = %d\n", tsar->a);
   چاپ_کن("tsar->b = %d\n", tsar->b);
   چاپ_کن("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   چاپ_کن("bolshevic.b = %d\n", *b);

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
