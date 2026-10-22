#include <stdio.h>
#include <stdarg.h>

정수 compile_errors(void)
{
#만약 TEST == 1
  {
    /* Not constant */
    static 정수 i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#만약 TEST == 2
  {
    /* Not constant */
    struct{정수 c;}v;
    static long i=((char*)&(v.c)-(char*)&v);
  }
#endif
#만약 TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: 반환 1;
   l2: 반환 2;
  }
#endif
  반환 0;
}

정수
main(void)
{
}
