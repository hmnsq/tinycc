#include <stdio.h>
පූර්ණ_සංඛ්‍යා main() {
  printf("%d\n", (පූර්ණ_සංඛ්‍යා)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (පූර්ණ_සංඛ්‍යා)d);

  printf("%d\n", (පූර්ණ_සංඛ්‍යා)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (පූර්ණ_සංඛ්‍යා)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#නැතහොත්
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}
