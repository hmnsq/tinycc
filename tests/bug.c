#include <stdio.h>
#include <stdarg.h>

整数 compile_errors(void)
{
#もし TEST == 1
  {
    /* Not constant */
    static 整数 i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#もし TEST == 2
  {
    /* Not constant */
    struct{整数 c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#もし TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: 戻る 1;
   l2: 戻る 2;
  }
#endif
  戻る 0;
}

整数
メインページ(void)
{
}
