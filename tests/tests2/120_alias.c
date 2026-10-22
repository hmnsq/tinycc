/* Check semantics of various constructs to generate renamed symbols.  */

بیرونی صحیح printf (ثابت نویسه *, ...);
تهی target(تهی);
تهی target(تهی) {
    printf("in target function\n");
}
تهی alias_for_target(تهی) __attribute__((alias("target")));

صحیح g_int = 34;
صحیح alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#وگرنه
# define _
#endif

تهی asm_for_target(تهی) __asm__(_"target");
صحیح asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

بیرونی تهی inunit2(تهی);

صحیح اصلی(تهی)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  بازگشت 0;
}
