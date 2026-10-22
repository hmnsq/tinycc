#include <stdio.h>
#include <stdarg.h>

ចំនួនគត់ compile_errors(void)
{
#ប្រសិនបើ TEST == 1
  {
    /* Not constant */
    static ចំនួនគត់ i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ប្រសិនបើ TEST == 2
  {
    /* Not constant */
    sa_nracanaa{ចំនួនគត់ c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#ប្រសិនបើ TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ត្រឡប់ 1;
   l2: ត្រឡប់ 2;
  }
#endif
  ត្រឡប់ 0;
}

ចំនួនគត់
main(void)
{
}
