बाह्य पूर्णांक म_लिखो (स्थिरांक अक्षर *, ...);
बाह्य शून्य target(शून्य);
बाह्य शून्य alias_for_target(शून्य);
बाह्य शून्य asm_for_target(शून्य);
बाह्य पूर्णांक g_int, alias_int;

शून्य inunit2(शून्य);

शून्य inunit2(शून्य)
{
  म_लिखो("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  म_लिखो("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
