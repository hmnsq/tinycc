बाह्य पूर्णाङ्क प्रारूप_लिख (ध्रुव वर्ण *, ...);
बाह्य शून्य target(शून्य);
बाह्य शून्य alias_for_target(शून्य);
बाह्य शून्य asm_for_target(शून्य);
बाह्य पूर्णाङ्क g_int, alias_int;

शून्य inunit2(शून्य);

शून्य inunit2(शून्य)
{
  प्रारूप_लिख("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  प्रारूप_लिख("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
