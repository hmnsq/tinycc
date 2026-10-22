#include <stdio.h>
целое основной() {
  printf("%d\n", (целое)-1.0);
  double d = -1.0;
  printf("%d\n", (целое)d);

  printf("%d\n", (целое)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (целое)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#иначе
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
