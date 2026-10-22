#include <stdio.h>
#include <stdarg.h>

ཧྲིལ compile_errors(void)
{
#གལ་ཏེ TEST == 1
  {
    /* Not constant */
    static ཧྲིལ i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#གལ་ཏེ TEST == 2
  {
    /* Not constant */
    sa_nracanaa{ཧྲིལ c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#གལ་ཏེ TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ཕྱིར 1;
   l2: ཕྱིར 2;
  }
#endif
  ཕྱིར 0;
}

ཧྲིལ
གཙོ(void)
{
}
