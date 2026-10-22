/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ସଂରଚନା S { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b,c,d, e[1024];};
ପୂର୍ଣ୍ଣସଂଖ୍ୟା foo (ସଂରଚନା S *a, ସଂରଚନା S *b)
{
  *a = *b;
  ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ *memmove(ଶୂନ୍ୟ*,ଅଚଳ ଶୂନ୍ୟ*,__SIZE_TYPE__);
ଶୂନ୍ୟ foo2 (ସଂରଚନା S *a, ସଂରଚନା S *b)
{
  memmove(a, b, ଆକାର *a);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  ଫେରନ୍ତୁ 0;
}
