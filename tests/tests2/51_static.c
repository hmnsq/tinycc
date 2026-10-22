#અન્તર્ભાવ <stdio.h>

સ્થિર પૂર્ણાંક fred = 1234;
સ્થિર પૂર્ણાંક joe;

શૂન્ય henry()
{
   સ્થિર પૂર્ણાંક fred = 4567;

   printf("%d\n", fred);
   fred++;
}

પૂર્ણાંક મુખ્ય()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
