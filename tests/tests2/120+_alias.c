ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಬಾಹ್ಯ ಶೂನ್ಯ target(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ alias_for_target(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ asm_for_target(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ g_int, alias_int;

ಶೂನ್ಯ inunit2(ಶೂನ್ಯ);

ಶೂನ್ಯ inunit2(ಶೂನ್ಯ)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
