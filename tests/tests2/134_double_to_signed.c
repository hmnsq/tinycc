#include <stdio.h>
цео main() {
  printf("%d\n", (цео)-1.0);
  double d = -1.0;
  printf("%d\n", (цео)d);

  printf("%d\n", (цео)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (цео)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#инако
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
