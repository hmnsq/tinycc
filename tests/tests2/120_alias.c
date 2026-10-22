/* Check semantics of various constructs to generate renamed symbols.  */

বাহ্য পূর্ণাঙ্ক printf (ধ্রুব বর্ণ *, ...);
শূন্য target(শূন্য);
শূন্য target(শূন্য) {
    printf("in target function\n");
}
শূন্য alias_for_target(শূন্য) __attribute__((alias("target")));

পূর্ণাঙ্ক g_int = 34;
পূর্ণাঙ্ক alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#অন্যথা
# define _
#endif

শূন্য asm_for_target(শূন্য) __asm__(_"target");
পূর্ণাঙ্ক asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

বাহ্য শূন্য inunit2(শূন্য);

পূর্ণাঙ্ক main(শূন্য)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  প্রত্যাগম 0;
}
