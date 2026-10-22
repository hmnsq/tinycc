#include <stdio.h>
цяло main() {
  printf("%d\n", (цяло)-1.0);
  double d = -1.0;
  printf("%d\n", (цяло)d);

  printf("%d\n", (цяло)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (цяло)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#иначе
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
