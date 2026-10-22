/* Check semantics of various constructs to generate renamed symbols.  */

خارجي صحيح printf (ثابت حرف *, ...);
فراغ target(فراغ);
فراغ target(فراغ) {
    printf("in target function\n");
}
فراغ alias_for_target(فراغ) __attribute__((alias("target")));

صحيح g_int = 34;
صحيح alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#ܐܚܪܢܐ
# define _
#endif

فراغ asm_for_target(فراغ) __asm__(_"target");
صحيح asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

خارجي فراغ inunit2(فراغ);

صحيح main(فراغ)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ܦܢܐ 0;
}
