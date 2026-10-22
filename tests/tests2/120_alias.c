/* Check semantics of various constructs to generate renamed symbols.  */

خارجي صحيح چاپ_کن (ثابت حرف *, ...);
فراغ هدف(فراغ);
فراغ هدف(فراغ) {
    چاپ_کن("in target function\n");
}
فراغ alias_for_هدف(فراغ) __attribute__((alias("target")));

صحيح g_int = 34;
صحيح alias_int __attribute__((alias("g_int")));

#اگر_تعریف_شده __leading_underscore
# define _ "_"
#وإلا
# define _
#پایان_اگر

فراغ asm_for_هدف(فراغ) __asm__(_"target");
صحيح asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

خارجي فراغ inunit2(فراغ);

صحيح اصلی(فراغ)
{
  هدف();
  alias_for_هدف();
  asm_for_هدف();
  چاپ_کن("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  أرجع 0;
}
