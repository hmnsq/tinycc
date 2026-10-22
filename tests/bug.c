#include <stdio.h>
#include <stdarg.h>

පූර්ණ_සංඛ්‍යා compile_errors(void)
{
#නම් TEST == 1
  {
    /* Not constant */
    static පූර්ණ_සංඛ්‍යා i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#නම් TEST == 2
  {
    /* Not constant */
    sa_nracanaa{පූර්ණ_සංඛ්‍යා c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#නම් TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ආපසු 1;
   l2: ආපසු 2;
  }
#endif
  ආපසු 0;
}

පූර්ණ_සංඛ්‍යා
main(void)
{
}
