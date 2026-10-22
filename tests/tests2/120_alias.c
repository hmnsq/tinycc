/* Check semantics of various constructs to generate renamed symbols.  */

خارجی صحیح لکھو (ثابت حرف *, ...);
خالی ہدف(خالی);
خالی ہدف(خالی) {
    لکھو("in target function\n");
}
خالی alias_for_ہدف(خالی) __attribute__((alias("target")));

صحیح g_int = 34;
صحیح alias_int __attribute__((alias("g_int")));

#اگر_تعریف_شدہ __leading_underscore
# define _ "_"
#ورنہ
# define _
#اگر_ختم

خالی asm_for_ہدف(خالی) __asm__(_"target");
صحیح asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

خارجی خالی inunit2(خالی);

صحیح مین(خالی)
{
  ہدف();
  alias_for_ہدف();
  asm_for_ہدف();
  لکھو("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  واپس 0;
}
