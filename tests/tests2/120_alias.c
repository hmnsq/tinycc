/* Check semantics of various constructs to generate renamed symbols.  */

बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
व्योम target(व्योम);
व्योम target(व्योम) {
    म_लिखो("in target function\n");
}
व्योम alias_for_target(व्योम) __attribute__((alias("target")));

पूर्णांक g_int = 34;
पूर्णांक alias_int __attribute__((alias("g_int")));

#अगर_घोषित __leading_underscore
# define _ "_"
#अन्यथा
# define _
#पूर्ण_अगर

व्योम asm_for_target(व्योम) __asm__(_"target");
पूर्णांक asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

बाह्य व्योम inunit2(व्योम);

पूर्णांक मुख्य(व्योम)
{
  target();
  alias_for_target();
  asm_for_target();
  म_लिखो("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  वापस 0;
}
