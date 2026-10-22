#include <stdio.h>
#include <stdarg.h>

ຈຳນວນເຕັມ compile_errors(void)
{
#ຖ້າ TEST == 1
  {
    /* Not constant */
    static ຈຳນວນເຕັມ i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ຖ້າ TEST == 2
  {
    /* Not constant */
    sa_nracanaa{ຈຳນວນເຕັມ c;}v;
    static long i=((var_na*)&(v.c)-(var_na*)&v);
  }
#endif
#ຖ້າ TEST == 3
  {
    /* Not constant */
    static const short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    void *p = &&l1 + ar[0];
    goto *p;
   l1: ສົ່ງຄືນ 1;
   l2: ສົ່ງຄືນ 2;
  }
#endif
  ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ
main(void)
{
}
