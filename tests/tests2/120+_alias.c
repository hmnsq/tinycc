ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
ബാഹ്യ ശൂന്യം target(ശൂന്യം);
ബാഹ്യ ശൂന്യം alias_for_target(ശൂന്യം);
ബാഹ്യ ശൂന്യം asm_for_target(ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ g_int, alias_int;

ശൂന്യം inunit2(ശൂന്യം);

ശൂന്യം inunit2(ശൂന്യം)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
