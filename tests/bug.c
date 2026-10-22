#include <stdio.h>
#include <stdarg.h>

цео compile_errors(void)
{
#ако TEST == 1
  {
    /* Not constant */
    static цео i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ако TEST == 2
  {
    /* Not constant */
    struct{цео c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#ако TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: врати 1;
   l2: врати 2;
  }
#endif
  врати 0;
}

цео
main(void)
{
}
