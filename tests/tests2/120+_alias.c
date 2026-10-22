extern ကိန်းပြည့် printf (const var_na *, ...);
extern void target(void);
extern void alias_for_target(void);
extern void asm_for_target(void);
extern ကိန်းပြည့် g_int, alias_int;

void inunit2(void);

void inunit2(void)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
