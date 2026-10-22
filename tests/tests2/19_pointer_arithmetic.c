#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ a;
   പൂർണ്ണസംഖ്യ *b;
   പൂർണ്ണസംഖ്യ *c;

   a = 42;
   b = &a;
   c = ശൂന്യ;

   printf("%d\n", *b);

   എങ്കിൽ (b == ശൂന്യ)
      printf("b is NULL\n");
   അല്ലെങ്കിൽ
      printf("b is not NULL\n");

   എങ്കിൽ (c == ശൂന്യ)
      printf("c is NULL\n");
   അല്ലെങ്കിൽ
      printf("c is not NULL\n");

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
