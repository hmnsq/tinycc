#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ a;
   പൂർണ്ണസംഖ്യ b;
   പൂർണ്ണസംഖ്യ *d;
   പൂർണ്ണസംഖ്യ *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
