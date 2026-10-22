/* Check semantics of various constructs to generate renamed symbols.  */

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಶೂನ್ಯ ಗುರಿ(ಶೂನ್ಯ);
ಶೂನ್ಯ ಗುರಿ(ಶೂನ್ಯ) {
    ಬರೆ("in target function\n");
}
ಶೂನ್ಯ alias_for_ಗುರಿ(ಶೂನ್ಯ) __attribute__((alias("target")));

ಪೂರ್ಣಾಂಕ g_int = 34;
ಪೂರ್ಣಾಂಕ alias_int __attribute__((alias("g_int")));

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
# define _ "_"
#ಇಲ್ಲದಿದ್ದರೆ
# define _
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ asm_for_ಗುರಿ(ಶೂನ್ಯ) __asm__(_"target");
ಪೂರ್ಣಾಂಕ asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

ಬಾಹ್ಯ ಶೂನ್ಯ inunit2(ಶೂನ್ಯ);

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
  ಗುರಿ();
  alias_for_ಗುರಿ();
  asm_for_ಗುರಿ();
  ಬರೆ("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ಹಿಂತಿರುಗಿ 0;
}
