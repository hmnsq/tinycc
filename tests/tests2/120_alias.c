/* Check semantics of various constructs to generate renamed symbols.  */

خارجي صحيح لکھو (ثابت حرف *, ...);
فراغ نشانہ(فراغ);
فراغ نشانہ(فراغ) {
    لکھو("in target function\n");
}
فراغ alias_for_نشانہ(فراغ) __attribute__((alias("target")));

صحيح g_int = 34;
صحيح alias_int __attribute__((alias("g_int")));

#جے_تعریف_شدہ __leading_underscore
# define _ "_"
#وإلا
# define _
#جے_انت

فراغ asm_for_نشانہ(فراغ) __asm__(_"target");
صحيح asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

خارجي فراغ inunit2(فراغ);

صحيح مکھ(فراغ)
{
  نشانہ();
  alias_for_نشانہ();
  asm_for_نشانہ();
  لکھو("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  أرجع 0;
}
