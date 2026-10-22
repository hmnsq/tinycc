#شامل <stdio.h>
#شامل <stdarg.h>

صحیح compile_errors(تهی)
{
#اگر TEST == 1
  {
    /* Not constant */
    ایستا صحیح i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#اگر TEST == 2
  {
    /* Not constant */
    ساختار{صحیح c;}v;
    ایستا long i=((نویسه*)&(v.c)-(نویسه*)&v);
  }
#endif
#اگر TEST == 3
  {
    /* Not constant */
    ایستا ثابت short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    تهی *p = &&l1 + ar[0];
    برو *p;
   l1: بازگشت 1;
   l2: بازگشت 2;
  }
#endif
  بازگشت 0;
}

صحیح
اصلی(تهی)
{
}
