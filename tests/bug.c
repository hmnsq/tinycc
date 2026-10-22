#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdarg.h>

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
    স্থির long i=((বর্ণ*)&(v.c)-(বর্ণ*)&v);
  }
#endif
#যদি TEST == 3
  {
    /* Not constant */
    স্থির ধ্রুব short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    শূন্য *p = &&l1 + ar[0];
    গচ্ছ *p;
   l1: প্রত্যাগম 1;
   l2: প্রত্যাগম 2;
  }
#endif
  প্রত্যাগম 0;
}

পূর্ণাঙ্ক
main(শূন্য)
{
}
