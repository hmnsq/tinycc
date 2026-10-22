#অন্তর্ভাৱ <stdio.h>
পূর্ণাঙ্ক main() {
  printf("%d\n", (পূর্ণাঙ্ক)-1.0);
  দ্ৱিগুণ d = -1.0;
  printf("%d\n", (পূর্ণাঙ্ক)d);

  printf("%d\n", (পূর্ণাঙ্ক)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (পূর্ণাঙ্ক)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#অন্যথা
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
