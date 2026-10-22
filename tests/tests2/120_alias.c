/* Check semantics of various constructs to generate renamed symbols.  */

ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
ശൂന്യം target(ശൂന്യം);
ശൂന്യം target(ശൂന്യം) {
    printf("in target function\n");
}
ശൂന്യം alias_for_target(ശൂന്യം) __attribute__((alias("target")));

പൂർണ്ണസംഖ്യ g_int = 34;
പൂർണ്ണസംഖ്യ alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#അല്ലെങ്കിൽ
# define _
#endif

ശൂന്യം asm_for_target(ശൂന്യം) __asm__(_"target");
പൂർണ്ണസംഖ്യ asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

ബാഹ്യ ശൂന്യം inunit2(ശൂന്യം);

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  തിരികെ 0;
}
