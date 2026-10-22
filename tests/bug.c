#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <stdarg.h>

পূর্ণাঙ্ক compile_errors(শূন্য)
{
#যদি TEST == 1
  {
    /* Not constant */
    স্থির পূর্ণাঙ্ক i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#যদি TEST == 2
  {
    /* Not constant */
    সংরচনা{পূর্ণাঙ্ক c;}v;
    স্থির long i=((ৱর্ণ*)&(v.c)-(ৱর্ণ*)&v);
  }
#endif
#যদি TEST == 3
  {
    /* Not constant */
    স্থির ধ্রুৱ short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    শূন্য *p = &&l1 + ar[0];
    গচ্ছ *p;
   l1: ঘূৰাই 1;
   l2: ঘূৰাই 2;
  }
#endif
  ঘূৰাই 0;
}

পূর্ণাঙ্ক
main(শূন্য)
{
}
