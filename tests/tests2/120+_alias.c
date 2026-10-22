বাহ্য পূর্ণাঙ্ক printf (ধ্রুব বর্ণ *, ...);
বাহ্য শূন্য target(শূন্য);
বাহ্য শূন্য alias_for_target(শূন্য);
বাহ্য শূন্য asm_for_target(শূন্য);
বাহ্য পূর্ণাঙ্ক g_int, alias_int;

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
