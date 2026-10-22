#include <stdio.h>
#include <stdarg.h>

цяло compile_errors(void)
{
#ако TEST == 1
  {
    /* Not constant */
    static цяло i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ако TEST == 2
  {
    /* Not constant */
    struct{цяло c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#ако TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: върни 1;
   l2: върни 2;
  }
#endif
  върни 0;
}

цяло
main(void)
{
}
