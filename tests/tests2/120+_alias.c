ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಬಾಹ್ಯ ಶೂನ್ಯ ಗುರಿ(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ alias_for_ಗುರಿ(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ asm_for_ಗುರಿ(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ g_int, alias_int;

ಶೂನ್ಯ inunit2(ಶೂನ್ಯ);

ಶೂನ್ಯ inunit2(ಶೂನ್ಯ)
{
  ಬರೆ("in unit2:\n");
  ಗುರಿ();
  alias_for_ಗುರಿ();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  ಬರೆ("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
