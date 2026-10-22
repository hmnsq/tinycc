#അന്തര്ഭാവ <stdio.h>

ശൂന്യം fred(പൂർണ്ണസംഖ്യ x)
{
   തിരഞ്ഞെടുപ്പ് (x)
   {
      അവസ്ഥ 1: printf("1\n"); തിരികെ;
      അവസ്ഥ 2: printf("2\n"); നിർത്തുക;
      അവസ്ഥ 3: printf("3\n"); തിരികെ;
   }

   printf("out\n");
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   fred(1);
   fred(2);
   fred(3);

   തിരികെ 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
