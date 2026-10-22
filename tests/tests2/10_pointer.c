#ضمن <stdio.h>

بنية ziggy
{
   صحيح a;
   صحيح b;
   صحيح c;
} bolshevic;

صحيح مکھ()
{
   صحيح a;
   صحيح *b;
   صحيح c;

   a = 42;
   b = &a;
   لکھو("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   لکھو("bolshevic.a = %d\n", bolshevic.a);
   لکھو("bolshevic.b = %d\n", bolshevic.b);
   لکھو("bolshevic.c = %d\n", bolshevic.c);

   بنية ziggy *tsar = &bolshevic;

   لکھو("tsar->a = %d\n", tsar->a);
   لکھو("tsar->b = %d\n", tsar->b);
   لکھو("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   لکھو("bolshevic.b = %d\n", *b);

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
