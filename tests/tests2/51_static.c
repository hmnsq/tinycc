#அந்தர்பாவ <stdio.h>

நிலையான முழு fred = 1234;
நிலையான முழு joe;

வெறுமை henry()
{
   நிலையான முழு fred = 4567;

   printf("%d\n", fred);
   fred++;
}

முழு முதன்மை()
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

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
