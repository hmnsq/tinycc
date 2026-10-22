/* Check semantics of various constructs to generate renamed symbols.  */

வெளி முழு printf (மாறிலி எழுத்து *, ...);
வெறுமை target(வெறுமை);
வெறுமை target(வெறுமை) {
    printf("in target function\n");
}
வெறுமை alias_for_target(வெறுமை) __attribute__((alias("target")));

முழு g_int = 34;
முழு alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#இல்லையெனில்
# define _
#endif

வெறுமை asm_for_target(வெறுமை) __asm__(_"target");
முழு asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

வெளி வெறுமை inunit2(வெறுமை);

முழு முதன்மை(வெறுமை)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  திரும்பு 0;
}
