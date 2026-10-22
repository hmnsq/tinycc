/* Check semantics of various constructs to generate renamed symbols.  */

ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਖਾਲੀ ਨਿਸ਼ਾਨਾ(ਖਾਲੀ);
ਖਾਲੀ ਨਿਸ਼ਾਨਾ(ਖਾਲੀ) {
    ਲਿਖੋ("in target function\n");
}
ਖਾਲੀ alias_for_ਨਿਸ਼ਾਨਾ(ਖਾਲੀ) __attribute__((alias("target")));

ਪੂਰਨ g_int = 34;
ਪੂਰਨ alias_int __attribute__((alias("g_int")));

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
# define _ "_"
#ਨਹੀਂਤਾਂ
# define _
#ਜੇ_ਅੰਤ

ਖਾਲੀ asm_for_ਨਿਸ਼ਾਨਾ(ਖਾਲੀ) __asm__(_"target");
ਪੂਰਨ asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

ਬਾਹਰੀ ਖਾਲੀ inunit2(ਖਾਲੀ);

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
  ਨਿਸ਼ਾਨਾ();
  alias_for_ਨਿਸ਼ਾਨਾ();
  asm_for_ਨਿਸ਼ਾਨਾ();
  ਲਿਖੋ("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ਵਾਪਸ 0;
}
