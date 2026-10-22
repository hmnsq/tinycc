#অন্তর্ভাব <stdio.h>
পূর্ণসংখ্যা প্রধান() {
  printf("%d\n", (পূর্ণসংখ্যা)-1.0);
  দ্বিগুণ d = -1.0;
  printf("%d\n", (পূর্ণসংখ্যা)d);

  printf("%d\n", (পূর্ণসংখ্যা)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (পূর্ণসংখ্যা)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#অন্যথা
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
