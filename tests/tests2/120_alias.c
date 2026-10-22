/* Check semantics of various constructs to generate renamed symbols.  */

बाह्य पूर्णाङ्क म_लिखो (अचर वर्ण *, ...);
शून्य target(शून्य);
शून्य target(शून्य) {
    म_लिखो("in target function\n");
}
शून्य alias_for_target(शून्य) __attribute__((alias("target")));

पूर्णाङ्क g_int = 34;
पूर्णाङ्क alias_int __attribute__((alias("g_int")));

#ifdef __leading_underscore
# define _ "_"
#अन्यथा
# define _
#endif

शून्य asm_for_target(शून्य) __asm__(_"target");
पूर्णाङ्क asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

बाह्य शून्य inunit2(शून्य);

पूर्णाङ्क main(शून्य)
{
  target();
  alias_for_target();
  asm_for_target();
  म_लिखो("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  फर्काऊ 0;
}
