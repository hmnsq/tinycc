#include <stdio.h>
#include <stdarg.h>

整数 compile_errors(void)
{
#如果 TEST == 1
  {
    /* Not constant */
    static 整数 i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#如果 TEST == 2
  {
    /* Not constant */
    struct{整数 c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#如果 TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: 返回 1;
   l2: 返回 2;
  }
#endif
  返回 0;
}

整数
主要(void)
{
}
