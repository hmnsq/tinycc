#അന്തര്ഭാവ <stdio.h>

#define FRED 12
#define BLOGGS(x) (12*(x))

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   printf("%d\n", FRED);
   printf("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));

   തിരികെ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
