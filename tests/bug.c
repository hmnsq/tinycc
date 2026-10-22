#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdarg.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା compile_errors(ଶୂନ୍ୟ)
{
#ଯଦି TEST == 1
  {
    /* Not constant */
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ଯଦି TEST == 2
  {
    /* Not constant */
    ସଂରଚନା{ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;}v;
    ସ୍ଥିର long i=((ଅକ୍ଷର*)&(v.c)-(ଅକ୍ଷର*)&v);
  }
#endif
#ଯଦି TEST == 3
  {
    /* Not constant */
    ସ୍ଥିର ଅଚଳ short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    ଶୂନ୍ୟ *p = &&l1 + ar[0];
    ଯାଅ *p;
   l1: ଫେରନ୍ତୁ 1;
   l2: ଫେରନ୍ତୁ 2;
  }
#endif
  ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
}
