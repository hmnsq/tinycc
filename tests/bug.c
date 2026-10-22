#include <stdio.h>
#include <stdarg.h>

ကိန်းပြည့် compile_errors(void)
{
#အကယ်၍ TEST == 1
  {
    /* Not constant */
    static ကိန်းပြည့် i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#အကယ်၍ TEST == 2
  {
    /* Not constant */
    sa_nracanaa{ကိန်းပြည့် c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#အကယ်၍ TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ပြန်ပေး 1;
   l2: ပြန်ပေး 2;
  }
#endif
  ပြန်ပေး 0;
}

ကိန်းပြည့်
main(void)
{
}
