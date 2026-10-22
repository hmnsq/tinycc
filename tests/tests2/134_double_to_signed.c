#include <stdio.h>
ціле main() {
  printf("%d\n", (ціле)-1.0);
  double d = -1.0;
  printf("%d\n", (ціле)d);

  printf("%d\n", (ціле)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ціле)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#інакше
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
