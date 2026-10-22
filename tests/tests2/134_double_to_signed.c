#include <stdio.h>
puur_naa_nka main() {
  printf("%d\n", (puur_naa_nka)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (puur_naa_nka)d);

  printf("%d\n", (puur_naa_nka)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (puur_naa_nka)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#ꦭꦶꦪ
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
