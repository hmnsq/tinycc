#include <stdio.h>
#include <stdarg.h>

ціле compile_errors(void)
{
#якщо TEST == 1
  {
    /* Not constant */
    static ціле i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#якщо TEST == 2
  {
    /* Not constant */
    struct{ціле c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#якщо TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: повернути 1;
   l2: повернути 2;
  }
#endif
  повернути 0;
}

ціле
main(void)
{
}
