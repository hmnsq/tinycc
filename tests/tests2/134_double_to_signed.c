#include <stdio.h>
จำนวนเต็ม หลัก() {
  printf("%d\n", (จำนวนเต็ม)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (จำนวนเต็ม)d);

  printf("%d\n", (จำนวนเต็ม)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (จำนวนเต็ม)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#มิฉะนั้น
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
