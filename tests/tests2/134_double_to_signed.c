#ଅନ୍ତର୍ଭାଵ <stdio.h>
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() {
  printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)-1.0);
  ଦ୍ୱିଗୁଣ d = -1.0;
  printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)d);

  printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#ଅନ୍ୟଥା
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
