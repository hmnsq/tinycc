/* Check semantics of various constructs to generate renamed symbols.  */

બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
શૂન્ય target(શૂન્ય);
શૂન્ય target(શૂન્ય) {
    printf("in target function\n");
}
શૂન્ય alias_for_target(શૂન્ય) __attribute__((alias("target")));

પૂર્ણાંક g_int = 34;
પૂર્ણાંક alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#નહીંતર
# define _
#endif

શૂન્ય asm_for_target(શૂન્ય) __asm__(_"target");
પૂર્ણાંક asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

બાહ્ય શૂન્ય inunit2(શૂન્ય);

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  પાછા 0;
}
