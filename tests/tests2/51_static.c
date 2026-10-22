#അന്തര്ഭാവ <stdio.h>

സ്ഥിതം പൂർണ്ണസംഖ്യ fred = 1234;
സ്ഥിതം പൂർണ്ണസംഖ്യ joe;

ശൂന്യം henry()
{
   സ്ഥിതം പൂർണ്ണസംഖ്യ fred = 4567;

   printf("%d\n", fred);
   fred++;
}

പൂർണ്ണസംഖ്യ പ്രധാന()
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

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
