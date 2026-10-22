#include <stdio.h>
#include <stdarg.h>

số_nguyên compile_errors(void)
{
#nếu TEST == 1
  {
    /* Not constant */
    static số_nguyên i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#nếu TEST == 2
  {
    /* Not constant */
    struct{số_nguyên c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#nếu TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: trả_về 1;
   l2: trả_về 2;
  }
#endif
  trả_về 0;
}

số_nguyên
main(void)
{
}
