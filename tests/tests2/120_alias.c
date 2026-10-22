/* Check semantics of various constructs to generate renamed symbols.  */

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಶೂನ್ಯ target(ಶೂನ್ಯ);
ಶೂನ್ಯ target(ಶೂನ್ಯ) {
    printf("in target function\n");
}
ಶೂನ್ಯ alias_for_target(ಶೂನ್ಯ) __attribute__((alias("target")));

ಪೂರ್ಣಾಙ್ಕ g_int = 34;
ಪೂರ್ಣಾಙ್ಕ alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#ಅನ್ಯಥಾ
# define _
#endif

ಶೂನ್ಯ asm_for_target(ಶೂನ್ಯ) __asm__(_"target");
ಪೂರ್ಣಾಙ್ಕ asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

ಬಾಹ್ಯ ಶೂನ್ಯ inunit2(ಶೂನ್ಯ);

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ಪ್ರತ್ಯಾಗಮ 0;
}
