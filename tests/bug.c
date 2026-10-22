#ضمن <stdio.h>
#ضمن <stdarg.h>

صحيح compile_errors(فراغ)
{
#𐤀𐤌 TEST == 1
  {
    /* Not constant */
    ساكن صحيح i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#𐤀𐤌 TEST == 2
  {
    /* Not constant */
    بنية{صحيح c;}v;
    ساكن long i=((حرف*)&(v.c)-(حرف*)&v);
  }
#endif
#𐤀𐤌 TEST == 3
  {
    /* Not constant */
    ساكن ثابت short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    فراغ *p = &&l1 + ar[0];
    اذهب *p;
   l1: أرجع 1;
   l2: أرجع 2;
  }
#endif
  أرجع 0;
}

صحيح
main(فراغ)
{
}
