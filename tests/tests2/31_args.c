#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
   പൂർണ്ണസംഖ്യ എണ്ണം_3;

   printf("hello world %d\n", argc);
   വേണ്ടി (എണ്ണം_3 = 1; എണ്ണം_3 < argc; എണ്ണം_3++)
      printf("arg %d: %s\n", എണ്ണം_3, argv[എണ്ണം_3]);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
