#include <stdio.h>
#include <stdarg.h>

จำนวนเต็ม compile_errors(void)
{
#ถ้า TEST == 1
  {
    /* Not constant */
    static จำนวนเต็ม i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ถ้า TEST == 2
  {
    /* Not constant */
    sa_nracanaa{จำนวนเต็ม c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#ถ้า TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: คืน 1;
   l2: คืน 2;
  }
#endif
  คืน 0;
}

จำนวนเต็ม
หลัก(void)
{
}
