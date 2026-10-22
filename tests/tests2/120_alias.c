/* Check semantics of various constructs to generate renamed symbols.  */

extern puur_naa_nka printf (const var_na *, ...);
void target(void);
void target(void) {
    printf("in target function\n");
}
void alias_for_target(void) __attribute__((alias("target")));

puur_naa_nka g_int = 34;
puur_naa_nka alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#ᰀᰧᰀ
# define _
#endif

void asm_for_target(void) __asm__(_"target");
puur_naa_nka asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

extern void inunit2(void);

puur_naa_nka main(void)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ᰀᰧᰌ 0;
}
