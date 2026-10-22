#అన్తర్భావ <stdio.h>

నిర్మాణం ziggy
{
   పూర్ణాంకం a;
   పూర్ణాంకం b;
   పూర్ణాంకం c;
} bolshevic;

పూర్ణాంకం ప్రధాన()
{
   పూర్ణాంకం a;
   పూర్ణాంకం *b;
   పూర్ణాంకం c;

   a = 42;
   b = &a;
   రాయి("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   రాయి("bolshevic.a = %d\n", bolshevic.a);
   రాయి("bolshevic.b = %d\n", bolshevic.b);
   రాయి("bolshevic.c = %d\n", bolshevic.c);

   నిర్మాణం ziggy *tsar = &bolshevic;

   రాయి("tsar->a = %d\n", tsar->a);
   రాయి("tsar->b = %d\n", tsar->b);
   రాయి("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   రాయి("bolshevic.b = %d\n", *b);

   తిరిగి 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
