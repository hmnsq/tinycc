#അന്തര്ഭാവ <stdio.h>

ശൂന്യം charfunc(അക്ഷരം a)
{
   printf("char: %c\n", a);
}

ശൂന്യം intfunc(പൂർണ്ണസംഖ്യ a)
{
   printf("int: %d\n", a);
}

ശൂന്യം floatfunc(ദശാംശം a)
{
   printf("float: %f\n", a);
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   അക്ഷരം b = 97;
   അക്ഷരം c = 97.0;

   printf("%d %d\n", b, c);

   പൂർണ്ണസംഖ്യ d = 'a';
   പൂർണ്ണസംഖ്യ e = 97.0;

   printf("%d %d\n", d, e);

   ദശാംശം f = 'a';
   ദശാംശം g = 97;

   printf("%f %f\n", f, g);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
