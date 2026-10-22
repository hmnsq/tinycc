#ضمن <stdio.h>

بنية ziggy
{
   صحيح a;
   صحيح b;
   صحيح c;
} bolshevic;

صحيح مکيه()
{
   صحيح a;
   صحيح *b;
   صحيح c;

   a = 42;
   b = &a;
   لکو("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   لکو("bolshevic.a = %d\n", bolshevic.a);
   لکو("bolshevic.b = %d\n", bolshevic.b);
   لکو("bolshevic.c = %d\n", bolshevic.c);

   بنية ziggy *tsar = &bolshevic;

   لکو("tsar->a = %d\n", tsar->a);
   لکو("tsar->b = %d\n", tsar->b);
   لکو("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   لکو("bolshevic.b = %d\n", *b);

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
