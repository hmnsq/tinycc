#અન્તર્ભાવ <stdio.h>

#define FRED 12
#define BLOGGS(x) (12*(x))

પૂર્ણાંક મુખ્ય()
{
   printf("%d\n", FRED);
   printf("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));

   પાછા 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
