#include <stdio.h>
ཧྲིལ main() {
  printf("%d\n", (ཧྲིལ)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (ཧྲིལ)d);

  printf("%d\n", (ཧྲིལ)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ཧྲིལ)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#དེ་མིན
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
