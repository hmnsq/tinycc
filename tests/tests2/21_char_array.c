#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ x = 'a';
   അക്ഷരം y = x;

   അക്ഷരം *a = "hello";

   printf("%s\n", a);

   പൂർണ്ണസംഖ്യ c;
   c = *a;

   അക്ഷരം *b;
   വേണ്ടി (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   അക്ഷരം destarray[10];
   അക്ഷരം *dest = &destarray[0];
   അക്ഷരം *src = a;

   ആകുമ്പോൾ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
