/* Check semantics of various constructs to generate renamed symbols.  */

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ଶୂନ୍ୟ target(ଶୂନ୍ୟ);
ଶୂନ୍ୟ target(ଶୂନ୍ୟ) {
    printf("in target function\n");
}
ଶୂନ୍ୟ alias_for_target(ଶୂନ୍ୟ) __attribute__((alias("target")));

ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_int = 34;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#ଅନ୍ୟଥା
# define _
#endif

ଶୂନ୍ୟ asm_for_target(ଶୂନ୍ୟ) __asm__(_"target");
ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

ବାହ୍ୟ ଶୂନ୍ୟ inunit2(ଶୂନ୍ୟ);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
  target();
  alias_for_target();
  asm_for_target();
  printf("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  ଫେରନ୍ତୁ 0;
}
