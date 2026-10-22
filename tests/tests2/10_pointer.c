#അന്തര്ഭാവ <stdio.h>

ഘടന ziggy
{
   പൂർണ്ണസംഖ്യ a;
   പൂർണ്ണസംഖ്യ b;
   പൂർണ്ണസംഖ്യ c;
} bolshevic;

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ a;
   പൂർണ്ണസംഖ്യ *b;
   പൂർണ്ണസംഖ്യ c;

   a = 42;
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   ഘടന ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   തിരികെ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
