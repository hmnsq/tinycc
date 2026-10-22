#ضمن <stdio.h>

بنية ziggy
{
   صحيح a;
   صحيح b;
   صحيح c;
} bolshevic;

صحيح اصلي()
{
   صحيح a;
   صحيح *b;
   صحيح c;

   a = 42;
   b = &a;
   چاپ_کړه("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   چاپ_کړه("bolshevic.a = %d\n", bolshevic.a);
   چاپ_کړه("bolshevic.b = %d\n", bolshevic.b);
   چاپ_کړه("bolshevic.c = %d\n", bolshevic.c);

   بنية ziggy *tsar = &bolshevic;

   چاپ_کړه("tsar->a = %d\n", tsar->a);
   چاپ_کړه("tsar->b = %d\n", tsar->b);
   چاپ_کړه("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   چاپ_کړه("bolshevic.b = %d\n", *b);

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
