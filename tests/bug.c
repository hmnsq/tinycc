#include <stdio.h>
#include <stdarg.h>

целое compile_errors(void)
{
#если TEST == 1
  {
    /* Not constant */
    static целое i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#если TEST == 2
  {
    /* Not constant */
    struct{целое c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#если TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: вернуть 1;
   l2: вернуть 2;
  }
#endif
  вернуть 0;
}

целое
основной(void)
{
}
