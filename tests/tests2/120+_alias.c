बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
बाह्य व्योम target(व्योम);
बाह्य व्योम alias_for_target(व्योम);
बाह्य व्योम asm_for_target(व्योम);
बाह्य पूर्णांक g_int, alias_int;

व्योम inunit2(व्योम);

व्योम inunit2(व्योम)
{
  म_लिखो("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  म_लिखो("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
