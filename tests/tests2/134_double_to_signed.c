#include <stdio.h>
정수 main() {
  printf("%d\n", (정수)-1.0);
  double d = -1.0;
  printf("%d\n", (정수)d);

  printf("%d\n", (정수)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (정수)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#아니면
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
