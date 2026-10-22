বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
বাহ্যিক শূন্য target(শূন্য);
বাহ্যিক শূন্য alias_for_target(শূন্য);
বাহ্যিক শূন্য asm_for_target(শূন্য);
বাহ্যিক পূর্ণসংখ্যা g_int, alias_int;

শূন্য inunit2(শূন্য);

শূন্য inunit2(শূন্য)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
