#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdarg.h>

পূর্ণসংখ্যা compile_errors(শূন্য)
{
#যদি TEST == 1
  {
    /* Not constant */
    স্থির পূর্ণসংখ্যা i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#যদি TEST == 2
  {
    /* Not constant */
    কাঠামো{পূর্ণসংখ্যা c;}v;
    স্থির long i=((অক্ষর*)&(v.c)-(অক্ষর*)&v);
  }
#endif
#যদি TEST == 3
  {
    /* Not constant */
    স্থির ধ্রুবক short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    শূন্য *p = &&l1 + ar[0];
    যাও *p;
   l1: ফেরত 1;
   l2: ফেরত 2;
  }
#endif
  ফেরত 0;
}

পূর্ণসংখ্যা
প্রধান(শূন্য)
{
}
