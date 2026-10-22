ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ବାହ୍ୟ ଶୂନ୍ୟ target(ଶୂନ୍ୟ);
ବାହ୍ୟ ଶୂନ୍ୟ alias_for_target(ଶୂନ୍ୟ);
ବାହ୍ୟ ଶୂନ୍ୟ asm_for_target(ଶୂନ୍ୟ);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_int, alias_int;

ଶୂନ୍ୟ inunit2(ଶୂନ୍ୟ);

ଶୂନ୍ୟ inunit2(ଶୂନ୍ୟ)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
