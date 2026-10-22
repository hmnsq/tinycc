#અન્તર્ભાવ <stdio.h>

સંરચના ziggy
{
   પૂર્ણાંક a;
   પૂર્ણાંક b;
   પૂર્ણાંક c;
} bolshevic;

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક a;
   પૂર્ણાંક *b;
   પૂર્ણાંક c;

   a = 42;
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   સંરચના ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   પાછા 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
