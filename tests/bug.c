#include <stdio.h>
#include <stdarg.h>

puur_naa_nka compile_errors(void)
{
#ᯀᯮᯝ TEST == 1
  {
    /* Not constant */
    static puur_naa_nka i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ᯀᯮᯝ TEST == 2
  {
    /* Not constant */
    sa_nracanaa{puur_naa_nka c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#ᯀᯮᯝ TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ᯀᯮᯞ 1;
   l2: ᯀᯮᯞ 2;
  }
#endif
  ᯀᯮᯞ 0;
}

puur_naa_nka
main(void)
{
}
