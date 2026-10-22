#ضمن <stdio.h>
#ضمن <stdarg.h>

صحيح compile_errors(فراغ)
{
#אם TEST == 1
  {
    /* Not constant */
    ساكن صحيح i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#אם TEST == 2
  {
    /* Not constant */
    بنية{صحيح c;}v;
    ساكن long i=((حرف*)&(v.c)-(حرف*)&v);
  }
#endif
#אם TEST == 3
  {
    /* Not constant */
    ساكن ثابت short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    فراغ *p = &&l1 + ar[0];
    اذهب *p;
   l1: החזר 1;
   l2: החזר 2;
  }
#endif
  החזר 0;
}

صحيح
main(فراغ)
{
}
